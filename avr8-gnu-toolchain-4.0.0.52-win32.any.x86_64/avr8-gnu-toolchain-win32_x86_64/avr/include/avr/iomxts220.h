/*
 * Copyright (C) 2023, Microchip Technology Inc. and its subsidiaries ("Microchip")
 * All rights reserved.
 *
 * This software is developed by Microchip Technology Inc. and its subsidiaries ("Microchip").
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *     1. Redistributions of source code must retain the above copyright notice, this list of
 *        conditions and the following disclaimer.
 *
 *     2. Redistributions in binary form must reproduce the above copyright notice, this list
 *        of conditions and the following disclaimer in the documentation and/or other
 *        materials provided with the distribution. Publication is not required when
 *        this file is used in an embedded application.
 *
 *     3. Microchip's name may not be used to endorse or promote products derived from this
 *        software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iomxts220.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_ATMXTS220_H_INCLUDED
#define _AVR_ATMXTS220_H_INCLUDED

/* Ungrouped common registers */
#define GPIOR0  _SFR_MEM8(0x0000)  /* General Purpose IO Register 0 */
#define GPIOR1  _SFR_MEM8(0x0001)  /* General Purpose IO Register 1 */
#define GPIOR2  _SFR_MEM8(0x0002)  /* General Purpose IO Register 2 */
#define GPIOR3  _SFR_MEM8(0x0003)  /* General Purpose IO Register 3 */

/* Deprecated */
#define GPIO0  _SFR_MEM8(0x0000)  /* General Purpose IO Register 0 */
#define GPIO1  _SFR_MEM8(0x0001)  /* General Purpose IO Register 1 */
#define GPIO2  _SFR_MEM8(0x0002)  /* General Purpose IO Register 2 */
#define GPIO3  _SFR_MEM8(0x0003)  /* General Purpose IO Register 3 */

#define CCP  _SFR_MEM8(0x0034)  /* Configuration Change Protection */
#define RAMPD  _SFR_MEM8(0x0038)  /* Ramp D */
#define RAMPX  _SFR_MEM8(0x0039)  /* Ramp X */
#define RAMPY  _SFR_MEM8(0x003A)  /* Ramp Y */
#define RAMPZ  _SFR_MEM8(0x003B)  /* Ramp Z */
#define EIND  _SFR_MEM8(0x003C)  /* Extended Indirect Jump */
#define SPL  _SFR_MEM8(0x003D)  /* Stack Pointer Low */
#define SPH  _SFR_MEM8(0x003E)  /* Stack Pointer High */
#define SREG  _SFR_MEM8(0x003F)  /* Status Register */

/* C Language Only */
#if !defined (__ASSEMBLER__)

#include <stdint.h>

typedef volatile uint8_t register8_t;
typedef volatile uint16_t register16_t;
typedef volatile uint32_t register32_t;


#ifdef _WORDREGISTER
#undef _WORDREGISTER
#endif
#define _WORDREGISTER(regname)   \
    __extension__ union \
    { \
        register16_t regname; \
        struct \
        { \
            register8_t regname ## L; \
            register8_t regname ## H; \
        }; \
    }

#ifdef _DWORDREGISTER
#undef _DWORDREGISTER
#endif
#define _DWORDREGISTER(regname)  \
    __extension__ union \
    { \
        register32_t regname; \
        struct \
        { \
            register8_t regname ## 0; \
            register8_t regname ## 1; \
            register8_t regname ## 2; \
            register8_t regname ## 3; \
        }; \
    }


/*
==========================================================================
IO Module Structures
==========================================================================
*/


/*
--------------------------------------------------------------------------
ADC_CMN - ADC Common Settings
--------------------------------------------------------------------------
*/

/* ADC Common Settings */
typedef struct ADC_CMN_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t EVSEL;  /* Event select register */
    register8_t PORTCTRL;  /* Port control register */
    register8_t PRESCALER;  /* Prescaler Register */
    register8_t reserved_1[1];
    register8_t INTCTRL;  /* Sensor Settling Interrupt Control Register */
    register8_t INTSTATUS;  /* Sensor Settling Interrupt Status Register */
    register8_t CHSTATUS;  /* Channel Status Register */
    register8_t THRESHOLD;  /* Threshold Register */
    register8_t reserved_2[2];
    register8_t CAL;  /* Calibration value register */
    register8_t reserved_3[3];
} ADC_CMN_t;


/*
--------------------------------------------------------------------------
ADC_GEN_CH - ADC General Channel
--------------------------------------------------------------------------
*/

/* ADC General Channel */
typedef struct ADC_GEN_CH_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t SAMPCTRL;  /* Sampling time control register */
    register8_t MUXCTRL;  /* MUX Control Register */
    register8_t INTCTRL;  /* Interrupt control register */
    register8_t reserved_1[1];
    register8_t INTSTATUS;  /* Interrupt status register */
    register8_t RESL;  /* Result register low */
    register8_t RESH;  /* Result register high */
    register8_t REFCTRL;  /* Reference control */
    register8_t RESHTMP;  /* Temporary result register high */
    register8_t reserved_2[6];
} ADC_GEN_CH_t;


/*
--------------------------------------------------------------------------
BANDGAP - Bandgap
--------------------------------------------------------------------------
*/

/* Bandgap */
typedef struct BANDGAP_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t reserved_1[1];
} BANDGAP_t;


/*
--------------------------------------------------------------------------
BIASCTRL - BIASCTRL
--------------------------------------------------------------------------
*/

/* BIASCTRL */
typedef struct BIASCTRL_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t reserved_1[1];
} BIASCTRL_t;


/*
--------------------------------------------------------------------------
BOOSTIF - Boost Converter Interface
--------------------------------------------------------------------------
*/

/* Boost Converter Interface */
typedef struct BOOSTIF_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t LEVEL;  /* Voltage Level */
    register8_t CNTHIGH;  /* High-period Cycle Count */
    register8_t CNTLOW;  /* Low-period Cycle Count */
    register8_t TEST;  /* Test Register */
    register8_t SETTLE;  /* Analog Settle Time */
    register8_t reserved_1[1];
} BOOSTIF_t;


/*
--------------------------------------------------------------------------
CLK - Clock System
--------------------------------------------------------------------------
*/

/* Clock System */
typedef struct CLK_struct
{
    register8_t CLKPSR;  /* Clock Prescaler Register */
    register8_t CLKSLR;  /* Prescaler Settings Lock Register */
    register8_t reserved_1[2];
    register8_t FRCCALL;  /* Fast RC Oscillator Calibration Low Byte */
    register8_t FRCCALH;  /* Fast RC Oscillator Calibration High Byte */
    register8_t ULPRCCALL;  /* Ulp RC Oscillator Calibration LSB */
    register8_t ULPRCCALH;  /* Ulp RC Oscillator Calibration MSB */
    register8_t reserved_2[8];
} CLK_t;

/* Clock Prescaler Division Factor  */
typedef enum CLK_CLKPS_enum
{
    CLK_CLKPS_CLKPS_DIV1_gc = (0x00<<0),  /* No division */
    CLK_CLKPS_CLKPS_DIV2_gc = (0x01<<0),  /* Divide system oscillator with 2 */
    CLK_CLKPS_CLKPS_DIV4_gc = (0x02<<0),  /* Divide system oscillator with 4 */
    CLK_CLKPS_CKLPS_DIV8_gc = (0x03<<0),  /* Divide system oscillator with 8 */
} CLK_CLKPS_t;

/*
--------------------------------------------------------------------------
CPU - CPU
--------------------------------------------------------------------------
*/

/* CCP signatures */
typedef enum CCP_enum
{
    CCP_SPM_gc = (0x9D<<0),  /* SPM Instruction Protection */
    CCP_IOREG_gc = (0xD8<<0),  /* IO Register Protection */
} CCP_t;

/*
--------------------------------------------------------------------------
CRC4 - Cyclic Redundancy Checker
--------------------------------------------------------------------------
*/

/* Cyclic Redundancy Checker */
typedef struct CRC4_struct
{
    register8_t DATAIN;  /* Data Input */
    register8_t CHECKSUM;  /* Checksum */
    register8_t reserved_1[2];
} CRC4_t;


/*
--------------------------------------------------------------------------
FUSES - Fuses and Lockbits
--------------------------------------------------------------------------
*/

/* Fuses */
typedef struct NVM_FUSES_struct
{
    register8_t reserved_1[4];
    register8_t FUSEBYTE4;  /* Start-up Configuration */
    register8_t FUSEBYTE5;  /* Non-Volatile Memory Fuse Byte 5 */
    register8_t FUSEBYTE6;  /* Non-Volatile Memory Fuse Byte 6 */
    register8_t reserved_2[3];
} NVM_FUSES_t;


/* Lockbits */
typedef struct NVM_LOCKBITS_struct
{
    register8_t LOCK_BITS;  /* Lock Bits (Changed from LOCKBITS to avoid avr-libc collision) */
} NVM_LOCKBITS_t;

/* Boot Loader Section Reset Vector */
typedef enum FUSES_NVM_FUSES_BOOTRST_enum
{
    FUSES_NVM_FUSES_BOOTRST_BOOTLDR_gc = (0x00<<5),  /* Boot Loader Reset */
    FUSES_NVM_FUSES_BOOTRST_APPLICATION_gc = (0x01<<5),  /* Application Reset */
} FUSES_NVM_FUSES_BOOTRST_t;

/* Start-up Time */
typedef enum FUSES_NVM_FUSES_SUT_enum
{
    FUSES_NVM_FUSES_SUT_512MS_gc = (0x00<<2),  /* 512 ms */
    FUSES_NVM_FUSES_SUT_64MS_gc = (0x01<<2),  /* 64 ms */
    FUSES_NVM_FUSES_SUT_4MS_gc = (0x02<<2),  /* 4 ms */
    FUSES_NVM_FUSES_SUT_0MS_gc = (0x03<<2),  /* 0 ms */
} FUSES_NVM_FUSES_SUT_t;

/* Watchdog (Window) Timeout Period */
typedef enum FUSES_NVM_FUSES_WDPER_enum
{
    FUSES_NVM_FUSES_WDPER_8CLK_gc = (0x00<<0),  /* 8 cycles (8ms ) */
    FUSES_NVM_FUSES_WDPER_16CLK_gc = (0x01<<0),  /* 16 cycles (16ms ) */
    FUSES_NVM_FUSES_WDPER_32CLK_gc = (0x02<<0),  /* 32 cycles (32ms ) */
    FUSES_NVM_FUSES_WDPER_64CLK_gc = (0x03<<0),  /* 64 cycles (64ms ) */
    FUSES_NVM_FUSES_WDPER_128CLK_gc = (0x04<<0),  /* 128 cycles (0.125s ) */
    FUSES_NVM_FUSES_WDPER_256CLK_gc = (0x05<<0),  /* 256 cycles (0.25s ) */
    FUSES_NVM_FUSES_WDPER_512CLK_gc = (0x06<<0),  /* 512 cycles (0.5s ) */
    FUSES_NVM_FUSES_WDPER_1KCLK_gc = (0x07<<0),  /* 1K cycles (1s ) */
    FUSES_NVM_FUSES_WDPER_2KCLK_gc = (0x08<<0),  /* 2K cycles (2s ) */
    FUSES_NVM_FUSES_WDPER_4KCLK_gc = (0x09<<0),  /* 4K cycles (4s ) */
    FUSES_NVM_FUSES_WDPER_8KCLK_gc = (0x0A<<0),  /* 8K cycles (8s ) */
} FUSES_NVM_FUSES_WDPER_t;

/* Watchdog (Window) Timeout Period */
typedef enum FUSES_NVM_FUSES_WDWPER_enum
{
    FUSES_NVM_FUSES_WDWPER_8CLK_gc = (0x00<<4),  /* 8 cycles (8ms ) */
    FUSES_NVM_FUSES_WDWPER_16CLK_gc = (0x01<<4),  /* 16 cycles (16ms ) */
    FUSES_NVM_FUSES_WDWPER_32CLK_gc = (0x02<<4),  /* 32 cycles (32ms ) */
    FUSES_NVM_FUSES_WDWPER_64CLK_gc = (0x03<<4),  /* 64 cycles (64ms ) */
    FUSES_NVM_FUSES_WDWPER_128CLK_gc = (0x04<<4),  /* 128 cycles (0.125s ) */
    FUSES_NVM_FUSES_WDWPER_256CLK_gc = (0x05<<4),  /* 256 cycles (0.25s ) */
    FUSES_NVM_FUSES_WDWPER_512CLK_gc = (0x06<<4),  /* 512 cycles (0.5s ) */
    FUSES_NVM_FUSES_WDWPER_1KCLK_gc = (0x07<<4),  /* 1K cycles (1s ) */
    FUSES_NVM_FUSES_WDWPER_2KCLK_gc = (0x08<<4),  /* 2K cycles (2s ) */
    FUSES_NVM_FUSES_WDWPER_4KCLK_gc = (0x09<<4),  /* 4K cycles (4s ) */
    FUSES_NVM_FUSES_WDWPER_8KCLK_gc = (0x0A<<4),  /* 8K cycles (8s ) */
} FUSES_NVM_FUSES_WDWPER_t;

/* Boot lock bits - application section */
typedef enum FUSES_NVM_LOCKBITS_BLBA_enum
{
    FUSES_NVM_LOCKBITS_BLBA_RWLOCK_gc = (0x00<<4),  /* Read and write not allowed */
    FUSES_NVM_LOCKBITS_BLBA_RLOCK_gc = (0x01<<4),  /* Read not allowed */
    FUSES_NVM_LOCKBITS_BLBA_WLOCK_gc = (0x02<<4),  /* Write not allowed */
    FUSES_NVM_LOCKBITS_BLBA_NOLOCK_gc = (0x03<<4),  /* No locks */
} FUSES_NVM_LOCKBITS_BLBA_t;

/* Boot lock bits - application table section */
typedef enum FUSES_NVM_LOCKBITS_BLBAT_enum
{
    FUSES_NVM_LOCKBITS_BLBAT_RWLOCK_gc = (0x00<<2),  /* Read and write not allowed */
    FUSES_NVM_LOCKBITS_BLBAT_RLOCK_gc = (0x01<<2),  /* Read not allowed */
    FUSES_NVM_LOCKBITS_BLBAT_WLOCK_gc = (0x02<<2),  /* Write not allowed */
    FUSES_NVM_LOCKBITS_BLBAT_NOLOCK_gc = (0x03<<2),  /* No locks */
} FUSES_NVM_LOCKBITS_BLBAT_t;

/* Boot lock bits - boot setcion */
typedef enum FUSES_NVM_LOCKBITS_BLBB_enum
{
    FUSES_NVM_LOCKBITS_BLBB_RWLOCK_gc = (0x00<<6),  /* Read and write not allowed */
    FUSES_NVM_LOCKBITS_BLBB_RLOCK_gc = (0x01<<6),  /* Read not allowed */
    FUSES_NVM_LOCKBITS_BLBB_WLOCK_gc = (0x02<<6),  /* Write not allowed */
    FUSES_NVM_LOCKBITS_BLBB_NOLOCK_gc = (0x03<<6),  /* No locks */
} FUSES_NVM_LOCKBITS_BLBB_t;

/* Lock bits */
typedef enum FUSES_NVM_LOCKBITS_LB_enum
{
    FUSES_NVM_LOCKBITS_LB_RWLOCK_gc = (0x00<<0),  /* Read and write not allowed */
    FUSES_NVM_LOCKBITS_LB_WLOCK_gc = (0x02<<0),  /* Write not allowed */
    FUSES_NVM_LOCKBITS_LB_NOLOCK_gc = (0x03<<0),  /* No locks */
} FUSES_NVM_LOCKBITS_LB_t;

/*
--------------------------------------------------------------------------
LDO - LDO
--------------------------------------------------------------------------
*/

/* LDO */
typedef struct LDO_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t reserved_1[1];
} LDO_t;


/*
--------------------------------------------------------------------------
MCU - MCU Control
--------------------------------------------------------------------------
*/

/* MCU Control */
typedef struct MCU_struct
{
    register8_t DEVID0;  /* Device ID byte 0 */
    register8_t DEVID1;  /* Device ID byte 1 */
    register8_t DEVID2;  /* Device ID byte 2 */
    register8_t REVID;  /* Revision ID */
    register8_t reserved_1[12];
} MCU_t;


/*
--------------------------------------------------------------------------
NVM - Non Volatile Memory Controller
--------------------------------------------------------------------------
*/

/* Non-volatile Memory Controller */
typedef struct NVM_struct
{
    register8_t ADDR0;  /* Address Register 0 */
    register8_t ADDR1;  /* Address Register 1 */
    register8_t ADDR2;  /* Address Register 2 */
    register8_t reserved_1[1];
    register8_t DATA0;  /* Data Register 0 */
    register8_t DATA1;  /* Data Register 1 */
    register8_t DATA2;  /* Data Register 2 */
    register8_t reserved_2[3];
    register8_t CMD;  /* Command */
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t reserved_3[1];
    register8_t STATUS;  /* Status */
    register8_t LOCK_BITS;  /* Lock Bits (Changed from LOCKBITS to avoid avr-libc collision) */
    register8_t reserved_4[15];
} NVM_t;

/* Boot lock bits - application section */
typedef enum NVM_BLBA_enum
{
    NVM_BLBA_RWLOCK_gc = (0x00<<4),  /* Read and write not allowed */
    NVM_BLBA_RLOCK_gc = (0x01<<4),  /* Read not allowed */
    NVM_BLBA_WLOCK_gc = (0x02<<4),  /* Write not allowed */
    NVM_BLBA_NOLOCK_gc = (0x03<<4),  /* No locks */
} NVM_BLBA_t;

/* Boot lock bits - application table section */
typedef enum NVM_BLBAT_enum
{
    NVM_BLBAT_RWLOCK_gc = (0x00<<2),  /* Read and write not allowed */
    NVM_BLBAT_RLOCK_gc = (0x01<<2),  /* Read not allowed */
    NVM_BLBAT_WLOCK_gc = (0x02<<2),  /* Write not allowed */
    NVM_BLBAT_NOLOCK_gc = (0x03<<2),  /* No locks */
} NVM_BLBAT_t;

/* Boot lock bits - boot setcion */
typedef enum NVM_BLBB_enum
{
    NVM_BLBB_RWLOCK_gc = (0x00<<6),  /* Read and write not allowed */
    NVM_BLBB_RLOCK_gc = (0x01<<6),  /* Read not allowed */
    NVM_BLBB_WLOCK_gc = (0x02<<6),  /* Write not allowed */
    NVM_BLBB_NOLOCK_gc = (0x03<<6),  /* No locks */
} NVM_BLBB_t;

/* NVM Command */
typedef enum NVM_CMD_enum
{
    NVM_CMD_NO_OPERATION_gc = (0x00<<0),  /* Noop/Ordinary LPM */
    NVM_CMD_READ_USER_SIG_ROW_gc = (0x01<<0),  /* Read user signature row */
    NVM_CMD_READ_CALIB_ROW_gc = (0x02<<0),  /* Read calibration row */
    NVM_CMD_READ_EEPROM_gc = (0x06<<0),  /* Read EEPROM */
    NVM_CMD_READ_FUSE_gc = (0x07<<0),  /* Read fuse byte */
    NVM_CMD_WRITE_LOCK_BITS_gc = (0x08<<0),  /* Write lock bits */
    NVM_CMD_ERASE_USER_SIG_ROW_gc = (0x18<<0),  /* Erase user signature row */
    NVM_CMD_WRITE_USER_SIG_ROW_gc = (0x1A<<0),  /* Write user signature row */
    NVM_CMD_ERASE_APP_gc = (0x20<<0),  /* Erase Application Section */
    NVM_CMD_ERASE_APP_PAGE_gc = (0x22<<0),  /* Erase Application Section page */
    NVM_CMD_LOAD_FLASH_BUFFER_gc = (0x23<<0),  /* Load Flash page buffer */
    NVM_CMD_WRITE_APP_PAGE_gc = (0x24<<0),  /* Write Application Section page */
    NVM_CMD_ERASE_WRITE_APP_PAGE_gc = (0x25<<0),  /* Erase-and-write Application Section page */
    NVM_CMD_ERASE_FLASH_BUFFER_gc = (0x26<<0),  /* Erase/flush Flash page buffer */
    NVM_CMD_ERASE_BOOT_PAGE_gc = (0x2A<<0),  /* Erase Boot Section page */
    NVM_CMD_ERASE_FLASH_PAGE_gc = (0x2B<<0),  /* Erase Flash Page */
    NVM_CMD_WRITE_BOOT_PAGE_gc = (0x2C<<0),  /* Write Boot Section page */
    NVM_CMD_ERASE_WRITE_BOOT_PAGE_gc = (0x2D<<0),  /* Erase-and-write Boot Section page */
    NVM_CMD_WRITE_FLASH_PAGE_gc = (0x2E<<0),  /* Write Flash Page */
    NVM_CMD_ERASE_WRITE_FLASH_PAGE_gc = (0x2F<<0),  /* Erase-and-write Flash Page */
    NVM_CMD_ERASE_EEPROM_gc = (0x30<<0),  /* Erase EEPROM */
    NVM_CMD_ERASE_EEPROM_PAGE_gc = (0x32<<0),  /* Erase EEPROM page */
    NVM_CMD_LOAD_EEPROM_BUFFER_gc = (0x33<<0),  /* Load EEPROM page buffer */
    NVM_CMD_WRITE_EEPROM_PAGE_gc = (0x34<<0),  /* Write EEPROM page */
    NVM_CMD_ERASE_WRITE_EEPROM_PAGE_gc = (0x35<<0),  /* Erase-and-write EEPROM page */
    NVM_CMD_ERASE_EEPROM_BUFFER_gc = (0x36<<0),  /* Erase/flush EEPROM page buffer */
    NVM_CMD_APP_CRC_gc = (0x38<<0),  /* Application section CRC */
    NVM_CMD_BOOT_CRC_gc = (0x39<<0),  /*  Boot Section CRC */
    NVM_CMD_FLASH_RANGE_CRC_gc = (0x3A<<0),  /* Flash Range CRC */
    NVM_CMD_CHIP_ERASE_gc = (0x40<<0),  /* Erase Chip */
    NVM_CMD_READ_NVM_gc = (0x43<<0),  /* Read NVM */
    NVM_CMD_WRITE_FUSE_gc = (0x4C<<0),  /* Write Fuse byte */
    NVM_CMD_ERASE_BOOT_gc = (0x68<<0),  /* Erase Boot Section */
    NVM_CMD_FLASH_CRC_gc = (0x78<<0),  /* Flash CRC */
} NVM_CMD_t;

/* EEPROM ready interrupt level */
typedef enum NVM_EELVL_enum
{
    NVM_EELVL_OFF_gc = (0x00<<0),  /* Interrupt disabled */
    NVM_EELVL_LO_gc = (0x01<<0),  /* Low level */
    NVM_EELVL_MED_gc = (0x02<<0),  /* Medium level */
    NVM_EELVL_HI_gc = (0x03<<0),  /* High level */
} NVM_EELVL_t;

/* Lock bits */
typedef enum NVM_LB_enum
{
    NVM_LB_RWLOCK_gc = (0x00<<0),  /* Read and write not allowed */
    NVM_LB_WLOCK_gc = (0x02<<0),  /* Write not allowed */
    NVM_LB_NOLOCK_gc = (0x03<<0),  /* No locks */
} NVM_LB_t;

/* SPM ready interrupt level */
typedef enum NVM_SPMLVL_enum
{
    NVM_SPMLVL_OFF_gc = (0x00<<2),  /* Interrupt disabled */
    NVM_SPMLVL_LO_gc = (0x01<<2),  /* Low level */
    NVM_SPMLVL_MED_gc = (0x02<<2),  /* Medium level */
    NVM_SPMLVL_HI_gc = (0x03<<2),  /* High level */
} NVM_SPMLVL_t;

/*
--------------------------------------------------------------------------
PMIC - Programmable Multi-level Interrupt Controller
--------------------------------------------------------------------------
*/

/* Programmable Multi-level Interrupt Controller */
typedef struct PMIC_struct
{
    register8_t STATUS;  /* Status Register */
    register8_t INTPRI;  /* Interrupt Priority */
    register8_t CTRL;  /* Control Register */
    register8_t reserved_1[13];
} PMIC_t;


/*
--------------------------------------------------------------------------
PORT - I/O Port Configuration
--------------------------------------------------------------------------
*/

/* I/O Ports */
typedef struct PORT_struct
{
    register8_t DIR;  /* I/O Port Data Direction */
    register8_t reserved_1[3];
    register8_t OUT;  /* I/O Port Output */
    register8_t reserved_2[3];
    register8_t IN;  /* I/O port Input */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t INT0MASK;  /* Port Interrupt 0 Mask */
    register8_t INT1MASK;  /* Port Interrupt 1 Mask */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t reserved_3[3];
    register8_t PIN0CTRL;  /* Pin 0 Control Register */
    register8_t PIN1CTRL;  /* Pin 1 Control Register */
    register8_t PIN2CTRL;  /* Pin 2 Control Register */
    register8_t PIN3CTRL;  /* Pin 3 Control Register */
    register8_t PIN4CTRL;  /* Pin 4 Control Register */
    register8_t PIN5CTRL;  /* Pin 5 Control Register */
    register8_t PIN6CTRL;  /* Pin 6 Control Register */
    register8_t PIN7CTRL;  /* Pin 7 Control Register */
    register8_t reserved_4[232];
} PORT_t;

/* Port Interrupt 0 Level */
typedef enum PORT_INT0LVL_enum
{
    PORT_INT0LVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    PORT_INT0LVL_LO_gc = (0x01<<0),  /* Low Level */
    PORT_INT0LVL_MED_gc = (0x02<<0),  /* Medium Level */
    PORT_INT0LVL_HI_gc = (0x03<<0),  /* High Level */
} PORT_INT0LVL_t;

/* Port Interrupt 1 Level */
typedef enum PORT_INT1LVL_enum
{
    PORT_INT1LVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    PORT_INT1LVL_LO_gc = (0x01<<2),  /* Low Level */
    PORT_INT1LVL_MED_gc = (0x02<<2),  /* Medium Level */
    PORT_INT1LVL_HI_gc = (0x03<<2),  /* High Level */
} PORT_INT1LVL_t;

/* Input/Sense Configuration */
typedef enum PORT_ISC_enum
{
    PORT_ISC_BOTHEDGES_gc = (0x00<<0),  /* Sense Both Edges */
    PORT_ISC_RISING_gc = (0x01<<0),  /* Sense Rising Edge */
    PORT_ISC_FALLING_gc = (0x02<<0),  /* Sense Falling Edge */
    PORT_ISC_LEVEL_gc = (0x03<<0),  /* Sense Level (Transparent For Events) */
    PORT_ISC_INPUT_DISABLE_gc = (0x07<<0),  /* Disable Digital Input Buffer */
} PORT_ISC_t;

/* Output/Pull Configuration */
typedef enum PORT_OPC_enum
{
    PORT_OPC_TOTEM_gc = (0x00<<3),  /* Totempole */
    PORT_OPC_BUSKEEPER_gc = (0x01<<3),  /* Totempole w/ Bus keeper on Input and Output */
    PORT_OPC_PULLDOWN_gc = (0x02<<3),  /* Totempole w/ Pull-down on Input */
    PORT_OPC_PULLUP_gc = (0x03<<3),  /* Totempole w/ Pull-up on Input */
    PORT_OPC_WIREDOR_gc = (0x04<<3),  /* Wired OR */
    PORT_OPC_WIREDAND_gc = (0x05<<3),  /* Wired AND */
    PORT_OPC_WIREDORPULL_gc = (0x06<<3),  /* Wired OR w/ Pull-down */
    PORT_OPC_WIREDANDPULL_gc = (0x07<<3),  /* Wired AND w/ Pull-up */
} PORT_OPC_t;

/*
--------------------------------------------------------------------------
PULLDOWN - Pulldown
--------------------------------------------------------------------------
*/

/* Pulldown */
typedef struct PULLDOWN_struct
{
    register8_t PDCTRLC;  /* Pulldown Control Register C */
    register8_t reserved_1[1];
} PULLDOWN_t;


/*
--------------------------------------------------------------------------
PWRCTRL - VS PM Control
--------------------------------------------------------------------------
*/

/* VS PM Control Interface */
typedef struct PWRCTRL_struct
{
    register8_t PWRCRVDD2;  /* VS PM Power Control */
    register8_t reserved_1[3];
} PWRCTRL_t;


/*
--------------------------------------------------------------------------
RST - Reset
--------------------------------------------------------------------------
*/

/* Reset */
typedef struct RST_struct
{
    register8_t STATUS;  /* Status Register */
    register8_t CTRL;  /* Control Register */
    register8_t reserved_1[2];
} RST_t;


/*
--------------------------------------------------------------------------
SIGROW - Signature Row
--------------------------------------------------------------------------
*/

/* Production Signatures */
typedef struct NVM_PROD_SIGNATURES_struct
{
    register8_t reserved_1[8];
    register8_t LOTNUM0;  /* Lot Number Byte 0, ASCII */
    register8_t LOTNUM1;  /* Lot Number Byte 1, ASCII */
    register8_t LOTNUM2;  /* Lot Number Byte 2, ASCII */
    register8_t LOTNUM3;  /* Lot Number Byte 3, ASCII */
    register8_t LOTNUM4;  /* Lot Number Byte 4, ASCII */
    register8_t LOTNUM5;  /* Lot Number Byte 5, ASCII */
    register8_t reserved_2[2];
    register8_t WAFNUM;  /* Wafer Number */
    register8_t reserved_3[1];
    register8_t COORDX0;  /* Wafer Coordinate X Byte 0 */
    register8_t COORDX1;  /* Wafer Coordinate X Byte 1 */
    register8_t COORDY0;  /* Wafer Coordinate Y Byte 0 */
    register8_t COORDY1;  /* Wafer Coordinate Y Byte 1 */
    register8_t reserved_4[10];
    register8_t ADCCAL;  /* ADC Calibration Byte */
    register8_t TEMPSENSE25CL;  /* Internal Temperature Sensor Low Byte */
    register8_t TEMPSENSE25CH;  /* Internal Temperature Sensor High Byte */
    register8_t TEMPSENSE85CL;  /* Internal Temperature Sensor Low Byte */
    register8_t TEMPSENSE85CH;  /* Internal Temperature Sensor High Byte */
    register8_t reserved_5[3];
    register8_t BATTOFFSET;  /* BATT Offset */
    register8_t BATTGAINL;  /* BATT Gain Low Byte */
    register8_t BATTGAINH;  /* BATT Gain High Byte */
    register8_t TESTTEMPROOM;  /* Test Temperature Room */
    register8_t TESTTEMPHOTDIFF;  /* Test Temperature Hot Diff */
    register8_t reserved_6[19];
    register8_t RCCAL24MHZL;  /* 24MHz RC Oscillator Calibration Low Byte */
    register8_t RCCAL24MHZH;  /* 24MHz RC Oscillator Calibration High Byte */
    register8_t ULPRCCALL;  /* ULP RC Oscillator Calibration Low Byte */
    register8_t ULPRCCALH;  /* ULP RC Oscillator Calibration High Byte */
    register8_t reserved_7[28];
    register8_t RC24MHZROOML;  /* 24 MHz Room Low Byte */
    register8_t RC24MHZROOMH;  /* 24 MHz Room High Byte */
    register8_t RC24MHZHOTL;  /* 24 MHz Hot Low Byte */
    register8_t RC24MHZHOTH;  /* 24 MHz Hot High Byte */
    register8_t ULPRCROOML;  /* ULP RC Room Low Byte */
    register8_t ULPRCROOMH;  /* ULP RC Room High Byte */
    register8_t ULPRCHOTL;  /* ULP RC Hot Low Byte */
    register8_t ULPRCHOTH;  /* ULP RC Hot High Byte */
    register8_t reserved_8[24];
} NVM_PROD_SIGNATURES_t;


/*
--------------------------------------------------------------------------
SLEEP - Sleep Controller
--------------------------------------------------------------------------
*/

/* Sleep Controller */
typedef struct SLEEP_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t reserved_1[1];
} SLEEP_t;

/* Sleep Mode */
typedef enum SLEEP_SMODE_enum
{
    SLEEP_SMODE_IDLE_gc = (0x00<<1),  /* Idle mode */
    SLEEP_SMODE_PSAVE_gc = (0x01<<1),  /* Power-save Mode */
} SLEEP_SMODE_t;

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_PWR_SAVE (0x01<<1)
/*
--------------------------------------------------------------------------
TIM8_16 - Timer 8/16 bit
--------------------------------------------------------------------------
*/

/* Timer 8/16 bit */
typedef struct TIM8_16_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t INTMSK;  /* Interrupt Mask Register */
    register8_t STATUS;  /* Status Register */
    register8_t TEMP;  /* Temporary Register */
    register8_t reserved_1[3];
    register8_t COUNTL;  /* Count Register Low Byte */
    register8_t COUNTH;  /* Count Register High Byte */
    register8_t OCRA;  /* Output Compare Register A */
    register8_t OCRB;  /* Output Compare Register B */
    register8_t reserved_2[4];
} TIM8_16_t;

/* Clock Select */
typedef enum TIM8_16_CS_enum
{
    TIM8_16_CS_STOPPED_gc = (0x00<<0),  /* No clock selected */
    TIM8_16_CS_CLKIO_gc = (0x01<<0),  /* clkIO - No prescaling */
    TIM8_16_CS_CLKIO_DIV8_gc = (0x02<<0),  /* clkIO/8 from prescaling */
    TIM8_16_CS_CLKIO_DIV64_gc = (0x03<<0),  /* clkIO/64 from prescaling */
    TIM8_16_CS_CLKIO_DIV256_gc = (0x04<<0),  /* clkIO/256 from prescaling */
    TIM8_16_CS_CLKIO_DIV1024_gc = (0x05<<0),  /* clkIO/1024 from prescaling */
    TIM8_16_CS_8U6_gc = (0x06<<0),  /* 8us clock selected */
    TIM8_16_CS_16U_gc = (0x07<<0),  /* 16us clock selected */
    TIM8_16_CS_64U_gc = (0x08<<0),  /* 64us clock selected */
    TIM8_16_CS_256U_gc = (0x09<<0),  /* 256us clock selected */
    TIM8_16_CS_1M_gc = (0x0A<<0),  /* 1ms clock selected */
    TIM8_16_CS_4M_gc = (0x0B<<0),  /* 4ms clock selected */
    TIM8_16_CS_16M_gc = (0x0C<<0),  /* 16ms clock selected */
    TIM8_16_CS_65M_gc = (0x0D<<0),  /* 65ms clock selected */
    TIM8_16_CS_262M_gc = (0x0E<<0),  /* 262ms clock selected */
    TIM8_16_CS_1S_gc = (0x0F<<0),  /* 1s clock selected */
} TIM8_16_CS_t;

/* Input Capture Select */
typedef enum TIM8_16_ICS_enum
{
    TIM8_16_ICS_PC0_gc = (0x00<<4),  /* Input capture source = PB0 */
    TIM8_16_ICS_PC1_gc = (0x01<<4),  /* Input capture source = PB1 */
    TIM8_16_ICS_PA0_gc = (0x02<<4),  /* Input capture source = PB2 */
} TIM8_16_ICS_t;

/*
--------------------------------------------------------------------------
TIMPRESC - Timer Prescaler
--------------------------------------------------------------------------
*/

/* Timer Prescaler */
typedef struct TIMPRESC_struct
{
    register8_t PRESC;  /* Prescaler Register */
    register8_t reserved_1[1];
} TIMPRESC_t;


