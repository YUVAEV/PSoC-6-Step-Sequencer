/******************************************************************************
* File Name: gui_functions.h
*
* Version: 1.00
*
* Description: This file contains functions which interfaces with hardware.
*
* Related Document:
*
* Hardware Dependency: CY8CKIT-062-BLE PSoC 6 BLE Pioneer Kit
*                      CY8CKIT-028-EPD E-INK Display Shield
*
*******************************************************************************/
#include "hw_functions.h"
#include "cycfg_capsense.h"
#include "cy_pdl.h"
#include "cy_ctdac.h"
#include "sound_samples.h"

#define READ_BIT(byte, index) (((byte) >> (index)) & 1)
#define CTDAC_NEXT_VALUE_PTR ((CTDAC_V1_Type *)0x41140104UL)

#define LEFT_FLICK_MASK		(0x03004080u)/* Macros for gesture detection. */
#define RIGHT_FLICK_MASK	(0x02004080u)

extern const int16 *SoundsPointers[16];
extern uint32 Y_SoundLoops[16];
extern uint32 Y_ZeroLoops[16];

static cy_stc_dma_descriptor_t DAC_DMA_SoundDescriptors[16] = {0};
static cy_stc_dma_descriptor_config_t DAC_DMA_SoundDescriptorsConfig[16] = {0};
static cy_stc_dma_descriptor_t DAC_DMA_ZeroDescriptors[16] = {0};
static cy_stc_dma_descriptor_config_t DAC_DMA_ZeroDescriptorsConfig[16] = {0};

void CapSense_Interrupt(void);
void ErrorHandler(void);
void InitUART(void);
void InitDAC(void);
void InitDMA(void);
void InitCapSense(void);
capsense_touch CapSenseGetTouch(void);
void SetupDAC_DMA(uint8*PatternPtr);

void ErrorHandler(void){
	__disable_irq();

	printf("\r\n\t ERROR!\r\n\t Interrupts will be disabled\r\n\t Program flow will be looped in cycle.");
	printf("\r\n===========================");
	LED_PrintByte(RGB_RED);
	/* Disable interrupts. */
	while (1u) {
		/* Do nothing in infinite cycle. */
	}
}

void LED_PrintByte(led_color Color){
	(READ_BIT(Color, 0)) ? (Cy_GPIO_Clr(RED_LED_PORT, RED_LED_PIN))     : (Cy_GPIO_Set(RED_LED_PORT, RED_LED_PIN));
	(READ_BIT(Color, 1)) ? (Cy_GPIO_Clr(GREEN_LED_PORT, GREEN_LED_PIN)) : (Cy_GPIO_Set(GREEN_LED_PORT, GREEN_LED_PIN));
	(READ_BIT(Color, 2)) ? (Cy_GPIO_Clr(BLUE_LED_PORT, BLUE_LED_PIN))   : (Cy_GPIO_Set(BLUE_LED_PORT, BLUE_LED_PIN));
	(READ_BIT(Color, 3)) ? (Cy_GPIO_Clr(LED8_PORT, LED8_PIN))           : (Cy_GPIO_Set(LED8_PORT, LED8_PIN));
	(READ_BIT(Color, 4)) ? (Cy_GPIO_Clr(LED9_PORT, LED9_PIN))           :  (Cy_GPIO_Set(LED9_PORT, LED9_PIN));
}

void InitUART(void){
	cy_stc_scb_uart_context_t UART_context;
	cy_en_scb_uart_status_t InitState;
	InitState = Cy_SCB_UART_Init(UART_HW, &UART_config, &UART_context);
	(InitState == CY_SCB_UART_SUCCESS)?(Cy_SCB_UART_Enable(UART_HW)):(ErrorHandler());
}

void InitDAC(void){
	Cy_SysAnalog_Init(&AREF_config);
	Cy_SysAnalog_Enable();
	Cy_CTB_OpampInit(DAC_BUFF_HW, CY_CTB_OPAMP_0, &DAC_BUFF_config);
	Cy_CTB_Enable(DAC_BUFF_HW);
	Cy_CTDAC_Init(KIT_DAC_HW, &KIT_DAC_config);
	Cy_CTDAC_Enable(KIT_DAC_HW);
}

void InitDMA(void){
	Cy_DMA_Descriptor_Init(&DAC_DMA_Descriptor_0, &DAC_DMA_Descriptor_0_config);
	for(int x = 0; x<16; x++){
			Cy_DMA_Descriptor_Init(&DAC_DMA_SoundDescriptors[x], &DAC_DMA_SoundDescriptorsConfig[x]);
			Cy_DMA_Descriptor_Init(&DAC_DMA_ZeroDescriptors[x], &DAC_DMA_ZeroDescriptorsConfig[x]);
	}
	Cy_DMA_Channel_Init(DAC_DMA_HW, DAC_DMA_CHANNEL, &DAC_DMA_channelConfig);

	Cy_DMA_Channel_SetDescriptor(DAC_DMA_HW, DAC_DMA_CHANNEL, &DAC_DMA_SoundDescriptors[0]);
	Cy_DMA_Channel_Enable(DAC_DMA_HW, DAC_DMA_CHANNEL);
	Cy_DMA_Enable(DAC_DMA_HW);
}

