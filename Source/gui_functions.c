/******************************************************************************
* File Name: gui_functions.h
*
* Version: 1.00
*
* Description: This file contains functions that provide graphical
* 			   user interface.
*
* Related Document:
*
* Hardware Dependency: CY8CKIT-062-BLE PSoC 6 BLE Pioneer Kit
*                      CY8CKIT-028-EPD E-INK Display Shield
*
*******************************************************************************/
#include "gui_functions.h"
#define READ_BIT(byte, index) (((byte) >> (index)) & 1)

extern void LCD_CopyDisplayBuffer(uint8* destination, int count);

void InitDisplay(void);
void UpdateDisplay(cy_eink_update_t updateMethod, bool powerCycle);
void DrawStartupScreen(void);
void DrawTempoValue(uint8 Tempo);
void DrawActivePatternSteps(uint8*PatternPtr);
void DrawMainScreen(void);
void DrawInvertedMenu(gui_menu Menu);
gui_menu MenuRoll(void);
void PatternCreator(uint8*PatternPtr);
void StepEditor(uint8 SoundNumber, uint8*PatternPtr);
void ShowInfoPages(void);

uint8 StepPositionsX[] = {7, 17, 27, 37, 52, 62, 72, 82, 97, 107, 117, 127, 142, 152, 162, 172};
uint8 StepPositionsY[] = {34, 70, 106, 142};

void InitDisplay(void)
{
	cy_eink_api_result InitState1, InitState2;
	InitState1 = Cy_EINK_Start(25u, CyDelay);
	InitState2 = Cy_EINK_Power(CY_EINK_ON);
	if ((InitState1 == CY_EINK_SUCCESS) && (InitState2 == CY_EINK_SUCCESS)){
		GUI_Init();
	}else{
		printf("\r\n Display initialization failed!!! \r\n");
		ErrorHandler();
	}
}

void UpdateDisplay(cy_eink_update_t updateMethod, bool powerCycle)
{
	static cy_eink_frame_t	currFrameBuffer  [CY_EINK_FRAME_SIZE];
	static cy_eink_frame_t	prevFrameBuffer [CY_EINK_FRAME_SIZE];

	LED_PrintByte(LED_8);
    /* Copy the EmWin display buffer to imageBuffer*/
    LCD_CopyDisplayBuffer(currFrameBuffer, CY_EINK_FRAME_SIZE);
    /* Update the EInk display */
    Cy_EINK_ShowFrame(prevFrameBuffer, currFrameBuffer, updateMethod, powerCycle);
    /* Copy the EmWin display buffer to the imageBuffer cache*/
    LCD_CopyDisplayBuffer(prevFrameBuffer, CY_EINK_FRAME_SIZE);
    LED_PrintByte(LED_NONE);
}

void DrawStartupScreen(void){
	GUI_SetColor(GUI_BLACK);
	GUI_SetBkColor(GUI_WHITE);
	GUI_Clear();
	GUI_SetFont(GUI_FONT_32B_1);
	GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("Step Sequencer", 132u, 50u);
    GUI_SetTextMode(GUI_TM_XOR);
	GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt(" Touch CapSense BTN1 to start ", 132u, 130u);
}

