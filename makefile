# ==========================
# Project Configuration
# ==========================

TARGET = main

MCU = atmega328p
F_CPU = 16000000UL

PORT = COM7
BAUD = 115200

# ==========================
# Toolchain
# ==========================

CC = avr-gcc
OBJCOPY = avr-objcopy
SIZE = avr-size

AVRDUDE = "C:/Users/SIDDARTH/AppData/Local/Arduino15/packages/arduino/tools/avrdude/8.0.0-arduino1/bin/avrdude.exe"
AVRCONF = "C:/Users/SIDDARTH/AppData/Local/Arduino15/packages/arduino/tools/avrdude/8.0.0-arduino1/etc/avrdude.conf"

# ==========================
# Compiler Options
# ==========================

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Wall -Os -IInc

SRC = main.c Src/gpio.c  Src/uart.c

# ==========================
# Build
# ==========================

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex
	$(SIZE) $(TARGET).elf

# ==========================
# Upload
# ==========================

flash:
	$(AVRDUDE) -C $(AVRCONF) -p m328p -c arduino -P $(PORT) -b $(BAUD) -D -U flash:w:$(TARGET).hex:i

# ==========================
# Clean
# ==========================

clean:
	del /Q *.elf *.hex