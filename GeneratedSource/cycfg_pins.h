/*******************************************************************************
* File Name: cycfg_pins.h
*
* Description:
* Pin configuration
* This file was automatically generated and should not be modified.
* 
********************************************************************************
* Copyright 2017-2019 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
********************************************************************************/

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define CY_EINK_DispIoEn_PORT GPIO_PRT0
#define CY_EINK_DispIoEn_PIN 2U
#define CY_EINK_DispIoEn_NUM 2U
#define CY_EINK_DispIoEn_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CY_EINK_DispIoEn_INIT_DRIVESTATE 0
#ifndef ioss_0_port_0_pin_2_HSIOM
	#define ioss_0_port_0_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define CY_EINK_DispIoEn_HSIOM ioss_0_port_0_pin_2_HSIOM
#define CY_EINK_DispIoEn_IRQ ioss_interrupts_gpio_0_IRQn
#define RED_LED_PORT GPIO_PRT0
#define RED_LED_PIN 3U
#define RED_LED_NUM 3U
#define RED_LED_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define RED_LED_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_3_HSIOM
	#define ioss_0_port_0_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define RED_LED_HSIOM ioss_0_port_0_pin_3_HSIOM
#define RED_LED_IRQ ioss_interrupts_gpio_0_IRQn
#define BLUE_LED_PORT GPIO_PRT11
#define BLUE_LED_PIN 1U
#define BLUE_LED_NUM 1U
#define BLUE_LED_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define BLUE_LED_INIT_DRIVESTATE 1
#ifndef ioss_0_port_11_pin_1_HSIOM
	#define ioss_0_port_11_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define BLUE_LED_HSIOM ioss_0_port_11_pin_1_HSIOM
#define BLUE_LED_IRQ ioss_interrupts_gpio_11_IRQn
#define CY_EINK_Mosi_PORT GPIO_PRT12
#define CY_EINK_Mosi_PIN 0U
#define CY_EINK_Mosi_NUM 0U
#define CY_EINK_Mosi_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CY_EINK_Mosi_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_0_HSIOM
	#define ioss_0_port_12_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define CY_EINK_Mosi_HSIOM ioss_0_port_12_pin_0_HSIOM
#define CY_EINK_Mosi_IRQ ioss_interrupts_gpio_12_IRQn
#define CY_EINK_Miso_PORT GPIO_PRT12
#define CY_EINK_Miso_PIN 1U
#define CY_EINK_Miso_NUM 1U
#define CY_EINK_Miso_DRIVEMODE CY_GPIO_DM_HIGHZ
#define CY_EINK_Miso_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_1_HSIOM
	#define ioss_0_port_12_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define CY_EINK_Miso_HSIOM ioss_0_port_12_pin_1_HSIOM
#define CY_EINK_Miso_IRQ ioss_interrupts_gpio_12_IRQn
#define CY_EINK_Sclk_PORT GPIO_PRT12
#define CY_EINK_Sclk_PIN 2U
#define CY_EINK_Sclk_NUM 2U
#define CY_EINK_Sclk_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CY_EINK_Sclk_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_2_HSIOM
	#define ioss_0_port_12_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define CY_EINK_Sclk_HSIOM ioss_0_port_12_pin_2_HSIOM
#define CY_EINK_Sclk_IRQ ioss_interrupts_gpio_12_IRQn
#define CY_EINK_Ssel_PORT GPIO_PRT12
#define CY_EINK_Ssel_PIN 3U
#define CY_EINK_Ssel_NUM 3U
#define CY_EINK_Ssel_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CY_EINK_Ssel_INIT_DRIVESTATE 0
#ifndef ioss_0_port_12_pin_3_HSIOM
	#define ioss_0_port_12_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define CY_EINK_Ssel_HSIOM ioss_0_port_12_pin_3_HSIOM
#define CY_EINK_Ssel_IRQ ioss_interrupts_gpio_12_IRQn
#define LED9_PORT GPIO_PRT13
#define LED9_PIN 7U
#define LED9_NUM 7U
#define LED9_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define LED9_INIT_DRIVESTATE 1
#ifndef ioss_0_port_13_pin_7_HSIOM
	#define ioss_0_port_13_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define LED9_HSIOM ioss_0_port_13_pin_7_HSIOM