/*
--------------------------------------------------------------------------
TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

/* Two-Wire Master Interface */
typedef struct TWI_MASTER_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t CTRLC;  /* Control Register C */
    register8_t STATUS;  /* Status Register */
    register8_t BAUD;  /* Baud Rate Control Register */
    register8_t ADDR;  /* Address Register */
    register8_t DATA;  /* Data Register */
} TWI_MASTER_t;


/* Two-Wire Slave Interface */
typedef struct TWI_SLAVE_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t STATUS;  /* Status Register */
    register8_t ADDR;  /* Address Register */
    register8_t DATA;  /* Data Register */
    register8_t ADDRMASK;  /* Address Mask Register */
} TWI_SLAVE_t;


/* Two-Wire Interface */
typedef struct TWI_struct
{
    register8_t CTRL;  /* TWI Common Control Register */
    TWI_MASTER_t MASTER;  /* TWI Master */
    TWI_SLAVE_t SLAVE;  /* TWI Slave */
} TWI_t;

/* Master Bus State */
typedef enum TWI_MASTER_BUSSTATE_enum
{
    TWI_MASTER_BUSSTATE_UNKNOWN_gc = (0x00<<0),  /* Unknown Bus State */
    TWI_MASTER_BUSSTATE_IDLE_gc = (0x01<<0),  /* Bus is Idle */
    TWI_MASTER_BUSSTATE_OWNER_gc = (0x02<<0),  /* This Module Controls The Bus */
    TWI_MASTER_BUSSTATE_BUSY_gc = (0x03<<0),  /* The Bus is Busy */
} TWI_MASTER_BUSSTATE_t;

/* Master Command */
typedef enum TWI_MASTER_CMD_enum
{
    TWI_MASTER_CMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_MASTER_CMD_REPSTART_gc = (0x01<<0),  /* Issue Repeated Start Condition */
    TWI_MASTER_CMD_RECVTRANS_gc = (0x02<<0),  /* Receive or Transmit Data */
    TWI_MASTER_CMD_STOP_gc = (0x03<<0),  /* Issue Stop Condition */
} TWI_MASTER_CMD_t;

/* Master Interrupt Level */
typedef enum TWI_MASTER_INTLVL_enum
{
    TWI_MASTER_INTLVL_OFF_gc = (0x00<<6),  /* Interrupt Disabled */
    TWI_MASTER_INTLVL_LO_gc = (0x01<<6),  /* Low Level */
    TWI_MASTER_INTLVL_MED_gc = (0x02<<6),  /* Medium Level */
    TWI_MASTER_INTLVL_HI_gc = (0x03<<6),  /* High Level */
} TWI_MASTER_INTLVL_t;

/* Inactive Timeout */
typedef enum TWI_MASTER_TIMEOUT_enum
{
    TWI_MASTER_TIMEOUT_DISABLED_gc = (0x00<<2),  /* Bus Timeout Disabled */
    TWI_MASTER_TIMEOUT_50US_gc = (0x01<<2),  /* 50 Microseconds */
    TWI_MASTER_TIMEOUT_100US_gc = (0x02<<2),  /* 100 Microseconds */
    TWI_MASTER_TIMEOUT_200US_gc = (0x03<<2),  /* 200 Microseconds */
} TWI_MASTER_TIMEOUT_t;

/* Slave Command */
typedef enum TWI_SLAVE_CMD_enum
{
    TWI_SLAVE_CMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_SLAVE_CMD_COMPTRANS_gc = (0x02<<0),  /* Used To Complete a Transaction */
    TWI_SLAVE_CMD_RESPONSE_gc = (0x03<<0),  /* Used in Response to Address/Data Interrupt */
} TWI_SLAVE_CMD_t;

/* Slave Interrupt Level */
typedef enum TWI_SLAVE_INTLVL_enum
{
    TWI_SLAVE_INTLVL_OFF_gc = (0x00<<6),  /* Interrupt Disabled */
    TWI_SLAVE_INTLVL_LO_gc = (0x01<<6),  /* Low Level */
    TWI_SLAVE_INTLVL_MED_gc = (0x02<<6),  /* Medium Level */
    TWI_SLAVE_INTLVL_HI_gc = (0x03<<6),  /* High Level */
} TWI_SLAVE_INTLVL_t;

/*
--------------------------------------------------------------------------
VPORT - Virtual Ports
--------------------------------------------------------------------------
*/

/* Virtual Port */
typedef struct VPORT_struct
{
    register8_t DIR;  /* I/O Port Data Direction */
    register8_t OUT;  /* I/O Port Output */
    register8_t IN;  /* I/O Port Input */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t reserved_1[12];
} VPORT_t;


/*
--------------------------------------------------------------------------
WDT - Watch-Dog Timer
--------------------------------------------------------------------------
*/

/* Watch-Dog Timer */
typedef struct WDT_struct
{
    register8_t CTRL;  /* Control */
    register8_t WINCTRL;  /* Windowed Mode Control */
    register8_t STATUS;  /* Status */
    register8_t reserved_1[13];
} WDT_t;

/* Period setting */
typedef enum WDT_PER_enum
{
    WDT_PER_8CLK_gc = (0x00<<2),  /* 8 cycles (8ms) */
    WDT_PER_16CLK_gc = (0x01<<2),  /* 16 cycles (16ms) */
    WDT_PER_32CLK_gc = (0x02<<2),  /* 32 cycles (32ms) */
    WDT_PER_64CLK_gc = (0x03<<2),  /* 64 cycles (64ms) */
    WDT_PER_128CLK_gc = (0x04<<2),  /* 128 cycles (0.128s) */
    WDT_PER_256CLK_gc = (0x05<<2),  /* 256 cycles (0.26s) */
    WDT_PER_512CLK_gc = (0x06<<2),  /* 512 cycles (0.5s) */
    WDT_PER_1KCLK_gc = (0x07<<2),  /* 1K cycles (1s) */
    WDT_PER_2KCLK_gc = (0x08<<2),  /* 2K cycles (2s) */
    WDT_PER_4KCLK_gc = (0x09<<2),  /* 4K cycles (4s) */
    WDT_PER_8KCLK_gc = (0x0A<<2),  /* 8K cycles (8s) */
} WDT_PER_t;

/* Closed window period */
typedef enum WDT_WPER_enum
{
    WDT_WPER_8CLK_gc = (0x00<<2),  /* 8 cycles (8ms ) */
    WDT_WPER_16CLK_gc = (0x01<<2),  /* 16 cycles (16ms ) */
    WDT_WPER_32CLK_gc = (0x02<<2),  /* 32 cycles (32ms ) */
    WDT_WPER_64CLK_gc = (0x03<<2),  /* 64 cycles (64ms ) */
    WDT_WPER_128CLK_gc = (0x04<<2),  /* 128 cycles (0.128s) */
    WDT_WPER_256CLK_gc = (0x05<<2),  /* 256 cycles (0.26s) */
    WDT_WPER_512CLK_gc = (0x06<<2),  /* 512 cycles (0.5s) */
    WDT_WPER_1KCLK_gc = (0x07<<2),  /* 1K cycles (1s ) */
    WDT_WPER_2KCLK_gc = (0x08<<2),  /* 2K cycles (2s ) */
    WDT_WPER_4KCLK_gc = (0x09<<2),  /* 4K cycles (4s ) */
    WDT_WPER_8KCLK_gc = (0x0A<<2),  /* 8K cycles (8s ) */
} WDT_WPER_t;

/*
--------------------------------------------------------------------------
WUT - Wake-up Timer
--------------------------------------------------------------------------
*/

/* Wake-up Timer */
typedef struct WUT_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t STATUS;  /* Status Register */
    register8_t reserved_1[1];
} WUT_t;

/* Wake-up Timer Mode */
typedef enum WUT_MODE_enum
{
    WUT_MODE_DISABLE_gc = (0x00<<3),  /* Disabled */
    WUT_MODE_DIRECT_gc = (0x01<<3),  /* Direct on Timekeeper event  */
    WUT_MODE_EVERY_8TH_gc = (0x02<<3),  /* Every 8th Timekeeper event */
} WUT_MODE_t;

/* Wake-up Timer Prescaling */
typedef enum WUT_PRESC_enum
{
    WUT_PRESC_PRESC_8_gc = (0x00<<0),  /* 64us with 125kHz Timerkeeper clock (actual clock is chip dependent) */
    WUT_PRESC_RPESC_16_gc = (0x01<<0),  /* 128us with 125kHz Timekeeper clock (actual clock is chip dependent) */
    WUT_PRESC_PRESC_32_gc = (0x02<<0),  /* 256us with 125kHz Timekeeper clock (actual clock is chip dependent) */
    WUT_PRESC_PRESC_64_gc = (0x03<<0),  /* 512us with 125kHz Timekeeper clock (actual clock is chip dependent) */
    WUT_PRESC_PRESC_128_gc = (0x04<<0),  /* 1024us with 125kHz Timekeeper clock (actual clock is chip dependent) */
    WUT_PRESC_PRESC_256_gc = (0x05<<0),  /* 2048us with 125kHz Timekeeper clock (actual clock is chip dependent) */
    WUT_PRESC_PRESC_512_gc = (0x06<<0),  /* 4096us with 125kHz Timekeeper clock (actual clock is chip dependent) */
    WUT_PRESC_PRESC_1024_gc = (0x07<<0),  /* 8192us with 125kHz Timekeeper clock (actual clock is chip dependent) */
} WUT_PRESC_t;

/*
--------------------------------------------------------------------------
XOCD - On-Chip Debug System
--------------------------------------------------------------------------
*/

/* On-Chip Debug System */
typedef struct OCD_struct
{
    register8_t OCDR0;  /* OCD Register 0 */
    register8_t OCDR1;  /* OCD Register 1 */
} OCD_t;

/*
==========================================================================
IO Module Instances. Mapped to memory.
==========================================================================
*/

#define VPORT0              (*(VPORT_t *) 0x0010) /* Virtual Port */
#define VPORT1              (*(VPORT_t *) 0x0014) /* Virtual Port */
#define VPORT2              (*(VPORT_t *) 0x0018) /* Virtual Port */
#define VPORT3              (*(VPORT_t *) 0x001C) /* Virtual Port */
#define OCD                   (*(OCD_t *) 0x002E) /* On-Chip Debug System */
#define SLEEP               (*(SLEEP_t *) 0x0040) /* Sleep Controller */
#define RST                   (*(RST_t *) 0x0044) /* Reset */
#define BANDGAP           (*(BANDGAP_t *) 0x0048) /* Bandgap */
#define BIASCTRL         (*(BIASCTRL_t *) 0x004A) /* BIASCTRL */
#define LDO                   (*(LDO_t *) 0x004C) /* LDO */
#define CLK                   (*(CLK_t *) 0x0050) /* Clock System */
#define WDT                   (*(WDT_t *) 0x0080) /* Watch-Dog Timer */
#define MCU                   (*(MCU_t *) 0x0090) /* MCU Control */
#define PMIC                 (*(PMIC_t *) 0x00A0) /* Programmable Multi-level Interrupt Controller */
#define WUT                   (*(WUT_t *) 0x00C0) /* Wake-up Timer */
#define CRC4                 (*(CRC4_t *) 0x00C4) /* Cyclic Redundancy Checker */
#define NVM                   (*(NVM_t *) 0x01C0) /* Non-volatile Memory Controller */
#define BOOSTIF           (*(BOOSTIF_t *) 0x03D8) /* Boost Converter Interface */
#define PWRCTRL           (*(PWRCTRL_t *) 0x03E4) /* VS PM Control Interface */
#define TWIC                  (*(TWI_t *) 0x03F0) /* Two-Wire Interface */
#define TIMER0            (*(TIM8_16_t *) 0x0400) /* Timer 8/16 bit */
#define TIMER1            (*(TIM8_16_t *) 0x0410) /* Timer 8/16 bit */
#define TIMPRESC         (*(TIMPRESC_t *) 0x0420) /* Timer Prescaler */
#define PORTA                (*(PORT_t *) 0x0480) /* I/O Ports */
#define PORTB                (*(PORT_t *) 0x04A0) /* I/O Ports */
#define PORTC                (*(PORT_t *) 0x04C0) /* I/O Ports */
#define PULLDOWN         (*(PULLDOWN_t *) 0x0500) /* Pulldown */
#define ADCCMN            (*(ADC_CMN_t *) 0x0800) /* ADC Common Settings */
#define ADCGENCH        (*(ADC_GEN_CH_t *) 0x0810) /* ADC General Channel */

#endif /* !defined (__ASSEMBLER__) */


/* ========== Flattened fully qualified IO register names ========== */


/* GPIO - General Purpose IO Registers */
#define GPIO_GPIOR0  _SFR_MEM8(0x0000)
#define GPIO_GPIOR1  _SFR_MEM8(0x0001)
#define GPIO_GPIOR2  _SFR_MEM8(0x0002)
#define GPIO_GPIOR3  _SFR_MEM8(0x0003)


/* Deprecated */
#define GPIO_GPIO0  _SFR_MEM8(0x0000)
#define GPIO_GPIO1  _SFR_MEM8(0x0001)
#define GPIO_GPIO2  _SFR_MEM8(0x0002)
#define GPIO_GPIO3  _SFR_MEM8(0x0003)


/* NVM_FUSES (FUSE) - Fuses */
#define FUSE_FUSEBYTE4  _SFR_MEM8(0x0004)
#define FUSE_FUSEBYTE5  _SFR_MEM8(0x0005)
#define FUSE_FUSEBYTE6  _SFR_MEM8(0x0006)


/* NVM_LOCKBITS (LOCKBIT) - Lockbits */
#define LOCKBIT_LOCKBITS  _SFR_MEM8(0x0000)


/* NVM_PROD_SIGNATURES (PROD_SIGNATURES) - Production Signatures */
#define PRODSIGNATURES_LOTNUM0  _SFR_MEM8(0x0008)
#define PRODSIGNATURES_LOTNUM1  _SFR_MEM8(0x0009)
#define PRODSIGNATURES_LOTNUM2  _SFR_MEM8(0x000A)
#define PRODSIGNATURES_LOTNUM3  _SFR_MEM8(0x000B)
#define PRODSIGNATURES_LOTNUM4  _SFR_MEM8(0x000C)
#define PRODSIGNATURES_LOTNUM5  _SFR_MEM8(0x000D)
#define PRODSIGNATURES_WAFNUM  _SFR_MEM8(0x0010)
#define PRODSIGNATURES_COORDX0  _SFR_MEM8(0x0012)
#define PRODSIGNATURES_COORDX1  _SFR_MEM8(0x0013)
#define PRODSIGNATURES_COORDY0  _SFR_MEM8(0x0014)
#define PRODSIGNATURES_COORDY1  _SFR_MEM8(0x0015)
#define PRODSIGNATURES_ADCCAL  _SFR_MEM8(0x0020)
#define PRODSIGNATURES_TEMPSENSE25CL  _SFR_MEM8(0x0021)
#define PRODSIGNATURES_TEMPSENSE25CH  _SFR_MEM8(0x0022)
#define PRODSIGNATURES_TEMPSENSE85CL  _SFR_MEM8(0x0023)
#define PRODSIGNATURES_TEMPSENSE85CH  _SFR_MEM8(0x0024)
#define PRODSIGNATURES_BATTOFFSET  _SFR_MEM8(0x0028)
#define PRODSIGNATURES_BATTGAINL  _SFR_MEM8(0x0029)
#define PRODSIGNATURES_BATTGAINH  _SFR_MEM8(0x002A)
#define PRODSIGNATURES_TESTTEMPROOM  _SFR_MEM8(0x002B)
#define PRODSIGNATURES_TESTTEMPHOTDIFF  _SFR_MEM8(0x002C)
#define PRODSIGNATURES_RCCAL24MHZL  _SFR_MEM8(0x0040)
#define PRODSIGNATURES_RCCAL24MHZH  _SFR_MEM8(0x0041)
#define PRODSIGNATURES_ULPRCCALL  _SFR_MEM8(0x0042)
#define PRODSIGNATURES_ULPRCCALH  _SFR_MEM8(0x0043)
#define PRODSIGNATURES_RC24MHZROOML  _SFR_MEM8(0x0060)
#define PRODSIGNATURES_RC24MHZROOMH  _SFR_MEM8(0x0061)
#define PRODSIGNATURES_RC24MHZHOTL  _SFR_MEM8(0x0062)
#define PRODSIGNATURES_RC24MHZHOTH  _SFR_MEM8(0x0063)
#define PRODSIGNATURES_ULPRCROOML  _SFR_MEM8(0x0064)
#define PRODSIGNATURES_ULPRCROOMH  _SFR_MEM8(0x0065)
#define PRODSIGNATURES_ULPRCHOTL  _SFR_MEM8(0x0066)
#define PRODSIGNATURES_ULPRCHOTH  _SFR_MEM8(0x0067)


/* VPORT (VPORT0) - Virtual Port */
#define VPORT0_DIR  _SFR_MEM8(0x0010)
#define VPORT0_OUT  _SFR_MEM8(0x0011)
#define VPORT0_IN  _SFR_MEM8(0x0012)
#define VPORT0_INTFLAGS  _SFR_MEM8(0x0013)


/* VPORT (VPORT1) - Virtual Port */
#define VPORT1_DIR  _SFR_MEM8(0x0014)
#define VPORT1_OUT  _SFR_MEM8(0x0015)
#define VPORT1_IN  _SFR_MEM8(0x0016)
#define VPORT1_INTFLAGS  _SFR_MEM8(0x0017)


/* VPORT (VPORT2) - Virtual Port */
#define VPORT2_DIR  _SFR_MEM8(0x0018)
#define VPORT2_OUT  _SFR_MEM8(0x0019)
#define VPORT2_IN  _SFR_MEM8(0x001A)
#define VPORT2_INTFLAGS  _SFR_MEM8(0x001B)


/* VPORT (VPORT3) - Virtual Port */
#define VPORT3_DIR  _SFR_MEM8(0x001C)
#define VPORT3_OUT  _SFR_MEM8(0x001D)
#define VPORT3_IN  _SFR_MEM8(0x001E)
#define VPORT3_INTFLAGS  _SFR_MEM8(0x001F)


/* OCD - On-Chip Debug System */
#define OCD_OCDR0  _SFR_MEM8(0x002E)
#define OCD_OCDR1  _SFR_MEM8(0x002F)


/* CPU - CPU registers */
#define CPU_CCP  _SFR_MEM8(0x0034)
#define CPU_RAMPD  _SFR_MEM8(0x0038)
#define CPU_RAMPX  _SFR_MEM8(0x0039)
#define CPU_RAMPY  _SFR_MEM8(0x003A)
#define CPU_RAMPZ  _SFR_MEM8(0x003B)
#define CPU_EIND  _SFR_MEM8(0x003C)
#define CPU_SPL  _SFR_MEM8(0x003D)
#define CPU_SPH  _SFR_MEM8(0x003E)
#define CPU_SREG  _SFR_MEM8(0x003F)


/* SLEEP - Sleep Controller */
#define SLEEP_CTRL  _SFR_MEM8(0x0040)


/* RST - Reset */
#define RST_STATUS  _SFR_MEM8(0x0044)
#define RST_CTRL  _SFR_MEM8(0x0045)


/* BANDGAP - Bandgap */
#define BANDGAP_CTRL  _SFR_MEM8(0x0048)


/* BIASCTRL - BIASCTRL */
#define BIASCTRL_CTRL  _SFR_MEM8(0x004A)


/* LDO - LDO */
#define LDO_CTRL  _SFR_MEM8(0x004C)


/* CLK - Clock System */
#define CLK_CLKPSR  _SFR_MEM8(0x0050)
#define CLK_CLKSLR  _SFR_MEM8(0x0051)
#define CLK_FRCCALL  _SFR_MEM8(0x0054)
#define CLK_FRCCALH  _SFR_MEM8(0x0055)
#define CLK_ULPRCCALL  _SFR_MEM8(0x0056)
#define CLK_ULPRCCALH  _SFR_MEM8(0x0057)


/* WDT - Watch-Dog Timer */
#define WDT_CTRL  _SFR_MEM8(0x0080)
#define WDT_WINCTRL  _SFR_MEM8(0x0081)
#define WDT_STATUS  _SFR_MEM8(0x0082)


/* MCU - MCU Control */
#define MCU_DEVID0  _SFR_MEM8(0x0090)
#define MCU_DEVID1  _SFR_MEM8(0x0091)
#define MCU_DEVID2  _SFR_MEM8(0x0092)
#define MCU_REVID  _SFR_MEM8(0x0093)


/* PMIC - Programmable Multi-level Interrupt Controller */
#define PMIC_STATUS  _SFR_MEM8(0x00A0)
#define PMIC_INTPRI  _SFR_MEM8(0x00A1)
#define PMIC_CTRL  _SFR_MEM8(0x00A2)


/* WUT - Wake-up Timer */
#define WUT_CTRL  _SFR_MEM8(0x00C0)
#define WUT_INTCTRL  _SFR_MEM8(0x00C1)
#define WUT_STATUS  _SFR_MEM8(0x00C2)


/* CRC4 - Cyclic Redundancy Checker */
#define CRC4_DATAIN  _SFR_MEM8(0x00C4)
#define CRC4_CHECKSUM  _SFR_MEM8(0x00C5)


/* NVM - Non-volatile Memory Controller */
#define NVM_ADDR0  _SFR_MEM8(0x01C0)
#define NVM_ADDR1  _SFR_MEM8(0x01C1)
#define NVM_ADDR2  _SFR_MEM8(0x01C2)
#define NVM_DATA0  _SFR_MEM8(0x01C4)
#define NVM_DATA1  _SFR_MEM8(0x01C5)
#define NVM_DATA2  _SFR_MEM8(0x01C6)
#define NVM_CMD  _SFR_MEM8(0x01CA)
#define NVM_CTRLA  _SFR_MEM8(0x01CB)
#define NVM_CTRLB  _SFR_MEM8(0x01CC)
#define NVM_INTCTRL  _SFR_MEM8(0x01CD)
#define NVM_STATUS  _SFR_MEM8(0x01CF)
#define NVM_LOCKBITS  _SFR_MEM8(0x01D0)


/* BOOSTIF - Boost Converter Interface */
#define BOOSTIF_CTRLA  _SFR_MEM8(0x03D8)
#define BOOSTIF_CTRLB  _SFR_MEM8(0x03D9)
#define BOOSTIF_LEVEL  _SFR_MEM8(0x03DA)
#define BOOSTIF_CNTHIGH  _SFR_MEM8(0x03DB)
#define BOOSTIF_CNTLOW  _SFR_MEM8(0x03DC)
#define BOOSTIF_TEST  _SFR_MEM8(0x03DD)
#define BOOSTIF_SETTLE  _SFR_MEM8(0x03DE)


/* PWRCTRL - VS PM Control Interface */
#define PWRCTRL_PWRCRVDD2  _SFR_MEM8(0x03E4)


/* TWI (TWIC) - Two-Wire Interface */
#define TWIC_CTRL  _SFR_MEM8(0x03F0)
#define TWIC_MASTER_CTRLA  _SFR_MEM8(0x03F1)
#define TWIC_MASTER_CTRLB  _SFR_MEM8(0x03F2)
#define TWIC_MASTER_CTRLC  _SFR_MEM8(0x03F3)
#define TWIC_MASTER_STATUS  _SFR_MEM8(0x03F4)
#define TWIC_MASTER_BAUD  _SFR_MEM8(0x03F5)
#define TWIC_MASTER_ADDR  _SFR_MEM8(0x03F6)
#define TWIC_MASTER_DATA  _SFR_MEM8(0x03F7)


#define TWIC_SLAVE_CTRLA  _SFR_MEM8(0x03F8)
#define TWIC_SLAVE_CTRLB  _SFR_MEM8(0x03F9)
#define TWIC_SLAVE_STATUS  _SFR_MEM8(0x03FA)
#define TWIC_SLAVE_ADDR  _SFR_MEM8(0x03FB)
#define TWIC_SLAVE_DATA  _SFR_MEM8(0x03FC)
#define TWIC_SLAVE_ADDRMASK  _SFR_MEM8(0x03FD)




/* TIM8_16 (TIMER0) - Timer 8/16 bit */
#define TIMER0_CTRLA  _SFR_MEM8(0x0400)
#define TIMER0_CTRLB  _SFR_MEM8(0x0401)
#define TIMER0_INTMSK  _SFR_MEM8(0x0402)
#define TIMER0_STATUS  _SFR_MEM8(0x0403)
#define TIMER0_TEMP  _SFR_MEM8(0x0404)
#define TIMER0_COUNTL  _SFR_MEM8(0x0408)
#define TIMER0_COUNTH  _SFR_MEM8(0x0409)
#define TIMER0_OCRA  _SFR_MEM8(0x040A)
#define TIMER0_OCRB  _SFR_MEM8(0x040B)


/* TIM8_16 (TIMER1) - Timer 8/16 bit */
#define TIMER1_CTRLA  _SFR_MEM8(0x0410)
#define TIMER1_CTRLB  _SFR_MEM8(0x0411)
#define TIMER1_INTMSK  _SFR_MEM8(0x0412)
#define TIMER1_STATUS  _SFR_MEM8(0x0413)
#define TIMER1_TEMP  _SFR_MEM8(0x0414)
#define TIMER1_COUNTL  _SFR_MEM8(0x0418)
#define TIMER1_COUNTH  _SFR_MEM8(0x0419)
#define TIMER1_OCRA  _SFR_MEM8(0x041A)
#define TIMER1_OCRB  _SFR_MEM8(0x041B)


/* TIMPRESC - Timer Prescaler */
#define TIMPRESC_PRESC  _SFR_MEM8(0x0420)


/* PORT (PORTA) - I/O Ports */
#define PORTA_DIR  _SFR_MEM8(0x0480)
#define PORTA_OUT  _SFR_MEM8(0x0484)
#define PORTA_IN  _SFR_MEM8(0x0488)
#define PORTA_INTCTRL  _SFR_MEM8(0x0489)
#define PORTA_INT0MASK  _SFR_MEM8(0x048A)
#define PORTA_INT1MASK  _SFR_MEM8(0x048B)
#define PORTA_INTFLAGS  _SFR_MEM8(0x048C)
#define PORTA_PIN0CTRL  _SFR_MEM8(0x0490)
#define PORTA_PIN1CTRL  _SFR_MEM8(0x0491)
#define PORTA_PIN2CTRL  _SFR_MEM8(0x0492)
#define PORTA_PIN3CTRL  _SFR_MEM8(0x0493)
#define PORTA_PIN4CTRL  _SFR_MEM8(0x0494)
#define PORTA_PIN5CTRL  _SFR_MEM8(0x0495)
#define PORTA_PIN6CTRL  _SFR_MEM8(0x0496)
#define PORTA_PIN7CTRL  _SFR_MEM8(0x0497)


/* PORT (PORTB) - I/O Ports */
#define PORTB_DIR  _SFR_MEM8(0x04A0)
#define PORTB_OUT  _SFR_MEM8(0x04A4)
#define PORTB_IN  _SFR_MEM8(0x04A8)
#define PORTB_INTCTRL  _SFR_MEM8(0x04A9)
#define PORTB_INT0MASK  _SFR_MEM8(0x04AA)
#define PORTB_INT1MASK  _SFR_MEM8(0x04AB)
#define PORTB_INTFLAGS  _SFR_MEM8(0x04AC)
#define PORTB_PIN0CTRL  _SFR_MEM8(0x04B0)
#define PORTB_PIN1CTRL  _SFR_MEM8(0x04B1)
#define PORTB_PIN2CTRL  _SFR_MEM8(0x04B2)
#define PORTB_PIN3CTRL  _SFR_MEM8(0x04B3)
#define PORTB_PIN4CTRL  _SFR_MEM8(0x04B4)
#define PORTB_PIN5CTRL  _SFR_MEM8(0x04B5)
#define PORTB_PIN6CTRL  _SFR_MEM8(0x04B6)
#define PORTB_PIN7CTRL  _SFR_MEM8(0x04B7)


/* PORT (PORTC) - I/O Ports */
#define PORTC_DIR  _SFR_MEM8(0x04C0)
#define PORTC_OUT  _SFR_MEM8(0x04C4)
#define PORTC_IN  _SFR_MEM8(0x04C8)
#define PORTC_INTCTRL  _SFR_MEM8(0x04C9)
#define PORTC_INT0MASK  _SFR_MEM8(0x04CA)
#define PORTC_INT1MASK  _SFR_MEM8(0x04CB)
#define PORTC_INTFLAGS  _SFR_MEM8(0x04CC)
#define PORTC_PIN0CTRL  _SFR_MEM8(0x04D0)
#define PORTC_PIN1CTRL  _SFR_MEM8(0x04D1)
#define PORTC_PIN2CTRL  _SFR_MEM8(0x04D2)
#define PORTC_PIN3CTRL  _SFR_MEM8(0x04D3)
#define PORTC_PIN4CTRL  _SFR_MEM8(0x04D4)
#define PORTC_PIN5CTRL  _SFR_MEM8(0x04D5)
#define PORTC_PIN6CTRL  _SFR_MEM8(0x04D6)
#define PORTC_PIN7CTRL  _SFR_MEM8(0x04D7)


/* PULLDOWN - Pulldown */
#define PULLDOWN_PDCTRLC  _SFR_MEM8(0x0500)


/* ADC_CMN - ADC Common Settings */
#define ADCCMN_CTRLA  _SFR_MEM8(0x0800)
#define ADCCMN_CTRLB  _SFR_MEM8(0x0801)
#define ADCCMN_EVSEL  _SFR_MEM8(0x0802)
#define ADCCMN_PORTCTRL  _SFR_MEM8(0x0803)
#define ADCCMN_PRESCALER  _SFR_MEM8(0x0804)
#define ADCCMN_INTCTRL  _SFR_MEM8(0x0806)
#define ADCCMN_INTSTATUS  _SFR_MEM8(0x0807)
#define ADCCMN_CHSTATUS  _SFR_MEM8(0x0808)
#define ADCCMN_THRESHOLD  _SFR_MEM8(0x0809)
#define ADCCMN_CAL  _SFR_MEM8(0x080C)


/* ADC_GEN_CH - ADC General Channel */
#define ADCGENCH_CTRLA  _SFR_MEM8(0x0810)
#define ADCGENCH_SAMPCTRL  _SFR_MEM8(0x0811)
#define ADCGENCH_MUXCTRL  _SFR_MEM8(0x0812)
#define ADCGENCH_INTCTRL  _SFR_MEM8(0x0813)
#define ADCGENCH_INTSTATUS  _SFR_MEM8(0x0815)
#define ADCGENCH_RESL  _SFR_MEM8(0x0816)
#define ADCGENCH_RESH  _SFR_MEM8(0x0817)
#define ADCGENCH_REFCTRL  _SFR_MEM8(0x0818)
#define ADCGENCH_RESHTMP  _SFR_MEM8(0x0819)



/*================== Bitfield Definitions ================== */

/* ADC_CMN - ADC Common Settings */
/* ADC_CMN.CTRLA  bit masks and bit positions */
#define ADC_CMN_SSEN_bm  0x01  /* Sensor settling enable bit mask. */
#define ADC_CMN_SSEN_bp  0  /* Sensor settling enable bit position. */
#define ADC_CMN_FLUSH_bm  0x02  /* Pipeline Flush bit mask. */
#define ADC_CMN_FLUSH_bp  1  /* Pipeline Flush bit position. */
#define ADC_CMN_ADCLDOBPEN_bm  0x04  /* ADC LDO Bypass Override Enable bit mask. */
#define ADC_CMN_ADCLDOBPEN_bp  2  /* ADC LDO Bypass Override Enable bit position. */
#define ADC_CMN_SSLDOBPEN_bm  0x08  /* Sensor settling LDO Bypass Override Enable bit mask. */
#define ADC_CMN_SSLDOBPEN_bp  3  /* Sensor settling LDO Bypass Override Enable bit position. */
#define ADC_CMN_TXEDGEDETEN_bm  0x20  /* Enable ADC-TX collision detector bit mask. */
#define ADC_CMN_TXEDGEDETEN_bp  5  /* Enable ADC-TX collision detector bit position. */
#define ADC_CMN_TXEDGEDETMODE_gm  0xC0  /* ADC-TX collision detector mode group mask. */
#define ADC_CMN_TXEDGEDETMODE_gp  6  /* ADC-TX collision detector mode group position. */
#define ADC_CMN_TXEDGEDETMODE0_bm  (1<<6)  /* ADC-TX collision detector mode bit 0 mask. */
#define ADC_CMN_TXEDGEDETMODE0_bp  6  /* ADC-TX collision detector mode bit 0 position. */
#define ADC_CMN_TXEDGEDETMODE1_bm  (1<<7)  /* ADC-TX collision detector mode bit 1 mask. */
#define ADC_CMN_TXEDGEDETMODE1_bp  7  /* ADC-TX collision detector mode bit 1 position. */

/* ADC_CMN.CTRLB  bit masks and bit positions */
#define ADC_CMN_ADCINIT_gm  0x1C  /* ADC initialization clock cycles group mask. */
#define ADC_CMN_ADCINIT_gp  2  /* ADC initialization clock cycles group position. */
#define ADC_CMN_ADCINIT0_bm  (1<<2)  /* ADC initialization clock cycles bit 0 mask. */
#define ADC_CMN_ADCINIT0_bp  2  /* ADC initialization clock cycles bit 0 position. */
#define ADC_CMN_ADCINIT1_bm  (1<<3)  /* ADC initialization clock cycles bit 1 mask. */
#define ADC_CMN_ADCINIT1_bp  3  /* ADC initialization clock cycles bit 1 position. */
#define ADC_CMN_ADCINIT2_bm  (1<<4)  /* ADC initialization clock cycles bit 2 mask. */
#define ADC_CMN_ADCINIT2_bp  4  /* ADC initialization clock cycles bit 2 position. */
#define ADC_CMN_CURRLIMIT_gm  0x60  /* Current Limitation group mask. */
#define ADC_CMN_CURRLIMIT_gp  5  /* Current Limitation group position. */
#define ADC_CMN_CURRLIMIT0_bm  (1<<5)  /* Current Limitation bit 0 mask. */
#define ADC_CMN_CURRLIMIT0_bp  5  /* Current Limitation bit 0 position. */
#define ADC_CMN_CURRLIMIT1_bm  (1<<6)  /* Current Limitation bit 1 mask. */
#define ADC_CMN_CURRLIMIT1_bp  6  /* Current Limitation bit 1 position. */

/* ADC_CMN.EVSEL  bit masks and bit positions */
#define ADC_CMN_SSTIMSEL_gm  0x07  /* Sensor settling time select group mask. */
#define ADC_CMN_SSTIMSEL_gp  0  /* Sensor settling time select group position. */
#define ADC_CMN_SSTIMSEL0_bm  (1<<0)  /* Sensor settling time select bit 0 mask. */
#define ADC_CMN_SSTIMSEL0_bp  0  /* Sensor settling time select bit 0 position. */
#define ADC_CMN_SSTIMSEL1_bm  (1<<1)  /* Sensor settling time select bit 1 mask. */
#define ADC_CMN_SSTIMSEL1_bp  1  /* Sensor settling time select bit 1 position. */
#define ADC_CMN_SSTIMSEL2_bm  (1<<2)  /* Sensor settling time select bit 2 mask. */
#define ADC_CMN_SSTIMSEL2_bp  2  /* Sensor settling time select bit 2 position. */
#define ADC_CMN_SCANTIMSEL_gm  0x30  /* ADC scan time select group mask. */
#define ADC_CMN_SCANTIMSEL_gp  4  /* ADC scan time select group position. */
#define ADC_CMN_SCANTIMSEL0_bm  (1<<4)  /* ADC scan time select bit 0 mask. */
#define ADC_CMN_SCANTIMSEL0_bp  4  /* ADC scan time select bit 0 position. */
#define ADC_CMN_SCANTIMSEL1_bm  (1<<5)  /* ADC scan time select bit 1 mask. */
#define ADC_CMN_SCANTIMSEL1_bp  5  /* ADC scan time select bit 1 position. */