void InitCapSense(void){
	const cy_stc_sysint_t CapSense_ISR_cfg ={ .intrSrc = csd_interrupt_IRQn, .intrPriority = 7u, };
	Cy_CapSense_Init(&cy_capsense_context);
	/* Initialize CapSense interrupt */
	Cy_SysInt_Init(&CapSense_ISR_cfg, &CapSense_Interrupt);
	NVIC_ClearPendingIRQ(CapSense_ISR_cfg.intrSrc);
	NVIC_EnableIRQ(CapSense_ISR_cfg.intrSrc);
	Cy_CapSense_Enable(&cy_capsense_context);  /* Initialize the CapSense firmware modules. */
}

capsense_touch CapSenseGetTouch(void){
	uint32 Slider_Status;
	capsense_touch CurrTouch = TOUCH_BTN1;
	capsense_touch PrevTouch = TOUCH_NONE;
	while(1u){
		if(CY_CAPSENSE_NOT_BUSY == Cy_CapSense_IsBusy(&cy_capsense_context))
		{
			PrevTouch = CurrTouch;
			/* Start the CapSense scan */
			Cy_CapSense_ScanAllWidgets(&cy_capsense_context);
			/* Process all widgets and read touch information */
			Cy_CapSense_ProcessAllWidgets(&cy_capsense_context);
			Slider_Status = Cy_CapSense_DecodeWidgetGestures(CY_CAPSENSE_LINEARSLIDER0_WDGT_ID, &cy_capsense_context);

			if (Cy_CapSense_IsWidgetActive(CY_CAPSENSE_BUTTON0_WDGT_ID, &cy_capsense_context)){
				CurrTouch = TOUCH_BTN0; /* Button0 is active */
				if (PrevTouch == TOUCH_NONE) return TOUCH_BTN0;

			}else if(Cy_CapSense_IsWidgetActive (CY_CAPSENSE_BUTTON1_WDGT_ID,&cy_capsense_context)){
				CurrTouch = TOUCH_BTN1; /* Button1 is active */
				if (PrevTouch == TOUCH_NONE) return TOUCH_BTN1;

			}else if(Slider_Status == LEFT_FLICK_MASK){
				CurrTouch = LEFT_SLIDE; return LEFT_SLIDE; /* Slider left flick detected. */

			}else if(Slider_Status == RIGHT_FLICK_MASK){
				CurrTouch = RIGHT_SLIDE;return RIGHT_SLIDE; /* Slider right flick detected. */

			}else{
				CurrTouch = TOUCH_NONE; /* No touch detected.*/
			}
		}
	}
}

