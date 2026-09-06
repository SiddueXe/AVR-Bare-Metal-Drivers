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
#  define _AVR_IOXXX_H_ "iomaxbse.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_MAXBSE_H_INCLUDED
#define _AVR_MAXBSE_H_INCLUDED

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
BOD12 - BOD 1.2V
--------------------------------------------------------------------------
*/

/* BOD 1.2V */
typedef struct BOD12_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t PSEL;  /* Prescaler Select */
    register8_t LEVEL;  /* Level */
    register8_t DEBUGCTRL;  /* Debug Control */
    register8_t STATUS;  /* Status Register */
    register8_t reserved_1[3];
} BOD12_t;


/*
--------------------------------------------------------------------------
BOD12EXT - BODEXT 1.2V
--------------------------------------------------------------------------
*/

/* BODEXT 1.2V */
typedef struct BOD12EXT_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t STATUS;  /* Status Register */
    register8_t ISOCTRL;  /* Isolation Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTF;  /* Interrupt Flag Register */
    register8_t reserved_1[2];
} BOD12EXT_t;


/*
--------------------------------------------------------------------------
BOD33 - BOD 3.3V
--------------------------------------------------------------------------
*/

/* BOD 3.3V */
typedef struct BOD33_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t PSEL;  /* Prescaler Select */
    register8_t LEVEL;  /* Level */
    register8_t DEBUGCTRL;  /* Debug Control */
    register8_t STATUS;  /* Status Register */
    register8_t reserved_1[3];
} BOD33_t;


/*
--------------------------------------------------------------------------
BUSBRG - Bus Bridge AVR8
--------------------------------------------------------------------------
*/

/* Bus Bridge AVR8 */
typedef struct BUSBRG_struct
{
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t STATUS;  /* Status Register */
    register8_t RXDATA;  /* RX Data */
    register8_t TXDATA;  /* TX Data */
    register8_t MEMADDRL;  /* Memory address low */
    register8_t MEMADDRH;  /* Memory address high */
    register8_t reserved_1[2];
} BUSBRG_t;


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
    register8_t reserved_2[1];
    register8_t OSCTST;  /* Oscillator Test Register */
    register8_t reserved_3[7];
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
CODEMEM - CODEMEM
--------------------------------------------------------------------------
*/

/* CODEMEM */
typedef struct CODEMEM_struct
{
    register8_t CRCENDADRL;  /* CRC End Address Low */
    register8_t CRCENDADRH;  /* CRC End Address High */
    register8_t CMEMCAL;  /* Code Memory Calibration Register */
    register8_t DMEMCAL;  /* Data Memory Calibration Register */
    register8_t reserved_1[4];
} CODEMEM_t;


/*
--------------------------------------------------------------------------
CONFIG - CONFIG
--------------------------------------------------------------------------
*/

/* CONFIG */
typedef struct CONFIG_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t INT;  /* Interrupt Register */
    register8_t reserved_1[2];
} CONFIG_t;


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
CRC - CRC
--------------------------------------------------------------------------
*/

/* CRC */
typedef struct CRC_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t STATUS;  /* Status Register */
    register8_t reserved_1[1];
    register8_t DATAIN;  /* Data Input Register */
    register8_t CHECKSUM0;  /* Checksum Byte 0 */
    register8_t CHECKSUM1;  /* Checksum Byte 1 */
    register8_t CHECKSUM2;  /* Checksum Byte 2 */
    register8_t CHECKSUM3;  /* Checksum Byte 3 */
} CRC_t;


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
PTC - Peripheral Touch Controller
--------------------------------------------------------------------------
*/

/* Peripheral Touch Controller */
typedef struct PTC_struct
{
    register8_t CTRLA;  /* Control A Register */
    register8_t reserved_1[3];
    register8_t CTRLB;  /* Control B Register */
    register8_t EVCTRL;  /* Event Control Register */
    register8_t reserved_2[2];
    register8_t INTEN;  /* Interrupt Level Register */
    register8_t reserved_3[1];
    register8_t INTFLAG;  /* Interrupt Flag Register */
    register8_t reserved_4[1];
    register8_t CTSCTRLA;  /* Capacitive Touch Sensing Control Register A */
    register8_t CTSCTRLC;  /* CTS Control C Register */
    register8_t reserved_5[2];
    register8_t YSELL;  /* Y Select Low Register */
    register8_t YSELH;  /* Y Select High Register */
    register8_t XSELL;  /* X Select Low Register */
    register8_t XSELH;  /* X Select High Register */
    register8_t YENL;  /* Y Enable Low Register */
    register8_t YENH;  /* Y Enable High Register */
    register8_t XENL;  /* X Enable Low Register */
    register8_t XENH;  /* X Enable High Register */
    register8_t CCCALL;  /* CTS Compensation Calibration Register */
    register8_t CCCALH;  /* CTS Compensations Calibration Register */
    register8_t CICAL;  /* CI Calibration Register */
    register8_t CTSRS;  /* CTSRS Register */
    register8_t RESULTL;  /* Result Low Register */
    register8_t RESULTH;  /* Result High Register */
    register8_t reserved_6[2];
    register8_t CTSCTRLB;  /* CTS Control B Register */
    register8_t WINCTRL;  /* Win Control Register */
    register8_t reserved_7[2];
    register8_t WCHTL;  /* WCHT Low Register */
    register8_t WCHTH;  /* WCHT High Register */
    register8_t WCLTL;  /* WCLT Low Register */
    register8_t WCLTH;  /* WCLT High Register */
    register8_t XYSEL;  /* XY Select Register */
    register8_t reserved_8[23];
} PTC_t;


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
VREF - Voltage Reference
--------------------------------------------------------------------------
*/

/* Voltage Reference */
typedef struct VREF_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t CALIBA;  /* Calibration Register A */
    register8_t CALIBB;  /* Calibration Register B */
    register8_t TESTA;  /* Test A */
    register8_t TESTB;  /* Test B */
    register8_t STATUS;  /* Status */
    register8_t TESTUVREFA;  /* Test Ulp VREF A */
    register8_t TESTPOR;  /* Test POR */
} VREF_t;


/*
--------------------------------------------------------------------------
VREG - Voltage Regulators
--------------------------------------------------------------------------
*/

/* Voltage Regulators */
typedef struct VREG_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t TESTA;  /* Test A */
    register8_t TESTB;  /* Test B */
    register8_t TESTC;  /* Test C */
} VREG_t;


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
    WDT_PER_125CLK_gc = (0x04<<2),  /* 125 cycles (0.125s) */
    WDT_PER_250CLK_gc = (0x05<<2),  /* 250 cycles (0.25s) */
    WDT_PER_500CLK_gc = (0x06<<2),  /* 500 cycles (0.5s) */
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
    WDT_WPER_125CLK_gc = (0x04<<2),  /* 125 cycles (0.125s ) */
    WDT_WPER_250CLK_gc = (0x05<<2),  /* 250 cycles (0.25s ) */
    WDT_WPER_500CLK_gc = (0x06<<2),  /* 500 cycles (0.5s ) */
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
#define VREF                 (*(VREF_t *) 0x0048) /* Voltage Reference */
#define VREG                 (*(VREG_t *) 0x004C) /* Voltage Regulators */
#define CLK                   (*(CLK_t *) 0x0050) /* Clock System */
#define WDT                   (*(WDT_t *) 0x0080) /* Watch-Dog Timer */
#define MCU                   (*(MCU_t *) 0x0090) /* MCU Control */
#define PMIC                 (*(PMIC_t *) 0x00A0) /* Programmable Multi-level Interrupt Controller */
#define CRC                   (*(CRC_t *) 0x00B0) /* CRC */
#define WUT                   (*(WUT_t *) 0x00C0) /* Wake-up Timer */
#define CONFIG             (*(CONFIG_t *) 0x00D0) /* CONFIG */
#define BOD33               (*(BOD33_t *) 0x00E0) /* BOD 3.3V */
#define BOD12               (*(BOD12_t *) 0x00E8) /* BOD 1.2V */
#define BOD12EXT         (*(BOD12EXT_t *) 0x00F0) /* BODEXT 1.2V */
#define CODEMEM           (*(CODEMEM_t *) 0x01C0) /* CODEMEM */
#define PTC                   (*(PTC_t *) 0x0280) /* Peripheral Touch Controller */
#define BUSBRG             (*(BUSBRG_t *) 0x03C0) /* Bus Bridge AVR8 */
#define PORTA                (*(PORT_t *) 0x0480) /* I/O Ports */
#define PORTB                (*(PORT_t *) 0x04A0) /* I/O Ports */

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


/* VREF - Voltage Reference */
#define VREF_CTRL  _SFR_MEM8(0x0048)
#define VREF_CALIBA  _SFR_MEM8(0x0049)
#define VREF_CALIBB  _SFR_MEM8(0x004A)
#define VREF_TESTA  _SFR_MEM8(0x004B)
#define VREF_TESTB  _SFR_MEM8(0x004C)
#define VREF_STATUS  _SFR_MEM8(0x004D)
#define VREF_TESTUVREFA  _SFR_MEM8(0x004E)
#define VREF_TESTPOR  _SFR_MEM8(0x004F)


/* VREG - Voltage Regulators */
#define VREG_CTRL  _SFR_MEM8(0x004C)
#define VREG_TESTA  _SFR_MEM8(0x004D)
#define VREG_TESTB  _SFR_MEM8(0x004E)
#define VREG_TESTC  _SFR_MEM8(0x004F)


/* CLK - Clock System */
#define CLK_CLKPSR  _SFR_MEM8(0x0050)
#define CLK_CLKSLR  _SFR_MEM8(0x0051)
#define CLK_FRCCALL  _SFR_MEM8(0x0054)
#define CLK_FRCCALH  _SFR_MEM8(0x0055)
#define CLK_ULPRCCALL  _SFR_MEM8(0x0056)
#define CLK_OSCTST  _SFR_MEM8(0x0058)


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


/* CRC - CRC */
#define CRC_CTRL  _SFR_MEM8(0x00B0)
#define CRC_STATUS  _SFR_MEM8(0x00B1)
#define CRC_DATAIN  _SFR_MEM8(0x00B3)
#define CRC_CHECKSUM0  _SFR_MEM8(0x00B4)
#define CRC_CHECKSUM1  _SFR_MEM8(0x00B5)
#define CRC_CHECKSUM2  _SFR_MEM8(0x00B6)
#define CRC_CHECKSUM3  _SFR_MEM8(0x00B7)


/* WUT - Wake-up Timer */
#define WUT_CTRL  _SFR_MEM8(0x00C0)
#define WUT_INTCTRL  _SFR_MEM8(0x00C1)
#define WUT_STATUS  _SFR_MEM8(0x00C2)


/* CONFIG - CONFIG */
#define CONFIG_CTRL  _SFR_MEM8(0x00D0)
#define CONFIG_INT  _SFR_MEM8(0x00D1)


/* BOD33 - BOD 3.3V */
#define BOD33_CTRLA  _SFR_MEM8(0x00E0)
#define BOD33_PSEL  _SFR_MEM8(0x00E1)
#define BOD33_LEVEL  _SFR_MEM8(0x00E2)
#define BOD33_DEBUGCTRL  _SFR_MEM8(0x00E3)
#define BOD33_STATUS  _SFR_MEM8(0x00E4)


/* BOD12 - BOD 1.2V */
#define BOD12_CTRLA  _SFR_MEM8(0x00E8)
#define BOD12_PSEL  _SFR_MEM8(0x00E9)
#define BOD12_LEVEL  _SFR_MEM8(0x00EA)
#define BOD12_DEBUGCTRL  _SFR_MEM8(0x00EB)
#define BOD12_STATUS  _SFR_MEM8(0x00EC)


/* BOD12EXT - BODEXT 1.2V */
#define BOD12EXT_CTRLA  _SFR_MEM8(0x00F0)
#define BOD12EXT_CTRLB  _SFR_MEM8(0x00F1)
#define BOD12EXT_STATUS  _SFR_MEM8(0x00F2)
#define BOD12EXT_ISOCTRL  _SFR_MEM8(0x00F3)
#define BOD12EXT_INTCTRL  _SFR_MEM8(0x00F4)
#define BOD12EXT_INTF  _SFR_MEM8(0x00F5)


/* CODEMEM - CODEMEM */
#define CODEMEM_CRCENDADRL  _SFR_MEM8(0x01C0)
#define CODEMEM_CRCENDADRH  _SFR_MEM8(0x01C1)
#define CODEMEM_CMEMCAL  _SFR_MEM8(0x01C2)
#define CODEMEM_DMEMCAL  _SFR_MEM8(0x01C3)