#define LED9_IRQ ioss_interrupts_gpio_13_IRQn
#define ioss_0_port_1_pin_0_PORT GPIO_PRT1
#define ioss_0_port_1_pin_0_PIN 0U
#define ioss_0_port_1_pin_0_NUM 0U
#define ioss_0_port_1_pin_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_1_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_0_HSIOM
	#define ioss_0_port_1_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_1_pin_0_IRQ ioss_interrupts_gpio_1_IRQn
#define GREEN_LED_PORT GPIO_PRT1
#define GREEN_LED_PIN 1U
#define GREEN_LED_NUM 1U
#define GREEN_LED_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define GREEN_LED_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_1_HSIOM
	#define ioss_0_port_1_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define GREEN_LED_HSIOM ioss_0_port_1_pin_1_HSIOM
#define GREEN_LED_IRQ ioss_interrupts_gpio_1_IRQn
#define LED8_PORT GPIO_PRT1
#define LED8_PIN 5U
#define LED8_NUM 5U
#define LED8_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define LED8_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_5_HSIOM
	#define ioss_0_port_1_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define LED8_HSIOM ioss_0_port_1_pin_5_HSIOM
#define LED8_IRQ ioss_interrupts_gpio_1_IRQn
#define KIT_UART_RX_PORT GPIO_PRT5
#define KIT_UART_RX_PIN 0U
#define KIT_UART_RX_NUM 0U
#define KIT_UART_RX_DRIVEMODE CY_GPIO_DM_HIGHZ
#define KIT_UART_RX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_0_HSIOM
	#define ioss_0_port_5_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define KIT_UART_RX_HSIOM ioss_0_port_5_pin_0_HSIOM
#define KIT_UART_RX_IRQ ioss_interrupts_gpio_5_IRQn
#define KIT_UART_TX_PORT GPIO_PRT5
#define KIT_UART_TX_PIN 1U
#define KIT_UART_TX_NUM 1U
#define KIT_UART_TX_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define KIT_UART_TX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_1_HSIOM
	#define ioss_0_port_5_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define KIT_UART_TX_HSIOM ioss_0_port_5_pin_1_HSIOM
#define KIT_UART_TX_IRQ ioss_interrupts_gpio_5_IRQn
#define CY_EINK_DispRst_PORT GPIO_PRT5
#define CY_EINK_DispRst_PIN 2U
#define CY_EINK_DispRst_NUM 2U
#define CY_EINK_DispRst_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CY_EINK_DispRst_INIT_DRIVESTATE 0
#ifndef ioss_0_port_5_pin_2_HSIOM
	#define ioss_0_port_5_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define CY_EINK_DispRst_HSIOM ioss_0_port_5_pin_2_HSIOM
#define CY_EINK_DispRst_IRQ ioss_interrupts_gpio_5_IRQn
#define CY_EINK_DispBusy_PORT GPIO_PRT5
#define CY_EINK_DispBusy_PIN 3U
#define CY_EINK_DispBusy_NUM 3U
#define CY_EINK_DispBusy_DRIVEMODE CY_GPIO_DM_HIGHZ
#define CY_EINK_DispBusy_INIT_DRIVESTATE 0
#ifndef ioss_0_port_5_pin_3_HSIOM
	#define ioss_0_port_5_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define CY_EINK_DispBusy_HSIOM ioss_0_port_5_pin_3_HSIOM
#define CY_EINK_DispBusy_IRQ ioss_interrupts_gpio_5_IRQn
#define CY_EINK_DispEn_PORT GPIO_PRT5
#define CY_EINK_DispEn_PIN 4U
#define CY_EINK_DispEn_NUM 4U
#define CY_EINK_DispEn_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CY_EINK_DispEn_INIT_DRIVESTATE 0
#ifndef ioss_0_port_5_pin_4_HSIOM
	#define ioss_0_port_5_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define CY_EINK_DispEn_HSIOM ioss_0_port_5_pin_4_HSIOM