void DrawMainScreen(void)
{
	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
	GUI_Clear();
	/*     Pattern creator section     */
	/*Pattern = 4tacts =  16parts*/
	/*Background for all section*/
	GUI_FillRect(2u, 21u, 185u, 164u);
	/*     Tact block prototype     */
	// Tact buttons background
	GUI_ClearRect(5u, 33u, 47u, 56u);
	// First part button
	GUI_FillRect(8u, 36u, 14u, 53u);
	// Triangle on first part button
	GUI_SetPenSize(1);
	GUI_SetColor(GUI_BLACK);
	GUI_DrawLine( 9u, 37u, 13u, 37u);
	GUI_DrawLine(10u, 38u, 12u, 38u);
	GUI_DrawPixel(11u, 39u);
	//GUI_DrawLine(10u, 41u, 12u, 37u);
	GUI_SetColor(GUI_WHITE);
	// Second part button
	GUI_FillRect(18u, 36u, 24u, 53u);
	// Third part button
	GUI_FillRect(28u, 36u, 34u, 53u);
	// Forth part button
	GUI_FillRect(38u, 36u, 44u, 53u);
	// Copy tact block into one line
	GUI_CopyRect(5u, 33u, 50u, 33u, 44u, 24u);
	GUI_CopyRect(5u, 33u, 95u, 33u, 44u, 24u);
	GUI_CopyRect(5u, 33u, 140u, 33u, 44u, 24u);
	// Copy first line, paste as second, third and forth
	GUI_CopyRect(5u, 33u, 5u, 69u, 178u, 24u);
	GUI_CopyRect(5u, 33u, 5u, 105u, 178u, 24u);
	GUI_CopyRect(5u, 33u, 5u, 141u, 178u, 24u);
	/*     Print sound names     */
	GUI_SetFont(GUI_FONT_8_1);
	GUI_SetTextMode(GUI_TM_XOR);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt(" Clap",       6u, 23u);
    GUI_DispStringAt(" Kick",       6u, 59u);
    GUI_DispStringAt(" Hi-Hat",     6u, 95u);
    GUI_DispStringAt(" Small drum", 6u, 132u);
	/*     Print controls     */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("BTN0-Select | BTN1-Back | Slider-Scroll", 132u, 168u);
	/*     Create buttons     */
    GUI_SetFont(GUI_FONT_13B_1);
    // Pattern creator
    GUI_DrawRect(2u, 2u, 185u, 18u);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("Pattern Creator", 92u, 4u);
    // Tempo
    GUI_DrawRect(189u, 21u, 262u, 90u);
	GUI_DrawLine(195, 40u, 256u, 40u);
    GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt("Tempo", 225u, 26u);
    // Play/Stop
	GUI_DrawRect(189u, 93u, 262u, 138u);
	GUI_DrawLine(189, 115u, 262u, 115u);
    GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt("Play", 225u, 98u);
    GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt("Stop", 225u, 120u);
    // Info
	GUI_DrawRect(189u, 141u, 262u, 164u);
    GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt("Info", 225u, 145u);
}

void DrawTempoValue(uint8 Tempo){
	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
	GUI_SetFont(GUI_FONT_32_1);
	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_SetTextMode(GUI_TM_XOR);
	GUI_ClearRect(195, 45u, 256u, 85u);
	(Tempo<100u)?(GUI_DispDecAt(Tempo, 225u, 50u, 2)):(GUI_DispDecAt(Tempo, 225u, 50u, 3));
}

void DrawActivePatternSteps(uint8*PatternPtr){
	printf("\t DrawActivePatternSteps call. \r\n");
	GUI_SetColor(GUI_BLACK);
	GUI_SetBkColor(GUI_WHITE);
	for(int x = 0; x < 16; x++){
		for(int y = 0; y < 4; y++){
			(READ_BIT(*(PatternPtr + x), y))
			? (GUI_FillRect ((StepPositionsX[x] + 2), (StepPositionsY[y] + 8), (StepPositionsX[x] + 6),  (StepPositionsY[y] + 18)))
			: (GUI_ClearRect((StepPositionsX[x] + 2), (StepPositionsY[y] + 8), (StepPositionsX[x] + 6),  (StepPositionsY[y] + 18)));
		}
	}
}

void DrawInvertedMenu(gui_menu Menu){
	GUI_SetTextMode(GUI_TM_REV);
	switch(Menu)
	{
		case PatternCreatorMenu: GUI_InvertRect(  2u,   2u, 185u,  18u); break;
		case TempoMenu:          GUI_InvertRect(189u,  21u, 262u,  90u); break;
		case PlayStopMenu:       GUI_InvertRect(189u,  93u, 262u, 115u); break;
		case InfoMenu:           GUI_InvertRect(189u, 141u, 262u, 164u); break;
	}
}