/* ADC_CMN.PORTCTRL  bit masks and bit positions */
#define ADC_CMN_PSEL_gm  0x07  /* Port select group mask. */
#define ADC_CMN_PSEL_gp  0  /* Port select group position. */
#define ADC_CMN_PSEL0_bm  (1<<0)  /* Port select bit 0 mask. */
#define ADC_CMN_PSEL0_bp  0  /* Port select bit 0 position. */
#define ADC_CMN_PSEL1_bm  (1<<1)  /* Port select bit 1 mask. */
#define ADC_CMN_PSEL1_bp  1  /* Port select bit 1 position. */
#define ADC_CMN_PSEL2_bm  (1<<2)  /* Port select bit 2 mask. */
#define ADC_CMN_PSEL2_bp  2  /* Port select bit 2 position. */
#define ADC_CMN_POV_bm  0x10  /* Port override value bit mask. */
#define ADC_CMN_POV_bp  4  /* Port override value bit position. */

/* ADC_CMN.PRESCALER  bit masks and bit positions */
#define ADC_CMN_PRESCALER_gm  0x07  /* Prescaler Configuration group mask. */
#define ADC_CMN_PRESCALER_gp  0  /* Prescaler Configuration group position. */
#define ADC_CMN_PRESCALER0_bm  (1<<0)  /* Prescaler Configuration bit 0 mask. */
#define ADC_CMN_PRESCALER0_bp  0  /* Prescaler Configuration bit 0 position. */
#define ADC_CMN_PRESCALER1_bm  (1<<1)  /* Prescaler Configuration bit 1 mask. */
#define ADC_CMN_PRESCALER1_bp  1  /* Prescaler Configuration bit 1 position. */
#define ADC_CMN_PRESCALER2_bm  (1<<2)  /* Prescaler Configuration bit 2 mask. */
#define ADC_CMN_PRESCALER2_bp  2  /* Prescaler Configuration bit 2 position. */

/* ADC_CMN.INTCTRL  bit masks and bit positions */
#define ADC_CMN_INTLVL_gm  0x03  /* Interrupt Level group mask. */
#define ADC_CMN_INTLVL_gp  0  /* Interrupt Level group position. */
#define ADC_CMN_INTLVL0_bm  (1<<0)  /* Interrupt Level bit 0 mask. */
#define ADC_CMN_INTLVL0_bp  0  /* Interrupt Level bit 0 position. */
#define ADC_CMN_INTLVL1_bm  (1<<1)  /* Interrupt Level bit 1 mask. */
#define ADC_CMN_INTLVL1_bp  1  /* Interrupt Level bit 1 position. */

/* ADC_CMN.INTSTATUS  bit masks and bit positions */
#define ADC_CMN_SENSETIF_bm  0x01  /* Sensor settling interrupt flag  bit mask. */
#define ADC_CMN_SENSETIF_bp  0  /* Sensor settling interrupt flag  bit position. */

/* ADC_CMN.CHSTATUS  bit masks and bit positions */
#define ADC_CMN_GENCHBUSY_bm  0x01  /* General channel busy bit mask. */
#define ADC_CMN_GENCHBUSY_bp  0  /* General channel busy bit position. */
#define ADC_CMN_SSENSYNCBSY_bm  0x10  /* Sensor settling enable synchronization busy bit mask. */
#define ADC_CMN_SSENSYNCBSY_bp  4  /* Sensor settling enable synchronization busy bit position. */
#define ADC_CMN_ANACLKON_bm  0x20  /* Analog Clock is running bit mask. */
#define ADC_CMN_ANACLKON_bp  5  /* Analog Clock is running bit position. */
#define ADC_CMN_SSBSY_bm  0x40  /* Sensor settling busy bit mask. */
#define ADC_CMN_SSBSY_bp  6  /* Sensor settling busy bit position. */

/* ADC_CMN.THRESHOLD  bit masks and bit positions */
#define ADC_CMN_THRESHOLD_gm  0xFF  /* Threshold value group mask. */
#define ADC_CMN_THRESHOLD_gp  0  /* Threshold value group position. */
#define ADC_CMN_THRESHOLD0_bm  (1<<0)  /* Threshold value bit 0 mask. */
#define ADC_CMN_THRESHOLD0_bp  0  /* Threshold value bit 0 position. */
#define ADC_CMN_THRESHOLD1_bm  (1<<1)  /* Threshold value bit 1 mask. */
#define ADC_CMN_THRESHOLD1_bp  1  /* Threshold value bit 1 position. */
#define ADC_CMN_THRESHOLD2_bm  (1<<2)  /* Threshold value bit 2 mask. */
#define ADC_CMN_THRESHOLD2_bp  2  /* Threshold value bit 2 position. */
#define ADC_CMN_THRESHOLD3_bm  (1<<3)  /* Threshold value bit 3 mask. */
#define ADC_CMN_THRESHOLD3_bp  3  /* Threshold value bit 3 position. */
#define ADC_CMN_THRESHOLD4_bm  (1<<4)  /* Threshold value bit 4 mask. */
#define ADC_CMN_THRESHOLD4_bp  4  /* Threshold value bit 4 position. */
#define ADC_CMN_THRESHOLD5_bm  (1<<5)  /* Threshold value bit 5 mask. */
#define ADC_CMN_THRESHOLD5_bp  5  /* Threshold value bit 5 position. */
#define ADC_CMN_THRESHOLD6_bm  (1<<6)  /* Threshold value bit 6 mask. */
#define ADC_CMN_THRESHOLD6_bp  6  /* Threshold value bit 6 position. */
#define ADC_CMN_THRESHOLD7_bm  (1<<7)  /* Threshold value bit 7 mask. */
#define ADC_CMN_THRESHOLD7_bp  7  /* Threshold value bit 7 position. */

/* ADC_CMN.CAL  bit masks and bit positions */
#define ADC_CMN_CAL_gm  0xFF  /* ADC calibration value group mask. */
#define ADC_CMN_CAL_gp  0  /* ADC calibration value group position. */
#define ADC_CMN_CAL0_bm  (1<<0)  /* ADC calibration value bit 0 mask. */
#define ADC_CMN_CAL0_bp  0  /* ADC calibration value bit 0 position. */
#define ADC_CMN_CAL1_bm  (1<<1)  /* ADC calibration value bit 1 mask. */
#define ADC_CMN_CAL1_bp  1  /* ADC calibration value bit 1 position. */
#define ADC_CMN_CAL2_bm  (1<<2)  /* ADC calibration value bit 2 mask. */
#define ADC_CMN_CAL2_bp  2  /* ADC calibration value bit 2 position. */
#define ADC_CMN_CAL3_bm  (1<<3)  /* ADC calibration value bit 3 mask. */
#define ADC_CMN_CAL3_bp  3  /* ADC calibration value bit 3 position. */
#define ADC_CMN_CAL4_bm  (1<<4)  /* ADC calibration value bit 4 mask. */
#define ADC_CMN_CAL4_bp  4  /* ADC calibration value bit 4 position. */
#define ADC_CMN_CAL5_bm  (1<<5)  /* ADC calibration value bit 5 mask. */
#define ADC_CMN_CAL5_bp  5  /* ADC calibration value bit 5 position. */
#define ADC_CMN_CAL6_bm  (1<<6)  /* ADC calibration value bit 6 mask. */
#define ADC_CMN_CAL6_bp  6  /* ADC calibration value bit 6 position. */
#define ADC_CMN_CAL7_bm  (1<<7)  /* ADC calibration value bit 7 mask. */
#define ADC_CMN_CAL7_bp  7  /* ADC calibration value bit 7 position. */

/* ADC_GEN_CH - ADC General Channel */
/* ADC_GEN_CH.CTRLA  bit masks and bit positions */
#define ADC_GEN_CH_GAIN_gm  0x1C  /* Gain Factor group mask. */
#define ADC_GEN_CH_GAIN_gp  2  /* Gain Factor group position. */
#define ADC_GEN_CH_GAIN0_bm  (1<<2)  /* Gain Factor bit 0 mask. */
#define ADC_GEN_CH_GAIN0_bp  2  /* Gain Factor bit 0 position. */
#define ADC_GEN_CH_GAIN1_bm  (1<<3)  /* Gain Factor bit 1 mask. */
#define ADC_GEN_CH_GAIN1_bp  3  /* Gain Factor bit 1 position. */
#define ADC_GEN_CH_GAIN2_bm  (1<<4)  /* Gain Factor bit 2 mask. */
#define ADC_GEN_CH_GAIN2_bp  4  /* Gain Factor bit 2 position. */
#define ADC_GEN_CH_START_bm  0x80  /* Start Conversion bit mask. */
#define ADC_GEN_CH_START_bp  7  /* Start Conversion bit position. */

/* ADC_GEN_CH.SAMPCTRL  bit masks and bit positions */
#define ADC_GEN_CH_SAMPVAL_gm  0x3F  /* Sampling Time Control group mask. */
#define ADC_GEN_CH_SAMPVAL_gp  0  /* Sampling Time Control group position. */
#define ADC_GEN_CH_SAMPVAL0_bm  (1<<0)  /* Sampling Time Control bit 0 mask. */
#define ADC_GEN_CH_SAMPVAL0_bp  0  /* Sampling Time Control bit 0 position. */
#define ADC_GEN_CH_SAMPVAL1_bm  (1<<1)  /* Sampling Time Control bit 1 mask. */
#define ADC_GEN_CH_SAMPVAL1_bp  1  /* Sampling Time Control bit 1 position. */
#define ADC_GEN_CH_SAMPVAL2_bm  (1<<2)  /* Sampling Time Control bit 2 mask. */
#define ADC_GEN_CH_SAMPVAL2_bp  2  /* Sampling Time Control bit 2 position. */
#define ADC_GEN_CH_SAMPVAL3_bm  (1<<3)  /* Sampling Time Control bit 3 mask. */
#define ADC_GEN_CH_SAMPVAL3_bp  3  /* Sampling Time Control bit 3 position. */
#define ADC_GEN_CH_SAMPVAL4_bm  (1<<4)  /* Sampling Time Control bit 4 mask. */
#define ADC_GEN_CH_SAMPVAL4_bp  4  /* Sampling Time Control bit 4 position. */
#define ADC_GEN_CH_SAMPVAL5_bm  (1<<5)  /* Sampling Time Control bit 5 mask. */
#define ADC_GEN_CH_SAMPVAL5_bp  5  /* Sampling Time Control bit 5 position. */

/* ADC_GEN_CH.MUXCTRL  bit masks and bit positions */
#define ADC_GEN_CH_MUXNEG_gm  0x07  /* MUX Selection on negative ADC input group mask. */
#define ADC_GEN_CH_MUXNEG_gp  0  /* MUX Selection on negative ADC input group position. */
#define ADC_GEN_CH_MUXNEG0_bm  (1<<0)  /* MUX Selection on negative ADC input bit 0 mask. */
#define ADC_GEN_CH_MUXNEG0_bp  0  /* MUX Selection on negative ADC input bit 0 position. */
#define ADC_GEN_CH_MUXNEG1_bm  (1<<1)  /* MUX Selection on negative ADC input bit 1 mask. */
#define ADC_GEN_CH_MUXNEG1_bp  1  /* MUX Selection on negative ADC input bit 1 position. */
#define ADC_GEN_CH_MUXNEG2_bm  (1<<2)  /* MUX Selection on negative ADC input bit 2 mask. */
#define ADC_GEN_CH_MUXNEG2_bp  2  /* MUX Selection on negative ADC input bit 2 position. */
#define ADC_GEN_CH_MUXPOS_gm  0x70  /* MUX Selection on positive ADC input group mask. */
#define ADC_GEN_CH_MUXPOS_gp  4  /* MUX Selection on positive ADC input group position. */
#define ADC_GEN_CH_MUXPOS0_bm  (1<<4)  /* MUX Selection on positive ADC input bit 0 mask. */
#define ADC_GEN_CH_MUXPOS0_bp  4  /* MUX Selection on positive ADC input bit 0 position. */
#define ADC_GEN_CH_MUXPOS1_bm  (1<<5)  /* MUX Selection on positive ADC input bit 1 mask. */
#define ADC_GEN_CH_MUXPOS1_bp  5  /* MUX Selection on positive ADC input bit 1 position. */
#define ADC_GEN_CH_MUXPOS2_bm  (1<<6)  /* MUX Selection on positive ADC input bit 2 mask. */
#define ADC_GEN_CH_MUXPOS2_bp  6  /* MUX Selection on positive ADC input bit 2 position. */

/* ADC_GEN_CH.INTCTRL  bit masks and bit positions */
#define ADC_GEN_CH_INTLVL_gm  0x03  /* Interrupt Level group mask. */
#define ADC_GEN_CH_INTLVL_gp  0  /* Interrupt Level group position. */
#define ADC_GEN_CH_INTLVL0_bm  (1<<0)  /* Interrupt Level bit 0 mask. */
#define ADC_GEN_CH_INTLVL0_bp  0  /* Interrupt Level bit 0 position. */
#define ADC_GEN_CH_INTLVL1_bm  (1<<1)  /* Interrupt Level bit 1 mask. */
#define ADC_GEN_CH_INTLVL1_bp  1  /* Interrupt Level bit 1 position. */

/* ADC_GEN_CH.INTSTATUS  bit masks and bit positions */
#define ADC_GEN_CH_CONVIF_bm  0x01  /* Conversion interrupt flag  bit mask. */
#define ADC_GEN_CH_CONVIF_bp  0  /* Conversion interrupt flag  bit position. */
#define ADC_GEN_CH_ABORTIF_bm  0x02  /* Abort interrupt flag  bit mask. */
#define ADC_GEN_CH_ABORTIF_bp  1  /* Abort interrupt flag  bit position. */
#define ADC_GEN_CH_TXCOLLISION_bm  0x10  /* TX collision flag  bit mask. */
#define ADC_GEN_CH_TXCOLLISION_bp  4  /* TX collision flag  bit position. */

/* ADC_GEN_CH.RESL  bit masks and bit positions */
#define ADC_GEN_CH_RES_gm  0xFF  /* Channel result low byte group mask. */
#define ADC_GEN_CH_RES_gp  0  /* Channel result low byte group position. */
#define ADC_GEN_CH_RES0_bm  (1<<0)  /* Channel result low byte bit 0 mask. */
#define ADC_GEN_CH_RES0_bp  0  /* Channel result low byte bit 0 position. */
#define ADC_GEN_CH_RES1_bm  (1<<1)  /* Channel result low byte bit 1 mask. */
#define ADC_GEN_CH_RES1_bp  1  /* Channel result low byte bit 1 position. */
#define ADC_GEN_CH_RES2_bm  (1<<2)  /* Channel result low byte bit 2 mask. */
#define ADC_GEN_CH_RES2_bp  2  /* Channel result low byte bit 2 position. */
#define ADC_GEN_CH_RES3_bm  (1<<3)  /* Channel result low byte bit 3 mask. */
#define ADC_GEN_CH_RES3_bp  3  /* Channel result low byte bit 3 position. */
#define ADC_GEN_CH_RES4_bm  (1<<4)  /* Channel result low byte bit 4 mask. */
#define ADC_GEN_CH_RES4_bp  4  /* Channel result low byte bit 4 position. */
#define ADC_GEN_CH_RES5_bm  (1<<5)  /* Channel result low byte bit 5 mask. */
#define ADC_GEN_CH_RES5_bp  5  /* Channel result low byte bit 5 position. */
#define ADC_GEN_CH_RES6_bm  (1<<6)  /* Channel result low byte bit 6 mask. */
#define ADC_GEN_CH_RES6_bp  6  /* Channel result low byte bit 6 position. */
#define ADC_GEN_CH_RES7_bm  (1<<7)  /* Channel result low byte bit 7 mask. */
#define ADC_GEN_CH_RES7_bp  7  /* Channel result low byte bit 7 position. */

/* ADC_GEN_CH.RESH  bit masks and bit positions */
/* ADC_GEN_CH_RES  is already defined. */

/* ADC_GEN_CH.REFCTRL  bit masks and bit positions */
#define ADC_GEN_CH_TEMPREFEN_bm  0x01  /* Temperature reference enable bit mask. */
#define ADC_GEN_CH_TEMPREFEN_bp  0  /* Temperature reference enable bit position. */
#define ADC_GEN_CH_REFGENSEL_gm  0x0E  /* Reference generator select group mask. */
#define ADC_GEN_CH_REFGENSEL_gp  1  /* Reference generator select group position. */
#define ADC_GEN_CH_REFGENSEL0_bm  (1<<1)  /* Reference generator select bit 0 mask. */
#define ADC_GEN_CH_REFGENSEL0_bp  1  /* Reference generator select bit 0 position. */
#define ADC_GEN_CH_REFGENSEL1_bm  (1<<2)  /* Reference generator select bit 1 mask. */
#define ADC_GEN_CH_REFGENSEL1_bp  2  /* Reference generator select bit 1 position. */
#define ADC_GEN_CH_REFGENSEL2_bm  (1<<3)  /* Reference generator select bit 2 mask. */
#define ADC_GEN_CH_REFGENSEL2_bp  3  /* Reference generator select bit 2 position. */
#define ADC_GEN_CH_REFSEL_gm  0x70  /* Channel reference select group mask. */
#define ADC_GEN_CH_REFSEL_gp  4  /* Channel reference select group position. */
#define ADC_GEN_CH_REFSEL0_bm  (1<<4)  /* Channel reference select bit 0 mask. */
#define ADC_GEN_CH_REFSEL0_bp  4  /* Channel reference select bit 0 position. */
#define ADC_GEN_CH_REFSEL1_bm  (1<<5)  /* Channel reference select bit 1 mask. */
#define ADC_GEN_CH_REFSEL1_bp  5  /* Channel reference select bit 1 position. */
#define ADC_GEN_CH_REFSEL2_bm  (1<<6)  /* Channel reference select bit 2 mask. */
#define ADC_GEN_CH_REFSEL2_bp  6  /* Channel reference select bit 2 position. */

/* ADC_GEN_CH.RESHTMP  bit masks and bit positions */
#define ADC_GEN_CH_RESHTMP_gm  0xFF  /* Temporary channel result high byte group mask. */
#define ADC_GEN_CH_RESHTMP_gp  0  /* Temporary channel result high byte group position. */
#define ADC_GEN_CH_RESHTMP0_bm  (1<<0)  /* Temporary channel result high byte bit 0 mask. */
#define ADC_GEN_CH_RESHTMP0_bp  0  /* Temporary channel result high byte bit 0 position. */
#define ADC_GEN_CH_RESHTMP1_bm  (1<<1)  /* Temporary channel result high byte bit 1 mask. */
#define ADC_GEN_CH_RESHTMP1_bp  1  /* Temporary channel result high byte bit 1 position. */
#define ADC_GEN_CH_RESHTMP2_bm  (1<<2)  /* Temporary channel result high byte bit 2 mask. */
#define ADC_GEN_CH_RESHTMP2_bp  2  /* Temporary channel result high byte bit 2 position. */
#define ADC_GEN_CH_RESHTMP3_bm  (1<<3)  /* Temporary channel result high byte bit 3 mask. */
#define ADC_GEN_CH_RESHTMP3_bp  3  /* Temporary channel result high byte bit 3 position. */
#define ADC_GEN_CH_RESHTMP4_bm  (1<<4)  /* Temporary channel result high byte bit 4 mask. */
#define ADC_GEN_CH_RESHTMP4_bp  4  /* Temporary channel result high byte bit 4 position. */
#define ADC_GEN_CH_RESHTMP5_bm  (1<<5)  /* Temporary channel result high byte bit 5 mask. */
#define ADC_GEN_CH_RESHTMP5_bp  5  /* Temporary channel result high byte bit 5 position. */
#define ADC_GEN_CH_RESHTMP6_bm  (1<<6)  /* Temporary channel result high byte bit 6 mask. */
#define ADC_GEN_CH_RESHTMP6_bp  6  /* Temporary channel result high byte bit 6 position. */
#define ADC_GEN_CH_RESHTMP7_bm  (1<<7)  /* Temporary channel result high byte bit 7 mask. */
#define ADC_GEN_CH_RESHTMP7_bp  7  /* Temporary channel result high byte bit 7 position. */

/* BANDGAP - Bandgap */
/* BANDGAP.CTRL  bit masks and bit positions */
#define BANDGAP_SAMPTIMOFF_gm  0x07  /* Sample mode off timing group mask. */
#define BANDGAP_SAMPTIMOFF_gp  0  /* Sample mode off timing group position. */
#define BANDGAP_SAMPTIMOFF0_bm  (1<<0)  /* Sample mode off timing bit 0 mask. */
#define BANDGAP_SAMPTIMOFF0_bp  0  /* Sample mode off timing bit 0 position. */
#define BANDGAP_SAMPTIMOFF1_bm  (1<<1)  /* Sample mode off timing bit 1 mask. */
#define BANDGAP_SAMPTIMOFF1_bp  1  /* Sample mode off timing bit 1 position. */
#define BANDGAP_SAMPTIMOFF2_bm  (1<<2)  /* Sample mode off timing bit 2 mask. */
#define BANDGAP_SAMPTIMOFF2_bp  2  /* Sample mode off timing bit 2 position. */
#define BANDGAP_SBSY_bm  0x08  /* Synchronization busy bit mask. */
#define BANDGAP_SBSY_bp  3  /* Synchronization busy bit position. */
#define BANDGAP_SAMPTIMON_gm  0xF0  /* Sample mode on timing group mask. */
#define BANDGAP_SAMPTIMON_gp  4  /* Sample mode on timing group position. */
#define BANDGAP_SAMPTIMON0_bm  (1<<4)  /* Sample mode on timing bit 0 mask. */
#define BANDGAP_SAMPTIMON0_bp  4  /* Sample mode on timing bit 0 position. */
#define BANDGAP_SAMPTIMON1_bm  (1<<5)  /* Sample mode on timing bit 1 mask. */
#define BANDGAP_SAMPTIMON1_bp  5  /* Sample mode on timing bit 1 position. */
#define BANDGAP_SAMPTIMON2_bm  (1<<6)  /* Sample mode on timing bit 2 mask. */
#define BANDGAP_SAMPTIMON2_bp  6  /* Sample mode on timing bit 2 position. */
#define BANDGAP_SAMPTIMON3_bm  (1<<7)  /* Sample mode on timing bit 3 mask. */
#define BANDGAP_SAMPTIMON3_bp  7  /* Sample mode on timing bit 3 position. */

/* BIASCTRL - BIASCTRL */
/* BIASCTRL.CTRL  bit masks and bit positions */
#define BIASCTRL_BIAS1uA_bm  0x01  /* BIAS 1uA Auto bit mask. */
#define BIASCTRL_BIAS1uA_bp  0  /* BIAS 1uA Auto bit position. */

/* BOOSTIF - Boost Converter Interface */
/* BOOSTIF.CTRLA  bit masks and bit positions */
#define BOOSTIF_EN_bm  0x01  /* Boost Converter Enable bit mask. */
#define BOOSTIF_EN_bp  0  /* Boost Converter Enable bit position. */
#define BOOSTIF_REFRESH_gm  0x0E  /* Refresh Interval group mask. */
#define BOOSTIF_REFRESH_gp  1  /* Refresh Interval group position. */
#define BOOSTIF_REFRESH0_bm  (1<<1)  /* Refresh Interval bit 0 mask. */
#define BOOSTIF_REFRESH0_bp  1  /* Refresh Interval bit 0 position. */
#define BOOSTIF_REFRESH1_bm  (1<<2)  /* Refresh Interval bit 1 mask. */
#define BOOSTIF_REFRESH1_bp  2  /* Refresh Interval bit 1 position. */
#define BOOSTIF_REFRESH2_bm  (1<<3)  /* Refresh Interval bit 2 mask. */
#define BOOSTIF_REFRESH2_bp  3  /* Refresh Interval bit 2 position. */
#define BOOSTIF_SLOWSTART_bm  0x10  /* Enable Slowstart Mode bit mask. */
#define BOOSTIF_SLOWSTART_bp  4  /* Enable Slowstart Mode bit position. */
#define BOOSTIF_OUTDIS_bm  0x20  /* Output Disable bit mask. */
#define BOOSTIF_OUTDIS_bp  5  /* Output Disable bit position. */
#define BOOSTIF_WAITFINISH_bm  0x40  /* Wait Finish Enable bit mask. */
#define BOOSTIF_WAITFINISH_bp  6  /* Wait Finish Enable bit position. */

/* BOOSTIF.CTRLB  bit masks and bit positions */
#define BOOSTIF_SLOWSTARTCTRL_gm  0x07  /* Slow start sequence duration group mask. */
#define BOOSTIF_SLOWSTARTCTRL_gp  0  /* Slow start sequence duration group position. */
#define BOOSTIF_SLOWSTARTCTRL0_bm  (1<<0)  /* Slow start sequence duration bit 0 mask. */
#define BOOSTIF_SLOWSTARTCTRL0_bp  0  /* Slow start sequence duration bit 0 position. */
#define BOOSTIF_SLOWSTARTCTRL1_bm  (1<<1)  /* Slow start sequence duration bit 1 mask. */
#define BOOSTIF_SLOWSTARTCTRL1_bp  1  /* Slow start sequence duration bit 1 position. */
#define BOOSTIF_SLOWSTARTCTRL2_bm  (1<<2)  /* Slow start sequence duration bit 2 mask. */
#define BOOSTIF_SLOWSTARTCTRL2_bp  2  /* Slow start sequence duration bit 2 position. */

/* BOOSTIF.LEVEL  bit masks and bit positions */
#define BOOSTIF_LEVEL_gm  0x1F  /* Boost Converter Voltage Level group mask. */
#define BOOSTIF_LEVEL_gp  0  /* Boost Converter Voltage Level group position. */
#define BOOSTIF_LEVEL0_bm  (1<<0)  /* Boost Converter Voltage Level bit 0 mask. */
#define BOOSTIF_LEVEL0_bp  0  /* Boost Converter Voltage Level bit 0 position. */
#define BOOSTIF_LEVEL1_bm  (1<<1)  /* Boost Converter Voltage Level bit 1 mask. */
#define BOOSTIF_LEVEL1_bp  1  /* Boost Converter Voltage Level bit 1 position. */
#define BOOSTIF_LEVEL2_bm  (1<<2)  /* Boost Converter Voltage Level bit 2 mask. */
#define BOOSTIF_LEVEL2_bp  2  /* Boost Converter Voltage Level bit 2 position. */
#define BOOSTIF_LEVEL3_bm  (1<<3)  /* Boost Converter Voltage Level bit 3 mask. */
#define BOOSTIF_LEVEL3_bp  3  /* Boost Converter Voltage Level bit 3 position. */
#define BOOSTIF_LEVEL4_bm  (1<<4)  /* Boost Converter Voltage Level bit 4 mask. */
#define BOOSTIF_LEVEL4_bp  4  /* Boost Converter Voltage Level bit 4 position. */

/* BOOSTIF.CNTHIGH  bit masks and bit positions */
#define BOOSTIF_CNTHIGH_gm  0x7F  /* High-period Cycle Count group mask. */
#define BOOSTIF_CNTHIGH_gp  0  /* High-period Cycle Count group position. */
#define BOOSTIF_CNTHIGH0_bm  (1<<0)  /* High-period Cycle Count bit 0 mask. */
#define BOOSTIF_CNTHIGH0_bp  0  /* High-period Cycle Count bit 0 position. */
#define BOOSTIF_CNTHIGH1_bm  (1<<1)  /* High-period Cycle Count bit 1 mask. */
#define BOOSTIF_CNTHIGH1_bp  1  /* High-period Cycle Count bit 1 position. */
#define BOOSTIF_CNTHIGH2_bm  (1<<2)  /* High-period Cycle Count bit 2 mask. */
#define BOOSTIF_CNTHIGH2_bp  2  /* High-period Cycle Count bit 2 position. */
#define BOOSTIF_CNTHIGH3_bm  (1<<3)  /* High-period Cycle Count bit 3 mask. */
#define BOOSTIF_CNTHIGH3_bp  3  /* High-period Cycle Count bit 3 position. */
#define BOOSTIF_CNTHIGH4_bm  (1<<4)  /* High-period Cycle Count bit 4 mask. */
#define BOOSTIF_CNTHIGH4_bp  4  /* High-period Cycle Count bit 4 position. */
#define BOOSTIF_CNTHIGH5_bm  (1<<5)  /* High-period Cycle Count bit 5 mask. */
#define BOOSTIF_CNTHIGH5_bp  5  /* High-period Cycle Count bit 5 position. */
#define BOOSTIF_CNTHIGH6_bm  (1<<6)  /* High-period Cycle Count bit 6 mask. */
#define BOOSTIF_CNTHIGH6_bp  6  /* High-period Cycle Count bit 6 position. */

/* BOOSTIF.CNTLOW  bit masks and bit positions */
#define BOOSTIF_CNTLOW_gm  0x7F  /* Low-period Cycle Count group mask. */
#define BOOSTIF_CNTLOW_gp  0  /* Low-period Cycle Count group position. */
#define BOOSTIF_CNTLOW0_bm  (1<<0)  /* Low-period Cycle Count bit 0 mask. */
#define BOOSTIF_CNTLOW0_bp  0  /* Low-period Cycle Count bit 0 position. */
#define BOOSTIF_CNTLOW1_bm  (1<<1)  /* Low-period Cycle Count bit 1 mask. */
#define BOOSTIF_CNTLOW1_bp  1  /* Low-period Cycle Count bit 1 position. */
#define BOOSTIF_CNTLOW2_bm  (1<<2)  /* Low-period Cycle Count bit 2 mask. */
#define BOOSTIF_CNTLOW2_bp  2  /* Low-period Cycle Count bit 2 position. */
#define BOOSTIF_CNTLOW3_bm  (1<<3)  /* Low-period Cycle Count bit 3 mask. */
#define BOOSTIF_CNTLOW3_bp  3  /* Low-period Cycle Count bit 3 position. */
#define BOOSTIF_CNTLOW4_bm  (1<<4)  /* Low-period Cycle Count bit 4 mask. */
#define BOOSTIF_CNTLOW4_bp  4  /* Low-period Cycle Count bit 4 position. */
#define BOOSTIF_CNTLOW5_bm  (1<<5)  /* Low-period Cycle Count bit 5 mask. */
#define BOOSTIF_CNTLOW5_bp  5  /* Low-period Cycle Count bit 5 position. */
#define BOOSTIF_CNTLOW6_bm  (1<<6)  /* Low-period Cycle Count bit 6 mask. */
#define BOOSTIF_CNTLOW6_bp  6  /* Low-period Cycle Count bit 6 position. */

/* BOOSTIF.TEST  bit masks and bit positions */
#define BOOSTIF_RAW_bm  0x01  /* NFET switch use analog output bit mask. */
#define BOOSTIF_RAW_bp  0  /* NFET switch use analog output bit position. */
#define BOOSTIF_ABOVE_bm  0x02  /* Regulated voltage level above configured level bit mask. */
#define BOOSTIF_ABOVE_bp  1  /* Regulated voltage level above configured level bit position. */
#define BOOSTIF_PINOD_bm  0x04  /* Pin Override Disable bit mask. */
#define BOOSTIF_PINOD_bp  2  /* Pin Override Disable bit position. */

/* BOOSTIF.SETTLE  bit masks and bit positions */
#define BOOSTIF_SETTLE_gm  0x0F  /* Analog Settle Time group mask. */
#define BOOSTIF_SETTLE_gp  0  /* Analog Settle Time group position. */
#define BOOSTIF_SETTLE0_bm  (1<<0)  /* Analog Settle Time bit 0 mask. */
#define BOOSTIF_SETTLE0_bp  0  /* Analog Settle Time bit 0 position. */
#define BOOSTIF_SETTLE1_bm  (1<<1)  /* Analog Settle Time bit 1 mask. */
#define BOOSTIF_SETTLE1_bp  1  /* Analog Settle Time bit 1 position. */
#define BOOSTIF_SETTLE2_bm  (1<<2)  /* Analog Settle Time bit 2 mask. */
#define BOOSTIF_SETTLE2_bp  2  /* Analog Settle Time bit 2 position. */
#define BOOSTIF_SETTLE3_bm  (1<<3)  /* Analog Settle Time bit 3 mask. */
#define BOOSTIF_SETTLE3_bp  3  /* Analog Settle Time bit 3 position. */

/* CLK - Clock System */
/* CLK.CLKPSR  bit masks and bit positions */
#define CLK_CLKPS_gm  0x03  /* Clock Prescale Divide Factor group mask. */
#define CLK_CLKPS_gp  0  /* Clock Prescale Divide Factor group position. */
#define CLK_CLKPS0_bm  (1<<0)  /* Clock Prescale Divide Factor bit 0 mask. */
#define CLK_CLKPS0_bp  0  /* Clock Prescale Divide Factor bit 0 position. */
#define CLK_CLKPS1_bm  (1<<1)  /* Clock Prescale Divide Factor bit 1 mask. */
#define CLK_CLKPS1_bp  1  /* Clock Prescale Divide Factor bit 1 position. */

/* CLK.CLKSLR  bit masks and bit positions */
#define CLK_CLKSL_bm  0x01  /* Clock Settings Lock bit mask. */
#define CLK_CLKSL_bp  0  /* Clock Settings Lock bit position. */

/* CLK.FRCCALL  bit masks and bit positions */
#define CLK_CAL_gm  0xFF  /* Fast RC Calibration group mask. */
#define CLK_CAL_gp  0  /* Fast RC Calibration group position. */
#define CLK_CAL0_bm  (1<<0)  /* Fast RC Calibration bit 0 mask. */
#define CLK_CAL0_bp  0  /* Fast RC Calibration bit 0 position. */
#define CLK_CAL1_bm  (1<<1)  /* Fast RC Calibration bit 1 mask. */
#define CLK_CAL1_bp  1  /* Fast RC Calibration bit 1 position. */
#define CLK_CAL2_bm  (1<<2)  /* Fast RC Calibration bit 2 mask. */
#define CLK_CAL2_bp  2  /* Fast RC Calibration bit 2 position. */
#define CLK_CAL3_bm  (1<<3)  /* Fast RC Calibration bit 3 mask. */
#define CLK_CAL3_bp  3  /* Fast RC Calibration bit 3 position. */
#define CLK_CAL4_bm  (1<<4)  /* Fast RC Calibration bit 4 mask. */
#define CLK_CAL4_bp  4  /* Fast RC Calibration bit 4 position. */
#define CLK_CAL5_bm  (1<<5)  /* Fast RC Calibration bit 5 mask. */
#define CLK_CAL5_bp  5  /* Fast RC Calibration bit 5 position. */
#define CLK_CAL6_bm  (1<<6)  /* Fast RC Calibration bit 6 mask. */
#define CLK_CAL6_bp  6  /* Fast RC Calibration bit 6 position. */
#define CLK_CAL7_bm  (1<<7)  /* Fast RC Calibration bit 7 mask. */
#define CLK_CAL7_bp  7  /* Fast RC Calibration bit 7 position. */

/* CLK.FRCCALH  bit masks and bit positions */
/* CLK_CAL  is already defined. */

/* CLK.ULPRCCALL  bit masks and bit positions */
/* CLK_CAL  is already defined. */

/* CLK.ULPRCCALH  bit masks and bit positions */
/* CLK_CAL  is already defined. */

