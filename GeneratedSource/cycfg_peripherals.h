/*******************************************************************************
* File Name: cycfg_peripherals.h
*
* Description:
* Peripheral Hardware Block configuration
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

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_sysclk.h"
#include "cy_csd.h"
#include "cy_sysanalog.h"
#include "cy_ctb.h"
#include "cy_ctdac.h"
#include "cy_scb_uart.h"
#include "cy_scb_spi.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define CY_CAPSENSE_CORE 4u
#define CY_CAPSENSE_CPU_CLK 144000000u
#define CY_CAPSENSE_PERI_CLK 72000000u
#define CY_CAPSENSE_VDDA_MV 3300u
#define CY_CAPSENSE_PERI_DIV_TYPE CY_SYSCLK_DIV_8_BIT
#define CY_CAPSENSE_PERI_DIV_INDEX 2u
#define Cmod_PORT GPIO_PRT7
#define CintA_PORT GPIO_PRT7
#define CintB_PORT GPIO_PRT7
#define Button0_Rx0_PORT GPIO_PRT8
#define Button0_Tx_PORT GPIO_PRT1
#define Button1_Rx0_PORT GPIO_PRT8
#define LinearSlider0_Sns0_PORT GPIO_PRT8
#define LinearSlider0_Sns1_PORT GPIO_PRT8
#define LinearSlider0_Sns2_PORT GPIO_PRT8
#define LinearSlider0_Sns3_PORT GPIO_PRT8
#define LinearSlider0_Sns4_PORT GPIO_PRT8
#define Cmod_PIN 7u
#define CintA_PIN 1u
#define CintB_PIN 2u
#define Button0_Rx0_PIN 1u
#define Button0_Tx_PIN 0u
#define Button1_Rx0_PIN 2u
#define LinearSlider0_Sns0_PIN 3u
#define LinearSlider0_Sns1_PIN 4u
#define LinearSlider0_Sns2_PIN 5u
#define LinearSlider0_Sns3_PIN 6u
#define LinearSlider0_Sns4_PIN 7u
#define Cmod_PORT_NUM 7u
#define CintA_PORT_NUM 7u
#define CintB_PORT_NUM 7u
#define CapSense_HW CSD0
#define CapSense_IRQ csd_interrupt_IRQn
#define DAC_BUFF_HW CTBM0
#define KIT_DAC_HW CTDAC0
#define UART_HW SCB5
#define UART_IRQ scb_5_interrupt_IRQn
#define CY_EINK_SPIM_HW SCB6
#define CY_EINK_SPIM_IRQ scb_6_interrupt_IRQn

extern cy_stc_csd_context_t cy_csd_0_context;
extern const cy_stc_sysanalog_config_t AREF_config;
extern const cy_stc_ctb_opamp_config_t DAC_BUFF_config;
extern const cy_stc_ctdac_config_t KIT_DAC_config;
extern const cy_stc_scb_uart_config_t UART_config;
extern const cy_stc_scb_spi_config_t CY_EINK_SPIM_config;

void init_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PERIPHERALS_H */
