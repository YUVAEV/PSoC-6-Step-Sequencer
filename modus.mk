################################################################################
# \file modus.mk
# \version 1.0
#
# \brief
# This file has two purposes.
# - The first purpose is to provide information to the makefile build system.
# - The second purpose is to provide information to any IDE about the example.
#   Therefore, this file should not contain anything other than make variables.
#
################################################################################
# \copyright
# Copyright 2018-2019 Cypress Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
################################################################################

#
# Toolchain, its optimization level and the configuration (Debug/Release) type
#
TOOLCHAIN=GCC
OPTIMIZATION = Og
CONFIG = Debug

# Define custom linker script location (<ABSOLUTE PATH>/customScript.ld)
# CY_MAINAPP_CM0P_LINKER_SCRIPT=
# CY_MAINAPP_CM4_LINKER_SCRIPT=

#
# Vector Floating-point flag (soft/hard) selection
# 
VFP_FLAG = soft

#
# The target platform for the example
#
PLATFORMS_VERSION = 1.0
PLATFORM=PSOC6_DUAL_CORE

#
# The default name of this example
#
CY_EXAMPLE_NAME = SequencerX

#
# Description of the example project to display
#
CY_EXAMPLE_DESCRIPTION = 

#
# New project dialog inclusion
#
CY_SHOW_NEW_PROJECT = true

#
# Valid platforms for this example
#
CY_VALID_PLATFORMS = PSOC6_DUAL_CORE PSOC6_SINGLE_CORE

#
# This is the required SDK for this example
#
CY_REQUIRED_SDK = Cypress SDK[1.1]

#
# Valid devices for this example. If empty, this example works for all devices
#
CY_VALID_DEVICES = CY8C6347BZI-BLD53

#
# The source code for the CM0+ application
#
CY_APP_CM0P_SOURCE = \

#
# The source code for the CM4 application
#
CY_APP_CM4_SOURCE = \
	Source/cy_cy8ckit_028_epd/cy_cy8ckit_028_epd.c \
	Source/cy_cy8ckit_028_epd/cy_cy8ckit_028_epd.h \
	Source/cy_cy8ckit_028_epd/cy_eink_psoc_interface.c \
	Source/cy_cy8ckit_028_epd/cy_eink_psoc_interface.h \
	Source/cy_cy8ckit_028_epd/pervasive_eink_configuration.h \
	Source/cy_cy8ckit_028_epd/pervasive_eink_hardware_driver.c \
	Source/cy_cy8ckit_028_epd/pervasive_eink_hardware_driver.h \
	Source/emWin_config/GUI_X.c \
	Source/emWin_config/GUIConf.c \
	Source/emWin_config/LCDConf.c \
	Source/emWin_config/LCDConf.h \
	Source/main.c\
	Source/hw_functions.c\
	Source/hw_functions.h\
	Source/gui_functions.c\
	Source/gui_functions.h\
	Source/sound_samples.h\
	Source/stdio_user.c\
	Source/stdio_user.h

#
# Paths to use for ModusToolbox IDE 
#
CY_LOCAL_INCLUDE_CM0P = $(CY_GENERATED_DIR)/$(CYMAINAPP_CM0P_NAME)
CY_LOCAL_INCLUDE_CM4 = $(CY_GENERATED_DIR)/$(CYMAINAPP_CM4_NAME)

#
# Includes specific to the CM0+ application
#
APP_MAINAPP_CM0P_INCLUDES = \
	-IGeneratedSource\

#
# Includes specific to the CM4 application
#
APP_MAINAPP_CM4_INCLUDES = \
	-IGeneratedSource\
	-I$(CY_LOCAL_INCLUDE_CM4)/Source

#
# Compiler flags specific to the CM0+ application
#
APP_MAINAPP_CM0P_FLAGS =

#
# Compiler flags specific to the CM4 application
#
APP_MAINAPP_CM4_FLAGS =

#
# Defines specific to the CM0+ application
#
APP_MAINAPP_CM0P_DEFINES = \
	-DAPP_NAME='"$(CY_EXAMPLE_NAME)_cm0p"'

#
# Defines specific to the CM4 application
#
APP_MAINAPP_CM4_DEFINES = \
	-DAPP_NAME='"$(CY_EXAMPLE_NAME)_cm4"'

#
# Software components needed by CM0+
#
CY_MAINAPP_CM0P_SWCOMP_USED = \

#
# Software components needed by CM4
#
CY_MAINAPP_SWCOMP_USED= \
    psoc6sw-1.1/components/psoc6mw/emWin/code/include/nosnts_softfp \
    psoc6sw-1.1/components/psoc6mw/emWin/code/drivers/BitPlains \
    psoc6sw-1.1/components/psoc6mw/capsense/softfp \
    psoc6sw-1.1/components/psoc6pdl/utilities/retarget_io \
    psoc6sw-1.1/components/psoc6pdl/devices/psoc6/cm0p/prebuilt

CY_MAINAPP_SWCOMP_EXT= \
    psoc6sw-1.1/components/psoc6pdl/utilities/retarget_io/user\
    psoc6sw-1.1/components/psoc6mw/emWin/code/drivers/BitPlains/config\
    psoc6sw-1.1/components/psoc6mw/emWin/code/config/nos

#
# Other libraries (.a) needed by the CM0+ application
#
APP_MAINAPP_CM0P_LIBS = \

#
# Other libraries (.a) needed by the CM4 application
#
APP_MAINAPP_CM4_LIBS = \

#
# The path to the design.modus file
#
CYCONFIG_DESIGN_MODUS = design.modus

#
# Additional (non-core) set of generated source files
#
CYCONFIG_GENERATED_SOURCES = \
	GeneratedSource/cycfg_capsense.c\
	GeneratedSource/cycfg_capsense.h

#
# Check that the CYSDK environment variable exists
#
ifndef CYSDK
$(error The SDK must be defined via the CYSDK environment variable)
endif

#
# Include the main makefile for building this type of example
#
include $(CYSDK)/libraries/platforms-$(PLATFORMS_VERSION)/common/find_platform.mk
