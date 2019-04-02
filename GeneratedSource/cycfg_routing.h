/*******************************************************************************
* File Name: cycfg_routing.h
*
* Description:
* Establishes all necessary connections between hardware elements.
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

#if !defined(CYCFG_ROUTING_H)
#define CYCFG_ROUTING_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "cycfg_notices.h"
void init_cycfg_routing(void);
#define init_cycfg_connectivity() init_cycfg_routing()
#define ioss_0_port_12_pin_0_HSIOM P12_0_SCB6_SPI_MOSI
#define ioss_0_port_12_pin_1_HSIOM P12_1_SCB6_SPI_MISO
#define ioss_0_port_12_pin_2_HSIOM P12_2_SCB6_SPI_CLK
#define ioss_0_port_1_pin_0_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_5_pin_0_HSIOM P5_0_SCB5_UART_RX
#define ioss_0_port_5_pin_1_HSIOM P5_1_SCB5_UART_TX
#define ioss_0_port_6_pin_4_HSIOM P6_4_CPUSS_SWJ_SWO_TDO
#define ioss_0_port_6_pin_6_HSIOM P6_6_CPUSS_SWJ_SWDIO_TMS
#define ioss_0_port_6_pin_7_HSIOM P6_7_CPUSS_SWJ_SWCLK_TCLK
#define ioss_0_port_7_pin_1_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_7_pin_2_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_7_pin_7_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_8_pin_1_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_8_pin_2_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_8_pin_3_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_8_pin_4_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_8_pin_5_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_8_pin_6_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_8_pin_7_HSIOM HSIOM_SEL_AMUXA

#define DAC_DMA_tr_in_0_TRIGGER_OUT TRIG0_OUT_CPUSS_DW0_TR_IN0
#define KIT_DAC_tr_ctdac_empty_0_TRIGGER_IN_0 TRIG0_IN_TR_GROUP14_OUTPUT1
#define KIT_DAC_tr_ctdac_empty_0_TRIGGER_IN_1 TRIG14_IN_PASS_TR_CTDAC_EMPTY

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_ROUTING_H */
