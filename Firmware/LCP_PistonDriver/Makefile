## Author : Basharat, Basharat
## Email  : Basharat.martin@noaa.gov
## Dated  : 11/10/2022

TARGET=LCPPistonDriver.elf
MAP=LCPPistonDriver.map
RM=rm

GCC_DIR = $(GCC_MSP_ROOT)
GCC_INCLUDE = $(GCC_DIR)/include

# Please set your device here
DEVICE  = MSP430FR5989
CC      = msp430-elf-gcc
GDB     = msp430-elf-gdb
FLASH	= msp430-elf-debug

ROOT	= .
SRC_DIR = $(ROOT)/src
INC_DIR = $(ROOT)/include

SRCS :=	main.c \
		$(wildcard $(SRC_DIR)/bsp/*.c) \
		$(wildcard $(SRC_DIR)/*.c) \
		$(wildcard $(SRC_DIR)/system/*.c) \
		$(wildcard $(ROOT)/driverlib/*.c)
	
INCS := -I $(INC_DIR) \
		-I $(INC_DIR)/system \
		-I $(INC_DIR)/bsp \
		-I $(ROOT)/driverlib

OBJECTS := $(SRCS:.c=.o)

CFLAGS = -I $(GCC_INCLUDE) $(INCS) -D__$(DEVICE)__ -mmcu=$(DEVICE) -mlarge -mcode-region=either -mdata-region=either -Os -Wall -g0 -ffunction-sections -fdata-sections
LFLAGS = -L $(GCC_INCLUDE) -D__$(DEVICE)__ -mmcu=$(DEVICE) -mlarge -mcode-region=either -mdata-region=either -Wl,-Map,$(MAP),--gc-sections

all: ${OBJECTS}
	$(CC) $(LFLAGS) $? -o $(TARGET)

%.o: %.c
	@echo ============================================
	@echo Compiling $<
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJECTS)
	$(RM) $(MAP)
	$(RM) $(TARGET)

flash:
	$(FLASH) tilib "prog $(TARGET)"

debug: all
	$(GDB) $(TARGET)