/* PTC - Peripheral Touch Controller */
#define PTC_CTRLA  _SFR_MEM8(0x0280)
#define PTC_CTRLB  _SFR_MEM8(0x0284)
#define PTC_EVCTRL  _SFR_MEM8(0x0285)
#define PTC_INTEN  _SFR_MEM8(0x0288)
#define PTC_INTFLAG  _SFR_MEM8(0x028A)
#define PTC_CTSCTRLA  _SFR_MEM8(0x028C)
#define PTC_CTSCTRLC  _SFR_MEM8(0x028D)
#define PTC_YSELL  _SFR_MEM8(0x0290)
#define PTC_YSELH  _SFR_MEM8(0x0291)
#define PTC_XSELL  _SFR_MEM8(0x0292)
#define PTC_XSELH  _SFR_MEM8(0x0293)
#define PTC_YENL  _SFR_MEM8(0x0294)
#define PTC_YENH  _SFR_MEM8(0x0295)
#define PTC_XENL  _SFR_MEM8(0x0296)
#define PTC_XENH  _SFR_MEM8(0x0297)
#define PTC_CCCALL  _SFR_MEM8(0x0298)
#define PTC_CCCALH  _SFR_MEM8(0x0299)
#define PTC_CICAL  _SFR_MEM8(0x029A)
#define PTC_CTSRS  _SFR_MEM8(0x029B)
#define PTC_RESULTL  _SFR_MEM8(0x029C)
#define PTC_RESULTH  _SFR_MEM8(0x029D)
#define PTC_CTSCTRLB  _SFR_MEM8(0x02A0)
#define PTC_WINCTRL  _SFR_MEM8(0x02A1)
#define PTC_WCHTL  _SFR_MEM8(0x02A4)
#define PTC_WCHTH  _SFR_MEM8(0x02A5)
#define PTC_WCLTL  _SFR_MEM8(0x02A6)
#define PTC_WCLTH  _SFR_MEM8(0x02A7)
#define PTC_XYSEL  _SFR_MEM8(0x02A8)


/* BUSBRG - Bus Bridge AVR8 */
#define BUSBRG_INTCTRL  _SFR_MEM8(0x03C0)
#define BUSBRG_STATUS  _SFR_MEM8(0x03C1)
#define BUSBRG_RXDATA  _SFR_MEM8(0x03C2)
#define BUSBRG_TXDATA  _SFR_MEM8(0x03C3)
#define BUSBRG_MEMADDRL  _SFR_MEM8(0x03C4)
#define BUSBRG_MEMADDRH  _SFR_MEM8(0x03C5)


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



/*================== Bitfield Definitions ================== */

/* BOD12 - BOD 1.2V */
/* BOD12.CTRLA  bit masks and bit positions */
#define BOD12_ENABLE_bm  0x01  /* Enable bit mask. */
#define BOD12_ENABLE_bp  0  /* Enable bit position. */
#define BOD12_HYST_bm  0x02  /* Hysteresis bit mask. */
#define BOD12_HYST_bp  1  /* Hysteresis bit position. */
#define BOD12_ACTION_bm  0x04  /* Action bit mask. */
#define BOD12_ACTION_bp  2  /* Action bit position. */
#define BOD12_MODE_bm  0x10  /* Operation mode bit mask. */
#define BOD12_MODE_bp  4  /* Operation mode bit position. */
#define BOD12_CEN_bm  0x40  /* Clock Enable bit mask. */
#define BOD12_CEN_bp  6  /* Clock Enable bit position. */

/* BOD12.PSEL  bit masks and bit positions */
#define BOD12_PSEL_gm  0x0F  /* Prescaler Select group mask. */
#define BOD12_PSEL_gp  0  /* Prescaler Select group position. */
#define BOD12_PSEL0_bm  (1<<0)  /* Prescaler Select bit 0 mask. */
#define BOD12_PSEL0_bp  0  /* Prescaler Select bit 0 position. */
#define BOD12_PSEL1_bm  (1<<1)  /* Prescaler Select bit 1 mask. */
#define BOD12_PSEL1_bp  1  /* Prescaler Select bit 1 position. */
#define BOD12_PSEL2_bm  (1<<2)  /* Prescaler Select bit 2 mask. */
#define BOD12_PSEL2_bp  2  /* Prescaler Select bit 2 position. */
#define BOD12_PSEL3_bm  (1<<3)  /* Prescaler Select bit 3 mask. */
#define BOD12_PSEL3_bp  3  /* Prescaler Select bit 3 position. */

/* BOD12.LEVEL  bit masks and bit positions */
#define BOD12_LEVEL_gm  0x1F  /* Level group mask. */
#define BOD12_LEVEL_gp  0  /* Level group position. */
#define BOD12_LEVEL0_bm  (1<<0)  /* Level bit 0 mask. */
#define BOD12_LEVEL0_bp  0  /* Level bit 0 position. */
#define BOD12_LEVEL1_bm  (1<<1)  /* Level bit 1 mask. */
#define BOD12_LEVEL1_bp  1  /* Level bit 1 position. */
#define BOD12_LEVEL2_bm  (1<<2)  /* Level bit 2 mask. */
#define BOD12_LEVEL2_bp  2  /* Level bit 2 position. */
#define BOD12_LEVEL3_bm  (1<<3)  /* Level bit 3 mask. */
#define BOD12_LEVEL3_bp  3  /* Level bit 3 position. */
#define BOD12_LEVEL4_bm  (1<<4)  /* Level bit 4 mask. */
#define BOD12_LEVEL4_bp  4  /* Level bit 4 position. */

/* BOD12.DEBUGCTRL  bit masks and bit positions */
#define BOD12_BOD12TSTEN_bm  0x01  /* BOD12 Test Mode Enable bit mask. */
#define BOD12_BOD12TSTEN_bp  0  /* BOD12 Test Mode Enable bit position. */
#define BOD12_BOD12CHKWAKEDIS_bm  0x02  /* BOD12 Check Wakeup Disable bit mask. */
#define BOD12_BOD12CHKWAKEDIS_bp  1  /* BOD12 Check Wakeup Disable bit position. */
#define BOD12_BOD12SLPMSKDIS_bm  0x04  /* BOD12 Sleep Mask Disable bit mask. */
#define BOD12_BOD12SLPMSKDIS_bp  2  /* BOD12 Sleep Mask Disable bit position. */

/* BOD12.STATUS  bit masks and bit positions */
#define BOD12_BOD12DET_bm  0x01  /* BOD12 Detection signal bit mask. */
#define BOD12_BOD12DET_bp  0  /* BOD12 Detection signal bit position. */
#define BOD12_BOD12SYNRDY_bm  0x02  /* BOD12 Synch Ready bit mask. */
#define BOD12_BOD12SYNRDY_bp  1  /* BOD12 Synch Ready bit position. */
#define BOD12_BOD12RDY_bm  0x04  /* BOD12 Ready bit mask. */
#define BOD12_BOD12RDY_bp  2  /* BOD12 Ready bit position. */

/* BOD12EXT - BODEXT 1.2V */
/* BOD12EXT.CTRLA  bit masks and bit positions */
#define BOD12EXT_ENABLE_bm  0x01  /* Enable bit mask. */
#define BOD12EXT_ENABLE_bp  0  /* Enable bit position. */
#define BOD12EXT_ENMAIN_bm  0x02  /* Enable Main BOD12EXT bit mask. */
#define BOD12EXT_ENMAIN_bp  1  /* Enable Main BOD12EXT bit position. */
#define BOD12EXT_HYST_bm  0x04  /* Hysteresis bit mask. */
#define BOD12EXT_HYST_bp  2  /* Hysteresis bit position. */

/* BOD12EXT.CTRLB  bit masks and bit positions */
#define BOD12EXT_CALIB_gm  0x1F  /* Calibration group mask. */
#define BOD12EXT_CALIB_gp  0  /* Calibration group position. */
#define BOD12EXT_CALIB0_bm  (1<<0)  /* Calibration bit 0 mask. */
#define BOD12EXT_CALIB0_bp  0  /* Calibration bit 0 position. */
#define BOD12EXT_CALIB1_bm  (1<<1)  /* Calibration bit 1 mask. */
#define BOD12EXT_CALIB1_bp  1  /* Calibration bit 1 position. */
#define BOD12EXT_CALIB2_bm  (1<<2)  /* Calibration bit 2 mask. */
#define BOD12EXT_CALIB2_bp  2  /* Calibration bit 2 position. */
#define BOD12EXT_CALIB3_bm  (1<<3)  /* Calibration bit 3 mask. */
#define BOD12EXT_CALIB3_bp  3  /* Calibration bit 3 position. */
#define BOD12EXT_CALIB4_bm  (1<<4)  /* Calibration bit 4 mask. */
#define BOD12EXT_CALIB4_bp  4  /* Calibration bit 4 position. */
#define BOD12EXT_LEVEL_gm  0xE0  /* Level group mask. */
#define BOD12EXT_LEVEL_gp  5  /* Level group position. */
#define BOD12EXT_LEVEL0_bm  (1<<5)  /* Level bit 0 mask. */
#define BOD12EXT_LEVEL0_bp  5  /* Level bit 0 position. */
#define BOD12EXT_LEVEL1_bm  (1<<6)  /* Level bit 1 mask. */
#define BOD12EXT_LEVEL1_bp  6  /* Level bit 1 position. */
#define BOD12EXT_LEVEL2_bm  (1<<7)  /* Level bit 2 mask. */
#define BOD12EXT_LEVEL2_bp  7  /* Level bit 2 position. */

/* BOD12EXT.STATUS  bit masks and bit positions */
#define BOD12EXT_DET_bm  0x01  /* Detection signal bit mask. */
#define BOD12EXT_DET_bp  0  /* Detection signal bit position. */
#define BOD12EXT_READY_bm  0x02  /* Ready flag bit mask. */
#define BOD12EXT_READY_bp  1  /* Ready flag bit position. */
#define BOD12EXT_MAINREQBSE_bm  0x04  /* Main Requests BSE bit mask. */
#define BOD12EXT_MAINREQBSE_bp  2  /* Main Requests BSE bit position. */

/* BOD12EXT.ISOCTRL  bit masks and bit positions */
#define BOD12EXT_FORCEISOOPEN_bm  0x01  /* Force Isolation Open bit mask. */
#define BOD12EXT_FORCEISOOPEN_bp  0  /* Force Isolation Open bit position. */

/* BOD12EXT.INTCTRL  bit masks and bit positions */
#define BOD12EXT_REQINTLVL_gm  0x03  /* Request interrupt level group mask. */
#define BOD12EXT_REQINTLVL_gp  0  /* Request interrupt level group position. */
#define BOD12EXT_REQINTLVL0_bm  (1<<0)  /* Request interrupt level bit 0 mask. */
#define BOD12EXT_REQINTLVL0_bp  0  /* Request interrupt level bit 0 position. */
#define BOD12EXT_REQINTLVL1_bm  (1<<1)  /* Request interrupt level bit 1 mask. */
#define BOD12EXT_REQINTLVL1_bp  1  /* Request interrupt level bit 1 position. */
#define BOD12EXT_DETINTLVL_gm  0x0C  /* Detect interrupt level group mask. */
#define BOD12EXT_DETINTLVL_gp  2  /* Detect interrupt level group position. */
#define BOD12EXT_DETINTLVL0_bm  (1<<2)  /* Detect interrupt level bit 0 mask. */
#define BOD12EXT_DETINTLVL0_bp  2  /* Detect interrupt level bit 0 position. */
#define BOD12EXT_DETINTLVL1_bm  (1<<3)  /* Detect interrupt level bit 1 mask. */
#define BOD12EXT_DETINTLVL1_bp  3  /* Detect interrupt level bit 1 position. */

/* BOD12EXT.INTF  bit masks and bit positions */
#define BOD12EXT_REQIF_bm  0x01  /* Request Interrupt Flag bit mask. */
#define BOD12EXT_REQIF_bp  0  /* Request Interrupt Flag bit position. */
#define BOD12EXT_DETIF_bm  0x02  /* Detect Interrupt Flag bit mask. */
#define BOD12EXT_DETIF_bp  1  /* Detect Interrupt Flag bit position. */

/* BOD33 - BOD 3.3V */
/* BOD33.CTRLA  bit masks and bit positions */
#define BOD33_ENABLE_bm  0x01  /* Enable bit mask. */
#define BOD33_ENABLE_bp  0  /* Enable bit position. */
#define BOD33_HYST_bm  0x02  /* Hysteresis bit mask. */
#define BOD33_HYST_bp  1  /* Hysteresis bit position. */
#define BOD33_ACTION_bm  0x04  /* Action bit mask. */
#define BOD33_ACTION_bp  2  /* Action bit position. */
#define BOD33_MODE_bm  0x10  /* Operation mode bit mask. */
#define BOD33_MODE_bp  4  /* Operation mode bit position. */