/* CPU - CPU */
/* CPU.CCP  bit masks and bit positions */
#define CPU_CCP_gm  0xFF  /* CCP signature group mask. */
#define CPU_CCP_gp  0  /* CCP signature group position. */
#define CPU_CCP0_bm  (1<<0)  /* CCP signature bit 0 mask. */
#define CPU_CCP0_bp  0  /* CCP signature bit 0 position. */
#define CPU_CCP1_bm  (1<<1)  /* CCP signature bit 1 mask. */
#define CPU_CCP1_bp  1  /* CCP signature bit 1 position. */
#define CPU_CCP2_bm  (1<<2)  /* CCP signature bit 2 mask. */
#define CPU_CCP2_bp  2  /* CCP signature bit 2 position. */
#define CPU_CCP3_bm  (1<<3)  /* CCP signature bit 3 mask. */
#define CPU_CCP3_bp  3  /* CCP signature bit 3 position. */
#define CPU_CCP4_bm  (1<<4)  /* CCP signature bit 4 mask. */
#define CPU_CCP4_bp  4  /* CCP signature bit 4 position. */
#define CPU_CCP5_bm  (1<<5)  /* CCP signature bit 5 mask. */
#define CPU_CCP5_bp  5  /* CCP signature bit 5 position. */
#define CPU_CCP6_bm  (1<<6)  /* CCP signature bit 6 mask. */
#define CPU_CCP6_bp  6  /* CCP signature bit 6 position. */
#define CPU_CCP7_bm  (1<<7)  /* CCP signature bit 7 mask. */
#define CPU_CCP7_bp  7  /* CCP signature bit 7 position. */

/* CPU.RAMPD  bit masks and bit positions */
#define CPU_RAMPD_gm  0xFF  /* Extended Direct Addressing bits group mask. */
#define CPU_RAMPD_gp  0  /* Extended Direct Addressing bits group position. */
#define CPU_RAMPD0_bm  (1<<0)  /* Extended Direct Addressing bits bit 0 mask. */
#define CPU_RAMPD0_bp  0  /* Extended Direct Addressing bits bit 0 position. */
#define CPU_RAMPD1_bm  (1<<1)  /* Extended Direct Addressing bits bit 1 mask. */
#define CPU_RAMPD1_bp  1  /* Extended Direct Addressing bits bit 1 position. */
#define CPU_RAMPD2_bm  (1<<2)  /* Extended Direct Addressing bits bit 2 mask. */
#define CPU_RAMPD2_bp  2  /* Extended Direct Addressing bits bit 2 position. */
#define CPU_RAMPD3_bm  (1<<3)  /* Extended Direct Addressing bits bit 3 mask. */
#define CPU_RAMPD3_bp  3  /* Extended Direct Addressing bits bit 3 position. */
#define CPU_RAMPD4_bm  (1<<4)  /* Extended Direct Addressing bits bit 4 mask. */
#define CPU_RAMPD4_bp  4  /* Extended Direct Addressing bits bit 4 position. */
#define CPU_RAMPD5_bm  (1<<5)  /* Extended Direct Addressing bits bit 5 mask. */
#define CPU_RAMPD5_bp  5  /* Extended Direct Addressing bits bit 5 position. */
#define CPU_RAMPD6_bm  (1<<6)  /* Extended Direct Addressing bits bit 6 mask. */
#define CPU_RAMPD6_bp  6  /* Extended Direct Addressing bits bit 6 position. */
#define CPU_RAMPD7_bm  (1<<7)  /* Extended Direct Addressing bits bit 7 mask. */
#define CPU_RAMPD7_bp  7  /* Extended Direct Addressing bits bit 7 position. */

/* CPU.RAMPX  bit masks and bit positions */
#define CPU_RAMPX_gm  0xFF  /* Extended X-pointer Address bits group mask. */
#define CPU_RAMPX_gp  0  /* Extended X-pointer Address bits group position. */
#define CPU_RAMPX0_bm  (1<<0)  /* Extended X-pointer Address bits bit 0 mask. */
#define CPU_RAMPX0_bp  0  /* Extended X-pointer Address bits bit 0 position. */
#define CPU_RAMPX1_bm  (1<<1)  /* Extended X-pointer Address bits bit 1 mask. */
#define CPU_RAMPX1_bp  1  /* Extended X-pointer Address bits bit 1 position. */
#define CPU_RAMPX2_bm  (1<<2)  /* Extended X-pointer Address bits bit 2 mask. */
#define CPU_RAMPX2_bp  2  /* Extended X-pointer Address bits bit 2 position. */
#define CPU_RAMPX3_bm  (1<<3)  /* Extended X-pointer Address bits bit 3 mask. */
#define CPU_RAMPX3_bp  3  /* Extended X-pointer Address bits bit 3 position. */
#define CPU_RAMPX4_bm  (1<<4)  /* Extended X-pointer Address bits bit 4 mask. */
#define CPU_RAMPX4_bp  4  /* Extended X-pointer Address bits bit 4 position. */
#define CPU_RAMPX5_bm  (1<<5)  /* Extended X-pointer Address bits bit 5 mask. */
#define CPU_RAMPX5_bp  5  /* Extended X-pointer Address bits bit 5 position. */
#define CPU_RAMPX6_bm  (1<<6)  /* Extended X-pointer Address bits bit 6 mask. */
#define CPU_RAMPX6_bp  6  /* Extended X-pointer Address bits bit 6 position. */
#define CPU_RAMPX7_bm  (1<<7)  /* Extended X-pointer Address bits bit 7 mask. */
#define CPU_RAMPX7_bp  7  /* Extended X-pointer Address bits bit 7 position. */

/* CPU.RAMPY  bit masks and bit positions */
#define CPU_RAMPY_gm  0xFF  /* Extended Y-pointer Address bits group mask. */
#define CPU_RAMPY_gp  0  /* Extended Y-pointer Address bits group position. */
#define CPU_RAMPY0_bm  (1<<0)  /* Extended Y-pointer Address bits bit 0 mask. */
#define CPU_RAMPY0_bp  0  /* Extended Y-pointer Address bits bit 0 position. */
#define CPU_RAMPY1_bm  (1<<1)  /* Extended Y-pointer Address bits bit 1 mask. */
#define CPU_RAMPY1_bp  1  /* Extended Y-pointer Address bits bit 1 position. */
#define CPU_RAMPY2_bm  (1<<2)  /* Extended Y-pointer Address bits bit 2 mask. */
#define CPU_RAMPY2_bp  2  /* Extended Y-pointer Address bits bit 2 position. */
#define CPU_RAMPY3_bm  (1<<3)  /* Extended Y-pointer Address bits bit 3 mask. */
#define CPU_RAMPY3_bp  3  /* Extended Y-pointer Address bits bit 3 position. */
#define CPU_RAMPY4_bm  (1<<4)  /* Extended Y-pointer Address bits bit 4 mask. */
#define CPU_RAMPY4_bp  4  /* Extended Y-pointer Address bits bit 4 position. */
#define CPU_RAMPY5_bm  (1<<5)  /* Extended Y-pointer Address bits bit 5 mask. */
#define CPU_RAMPY5_bp  5  /* Extended Y-pointer Address bits bit 5 position. */
#define CPU_RAMPY6_bm  (1<<6)  /* Extended Y-pointer Address bits bit 6 mask. */
#define CPU_RAMPY6_bp  6  /* Extended Y-pointer Address bits bit 6 position. */
#define CPU_RAMPY7_bm  (1<<7)  /* Extended Y-pointer Address bits bit 7 mask. */
#define CPU_RAMPY7_bp  7  /* Extended Y-pointer Address bits bit 7 position. */

/* CPU.RAMPZ  bit masks and bit positions */
#define CPU_RAMPZ_gm  0xFF  /* Extended Z-pointer Address bits group mask. */
#define CPU_RAMPZ_gp  0  /* Extended Z-pointer Address bits group position. */
#define CPU_RAMPZ0_bm  (1<<0)  /* Extended Z-pointer Address bits bit 0 mask. */
#define CPU_RAMPZ0_bp  0  /* Extended Z-pointer Address bits bit 0 position. */
#define CPU_RAMPZ1_bm  (1<<1)  /* Extended Z-pointer Address bits bit 1 mask. */
#define CPU_RAMPZ1_bp  1  /* Extended Z-pointer Address bits bit 1 position. */
#define CPU_RAMPZ2_bm  (1<<2)  /* Extended Z-pointer Address bits bit 2 mask. */
#define CPU_RAMPZ2_bp  2  /* Extended Z-pointer Address bits bit 2 position. */
#define CPU_RAMPZ3_bm  (1<<3)  /* Extended Z-pointer Address bits bit 3 mask. */
#define CPU_RAMPZ3_bp  3  /* Extended Z-pointer Address bits bit 3 position. */
#define CPU_RAMPZ4_bm  (1<<4)  /* Extended Z-pointer Address bits bit 4 mask. */
#define CPU_RAMPZ4_bp  4  /* Extended Z-pointer Address bits bit 4 position. */
#define CPU_RAMPZ5_bm  (1<<5)  /* Extended Z-pointer Address bits bit 5 mask. */
#define CPU_RAMPZ5_bp  5  /* Extended Z-pointer Address bits bit 5 position. */
#define CPU_RAMPZ6_bm  (1<<6)  /* Extended Z-pointer Address bits bit 6 mask. */
#define CPU_RAMPZ6_bp  6  /* Extended Z-pointer Address bits bit 6 position. */
#define CPU_RAMPZ7_bm  (1<<7)  /* Extended Z-pointer Address bits bit 7 mask. */
#define CPU_RAMPZ7_bp  7  /* Extended Z-pointer Address bits bit 7 position. */

/* CPU.EIND  bit masks and bit positions */
#define CPU_EIND_gm  0xFF  /* Extended Indirect Address bits group mask. */
#define CPU_EIND_gp  0  /* Extended Indirect Address bits group position. */
#define CPU_EIND0_bm  (1<<0)  /* Extended Indirect Address bits bit 0 mask. */
#define CPU_EIND0_bp  0  /* Extended Indirect Address bits bit 0 position. */
#define CPU_EIND1_bm  (1<<1)  /* Extended Indirect Address bits bit 1 mask. */
#define CPU_EIND1_bp  1  /* Extended Indirect Address bits bit 1 position. */
#define CPU_EIND2_bm  (1<<2)  /* Extended Indirect Address bits bit 2 mask. */
#define CPU_EIND2_bp  2  /* Extended Indirect Address bits bit 2 position. */
#define CPU_EIND3_bm  (1<<3)  /* Extended Indirect Address bits bit 3 mask. */
#define CPU_EIND3_bp  3  /* Extended Indirect Address bits bit 3 position. */
#define CPU_EIND4_bm  (1<<4)  /* Extended Indirect Address bits bit 4 mask. */
#define CPU_EIND4_bp  4  /* Extended Indirect Address bits bit 4 position. */
#define CPU_EIND5_bm  (1<<5)  /* Extended Indirect Address bits bit 5 mask. */
#define CPU_EIND5_bp  5  /* Extended Indirect Address bits bit 5 position. */
#define CPU_EIND6_bm  (1<<6)  /* Extended Indirect Address bits bit 6 mask. */
#define CPU_EIND6_bp  6  /* Extended Indirect Address bits bit 6 position. */
#define CPU_EIND7_bm  (1<<7)  /* Extended Indirect Address bits bit 7 mask. */
#define CPU_EIND7_bp  7  /* Extended Indirect Address bits bit 7 position. */

/* CPU.SPL  bit masks and bit positions */
#define CPU_SP_gm  0xFF  /* Stack Pointer Register Low bits group mask. */
#define CPU_SP_gp  0  /* Stack Pointer Register Low bits group position. */
#define CPU_SP0_bm  (1<<0)  /* Stack Pointer Register Low bits bit 0 mask. */
#define CPU_SP0_bp  0  /* Stack Pointer Register Low bits bit 0 position. */
#define CPU_SP1_bm  (1<<1)  /* Stack Pointer Register Low bits bit 1 mask. */
#define CPU_SP1_bp  1  /* Stack Pointer Register Low bits bit 1 position. */
#define CPU_SP2_bm  (1<<2)  /* Stack Pointer Register Low bits bit 2 mask. */
#define CPU_SP2_bp  2  /* Stack Pointer Register Low bits bit 2 position. */
#define CPU_SP3_bm  (1<<3)  /* Stack Pointer Register Low bits bit 3 mask. */
#define CPU_SP3_bp  3  /* Stack Pointer Register Low bits bit 3 position. */
#define CPU_SP4_bm  (1<<4)  /* Stack Pointer Register Low bits bit 4 mask. */
#define CPU_SP4_bp  4  /* Stack Pointer Register Low bits bit 4 position. */
#define CPU_SP5_bm  (1<<5)  /* Stack Pointer Register Low bits bit 5 mask. */
#define CPU_SP5_bp  5  /* Stack Pointer Register Low bits bit 5 position. */
#define CPU_SP6_bm  (1<<6)  /* Stack Pointer Register Low bits bit 6 mask. */
#define CPU_SP6_bp  6  /* Stack Pointer Register Low bits bit 6 position. */
#define CPU_SP7_bm  (1<<7)  /* Stack Pointer Register Low bits bit 7 mask. */
#define CPU_SP7_bp  7  /* Stack Pointer Register Low bits bit 7 position. */

/* CPU.SPH  bit masks and bit positions */
/* CPU_SP  is already defined. */

/* CPU.SREG  bit masks and bit positions */
#define CPU_C_bm  0x01  /* Carry Flag bit mask. */
#define CPU_C_bp  0  /* Carry Flag bit position. */
#define CPU_Z_bm  0x02  /* Zero Flag bit mask. */
#define CPU_Z_bp  1  /* Zero Flag bit position. */
#define CPU_N_bm  0x04  /* Negative Flag bit mask. */
#define CPU_N_bp  2  /* Negative Flag bit position. */
#define CPU_V_bm  0x08  /* Two's Complement Overflow Flag bit mask. */
#define CPU_V_bp  3  /* Two's Complement Overflow Flag bit position. */
#define CPU_S_bm  0x10  /* N Exclusive Or V Flag bit mask. */
#define CPU_S_bp  4  /* N Exclusive Or V Flag bit position. */
#define CPU_H_bm  0x20  /* Half Carry Flag bit mask. */
#define CPU_H_bp  5  /* Half Carry Flag bit position. */
#define CPU_T_bm  0x40  /* Transfer Bit bit mask. */
#define CPU_T_bp  6  /* Transfer Bit bit position. */
#define CPU_I_bm  0x80  /* Global Interrupt Enable Flag bit mask. */
#define CPU_I_bp  7  /* Global Interrupt Enable Flag bit position. */

/* CRC4 - Cyclic Redundancy Checker */
/* CRC4.DATAIN  bit masks and bit positions */
#define CRC4_DATAIN_gm  0xFF  /* Input data group mask. */
#define CRC4_DATAIN_gp  0  /* Input data group position. */
#define CRC4_DATAIN0_bm  (1<<0)  /* Input data bit 0 mask. */
#define CRC4_DATAIN0_bp  0  /* Input data bit 0 position. */
#define CRC4_DATAIN1_bm  (1<<1)  /* Input data bit 1 mask. */
#define CRC4_DATAIN1_bp  1  /* Input data bit 1 position. */
#define CRC4_DATAIN2_bm  (1<<2)  /* Input data bit 2 mask. */
#define CRC4_DATAIN2_bp  2  /* Input data bit 2 position. */
#define CRC4_DATAIN3_bm  (1<<3)  /* Input data bit 3 mask. */
#define CRC4_DATAIN3_bp  3  /* Input data bit 3 position. */
#define CRC4_DATAIN4_bm  (1<<4)  /* Input data bit 4 mask. */
#define CRC4_DATAIN4_bp  4  /* Input data bit 4 position. */
#define CRC4_DATAIN5_bm  (1<<5)  /* Input data bit 5 mask. */
#define CRC4_DATAIN5_bp  5  /* Input data bit 5 position. */
#define CRC4_DATAIN6_bm  (1<<6)  /* Input data bit 6 mask. */
#define CRC4_DATAIN6_bp  6  /* Input data bit 6 position. */
#define CRC4_DATAIN7_bm  (1<<7)  /* Input data bit 7 mask. */
#define CRC4_DATAIN7_bp  7  /* Input data bit 7 position. */

/* CRC4.CHECKSUM  bit masks and bit positions */
#define CRC4_CHECKSUM_gm  0x0F  /* Checsum group mask. */
#define CRC4_CHECKSUM_gp  0  /* Checsum group position. */
#define CRC4_CHECKSUM0_bm  (1<<0)  /* Checsum bit 0 mask. */
#define CRC4_CHECKSUM0_bp  0  /* Checsum bit 0 position. */
#define CRC4_CHECKSUM1_bm  (1<<1)  /* Checsum bit 1 mask. */
#define CRC4_CHECKSUM1_bp  1  /* Checsum bit 1 position. */
#define CRC4_CHECKSUM2_bm  (1<<2)  /* Checsum bit 2 mask. */
#define CRC4_CHECKSUM2_bp  2  /* Checsum bit 2 position. */
#define CRC4_CHECKSUM3_bm  (1<<3)  /* Checsum bit 3 mask. */
#define CRC4_CHECKSUM3_bp  3  /* Checsum bit 3 position. */

/* FUSES - Fuses and Lockbits */
/* NVM_FUSES.FUSEBYTE4  bit masks and bit positions */
#define NVM_FUSES_WDLOCK_bm  0x02  /* Watchdog Timer Lock bit mask. */
#define NVM_FUSES_WDLOCK_bp  1  /* Watchdog Timer Lock bit position. */
#define NVM_FUSES_SUT_gm  0x0C  /* Start-up Time group mask. */
#define NVM_FUSES_SUT_gp  2  /* Start-up Time group position. */
#define NVM_FUSES_SUT0_bm  (1<<2)  /* Start-up Time bit 0 mask. */
#define NVM_FUSES_SUT0_bp  2  /* Start-up Time bit 0 position. */
#define NVM_FUSES_SUT1_bm  (1<<3)  /* Start-up Time bit 1 mask. */
#define NVM_FUSES_SUT1_bp  3  /* Start-up Time bit 1 position. */
#define NVM_FUSES_RSTDISBL_bm  0x10  /* External Reset Disable bit mask. */
#define NVM_FUSES_RSTDISBL_bp  4  /* External Reset Disable bit position. */
#define NVM_FUSES_BOOTRST_bm  0x20  /* Boot Loader Section Reset Vector bit mask. */
#define NVM_FUSES_BOOTRST_bp  5  /* Boot Loader Section Reset Vector bit position. */

/* NVM_FUSES.FUSEBYTE5  bit masks and bit positions */
#define NVM_FUSES_RESERVED_gm  0xFF  /* Reserved for factory calibration group mask. */
#define NVM_FUSES_RESERVED_gp  0  /* Reserved for factory calibration group position. */
#define NVM_FUSES_RESERVED0_bm  (1<<0)  /* Reserved for factory calibration bit 0 mask. */
#define NVM_FUSES_RESERVED0_bp  0  /* Reserved for factory calibration bit 0 position. */
#define NVM_FUSES_RESERVED1_bm  (1<<1)  /* Reserved for factory calibration bit 1 mask. */
#define NVM_FUSES_RESERVED1_bp  1  /* Reserved for factory calibration bit 1 position. */
#define NVM_FUSES_RESERVED2_bm  (1<<2)  /* Reserved for factory calibration bit 2 mask. */
#define NVM_FUSES_RESERVED2_bp  2  /* Reserved for factory calibration bit 2 position. */
#define NVM_FUSES_RESERVED3_bm  (1<<3)  /* Reserved for factory calibration bit 3 mask. */
#define NVM_FUSES_RESERVED3_bp  3  /* Reserved for factory calibration bit 3 position. */
#define NVM_FUSES_RESERVED4_bm  (1<<4)  /* Reserved for factory calibration bit 4 mask. */
#define NVM_FUSES_RESERVED4_bp  4  /* Reserved for factory calibration bit 4 position. */
#define NVM_FUSES_RESERVED5_bm  (1<<5)  /* Reserved for factory calibration bit 5 mask. */
#define NVM_FUSES_RESERVED5_bp  5  /* Reserved for factory calibration bit 5 position. */
#define NVM_FUSES_RESERVED6_bm  (1<<6)  /* Reserved for factory calibration bit 6 mask. */
#define NVM_FUSES_RESERVED6_bp  6  /* Reserved for factory calibration bit 6 position. */
#define NVM_FUSES_RESERVED7_bm  (1<<7)  /* Reserved for factory calibration bit 7 mask. */
#define NVM_FUSES_RESERVED7_bp  7  /* Reserved for factory calibration bit 7 position. */

/* NVM_FUSES.FUSEBYTE6  bit masks and bit positions */
#define NVM_FUSES_WDPER_gm  0x0F  /* Watchdog Timeout Period group mask. */
#define NVM_FUSES_WDPER_gp  0  /* Watchdog Timeout Period group position. */
#define NVM_FUSES_WDPER0_bm  (1<<0)  /* Watchdog Timeout Period bit 0 mask. */
#define NVM_FUSES_WDPER0_bp  0  /* Watchdog Timeout Period bit 0 position. */
#define NVM_FUSES_WDPER1_bm  (1<<1)  /* Watchdog Timeout Period bit 1 mask. */
#define NVM_FUSES_WDPER1_bp  1  /* Watchdog Timeout Period bit 1 position. */
#define NVM_FUSES_WDPER2_bm  (1<<2)  /* Watchdog Timeout Period bit 2 mask. */
#define NVM_FUSES_WDPER2_bp  2  /* Watchdog Timeout Period bit 2 position. */
#define NVM_FUSES_WDPER3_bm  (1<<3)  /* Watchdog Timeout Period bit 3 mask. */
#define NVM_FUSES_WDPER3_bp  3  /* Watchdog Timeout Period bit 3 position. */
#define NVM_FUSES_WDWPER_gm  0xF0  /* Watchdog Window Timeout Period group mask. */
#define NVM_FUSES_WDWPER_gp  4  /* Watchdog Window Timeout Period group position. */
#define NVM_FUSES_WDWPER0_bm  (1<<4)  /* Watchdog Window Timeout Period bit 0 mask. */
#define NVM_FUSES_WDWPER0_bp  4  /* Watchdog Window Timeout Period bit 0 position. */
#define NVM_FUSES_WDWPER1_bm  (1<<5)  /* Watchdog Window Timeout Period bit 1 mask. */
#define NVM_FUSES_WDWPER1_bp  5  /* Watchdog Window Timeout Period bit 1 position. */
#define NVM_FUSES_WDWPER2_bm  (1<<6)  /* Watchdog Window Timeout Period bit 2 mask. */
#define NVM_FUSES_WDWPER2_bp  6  /* Watchdog Window Timeout Period bit 2 position. */
#define NVM_FUSES_WDWPER3_bm  (1<<7)  /* Watchdog Window Timeout Period bit 3 mask. */
#define NVM_FUSES_WDWPER3_bp  7  /* Watchdog Window Timeout Period bit 3 position. */

/* NVM_LOCKBITS.LOCKBITS  bit masks and bit positions */
#define NVM_LOCKBITS_LB_gm  0x03  /* Lock Bits group mask. */
#define NVM_LOCKBITS_LB_gp  0  /* Lock Bits group position. */
#define NVM_LOCKBITS_LB0_bm  (1<<0)  /* Lock Bits bit 0 mask. */
#define NVM_LOCKBITS_LB0_bp  0  /* Lock Bits bit 0 position. */
#define NVM_LOCKBITS_LB1_bm  (1<<1)  /* Lock Bits bit 1 mask. */
#define NVM_LOCKBITS_LB1_bp  1  /* Lock Bits bit 1 position. */
#define NVM_LOCKBITS_BLBAT_gm  0x0C  /* Boot Lock Bits - Application Table group mask. */
#define NVM_LOCKBITS_BLBAT_gp  2  /* Boot Lock Bits - Application Table group position. */
#define NVM_LOCKBITS_BLBAT0_bm  (1<<2)  /* Boot Lock Bits - Application Table bit 0 mask. */
#define NVM_LOCKBITS_BLBAT0_bp  2  /* Boot Lock Bits - Application Table bit 0 position. */
#define NVM_LOCKBITS_BLBAT1_bm  (1<<3)  /* Boot Lock Bits - Application Table bit 1 mask. */
#define NVM_LOCKBITS_BLBAT1_bp  3  /* Boot Lock Bits - Application Table bit 1 position. */
#define NVM_LOCKBITS_BLBA_gm  0x30  /* Boot Lock Bits - Application Section group mask. */
#define NVM_LOCKBITS_BLBA_gp  4  /* Boot Lock Bits - Application Section group position. */
#define NVM_LOCKBITS_BLBA0_bm  (1<<4)  /* Boot Lock Bits - Application Section bit 0 mask. */
#define NVM_LOCKBITS_BLBA0_bp  4  /* Boot Lock Bits - Application Section bit 0 position. */
#define NVM_LOCKBITS_BLBA1_bm  (1<<5)  /* Boot Lock Bits - Application Section bit 1 mask. */
#define NVM_LOCKBITS_BLBA1_bp  5  /* Boot Lock Bits - Application Section bit 1 position. */
#define NVM_LOCKBITS_BLBB_gm  0xC0  /* Boot Lock Bits - Boot Section group mask. */
#define NVM_LOCKBITS_BLBB_gp  6  /* Boot Lock Bits - Boot Section group position. */
#define NVM_LOCKBITS_BLBB0_bm  (1<<6)  /* Boot Lock Bits - Boot Section bit 0 mask. */
#define NVM_LOCKBITS_BLBB0_bp  6  /* Boot Lock Bits - Boot Section bit 0 position. */
#define NVM_LOCKBITS_BLBB1_bm  (1<<7)  /* Boot Lock Bits - Boot Section bit 1 mask. */
#define NVM_LOCKBITS_BLBB1_bp  7  /* Boot Lock Bits - Boot Section bit 1 position. */

/* GPIO - General Purpose IO */
/* GPIO.GPIOR0  bit masks and bit positions */
#define GPIO_GPIO_gm  0xFF  /* General Purpose I/O Byte group mask. */
#define GPIO_GPIO_gp  0  /* General Purpose I/O Byte group position. */
#define GPIO_GPIO0_bm  (1<<0)  /* General Purpose I/O Byte bit 0 mask. */
#define GPIO_GPIO0_bp  0  /* General Purpose I/O Byte bit 0 position. */
#define GPIO_GPIO1_bm  (1<<1)  /* General Purpose I/O Byte bit 1 mask. */
#define GPIO_GPIO1_bp  1  /* General Purpose I/O Byte bit 1 position. */
#define GPIO_GPIO2_bm  (1<<2)  /* General Purpose I/O Byte bit 2 mask. */
#define GPIO_GPIO2_bp  2  /* General Purpose I/O Byte bit 2 position. */
#define GPIO_GPIO3_bm  (1<<3)  /* General Purpose I/O Byte bit 3 mask. */
#define GPIO_GPIO3_bp  3  /* General Purpose I/O Byte bit 3 position. */
#define GPIO_GPIO4_bm  (1<<4)  /* General Purpose I/O Byte bit 4 mask. */
#define GPIO_GPIO4_bp  4  /* General Purpose I/O Byte bit 4 position. */
#define GPIO_GPIO5_bm  (1<<5)  /* General Purpose I/O Byte bit 5 mask. */
#define GPIO_GPIO5_bp  5  /* General Purpose I/O Byte bit 5 position. */
#define GPIO_GPIO6_bm  (1<<6)  /* General Purpose I/O Byte bit 6 mask. */
#define GPIO_GPIO6_bp  6  /* General Purpose I/O Byte bit 6 position. */
#define GPIO_GPIO7_bm  (1<<7)  /* General Purpose I/O Byte bit 7 mask. */
#define GPIO_GPIO7_bp  7  /* General Purpose I/O Byte bit 7 position. */

/* GPIO.GPIOR1  bit masks and bit positions */
/* GPIO_GPIO  is already defined. */

/* GPIO.GPIOR2  bit masks and bit positions */
/* GPIO_GPIO  is already defined. */

/* GPIO.GPIOR3  bit masks and bit positions */
/* GPIO_GPIO  is already defined. */

/* LDO - LDO */
/* LDO.CTRL  bit masks and bit positions */
#define LDO_MODE_gm  0x03  /* Mode Configuration group mask. */
#define LDO_MODE_gp  0  /* Mode Configuration group position. */
#define LDO_MODE0_bm  (1<<0)  /* Mode Configuration bit 0 mask. */
#define LDO_MODE0_bp  0  /* Mode Configuration bit 0 position. */
#define LDO_MODE1_bm  (1<<1)  /* Mode Configuration bit 1 mask. */
#define LDO_MODE1_bp  1  /* Mode Configuration bit 1 position. */
#define LDO_SBSY_bm  0x80  /* Synchronization busy bit mask. */
#define LDO_SBSY_bp  7  /* Synchronization busy bit position. */

/* MCU - MCU Control */
/* MCU.DEVID0  bit masks and bit positions */
#define MCU_DEVID0_gm  0xFF  /* Device ID 0 group mask. */
#define MCU_DEVID0_gp  0  /* Device ID 0 group position. */
#define MCU_DEVID00_bm  (1<<0)  /* Device ID 0 bit 0 mask. */
#define MCU_DEVID00_bp  0  /* Device ID 0 bit 0 position. */
#define MCU_DEVID01_bm  (1<<1)  /* Device ID 0 bit 1 mask. */
#define MCU_DEVID01_bp  1  /* Device ID 0 bit 1 position. */
#define MCU_DEVID02_bm  (1<<2)  /* Device ID 0 bit 2 mask. */
#define MCU_DEVID02_bp  2  /* Device ID 0 bit 2 position. */
#define MCU_DEVID03_bm  (1<<3)  /* Device ID 0 bit 3 mask. */
#define MCU_DEVID03_bp  3  /* Device ID 0 bit 3 position. */
#define MCU_DEVID04_bm  (1<<4)  /* Device ID 0 bit 4 mask. */
#define MCU_DEVID04_bp  4  /* Device ID 0 bit 4 position. */
#define MCU_DEVID05_bm  (1<<5)  /* Device ID 0 bit 5 mask. */
#define MCU_DEVID05_bp  5  /* Device ID 0 bit 5 position. */
#define MCU_DEVID06_bm  (1<<6)  /* Device ID 0 bit 6 mask. */
#define MCU_DEVID06_bp  6  /* Device ID 0 bit 6 position. */
#define MCU_DEVID07_bm  (1<<7)  /* Device ID 0 bit 7 mask. */
#define MCU_DEVID07_bp  7  /* Device ID 0 bit 7 position. */

/* MCU.DEVID1  bit masks and bit positions */
#define MCU_DEVID1_gm  0xFF  /* Device ID 1 group mask. */
#define MCU_DEVID1_gp  0  /* Device ID 1 group position. */
#define MCU_DEVID10_bm  (1<<0)  /* Device ID 1 bit 0 mask. */
#define MCU_DEVID10_bp  0  /* Device ID 1 bit 0 position. */
#define MCU_DEVID11_bm  (1<<1)  /* Device ID 1 bit 1 mask. */
#define MCU_DEVID11_bp  1  /* Device ID 1 bit 1 position. */
#define MCU_DEVID12_bm  (1<<2)  /* Device ID 1 bit 2 mask. */
#define MCU_DEVID12_bp  2  /* Device ID 1 bit 2 position. */
#define MCU_DEVID13_bm  (1<<3)  /* Device ID 1 bit 3 mask. */
#define MCU_DEVID13_bp  3  /* Device ID 1 bit 3 position. */
#define MCU_DEVID14_bm  (1<<4)  /* Device ID 1 bit 4 mask. */
#define MCU_DEVID14_bp  4  /* Device ID 1 bit 4 position. */
#define MCU_DEVID15_bm  (1<<5)  /* Device ID 1 bit 5 mask. */
#define MCU_DEVID15_bp  5  /* Device ID 1 bit 5 position. */
#define MCU_DEVID16_bm  (1<<6)  /* Device ID 1 bit 6 mask. */
#define MCU_DEVID16_bp  6  /* Device ID 1 bit 6 position. */
#define MCU_DEVID17_bm  (1<<7)  /* Device ID 1 bit 7 mask. */
#define MCU_DEVID17_bp  7  /* Device ID 1 bit 7 position. */

/* MCU.DEVID2  bit masks and bit positions */
#define MCU_DEVID2_gm  0xFF  /* Device ID 2 group mask. */
#define MCU_DEVID2_gp  0  /* Device ID 2 group position. */
#define MCU_DEVID20_bm  (1<<0)  /* Device ID 2 bit 0 mask. */
#define MCU_DEVID20_bp  0  /* Device ID 2 bit 0 position. */
#define MCU_DEVID21_bm  (1<<1)  /* Device ID 2 bit 1 mask. */
#define MCU_DEVID21_bp  1  /* Device ID 2 bit 1 position. */
#define MCU_DEVID22_bm  (1<<2)  /* Device ID 2 bit 2 mask. */
#define MCU_DEVID22_bp  2  /* Device ID 2 bit 2 position. */
#define MCU_DEVID23_bm  (1<<3)  /* Device ID 2 bit 3 mask. */
#define MCU_DEVID23_bp  3  /* Device ID 2 bit 3 position. */
#define MCU_DEVID24_bm  (1<<4)  /* Device ID 2 bit 4 mask. */
#define MCU_DEVID24_bp  4  /* Device ID 2 bit 4 position. */
#define MCU_DEVID25_bm  (1<<5)  /* Device ID 2 bit 5 mask. */
#define MCU_DEVID25_bp  5  /* Device ID 2 bit 5 position. */
#define MCU_DEVID26_bm  (1<<6)  /* Device ID 2 bit 6 mask. */
#define MCU_DEVID26_bp  6  /* Device ID 2 bit 6 position. */
#define MCU_DEVID27_bm  (1<<7)  /* Device ID 2 bit 7 mask. */
#define MCU_DEVID27_bp  7  /* Device ID 2 bit 7 position. */

/* MCU.REVID  bit masks and bit positions */
#define MCU_REVID_gm  0xFF  /* Revision ID group mask. */
#define MCU_REVID_gp  0  /* Revision ID group position. */
#define MCU_REVID0_bm  (1<<0)  /* Revision ID bit 0 mask. */
#define MCU_REVID0_bp  0  /* Revision ID bit 0 position. */
#define MCU_REVID1_bm  (1<<1)  /* Revision ID bit 1 mask. */
#define MCU_REVID1_bp  1  /* Revision ID bit 1 position. */
#define MCU_REVID2_bm  (1<<2)  /* Revision ID bit 2 mask. */
#define MCU_REVID2_bp  2  /* Revision ID bit 2 position. */
#define MCU_REVID3_bm  (1<<3)  /* Revision ID bit 3 mask. */
#define MCU_REVID3_bp  3  /* Revision ID bit 3 position. */
#define MCU_REVID4_bm  (1<<4)  /* Revision ID bit 4 mask. */
#define MCU_REVID4_bp  4  /* Revision ID bit 4 position. */
#define MCU_REVID5_bm  (1<<5)  /* Revision ID bit 5 mask. */
#define MCU_REVID5_bp  5  /* Revision ID bit 5 position. */
#define MCU_REVID6_bm  (1<<6)  /* Revision ID bit 6 mask. */
#define MCU_REVID6_bp  6  /* Revision ID bit 6 position. */
#define MCU_REVID7_bm  (1<<7)  /* Revision ID bit 7 mask. */
#define MCU_REVID7_bp  7  /* Revision ID bit 7 position. */