gui_menu MenuRoll(void)
{
	printf("\t MenuRoll call. \r\n");
	static gui_menu CurrMenu;
	capsense_touch CurrTouch;
	while(1u){
		CurrTouch = CapSenseGetTouch();
		switch (CurrTouch){
			case LEFT_SLIDE:
				DrawInvertedMenu(CurrMenu);
				(CurrMenu <= PatternCreatorMenu)?(CurrMenu = InfoMenu):(CurrMenu--);
				DrawInvertedMenu(CurrMenu);
				UpdateDisplay(CY_EINK_PARTIAL, true);
				break;

			case RIGHT_SLIDE:
				DrawInvertedMenu(CurrMenu);
				(CurrMenu >= InfoMenu)?(CurrMenu = PatternCreatorMenu):(CurrMenu++);
				DrawInvertedMenu(CurrMenu);
				UpdateDisplay(CY_EINK_PARTIAL, true);
				break;

			case TOUCH_BTN0:
				return CurrMenu;

			default: break;
		}
	}
}

void PatternCreator(uint8*PatternPtr)
{
	uint8 CurrSound = 0;
	capsense_touch CurrTouch = TOUCH_NONE;
	printf("\t PatternCreator call. \r\n");

	while(CurrTouch != TOUCH_BTN1){
		if (CurrTouch == RIGHT_SLIDE) (CurrSound >= 3) ? (CurrSound = 0) : (CurrSound++);
		if (CurrTouch == LEFT_SLIDE)  (CurrSound <= 0) ? (CurrSound = 3) : (CurrSound--);
		if (CurrTouch == TOUCH_BTN0) StepEditor(CurrSound, PatternPtr);

		switch(CurrSound){
			case 0: GUI_InvertRect(5u, 22u,  182u, 31u ); break;
			case 1: GUI_InvertRect(5u, 58u,  182u, 67u ); break;
			case 2: GUI_InvertRect(5u, 94u,  182u, 103u); break;
			case 3: GUI_InvertRect(5u, 131u, 182u, 139u); break;
		}
		UpdateDisplay(CY_EINK_PARTIAL, true);
		switch(CurrSound){
			case 0: GUI_InvertRect(5u, 22u,  182u, 31u ); break;
			case 1: GUI_InvertRect(5u, 58u,  182u, 67u ); break;
			case 2: GUI_InvertRect(5u, 94u,  182u, 103u); break;
			case 3: GUI_InvertRect(5u, 131u, 182u, 139u); break;
		}
		CurrTouch = CapSenseGetTouch();
	}
	UpdateDisplay(CY_EINK_PARTIAL, true);
}

void StepEditor(uint8 SoundNumber, uint8*PatternPtr)
{
	printf("\tStepEditor call. \r\n");
	uint16 Y_TopPos = 0;
	uint16 X_TopPos = 0;
	uint16 Y_BottomPos, X_BottomPos;
	uint8 PatternBit = 0;

	capsense_touch CurrTouch = TOUCH_NONE;
	uint8 CurrStep = 0;
	switch(SoundNumber)
	{
		case 0: Y_TopPos =  34u; PatternBit = 0b00000001; break;
		case 1: Y_TopPos =  70u; PatternBit = 0b00000010; break;
		case 2: Y_TopPos = 106u; PatternBit = 0b00000100; break;
		case 3: Y_TopPos = 142u; PatternBit = 0b00001000; break;
		default :
			printf("StepEditor -  CURRENT SOUND NUMBER IS OUT OF RANGE \r\n");
			ErrorHandler();
	}
	Y_BottomPos = Y_TopPos + 21;
	while (CurrTouch != TOUCH_BTN1){
		if (CurrTouch == RIGHT_SLIDE) (CurrStep >= 15) ? (CurrStep = 0)  : (CurrStep++);
		if (CurrTouch == LEFT_SLIDE)  (CurrStep <= 0)  ? (CurrStep = 15) : (CurrStep--);
		switch(CurrStep){
			case  0: X_TopPos =   7u; break;
			case  1: X_TopPos =  17u; break;
			case  2: X_TopPos =  27u; break;
			case  3: X_TopPos =  37u; break;

			case  4: X_TopPos =  52u; break;
			case  5: X_TopPos =  62u; break;
			case  6: X_TopPos =  72u; break;
			case  7: X_TopPos =  82u; break;

			case  8: X_TopPos =  97u; break;
			case  9: X_TopPos = 107u; break;
			case 10: X_TopPos = 117u; break;
			case 11: X_TopPos = 127u; break;

			case 12: X_TopPos = 142u; break;
			case 13: X_TopPos = 152u; break;
			case 14: X_TopPos = 162u; break;
			case 15: X_TopPos = 172u; break;
			default :
				printf("StepEditor -  CURRENT STEP IS OUT OF RANGE \r\n");
				ErrorHandler();
		}
		X_BottomPos = X_TopPos + 8u;

		if (CurrTouch == TOUCH_BTN0) {
			*(PatternPtr + CurrStep) = *(PatternPtr + CurrStep) ^ PatternBit;
			GUI_InvertRect( (X_BottomPos - 6), (Y_BottomPos - 13), (X_BottomPos- 2), (Y_BottomPos - 3));
		}

		GUI_InvertRect(  X_TopPos, Y_TopPos,  X_BottomPos, Y_BottomPos);
		UpdateDisplay(CY_EINK_PARTIAL, true);
		GUI_InvertRect(  X_TopPos, Y_TopPos,  X_BottomPos, Y_BottomPos);

		CurrTouch = CapSenseGetTouch();
	}
}