/* BOD33.PSEL  bit masks and bit positions */
#define BOD33_PSEL_gm  0x0F  /* Prescaler Select group mask. */
#define BOD33_PSEL_gp  0  /* Prescaler Select group position. */
#define BOD33_PSEL0_bm  (1<<0)  /* Prescaler Select bit 0 mask. */
#define BOD33_PSEL0_bp  0  /* Prescaler Select bit 0 position. */
#define BOD33_PSEL1_bm  (1<<1)  /* Prescaler Select bit 1 mask. */
#define BOD33_PSEL1_bp  1  /* Prescaler Select bit 1 position. */
#define BOD33_PSEL2_bm  (1<<2)  /* Prescaler Select bit 2 mask. */
#define BOD33_PSEL2_bp  2  /* Prescaler Select bit 2 position. */
#define BOD33_PSEL3_bm  (1<<3)  /* Prescaler Select bit 3 mask. */
#define BOD33_PSEL3_bp  3  /* Prescaler Select bit 3 position. */

/* BOD33.LEVEL  bit masks and bit positions */
#define BOD33_LEVEL_gm  0x3F  /* Level group mask. */
#define BOD33_LEVEL_gp  0  /* Level group position. */
#define BOD33_LEVEL0_bm  (1<<0)  /* Level bit 0 mask. */
#define BOD33_LEVEL0_bp  0  /* Level bit 0 position. */
#define BOD33_LEVEL1_bm  (1<<1)  /* Level bit 1 mask. */
#define BOD33_LEVEL1_bp  1  /* Level bit 1 position. */
#define BOD33_LEVEL2_bm  (1<<2)  /* Level bit 2 mask. */
#define BOD33_LEVEL2_bp  2  /* Level bit 2 position. */
#define BOD33_LEVEL3_bm  (1<<3)  /* Level bit 3 mask. */
#define BOD33_LEVEL3_bp  3  /* Level bit 3 position. */
#define BOD33_LEVEL4_bm  (1<<4)  /* Level bit 4 mask. */
#define BOD33_LEVEL4_bp  4  /* Level bit 4 position. */
#define BOD33_LEVEL5_bm  (1<<5)  /* Level bit 5 mask. */
#define BOD33_LEVEL5_bp  5  /* Level bit 5 position. */

/* BOD33.DEBUGCTRL  bit masks and bit positions */
#define BOD33_BOD33SPARE_bm  0x01  /* BOD33 SPARE bit bit mask. */
#define BOD33_BOD33SPARE_bp  0  /* BOD33 SPARE bit bit position. */
#define BOD33_ALLOWCONTMODEPSAVE_bm  0x02  /* Allow CONT mode in powersave bit mask. */
#define BOD33_ALLOWCONTMODEPSAVE_bp  1  /* Allow CONT mode in powersave bit position. */

/* BOD33.STATUS  bit masks and bit positions */
#define BOD33_BOD33SUPPLYOK_bm  0x01  /* BOD33 Supply OK bit mask. */
#define BOD33_BOD33SUPPLYOK_bp  0  /* BOD33 Supply OK bit position. */
#define BOD33_BOD33SYNCBUSY_bm  0x02  /* BOD33 Sync Busy bit mask. */
#define BOD33_BOD33SYNCBUSY_bp  1  /* BOD33 Sync Busy bit position. */
#define BOD33_BOD33RDY_bm  0x04  /* BOD33 Ready bit mask. */
#define BOD33_BOD33RDY_bp  2  /* BOD33 Ready bit position. */
#define BOD33_BOD33RSTREQ_bm  0x08  /* BOD33 Reset Request bit mask. */
#define BOD33_BOD33RSTREQ_bp  3  /* BOD33 Reset Request bit position. */

/* BUSBRG - Bus Bridge AVR8 */
/* BUSBRG.INTCTRL  bit masks and bit positions */
#define BUSBRG_INTLVL0_gm  0x03  /* RX Interrupt Level group mask. */
#define BUSBRG_INTLVL0_gp  0  /* RX Interrupt Level group position. */
#define BUSBRG_INTLVL00_bm  (1<<0)  /* RX Interrupt Level bit 0 mask. */
#define BUSBRG_INTLVL00_bp  0  /* RX Interrupt Level bit 0 position. */
#define BUSBRG_INTLVL01_bm  (1<<1)  /* RX Interrupt Level bit 1 mask. */
#define BUSBRG_INTLVL01_bp  1  /* RX Interrupt Level bit 1 position. */
#define BUSBRG_INTLVL1_gm  0x0C  /* TX Interrupt Level group mask. */
#define BUSBRG_INTLVL1_gp  2  /* TX Interrupt Level group position. */
#define BUSBRG_INTLVL10_bm  (1<<2)  /* TX Interrupt Level bit 0 mask. */
#define BUSBRG_INTLVL10_bp  2  /* TX Interrupt Level bit 0 position. */
#define BUSBRG_INTLVL11_bm  (1<<3)  /* TX Interrupt Level bit 1 mask. */
#define BUSBRG_INTLVL11_bp  3  /* TX Interrupt Level bit 1 position. */

/* BUSBRG.STATUS  bit masks and bit positions */
#define BUSBRG_RXIF_bm  0x01  /* RX Data ready bit mask. */
#define BUSBRG_RXIF_bp  0  /* RX Data ready bit position. */
#define BUSBRG_BOOTREQ_bm  0x04  /* Boot Request bit mask. */
#define BUSBRG_BOOTREQ_bp  2  /* Boot Request bit position. */
#define BUSBRG_TXIF_bm  0x08  /* TX Data ready bit mask. */
#define BUSBRG_TXIF_bp  3  /* TX Data ready bit position. */
#define BUSBRG_AVR32ISOOPEN_bm  0x10  /* AVR32 isolation open bit mask. */
#define BUSBRG_AVR32ISOOPEN_bp  4  /* AVR32 isolation open bit position. */
#define BUSBRG_AVR32RST_bm  0x20  /* AVR32 reset bit mask. */
#define BUSBRG_AVR32RST_bp  5  /* AVR32 reset bit position. */
#define BUSBRG_AVR32SLP_bm  0x40  /* AVR32 sleep bit mask. */
#define BUSBRG_AVR32SLP_bp  6  /* AVR32 sleep bit position. */
#define BUSBRG_BSY_bm  0x80  /* Synchronization Busy bit mask. */
#define BUSBRG_BSY_bp  7  /* Synchronization Busy bit position. */

/* BUSBRG.RXDATA  bit masks and bit positions */
#define BUSBRG_RXDATA_gm  0xFF  /* RX Data group mask. */
#define BUSBRG_RXDATA_gp  0  /* RX Data group position. */
#define BUSBRG_RXDATA0_bm  (1<<0)  /* RX Data bit 0 mask. */
#define BUSBRG_RXDATA0_bp  0  /* RX Data bit 0 position. */
#define BUSBRG_RXDATA1_bm  (1<<1)  /* RX Data bit 1 mask. */
#define BUSBRG_RXDATA1_bp  1  /* RX Data bit 1 position. */
#define BUSBRG_RXDATA2_bm  (1<<2)  /* RX Data bit 2 mask. */
#define BUSBRG_RXDATA2_bp  2  /* RX Data bit 2 position. */
#define BUSBRG_RXDATA3_bm  (1<<3)  /* RX Data bit 3 mask. */
#define BUSBRG_RXDATA3_bp  3  /* RX Data bit 3 position. */
#define BUSBRG_RXDATA4_bm  (1<<4)  /* RX Data bit 4 mask. */
#define BUSBRG_RXDATA4_bp  4  /* RX Data bit 4 position. */
#define BUSBRG_RXDATA5_bm  (1<<5)  /* RX Data bit 5 mask. */
#define BUSBRG_RXDATA5_bp  5  /* RX Data bit 5 position. */
#define BUSBRG_RXDATA6_bm  (1<<6)  /* RX Data bit 6 mask. */
#define BUSBRG_RXDATA6_bp  6  /* RX Data bit 6 position. */
#define BUSBRG_RXDATA7_bm  (1<<7)  /* RX Data bit 7 mask. */
#define BUSBRG_RXDATA7_bp  7  /* RX Data bit 7 position. */

/* BUSBRG.TXDATA  bit masks and bit positions */
#define BUSBRG_TXDATA_gm  0xFF  /* TX Data group mask. */
#define BUSBRG_TXDATA_gp  0  /* TX Data group position. */
#define BUSBRG_TXDATA0_bm  (1<<0)  /* TX Data bit 0 mask. */
#define BUSBRG_TXDATA0_bp  0  /* TX Data bit 0 position. */
#define BUSBRG_TXDATA1_bm  (1<<1)  /* TX Data bit 1 mask. */
#define BUSBRG_TXDATA1_bp  1  /* TX Data bit 1 position. */
#define BUSBRG_TXDATA2_bm  (1<<2)  /* TX Data bit 2 mask. */
#define BUSBRG_TXDATA2_bp  2  /* TX Data bit 2 position. */
#define BUSBRG_TXDATA3_bm  (1<<3)  /* TX Data bit 3 mask. */
#define BUSBRG_TXDATA3_bp  3  /* TX Data bit 3 position. */
#define BUSBRG_TXDATA4_bm  (1<<4)  /* TX Data bit 4 mask. */
#define BUSBRG_TXDATA4_bp  4  /* TX Data bit 4 position. */
#define BUSBRG_TXDATA5_bm  (1<<5)  /* TX Data bit 5 mask. */
#define BUSBRG_TXDATA5_bp  5  /* TX Data bit 5 position. */
#define BUSBRG_TXDATA6_bm  (1<<6)  /* TX Data bit 6 mask. */
#define BUSBRG_TXDATA6_bp  6  /* TX Data bit 6 position. */
#define BUSBRG_TXDATA7_bm  (1<<7)  /* TX Data bit 7 mask. */
#define BUSBRG_TXDATA7_bp  7  /* TX Data bit 7 position. */

/* BUSBRG.MEMADDRL  bit masks and bit positions */
#define BUSBRG_MEMADDRL_gm  0xFF  /* Memory address group mask. */
#define BUSBRG_MEMADDRL_gp  0  /* Memory address group position. */
#define BUSBRG_MEMADDRL0_bm  (1<<0)  /* Memory address bit 0 mask. */
#define BUSBRG_MEMADDRL0_bp  0  /* Memory address bit 0 position. */
#define BUSBRG_MEMADDRL1_bm  (1<<1)  /* Memory address bit 1 mask. */
#define BUSBRG_MEMADDRL1_bp  1  /* Memory address bit 1 position. */
#define BUSBRG_MEMADDRL2_bm  (1<<2)  /* Memory address bit 2 mask. */
#define BUSBRG_MEMADDRL2_bp  2  /* Memory address bit 2 position. */
#define BUSBRG_MEMADDRL3_bm  (1<<3)  /* Memory address bit 3 mask. */
#define BUSBRG_MEMADDRL3_bp  3  /* Memory address bit 3 position. */
#define BUSBRG_MEMADDRL4_bm  (1<<4)  /* Memory address bit 4 mask. */
#define BUSBRG_MEMADDRL4_bp  4  /* Memory address bit 4 position. */
#define BUSBRG_MEMADDRL5_bm  (1<<5)  /* Memory address bit 5 mask. */
#define BUSBRG_MEMADDRL5_bp  5  /* Memory address bit 5 position. */
#define BUSBRG_MEMADDRL6_bm  (1<<6)  /* Memory address bit 6 mask. */
#define BUSBRG_MEMADDRL6_bp  6  /* Memory address bit 6 position. */
#define BUSBRG_MEMADDRL7_bm  (1<<7)  /* Memory address bit 7 mask. */
#define BUSBRG_MEMADDRL7_bp  7  /* Memory address bit 7 position. */

/* BUSBRG.MEMADDRH  bit masks and bit positions */
#define BUSBRG_MEMADDRH_gm  0xFF  /* Memory address group mask. */
#define BUSBRG_MEMADDRH_gp  0  /* Memory address group position. */
#define BUSBRG_MEMADDRH0_bm  (1<<0)  /* Memory address bit 0 mask. */
#define BUSBRG_MEMADDRH0_bp  0  /* Memory address bit 0 position. */
#define BUSBRG_MEMADDRH1_bm  (1<<1)  /* Memory address bit 1 mask. */
#define BUSBRG_MEMADDRH1_bp  1  /* Memory address bit 1 position. */
#define BUSBRG_MEMADDRH2_bm  (1<<2)  /* Memory address bit 2 mask. */
#define BUSBRG_MEMADDRH2_bp  2  /* Memory address bit 2 position. */
#define BUSBRG_MEMADDRH3_bm  (1<<3)  /* Memory address bit 3 mask. */
#define BUSBRG_MEMADDRH3_bp  3  /* Memory address bit 3 position. */
#define BUSBRG_MEMADDRH4_bm  (1<<4)  /* Memory address bit 4 mask. */
#define BUSBRG_MEMADDRH4_bp  4  /* Memory address bit 4 position. */
#define BUSBRG_MEMADDRH5_bm  (1<<5)  /* Memory address bit 5 mask. */
#define BUSBRG_MEMADDRH5_bp  5  /* Memory address bit 5 position. */
#define BUSBRG_MEMADDRH6_bm  (1<<6)  /* Memory address bit 6 mask. */
#define BUSBRG_MEMADDRH6_bp  6  /* Memory address bit 6 position. */
#define BUSBRG_MEMADDRH7_bm  (1<<7)  /* Memory address bit 7 mask. */
#define BUSBRG_MEMADDRH7_bp  7  /* Memory address bit 7 position. */

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

