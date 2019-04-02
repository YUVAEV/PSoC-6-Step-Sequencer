/*******************************************************************************
* File Name: cycfg_dmas.c
*
* Description:
* DMA configuration
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

#include "cycfg_dmas.h"

const cy_stc_dma_descriptor_config_t DAC_DMA_Descriptor_0_config = 
{
	.retrigger = CY_DMA_RETRIG_IM,
	.interruptType = CY_DMA_1ELEMENT,
	.triggerOutType = CY_DMA_DESCR_CHAIN,
	.channelState = CY_DMA_CHANNEL_ENABLED,
	.triggerInType = CY_DMA_1ELEMENT,
	.dataSize = CY_DMA_HALFWORD,
	.srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
	.dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
	.descriptorType = CY_DMA_SINGLE_TRANSFER,
	.srcAddress = NULL,
	.dstAddress = NULL,
	.srcXincrement = 0,
	.dstXincrement = 0,
	.xCount = 1,
	.srcYincrement = 0,
	.dstYincrement = 0,
	.yCount = 1,
	.nextDescriptor = NULL,
};
cy_stc_dma_descriptor_t DAC_DMA_Descriptor_0 = 
{
	.ctl = 0UL,
	.src = 0UL,
	.dst = 0UL,
	.xCtl = 0UL,
	.yCtl = 0UL,
	.nextPtr = 0UL,
};
const cy_stc_dma_channel_config_t DAC_DMA_channelConfig = 
{
	.descriptor = &DAC_DMA_Descriptor_0,
	.preemptable = false,
	.priority = 3,
	.enable = false,
	.bufferable = false,
};

