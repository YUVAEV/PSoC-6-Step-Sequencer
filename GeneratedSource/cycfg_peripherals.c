/*******************************************************************************
* File Name: cycfg_peripherals.c
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

#include "cycfg_peripherals.h"

cy_stc_csd_context_t cy_csd_0_context = 
{
	.lockKey = CY_CSD_NONE_KEY,
};
const cy_stc_sysanalog_config_t AREF_config = 
{
	.startup = CY_SYSANALOG_STARTUP_FAST,
	.iztat = CY_SYSANALOG_IZTAT_SOURCE_LOCAL,
	.vref = CY_SYSANALOG_VREF_SOURCE_LOCAL_1_2V,
	.deepSleep = CY_SYSANALOG_DEEPSLEEP_DISABLE,
};
const cy_stc_ctb_opamp_config_t DAC_BUFF_config = 
{
	.oaPower = CY_CTB_POWER_MEDIUM,
	.oaMode = CY_CTB_MODE_OPAMP10X,
	.oaPump = CY_CTB_PUMP_ENABLE,
	.oaCompEdge = CY_CTB_COMP_EDGE_BOTH,
	.oaCompLevel = CY_CTB_COMP_DSI_TRIGGER_OUT_PULSE,
	.oaCompBypass = CY_CTB_COMP_BYPASS_SYNC,
	.oaCompHyst = CY_CTB_COMP_HYST_DISABLE,
	.oaCompIntrEn = false,
};
const cy_stc_ctdac_config_t KIT_DAC_config = 
{
	.refSource = CY_CTDAC_REFSOURCE_VDDA,
	.formatMode = CY_CTDAC_FORMAT_SIGNED,
	.updateMode = CY_CTDAC_UPDATE_BUFFERED_WRITE,
	.deglitchMode = CY_CTDAC_DEGLITCHMODE_BUFFERED,
	.outputMode = CY_CTDAC_OUTPUT_VALUE,
	.outputBuffer = CY_CTDAC_OUTPUT_BUFFERED,
	.deepSleep = CY_CTDAC_DEEPSLEEP_DISABLE,
	.deglitchCycles = 0,
	.value = 0,
	.nextValue = 0,
	.enableInterrupt = true,
	.configClock = false,
	.dividerType = 0,
	.dividerNum = 0,
	.dividerIntValue = 0,
	.dividerFracValue = 0,
};
const cy_stc_scb_uart_config_t UART_config = 
{
	.uartMode = CY_SCB_UART_STANDARD,
	.enableMutliProcessorMode = false,
	.smartCardRetryOnNack = false,
	.irdaInvertRx = false,
	.irdaEnableLowPowerReceiver = false,
	.oversample = 8,
	.enableMsbFirst = false,
	.dataWidth = 8UL,
	.parity = CY_SCB_UART_PARITY_NONE,
	.stopBits = CY_SCB_UART_STOP_BITS_1,
	.enableInputFilter = false,
	.breakWidth = 11UL,
	.dropOnFrameError = false,
	.dropOnParityError = false,
	.receiverAddress = 0x0UL,
	.receiverAddressMask = 0x0UL,
	.acceptAddrInFifo = false,
	.enableCts = false,
	.ctsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rtsRxFifoLevel = 0UL,
	.rtsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rxFifoTriggerLevel = 63UL,
	.rxFifoIntEnableMask = 0UL,
	.txFifoTriggerLevel = 63UL,
	.txFifoIntEnableMask = 0UL,
};
const cy_stc_scb_spi_config_t CY_EINK_SPIM_config = 
{
	.spiMode = CY_SCB_SPI_MASTER,
	.subMode = CY_SCB_SPI_MOTOROLA,
	.sclkMode = CY_SCB_SPI_CPHA0_CPOL0,
	.oversample = 4,
	.rxDataWidth = 8UL,
	.txDataWidth = 8UL,
	.enableMsbFirst = true,
	.enableInputFilter = false,
	.enableFreeRunSclk = false,
	.enableMisoLateSample = false,
	.enableTransferSeperation = false,
	.ssPolarity = ((CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT0) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT1) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT2) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT3)),
	.enableWakeFromSleep = false,
	.rxFifoTriggerLevel = 63UL,
	.rxFifoIntEnableMask = 0UL,
	.txFifoTriggerLevel = 63UL,
	.txFifoIntEnableMask = 0UL,
	.masterSlaveIntEnableMask = 0UL,
};


void init_cycfg_peripherals(void)
{
	Cy_SysClk_PeriphAssignDivider(PCLK_CSD_CLOCK, CY_SYSCLK_DIV_8_BIT, 2U);

	Cy_SysClk_PeriphAssignDivider(PCLK_PASS_CLOCK_PUMP_PERI, CY_SYSCLK_DIV_8_BIT, 3U);
	Cy_CTB_SetDeepSleepMode(CTBM0, CY_CTB_DEEPSLEEP_DISABLE);

	Cy_SysClk_PeriphAssignDivider(PCLK_PASS_CLOCK_CTDAC, CY_SYSCLK_DIV_16_BIT, 0U);

	Cy_SysClk_PeriphAssignDivider(PCLK_SCB5_CLOCK, CY_SYSCLK_DIV_8_BIT, 0U);

	Cy_SysClk_PeriphAssignDivider(PCLK_SCB6_CLOCK, CY_SYSCLK_DIV_8_BIT, 1U);
}