/* CLK.OSCTST  bit masks and bit positions */
#define CLK_ULPRCEOV_bm  0x01  /* ULP RC Oscillator Enable Override Value bit mask. */
#define CLK_ULPRCEOV_bp  0  /* ULP RC Oscillator Enable Override Value bit position. */
#define CLK_ULPRCEOE_bm  0x02  /* ULP RC Oscillator Enable Override Enable bit mask. */
#define CLK_ULPRCEOE_bp  1  /* ULP RC Oscillator Enable Override Enable bit position. */
#define CLK_FRCEOV_bm  0x04  /* Fast RC Oscillator Enable Override Value bit mask. */
#define CLK_FRCEOV_bp  2  /* Fast RC Oscillator Enable Override Value bit position. */
#define CLK_FRCEOE_bm  0x08  /* Fast RC Oscillator Enable Override Enable bit mask. */
#define CLK_FRCEOE_bp  3  /* Fast RC Oscillator Enable Override Enable bit position. */

/* CODEMEM - CODEMEM */
/* CODEMEM.CRCENDADRL  bit masks and bit positions */
#define CODEMEM_CRCENDADRL_gm  0xFF  /* CRC End Address Low group mask. */
#define CODEMEM_CRCENDADRL_gp  0  /* CRC End Address Low group position. */
#define CODEMEM_CRCENDADRL0_bm  (1<<0)  /* CRC End Address Low bit 0 mask. */
#define CODEMEM_CRCENDADRL0_bp  0  /* CRC End Address Low bit 0 position. */
#define CODEMEM_CRCENDADRL1_bm  (1<<1)  /* CRC End Address Low bit 1 mask. */
#define CODEMEM_CRCENDADRL1_bp  1  /* CRC End Address Low bit 1 position. */
#define CODEMEM_CRCENDADRL2_bm  (1<<2)  /* CRC End Address Low bit 2 mask. */
#define CODEMEM_CRCENDADRL2_bp  2  /* CRC End Address Low bit 2 position. */
#define CODEMEM_CRCENDADRL3_bm  (1<<3)  /* CRC End Address Low bit 3 mask. */
#define CODEMEM_CRCENDADRL3_bp  3  /* CRC End Address Low bit 3 position. */
#define CODEMEM_CRCENDADRL4_bm  (1<<4)  /* CRC End Address Low bit 4 mask. */
#define CODEMEM_CRCENDADRL4_bp  4  /* CRC End Address Low bit 4 position. */
#define CODEMEM_CRCENDADRL5_bm  (1<<5)  /* CRC End Address Low bit 5 mask. */
#define CODEMEM_CRCENDADRL5_bp  5  /* CRC End Address Low bit 5 position. */
#define CODEMEM_CRCENDADRL6_bm  (1<<6)  /* CRC End Address Low bit 6 mask. */
#define CODEMEM_CRCENDADRL6_bp  6  /* CRC End Address Low bit 6 position. */
#define CODEMEM_CRCENDADRL7_bm  (1<<7)  /* CRC End Address Low bit 7 mask. */
#define CODEMEM_CRCENDADRL7_bp  7  /* CRC End Address Low bit 7 position. */

/* CODEMEM.CRCENDADRH  bit masks and bit positions */
#define CODEMEM_CRCENDADRH_gm  0x1F  /* CRC End Address High group mask. */
#define CODEMEM_CRCENDADRH_gp  0  /* CRC End Address High group position. */
#define CODEMEM_CRCENDADRH0_bm  (1<<0)  /* CRC End Address High bit 0 mask. */
#define CODEMEM_CRCENDADRH0_bp  0  /* CRC End Address High bit 0 position. */
#define CODEMEM_CRCENDADRH1_bm  (1<<1)  /* CRC End Address High bit 1 mask. */
#define CODEMEM_CRCENDADRH1_bp  1  /* CRC End Address High bit 1 position. */
#define CODEMEM_CRCENDADRH2_bm  (1<<2)  /* CRC End Address High bit 2 mask. */
#define CODEMEM_CRCENDADRH2_bp  2  /* CRC End Address High bit 2 position. */
#define CODEMEM_CRCENDADRH3_bm  (1<<3)  /* CRC End Address High bit 3 mask. */
#define CODEMEM_CRCENDADRH3_bp  3  /* CRC End Address High bit 3 position. */
#define CODEMEM_CRCENDADRH4_bm  (1<<4)  /* CRC End Address High bit 4 mask. */
#define CODEMEM_CRCENDADRH4_bp  4  /* CRC End Address High bit 4 position. */

/* CODEMEM.CMEMCAL  bit masks and bit positions */
#define CODEMEM_CMEMCAL_gm  0x0F  /* Code Memory Calibration Value group mask. */
#define CODEMEM_CMEMCAL_gp  0  /* Code Memory Calibration Value group position. */
#define CODEMEM_CMEMCAL0_bm  (1<<0)  /* Code Memory Calibration Value bit 0 mask. */
#define CODEMEM_CMEMCAL0_bp  0  /* Code Memory Calibration Value bit 0 position. */
#define CODEMEM_CMEMCAL1_bm  (1<<1)  /* Code Memory Calibration Value bit 1 mask. */
#define CODEMEM_CMEMCAL1_bp  1  /* Code Memory Calibration Value bit 1 position. */
#define CODEMEM_CMEMCAL2_bm  (1<<2)  /* Code Memory Calibration Value bit 2 mask. */
#define CODEMEM_CMEMCAL2_bp  2  /* Code Memory Calibration Value bit 2 position. */
#define CODEMEM_CMEMCAL3_bm  (1<<3)  /* Code Memory Calibration Value bit 3 mask. */
#define CODEMEM_CMEMCAL3_bp  3  /* Code Memory Calibration Value bit 3 position. */

/* CODEMEM.DMEMCAL  bit masks and bit positions */
#define CODEMEM_DMEMCAL_gm  0x0F  /* Data Memory Calibration Value group mask. */
#define CODEMEM_DMEMCAL_gp  0  /* Data Memory Calibration Value group position. */
#define CODEMEM_DMEMCAL0_bm  (1<<0)  /* Data Memory Calibration Value bit 0 mask. */
#define CODEMEM_DMEMCAL0_bp  0  /* Data Memory Calibration Value bit 0 position. */
#define CODEMEM_DMEMCAL1_bm  (1<<1)  /* Data Memory Calibration Value bit 1 mask. */
#define CODEMEM_DMEMCAL1_bp  1  /* Data Memory Calibration Value bit 1 position. */
#define CODEMEM_DMEMCAL2_bm  (1<<2)  /* Data Memory Calibration Value bit 2 mask. */
#define CODEMEM_DMEMCAL2_bp  2  /* Data Memory Calibration Value bit 2 position. */
#define CODEMEM_DMEMCAL3_bm  (1<<3)  /* Data Memory Calibration Value bit 3 mask. */
#define CODEMEM_DMEMCAL3_bp  3  /* Data Memory Calibration Value bit 3 position. */

/* CONFIG - CONFIG */
/* CONFIG.CTRL  bit masks and bit positions */
#define CONFIG_DISDEBUG_bm  0x01  /* Disable Debug Wire bit mask. */
#define CONFIG_DISDEBUG_bp  0  /* Disable Debug Wire bit position. */
#define CONFIG_SELDBGPAD_bm  0x02  /* Select Debug Pads bit mask. */
#define CONFIG_SELDBGPAD_bp  1  /* Select Debug Pads bit position. */
#define CONFIG_SELEXTCLK_bm  0x04  /* Select External Clock bit mask. */
#define CONFIG_SELEXTCLK_bp  2  /* Select External Clock bit position. */
#define CONFIG_ISOOVER_bm  0x08  /* Isolation Override bit mask. */
#define CONFIG_ISOOVER_bp  3  /* Isolation Override bit position. */
#define CONFIG_UNLOCKMEM_bm  0x10  /* Unlock memory access bit mask. */
#define CONFIG_UNLOCKMEM_bp  4  /* Unlock memory access bit position. */
#define CONFIG_PTCTSTEN_bm  0x20  /* PTC Test Enable bit mask. */
#define CONFIG_PTCTSTEN_bp  5  /* PTC Test Enable bit position. */

/* CONFIG.INT  bit masks and bit positions */
#define CONFIG_INTLVL_gm  0x03  /* Interrupt Level group mask. */
#define CONFIG_INTLVL_gp  0  /* Interrupt Level group position. */
#define CONFIG_INTLVL0_bm  (1<<0)  /* Interrupt Level bit 0 mask. */
#define CONFIG_INTLVL0_bp  0  /* Interrupt Level bit 0 position. */
#define CONFIG_INTLVL1_bm  (1<<1)  /* Interrupt Level bit 1 mask. */
#define CONFIG_INTLVL1_bp  1  /* Interrupt Level bit 1 position. */
#define CONFIG_OCDBREAKIF_bm  0x04  /* AVR32 Debug interrupt bit mask. */
#define CONFIG_OCDBREAKIF_bp  2  /* AVR32 Debug interrupt bit position. */

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

/* CRC - CRC */
/* CRC.CTRL  bit masks and bit positions */
#define CRC_SOURCE_gm  0x07  /* CRC Input Source group mask. */
#define CRC_SOURCE_gp  0  /* CRC Input Source group position. */
#define CRC_SOURCE0_bm  (1<<0)  /* CRC Input Source bit 0 mask. */
#define CRC_SOURCE0_bp  0  /* CRC Input Source bit 0 position. */
#define CRC_SOURCE1_bm  (1<<1)  /* CRC Input Source bit 1 mask. */
#define CRC_SOURCE1_bp  1  /* CRC Input Source bit 1 position. */
#define CRC_SOURCE2_bm  (1<<2)  /* CRC Input Source bit 2 mask. */
#define CRC_SOURCE2_bp  2  /* CRC Input Source bit 2 position. */
#define CRC_CRC32_bm  0x20  /* CRC-32 Enable bit mask. */
#define CRC_CRC32_bp  5  /* CRC-32 Enable bit position. */
#define CRC_RESET_gm  0xC0  /* CRC Reset group mask. */
#define CRC_RESET_gp  6  /* CRC Reset group position. */
#define CRC_RESET0_bm  (1<<6)  /* CRC Reset bit 0 mask. */
#define CRC_RESET0_bp  6  /* CRC Reset bit 0 position. */
#define CRC_RESET1_bm  (1<<7)  /* CRC Reset bit 1 mask. */
#define CRC_RESET1_bp  7  /* CRC Reset bit 1 position. */

/* CRC.STATUS  bit masks and bit positions */
#define CRC_BUSY_bm  0x01  /* CRC ongoing bit mask. */
#define CRC_BUSY_bp  0  /* CRC ongoing bit position. */
#define CRC_ZERO_bm  0x02  /* CRC Data Zero bit mask. */
#define CRC_ZERO_bp  1  /* CRC Data Zero bit position. */

/* CRC.DATAIN  bit masks and bit positions */
#define CRC_DATAIN_gm  0xFF  /* Data Input group mask. */
#define CRC_DATAIN_gp  0  /* Data Input group position. */
#define CRC_DATAIN0_bm  (1<<0)  /* Data Input bit 0 mask. */
#define CRC_DATAIN0_bp  0  /* Data Input bit 0 position. */
#define CRC_DATAIN1_bm  (1<<1)  /* Data Input bit 1 mask. */
#define CRC_DATAIN1_bp  1  /* Data Input bit 1 position. */
#define CRC_DATAIN2_bm  (1<<2)  /* Data Input bit 2 mask. */
#define CRC_DATAIN2_bp  2  /* Data Input bit 2 position. */
#define CRC_DATAIN3_bm  (1<<3)  /* Data Input bit 3 mask. */
#define CRC_DATAIN3_bp  3  /* Data Input bit 3 position. */
#define CRC_DATAIN4_bm  (1<<4)  /* Data Input bit 4 mask. */
#define CRC_DATAIN4_bp  4  /* Data Input bit 4 position. */
#define CRC_DATAIN5_bm  (1<<5)  /* Data Input bit 5 mask. */
#define CRC_DATAIN5_bp  5  /* Data Input bit 5 position. */
#define CRC_DATAIN6_bm  (1<<6)  /* Data Input bit 6 mask. */
#define CRC_DATAIN6_bp  6  /* Data Input bit 6 position. */
#define CRC_DATAIN7_bm  (1<<7)  /* Data Input bit 7 mask. */
#define CRC_DATAIN7_bp  7  /* Data Input bit 7 position. */