void SetupDAC_DMA(uint8 *PatternPtr){
	Cy_DMA_Channel_SetDescriptor(DAC_DMA_HW, DAC_DMA_CHANNEL, &DAC_DMA_Descriptor_0);
	Cy_DMA_Disable(DAC_DMA_HW);

	for(int i = 0; i<16; i++){
		/*Sounds*/
		Cy_DMA_Descriptor_SetRetrigger(&DAC_DMA_SoundDescriptors[i], CY_DMA_RETRIG_IM);
		Cy_DMA_Descriptor_SetInterruptType(&DAC_DMA_SoundDescriptors[i], CY_DMA_DESCR_CHAIN);
		Cy_DMA_Descriptor_SetTriggerOutType(&DAC_DMA_SoundDescriptors[i], CY_DMA_DESCR_CHAIN);
		Cy_DMA_Descriptor_SetChannelState(&DAC_DMA_SoundDescriptors[i], CY_DMA_CHANNEL_ENABLED);
		Cy_DMA_Descriptor_SetTriggerInType(&DAC_DMA_SoundDescriptors[i], CY_DMA_1ELEMENT);
		Cy_DMA_Descriptor_SetDataSize(&DAC_DMA_SoundDescriptors[i], CY_DMA_HALFWORD);
		Cy_DMA_Descriptor_SetSrcTransferSize(&DAC_DMA_SoundDescriptors[i], CY_DMA_TRANSFER_SIZE_DATA);
		Cy_DMA_Descriptor_SetDstTransferSize(&DAC_DMA_SoundDescriptors[i], CY_DMA_TRANSFER_SIZE_WORD);
		Cy_DMA_Descriptor_SetDescriptorType(&DAC_DMA_SoundDescriptors[i], CY_DMA_2D_TRANSFER);
		Cy_DMA_Descriptor_SetSrcAddress(&DAC_DMA_SoundDescriptors[i], SoundsPointers[*(PatternPtr + i)]);
		Cy_DMA_Descriptor_SetDstAddress(&DAC_DMA_SoundDescriptors[i], CTDAC_NEXT_VALUE_PTR);

		Cy_DMA_Descriptor_SetXloopSrcIncrement(&DAC_DMA_SoundDescriptors[i], 1UL);
		Cy_DMA_Descriptor_SetXloopDstIncrement(&DAC_DMA_SoundDescriptors[i], 0UL);
		Cy_DMA_Descriptor_SetXloopDataCount(&DAC_DMA_SoundDescriptors[i], 256UL);
		Cy_DMA_Descriptor_SetYloopSrcIncrement(&DAC_DMA_SoundDescriptors[i], 256UL);
		Cy_DMA_Descriptor_SetYloopDstIncrement(&DAC_DMA_SoundDescriptors[i], 0UL);
		Cy_DMA_Descriptor_SetYloopDataCount(&DAC_DMA_SoundDescriptors[i], Y_SoundLoops[*(PatternPtr + i)]);
		Cy_DMA_Descriptor_SetNextDescriptor(&DAC_DMA_SoundDescriptors[i], &DAC_DMA_ZeroDescriptors[i]);

		/*Zeros*/
		Cy_DMA_Descriptor_SetRetrigger(&DAC_DMA_ZeroDescriptors[i], CY_DMA_RETRIG_IM);
		Cy_DMA_Descriptor_SetInterruptType(&DAC_DMA_ZeroDescriptors[i], CY_DMA_DESCR_CHAIN);
		Cy_DMA_Descriptor_SetTriggerOutType(&DAC_DMA_ZeroDescriptors[i], CY_DMA_DESCR_CHAIN);
		Cy_DMA_Descriptor_SetChannelState(&DAC_DMA_ZeroDescriptors[i], CY_DMA_CHANNEL_ENABLED);
		Cy_DMA_Descriptor_SetTriggerInType(&DAC_DMA_ZeroDescriptors[i], CY_DMA_1ELEMENT);
		Cy_DMA_Descriptor_SetDataSize(&DAC_DMA_ZeroDescriptors[i], CY_DMA_HALFWORD);
		Cy_DMA_Descriptor_SetSrcTransferSize(&DAC_DMA_ZeroDescriptors[i], CY_DMA_TRANSFER_SIZE_DATA);
		Cy_DMA_Descriptor_SetDstTransferSize(&DAC_DMA_ZeroDescriptors[i], CY_DMA_TRANSFER_SIZE_WORD);
		Cy_DMA_Descriptor_SetDescriptorType(&DAC_DMA_ZeroDescriptors[i], CY_DMA_2D_TRANSFER);
		Cy_DMA_Descriptor_SetSrcAddress(&DAC_DMA_ZeroDescriptors[i], SoundsPointers[0]);
		Cy_DMA_Descriptor_SetDstAddress(&DAC_DMA_ZeroDescriptors[i], CTDAC_NEXT_VALUE_PTR);

		Cy_DMA_Descriptor_SetXloopSrcIncrement(&DAC_DMA_ZeroDescriptors[i], 1UL);
		Cy_DMA_Descriptor_SetXloopDstIncrement(&DAC_DMA_ZeroDescriptors[i], 0UL);
		Cy_DMA_Descriptor_SetXloopDataCount(&DAC_DMA_ZeroDescriptors[i], 256UL);
		Cy_DMA_Descriptor_SetYloopSrcIncrement(&DAC_DMA_ZeroDescriptors[i], 0UL);
		Cy_DMA_Descriptor_SetYloopDstIncrement(&DAC_DMA_ZeroDescriptors[i], 0UL);
		Cy_DMA_Descriptor_SetYloopDataCount(&DAC_DMA_ZeroDescriptors[i], Y_ZeroLoops[*(PatternPtr + i)]);
		(i < 15)?(Cy_DMA_Descriptor_SetNextDescriptor(&DAC_DMA_ZeroDescriptors[i], &DAC_DMA_SoundDescriptors[i+1]))
				 :(Cy_DMA_Descriptor_SetNextDescriptor(&DAC_DMA_ZeroDescriptors[i], &DAC_DMA_SoundDescriptors[0]));

		Cy_DMA_Channel_SetDescriptor(DAC_DMA_HW, DAC_DMA_CHANNEL, &DAC_DMA_SoundDescriptors[0]);
		Cy_DMA_Enable(DAC_DMA_HW);
	}
}


void CapSense_Interrupt(void)
{
    Cy_CapSense_InterruptHandler(CapSense_HW, &cy_capsense_context);
}