#define CY_EINK_DispEn_IRQ ioss_interrupts_gpio_5_IRQn
#define CY_EINK_Discharge_PORT GPIO_PRT5
#define CY_EINK_Discharge_PIN 5U
#define CY_EINK_Discharge_NUM 5U
#define CY_EINK_Discharge_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CY_EINK_Discharge_INIT_DRIVESTATE 0
#ifndef ioss_0_port_5_pin_5_HSIOM
	#define ioss_0_port_5_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define CY_EINK_Discharge_HSIOM ioss_0_port_5_pin_5_HSIOM
#define CY_EINK_Discharge_IRQ ioss_interrupts_gpio_5_IRQn
#define CY_EINK_Border_PORT GPIO_PRT5
#define CY_EINK_Border_PIN 6U
#define CY_EINK_Border_NUM 6U
#define CY_EINK_Border_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CY_EINK_Border_INIT_DRIVESTATE 0
#ifndef ioss_0_port_5_pin_6_HSIOM
	#define ioss_0_port_5_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define CY_EINK_Border_HSIOM ioss_0_port_5_pin_6_HSIOM
#define CY_EINK_Border_IRQ ioss_interrupts_gpio_5_IRQn
#define ioss_0_port_6_pin_4_PORT GPIO_PRT6
#define ioss_0_port_6_pin_4_PIN 4U
#define ioss_0_port_6_pin_4_NUM 4U
#define ioss_0_port_6_pin_4_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_6_pin_4_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_4_HSIOM
	#define ioss_0_port_6_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_6_pin_4_IRQ ioss_interrupts_gpio_6_IRQn
#define ioss_0_port_6_pin_6_PORT GPIO_PRT6
#define ioss_0_port_6_pin_6_PIN 6U
#define ioss_0_port_6_pin_6_NUM 6U
#define ioss_0_port_6_pin_6_DRIVEMODE CY_GPIO_DM_PULLUP
#define ioss_0_port_6_pin_6_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_6_HSIOM
	#define ioss_0_port_6_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_6_pin_6_IRQ ioss_interrupts_gpio_6_IRQn
#define ioss_0_port_6_pin_7_PORT GPIO_PRT6
#define ioss_0_port_6_pin_7_PIN 7U
#define ioss_0_port_6_pin_7_NUM 7U
#define ioss_0_port_6_pin_7_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define ioss_0_port_6_pin_7_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_7_HSIOM
	#define ioss_0_port_6_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_6_pin_7_IRQ ioss_interrupts_gpio_6_IRQn
#define ioss_0_port_7_pin_1_PORT GPIO_PRT7
#define ioss_0_port_7_pin_1_PIN 1U
#define ioss_0_port_7_pin_1_NUM 1U
#define ioss_0_port_7_pin_1_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_7_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_1_HSIOM
	#define ioss_0_port_7_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_7_pin_1_IRQ ioss_interrupts_gpio_7_IRQn
#define ioss_0_port_7_pin_2_PORT GPIO_PRT7
#define ioss_0_port_7_pin_2_PIN 2U
#define ioss_0_port_7_pin_2_NUM 2U
#define ioss_0_port_7_pin_2_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_7_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_2_HSIOM
	#define ioss_0_port_7_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_7_pin_2_IRQ ioss_interrupts_gpio_7_IRQn
#define ioss_0_port_7_pin_7_PORT GPIO_PRT7
#define ioss_0_port_7_pin_7_PIN 7U
#define ioss_0_port_7_pin_7_NUM 7U
#define ioss_0_port_7_pin_7_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_7_pin_7_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_7_HSIOM
	#define ioss_0_port_7_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_7_pin_7_IRQ ioss_interrupts_gpio_7_IRQn
#define ioss_0_port_8_pin_1_PORT GPIO_PRT8
#define ioss_0_port_8_pin_1_PIN 1U
#define ioss_0_port_8_pin_1_NUM 1U
#define ioss_0_port_8_pin_1_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_8_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_1_HSIOM
	#define ioss_0_port_8_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_1_IRQ ioss_interrupts_gpio_8_IRQn
