/******************************************************************************
* File Name: gui_functions.h
*
* Version: 1.00
*
* Description: This file is the public interface of gui_functions.c
*
* Related Document:
*
* Hardware Dependency: CY8CKIT-062-BLE PSoC 6 BLE Pioneer Kit
*                      CY8CKIT-028-EPD E-INK Display Shield
*
*******************************************************************************/
#include "hw_functions.h"
#include "./cy_cy8ckit_028_epd/cy_cy8ckit_028_epd.h"
#include "GUI.h"

#define READ_BIT(byte, index) (((byte) >> (index)) & 1)

typedef enum {
	PatternCreatorMenu,
	TempoMenu,
	PlayStopMenu,
	InfoMenu
}gui_menu;

void InitDisplay(void);
void UpdateDisplay(cy_eink_update_t updateMethod, bool powerCycle);
void DrawStartupScreen(void);
void DrawMainScreen(void);
void DrawTempoValue(uint8 Tempo);
void DrawActivePatternSteps(uint8*PatternPtr);
void DrawInvertedMenu(gui_menu Menu);
gui_menu MenuRoll(void);
void PatternCreator(uint8*PatternPtr);
void ShowInfoPages(void);