/* CRC.CHECKSUM0  bit masks and bit positions */
#define CRC_CHECKSUM_gm  0xFF  /* Checksum group mask. */
#define CRC_CHECKSUM_gp  0  /* Checksum group position. */
#define CRC_CHECKSUM0_bm  (1<<0)  /* Checksum bit 0 mask. */
#define CRC_CHECKSUM0_bp  0  /* Checksum bit 0 position. */
#define CRC_CHECKSUM1_bm  (1<<1)  /* Checksum bit 1 mask. */
#define CRC_CHECKSUM1_bp  1  /* Checksum bit 1 position. */
#define CRC_CHECKSUM2_bm  (1<<2)  /* Checksum bit 2 mask. */
#define CRC_CHECKSUM2_bp  2  /* Checksum bit 2 position. */
#define CRC_CHECKSUM3_bm  (1<<3)  /* Checksum bit 3 mask. */
#define CRC_CHECKSUM3_bp  3  /* Checksum bit 3 position. */
#define CRC_CHECKSUM4_bm  (1<<4)  /* Checksum bit 4 mask. */
#define CRC_CHECKSUM4_bp  4  /* Checksum bit 4 position. */
#define CRC_CHECKSUM5_bm  (1<<5)  /* Checksum bit 5 mask. */
#define CRC_CHECKSUM5_bp  5  /* Checksum bit 5 position. */
#define CRC_CHECKSUM6_bm  (1<<6)  /* Checksum bit 6 mask. */
#define CRC_CHECKSUM6_bp  6  /* Checksum bit 6 position. */
#define CRC_CHECKSUM7_bm  (1<<7)  /* Checksum bit 7 mask. */
#define CRC_CHECKSUM7_bp  7  /* Checksum bit 7 position. */

/* CRC.CHECKSUM1  bit masks and bit positions */
/* CRC_CHECKSUM  is already defined. */

/* CRC.CHECKSUM2  bit masks and bit positions */
/* CRC_CHECKSUM  is already defined. */

/* CRC.CHECKSUM3  bit masks and bit positions */
/* CRC_CHECKSUM  is already defined. */

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

/* PTC - Peripheral Touch Controller */
/* PTC.CTRLA  bit masks and bit positions */
#define PTC_SWRST_bm  0x01  /* Software Reset bit mask. */
#define PTC_SWRST_bp  0  /* Software Reset bit position. */
#define PTC_ENABLE_bm  0x02  /* Enable bit mask. */
#define PTC_ENABLE_bp  1  /* Enable bit position. */
#define PTC_RUNSTDBY_bm  0x04  /* Run Standby bit mask. */
#define PTC_RUNSTDBY_bp  2  /* Run Standby bit position. */

/* PTC.CTRLB  bit masks and bit positions */
#define PTC_PRSC_gm  0x03  /* PRSC group mask. */
#define PTC_PRSC_gp  0  /* PRSC group position. */
#define PTC_PRSC0_bm  (1<<0)  /* PRSC bit 0 mask. */
#define PTC_PRSC0_bp  0  /* PRSC bit 0 position. */
#define PTC_PRSC1_bm  (1<<1)  /* PRSC bit 1 mask. */
#define PTC_PRSC1_bp  1  /* PRSC bit 1 position. */
#define PTC_FREERUN_bm  0x04  /* Freerun bit mask. */
#define PTC_FREERUN_bp  2  /* Freerun bit position. */
#define PTC_ADRS_bm  0x08  /* ADRS bit mask. */
#define PTC_ADRS_bp  3  /* ADRS bit position. */
#define PTC_ENBUFSDS_bm  0x10  /* Enable Buffered Sample Delay Selection bit mask. */
#define PTC_ENBUFSDS_bp  4  /* Enable Buffered Sample Delay Selection bit position. */

/* PTC.EVCTRL  bit masks and bit positions */
#define PTC_STCONVEI_bm  0x01  /* Start Conversion Event Input bit mask. */
#define PTC_STCONVEI_bp  0  /* Start Conversion Event Input bit position. */
#define PTC_EOCEO_bm  0x02  /* End of Conversion Event Output bit mask. */
#define PTC_EOCEO_bp  1  /* End of Conversion Event Output bit position. */
#define PTC_WCOMPEO_bm  0x04  /* Window Comparator Event Output bit mask. */
#define PTC_WCOMPEO_bp  2  /* Window Comparator Event Output bit position. */

/* PTC.INTEN  bit masks and bit positions */
#define PTC_EOCINTLVL_gm  0x03  /* End of Conversion Interrupt Level group mask. */
#define PTC_EOCINTLVL_gp  0  /* End of Conversion Interrupt Level group position. */
#define PTC_EOCINTLVL0_bm  (1<<0)  /* End of Conversion Interrupt Level bit 0 mask. */
#define PTC_EOCINTLVL0_bp  0  /* End of Conversion Interrupt Level bit 0 position. */
#define PTC_EOCINTLVL1_bm  (1<<1)  /* End of Conversion Interrupt Level bit 1 mask. */
#define PTC_EOCINTLVL1_bp  1  /* End of Conversion Interrupt Level bit 1 position. */
#define PTC_WCMPINTLVL_gm  0x0C  /* Window Comparator Interrupt Level group mask. */
#define PTC_WCMPINTLVL_gp  2  /* Window Comparator Interrupt Level group position. */
#define PTC_WCMPINTLVL0_bm  (1<<2)  /* Window Comparator Interrupt Level bit 0 mask. */
#define PTC_WCMPINTLVL0_bp  2  /* Window Comparator Interrupt Level bit 0 position. */
#define PTC_WCMPINTLVL1_bm  (1<<3)  /* Window Comparator Interrupt Level bit 1 mask. */
#define PTC_WCMPINTLVL1_bp  3  /* Window Comparator Interrupt Level bit 1 position. */

/* PTC.INTFLAG  bit masks and bit positions */
#define PTC_EOC_bm  0x01  /* End of Conversion Interrupt Flag bit mask. */
#define PTC_EOC_bp  0  /* End of Conversion Interrupt Flag bit position. */
#define PTC_WCOMP_bm  0x02  /* Window Comparator Interrupt Flag bit mask. */
#define PTC_WCOMP_bp  1  /* Window Comparator Interrupt Flag bit position. */

/* PTC.CTSCTRLA  bit masks and bit positions */
#define PTC_SDS_gm  0x0F  /* Sampling Delay Selection group mask. */
#define PTC_SDS_gp  0  /* Sampling Delay Selection group position. */
#define PTC_SDS0_bm  (1<<0)  /* Sampling Delay Selection bit 0 mask. */
#define PTC_SDS0_bp  0  /* Sampling Delay Selection bit 0 position. */
#define PTC_SDS1_bm  (1<<1)  /* Sampling Delay Selection bit 1 mask. */
#define PTC_SDS1_bp  1  /* Sampling Delay Selection bit 1 position. */
#define PTC_SDS2_bm  (1<<2)  /* Sampling Delay Selection bit 2 mask. */
#define PTC_SDS2_bp  2  /* Sampling Delay Selection bit 2 position. */
#define PTC_SDS3_bm  (1<<3)  /* Sampling Delay Selection bit 3 mask. */
#define PTC_SDS3_bp  3  /* Sampling Delay Selection bit 3 position. */
#define PTC_ASDV_bm  0x10  /* Automatic Sampling Delay Variation bit mask. */
#define PTC_ASDV_bp  4  /* Automatic Sampling Delay Variation bit position. */
#define PTC_CCDS_gm  0x60  /* Channel Change Delay Selection group mask. */
#define PTC_CCDS_gp  5  /* Channel Change Delay Selection group position. */
#define PTC_CCDS0_bm  (1<<5)  /* Channel Change Delay Selection bit 0 mask. */
#define PTC_CCDS0_bp  5  /* Channel Change Delay Selection bit 0 position. */
#define PTC_CCDS1_bm  (1<<6)  /* Channel Change Delay Selection bit 1 mask. */
#define PTC_CCDS1_bp  6  /* Channel Change Delay Selection bit 1 position. */

/* PTC.CTSCTRLC  bit masks and bit positions */
#define PTC_ADAS_gm  0x07  /* ADC Accumulation Number Select group mask. */
#define PTC_ADAS_gp  0  /* ADC Accumulation Number Select group position. */
#define PTC_ADAS0_bm  (1<<0)  /* ADC Accumulation Number Select bit 0 mask. */
#define PTC_ADAS0_bp  0  /* ADC Accumulation Number Select bit 0 position. */
#define PTC_ADAS1_bm  (1<<1)  /* ADC Accumulation Number Select bit 1 mask. */
#define PTC_ADAS1_bp  1  /* ADC Accumulation Number Select bit 1 position. */
#define PTC_ADAS2_bm  (1<<2)  /* ADC Accumulation Number Select bit 2 mask. */
#define PTC_ADAS2_bp  2  /* ADC Accumulation Number Select bit 2 position. */
#define PTC_STCONV_bm  0x80  /* Start Conversion Operation bit mask. */
#define PTC_STCONV_bp  7  /* Start Conversion Operation bit position. */

/* PTC.YSELL  bit masks and bit positions */
#define PTC_YSEL_gm  0xFF  /* Y Line Selection group mask. */
#define PTC_YSEL_gp  0  /* Y Line Selection group position. */
#define PTC_YSEL0_bm  (1<<0)  /* Y Line Selection bit 0 mask. */
#define PTC_YSEL0_bp  0  /* Y Line Selection bit 0 position. */
#define PTC_YSEL1_bm  (1<<1)  /* Y Line Selection bit 1 mask. */
#define PTC_YSEL1_bp  1  /* Y Line Selection bit 1 position. */
#define PTC_YSEL2_bm  (1<<2)  /* Y Line Selection bit 2 mask. */
#define PTC_YSEL2_bp  2  /* Y Line Selection bit 2 position. */
#define PTC_YSEL3_bm  (1<<3)  /* Y Line Selection bit 3 mask. */
#define PTC_YSEL3_bp  3  /* Y Line Selection bit 3 position. */
#define PTC_YSEL4_bm  (1<<4)  /* Y Line Selection bit 4 mask. */
#define PTC_YSEL4_bp  4  /* Y Line Selection bit 4 position. */
#define PTC_YSEL5_bm  (1<<5)  /* Y Line Selection bit 5 mask. */
#define PTC_YSEL5_bp  5  /* Y Line Selection bit 5 position. */
#define PTC_YSEL6_bm  (1<<6)  /* Y Line Selection bit 6 mask. */
#define PTC_YSEL6_bp  6  /* Y Line Selection bit 6 position. */
#define PTC_YSEL7_bm  (1<<7)  /* Y Line Selection bit 7 mask. */
#define PTC_YSEL7_bp  7  /* Y Line Selection bit 7 position. */

/* PTC.YSELH  bit masks and bit positions */
/* PTC_YSEL  is already defined. */

/* PTC.XSELL  bit masks and bit positions */
#define PTC_XSEL_gm  0xFF  /* X Line Selection group mask. */
#define PTC_XSEL_gp  0  /* X Line Selection group position. */
#define PTC_XSEL0_bm  (1<<0)  /* X Line Selection bit 0 mask. */
#define PTC_XSEL0_bp  0  /* X Line Selection bit 0 position. */
#define PTC_XSEL1_bm  (1<<1)  /* X Line Selection bit 1 mask. */
#define PTC_XSEL1_bp  1  /* X Line Selection bit 1 position. */
#define PTC_XSEL2_bm  (1<<2)  /* X Line Selection bit 2 mask. */
#define PTC_XSEL2_bp  2  /* X Line Selection bit 2 position. */
#define PTC_XSEL3_bm  (1<<3)  /* X Line Selection bit 3 mask. */
#define PTC_XSEL3_bp  3  /* X Line Selection bit 3 position. */
#define PTC_XSEL4_bm  (1<<4)  /* X Line Selection bit 4 mask. */
#define PTC_XSEL4_bp  4  /* X Line Selection bit 4 position. */
#define PTC_XSEL5_bm  (1<<5)  /* X Line Selection bit 5 mask. */
#define PTC_XSEL5_bp  5  /* X Line Selection bit 5 position. */
#define PTC_XSEL6_bm  (1<<6)  /* X Line Selection bit 6 mask. */
#define PTC_XSEL6_bp  6  /* X Line Selection bit 6 position. */
#define PTC_XSEL7_bm  (1<<7)  /* X Line Selection bit 7 mask. */
#define PTC_XSEL7_bp  7  /* X Line Selection bit 7 position. */