void ShowInfoPages(void){

	GUI_RECT textMargins = {8u, 26u, 254u, 120u};
	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
	GUI_Clear();
	GUI_SetTextMode(GUI_TM_XOR);
	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_SetFont(GUI_FONT_8_1);

	GUI_DispStringHCenterAt("BTN0-Select | BTN1-Exit Info | Slider-Scroll", 132u, 168u);

	GUI_SetPenSize(1);
	GUI_SetFont(GUI_FONT_13B_1);

	GUI_DispStringHCenterAt("Sequencer Functions",  67u, 126u);
	GUI_DrawRect(5u,   124u, 129u, 140u);
	GUI_DispStringHCenterAt("Pattern Creation", 195u, 126u);
	GUI_DrawRect(133u, 124u, 258u, 140u);
	GUI_DispStringHCenterAt("Setting Tempo",     67u, 146u);
	GUI_DrawRect(5u,   144u, 129u, 160u);
	GUI_DispStringHCenterAt("Sound Playback",   195u, 146u);
	GUI_DrawRect(133u, 144u, 258u, 160u);

	UpdateDisplay(CY_EINK_FULL_4STAGE, true);

	capsense_touch CurrTouch = TOUCH_BTN0;
	uint8 CurrMenu = 1;
	while(CurrTouch != TOUCH_BTN1){

		if (CurrTouch == RIGHT_SLIDE) (CurrMenu >= 4) ? (CurrMenu = 0) : (CurrMenu++);
		if (CurrTouch == LEFT_SLIDE)  (CurrMenu <= 0) ? (CurrMenu = 4) : (CurrMenu--);

		if (CurrTouch == TOUCH_BTN0){
			GUI_FillRect(4u, 4u, 259u, 122u); // Text block
			GUI_ClearRect(8u, 22u, 254u, 23u);
			GUI_SetFont(GUI_FONT_16B_1);
			switch(CurrMenu){
				case 1:
					GUI_DispStringHCenterAt("Sequencer Functions", 132u, 6u);
					GUI_SetFont(GUI_FONT_8_1);

					GUI_DispStringInRectWrap(
					"The main purpose of step sequencer is to create,     \n"\
					"   edit and playback defined by user sequences       \n"\
					"   of different sounds.                              \n"\
					"                                                     \n"\
					"Feasibilities:                                       \n"\
					"   - Create and play drum loops or simple melodies   \n"\
					"   melodies by setting up a pattern.                 \n"\
					"   - Change sound length and pitch by changing       \n"\
					"   Tempo value.                                      \n"\
					"   - Configure patterns for up to 4 sounds.          \n"\
					"   - 16 steps per pattern loop.                      \n"\
					"   - Playback several sounds at once.                ",
					&textMargins, GUI_TA_LEFT, GUI_WRAPMODE_WORD);
					break;

				case 2:
					GUI_DispStringHCenterAt("Pattern Creation", 132u, 6u);
					GUI_SetFont(GUI_FONT_8_1);
					GUI_DispStringInRectWrap(
					"This program has typical for the step sequencer      \n"\
					"  principle of work - pattern represents 16 equal    \n"\
					"  time intervals(called steps) which are looped,     \n"\
					"  and user can activate instrument in any pattern    \n"\
					"  step.                                              \n"\
					"To set up pattern you should do next steps:          \n"\
					" 1.  Select Pattern Creator menu on main screen.     \n"\
					" 2. Select sound which you want to use.              \n"\
					" 3. Using slider set cursor to desired step.         \n"\
					" 4. Press select button to enable/disable current    \n"\
					"  step, black rectangle indicates active step.       \n"\
					" 5. Set other sounds or return to main screen.       ",
					&textMargins, GUI_TA_LEFT, GUI_WRAPMODE_WORD);
					break;

				case 3:
					GUI_DispStringHCenterAt("Setting Tempo",    132u, 6u);
					GUI_SetFont(GUI_FONT_8_1);
					GUI_DispStringInRectWrap(
					"Tempo value is responsible for number of steps       \n"\
					"   per minute(sets the bits per minute (BPM))        \n"\
					"Tempo value also change pitch of the sounds,         \n"\
					"  it 'stretches' sample length and length of step.   \n"\
					"The maximum tempo value is 240 BPM,                  \n"\
					"  and minimum - 30BPM                                \n"\
					"To set tempo value you should do next steps:         \n"\
					" 1. Select Tempo menu on main screen, tempo value    \n"\
					"  highlights when menu is active.                    \n"\
					" 2. Slide right to increase tempo by 5, and left     \n"\
					"  slide to decrase tempo by 5.                       \n"\
					" 3. Press back button to set current value as active.",
					&textMargins, GUI_TA_LEFT, GUI_WRAPMODE_WORD);
					break;

				case 4:
					GUI_DispStringHCenterAt("Sound Playback",   132u, 6u);
					GUI_SetFont(GUI_FONT_8_1);
					GUI_DispStringInRectWrap(
					"Playback sound sequence from your pattern is very \n"\
					"  easy, and can be done in few steps:             \n"\
					"                                                  \n"\
					" 1. Select Play menu on main screen, blue led will\n"\
					"  turn on, button `Stop` will highlight and audio \n"\
					"  out become active.                              \n"\
					" 2. All commands will freeze, selecting a 'Stop'  \n"\
					"  button is a only way to legal return to menu and\n"\
					"  stop the audio playback.                        ",
					&textMargins, GUI_TA_LEFT, GUI_WRAPMODE_WORD);
					break;
			}


		}
		switch(CurrMenu){
			case 1:
				GUI_InvertRect(5u,   124u, 129u, 140u);
				UpdateDisplay(CY_EINK_PARTIAL, true);
				GUI_InvertRect(5u,   124u, 129u, 140u);

				break;
			case 2:
				GUI_InvertRect(133u, 124u, 258u, 140u);
				UpdateDisplay(CY_EINK_PARTIAL, true);
				GUI_InvertRect(133u, 124u, 258u, 140u);

				break;
			case 3:
				GUI_InvertRect(5u,   144u, 129u, 160u);
				UpdateDisplay(CY_EINK_PARTIAL, true);
				GUI_InvertRect(5u,   144u, 129u, 160u);
				break;
			case 4:
				GUI_InvertRect(133u, 144u, 258u, 160u);
				UpdateDisplay(CY_EINK_PARTIAL, true);
				GUI_InvertRect(133u, 144u, 258u, 160u);
				break;
		}

		CurrTouch = CapSenseGetTouch();
	}
}