/* NVM - Non Volatile Memory Controller */
/* NVM.ADDR0  bit masks and bit positions */
#define NVM_ADDR_gm  0xFF  /* Address Register Byte 0 group mask. */
#define NVM_ADDR_gp  0  /* Address Register Byte 0 group position. */
#define NVM_ADDR0_bm  (1<<0)  /* Address Register Byte 0 bit 0 mask. */
#define NVM_ADDR0_bp  0  /* Address Register Byte 0 bit 0 position. */
#define NVM_ADDR1_bm  (1<<1)  /* Address Register Byte 0 bit 1 mask. */
#define NVM_ADDR1_bp  1  /* Address Register Byte 0 bit 1 position. */
#define NVM_ADDR2_bm  (1<<2)  /* Address Register Byte 0 bit 2 mask. */
#define NVM_ADDR2_bp  2  /* Address Register Byte 0 bit 2 position. */
#define NVM_ADDR3_bm  (1<<3)  /* Address Register Byte 0 bit 3 mask. */
#define NVM_ADDR3_bp  3  /* Address Register Byte 0 bit 3 position. */
#define NVM_ADDR4_bm  (1<<4)  /* Address Register Byte 0 bit 4 mask. */
#define NVM_ADDR4_bp  4  /* Address Register Byte 0 bit 4 position. */
#define NVM_ADDR5_bm  (1<<5)  /* Address Register Byte 0 bit 5 mask. */
#define NVM_ADDR5_bp  5  /* Address Register Byte 0 bit 5 position. */
#define NVM_ADDR6_bm  (1<<6)  /* Address Register Byte 0 bit 6 mask. */
#define NVM_ADDR6_bp  6  /* Address Register Byte 0 bit 6 position. */
#define NVM_ADDR7_bm  (1<<7)  /* Address Register Byte 0 bit 7 mask. */
#define NVM_ADDR7_bp  7  /* Address Register Byte 0 bit 7 position. */

/* NVM.ADDR1  bit masks and bit positions */
/* NVM_ADDR  is already defined. */

/* NVM.ADDR2  bit masks and bit positions */
/* NVM_ADDR  is already defined. */

/* NVM.DATA0  bit masks and bit positions */
#define NVM_DATA_gm  0xFF  /* Data Register Byte 0 group mask. */
#define NVM_DATA_gp  0  /* Data Register Byte 0 group position. */
#define NVM_DATA0_bm  (1<<0)  /* Data Register Byte 0 bit 0 mask. */
#define NVM_DATA0_bp  0  /* Data Register Byte 0 bit 0 position. */
#define NVM_DATA1_bm  (1<<1)  /* Data Register Byte 0 bit 1 mask. */
#define NVM_DATA1_bp  1  /* Data Register Byte 0 bit 1 position. */
#define NVM_DATA2_bm  (1<<2)  /* Data Register Byte 0 bit 2 mask. */
#define NVM_DATA2_bp  2  /* Data Register Byte 0 bit 2 position. */
#define NVM_DATA3_bm  (1<<3)  /* Data Register Byte 0 bit 3 mask. */
#define NVM_DATA3_bp  3  /* Data Register Byte 0 bit 3 position. */
#define NVM_DATA4_bm  (1<<4)  /* Data Register Byte 0 bit 4 mask. */
#define NVM_DATA4_bp  4  /* Data Register Byte 0 bit 4 position. */
#define NVM_DATA5_bm  (1<<5)  /* Data Register Byte 0 bit 5 mask. */
#define NVM_DATA5_bp  5  /* Data Register Byte 0 bit 5 position. */
#define NVM_DATA6_bm  (1<<6)  /* Data Register Byte 0 bit 6 mask. */
#define NVM_DATA6_bp  6  /* Data Register Byte 0 bit 6 position. */
#define NVM_DATA7_bm  (1<<7)  /* Data Register Byte 0 bit 7 mask. */
#define NVM_DATA7_bp  7  /* Data Register Byte 0 bit 7 position. */

/* NVM.DATA1  bit masks and bit positions */
/* NVM_DATA  is already defined. */

/* NVM.DATA2  bit masks and bit positions */
/* NVM_DATA  is already defined. */

/* NVM.CMD  bit masks and bit positions */
#define NVM_CMD_gm  0x7F  /* Command group mask. */
#define NVM_CMD_gp  0  /* Command group position. */
#define NVM_CMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define NVM_CMD0_bp  0  /* Command bit 0 position. */
#define NVM_CMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define NVM_CMD1_bp  1  /* Command bit 1 position. */
#define NVM_CMD2_bm  (1<<2)  /* Command bit 2 mask. */
#define NVM_CMD2_bp  2  /* Command bit 2 position. */
#define NVM_CMD3_bm  (1<<3)  /* Command bit 3 mask. */
#define NVM_CMD3_bp  3  /* Command bit 3 position. */
#define NVM_CMD4_bm  (1<<4)  /* Command bit 4 mask. */
#define NVM_CMD4_bp  4  /* Command bit 4 position. */
#define NVM_CMD5_bm  (1<<5)  /* Command bit 5 mask. */
#define NVM_CMD5_bp  5  /* Command bit 5 position. */
#define NVM_CMD6_bm  (1<<6)  /* Command bit 6 mask. */
#define NVM_CMD6_bp  6  /* Command bit 6 position. */

/* NVM.CTRLA  bit masks and bit positions */
#define NVM_CMDEX_bm  0x01  /* Command Execute bit mask. */
#define NVM_CMDEX_bp  0  /* Command Execute bit position. */

/* NVM.CTRLB  bit masks and bit positions */
#define NVM_SPMLOCK_bm  0x01  /* SPM Lock bit mask. */
#define NVM_SPMLOCK_bp  0  /* SPM Lock bit position. */
#define NVM_EPRM_bm  0x02  /* EEPROM Power Reduction Enable bit mask. */
#define NVM_EPRM_bp  1  /* EEPROM Power Reduction Enable bit position. */
#define NVM_FPRM_bm  0x04  /* Flash Power Reduction Enable bit mask. */
#define NVM_FPRM_bp  2  /* Flash Power Reduction Enable bit position. */
#define NVM_EEMAPEN_bm  0x08  /* EEPROM Mapping Enable bit mask. */
#define NVM_EEMAPEN_bp  3  /* EEPROM Mapping Enable bit position. */

/* NVM.INTCTRL  bit masks and bit positions */
#define NVM_EELVL_gm  0x03  /* EEPROM Interrupt Level group mask. */
#define NVM_EELVL_gp  0  /* EEPROM Interrupt Level group position. */
#define NVM_EELVL0_bm  (1<<0)  /* EEPROM Interrupt Level bit 0 mask. */
#define NVM_EELVL0_bp  0  /* EEPROM Interrupt Level bit 0 position. */
#define NVM_EELVL1_bm  (1<<1)  /* EEPROM Interrupt Level bit 1 mask. */
#define NVM_EELVL1_bp  1  /* EEPROM Interrupt Level bit 1 position. */
#define NVM_SPMLVL_gm  0x0C  /* SPM Interrupt Level group mask. */
#define NVM_SPMLVL_gp  2  /* SPM Interrupt Level group position. */
#define NVM_SPMLVL0_bm  (1<<2)  /* SPM Interrupt Level bit 0 mask. */
#define NVM_SPMLVL0_bp  2  /* SPM Interrupt Level bit 0 position. */
#define NVM_SPMLVL1_bm  (1<<3)  /* SPM Interrupt Level bit 1 mask. */
#define NVM_SPMLVL1_bp  3  /* SPM Interrupt Level bit 1 position. */

/* NVM.STATUS  bit masks and bit positions */
#define NVM_FLOAD_bm  0x01  /* Flash Page Buffer Active Loading bit mask. */
#define NVM_FLOAD_bp  0  /* Flash Page Buffer Active Loading bit position. */
#define NVM_EELOAD_bm  0x02  /* EEPROM Page Buffer Active Loading bit mask. */
#define NVM_EELOAD_bp  1  /* EEPROM Page Buffer Active Loading bit position. */
#define NVM_FBUSY_bm  0x40  /* Flash Memory Busy bit mask. */
#define NVM_FBUSY_bp  6  /* Flash Memory Busy bit position. */
#define NVM_NVMBUSY_bm  0x80  /* Non-volatile Memory Busy bit mask. */
#define NVM_NVMBUSY_bp  7  /* Non-volatile Memory Busy bit position. */

/* NVM.LOCKBITS  bit masks and bit positions */
#define NVM_LB_gm  0x03  /* Lock Bits group mask. */
#define NVM_LB_gp  0  /* Lock Bits group position. */
#define NVM_LB0_bm  (1<<0)  /* Lock Bits bit 0 mask. */
#define NVM_LB0_bp  0  /* Lock Bits bit 0 position. */
#define NVM_LB1_bm  (1<<1)  /* Lock Bits bit 1 mask. */
#define NVM_LB1_bp  1  /* Lock Bits bit 1 position. */
#define NVM_BLBAT_gm  0x0C  /* Boot Lock Bits - Application Table group mask. */
#define NVM_BLBAT_gp  2  /* Boot Lock Bits - Application Table group position. */
#define NVM_BLBAT0_bm  (1<<2)  /* Boot Lock Bits - Application Table bit 0 mask. */
#define NVM_BLBAT0_bp  2  /* Boot Lock Bits - Application Table bit 0 position. */
#define NVM_BLBAT1_bm  (1<<3)  /* Boot Lock Bits - Application Table bit 1 mask. */
#define NVM_BLBAT1_bp  3  /* Boot Lock Bits - Application Table bit 1 position. */
#define NVM_BLBA_gm  0x30  /* Boot Lock Bits - Application Section group mask. */
#define NVM_BLBA_gp  4  /* Boot Lock Bits - Application Section group position. */
#define NVM_BLBA0_bm  (1<<4)  /* Boot Lock Bits - Application Section bit 0 mask. */
#define NVM_BLBA0_bp  4  /* Boot Lock Bits - Application Section bit 0 position. */
#define NVM_BLBA1_bm  (1<<5)  /* Boot Lock Bits - Application Section bit 1 mask. */
#define NVM_BLBA1_bp  5  /* Boot Lock Bits - Application Section bit 1 position. */
#define NVM_BLBB_gm  0xC0  /* Boot Lock Bits - Boot Section group mask. */
#define NVM_BLBB_gp  6  /* Boot Lock Bits - Boot Section group position. */
#define NVM_BLBB0_bm  (1<<6)  /* Boot Lock Bits - Boot Section bit 0 mask. */
#define NVM_BLBB0_bp  6  /* Boot Lock Bits - Boot Section bit 0 position. */
#define NVM_BLBB1_bm  (1<<7)  /* Boot Lock Bits - Boot Section bit 1 mask. */
#define NVM_BLBB1_bp  7  /* Boot Lock Bits - Boot Section bit 1 position. */

/* PMIC - Programmable Multi-level Interrupt Controller */
/* PMIC.STATUS  bit masks and bit positions */
#define PMIC_LOLVLEX_bm  0x01  /* Low Level Interrupt Executing bit mask. */
#define PMIC_LOLVLEX_bp  0  /* Low Level Interrupt Executing bit position. */
#define PMIC_MEDLVLEX_bm  0x02  /* Medium Level Interrupt Executing bit mask. */
#define PMIC_MEDLVLEX_bp  1  /* Medium Level Interrupt Executing bit position. */
#define PMIC_HILVLEX_bm  0x04  /* High Level Interrupt Executing bit mask. */
#define PMIC_HILVLEX_bp  2  /* High Level Interrupt Executing bit position. */
#define PMIC_NMIEX_bm  0x80  /* Non-maskable Interrupt Executing bit mask. */
#define PMIC_NMIEX_bp  7  /* Non-maskable Interrupt Executing bit position. */

/* PMIC.INTPRI  bit masks and bit positions */
#define PMIC_INTPRI_gm  0xFF  /* Interrupt Priority group mask. */
#define PMIC_INTPRI_gp  0  /* Interrupt Priority group position. */
#define PMIC_INTPRI0_bm  (1<<0)  /* Interrupt Priority bit 0 mask. */
#define PMIC_INTPRI0_bp  0  /* Interrupt Priority bit 0 position. */
#define PMIC_INTPRI1_bm  (1<<1)  /* Interrupt Priority bit 1 mask. */
#define PMIC_INTPRI1_bp  1  /* Interrupt Priority bit 1 position. */
#define PMIC_INTPRI2_bm  (1<<2)  /* Interrupt Priority bit 2 mask. */
#define PMIC_INTPRI2_bp  2  /* Interrupt Priority bit 2 position. */
#define PMIC_INTPRI3_bm  (1<<3)  /* Interrupt Priority bit 3 mask. */
#define PMIC_INTPRI3_bp  3  /* Interrupt Priority bit 3 position. */
#define PMIC_INTPRI4_bm  (1<<4)  /* Interrupt Priority bit 4 mask. */
#define PMIC_INTPRI4_bp  4  /* Interrupt Priority bit 4 position. */
#define PMIC_INTPRI5_bm  (1<<5)  /* Interrupt Priority bit 5 mask. */
#define PMIC_INTPRI5_bp  5  /* Interrupt Priority bit 5 position. */
#define PMIC_INTPRI6_bm  (1<<6)  /* Interrupt Priority bit 6 mask. */
#define PMIC_INTPRI6_bp  6  /* Interrupt Priority bit 6 position. */
#define PMIC_INTPRI7_bm  (1<<7)  /* Interrupt Priority bit 7 mask. */
#define PMIC_INTPRI7_bp  7  /* Interrupt Priority bit 7 position. */

/* PMIC.CTRL  bit masks and bit positions */
#define PMIC_LOLVLEN_bm  0x01  /* Low Level Enable bit mask. */
#define PMIC_LOLVLEN_bp  0  /* Low Level Enable bit position. */
#define PMIC_MEDLVLEN_bm  0x02  /* Medium Level Enable bit mask. */
#define PMIC_MEDLVLEN_bp  1  /* Medium Level Enable bit position. */
#define PMIC_HILVLEN_bm  0x04  /* High Level Enable bit mask. */
#define PMIC_HILVLEN_bp  2  /* High Level Enable bit position. */
#define PMIC_IVSEL_bm  0x40  /* Interrupt Vector Select bit mask. */
#define PMIC_IVSEL_bp  6  /* Interrupt Vector Select bit position. */
#define PMIC_RREN_bm  0x80  /* Round-Robin Priority Enable bit mask. */
#define PMIC_RREN_bp  7  /* Round-Robin Priority Enable bit position. */

/* PORT - I/O Port Configuration */
/* PORT.DIR  bit masks and bit positions */
#define PORT_DIR_gm  0xFF  /* Data Direction group mask. */
#define PORT_DIR_gp  0  /* Data Direction group position. */
#define PORT_DIR0_bm  (1<<0)  /* Data Direction bit 0 mask. */
#define PORT_DIR0_bp  0  /* Data Direction bit 0 position. */
#define PORT_DIR1_bm  (1<<1)  /* Data Direction bit 1 mask. */
#define PORT_DIR1_bp  1  /* Data Direction bit 1 position. */
#define PORT_DIR2_bm  (1<<2)  /* Data Direction bit 2 mask. */
#define PORT_DIR2_bp  2  /* Data Direction bit 2 position. */
#define PORT_DIR3_bm  (1<<3)  /* Data Direction bit 3 mask. */
#define PORT_DIR3_bp  3  /* Data Direction bit 3 position. */
#define PORT_DIR4_bm  (1<<4)  /* Data Direction bit 4 mask. */
#define PORT_DIR4_bp  4  /* Data Direction bit 4 position. */
#define PORT_DIR5_bm  (1<<5)  /* Data Direction bit 5 mask. */
#define PORT_DIR5_bp  5  /* Data Direction bit 5 position. */
#define PORT_DIR6_bm  (1<<6)  /* Data Direction bit 6 mask. */
#define PORT_DIR6_bp  6  /* Data Direction bit 6 position. */
#define PORT_DIR7_bm  (1<<7)  /* Data Direction bit 7 mask. */
#define PORT_DIR7_bp  7  /* Data Direction bit 7 position. */

/* PORT.OUT  bit masks and bit positions */
#define PORT_OUT_gm  0xFF  /* Output Data group mask. */
#define PORT_OUT_gp  0  /* Output Data group position. */
#define PORT_OUT0_bm  (1<<0)  /* Output Data bit 0 mask. */
#define PORT_OUT0_bp  0  /* Output Data bit 0 position. */
#define PORT_OUT1_bm  (1<<1)  /* Output Data bit 1 mask. */
#define PORT_OUT1_bp  1  /* Output Data bit 1 position. */
#define PORT_OUT2_bm  (1<<2)  /* Output Data bit 2 mask. */
#define PORT_OUT2_bp  2  /* Output Data bit 2 position. */
#define PORT_OUT3_bm  (1<<3)  /* Output Data bit 3 mask. */
#define PORT_OUT3_bp  3  /* Output Data bit 3 position. */
#define PORT_OUT4_bm  (1<<4)  /* Output Data bit 4 mask. */
#define PORT_OUT4_bp  4  /* Output Data bit 4 position. */
#define PORT_OUT5_bm  (1<<5)  /* Output Data bit 5 mask. */
#define PORT_OUT5_bp  5  /* Output Data bit 5 position. */
#define PORT_OUT6_bm  (1<<6)  /* Output Data bit 6 mask. */
#define PORT_OUT6_bp  6  /* Output Data bit 6 position. */
#define PORT_OUT7_bm  (1<<7)  /* Output Data bit 7 mask. */
#define PORT_OUT7_bp  7  /* Output Data bit 7 position. */

/* PORT.IN  bit masks and bit positions */
#define PORT_IN_gm  0xFF  /* Input Data group mask. */
#define PORT_IN_gp  0  /* Input Data group position. */
#define PORT_IN0_bm  (1<<0)  /* Input Data bit 0 mask. */
#define PORT_IN0_bp  0  /* Input Data bit 0 position. */
#define PORT_IN1_bm  (1<<1)  /* Input Data bit 1 mask. */
#define PORT_IN1_bp  1  /* Input Data bit 1 position. */
#define PORT_IN2_bm  (1<<2)  /* Input Data bit 2 mask. */
#define PORT_IN2_bp  2  /* Input Data bit 2 position. */
#define PORT_IN3_bm  (1<<3)  /* Input Data bit 3 mask. */
#define PORT_IN3_bp  3  /* Input Data bit 3 position. */
#define PORT_IN4_bm  (1<<4)  /* Input Data bit 4 mask. */
#define PORT_IN4_bp  4  /* Input Data bit 4 position. */
#define PORT_IN5_bm  (1<<5)  /* Input Data bit 5 mask. */
#define PORT_IN5_bp  5  /* Input Data bit 5 position. */
#define PORT_IN6_bm  (1<<6)  /* Input Data bit 6 mask. */
#define PORT_IN6_bp  6  /* Input Data bit 6 position. */
#define PORT_IN7_bm  (1<<7)  /* Input Data bit 7 mask. */
#define PORT_IN7_bp  7  /* Input Data bit 7 position. */

/* PORT.INTCTRL  bit masks and bit positions */
#define PORT_INT0LVL_gm  0x03  /* Port Interrupt 0 Level group mask. */
#define PORT_INT0LVL_gp  0  /* Port Interrupt 0 Level group position. */
#define PORT_INT0LVL0_bm  (1<<0)  /* Port Interrupt 0 Level bit 0 mask. */
#define PORT_INT0LVL0_bp  0  /* Port Interrupt 0 Level bit 0 position. */
#define PORT_INT0LVL1_bm  (1<<1)  /* Port Interrupt 0 Level bit 1 mask. */
#define PORT_INT0LVL1_bp  1  /* Port Interrupt 0 Level bit 1 position. */
#define PORT_INT1LVL_gm  0x0C  /* Port Interrupt 1 Level group mask. */
#define PORT_INT1LVL_gp  2  /* Port Interrupt 1 Level group position. */
#define PORT_INT1LVL0_bm  (1<<2)  /* Port Interrupt 1 Level bit 0 mask. */
#define PORT_INT1LVL0_bp  2  /* Port Interrupt 1 Level bit 0 position. */
#define PORT_INT1LVL1_bm  (1<<3)  /* Port Interrupt 1 Level bit 1 mask. */
#define PORT_INT1LVL1_bp  3  /* Port Interrupt 1 Level bit 1 position. */

/* PORT.INT0MASK  bit masks and bit positions */
#define PORT_INT0MASK_gm  0xFF  /* Interrupt 0 Mask Register group mask. */
#define PORT_INT0MASK_gp  0  /* Interrupt 0 Mask Register group position. */
#define PORT_INT0MASK0_bm  (1<<0)  /* Interrupt 0 Mask Register bit 0 mask. */
#define PORT_INT0MASK0_bp  0  /* Interrupt 0 Mask Register bit 0 position. */
#define PORT_INT0MASK1_bm  (1<<1)  /* Interrupt 0 Mask Register bit 1 mask. */
#define PORT_INT0MASK1_bp  1  /* Interrupt 0 Mask Register bit 1 position. */
#define PORT_INT0MASK2_bm  (1<<2)  /* Interrupt 0 Mask Register bit 2 mask. */
#define PORT_INT0MASK2_bp  2  /* Interrupt 0 Mask Register bit 2 position. */
#define PORT_INT0MASK3_bm  (1<<3)  /* Interrupt 0 Mask Register bit 3 mask. */
#define PORT_INT0MASK3_bp  3  /* Interrupt 0 Mask Register bit 3 position. */
#define PORT_INT0MASK4_bm  (1<<4)  /* Interrupt 0 Mask Register bit 4 mask. */
#define PORT_INT0MASK4_bp  4  /* Interrupt 0 Mask Register bit 4 position. */
#define PORT_INT0MASK5_bm  (1<<5)  /* Interrupt 0 Mask Register bit 5 mask. */
#define PORT_INT0MASK5_bp  5  /* Interrupt 0 Mask Register bit 5 position. */
#define PORT_INT0MASK6_bm  (1<<6)  /* Interrupt 0 Mask Register bit 6 mask. */
#define PORT_INT0MASK6_bp  6  /* Interrupt 0 Mask Register bit 6 position. */
#define PORT_INT0MASK7_bm  (1<<7)  /* Interrupt 0 Mask Register bit 7 mask. */
#define PORT_INT0MASK7_bp  7  /* Interrupt 0 Mask Register bit 7 position. */

/* PORT.INT1MASK  bit masks and bit positions */
#define PORT_INT1MASK_gm  0xFF  /* Interrupt 1 Mask Register group mask. */
#define PORT_INT1MASK_gp  0  /* Interrupt 1 Mask Register group position. */
#define PORT_INT1MASK0_bm  (1<<0)  /* Interrupt 1 Mask Register bit 0 mask. */
#define PORT_INT1MASK0_bp  0  /* Interrupt 1 Mask Register bit 0 position. */
#define PORT_INT1MASK1_bm  (1<<1)  /* Interrupt 1 Mask Register bit 1 mask. */
#define PORT_INT1MASK1_bp  1  /* Interrupt 1 Mask Register bit 1 position. */
#define PORT_INT1MASK2_bm  (1<<2)  /* Interrupt 1 Mask Register bit 2 mask. */
#define PORT_INT1MASK2_bp  2  /* Interrupt 1 Mask Register bit 2 position. */
#define PORT_INT1MASK3_bm  (1<<3)  /* Interrupt 1 Mask Register bit 3 mask. */
#define PORT_INT1MASK3_bp  3  /* Interrupt 1 Mask Register bit 3 position. */
#define PORT_INT1MASK4_bm  (1<<4)  /* Interrupt 1 Mask Register bit 4 mask. */
#define PORT_INT1MASK4_bp  4  /* Interrupt 1 Mask Register bit 4 position. */
#define PORT_INT1MASK5_bm  (1<<5)  /* Interrupt 1 Mask Register bit 5 mask. */
#define PORT_INT1MASK5_bp  5  /* Interrupt 1 Mask Register bit 5 position. */
#define PORT_INT1MASK6_bm  (1<<6)  /* Interrupt 1 Mask Register bit 6 mask. */
#define PORT_INT1MASK6_bp  6  /* Interrupt 1 Mask Register bit 6 position. */
#define PORT_INT1MASK7_bm  (1<<7)  /* Interrupt 1 Mask Register bit 7 mask. */
#define PORT_INT1MASK7_bp  7  /* Interrupt 1 Mask Register bit 7 position. */

/* PORT.INTFLAGS  bit masks and bit positions */
#define PORT_INT0IF_bm  0x01  /* Port Interrupt 0 Flag bit mask. */
#define PORT_INT0IF_bp  0  /* Port Interrupt 0 Flag bit position. */
#define PORT_INT1IF_bm  0x02  /* Port Interrupt 1 Flag bit mask. */
#define PORT_INT1IF_bp  1  /* Port Interrupt 1 Flag bit position. */

/* PORT.PIN0CTRL  bit masks and bit positions */
#define PORT_ISC_gm  0x07  /* Input/Sense Configuration group mask. */
#define PORT_ISC_gp  0  /* Input/Sense Configuration group position. */
#define PORT_ISC0_bm  (1<<0)  /* Input/Sense Configuration bit 0 mask. */
#define PORT_ISC0_bp  0  /* Input/Sense Configuration bit 0 position. */
#define PORT_ISC1_bm  (1<<1)  /* Input/Sense Configuration bit 1 mask. */
#define PORT_ISC1_bp  1  /* Input/Sense Configuration bit 1 position. */
#define PORT_ISC2_bm  (1<<2)  /* Input/Sense Configuration bit 2 mask. */
#define PORT_ISC2_bp  2  /* Input/Sense Configuration bit 2 position. */
#define PORT_OPC_gm  0x38  /* Output/Pull Configuration group mask. */
#define PORT_OPC_gp  3  /* Output/Pull Configuration group position. */
#define PORT_OPC0_bm  (1<<3)  /* Output/Pull Configuration bit 0 mask. */
#define PORT_OPC0_bp  3  /* Output/Pull Configuration bit 0 position. */
#define PORT_OPC1_bm  (1<<4)  /* Output/Pull Configuration bit 1 mask. */
#define PORT_OPC1_bp  4  /* Output/Pull Configuration bit 1 position. */
#define PORT_OPC2_bm  (1<<5)  /* Output/Pull Configuration bit 2 mask. */
#define PORT_OPC2_bp  5  /* Output/Pull Configuration bit 2 position. */
#define PORT_INVEN_bm  0x40  /* Inverted I/O Enable bit mask. */
#define PORT_INVEN_bp  6  /* Inverted I/O Enable bit position. */
#define PORT_SRLEN_bm  0x80  /* Slew Rate Enable bit mask. */
#define PORT_SRLEN_bp  7  /* Slew Rate Enable bit position. */

/* PORT.PIN1CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_OPC  is already defined. */
/* PORT_INVEN  is already defined. */
/* PORT_SRLEN  is already defined. */

/* PORT.PIN2CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_OPC  is already defined. */
/* PORT_INVEN  is already defined. */
/* PORT_SRLEN  is already defined. */

/* PORT.PIN3CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_OPC  is already defined. */
/* PORT_INVEN  is already defined. */
/* PORT_SRLEN  is already defined. */

/* PORT.PIN4CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_OPC  is already defined. */
/* PORT_INVEN  is already defined. */
/* PORT_SRLEN  is already defined. */

/* PORT.PIN5CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_OPC  is already defined. */
/* PORT_INVEN  is already defined. */
/* PORT_SRLEN  is already defined. */

/* PORT.PIN6CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_OPC  is already defined. */
/* PORT_INVEN  is already defined. */
/* PORT_SRLEN  is already defined. */

/* PORT.PIN7CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_OPC  is already defined. */
/* PORT_INVEN  is already defined. */
/* PORT_SRLEN  is already defined. */

/* PULLDOWN - Pulldown */
/* PULLDOWN.PDCTRLC  bit masks and bit positions */
#define PULLDOWN_PULLPC0_bm  0x01  /* Pulldown Pin C0 bit mask. */
#define PULLDOWN_PULLPC0_bp  0  /* Pulldown Pin C0 bit position. */
#define PULLDOWN_PULLPC1_bm  0x02  /* Pulldown Pin C1 bit mask. */
#define PULLDOWN_PULLPC1_bp  1  /* Pulldown Pin C1 bit position. */

/* PWRCTRL - VS PM Control */
/* PWRCTRL.PWRCRVDD2  bit masks and bit positions */
#define PWRCTRL_LSE_bm  0x01  /* VDD2 Enabled bit mask. */
#define PWRCTRL_LSE_bp  0  /* VDD2 Enabled bit position. */
#define PWRCTRL_LSD_bm  0x02  /* VDD2 Disabled bit mask. */
#define PWRCTRL_LSD_bp  1  /* VDD2 Disabled bit position. */
#define PWRCTRL_AUTOEN_bm  0x04  /* AUTO Mode Enabled bit mask. */
#define PWRCTRL_AUTOEN_bp  2  /* AUTO Mode Enabled bit position. */

/* RST - Reset */
/* RST.STATUS  bit masks and bit positions */
#define RST_PORF_bm  0x01  /* Power-on Reset Flag bit mask. */
#define RST_PORF_bp  0  /* Power-on Reset Flag bit position. */
#define RST_EXTRF_bm  0x02  /* External Reset Flag bit mask. */
#define RST_EXTRF_bp  1  /* External Reset Flag bit position. */
#define RST_BORF_bm  0x04  /* Brown-out Reset Flag bit mask. */
#define RST_BORF_bp  2  /* Brown-out Reset Flag bit position. */
#define RST_WDRF_bm  0x08  /* Watchdog Reset Flag bit mask. */
#define RST_WDRF_bp  3  /* Watchdog Reset Flag bit position. */
#define RST_PDIRF_bm  0x10  /* Programming and Debug Interface Interface Reset Flag bit mask. */
#define RST_PDIRF_bp  4  /* Programming and Debug Interface Interface Reset Flag bit position. */
#define RST_FWRF_bm  0x20  /* Firmware Reset Flag bit mask. */
#define RST_FWRF_bp  5  /* Firmware Reset Flag bit position. */

/* RST.CTRL  bit masks and bit positions */
#define RST_FWRST_bm  0x01  /* Firmware Reset bit mask. */
#define RST_FWRST_bp  0  /* Firmware Reset bit position. */

/* SIGROW - Signature Row */
/* NVM_PROD_SIGNATURES.LOTNUM0  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_LOTNUM0_gm  0xFF  /* Lot Number Byte 0, ASCII group mask. */
#define NVM_PROD_SIGNATURES_LOTNUM0_gp  0  /* Lot Number Byte 0, ASCII group position. */
#define NVM_PROD_SIGNATURES_LOTNUM00_bm  (1<<0)  /* Lot Number Byte 0, ASCII bit 0 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM00_bp  0  /* Lot Number Byte 0, ASCII bit 0 position. */
#define NVM_PROD_SIGNATURES_LOTNUM01_bm  (1<<1)  /* Lot Number Byte 0, ASCII bit 1 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM01_bp  1  /* Lot Number Byte 0, ASCII bit 1 position. */
#define NVM_PROD_SIGNATURES_LOTNUM02_bm  (1<<2)  /* Lot Number Byte 0, ASCII bit 2 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM02_bp  2  /* Lot Number Byte 0, ASCII bit 2 position. */
#define NVM_PROD_SIGNATURES_LOTNUM03_bm  (1<<3)  /* Lot Number Byte 0, ASCII bit 3 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM03_bp  3  /* Lot Number Byte 0, ASCII bit 3 position. */
#define NVM_PROD_SIGNATURES_LOTNUM04_bm  (1<<4)  /* Lot Number Byte 0, ASCII bit 4 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM04_bp  4  /* Lot Number Byte 0, ASCII bit 4 position. */
#define NVM_PROD_SIGNATURES_LOTNUM05_bm  (1<<5)  /* Lot Number Byte 0, ASCII bit 5 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM05_bp  5  /* Lot Number Byte 0, ASCII bit 5 position. */
#define NVM_PROD_SIGNATURES_LOTNUM06_bm  (1<<6)  /* Lot Number Byte 0, ASCII bit 6 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM06_bp  6  /* Lot Number Byte 0, ASCII bit 6 position. */
#define NVM_PROD_SIGNATURES_LOTNUM07_bm  (1<<7)  /* Lot Number Byte 0, ASCII bit 7 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM07_bp  7  /* Lot Number Byte 0, ASCII bit 7 position. */

/* NVM_PROD_SIGNATURES.LOTNUM1  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_LOTNUM1_gm  0xFF  /* Lot Number Byte 1, ASCII group mask. */
#define NVM_PROD_SIGNATURES_LOTNUM1_gp  0  /* Lot Number Byte 1, ASCII group position. */
#define NVM_PROD_SIGNATURES_LOTNUM10_bm  (1<<0)  /* Lot Number Byte 1, ASCII bit 0 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM10_bp  0  /* Lot Number Byte 1, ASCII bit 0 position. */
#define NVM_PROD_SIGNATURES_LOTNUM11_bm  (1<<1)  /* Lot Number Byte 1, ASCII bit 1 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM11_bp  1  /* Lot Number Byte 1, ASCII bit 1 position. */
#define NVM_PROD_SIGNATURES_LOTNUM12_bm  (1<<2)  /* Lot Number Byte 1, ASCII bit 2 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM12_bp  2  /* Lot Number Byte 1, ASCII bit 2 position. */
#define NVM_PROD_SIGNATURES_LOTNUM13_bm  (1<<3)  /* Lot Number Byte 1, ASCII bit 3 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM13_bp  3  /* Lot Number Byte 1, ASCII bit 3 position. */
#define NVM_PROD_SIGNATURES_LOTNUM14_bm  (1<<4)  /* Lot Number Byte 1, ASCII bit 4 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM14_bp  4  /* Lot Number Byte 1, ASCII bit 4 position. */
#define NVM_PROD_SIGNATURES_LOTNUM15_bm  (1<<5)  /* Lot Number Byte 1, ASCII bit 5 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM15_bp  5  /* Lot Number Byte 1, ASCII bit 5 position. */
#define NVM_PROD_SIGNATURES_LOTNUM16_bm  (1<<6)  /* Lot Number Byte 1, ASCII bit 6 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM16_bp  6  /* Lot Number Byte 1, ASCII bit 6 position. */
#define NVM_PROD_SIGNATURES_LOTNUM17_bm  (1<<7)  /* Lot Number Byte 1, ASCII bit 7 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM17_bp  7  /* Lot Number Byte 1, ASCII bit 7 position. */

/* NVM_PROD_SIGNATURES.LOTNUM2  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_LOTNUM2_gm  0xFF  /* Lot Number Byte 2, ASCII group mask. */
#define NVM_PROD_SIGNATURES_LOTNUM2_gp  0  /* Lot Number Byte 2, ASCII group position. */
#define NVM_PROD_SIGNATURES_LOTNUM20_bm  (1<<0)  /* Lot Number Byte 2, ASCII bit 0 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM20_bp  0  /* Lot Number Byte 2, ASCII bit 0 position. */
#define NVM_PROD_SIGNATURES_LOTNUM21_bm  (1<<1)  /* Lot Number Byte 2, ASCII bit 1 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM21_bp  1  /* Lot Number Byte 2, ASCII bit 1 position. */
#define NVM_PROD_SIGNATURES_LOTNUM22_bm  (1<<2)  /* Lot Number Byte 2, ASCII bit 2 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM22_bp  2  /* Lot Number Byte 2, ASCII bit 2 position. */
#define NVM_PROD_SIGNATURES_LOTNUM23_bm  (1<<3)  /* Lot Number Byte 2, ASCII bit 3 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM23_bp  3  /* Lot Number Byte 2, ASCII bit 3 position. */
#define NVM_PROD_SIGNATURES_LOTNUM24_bm  (1<<4)  /* Lot Number Byte 2, ASCII bit 4 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM24_bp  4  /* Lot Number Byte 2, ASCII bit 4 position. */
#define NVM_PROD_SIGNATURES_LOTNUM25_bm  (1<<5)  /* Lot Number Byte 2, ASCII bit 5 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM25_bp  5  /* Lot Number Byte 2, ASCII bit 5 position. */
#define NVM_PROD_SIGNATURES_LOTNUM26_bm  (1<<6)  /* Lot Number Byte 2, ASCII bit 6 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM26_bp  6  /* Lot Number Byte 2, ASCII bit 6 position. */
#define NVM_PROD_SIGNATURES_LOTNUM27_bm  (1<<7)  /* Lot Number Byte 2, ASCII bit 7 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM27_bp  7  /* Lot Number Byte 2, ASCII bit 7 position. */

