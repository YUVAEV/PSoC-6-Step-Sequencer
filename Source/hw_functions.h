#include "cycfg.h"
#include "cy_pdl.h"
#include <stdio.h>
#include "stdio_user.h"
#include "cy_dma.h"

//#define DAC_CLOCK_FREQ (72000000UL)
typedef enum {
	/* use `&` to combine colors */
	LED_NONE    =   0b00000000,
	RGB_RED     =   0b00000001,
	RGB_GREEN   =   0b00000010,
	RGB_BLUE    =   0b00000100,
	LED_8       =   0b00001000,
	LED_9       =   0b00010000
} led_color;

typedef enum {
	TOUCH_NONE,
	TOUCH_BTN0,
	TOUCH_BTN1,
	LEFT_SLIDE,
	RIGHT_SLIDE
} capsense_touch;

void LED_PrintByte(led_color Color);
void ErrorHandler(void);
void InitUART(void);
void InitDAC(void);
void InitDMA(void);
void InitCapSense(void);

void SetupDAC_DMA(uint8*PatternPtr);

//void SetUpSounds(uint8*PatternPtr);
capsense_touch CapSenseGetTouch(void);
