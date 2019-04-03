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

/*******************************************************************************
* Pointers to audio samples and their DMA Y loops of data transfer.
*******************************************************************************/
extern const int16 *SoundsPointers[16];
extern uint32 Y_SoundLoops[16];
extern uint32 Y_ZeroLoops[16];

/*******************************************************************************
* DMA descriptors and their configurations.
*******************************************************************************/
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

/*******************************************************************************
* void ErrorHandler(void)
********************************************************************************
*
* Summary:
*  This function is used to disable interrupts and to loop program in cycle which
 do nothing.
*  
* Parameters:
*  led_color Color - single byte which corresponds to the colour of LED.
*
* Return:
*  None.
*
*******************************************************************************/
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
/*******************************************************************************
* void LED_PrintByte(led_color Color)
********************************************************************************
*
* Summary:
*  This function is used controll all LED with one byte.
*  
* Parameters:
*  led_color Color - single byte which corresponds to the colour of LED.
*
* Return:
*  None.
*
*******************************************************************************/
void LED_PrintByte(led_color Color){
	(READ_BIT(Color, 0)) ? (Cy_GPIO_Clr(RED_LED_PORT, RED_LED_PIN))     : (Cy_GPIO_Set(RED_LED_PORT, RED_LED_PIN));
	(READ_BIT(Color, 1)) ? (Cy_GPIO_Clr(GREEN_LED_PORT, GREEN_LED_PIN)) : (Cy_GPIO_Set(GREEN_LED_PORT, GREEN_LED_PIN));
	(READ_BIT(Color, 2)) ? (Cy_GPIO_Clr(BLUE_LED_PORT, BLUE_LED_PIN))   : (Cy_GPIO_Set(BLUE_LED_PORT, BLUE_LED_PIN));
	(READ_BIT(Color, 3)) ? (Cy_GPIO_Clr(LED8_PORT, LED8_PIN))           : (Cy_GPIO_Set(LED8_PORT, LED8_PIN));
	(READ_BIT(Color, 4)) ? (Cy_GPIO_Clr(LED9_PORT, LED9_PIN))           :  (Cy_GPIO_Set(LED9_PORT, LED9_PIN));
}

/*******************************************************************************
* void InitUART(void)
********************************************************************************
*
* Summary:
*  This function is used to initialize UART.
*  
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void InitUART(void){
	cy_stc_scb_uart_context_t UART_context;
	cy_en_scb_uart_status_t InitState;
	InitState = Cy_SCB_UART_Init(UART_HW, &UART_config, &UART_context);
	(InitState == CY_SCB_UART_SUCCESS)?(Cy_SCB_UART_Enable(UART_HW)):(ErrorHandler());
}

/*******************************************************************************
* void InitDAC(void)
********************************************************************************
*
* Summary:
*  This function is used to initialize DAC with OpAmp as buffer. Pin 
*  
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void InitDAC(void){
	Cy_SysAnalog_Init(&AREF_config);
	Cy_SysAnalog_Enable();
	Cy_CTB_OpampInit(DAC_BUFF_HW, CY_CTB_OPAMP_0, &DAC_BUFF_config);
	Cy_CTB_Enable(DAC_BUFF_HW);
	Cy_CTDAC_Init(KIT_DAC_HW, &KIT_DAC_config);
	Cy_CTDAC_Enable(KIT_DAC_HW);
}

/*******************************************************************************
* void InitDMA(void)
********************************************************************************
*
* Summary:
*  This function is used to initialize DMA descriptors and channel.
*  
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void InitDMA(void){
	/* Initialize all descriptors. */
	Cy_DMA_Descriptor_Init(&DAC_DMA_Descriptor_0, &DAC_DMA_Descriptor_0_config);
	for(int x = 0; x<16; x++){
			Cy_DMA_Descriptor_Init(&DAC_DMA_SoundDescriptors[x], &DAC_DMA_SoundDescriptorsConfig[x]);
			Cy_DMA_Descriptor_Init(&DAC_DMA_ZeroDescriptors[x], &DAC_DMA_ZeroDescriptorsConfig[x]);
	}
	Cy_DMA_Channel_Init(DAC_DMA_HW, DAC_DMA_CHANNEL, &DAC_DMA_channelConfig);
	/* Enable DMA. */
	Cy_DMA_Channel_SetDescriptor(DAC_DMA_HW, DAC_DMA_CHANNEL, &DAC_DMA_SoundDescriptors[0]);
	Cy_DMA_Channel_Enable(DAC_DMA_HW, DAC_DMA_CHANNEL);
	Cy_DMA_Enable(DAC_DMA_HW);
}

/*******************************************************************************
* void InitCapSense(void)
********************************************************************************
*
* Summary:
*  This function is used to initialize CapSense and its interrupt.
*  
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void InitCapSense(void){
	const cy_stc_sysint_t CapSense_ISR_cfg ={ .intrSrc = csd_interrupt_IRQn, .intrPriority = 7u, };
	Cy_CapSense_Init(&cy_capsense_context);
	/* Initialize CapSense interrupt */
	Cy_SysInt_Init(&CapSense_ISR_cfg, &CapSense_Interrupt);
	NVIC_ClearPendingIRQ(CapSense_ISR_cfg.intrSrc);
	NVIC_EnableIRQ(CapSense_ISR_cfg.intrSrc);
	Cy_CapSense_Enable(&cy_capsense_context);  /* Initialize the CapSense firmware modules. */
}



/*******************************************************************************
* Function Name: capsense_touch CapSenseGetTouch(void)
********************************************************************************
*
* Summary:
*  This function is used to scan CapSense vidgets untill touch registered.
*  
* Parameters:
*  None
*
* Return:
*  capsense_touch - registered touch.
*
*******************************************************************************/
/* Macros for gesture detection. */
#define LEFT_FLICK_MASK		(0x03004080u)
#define RIGHT_FLICK_MASK	(0x02004080u)