/* NVM_PROD_SIGNATURES.LOTNUM3  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_LOTNUM3_gm  0xFF  /* Lot Number Byte 3, ASCII group mask. */
#define NVM_PROD_SIGNATURES_LOTNUM3_gp  0  /* Lot Number Byte 3, ASCII group position. */
#define NVM_PROD_SIGNATURES_LOTNUM30_bm  (1<<0)  /* Lot Number Byte 3, ASCII bit 0 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM30_bp  0  /* Lot Number Byte 3, ASCII bit 0 position. */
#define NVM_PROD_SIGNATURES_LOTNUM31_bm  (1<<1)  /* Lot Number Byte 3, ASCII bit 1 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM31_bp  1  /* Lot Number Byte 3, ASCII bit 1 position. */
#define NVM_PROD_SIGNATURES_LOTNUM32_bm  (1<<2)  /* Lot Number Byte 3, ASCII bit 2 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM32_bp  2  /* Lot Number Byte 3, ASCII bit 2 position. */
#define NVM_PROD_SIGNATURES_LOTNUM33_bm  (1<<3)  /* Lot Number Byte 3, ASCII bit 3 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM33_bp  3  /* Lot Number Byte 3, ASCII bit 3 position. */
#define NVM_PROD_SIGNATURES_LOTNUM34_bm  (1<<4)  /* Lot Number Byte 3, ASCII bit 4 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM34_bp  4  /* Lot Number Byte 3, ASCII bit 4 position. */
#define NVM_PROD_SIGNATURES_LOTNUM35_bm  (1<<5)  /* Lot Number Byte 3, ASCII bit 5 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM35_bp  5  /* Lot Number Byte 3, ASCII bit 5 position. */
#define NVM_PROD_SIGNATURES_LOTNUM36_bm  (1<<6)  /* Lot Number Byte 3, ASCII bit 6 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM36_bp  6  /* Lot Number Byte 3, ASCII bit 6 position. */
#define NVM_PROD_SIGNATURES_LOTNUM37_bm  (1<<7)  /* Lot Number Byte 3, ASCII bit 7 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM37_bp  7  /* Lot Number Byte 3, ASCII bit 7 position. */

/* NVM_PROD_SIGNATURES.LOTNUM4  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_LOTNUM4_gm  0xFF  /* Lot Number Byte 4, ASCII group mask. */
#define NVM_PROD_SIGNATURES_LOTNUM4_gp  0  /* Lot Number Byte 4, ASCII group position. */
#define NVM_PROD_SIGNATURES_LOTNUM40_bm  (1<<0)  /* Lot Number Byte 4, ASCII bit 0 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM40_bp  0  /* Lot Number Byte 4, ASCII bit 0 position. */
#define NVM_PROD_SIGNATURES_LOTNUM41_bm  (1<<1)  /* Lot Number Byte 4, ASCII bit 1 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM41_bp  1  /* Lot Number Byte 4, ASCII bit 1 position. */
#define NVM_PROD_SIGNATURES_LOTNUM42_bm  (1<<2)  /* Lot Number Byte 4, ASCII bit 2 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM42_bp  2  /* Lot Number Byte 4, ASCII bit 2 position. */
#define NVM_PROD_SIGNATURES_LOTNUM43_bm  (1<<3)  /* Lot Number Byte 4, ASCII bit 3 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM43_bp  3  /* Lot Number Byte 4, ASCII bit 3 position. */
#define NVM_PROD_SIGNATURES_LOTNUM44_bm  (1<<4)  /* Lot Number Byte 4, ASCII bit 4 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM44_bp  4  /* Lot Number Byte 4, ASCII bit 4 position. */
#define NVM_PROD_SIGNATURES_LOTNUM45_bm  (1<<5)  /* Lot Number Byte 4, ASCII bit 5 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM45_bp  5  /* Lot Number Byte 4, ASCII bit 5 position. */
#define NVM_PROD_SIGNATURES_LOTNUM46_bm  (1<<6)  /* Lot Number Byte 4, ASCII bit 6 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM46_bp  6  /* Lot Number Byte 4, ASCII bit 6 position. */
#define NVM_PROD_SIGNATURES_LOTNUM47_bm  (1<<7)  /* Lot Number Byte 4, ASCII bit 7 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM47_bp  7  /* Lot Number Byte 4, ASCII bit 7 position. */

/* NVM_PROD_SIGNATURES.LOTNUM5  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_LOTNUM5_gm  0xFF  /* Lot Number Byte 5, ASCII group mask. */
#define NVM_PROD_SIGNATURES_LOTNUM5_gp  0  /* Lot Number Byte 5, ASCII group position. */
#define NVM_PROD_SIGNATURES_LOTNUM50_bm  (1<<0)  /* Lot Number Byte 5, ASCII bit 0 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM50_bp  0  /* Lot Number Byte 5, ASCII bit 0 position. */
#define NVM_PROD_SIGNATURES_LOTNUM51_bm  (1<<1)  /* Lot Number Byte 5, ASCII bit 1 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM51_bp  1  /* Lot Number Byte 5, ASCII bit 1 position. */
#define NVM_PROD_SIGNATURES_LOTNUM52_bm  (1<<2)  /* Lot Number Byte 5, ASCII bit 2 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM52_bp  2  /* Lot Number Byte 5, ASCII bit 2 position. */
#define NVM_PROD_SIGNATURES_LOTNUM53_bm  (1<<3)  /* Lot Number Byte 5, ASCII bit 3 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM53_bp  3  /* Lot Number Byte 5, ASCII bit 3 position. */
#define NVM_PROD_SIGNATURES_LOTNUM54_bm  (1<<4)  /* Lot Number Byte 5, ASCII bit 4 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM54_bp  4  /* Lot Number Byte 5, ASCII bit 4 position. */
#define NVM_PROD_SIGNATURES_LOTNUM55_bm  (1<<5)  /* Lot Number Byte 5, ASCII bit 5 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM55_bp  5  /* Lot Number Byte 5, ASCII bit 5 position. */
#define NVM_PROD_SIGNATURES_LOTNUM56_bm  (1<<6)  /* Lot Number Byte 5, ASCII bit 6 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM56_bp  6  /* Lot Number Byte 5, ASCII bit 6 position. */
#define NVM_PROD_SIGNATURES_LOTNUM57_bm  (1<<7)  /* Lot Number Byte 5, ASCII bit 7 mask. */
#define NVM_PROD_SIGNATURES_LOTNUM57_bp  7  /* Lot Number Byte 5, ASCII bit 7 position. */

/* NVM_PROD_SIGNATURES.WAFNUM  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_WAFNUM_gm  0xFF  /* Wafer Number group mask. */
#define NVM_PROD_SIGNATURES_WAFNUM_gp  0  /* Wafer Number group position. */
#define NVM_PROD_SIGNATURES_WAFNUM0_bm  (1<<0)  /* Wafer Number bit 0 mask. */
#define NVM_PROD_SIGNATURES_WAFNUM0_bp  0  /* Wafer Number bit 0 position. */
#define NVM_PROD_SIGNATURES_WAFNUM1_bm  (1<<1)  /* Wafer Number bit 1 mask. */
#define NVM_PROD_SIGNATURES_WAFNUM1_bp  1  /* Wafer Number bit 1 position. */
#define NVM_PROD_SIGNATURES_WAFNUM2_bm  (1<<2)  /* Wafer Number bit 2 mask. */
#define NVM_PROD_SIGNATURES_WAFNUM2_bp  2  /* Wafer Number bit 2 position. */
#define NVM_PROD_SIGNATURES_WAFNUM3_bm  (1<<3)  /* Wafer Number bit 3 mask. */
#define NVM_PROD_SIGNATURES_WAFNUM3_bp  3  /* Wafer Number bit 3 position. */
#define NVM_PROD_SIGNATURES_WAFNUM4_bm  (1<<4)  /* Wafer Number bit 4 mask. */
#define NVM_PROD_SIGNATURES_WAFNUM4_bp  4  /* Wafer Number bit 4 position. */
#define NVM_PROD_SIGNATURES_WAFNUM5_bm  (1<<5)  /* Wafer Number bit 5 mask. */
#define NVM_PROD_SIGNATURES_WAFNUM5_bp  5  /* Wafer Number bit 5 position. */
#define NVM_PROD_SIGNATURES_WAFNUM6_bm  (1<<6)  /* Wafer Number bit 6 mask. */
#define NVM_PROD_SIGNATURES_WAFNUM6_bp  6  /* Wafer Number bit 6 position. */
#define NVM_PROD_SIGNATURES_WAFNUM7_bm  (1<<7)  /* Wafer Number bit 7 mask. */
#define NVM_PROD_SIGNATURES_WAFNUM7_bp  7  /* Wafer Number bit 7 position. */

/* NVM_PROD_SIGNATURES.COORDX0  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_COORDX0_gm  0xFF  /* Wafer Coordinate X Byte 0 group mask. */
#define NVM_PROD_SIGNATURES_COORDX0_gp  0  /* Wafer Coordinate X Byte 0 group position. */
#define NVM_PROD_SIGNATURES_COORDX00_bm  (1<<0)  /* Wafer Coordinate X Byte 0 bit 0 mask. */
#define NVM_PROD_SIGNATURES_COORDX00_bp  0  /* Wafer Coordinate X Byte 0 bit 0 position. */
#define NVM_PROD_SIGNATURES_COORDX01_bm  (1<<1)  /* Wafer Coordinate X Byte 0 bit 1 mask. */
#define NVM_PROD_SIGNATURES_COORDX01_bp  1  /* Wafer Coordinate X Byte 0 bit 1 position. */
#define NVM_PROD_SIGNATURES_COORDX02_bm  (1<<2)  /* Wafer Coordinate X Byte 0 bit 2 mask. */
#define NVM_PROD_SIGNATURES_COORDX02_bp  2  /* Wafer Coordinate X Byte 0 bit 2 position. */
#define NVM_PROD_SIGNATURES_COORDX03_bm  (1<<3)  /* Wafer Coordinate X Byte 0 bit 3 mask. */
#define NVM_PROD_SIGNATURES_COORDX03_bp  3  /* Wafer Coordinate X Byte 0 bit 3 position. */
#define NVM_PROD_SIGNATURES_COORDX04_bm  (1<<4)  /* Wafer Coordinate X Byte 0 bit 4 mask. */
#define NVM_PROD_SIGNATURES_COORDX04_bp  4  /* Wafer Coordinate X Byte 0 bit 4 position. */
#define NVM_PROD_SIGNATURES_COORDX05_bm  (1<<5)  /* Wafer Coordinate X Byte 0 bit 5 mask. */
#define NVM_PROD_SIGNATURES_COORDX05_bp  5  /* Wafer Coordinate X Byte 0 bit 5 position. */
#define NVM_PROD_SIGNATURES_COORDX06_bm  (1<<6)  /* Wafer Coordinate X Byte 0 bit 6 mask. */
#define NVM_PROD_SIGNATURES_COORDX06_bp  6  /* Wafer Coordinate X Byte 0 bit 6 position. */
#define NVM_PROD_SIGNATURES_COORDX07_bm  (1<<7)  /* Wafer Coordinate X Byte 0 bit 7 mask. */
#define NVM_PROD_SIGNATURES_COORDX07_bp  7  /* Wafer Coordinate X Byte 0 bit 7 position. */

/* NVM_PROD_SIGNATURES.COORDX1  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_COORDX1_gm  0xFF  /* Wafer Coordinate X Byte 1 group mask. */
#define NVM_PROD_SIGNATURES_COORDX1_gp  0  /* Wafer Coordinate X Byte 1 group position. */
#define NVM_PROD_SIGNATURES_COORDX10_bm  (1<<0)  /* Wafer Coordinate X Byte 1 bit 0 mask. */
#define NVM_PROD_SIGNATURES_COORDX10_bp  0  /* Wafer Coordinate X Byte 1 bit 0 position. */
#define NVM_PROD_SIGNATURES_COORDX11_bm  (1<<1)  /* Wafer Coordinate X Byte 1 bit 1 mask. */
#define NVM_PROD_SIGNATURES_COORDX11_bp  1  /* Wafer Coordinate X Byte 1 bit 1 position. */
#define NVM_PROD_SIGNATURES_COORDX12_bm  (1<<2)  /* Wafer Coordinate X Byte 1 bit 2 mask. */
#define NVM_PROD_SIGNATURES_COORDX12_bp  2  /* Wafer Coordinate X Byte 1 bit 2 position. */
#define NVM_PROD_SIGNATURES_COORDX13_bm  (1<<3)  /* Wafer Coordinate X Byte 1 bit 3 mask. */
#define NVM_PROD_SIGNATURES_COORDX13_bp  3  /* Wafer Coordinate X Byte 1 bit 3 position. */
#define NVM_PROD_SIGNATURES_COORDX14_bm  (1<<4)  /* Wafer Coordinate X Byte 1 bit 4 mask. */
#define NVM_PROD_SIGNATURES_COORDX14_bp  4  /* Wafer Coordinate X Byte 1 bit 4 position. */
#define NVM_PROD_SIGNATURES_COORDX15_bm  (1<<5)  /* Wafer Coordinate X Byte 1 bit 5 mask. */
#define NVM_PROD_SIGNATURES_COORDX15_bp  5  /* Wafer Coordinate X Byte 1 bit 5 position. */
#define NVM_PROD_SIGNATURES_COORDX16_bm  (1<<6)  /* Wafer Coordinate X Byte 1 bit 6 mask. */
#define NVM_PROD_SIGNATURES_COORDX16_bp  6  /* Wafer Coordinate X Byte 1 bit 6 position. */
#define NVM_PROD_SIGNATURES_COORDX17_bm  (1<<7)  /* Wafer Coordinate X Byte 1 bit 7 mask. */
#define NVM_PROD_SIGNATURES_COORDX17_bp  7  /* Wafer Coordinate X Byte 1 bit 7 position. */

/* NVM_PROD_SIGNATURES.COORDY0  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_COORDY0_gm  0xFF  /* Wafer Coordinate Y Byte 0 group mask. */
#define NVM_PROD_SIGNATURES_COORDY0_gp  0  /* Wafer Coordinate Y Byte 0 group position. */
#define NVM_PROD_SIGNATURES_COORDY00_bm  (1<<0)  /* Wafer Coordinate Y Byte 0 bit 0 mask. */
#define NVM_PROD_SIGNATURES_COORDY00_bp  0  /* Wafer Coordinate Y Byte 0 bit 0 position. */
#define NVM_PROD_SIGNATURES_COORDY01_bm  (1<<1)  /* Wafer Coordinate Y Byte 0 bit 1 mask. */
#define NVM_PROD_SIGNATURES_COORDY01_bp  1  /* Wafer Coordinate Y Byte 0 bit 1 position. */
#define NVM_PROD_SIGNATURES_COORDY02_bm  (1<<2)  /* Wafer Coordinate Y Byte 0 bit 2 mask. */
#define NVM_PROD_SIGNATURES_COORDY02_bp  2  /* Wafer Coordinate Y Byte 0 bit 2 position. */
#define NVM_PROD_SIGNATURES_COORDY03_bm  (1<<3)  /* Wafer Coordinate Y Byte 0 bit 3 mask. */
#define NVM_PROD_SIGNATURES_COORDY03_bp  3  /* Wafer Coordinate Y Byte 0 bit 3 position. */
#define NVM_PROD_SIGNATURES_COORDY04_bm  (1<<4)  /* Wafer Coordinate Y Byte 0 bit 4 mask. */
#define NVM_PROD_SIGNATURES_COORDY04_bp  4  /* Wafer Coordinate Y Byte 0 bit 4 position. */
#define NVM_PROD_SIGNATURES_COORDY05_bm  (1<<5)  /* Wafer Coordinate Y Byte 0 bit 5 mask. */
#define NVM_PROD_SIGNATURES_COORDY05_bp  5  /* Wafer Coordinate Y Byte 0 bit 5 position. */
#define NVM_PROD_SIGNATURES_COORDY06_bm  (1<<6)  /* Wafer Coordinate Y Byte 0 bit 6 mask. */
#define NVM_PROD_SIGNATURES_COORDY06_bp  6  /* Wafer Coordinate Y Byte 0 bit 6 position. */
#define NVM_PROD_SIGNATURES_COORDY07_bm  (1<<7)  /* Wafer Coordinate Y Byte 0 bit 7 mask. */
#define NVM_PROD_SIGNATURES_COORDY07_bp  7  /* Wafer Coordinate Y Byte 0 bit 7 position. */

/* NVM_PROD_SIGNATURES.COORDY1  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_COORDY1_gm  0xFF  /* Wafer Coordinate Y Byte 1 group mask. */
#define NVM_PROD_SIGNATURES_COORDY1_gp  0  /* Wafer Coordinate Y Byte 1 group position. */
#define NVM_PROD_SIGNATURES_COORDY10_bm  (1<<0)  /* Wafer Coordinate Y Byte 1 bit 0 mask. */
#define NVM_PROD_SIGNATURES_COORDY10_bp  0  /* Wafer Coordinate Y Byte 1 bit 0 position. */
#define NVM_PROD_SIGNATURES_COORDY11_bm  (1<<1)  /* Wafer Coordinate Y Byte 1 bit 1 mask. */
#define NVM_PROD_SIGNATURES_COORDY11_bp  1  /* Wafer Coordinate Y Byte 1 bit 1 position. */
#define NVM_PROD_SIGNATURES_COORDY12_bm  (1<<2)  /* Wafer Coordinate Y Byte 1 bit 2 mask. */
#define NVM_PROD_SIGNATURES_COORDY12_bp  2  /* Wafer Coordinate Y Byte 1 bit 2 position. */
#define NVM_PROD_SIGNATURES_COORDY13_bm  (1<<3)  /* Wafer Coordinate Y Byte 1 bit 3 mask. */
#define NVM_PROD_SIGNATURES_COORDY13_bp  3  /* Wafer Coordinate Y Byte 1 bit 3 position. */
#define NVM_PROD_SIGNATURES_COORDY14_bm  (1<<4)  /* Wafer Coordinate Y Byte 1 bit 4 mask. */
#define NVM_PROD_SIGNATURES_COORDY14_bp  4  /* Wafer Coordinate Y Byte 1 bit 4 position. */
#define NVM_PROD_SIGNATURES_COORDY15_bm  (1<<5)  /* Wafer Coordinate Y Byte 1 bit 5 mask. */
#define NVM_PROD_SIGNATURES_COORDY15_bp  5  /* Wafer Coordinate Y Byte 1 bit 5 position. */
#define NVM_PROD_SIGNATURES_COORDY16_bm  (1<<6)  /* Wafer Coordinate Y Byte 1 bit 6 mask. */
#define NVM_PROD_SIGNATURES_COORDY16_bp  6  /* Wafer Coordinate Y Byte 1 bit 6 position. */
#define NVM_PROD_SIGNATURES_COORDY17_bm  (1<<7)  /* Wafer Coordinate Y Byte 1 bit 7 mask. */
#define NVM_PROD_SIGNATURES_COORDY17_bp  7  /* Wafer Coordinate Y Byte 1 bit 7 position. */

/* NVM_PROD_SIGNATURES.ADCCAL  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_ADCCAL_gm  0xFF  /* ADC Calibration Byte group mask. */
#define NVM_PROD_SIGNATURES_ADCCAL_gp  0  /* ADC Calibration Byte group position. */
#define NVM_PROD_SIGNATURES_ADCCAL0_bm  (1<<0)  /* ADC Calibration Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_ADCCAL0_bp  0  /* ADC Calibration Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_ADCCAL1_bm  (1<<1)  /* ADC Calibration Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_ADCCAL1_bp  1  /* ADC Calibration Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_ADCCAL2_bm  (1<<2)  /* ADC Calibration Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_ADCCAL2_bp  2  /* ADC Calibration Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_ADCCAL3_bm  (1<<3)  /* ADC Calibration Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_ADCCAL3_bp  3  /* ADC Calibration Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_ADCCAL4_bm  (1<<4)  /* ADC Calibration Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_ADCCAL4_bp  4  /* ADC Calibration Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_ADCCAL5_bm  (1<<5)  /* ADC Calibration Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_ADCCAL5_bp  5  /* ADC Calibration Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_ADCCAL6_bm  (1<<6)  /* ADC Calibration Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_ADCCAL6_bp  6  /* ADC Calibration Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_ADCCAL7_bm  (1<<7)  /* ADC Calibration Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_ADCCAL7_bp  7  /* ADC Calibration Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.TEMPSENSE25CL  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL_gm  0xFF  /* Internal Temperature Sensor Low Byte group mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL_gp  0  /* Internal Temperature Sensor Low Byte group position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL0_bm  (1<<0)  /* Internal Temperature Sensor Low Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL0_bp  0  /* Internal Temperature Sensor Low Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL1_bm  (1<<1)  /* Internal Temperature Sensor Low Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL1_bp  1  /* Internal Temperature Sensor Low Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL2_bm  (1<<2)  /* Internal Temperature Sensor Low Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL2_bp  2  /* Internal Temperature Sensor Low Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL3_bm  (1<<3)  /* Internal Temperature Sensor Low Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL3_bp  3  /* Internal Temperature Sensor Low Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL4_bm  (1<<4)  /* Internal Temperature Sensor Low Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL4_bp  4  /* Internal Temperature Sensor Low Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL5_bm  (1<<5)  /* Internal Temperature Sensor Low Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL5_bp  5  /* Internal Temperature Sensor Low Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL6_bm  (1<<6)  /* Internal Temperature Sensor Low Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL6_bp  6  /* Internal Temperature Sensor Low Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL7_bm  (1<<7)  /* Internal Temperature Sensor Low Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CL7_bp  7  /* Internal Temperature Sensor Low Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.TEMPSENSE25CH  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CH_gm  0x0F  /* Internal Temperature Sensor High Byte group mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CH_gp  0  /* Internal Temperature Sensor High Byte group position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CH0_bm  (1<<0)  /* Internal Temperature Sensor High Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CH0_bp  0  /* Internal Temperature Sensor High Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CH1_bm  (1<<1)  /* Internal Temperature Sensor High Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CH1_bp  1  /* Internal Temperature Sensor High Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CH2_bm  (1<<2)  /* Internal Temperature Sensor High Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CH2_bp  2  /* Internal Temperature Sensor High Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CH3_bm  (1<<3)  /* Internal Temperature Sensor High Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE25CH3_bp  3  /* Internal Temperature Sensor High Byte bit 3 position. */

/* NVM_PROD_SIGNATURES.TEMPSENSE85CL  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL_gm  0xFF  /* Internal Temperature Sensor Low Byte group mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL_gp  0  /* Internal Temperature Sensor Low Byte group position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL0_bm  (1<<0)  /* Internal Temperature Sensor Low Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL0_bp  0  /* Internal Temperature Sensor Low Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL1_bm  (1<<1)  /* Internal Temperature Sensor Low Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL1_bp  1  /* Internal Temperature Sensor Low Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL2_bm  (1<<2)  /* Internal Temperature Sensor Low Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL2_bp  2  /* Internal Temperature Sensor Low Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL3_bm  (1<<3)  /* Internal Temperature Sensor Low Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL3_bp  3  /* Internal Temperature Sensor Low Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL4_bm  (1<<4)  /* Internal Temperature Sensor Low Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL4_bp  4  /* Internal Temperature Sensor Low Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL5_bm  (1<<5)  /* Internal Temperature Sensor Low Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL5_bp  5  /* Internal Temperature Sensor Low Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL6_bm  (1<<6)  /* Internal Temperature Sensor Low Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL6_bp  6  /* Internal Temperature Sensor Low Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL7_bm  (1<<7)  /* Internal Temperature Sensor Low Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CL7_bp  7  /* Internal Temperature Sensor Low Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.TEMPSENSE85CH  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CH_gm  0x0F  /* Internal Temperature Sensor High Byte group mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CH_gp  0  /* Internal Temperature Sensor High Byte group position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CH0_bm  (1<<0)  /* Internal Temperature Sensor High Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CH0_bp  0  /* Internal Temperature Sensor High Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CH1_bm  (1<<1)  /* Internal Temperature Sensor High Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CH1_bp  1  /* Internal Temperature Sensor High Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CH2_bm  (1<<2)  /* Internal Temperature Sensor High Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CH2_bp  2  /* Internal Temperature Sensor High Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CH3_bm  (1<<3)  /* Internal Temperature Sensor High Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_TEMPSENSE85CH3_bp  3  /* Internal Temperature Sensor High Byte bit 3 position. */

/* NVM_PROD_SIGNATURES.BATTOFFSET  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_BATTOFFSET_gm  0xFF  /* BATT Offset group mask. */
#define NVM_PROD_SIGNATURES_BATTOFFSET_gp  0  /* BATT Offset group position. */
#define NVM_PROD_SIGNATURES_BATTOFFSET0_bm  (1<<0)  /* BATT Offset bit 0 mask. */
#define NVM_PROD_SIGNATURES_BATTOFFSET0_bp  0  /* BATT Offset bit 0 position. */
#define NVM_PROD_SIGNATURES_BATTOFFSET1_bm  (1<<1)  /* BATT Offset bit 1 mask. */
#define NVM_PROD_SIGNATURES_BATTOFFSET1_bp  1  /* BATT Offset bit 1 position. */
#define NVM_PROD_SIGNATURES_BATTOFFSET2_bm  (1<<2)  /* BATT Offset bit 2 mask. */
#define NVM_PROD_SIGNATURES_BATTOFFSET2_bp  2  /* BATT Offset bit 2 position. */
#define NVM_PROD_SIGNATURES_BATTOFFSET3_bm  (1<<3)  /* BATT Offset bit 3 mask. */
#define NVM_PROD_SIGNATURES_BATTOFFSET3_bp  3  /* BATT Offset bit 3 position. */
#define NVM_PROD_SIGNATURES_BATTOFFSET4_bm  (1<<4)  /* BATT Offset bit 4 mask. */
#define NVM_PROD_SIGNATURES_BATTOFFSET4_bp  4  /* BATT Offset bit 4 position. */
#define NVM_PROD_SIGNATURES_BATTOFFSET5_bm  (1<<5)  /* BATT Offset bit 5 mask. */
#define NVM_PROD_SIGNATURES_BATTOFFSET5_bp  5  /* BATT Offset bit 5 position. */
#define NVM_PROD_SIGNATURES_BATTOFFSET6_bm  (1<<6)  /* BATT Offset bit 6 mask. */
#define NVM_PROD_SIGNATURES_BATTOFFSET6_bp  6  /* BATT Offset bit 6 position. */
#define NVM_PROD_SIGNATURES_BATTOFFSET7_bm  (1<<7)  /* BATT Offset bit 7 mask. */
#define NVM_PROD_SIGNATURES_BATTOFFSET7_bp  7  /* BATT Offset bit 7 position. */

/* NVM_PROD_SIGNATURES.BATTGAINL  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_BATTGAINL_gm  0xFF  /* BATT Gain Low Byte group mask. */
#define NVM_PROD_SIGNATURES_BATTGAINL_gp  0  /* BATT Gain Low Byte group position. */
#define NVM_PROD_SIGNATURES_BATTGAINL0_bm  (1<<0)  /* BATT Gain Low Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINL0_bp  0  /* BATT Gain Low Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_BATTGAINL1_bm  (1<<1)  /* BATT Gain Low Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINL1_bp  1  /* BATT Gain Low Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_BATTGAINL2_bm  (1<<2)  /* BATT Gain Low Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINL2_bp  2  /* BATT Gain Low Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_BATTGAINL3_bm  (1<<3)  /* BATT Gain Low Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINL3_bp  3  /* BATT Gain Low Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_BATTGAINL4_bm  (1<<4)  /* BATT Gain Low Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINL4_bp  4  /* BATT Gain Low Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_BATTGAINL5_bm  (1<<5)  /* BATT Gain Low Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINL5_bp  5  /* BATT Gain Low Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_BATTGAINL6_bm  (1<<6)  /* BATT Gain Low Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINL6_bp  6  /* BATT Gain Low Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_BATTGAINL7_bm  (1<<7)  /* BATT Gain Low Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINL7_bp  7  /* BATT Gain Low Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.BATTGAINH  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_BATTGAINH_gm  0xFF  /* BATT Gain High Byte group mask. */
#define NVM_PROD_SIGNATURES_BATTGAINH_gp  0  /* BATT Gain High Byte group position. */
#define NVM_PROD_SIGNATURES_BATTGAINH0_bm  (1<<0)  /* BATT Gain High Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINH0_bp  0  /* BATT Gain High Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_BATTGAINH1_bm  (1<<1)  /* BATT Gain High Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINH1_bp  1  /* BATT Gain High Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_BATTGAINH2_bm  (1<<2)  /* BATT Gain High Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINH2_bp  2  /* BATT Gain High Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_BATTGAINH3_bm  (1<<3)  /* BATT Gain High Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINH3_bp  3  /* BATT Gain High Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_BATTGAINH4_bm  (1<<4)  /* BATT Gain High Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINH4_bp  4  /* BATT Gain High Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_BATTGAINH5_bm  (1<<5)  /* BATT Gain High Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINH5_bp  5  /* BATT Gain High Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_BATTGAINH6_bm  (1<<6)  /* BATT Gain High Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINH6_bp  6  /* BATT Gain High Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_BATTGAINH7_bm  (1<<7)  /* BATT Gain High Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_BATTGAINH7_bp  7  /* BATT Gain High Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.TESTTEMPROOM  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM_gm  0x7F  /* Test Temperature Room group mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM_gp  0  /* Test Temperature Room group position. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM0_bm  (1<<0)  /* Test Temperature Room bit 0 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM0_bp  0  /* Test Temperature Room bit 0 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM1_bm  (1<<1)  /* Test Temperature Room bit 1 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM1_bp  1  /* Test Temperature Room bit 1 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM2_bm  (1<<2)  /* Test Temperature Room bit 2 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM2_bp  2  /* Test Temperature Room bit 2 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM3_bm  (1<<3)  /* Test Temperature Room bit 3 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM3_bp  3  /* Test Temperature Room bit 3 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM4_bm  (1<<4)  /* Test Temperature Room bit 4 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM4_bp  4  /* Test Temperature Room bit 4 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM5_bm  (1<<5)  /* Test Temperature Room bit 5 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM5_bp  5  /* Test Temperature Room bit 5 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM6_bm  (1<<6)  /* Test Temperature Room bit 6 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPROOM6_bp  6  /* Test Temperature Room bit 6 position. */

/* NVM_PROD_SIGNATURES.TESTTEMPHOTDIFF  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF_gm  0x7F  /* Test Temperature Hot Diff group mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF_gp  0  /* Test Temperature Hot Diff group position. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF0_bm  (1<<0)  /* Test Temperature Hot Diff bit 0 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF0_bp  0  /* Test Temperature Hot Diff bit 0 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF1_bm  (1<<1)  /* Test Temperature Hot Diff bit 1 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF1_bp  1  /* Test Temperature Hot Diff bit 1 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF2_bm  (1<<2)  /* Test Temperature Hot Diff bit 2 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF2_bp  2  /* Test Temperature Hot Diff bit 2 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF3_bm  (1<<3)  /* Test Temperature Hot Diff bit 3 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF3_bp  3  /* Test Temperature Hot Diff bit 3 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF4_bm  (1<<4)  /* Test Temperature Hot Diff bit 4 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF4_bp  4  /* Test Temperature Hot Diff bit 4 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF5_bm  (1<<5)  /* Test Temperature Hot Diff bit 5 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF5_bp  5  /* Test Temperature Hot Diff bit 5 position. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF6_bm  (1<<6)  /* Test Temperature Hot Diff bit 6 mask. */
#define NVM_PROD_SIGNATURES_TESTTEMPHOTDIFF6_bp  6  /* Test Temperature Hot Diff bit 6 position. */

/* NVM_PROD_SIGNATURES.RCCAL24MHZL  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL_gm  0xFF  /* 24MHz RC Oscillator Calibration Low Byte group mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL_gp  0  /* 24MHz RC Oscillator Calibration Low Byte group position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL0_bm  (1<<0)  /* 24MHz RC Oscillator Calibration Low Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL0_bp  0  /* 24MHz RC Oscillator Calibration Low Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL1_bm  (1<<1)  /* 24MHz RC Oscillator Calibration Low Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL1_bp  1  /* 24MHz RC Oscillator Calibration Low Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL2_bm  (1<<2)  /* 24MHz RC Oscillator Calibration Low Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL2_bp  2  /* 24MHz RC Oscillator Calibration Low Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL3_bm  (1<<3)  /* 24MHz RC Oscillator Calibration Low Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL3_bp  3  /* 24MHz RC Oscillator Calibration Low Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL4_bm  (1<<4)  /* 24MHz RC Oscillator Calibration Low Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL4_bp  4  /* 24MHz RC Oscillator Calibration Low Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL5_bm  (1<<5)  /* 24MHz RC Oscillator Calibration Low Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL5_bp  5  /* 24MHz RC Oscillator Calibration Low Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL6_bm  (1<<6)  /* 24MHz RC Oscillator Calibration Low Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL6_bp  6  /* 24MHz RC Oscillator Calibration Low Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL7_bm  (1<<7)  /* 24MHz RC Oscillator Calibration Low Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZL7_bp  7  /* 24MHz RC Oscillator Calibration Low Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.RCCAL24MHZH  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH_gm  0x1F  /* 24MHz RC Oscillator Calibration High Byte group mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH_gp  0  /* 24MHz RC Oscillator Calibration High Byte group position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH0_bm  (1<<0)  /* 24MHz RC Oscillator Calibration High Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH0_bp  0  /* 24MHz RC Oscillator Calibration High Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH1_bm  (1<<1)  /* 24MHz RC Oscillator Calibration High Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH1_bp  1  /* 24MHz RC Oscillator Calibration High Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH2_bm  (1<<2)  /* 24MHz RC Oscillator Calibration High Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH2_bp  2  /* 24MHz RC Oscillator Calibration High Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH3_bm  (1<<3)  /* 24MHz RC Oscillator Calibration High Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH3_bp  3  /* 24MHz RC Oscillator Calibration High Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH4_bm  (1<<4)  /* 24MHz RC Oscillator Calibration High Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_RCCAL24MHZH4_bp  4  /* 24MHz RC Oscillator Calibration High Byte bit 4 position. */

/* NVM_PROD_SIGNATURES.ULPRCCALL  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_ULPRCCALL_gm  0xFF  /* ULP RC Oscillator Calibration Low Byte group mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALL_gp  0  /* ULP RC Oscillator Calibration Low Byte group position. */
#define NVM_PROD_SIGNATURES_ULPRCCALL0_bm  (1<<0)  /* ULP RC Oscillator Calibration Low Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALL0_bp  0  /* ULP RC Oscillator Calibration Low Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALL1_bm  (1<<1)  /* ULP RC Oscillator Calibration Low Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALL1_bp  1  /* ULP RC Oscillator Calibration Low Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALL2_bm  (1<<2)  /* ULP RC Oscillator Calibration Low Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALL2_bp  2  /* ULP RC Oscillator Calibration Low Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALL3_bm  (1<<3)  /* ULP RC Oscillator Calibration Low Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALL3_bp  3  /* ULP RC Oscillator Calibration Low Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALL4_bm  (1<<4)  /* ULP RC Oscillator Calibration Low Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALL4_bp  4  /* ULP RC Oscillator Calibration Low Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALL5_bm  (1<<5)  /* ULP RC Oscillator Calibration Low Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALL5_bp  5  /* ULP RC Oscillator Calibration Low Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALL6_bm  (1<<6)  /* ULP RC Oscillator Calibration Low Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALL6_bp  6  /* ULP RC Oscillator Calibration Low Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALL7_bm  (1<<7)  /* ULP RC Oscillator Calibration Low Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALL7_bp  7  /* ULP RC Oscillator Calibration Low Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.ULPRCCALH  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_ULPRCCALH_gm  0x1F  /* ULP RC Oscillator Calibration High Byte group mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALH_gp  0  /* ULP RC Oscillator Calibration High Byte group position. */
#define NVM_PROD_SIGNATURES_ULPRCCALH0_bm  (1<<0)  /* ULP RC Oscillator Calibration High Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALH0_bp  0  /* ULP RC Oscillator Calibration High Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALH1_bm  (1<<1)  /* ULP RC Oscillator Calibration High Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALH1_bp  1  /* ULP RC Oscillator Calibration High Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALH2_bm  (1<<2)  /* ULP RC Oscillator Calibration High Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALH2_bp  2  /* ULP RC Oscillator Calibration High Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALH3_bm  (1<<3)  /* ULP RC Oscillator Calibration High Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALH3_bp  3  /* ULP RC Oscillator Calibration High Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_ULPRCCALH4_bm  (1<<4)  /* ULP RC Oscillator Calibration High Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_ULPRCCALH4_bp  4  /* ULP RC Oscillator Calibration High Byte bit 4 position. */