/* PTC.XSELH  bit masks and bit positions */
/* PTC_XSEL  is already defined. */

/* PTC.YENL  bit masks and bit positions */
#define PTC_YEN_gm  0xFF  /* Y Line Enable group mask. */
#define PTC_YEN_gp  0  /* Y Line Enable group position. */
#define PTC_YEN0_bm  (1<<0)  /* Y Line Enable bit 0 mask. */
#define PTC_YEN0_bp  0  /* Y Line Enable bit 0 position. */
#define PTC_YEN1_bm  (1<<1)  /* Y Line Enable bit 1 mask. */
#define PTC_YEN1_bp  1  /* Y Line Enable bit 1 position. */
#define PTC_YEN2_bm  (1<<2)  /* Y Line Enable bit 2 mask. */
#define PTC_YEN2_bp  2  /* Y Line Enable bit 2 position. */
#define PTC_YEN3_bm  (1<<3)  /* Y Line Enable bit 3 mask. */
#define PTC_YEN3_bp  3  /* Y Line Enable bit 3 position. */
#define PTC_YEN4_bm  (1<<4)  /* Y Line Enable bit 4 mask. */
#define PTC_YEN4_bp  4  /* Y Line Enable bit 4 position. */
#define PTC_YEN5_bm  (1<<5)  /* Y Line Enable bit 5 mask. */
#define PTC_YEN5_bp  5  /* Y Line Enable bit 5 position. */
#define PTC_YEN6_bm  (1<<6)  /* Y Line Enable bit 6 mask. */
#define PTC_YEN6_bp  6  /* Y Line Enable bit 6 position. */
#define PTC_YEN7_bm  (1<<7)  /* Y Line Enable bit 7 mask. */
#define PTC_YEN7_bp  7  /* Y Line Enable bit 7 position. */

/* PTC.YENH  bit masks and bit positions */
/* PTC_YEN  is already defined. */

/* PTC.XENL  bit masks and bit positions */
#define PTC_XEN_gm  0xFF  /* X Line Enable group mask. */
#define PTC_XEN_gp  0  /* X Line Enable group position. */
#define PTC_XEN0_bm  (1<<0)  /* X Line Enable bit 0 mask. */
#define PTC_XEN0_bp  0  /* X Line Enable bit 0 position. */
#define PTC_XEN1_bm  (1<<1)  /* X Line Enable bit 1 mask. */
#define PTC_XEN1_bp  1  /* X Line Enable bit 1 position. */
#define PTC_XEN2_bm  (1<<2)  /* X Line Enable bit 2 mask. */
#define PTC_XEN2_bp  2  /* X Line Enable bit 2 position. */
#define PTC_XEN3_bm  (1<<3)  /* X Line Enable bit 3 mask. */
#define PTC_XEN3_bp  3  /* X Line Enable bit 3 position. */
#define PTC_XEN4_bm  (1<<4)  /* X Line Enable bit 4 mask. */
#define PTC_XEN4_bp  4  /* X Line Enable bit 4 position. */
#define PTC_XEN5_bm  (1<<5)  /* X Line Enable bit 5 mask. */
#define PTC_XEN5_bp  5  /* X Line Enable bit 5 position. */
#define PTC_XEN6_bm  (1<<6)  /* X Line Enable bit 6 mask. */
#define PTC_XEN6_bp  6  /* X Line Enable bit 6 position. */
#define PTC_XEN7_bm  (1<<7)  /* X Line Enable bit 7 mask. */
#define PTC_XEN7_bp  7  /* X Line Enable bit 7 position. */

/* PTC.XENH  bit masks and bit positions */
/* PTC_XEN  is already defined. */

/* PTC.CCCALL  bit masks and bit positions */
#define PTC_CCA_gm  0x0F  /* Compensation Capacitor Accurate Value group mask. */
#define PTC_CCA_gp  0  /* Compensation Capacitor Accurate Value group position. */
#define PTC_CCA0_bm  (1<<0)  /* Compensation Capacitor Accurate Value bit 0 mask. */
#define PTC_CCA0_bp  0  /* Compensation Capacitor Accurate Value bit 0 position. */
#define PTC_CCA1_bm  (1<<1)  /* Compensation Capacitor Accurate Value bit 1 mask. */
#define PTC_CCA1_bp  1  /* Compensation Capacitor Accurate Value bit 1 position. */
#define PTC_CCA2_bm  (1<<2)  /* Compensation Capacitor Accurate Value bit 2 mask. */
#define PTC_CCA2_bp  2  /* Compensation Capacitor Accurate Value bit 2 position. */
#define PTC_CCA3_bm  (1<<3)  /* Compensation Capacitor Accurate Value bit 3 mask. */
#define PTC_CCA3_bp  3  /* Compensation Capacitor Accurate Value bit 3 position. */
#define PTC_CCF_gm  0xF0  /* Compensation Capacitor Fine Value group mask. */
#define PTC_CCF_gp  4  /* Compensation Capacitor Fine Value group position. */
#define PTC_CCF0_bm  (1<<4)  /* Compensation Capacitor Fine Value bit 0 mask. */
#define PTC_CCF0_bp  4  /* Compensation Capacitor Fine Value bit 0 position. */
#define PTC_CCF1_bm  (1<<5)  /* Compensation Capacitor Fine Value bit 1 mask. */
#define PTC_CCF1_bp  5  /* Compensation Capacitor Fine Value bit 1 position. */
#define PTC_CCF2_bm  (1<<6)  /* Compensation Capacitor Fine Value bit 2 mask. */
#define PTC_CCF2_bp  6  /* Compensation Capacitor Fine Value bit 2 position. */
#define PTC_CCF3_bm  (1<<7)  /* Compensation Capacitor Fine Value bit 3 mask. */
#define PTC_CCF3_bp  7  /* Compensation Capacitor Fine Value bit 3 position. */

/* PTC.CCCALH  bit masks and bit positions */
#define PTC_CCC_gm  0x0F  /* Compensation Capacitor Coarse Value group mask. */
#define PTC_CCC_gp  0  /* Compensation Capacitor Coarse Value group position. */
#define PTC_CCC0_bm  (1<<0)  /* Compensation Capacitor Coarse Value bit 0 mask. */
#define PTC_CCC0_bp  0  /* Compensation Capacitor Coarse Value bit 0 position. */
#define PTC_CCC1_bm  (1<<1)  /* Compensation Capacitor Coarse Value bit 1 mask. */
#define PTC_CCC1_bp  1  /* Compensation Capacitor Coarse Value bit 1 position. */
#define PTC_CCC2_bm  (1<<2)  /* Compensation Capacitor Coarse Value bit 2 mask. */
#define PTC_CCC2_bp  2  /* Compensation Capacitor Coarse Value bit 2 position. */
#define PTC_CCC3_bm  (1<<3)  /* Compensation Capacitor Coarse Value bit 3 mask. */
#define PTC_CCC3_bp  3  /* Compensation Capacitor Coarse Value bit 3 position. */
#define PTC_CCR_gm  0x30  /* Compensation Capacitor Rough Value group mask. */
#define PTC_CCR_gp  4  /* Compensation Capacitor Rough Value group position. */
#define PTC_CCR0_bm  (1<<4)  /* Compensation Capacitor Rough Value bit 0 mask. */
#define PTC_CCR0_bp  4  /* Compensation Capacitor Rough Value bit 0 position. */
#define PTC_CCR1_bm  (1<<5)  /* Compensation Capacitor Rough Value bit 1 mask. */
#define PTC_CCR1_bp  5  /* Compensation Capacitor Rough Value bit 1 position. */

/* PTC.CICAL  bit masks and bit positions */
#define PTC_CIF_gm  0x0F  /* CIF group mask. */
#define PTC_CIF_gp  0  /* CIF group position. */
#define PTC_CIF0_bm  (1<<0)  /* CIF bit 0 mask. */
#define PTC_CIF0_bp  0  /* CIF bit 0 position. */
#define PTC_CIF1_bm  (1<<1)  /* CIF bit 1 mask. */
#define PTC_CIF1_bp  1  /* CIF bit 1 position. */
#define PTC_CIF2_bm  (1<<2)  /* CIF bit 2 mask. */
#define PTC_CIF2_bp  2  /* CIF bit 2 position. */
#define PTC_CIF3_bm  (1<<3)  /* CIF bit 3 mask. */
#define PTC_CIF3_bp  3  /* CIF bit 3 position. */
#define PTC_CIC_gm  0x30  /* Integration Capacitor Coarse Value group mask. */
#define PTC_CIC_gp  4  /* Integration Capacitor Coarse Value group position. */
#define PTC_CIC0_bm  (1<<4)  /* Integration Capacitor Coarse Value bit 0 mask. */
#define PTC_CIC0_bp  4  /* Integration Capacitor Coarse Value bit 0 position. */
#define PTC_CIC1_bm  (1<<5)  /* Integration Capacitor Coarse Value bit 1 mask. */
#define PTC_CIC1_bp  5  /* Integration Capacitor Coarse Value bit 1 position. */

/* PTC.CTSRS  bit masks and bit positions */
#define PTC_RSEL_gm  0x03  /* RSEL group mask. */
#define PTC_RSEL_gp  0  /* RSEL group position. */
#define PTC_RSEL0_bm  (1<<0)  /* RSEL bit 0 mask. */
#define PTC_RSEL0_bp  0  /* RSEL bit 0 position. */
#define PTC_RSEL1_bm  (1<<1)  /* RSEL bit 1 mask. */
#define PTC_RSEL1_bp  1  /* RSEL bit 1 position. */
#define PTC_RSEL100K_bm  0x04  /* RSEL100K bit mask. */
#define PTC_RSEL100K_bp  2  /* RSEL100K bit position. */

/* PTC.RESULTL  bit masks and bit positions */
#define PTC_RESULT_gm  0xFF  /* ADC/Accumulator Result Data Register group mask. */
#define PTC_RESULT_gp  0  /* ADC/Accumulator Result Data Register group position. */
#define PTC_RESULT0_bm  (1<<0)  /* ADC/Accumulator Result Data Register bit 0 mask. */
#define PTC_RESULT0_bp  0  /* ADC/Accumulator Result Data Register bit 0 position. */
#define PTC_RESULT1_bm  (1<<1)  /* ADC/Accumulator Result Data Register bit 1 mask. */
#define PTC_RESULT1_bp  1  /* ADC/Accumulator Result Data Register bit 1 position. */
#define PTC_RESULT2_bm  (1<<2)  /* ADC/Accumulator Result Data Register bit 2 mask. */
#define PTC_RESULT2_bp  2  /* ADC/Accumulator Result Data Register bit 2 position. */
#define PTC_RESULT3_bm  (1<<3)  /* ADC/Accumulator Result Data Register bit 3 mask. */
#define PTC_RESULT3_bp  3  /* ADC/Accumulator Result Data Register bit 3 position. */
#define PTC_RESULT4_bm  (1<<4)  /* ADC/Accumulator Result Data Register bit 4 mask. */
#define PTC_RESULT4_bp  4  /* ADC/Accumulator Result Data Register bit 4 position. */
#define PTC_RESULT5_bm  (1<<5)  /* ADC/Accumulator Result Data Register bit 5 mask. */
#define PTC_RESULT5_bp  5  /* ADC/Accumulator Result Data Register bit 5 position. */
#define PTC_RESULT6_bm  (1<<6)  /* ADC/Accumulator Result Data Register bit 6 mask. */
#define PTC_RESULT6_bp  6  /* ADC/Accumulator Result Data Register bit 6 position. */
#define PTC_RESULT7_bm  (1<<7)  /* ADC/Accumulator Result Data Register bit 7 mask. */
#define PTC_RESULT7_bp  7  /* ADC/Accumulator Result Data Register bit 7 position. */

/* PTC.RESULTH  bit masks and bit positions */
/* PTC_RESULT  is already defined. */

