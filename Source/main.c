/******************************************************************************
* File Name: main.c
*
* Version: 1.00
*
* Description:
*
* Related Document:
*
* Hardware Dependency: CY8CKIT-062-BLE PSoC 6 BLE Pioneer Kit
*                      CY8CKIT-028-EPD E-INK Display Shield
*
*******************************************************************************/
#include "cy_syslib.h"
#include "cycfg.h"
#include "gui_functions.h"

#define DEFAULT_TEMPO (60U)
#define DEFAULT_SAMPLE_RATE (44155U)
#define SAMPLES_PER_BEAT (735U)
#define DAC_CLOCK_FREQ (72000000UL)

int main(void)
{
	uint8 Pattern[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	//uint8 Pattern[16] = {0};
	uint8 Tempo = DEFAULT_TEMPO;
	uint16 CurrClockDivider = 0;
	capsense_touch CurrentTouch = TOUCH_NONE;
	init_cycfg_all();
	LED_PrintByte(LED_9);
	InitUART();
	InitDAC();
	InitDMA();
	__enable_irq();
	InitCapSense();
	InitDisplay();
	LED_PrintByte(LED_NONE);
	DrawStartupScreen();
	UpdateDisplay(CY_EINK_FULL_4STAGE, true);
	SetupDAC_DMA(&Pattern[0]);
	while(TOUCH_BTN1 != CapSenseGetTouch());
	DrawMainScreen();
	DrawInvertedMenu(PatternCreatorMenu);
	DrawTempoValue(Tempo);
	DrawActivePatternSteps(&Pattern[0]);
	UpdateDisplay(CY_EINK_FULL_4STAGE, true);
	for(;;)
	{
		switch (MenuRoll()){
			case PatternCreatorMenu:
				printf("PatternCreatorMenu. \r\n");
				PatternCreator(&Pattern[0]);
				break;
			case TempoMenu:
				printf("TempoMenu. \r\n");
				GUI_InvertRect(195, 45u, 256u, 85u);
				UpdateDisplay(CY_EINK_PARTIAL, true);
				CurrentTouch = TOUCH_NONE;
				while(CurrentTouch != TOUCH_BTN1){
					CurrentTouch = CapSenseGetTouch();
					if (CurrentTouch == RIGHT_SLIDE) (Tempo >= 240) ? (Tempo = 30)  : (Tempo+=5);
					if (CurrentTouch == LEFT_SLIDE)  (Tempo <= 30)  ? (Tempo = 240) : (Tempo-=5);

					if (CurrentTouch != TOUCH_BTN0){
					DrawTempoValue(Tempo);
					UpdateDisplay(CY_EINK_PARTIAL, true);
					}
				}
				CurrClockDivider = DAC_CLOCK_FREQ / (SAMPLES_PER_BEAT * Tempo);
				Cy_SysClk_PeriphSetDivider(DAC_Clock_HW, DAC_Clock_NUM, CurrClockDivider);
				GUI_InvertRect(195, 45u, 256u, 85u);
				UpdateDisplay(CY_EINK_PARTIAL, true);
				break;
			case PlayStopMenu:
				printf("PlayStopMenu. \r\n");
				GUI_InvertRect(189u, 93u, 262u, 138u);
				UpdateDisplay(CY_EINK_PARTIAL, true);
				LED_PrintByte(RGB_BLUE);
				SetupDAC_DMA(&Pattern[0]);
				Cy_SysClk_PeriphEnableDivider(DAC_Clock_HW, DAC_Clock_NUM);

				while(TOUCH_BTN0 != CapSenseGetTouch());
				Cy_SysClk_PeriphDisableDivider(DAC_Clock_HW, DAC_Clock_NUM);
				GUI_InvertRect(189u, 93u, 262u, 138u);
				UpdateDisplay(CY_EINK_PARTIAL, true);
				LED_PrintByte(LED_NONE);
				break;
			case InfoMenu:
				printf("InfoMenu. \r\n");
				ShowInfoPages();
				while(TOUCH_BTN1 != CapSenseGetTouch());
				DrawMainScreen();
				DrawInvertedMenu(InfoMenu);
				DrawTempoValue(Tempo);
				DrawActivePatternSteps(&Pattern[0]);
				UpdateDisplay(CY_EINK_FULL_4STAGE, true);
				break;
		}
	}
}