/* NVM_PROD_SIGNATURES.RC24MHZROOML  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_RC24MHZROOML_gm  0xFF  /* 24 MHz Room Low Byte group mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML_gp  0  /* 24 MHz Room Low Byte group position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML0_bm  (1<<0)  /* 24 MHz Room Low Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML0_bp  0  /* 24 MHz Room Low Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML1_bm  (1<<1)  /* 24 MHz Room Low Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML1_bp  1  /* 24 MHz Room Low Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML2_bm  (1<<2)  /* 24 MHz Room Low Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML2_bp  2  /* 24 MHz Room Low Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML3_bm  (1<<3)  /* 24 MHz Room Low Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML3_bp  3  /* 24 MHz Room Low Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML4_bm  (1<<4)  /* 24 MHz Room Low Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML4_bp  4  /* 24 MHz Room Low Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML5_bm  (1<<5)  /* 24 MHz Room Low Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML5_bp  5  /* 24 MHz Room Low Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML6_bm  (1<<6)  /* 24 MHz Room Low Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML6_bp  6  /* 24 MHz Room Low Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML7_bm  (1<<7)  /* 24 MHz Room Low Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOML7_bp  7  /* 24 MHz Room Low Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.RC24MHZROOMH  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH_gm  0xFF  /* 24 MHz Room High Byte group mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH_gp  0  /* 24 MHz Room High Byte group position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH0_bm  (1<<0)  /* 24 MHz Room High Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH0_bp  0  /* 24 MHz Room High Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH1_bm  (1<<1)  /* 24 MHz Room High Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH1_bp  1  /* 24 MHz Room High Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH2_bm  (1<<2)  /* 24 MHz Room High Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH2_bp  2  /* 24 MHz Room High Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH3_bm  (1<<3)  /* 24 MHz Room High Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH3_bp  3  /* 24 MHz Room High Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH4_bm  (1<<4)  /* 24 MHz Room High Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH4_bp  4  /* 24 MHz Room High Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH5_bm  (1<<5)  /* 24 MHz Room High Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH5_bp  5  /* 24 MHz Room High Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH6_bm  (1<<6)  /* 24 MHz Room High Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH6_bp  6  /* 24 MHz Room High Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH7_bm  (1<<7)  /* 24 MHz Room High Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZROOMH7_bp  7  /* 24 MHz Room High Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.RC24MHZHOTL  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL_gm  0xFF  /* 24 MHz Hot Low Byte group mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL_gp  0  /* 24 MHz Hot Low Byte group position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL0_bm  (1<<0)  /* 24 MHz Hot Low Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL0_bp  0  /* 24 MHz Hot Low Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL1_bm  (1<<1)  /* 24 MHz Hot Low Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL1_bp  1  /* 24 MHz Hot Low Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL2_bm  (1<<2)  /* 24 MHz Hot Low Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL2_bp  2  /* 24 MHz Hot Low Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL3_bm  (1<<3)  /* 24 MHz Hot Low Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL3_bp  3  /* 24 MHz Hot Low Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL4_bm  (1<<4)  /* 24 MHz Hot Low Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL4_bp  4  /* 24 MHz Hot Low Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL5_bm  (1<<5)  /* 24 MHz Hot Low Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL5_bp  5  /* 24 MHz Hot Low Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL6_bm  (1<<6)  /* 24 MHz Hot Low Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL6_bp  6  /* 24 MHz Hot Low Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL7_bm  (1<<7)  /* 24 MHz Hot Low Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTL7_bp  7  /* 24 MHz Hot Low Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.RC24MHZHOTH  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH_gm  0xFF  /* 24 MHz Hot High Byte group mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH_gp  0  /* 24 MHz Hot High Byte group position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH0_bm  (1<<0)  /* 24 MHz Hot High Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH0_bp  0  /* 24 MHz Hot High Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH1_bm  (1<<1)  /* 24 MHz Hot High Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH1_bp  1  /* 24 MHz Hot High Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH2_bm  (1<<2)  /* 24 MHz Hot High Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH2_bp  2  /* 24 MHz Hot High Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH3_bm  (1<<3)  /* 24 MHz Hot High Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH3_bp  3  /* 24 MHz Hot High Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH4_bm  (1<<4)  /* 24 MHz Hot High Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH4_bp  4  /* 24 MHz Hot High Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH5_bm  (1<<5)  /* 24 MHz Hot High Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH5_bp  5  /* 24 MHz Hot High Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH6_bm  (1<<6)  /* 24 MHz Hot High Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH6_bp  6  /* 24 MHz Hot High Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH7_bm  (1<<7)  /* 24 MHz Hot High Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_RC24MHZHOTH7_bp  7  /* 24 MHz Hot High Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.ULPRCROOML  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_ULPRCROOML_gm  0xFF  /* ULP RC Room Low Byte group mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOML_gp  0  /* ULP RC Room Low Byte group position. */
#define NVM_PROD_SIGNATURES_ULPRCROOML0_bm  (1<<0)  /* ULP RC Room Low Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOML0_bp  0  /* ULP RC Room Low Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOML1_bm  (1<<1)  /* ULP RC Room Low Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOML1_bp  1  /* ULP RC Room Low Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOML2_bm  (1<<2)  /* ULP RC Room Low Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOML2_bp  2  /* ULP RC Room Low Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOML3_bm  (1<<3)  /* ULP RC Room Low Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOML3_bp  3  /* ULP RC Room Low Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOML4_bm  (1<<4)  /* ULP RC Room Low Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOML4_bp  4  /* ULP RC Room Low Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOML5_bm  (1<<5)  /* ULP RC Room Low Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOML5_bp  5  /* ULP RC Room Low Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOML6_bm  (1<<6)  /* ULP RC Room Low Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOML6_bp  6  /* ULP RC Room Low Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOML7_bm  (1<<7)  /* ULP RC Room Low Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOML7_bp  7  /* ULP RC Room Low Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.ULPRCROOMH  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_ULPRCROOMH_gm  0xFF  /* ULP RC Room High Byte group mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH_gp  0  /* ULP RC Room High Byte group position. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH0_bm  (1<<0)  /* ULP RC Room High Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH0_bp  0  /* ULP RC Room High Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH1_bm  (1<<1)  /* ULP RC Room High Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH1_bp  1  /* ULP RC Room High Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH2_bm  (1<<2)  /* ULP RC Room High Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH2_bp  2  /* ULP RC Room High Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH3_bm  (1<<3)  /* ULP RC Room High Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH3_bp  3  /* ULP RC Room High Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH4_bm  (1<<4)  /* ULP RC Room High Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH4_bp  4  /* ULP RC Room High Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH5_bm  (1<<5)  /* ULP RC Room High Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH5_bp  5  /* ULP RC Room High Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH6_bm  (1<<6)  /* ULP RC Room High Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH6_bp  6  /* ULP RC Room High Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH7_bm  (1<<7)  /* ULP RC Room High Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_ULPRCROOMH7_bp  7  /* ULP RC Room High Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.ULPRCHOTL  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_ULPRCHOTL_gm  0xFF  /* ULP RC Hot Low Byte group mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL_gp  0  /* ULP RC Hot Low Byte group position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL0_bm  (1<<0)  /* ULP RC Hot Low Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL0_bp  0  /* ULP RC Hot Low Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL1_bm  (1<<1)  /* ULP RC Hot Low Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL1_bp  1  /* ULP RC Hot Low Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL2_bm  (1<<2)  /* ULP RC Hot Low Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL2_bp  2  /* ULP RC Hot Low Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL3_bm  (1<<3)  /* ULP RC Hot Low Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL3_bp  3  /* ULP RC Hot Low Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL4_bm  (1<<4)  /* ULP RC Hot Low Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL4_bp  4  /* ULP RC Hot Low Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL5_bm  (1<<5)  /* ULP RC Hot Low Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL5_bp  5  /* ULP RC Hot Low Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL6_bm  (1<<6)  /* ULP RC Hot Low Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL6_bp  6  /* ULP RC Hot Low Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL7_bm  (1<<7)  /* ULP RC Hot Low Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTL7_bp  7  /* ULP RC Hot Low Byte bit 7 position. */

/* NVM_PROD_SIGNATURES.ULPRCHOTH  bit masks and bit positions */
#define NVM_PROD_SIGNATURES_ULPRCHOTH_gm  0xFF  /* ULP RC Hot High Byte group mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH_gp  0  /* ULP RC Hot High Byte group position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH0_bm  (1<<0)  /* ULP RC Hot High Byte bit 0 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH0_bp  0  /* ULP RC Hot High Byte bit 0 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH1_bm  (1<<1)  /* ULP RC Hot High Byte bit 1 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH1_bp  1  /* ULP RC Hot High Byte bit 1 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH2_bm  (1<<2)  /* ULP RC Hot High Byte bit 2 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH2_bp  2  /* ULP RC Hot High Byte bit 2 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH3_bm  (1<<3)  /* ULP RC Hot High Byte bit 3 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH3_bp  3  /* ULP RC Hot High Byte bit 3 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH4_bm  (1<<4)  /* ULP RC Hot High Byte bit 4 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH4_bp  4  /* ULP RC Hot High Byte bit 4 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH5_bm  (1<<5)  /* ULP RC Hot High Byte bit 5 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH5_bp  5  /* ULP RC Hot High Byte bit 5 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH6_bm  (1<<6)  /* ULP RC Hot High Byte bit 6 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH6_bp  6  /* ULP RC Hot High Byte bit 6 position. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH7_bm  (1<<7)  /* ULP RC Hot High Byte bit 7 mask. */
#define NVM_PROD_SIGNATURES_ULPRCHOTH7_bp  7  /* ULP RC Hot High Byte bit 7 position. */

/* SLEEP - Sleep Controller */
/* SLEEP.CTRL  bit masks and bit positions */
#define SLEEP_SEN_bm  0x01  /* Sleep Enable bit mask. */
#define SLEEP_SEN_bp  0  /* Sleep Enable bit position. */
#define SLEEP_SMODE_gm  0x06  /* Sleep Mode Selection group mask. */
#define SLEEP_SMODE_gp  1  /* Sleep Mode Selection group position. */
#define SLEEP_SMODE0_bm  (1<<1)  /* Sleep Mode Selection bit 0 mask. */
#define SLEEP_SMODE0_bp  1  /* Sleep Mode Selection bit 0 position. */
#define SLEEP_SMODE1_bm  (1<<2)  /* Sleep Mode Selection bit 1 mask. */
#define SLEEP_SMODE1_bp  2  /* Sleep Mode Selection bit 1 position. */

/* TIM8_16 - Timer 8/16 bit */
/* TIM8_16.CTRLA  bit masks and bit positions */
#define TIM8_16_CTC_bm  0x01  /* Clear Timer on Compare Match Mode bit mask. */
#define TIM8_16_CTC_bp  0  /* Clear Timer on Compare Match Mode bit position. */
#define TIM8_16_ICES_bm  0x10  /* Input Capture Edge Select bit mask. */
#define TIM8_16_ICES_bp  4  /* Input Capture Edge Select bit position. */
#define TIM8_16_ICNC_bm  0x20  /* Input Capture Noise Canceller bit mask. */
#define TIM8_16_ICNC_bp  5  /* Input Capture Noise Canceller bit position. */
#define TIM8_16_ICEN_bm  0x40  /* Input Capture Mode Enable bit mask. */
#define TIM8_16_ICEN_bp  6  /* Input Capture Mode Enable bit position. */
#define TIM8_16_WORDM_bm  0x80  /* Word (16-bit) Mode bit mask. */
#define TIM8_16_WORDM_bp  7  /* Word (16-bit) Mode bit position. */

/* TIM8_16.CTRLB  bit masks and bit positions */
#define TIM8_16_CS_gm  0x0F  /* Clock Select group mask. */
#define TIM8_16_CS_gp  0  /* Clock Select group position. */
#define TIM8_16_CS0_bm  (1<<0)  /* Clock Select bit 0 mask. */
#define TIM8_16_CS0_bp  0  /* Clock Select bit 0 position. */
#define TIM8_16_CS1_bm  (1<<1)  /* Clock Select bit 1 mask. */
#define TIM8_16_CS1_bp  1  /* Clock Select bit 1 position. */
#define TIM8_16_CS2_bm  (1<<2)  /* Clock Select bit 2 mask. */
#define TIM8_16_CS2_bp  2  /* Clock Select bit 2 position. */
#define TIM8_16_CS3_bm  (1<<3)  /* Clock Select bit 3 mask. */
#define TIM8_16_CS3_bp  3  /* Clock Select bit 3 position. */
#define TIM8_16_ICS_gm  0x70  /* Input Capture Select group mask. */
#define TIM8_16_ICS_gp  4  /* Input Capture Select group position. */
#define TIM8_16_ICS0_bm  (1<<4)  /* Input Capture Select bit 0 mask. */
#define TIM8_16_ICS0_bp  4  /* Input Capture Select bit 0 position. */
#define TIM8_16_ICS1_bm  (1<<5)  /* Input Capture Select bit 1 mask. */
#define TIM8_16_ICS1_bp  5  /* Input Capture Select bit 1 position. */
#define TIM8_16_ICS2_bm  (1<<6)  /* Input Capture Select bit 2 mask. */
#define TIM8_16_ICS2_bp  6  /* Input Capture Select bit 2 position. */

/* TIM8_16.INTMSK  bit masks and bit positions */
#define TIM8_16_OVFILVL_gm  0x03  /* Overflow Interrupt Level group mask. */
#define TIM8_16_OVFILVL_gp  0  /* Overflow Interrupt Level group position. */
#define TIM8_16_OVFILVL0_bm  (1<<0)  /* Overflow Interrupt Level bit 0 mask. */
#define TIM8_16_OVFILVL0_bp  0  /* Overflow Interrupt Level bit 0 position. */
#define TIM8_16_OVFILVL1_bm  (1<<1)  /* Overflow Interrupt Level bit 1 mask. */
#define TIM8_16_OVFILVL1_bp  1  /* Overflow Interrupt Level bit 1 position. */
#define TIM8_16_OCAILVL_gm  0x0C  /* Output Compare Match A Interrupt Level group mask. */
#define TIM8_16_OCAILVL_gp  2  /* Output Compare Match A Interrupt Level group position. */
#define TIM8_16_OCAILVL0_bm  (1<<2)  /* Output Compare Match A Interrupt Level bit 0 mask. */
#define TIM8_16_OCAILVL0_bp  2  /* Output Compare Match A Interrupt Level bit 0 position. */
#define TIM8_16_OCAILVL1_bm  (1<<3)  /* Output Compare Match A Interrupt Level bit 1 mask. */
#define TIM8_16_OCAILVL1_bp  3  /* Output Compare Match A Interrupt Level bit 1 position. */
#define TIM8_16_OCBILVL_gm  0x30  /* Output Compare Match B Interrupt Level group mask. */
#define TIM8_16_OCBILVL_gp  4  /* Output Compare Match B Interrupt Level group position. */
#define TIM8_16_OCBILVL0_bm  (1<<4)  /* Output Compare Match B Interrupt Level bit 0 mask. */
#define TIM8_16_OCBILVL0_bp  4  /* Output Compare Match B Interrupt Level bit 0 position. */
#define TIM8_16_OCBILVL1_bm  (1<<5)  /* Output Compare Match B Interrupt Level bit 1 mask. */
#define TIM8_16_OCBILVL1_bp  5  /* Output Compare Match B Interrupt Level bit 1 position. */
#define TIM8_16_ICILVL_gm  0xC0  /* Input Capture Interrupt Level group mask. */
#define TIM8_16_ICILVL_gp  6  /* Input Capture Interrupt Level group position. */
#define TIM8_16_ICILVL0_bm  (1<<6)  /* Input Capture Interrupt Level bit 0 mask. */
#define TIM8_16_ICILVL0_bp  6  /* Input Capture Interrupt Level bit 0 position. */
#define TIM8_16_ICILVL1_bm  (1<<7)  /* Input Capture Interrupt Level bit 1 mask. */
#define TIM8_16_ICILVL1_bp  7  /* Input Capture Interrupt Level bit 1 position. */

/* TIM8_16.STATUS  bit masks and bit positions */
#define TIM8_16_OVF_bm  0x01  /* Overflow Interrupt Flag bit mask. */
#define TIM8_16_OVF_bp  0  /* Overflow Interrupt Flag bit position. */
#define TIM8_16_OCFA_bm  0x02  /* Output Compare Match A Interrupt Flag bit mask. */
#define TIM8_16_OCFA_bp  1  /* Output Compare Match A Interrupt Flag bit position. */
#define TIM8_16_OCFB_bm  0x04  /* Output Compare Match B Interrupt Flag bit mask. */
#define TIM8_16_OCFB_bp  2  /* Output Compare Match B Interrupt Flag bit position. */
#define TIM8_16_ICF_bm  0x08  /* Input Capture Interrupt Flag bit mask. */
#define TIM8_16_ICF_bp  3  /* Input Capture Interrupt Flag bit position. */

/* TIM8_16.TEMP  bit masks and bit positions */
#define TIM8_16_TEMP_gm  0xFF  /* Temporary High Byte Value group mask. */
#define TIM8_16_TEMP_gp  0  /* Temporary High Byte Value group position. */
#define TIM8_16_TEMP0_bm  (1<<0)  /* Temporary High Byte Value bit 0 mask. */
#define TIM8_16_TEMP0_bp  0  /* Temporary High Byte Value bit 0 position. */
#define TIM8_16_TEMP1_bm  (1<<1)  /* Temporary High Byte Value bit 1 mask. */
#define TIM8_16_TEMP1_bp  1  /* Temporary High Byte Value bit 1 position. */
#define TIM8_16_TEMP2_bm  (1<<2)  /* Temporary High Byte Value bit 2 mask. */
#define TIM8_16_TEMP2_bp  2  /* Temporary High Byte Value bit 2 position. */
#define TIM8_16_TEMP3_bm  (1<<3)  /* Temporary High Byte Value bit 3 mask. */
#define TIM8_16_TEMP3_bp  3  /* Temporary High Byte Value bit 3 position. */
#define TIM8_16_TEMP4_bm  (1<<4)  /* Temporary High Byte Value bit 4 mask. */
#define TIM8_16_TEMP4_bp  4  /* Temporary High Byte Value bit 4 position. */
#define TIM8_16_TEMP5_bm  (1<<5)  /* Temporary High Byte Value bit 5 mask. */
#define TIM8_16_TEMP5_bp  5  /* Temporary High Byte Value bit 5 position. */
#define TIM8_16_TEMP6_bm  (1<<6)  /* Temporary High Byte Value bit 6 mask. */
#define TIM8_16_TEMP6_bp  6  /* Temporary High Byte Value bit 6 position. */
#define TIM8_16_TEMP7_bm  (1<<7)  /* Temporary High Byte Value bit 7 mask. */
#define TIM8_16_TEMP7_bp  7  /* Temporary High Byte Value bit 7 position. */

/* TIM8_16.COUNTL  bit masks and bit positions */
#define TIM8_16_COUNT_gm  0xFF  /* Counter Value Low Byte group mask. */
#define TIM8_16_COUNT_gp  0  /* Counter Value Low Byte group position. */
#define TIM8_16_COUNT0_bm  (1<<0)  /* Counter Value Low Byte bit 0 mask. */
#define TIM8_16_COUNT0_bp  0  /* Counter Value Low Byte bit 0 position. */
#define TIM8_16_COUNT1_bm  (1<<1)  /* Counter Value Low Byte bit 1 mask. */
#define TIM8_16_COUNT1_bp  1  /* Counter Value Low Byte bit 1 position. */
#define TIM8_16_COUNT2_bm  (1<<2)  /* Counter Value Low Byte bit 2 mask. */
#define TIM8_16_COUNT2_bp  2  /* Counter Value Low Byte bit 2 position. */
#define TIM8_16_COUNT3_bm  (1<<3)  /* Counter Value Low Byte bit 3 mask. */
#define TIM8_16_COUNT3_bp  3  /* Counter Value Low Byte bit 3 position. */
#define TIM8_16_COUNT4_bm  (1<<4)  /* Counter Value Low Byte bit 4 mask. */
#define TIM8_16_COUNT4_bp  4  /* Counter Value Low Byte bit 4 position. */
#define TIM8_16_COUNT5_bm  (1<<5)  /* Counter Value Low Byte bit 5 mask. */
#define TIM8_16_COUNT5_bp  5  /* Counter Value Low Byte bit 5 position. */
#define TIM8_16_COUNT6_bm  (1<<6)  /* Counter Value Low Byte bit 6 mask. */
#define TIM8_16_COUNT6_bp  6  /* Counter Value Low Byte bit 6 position. */
#define TIM8_16_COUNT7_bm  (1<<7)  /* Counter Value Low Byte bit 7 mask. */
#define TIM8_16_COUNT7_bp  7  /* Counter Value Low Byte bit 7 position. */

/* TIM8_16.COUNTH  bit masks and bit positions */
/* TIM8_16_COUNT  is already defined. */

/* TIM8_16.OCRA  bit masks and bit positions */
#define TIM8_16_OCRA_gm  0xFF  /* Output Compare Value A group mask. */
#define TIM8_16_OCRA_gp  0  /* Output Compare Value A group position. */
#define TIM8_16_OCRA0_bm  (1<<0)  /* Output Compare Value A bit 0 mask. */
#define TIM8_16_OCRA0_bp  0  /* Output Compare Value A bit 0 position. */
#define TIM8_16_OCRA1_bm  (1<<1)  /* Output Compare Value A bit 1 mask. */
#define TIM8_16_OCRA1_bp  1  /* Output Compare Value A bit 1 position. */
#define TIM8_16_OCRA2_bm  (1<<2)  /* Output Compare Value A bit 2 mask. */
#define TIM8_16_OCRA2_bp  2  /* Output Compare Value A bit 2 position. */
#define TIM8_16_OCRA3_bm  (1<<3)  /* Output Compare Value A bit 3 mask. */
#define TIM8_16_OCRA3_bp  3  /* Output Compare Value A bit 3 position. */
#define TIM8_16_OCRA4_bm  (1<<4)  /* Output Compare Value A bit 4 mask. */
#define TIM8_16_OCRA4_bp  4  /* Output Compare Value A bit 4 position. */
#define TIM8_16_OCRA5_bm  (1<<5)  /* Output Compare Value A bit 5 mask. */
#define TIM8_16_OCRA5_bp  5  /* Output Compare Value A bit 5 position. */
#define TIM8_16_OCRA6_bm  (1<<6)  /* Output Compare Value A bit 6 mask. */
#define TIM8_16_OCRA6_bp  6  /* Output Compare Value A bit 6 position. */
#define TIM8_16_OCRA7_bm  (1<<7)  /* Output Compare Value A bit 7 mask. */
#define TIM8_16_OCRA7_bp  7  /* Output Compare Value A bit 7 position. */

/* TIM8_16.OCRB  bit masks and bit positions */
#define TIM8_16_OCRB_gm  0xFF  /* Output Compare Value B group mask. */
#define TIM8_16_OCRB_gp  0  /* Output Compare Value B group position. */
#define TIM8_16_OCRB0_bm  (1<<0)  /* Output Compare Value B bit 0 mask. */
#define TIM8_16_OCRB0_bp  0  /* Output Compare Value B bit 0 position. */
#define TIM8_16_OCRB1_bm  (1<<1)  /* Output Compare Value B bit 1 mask. */
#define TIM8_16_OCRB1_bp  1  /* Output Compare Value B bit 1 position. */
#define TIM8_16_OCRB2_bm  (1<<2)  /* Output Compare Value B bit 2 mask. */
#define TIM8_16_OCRB2_bp  2  /* Output Compare Value B bit 2 position. */
#define TIM8_16_OCRB3_bm  (1<<3)  /* Output Compare Value B bit 3 mask. */
#define TIM8_16_OCRB3_bp  3  /* Output Compare Value B bit 3 position. */
#define TIM8_16_OCRB4_bm  (1<<4)  /* Output Compare Value B bit 4 mask. */
#define TIM8_16_OCRB4_bp  4  /* Output Compare Value B bit 4 position. */
#define TIM8_16_OCRB5_bm  (1<<5)  /* Output Compare Value B bit 5 mask. */
#define TIM8_16_OCRB5_bp  5  /* Output Compare Value B bit 5 position. */
#define TIM8_16_OCRB6_bm  (1<<6)  /* Output Compare Value B bit 6 mask. */
#define TIM8_16_OCRB6_bp  6  /* Output Compare Value B bit 6 position. */
#define TIM8_16_OCRB7_bm  (1<<7)  /* Output Compare Value B bit 7 mask. */
#define TIM8_16_OCRB7_bp  7  /* Output Compare Value B bit 7 position. */

/* TIMPRESC - Timer Prescaler */
/* TIMPRESC.PRESC  bit masks and bit positions */
#define TIMPRESC_PSRSYNC_bm  0x01  /* Prescaler Reset bit mask. */
#define TIMPRESC_PSRSYNC_bp  0  /* Prescaler Reset bit position. */
#define TIMPRESC_TSM_bm  0x80  /* Timer Synchronization mode Register bit mask. */
#define TIMPRESC_TSM_bp  7  /* Timer Synchronization mode Register bit position. */

/* TWI - Two-Wire Interface */
/* TWI.CTRL  bit masks and bit positions */
#define TWI_EDIEN_bm  0x01  /* External Driver Interface Enable bit mask. */
#define TWI_EDIEN_bp  0  /* External Driver Interface Enable bit position. */
#define TWI_SDAHOLD_gm  0x06  /* SDA Hold Time Enable group mask. */
#define TWI_SDAHOLD_gp  1  /* SDA Hold Time Enable group position. */
#define TWI_SDAHOLD0_bm  (1<<1)  /* SDA Hold Time Enable bit 0 mask. */
#define TWI_SDAHOLD0_bp  1  /* SDA Hold Time Enable bit 0 position. */
#define TWI_SDAHOLD1_bm  (1<<2)  /* SDA Hold Time Enable bit 1 mask. */
#define TWI_SDAHOLD1_bp  2  /* SDA Hold Time Enable bit 1 position. */

/* TWI_MASTER.CTRLA  bit masks and bit positions */
#define TWI_MASTER_ENABLE_bm  0x08  /* Enable TWI Master bit mask. */
#define TWI_MASTER_ENABLE_bp  3  /* Enable TWI Master bit position. */
#define TWI_MASTER_WIEN_bm  0x10  /* Write Interrupt Enable bit mask. */
#define TWI_MASTER_WIEN_bp  4  /* Write Interrupt Enable bit position. */
#define TWI_MASTER_RIEN_bm  0x20  /* Read Interrupt Enable bit mask. */
#define TWI_MASTER_RIEN_bp  5  /* Read Interrupt Enable bit position. */
#define TWI_MASTER_INTLVL_gm  0xC0  /* Interrupt Level group mask. */
#define TWI_MASTER_INTLVL_gp  6  /* Interrupt Level group position. */
#define TWI_MASTER_INTLVL0_bm  (1<<6)  /* Interrupt Level bit 0 mask. */
#define TWI_MASTER_INTLVL0_bp  6  /* Interrupt Level bit 0 position. */
#define TWI_MASTER_INTLVL1_bm  (1<<7)  /* Interrupt Level bit 1 mask. */
#define TWI_MASTER_INTLVL1_bp  7  /* Interrupt Level bit 1 position. */

/* TWI_MASTER.CTRLB  bit masks and bit positions */
#define TWI_MASTER_SMEN_bm  0x01  /* Smart Mode Enable bit mask. */
#define TWI_MASTER_SMEN_bp  0  /* Smart Mode Enable bit position. */
#define TWI_MASTER_QCEN_bm  0x02  /* Quick Command Enable bit mask. */
#define TWI_MASTER_QCEN_bp  1  /* Quick Command Enable bit position. */
#define TWI_MASTER_TIMEOUT_gm  0x0C  /* Inactive Bus Timeout group mask. */
#define TWI_MASTER_TIMEOUT_gp  2  /* Inactive Bus Timeout group position. */
#define TWI_MASTER_TIMEOUT0_bm  (1<<2)  /* Inactive Bus Timeout bit 0 mask. */
#define TWI_MASTER_TIMEOUT0_bp  2  /* Inactive Bus Timeout bit 0 position. */
#define TWI_MASTER_TIMEOUT1_bm  (1<<3)  /* Inactive Bus Timeout bit 1 mask. */
#define TWI_MASTER_TIMEOUT1_bp  3  /* Inactive Bus Timeout bit 1 position. */

/* TWI_MASTER.CTRLC  bit masks and bit positions */
#define TWI_MASTER_CMD_gm  0x03  /* Command group mask. */
#define TWI_MASTER_CMD_gp  0  /* Command group position. */
#define TWI_MASTER_CMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_MASTER_CMD0_bp  0  /* Command bit 0 position. */
#define TWI_MASTER_CMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_MASTER_CMD1_bp  1  /* Command bit 1 position. */
#define TWI_MASTER_ACKACT_bm  0x04  /* Acknowledge Action bit mask. */
#define TWI_MASTER_ACKACT_bp  2  /* Acknowledge Action bit position. */

/* TWI_MASTER.STATUS  bit masks and bit positions */
#define TWI_MASTER_BUSSTATE_gm  0x03  /* Bus State group mask. */
#define TWI_MASTER_BUSSTATE_gp  0  /* Bus State group position. */
#define TWI_MASTER_BUSSTATE0_bm  (1<<0)  /* Bus State bit 0 mask. */
#define TWI_MASTER_BUSSTATE0_bp  0  /* Bus State bit 0 position. */
#define TWI_MASTER_BUSSTATE1_bm  (1<<1)  /* Bus State bit 1 mask. */
#define TWI_MASTER_BUSSTATE1_bp  1  /* Bus State bit 1 position. */
#define TWI_MASTER_BUSERR_bm  0x04  /* Bus Error bit mask. */
#define TWI_MASTER_BUSERR_bp  2  /* Bus Error bit position. */
#define TWI_MASTER_ARBLOST_bm  0x08  /* Arbitration Lost bit mask. */
#define TWI_MASTER_ARBLOST_bp  3  /* Arbitration Lost bit position. */
#define TWI_MASTER_RXACK_bm  0x10  /* Received Acknowledge bit mask. */
#define TWI_MASTER_RXACK_bp  4  /* Received Acknowledge bit position. */
#define TWI_MASTER_CLKHOLD_bm  0x20  /* Clock Hold bit mask. */
#define TWI_MASTER_CLKHOLD_bp  5  /* Clock Hold bit position. */
#define TWI_MASTER_WIF_bm  0x40  /* Write Interrupt Flag bit mask. */
#define TWI_MASTER_WIF_bp  6  /* Write Interrupt Flag bit position. */
#define TWI_MASTER_RIF_bm  0x80  /* Read Interrupt Flag bit mask. */
#define TWI_MASTER_RIF_bp  7  /* Read Interrupt Flag bit position. */

/* TWI_MASTER.BAUD  bit masks and bit positions */
#define TWI_MASTER_BAUD_gm  0xFF  /* Baud Rade Register group mask. */
#define TWI_MASTER_BAUD_gp  0  /* Baud Rade Register group position. */
#define TWI_MASTER_BAUD0_bm  (1<<0)  /* Baud Rade Register bit 0 mask. */
#define TWI_MASTER_BAUD0_bp  0  /* Baud Rade Register bit 0 position. */
#define TWI_MASTER_BAUD1_bm  (1<<1)  /* Baud Rade Register bit 1 mask. */
#define TWI_MASTER_BAUD1_bp  1  /* Baud Rade Register bit 1 position. */
#define TWI_MASTER_BAUD2_bm  (1<<2)  /* Baud Rade Register bit 2 mask. */
#define TWI_MASTER_BAUD2_bp  2  /* Baud Rade Register bit 2 position. */
#define TWI_MASTER_BAUD3_bm  (1<<3)  /* Baud Rade Register bit 3 mask. */
#define TWI_MASTER_BAUD3_bp  3  /* Baud Rade Register bit 3 position. */
#define TWI_MASTER_BAUD4_bm  (1<<4)  /* Baud Rade Register bit 4 mask. */
#define TWI_MASTER_BAUD4_bp  4  /* Baud Rade Register bit 4 position. */
#define TWI_MASTER_BAUD5_bm  (1<<5)  /* Baud Rade Register bit 5 mask. */
#define TWI_MASTER_BAUD5_bp  5  /* Baud Rade Register bit 5 position. */
#define TWI_MASTER_BAUD6_bm  (1<<6)  /* Baud Rade Register bit 6 mask. */
#define TWI_MASTER_BAUD6_bp  6  /* Baud Rade Register bit 6 position. */
#define TWI_MASTER_BAUD7_bm  (1<<7)  /* Baud Rade Register bit 7 mask. */
#define TWI_MASTER_BAUD7_bp  7  /* Baud Rade Register bit 7 position. */

/* TWI_MASTER.ADDR  bit masks and bit positions */
#define TWI_MASTER_ADDR_gm  0xFF  /* Address Register group mask. */
#define TWI_MASTER_ADDR_gp  0  /* Address Register group position. */
#define TWI_MASTER_ADDR0_bm  (1<<0)  /* Address Register bit 0 mask. */
#define TWI_MASTER_ADDR0_bp  0  /* Address Register bit 0 position. */
#define TWI_MASTER_ADDR1_bm  (1<<1)  /* Address Register bit 1 mask. */
#define TWI_MASTER_ADDR1_bp  1  /* Address Register bit 1 position. */
#define TWI_MASTER_ADDR2_bm  (1<<2)  /* Address Register bit 2 mask. */
#define TWI_MASTER_ADDR2_bp  2  /* Address Register bit 2 position. */
#define TWI_MASTER_ADDR3_bm  (1<<3)  /* Address Register bit 3 mask. */
#define TWI_MASTER_ADDR3_bp  3  /* Address Register bit 3 position. */
#define TWI_MASTER_ADDR4_bm  (1<<4)  /* Address Register bit 4 mask. */
#define TWI_MASTER_ADDR4_bp  4  /* Address Register bit 4 position. */
#define TWI_MASTER_ADDR5_bm  (1<<5)  /* Address Register bit 5 mask. */
#define TWI_MASTER_ADDR5_bp  5  /* Address Register bit 5 position. */
#define TWI_MASTER_ADDR6_bm  (1<<6)  /* Address Register bit 6 mask. */
#define TWI_MASTER_ADDR6_bp  6  /* Address Register bit 6 position. */
#define TWI_MASTER_ADDR7_bm  (1<<7)  /* Address Register bit 7 mask. */
#define TWI_MASTER_ADDR7_bp  7  /* Address Register bit 7 position. */