/* PTC.CTSCTRLB  bit masks and bit positions */
#define PTC_CTSLP_bm  0x04  /* Capacitive Touch System Low Power bit mask. */
#define PTC_CTSLP_bp  2  /* Capacitive Touch System Low Power bit position. */
#define PTC_SCFIX_bm  0x08  /* Self Cap Fix bit mask. */
#define PTC_SCFIX_bp  3  /* Self Cap Fix bit position. */
#define PTC_CTSM_gm  0xF0  /* Capacitive Touch Sensing Mode group mask. */
#define PTC_CTSM_gp  4  /* Capacitive Touch Sensing Mode group position. */
#define PTC_CTSM0_bm  (1<<4)  /* Capacitive Touch Sensing Mode bit 0 mask. */
#define PTC_CTSM0_bp  4  /* Capacitive Touch Sensing Mode bit 0 position. */
#define PTC_CTSM1_bm  (1<<5)  /* Capacitive Touch Sensing Mode bit 1 mask. */
#define PTC_CTSM1_bp  5  /* Capacitive Touch Sensing Mode bit 1 position. */
#define PTC_CTSM2_bm  (1<<6)  /* Capacitive Touch Sensing Mode bit 2 mask. */
#define PTC_CTSM2_bp  6  /* Capacitive Touch Sensing Mode bit 2 position. */
#define PTC_CTSM3_bm  (1<<7)  /* Capacitive Touch Sensing Mode bit 3 mask. */
#define PTC_CTSM3_bp  7  /* Capacitive Touch Sensing Mode bit 3 position. */

/* PTC.WINCTRL  bit masks and bit positions */
#define PTC_WINCM_gm  0x07  /* Window Comparator Mode group mask. */
#define PTC_WINCM_gp  0  /* Window Comparator Mode group position. */
#define PTC_WINCM0_bm  (1<<0)  /* Window Comparator Mode bit 0 mask. */
#define PTC_WINCM0_bp  0  /* Window Comparator Mode bit 0 position. */
#define PTC_WINCM1_bm  (1<<1)  /* Window Comparator Mode bit 1 mask. */
#define PTC_WINCM1_bp  1  /* Window Comparator Mode bit 1 position. */
#define PTC_WINCM2_bm  (1<<2)  /* Window Comparator Mode bit 2 mask. */
#define PTC_WINCM2_bp  2  /* Window Comparator Mode bit 2 position. */

/* PTC.WCHTL  bit masks and bit positions */
#define PTC_WCHT_gm  0xFF  /* Window Comparator High Threshold Register group mask. */
#define PTC_WCHT_gp  0  /* Window Comparator High Threshold Register group position. */
#define PTC_WCHT0_bm  (1<<0)  /* Window Comparator High Threshold Register bit 0 mask. */
#define PTC_WCHT0_bp  0  /* Window Comparator High Threshold Register bit 0 position. */
#define PTC_WCHT1_bm  (1<<1)  /* Window Comparator High Threshold Register bit 1 mask. */
#define PTC_WCHT1_bp  1  /* Window Comparator High Threshold Register bit 1 position. */
#define PTC_WCHT2_bm  (1<<2)  /* Window Comparator High Threshold Register bit 2 mask. */
#define PTC_WCHT2_bp  2  /* Window Comparator High Threshold Register bit 2 position. */
#define PTC_WCHT3_bm  (1<<3)  /* Window Comparator High Threshold Register bit 3 mask. */
#define PTC_WCHT3_bp  3  /* Window Comparator High Threshold Register bit 3 position. */
#define PTC_WCHT4_bm  (1<<4)  /* Window Comparator High Threshold Register bit 4 mask. */
#define PTC_WCHT4_bp  4  /* Window Comparator High Threshold Register bit 4 position. */
#define PTC_WCHT5_bm  (1<<5)  /* Window Comparator High Threshold Register bit 5 mask. */
#define PTC_WCHT5_bp  5  /* Window Comparator High Threshold Register bit 5 position. */
#define PTC_WCHT6_bm  (1<<6)  /* Window Comparator High Threshold Register bit 6 mask. */
#define PTC_WCHT6_bp  6  /* Window Comparator High Threshold Register bit 6 position. */
#define PTC_WCHT7_bm  (1<<7)  /* Window Comparator High Threshold Register bit 7 mask. */
#define PTC_WCHT7_bp  7  /* Window Comparator High Threshold Register bit 7 position. */

/* PTC.WCHTH  bit masks and bit positions */
/* PTC_WCHT  is already defined. */

/* PTC.WCLTL  bit masks and bit positions */
#define PTC_WCLT_gm  0xFF  /* WCLT group mask. */
#define PTC_WCLT_gp  0  /* WCLT group position. */
#define PTC_WCLT0_bm  (1<<0)  /* WCLT bit 0 mask. */
#define PTC_WCLT0_bp  0  /* WCLT bit 0 position. */
#define PTC_WCLT1_bm  (1<<1)  /* WCLT bit 1 mask. */
#define PTC_WCLT1_bp  1  /* WCLT bit 1 position. */
#define PTC_WCLT2_bm  (1<<2)  /* WCLT bit 2 mask. */
#define PTC_WCLT2_bp  2  /* WCLT bit 2 position. */
#define PTC_WCLT3_bm  (1<<3)  /* WCLT bit 3 mask. */
#define PTC_WCLT3_bp  3  /* WCLT bit 3 position. */
#define PTC_WCLT4_bm  (1<<4)  /* WCLT bit 4 mask. */
#define PTC_WCLT4_bp  4  /* WCLT bit 4 position. */
#define PTC_WCLT5_bm  (1<<5)  /* WCLT bit 5 mask. */
#define PTC_WCLT5_bp  5  /* WCLT bit 5 position. */
#define PTC_WCLT6_bm  (1<<6)  /* WCLT bit 6 mask. */
#define PTC_WCLT6_bp  6  /* WCLT bit 6 position. */
#define PTC_WCLT7_bm  (1<<7)  /* WCLT bit 7 mask. */
#define PTC_WCLT7_bp  7  /* WCLT bit 7 position. */

/* PTC.WCLTH  bit masks and bit positions */
/* PTC_WCLT  is already defined. */

/* PTC.XYSEL  bit masks and bit positions */
#define PTC_BUFSDS_gm  0xF0  /* Buffered Sample Delay Selection group mask. */
#define PTC_BUFSDS_gp  4  /* Buffered Sample Delay Selection group position. */
#define PTC_BUFSDS0_bm  (1<<4)  /* Buffered Sample Delay Selection bit 0 mask. */
#define PTC_BUFSDS0_bp  4  /* Buffered Sample Delay Selection bit 0 position. */
#define PTC_BUFSDS1_bm  (1<<5)  /* Buffered Sample Delay Selection bit 1 mask. */
#define PTC_BUFSDS1_bp  5  /* Buffered Sample Delay Selection bit 1 position. */
#define PTC_BUFSDS2_bm  (1<<6)  /* Buffered Sample Delay Selection bit 2 mask. */
#define PTC_BUFSDS2_bp  6  /* Buffered Sample Delay Selection bit 2 position. */
#define PTC_BUFSDS3_bm  (1<<7)  /* Buffered Sample Delay Selection bit 3 mask. */
#define PTC_BUFSDS3_bp  7  /* Buffered Sample Delay Selection bit 3 position. */

/* RST - Reset */
/* RST.STATUS  bit masks and bit positions */
#define RST_PORF_bm  0x01  /* Power-on Reset Flag bit mask. */
#define RST_PORF_bp  0  /* Power-on Reset Flag bit position. */
#define RST_BOD33RF_bm  0x02  /* BOD33 Reset Flag bit mask. */
#define RST_BOD33RF_bp  1  /* BOD33 Reset Flag bit position. */
#define RST_BOD12RF_bm  0x04  /* BOD12 Reset Flag bit mask. */
#define RST_BOD12RF_bp  2  /* BOD12 Reset Flag bit position. */
#define RST_WDRF_bm  0x08  /* Watchdog Reset Flag bit mask. */
#define RST_WDRF_bp  3  /* Watchdog Reset Flag bit position. */
#define RST_PDIRF_bm  0x10  /* Programming and Debug Interface Interface Reset Flag bit mask. */
#define RST_PDIRF_bp  4  /* Programming and Debug Interface Interface Reset Flag bit position. */
#define RST_FWRF_bm  0x20  /* Firmware Reset Flag bit mask. */
#define RST_FWRF_bp  5  /* Firmware Reset Flag bit position. */
#define RST_BUSRF_bm  0x40  /* Busbridge Reset Flag bit mask. */
#define RST_BUSRF_bp  6  /* Busbridge Reset Flag bit position. */

/* RST.CTRL  bit masks and bit positions */
#define RST_FWRST_bm  0x01  /* Firmware Reset bit mask. */
#define RST_FWRST_bp  0  /* Firmware Reset bit position. */

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

/* VREF - Voltage Reference */
/* VREF.CTRL  bit masks and bit positions */
#define VREF_RES0_bm  0x01  /* Reserved 0 bit mask. */
#define VREF_RES0_bp  0  /* Reserved 0 bit position. */
#define VREF_RES1_bm  0x02  /* Reserved 1 bit mask. */
#define VREF_RES1_bp  1  /* Reserved 1 bit position. */

/* VREF.CALIBA  bit masks and bit positions */
#define VREF_CALIB_gm  0xFF  /* Bandgap calibration group mask. */
#define VREF_CALIB_gp  0  /* Bandgap calibration group position. */
#define VREF_CALIB0_bm  (1<<0)  /* Bandgap calibration bit 0 mask. */
#define VREF_CALIB0_bp  0  /* Bandgap calibration bit 0 position. */
#define VREF_CALIB1_bm  (1<<1)  /* Bandgap calibration bit 1 mask. */
#define VREF_CALIB1_bp  1  /* Bandgap calibration bit 1 position. */
#define VREF_CALIB2_bm  (1<<2)  /* Bandgap calibration bit 2 mask. */
#define VREF_CALIB2_bp  2  /* Bandgap calibration bit 2 position. */
#define VREF_CALIB3_bm  (1<<3)  /* Bandgap calibration bit 3 mask. */
#define VREF_CALIB3_bp  3  /* Bandgap calibration bit 3 position. */
#define VREF_CALIB4_bm  (1<<4)  /* Bandgap calibration bit 4 mask. */
#define VREF_CALIB4_bp  4  /* Bandgap calibration bit 4 position. */
#define VREF_CALIB5_bm  (1<<5)  /* Bandgap calibration bit 5 mask. */
#define VREF_CALIB5_bp  5  /* Bandgap calibration bit 5 position. */
#define VREF_CALIB6_bm  (1<<6)  /* Bandgap calibration bit 6 mask. */
#define VREF_CALIB6_bp  6  /* Bandgap calibration bit 6 position. */
#define VREF_CALIB7_bm  (1<<7)  /* Bandgap calibration bit 7 mask. */
#define VREF_CALIB7_bp  7  /* Bandgap calibration bit 7 position. */

/* VREF.CALIBB  bit masks and bit positions */
/* VREF_CALIB  is already defined. */

/* VREF.TESTA  bit masks and bit positions */
#define VREF_TESTEN_bm  0x01  /* Test Enable bit mask. */
#define VREF_TESTEN_bp  0  /* Test Enable bit position. */
#define VREF_BGEN_bm  0x02  /* Bandgap Enable bit mask. */
#define VREF_BGEN_bp  1  /* Bandgap Enable bit position. */
#define VREF_BIASEN_bm  0x04  /* BIAS Enable bit mask. */
#define VREF_BIASEN_bp  2  /* BIAS Enable bit position. */
#define VREF_BUFRRSEL_bm  0x08  /* BUFRR Select bit mask. */
#define VREF_BUFRRSEL_bp  3  /* BUFRR Select bit position. */
#define VREF_BIASTSTEN_bm  0x10  /* Bias test enable bit mask. */
#define VREF_BIASTSTEN_bp  4  /* Bias test enable bit position. */

/* VREF.TESTB  bit masks and bit positions */
#define VREF_BGBUFRREN_bm  0x01  /* BGBUFRR Enable bit mask. */
#define VREF_BGBUFRREN_bp  0  /* BGBUFRR Enable bit position. */
#define VREF_DIV2BUFEN_bm  0x02  /* Divide by 2 buffer enable bit mask. */
#define VREF_DIV2BUFEN_bp  1  /* Divide by 2 buffer enable bit position. */

/* VREF.STATUS  bit masks and bit positions */
#define VREF_BGRDY_bm  0x01  /* Bandgap ready bit mask. */
#define VREF_BGRDY_bp  0  /* Bandgap ready bit position. */
#define VREF_BIASRDY_bm  0x02  /* Bias ready bit mask. */
#define VREF_BIASRDY_bp  1  /* Bias ready bit position. */
#define VREF_BGBUFRRRDY_bm  0x04  /* Bandgap buffer ready bit mask. */
#define VREF_BGBUFRRRDY_bp  2  /* Bandgap buffer ready bit position. */
#define VREF_DIV2BUFRDY_bm  0x08  /* Divide by 2 buffer ready bit mask. */
#define VREF_DIV2BUFRDY_bp  3  /* Divide by 2 buffer ready bit position. */