#define ioss_0_port_8_pin_2_PORT GPIO_PRT8
#define ioss_0_port_8_pin_2_PIN 2U
#define ioss_0_port_8_pin_2_NUM 2U
#define ioss_0_port_8_pin_2_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_8_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_2_HSIOM
	#define ioss_0_port_8_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_2_IRQ ioss_interrupts_gpio_8_IRQn
#define ioss_0_port_8_pin_3_PORT GPIO_PRT8
#define ioss_0_port_8_pin_3_PIN 3U
#define ioss_0_port_8_pin_3_NUM 3U
#define ioss_0_port_8_pin_3_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_8_pin_3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_3_HSIOM
	#define ioss_0_port_8_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_3_IRQ ioss_interrupts_gpio_8_IRQn
#define ioss_0_port_8_pin_4_PORT GPIO_PRT8
#define ioss_0_port_8_pin_4_PIN 4U
#define ioss_0_port_8_pin_4_NUM 4U
#define ioss_0_port_8_pin_4_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_8_pin_4_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_4_HSIOM
	#define ioss_0_port_8_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_4_IRQ ioss_interrupts_gpio_8_IRQn
#define ioss_0_port_8_pin_5_PORT GPIO_PRT8
#define ioss_0_port_8_pin_5_PIN 5U
#define ioss_0_port_8_pin_5_NUM 5U
#define ioss_0_port_8_pin_5_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_8_pin_5_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_5_HSIOM
	#define ioss_0_port_8_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_5_IRQ ioss_interrupts_gpio_8_IRQn
#define ioss_0_port_8_pin_6_PORT GPIO_PRT8
#define ioss_0_port_8_pin_6_PIN 6U
#define ioss_0_port_8_pin_6_NUM 6U
#define ioss_0_port_8_pin_6_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_8_pin_6_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_6_HSIOM
	#define ioss_0_port_8_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_6_IRQ ioss_interrupts_gpio_8_IRQn
#define ioss_0_port_8_pin_7_PORT GPIO_PRT8
#define ioss_0_port_8_pin_7_PIN 7U
#define ioss_0_port_8_pin_7_NUM 7U
#define ioss_0_port_8_pin_7_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_8_pin_7_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_7_HSIOM
	#define ioss_0_port_8_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_7_IRQ ioss_interrupts_gpio_8_IRQn
#define ioss_0_port_9_pin_2_PORT GPIO_PRT9
#define ioss_0_port_9_pin_2_PIN 2U
#define ioss_0_port_9_pin_2_NUM 2U
#define ioss_0_port_9_pin_2_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_9_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_2_HSIOM
	#define ioss_0_port_9_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_9_pin_2_IRQ ioss_interrupts_gpio_9_IRQn

extern const cy_stc_gpio_pin_config_t CY_EINK_DispIoEn_config;
extern const cy_stc_gpio_pin_config_t RED_LED_config;
extern const cy_stc_gpio_pin_config_t BLUE_LED_config;
extern const cy_stc_gpio_pin_config_t CY_EINK_Mosi_config;
extern const cy_stc_gpio_pin_config_t CY_EINK_Miso_config;
extern const cy_stc_gpio_pin_config_t CY_EINK_Sclk_config;
extern const cy_stc_gpio_pin_config_t CY_EINK_Ssel_config;
extern const cy_stc_gpio_pin_config_t LED9_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_0_config;
extern const cy_stc_gpio_pin_config_t GREEN_LED_config;
extern const cy_stc_gpio_pin_config_t LED8_config;
extern const cy_stc_gpio_pin_config_t KIT_UART_RX_config;
extern const cy_stc_gpio_pin_config_t KIT_UART_TX_config;
extern const cy_stc_gpio_pin_config_t CY_EINK_DispRst_config;
extern const cy_stc_gpio_pin_config_t CY_EINK_DispBusy_config;
extern const cy_stc_gpio_pin_config_t CY_EINK_DispEn_config;
extern const cy_stc_gpio_pin_config_t CY_EINK_Discharge_config;
extern const cy_stc_gpio_pin_config_t CY_EINK_Border_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_4_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_6_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_7_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_1_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_2_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_7_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_1_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_2_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_3_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_4_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_5_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_6_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_7_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_2_config;

void init_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PINS_H */