/* TWI_MASTER.DATA  bit masks and bit positions */
#define TWI_MASTER_DATA_gm  0xFF  /* Address Register group mask. */
#define TWI_MASTER_DATA_gp  0  /* Address Register group position. */
#define TWI_MASTER_DATA0_bm  (1<<0)  /* Address Register bit 0 mask. */
#define TWI_MASTER_DATA0_bp  0  /* Address Register bit 0 position. */
#define TWI_MASTER_DATA1_bm  (1<<1)  /* Address Register bit 1 mask. */
#define TWI_MASTER_DATA1_bp  1  /* Address Register bit 1 position. */
#define TWI_MASTER_DATA2_bm  (1<<2)  /* Address Register bit 2 mask. */
#define TWI_MASTER_DATA2_bp  2  /* Address Register bit 2 position. */
#define TWI_MASTER_DATA3_bm  (1<<3)  /* Address Register bit 3 mask. */
#define TWI_MASTER_DATA3_bp  3  /* Address Register bit 3 position. */
#define TWI_MASTER_DATA4_bm  (1<<4)  /* Address Register bit 4 mask. */
#define TWI_MASTER_DATA4_bp  4  /* Address Register bit 4 position. */
#define TWI_MASTER_DATA5_bm  (1<<5)  /* Address Register bit 5 mask. */
#define TWI_MASTER_DATA5_bp  5  /* Address Register bit 5 position. */
#define TWI_MASTER_DATA6_bm  (1<<6)  /* Address Register bit 6 mask. */
#define TWI_MASTER_DATA6_bp  6  /* Address Register bit 6 position. */
#define TWI_MASTER_DATA7_bm  (1<<7)  /* Address Register bit 7 mask. */
#define TWI_MASTER_DATA7_bp  7  /* Address Register bit 7 position. */

/* TWI_SLAVE.CTRLA  bit masks and bit positions */
#define TWI_SLAVE_SMEN_bm  0x01  /* Smart Mode Enable bit mask. */
#define TWI_SLAVE_SMEN_bp  0  /* Smart Mode Enable bit position. */
#define TWI_SLAVE_PMEN_bm  0x02  /* Promiscuous Mode Enable bit mask. */
#define TWI_SLAVE_PMEN_bp  1  /* Promiscuous Mode Enable bit position. */
#define TWI_SLAVE_PIEN_bm  0x04  /* Stop Interrupt Enable bit mask. */
#define TWI_SLAVE_PIEN_bp  2  /* Stop Interrupt Enable bit position. */
#define TWI_SLAVE_ENABLE_bm  0x08  /* Enable TWI Slave bit mask. */
#define TWI_SLAVE_ENABLE_bp  3  /* Enable TWI Slave bit position. */
#define TWI_SLAVE_APIEN_bm  0x10  /* Address/Stop Interrupt Enable bit mask. */
#define TWI_SLAVE_APIEN_bp  4  /* Address/Stop Interrupt Enable bit position. */
#define TWI_SLAVE_DIEN_bm  0x20  /* Data Interrupt Enable bit mask. */
#define TWI_SLAVE_DIEN_bp  5  /* Data Interrupt Enable bit position. */
#define TWI_SLAVE_INTLVL_gm  0xC0  /* Interrupt Level group mask. */
#define TWI_SLAVE_INTLVL_gp  6  /* Interrupt Level group position. */
#define TWI_SLAVE_INTLVL0_bm  (1<<6)  /* Interrupt Level bit 0 mask. */
#define TWI_SLAVE_INTLVL0_bp  6  /* Interrupt Level bit 0 position. */
#define TWI_SLAVE_INTLVL1_bm  (1<<7)  /* Interrupt Level bit 1 mask. */
#define TWI_SLAVE_INTLVL1_bp  7  /* Interrupt Level bit 1 position. */

/* TWI_SLAVE.CTRLB  bit masks and bit positions */
#define TWI_SLAVE_CMD_gm  0x03  /* Command group mask. */
#define TWI_SLAVE_CMD_gp  0  /* Command group position. */
#define TWI_SLAVE_CMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_SLAVE_CMD0_bp  0  /* Command bit 0 position. */
#define TWI_SLAVE_CMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_SLAVE_CMD1_bp  1  /* Command bit 1 position. */
#define TWI_SLAVE_ACKACT_bm  0x04  /* Acknowledge Action bit mask. */
#define TWI_SLAVE_ACKACT_bp  2  /* Acknowledge Action bit position. */

/* TWI_SLAVE.STATUS  bit masks and bit positions */
#define TWI_SLAVE_AP_bm  0x01  /* Slave Address or Stop bit mask. */
#define TWI_SLAVE_AP_bp  0  /* Slave Address or Stop bit position. */
#define TWI_SLAVE_DIR_bm  0x02  /* Read/Write Direction bit mask. */
#define TWI_SLAVE_DIR_bp  1  /* Read/Write Direction bit position. */
#define TWI_SLAVE_BUSERR_bm  0x04  /* Bus Error bit mask. */
#define TWI_SLAVE_BUSERR_bp  2  /* Bus Error bit position. */
#define TWI_SLAVE_COLL_bm  0x08  /* Collision bit mask. */
#define TWI_SLAVE_COLL_bp  3  /* Collision bit position. */
#define TWI_SLAVE_RXACK_bm  0x10  /* Received Acknowledge bit mask. */
#define TWI_SLAVE_RXACK_bp  4  /* Received Acknowledge bit position. */
#define TWI_SLAVE_CLKHOLD_bm  0x20  /* Clock Hold bit mask. */
#define TWI_SLAVE_CLKHOLD_bp  5  /* Clock Hold bit position. */
#define TWI_SLAVE_APIF_bm  0x40  /* Address/Stop Interrupt Flag bit mask. */
#define TWI_SLAVE_APIF_bp  6  /* Address/Stop Interrupt Flag bit position. */
#define TWI_SLAVE_DIF_bm  0x80  /* Data Interrupt Flag bit mask. */
#define TWI_SLAVE_DIF_bp  7  /* Data Interrupt Flag bit position. */

/* TWI_SLAVE.ADDR  bit masks and bit positions */
#define TWI_SLAVE_ADDR_gm  0xFF  /* Address Register group mask. */
#define TWI_SLAVE_ADDR_gp  0  /* Address Register group position. */
#define TWI_SLAVE_ADDR0_bm  (1<<0)  /* Address Register bit 0 mask. */
#define TWI_SLAVE_ADDR0_bp  0  /* Address Register bit 0 position. */
#define TWI_SLAVE_ADDR1_bm  (1<<1)  /* Address Register bit 1 mask. */
#define TWI_SLAVE_ADDR1_bp  1  /* Address Register bit 1 position. */
#define TWI_SLAVE_ADDR2_bm  (1<<2)  /* Address Register bit 2 mask. */
#define TWI_SLAVE_ADDR2_bp  2  /* Address Register bit 2 position. */
#define TWI_SLAVE_ADDR3_bm  (1<<3)  /* Address Register bit 3 mask. */
#define TWI_SLAVE_ADDR3_bp  3  /* Address Register bit 3 position. */
#define TWI_SLAVE_ADDR4_bm  (1<<4)  /* Address Register bit 4 mask. */
#define TWI_SLAVE_ADDR4_bp  4  /* Address Register bit 4 position. */
#define TWI_SLAVE_ADDR5_bm  (1<<5)  /* Address Register bit 5 mask. */
#define TWI_SLAVE_ADDR5_bp  5  /* Address Register bit 5 position. */
#define TWI_SLAVE_ADDR6_bm  (1<<6)  /* Address Register bit 6 mask. */
#define TWI_SLAVE_ADDR6_bp  6  /* Address Register bit 6 position. */
#define TWI_SLAVE_ADDR7_bm  (1<<7)  /* Address Register bit 7 mask. */
#define TWI_SLAVE_ADDR7_bp  7  /* Address Register bit 7 position. */

/* TWI_SLAVE.DATA  bit masks and bit positions */
#define TWI_SLAVE_DATA_gm  0xFF  /* Data Register group mask. */
#define TWI_SLAVE_DATA_gp  0  /* Data Register group position. */
#define TWI_SLAVE_DATA0_bm  (1<<0)  /* Data Register bit 0 mask. */
#define TWI_SLAVE_DATA0_bp  0  /* Data Register bit 0 position. */
#define TWI_SLAVE_DATA1_bm  (1<<1)  /* Data Register bit 1 mask. */
#define TWI_SLAVE_DATA1_bp  1  /* Data Register bit 1 position. */
#define TWI_SLAVE_DATA2_bm  (1<<2)  /* Data Register bit 2 mask. */
#define TWI_SLAVE_DATA2_bp  2  /* Data Register bit 2 position. */
#define TWI_SLAVE_DATA3_bm  (1<<3)  /* Data Register bit 3 mask. */
#define TWI_SLAVE_DATA3_bp  3  /* Data Register bit 3 position. */
#define TWI_SLAVE_DATA4_bm  (1<<4)  /* Data Register bit 4 mask. */
#define TWI_SLAVE_DATA4_bp  4  /* Data Register bit 4 position. */
#define TWI_SLAVE_DATA5_bm  (1<<5)  /* Data Register bit 5 mask. */
#define TWI_SLAVE_DATA5_bp  5  /* Data Register bit 5 position. */
#define TWI_SLAVE_DATA6_bm  (1<<6)  /* Data Register bit 6 mask. */
#define TWI_SLAVE_DATA6_bp  6  /* Data Register bit 6 position. */
#define TWI_SLAVE_DATA7_bm  (1<<7)  /* Data Register bit 7 mask. */
#define TWI_SLAVE_DATA7_bp  7  /* Data Register bit 7 position. */

/* TWI_SLAVE.ADDRMASK  bit masks and bit positions */
#define TWI_SLAVE_ADDREN_bm  0x01  /* Address Enable bit mask. */
#define TWI_SLAVE_ADDREN_bp  0  /* Address Enable bit position. */
#define TWI_SLAVE_ADDRMASK_gm  0xFE  /* Address Mask group mask. */
#define TWI_SLAVE_ADDRMASK_gp  1  /* Address Mask group position. */
#define TWI_SLAVE_ADDRMASK0_bm  (1<<1)  /* Address Mask bit 0 mask. */
#define TWI_SLAVE_ADDRMASK0_bp  1  /* Address Mask bit 0 position. */
#define TWI_SLAVE_ADDRMASK1_bm  (1<<2)  /* Address Mask bit 1 mask. */
#define TWI_SLAVE_ADDRMASK1_bp  2  /* Address Mask bit 1 position. */
#define TWI_SLAVE_ADDRMASK2_bm  (1<<3)  /* Address Mask bit 2 mask. */
#define TWI_SLAVE_ADDRMASK2_bp  3  /* Address Mask bit 2 position. */
#define TWI_SLAVE_ADDRMASK3_bm  (1<<4)  /* Address Mask bit 3 mask. */
#define TWI_SLAVE_ADDRMASK3_bp  4  /* Address Mask bit 3 position. */
#define TWI_SLAVE_ADDRMASK4_bm  (1<<5)  /* Address Mask bit 4 mask. */
#define TWI_SLAVE_ADDRMASK4_bp  5  /* Address Mask bit 4 position. */
#define TWI_SLAVE_ADDRMASK5_bm  (1<<6)  /* Address Mask bit 5 mask. */
#define TWI_SLAVE_ADDRMASK5_bp  6  /* Address Mask bit 5 position. */
#define TWI_SLAVE_ADDRMASK6_bm  (1<<7)  /* Address Mask bit 6 mask. */
#define TWI_SLAVE_ADDRMASK6_bp  7  /* Address Mask bit 6 position. */

/* VPORT - Virtual Ports */
/* VPORT.DIR  bit masks and bit positions */
#define VPORT_DIR_gm  0xFF  /* Data Direction Value group mask. */
#define VPORT_DIR_gp  0  /* Data Direction Value group position. */
#define VPORT_DIR0_bm  (1<<0)  /* Data Direction Value bit 0 mask. */
#define VPORT_DIR0_bp  0  /* Data Direction Value bit 0 position. */
#define VPORT_DIR1_bm  (1<<1)  /* Data Direction Value bit 1 mask. */
#define VPORT_DIR1_bp  1  /* Data Direction Value bit 1 position. */
#define VPORT_DIR2_bm  (1<<2)  /* Data Direction Value bit 2 mask. */
#define VPORT_DIR2_bp  2  /* Data Direction Value bit 2 position. */
#define VPORT_DIR3_bm  (1<<3)  /* Data Direction Value bit 3 mask. */
#define VPORT_DIR3_bp  3  /* Data Direction Value bit 3 position. */
#define VPORT_DIR4_bm  (1<<4)  /* Data Direction Value bit 4 mask. */
#define VPORT_DIR4_bp  4  /* Data Direction Value bit 4 position. */
#define VPORT_DIR5_bm  (1<<5)  /* Data Direction Value bit 5 mask. */
#define VPORT_DIR5_bp  5  /* Data Direction Value bit 5 position. */
#define VPORT_DIR6_bm  (1<<6)  /* Data Direction Value bit 6 mask. */
#define VPORT_DIR6_bp  6  /* Data Direction Value bit 6 position. */
#define VPORT_DIR7_bm  (1<<7)  /* Data Direction Value bit 7 mask. */
#define VPORT_DIR7_bp  7  /* Data Direction Value bit 7 position. */

/* VPORT.OUT  bit masks and bit positions */
#define VPORT_OUT_gm  0xFF  /* Output Value group mask. */
#define VPORT_OUT_gp  0  /* Output Value group position. */
#define VPORT_OUT0_bm  (1<<0)  /* Output Value bit 0 mask. */
#define VPORT_OUT0_bp  0  /* Output Value bit 0 position. */
#define VPORT_OUT1_bm  (1<<1)  /* Output Value bit 1 mask. */
#define VPORT_OUT1_bp  1  /* Output Value bit 1 position. */
#define VPORT_OUT2_bm  (1<<2)  /* Output Value bit 2 mask. */
#define VPORT_OUT2_bp  2  /* Output Value bit 2 position. */
#define VPORT_OUT3_bm  (1<<3)  /* Output Value bit 3 mask. */
#define VPORT_OUT3_bp  3  /* Output Value bit 3 position. */
#define VPORT_OUT4_bm  (1<<4)  /* Output Value bit 4 mask. */
#define VPORT_OUT4_bp  4  /* Output Value bit 4 position. */
#define VPORT_OUT5_bm  (1<<5)  /* Output Value bit 5 mask. */
#define VPORT_OUT5_bp  5  /* Output Value bit 5 position. */
#define VPORT_OUT6_bm  (1<<6)  /* Output Value bit 6 mask. */
#define VPORT_OUT6_bp  6  /* Output Value bit 6 position. */
#define VPORT_OUT7_bm  (1<<7)  /* Output Value bit 7 mask. */
#define VPORT_OUT7_bp  7  /* Output Value bit 7 position. */

/* VPORT.IN  bit masks and bit positions */
#define VPORT_IN_gm  0xFF  /* Input Value group mask. */
#define VPORT_IN_gp  0  /* Input Value group position. */
#define VPORT_IN0_bm  (1<<0)  /* Input Value bit 0 mask. */
#define VPORT_IN0_bp  0  /* Input Value bit 0 position. */
#define VPORT_IN1_bm  (1<<1)  /* Input Value bit 1 mask. */
#define VPORT_IN1_bp  1  /* Input Value bit 1 position. */
#define VPORT_IN2_bm  (1<<2)  /* Input Value bit 2 mask. */
#define VPORT_IN2_bp  2  /* Input Value bit 2 position. */
#define VPORT_IN3_bm  (1<<3)  /* Input Value bit 3 mask. */
#define VPORT_IN3_bp  3  /* Input Value bit 3 position. */
#define VPORT_IN4_bm  (1<<4)  /* Input Value bit 4 mask. */
#define VPORT_IN4_bp  4  /* Input Value bit 4 position. */
#define VPORT_IN5_bm  (1<<5)  /* Input Value bit 5 mask. */
#define VPORT_IN5_bp  5  /* Input Value bit 5 position. */
#define VPORT_IN6_bm  (1<<6)  /* Input Value bit 6 mask. */
#define VPORT_IN6_bp  6  /* Input Value bit 6 position. */
#define VPORT_IN7_bm  (1<<7)  /* Input Value bit 7 mask. */
#define VPORT_IN7_bp  7  /* Input Value bit 7 position. */

/* VPORT.INTFLAGS  bit masks and bit positions */
#define VPORT_INT0IF_bm  0x01  /* Port Interrupt 0 Flag bit mask. */
#define VPORT_INT0IF_bp  0  /* Port Interrupt 0 Flag bit position. */
#define VPORT_INT1IF_bm  0x02  /* Port Interrupt 1 Flag bit mask. */
#define VPORT_INT1IF_bp  1  /* Port Interrupt 1 Flag bit position. */

/* WDT - Watch-Dog Timer */
/* WDT.CTRL  bit masks and bit positions */
#define WDT_CEN_bm  0x01  /* Change Enable bit mask. */
#define WDT_CEN_bp  0  /* Change Enable bit position. */
#define WDT_ENABLE_bm  0x02  /* Enable bit mask. */
#define WDT_ENABLE_bp  1  /* Enable bit position. */
#define WDT_PER_gm  0x3C  /* Period group mask. */
#define WDT_PER_gp  2  /* Period group position. */
#define WDT_PER0_bm  (1<<2)  /* Period bit 0 mask. */
#define WDT_PER0_bp  2  /* Period bit 0 position. */
#define WDT_PER1_bm  (1<<3)  /* Period bit 1 mask. */
#define WDT_PER1_bp  3  /* Period bit 1 position. */
#define WDT_PER2_bm  (1<<4)  /* Period bit 2 mask. */
#define WDT_PER2_bp  4  /* Period bit 2 position. */
#define WDT_PER3_bm  (1<<5)  /* Period bit 3 mask. */
#define WDT_PER3_bp  5  /* Period bit 3 position. */

/* WDT.WINCTRL  bit masks and bit positions */
#define WDT_WCEN_bm  0x01  /* Windowed Mode Change Enable bit mask. */
#define WDT_WCEN_bp  0  /* Windowed Mode Change Enable bit position. */
#define WDT_WEN_bm  0x02  /* Windowed Mode Enable bit mask. */
#define WDT_WEN_bp  1  /* Windowed Mode Enable bit position. */
#define WDT_WPER_gm  0x3C  /* Windowed Mode Period group mask. */
#define WDT_WPER_gp  2  /* Windowed Mode Period group position. */
#define WDT_WPER0_bm  (1<<2)  /* Windowed Mode Period bit 0 mask. */
#define WDT_WPER0_bp  2  /* Windowed Mode Period bit 0 position. */
#define WDT_WPER1_bm  (1<<3)  /* Windowed Mode Period bit 1 mask. */
#define WDT_WPER1_bp  3  /* Windowed Mode Period bit 1 position. */
#define WDT_WPER2_bm  (1<<4)  /* Windowed Mode Period bit 2 mask. */
#define WDT_WPER2_bp  4  /* Windowed Mode Period bit 2 position. */
#define WDT_WPER3_bm  (1<<5)  /* Windowed Mode Period bit 3 mask. */
#define WDT_WPER3_bp  5  /* Windowed Mode Period bit 3 position. */

/* WDT.STATUS  bit masks and bit positions */
#define WDT_SYNCBUSY_bm  0x01  /* Synchronization busy bit mask. */
#define WDT_SYNCBUSY_bp  0  /* Synchronization busy bit position. */

/* WUT - Wake-up Timer */
/* WUT.CTRL  bit masks and bit positions */
#define WUT_PRESC_gm  0x07  /* Wake-up Timer Prescaling group mask. */
#define WUT_PRESC_gp  0  /* Wake-up Timer Prescaling group position. */
#define WUT_PRESC0_bm  (1<<0)  /* Wake-up Timer Prescaling bit 0 mask. */
#define WUT_PRESC0_bp  0  /* Wake-up Timer Prescaling bit 0 position. */
#define WUT_PRESC1_bm  (1<<1)  /* Wake-up Timer Prescaling bit 1 mask. */
#define WUT_PRESC1_bp  1  /* Wake-up Timer Prescaling bit 1 position. */
#define WUT_PRESC2_bm  (1<<2)  /* Wake-up Timer Prescaling bit 2 mask. */
#define WUT_PRESC2_bp  2  /* Wake-up Timer Prescaling bit 2 position. */
#define WUT_MODE_gm  0x18  /* Wake-up Timer Mode group mask. */
#define WUT_MODE_gp  3  /* Wake-up Timer Mode group position. */
#define WUT_MODE0_bm  (1<<3)  /* Wake-up Timer Mode bit 0 mask. */
#define WUT_MODE0_bp  3  /* Wake-up Timer Mode bit 0 position. */
#define WUT_MODE1_bm  (1<<4)  /* Wake-up Timer Mode bit 1 mask. */
#define WUT_MODE1_bp  4  /* Wake-up Timer Mode bit 1 position. */

/* WUT.INTCTRL  bit masks and bit positions */
#define WUT_INTLVL_gm  0x03  /* Wake-up Timer Interrupt Level group mask. */
#define WUT_INTLVL_gp  0  /* Wake-up Timer Interrupt Level group position. */
#define WUT_INTLVL0_bm  (1<<0)  /* Wake-up Timer Interrupt Level bit 0 mask. */
#define WUT_INTLVL0_bp  0  /* Wake-up Timer Interrupt Level bit 0 position. */
#define WUT_INTLVL1_bm  (1<<1)  /* Wake-up Timer Interrupt Level bit 1 mask. */
#define WUT_INTLVL1_bp  1  /* Wake-up Timer Interrupt Level bit 1 position. */

/* WUT.STATUS  bit masks and bit positions */
#define WUT_OVIF_bm  0x01  /* Overflow Interrupt Flag bit mask. */
#define WUT_OVIF_bp  0  /* Overflow Interrupt Flag bit position. */
#define WUT_SBSY_bm  0x80  /* Synchronization Busy bit mask. */
#define WUT_SBSY_bp  7  /* Synchronization Busy bit position. */

/* XOCD - On-Chip Debug System */
/* OCD.OCDR0  bit masks and bit positions */
#define OCD_OCDRD_gm  0xFF  /* OCDR Dirty group mask. */
#define OCD_OCDRD_gp  0  /* OCDR Dirty group position. */
#define OCD_OCDRD0_bm  (1<<0)  /* OCDR Dirty bit 0 mask. */
#define OCD_OCDRD0_bp  0  /* OCDR Dirty bit 0 position. */
#define OCD_OCDRD1_bm  (1<<1)  /* OCDR Dirty bit 1 mask. */
#define OCD_OCDRD1_bp  1  /* OCDR Dirty bit 1 position. */
#define OCD_OCDRD2_bm  (1<<2)  /* OCDR Dirty bit 2 mask. */
#define OCD_OCDRD2_bp  2  /* OCDR Dirty bit 2 position. */
#define OCD_OCDRD3_bm  (1<<3)  /* OCDR Dirty bit 3 mask. */
#define OCD_OCDRD3_bp  3  /* OCDR Dirty bit 3 position. */
#define OCD_OCDRD4_bm  (1<<4)  /* OCDR Dirty bit 4 mask. */
#define OCD_OCDRD4_bp  4  /* OCDR Dirty bit 4 position. */
#define OCD_OCDRD5_bm  (1<<5)  /* OCDR Dirty bit 5 mask. */
#define OCD_OCDRD5_bp  5  /* OCDR Dirty bit 5 position. */
#define OCD_OCDRD6_bm  (1<<6)  /* OCDR Dirty bit 6 mask. */
#define OCD_OCDRD6_bp  6  /* OCDR Dirty bit 6 position. */
#define OCD_OCDRD7_bm  (1<<7)  /* OCDR Dirty bit 7 mask. */
#define OCD_OCDRD7_bp  7  /* OCDR Dirty bit 7 position. */

/* OCD.OCDR1  bit masks and bit positions */
/* OCD_OCDRD  is already defined. */



// Generic Port Pins

#define PIN0_bm 0x01
#define PIN0_bp 0
#define PIN1_bm 0x02
#define PIN1_bp 1
#define PIN2_bm 0x04
#define PIN2_bp 2
#define PIN3_bm 0x08
#define PIN3_bp 3
#define PIN4_bm 0x10
#define PIN4_bp 4
#define PIN5_bm 0x20
#define PIN5_bp 5
#define PIN6_bm 0x40
#define PIN6_bp 6
#define PIN7_bm 0x80
#define PIN7_bp 7

/* ========== Interrupt Vector Definitions ========== */
/* Vector 0 is the reset vector */

/* ADC_GEN_CH interrupt vectors */
#define ADC_GEN_CH_ADC_GEN_CH_vect_num  8
#define ADC_GEN_CH_ADC_GEN_CH_vect      _VECTOR(8)  /* ADC General Channel Interrupt */

/* ADC_CMN interrupt vectors */
#define ADC_CMN_ADC_CMN_vect_num  9
#define ADC_CMN_ADC_CMN_vect      _VECTOR(9)  /* ADC Sensor Settling Interrupt */

/* PORTA interrupt vectors */
#define PORTA_INT0_vect_num  10
#define PORTA_INT0_vect      _VECTOR(10)  /* External Interrupt 0 */
#define PORTA_INT1_vect_num  11
#define PORTA_INT1_vect      _VECTOR(11)  /* External Interrupt 1 */

/* PORTB interrupt vectors */
#define PORTB_INT0_vect_num  12
#define PORTB_INT0_vect      _VECTOR(12)  /* External Interrupt 0 */
#define PORTB_INT1_vect_num  13
#define PORTB_INT1_vect      _VECTOR(13)  /* External Interrupt 1 */

/* PORTC interrupt vectors */
#define PORTC_INT0_vect_num  14
#define PORTC_INT0_vect      _VECTOR(14)  /* External Interrupt 0 */
#define PORTC_INT1_vect_num  15
#define PORTC_INT1_vect      _VECTOR(15)  /* External Interrupt 1 */

/* WUT interrupt vectors */
#define WUT_WUT_vect_num  16
#define WUT_WUT_vect      _VECTOR(16)  /* Wake-up Timeout */

/* TIMER0 interrupt vectors */
#define TIMER0_OVF_vect_num  17
#define TIMER0_OVF_vect      _VECTOR(17)  /* Overflow Interrupt */
#define TIMER0_OCFA_vect_num  18
#define TIMER0_OCFA_vect      _VECTOR(18)  /* Output Compare A Interrupt */
#define TIMER0_OCFB_vect_num  19
#define TIMER0_OCFB_vect      _VECTOR(19)  /* Output Compare B Interrupt  */
#define TIMER0_ICF_vect_num  20
#define TIMER0_ICF_vect      _VECTOR(20)  /* Input Capture Interrupt */

/* TIMER1 interrupt vectors */
#define TIMER1_OVF_vect_num  21
#define TIMER1_OVF_vect      _VECTOR(21)  /* Overflow Interrupt */
#define TIMER1_OCFA_vect_num  22
#define TIMER1_OCFA_vect      _VECTOR(22)  /* Output Compare A Interrupt */
#define TIMER1_OCFB_vect_num  23
#define TIMER1_OCFB_vect      _VECTOR(23)  /* Output Compare B Interrupt  */
#define TIMER1_ICF_vect_num  24
#define TIMER1_ICF_vect      _VECTOR(24)  /* Input Capture Interrupt */

/* TWIC interrupt vectors */
#define TWIC_TWIS_vect_num  25
#define TWIC_TWIS_vect      _VECTOR(25)  /* TWI Slave Interrupt */
#define TWIC_TWIM_vect_num  26
#define TWIC_TWIM_vect      _VECTOR(26)  /* TWI Master Interrupt */

/* NVM interrupt vectors */
#define NVM_EE_vect_num  27
#define NVM_EE_vect      _VECTOR(27)  /* EE Interrupt */
#define NVM_SPM_vect_num  28
#define NVM_SPM_vect      _VECTOR(28)  /* SPM Interrupt */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (29 * _VECTOR_SIZE)


/* ========== Constants ========== */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_START     (0x0000)
#  define PROGMEM_SIZE      (16384)
#else
#  define PROGMEM_START     (0x0000U)
#  define PROGMEM_SIZE      (16384U)
#endif
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define APP_SECTION_START     (0x0000)
#  define APP_SECTION_SIZE      (12288)
#  define APP_SECTION_PAGE_SIZE (128)
#else
#  define APP_SECTION_START     (0x0000U)
#  define APP_SECTION_SIZE      (12288U)
#  define APP_SECTION_PAGE_SIZE (128U)
#endif
#define APP_SECTION_END       (APP_SECTION_START + APP_SECTION_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define APPTABLE_SECTION_START     (0x2000)
#  define APPTABLE_SECTION_SIZE      (4096)
#  define APPTABLE_SECTION_PAGE_SIZE (128)
#else
#  define APPTABLE_SECTION_START     (0x2000U)
#  define APPTABLE_SECTION_SIZE      (4096U)
#  define APPTABLE_SECTION_PAGE_SIZE (128U)
#endif
#define APPTABLE_SECTION_END       (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define BOOT_SECTION_START     (0x3000)
#  define BOOT_SECTION_SIZE      (4096)
#  define BOOT_SECTION_PAGE_SIZE (128)
#else
#  define BOOT_SECTION_START     (0x3000U)
#  define BOOT_SECTION_SIZE      (4096U)
#  define BOOT_SECTION_PAGE_SIZE (128U)
#endif
#define BOOT_SECTION_END       (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define DATAMEM_START     (0x0000)
#  define DATAMEM_SIZE      (12288)
#else
#  define DATAMEM_START     (0x0000U)
#  define DATAMEM_SIZE      (12288U)
#endif
#define DATAMEM_END       (DATAMEM_START + DATAMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define IO_START     (0x0000)
#  define IO_SIZE      (4096)
#  define IO_PAGE_SIZE (0)
#else
#  define IO_START     (0x0000U)
#  define IO_SIZE      (4096U)
#  define IO_PAGE_SIZE (0U)
#endif
#define IO_END       (IO_START + IO_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define INTERNAL_SRAM_START     (0x2000)
#  define INTERNAL_SRAM_SIZE      (1024)
#  define INTERNAL_SRAM_PAGE_SIZE (0)
#else
#  define INTERNAL_SRAM_START     (0x2000U)
#  define INTERNAL_SRAM_SIZE      (1024U)
#  define INTERNAL_SRAM_PAGE_SIZE (0U)
#endif
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SIGNATURES_START     (0x0000)
#  define SIGNATURES_SIZE      (3)
#  define SIGNATURES_PAGE_SIZE (0)
#else
#  define SIGNATURES_START     (0x0000U)
#  define SIGNATURES_SIZE      (3U)
#  define SIGNATURES_PAGE_SIZE (0U)
#endif
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define FUSES_START     (0x0000)
#  define FUSES_SIZE      (7)
#  define FUSES_PAGE_SIZE (0)
#else
#  define FUSES_START     (0x0000U)
#  define FUSES_SIZE      (7U)
#  define FUSES_PAGE_SIZE (0U)
#endif
#define FUSES_END       (FUSES_START + FUSES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define LOCKBITS_START     (0x0000)
#  define LOCKBITS_SIZE      (1)
#  define LOCKBITS_PAGE_SIZE (0)
#else
#  define LOCKBITS_START     (0x0000U)
#  define LOCKBITS_SIZE      (1U)
#  define LOCKBITS_PAGE_SIZE (0U)
#endif
#define LOCKBITS_END       (LOCKBITS_START + LOCKBITS_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define USER_SIGNATURES_START     (0x0000)
#  define USER_SIGNATURES_SIZE      (128)
#  define USER_SIGNATURES_PAGE_SIZE (128)
#else
#  define USER_SIGNATURES_START     (0x0000U)
#  define USER_SIGNATURES_SIZE      (128U)
#  define USER_SIGNATURES_PAGE_SIZE (128U)
#endif
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROD_SIGNATURES_START     (0x0000)
#  define PROD_SIGNATURES_SIZE      (128)
#  define PROD_SIGNATURES_PAGE_SIZE (128)
#else
#  define PROD_SIGNATURES_START     (0x0000U)
#  define PROD_SIGNATURES_SIZE      (128U)
#  define PROD_SIGNATURES_PAGE_SIZE (128U)
#endif
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SPM_PAGESIZE 128
#else
#  define SPM_PAGESIZE 128U
#endif
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END


/* ========== Fuses ========== */
#define FUSE_MEMORY_SIZE 7

/* Fuse Byte 0 Reserved */

/* Fuse Byte 1 Reserved */

/* Fuse Byte 2 Reserved */

/* Fuse Byte 3 Reserved */

/* Fuse Byte 4 (FUSEBYTE4) */
#define FUSE_WDLOCK  (unsigned char)~_BV(1)  /* Watchdog Timer Lock */
#define FUSE_SUT0  (unsigned char)~_BV(2)  /* Start-up Time Bit 0 */
#define FUSE_SUT1  (unsigned char)~_BV(3)  /* Start-up Time Bit 1 */
#define FUSE_RSTDISBL  (unsigned char)~_BV(4)  /* External Reset Disable */
#define FUSE_BOOTRST  (unsigned char)~_BV(5)  /* Boot Loader Section Reset Vector */
#define FUSE4_DEFAULT  (0xFB)
#define FUSE_FUSEBYTE4_DEFAULT  (0xFB)

/* Fuse Byte 5 (FUSEBYTE5) */
#define FUSE_RESERVED0  (unsigned char)~_BV(0)  /* Reserved for factory calibration Bit 0 */
#define FUSE_RESERVED1  (unsigned char)~_BV(1)  /* Reserved for factory calibration Bit 1 */
#define FUSE_RESERVED2  (unsigned char)~_BV(2)  /* Reserved for factory calibration Bit 2 */
#define FUSE_RESERVED3  (unsigned char)~_BV(3)  /* Reserved for factory calibration Bit 3 */
#define FUSE_RESERVED4  (unsigned char)~_BV(4)  /* Reserved for factory calibration Bit 4 */
#define FUSE_RESERVED5  (unsigned char)~_BV(5)  /* Reserved for factory calibration Bit 5 */
#define FUSE_RESERVED6  (unsigned char)~_BV(6)  /* Reserved for factory calibration Bit 6 */
#define FUSE_RESERVED7  (unsigned char)~_BV(7)  /* Reserved for factory calibration Bit 7 */
#define FUSE5_DEFAULT  (0x2F)
#define FUSE_FUSEBYTE5_DEFAULT  (0x2F)

/* Fuse Byte 6 (FUSEBYTE6) */
#define FUSE_WDPER0  (unsigned char)~_BV(0)  /* Watchdog Timeout Period Bit 0 */
#define FUSE_WDPER1  (unsigned char)~_BV(1)  /* Watchdog Timeout Period Bit 1 */
#define FUSE_WDPER2  (unsigned char)~_BV(2)  /* Watchdog Timeout Period Bit 2 */
#define FUSE_WDPER3  (unsigned char)~_BV(3)  /* Watchdog Timeout Period Bit 3 */
#define FUSE_WDWPER0  (unsigned char)~_BV(4)  /* Watchdog Window Timeout Period Bit 0 */
#define FUSE_WDWPER1  (unsigned char)~_BV(5)  /* Watchdog Window Timeout Period Bit 1 */
#define FUSE_WDWPER2  (unsigned char)~_BV(6)  /* Watchdog Window Timeout Period Bit 2 */
#define FUSE_WDWPER3  (unsigned char)~_BV(7)  /* Watchdog Window Timeout Period Bit 3 */
#define FUSE6_DEFAULT  (0xFF)
#define FUSE_FUSEBYTE6_DEFAULT  (0xFF)

/* ========== Lock Bits ========== */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_APPLICATION_TABLE_BITS_EXIST
#define __BOOT_LOCK_APPLICATION_BITS_EXIST
#define __BOOT_LOCK_BOOT_BITS_EXIST

/* ========== Signature ========== */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x94
#define SIGNATURE_2 0x48


#endif /* #ifdef _AVR_ATMXTS220_H_INCLUDED */