capsense_touch CapSenseGetTouch(void){
	uint32 Slider_Status;
	/* Function use curr and prev touch to avoid return of same touch
	in the next function call. CurrTouch should be initialized with 
	non zero value to return touch only when previous scan was TOUCH_NONE.*/
	capsense_touch CurrTouch = TOUCH_BTN1; 
	capsense_touch PrevTouch = TOUCH_NONE;
	while(1u){
		if(CY_CAPSENSE_NOT_BUSY == Cy_CapSense_IsBusy(&cy_capsense_context))
		{
			PrevTouch = CurrTouch;
			/* Start the CapSense scan, process all widgets and read touch information */
			Cy_CapSense_ScanAllWidgets(&cy_capsense_context);
			Cy_CapSense_ProcessAllWidgets(&cy_capsense_context);
			Slider_Status = Cy_CapSense_DecodeWidgetGestures(CY_CAPSENSE_LINEARSLIDER0_WDGT_ID, &cy_capsense_context);
			/* Button0 is active */
			if (Cy_CapSense_IsWidgetActive(CY_CAPSENSE_BUTTON0_WDGT_ID, &cy_capsense_context)){
				CurrTouch = TOUCH_BTN0;
				 /* Return button touch if it changed state from 0 to 1 */
				if (PrevTouch == TOUCH_NONE) return TOUCH_BTN0;
			/* Button1 is active */
			}else if(Cy_CapSense_IsWidgetActive (CY_CAPSENSE_BUTTON1_WDGT_ID,&cy_capsense_context)){ 
				CurrTouch = TOUCH_BTN1; 
				/* Return button touch if it changed state from 0 to 1 */
				if (PrevTouch == TOUCH_NONE) return TOUCH_BTN1;
			/* Slider left flick detected. */
			}else if(Slider_Status == LEFT_FLICK_MASK){
				return LEFT_SLIDE; 
			/* Slider right flick detected. */
			}else if(Slider_Status == RIGHT_FLICK_MASK){
				return RIGHT_SLIDE; 
			/* No touch detected.*/
			}else{
				CurrTouch = TOUCH_NONE; 
			}
		}
	}
}

/*******************************************************************************
* void SetupDAC_DMA(uint8 *PatternPtr)
********************************************************************************
*
* Summary:
*  This function is used to configure DMA descriptors which used for audio playback.
*  
* Parameters:
*  uint8 *PatternPtr - pointer to first element of Pattern array.
*
* Return:
*  None.
*
*******************************************************************************/
void SetupDAC_DMA(uint8 *PatternPtr){
	/* Set not used in audio playback descriptor as current for channel; disable channel. */
	Cy_DMA_Channel_SetDescriptor(DAC_DMA_HW, DAC_DMA_CHANNEL, &DAC_DMA_Descriptor_0);
	Cy_DMA_Disable(DAC_DMA_HW);
	
	/* Configure each descriptor in descriptors array. Set source address and Y loops 
		for each descriptor using corresponding Pattern element. 
		DAC_DMA_SoundDescriptors chained to DAC_DMA_ZeroDescriptors which chained to next 
		sound descriptor, last descriptor in chain chained to first in order to create loop.
		DAC_DMA_SoundDescriptors used sound raw data as source, and  DAC_DMA_ZeroDescriptors
		source is a array with zeros.*/
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
		Cy_DMA_Descriptor_SetDstAddress(&DAC_DMA_SoundDescriptors[i], &CTDAC0->CTDAC_VAL_NXT);

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
		Cy_DMA_Descriptor_SetDstAddress(&DAC_DMA_ZeroDescriptors[i], &CTDAC0->CTDAC_VAL_NXT);

		Cy_DMA_Descriptor_SetXloopSrcIncrement(&DAC_DMA_ZeroDescriptors[i], 1UL);
		Cy_DMA_Descriptor_SetXloopDstIncrement(&DAC_DMA_ZeroDescriptors[i], 0UL);
		Cy_DMA_Descriptor_SetXloopDataCount(&DAC_DMA_ZeroDescriptors[i], 256UL);
		Cy_DMA_Descriptor_SetYloopSrcIncrement(&DAC_DMA_ZeroDescriptors[i], 0UL);
		Cy_DMA_Descriptor_SetYloopDstIncrement(&DAC_DMA_ZeroDescriptors[i], 0UL);
		Cy_DMA_Descriptor_SetYloopDataCount(&DAC_DMA_ZeroDescriptors[i], Y_ZeroLoops[*(PatternPtr + i)]);
		(i < 15)?(Cy_DMA_Descriptor_SetNextDescriptor(&DAC_DMA_ZeroDescriptors[i], &DAC_DMA_SoundDescriptors[i+1]))
				 :(Cy_DMA_Descriptor_SetNextDescriptor(&DAC_DMA_ZeroDescriptors[i], &DAC_DMA_SoundDescriptors[0]));

		/* Set first in chain descriptor as active for channel; enable channel. */
		Cy_DMA_Channel_SetDescriptor(DAC_DMA_HW, DAC_DMA_CHANNEL, &DAC_DMA_SoundDescriptors[0]);
		Cy_DMA_Enable(DAC_DMA_HW);
	}
}

/*******************************************************************************
* void CapSense_Interrupt(void)
********************************************************************************
*
* Summary:
*  CapSense interrupt function.
*
*******************************************************************************/
void CapSense_Interrupt(void)
{
    Cy_CapSense_InterruptHandler(CapSense_HW, &cy_capsense_context);
}