/* VREF.TESTUVREFA  bit masks and bit positions */
#define VREF_DIVLEVEN_bm  0x01  /* Division Level Enable bit mask. */
#define VREF_DIVLEVEN_bp  0  /* Division Level Enable bit position. */
#define VREF_DIVLEV_gm  0x0E  /* Division Level group mask. */
#define VREF_DIVLEV_gp  1  /* Division Level group position. */
#define VREF_DIVLEV0_bm  (1<<1)  /* Division Level bit 0 mask. */
#define VREF_DIVLEV0_bp  1  /* Division Level bit 0 position. */
#define VREF_DIVLEV1_bm  (1<<2)  /* Division Level bit 1 mask. */
#define VREF_DIVLEV1_bp  2  /* Division Level bit 1 position. */
#define VREF_DIVLEV2_bm  (1<<3)  /* Division Level bit 2 mask. */
#define VREF_DIVLEV2_bp  3  /* Division Level bit 2 position. */
#define VREF_GAINDIVLEVEN_bm  0x10  /* Gain Division Level Enable bit mask. */
#define VREF_GAINDIVLEVEN_bp  4  /* Gain Division Level Enable bit position. */
#define VREF_GAINDIVLEV_gm  0xE0  /* Gain Division Level group mask. */
#define VREF_GAINDIVLEV_gp  5  /* Gain Division Level group position. */
#define VREF_GAINDIVLEV0_bm  (1<<5)  /* Gain Division Level bit 0 mask. */
#define VREF_GAINDIVLEV0_bp  5  /* Gain Division Level bit 0 position. */
#define VREF_GAINDIVLEV1_bm  (1<<6)  /* Gain Division Level bit 1 mask. */
#define VREF_GAINDIVLEV1_bp  6  /* Gain Division Level bit 1 position. */
#define VREF_GAINDIVLEV2_bm  (1<<7)  /* Gain Division Level bit 2 mask. */
#define VREF_GAINDIVLEV2_bp  7  /* Gain Division Level bit 2 position. */

/* VREF.TESTPOR  bit masks and bit positions */
#define VREF_UBODEN_bm  0x01  /* Micro BOD Enable bit mask. */
#define VREF_UBODEN_bp  0  /* Micro BOD Enable bit position. */
/* VREF_TESTEN  is already defined. */
#define VREF_TESTCURREN_bm  0x08  /* Test Current Enable bit mask. */
#define VREF_TESTCURREN_bp  3  /* Test Current Enable bit position. */

/* VREG - Voltage Regulators */
/* VREG.CTRL  bit masks and bit positions */
#define VREG_VREGEN_bm  0x01  /* Voltage Regulator Enable bit mask. */
#define VREG_VREGEN_bp  0  /* Voltage Regulator Enable bit position. */
#define VREG_VREGLVL_gm  0x0E  /* Voltage Regulator Level group mask. */
#define VREG_VREGLVL_gp  1  /* Voltage Regulator Level group position. */
#define VREG_VREGLVL0_bm  (1<<1)  /* Voltage Regulator Level bit 0 mask. */
#define VREG_VREGLVL0_bp  1  /* Voltage Regulator Level bit 0 position. */
#define VREG_VREGLVL1_bm  (1<<2)  /* Voltage Regulator Level bit 1 mask. */
#define VREG_VREGLVL1_bp  2  /* Voltage Regulator Level bit 1 position. */
#define VREG_VREGLVL2_bm  (1<<3)  /* Voltage Regulator Level bit 2 mask. */
#define VREG_VREGLVL2_bp  3  /* Voltage Regulator Level bit 2 position. */
#define VREG_INCBIAS_bm  0x10  /* Incremental Bias bit mask. */
#define VREG_INCBIAS_bp  4  /* Incremental Bias bit position. */
#define VREG_FORCELDO_bm  0x20  /* Force LDO bit mask. */
#define VREG_FORCELDO_bp  5  /* Force LDO bit position. */
#define VREG_WAKEMAIN_bm  0x40  /* Wake Main bit mask. */
#define VREG_WAKEMAIN_bp  6  /* Wake Main bit position. */
#define VREG_FORCEMAIN_bm  0x80  /* Force Main bit mask. */
#define VREG_FORCEMAIN_bp  7  /* Force Main bit position. */

/* VREG.TESTA  bit masks and bit positions */
#define VREG_UVTSTEN_bm  0x01  /* Ulp Voltage Regulator Test Enable bit mask. */
#define VREG_UVTSTEN_bp  0  /* Ulp Voltage Regulator Test Enable bit position. */
#define VREG_UVEN_bm  0x02  /* Ulp Voltage Regulator Enable bit mask. */
#define VREG_UVEN_bp  1  /* Ulp Voltage Regulator Enable bit position. */
#define VREG_UVBODIEN_bm  0x04  /* Ulp Voltage Regulator BODI Enable bit mask. */
#define VREG_UVBODIEN_bp  2  /* Ulp Voltage Regulator BODI Enable bit position. */
#define VREG_UVBODIIEN_bm  0x08  /* Ulp Voltage Regulator BODII Enable bit mask. */
#define VREG_UVBODIIEN_bp  3  /* Ulp Voltage Regulator BODII Enable bit position. */
#define VREG_UVOSCEN_bm  0x10  /* Ulp Voltage Regulator Oscillator Enable bit mask. */
#define VREG_UVOSCEN_bp  4  /* Ulp Voltage Regulator Oscillator Enable bit position. */
#define VREG_UVLDOEN_bm  0x20  /* Ulp Voltage Regulator LDO Enable bit mask. */
#define VREG_UVLDOEN_bp  5  /* Ulp Voltage Regulator LDO Enable bit position. */
#define VREG_UVREFSEL_bm  0x40  /* Ulp Voltage Regulator Reference Select bit mask. */
#define VREG_UVREFSEL_bp  6  /* Ulp Voltage Regulator Reference Select bit position. */

/* VREG.TESTB  bit masks and bit positions */
#define VREG_UVFORCEGAIN_gm  0x03  /* Ulp Voltage Regulator Force Gain group mask. */
#define VREG_UVFORCEGAIN_gp  0  /* Ulp Voltage Regulator Force Gain group position. */
#define VREG_UVFORCEGAIN0_bm  (1<<0)  /* Ulp Voltage Regulator Force Gain bit 0 mask. */
#define VREG_UVFORCEGAIN0_bp  0  /* Ulp Voltage Regulator Force Gain bit 0 position. */
#define VREG_UVFORCEGAIN1_bm  (1<<1)  /* Ulp Voltage Regulator Force Gain bit 1 mask. */
#define VREG_UVFORCEGAIN1_bp  1  /* Ulp Voltage Regulator Force Gain bit 1 position. */
#define VREG_UVRAMREFSEL_gm  0x1C  /* Ulp Voltage Regulator RAM Reference Select group mask. */
#define VREG_UVRAMREFSEL_gp  2  /* Ulp Voltage Regulator RAM Reference Select group position. */
#define VREG_UVRAMREFSEL0_bm  (1<<2)  /* Ulp Voltage Regulator RAM Reference Select bit 0 mask. */
#define VREG_UVRAMREFSEL0_bp  2  /* Ulp Voltage Regulator RAM Reference Select bit 0 position. */
#define VREG_UVRAMREFSEL1_bm  (1<<3)  /* Ulp Voltage Regulator RAM Reference Select bit 1 mask. */
#define VREG_UVRAMREFSEL1_bp  3  /* Ulp Voltage Regulator RAM Reference Select bit 1 position. */
#define VREG_UVRAMREFSEL2_bm  (1<<4)  /* Ulp Voltage Regulator RAM Reference Select bit 2 mask. */
#define VREG_UVRAMREFSEL2_bp  4  /* Ulp Voltage Regulator RAM Reference Select bit 2 position. */
#define VREG_UVREQBIAS_bm  0x20  /* Ulp Voltage Regulator Request Bias bit mask. */
#define VREG_UVREQBIAS_bp  5  /* Ulp Voltage Regulator Request Bias bit position. */
#define VREG_UVREQHLPI_bm  0x40  /* Ulp Voltage Regulator Request Help I bit mask. */
#define VREG_UVREQHLPI_bp  6  /* Ulp Voltage Regulator Request Help I bit position. */
#define VREG_UVREQHLPII_bm  0x80  /* Ulp Voltage Regulator Request Help II bit mask. */
#define VREG_UVREQHLPII_bp  7  /* Ulp Voltage Regulator Request Help II bit position. */

/* VREG.TESTC  bit masks and bit positions */
#define VREG_UVREGTSTUSEBODIIRST_bm  0x01  /* Ulp Voltage Regulator Test Use BODII As Reset bit mask. */
#define VREG_UVREGTSTUSEBODIIRST_bp  0  /* Ulp Voltage Regulator Test Use BODII As Reset bit position. */
#define VREG_UVREGTSTFORCEBODIIEN_bm  0x02  /* Ulp Voltage Regulator Test Force BODII Enable bit mask. */
#define VREG_UVREGTSTFORCEBODIIEN_bp  1  /* Ulp Voltage Regulator Test Force BODII Enable bit position. */
#define VREG_VREGTSTPMKEEPDIS_bm  0x04  /* Voltage Regulator Test PM Keep Disable bit mask. */
#define VREG_VREGTSTPMKEEPDIS_bp  2  /* Voltage Regulator Test PM Keep Disable bit position. */
#define VREG_VREGTSTRDYOSCENDIS_bm  0x10  /* Voltage Regulator Test Ready Oscillator Enable Disable bit mask. */
#define VREG_VREGTSTRDYOSCENDIS_bp  4  /* Voltage Regulator Test Ready Oscillator Enable Disable bit position. */

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

/* CONFIG interrupt vectors */
#define CONFIG_AVR32_debug_vect_num  1
#define CONFIG_AVR32_debug_vect      _VECTOR(1)  /* AVR32 Stopped */

/* Busbridge interrupt vectors */
#define Busbridge_Data_received_vect_num  2
#define Busbridge_Data_received_vect      _VECTOR(2)  /* Bus Bridge AVR8 */
#define Busbridge_Data_read_vect_num  3
#define Busbridge_Data_read_vect      _VECTOR(3)  /* Bus Bridge AVR8 */

/* PTC interrupt vectors */
#define PTC_EOC_vect_num  4
#define PTC_EOC_vect      _VECTOR(4)  /* End of conversion */
#define PTC_WCOMP_vect_num  5
#define PTC_WCOMP_vect      _VECTOR(5)  /* WCOMP */

/* WUT interrupt vectors */
#define WUT_WUT_vect_num  6
#define WUT_WUT_vect      _VECTOR(6)  /* Wake-up Timeout */

/* BOD12EXT interrupt vectors */
#define BOD12EXT_Request_vect_num  7
#define BOD12EXT_Request_vect      _VECTOR(7)  /* BOD12EXT request */
#define BOD12EXT_Detect_vect_num  8
#define BOD12EXT_Detect_vect      _VECTOR(8)  /* BOD12EXT detect */

/* PORTA interrupt vectors */
#define PORTA_INT0_vect_num  9
#define PORTA_INT0_vect      _VECTOR(9)  /* External Interrupt 0 */
#define PORTA_INT1_vect_num  10
#define PORTA_INT1_vect      _VECTOR(10)  /* External Interrupt 1 */

/* PORTB interrupt vectors */
#define PORTB_INT0_vect_num  11
#define PORTB_INT0_vect      _VECTOR(11)  /* External Interrupt 0 */
#define PORTB_INT1_vect_num  12
#define PORTB_INT1_vect      _VECTOR(12)  /* External Interrupt 1 */

#define _VECTOR_SIZE 2 /* Size of individual vector. */
#define _VECTORS_SIZE (13 * _VECTOR_SIZE)


/* ========== Constants ========== */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_START     (0x0000)
#  define PROGMEM_SIZE      (6144)
#else
#  define PROGMEM_START     (0x0000U)
#  define PROGMEM_SIZE      (6144U)
#endif
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define APP_SECTION_START     (0x0000)
#  define APP_SECTION_SIZE      (6144)
#  define APP_SECTION_PAGE_SIZE (1)
#else
#  define APP_SECTION_START     (0x0000U)
#  define APP_SECTION_SIZE      (6144U)
#  define APP_SECTION_PAGE_SIZE (1U)
#endif
#define APP_SECTION_END       (APP_SECTION_START + APP_SECTION_SIZE - 1)

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
#  define INTERNAL_SRAM_SIZE      (512)
#  define INTERNAL_SRAM_PAGE_SIZE (0)
#else
#  define INTERNAL_SRAM_START     (0x2000U)
#  define INTERNAL_SRAM_SIZE      (512U)
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

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SPM_PAGESIZE 1
#else
#  define SPM_PAGESIZE 1U
#endif
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END


/* ========== Signature ========== */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x43
#define SIGNATURE_2 0x93


#endif /* #ifdef _AVR_MAXBSE_H_INCLUDED */

