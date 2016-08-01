# TARGET #

TARGET := WIIU
LIBRARY := 0

ifeq ($(TARGET),$(filter $(TARGET),3DS WIIU))
    ifeq ($(strip $(DEVKITPRO)),)
        $(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPro")
    endif
endif

# COMMON CONFIGURATION #

NAME := helloworld

TITLE := Hello World
AUTHOR := brienj
VERSION := 1337
SHORT_DESCRIPTION := Hello World
LONG_DESCRIPTION := Hello World built with libcafe
ICON := icon.png

BUILD_DIR := build
OUTPUT_DIR := output
INCLUDE_DIRS := source \
				$(DEVKITPRO)/libcafe
				
SOURCE_DIRS := source

EXTRA_OUTPUT_FILES :=

LIBRARY_DIRS := $(DEVKITPRO)/libcafe
LIBRARIES := cafe

BUILD_FLAGS :=
RUN_FLAGS :=

# INTERNAL #

include buildtools/make_base
