/*
 * Copyright (C) 2024, Microchip Technology Inc. and its subsidiaries ("Microchip")
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
#  define _AVR_IOXXX_H_ "ioavrfpgav2.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_AVRFPGAV2_H_INCLUDED
#define _AVR_AVRFPGAV2_H_INCLUDED

/* Ungrouped common registers */
#define CCP  _SFR_MEM8(0x0034)  /* Configuration Change Protection */
#define RAMPZ  _SFR_MEM8(0x003B)  /* Extended Z-pointer Register */
#define SP  _SFR_MEM16(0x003D)  /* Stack Pointer */
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
AC - Analog Comparator
--------------------------------------------------------------------------
*/

/* Analog Comparator */
typedef struct AC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t MUXCTRL;  /* Mux Control A */
    register8_t reserved_1[2];
    register8_t DACREF;  /* DAC Voltage Reference */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t STATUS;  /* Status */
} AC_t;

/* Hysteresis Mode select */
typedef enum AC_HYSMODE_enum
{
    AC_HYSMODE_NONE_gc = (0x00<<1),  /* No hysteresis */
    AC_HYSMODE_SMALL_gc = (0x01<<1),  /* Small hysteresis */
    AC_HYSMODE_MEDIUM_gc = (0x02<<1),  /* Medium hysteresis */
    AC_HYSMODE_LARGE_gc = (0x03<<1)  /* Large hysteresis */
} AC_HYSMODE_t;

/* AC Output Initial Value select */
typedef enum AC_INITVAL_enum
{
    AC_INITVAL_LOW_gc = (0x00<<6),  /* Output initialized to 0 */
    AC_INITVAL_HIGH_gc = (0x01<<6)  /* Output initialized to 1 */
} AC_INITVAL_t;

/* Interrupt Mode select */
typedef enum AC_INTMODE_NORMAL_enum
{
    AC_INTMODE_NORMAL_BOTHEDGE_gc = (0x00<<4),  /* Positive and negative inputs crosses */
    AC_INTMODE_NORMAL_NEGEDGE_gc = (0x02<<4),  /* Positive input goes below negative input */
    AC_INTMODE_NORMAL_POSEDGE_gc = (0x03<<4)  /* Positive input goes above negative input */
} AC_INTMODE_NORMAL_t;

/* Interrupt Mode select */
typedef enum AC_INTMODE_WINDOW_enum
{
    AC_INTMODE_WINDOW_ABOVE_gc = (0x00<<4),  /* Window interrupt when input above both references */
    AC_INTMODE_WINDOW_INSIDE_gc = (0x01<<4),  /* Window interrupt when input betweeen references */
    AC_INTMODE_WINDOW_BELOW_gc = (0x02<<4),  /* Window interrupt when input below both references */
    AC_INTMODE_WINDOW_OUTSIDE_gc = (0x03<<4)  /* Window interrupt when input outside reference */
} AC_INTMODE_WINDOW_t;

/* Negative Input MUX Selection */
typedef enum AC_MUXNEG_enum
{
    AC_MUXNEG_AINN0_gc = (0x00<<0),  /* Negative Pin 0 */
    AC_MUXNEG_AINN1_gc = (0x01<<0),  /* Negative Pin 1 */
    AC_MUXNEG_AINN2_gc = (0x02<<0),  /* Negative Pin 2 */
    AC_MUXNEG_DACREF_gc = (0x03<<0)  /* DAC Reference */
} AC_MUXNEG_t;

/* Positive Input MUX Selection */
typedef enum AC_MUXPOS_enum
{
    AC_MUXPOS_AINP0_gc = (0x00<<3),  /* Positive Pin 0 */
    AC_MUXPOS_AINP1_gc = (0x01<<3),  /* Positive Pin 1 */
    AC_MUXPOS_AINP2_gc = (0x02<<3),  /* Positive Pin 2 */
    AC_MUXPOS_AINP3_gc = (0x03<<3),  /* Positive Pin 3 */
    AC_MUXPOS_AINP4_gc = (0x04<<3),  /* Positive Pin 4 */
    AC_MUXPOS_AINP5_gc = (0x05<<3),  /* Positive Pin 5 */
    AC_MUXPOS_AINP6_gc = (0x06<<3)  /* Positive Pin 6 */
} AC_MUXPOS_t;

/* Power profile select */
typedef enum AC_POWER_enum
{
    AC_POWER_PROFILE0_gc = (0x00<<3),  /* Power profile 0, Fastest response time, highest consumption */
    AC_POWER_PROFILE1_gc = (0x01<<3)  /* Power profile 1 */
} AC_POWER_t;

/* Window selection mode */
typedef enum AC_WINSEL_enum
{
    AC_WINSEL_DISABLED_gc = (0x00<<0),  /* Window function disabled */
    AC_WINSEL_UPSEL1_gc = (0x01<<0),  /* Select ACn+1 as upper limit in window compare */
    AC_WINSEL_UPSEL2_gc = (0x02<<0)  /* Select ACn+2 as upper limit in window compare */
} AC_WINSEL_t;

/* Analog Comparator Window State select */
typedef enum AC_WINSTATE_enum
{
    AC_WINSTATE_ABOVE_gc = (0x00<<6),  /* Above window */
    AC_WINSTATE_INSIDE_gc = (0x01<<6),  /* Inside window */
    AC_WINSTATE_BELOW_gc = (0x02<<6)  /* Below window */
} AC_WINSTATE_t;

/*
--------------------------------------------------------------------------
CCL - Configurable Custom Logic
--------------------------------------------------------------------------
*/

/* Configurable Custom Logic */
typedef struct CCL_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t SEQCTRL0;  /* Sequential Control 0 */
    register8_t SEQCTRL1;  /* Sequential Control 1 */
    register8_t reserved_1[2];
    register8_t INTCTRL0;  /* Interrupt Control 0 */
    register8_t reserved_2[1];
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t LUT0CTRLA;  /* LUT 0 Control A */
    register8_t LUT0CTRLB;  /* LUT 0 Control B */
    register8_t LUT0CTRLC;  /* LUT 0 Control C */
    register8_t TRUTH0;  /* Truth 0 */
    register8_t LUT1CTRLA;  /* LUT 1 Control A */
    register8_t LUT1CTRLB;  /* LUT 1 Control B */
    register8_t LUT1CTRLC;  /* LUT 1 Control C */
    register8_t TRUTH1;  /* Truth 1 */
    register8_t LUT2CTRLA;  /* LUT 2 Control A */
    register8_t LUT2CTRLB;  /* LUT 2 Control B */
    register8_t LUT2CTRLC;  /* LUT 2 Control C */
    register8_t TRUTH2;  /* Truth 2 */
    register8_t LUT3CTRLA;  /* LUT 3 Control A */
    register8_t LUT3CTRLB;  /* LUT 3 Control B */
    register8_t LUT3CTRLC;  /* LUT 3 Control C */
    register8_t TRUTH3;  /* Truth 3 */
    register8_t reserved_3[40];
} CCL_t;

/* Clock Source Selection */
typedef enum CCL_CLKSRC_enum
{
    CCL_CLKSRC_CLKPER_gc = (0x00<<1),  /* Peripheral Clock */
    CCL_CLKSRC_IN2_gc = (0x01<<1),  /* INSEL2 selection */
    CCL_CLKSRC_OSCHF_gc = (0x04<<1),  /* Internal High Frequency oscillator */
    CCL_CLKSRC_OSC32K_gc = (0x05<<1),  /* Internal 32.768 kHz oscillator */
    CCL_CLKSRC_OSC1K_gc = (0x06<<1)  /* Internal 32.768 kHz oscillator divided by 32 */
} CCL_CLKSRC_t;

/* Edge Detection Enable select */
typedef enum CCL_EDGEDET_enum
{
    CCL_EDGEDET_DIS_gc = (0x00<<7),  /* Edge detector is disabled */
    CCL_EDGEDET_EN_gc = (0x01<<7)  /* Edge detector is enabled */
} CCL_EDGEDET_t;

/* Filter Selection */
typedef enum CCL_FILTSEL_enum
{
    CCL_FILTSEL_DISABLE_gc = (0x00<<4),  /* Filter disabled */
    CCL_FILTSEL_SYNCH_gc = (0x01<<4),  /* Synchronizer enabled */
    CCL_FILTSEL_FILTER_gc = (0x02<<4)  /* Filter enabled */
} CCL_FILTSEL_t;

/* LUT Input 0 Source Selection */
typedef enum CCL_INSEL0_enum
{
    CCL_INSEL0_MASK_gc = (0x00<<0),  /* Masked input */
    CCL_INSEL0_FEEDBACK_gc = (0x01<<0),  /* Feedback input */
    CCL_INSEL0_LINK_gc = (0x02<<0),  /* Output from LUT[n+1] as input source */
    CCL_INSEL0_EVENTA_gc = (0x03<<0),  /* Event A as input source */
    CCL_INSEL0_EVENTB_gc = (0x04<<0),  /* Event B as input source */
    CCL_INSEL0_IO_gc = (0x05<<0),  /* IN0 input source */
    CCL_INSEL0_AC0_gc = (0x06<<0),  /* AC0 output input source */
    CCL_INSEL0_USART0_gc = (0x07<<0),  /* USART0 TxD input source */
    CCL_INSEL0_SPI0_gc = (0x08<<0),  /* SPI0 MOSI input source */
    CCL_INSEL0_TCE0_gc = (0x09<<0),  /* TCE0 WO0 input source */
    CCL_INSEL0_TCB0_gc = (0x0A<<0),  /* TCB0 WO input source */
    CCL_INSEL0_TCF0_gc = (0x0B<<0),  /* TCF0 WO0 input source */
    CCL_INSEL0_WEX0_gc = (0x0C<<0)  /* Blanking input source */
} CCL_INSEL0_t;

/* LUT Input 1 Source Selection */
typedef enum CCL_INSEL1_enum
{
    CCL_INSEL1_MASK_gc = (0x00<<4),  /* Masked input */
    CCL_INSEL1_FEEDBACK_gc = (0x01<<4),  /* Feedback input */
    CCL_INSEL1_LINK_gc = (0x02<<4),  /* Output from LUT[n+1] as input source */
    CCL_INSEL1_EVENTA_gc = (0x03<<4),  /* Event A as input source */
    CCL_INSEL1_EVENTB_gc = (0x04<<4),  /* Event B as input source */
    CCL_INSEL1_IO_gc = (0x05<<4),  /* IN0 input source */
    CCL_INSEL1_AC1_gc = (0x06<<4),  /* AC1 output input source */
    CCL_INSEL1_USART1_gc = (0x07<<4),  /* USART1 TxD input source */
    CCL_INSEL1_SPI0_gc = (0x08<<4),  /* SPI0 MOSI input source */
    CCL_INSEL1_TCE0_gc = (0x09<<4),  /* TCE0 WO1 input source */
    CCL_INSEL1_TCB1_gc = (0x0A<<4),  /* TCB1 WO input source */
    CCL_INSEL1_TCF0_gc = (0x0B<<4),  /* TCF0 WO1 input source */
    CCL_INSEL1_WEX0_gc = (0x0C<<4)  /* Blanking input source */
} CCL_INSEL1_t;

/* LUT Input 2 Source Selection */
typedef enum CCL_INSEL2_enum
{
    CCL_INSEL2_MASK_gc = (0x00<<0),  /* Masked input */
    CCL_INSEL2_FEEDBACK_gc = (0x01<<0),  /* Feedback input */
    CCL_INSEL2_LINK_gc = (0x02<<0),  /* Output from LUT[n+1] as input source */
    CCL_INSEL2_EVENTA_gc = (0x03<<0),  /* Event A as input source */
    CCL_INSEL2_EVENTB_gc = (0x04<<0),  /* Event B as input source */
    CCL_INSEL2_IO_gc = (0x05<<0),  /* IN0 input source */
    CCL_INSEL2_AC_gc = (0x06<<0),  /* AC0 output input source */
    CCL_INSEL2_USART2_gc = (0x07<<0),  /* USART2 TxD input source */
    CCL_INSEL2_SPI0_gc = (0x08<<0),  /* SPI0 MOSI input source */
    CCL_INSEL2_TCE0_gc = (0x09<<0),  /* TCE0 WO2 input source */
    CCL_INSEL2_TCB0_gc = (0x0A<<0),  /* TCB1 WO input source */
    CCL_INSEL2_TCF0_gc = (0x0B<<0),  /* TCF0 WO0 input source */
    CCL_INSEL2_WEX0_gc = (0x0C<<0)  /* Blanking input source */
} CCL_INSEL2_t;

/* Interrupt Mode for LUT0 select */
typedef enum CCL_INTMODE0_enum
{
    CCL_INTMODE0_BOTH_gc = (0x00<<0),  /* Sense both edges */
    CCL_INTMODE0_FALLING_gc = (0x01<<0),  /* Sense falling edge */
    CCL_INTMODE0_RISING_gc = (0x02<<0),  /* Sense rising edge */
    CCL_INTMODE0_INTDISABLE_gc = (0x03<<0)  /* Interrupt disabled */
} CCL_INTMODE0_t;

/* Interrupt Mode for LUT1 select */
typedef enum CCL_INTMODE1_enum
{
    CCL_INTMODE1_BOTH_gc = (0x00<<2),  /* Sense both edges */
    CCL_INTMODE1_FALLING_gc = (0x01<<2),  /* Sense falling edge */
    CCL_INTMODE1_RISING_gc = (0x02<<2),  /* Sense rising edge */
    CCL_INTMODE1_INTDISABLE_gc = (0x03<<2)  /* Interrupt disabled */
} CCL_INTMODE1_t;

/* Interrupt Mode for LUT2 select */
typedef enum CCL_INTMODE2_enum
{
    CCL_INTMODE2_BOTH_gc = (0x00<<4),  /* Sense both edges */
    CCL_INTMODE2_FALLING_gc = (0x01<<4),  /* Sense falling edge */
    CCL_INTMODE2_RISING_gc = (0x02<<4),  /* Sense rising edge */
    CCL_INTMODE2_INTDISABLE_gc = (0x03<<4)  /* Interrupt disabled */
} CCL_INTMODE2_t;

/* Interrupt Mode for LUT3 select */
typedef enum CCL_INTMODE3_enum
{
    CCL_INTMODE3_BOTH_gc = (0x00<<6),  /* Sense both edges */
    CCL_INTMODE3_FALLING_gc = (0x01<<6),  /* Sense falling edge */
    CCL_INTMODE3_RISING_gc = (0x02<<6),  /* Sense rising edge */
    CCL_INTMODE3_INTDISABLE_gc = (0x03<<6)  /* Interrupt disabled */
} CCL_INTMODE3_t;

/* Sequential Selection */
typedef enum CCL_SEQSEL_enum
{
    CCL_SEQSEL_DISABLE_gc = (0x00<<0),  /* Sequential logic disabled */
    CCL_SEQSEL_DFF_gc = (0x01<<0),  /* D FlipFlop */
    CCL_SEQSEL_JK_gc = (0x02<<0),  /* JK FlipFlop */
    CCL_SEQSEL_LATCH_gc = (0x03<<0),  /* D Latch */
    CCL_SEQSEL_RS_gc = (0x04<<0)  /* RS Latch */
} CCL_SEQSEL_t;

/*
--------------------------------------------------------------------------
CLKCTRL - Clock controller
--------------------------------------------------------------------------
*/

/* Clock controller */
typedef struct CLKCTRL_struct
{
    register8_t MCLKCTRLA;  /* MCLK Control A */
    register8_t MCLKCTRLB;  /* MCLK Control B */
    register8_t MCLKLOCK;  /* MCLK Lock */
    register8_t MCLKSTATUS;  /* MCLK Status */
    register8_t MCLKSTATUSB;  /* MCLK Status B */
    register8_t reserved_1[2];
    register8_t MCLKTEST;  /* MCLK Test */
    register8_t OSCHFCTRLA;  /* OSCHF Control A */
    register8_t OSCHFTUNE;  /* OSCHF Tune */
    register8_t reserved_2[2];
    register8_t OSCHFCALL;  /* OSCHF Freq Calibration Low */
    register8_t OSCHFCALH;  /* OSCHF Freq Calibration High */
    register8_t OSCHFTCAL;  /* OSCHF Temp cal */
    register8_t OSCHFTEST;  /* OSCHF Test */
    register8_t PLLCTRLA;  /* PLL Control A */
    register8_t reserved_3[2];
    register8_t PLLTEST;  /* PLL Test */
    register8_t reserved_4[1];
    register8_t OSCPDICAL;  /* OSC PDI Calibration */
    register8_t reserved_5[1];
    register8_t OSCPDITEST;  /* OSC PDI Test */
    register8_t OSC32KCTRLA;  /* OSC32K Control A */
    register8_t OSC32KCAL;  /* OSC32K Calibration */
    register8_t reserved_6[1];
    register8_t OSC32KTEST;  /* OSC32K Test */
    register8_t XOSC32KCTRLA;  /* XOSC32K Control A */
    register8_t reserved_7[2];
    register8_t XOSC32KTEST;  /* XOSC32K Test */
} CLKCTRL_t;

/* clock select */
typedef enum CLKCTRL_CLKSEL_enum
{
    CLKCTRL_CLKSEL_OSCHF_gc = (0x00<<0),  /* Internal high-frequency oscillator */
    CLKCTRL_CLKSEL_OSC32K_gc = (0x01<<0),  /* Internal 32.768 kHz oscillator */
    CLKCTRL_CLKSEL_XOSC32K_gc = (0x02<<0),  /* 32.768 kHz crystal oscillator */
    CLKCTRL_CLKSEL_EXTCLK_gc = (0x03<<0),  /* External clock */
    CLKCTRL_CLKSEL_PLL_gc = (0x04<<0),  /* 32-96 MHz PLL (test) */
    CLKCTRL_CLKSEL_OSCPDI_gc = (0x05<<0),  /* Internal PDI oscillator (test) */
    CLKCTRL_CLKSEL_EXTCLKPDI_gc = (0x06<<0),  /* External PDI clock (test) */
    CLKCTRL_CLKSEL_OSC600K_gc = (0x07<<0)  /* Internal 600 kHz oscillator (test) */
} CLKCTRL_CLKSEL_t;

/* Crystal startup time select */
typedef enum CLKCTRL_CSUT_enum
{
    CLKCTRL_CSUT_1K_gc = (0x00<<4),  /* 1k cycles */
    CLKCTRL_CSUT_16K_gc = (0x01<<4),  /* 16k cycles */
    CLKCTRL_CSUT_32K_gc = (0x02<<4),  /* 32k cycles */
    CLKCTRL_CSUT_64K_gc = (0x03<<4)  /* 64k cycles */
} CLKCTRL_CSUT_t;

/* Frequency select */
typedef enum CLKCTRL_FREQSEL_enum
{
    CLKCTRL_FREQSEL_1M_gc = (0x00<<2),  /* 1 MHz system clock */
    CLKCTRL_FREQSEL_2M_gc = (0x01<<2),  /* 2 MHz system clock */
    CLKCTRL_FREQSEL_3M_gc = (0x02<<2),  /* 3 MHz system clock */
    CLKCTRL_FREQSEL_4M_gc = (0x03<<2),  /* 4 MHz system clock (default) */
    CLKCTRL_FREQSEL_8M_gc = (0x05<<2),  /* 8 MHz system clock */
    CLKCTRL_FREQSEL_12M_gc = (0x06<<2),  /* 12 MHz system clock */
    CLKCTRL_FREQSEL_16M_gc = (0x07<<2),  /* 16 MHz system clock */
    CLKCTRL_FREQSEL_20M_gc = (0x08<<2),  /* 20 MHz system clock */
    CLKCTRL_FREQSEL_24M_gc = (0x09<<2),  /* 24 MHz system clock */
    CLKCTRL_FREQSEL_28M_gc = (0x0A<<2),  /* 28 MHz system clock */
    CLKCTRL_FREQSEL_32M_gc = (0x0B<<2)  /* 32 MHz system clock */
} CLKCTRL_FREQSEL_t;

/* Prescaler division select */
typedef enum CLKCTRL_PDIV_enum
{
    CLKCTRL_PDIV_2X_gc = (0x00<<1),  /* 2X */
    CLKCTRL_PDIV_4X_gc = (0x01<<1),  /* 4X */
    CLKCTRL_PDIV_8X_gc = (0x02<<1),  /* 8X */
    CLKCTRL_PDIV_16X_gc = (0x03<<1),  /* 16X */
    CLKCTRL_PDIV_32X_gc = (0x04<<1),  /* 32X */
    CLKCTRL_PDIV_64X_gc = (0x05<<1),  /* 64X */
    CLKCTRL_PDIV_6X_gc = (0x08<<1),  /* 6X */
    CLKCTRL_PDIV_10X_gc = (0x09<<1),  /* 10X */
    CLKCTRL_PDIV_12X_gc = (0x0A<<1),  /* 12X */
    CLKCTRL_PDIV_24X_gc = (0x0B<<1),  /* 24X */
    CLKCTRL_PDIV_48X_gc = (0x0C<<1)  /* 48X */
} CLKCTRL_PDIV_t;

/*
--------------------------------------------------------------------------
CPU - CPU
--------------------------------------------------------------------------
*/

#define CORE_VERSION  V4TXA

/* CCP signature select */
typedef enum CCP_enum
{
    CCP_TM_gc = (0x4C<<0),  /* TM Register Protection */
    CCP_SPM_gc = (0x9D<<0),  /* SPM Instruction Protection */
    CCP_IOREG_gc = (0xD8<<0)  /* IO Register Protection */
} CCP_t;

/*
--------------------------------------------------------------------------
CPUINT - Interrupt Controller
--------------------------------------------------------------------------
*/

/* Interrupt Controller */
typedef struct CPUINT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
    register8_t LVL0PRI;  /* Interrupt Level 0 Priority */
    register8_t LVL1VEC;  /* Interrupt Level 1 Priority Vector */
} CPUINT_t;


/*
--------------------------------------------------------------------------
CRCSCAN - CRCSCAN
--------------------------------------------------------------------------
*/

/* CRCSCAN */
typedef struct CRCSCAN_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t STATUS;  /* Status */
    register8_t reserved_1[1];
} CRCSCAN_t;

/* CRC Flash Access Mode select */
typedef enum CRCSCAN_MODE_enum
{
    CRCSCAN_MODE_PRIORITY_gc = (0x00<<4),  /* Priority to flash */
    CRCSCAN_MODE_RESERVED_gc = (0x01<<4),  /* Reserved */
    CRCSCAN_MODE_BACKGROUND_gc = (0x02<<4),  /* Lowest priority to flash */
    CRCSCAN_MODE_CONTINUOUS_gc = (0x03<<4)  /* Continuous checks in background */
} CRCSCAN_MODE_t;

/* CRC Source select */
typedef enum CRCSCAN_SRC_enum
{
    CRCSCAN_SRC_FLASH_gc = (0x00<<0),  /* CRC on entire flash */
    CRCSCAN_SRC_APPLICATION_gc = (0x01<<0),  /* CRC on boot and appl section of flash */
    CRCSCAN_SRC_BOOT_gc = (0x02<<0),  /* CRC on boot section of flash */
    CRCSCAN_SRC_SIGROW_gc = (0x03<<0)  /* CRC on flash signature row (AUX) */
} CRCSCAN_SRC_t;

/*
--------------------------------------------------------------------------
EVSYS - Event System
--------------------------------------------------------------------------
*/

/* Event System */
typedef struct EVSYS_struct
{
    register8_t SWEVENTA;  /* Software Event A */
    register8_t reserved_1[15];
    register8_t CHANNEL0;  /* Multiplexer Channel 0 */
    register8_t CHANNEL1;  /* Multiplexer Channel 1 */
    register8_t CHANNEL2;  /* Multiplexer Channel 2 */
    register8_t CHANNEL3;  /* Multiplexer Channel 3 */
    register8_t CHANNEL4;  /* Multiplexer Channel 4 */
    register8_t CHANNEL5;  /* Multiplexer Channel 5 */
    register8_t CHANNEL6;  /* Multiplexer Channel 6 */
    register8_t CHANNEL7;  /* Multiplexer Channel 7 */
    register8_t reserved_2[8];
    register8_t USERCCLLUT0A;  /* CCL0 Event A */
    register8_t USERCCLLUT0B;  /* CCL0 Event B */
    register8_t USERCCLLUT1A;  /* CCL1 Event A */
    register8_t USERCCLLUT1B;  /* CCL1 Event B */
    register8_t USERCCLLUT2A;  /* CCL2 Event A */
    register8_t USERCCLLUT2B;  /* CCL2 Event B */
    register8_t USERCCLLUT3A;  /* CCL3 Event A */
    register8_t USERCCLLUT3B;  /* CCL3 Event B */
    register8_t USERADC0START;  /* ADC0 */
    register8_t USEREVSYSEVOUTA;  /* EVOUTA */
    register8_t USEREVSYSEVOUTC;  /* EVOUTC */
    register8_t USEREVSYSEVOUTD;  /* EVOUTD */
    register8_t USEREVSYSEVOUTF;  /* EVOUTF */
    register8_t USERUSART0IRDA;  /* USART0 */
    register8_t USERTCE0CNTA;  /* TCE0 Event A */
    register8_t USERTCE0CNTB;  /* TCE0 Event B */
    register8_t USERTCB0CAPT;  /* TCB0 Event A */
    register8_t USERTCB0COUNT;  /* TCB0 Event B */
    register8_t USERTCB1CAPT;  /* TCB1 Event A */
    register8_t USERTCB1COUNT;  /* TCB1 Event B */
    register8_t USERTCF0CNT;  /* TCF0 Clock Event */
    register8_t USERTCF0ACT;  /* TCF0 Action Event */
    register8_t USERWEXA;  /* WEX Event A */
    register8_t USERWEXB;  /* WEX Event B */
    register8_t USERWEXC;  /* WEX Event C */
    register8_t reserved_3[38];
    register8_t USERTEST;  /* OSCTEST */
} EVSYS_t;

/* Channel generator select */
typedef enum EVSYS_CHANNEL_enum
{
    EVSYS_CHANNEL_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI SYNCH character */
    EVSYS_CHANNEL_TEST_gc = (0x02<<0),  /* Test event */
    EVSYS_CHANNEL_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL_RTC_PITEV0_gc = (0x08<<0),  /* Periodic Interrupt Timer Event 0 */
    EVSYS_CHANNEL_RTC_PITEV1_gc = (0x09<<0),  /* Periodic Interrupt Timer Event 1 */
    EVSYS_CHANNEL_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL_PORTF_EV0_gc = (0x40<<0),  /* Port F Event 0 */
    EVSYS_CHANNEL_PORTF_EV1_gc = (0x41<<0),  /* Port F Event 1 */
    EVSYS_CHANNEL_PORTF_EV2_gc = (0x42<<0),  /* Port F Event 2 */
    EVSYS_CHANNEL_PORTF_EV3_gc = (0x43<<0),  /* Port F Event 3 */
    EVSYS_CHANNEL_PORTF_EV4_gc = (0x44<<0),  /* Port F Event 4 */
    EVSYS_CHANNEL_PORTF_EV5_gc = (0x45<<0),  /* Port F Event 5 */
    EVSYS_CHANNEL_PORTF_EV6_gc = (0x46<<0),  /* Port F Event 6 */
    EVSYS_CHANNEL_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL_TCE0_OVF_gc = (0x80<<0),  /* Timer/Counter E0 Overflow */
    EVSYS_CHANNEL_TCE0_CMP0_gc = (0x84<<0),  /* Timer/Counter E0 Compare 0 */
    EVSYS_CHANNEL_TCE0_CMP1_gc = (0x85<<0),  /* Timer/Counter E0 Compare 1 */
    EVSYS_CHANNEL_TCE0_CMP2_gc = (0x86<<0),  /* Timer/Counter E0 Compare 2 */
    EVSYS_CHANNEL_TCE0_CMP3_gc = (0x87<<0),  /* Timer/Counter E0 Compare 3 */
    EVSYS_CHANNEL_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 Capture */
    EVSYS_CHANNEL_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 Overflow */
    EVSYS_CHANNEL_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 Capture */
    EVSYS_CHANNEL_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 Overflow */
    EVSYS_CHANNEL_TCF0_OVF_gc = (0xB8<<0),  /* Timer/Counter F0 Overflow */
    EVSYS_CHANNEL_TCF0_CMP0_gc = (0xB9<<0),  /* Timer/Counter F0 Compare 0 */
    EVSYS_CHANNEL_TCF0_CMP1_gc = (0xBA<<0)  /* Timer/Counter F0 Compare 1 */
} EVSYS_CHANNEL_t;

/* Software event on channel select */
typedef enum EVSYS_SWEVENTA_enum
{
    EVSYS_SWEVENTA_CH0_gc = (0x01<<0),  /* Software event on channel 0 */
    EVSYS_SWEVENTA_CH1_gc = (0x02<<0),  /* Software event on channel 1 */
    EVSYS_SWEVENTA_CH2_gc = (0x04<<0),  /* Software event on channel 2 */
    EVSYS_SWEVENTA_CH3_gc = (0x08<<0),  /* Software event on channel 3 */
    EVSYS_SWEVENTA_CH4_gc = (0x10<<0),  /* Software event on channel 4 */
    EVSYS_SWEVENTA_CH5_gc = (0x20<<0),  /* Software event on channel 5 */
    EVSYS_SWEVENTA_CH6_gc = (0x40<<0),  /* Software event on channel 6 */
    EVSYS_SWEVENTA_CH7_gc = (0x80<<0)  /* Software event on channel 7 */
} EVSYS_SWEVENTA_t;

/* User channel select */
typedef enum EVSYS_USER_enum
{
    EVSYS_USER_OFF_gc = (0x00<<0),  /* Off, No Eventsys Channel connected */
    EVSYS_USER_CHANNEL0_gc = (0x01<<0),  /* Connect user to event channel 0 */
    EVSYS_USER_CHANNEL1_gc = (0x02<<0),  /* Connect user to event channel 1 */
    EVSYS_USER_CHANNEL2_gc = (0x03<<0),  /* Connect user to event channel 2 */
    EVSYS_USER_CHANNEL3_gc = (0x04<<0),  /* Connect user to event channel 3 */
    EVSYS_USER_CHANNEL4_gc = (0x05<<0),  /* Connect user to event channel 4 */
    EVSYS_USER_CHANNEL5_gc = (0x06<<0),  /* Connect user to event channel 5 */
    EVSYS_USER_CHANNEL6_gc = (0x07<<0),  /* Connect user to event channel 6 */
    EVSYS_USER_CHANNEL7_gc = (0x08<<0)  /* Connect user to event channel 7 */
} EVSYS_USER_t;

/*
--------------------------------------------------------------------------
FIM - FPGA Interface Module
--------------------------------------------------------------------------
*/

/* FPGA Interface Module */
typedef struct FIM_struct
{
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status of Buttons and USB connection */
    register8_t reserved_1[1];
    _WORDREGISTER(SWITCHES);  /* Slider Switches */
    _WORDREGISTER(LEDS);  /* LEDs */
    _DWORDREGISTER(SEVENSEG);  /* Seven Segment Display */
    register8_t DOTS;  /* Dots in Seven Segment Displays */
    register8_t reserved_2[3];
    _DWORDREGISTER(MCLED0);  /* Multi-color LED0 */
    _DWORDREGISTER(MCLED1);  /* Multi-color LED1 */
    _DWORDREGISTER(DNALSDW);  /* FPGA DNA Least Siginificant Double Word */
    _DWORDREGISTER(DNAMSDW);  /* FPGA DNA Most Significant Double Word */
    register8_t VGA;  /* VGA */
    register8_t reserved_3[31];
} FIM_t;


/*
--------------------------------------------------------------------------
FUSE - Fuses
--------------------------------------------------------------------------
*/

/* Fuses */
typedef struct FUSE_struct
{
    register8_t WDTCFG;  /* Watchdog Configuration */
    register8_t BODCFG;  /* BOD Configuration */
    register8_t OSCCFG;  /* Oscillator Configuration */
    register8_t reserved_1[2];
    register8_t SYSCFG0;  /* System Configuration 0 */
    register8_t SYSCFG1;  /* System Configuration 1 */
    register8_t CODESIZE;  /* Code Section Size */
    register8_t BOOTSIZE;  /* Boot Section Size */
    register8_t reserved_2[7];
} FUSE_t;

/* avr-libc typedef for avr/fuse.h */
typedef FUSE_t NVM_FUSES_t;

/* BOD Operation in Active Mode select */
typedef enum ACTIVE_enum
{
    ACTIVE_DISABLE_gc = (0x00<<2),  /* BOD disabled */
    ACTIVE_ENABLE_gc = (0x01<<2),  /* BOD enabled in continiuous mode */
    ACTIVE_SAMPLE_gc = (0x02<<2),  /* BOD enabled in sampled mode */
    ACTIVE_ENABLEWAIT_gc = (0x03<<2)  /* BOD enabled in continiuous mode. Execution is halted at wake-up until BOD is running. */
} ACTIVE_t;

/* Frequency Select */
typedef enum CLKSEL_enum
{
    CLKSEL_OSCHF_gc = (0x00<<0),  /* 1-32MHz internal oscillator */
    CLKSEL_OSC32K_gc = (0x01<<0)  /* 32.768kHz internal oscillator */
} CLKSEL_t;

/* CRC Select */
typedef enum CRCSEL_enum
{
    CRCSEL_CRC32_gc = (0x00<<5),  /* Enable CRC32 */
    CRCSEL_CRC16_gc = (0x01<<5)  /* Enable CRC16 */
} CRCSEL_t;

/* CRC Source select */
typedef enum CRCSRC_enum
{
    CRCSRC_FLASH_gc = (0x00<<6),  /* CRC of full Flash (boot, application code and application data) */
    CRCSRC_BOOT_gc = (0x01<<6),  /* CRC of boot section */
    CRCSRC_BOOTAPP_gc = (0x02<<6),  /* CRC of application code and boot sections */
    CRCSRC_NOCRC_gc = (0x03<<6)  /* No CRC */
} CRCSRC_t;

/* BOD Level select */
typedef enum LVL_enum
{
    LVL_BODLEVEL0_gc = (0x00<<5),  /* 1.9V */
    LVL_BODLEVEL1_gc = (0x01<<5),  /* 2.45V */
    LVL_BODLEVEL2_gc = (0x02<<5),  /* 2.7V */
    LVL_BODLEVEL3_gc = (0x03<<5)  /* 2.85V */
} LVL_t;

/* Watchdog Timeout Period select */
typedef enum PERIOD_enum
{
    PERIOD_OFF_gc = (0x00<<0),  /* Watch-Dog timer Off */
    PERIOD_8CLK_gc = (0x01<<0),  /* 8 cycles (8ms) */
    PERIOD_16CLK_gc = (0x02<<0),  /* 16 cycles (16ms) */
    PERIOD_32CLK_gc = (0x03<<0),  /* 32 cycles (32ms) */
    PERIOD_64CLK_gc = (0x04<<0),  /* 64 cycles (64ms) */
    PERIOD_128CLK_gc = (0x05<<0),  /* 128 cycles (0.128s) */
    PERIOD_256CLK_gc = (0x06<<0),  /* 256 cycles (0.256s) */
    PERIOD_512CLK_gc = (0x07<<0),  /* 512 cycles (0.512s) */
    PERIOD_1KCLK_gc = (0x08<<0),  /* 1K cycles (1.0s) */
    PERIOD_2KCLK_gc = (0x09<<0),  /* 2K cycles (2.0s) */
    PERIOD_4KCLK_gc = (0x0A<<0),  /* 4K cycles (4.0s) */
    PERIOD_8KCLK_gc = (0x0B<<0)  /* 8K cycles (8.0s) */
} PERIOD_t;

/* Reset Pin Configuration select */
typedef enum RSTPINCFG_enum
{
    RSTPINCFG_GPIO_gc = (0x00<<2),  /* GPIO mode */
    RSTPINCFG_RST_gc = (0x02<<2)  /* Reset mode */
} RSTPINCFG_t;

/* BOD Sample Frequency select */
typedef enum SAMPFREQ_enum
{
    SAMPFREQ_128Hz_gc = (0x00<<4),  /* Sample frequency is 128 Hz */
    SAMPFREQ_32Hz_gc = (0x01<<4)  /* Sample frequency is 32 Hz */
} SAMPFREQ_t;

/* BOD Operation in Sleep Mode select */
typedef enum SLEEP_enum
{
    SLEEP_DISABLE_gc = (0x00<<0),  /* BOD disabled */
    SLEEP_ENABLE_gc = (0x01<<0),  /* BOD enabled in continiuous mode */
    SLEEP_SAMPLE_gc = (0x02<<0)  /* BOD enabled in sampled mode */
} SLEEP_t;

/* Startup Time select */
typedef enum SUT_enum
{
    SUT_0MS_gc = (0x00<<0),  /* 0 ms */
    SUT_1MS_gc = (0x01<<0),  /* 1 ms */
    SUT_2MS_gc = (0x02<<0),  /* 2 ms */
    SUT_4MS_gc = (0x03<<0),  /* 4 ms */
    SUT_8MS_gc = (0x04<<0),  /* 8 ms */
    SUT_16MS_gc = (0x05<<0),  /* 16 ms */
    SUT_32MS_gc = (0x06<<0),  /* 32 ms */
    SUT_64MS_gc = (0x07<<0)  /* 64 ms */
} SUT_t;

/* Watchdog Window Timeout Period select */
typedef enum WINDOW_enum
{
    WINDOW_OFF_gc = (0x00<<4),  /* Window mode off */
    WINDOW_8CLK_gc = (0x01<<4),  /* 8 cycles (8ms) */
    WINDOW_16CLK_gc = (0x02<<4),  /* 16 cycles (16ms) */
    WINDOW_32CLK_gc = (0x03<<4),  /* 32 cycles (32ms) */
    WINDOW_64CLK_gc = (0x04<<4),  /* 64 cycles (64ms) */
    WINDOW_128CLK_gc = (0x05<<4),  /* 128 cycles (0.128s) */
    WINDOW_256CLK_gc = (0x06<<4),  /* 256 cycles (0.256s) */
    WINDOW_512CLK_gc = (0x07<<4),  /* 512 cycles (0.512s) */
    WINDOW_1KCLK_gc = (0x08<<4),  /* 1K cycles (1.0s) */
    WINDOW_2KCLK_gc = (0x09<<4),  /* 2K cycles (2.0s) */
    WINDOW_4KCLK_gc = (0x0A<<4),  /* 4K cycles (4.0s) */
    WINDOW_8KCLK_gc = (0x0B<<4)  /* 8K cycles (8.0s) */
} WINDOW_t;

/*
--------------------------------------------------------------------------
GPR - General Purpose Registers
--------------------------------------------------------------------------
*/

/* General Purpose Registers */
typedef struct GPR_struct
{
    register8_t GPR0;  /* General Purpose Register 0 */
    register8_t GPR1;  /* General Purpose Register 1 */
    register8_t GPR2;  /* General Purpose Register 2 */
    register8_t GPR3;  /* General Purpose Register 3 */
} GPR_t;


/*
--------------------------------------------------------------------------
LOCK - Lockbit
--------------------------------------------------------------------------
*/

/* Lockbit */
typedef struct LOCK_struct
{
    _DWORDREGISTER(KEY);  /* Lock Key Bits */
} LOCK_t;

/* Lock Key select */
typedef enum LOCK_LB_enum
{
    LOCK_LB_NOLOCK_gc = (0x5CC5C55C<<0),  /* No locks */
    LOCK_LB_RWLOCK_gc = (0xA33A3AA3<<0)  /* Read and write lock */
} LOCK_LB_t;

/*
--------------------------------------------------------------------------
NVMCTRL - Non-volatile Memory Controller
--------------------------------------------------------------------------
*/

/* Non-volatile Memory Controller */
typedef struct NVMCTRL_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t STATUS;  /* Status */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_1[1];
    _WORDREGISTER(DATA);  /* Data */
    _DWORDREGISTER(ADDR);  /* Address */
    register8_t LOCKBITS;  /* Lock Bits */
    register8_t HIDDENCTRLA;  /* Hidden Control */
    register8_t TESTCTRLA;  /* Test Control A */
    register8_t TESTCTRLB;  /* Test Control B */
    register8_t TESTCTRLC;  /* Test Control C */
    register8_t TESTCTRLD;  /* Test Control D */
    register8_t TESTCTRLE;  /* Test Control E */
    register8_t TESTCTRLF;  /* Test Control F */
    register8_t TESTCTRLG;  /* Test Control G */
    register8_t TESTCTRLH;  /* Test Control H */
    register8_t TESTCTRLI;  /* Test Control I */
    register8_t TESTCTRLJ;  /* Test Control J */
    register8_t TESTCTRLK;  /* Test Control K */
    register8_t TESTCTRLL;  /* Test Control L */
    register8_t CALA;  /* Calibration A */
    register8_t CALB;  /* Calibration B */
    register8_t CALC;  /* Calibration C */
    register8_t CALD;  /* Calibration D */
    register8_t CALE;  /* Calibration E */
    register8_t CALF;  /* Calibration F */
    register8_t CALG;  /* Calibration G */
} NVMCTRL_t;

/* Bandgap Request select */
typedef enum NVMCTRL_BGREQ_enum
{
    NVMCTRL_BGREQ_DEFAULT_gc = (0x00<<0),  /* Bandgap requested when required by NVM */
    NVMCTRL_BGREQ_ON_gc = (0x01<<0)  /* Bandgap always enabled */
} NVMCTRL_BGREQ_t;

/* BOD Request Enable select */
typedef enum NVMCTRL_BODREQ_enum
{
    NVMCTRL_BODREQ_ALWAYS_gc = (0x00<<4),  /* The BOD will always be forced on during chip erase */
    NVMCTRL_BODREQ_LOCKED_gc = (0x01<<4)  /* The BOD will be forced on during chip erase only if device is locked */
} NVMCTRL_BODREQ_t;

/* Command select */
typedef enum NVMCTRL_CMD_enum
{
    NVMCTRL_CMD_NONE_gc = (0x00<<0),  /* No Command */
    NVMCTRL_CMD_NOOP_gc = (0x01<<0),  /* No Operation */
    NVMCTRL_CMD_FLWR_gc = (0x02<<0),  /* Flash Write */
    NVMCTRL_CMD_FLPER_gc = (0x08<<0),  /* Flash Page Erase */
    NVMCTRL_CMD_FLMPER2_gc = (0x09<<0),  /* Flash Multi-Page Erase 2 pages */
    NVMCTRL_CMD_FLMPER4_gc = (0x0A<<0),  /* Flash Multi-Page Erase 4 pages */
    NVMCTRL_CMD_FLMPER8_gc = (0x0B<<0),  /* Flash Multi-Page Erase 8 pages */
    NVMCTRL_CMD_FLMPER16_gc = (0x0C<<0),  /* Flash Multi-Page Erase 16 pages */
    NVMCTRL_CMD_FLMPER32_gc = (0x0D<<0),  /* Flash Multi-Page Erase 32 pages */
    NVMCTRL_CMD_EEWR_gc = (0x12<<0),  /* EEPROM Write */
    NVMCTRL_CMD_EEERWR_gc = (0x13<<0),  /* EEPROM Erase and Write */
    NVMCTRL_CMD_EEBER_gc = (0x18<<0),  /* EEPROM Byte Erase */
    NVMCTRL_CMD_EEMBER2_gc = (0x19<<0),  /* EEPROM Multi-Byte Erase 2 bytes */
    NVMCTRL_CMD_EEMBER4_gc = (0x1A<<0),  /* EEPROM Multi-Byte Erase 4 bytes */
    NVMCTRL_CMD_EEMBER8_gc = (0x1B<<0),  /* EEPROM Multi-Byte Erase 8 bytes */
    NVMCTRL_CMD_EEMBER16_gc = (0x1C<<0),  /* EEPROM Multi-Byte Erase 16 bytes */
    NVMCTRL_CMD_EEMBER32_gc = (0x1D<<0),  /* EEPROM Multi-Byte Erase 32 bytes */
    NVMCTRL_CMD_CHER_gc = (0x20<<0),  /* Chip Erase Command */
    NVMCTRL_CMD_EECHER_gc = (0x30<<0),  /* EEPROM Erase Command */
    NVMCTRL_CMD_TCHER_gc = (0x40<<0),  /* Test Chip Erase Command */
    NVMCTRL_CMD_STRESSWR_gc = (0x42<<0),  /* Test Stress Write Command */
    NVMCTRL_CMD_STRESSER_gc = (0x48<<0)  /* Test Stress Erase Command */
} NVMCTRL_CMD_t;

/* EEPROM Bit Line Override select */
typedef enum NVMCTRL_EEBIT_enum
{
    NVMCTRL_EEBIT_ZERO_gc = (0x00<<0),  /* Bit Line '0' */
    NVMCTRL_EEBIT_ONE_gc = (0x01<<0)  /* Bit Line '1' */
} NVMCTRL_EEBIT_t;

/* EEPROM Word/Bit Line Override select */
typedef enum NVMCTRL_EELINE_enum
{
    NVMCTRL_EELINE_NORMAL_gc = (0x00<<2),  /* Normal Operation */
    NVMCTRL_EELINE_OVERRIDE_gc = (0x01<<2)  /* Word/Bit line Override */
} NVMCTRL_EELINE_t;

/* EEPROM Word Line Override select */
typedef enum NVMCTRL_EEWORD_enum
{
    NVMCTRL_EEWORD_ZERO_gc = (0x00<<1),  /* Word Line '0' */
    NVMCTRL_EEWORD_ONE_gc = (0x01<<1)  /* Word Line '1' */
} NVMCTRL_EEWORD_t;

/* Write error select */
typedef enum NVMCTRL_ERROR_enum
{
    NVMCTRL_ERROR_NOERROR_gc = (0x00<<4),  /* No Error */
    NVMCTRL_ERROR_ILLEGALCMD_gc = (0x01<<4),  /* Write command not selected */
    NVMCTRL_ERROR_ILLEGALSADDR_gc = (0x02<<4),  /* Write to section not allowed */
    NVMCTRL_ERROR_DOUBLESELECT_gc = (0x03<<4),  /* Selecting new write command while write command already seleted */
    NVMCTRL_ERROR_ONGOINGPROG_gc = (0x04<<4)  /* Starting a new programming operation before previous is completed */
} NVMCTRL_ERROR_t;

/* Flash Bit Line Override select */
typedef enum NVMCTRL_FLBIT_enum
{
    NVMCTRL_FLBIT_ZERO_gc = (0x00<<3),  /* Bit Line '0' */
    NVMCTRL_FLBIT_ONE_gc = (0x01<<3)  /* Bit Line '1' */
} NVMCTRL_FLBIT_t;

/* Flash Word/Bit Line Override Enable select */
typedef enum NVMCTRL_FLLINE_enum
{
    NVMCTRL_FLLINE_NORMAL_gc = (0x00<<5),  /* Normal Operation */
    NVMCTRL_FLLINE_OVERRIDE_gc = (0x01<<5)  /* Word/Bit Line override */
} NVMCTRL_FLLINE_t;

/* Flash Mapping in Data space select */
typedef enum NVMCTRL_FLMAP_enum
{
    NVMCTRL_FLMAP_SECTION0_gc = (0x00<<4),  /* Flash section 0, 0 - 32KB */
    NVMCTRL_FLMAP_SECTION1_gc = (0x01<<4),  /* Flash section 1, 32 - 64KB */
    NVMCTRL_FLMAP_SECTION2_gc = (0x02<<4),  /* Flash section 2, 64 - 96KB */
    NVMCTRL_FLMAP_SECTION3_gc = (0x03<<4)  /* Flash section 3, 96 - 128KB */
} NVMCTRL_FLMAP_t;

/* Flash Signature Row select */
typedef enum NVMCTRL_FLSIGROW_enum
{
    NVMCTRL_FLSIGROW_NONE_gc = (0x00<<2),  /* No XROW selected */
    NVMCTRL_FLSIGROW_SIGNATURE_gc = (0x01<<2),  /* Signature XROW selected */
    NVMCTRL_FLSIGROW_USERROW_gc = (0x02<<2),  /* User row selected */
    NVMCTRL_FLSIGROW_TSPACE1_gc = (0x04<<2)  /* Signature XROW selected */
} NVMCTRL_FLSIGROW_t;

/* Flash Word Line Override select */
typedef enum NVMCTRL_FLWORD_enum
{
    NVMCTRL_FLWORD_ZERO_gc = (0x00<<4),  /* Word Line '0' */
    NVMCTRL_FLWORD_ONE_gc = (0x01<<4)  /* Word Line '1' */
} NVMCTRL_FLWORD_t;

/* Half-row Programming select */
typedef enum NVMCTRL_HALFROW_enum
{
    NVMCTRL_HALFROW_DISABLE_gc = (0x00<<5),  /* Half-row programming disabled */
    NVMCTRL_HALFROW_ENABLE_gc = (0x01<<5)  /* Half-row programming enabled */
} NVMCTRL_HALFROW_t;

/* Cell Current Enable select */
typedef enum NVMCTRL_ICELLEN_enum
{
    NVMCTRL_ICELLEN_DISABLE_gc = (0x00<<5),  /* Bulk cell current mode disabled */
    NVMCTRL_ICELLEN_ENABLE_gc = (0x01<<5)  /* Bulk cell current mode enabled (ignored is ICELLSRC[1:0]=2'b00) */
} NVMCTRL_ICELLEN_t;

/* Cell Current Select */
typedef enum NVMCTRL_ICELLSEL_enum
{
    NVMCTRL_ICELLSEL_MEM1_gc = (0x00<<0),  /* Memory cell column 1 read / Memory cell A column 1 read */
    NVMCTRL_ICELLSEL_MEM2_gc = (0x01<<0),  /* Memory cell column 2 read / Memory cell A column 2 read */
    NVMCTRL_ICELLSEL_MEM3_gc = (0x02<<0),  /* Memory cell column 3 read / Memory cell B column 1 read */
    NVMCTRL_ICELLSEL_MEM4_gc = (0x03<<0),  /* Memory cell column 4 read / Memory cell B column 2 read */
    NVMCTRL_ICELLSEL_REF1_gc = (0x04<<0),  /* Reference cell column 1 read */
    NVMCTRL_ICELLSEL_REF2_gc = (0x05<<0),  /* Reference cell column 2 read */
    NVMCTRL_ICELLSEL_REF3_gc = (0x06<<0),  /* Reference cell column 3 read */
    NVMCTRL_ICELLSEL_REF4_gc = (0x07<<0)  /* Reference cell column 4 read */
} NVMCTRL_ICELLSEL_t;

/* Cell Current Source Select */
typedef enum NVMCTRL_ICELLSRC_enum
{
    NVMCTRL_ICELLSRC_NONE_gc = (0x00<<3),  /* No memory selected */
    NVMCTRL_ICELLSRC_EEPROM_gc = (0x01<<3),  /* EEPROM cell current */
    NVMCTRL_ICELLSRC_FLASH_gc = (0x02<<3)  /* Flash cell current */
} NVMCTRL_ICELLSRC_t;

/* Margin Mode Select */
typedef enum NVMCTRL_MARGINSEL_enum
{
    NVMCTRL_MARGINSEL_NONE_gc = (0x00<<0),  /* No margni mode select */
    NVMCTRL_MARGINSEL_EECELLB_gc = (0x03<<0),  /* EEPROM cell B margin mode, compare cell B currrent to external reference */
    NVMCTRL_MARGINSEL_EECELLA_gc = (0x04<<0),  /* EEPROM cell A margin mode, compare cell B currrent to external reference */
    NVMCTRL_MARGINSEL_FLMODE1_gc = (0x05<<0),  /* Flash Margin Mode 1, check erased cells margin */
    NVMCTRL_MARGINSEL_FLMODE2_gc = (0x06<<0)  /* Flash Margin Mode 1, check programmed cells margin */
} NVMCTRL_MARGINSEL_t;

/* NVM enable override select */
typedef enum NVMCTRL_NVMEN_enum
{
    NVMCTRL_NVMEN_DISABLE_gc = (0x00<<7),  /* NVM is disabled (if TESTCTRLC.TESTEN=1) */
    NVMCTRL_NVMEN_ENABLE_gc = (0x01<<7)  /* NVM is enabled (if TESTCTRL.TESTEN=1) */
} NVMCTRL_NVMEN_t;

/* Reference Programming select */
typedef enum NVMCTRL_REFPROG_enum
{
    NVMCTRL_REFPROG_OFF_gc = (0x00<<3),  /* A programming operation is performed on the memory cell */
    NVMCTRL_REFPROG_ON_gc = (0x01<<3)  /* A programming operation is performed on the reference cell */
} NVMCTRL_REFPROG_t;

/* Source Line regulation select */
typedef enum NVMCTRL_SRCLINE_enum
{
    NVMCTRL_SRCLINE_REGULATION_gc = (0x00<<7),  /* Regulation loop for biasing Source Line */
    NVMCTRL_SRCLINE_STABILIZE_gc = (0x01<<7)  /* Stabilization for biaings Source Line */
} NVMCTRL_SRCLINE_t;

/* Voltage ramping for programming operations select */
typedef enum NVMCTRL_VRAMPDIS_enum
{
    NVMCTRL_VRAMPDIS_ENABLE_gc = (0x00<<2),  /* Voltage ramp enabled */
    NVMCTRL_VRAMPDIS_DISABLE_gc = (0x01<<2)  /* Voltage ramp disabled */
} NVMCTRL_VRAMPDIS_t;

/* Weak erase enable select */
typedef enum NVMCTRL_WEAKERASE_enum
{
    NVMCTRL_WEAKERASE_DISABLE_gc = (0x00<<4),  /* Normal voltage is employed during erase operation */
    NVMCTRL_WEAKERASE_ENABLE_gc = (0x01<<4)  /* Low voltage is employed during erase operation */
} NVMCTRL_WEAKERASE_t;

/* Write 1 behavior select */
typedef enum NVMCTRL_WRITEONE_enum
{
    NVMCTRL_WRITEONE_SKIP_gc = (0x00<<5),  /* Do not write 1's to bits already containing 1's */
    NVMCTRL_WRITEONE_ALWAYS_gc = (0x01<<5)  /* Always write 1's */
} NVMCTRL_WRITEONE_t;

/*
--------------------------------------------------------------------------
PORT - I/O Ports
--------------------------------------------------------------------------
*/

/* I/O Ports */
typedef struct PORT_struct
{
    register8_t DIR;  /* Data Direction */
    register8_t DIRSET;  /* Data Direction Set */
    register8_t DIRCLR;  /* Data Direction Clear */
    register8_t DIRTGL;  /* Data Direction Toggle */
    register8_t OUT;  /* Output Value */
    register8_t OUTSET;  /* Output Value Set */
    register8_t OUTCLR;  /* Output Value Clear */
    register8_t OUTTGL;  /* Output Value Toggle */
    register8_t IN;  /* Input Value */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t PORTCTRL;  /* Port Control */
    register8_t PINCONFIG;  /* Pin Control Config */
    register8_t PINCTRLUPD;  /* Pin Control Update */
    register8_t PINCTRLSET;  /* Pin Control Set */
    register8_t PINCTRLCLR;  /* Pin Control Clear */
    register8_t reserved_1[1];
    register8_t PIN0CTRL;  /* Pin 0 Control */
    register8_t PIN1CTRL;  /* Pin 1 Control */
    register8_t PIN2CTRL;  /* Pin 2 Control */
    register8_t PIN3CTRL;  /* Pin 3 Control */
    register8_t PIN4CTRL;  /* Pin 4 Control */
    register8_t PIN5CTRL;  /* Pin 5 Control */
    register8_t PIN6CTRL;  /* Pin 6 Control */
    register8_t PIN7CTRL;  /* Pin 7 Control */
    register8_t reserved_2[8];
} PORT_t;

/* Input Level Select */
typedef enum PORT_INLVL_enum
{
    PORT_INLVL_ST_gc = (0x00<<6),  /* Schmitt-Trigger input level */
    PORT_INLVL_TTL_gc = (0x01<<6)  /* TTL Input level */
} PORT_INLVL_t;

/* Input/Sense Configuration select */
typedef enum PORT_ISC_enum
{
    PORT_ISC_INTDISABLE_gc = (0x00<<0),  /* Interrupt disabled but input buffer enabled */
    PORT_ISC_BOTHEDGES_gc = (0x01<<0),  /* Sense Both Edges */
    PORT_ISC_RISING_gc = (0x02<<0),  /* Sense Rising Edge */
    PORT_ISC_FALLING_gc = (0x03<<0),  /* Sense Falling Edge */
    PORT_ISC_INPUT_DISABLE_gc = (0x04<<0),  /* Digital Input Buffer disabled */
    PORT_ISC_LEVEL_gc = (0x05<<0)  /* Sense low Level */
} PORT_ISC_t;

/*
--------------------------------------------------------------------------
PORTMUX - Port Multiplexer
--------------------------------------------------------------------------
*/

/* Port Multiplexer */
typedef struct PORTMUX_struct
{
    register8_t EVSYSROUTEA;  /* EVSYS route A */
    register8_t CCLROUTEA;  /* CCL route A */
    register8_t USARTROUTEA;  /* USART route A */
    register8_t reserved_1[2];
    register8_t SPIROUTEA;  /* SPI route A */
    register8_t TWIROUTEA;  /* TWI route A */
    register8_t TCEROUTEA;  /* TCE route A */
    register8_t TCBROUTEA;  /* TCB route A */
    register8_t reserved_2[1];
    register8_t TCDROUTEA;  /* TCD route A */
    register8_t ACROUTEA;  /* AC route A */
    register8_t TCFROUTEA;  /* TCF route A */
    register8_t reserved_3[2];
    register8_t ZCDROUTEA;  /* ZCD route A */
    register8_t EEXROUTEA;  /* EEX route A */
} PORTMUX_t;

/* External Break select */
typedef enum PORTMUX_EXTBRK_enum
{
    PORTMUX_EXTBRK_DEFAULT_gc = (0x00<<7),  /* Default pin */
    PORTMUX_EXTBRK_ALTERNATE_gc = (0x01<<7)  /* Alternate pin */
} PORTMUX_EXTBRK_t;

/*  */
typedef enum PORTMUX_SPI0_enum
{
    PORTMUX_SPI0_DEFAULT_gc = (0x00<<0),  /* SPI routed to default pins */
    PORTMUX_SPI0_ALT1_gc = (0x01<<0)  /* SPI routed to alternate 1 pins */
} PORTMUX_SPI0_t;

/*  */
typedef enum PORTMUX_TCE0_enum
{
    PORTMUX_TCE0_DEFAULT_gc = (0x00<<0),  /* TCE0 routed to default pins */
    PORTMUX_TCE0_ALT3_gc = (0x03<<0)  /* TCE0 routed to alternate 3 pins */
} PORTMUX_TCE0_t;

/* TCF0 Routing select */
typedef enum PORTMUX_TCF0_enum
{
    PORTMUX_TCF0_DEFAULT_gc = (0x00<<0),  /* TCF0 routed to default pins */
    PORTMUX_TCF0_ALT2_gc = (0x01<<0)  /* TCF0 routed to alternate 2 pins */
} PORTMUX_TCF0_t;

/*
--------------------------------------------------------------------------
RSTCTRL - Reset controller
--------------------------------------------------------------------------
*/

/* Reset controller */
typedef struct RSTCTRL_struct
{
    register8_t RSTFR;  /* Reset Flags */
    register8_t SWRR;  /* Software Reset */
    register8_t BOOTCTRL;  /* Internal Control */
    register8_t TEST;  /* Test Control */
} RSTCTRL_t;


/*
--------------------------------------------------------------------------
RTC - Real-Time Counter
--------------------------------------------------------------------------
*/

/* Real-Time Counter */
typedef struct RTC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t TEMP;  /* Temporary */
    register8_t DBGCTRL;  /* Debug control */
    register8_t CALIB;  /* Calibration */
    register8_t CLKSEL;  /* Clock Select */
    _WORDREGISTER(CNT);  /* Counter */
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CMP);  /* Compare */
    register8_t reserved_1[2];
    register8_t PITCTRLA;  /* PIT Control A */
    register8_t PITSTATUS;  /* PIT Status */
    register8_t PITINTCTRL;  /* PIT Interrupt Control */
    register8_t PITINTFLAGS;  /* PIT Interrupt Flags */
    register8_t reserved_2[1];
    register8_t PITDBGCTRL;  /* PIT Debug control */
    register8_t PITEVGENCTRLA;  /* PIT Event Generation Control A */
    register8_t reserved_3[9];
} RTC_t;

/* Clock Select */
typedef enum RTC_CLKSEL_enum
{
    RTC_CLKSEL_OSC32K_gc = (0x00<<0),  /* Internal 32.768 kHz Oscillator */
    RTC_CLKSEL_OSC1K_gc = (0x01<<0),  /* Internal 32.768 kHz Oscillator Divided by 32 */
    RTC_CLKSEL_XOSC32K_gc = (0x02<<0),  /* 32.768 kHz Crystal Oscillator */
    RTC_CLKSEL_EXTCLK_gc = (0x03<<0)  /* External Clock */
} RTC_CLKSEL_t;

/* Event Generation 0 Select */
typedef enum RTC_EVGEN0SEL_enum
{
    RTC_EVGEN0SEL_OFF_gc = (0x00<<0),  /* No Event Generated */
    RTC_EVGEN0SEL_DIV4_gc = (0x01<<0),  /* CLK_RTC divided by 4 */
    RTC_EVGEN0SEL_DIV8_gc = (0x02<<0),  /* CLK_RTC divided by 8 */
    RTC_EVGEN0SEL_DIV16_gc = (0x03<<0),  /* CLK_RTC divided by 16 */
    RTC_EVGEN0SEL_DIV32_gc = (0x04<<0),  /* CLK_RTC divided by 32 */
    RTC_EVGEN0SEL_DIV64_gc = (0x05<<0),  /* CLK_RTC divided by 64 */
    RTC_EVGEN0SEL_DIV128_gc = (0x06<<0),  /* CLK_RTC divided by 128 */
    RTC_EVGEN0SEL_DIV256_gc = (0x07<<0),  /* CLK_RTC divided by 256 */
    RTC_EVGEN0SEL_DIV512_gc = (0x08<<0),  /* CLK_RTC divided by 512 */
    RTC_EVGEN0SEL_DIV1024_gc = (0x09<<0),  /* CLK_RTC divided by 1024 */
    RTC_EVGEN0SEL_DIV2048_gc = (0x0A<<0),  /* CLK_RTC divided by 2048 */
    RTC_EVGEN0SEL_DIV4096_gc = (0x0B<<0),  /* CLK_RTC divided by 4096 */
    RTC_EVGEN0SEL_DIV8192_gc = (0x0C<<0),  /* CLK_RTC divided by 8192 */
    RTC_EVGEN0SEL_DIV16384_gc = (0x0D<<0),  /* CLK_RTC divided by 16384 */
    RTC_EVGEN0SEL_DIV32768_gc = (0x0E<<0)  /* CLK_RTC divided by 32768 */
} RTC_EVGEN0SEL_t;

/* Event Generation 1 Select */
typedef enum RTC_EVGEN1SEL_enum
{
    RTC_EVGEN1SEL_OFF_gc = (0x00<<4),  /* No Event Generated */
    RTC_EVGEN1SEL_DIV4_gc = (0x01<<4),  /* CLK_RTC divided by 4 */
    RTC_EVGEN1SEL_DIV8_gc = (0x02<<4),  /* CLK_RTC divided by 8 */
    RTC_EVGEN1SEL_DIV16_gc = (0x03<<4),  /* CLK_RTC divided by 16 */
    RTC_EVGEN1SEL_DIV32_gc = (0x04<<4),  /* CLK_RTC divided by 32 */
    RTC_EVGEN1SEL_DIV64_gc = (0x05<<4),  /* CLK_RTC divided by 64 */
    RTC_EVGEN1SEL_DIV128_gc = (0x06<<4),  /* CLK_RTC divided by 128 */
    RTC_EVGEN1SEL_DIV256_gc = (0x07<<4),  /* CLK_RTC divided by 256 */
    RTC_EVGEN1SEL_DIV512_gc = (0x08<<4),  /* CLK_RTC divided by 512 */
    RTC_EVGEN1SEL_DIV1024_gc = (0x09<<4),  /* CLK_RTC divided by 1024 */
    RTC_EVGEN1SEL_DIV2048_gc = (0x0A<<4),  /* CLK_RTC divided by 2048 */
    RTC_EVGEN1SEL_DIV4096_gc = (0x0B<<4),  /* CLK_RTC divided by 4096 */
    RTC_EVGEN1SEL_DIV8192_gc = (0x0C<<4),  /* CLK_RTC divided by 8192 */
    RTC_EVGEN1SEL_DIV16384_gc = (0x0D<<4),  /* CLK_RTC divided by 16384 */
    RTC_EVGEN1SEL_DIV32768_gc = (0x0E<<4)  /* CLK_RTC divided by 32768 */
} RTC_EVGEN1SEL_t;

/* Period select */
typedef enum RTC_PERIOD_enum
{
    RTC_PERIOD_OFF_gc = (0x00<<3),  /* Off */
    RTC_PERIOD_CYC4_gc = (0x01<<3),  /* RTC Clock Cycles 4 */
    RTC_PERIOD_CYC8_gc = (0x02<<3),  /* RTC Clock Cycles 8 */
    RTC_PERIOD_CYC16_gc = (0x03<<3),  /* RTC Clock Cycles 16 */
    RTC_PERIOD_CYC32_gc = (0x04<<3),  /* RTC Clock Cycles 32 */
    RTC_PERIOD_CYC64_gc = (0x05<<3),  /* RTC Clock Cycles 64 */
    RTC_PERIOD_CYC128_gc = (0x06<<3),  /* RTC Clock Cycles 128 */
    RTC_PERIOD_CYC256_gc = (0x07<<3),  /* RTC Clock Cycles 256 */
    RTC_PERIOD_CYC512_gc = (0x08<<3),  /* RTC Clock Cycles 512 */
    RTC_PERIOD_CYC1024_gc = (0x09<<3),  /* RTC Clock Cycles 1024 */
    RTC_PERIOD_CYC2048_gc = (0x0A<<3),  /* RTC Clock Cycles 2048 */
    RTC_PERIOD_CYC4096_gc = (0x0B<<3),  /* RTC Clock Cycles 4096 */
    RTC_PERIOD_CYC8192_gc = (0x0C<<3),  /* RTC Clock Cycles 8192 */
    RTC_PERIOD_CYC16384_gc = (0x0D<<3),  /* RTC Clock Cycles 16384 */
    RTC_PERIOD_CYC32768_gc = (0x0E<<3)  /* RTC Clock Cycles 32768 */
} RTC_PERIOD_t;

/* Prescaling Factor select */
typedef enum RTC_PRESCALER_enum
{
    RTC_PRESCALER_DIV1_gc = (0x00<<3),  /* RTC Clock / 1 */
    RTC_PRESCALER_DIV2_gc = (0x01<<3),  /* RTC Clock / 2 */
    RTC_PRESCALER_DIV4_gc = (0x02<<3),  /* RTC Clock / 4 */
    RTC_PRESCALER_DIV8_gc = (0x03<<3),  /* RTC Clock / 8 */
    RTC_PRESCALER_DIV16_gc = (0x04<<3),  /* RTC Clock / 16 */
    RTC_PRESCALER_DIV32_gc = (0x05<<3),  /* RTC Clock / 32 */
    RTC_PRESCALER_DIV64_gc = (0x06<<3),  /* RTC Clock / 64 */
    RTC_PRESCALER_DIV128_gc = (0x07<<3),  /* RTC Clock / 128 */
    RTC_PRESCALER_DIV256_gc = (0x08<<3),  /* RTC Clock / 256 */
    RTC_PRESCALER_DIV512_gc = (0x09<<3),  /* RTC Clock / 512 */
    RTC_PRESCALER_DIV1024_gc = (0x0A<<3),  /* RTC Clock / 1024 */
    RTC_PRESCALER_DIV2048_gc = (0x0B<<3),  /* RTC Clock / 2048 */
    RTC_PRESCALER_DIV4096_gc = (0x0C<<3),  /* RTC Clock / 4096 */
    RTC_PRESCALER_DIV8192_gc = (0x0D<<3),  /* RTC Clock / 8192 */
    RTC_PRESCALER_DIV16384_gc = (0x0E<<3),  /* RTC Clock / 16384 */
    RTC_PRESCALER_DIV32768_gc = (0x0F<<3)  /* RTC Clock / 32768 */
} RTC_PRESCALER_t;

/*
--------------------------------------------------------------------------
SIGROW - Signature row
--------------------------------------------------------------------------
*/

/* Signature row */
typedef struct SIGROW_struct
{
    register8_t DEVICEID0;  /* Device ID Byte 0 */
    register8_t DEVICEID1;  /* Device ID Byte 1 */
    register8_t DEVICEID2;  /* Device ID Byte 2 */
    register8_t reserved_1[1];
    _WORDREGISTER(TEMPSENSE0);  /* Temperature Calibration 0 */
    _WORDREGISTER(TEMPSENSE1);  /* Temperature Calibration 1 */
    register8_t reserved_2[8];
    register8_t SERNUM0;  /* LOTNUM0 */
    register8_t SERNUM1;  /* LOTNUM1 */
    register8_t SERNUM2;  /* LOTNUM2 */
    register8_t SERNUM3;  /* LOTNUM3 */
    register8_t SERNUM4;  /* LOTNUM4 */
    register8_t SERNUM5;  /* LOTNUM5 */
    register8_t SERNUM6;  /* RANDOM */
    register8_t SERNUM7;  /* SCRIBE */
    register8_t SERNUM8;  /* XPOS0 */
    register8_t SERNUM9;  /* XPOS1 */
    register8_t SERNUM10;  /* YPOS0 */
    register8_t SERNUM11;  /* YPOS1 */
    register8_t SERNUM12;  /* RES0 */
    register8_t SERNUM13;  /* RES1 */
    register8_t SERNUM14;  /* RES2 */
    register8_t SERNUM15;  /* RES3 */
    register8_t reserved_3[32];
} SIGROW_t;


/*
--------------------------------------------------------------------------
SLPCTRL - Sleep Controller
--------------------------------------------------------------------------
*/

/* Sleep Controller */
typedef struct SLPCTRL_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t VREGCTRL;  /* Control B */
    register8_t reserved_1[2];
    register8_t CALLDO;  /* Calibration VREG LDO */
    register8_t CALULP;  /* Calibration VREG ULP */
    register8_t CALBB;  /* Calibration VREG BB */
    register8_t reserved_2[1];
    register8_t TESTLDOA;  /* Test VREG LDO A */
    register8_t TESTLDOB;  /* Test VREG LDO B */
    register8_t TESTULP;  /* Test VREG ULP */
    register8_t TESTCMP;  /* Test VREG CMP */
    register8_t TESTSTATUS;  /* Test Status */
} SLPCTRL_t;

/* EOS Comparator Enable select */
typedef enum SLPCTRL_EOSCMPEN_enum
{
    SLPCTRL_EOSCMPEN_AUTO_gc = (0x00<<6),  /* EOS Comparator is enabled if EOSEN is '1' */
    SLPCTRL_EOSCMPEN_ON_gc = (0x01<<6)  /* EOS Comparator always enabled */
} SLPCTRL_EOSCMPEN_t;

/* EOS Feedback Enble select */
typedef enum SLPCTRL_EOSFBEN_enum
{
    SLPCTRL_EOSFBEN_OFF_gc = (0x00<<7),  /* EOS will not disable the regulator passgates */
    SLPCTRL_EOSFBEN_ON_gc = (0x01<<7)  /* EOS can disable the LDO and ULP regualtor passgates */
} SLPCTRL_EOSFBEN_t;

/* Fast Comaprator Reset select */
typedef enum SLPCTRL_FCMPLTRST_enum
{
    SLPCTRL_FCMPLTRST_NORMAL_gc = (0x00<<2),  /* Fast Comparator output latched out of reset */
    SLPCTRL_FCMPLTRST_RESET_gc = (0x01<<2)  /* Fast comparator output latched in reset */
} SLPCTRL_FCMPLTRST_t;

/* Fast Comparator Polarity select */
typedef enum SLPCTRL_FCMPPOL_enum
{
    SLPCTRL_FCMPPOL_ABOVE_gc = (0x00<<1),  /* Comparators detects internal voltage above test voltage */
    SLPCTRL_FCMPPOL_BELOW_gc = (0x01<<1)  /* Comparators detects internal voltage below test voltage */
} SLPCTRL_FCMPPOL_t;

/* Fast Comparator Selection */
typedef enum SLPCTRL_FCMPSEL_enum
{
    SLPCTRL_FCMPSEL_VDD18_gc = (0x00<<0),  /* LVDSC fast comparator monitors VDD 1.8V domain */
    SLPCTRL_FCMPSEL_VDDSC_gc = (0x01<<0)  /* LVDSC fast comparator monitors VDDSC */
} SLPCTRL_FCMPSEL_t;

/* LDO High-power mode select */
typedef enum SLPCTRL_HPMODE_enum
{
    SLPCTRL_HPMODE_OFF_gc = (0x00<<6),  /* LDO disabled */
    SLPCTRL_HPMODE_ON_gc = (0x01<<6),  /* LDO enabled */
    SLPCTRL_HPMODE_READY_gc = (0x02<<6)  /* LDO forced off, but ready bit indicate enable status */
} SLPCTRL_HPMODE_t;

/* High Temperature Back Bias select */
typedef enum SLPCTRL_HTBB_enum
{
    SLPCTRL_HTBB_OFF_gc = (0x00<<4),  /* Disabled */
    SLPCTRL_HTBB_ON_gc = (0x01<<4)  /* High temperature operation */
} SLPCTRL_HTBB_t;

/* Low Latency start-up from deep sleep select */
typedef enum SLPCTRL_LOWLAT_enum
{
    SLPCTRL_LOWLAT_OFF_gc = (0x00<<7),  /* Normal start-up time */
    SLPCTRL_LOWLAT_ON_gc = (0x01<<7)  /* Voltage regulator reference kept on in Standby and Powerdown for fast start-up */
} SLPCTRL_LOWLAT_t;

/* LDO Low-power mode Enable select */
typedef enum SLPCTRL_LPMODE_enum
{
    SLPCTRL_LPMODE_OFF_gc = (0x00<<4),  /* LDO disabled */
    SLPCTRL_LPMODE_ON_gc = (0x01<<4),  /* LDO enabled */
    SLPCTRL_LPMODE_READY_gc = (0x02<<4)  /* LDO forced off, but ready bit indicate enable status */
} SLPCTRL_LPMODE_t;

/* Performance Mode select */
typedef enum SLPCTRL_PMODE_enum
{
    SLPCTRL_PMODE_AUTO_gc = (0x00<<0),  /*  */
    SLPCTRL_PMODE_FULL_gc = (0x01<<0),  /*  */
    SLPCTRL_PMODE_REDUCED_gc = (0x02<<0),  /*  */
    SLPCTRL_PMODE_AUTOLF_gc = (0x03<<0)  /*  */
} SLPCTRL_PMODE_t;

/* Sleep mode select */
typedef enum SLPCTRL_SMODE_enum
{
    SLPCTRL_SMODE_IDLE_gc = (0x00<<1),  /* Idle mode */
    SLPCTRL_SMODE_STDBY_gc = (0x01<<1),  /* Standby Mode */
    SLPCTRL_SMODE_PDOWN_gc = (0x02<<1)  /* Power-down Mode */
} SLPCTRL_SMODE_t;

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_STANDBY (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
/* Regulator Switch 1 select */
typedef enum SLPCTRL_SW1EN_enum
{
    SLPCTRL_SW1EN_OFF_gc = (0x00<<6),  /* Switch is open */
    SLPCTRL_SW1EN_ON_gc = (0x01<<6)  /* Switch is connecting */
} SLPCTRL_SW1EN_t;

/* Regulator Switch 3 select */
typedef enum SLPCTRL_SW3EN_enum
{
    SLPCTRL_SW3EN_OFF_gc = (0x00<<7),  /* Switch is open */
    SLPCTRL_SW3EN_ON_gc = (0x01<<7)  /* Switch is connecting */
} SLPCTRL_SW3EN_t;

/* Tracking Detector Disable select */
typedef enum SLPCTRL_TRACKDIS_enum
{
    SLPCTRL_TRACKDIS_OFF_gc = (0x00<<3),  /* Regulator in regulation mode or tracking mode */
    SLPCTRL_TRACKDIS_ON_gc = (0x01<<3)  /* Regulator disabled in tracking mode */
} SLPCTRL_TRACKDIS_t;

/* Tracking Mode Enable select */
typedef enum SLPCTRL_TRACKEN_enum
{
    SLPCTRL_TRACKEN_OFF_gc = (0x00<<2),  /* Normal regulation */
    SLPCTRL_TRACKEN_ON_gc = (0x01<<2)  /* Tracking Mode Forced On */
} SLPCTRL_TRACKEN_t;

/* Trancient Enhancer select */
typedef enum SLPCTRL_ULPTRANS_enum
{
    SLPCTRL_ULPTRANS_ON_gc = (0x00<<3),  /* Transient Enhancer Enabled */
    SLPCTRL_ULPTRANS_OFF_gc = (0x01<<3)  /* Transient Enhancer Disabled */
} SLPCTRL_ULPTRANS_t;

/*
--------------------------------------------------------------------------
SPI - Serial Peripheral Interface
--------------------------------------------------------------------------
*/

/* Serial Peripheral Interface */
typedef struct SPI_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t DATA;  /* Data */
    register8_t reserved_1[3];
} SPI_t;

/* SPI Mode select */
typedef enum SPI_MODE_enum
{
    SPI_MODE_0_gc = (0x00<<0),  /* SPI Mode 0 */
    SPI_MODE_1_gc = (0x01<<0),  /* SPI Mode 1 */
    SPI_MODE_2_gc = (0x02<<0),  /* SPI Mode 2 */
    SPI_MODE_3_gc = (0x03<<0)  /* SPI Mode 3 */
} SPI_MODE_t;

/* Prescaler select */
typedef enum SPI_PRESC_enum
{
    SPI_PRESC_DIV4_gc = (0x00<<1),  /* System Clock / 4 */
    SPI_PRESC_DIV16_gc = (0x01<<1),  /* System Clock / 16 */
    SPI_PRESC_DIV64_gc = (0x02<<1),  /* System Clock / 64 */
    SPI_PRESC_DIV128_gc = (0x03<<1)  /* System Clock / 128 */
} SPI_PRESC_t;

/*
--------------------------------------------------------------------------
SYSCFG - System Configuration Registers
--------------------------------------------------------------------------
*/

/* System Configuration Registers */
typedef struct SYSCFG_struct
{
    register8_t ASI;  /* System Init */
    register8_t REVID;  /* Revision ID */
    register8_t EXTBRK;  /* External Break */
    register8_t reserved_1[1];
    register8_t FRESH;  /* Fresh from FAB */
    register8_t SYSCFG0;  /* System Configuration Fuse Register 0 */
    register8_t SYSCFG1;  /* System Configuration Fuse Register 1 */
    register8_t CODESIZE;  /* Code Section Size */
    register8_t BOOTSIZE;  /* Boot Section Size */
    register8_t HVDSTATUS;  /* High Voltage Detect Status */
    register8_t HVDCTRL;  /* High Voltage Detect Control */
    register8_t reserved_2[1];
    register8_t TESTCTRLA;  /* Test Control A */
    register8_t TESTCTRLB;  /* Test Control B */
    register8_t TESTCTRLC;  /* Test Control C */
    register8_t TESTCTRLD;  /* Test Control D */
    register8_t MEMSIZE0;  /* Memory size 0 */
    register8_t MEMSIZE1;  /* Memory size 1 */
    register8_t PINCNT;  /* Pin count */
    register8_t CONFIG0;  /* Configuration 0 */
    register8_t CONFIG1;  /* Configuration 1 */
    register8_t reserved_3[3];
    register8_t OCDMCTRL;  /* OCD Message Control */
    register8_t OCDMSTATUS;  /* OCD Message Status */
    register8_t reserved_4[6];
} SYSCFG_t;

/* Code execution mode select */
typedef enum SYSCFG_EXECMODE_enum
{
    SYSCFG_EXECMODE_Flash_gc = (0x00<<0),  /* Flash execution */
    SYSCFG_EXECMODE_RAM_gc = (0x01<<0),  /* RAM execution */
    SYSCFG_EXECMODE_TESTSPACE2_gc = (0x02<<0),  /* Flash test speace, 1KB. Not available on locked devices. */
    SYSCFG_EXECMODE_EPX0_gc = (0x03<<0),  /* External execution, 4 inout/pins */
    SYSCFG_EXECMODE_EPX4_gc = (0x04<<0),  /* External execution, 4 input, 4 output */
    SYSCFG_EXECMODE_EPX8_gc = (0x05<<0),  /* External execution, 4 input, 8 output */
    SYSCFG_EXECMODE_EPX8D_gc = (0x06<<0),  /* External execution, 8 input/output */
    SYSCFG_EXECMODE_ESX_gc = (0x07<<0)  /* External execution, serial */
} SYSCFG_EXECMODE_t;

/*
--------------------------------------------------------------------------
TCB - 16-bit Timer/Counter Type B
--------------------------------------------------------------------------
*/

/* 16-bit Timer/Counter Type B */
typedef struct TCB_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t reserved_1[1];
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t TEMP;  /* Temporary Value */
    _WORDREGISTER(CNT);  /* Count */
    _WORDREGISTER(CCMP);  /* Compare or Capture */
    register8_t reserved_2[2];
} TCB_t;

/* Clock Select */
typedef enum TCB_CLKSEL_enum
{
    TCB_CLKSEL_DIV1_gc = (0x00<<1),  /* CLK_PER */
    TCB_CLKSEL_DIV2_gc = (0x01<<1),  /* CLK_PER/2 */
    TCB_CLKSEL_TCE0_gc = (0x02<<1),  /* Use CLK_TCE from TCE0 */
    TCB_CLKSEL_EVENT_gc = (0x07<<1)  /* Count on event edge */
} TCB_CLKSEL_t;

/* Timer Mode select */
typedef enum TCB_CNTMODE_enum
{
    TCB_CNTMODE_INT_gc = (0x00<<0),  /* Periodic Interrupt */
    TCB_CNTMODE_TIMEOUT_gc = (0x01<<0),  /* Periodic Timeout */
    TCB_CNTMODE_CAPT_gc = (0x02<<0),  /* Input Capture Event */
    TCB_CNTMODE_FRQ_gc = (0x03<<0),  /* Input Capture Frequency measurement */
    TCB_CNTMODE_PW_gc = (0x04<<0),  /* Input Capture Pulse-Width measurement */
    TCB_CNTMODE_FRQPW_gc = (0x05<<0),  /* Input Capture Frequency and Pulse-Width measurement */
    TCB_CNTMODE_SINGLE_gc = (0x06<<0),  /* Single Shot */
    TCB_CNTMODE_PWM8_gc = (0x07<<0)  /* 8-bit PWM */
} TCB_CNTMODE_t;

/* Counter Size select */
typedef enum TCB_CNTSIZE_enum
{
    TCB_CNTSIZE_16BITS_gc = (0x00<<0),  /* 16-bit CNT. MAX=16'hFFFF */
    TCB_CNTSIZE_15BITS_gc = (0x01<<0),  /* 15-bit CNT. MAX=16'h7FFF */
    TCB_CNTSIZE_14BITS_gc = (0x02<<0),  /* 14-bit CNT. MAX=16'h3FFF */
    TCB_CNTSIZE_13BITS_gc = (0x03<<0),  /* 13-bit CNT. MAX=16'h1FFF */
    TCB_CNTSIZE_12BITS_gc = (0x04<<0),  /* 12-bit CNT. MAX=16'h0FFF */
    TCB_CNTSIZE_11BITS_gc = (0x05<<0),  /* 11-bit CNT. MAX=16'h07FF */
    TCB_CNTSIZE_10BITS_gc = (0x06<<0),  /* 10-bit CNT. MAX=16'h03FF */
    TCB_CNTSIZE_9BITS_gc = (0x07<<0)  /* 9-bit CNT. MAX=16'h01FF */
} TCB_CNTSIZE_t;

/* Event Generation select */
typedef enum TCB_EVGEN_enum
{
    TCB_EVGEN_PULSE_gc = (0x00<<7),  /* Event is generated as pulse at compare match or capture */
    TCB_EVGEN_WAVEFORM_gc = (0x01<<7)  /* Event is generated as waveform for modes with waveform */
} TCB_EVGEN_t;

/*
--------------------------------------------------------------------------
TCE - 16-bit Timer/Counter Type E
--------------------------------------------------------------------------
*/

/* 16-bit Timer/Counter Type E */
typedef struct TCE_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLECLR;  /* Control E Clear */
    register8_t CTRLESET;  /* Control E Set */
    register8_t CTRLFCLR;  /* Control F Clear */
    register8_t CTRLFSET;  /* Control F Set */
    register8_t EVGENCTRL;  /* Event Generation Control */
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_1[2];
    register8_t DBGCTRL;  /* Debug Control */
    register8_t TEMP;  /* Temporary data for 16-bit Access */
    register8_t reserved_2[16];
    _WORDREGISTER(CNT);  /* Count */
    _WORDREGISTER(AMP);  /* Amplitude */
    _WORDREGISTER(OFFSET);  /* Offset */
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CMP0);  /* Compare 0 */
    _WORDREGISTER(CMP1);  /* Compare 1 */
    _WORDREGISTER(CMP2);  /* Compare 2 */
    _WORDREGISTER(CMP3);  /* Compare 3 */
    register8_t reserved_3[6];
    _WORDREGISTER(PERBUF);  /* Period Buffer */
    _WORDREGISTER(CMP0BUF);  /* Compare 0 Buffer */
    _WORDREGISTER(CMP1BUF);  /* Compare 1 Buffer */
    _WORDREGISTER(CMP2BUF);  /* Compare 2 Buffer */
    _WORDREGISTER(CMP3BUF);  /* Compare 3 Buffer */
} TCE_t;

/* Clock Selection */
typedef enum TCE_CLKSEL_enum
{
    TCE_CLKSEL_DIV1_gc = (0x00<<1),  /* System Clock */
    TCE_CLKSEL_DIV2_gc = (0x01<<1),  /* System Clock / 2 */
    TCE_CLKSEL_DIV4_gc = (0x02<<1),  /* System Clock / 4 */
    TCE_CLKSEL_DIV8_gc = (0x03<<1),  /* System Clock / 8 */
    TCE_CLKSEL_DIV16_gc = (0x04<<1),  /* System Clock / 16 */
    TCE_CLKSEL_DIV64_gc = (0x05<<1),  /* System Clock / 64 */
    TCE_CLKSEL_DIV256_gc = (0x06<<1),  /* System Clock / 256 */
    TCE_CLKSEL_DIV1024_gc = (0x07<<1)  /* System Clock / 1024 */
} TCE_CLKSEL_t;

/* Command select */
typedef enum TCE_CMD_enum
{
    TCE_CMD_NONE_gc = (0x00<<2),  /* No Command */
    TCE_CMD_UPDATE_gc = (0x01<<2),  /* Force Update */
    TCE_CMD_RESTART_gc = (0x02<<2),  /* Force Restart */
    TCE_CMD_RESET_gc = (0x03<<2)  /* Force Hard Reset */
} TCE_CMD_t;

/* Compare # Event select */
typedef enum TCE_CMP0EV_enum
{
    TCE_CMP0EV_PULSE_gc = (0x00<<4),  /* Event output for CMP is a pulse */
    TCE_CMP0EV_WO_gc = (0x01<<4)  /* Event output for CMP is equal to waveform */
} TCE_CMP0EV_t;

/* Compare # Event select */
typedef enum TCE_CMP1EV_enum
{
    TCE_CMP1EV_PULSE_gc = (0x00<<5),  /* Event output for CMP is a pulse */
    TCE_CMP1EV_WO_gc = (0x01<<5)  /* Event output for CMP is equal to waveform */
} TCE_CMP1EV_t;

/* Compare # Event select */
typedef enum TCE_CMP2EV_enum
{
    TCE_CMP2EV_PULSE_gc = (0x00<<6),  /* Event output for CMP is a pulse */
    TCE_CMP2EV_WO_gc = (0x01<<6)  /* Event output for CMP is equal to waveform */
} TCE_CMP2EV_t;

/* Compare # Event select */
typedef enum TCE_CMP3EV_enum
{
    TCE_CMP3EV_PULSE_gc = (0x00<<7),  /* Event output for CMP is a pulse */
    TCE_CMP3EV_WO_gc = (0x01<<7)  /* Event output for CMP is equal to waveform */
} TCE_CMP3EV_t;

/* Direction select */
typedef enum TCE_DIR_enum
{
    TCE_DIR_UP_gc = (0x00<<0),  /* Count up */
    TCE_DIR_DOWN_gc = (0x01<<0)  /* Count down */
} TCE_DIR_t;

/* Event Action A select */
typedef enum TCE_EVACTA_enum
{
    TCE_EVACTA_CNT_POSEDGE_gc = (0x00<<1),  /* Count on positive edge event */
    TCE_EVACTA_CNT_ANYEDGE_gc = (0x01<<1),  /* Count on any edge event */
    TCE_EVACTA_CNT_HIGHLVL_gc = (0x02<<1),  /* Count on prescaled clock while event line is 1. */
    TCE_EVACTA_UPDOWN_gc = (0x03<<1)  /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
} TCE_EVACTA_t;

/* Event Action B select */
typedef enum TCE_EVACTB_enum
{
    TCE_EVACTB_NONE_gc = (0x00<<5),  /* No Action */
    TCE_EVACTB_UPDOWN_gc = (0x03<<5),  /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
    TCE_EVACTB_RESTART_POSEDGE_gc = (0x04<<5),  /* Restart counter at positive edge event */
    TCE_EVACTB_RESTART_ANYEDGE_gc = (0x05<<5),  /* Restart counter on any edge event */
    TCE_EVACTB_RESTART_HIGHLVL_gc = (0x06<<5)  /* Restart counter while event line is 1. */
} TCE_EVACTB_t;

/* High Resolution Enable select */
typedef enum TCE_HREN_enum
{
    TCE_HREN_OFF_gc = (0x00<<6),  /* High Resolution Disable */
    TCE_HREN_4X_gc = (0x01<<6),  /* Resolution increased by 4 (2 bits) */
    TCE_HREN_8X_gc = (0x02<<6)  /* Resolution increased by 4 (3 bits) */
} TCE_HREN_t;

/* Scaled Write select */
typedef enum TCE_SCALE_enum
{
    TCE_SCALE_NORMAL_gc = (0x00<<2),  /* Absolute values used when writing to CMPn, CMPnBUF and registers */
    TCE_SCALE_FRACTIONAL_gc = (0x01<<2)  /* Fractional values used when writing to CMPn, CMPnBUF and registers */
} TCE_SCALE_t;

/* Scaling Mode select */
typedef enum TCE_SCALEMODE_enum
{
    TCE_SCALEMODE_CENTER_gc = (0x00<<4),  /* CMPn registers scaled vs center (50% duty cycle) */
    TCE_SCALEMODE_BOTTOM_gc = (0x01<<4),  /* CMPn registers scaled vs BOTTOM (0% duty cycle) */
    TCE_SCALEMODE_TOP_gc = (0x02<<4),  /* CMPn registers scaled vs TOP (100% duty cycle) */
    TCE_SCALEMODE_TOPBOTTOM_gc = (0x03<<4)  /* CMPn registers scaled vs TOP or BOTTOM depending on written value. */
} TCE_SCALEMODE_t;

/* Waveform generation mode select */
typedef enum TCE_WGMODE_enum
{
    TCE_WGMODE_NORMAL_gc = (0x00<<0),  /* Normal Mode */
    TCE_WGMODE_FRQ_gc = (0x01<<0),  /* Frequency Generation Mode */
    TCE_WGMODE_SINGLESLOPE_gc = (0x03<<0),  /* Single Slope PWM */
    TCE_WGMODE_DSTOP_gc = (0x05<<0),  /* Dual Slope PWM, overflow on TOP */
    TCE_WGMODE_DSBOTH_gc = (0x06<<0),  /* Dual Slope PWM, overflow on TOP and BOTTOM */
    TCE_WGMODE_DSBOTTOM_gc = (0x07<<0)  /* Dual Slope PWM, overflow on BOTTOM */
} TCE_WGMODE_t;

/*
--------------------------------------------------------------------------
TCF - 24-bit Timer/Counter for frequency generation
--------------------------------------------------------------------------
*/

/* 24-bit Timer/Counter for frequency generation */
typedef struct TCF_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t reserved_1[5];
    register8_t DBGCTRL;  /* Debug Control */
    register8_t reserved_2[2];
    _DWORDREGISTER(CNT);  /* Count */
    _DWORDREGISTER(CMP);  /* Compare */
    register8_t reserved_3[8];
} TCF_t;

/* Clock Select */
typedef enum TCF_CLKSEL_enum
{
    TCF_CLKSEL_CLKPER_gc = (0x00<<3),  /* Peripheral Clock */
    TCF_CLKSEL_EVENT_gc = (0x01<<3),  /* Event as clock source */
    TCF_CLKSEL_OSCHF_gc = (0x02<<3),  /* Internal High Frequency Oscillator */
    TCF_CLKSEL_OSC32K_gc = (0x03<<3),  /* Internal 32.768 kHz Oscillator */
    TCF_CLKSEL_PLL_gc = (0x04<<3),  /* PLL */
    TCF_CLKSEL_OSCBOOT_gc = (0x07<<3)  /* Boot Oscillator */
} TCF_CLKSEL_t;

/* Command select */
typedef enum TCF_CMD_enum
{
    TCF_CMD_NONE_gc = (0x00<<0),  /* No command */
    TCF_CMD_UPDATE_gc = (0x01<<0),  /* Force update */
    TCF_CMD_RESTART_gc = (0x02<<0)  /* Force restart */
} TCF_CMD_t;

/* Compare # Event Generation select */
typedef enum TCF_CMP0EV_enum
{
    TCF_CMP0EV_PULSE_gc = (0x00<<6),  /* Event is generated as pulse */
    TCF_CMP0EV_WAVEFORM_gc = (0x01<<6)  /* Waveform is used as event output */
} TCF_CMP0EV_t;

/* Compare # Event Generation select */
typedef enum TCF_CMP1EV_enum
{
    TCF_CMP1EV_PULSE_gc = (0x00<<7),  /* Event is generated as pulse */
    TCF_CMP1EV_WAVEFORM_gc = (0x01<<7)  /* Waveform is used as event output */
} TCF_CMP1EV_t;

/* Event Action A select */
typedef enum TCF_EVACTA_enum
{
    TCF_EVACTA_RESTART_gc = (0x00<<1),  /* Restart Counter */
    TCF_EVACTA_BLANK_gc = (0x01<<1)  /* Mask waveform output to '0' */
} TCF_EVACTA_t;

/* Clock Prescaler select */
typedef enum TCF_PRESC_enum
{
    TCF_PRESC_DIV1_gc = (0x00<<1),  /* Runs directly on Clock Source */
    TCF_PRESC_DIV2_gc = (0x01<<1),  /* Divide clock source by 2 */
    TCF_PRESC_DIV4_gc = (0x02<<1),  /* Divide clock source by 4 */
    TCF_PRESC_DIV8_gc = (0x03<<1),  /* Divide clock source by 8 */
    TCF_PRESC_DIV16_gc = (0x04<<1),  /* Divide clock source by 16 */
    TCF_PRESC_DIV32_gc = (0x05<<1),  /* Divide clock source by 32 */
    TCF_PRESC_DIV64_gc = (0x06<<1),  /* Divide clock source by 64 */
    TCF_PRESC_DIV128_gc = (0x07<<1)  /* Divide clock source by 128 */
} TCF_PRESC_t;

/* Waveform Generation Mode select */
typedef enum TCF_WGMODE_enum
{
    TCF_WGMODE_FRQ_gc = (0x00<<0),  /* Frequency */
    TCF_WGMODE_NCOPF_gc = (0x01<<0),  /* Numerically Controlled Oscillator Pulse-Frequency */
    TCF_WGMODE_NCOFDC_gc = (0x02<<0),  /* Numerically Controlled Oscillator Fixed Duty Cycle */
    TCF_WGMODE_PWM8_gc = (0x07<<0)  /* 8-bit PWM */
} TCF_WGMODE_t;

/* Waveform Generation Pulse Length select */
typedef enum TCF_WGPULSE_enum
{
    TCF_WGPULSE_CLK1_gc = (0x00<<4),  /* High pulse duration is 1 clock period */
    TCF_WGPULSE_CLK2_gc = (0x01<<4),  /* High pulse duration is 2 clock period */
    TCF_WGPULSE_CLK4_gc = (0x02<<4),  /* High pulse duration is 4 clock period */
    TCF_WGPULSE_CLK8_gc = (0x03<<4),  /* High pulse duration is 8 clock period */
    TCF_WGPULSE_CLK16_gc = (0x04<<4),  /* High pulse duration is 16 clock period */
    TCF_WGPULSE_CLK32_gc = (0x05<<4),  /* High pulse duration is 32 clock period */
    TCF_WGPULSE_CLK64_gc = (0x06<<4),  /* High pulse duration is 64 clock period */
    TCF_WGPULSE_CLK128_gc = (0x07<<4)  /* High pulse duration is 128 clock period */
} TCF_WGPULSE_t;

/* Waveform Output # Polarity select */
typedef enum TCF_WO0POL_enum
{
    TCF_WO0POL_NORMAL_gc = (0x00<<2),  /* Waveform output set on update and cleared on match */
    TCF_WO0POL_INVERSE_gc = (0x01<<2)  /* Waveform output cleared on update and set on match */
} TCF_WO0POL_t;

/* Waveform Output # Polarity select */
typedef enum TCF_WO1POL_enum
{
    TCF_WO1POL_NORMAL_gc = (0x00<<3),  /* Waveform output set on update and cleared on match */
    TCF_WO1POL_INVERSE_gc = (0x01<<3)  /* Waveform output cleared on update and set on match */
} TCF_WO1POL_t;

/*
--------------------------------------------------------------------------
TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

/* Two-Wire Interface */
typedef struct TWI_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t reserved_1[1];
    register8_t DBGCTRL;  /* Debug Control */
    register8_t MCTRLA;  /* Host Control A */
    register8_t MCTRLB;  /* Host Control B */
    register8_t MSTATUS;  /* Host STATUS */
    register8_t MBAUD;  /* Host Baud Rate */
    register8_t MADDR;  /* Host Address */
    register8_t MDATA;  /* Host Data */
    register8_t SCTRLA;  /* Client Control A */
    register8_t SCTRLB;  /* Client Control B */
    register8_t SSTATUS;  /* Client Status */
    register8_t SADDR;  /* Client Address */
    register8_t SDATA;  /* Client Data */
    register8_t SADDRMASK;  /* Client Address Mask */
    register8_t TESTCTRL;  /* Test Control */
} TWI_t;

/* Acknowledge Action select */
typedef enum TWI_ACKACT_enum
{
    TWI_ACKACT_ACK_gc = (0x00<<2),  /* Send ACK */
    TWI_ACKACT_NACK_gc = (0x01<<2)  /* Send NACK */
} TWI_ACKACT_t;

/* Address or Stop select */
typedef enum TWI_AP_enum
{
    TWI_AP_STOP_gc = (0x00<<0),  /* A Stop condition generated the interrupt on APIF flag */
    TWI_AP_ADR_gc = (0x01<<0)  /* Address detection generated the interrupt on APIF flag */
} TWI_AP_t;

/* Bus State select */
typedef enum TWI_BUSSTATE_enum
{
    TWI_BUSSTATE_UNKNOWN_gc = (0x00<<0),  /* Unknown bus state */
    TWI_BUSSTATE_IDLE_gc = (0x01<<0),  /* Bus is idle */
    TWI_BUSSTATE_OWNER_gc = (0x02<<0),  /* This TWI controls the bus */
    TWI_BUSSTATE_BUSY_gc = (0x03<<0)  /* The bus is busy */
} TWI_BUSSTATE_t;

/* Debug Run select */
typedef enum TWI_DBGRUN_enum
{
    TWI_DBGRUN_HALT_gc = (0x00<<0),  /* The peripheral is halted in Break Debug mode and ignores events */
    TWI_DBGRUN_RUN_gc = (0x01<<0)  /* The peripheral will continue to run in Break Debug mode when the CPU is halted */
} TWI_DBGRUN_t;

/* Fast-mode Plus Enable select */
typedef enum TWI_FMPEN_enum
{
    TWI_FMPEN_OFF_gc = (0x00<<1),  /* Operating in Standard-mode or Fast-mode */
    TWI_FMPEN_ON_gc = (0x01<<1)  /* Operating in Fast-mode Plus */
} TWI_FMPEN_t;

/* Input voltage transition level select */
typedef enum TWI_INPUTLVL_enum
{
    TWI_INPUTLVL_I2C_gc = (0x00<<6),  /* I2C input voltage transition level */
    TWI_INPUTLVL_SMBUS_gc = (0x01<<6)  /* SMBus 3.0 input voltage transition level */
} TWI_INPUTLVL_t;

/* Command select */
typedef enum TWI_MCMD_enum
{
    TWI_MCMD_NOACT_gc = (0x00<<0),  /* No action */
    TWI_MCMD_REPSTART_gc = (0x01<<0),  /* Execute Acknowledge Action followed by repeated Start. */
    TWI_MCMD_RECVTRANS_gc = (0x02<<0),  /* Execute Acknowledge Action followed by a byte read/write operation. Read/write is defined by DIR. */
    TWI_MCMD_STOP_gc = (0x03<<0)  /* Execute Acknowledge Action followed by issuing a Stop condition. */
} TWI_MCMD_t;

/* SCL Duty Cycle Adjustment select */
typedef enum TWI_SCLDUTY_enum
{
    TWI_SCLDUTY_ZERO_gc = (0x00<<0),  /* No adjustment. Duty cycle default */
    TWI_SCLDUTY_PLUS1_gc = (0x01<<0),  /* SCL Low time increased and High time reduced by one clock cycle */
    TWI_SCLDUTY_PLUS2_gc = (0x02<<0),  /* SCL Low time increased and High time reduced by two clock cycles */
    TWI_SCLDUTY_PLUS3_gc = (0x03<<0),  /* SCL Low time increased and High time reduced by three clock cycles */
    TWI_SCLDUTY_PLUS4_gc = (0x04<<0),  /* SCL Low time increased and High time reduced by four clock cycles */
    TWI_SCLDUTY_PLUS5_gc = (0x05<<0),  /* SCL Low time increased and High time reduced by five clock cycles */
    TWI_SCLDUTY_PLUS6_gc = (0x06<<0),  /* SCL Low time increased and High time reduced by six clock cycles */
    TWI_SCLDUTY_PLUS7_gc = (0x07<<0)  /* SCL Low time increased and High time reduced by seven clock cycles */
} TWI_SCLDUTY_t;

/* Command select */
typedef enum TWI_SCMD_enum
{
    TWI_SCMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_SCMD_COMPTRANS_gc = (0x02<<0),  /* Complete transaction */
    TWI_SCMD_RESPONSE_gc = (0x03<<0)  /* Used in response to an interrupt */
} TWI_SCMD_t;

/* SDA Hold Time select */
typedef enum TWI_SDAHOLD_enum
{
    TWI_SDAHOLD_OFF_gc = (0x00<<2),  /* No SDA Hold Delay */
    TWI_SDAHOLD_50NS_gc = (0x01<<2),  /* Short SDA hold time */
    TWI_SDAHOLD_300NS_gc = (0x02<<2),  /* Meets SMBUS 2.0 specification under typical conditions */
    TWI_SDAHOLD_500NS_gc = (0x03<<2)  /* Meets SMBUS 2.0 specificaiton across all corners */
} TWI_SDAHOLD_t;

/* SDA Setup Time select */
typedef enum TWI_SDASETUP_enum
{
    TWI_SDASETUP_4CYC_gc = (0x00<<4),  /* SDA setup time is four clock cycles */
    TWI_SDASETUP_8CYC_gc = (0x01<<4)  /* SDA setup time is eight clock cycle */
} TWI_SDASETUP_t;

/* Inactive Bus Time-Out select */
typedef enum TWI_TIMEOUT_enum
{
    TWI_TIMEOUT_DISABLED_gc = (0x00<<2),  /* Bus time-out disabled. I2C. */
    TWI_TIMEOUT_50US_gc = (0x01<<2),  /* 50us - SMBus */
    TWI_TIMEOUT_100US_gc = (0x02<<2),  /* 100us */
    TWI_TIMEOUT_200US_gc = (0x03<<2)  /* 200us */
} TWI_TIMEOUT_t;

/*
--------------------------------------------------------------------------
USART - Universal Synchronous and Asynchronous Receiver and Transmitter
--------------------------------------------------------------------------
*/

/* Universal Synchronous and Asynchronous Receiver and Transmitter */
typedef struct USART_struct
{
    register8_t RXDATAL;  /* Receive Data Low Byte */
    register8_t RXDATAH;  /* Receive Data High Byte */
    register8_t TXDATAL;  /* Transmit Data Low Byte */
    register8_t TXDATAH;  /* Transmit Data High Byte */
    register8_t STATUS;  /* Status */
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    _WORDREGISTER(BAUD);  /* Baud Rate */
    register8_t CTRLD;  /* Control D */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t EVCTRL;  /* Event Control */
    register8_t TXPLCTRL;  /* IRCOM Transmitter Pulse Length Control */
    register8_t RXPLCTRL;  /* IRCOM Receiver Pulse Length Control */
    register8_t reserved_1[1];
} USART_t;

/* Auto Baud Window select */
typedef enum USART_ABW_enum
{
    USART_ABW_WDW0_gc = (0x00<<6),  /* 18% tolerance */
    USART_ABW_WDW1_gc = (0x01<<6),  /* 15% tolerance */
    USART_ABW_WDW2_gc = (0x02<<6),  /* 21% tolerance */
    USART_ABW_WDW3_gc = (0x03<<6)  /* 25% tolerance */
} USART_ABW_t;

/* Character Size select */
typedef enum USART_CHSIZE_enum
{
    USART_CHSIZE_5BIT_gc = (0x00<<0),  /* Character size: 5 bit */
    USART_CHSIZE_6BIT_gc = (0x01<<0),  /* Character size: 6 bit */
    USART_CHSIZE_7BIT_gc = (0x02<<0),  /* Character size: 7 bit */
    USART_CHSIZE_8BIT_gc = (0x03<<0),  /* Character size: 8 bit */
    USART_CHSIZE_9BITL_gc = (0x06<<0),  /* Character size: 9 bit read low byte first */
    USART_CHSIZE_9BITH_gc = (0x07<<0)  /* Character size: 9 bit read high byte first */
} USART_CHSIZE_t;

/* Communication Mode select */
typedef enum USART_CMODE_enum
{
    USART_CMODE_ASYNCHRONOUS_gc = (0x00<<6),  /* Asynchronous Mode */
    USART_CMODE_SYNCHRONOUS_gc = (0x01<<6),  /* Synchronous Mode */
    USART_CMODE_IRCOM_gc = (0x02<<6),  /* Infrared Communication */
    USART_CMODE_MSPI_gc = (0x03<<6)  /* SPI Host Mode */
} USART_CMODE_t;

/* Parity Mode select */
typedef enum USART_PMODE_enum
{
    USART_PMODE_DISABLED_gc = (0x00<<4),  /* No Parity */
    USART_PMODE_EVEN_gc = (0x02<<4),  /* Even Parity */
    USART_PMODE_ODD_gc = (0x03<<4)  /* Odd Parity */
} USART_PMODE_t;

/* RS485 Mode internal transmitter select */
typedef enum USART_RS485_enum
{
    USART_RS485_DISABLE_gc = (0x00<<0),  /* RS485 Mode disabled */
    USART_RS485_ENABLE_gc = (0x01<<0)  /* RS485 Mode enabled */
} USART_RS485_t;

/* Receiver Mode select */
typedef enum USART_RXMODE_enum
{
    USART_RXMODE_NORMAL_gc = (0x00<<1),  /* Normal mode */
    USART_RXMODE_CLK2X_gc = (0x01<<1),  /* CLK2x mode */
    USART_RXMODE_GENAUTO_gc = (0x02<<1),  /* Generic autobaud mode */
    USART_RXMODE_LINAUTO_gc = (0x03<<1)  /* LIN constrained autobaud mode */
} USART_RXMODE_t;

/* Stop Bit Mode select */
typedef enum USART_SBMODE_enum
{
    USART_SBMODE_1BIT_gc = (0x00<<3),  /* 1 stop bit */
    USART_SBMODE_2BIT_gc = (0x01<<3)  /* 2 stop bits */
} USART_SBMODE_t;

/*
--------------------------------------------------------------------------
USERROW - User Row
--------------------------------------------------------------------------
*/

/* User Row */
typedef struct USERROW_struct
{
    register8_t USERROW[64];  /* User Row */
} USERROW_t;


/*
--------------------------------------------------------------------------
VPORT - Virtual Ports
--------------------------------------------------------------------------
*/

/* Virtual Ports */
typedef struct VPORT_struct
{
    register8_t DIR;  /* Data Direction */
    register8_t OUT;  /* Output Value */
    register8_t IN;  /* Input Value */
    register8_t INTFLAGS;  /* Interrupt Flags */
} VPORT_t;


/*
--------------------------------------------------------------------------
WDT - Watch-Dog Timer
--------------------------------------------------------------------------
*/

/* Watch-Dog Timer */
typedef struct WDT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
} WDT_t;

/* Period select */
typedef enum WDT_PERIOD_enum
{
    WDT_PERIOD_OFF_gc = (0x00<<0),  /* Off */
    WDT_PERIOD_8CLK_gc = (0x01<<0),  /* 8 cycles (8ms) */
    WDT_PERIOD_16CLK_gc = (0x02<<0),  /* 16 cycles (16ms) */
    WDT_PERIOD_32CLK_gc = (0x03<<0),  /* 32 cycles (32ms) */
    WDT_PERIOD_64CLK_gc = (0x04<<0),  /* 64 cycles (64ms) */
    WDT_PERIOD_128CLK_gc = (0x05<<0),  /* 128 cycles (0.128s) */
    WDT_PERIOD_256CLK_gc = (0x06<<0),  /* 256 cycles (0.256s) */
    WDT_PERIOD_512CLK_gc = (0x07<<0),  /* 512 cycles (0.512s) */
    WDT_PERIOD_1KCLK_gc = (0x08<<0),  /* 1K cycles (1.0s) */
    WDT_PERIOD_2KCLK_gc = (0x09<<0),  /* 2K cycles (2.0s) */
    WDT_PERIOD_4KCLK_gc = (0x0A<<0),  /* 4K cycles (4.1s) */
    WDT_PERIOD_8KCLK_gc = (0x0B<<0)  /* 8K cycles (8.2s) */
} WDT_PERIOD_t;

/* Window select */
typedef enum WDT_WINDOW_enum
{
    WDT_WINDOW_OFF_gc = (0x00<<4),  /* Off */
    WDT_WINDOW_8CLK_gc = (0x01<<4),  /* 8 cycles (8ms) */
    WDT_WINDOW_16CLK_gc = (0x02<<4),  /* 16 cycles (16ms) */
    WDT_WINDOW_32CLK_gc = (0x03<<4),  /* 32 cycles (32ms) */
    WDT_WINDOW_64CLK_gc = (0x04<<4),  /* 64 cycles (64ms) */
    WDT_WINDOW_128CLK_gc = (0x05<<4),  /* 128 cycles (0.128s) */
    WDT_WINDOW_256CLK_gc = (0x06<<4),  /* 256 cycles (0.256s) */
    WDT_WINDOW_512CLK_gc = (0x07<<4),  /* 512 cycles (0.512s) */
    WDT_WINDOW_1KCLK_gc = (0x08<<4),  /* 1K cycles (1.0s) */
    WDT_WINDOW_2KCLK_gc = (0x09<<4),  /* 2K cycles (2.0s) */
    WDT_WINDOW_4KCLK_gc = (0x0A<<4),  /* 4K cycles (4.1s) */
    WDT_WINDOW_8KCLK_gc = (0x0B<<4)  /* 8K cycles (8.2s) */
} WDT_WINDOW_t;

/*
--------------------------------------------------------------------------
WEX - Waveform Extension
--------------------------------------------------------------------------
*/

/* Waveform Extension */
typedef struct WEX_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t reserved_1[1];
    register8_t EVCTRLA;  /* Event Control A */
    register8_t EVCTRLB;  /* Event Control B */
    register8_t EVCTRLC;  /* Event Control C */
    register8_t BUFCTRL;  /* Buffer Valid Control */
    register8_t BLANKCTRL;  /* Blanking Control */
    register8_t BLANKTIME;  /* Blanking Time */
    register8_t FAULTCTRL;  /* Fault Control */
    register8_t FAULTDRV;  /* Fault Drive */
    register8_t FAULTOUT;  /* Fault Output */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t DTLS;  /* Dead-time Low Side */
    register8_t DTHS;  /* Dead-time High Side */
    register8_t DTBOTH;  /* Dead-time Both Sides */
    register8_t SWAP;  /* DTI Swap */
    register8_t PGMOVR;  /* Pattern Generation Override */
    register8_t PGMOUT;  /* Pattern Generation Output */
    register8_t reserved_2[1];
    register8_t OUTOVEN;  /* Output Override Enable */
    register8_t DTLSBUF;  /* Dead-time Low Side Buffer */
    register8_t DTHSBUF;  /* Dead-time High Side Buffer */
    register8_t DTBOTHBUF;  /* Dead-time Both Sides Buffer */
    register8_t SWAPBUF;  /* DTI Swap Buffer */
    register8_t PGMOVRBUF;  /* Pattern Generation Override Buffer */
    register8_t PGMOUTBUF;  /* Pattern Generation Output Buffer */
    register8_t reserved_3[2];
} WEX_t;

/* Blanking Prescaler select */
typedef enum WEX_BLANKPRESC_enum
{
    WEX_BLANKPRESC_DIV1_gc = (0x00<<5),  /* No prescaling */
    WEX_BLANKPRESC_DIV4_gc = (0x01<<5),  /* Divide CLK_PER by 4 */
    WEX_BLANKPRESC_DIV16_gc = (0x02<<5),  /* Divide CLK_PER by 16 */
    WEX_BLANKPRESC_DIV64_gc = (0x03<<5)  /* Divide CLK_PER by 64 */
} WEX_BLANKPRESC_t;

/* Blanking Trigger Source select */
typedef enum WEX_BLANKSRC_enum
{
    WEX_BLANKSRC_TCE0_gc = (0x00<<0)  /* TCE0 */
} WEX_BLANKSRC_t;

/* Blanking State select */
typedef enum WEX_BLANKSTATE_enum
{
    WEX_BLANKSTATE_OFF_gc = (0x00<<7),  /* Blanking off */
    WEX_BLANKSTATE_ON_gc = (0x01<<7)  /* Blanking active */
} WEX_BLANKSTATE_t;

/* Blanking Trigger select */
typedef enum WEX_BLANKTRIG_enum
{
    WEX_BLANKTRIG_NONE_gc = (0x00<<2),  /* No HW blanking trigger. SW blanking only */
    WEX_BLANKTRIG_UPDATE_gc = (0x01<<2),  /* T/C Update Condition */
    WEX_BLANKTRIG_CMP0_gc = (0x02<<2),  /* Compare Match 0 */
    WEX_BLANKTRIG_CMP1_gc = (0x03<<2),  /* Compare Match 1 */
    WEX_BLANKTRIG_CMP2_gc = (0x04<<2),  /* Compare Match 2 */
    WEX_BLANKTRIG_CMP3_gc = (0x05<<2)  /* Compare Match 3 */
} WEX_BLANKTRIG_t;

/* Command select */
typedef enum WEX_CMD_enum
{
    WEX_CMD_NONE_gc = (0x00<<0),  /* No Command */
    WEX_CMD_UPDATE_gc = (0x01<<0),  /* Force update of Dead-time, SWAP and PGM buffer registers. */
    WEX_CMD_FAULTSET_gc = (0x02<<0),  /* Set Fault Detection */
    WEX_CMD_FAULTCLR_gc = (0x03<<0),  /* Clear Fault Detection. */
    WEX_CMD_BLANKSET_gc = (0x04<<0),  /* Set SW Blanking */
    WEX_CMD_BLANKCLR_gc = (0x05<<0)  /* Clear SW Blanking */
} WEX_CMD_t;

/* Fault Detection Action select */
typedef enum WEX_FDACT_enum
{
    WEX_FDACT_NONE_gc = (0x00<<0),  /* None. Fault Protection Disabled */
    WEX_FDACT_LOW_gc = (0x01<<0),  /* Drive all pins low */
    WEX_FDACT_CUSTOM_gc = (0x03<<0)  /* Drive all pins to setting defined by FAULTDRV and FAULTVAL */
} WEX_FDACT_t;

/* Fault Detection on Debug Break Detection select */
typedef enum WEX_FDDBD_enum
{
    WEX_FDDBD_FAULT_gc = (0x00<<7),  /* OCD Break request is treated as a fault if fault protection is enabled */
    WEX_FDDBD_IGNORE_gc = (0x01<<7)  /* OCD Breask request will not trigger a fault */
} WEX_FDDBD_t;

/* Fault Detection Restart Mode select */
typedef enum WEX_FDMODE_enum
{
    WEX_FDMODE_LATCHED_gc = (0x00<<2),  /* Latched Mode. Output will remain in fault state until fault condition is no longer active and FDF is cleared by SW. */
    WEX_FDMODE_CBC_gc = (0x01<<2)  /* Cycle-by-cycle mode. Waveform output will remain in fault state until fault condition is no longer active. */
} WEX_FDMODE_t;

/* Fault Detection State select */
typedef enum WEX_FDSTATE_enum
{
    WEX_FDSTATE_NORMAL_gc = (0x00<<0),  /* Normal state */
    WEX_FDSTATE_FAULT_gc = (0x01<<0)  /* Fault state */
} WEX_FDSTATE_t;

/* Fault Event Filter Enable select */
typedef enum WEX_FILTER_enum
{
    WEX_FILTER_OFF_gc = (0x00<<2),  /* No digital filter */
    WEX_FILTER_SAMPLE1_gc = (0x01<<2),  /* One Sample */
    WEX_FILTER_SAMPLE2_gc = (0x02<<2),  /* Two Samples */
    WEX_FILTER_SAMPLE3_gc = (0x03<<2),  /* Three Samples */
    WEX_FILTER_SAMPLE4_gc = (0x04<<2),  /* Four Samples */
    WEX_FILTER_SAMPLE5_gc = (0x05<<2),  /* Five Samples */
    WEX_FILTER_SAMPLE6_gc = (0x06<<2),  /* Six Samples */
    WEX_FILTER_SAMPLE7_gc = (0x07<<2)  /* Seven Samples */
} WEX_FILTER_t;

/* Input Matrix select */
typedef enum WEX_INMX_enum
{
    WEX_INMX_DIRECT_gc = (0x00<<4),  /* Direct from TCE0 */
    WEX_INMX_CWCMA_gc = (0x02<<4),  /* Common Waveform Channel Mode A. Single WO */
    WEX_INMX_CWCMB_gc = (0x03<<4)  /* Common Waveform Channel Mode B. WO from two PWM channels */
} WEX_INMX_t;

/* Update Source select */
typedef enum WEX_UPDSRC_enum
{
    WEX_UPDSRC_TCPWM0_gc = (0x00<<0),  /* Timer/Counter for PWM 0 update condition */
    WEX_UPDSRC_NONE_gc = (0x03<<0)  /* No hardware update condition */
} WEX_UPDSRC_t;
/*
==========================================================================
IO Module Instances. Mapped to memory.
==========================================================================
*/

#define VPORTA              (*(VPORT_t *) 0x0000) /* Virtual Ports */
#define VPORTC              (*(VPORT_t *) 0x0008) /* Virtual Ports */
#define VPORTD              (*(VPORT_t *) 0x000C) /* Virtual Ports */
#define VPORTF              (*(VPORT_t *) 0x0014) /* Virtual Ports */
#define RSTCTRL           (*(RSTCTRL_t *) 0x0040) /* Reset controller */
#define SLPCTRL           (*(SLPCTRL_t *) 0x0050) /* Sleep Controller */
#define CLKCTRL           (*(CLKCTRL_t *) 0x0060) /* Clock controller */
#define WDT                   (*(WDT_t *) 0x0100) /* Watch-Dog Timer */
#define CPUINT             (*(CPUINT_t *) 0x0110) /* Interrupt Controller */
#define CRCSCAN           (*(CRCSCAN_t *) 0x0120) /* CRCSCAN */
#define RTC                   (*(RTC_t *) 0x0140) /* Real-Time Counter */
#define CCL                   (*(CCL_t *) 0x01C0) /* Configurable Custom Logic */
#define EVSYS               (*(EVSYS_t *) 0x0200) /* Event System */
#define PORTA                (*(PORT_t *) 0x0400) /* I/O Ports */
#define PORTC                (*(PORT_t *) 0x0440) /* I/O Ports */
#define PORTD                (*(PORT_t *) 0x0460) /* I/O Ports */
#define PORTF                (*(PORT_t *) 0x04A0) /* I/O Ports */
#define PORTMUX           (*(PORTMUX_t *) 0x05E0) /* Port Multiplexer */
#define AC0                    (*(AC_t *) 0x0680) /* Analog Comparator */
#define AC1                    (*(AC_t *) 0x0688) /* Analog Comparator */
#define USART0              (*(USART_t *) 0x0800) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define TWI0                  (*(TWI_t *) 0x0900) /* Two-Wire Interface */
#define SPI0                  (*(SPI_t *) 0x0940) /* Serial Peripheral Interface */
#define TCE0                  (*(TCE_t *) 0x0A00) /* 16-bit Timer/Counter Type E */
#define TCB0                  (*(TCB_t *) 0x0B00) /* 16-bit Timer/Counter Type B */
#define TCB1                  (*(TCB_t *) 0x0B10) /* 16-bit Timer/Counter Type B */
#define TCF0                  (*(TCF_t *) 0x0C00) /* 24-bit Timer/Counter for frequency generation */
#define WEX0                  (*(WEX_t *) 0x0C80) /* Waveform Extension */
#define FPGA                  (*(FIM_t *) 0x0E40) /* FPGA Interface Module */
#define SYSCFG             (*(SYSCFG_t *) 0x0F00) /* System Configuration Registers */
#define NVMCTRL           (*(NVMCTRL_t *) 0x1000) /* Non-volatile Memory Controller */
#define LOCK                 (*(LOCK_t *) 0x1040) /* Lockbit */
#define FUSE                 (*(FUSE_t *) 0x1050) /* Fuses */
#define SIGROW             (*(SIGROW_t *) 0x1100) /* Signature row */
#define USERROW           (*(USERROW_t *) 0x1200) /* User Row */

#endif /* !defined (__ASSEMBLER__) */


/* ========== Flattened fully qualified IO register names ========== */


/* VPORT (VPORTA) - Virtual Ports */
#define VPORTA_DIR  _SFR_MEM8(0x0000)
#define VPORTA_OUT  _SFR_MEM8(0x0001)
#define VPORTA_IN  _SFR_MEM8(0x0002)
#define VPORTA_INTFLAGS  _SFR_MEM8(0x0003)


/* VPORT (VPORTC) - Virtual Ports */
#define VPORTC_DIR  _SFR_MEM8(0x0008)
#define VPORTC_OUT  _SFR_MEM8(0x0009)
#define VPORTC_IN  _SFR_MEM8(0x000A)
#define VPORTC_INTFLAGS  _SFR_MEM8(0x000B)


/* VPORT (VPORTD) - Virtual Ports */
#define VPORTD_DIR  _SFR_MEM8(0x000C)
#define VPORTD_OUT  _SFR_MEM8(0x000D)
#define VPORTD_IN  _SFR_MEM8(0x000E)
#define VPORTD_INTFLAGS  _SFR_MEM8(0x000F)


/* VPORT (VPORTF) - Virtual Ports */
#define VPORTF_DIR  _SFR_MEM8(0x0014)
#define VPORTF_OUT  _SFR_MEM8(0x0015)
#define VPORTF_IN  _SFR_MEM8(0x0016)
#define VPORTF_INTFLAGS  _SFR_MEM8(0x0017)


/* GPR (GPIO) - General Purpose Registers */
#define GPIO_GPR0  _SFR_MEM8(0x001C)
#define GPIO_GPR1  _SFR_MEM8(0x001D)
#define GPIO_GPR2  _SFR_MEM8(0x001E)
#define GPIO_GPR3  _SFR_MEM8(0x001F)


/* CPU - CPU */
#define CPU_CCP  _SFR_MEM8(0x0034)
#define CPU_RAMPZ  _SFR_MEM8(0x003B)
#define CPU_SP  _SFR_MEM16(0x003D)
#define CPU_SPL  _SFR_MEM8(0x003D)
#define CPU_SPH  _SFR_MEM8(0x003E)
#define CPU_SREG  _SFR_MEM8(0x003F)


/* RSTCTRL - Reset controller */
#define RSTCTRL_RSTFR  _SFR_MEM8(0x0040)
#define RSTCTRL_SWRR  _SFR_MEM8(0x0041)
#define RSTCTRL_BOOTCTRL  _SFR_MEM8(0x0042)
#define RSTCTRL_TEST  _SFR_MEM8(0x0043)


/* SLPCTRL - Sleep Controller */
#define SLPCTRL_CTRLA  _SFR_MEM8(0x0050)
#define SLPCTRL_VREGCTRL  _SFR_MEM8(0x0051)
#define SLPCTRL_CALLDO  _SFR_MEM8(0x0054)
#define SLPCTRL_CALULP  _SFR_MEM8(0x0055)
#define SLPCTRL_CALBB  _SFR_MEM8(0x0056)
#define SLPCTRL_TESTLDOA  _SFR_MEM8(0x0058)
#define SLPCTRL_TESTLDOB  _SFR_MEM8(0x0059)
#define SLPCTRL_TESTULP  _SFR_MEM8(0x005A)
#define SLPCTRL_TESTCMP  _SFR_MEM8(0x005B)
#define SLPCTRL_TESTSTATUS  _SFR_MEM8(0x005C)


/* CLKCTRL - Clock controller */
#define CLKCTRL_MCLKCTRLA  _SFR_MEM8(0x0060)
#define CLKCTRL_MCLKCTRLB  _SFR_MEM8(0x0061)
#define CLKCTRL_MCLKLOCK  _SFR_MEM8(0x0062)
#define CLKCTRL_MCLKSTATUS  _SFR_MEM8(0x0063)
#define CLKCTRL_MCLKSTATUSB  _SFR_MEM8(0x0064)
#define CLKCTRL_MCLKTEST  _SFR_MEM8(0x0067)
#define CLKCTRL_OSCHFCTRLA  _SFR_MEM8(0x0068)
#define CLKCTRL_OSCHFTUNE  _SFR_MEM8(0x0069)
#define CLKCTRL_OSCHFCALL  _SFR_MEM8(0x006C)
#define CLKCTRL_OSCHFCALH  _SFR_MEM8(0x006D)
#define CLKCTRL_OSCHFTCAL  _SFR_MEM8(0x006E)
#define CLKCTRL_OSCHFTEST  _SFR_MEM8(0x006F)
#define CLKCTRL_PLLCTRLA  _SFR_MEM8(0x0070)
#define CLKCTRL_PLLTEST  _SFR_MEM8(0x0073)
#define CLKCTRL_OSCPDICAL  _SFR_MEM8(0x0075)
#define CLKCTRL_OSCPDITEST  _SFR_MEM8(0x0077)
#define CLKCTRL_OSC32KCTRLA  _SFR_MEM8(0x0078)
#define CLKCTRL_OSC32KCAL  _SFR_MEM8(0x0079)
#define CLKCTRL_OSC32KTEST  _SFR_MEM8(0x007B)
#define CLKCTRL_XOSC32KCTRLA  _SFR_MEM8(0x007C)
#define CLKCTRL_XOSC32KTEST  _SFR_MEM8(0x007F)


/* WDT - Watch-Dog Timer */
#define WDT_CTRLA  _SFR_MEM8(0x0100)
#define WDT_STATUS  _SFR_MEM8(0x0101)


/* CPUINT - Interrupt Controller */
#define CPUINT_CTRLA  _SFR_MEM8(0x0110)
#define CPUINT_STATUS  _SFR_MEM8(0x0111)
#define CPUINT_LVL0PRI  _SFR_MEM8(0x0112)
#define CPUINT_LVL1VEC  _SFR_MEM8(0x0113)


/* CRCSCAN - CRCSCAN */
#define CRCSCAN_CTRLA  _SFR_MEM8(0x0120)
#define CRCSCAN_CTRLB  _SFR_MEM8(0x0121)
#define CRCSCAN_STATUS  _SFR_MEM8(0x0122)


/* RTC - Real-Time Counter */
#define RTC_CTRLA  _SFR_MEM8(0x0140)
#define RTC_STATUS  _SFR_MEM8(0x0141)
#define RTC_INTCTRL  _SFR_MEM8(0x0142)
#define RTC_INTFLAGS  _SFR_MEM8(0x0143)
#define RTC_TEMP  _SFR_MEM8(0x0144)
#define RTC_DBGCTRL  _SFR_MEM8(0x0145)
#define RTC_CALIB  _SFR_MEM8(0x0146)
#define RTC_CLKSEL  _SFR_MEM8(0x0147)
#define RTC_CNT  _SFR_MEM16(0x0148)
#define RTC_CNTL  _SFR_MEM8(0x0148)
#define RTC_CNTH  _SFR_MEM8(0x0149)
#define RTC_PER  _SFR_MEM16(0x014A)
#define RTC_PERL  _SFR_MEM8(0x014A)
#define RTC_PERH  _SFR_MEM8(0x014B)
#define RTC_CMP  _SFR_MEM16(0x014C)
#define RTC_CMPL  _SFR_MEM8(0x014C)
#define RTC_CMPH  _SFR_MEM8(0x014D)
#define RTC_PITCTRLA  _SFR_MEM8(0x0150)
#define RTC_PITSTATUS  _SFR_MEM8(0x0151)
#define RTC_PITINTCTRL  _SFR_MEM8(0x0152)
#define RTC_PITINTFLAGS  _SFR_MEM8(0x0153)
#define RTC_PITDBGCTRL  _SFR_MEM8(0x0155)
#define RTC_PITEVGENCTRLA  _SFR_MEM8(0x0156)


/* CCL - Configurable Custom Logic */
#define CCL_CTRLA  _SFR_MEM8(0x01C0)
#define CCL_SEQCTRL0  _SFR_MEM8(0x01C1)
#define CCL_SEQCTRL1  _SFR_MEM8(0x01C2)
#define CCL_INTCTRL0  _SFR_MEM8(0x01C5)
#define CCL_INTFLAGS  _SFR_MEM8(0x01C7)
#define CCL_LUT0CTRLA  _SFR_MEM8(0x01C8)
#define CCL_LUT0CTRLB  _SFR_MEM8(0x01C9)
#define CCL_LUT0CTRLC  _SFR_MEM8(0x01CA)
#define CCL_TRUTH0  _SFR_MEM8(0x01CB)
#define CCL_LUT1CTRLA  _SFR_MEM8(0x01CC)
#define CCL_LUT1CTRLB  _SFR_MEM8(0x01CD)
#define CCL_LUT1CTRLC  _SFR_MEM8(0x01CE)
#define CCL_TRUTH1  _SFR_MEM8(0x01CF)
#define CCL_LUT2CTRLA  _SFR_MEM8(0x01D0)
#define CCL_LUT2CTRLB  _SFR_MEM8(0x01D1)
#define CCL_LUT2CTRLC  _SFR_MEM8(0x01D2)
#define CCL_TRUTH2  _SFR_MEM8(0x01D3)
#define CCL_LUT3CTRLA  _SFR_MEM8(0x01D4)
#define CCL_LUT3CTRLB  _SFR_MEM8(0x01D5)
#define CCL_LUT3CTRLC  _SFR_MEM8(0x01D6)
#define CCL_TRUTH3  _SFR_MEM8(0x01D7)


/* EVSYS - Event System */
#define EVSYS_SWEVENTA  _SFR_MEM8(0x0200)
#define EVSYS_CHANNEL0  _SFR_MEM8(0x0210)
#define EVSYS_CHANNEL1  _SFR_MEM8(0x0211)
#define EVSYS_CHANNEL2  _SFR_MEM8(0x0212)
#define EVSYS_CHANNEL3  _SFR_MEM8(0x0213)
#define EVSYS_CHANNEL4  _SFR_MEM8(0x0214)
#define EVSYS_CHANNEL5  _SFR_MEM8(0x0215)
#define EVSYS_CHANNEL6  _SFR_MEM8(0x0216)
#define EVSYS_CHANNEL7  _SFR_MEM8(0x0217)
#define EVSYS_USERCCLLUT0A  _SFR_MEM8(0x0220)
#define EVSYS_USERCCLLUT0B  _SFR_MEM8(0x0221)
#define EVSYS_USERCCLLUT1A  _SFR_MEM8(0x0222)
#define EVSYS_USERCCLLUT1B  _SFR_MEM8(0x0223)
#define EVSYS_USERCCLLUT2A  _SFR_MEM8(0x0224)
#define EVSYS_USERCCLLUT2B  _SFR_MEM8(0x0225)
#define EVSYS_USERCCLLUT3A  _SFR_MEM8(0x0226)
#define EVSYS_USERCCLLUT3B  _SFR_MEM8(0x0227)
#define EVSYS_USERADC0START  _SFR_MEM8(0x0228)
#define EVSYS_USEREVSYSEVOUTA  _SFR_MEM8(0x0229)
#define EVSYS_USEREVSYSEVOUTC  _SFR_MEM8(0x022A)
#define EVSYS_USEREVSYSEVOUTD  _SFR_MEM8(0x022B)
#define EVSYS_USEREVSYSEVOUTF  _SFR_MEM8(0x022C)
#define EVSYS_USERUSART0IRDA  _SFR_MEM8(0x022D)
#define EVSYS_USERTCE0CNTA  _SFR_MEM8(0x022E)
#define EVSYS_USERTCE0CNTB  _SFR_MEM8(0x022F)
#define EVSYS_USERTCB0CAPT  _SFR_MEM8(0x0230)
#define EVSYS_USERTCB0COUNT  _SFR_MEM8(0x0231)
#define EVSYS_USERTCB1CAPT  _SFR_MEM8(0x0232)
#define EVSYS_USERTCB1COUNT  _SFR_MEM8(0x0233)
#define EVSYS_USERTCF0CNT  _SFR_MEM8(0x0234)
#define EVSYS_USERTCF0ACT  _SFR_MEM8(0x0235)
#define EVSYS_USERWEXA  _SFR_MEM8(0x0236)
#define EVSYS_USERWEXB  _SFR_MEM8(0x0237)
#define EVSYS_USERWEXC  _SFR_MEM8(0x0238)
#define EVSYS_USERTEST  _SFR_MEM8(0x025F)


/* PORT (PORTA) - I/O Ports */
#define PORTA_DIR  _SFR_MEM8(0x0400)
#define PORTA_DIRSET  _SFR_MEM8(0x0401)
#define PORTA_DIRCLR  _SFR_MEM8(0x0402)
#define PORTA_DIRTGL  _SFR_MEM8(0x0403)
#define PORTA_OUT  _SFR_MEM8(0x0404)
#define PORTA_OUTSET  _SFR_MEM8(0x0405)
#define PORTA_OUTCLR  _SFR_MEM8(0x0406)
#define PORTA_OUTTGL  _SFR_MEM8(0x0407)
#define PORTA_IN  _SFR_MEM8(0x0408)
#define PORTA_INTFLAGS  _SFR_MEM8(0x0409)
#define PORTA_PORTCTRL  _SFR_MEM8(0x040A)
#define PORTA_PINCONFIG  _SFR_MEM8(0x040B)
#define PORTA_PINCTRLUPD  _SFR_MEM8(0x040C)
#define PORTA_PINCTRLSET  _SFR_MEM8(0x040D)
#define PORTA_PINCTRLCLR  _SFR_MEM8(0x040E)
#define PORTA_PIN0CTRL  _SFR_MEM8(0x0410)
#define PORTA_PIN1CTRL  _SFR_MEM8(0x0411)
#define PORTA_PIN2CTRL  _SFR_MEM8(0x0412)
#define PORTA_PIN3CTRL  _SFR_MEM8(0x0413)
#define PORTA_PIN4CTRL  _SFR_MEM8(0x0414)
#define PORTA_PIN5CTRL  _SFR_MEM8(0x0415)
#define PORTA_PIN6CTRL  _SFR_MEM8(0x0416)
#define PORTA_PIN7CTRL  _SFR_MEM8(0x0417)


/* PORT (PORTC) - I/O Ports */
#define PORTC_DIR  _SFR_MEM8(0x0440)
#define PORTC_DIRSET  _SFR_MEM8(0x0441)
#define PORTC_DIRCLR  _SFR_MEM8(0x0442)
#define PORTC_DIRTGL  _SFR_MEM8(0x0443)
#define PORTC_OUT  _SFR_MEM8(0x0444)
#define PORTC_OUTSET  _SFR_MEM8(0x0445)
#define PORTC_OUTCLR  _SFR_MEM8(0x0446)
#define PORTC_OUTTGL  _SFR_MEM8(0x0447)
#define PORTC_IN  _SFR_MEM8(0x0448)
#define PORTC_INTFLAGS  _SFR_MEM8(0x0449)
#define PORTC_PORTCTRL  _SFR_MEM8(0x044A)
#define PORTC_PINCONFIG  _SFR_MEM8(0x044B)
#define PORTC_PINCTRLUPD  _SFR_MEM8(0x044C)
#define PORTC_PINCTRLSET  _SFR_MEM8(0x044D)
#define PORTC_PINCTRLCLR  _SFR_MEM8(0x044E)
#define PORTC_PIN0CTRL  _SFR_MEM8(0x0450)
#define PORTC_PIN1CTRL  _SFR_MEM8(0x0451)
#define PORTC_PIN2CTRL  _SFR_MEM8(0x0452)
#define PORTC_PIN3CTRL  _SFR_MEM8(0x0453)
#define PORTC_PIN4CTRL  _SFR_MEM8(0x0454)
#define PORTC_PIN5CTRL  _SFR_MEM8(0x0455)
#define PORTC_PIN6CTRL  _SFR_MEM8(0x0456)
#define PORTC_PIN7CTRL  _SFR_MEM8(0x0457)


/* PORT (PORTD) - I/O Ports */
#define PORTD_DIR  _SFR_MEM8(0x0460)
#define PORTD_DIRSET  _SFR_MEM8(0x0461)
#define PORTD_DIRCLR  _SFR_MEM8(0x0462)
#define PORTD_DIRTGL  _SFR_MEM8(0x0463)
#define PORTD_OUT  _SFR_MEM8(0x0464)
#define PORTD_OUTSET  _SFR_MEM8(0x0465)
#define PORTD_OUTCLR  _SFR_MEM8(0x0466)
#define PORTD_OUTTGL  _SFR_MEM8(0x0467)
#define PORTD_IN  _SFR_MEM8(0x0468)
#define PORTD_INTFLAGS  _SFR_MEM8(0x0469)
#define PORTD_PORTCTRL  _SFR_MEM8(0x046A)
#define PORTD_PINCONFIG  _SFR_MEM8(0x046B)
#define PORTD_PINCTRLUPD  _SFR_MEM8(0x046C)
#define PORTD_PINCTRLSET  _SFR_MEM8(0x046D)
#define PORTD_PINCTRLCLR  _SFR_MEM8(0x046E)
#define PORTD_PIN0CTRL  _SFR_MEM8(0x0470)
#define PORTD_PIN1CTRL  _SFR_MEM8(0x0471)
#define PORTD_PIN2CTRL  _SFR_MEM8(0x0472)
#define PORTD_PIN3CTRL  _SFR_MEM8(0x0473)
#define PORTD_PIN4CTRL  _SFR_MEM8(0x0474)
#define PORTD_PIN5CTRL  _SFR_MEM8(0x0475)
#define PORTD_PIN6CTRL  _SFR_MEM8(0x0476)
#define PORTD_PIN7CTRL  _SFR_MEM8(0x0477)


/* PORT (PORTF) - I/O Ports */
#define PORTF_DIR  _SFR_MEM8(0x04A0)
#define PORTF_DIRSET  _SFR_MEM8(0x04A1)
#define PORTF_DIRCLR  _SFR_MEM8(0x04A2)
#define PORTF_DIRTGL  _SFR_MEM8(0x04A3)
#define PORTF_OUT  _SFR_MEM8(0x04A4)
#define PORTF_OUTSET  _SFR_MEM8(0x04A5)
#define PORTF_OUTCLR  _SFR_MEM8(0x04A6)
#define PORTF_OUTTGL  _SFR_MEM8(0x04A7)
#define PORTF_IN  _SFR_MEM8(0x04A8)
#define PORTF_INTFLAGS  _SFR_MEM8(0x04A9)
#define PORTF_PORTCTRL  _SFR_MEM8(0x04AA)
#define PORTF_PINCONFIG  _SFR_MEM8(0x04AB)
#define PORTF_PINCTRLUPD  _SFR_MEM8(0x04AC)
#define PORTF_PINCTRLSET  _SFR_MEM8(0x04AD)
#define PORTF_PINCTRLCLR  _SFR_MEM8(0x04AE)
#define PORTF_PIN0CTRL  _SFR_MEM8(0x04B0)
#define PORTF_PIN1CTRL  _SFR_MEM8(0x04B1)
#define PORTF_PIN2CTRL  _SFR_MEM8(0x04B2)
#define PORTF_PIN3CTRL  _SFR_MEM8(0x04B3)
#define PORTF_PIN4CTRL  _SFR_MEM8(0x04B4)
#define PORTF_PIN5CTRL  _SFR_MEM8(0x04B5)
#define PORTF_PIN6CTRL  _SFR_MEM8(0x04B6)
#define PORTF_PIN7CTRL  _SFR_MEM8(0x04B7)


/* PORTMUX - Port Multiplexer */
#define PORTMUX_EVSYSROUTEA  _SFR_MEM8(0x05E0)
#define PORTMUX_CCLROUTEA  _SFR_MEM8(0x05E1)
#define PORTMUX_USARTROUTEA  _SFR_MEM8(0x05E2)
#define PORTMUX_SPIROUTEA  _SFR_MEM8(0x05E5)
#define PORTMUX_TWIROUTEA  _SFR_MEM8(0x05E6)
#define PORTMUX_TCEROUTEA  _SFR_MEM8(0x05E7)
#define PORTMUX_TCBROUTEA  _SFR_MEM8(0x05E8)
#define PORTMUX_TCDROUTEA  _SFR_MEM8(0x05EA)
#define PORTMUX_ACROUTEA  _SFR_MEM8(0x05EB)
#define PORTMUX_TCFROUTEA  _SFR_MEM8(0x05EC)
#define PORTMUX_ZCDROUTEA  _SFR_MEM8(0x05EF)
#define PORTMUX_EEXROUTEA  _SFR_MEM8(0x05F0)


/* AC (AC0) - Analog Comparator */
#define AC0_CTRLA  _SFR_MEM8(0x0680)
#define AC0_CTRLB  _SFR_MEM8(0x0681)
#define AC0_MUXCTRL  _SFR_MEM8(0x0682)
#define AC0_DACREF  _SFR_MEM8(0x0685)
#define AC0_INTCTRL  _SFR_MEM8(0x0686)
#define AC0_STATUS  _SFR_MEM8(0x0687)


/* AC (AC1) - Analog Comparator */
#define AC1_CTRLA  _SFR_MEM8(0x0688)
#define AC1_CTRLB  _SFR_MEM8(0x0689)
#define AC1_MUXCTRL  _SFR_MEM8(0x068A)
#define AC1_DACREF  _SFR_MEM8(0x068D)
#define AC1_INTCTRL  _SFR_MEM8(0x068E)
#define AC1_STATUS  _SFR_MEM8(0x068F)


/* USART (USART0) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART0_RXDATAL  _SFR_MEM8(0x0800)
#define USART0_RXDATAH  _SFR_MEM8(0x0801)
#define USART0_TXDATAL  _SFR_MEM8(0x0802)
#define USART0_TXDATAH  _SFR_MEM8(0x0803)
#define USART0_STATUS  _SFR_MEM8(0x0804)
#define USART0_CTRLA  _SFR_MEM8(0x0805)
#define USART0_CTRLB  _SFR_MEM8(0x0806)
#define USART0_CTRLC  _SFR_MEM8(0x0807)
#define USART0_BAUD  _SFR_MEM16(0x0808)
#define USART0_BAUDL  _SFR_MEM8(0x0808)
#define USART0_BAUDH  _SFR_MEM8(0x0809)
#define USART0_CTRLD  _SFR_MEM8(0x080A)
#define USART0_DBGCTRL  _SFR_MEM8(0x080B)
#define USART0_EVCTRL  _SFR_MEM8(0x080C)
#define USART0_TXPLCTRL  _SFR_MEM8(0x080D)
#define USART0_RXPLCTRL  _SFR_MEM8(0x080E)


/* TWI (TWI0) - Two-Wire Interface */
#define TWI0_CTRLA  _SFR_MEM8(0x0900)
#define TWI0_DBGCTRL  _SFR_MEM8(0x0902)
#define TWI0_MCTRLA  _SFR_MEM8(0x0903)
#define TWI0_MCTRLB  _SFR_MEM8(0x0904)
#define TWI0_MSTATUS  _SFR_MEM8(0x0905)
#define TWI0_MBAUD  _SFR_MEM8(0x0906)
#define TWI0_MADDR  _SFR_MEM8(0x0907)
#define TWI0_MDATA  _SFR_MEM8(0x0908)
#define TWI0_SCTRLA  _SFR_MEM8(0x0909)
#define TWI0_SCTRLB  _SFR_MEM8(0x090A)
#define TWI0_SSTATUS  _SFR_MEM8(0x090B)
#define TWI0_SADDR  _SFR_MEM8(0x090C)
#define TWI0_SDATA  _SFR_MEM8(0x090D)
#define TWI0_SADDRMASK  _SFR_MEM8(0x090E)
#define TWI0_TESTCTRL  _SFR_MEM8(0x090F)


/* SPI (SPI0) - Serial Peripheral Interface */
#define SPI0_CTRLA  _SFR_MEM8(0x0940)
#define SPI0_CTRLB  _SFR_MEM8(0x0941)
#define SPI0_INTCTRL  _SFR_MEM8(0x0942)
#define SPI0_INTFLAGS  _SFR_MEM8(0x0943)
#define SPI0_DATA  _SFR_MEM8(0x0944)


/* TCE (TCE0) - 16-bit Timer/Counter Type E */
#define TCE0_CTRLA  _SFR_MEM8(0x0A00)
#define TCE0_CTRLB  _SFR_MEM8(0x0A01)
#define TCE0_CTRLC  _SFR_MEM8(0x0A02)
#define TCE0_CTRLD  _SFR_MEM8(0x0A03)
#define TCE0_CTRLECLR  _SFR_MEM8(0x0A04)
#define TCE0_CTRLESET  _SFR_MEM8(0x0A05)
#define TCE0_CTRLFCLR  _SFR_MEM8(0x0A06)
#define TCE0_CTRLFSET  _SFR_MEM8(0x0A07)
#define TCE0_EVGENCTRL  _SFR_MEM8(0x0A08)
#define TCE0_EVCTRL  _SFR_MEM8(0x0A09)
#define TCE0_INTCTRL  _SFR_MEM8(0x0A0A)
#define TCE0_INTFLAGS  _SFR_MEM8(0x0A0B)
#define TCE0_DBGCTRL  _SFR_MEM8(0x0A0E)
#define TCE0_TEMP  _SFR_MEM8(0x0A0F)
#define TCE0_CNT  _SFR_MEM16(0x0A20)
#define TCE0_CNTL  _SFR_MEM8(0x0A20)
#define TCE0_CNTH  _SFR_MEM8(0x0A21)
#define TCE0_AMP  _SFR_MEM16(0x0A22)
#define TCE0_AMPL  _SFR_MEM8(0x0A22)
#define TCE0_AMPH  _SFR_MEM8(0x0A23)
#define TCE0_OFFSET  _SFR_MEM16(0x0A24)
#define TCE0_OFFSETL  _SFR_MEM8(0x0A24)
#define TCE0_OFFSETH  _SFR_MEM8(0x0A25)
#define TCE0_PER  _SFR_MEM16(0x0A26)
#define TCE0_PERL  _SFR_MEM8(0x0A26)
#define TCE0_PERH  _SFR_MEM8(0x0A27)
#define TCE0_CMP0  _SFR_MEM16(0x0A28)
#define TCE0_CMP0L  _SFR_MEM8(0x0A28)
#define TCE0_CMP0H  _SFR_MEM8(0x0A29)
#define TCE0_CMP1  _SFR_MEM16(0x0A2A)
#define TCE0_CMP1L  _SFR_MEM8(0x0A2A)
#define TCE0_CMP1H  _SFR_MEM8(0x0A2B)
#define TCE0_CMP2  _SFR_MEM16(0x0A2C)
#define TCE0_CMP2L  _SFR_MEM8(0x0A2C)
#define TCE0_CMP2H  _SFR_MEM8(0x0A2D)
#define TCE0_CMP3  _SFR_MEM16(0x0A2E)
#define TCE0_CMP3L  _SFR_MEM8(0x0A2E)
#define TCE0_CMP3H  _SFR_MEM8(0x0A2F)
#define TCE0_PERBUF  _SFR_MEM16(0x0A36)
#define TCE0_PERBUFL  _SFR_MEM8(0x0A36)
#define TCE0_PERBUFH  _SFR_MEM8(0x0A37)
#define TCE0_CMP0BUF  _SFR_MEM16(0x0A38)
#define TCE0_CMP0BUFL  _SFR_MEM8(0x0A38)
#define TCE0_CMP0BUFH  _SFR_MEM8(0x0A39)
#define TCE0_CMP1BUF  _SFR_MEM16(0x0A3A)
#define TCE0_CMP1BUFL  _SFR_MEM8(0x0A3A)
#define TCE0_CMP1BUFH  _SFR_MEM8(0x0A3B)
#define TCE0_CMP2BUF  _SFR_MEM16(0x0A3C)
#define TCE0_CMP2BUFL  _SFR_MEM8(0x0A3C)
#define TCE0_CMP2BUFH  _SFR_MEM8(0x0A3D)
#define TCE0_CMP3BUF  _SFR_MEM16(0x0A3E)
#define TCE0_CMP3BUFL  _SFR_MEM8(0x0A3E)
#define TCE0_CMP3BUFH  _SFR_MEM8(0x0A3F)


/* TCB (TCB0) - 16-bit Timer/Counter Type B */
#define TCB0_CTRLA  _SFR_MEM8(0x0B00)
#define TCB0_CTRLB  _SFR_MEM8(0x0B01)
#define TCB0_CTRLC  _SFR_MEM8(0x0B02)
#define TCB0_EVCTRL  _SFR_MEM8(0x0B04)
#define TCB0_INTCTRL  _SFR_MEM8(0x0B05)
#define TCB0_INTFLAGS  _SFR_MEM8(0x0B06)
#define TCB0_STATUS  _SFR_MEM8(0x0B07)
#define TCB0_DBGCTRL  _SFR_MEM8(0x0B08)
#define TCB0_TEMP  _SFR_MEM8(0x0B09)
#define TCB0_CNT  _SFR_MEM16(0x0B0A)
#define TCB0_CNTL  _SFR_MEM8(0x0B0A)
#define TCB0_CNTH  _SFR_MEM8(0x0B0B)
#define TCB0_CCMP  _SFR_MEM16(0x0B0C)
#define TCB0_CCMPL  _SFR_MEM8(0x0B0C)
#define TCB0_CCMPH  _SFR_MEM8(0x0B0D)


/* TCB (TCB1) - 16-bit Timer/Counter Type B */
#define TCB1_CTRLA  _SFR_MEM8(0x0B10)
#define TCB1_CTRLB  _SFR_MEM8(0x0B11)
#define TCB1_CTRLC  _SFR_MEM8(0x0B12)
#define TCB1_EVCTRL  _SFR_MEM8(0x0B14)
#define TCB1_INTCTRL  _SFR_MEM8(0x0B15)
#define TCB1_INTFLAGS  _SFR_MEM8(0x0B16)
#define TCB1_STATUS  _SFR_MEM8(0x0B17)
#define TCB1_DBGCTRL  _SFR_MEM8(0x0B18)
#define TCB1_TEMP  _SFR_MEM8(0x0B19)
#define TCB1_CNT  _SFR_MEM16(0x0B1A)
#define TCB1_CNTL  _SFR_MEM8(0x0B1A)
#define TCB1_CNTH  _SFR_MEM8(0x0B1B)
#define TCB1_CCMP  _SFR_MEM16(0x0B1C)
#define TCB1_CCMPL  _SFR_MEM8(0x0B1C)
#define TCB1_CCMPH  _SFR_MEM8(0x0B1D)


/* TCF (TCF0) - 24-bit Timer/Counter for frequency generation */
#define TCF0_CTRLA  _SFR_MEM8(0x0C00)
#define TCF0_CTRLB  _SFR_MEM8(0x0C01)
#define TCF0_CTRLC  _SFR_MEM8(0x0C02)
#define TCF0_CTRLD  _SFR_MEM8(0x0C03)
#define TCF0_EVCTRL  _SFR_MEM8(0x0C04)
#define TCF0_INTCTRL  _SFR_MEM8(0x0C05)
#define TCF0_INTFLAGS  _SFR_MEM8(0x0C06)
#define TCF0_STATUS  _SFR_MEM8(0x0C07)
#define TCF0_DBGCTRL  _SFR_MEM8(0x0C0D)
#define TCF0_CNT  _SFR_MEM32(0x0C10)
#define TCF0_CNT0  _SFR_MEM8(0x0C10)
#define TCF0_CNT1  _SFR_MEM8(0x0C11)
#define TCF0_CNT2  _SFR_MEM8(0x0C12)
#define TCF0_CNT3  _SFR_MEM8(0x0C13)
#define TCF0_CMP  _SFR_MEM32(0x0C14)
#define TCF0_CMP0  _SFR_MEM8(0x0C14)
#define TCF0_CMP1  _SFR_MEM8(0x0C15)
#define TCF0_CMP2  _SFR_MEM8(0x0C16)
#define TCF0_CMP3  _SFR_MEM8(0x0C17)


/* WEX (WEX0) - Waveform Extension */
#define WEX0_CTRLA  _SFR_MEM8(0x0C80)
#define WEX0_CTRLB  _SFR_MEM8(0x0C81)
#define WEX0_CTRLC  _SFR_MEM8(0x0C82)
#define WEX0_EVCTRLA  _SFR_MEM8(0x0C84)
#define WEX0_EVCTRLB  _SFR_MEM8(0x0C85)
#define WEX0_EVCTRLC  _SFR_MEM8(0x0C86)
#define WEX0_BUFCTRL  _SFR_MEM8(0x0C87)
#define WEX0_BLANKCTRL  _SFR_MEM8(0x0C88)
#define WEX0_BLANKTIME  _SFR_MEM8(0x0C89)
#define WEX0_FAULTCTRL  _SFR_MEM8(0x0C8A)
#define WEX0_FAULTDRV  _SFR_MEM8(0x0C8B)
#define WEX0_FAULTOUT  _SFR_MEM8(0x0C8C)
#define WEX0_INTCTRL  _SFR_MEM8(0x0C8D)
#define WEX0_INTFLAGS  _SFR_MEM8(0x0C8E)
#define WEX0_STATUS  _SFR_MEM8(0x0C8F)
#define WEX0_DTLS  _SFR_MEM8(0x0C90)
#define WEX0_DTHS  _SFR_MEM8(0x0C91)
#define WEX0_DTBOTH  _SFR_MEM8(0x0C92)
#define WEX0_SWAP  _SFR_MEM8(0x0C93)
#define WEX0_PGMOVR  _SFR_MEM8(0x0C94)
#define WEX0_PGMOUT  _SFR_MEM8(0x0C95)
#define WEX0_OUTOVEN  _SFR_MEM8(0x0C97)
#define WEX0_DTLSBUF  _SFR_MEM8(0x0C98)
#define WEX0_DTHSBUF  _SFR_MEM8(0x0C99)
#define WEX0_DTBOTHBUF  _SFR_MEM8(0x0C9A)
#define WEX0_SWAPBUF  _SFR_MEM8(0x0C9B)
#define WEX0_PGMOVRBUF  _SFR_MEM8(0x0C9C)
#define WEX0_PGMOUTBUF  _SFR_MEM8(0x0C9D)


/* FIM (FPGA) - FPGA Interface Module */
#define FPGA_INTCTRL  _SFR_MEM8(0x0E40)
#define FPGA_INTFLAGS  _SFR_MEM8(0x0E41)
#define FPGA_STATUS  _SFR_MEM8(0x0E42)
#define FPGA_SWITCHES  _SFR_MEM16(0x0E44)
#define FPGA_SWITCHESL  _SFR_MEM8(0x0E44)
#define FPGA_SWITCHESH  _SFR_MEM8(0x0E45)
#define FPGA_LEDS  _SFR_MEM16(0x0E46)
#define FPGA_LEDSL  _SFR_MEM8(0x0E46)
#define FPGA_LEDSH  _SFR_MEM8(0x0E47)
#define FPGA_SEVENSEG  _SFR_MEM32(0x0E48)
#define FPGA_SEVENSEG0  _SFR_MEM8(0x0E48)
#define FPGA_SEVENSEG1  _SFR_MEM8(0x0E49)
#define FPGA_SEVENSEG2  _SFR_MEM8(0x0E4A)
#define FPGA_SEVENSEG3  _SFR_MEM8(0x0E4B)
#define FPGA_DOTS  _SFR_MEM8(0x0E4C)
#define FPGA_MCLED0  _SFR_MEM32(0x0E50)
#define FPGA_MCLED00  _SFR_MEM8(0x0E50)
#define FPGA_MCLED01  _SFR_MEM8(0x0E51)
#define FPGA_MCLED02  _SFR_MEM8(0x0E52)
#define FPGA_MCLED03  _SFR_MEM8(0x0E53)
#define FPGA_MCLED1  _SFR_MEM32(0x0E54)
#define FPGA_MCLED10  _SFR_MEM8(0x0E54)
#define FPGA_MCLED11  _SFR_MEM8(0x0E55)
#define FPGA_MCLED12  _SFR_MEM8(0x0E56)
#define FPGA_MCLED13  _SFR_MEM8(0x0E57)
#define FPGA_DNALSDW  _SFR_MEM32(0x0E58)
#define FPGA_DNALSDW0  _SFR_MEM8(0x0E58)
#define FPGA_DNALSDW1  _SFR_MEM8(0x0E59)
#define FPGA_DNALSDW2  _SFR_MEM8(0x0E5A)
#define FPGA_DNALSDW3  _SFR_MEM8(0x0E5B)
#define FPGA_DNAMSDW  _SFR_MEM32(0x0E5C)
#define FPGA_DNAMSDW0  _SFR_MEM8(0x0E5C)
#define FPGA_DNAMSDW1  _SFR_MEM8(0x0E5D)
#define FPGA_DNAMSDW2  _SFR_MEM8(0x0E5E)
#define FPGA_DNAMSDW3  _SFR_MEM8(0x0E5F)
#define FPGA_VGA  _SFR_MEM8(0x0E60)


/* SYSCFG - System Configuration Registers */
#define SYSCFG_ASI  _SFR_MEM8(0x0F00)
#define SYSCFG_REVID  _SFR_MEM8(0x0F01)
#define SYSCFG_EXTBRK  _SFR_MEM8(0x0F02)
#define SYSCFG_FRESH  _SFR_MEM8(0x0F04)
#define SYSCFG_SYSCFG0  _SFR_MEM8(0x0F05)
#define SYSCFG_SYSCFG1  _SFR_MEM8(0x0F06)
#define SYSCFG_CODESIZE  _SFR_MEM8(0x0F07)
#define SYSCFG_BOOTSIZE  _SFR_MEM8(0x0F08)
#define SYSCFG_HVDSTATUS  _SFR_MEM8(0x0F09)
#define SYSCFG_HVDCTRL  _SFR_MEM8(0x0F0A)
#define SYSCFG_TESTCTRLA  _SFR_MEM8(0x0F0C)
#define SYSCFG_TESTCTRLB  _SFR_MEM8(0x0F0D)
#define SYSCFG_TESTCTRLC  _SFR_MEM8(0x0F0E)
#define SYSCFG_TESTCTRLD  _SFR_MEM8(0x0F0F)
#define SYSCFG_MEMSIZE0  _SFR_MEM8(0x0F10)
#define SYSCFG_MEMSIZE1  _SFR_MEM8(0x0F11)
#define SYSCFG_PINCNT  _SFR_MEM8(0x0F12)
#define SYSCFG_CONFIG0  _SFR_MEM8(0x0F13)
#define SYSCFG_CONFIG1  _SFR_MEM8(0x0F14)
#define SYSCFG_OCDMCTRL  _SFR_MEM8(0x0F18)
#define SYSCFG_OCDMSTATUS  _SFR_MEM8(0x0F19)


/* NVMCTRL - Non-volatile Memory Controller */
#define NVMCTRL_CTRLA  _SFR_MEM8(0x1000)
#define NVMCTRL_CTRLB  _SFR_MEM8(0x1001)
#define NVMCTRL_STATUS  _SFR_MEM8(0x1002)
#define NVMCTRL_INTCTRL  _SFR_MEM8(0x1003)
#define NVMCTRL_INTFLAGS  _SFR_MEM8(0x1004)
#define NVMCTRL_DATA  _SFR_MEM16(0x1006)
#define NVMCTRL_DATAL  _SFR_MEM8(0x1006)
#define NVMCTRL_DATAH  _SFR_MEM8(0x1007)
#define NVMCTRL_ADDR  _SFR_MEM32(0x1008)
#define NVMCTRL_ADDR0  _SFR_MEM8(0x1008)
#define NVMCTRL_ADDR1  _SFR_MEM8(0x1009)
#define NVMCTRL_ADDR2  _SFR_MEM8(0x100A)
#define NVMCTRL_ADDR3  _SFR_MEM8(0x100B)
#define NVMCTRL_LOCKBITS  _SFR_MEM8(0x100B)
#define NVMCTRL_HIDDENCTRLA  _SFR_MEM8(0x100C)
#define NVMCTRL_TESTCTRLA  _SFR_MEM8(0x100D)
#define NVMCTRL_TESTCTRLB  _SFR_MEM8(0x100E)
#define NVMCTRL_TESTCTRLC  _SFR_MEM8(0x100F)
#define NVMCTRL_TESTCTRLD  _SFR_MEM8(0x1010)
#define NVMCTRL_TESTCTRLE  _SFR_MEM8(0x1011)
#define NVMCTRL_TESTCTRLF  _SFR_MEM8(0x1012)
#define NVMCTRL_TESTCTRLG  _SFR_MEM8(0x1013)
#define NVMCTRL_TESTCTRLH  _SFR_MEM8(0x1014)
#define NVMCTRL_TESTCTRLI  _SFR_MEM8(0x1015)
#define NVMCTRL_TESTCTRLJ  _SFR_MEM8(0x1016)
#define NVMCTRL_TESTCTRLK  _SFR_MEM8(0x1017)
#define NVMCTRL_TESTCTRLL  _SFR_MEM8(0x1018)
#define NVMCTRL_CALA  _SFR_MEM8(0x1019)
#define NVMCTRL_CALB  _SFR_MEM8(0x101A)
#define NVMCTRL_CALC  _SFR_MEM8(0x101B)
#define NVMCTRL_CALD  _SFR_MEM8(0x101C)
#define NVMCTRL_CALE  _SFR_MEM8(0x101D)
#define NVMCTRL_CALF  _SFR_MEM8(0x101E)
#define NVMCTRL_CALG  _SFR_MEM8(0x101F)


/* LOCK - Lockbit */
#define LOCK_KEY  _SFR_MEM32(0x1040)
#define LOCK_KEY0  _SFR_MEM8(0x1040)
#define LOCK_KEY1  _SFR_MEM8(0x1041)
#define LOCK_KEY2  _SFR_MEM8(0x1042)
#define LOCK_KEY3  _SFR_MEM8(0x1043)


/* FUSE - Fuses */
#define FUSE_WDTCFG  _SFR_MEM8(0x1050)
#define FUSE_BODCFG  _SFR_MEM8(0x1051)
#define FUSE_OSCCFG  _SFR_MEM8(0x1052)
#define FUSE_SYSCFG0  _SFR_MEM8(0x1055)
#define FUSE_SYSCFG1  _SFR_MEM8(0x1056)
#define FUSE_CODESIZE  _SFR_MEM8(0x1057)
#define FUSE_BOOTSIZE  _SFR_MEM8(0x1058)


/* SIGROW - Signature row */
#define SIGROW_DEVICEID0  _SFR_MEM8(0x1100)
#define SIGROW_DEVICEID1  _SFR_MEM8(0x1101)
#define SIGROW_DEVICEID2  _SFR_MEM8(0x1102)
#define SIGROW_TEMPSENSE0  _SFR_MEM16(0x1104)
#define SIGROW_TEMPSENSE0L  _SFR_MEM8(0x1104)
#define SIGROW_TEMPSENSE0H  _SFR_MEM8(0x1105)
#define SIGROW_TEMPSENSE1  _SFR_MEM16(0x1106)
#define SIGROW_TEMPSENSE1L  _SFR_MEM8(0x1106)
#define SIGROW_TEMPSENSE1H  _SFR_MEM8(0x1107)
#define SIGROW_SERNUM0  _SFR_MEM8(0x1110)
#define SIGROW_SERNUM1  _SFR_MEM8(0x1111)
#define SIGROW_SERNUM2  _SFR_MEM8(0x1112)
#define SIGROW_SERNUM3  _SFR_MEM8(0x1113)
#define SIGROW_SERNUM4  _SFR_MEM8(0x1114)
#define SIGROW_SERNUM5  _SFR_MEM8(0x1115)
#define SIGROW_SERNUM6  _SFR_MEM8(0x1116)
#define SIGROW_SERNUM7  _SFR_MEM8(0x1117)
#define SIGROW_SERNUM8  _SFR_MEM8(0x1118)
#define SIGROW_SERNUM9  _SFR_MEM8(0x1119)
#define SIGROW_SERNUM10  _SFR_MEM8(0x111A)
#define SIGROW_SERNUM11  _SFR_MEM8(0x111B)
#define SIGROW_SERNUM12  _SFR_MEM8(0x111C)
#define SIGROW_SERNUM13  _SFR_MEM8(0x111D)
#define SIGROW_SERNUM14  _SFR_MEM8(0x111E)
#define SIGROW_SERNUM15  _SFR_MEM8(0x111F)


/* USERROW - User Row */
#define USERROW_USERROW  _SFR_MEM8(0x1200)



/*================== Bitfield Definitions ================== */

/* AC - Analog Comparator */
/* AC.CTRLA  bit masks and bit positions */
#define AC_ENABLE_bm  0x01  /* Enable bit mask. */
#define AC_ENABLE_bp  0  /* Enable bit position. */
#define AC_HYSMODE_gm  0x06  /* Hysteresis Mode group mask. */
#define AC_HYSMODE_gp  1  /* Hysteresis Mode group position. */
#define AC_HYSMODE_0_bm  (1<<1)  /* Hysteresis Mode bit 0 mask. */
#define AC_HYSMODE_0_bp  1  /* Hysteresis Mode bit 0 position. */
#define AC_HYSMODE_1_bm  (1<<2)  /* Hysteresis Mode bit 1 mask. */
#define AC_HYSMODE_1_bp  2  /* Hysteresis Mode bit 1 position. */
#define AC_POWER_gm  0x18  /* Power profile group mask. */
#define AC_POWER_gp  3  /* Power profile group position. */
#define AC_POWER_0_bm  (1<<3)  /* Power profile bit 0 mask. */
#define AC_POWER_0_bp  3  /* Power profile bit 0 position. */
#define AC_POWER_1_bm  (1<<4)  /* Power profile bit 1 mask. */
#define AC_POWER_1_bp  4  /* Power profile bit 1 position. */
#define AC_OUTEN_bm  0x40  /* Output Pad Enable bit mask. */
#define AC_OUTEN_bp  6  /* Output Pad Enable bit position. */
#define AC_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define AC_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */

/* AC.CTRLB  bit masks and bit positions */
#define AC_WINSEL_gm  0x03  /* Window selection mode group mask. */
#define AC_WINSEL_gp  0  /* Window selection mode group position. */
#define AC_WINSEL_0_bm  (1<<0)  /* Window selection mode bit 0 mask. */
#define AC_WINSEL_0_bp  0  /* Window selection mode bit 0 position. */
#define AC_WINSEL_1_bm  (1<<1)  /* Window selection mode bit 1 mask. */
#define AC_WINSEL_1_bp  1  /* Window selection mode bit 1 position. */

/* AC.MUXCTRL  bit masks and bit positions */
#define AC_MUXNEG_gm  0x07  /* Negative Input MUX Selection group mask. */
#define AC_MUXNEG_gp  0  /* Negative Input MUX Selection group position. */
#define AC_MUXNEG_0_bm  (1<<0)  /* Negative Input MUX Selection bit 0 mask. */
#define AC_MUXNEG_0_bp  0  /* Negative Input MUX Selection bit 0 position. */
#define AC_MUXNEG_1_bm  (1<<1)  /* Negative Input MUX Selection bit 1 mask. */
#define AC_MUXNEG_1_bp  1  /* Negative Input MUX Selection bit 1 position. */
#define AC_MUXNEG_2_bm  (1<<2)  /* Negative Input MUX Selection bit 2 mask. */
#define AC_MUXNEG_2_bp  2  /* Negative Input MUX Selection bit 2 position. */
#define AC_MUXPOS_gm  0x38  /* Positive Input MUX Selection group mask. */
#define AC_MUXPOS_gp  3  /* Positive Input MUX Selection group position. */
#define AC_MUXPOS_0_bm  (1<<3)  /* Positive Input MUX Selection bit 0 mask. */
#define AC_MUXPOS_0_bp  3  /* Positive Input MUX Selection bit 0 position. */
#define AC_MUXPOS_1_bm  (1<<4)  /* Positive Input MUX Selection bit 1 mask. */
#define AC_MUXPOS_1_bp  4  /* Positive Input MUX Selection bit 1 position. */
#define AC_MUXPOS_2_bm  (1<<5)  /* Positive Input MUX Selection bit 2 mask. */
#define AC_MUXPOS_2_bp  5  /* Positive Input MUX Selection bit 2 position. */
#define AC_INITVAL_bm  0x40  /* AC Output Initial Value bit mask. */
#define AC_INITVAL_bp  6  /* AC Output Initial Value bit position. */
#define AC_INVERT_bm  0x80  /* Invert AC Output bit mask. */
#define AC_INVERT_bp  7  /* Invert AC Output bit position. */

/* AC.DACREF  bit masks and bit positions */
#define AC_DACREF_gm  0xFF  /* DACREF group mask. */
#define AC_DACREF_gp  0  /* DACREF group position. */
#define AC_DACREF_0_bm  (1<<0)  /* DACREF bit 0 mask. */
#define AC_DACREF_0_bp  0  /* DACREF bit 0 position. */
#define AC_DACREF_1_bm  (1<<1)  /* DACREF bit 1 mask. */
#define AC_DACREF_1_bp  1  /* DACREF bit 1 position. */
#define AC_DACREF_2_bm  (1<<2)  /* DACREF bit 2 mask. */
#define AC_DACREF_2_bp  2  /* DACREF bit 2 position. */
#define AC_DACREF_3_bm  (1<<3)  /* DACREF bit 3 mask. */
#define AC_DACREF_3_bp  3  /* DACREF bit 3 position. */
#define AC_DACREF_4_bm  (1<<4)  /* DACREF bit 4 mask. */
#define AC_DACREF_4_bp  4  /* DACREF bit 4 position. */
#define AC_DACREF_5_bm  (1<<5)  /* DACREF bit 5 mask. */
#define AC_DACREF_5_bp  5  /* DACREF bit 5 position. */
#define AC_DACREF_6_bm  (1<<6)  /* DACREF bit 6 mask. */
#define AC_DACREF_6_bp  6  /* DACREF bit 6 position. */
#define AC_DACREF_7_bm  (1<<7)  /* DACREF bit 7 mask. */
#define AC_DACREF_7_bp  7  /* DACREF bit 7 position. */

/* AC.INTCTRL  bit masks and bit positions */
#define AC_CMP_bm  0x01  /* Interrupt Enable bit mask. */
#define AC_CMP_bp  0  /* Interrupt Enable bit position. */
#define AC_INTMODE_NORMAL_gm  0x30  /* Interrupt Mode group mask. */
#define AC_INTMODE_NORMAL_gp  4  /* Interrupt Mode group position. */
#define AC_INTMODE_NORMAL_0_bm  (1<<4)  /* Interrupt Mode bit 0 mask. */
#define AC_INTMODE_NORMAL_0_bp  4  /* Interrupt Mode bit 0 position. */
#define AC_INTMODE_NORMAL_1_bm  (1<<5)  /* Interrupt Mode bit 1 mask. */
#define AC_INTMODE_NORMAL_1_bp  5  /* Interrupt Mode bit 1 position. */
#define AC_INTMODE_WINDOW_gm  0x30  /* Interrupt Mode group mask. */
#define AC_INTMODE_WINDOW_gp  4  /* Interrupt Mode group position. */
#define AC_INTMODE_WINDOW_0_bm  (1<<4)  /* Interrupt Mode bit 0 mask. */
#define AC_INTMODE_WINDOW_0_bp  4  /* Interrupt Mode bit 0 position. */
#define AC_INTMODE_WINDOW_1_bm  (1<<5)  /* Interrupt Mode bit 1 mask. */
#define AC_INTMODE_WINDOW_1_bp  5  /* Interrupt Mode bit 1 position. */

/* AC.STATUS  bit masks and bit positions */
#define AC_CMPIF_bm  0x01  /* Analog Comparator Interrupt Flag bit mask. */
#define AC_CMPIF_bp  0  /* Analog Comparator Interrupt Flag bit position. */
#define AC_CMPSTATE_bm  0x10  /* Analog Comparator State bit mask. */
#define AC_CMPSTATE_bp  4  /* Analog Comparator State bit position. */
#define AC_WINSTATE_gm  0xC0  /* Analog Comparator Window State group mask. */
#define AC_WINSTATE_gp  6  /* Analog Comparator Window State group position. */
#define AC_WINSTATE_0_bm  (1<<6)  /* Analog Comparator Window State bit 0 mask. */
#define AC_WINSTATE_0_bp  6  /* Analog Comparator Window State bit 0 position. */
#define AC_WINSTATE_1_bm  (1<<7)  /* Analog Comparator Window State bit 1 mask. */
#define AC_WINSTATE_1_bp  7  /* Analog Comparator Window State bit 1 position. */


/* CCL - Configurable Custom Logic */
/* CCL.CTRLA  bit masks and bit positions */
#define CCL_ENABLE_bm  0x01  /* Enable bit mask. */
#define CCL_ENABLE_bp  0  /* Enable bit position. */
#define CCL_RUNSTDBY_bm  0x40  /* Run in Standby bit mask. */
#define CCL_RUNSTDBY_bp  6  /* Run in Standby bit position. */

/* CCL.SEQCTRL0  bit masks and bit positions */
#define CCL_SEQSEL_gm  0x07  /* Sequential Selection group mask. */
#define CCL_SEQSEL_gp  0  /* Sequential Selection group position. */
#define CCL_SEQSEL_0_bm  (1<<0)  /* Sequential Selection bit 0 mask. */
#define CCL_SEQSEL_0_bp  0  /* Sequential Selection bit 0 position. */
#define CCL_SEQSEL_1_bm  (1<<1)  /* Sequential Selection bit 1 mask. */
#define CCL_SEQSEL_1_bp  1  /* Sequential Selection bit 1 position. */
#define CCL_SEQSEL_2_bm  (1<<2)  /* Sequential Selection bit 2 mask. */
#define CCL_SEQSEL_2_bp  2  /* Sequential Selection bit 2 position. */

/* CCL.SEQCTRL1  bit masks and bit positions */
/* CCL_SEQSEL  is already defined. */

/* CCL.INTCTRL0  bit masks and bit positions */
#define CCL_INTMODE0_gm  0x03  /* Interrupt Mode for LUT0 group mask. */
#define CCL_INTMODE0_gp  0  /* Interrupt Mode for LUT0 group position. */
#define CCL_INTMODE0_0_bm  (1<<0)  /* Interrupt Mode for LUT0 bit 0 mask. */
#define CCL_INTMODE0_0_bp  0  /* Interrupt Mode for LUT0 bit 0 position. */
#define CCL_INTMODE0_1_bm  (1<<1)  /* Interrupt Mode for LUT0 bit 1 mask. */
#define CCL_INTMODE0_1_bp  1  /* Interrupt Mode for LUT0 bit 1 position. */
#define CCL_INTMODE1_gm  0x0C  /* Interrupt Mode for LUT1 group mask. */
#define CCL_INTMODE1_gp  2  /* Interrupt Mode for LUT1 group position. */
#define CCL_INTMODE1_0_bm  (1<<2)  /* Interrupt Mode for LUT1 bit 0 mask. */
#define CCL_INTMODE1_0_bp  2  /* Interrupt Mode for LUT1 bit 0 position. */
#define CCL_INTMODE1_1_bm  (1<<3)  /* Interrupt Mode for LUT1 bit 1 mask. */
#define CCL_INTMODE1_1_bp  3  /* Interrupt Mode for LUT1 bit 1 position. */
#define CCL_INTMODE2_gm  0x30  /* Interrupt Mode for LUT2 group mask. */
#define CCL_INTMODE2_gp  4  /* Interrupt Mode for LUT2 group position. */
#define CCL_INTMODE2_0_bm  (1<<4)  /* Interrupt Mode for LUT2 bit 0 mask. */
#define CCL_INTMODE2_0_bp  4  /* Interrupt Mode for LUT2 bit 0 position. */
#define CCL_INTMODE2_1_bm  (1<<5)  /* Interrupt Mode for LUT2 bit 1 mask. */
#define CCL_INTMODE2_1_bp  5  /* Interrupt Mode for LUT2 bit 1 position. */
#define CCL_INTMODE3_gm  0xC0  /* Interrupt Mode for LUT3 group mask. */
#define CCL_INTMODE3_gp  6  /* Interrupt Mode for LUT3 group position. */
#define CCL_INTMODE3_0_bm  (1<<6)  /* Interrupt Mode for LUT3 bit 0 mask. */
#define CCL_INTMODE3_0_bp  6  /* Interrupt Mode for LUT3 bit 0 position. */
#define CCL_INTMODE3_1_bm  (1<<7)  /* Interrupt Mode for LUT3 bit 1 mask. */
#define CCL_INTMODE3_1_bp  7  /* Interrupt Mode for LUT3 bit 1 position. */

/* CCL.INTFLAGS  bit masks and bit positions */
#define CCL_INT_gm  0x0F  /* Interrupt Flag group mask. */
#define CCL_INT_gp  0  /* Interrupt Flag group position. */
#define CCL_INT_0_bm  (1<<0)  /* Interrupt Flag bit 0 mask. */
#define CCL_INT_0_bp  0  /* Interrupt Flag bit 0 position. */
#define CCL_INT0_bm  CCL_INT_0_bm  /* This define is deprecated and should not be used */
#define CCL_INT0_bp  CCL_INT_0_bp  /* This define is deprecated and should not be used */
#define CCL_INT_1_bm  (1<<1)  /* Interrupt Flag bit 1 mask. */
#define CCL_INT_1_bp  1  /* Interrupt Flag bit 1 position. */
#define CCL_INT1_bm  CCL_INT_1_bm  /* This define is deprecated and should not be used */
#define CCL_INT1_bp  CCL_INT_1_bp  /* This define is deprecated and should not be used */
#define CCL_INT_2_bm  (1<<2)  /* Interrupt Flag bit 2 mask. */
#define CCL_INT_2_bp  2  /* Interrupt Flag bit 2 position. */
#define CCL_INT2_bm  CCL_INT_2_bm  /* This define is deprecated and should not be used */
#define CCL_INT2_bp  CCL_INT_2_bp  /* This define is deprecated and should not be used */
#define CCL_INT_3_bm  (1<<3)  /* Interrupt Flag bit 3 mask. */
#define CCL_INT_3_bp  3  /* Interrupt Flag bit 3 position. */
#define CCL_INT3_bm  CCL_INT_3_bm  /* This define is deprecated and should not be used */
#define CCL_INT3_bp  CCL_INT_3_bp  /* This define is deprecated and should not be used */

/* CCL.LUT0CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
#define CCL_CLKSRC_gm  0x0E  /* Clock Source Selection group mask. */
#define CCL_CLKSRC_gp  1  /* Clock Source Selection group position. */
#define CCL_CLKSRC_0_bm  (1<<1)  /* Clock Source Selection bit 0 mask. */
#define CCL_CLKSRC_0_bp  1  /* Clock Source Selection bit 0 position. */
#define CCL_CLKSRC_1_bm  (1<<2)  /* Clock Source Selection bit 1 mask. */
#define CCL_CLKSRC_1_bp  2  /* Clock Source Selection bit 1 position. */
#define CCL_CLKSRC_2_bm  (1<<3)  /* Clock Source Selection bit 2 mask. */
#define CCL_CLKSRC_2_bp  3  /* Clock Source Selection bit 2 position. */
#define CCL_FILTSEL_gm  0x30  /* Filter Selection group mask. */
#define CCL_FILTSEL_gp  4  /* Filter Selection group position. */
#define CCL_FILTSEL_0_bm  (1<<4)  /* Filter Selection bit 0 mask. */
#define CCL_FILTSEL_0_bp  4  /* Filter Selection bit 0 position. */
#define CCL_FILTSEL_1_bm  (1<<5)  /* Filter Selection bit 1 mask. */
#define CCL_FILTSEL_1_bp  5  /* Filter Selection bit 1 position. */
#define CCL_OUTEN_bm  0x40  /* Output Enable bit mask. */
#define CCL_OUTEN_bp  6  /* Output Enable bit position. */
#define CCL_EDGEDET_bm  0x80  /* Edge Detection Enable bit mask. */
#define CCL_EDGEDET_bp  7  /* Edge Detection Enable bit position. */

/* CCL.LUT0CTRLB  bit masks and bit positions */
#define CCL_INSEL0_gm  0x0F  /* LUT Input 0 Source Selection group mask. */
#define CCL_INSEL0_gp  0  /* LUT Input 0 Source Selection group position. */
#define CCL_INSEL0_0_bm  (1<<0)  /* LUT Input 0 Source Selection bit 0 mask. */
#define CCL_INSEL0_0_bp  0  /* LUT Input 0 Source Selection bit 0 position. */
#define CCL_INSEL0_1_bm  (1<<1)  /* LUT Input 0 Source Selection bit 1 mask. */
#define CCL_INSEL0_1_bp  1  /* LUT Input 0 Source Selection bit 1 position. */
#define CCL_INSEL0_2_bm  (1<<2)  /* LUT Input 0 Source Selection bit 2 mask. */
#define CCL_INSEL0_2_bp  2  /* LUT Input 0 Source Selection bit 2 position. */
#define CCL_INSEL0_3_bm  (1<<3)  /* LUT Input 0 Source Selection bit 3 mask. */
#define CCL_INSEL0_3_bp  3  /* LUT Input 0 Source Selection bit 3 position. */
#define CCL_INSEL1_gm  0xF0  /* LUT Input 1 Source Selection group mask. */
#define CCL_INSEL1_gp  4  /* LUT Input 1 Source Selection group position. */
#define CCL_INSEL1_0_bm  (1<<4)  /* LUT Input 1 Source Selection bit 0 mask. */
#define CCL_INSEL1_0_bp  4  /* LUT Input 1 Source Selection bit 0 position. */
#define CCL_INSEL1_1_bm  (1<<5)  /* LUT Input 1 Source Selection bit 1 mask. */
#define CCL_INSEL1_1_bp  5  /* LUT Input 1 Source Selection bit 1 position. */
#define CCL_INSEL1_2_bm  (1<<6)  /* LUT Input 1 Source Selection bit 2 mask. */
#define CCL_INSEL1_2_bp  6  /* LUT Input 1 Source Selection bit 2 position. */
#define CCL_INSEL1_3_bm  (1<<7)  /* LUT Input 1 Source Selection bit 3 mask. */
#define CCL_INSEL1_3_bp  7  /* LUT Input 1 Source Selection bit 3 position. */

/* CCL.LUT0CTRLC  bit masks and bit positions */
#define CCL_INSEL2_gm  0x0F  /* LUT Input 2 Source Selection group mask. */
#define CCL_INSEL2_gp  0  /* LUT Input 2 Source Selection group position. */
#define CCL_INSEL2_0_bm  (1<<0)  /* LUT Input 2 Source Selection bit 0 mask. */
#define CCL_INSEL2_0_bp  0  /* LUT Input 2 Source Selection bit 0 position. */
#define CCL_INSEL2_1_bm  (1<<1)  /* LUT Input 2 Source Selection bit 1 mask. */
#define CCL_INSEL2_1_bp  1  /* LUT Input 2 Source Selection bit 1 position. */
#define CCL_INSEL2_2_bm  (1<<2)  /* LUT Input 2 Source Selection bit 2 mask. */
#define CCL_INSEL2_2_bp  2  /* LUT Input 2 Source Selection bit 2 position. */
#define CCL_INSEL2_3_bm  (1<<3)  /* LUT Input 2 Source Selection bit 3 mask. */
#define CCL_INSEL2_3_bp  3  /* LUT Input 2 Source Selection bit 3 position. */

/* CCL.TRUTH0  bit masks and bit positions */
#define CCL_TRUTH_gm  0xFF  /* Truth Table group mask. */
#define CCL_TRUTH_gp  0  /* Truth Table group position. */
#define CCL_TRUTH_0_bm  (1<<0)  /* Truth Table bit 0 mask. */
#define CCL_TRUTH_0_bp  0  /* Truth Table bit 0 position. */
#define CCL_TRUTH_1_bm  (1<<1)  /* Truth Table bit 1 mask. */
#define CCL_TRUTH_1_bp  1  /* Truth Table bit 1 position. */
#define CCL_TRUTH_2_bm  (1<<2)  /* Truth Table bit 2 mask. */
#define CCL_TRUTH_2_bp  2  /* Truth Table bit 2 position. */
#define CCL_TRUTH_3_bm  (1<<3)  /* Truth Table bit 3 mask. */
#define CCL_TRUTH_3_bp  3  /* Truth Table bit 3 position. */
#define CCL_TRUTH_4_bm  (1<<4)  /* Truth Table bit 4 mask. */
#define CCL_TRUTH_4_bp  4  /* Truth Table bit 4 position. */
#define CCL_TRUTH_5_bm  (1<<5)  /* Truth Table bit 5 mask. */
#define CCL_TRUTH_5_bp  5  /* Truth Table bit 5 position. */
#define CCL_TRUTH_6_bm  (1<<6)  /* Truth Table bit 6 mask. */
#define CCL_TRUTH_6_bp  6  /* Truth Table bit 6 position. */
#define CCL_TRUTH_7_bm  (1<<7)  /* Truth Table bit 7 mask. */
#define CCL_TRUTH_7_bp  7  /* Truth Table bit 7 position. */

/* CCL.LUT1CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT1CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT1CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */

/* CCL.TRUTH1  bit masks and bit positions */
/* CCL_TRUTH  is already defined. */

/* CCL.LUT2CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT2CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT2CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */

/* CCL.TRUTH2  bit masks and bit positions */
/* CCL_TRUTH  is already defined. */

/* CCL.LUT3CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT3CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT3CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */

/* CCL.TRUTH3  bit masks and bit positions */
/* CCL_TRUTH  is already defined. */


/* CLKCTRL - Clock controller */
/* CLKCTRL.MCLKCTRLA  bit masks and bit positions */
#define CLKCTRL_CLKSEL_gm  0x07  /* clock select group mask. */
#define CLKCTRL_CLKSEL_gp  0  /* clock select group position. */
#define CLKCTRL_CLKSEL_0_bm  (1<<0)  /* clock select bit 0 mask. */
#define CLKCTRL_CLKSEL_0_bp  0  /* clock select bit 0 position. */
#define CLKCTRL_CLKSEL_1_bm  (1<<1)  /* clock select bit 1 mask. */
#define CLKCTRL_CLKSEL_1_bp  1  /* clock select bit 1 position. */
#define CLKCTRL_CLKSEL_2_bm  (1<<2)  /* clock select bit 2 mask. */
#define CLKCTRL_CLKSEL_2_bp  2  /* clock select bit 2 position. */
#define CLKCTRL_CLKOUT_bm  0x80  /* System clock out bit mask. */
#define CLKCTRL_CLKOUT_bp  7  /* System clock out bit position. */

/* CLKCTRL.MCLKCTRLB  bit masks and bit positions */
#define CLKCTRL_PEN_bm  0x01  /* Prescaler enable bit mask. */
#define CLKCTRL_PEN_bp  0  /* Prescaler enable bit position. */
#define CLKCTRL_PDIV_gm  0x1E  /* Prescaler division group mask. */
#define CLKCTRL_PDIV_gp  1  /* Prescaler division group position. */
#define CLKCTRL_PDIV_0_bm  (1<<1)  /* Prescaler division bit 0 mask. */
#define CLKCTRL_PDIV_0_bp  1  /* Prescaler division bit 0 position. */
#define CLKCTRL_PDIV_1_bm  (1<<2)  /* Prescaler division bit 1 mask. */
#define CLKCTRL_PDIV_1_bp  2  /* Prescaler division bit 1 position. */
#define CLKCTRL_PDIV_2_bm  (1<<3)  /* Prescaler division bit 2 mask. */
#define CLKCTRL_PDIV_2_bp  3  /* Prescaler division bit 2 position. */
#define CLKCTRL_PDIV_3_bm  (1<<4)  /* Prescaler division bit 3 mask. */
#define CLKCTRL_PDIV_3_bp  4  /* Prescaler division bit 3 position. */

/* CLKCTRL.MCLKLOCK  bit masks and bit positions */
#define CLKCTRL_LOCKEN_bm  0x01  /* lock ebable bit mask. */
#define CLKCTRL_LOCKEN_bp  0  /* lock ebable bit position. */

/* CLKCTRL.MCLKSTATUS  bit masks and bit positions */
#define CLKCTRL_SOSC_bm  0x01  /* System Oscillator changing bit mask. */
#define CLKCTRL_SOSC_bp  0  /* System Oscillator changing bit position. */
#define CLKCTRL_OSCHFS_bm  0x02  /* High frequency oscillator status bit mask. */
#define CLKCTRL_OSCHFS_bp  1  /* High frequency oscillator status bit position. */
#define CLKCTRL_OSC32KS_bm  0x04  /* 32KHz oscillator status bit mask. */
#define CLKCTRL_OSC32KS_bp  2  /* 32KHz oscillator status bit position. */
#define CLKCTRL_XOSC32KS_bm  0x08  /* 32.768 kHz Crystal Oscillator status bit mask. */
#define CLKCTRL_XOSC32KS_bp  3  /* 32.768 kHz Crystal Oscillator status bit position. */
#define CLKCTRL_EXTS_bm  0x10  /* External Clock status bit mask. */
#define CLKCTRL_EXTS_bp  4  /* External Clock status bit position. */
#define CLKCTRL_PLLS_bm  0x20  /* PLL oscillator status bit mask. */
#define CLKCTRL_PLLS_bp  5  /* PLL oscillator status bit position. */

/* CLKCTRL.MCLKSTATUSB  bit masks and bit positions */
#define CLKCTRL_OSCPDIS_bm  0x01  /* PDI oscillator status bit mask. */
#define CLKCTRL_OSCPDIS_bp  0  /* PDI oscillator status bit position. */
#define CLKCTRL_EXTPDIS_bm  0x02  /* External PDI oscillator status bit mask. */
#define CLKCTRL_EXTPDIS_bp  1  /* External PDI oscillator status bit position. */
#define CLKCTRL_OSC600K_bm  0x04  /* 600K oscillator status bit mask. */
#define CLKCTRL_OSC600K_bp  2  /* 600K oscillator status bit position. */

/* CLKCTRL.OSCHFCTRLA  bit masks and bit positions */
#define CLKCTRL_AUTOTUNE_bm  0x01  /* Autotune bit mask. */
#define CLKCTRL_AUTOTUNE_bp  0  /* Autotune bit position. */
#define CLKCTRL_FREQSEL_gm  0x3C  /* Frequency select group mask. */
#define CLKCTRL_FREQSEL_gp  2  /* Frequency select group position. */
#define CLKCTRL_FREQSEL_0_bm  (1<<2)  /* Frequency select bit 0 mask. */
#define CLKCTRL_FREQSEL_0_bp  2  /* Frequency select bit 0 position. */
#define CLKCTRL_FREQSEL_1_bm  (1<<3)  /* Frequency select bit 1 mask. */
#define CLKCTRL_FREQSEL_1_bp  3  /* Frequency select bit 1 position. */
#define CLKCTRL_FREQSEL_2_bm  (1<<4)  /* Frequency select bit 2 mask. */
#define CLKCTRL_FREQSEL_2_bp  4  /* Frequency select bit 2 position. */
#define CLKCTRL_FREQSEL_3_bm  (1<<5)  /* Frequency select bit 3 mask. */
#define CLKCTRL_FREQSEL_3_bp  5  /* Frequency select bit 3 position. */
#define CLKCTRL_RUNSTDBY_bm  0x80  /* Run standby bit mask. */
#define CLKCTRL_RUNSTDBY_bp  7  /* Run standby bit position. */

/* CLKCTRL.OSCHFTUNE  bit masks and bit positions */
#define CLKCTRL_TUNE_gm  0xFF  /* Tune group mask. */
#define CLKCTRL_TUNE_gp  0  /* Tune group position. */
#define CLKCTRL_TUNE_0_bm  (1<<0)  /* Tune bit 0 mask. */
#define CLKCTRL_TUNE_0_bp  0  /* Tune bit 0 position. */
#define CLKCTRL_TUNE_1_bm  (1<<1)  /* Tune bit 1 mask. */
#define CLKCTRL_TUNE_1_bp  1  /* Tune bit 1 position. */
#define CLKCTRL_TUNE_2_bm  (1<<2)  /* Tune bit 2 mask. */
#define CLKCTRL_TUNE_2_bp  2  /* Tune bit 2 position. */
#define CLKCTRL_TUNE_3_bm  (1<<3)  /* Tune bit 3 mask. */
#define CLKCTRL_TUNE_3_bp  3  /* Tune bit 3 position. */
#define CLKCTRL_TUNE_4_bm  (1<<4)  /* Tune bit 4 mask. */
#define CLKCTRL_TUNE_4_bp  4  /* Tune bit 4 position. */
#define CLKCTRL_TUNE_5_bm  (1<<5)  /* Tune bit 5 mask. */
#define CLKCTRL_TUNE_5_bp  5  /* Tune bit 5 position. */
#define CLKCTRL_TUNE_6_bm  (1<<6)  /* Tune bit 6 mask. */
#define CLKCTRL_TUNE_6_bp  6  /* Tune bit 6 position. */
#define CLKCTRL_TUNE_7_bm  (1<<7)  /* Tune bit 7 mask. */
#define CLKCTRL_TUNE_7_bp  7  /* Tune bit 7 position. */

/* CLKCTRL.OSCHFCALL  bit masks and bit positions */
#define CLKCTRL_FCAL_gm  0xFF  /* Freq Calibration group mask. */
#define CLKCTRL_FCAL_gp  0  /* Freq Calibration group position. */
#define CLKCTRL_FCAL_0_bm  (1<<0)  /* Freq Calibration bit 0 mask. */
#define CLKCTRL_FCAL_0_bp  0  /* Freq Calibration bit 0 position. */
#define CLKCTRL_FCAL_1_bm  (1<<1)  /* Freq Calibration bit 1 mask. */
#define CLKCTRL_FCAL_1_bp  1  /* Freq Calibration bit 1 position. */
#define CLKCTRL_FCAL_2_bm  (1<<2)  /* Freq Calibration bit 2 mask. */
#define CLKCTRL_FCAL_2_bp  2  /* Freq Calibration bit 2 position. */
#define CLKCTRL_FCAL_3_bm  (1<<3)  /* Freq Calibration bit 3 mask. */
#define CLKCTRL_FCAL_3_bp  3  /* Freq Calibration bit 3 position. */
#define CLKCTRL_FCAL_4_bm  (1<<4)  /* Freq Calibration bit 4 mask. */
#define CLKCTRL_FCAL_4_bp  4  /* Freq Calibration bit 4 position. */
#define CLKCTRL_FCAL_5_bm  (1<<5)  /* Freq Calibration bit 5 mask. */
#define CLKCTRL_FCAL_5_bp  5  /* Freq Calibration bit 5 position. */
#define CLKCTRL_FCAL_6_bm  (1<<6)  /* Freq Calibration bit 6 mask. */
#define CLKCTRL_FCAL_6_bp  6  /* Freq Calibration bit 6 position. */
#define CLKCTRL_FCAL_7_bm  (1<<7)  /* Freq Calibration bit 7 mask. */
#define CLKCTRL_FCAL_7_bp  7  /* Freq Calibration bit 7 position. */

/* CLKCTRL.OSCHFCALH  bit masks and bit positions */
/* CLKCTRL_FCAL  is already defined. */

/* CLKCTRL.OSCHFTCAL  bit masks and bit positions */
#define CLKCTRL_RTEMPCAL_gm  0x1F  /* RTEMPCAL group mask. */
#define CLKCTRL_RTEMPCAL_gp  0  /* RTEMPCAL group position. */
#define CLKCTRL_RTEMPCAL_0_bm  (1<<0)  /* RTEMPCAL bit 0 mask. */
#define CLKCTRL_RTEMPCAL_0_bp  0  /* RTEMPCAL bit 0 position. */
#define CLKCTRL_RTEMPCAL_1_bm  (1<<1)  /* RTEMPCAL bit 1 mask. */
#define CLKCTRL_RTEMPCAL_1_bp  1  /* RTEMPCAL bit 1 position. */
#define CLKCTRL_RTEMPCAL_2_bm  (1<<2)  /* RTEMPCAL bit 2 mask. */
#define CLKCTRL_RTEMPCAL_2_bp  2  /* RTEMPCAL bit 2 position. */
#define CLKCTRL_RTEMPCAL_3_bm  (1<<3)  /* RTEMPCAL bit 3 mask. */
#define CLKCTRL_RTEMPCAL_3_bp  3  /* RTEMPCAL bit 3 position. */
#define CLKCTRL_RTEMPCAL_4_bm  (1<<4)  /* RTEMPCAL bit 4 mask. */
#define CLKCTRL_RTEMPCAL_4_bp  4  /* RTEMPCAL bit 4 position. */
#define CLKCTRL_RNGDN_bm  0x40  /* Range down bit mask. */
#define CLKCTRL_RNGDN_bp  6  /* Range down bit position. */
#define CLKCTRL_RNGUP_bm  0x80  /* Range up bit mask. */
#define CLKCTRL_RNGUP_bp  7  /* Range up bit position. */

/* CLKCTRL.OSCHFTEST  bit masks and bit positions */
#define CLKCTRL_CLKDIS_bm  0x01  /* Clock disable bit mask. */
#define CLKCTRL_CLKDIS_bp  0  /* Clock disable bit position. */
#define CLKCTRL_ZEROSUT_bm  0x20  /* Zero SUT bit mask. */
#define CLKCTRL_ZEROSUT_bp  5  /* Zero SUT bit position. */

/* CLKCTRL.PLLCTRLA  bit masks and bit positions */
#define CLKCTRL_MULFAC_gm  0x03  /* Multiplication factor group mask. */
#define CLKCTRL_MULFAC_gp  0  /* Multiplication factor group position. */
#define CLKCTRL_MULFAC_0_bm  (1<<0)  /* Multiplication factor bit 0 mask. */
#define CLKCTRL_MULFAC_0_bp  0  /* Multiplication factor bit 0 position. */
#define CLKCTRL_MULFAC_1_bm  (1<<1)  /* Multiplication factor bit 1 mask. */
#define CLKCTRL_MULFAC_1_bp  1  /* Multiplication factor bit 1 position. */
#define CLKCTRL_SOURCE_bm  0x10  /* Source bit mask. */
#define CLKCTRL_SOURCE_bp  4  /* Source bit position. */
/* CLKCTRL_RUNSTDBY  is already defined. */

/* CLKCTRL.PLLTEST  bit masks and bit positions */
/* CLKCTRL_CLKDIS  is already defined. */
/* CLKCTRL_ZEROSUT  is already defined. */

/* CLKCTRL.OSCPDICAL  bit masks and bit positions */
#define CLKCTRL_OSCPDICAL_gm  0x07  /* PDI Oscillator Calibration group mask. */
#define CLKCTRL_OSCPDICAL_gp  0  /* PDI Oscillator Calibration group position. */
#define CLKCTRL_OSCPDICAL_0_bm  (1<<0)  /* PDI Oscillator Calibration bit 0 mask. */
#define CLKCTRL_OSCPDICAL_0_bp  0  /* PDI Oscillator Calibration bit 0 position. */
#define CLKCTRL_OSCPDICAL_1_bm  (1<<1)  /* PDI Oscillator Calibration bit 1 mask. */
#define CLKCTRL_OSCPDICAL_1_bp  1  /* PDI Oscillator Calibration bit 1 position. */
#define CLKCTRL_OSCPDICAL_2_bm  (1<<2)  /* PDI Oscillator Calibration bit 2 mask. */
#define CLKCTRL_OSCPDICAL_2_bp  2  /* PDI Oscillator Calibration bit 2 position. */

/* CLKCTRL.OSCPDITEST  bit masks and bit positions */
/* CLKCTRL_CLKDIS  is already defined. */
/* CLKCTRL_ZEROSUT  is already defined. */

/* CLKCTRL.OSC32KCTRLA  bit masks and bit positions */
/* CLKCTRL_RUNSTDBY  is already defined. */

/* CLKCTRL.OSC32KCAL  bit masks and bit positions */
#define CLKCTRL_OSC32KCAL_gm  0x3F  /* Calibration group mask. */
#define CLKCTRL_OSC32KCAL_gp  0  /* Calibration group position. */
#define CLKCTRL_OSC32KCAL_0_bm  (1<<0)  /* Calibration bit 0 mask. */
#define CLKCTRL_OSC32KCAL_0_bp  0  /* Calibration bit 0 position. */
#define CLKCTRL_OSC32KCAL_1_bm  (1<<1)  /* Calibration bit 1 mask. */
#define CLKCTRL_OSC32KCAL_1_bp  1  /* Calibration bit 1 position. */
#define CLKCTRL_OSC32KCAL_2_bm  (1<<2)  /* Calibration bit 2 mask. */
#define CLKCTRL_OSC32KCAL_2_bp  2  /* Calibration bit 2 position. */
#define CLKCTRL_OSC32KCAL_3_bm  (1<<3)  /* Calibration bit 3 mask. */
#define CLKCTRL_OSC32KCAL_3_bp  3  /* Calibration bit 3 position. */
#define CLKCTRL_OSC32KCAL_4_bm  (1<<4)  /* Calibration bit 4 mask. */
#define CLKCTRL_OSC32KCAL_4_bp  4  /* Calibration bit 4 position. */
#define CLKCTRL_OSC32KCAL_5_bm  (1<<5)  /* Calibration bit 5 mask. */
#define CLKCTRL_OSC32KCAL_5_bp  5  /* Calibration bit 5 position. */

/* CLKCTRL.OSC32KTEST  bit masks and bit positions */
/* CLKCTRL_CLKDIS  is already defined. */

/* CLKCTRL.XOSC32KCTRLA  bit masks and bit positions */
#define CLKCTRL_ENABLE_bm  0x01  /* Enable bit mask. */
#define CLKCTRL_ENABLE_bp  0  /* Enable bit position. */
#define CLKCTRL_LPMODE_bm  0x02  /* Low power mode bit mask. */
#define CLKCTRL_LPMODE_bp  1  /* Low power mode bit position. */
#define CLKCTRL_SEL_bm  0x04  /* Select bit mask. */
#define CLKCTRL_SEL_bp  2  /* Select bit position. */
#define CLKCTRL_CSUT_gm  0x30  /* Crystal startup time group mask. */
#define CLKCTRL_CSUT_gp  4  /* Crystal startup time group position. */
#define CLKCTRL_CSUT_0_bm  (1<<4)  /* Crystal startup time bit 0 mask. */
#define CLKCTRL_CSUT_0_bp  4  /* Crystal startup time bit 0 position. */
#define CLKCTRL_CSUT_1_bm  (1<<5)  /* Crystal startup time bit 1 mask. */
#define CLKCTRL_CSUT_1_bp  5  /* Crystal startup time bit 1 position. */
/* CLKCTRL_RUNSTDBY  is already defined. */

/* CLKCTRL.XOSC32KTEST  bit masks and bit positions */
/* CLKCTRL_CLKDIS  is already defined. */
#define CLKCTRL_LPTESTEN_bm  0x02  /* LP test enable bit mask. */
#define CLKCTRL_LPTESTEN_bp  1  /* LP test enable bit position. */
/* CLKCTRL_ZEROSUT  is already defined. */


/* CPU - CPU */
/* CPU.CCP  bit masks and bit positions */
#define CPU_CCP_gm  0xFF  /* CCP signature group mask. */
#define CPU_CCP_gp  0  /* CCP signature group position. */
#define CPU_CCP_0_bm  (1<<0)  /* CCP signature bit 0 mask. */
#define CPU_CCP_0_bp  0  /* CCP signature bit 0 position. */
#define CPU_CCP_1_bm  (1<<1)  /* CCP signature bit 1 mask. */
#define CPU_CCP_1_bp  1  /* CCP signature bit 1 position. */
#define CPU_CCP_2_bm  (1<<2)  /* CCP signature bit 2 mask. */
#define CPU_CCP_2_bp  2  /* CCP signature bit 2 position. */
#define CPU_CCP_3_bm  (1<<3)  /* CCP signature bit 3 mask. */
#define CPU_CCP_3_bp  3  /* CCP signature bit 3 position. */
#define CPU_CCP_4_bm  (1<<4)  /* CCP signature bit 4 mask. */
#define CPU_CCP_4_bp  4  /* CCP signature bit 4 position. */
#define CPU_CCP_5_bm  (1<<5)  /* CCP signature bit 5 mask. */
#define CPU_CCP_5_bp  5  /* CCP signature bit 5 position. */
#define CPU_CCP_6_bm  (1<<6)  /* CCP signature bit 6 mask. */
#define CPU_CCP_6_bp  6  /* CCP signature bit 6 position. */
#define CPU_CCP_7_bm  (1<<7)  /* CCP signature bit 7 mask. */
#define CPU_CCP_7_bp  7  /* CCP signature bit 7 position. */

/* CPU.RAMPZ  bit masks and bit positions */
#define CPU_RAMPZ6_bm  0x40  /* Extended Z-Pointer Test Address bits bit mask. */
#define CPU_RAMPZ6_bp  6  /* Extended Z-Pointer Test Address bits bit position. */

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


/* CPUINT - Interrupt Controller */
/* CPUINT.CTRLA  bit masks and bit positions */
#define CPUINT_LVL0RR_bm  0x01  /* Round-robin Scheduling Enable bit mask. */
#define CPUINT_LVL0RR_bp  0  /* Round-robin Scheduling Enable bit position. */
#define CPUINT_CVT_bm  0x20  /* Compact Vector Table bit mask. */
#define CPUINT_CVT_bp  5  /* Compact Vector Table bit position. */
#define CPUINT_IVSEL_bm  0x40  /* Interrupt Vector Select bit mask. */
#define CPUINT_IVSEL_bp  6  /* Interrupt Vector Select bit position. */

/* CPUINT.STATUS  bit masks and bit positions */
#define CPUINT_LVL0EX_bm  0x01  /* Level 0 Interrupt Executing bit mask. */
#define CPUINT_LVL0EX_bp  0  /* Level 0 Interrupt Executing bit position. */
#define CPUINT_LVL1EX_bm  0x02  /* Level 1 Interrupt Executing bit mask. */
#define CPUINT_LVL1EX_bp  1  /* Level 1 Interrupt Executing bit position. */
#define CPUINT_NMIEX_bm  0x80  /* Non-maskable Interrupt Executing bit mask. */
#define CPUINT_NMIEX_bp  7  /* Non-maskable Interrupt Executing bit position. */

/* CPUINT.LVL0PRI  bit masks and bit positions */
#define CPUINT_LVL0PRI_gm  0xFF  /* Interrupt Level Priority group mask. */
#define CPUINT_LVL0PRI_gp  0  /* Interrupt Level Priority group position. */
#define CPUINT_LVL0PRI_0_bm  (1<<0)  /* Interrupt Level Priority bit 0 mask. */
#define CPUINT_LVL0PRI_0_bp  0  /* Interrupt Level Priority bit 0 position. */
#define CPUINT_LVL0PRI_1_bm  (1<<1)  /* Interrupt Level Priority bit 1 mask. */
#define CPUINT_LVL0PRI_1_bp  1  /* Interrupt Level Priority bit 1 position. */
#define CPUINT_LVL0PRI_2_bm  (1<<2)  /* Interrupt Level Priority bit 2 mask. */
#define CPUINT_LVL0PRI_2_bp  2  /* Interrupt Level Priority bit 2 position. */
#define CPUINT_LVL0PRI_3_bm  (1<<3)  /* Interrupt Level Priority bit 3 mask. */
#define CPUINT_LVL0PRI_3_bp  3  /* Interrupt Level Priority bit 3 position. */
#define CPUINT_LVL0PRI_4_bm  (1<<4)  /* Interrupt Level Priority bit 4 mask. */
#define CPUINT_LVL0PRI_4_bp  4  /* Interrupt Level Priority bit 4 position. */
#define CPUINT_LVL0PRI_5_bm  (1<<5)  /* Interrupt Level Priority bit 5 mask. */
#define CPUINT_LVL0PRI_5_bp  5  /* Interrupt Level Priority bit 5 position. */
#define CPUINT_LVL0PRI_6_bm  (1<<6)  /* Interrupt Level Priority bit 6 mask. */
#define CPUINT_LVL0PRI_6_bp  6  /* Interrupt Level Priority bit 6 position. */
#define CPUINT_LVL0PRI_7_bm  (1<<7)  /* Interrupt Level Priority bit 7 mask. */
#define CPUINT_LVL0PRI_7_bp  7  /* Interrupt Level Priority bit 7 position. */

/* CPUINT.LVL1VEC  bit masks and bit positions */
#define CPUINT_LVL1VEC_gm  0xFF  /* Interrupt Vector with High Priority group mask. */
#define CPUINT_LVL1VEC_gp  0  /* Interrupt Vector with High Priority group position. */
#define CPUINT_LVL1VEC_0_bm  (1<<0)  /* Interrupt Vector with High Priority bit 0 mask. */
#define CPUINT_LVL1VEC_0_bp  0  /* Interrupt Vector with High Priority bit 0 position. */
#define CPUINT_LVL1VEC_1_bm  (1<<1)  /* Interrupt Vector with High Priority bit 1 mask. */
#define CPUINT_LVL1VEC_1_bp  1  /* Interrupt Vector with High Priority bit 1 position. */
#define CPUINT_LVL1VEC_2_bm  (1<<2)  /* Interrupt Vector with High Priority bit 2 mask. */
#define CPUINT_LVL1VEC_2_bp  2  /* Interrupt Vector with High Priority bit 2 position. */
#define CPUINT_LVL1VEC_3_bm  (1<<3)  /* Interrupt Vector with High Priority bit 3 mask. */
#define CPUINT_LVL1VEC_3_bp  3  /* Interrupt Vector with High Priority bit 3 position. */
#define CPUINT_LVL1VEC_4_bm  (1<<4)  /* Interrupt Vector with High Priority bit 4 mask. */
#define CPUINT_LVL1VEC_4_bp  4  /* Interrupt Vector with High Priority bit 4 position. */
#define CPUINT_LVL1VEC_5_bm  (1<<5)  /* Interrupt Vector with High Priority bit 5 mask. */
#define CPUINT_LVL1VEC_5_bp  5  /* Interrupt Vector with High Priority bit 5 position. */
#define CPUINT_LVL1VEC_6_bm  (1<<6)  /* Interrupt Vector with High Priority bit 6 mask. */
#define CPUINT_LVL1VEC_6_bp  6  /* Interrupt Vector with High Priority bit 6 position. */
#define CPUINT_LVL1VEC_7_bm  (1<<7)  /* Interrupt Vector with High Priority bit 7 mask. */
#define CPUINT_LVL1VEC_7_bp  7  /* Interrupt Vector with High Priority bit 7 position. */


/* CRCSCAN - CRCSCAN */
/* CRCSCAN.CTRLA  bit masks and bit positions */
#define CRCSCAN_ENABLE_bm  0x01  /* Enable CRC scan bit mask. */
#define CRCSCAN_ENABLE_bp  0  /* Enable CRC scan bit position. */
#define CRCSCAN_NMIEN_bm  0x02  /* Enable NMI Trigger bit mask. */
#define CRCSCAN_NMIEN_bp  1  /* Enable NMI Trigger bit position. */
#define CRCSCAN_RESET_bm  0x80  /* Reset CRC scan bit mask. */
#define CRCSCAN_RESET_bp  7  /* Reset CRC scan bit position. */

/* CRCSCAN.CTRLB  bit masks and bit positions */
#define CRCSCAN_SRC_gm  0x03  /* CRC Source group mask. */
#define CRCSCAN_SRC_gp  0  /* CRC Source group position. */
#define CRCSCAN_SRC_0_bm  (1<<0)  /* CRC Source bit 0 mask. */
#define CRCSCAN_SRC_0_bp  0  /* CRC Source bit 0 position. */
#define CRCSCAN_SRC_1_bm  (1<<1)  /* CRC Source bit 1 mask. */
#define CRCSCAN_SRC_1_bp  1  /* CRC Source bit 1 position. */
#define CRCSCAN_MODE_gm  0x30  /* CRC Flash Access Mode group mask. */
#define CRCSCAN_MODE_gp  4  /* CRC Flash Access Mode group position. */
#define CRCSCAN_MODE_0_bm  (1<<4)  /* CRC Flash Access Mode bit 0 mask. */
#define CRCSCAN_MODE_0_bp  4  /* CRC Flash Access Mode bit 0 position. */
#define CRCSCAN_MODE_1_bm  (1<<5)  /* CRC Flash Access Mode bit 1 mask. */
#define CRCSCAN_MODE_1_bp  5  /* CRC Flash Access Mode bit 1 position. */

/* CRCSCAN.STATUS  bit masks and bit positions */
#define CRCSCAN_BUSY_bm  0x01  /* CRC Busy bit mask. */
#define CRCSCAN_BUSY_bp  0  /* CRC Busy bit position. */
#define CRCSCAN_OK_bm  0x02  /* CRC Ok bit mask. */
#define CRCSCAN_OK_bp  1  /* CRC Ok bit position. */


/* EVSYS - Event System */
/* EVSYS.SWEVENTA  bit masks and bit positions */
#define EVSYS_SWEVENTA_gm  0xFF  /* Software event on channel select group mask. */
#define EVSYS_SWEVENTA_gp  0  /* Software event on channel select group position. */
#define EVSYS_SWEVENTA_0_bm  (1<<0)  /* Software event on channel select bit 0 mask. */
#define EVSYS_SWEVENTA_0_bp  0  /* Software event on channel select bit 0 position. */
#define EVSYS_SWEVENTA_1_bm  (1<<1)  /* Software event on channel select bit 1 mask. */
#define EVSYS_SWEVENTA_1_bp  1  /* Software event on channel select bit 1 position. */
#define EVSYS_SWEVENTA_2_bm  (1<<2)  /* Software event on channel select bit 2 mask. */
#define EVSYS_SWEVENTA_2_bp  2  /* Software event on channel select bit 2 position. */
#define EVSYS_SWEVENTA_3_bm  (1<<3)  /* Software event on channel select bit 3 mask. */
#define EVSYS_SWEVENTA_3_bp  3  /* Software event on channel select bit 3 position. */
#define EVSYS_SWEVENTA_4_bm  (1<<4)  /* Software event on channel select bit 4 mask. */
#define EVSYS_SWEVENTA_4_bp  4  /* Software event on channel select bit 4 position. */
#define EVSYS_SWEVENTA_5_bm  (1<<5)  /* Software event on channel select bit 5 mask. */
#define EVSYS_SWEVENTA_5_bp  5  /* Software event on channel select bit 5 position. */
#define EVSYS_SWEVENTA_6_bm  (1<<6)  /* Software event on channel select bit 6 mask. */
#define EVSYS_SWEVENTA_6_bp  6  /* Software event on channel select bit 6 position. */
#define EVSYS_SWEVENTA_7_bm  (1<<7)  /* Software event on channel select bit 7 mask. */
#define EVSYS_SWEVENTA_7_bp  7  /* Software event on channel select bit 7 position. */

/* EVSYS.CHANNEL0  bit masks and bit positions */
#define EVSYS_CHANNEL_gm  0xFF  /* Channel generator select group mask. */
#define EVSYS_CHANNEL_gp  0  /* Channel generator select group position. */
#define EVSYS_CHANNEL_0_bm  (1<<0)  /* Channel generator select bit 0 mask. */
#define EVSYS_CHANNEL_0_bp  0  /* Channel generator select bit 0 position. */
#define EVSYS_CHANNEL_1_bm  (1<<1)  /* Channel generator select bit 1 mask. */
#define EVSYS_CHANNEL_1_bp  1  /* Channel generator select bit 1 position. */
#define EVSYS_CHANNEL_2_bm  (1<<2)  /* Channel generator select bit 2 mask. */
#define EVSYS_CHANNEL_2_bp  2  /* Channel generator select bit 2 position. */
#define EVSYS_CHANNEL_3_bm  (1<<3)  /* Channel generator select bit 3 mask. */
#define EVSYS_CHANNEL_3_bp  3  /* Channel generator select bit 3 position. */
#define EVSYS_CHANNEL_4_bm  (1<<4)  /* Channel generator select bit 4 mask. */
#define EVSYS_CHANNEL_4_bp  4  /* Channel generator select bit 4 position. */
#define EVSYS_CHANNEL_5_bm  (1<<5)  /* Channel generator select bit 5 mask. */
#define EVSYS_CHANNEL_5_bp  5  /* Channel generator select bit 5 position. */
#define EVSYS_CHANNEL_6_bm  (1<<6)  /* Channel generator select bit 6 mask. */
#define EVSYS_CHANNEL_6_bp  6  /* Channel generator select bit 6 position. */
#define EVSYS_CHANNEL_7_bm  (1<<7)  /* Channel generator select bit 7 mask. */
#define EVSYS_CHANNEL_7_bp  7  /* Channel generator select bit 7 position. */

/* EVSYS.CHANNEL1  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.CHANNEL2  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.CHANNEL3  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.CHANNEL4  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.CHANNEL5  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.CHANNEL6  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.CHANNEL7  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERCCLLUT0A  bit masks and bit positions */
#define EVSYS_USER_gm  0xFF  /* User channel select group mask. */
#define EVSYS_USER_gp  0  /* User channel select group position. */
#define EVSYS_USER_0_bm  (1<<0)  /* User channel select bit 0 mask. */
#define EVSYS_USER_0_bp  0  /* User channel select bit 0 position. */
#define EVSYS_USER_1_bm  (1<<1)  /* User channel select bit 1 mask. */
#define EVSYS_USER_1_bp  1  /* User channel select bit 1 position. */
#define EVSYS_USER_2_bm  (1<<2)  /* User channel select bit 2 mask. */
#define EVSYS_USER_2_bp  2  /* User channel select bit 2 position. */
#define EVSYS_USER_3_bm  (1<<3)  /* User channel select bit 3 mask. */
#define EVSYS_USER_3_bp  3  /* User channel select bit 3 position. */
#define EVSYS_USER_4_bm  (1<<4)  /* User channel select bit 4 mask. */
#define EVSYS_USER_4_bp  4  /* User channel select bit 4 position. */
#define EVSYS_USER_5_bm  (1<<5)  /* User channel select bit 5 mask. */
#define EVSYS_USER_5_bp  5  /* User channel select bit 5 position. */
#define EVSYS_USER_6_bm  (1<<6)  /* User channel select bit 6 mask. */
#define EVSYS_USER_6_bp  6  /* User channel select bit 6 position. */
#define EVSYS_USER_7_bm  (1<<7)  /* User channel select bit 7 mask. */
#define EVSYS_USER_7_bp  7  /* User channel select bit 7 position. */

/* EVSYS.USERCCLLUT0B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT1A  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT1B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT2A  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT2B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT3A  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT3B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERADC0START  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTC  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTD  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTF  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERUSART0IRDA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCE0CNTA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCE0CNTB  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB0CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB0COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB1CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB1COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCF0CNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCF0ACT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERWEXA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERWEXB  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERWEXC  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTEST  bit masks and bit positions */
/* EVSYS_USER  is already defined. */


/* FIM - FPGA Interface Module */
/* FIM.INTCTRL  bit masks and bit positions */
#define FIM_BTNR_bm  0x01  /* Right-Button Interrupt Enable bit mask. */
#define FIM_BTNR_bp  0  /* Right-Button Interrupt Enable bit position. */
#define FIM_BTNL_bm  0x02  /* Left-Button Interrupt Enable bit mask. */
#define FIM_BTNL_bp  1  /* Left-Button Interrupt Enable bit position. */
#define FIM_BTND_bm  0x04  /* Down-Button Interrupt Enable bit mask. */
#define FIM_BTND_bp  2  /* Down-Button Interrupt Enable bit position. */
#define FIM_BTNU_bm  0x08  /* Up-Button Interrupt Enable bit mask. */
#define FIM_BTNU_bp  3  /* Up-Button Interrupt Enable bit position. */
#define FIM_BTNC_bm  0x10  /* Center-Button Interrupt Enable bit mask. */
#define FIM_BTNC_bp  4  /* Center-Button Interrupt Enable bit position. */
#define FIM_SW_bm  0x20  /* Switch Chenge Interrupt Enable bit mask. */
#define FIM_SW_bp  5  /* Switch Chenge Interrupt Enable bit position. */
#define FIM_VGAEOF_bm  0x40  /* VGA End-of-Frame Interrupt Enable bit mask. */
#define FIM_VGAEOF_bp  6  /* VGA End-of-Frame Interrupt Enable bit position. */

/* FIM.INTFLAGS  bit masks and bit positions */
/* FIM_BTNR  is already defined. */
/* FIM_BTNL  is already defined. */
/* FIM_BTND  is already defined. */
/* FIM_BTNU  is already defined. */
/* FIM_BTNC  is already defined. */
/* FIM_SW  is already defined. */
/* FIM_VGAEOF  is already defined. */

/* FIM.STATUS  bit masks and bit positions */
/* FIM_BTNR  is already defined. */
/* FIM_BTNL  is already defined. */
/* FIM_BTND  is already defined. */
/* FIM_BTNU  is already defined. */
/* FIM_BTNC  is already defined. */
#define FIM_VBUS_bm  0x20  /* VBUS Status bit mask. */
#define FIM_VBUS_bp  5  /* VBUS Status bit position. */

/* FIM.SWITCHES  bit masks and bit positions */
#define FIM_SWITCHES_gm  0xFFFF  /* Position of Slider Switches group mask. */
#define FIM_SWITCHES_gp  0  /* Position of Slider Switches group position. */
#define FIM_SWITCHES_0_bm  (1<<0)  /* Position of Slider Switches bit 0 mask. */
#define FIM_SWITCHES_0_bp  0  /* Position of Slider Switches bit 0 position. */
#define FIM_SWITCHES_1_bm  (1<<1)  /* Position of Slider Switches bit 1 mask. */
#define FIM_SWITCHES_1_bp  1  /* Position of Slider Switches bit 1 position. */
#define FIM_SWITCHES_2_bm  (1<<2)  /* Position of Slider Switches bit 2 mask. */
#define FIM_SWITCHES_2_bp  2  /* Position of Slider Switches bit 2 position. */
#define FIM_SWITCHES_3_bm  (1<<3)  /* Position of Slider Switches bit 3 mask. */
#define FIM_SWITCHES_3_bp  3  /* Position of Slider Switches bit 3 position. */
#define FIM_SWITCHES_4_bm  (1<<4)  /* Position of Slider Switches bit 4 mask. */
#define FIM_SWITCHES_4_bp  4  /* Position of Slider Switches bit 4 position. */
#define FIM_SWITCHES_5_bm  (1<<5)  /* Position of Slider Switches bit 5 mask. */
#define FIM_SWITCHES_5_bp  5  /* Position of Slider Switches bit 5 position. */
#define FIM_SWITCHES_6_bm  (1<<6)  /* Position of Slider Switches bit 6 mask. */
#define FIM_SWITCHES_6_bp  6  /* Position of Slider Switches bit 6 position. */
#define FIM_SWITCHES_7_bm  (1<<7)  /* Position of Slider Switches bit 7 mask. */
#define FIM_SWITCHES_7_bp  7  /* Position of Slider Switches bit 7 position. */
#define FIM_SWITCHES_8_bm  (1<<8)  /* Position of Slider Switches bit 8 mask. */
#define FIM_SWITCHES_8_bp  8  /* Position of Slider Switches bit 8 position. */
#define FIM_SWITCHES_9_bm  (1<<9)  /* Position of Slider Switches bit 9 mask. */
#define FIM_SWITCHES_9_bp  9  /* Position of Slider Switches bit 9 position. */
#define FIM_SWITCHES_10_bm  (1<<10)  /* Position of Slider Switches bit 10 mask. */
#define FIM_SWITCHES_10_bp  10  /* Position of Slider Switches bit 10 position. */
#define FIM_SWITCHES_11_bm  (1<<11)  /* Position of Slider Switches bit 11 mask. */
#define FIM_SWITCHES_11_bp  11  /* Position of Slider Switches bit 11 position. */
#define FIM_SWITCHES_12_bm  (1<<12)  /* Position of Slider Switches bit 12 mask. */
#define FIM_SWITCHES_12_bp  12  /* Position of Slider Switches bit 12 position. */
#define FIM_SWITCHES_13_bm  (1<<13)  /* Position of Slider Switches bit 13 mask. */
#define FIM_SWITCHES_13_bp  13  /* Position of Slider Switches bit 13 position. */
#define FIM_SWITCHES_14_bm  (1<<14)  /* Position of Slider Switches bit 14 mask. */
#define FIM_SWITCHES_14_bp  14  /* Position of Slider Switches bit 14 position. */
#define FIM_SWITCHES_15_bm  (1<<15)  /* Position of Slider Switches bit 15 mask. */
#define FIM_SWITCHES_15_bp  15  /* Position of Slider Switches bit 15 position. */

/* FIM.LEDS  bit masks and bit positions */
#define FIM_LEDS_gm  0xFFFF  /* LED Value group mask. */
#define FIM_LEDS_gp  0  /* LED Value group position. */
#define FIM_LEDS_0_bm  (1<<0)  /* LED Value bit 0 mask. */
#define FIM_LEDS_0_bp  0  /* LED Value bit 0 position. */
#define FIM_LEDS_1_bm  (1<<1)  /* LED Value bit 1 mask. */
#define FIM_LEDS_1_bp  1  /* LED Value bit 1 position. */
#define FIM_LEDS_2_bm  (1<<2)  /* LED Value bit 2 mask. */
#define FIM_LEDS_2_bp  2  /* LED Value bit 2 position. */
#define FIM_LEDS_3_bm  (1<<3)  /* LED Value bit 3 mask. */
#define FIM_LEDS_3_bp  3  /* LED Value bit 3 position. */
#define FIM_LEDS_4_bm  (1<<4)  /* LED Value bit 4 mask. */
#define FIM_LEDS_4_bp  4  /* LED Value bit 4 position. */
#define FIM_LEDS_5_bm  (1<<5)  /* LED Value bit 5 mask. */
#define FIM_LEDS_5_bp  5  /* LED Value bit 5 position. */
#define FIM_LEDS_6_bm  (1<<6)  /* LED Value bit 6 mask. */
#define FIM_LEDS_6_bp  6  /* LED Value bit 6 position. */
#define FIM_LEDS_7_bm  (1<<7)  /* LED Value bit 7 mask. */
#define FIM_LEDS_7_bp  7  /* LED Value bit 7 position. */
#define FIM_LEDS_8_bm  (1<<8)  /* LED Value bit 8 mask. */
#define FIM_LEDS_8_bp  8  /* LED Value bit 8 position. */
#define FIM_LEDS_9_bm  (1<<9)  /* LED Value bit 9 mask. */
#define FIM_LEDS_9_bp  9  /* LED Value bit 9 position. */
#define FIM_LEDS_10_bm  (1<<10)  /* LED Value bit 10 mask. */
#define FIM_LEDS_10_bp  10  /* LED Value bit 10 position. */
#define FIM_LEDS_11_bm  (1<<11)  /* LED Value bit 11 mask. */
#define FIM_LEDS_11_bp  11  /* LED Value bit 11 position. */
#define FIM_LEDS_12_bm  (1<<12)  /* LED Value bit 12 mask. */
#define FIM_LEDS_12_bp  12  /* LED Value bit 12 position. */
#define FIM_LEDS_13_bm  (1<<13)  /* LED Value bit 13 mask. */
#define FIM_LEDS_13_bp  13  /* LED Value bit 13 position. */
#define FIM_LEDS_14_bm  (1<<14)  /* LED Value bit 14 mask. */
#define FIM_LEDS_14_bp  14  /* LED Value bit 14 position. */
#define FIM_LEDS_15_bm  (1<<15)  /* LED Value bit 15 mask. */
#define FIM_LEDS_15_bp  15  /* LED Value bit 15 position. */

/* FIM.SEVENSEG  bit masks and bit positions */
#define FIM_DISP0_gm  0x0F  /* Display Value group mask. */
#define FIM_DISP0_gp  0  /* Display Value group position. */
#define FIM_DISP0_0_bm  (1<<0)  /* Display Value bit 0 mask. */
#define FIM_DISP0_0_bp  0  /* Display Value bit 0 position. */
#define FIM_DISP0_1_bm  (1<<1)  /* Display Value bit 1 mask. */
#define FIM_DISP0_1_bp  1  /* Display Value bit 1 position. */
#define FIM_DISP0_2_bm  (1<<2)  /* Display Value bit 2 mask. */
#define FIM_DISP0_2_bp  2  /* Display Value bit 2 position. */
#define FIM_DISP0_3_bm  (1<<3)  /* Display Value bit 3 mask. */
#define FIM_DISP0_3_bp  3  /* Display Value bit 3 position. */
#define FIM_DISP1_gm  0xF0  /* Display Value group mask. */
#define FIM_DISP1_gp  4  /* Display Value group position. */
#define FIM_DISP1_0_bm  (1<<4)  /* Display Value bit 0 mask. */
#define FIM_DISP1_0_bp  4  /* Display Value bit 0 position. */
#define FIM_DISP1_1_bm  (1<<5)  /* Display Value bit 1 mask. */
#define FIM_DISP1_1_bp  5  /* Display Value bit 1 position. */
#define FIM_DISP1_2_bm  (1<<6)  /* Display Value bit 2 mask. */
#define FIM_DISP1_2_bp  6  /* Display Value bit 2 position. */
#define FIM_DISP1_3_bm  (1<<7)  /* Display Value bit 3 mask. */
#define FIM_DISP1_3_bp  7  /* Display Value bit 3 position. */
#define FIM_DISP2_gm  0xF00  /* Display Value group mask. */
#define FIM_DISP2_gp  8  /* Display Value group position. */
#define FIM_DISP2_0_bm  (1<<8)  /* Display Value bit 0 mask. */
#define FIM_DISP2_0_bp  8  /* Display Value bit 0 position. */
#define FIM_DISP2_1_bm  (1<<9)  /* Display Value bit 1 mask. */
#define FIM_DISP2_1_bp  9  /* Display Value bit 1 position. */
#define FIM_DISP2_2_bm  (1<<10)  /* Display Value bit 2 mask. */
#define FIM_DISP2_2_bp  10  /* Display Value bit 2 position. */
#define FIM_DISP2_3_bm  (1<<11)  /* Display Value bit 3 mask. */
#define FIM_DISP2_3_bp  11  /* Display Value bit 3 position. */
#define FIM_DISP3_gm  0xF000  /* Display Value group mask. */
#define FIM_DISP3_gp  12  /* Display Value group position. */
#define FIM_DISP3_0_bm  (1<<12)  /* Display Value bit 0 mask. */
#define FIM_DISP3_0_bp  12  /* Display Value bit 0 position. */
#define FIM_DISP3_1_bm  (1<<13)  /* Display Value bit 1 mask. */
#define FIM_DISP3_1_bp  13  /* Display Value bit 1 position. */
#define FIM_DISP3_2_bm  (1<<14)  /* Display Value bit 2 mask. */
#define FIM_DISP3_2_bp  14  /* Display Value bit 2 position. */
#define FIM_DISP3_3_bm  (1<<15)  /* Display Value bit 3 mask. */
#define FIM_DISP3_3_bp  15  /* Display Value bit 3 position. */
#define FIM_DISP4_gm  0xF0000  /* Display Value group mask. */
#define FIM_DISP4_gp  16  /* Display Value group position. */
#define FIM_DISP4_0_bm  (1<<16)  /* Display Value bit 0 mask. */
#define FIM_DISP4_0_bp  16  /* Display Value bit 0 position. */
#define FIM_DISP4_1_bm  (1<<17)  /* Display Value bit 1 mask. */
#define FIM_DISP4_1_bp  17  /* Display Value bit 1 position. */
#define FIM_DISP4_2_bm  (1<<18)  /* Display Value bit 2 mask. */
#define FIM_DISP4_2_bp  18  /* Display Value bit 2 position. */
#define FIM_DISP4_3_bm  (1<<19)  /* Display Value bit 3 mask. */
#define FIM_DISP4_3_bp  19  /* Display Value bit 3 position. */
#define FIM_DISP5_gm  0xF00000  /* Display Value group mask. */
#define FIM_DISP5_gp  20  /* Display Value group position. */
#define FIM_DISP5_0_bm  (1<<20)  /* Display Value bit 0 mask. */
#define FIM_DISP5_0_bp  20  /* Display Value bit 0 position. */
#define FIM_DISP5_1_bm  (1<<21)  /* Display Value bit 1 mask. */
#define FIM_DISP5_1_bp  21  /* Display Value bit 1 position. */
#define FIM_DISP5_2_bm  (1<<22)  /* Display Value bit 2 mask. */
#define FIM_DISP5_2_bp  22  /* Display Value bit 2 position. */
#define FIM_DISP5_3_bm  (1<<23)  /* Display Value bit 3 mask. */
#define FIM_DISP5_3_bp  23  /* Display Value bit 3 position. */
#define FIM_DISP6_gm  0xF000000  /* Display Value group mask. */
#define FIM_DISP6_gp  24  /* Display Value group position. */
#define FIM_DISP6_0_bm  (1<<24)  /* Display Value bit 0 mask. */
#define FIM_DISP6_0_bp  24  /* Display Value bit 0 position. */
#define FIM_DISP6_1_bm  (1<<25)  /* Display Value bit 1 mask. */
#define FIM_DISP6_1_bp  25  /* Display Value bit 1 position. */
#define FIM_DISP6_2_bm  (1<<26)  /* Display Value bit 2 mask. */
#define FIM_DISP6_2_bp  26  /* Display Value bit 2 position. */
#define FIM_DISP6_3_bm  (1<<27)  /* Display Value bit 3 mask. */
#define FIM_DISP6_3_bp  27  /* Display Value bit 3 position. */
#define FIM_DISP7_gm  0xF0000000  /* Display Value group mask. */
#define FIM_DISP7_gp  28  /* Display Value group position. */
#define FIM_DISP7_0_bm  (1<<28)  /* Display Value bit 0 mask. */
#define FIM_DISP7_0_bp  28  /* Display Value bit 0 position. */
#define FIM_DISP7_1_bm  (1<<29)  /* Display Value bit 1 mask. */
#define FIM_DISP7_1_bp  29  /* Display Value bit 1 position. */
#define FIM_DISP7_2_bm  (1<<30)  /* Display Value bit 2 mask. */
#define FIM_DISP7_2_bp  30  /* Display Value bit 2 position. */
#define FIM_DISP7_3_bm  (1<<31)  /* Display Value bit 3 mask. */
#define FIM_DISP7_3_bp  31  /* Display Value bit 3 position. */

/* FIM.DOTS  bit masks and bit positions */
#define FIM_DOTS_gm  0xFF  /* Dots in Seven-Segment Display group mask. */
#define FIM_DOTS_gp  0  /* Dots in Seven-Segment Display group position. */
#define FIM_DOTS_0_bm  (1<<0)  /* Dots in Seven-Segment Display bit 0 mask. */
#define FIM_DOTS_0_bp  0  /* Dots in Seven-Segment Display bit 0 position. */
#define FIM_DOTS_1_bm  (1<<1)  /* Dots in Seven-Segment Display bit 1 mask. */
#define FIM_DOTS_1_bp  1  /* Dots in Seven-Segment Display bit 1 position. */
#define FIM_DOTS_2_bm  (1<<2)  /* Dots in Seven-Segment Display bit 2 mask. */
#define FIM_DOTS_2_bp  2  /* Dots in Seven-Segment Display bit 2 position. */
#define FIM_DOTS_3_bm  (1<<3)  /* Dots in Seven-Segment Display bit 3 mask. */
#define FIM_DOTS_3_bp  3  /* Dots in Seven-Segment Display bit 3 position. */
#define FIM_DOTS_4_bm  (1<<4)  /* Dots in Seven-Segment Display bit 4 mask. */
#define FIM_DOTS_4_bp  4  /* Dots in Seven-Segment Display bit 4 position. */
#define FIM_DOTS_5_bm  (1<<5)  /* Dots in Seven-Segment Display bit 5 mask. */
#define FIM_DOTS_5_bp  5  /* Dots in Seven-Segment Display bit 5 position. */
#define FIM_DOTS_6_bm  (1<<6)  /* Dots in Seven-Segment Display bit 6 mask. */
#define FIM_DOTS_6_bp  6  /* Dots in Seven-Segment Display bit 6 position. */
#define FIM_DOTS_7_bm  (1<<7)  /* Dots in Seven-Segment Display bit 7 mask. */
#define FIM_DOTS_7_bp  7  /* Dots in Seven-Segment Display bit 7 position. */

/* FIM.MCLED0  bit masks and bit positions */
#define FIM_RED_gm  0xFF  /* Intensity of Red group mask. */
#define FIM_RED_gp  0  /* Intensity of Red group position. */
#define FIM_RED_0_bm  (1<<0)  /* Intensity of Red bit 0 mask. */
#define FIM_RED_0_bp  0  /* Intensity of Red bit 0 position. */
#define FIM_RED_1_bm  (1<<1)  /* Intensity of Red bit 1 mask. */
#define FIM_RED_1_bp  1  /* Intensity of Red bit 1 position. */
#define FIM_RED_2_bm  (1<<2)  /* Intensity of Red bit 2 mask. */
#define FIM_RED_2_bp  2  /* Intensity of Red bit 2 position. */
#define FIM_RED_3_bm  (1<<3)  /* Intensity of Red bit 3 mask. */
#define FIM_RED_3_bp  3  /* Intensity of Red bit 3 position. */
#define FIM_RED_4_bm  (1<<4)  /* Intensity of Red bit 4 mask. */
#define FIM_RED_4_bp  4  /* Intensity of Red bit 4 position. */
#define FIM_RED_5_bm  (1<<5)  /* Intensity of Red bit 5 mask. */
#define FIM_RED_5_bp  5  /* Intensity of Red bit 5 position. */
#define FIM_RED_6_bm  (1<<6)  /* Intensity of Red bit 6 mask. */
#define FIM_RED_6_bp  6  /* Intensity of Red bit 6 position. */
#define FIM_RED_7_bm  (1<<7)  /* Intensity of Red bit 7 mask. */
#define FIM_RED_7_bp  7  /* Intensity of Red bit 7 position. */
#define FIM_GREEN_gm  0xFF00  /* Intensity of Green group mask. */
#define FIM_GREEN_gp  8  /* Intensity of Green group position. */
#define FIM_GREEN_0_bm  (1<<8)  /* Intensity of Green bit 0 mask. */
#define FIM_GREEN_0_bp  8  /* Intensity of Green bit 0 position. */
#define FIM_GREEN_1_bm  (1<<9)  /* Intensity of Green bit 1 mask. */
#define FIM_GREEN_1_bp  9  /* Intensity of Green bit 1 position. */
#define FIM_GREEN_2_bm  (1<<10)  /* Intensity of Green bit 2 mask. */
#define FIM_GREEN_2_bp  10  /* Intensity of Green bit 2 position. */
#define FIM_GREEN_3_bm  (1<<11)  /* Intensity of Green bit 3 mask. */
#define FIM_GREEN_3_bp  11  /* Intensity of Green bit 3 position. */
#define FIM_GREEN_4_bm  (1<<12)  /* Intensity of Green bit 4 mask. */
#define FIM_GREEN_4_bp  12  /* Intensity of Green bit 4 position. */
#define FIM_GREEN_5_bm  (1<<13)  /* Intensity of Green bit 5 mask. */
#define FIM_GREEN_5_bp  13  /* Intensity of Green bit 5 position. */
#define FIM_GREEN_6_bm  (1<<14)  /* Intensity of Green bit 6 mask. */
#define FIM_GREEN_6_bp  14  /* Intensity of Green bit 6 position. */
#define FIM_GREEN_7_bm  (1<<15)  /* Intensity of Green bit 7 mask. */
#define FIM_GREEN_7_bp  15  /* Intensity of Green bit 7 position. */
#define FIM_BLUE_gm  0xFF0000  /* Intensity of Blue group mask. */
#define FIM_BLUE_gp  16  /* Intensity of Blue group position. */
#define FIM_BLUE_0_bm  (1<<16)  /* Intensity of Blue bit 0 mask. */
#define FIM_BLUE_0_bp  16  /* Intensity of Blue bit 0 position. */
#define FIM_BLUE_1_bm  (1<<17)  /* Intensity of Blue bit 1 mask. */
#define FIM_BLUE_1_bp  17  /* Intensity of Blue bit 1 position. */
#define FIM_BLUE_2_bm  (1<<18)  /* Intensity of Blue bit 2 mask. */
#define FIM_BLUE_2_bp  18  /* Intensity of Blue bit 2 position. */
#define FIM_BLUE_3_bm  (1<<19)  /* Intensity of Blue bit 3 mask. */
#define FIM_BLUE_3_bp  19  /* Intensity of Blue bit 3 position. */
#define FIM_BLUE_4_bm  (1<<20)  /* Intensity of Blue bit 4 mask. */
#define FIM_BLUE_4_bp  20  /* Intensity of Blue bit 4 position. */
#define FIM_BLUE_5_bm  (1<<21)  /* Intensity of Blue bit 5 mask. */
#define FIM_BLUE_5_bp  21  /* Intensity of Blue bit 5 position. */
#define FIM_BLUE_6_bm  (1<<22)  /* Intensity of Blue bit 6 mask. */
#define FIM_BLUE_6_bp  22  /* Intensity of Blue bit 6 position. */
#define FIM_BLUE_7_bm  (1<<23)  /* Intensity of Blue bit 7 mask. */
#define FIM_BLUE_7_bp  23  /* Intensity of Blue bit 7 position. */

/* FIM.MCLED1  bit masks and bit positions */
/* FIM_RED  is already defined. */
/* FIM_GREEN  is already defined. */
/* FIM_BLUE  is already defined. */

/* FIM.DNALSDW  bit masks and bit positions */
#define FIM_DNALSDW_gm  0xFFFFFFFF  /* FPGA DNA Least Siginificant Double Word group mask. */
#define FIM_DNALSDW_gp  0  /* FPGA DNA Least Siginificant Double Word group position. */
#define FIM_DNALSDW_0_bm  (1<<0)  /* FPGA DNA Least Siginificant Double Word bit 0 mask. */
#define FIM_DNALSDW_0_bp  0  /* FPGA DNA Least Siginificant Double Word bit 0 position. */
#define FIM_DNALSDW_1_bm  (1<<1)  /* FPGA DNA Least Siginificant Double Word bit 1 mask. */
#define FIM_DNALSDW_1_bp  1  /* FPGA DNA Least Siginificant Double Word bit 1 position. */
#define FIM_DNALSDW_2_bm  (1<<2)  /* FPGA DNA Least Siginificant Double Word bit 2 mask. */
#define FIM_DNALSDW_2_bp  2  /* FPGA DNA Least Siginificant Double Word bit 2 position. */
#define FIM_DNALSDW_3_bm  (1<<3)  /* FPGA DNA Least Siginificant Double Word bit 3 mask. */
#define FIM_DNALSDW_3_bp  3  /* FPGA DNA Least Siginificant Double Word bit 3 position. */
#define FIM_DNALSDW_4_bm  (1<<4)  /* FPGA DNA Least Siginificant Double Word bit 4 mask. */
#define FIM_DNALSDW_4_bp  4  /* FPGA DNA Least Siginificant Double Word bit 4 position. */
#define FIM_DNALSDW_5_bm  (1<<5)  /* FPGA DNA Least Siginificant Double Word bit 5 mask. */
#define FIM_DNALSDW_5_bp  5  /* FPGA DNA Least Siginificant Double Word bit 5 position. */
#define FIM_DNALSDW_6_bm  (1<<6)  /* FPGA DNA Least Siginificant Double Word bit 6 mask. */
#define FIM_DNALSDW_6_bp  6  /* FPGA DNA Least Siginificant Double Word bit 6 position. */
#define FIM_DNALSDW_7_bm  (1<<7)  /* FPGA DNA Least Siginificant Double Word bit 7 mask. */
#define FIM_DNALSDW_7_bp  7  /* FPGA DNA Least Siginificant Double Word bit 7 position. */
#define FIM_DNALSDW_8_bm  (1<<8)  /* FPGA DNA Least Siginificant Double Word bit 8 mask. */
#define FIM_DNALSDW_8_bp  8  /* FPGA DNA Least Siginificant Double Word bit 8 position. */
#define FIM_DNALSDW_9_bm  (1<<9)  /* FPGA DNA Least Siginificant Double Word bit 9 mask. */
#define FIM_DNALSDW_9_bp  9  /* FPGA DNA Least Siginificant Double Word bit 9 position. */
#define FIM_DNALSDW_10_bm  (1<<10)  /* FPGA DNA Least Siginificant Double Word bit 10 mask. */
#define FIM_DNALSDW_10_bp  10  /* FPGA DNA Least Siginificant Double Word bit 10 position. */
#define FIM_DNALSDW_11_bm  (1<<11)  /* FPGA DNA Least Siginificant Double Word bit 11 mask. */
#define FIM_DNALSDW_11_bp  11  /* FPGA DNA Least Siginificant Double Word bit 11 position. */
#define FIM_DNALSDW_12_bm  (1<<12)  /* FPGA DNA Least Siginificant Double Word bit 12 mask. */
#define FIM_DNALSDW_12_bp  12  /* FPGA DNA Least Siginificant Double Word bit 12 position. */
#define FIM_DNALSDW_13_bm  (1<<13)  /* FPGA DNA Least Siginificant Double Word bit 13 mask. */
#define FIM_DNALSDW_13_bp  13  /* FPGA DNA Least Siginificant Double Word bit 13 position. */
#define FIM_DNALSDW_14_bm  (1<<14)  /* FPGA DNA Least Siginificant Double Word bit 14 mask. */
#define FIM_DNALSDW_14_bp  14  /* FPGA DNA Least Siginificant Double Word bit 14 position. */
#define FIM_DNALSDW_15_bm  (1<<15)  /* FPGA DNA Least Siginificant Double Word bit 15 mask. */
#define FIM_DNALSDW_15_bp  15  /* FPGA DNA Least Siginificant Double Word bit 15 position. */
#define FIM_DNALSDW_16_bm  (1<<16)  /* FPGA DNA Least Siginificant Double Word bit 16 mask. */
#define FIM_DNALSDW_16_bp  16  /* FPGA DNA Least Siginificant Double Word bit 16 position. */
#define FIM_DNALSDW_17_bm  (1<<17)  /* FPGA DNA Least Siginificant Double Word bit 17 mask. */
#define FIM_DNALSDW_17_bp  17  /* FPGA DNA Least Siginificant Double Word bit 17 position. */
#define FIM_DNALSDW_18_bm  (1<<18)  /* FPGA DNA Least Siginificant Double Word bit 18 mask. */
#define FIM_DNALSDW_18_bp  18  /* FPGA DNA Least Siginificant Double Word bit 18 position. */
#define FIM_DNALSDW_19_bm  (1<<19)  /* FPGA DNA Least Siginificant Double Word bit 19 mask. */
#define FIM_DNALSDW_19_bp  19  /* FPGA DNA Least Siginificant Double Word bit 19 position. */
#define FIM_DNALSDW_20_bm  (1<<20)  /* FPGA DNA Least Siginificant Double Word bit 20 mask. */
#define FIM_DNALSDW_20_bp  20  /* FPGA DNA Least Siginificant Double Word bit 20 position. */
#define FIM_DNALSDW_21_bm  (1<<21)  /* FPGA DNA Least Siginificant Double Word bit 21 mask. */
#define FIM_DNALSDW_21_bp  21  /* FPGA DNA Least Siginificant Double Word bit 21 position. */
#define FIM_DNALSDW_22_bm  (1<<22)  /* FPGA DNA Least Siginificant Double Word bit 22 mask. */
#define FIM_DNALSDW_22_bp  22  /* FPGA DNA Least Siginificant Double Word bit 22 position. */
#define FIM_DNALSDW_23_bm  (1<<23)  /* FPGA DNA Least Siginificant Double Word bit 23 mask. */
#define FIM_DNALSDW_23_bp  23  /* FPGA DNA Least Siginificant Double Word bit 23 position. */
#define FIM_DNALSDW_24_bm  (1<<24)  /* FPGA DNA Least Siginificant Double Word bit 24 mask. */
#define FIM_DNALSDW_24_bp  24  /* FPGA DNA Least Siginificant Double Word bit 24 position. */
#define FIM_DNALSDW_25_bm  (1<<25)  /* FPGA DNA Least Siginificant Double Word bit 25 mask. */
#define FIM_DNALSDW_25_bp  25  /* FPGA DNA Least Siginificant Double Word bit 25 position. */
#define FIM_DNALSDW_26_bm  (1<<26)  /* FPGA DNA Least Siginificant Double Word bit 26 mask. */
#define FIM_DNALSDW_26_bp  26  /* FPGA DNA Least Siginificant Double Word bit 26 position. */
#define FIM_DNALSDW_27_bm  (1<<27)  /* FPGA DNA Least Siginificant Double Word bit 27 mask. */
#define FIM_DNALSDW_27_bp  27  /* FPGA DNA Least Siginificant Double Word bit 27 position. */
#define FIM_DNALSDW_28_bm  (1<<28)  /* FPGA DNA Least Siginificant Double Word bit 28 mask. */
#define FIM_DNALSDW_28_bp  28  /* FPGA DNA Least Siginificant Double Word bit 28 position. */
#define FIM_DNALSDW_29_bm  (1<<29)  /* FPGA DNA Least Siginificant Double Word bit 29 mask. */
#define FIM_DNALSDW_29_bp  29  /* FPGA DNA Least Siginificant Double Word bit 29 position. */
#define FIM_DNALSDW_30_bm  (1<<30)  /* FPGA DNA Least Siginificant Double Word bit 30 mask. */
#define FIM_DNALSDW_30_bp  30  /* FPGA DNA Least Siginificant Double Word bit 30 position. */
#define FIM_DNALSDW_31_bm  (1<<31)  /* FPGA DNA Least Siginificant Double Word bit 31 mask. */
#define FIM_DNALSDW_31_bp  31  /* FPGA DNA Least Siginificant Double Word bit 31 position. */

/* FIM.DNAMSDW  bit masks and bit positions */
#define FIM_DNAMSDW_gm  0xFFFFFFFF  /* FPGA DNA Most Significant Double Word group mask. */
#define FIM_DNAMSDW_gp  0  /* FPGA DNA Most Significant Double Word group position. */
#define FIM_DNAMSDW_0_bm  (1<<0)  /* FPGA DNA Most Significant Double Word bit 0 mask. */
#define FIM_DNAMSDW_0_bp  0  /* FPGA DNA Most Significant Double Word bit 0 position. */
#define FIM_DNAMSDW_1_bm  (1<<1)  /* FPGA DNA Most Significant Double Word bit 1 mask. */
#define FIM_DNAMSDW_1_bp  1  /* FPGA DNA Most Significant Double Word bit 1 position. */
#define FIM_DNAMSDW_2_bm  (1<<2)  /* FPGA DNA Most Significant Double Word bit 2 mask. */
#define FIM_DNAMSDW_2_bp  2  /* FPGA DNA Most Significant Double Word bit 2 position. */
#define FIM_DNAMSDW_3_bm  (1<<3)  /* FPGA DNA Most Significant Double Word bit 3 mask. */
#define FIM_DNAMSDW_3_bp  3  /* FPGA DNA Most Significant Double Word bit 3 position. */
#define FIM_DNAMSDW_4_bm  (1<<4)  /* FPGA DNA Most Significant Double Word bit 4 mask. */
#define FIM_DNAMSDW_4_bp  4  /* FPGA DNA Most Significant Double Word bit 4 position. */
#define FIM_DNAMSDW_5_bm  (1<<5)  /* FPGA DNA Most Significant Double Word bit 5 mask. */
#define FIM_DNAMSDW_5_bp  5  /* FPGA DNA Most Significant Double Word bit 5 position. */
#define FIM_DNAMSDW_6_bm  (1<<6)  /* FPGA DNA Most Significant Double Word bit 6 mask. */
#define FIM_DNAMSDW_6_bp  6  /* FPGA DNA Most Significant Double Word bit 6 position. */
#define FIM_DNAMSDW_7_bm  (1<<7)  /* FPGA DNA Most Significant Double Word bit 7 mask. */
#define FIM_DNAMSDW_7_bp  7  /* FPGA DNA Most Significant Double Word bit 7 position. */
#define FIM_DNAMSDW_8_bm  (1<<8)  /* FPGA DNA Most Significant Double Word bit 8 mask. */
#define FIM_DNAMSDW_8_bp  8  /* FPGA DNA Most Significant Double Word bit 8 position. */
#define FIM_DNAMSDW_9_bm  (1<<9)  /* FPGA DNA Most Significant Double Word bit 9 mask. */
#define FIM_DNAMSDW_9_bp  9  /* FPGA DNA Most Significant Double Word bit 9 position. */
#define FIM_DNAMSDW_10_bm  (1<<10)  /* FPGA DNA Most Significant Double Word bit 10 mask. */
#define FIM_DNAMSDW_10_bp  10  /* FPGA DNA Most Significant Double Word bit 10 position. */
#define FIM_DNAMSDW_11_bm  (1<<11)  /* FPGA DNA Most Significant Double Word bit 11 mask. */
#define FIM_DNAMSDW_11_bp  11  /* FPGA DNA Most Significant Double Word bit 11 position. */
#define FIM_DNAMSDW_12_bm  (1<<12)  /* FPGA DNA Most Significant Double Word bit 12 mask. */
#define FIM_DNAMSDW_12_bp  12  /* FPGA DNA Most Significant Double Word bit 12 position. */
#define FIM_DNAMSDW_13_bm  (1<<13)  /* FPGA DNA Most Significant Double Word bit 13 mask. */
#define FIM_DNAMSDW_13_bp  13  /* FPGA DNA Most Significant Double Word bit 13 position. */
#define FIM_DNAMSDW_14_bm  (1<<14)  /* FPGA DNA Most Significant Double Word bit 14 mask. */
#define FIM_DNAMSDW_14_bp  14  /* FPGA DNA Most Significant Double Word bit 14 position. */
#define FIM_DNAMSDW_15_bm  (1<<15)  /* FPGA DNA Most Significant Double Word bit 15 mask. */
#define FIM_DNAMSDW_15_bp  15  /* FPGA DNA Most Significant Double Word bit 15 position. */
#define FIM_DNAMSDW_16_bm  (1<<16)  /* FPGA DNA Most Significant Double Word bit 16 mask. */
#define FIM_DNAMSDW_16_bp  16  /* FPGA DNA Most Significant Double Word bit 16 position. */
#define FIM_DNAMSDW_17_bm  (1<<17)  /* FPGA DNA Most Significant Double Word bit 17 mask. */
#define FIM_DNAMSDW_17_bp  17  /* FPGA DNA Most Significant Double Word bit 17 position. */
#define FIM_DNAMSDW_18_bm  (1<<18)  /* FPGA DNA Most Significant Double Word bit 18 mask. */
#define FIM_DNAMSDW_18_bp  18  /* FPGA DNA Most Significant Double Word bit 18 position. */
#define FIM_DNAMSDW_19_bm  (1<<19)  /* FPGA DNA Most Significant Double Word bit 19 mask. */
#define FIM_DNAMSDW_19_bp  19  /* FPGA DNA Most Significant Double Word bit 19 position. */
#define FIM_DNAMSDW_20_bm  (1<<20)  /* FPGA DNA Most Significant Double Word bit 20 mask. */
#define FIM_DNAMSDW_20_bp  20  /* FPGA DNA Most Significant Double Word bit 20 position. */
#define FIM_DNAMSDW_21_bm  (1<<21)  /* FPGA DNA Most Significant Double Word bit 21 mask. */
#define FIM_DNAMSDW_21_bp  21  /* FPGA DNA Most Significant Double Word bit 21 position. */
#define FIM_DNAMSDW_22_bm  (1<<22)  /* FPGA DNA Most Significant Double Word bit 22 mask. */
#define FIM_DNAMSDW_22_bp  22  /* FPGA DNA Most Significant Double Word bit 22 position. */
#define FIM_DNAMSDW_23_bm  (1<<23)  /* FPGA DNA Most Significant Double Word bit 23 mask. */
#define FIM_DNAMSDW_23_bp  23  /* FPGA DNA Most Significant Double Word bit 23 position. */
#define FIM_DNAMSDW_24_bm  (1<<24)  /* FPGA DNA Most Significant Double Word bit 24 mask. */
#define FIM_DNAMSDW_24_bp  24  /* FPGA DNA Most Significant Double Word bit 24 position. */
#define FIM_DNAMSDW_25_bm  (1<<25)  /* FPGA DNA Most Significant Double Word bit 25 mask. */
#define FIM_DNAMSDW_25_bp  25  /* FPGA DNA Most Significant Double Word bit 25 position. */
#define FIM_DNAMSDW_26_bm  (1<<26)  /* FPGA DNA Most Significant Double Word bit 26 mask. */
#define FIM_DNAMSDW_26_bp  26  /* FPGA DNA Most Significant Double Word bit 26 position. */
#define FIM_DNAMSDW_27_bm  (1<<27)  /* FPGA DNA Most Significant Double Word bit 27 mask. */
#define FIM_DNAMSDW_27_bp  27  /* FPGA DNA Most Significant Double Word bit 27 position. */
#define FIM_DNAMSDW_28_bm  (1<<28)  /* FPGA DNA Most Significant Double Word bit 28 mask. */
#define FIM_DNAMSDW_28_bp  28  /* FPGA DNA Most Significant Double Word bit 28 position. */
#define FIM_DNAMSDW_29_bm  (1<<29)  /* FPGA DNA Most Significant Double Word bit 29 mask. */
#define FIM_DNAMSDW_29_bp  29  /* FPGA DNA Most Significant Double Word bit 29 position. */
#define FIM_DNAMSDW_30_bm  (1<<30)  /* FPGA DNA Most Significant Double Word bit 30 mask. */
#define FIM_DNAMSDW_30_bp  30  /* FPGA DNA Most Significant Double Word bit 30 position. */
#define FIM_DNAMSDW_31_bm  (1<<31)  /* FPGA DNA Most Significant Double Word bit 31 mask. */
#define FIM_DNAMSDW_31_bp  31  /* FPGA DNA Most Significant Double Word bit 31 position. */

/* FIM.VGA  bit masks and bit positions */
#define FIM_PAGE_gm  0x03  /* VGA Page group mask. */
#define FIM_PAGE_gp  0  /* VGA Page group position. */
#define FIM_PAGE_0_bm  (1<<0)  /* VGA Page bit 0 mask. */
#define FIM_PAGE_0_bp  0  /* VGA Page bit 0 position. */
#define FIM_PAGE_1_bm  (1<<1)  /* VGA Page bit 1 mask. */
#define FIM_PAGE_1_bp  1  /* VGA Page bit 1 position. */


/* FUSE - Fuses */
/* FUSE.WDTCFG  bit masks and bit positions */
#define FUSE_PERIOD_gm  0x0F  /* Watchdog Timeout Period group mask. */
#define FUSE_PERIOD_gp  0  /* Watchdog Timeout Period group position. */
#define FUSE_PERIOD_0_bm  (1<<0)  /* Watchdog Timeout Period bit 0 mask. */
#define FUSE_PERIOD_0_bp  0  /* Watchdog Timeout Period bit 0 position. */
#define FUSE_PERIOD_1_bm  (1<<1)  /* Watchdog Timeout Period bit 1 mask. */
#define FUSE_PERIOD_1_bp  1  /* Watchdog Timeout Period bit 1 position. */
#define FUSE_PERIOD_2_bm  (1<<2)  /* Watchdog Timeout Period bit 2 mask. */
#define FUSE_PERIOD_2_bp  2  /* Watchdog Timeout Period bit 2 position. */
#define FUSE_PERIOD_3_bm  (1<<3)  /* Watchdog Timeout Period bit 3 mask. */
#define FUSE_PERIOD_3_bp  3  /* Watchdog Timeout Period bit 3 position. */
#define FUSE_WINDOW_gm  0xF0  /* Watchdog Window Timeout Period group mask. */
#define FUSE_WINDOW_gp  4  /* Watchdog Window Timeout Period group position. */
#define FUSE_WINDOW_0_bm  (1<<4)  /* Watchdog Window Timeout Period bit 0 mask. */
#define FUSE_WINDOW_0_bp  4  /* Watchdog Window Timeout Period bit 0 position. */
#define FUSE_WINDOW_1_bm  (1<<5)  /* Watchdog Window Timeout Period bit 1 mask. */
#define FUSE_WINDOW_1_bp  5  /* Watchdog Window Timeout Period bit 1 position. */
#define FUSE_WINDOW_2_bm  (1<<6)  /* Watchdog Window Timeout Period bit 2 mask. */
#define FUSE_WINDOW_2_bp  6  /* Watchdog Window Timeout Period bit 2 position. */
#define FUSE_WINDOW_3_bm  (1<<7)  /* Watchdog Window Timeout Period bit 3 mask. */
#define FUSE_WINDOW_3_bp  7  /* Watchdog Window Timeout Period bit 3 position. */

/* FUSE.BODCFG  bit masks and bit positions */
#define FUSE_SLEEP_gm  0x03  /* BOD Operation in Sleep Mode group mask. */
#define FUSE_SLEEP_gp  0  /* BOD Operation in Sleep Mode group position. */
#define FUSE_SLEEP_0_bm  (1<<0)  /* BOD Operation in Sleep Mode bit 0 mask. */
#define FUSE_SLEEP_0_bp  0  /* BOD Operation in Sleep Mode bit 0 position. */
#define FUSE_SLEEP_1_bm  (1<<1)  /* BOD Operation in Sleep Mode bit 1 mask. */
#define FUSE_SLEEP_1_bp  1  /* BOD Operation in Sleep Mode bit 1 position. */
#define FUSE_ACTIVE_gm  0x0C  /* BOD Operation in Active Mode group mask. */
#define FUSE_ACTIVE_gp  2  /* BOD Operation in Active Mode group position. */
#define FUSE_ACTIVE_0_bm  (1<<2)  /* BOD Operation in Active Mode bit 0 mask. */
#define FUSE_ACTIVE_0_bp  2  /* BOD Operation in Active Mode bit 0 position. */
#define FUSE_ACTIVE_1_bm  (1<<3)  /* BOD Operation in Active Mode bit 1 mask. */
#define FUSE_ACTIVE_1_bp  3  /* BOD Operation in Active Mode bit 1 position. */
#define FUSE_SAMPFREQ_bm  0x10  /* BOD Sample Frequency bit mask. */
#define FUSE_SAMPFREQ_bp  4  /* BOD Sample Frequency bit position. */
#define FUSE_LVL_gm  0xE0  /* BOD Level group mask. */
#define FUSE_LVL_gp  5  /* BOD Level group position. */
#define FUSE_LVL_0_bm  (1<<5)  /* BOD Level bit 0 mask. */
#define FUSE_LVL_0_bp  5  /* BOD Level bit 0 position. */
#define FUSE_LVL_1_bm  (1<<6)  /* BOD Level bit 1 mask. */
#define FUSE_LVL_1_bp  6  /* BOD Level bit 1 position. */
#define FUSE_LVL_2_bm  (1<<7)  /* BOD Level bit 2 mask. */
#define FUSE_LVL_2_bp  7  /* BOD Level bit 2 position. */

/* FUSE.OSCCFG  bit masks and bit positions */
#define FUSE_CLKSEL_gm  0x07  /* Frequency Select group mask. */
#define FUSE_CLKSEL_gp  0  /* Frequency Select group position. */
#define FUSE_CLKSEL_0_bm  (1<<0)  /* Frequency Select bit 0 mask. */
#define FUSE_CLKSEL_0_bp  0  /* Frequency Select bit 0 position. */
#define FUSE_CLKSEL_1_bm  (1<<1)  /* Frequency Select bit 1 mask. */
#define FUSE_CLKSEL_1_bp  1  /* Frequency Select bit 1 position. */
#define FUSE_CLKSEL_2_bm  (1<<2)  /* Frequency Select bit 2 mask. */
#define FUSE_CLKSEL_2_bp  2  /* Frequency Select bit 2 position. */
#define FUSE_OSCLOCK_bm  0x80  /* Oscillator Lock bit mask. */
#define FUSE_OSCLOCK_bp  7  /* Oscillator Lock bit position. */

/* FUSE.SYSCFG0  bit masks and bit positions */
#define FUSE_EESAVE_bm  0x01  /* EEPROM Save bit mask. */
#define FUSE_EESAVE_bp  0  /* EEPROM Save bit position. */
#define FUSE_RSTPINCFG_gm  0x0C  /* Reset Pin Configuration group mask. */
#define FUSE_RSTPINCFG_gp  2  /* Reset Pin Configuration group position. */
#define FUSE_RSTPINCFG_0_bm  (1<<2)  /* Reset Pin Configuration bit 0 mask. */
#define FUSE_RSTPINCFG_0_bp  2  /* Reset Pin Configuration bit 0 position. */
#define FUSE_RSTPINCFG_1_bm  (1<<3)  /* Reset Pin Configuration bit 1 mask. */
#define FUSE_RSTPINCFG_1_bp  3  /* Reset Pin Configuration bit 1 position. */
#define FUSE_CRCSEL_bm  0x20  /* CRC Select bit mask. */
#define FUSE_CRCSEL_bp  5  /* CRC Select bit position. */
#define FUSE_CRCSRC_gm  0xC0  /* CRC Source group mask. */
#define FUSE_CRCSRC_gp  6  /* CRC Source group position. */
#define FUSE_CRCSRC_0_bm  (1<<6)  /* CRC Source bit 0 mask. */
#define FUSE_CRCSRC_0_bp  6  /* CRC Source bit 0 position. */
#define FUSE_CRCSRC_1_bm  (1<<7)  /* CRC Source bit 1 mask. */
#define FUSE_CRCSRC_1_bp  7  /* CRC Source bit 1 position. */

/* FUSE.SYSCFG1  bit masks and bit positions */
#define FUSE_SUT_gm  0x07  /* Startup Time group mask. */
#define FUSE_SUT_gp  0  /* Startup Time group position. */
#define FUSE_SUT_0_bm  (1<<0)  /* Startup Time bit 0 mask. */
#define FUSE_SUT_0_bp  0  /* Startup Time bit 0 position. */
#define FUSE_SUT_1_bm  (1<<1)  /* Startup Time bit 1 mask. */
#define FUSE_SUT_1_bp  1  /* Startup Time bit 1 position. */
#define FUSE_SUT_2_bm  (1<<2)  /* Startup Time bit 2 mask. */
#define FUSE_SUT_2_bp  2  /* Startup Time bit 2 position. */



/* LOCK - Lockbit */
/* LOCK.KEY  bit masks and bit positions */
#define LOCK_LB_gm  0xFFFFFFFF  /* Lock Key group mask. */
#define LOCK_LB_gp  0  /* Lock Key group position. */
#define LOCK_LB_0_bm  (1<<0)  /* Lock Key bit 0 mask. */
#define LOCK_LB_0_bp  0  /* Lock Key bit 0 position. */
#define LOCK_LB_1_bm  (1<<1)  /* Lock Key bit 1 mask. */
#define LOCK_LB_1_bp  1  /* Lock Key bit 1 position. */
#define LOCK_LB_2_bm  (1<<2)  /* Lock Key bit 2 mask. */
#define LOCK_LB_2_bp  2  /* Lock Key bit 2 position. */
#define LOCK_LB_3_bm  (1<<3)  /* Lock Key bit 3 mask. */
#define LOCK_LB_3_bp  3  /* Lock Key bit 3 position. */
#define LOCK_LB_4_bm  (1<<4)  /* Lock Key bit 4 mask. */
#define LOCK_LB_4_bp  4  /* Lock Key bit 4 position. */
#define LOCK_LB_5_bm  (1<<5)  /* Lock Key bit 5 mask. */
#define LOCK_LB_5_bp  5  /* Lock Key bit 5 position. */
#define LOCK_LB_6_bm  (1<<6)  /* Lock Key bit 6 mask. */
#define LOCK_LB_6_bp  6  /* Lock Key bit 6 position. */
#define LOCK_LB_7_bm  (1<<7)  /* Lock Key bit 7 mask. */
#define LOCK_LB_7_bp  7  /* Lock Key bit 7 position. */
#define LOCK_LB_8_bm  (1<<8)  /* Lock Key bit 8 mask. */
#define LOCK_LB_8_bp  8  /* Lock Key bit 8 position. */
#define LOCK_LB_9_bm  (1<<9)  /* Lock Key bit 9 mask. */
#define LOCK_LB_9_bp  9  /* Lock Key bit 9 position. */
#define LOCK_LB_10_bm  (1<<10)  /* Lock Key bit 10 mask. */
#define LOCK_LB_10_bp  10  /* Lock Key bit 10 position. */
#define LOCK_LB_11_bm  (1<<11)  /* Lock Key bit 11 mask. */
#define LOCK_LB_11_bp  11  /* Lock Key bit 11 position. */
#define LOCK_LB_12_bm  (1<<12)  /* Lock Key bit 12 mask. */
#define LOCK_LB_12_bp  12  /* Lock Key bit 12 position. */
#define LOCK_LB_13_bm  (1<<13)  /* Lock Key bit 13 mask. */
#define LOCK_LB_13_bp  13  /* Lock Key bit 13 position. */
#define LOCK_LB_14_bm  (1<<14)  /* Lock Key bit 14 mask. */
#define LOCK_LB_14_bp  14  /* Lock Key bit 14 position. */
#define LOCK_LB_15_bm  (1<<15)  /* Lock Key bit 15 mask. */
#define LOCK_LB_15_bp  15  /* Lock Key bit 15 position. */
#define LOCK_LB_16_bm  (1<<16)  /* Lock Key bit 16 mask. */
#define LOCK_LB_16_bp  16  /* Lock Key bit 16 position. */
#define LOCK_LB_17_bm  (1<<17)  /* Lock Key bit 17 mask. */
#define LOCK_LB_17_bp  17  /* Lock Key bit 17 position. */
#define LOCK_LB_18_bm  (1<<18)  /* Lock Key bit 18 mask. */
#define LOCK_LB_18_bp  18  /* Lock Key bit 18 position. */
#define LOCK_LB_19_bm  (1<<19)  /* Lock Key bit 19 mask. */
#define LOCK_LB_19_bp  19  /* Lock Key bit 19 position. */
#define LOCK_LB_20_bm  (1<<20)  /* Lock Key bit 20 mask. */
#define LOCK_LB_20_bp  20  /* Lock Key bit 20 position. */
#define LOCK_LB_21_bm  (1<<21)  /* Lock Key bit 21 mask. */
#define LOCK_LB_21_bp  21  /* Lock Key bit 21 position. */
#define LOCK_LB_22_bm  (1<<22)  /* Lock Key bit 22 mask. */
#define LOCK_LB_22_bp  22  /* Lock Key bit 22 position. */
#define LOCK_LB_23_bm  (1<<23)  /* Lock Key bit 23 mask. */
#define LOCK_LB_23_bp  23  /* Lock Key bit 23 position. */
#define LOCK_LB_24_bm  (1<<24)  /* Lock Key bit 24 mask. */
#define LOCK_LB_24_bp  24  /* Lock Key bit 24 position. */
#define LOCK_LB_25_bm  (1<<25)  /* Lock Key bit 25 mask. */
#define LOCK_LB_25_bp  25  /* Lock Key bit 25 position. */
#define LOCK_LB_26_bm  (1<<26)  /* Lock Key bit 26 mask. */
#define LOCK_LB_26_bp  26  /* Lock Key bit 26 position. */
#define LOCK_LB_27_bm  (1<<27)  /* Lock Key bit 27 mask. */
#define LOCK_LB_27_bp  27  /* Lock Key bit 27 position. */
#define LOCK_LB_28_bm  (1<<28)  /* Lock Key bit 28 mask. */
#define LOCK_LB_28_bp  28  /* Lock Key bit 28 position. */
#define LOCK_LB_29_bm  (1<<29)  /* Lock Key bit 29 mask. */
#define LOCK_LB_29_bp  29  /* Lock Key bit 29 position. */
#define LOCK_LB_30_bm  (1<<30)  /* Lock Key bit 30 mask. */
#define LOCK_LB_30_bp  30  /* Lock Key bit 30 position. */
#define LOCK_LB_31_bm  (1<<31)  /* Lock Key bit 31 mask. */
#define LOCK_LB_31_bp  31  /* Lock Key bit 31 position. */


/* NVMCTRL - Non-volatile Memory Controller */
/* NVMCTRL.CTRLA  bit masks and bit positions */
#define NVMCTRL_CMD_gm  0x7F  /* Command group mask. */
#define NVMCTRL_CMD_gp  0  /* Command group position. */
#define NVMCTRL_CMD_0_bm  (1<<0)  /* Command bit 0 mask. */
#define NVMCTRL_CMD_0_bp  0  /* Command bit 0 position. */
#define NVMCTRL_CMD_1_bm  (1<<1)  /* Command bit 1 mask. */
#define NVMCTRL_CMD_1_bp  1  /* Command bit 1 position. */
#define NVMCTRL_CMD_2_bm  (1<<2)  /* Command bit 2 mask. */
#define NVMCTRL_CMD_2_bp  2  /* Command bit 2 position. */
#define NVMCTRL_CMD_3_bm  (1<<3)  /* Command bit 3 mask. */
#define NVMCTRL_CMD_3_bp  3  /* Command bit 3 position. */
#define NVMCTRL_CMD_4_bm  (1<<4)  /* Command bit 4 mask. */
#define NVMCTRL_CMD_4_bp  4  /* Command bit 4 position. */
#define NVMCTRL_CMD_5_bm  (1<<5)  /* Command bit 5 mask. */
#define NVMCTRL_CMD_5_bp  5  /* Command bit 5 position. */
#define NVMCTRL_CMD_6_bm  (1<<6)  /* Command bit 6 mask. */
#define NVMCTRL_CMD_6_bp  6  /* Command bit 6 position. */

/* NVMCTRL.CTRLB  bit masks and bit positions */
#define NVMCTRL_APPCODEWP_bm  0x01  /* Application Code Write Protect bit mask. */
#define NVMCTRL_APPCODEWP_bp  0  /* Application Code Write Protect bit position. */
#define NVMCTRL_BOOTRP_bm  0x02  /* Boot Read Protect bit mask. */
#define NVMCTRL_BOOTRP_bp  1  /* Boot Read Protect bit position. */
#define NVMCTRL_APPDATAWP_bm  0x04  /* Application Data Write Protect bit mask. */
#define NVMCTRL_APPDATAWP_bp  2  /* Application Data Write Protect bit position. */
#define NVMCTRL_FLMAP_gm  0x30  /* Flash Mapping in Data space group mask. */
#define NVMCTRL_FLMAP_gp  4  /* Flash Mapping in Data space group position. */
#define NVMCTRL_FLMAP_0_bm  (1<<4)  /* Flash Mapping in Data space bit 0 mask. */
#define NVMCTRL_FLMAP_0_bp  4  /* Flash Mapping in Data space bit 0 position. */
#define NVMCTRL_FLMAP_1_bm  (1<<5)  /* Flash Mapping in Data space bit 1 mask. */
#define NVMCTRL_FLMAP_1_bp  5  /* Flash Mapping in Data space bit 1 position. */
#define NVMCTRL_FLMAPLOCK_bm  0x80  /* Flash Mapping Lock bit mask. */
#define NVMCTRL_FLMAPLOCK_bp  7  /* Flash Mapping Lock bit position. */

/* NVMCTRL.STATUS  bit masks and bit positions */
#define NVMCTRL_FBUSY_bm  0x01  /* Flash busy bit mask. */
#define NVMCTRL_FBUSY_bp  0  /* Flash busy bit position. */
#define NVMCTRL_EEBUSY_bm  0x02  /* EEPROM busy bit mask. */
#define NVMCTRL_EEBUSY_bp  1  /* EEPROM busy bit position. */
#define NVMCTRL_ERROR_gm  0x70  /* Write error group mask. */
#define NVMCTRL_ERROR_gp  4  /* Write error group position. */
#define NVMCTRL_ERROR_0_bm  (1<<4)  /* Write error bit 0 mask. */
#define NVMCTRL_ERROR_0_bp  4  /* Write error bit 0 position. */
#define NVMCTRL_ERROR_1_bm  (1<<5)  /* Write error bit 1 mask. */
#define NVMCTRL_ERROR_1_bp  5  /* Write error bit 1 position. */
#define NVMCTRL_ERROR_2_bm  (1<<6)  /* Write error bit 2 mask. */
#define NVMCTRL_ERROR_2_bp  6  /* Write error bit 2 position. */

/* NVMCTRL.INTCTRL  bit masks and bit positions */
#define NVMCTRL_EEREADY_bm  0x01  /* EEPROM Ready bit mask. */
#define NVMCTRL_EEREADY_bp  0  /* EEPROM Ready bit position. */

/* NVMCTRL.INTFLAGS  bit masks and bit positions */
/* NVMCTRL_EEREADY  is already defined. */

/* NVMCTRL.HIDDENCTRLA  bit masks and bit positions */
#define NVMCTRL_FUSERDY_bm  0x01  /* Fuse Ready bit mask. */
#define NVMCTRL_FUSERDY_bp  0  /* Fuse Ready bit position. */
#define NVMCTRL_NVMDIS_bm  0x02  /* NVM Disable bit mask. */
#define NVMCTRL_NVMDIS_bp  1  /* NVM Disable bit position. */

/* NVMCTRL.TESTCTRLA  bit masks and bit positions */
#define NVMCTRL_FLASH_bm  0x01  /* Flash array bit mask. */
#define NVMCTRL_FLASH_bp  0  /* Flash array bit position. */
#define NVMCTRL_EEPROM_bm  0x02  /* EEPROM array bit mask. */
#define NVMCTRL_EEPROM_bp  1  /* EEPROM array bit position. */
#define NVMCTRL_FLSIGROW_bm  0x04  /* Flash Signature Row bit mask. */
#define NVMCTRL_FLSIGROW_bp  2  /* Flash Signature Row bit position. */
#define NVMCTRL_FLUSERROW_bm  0x08  /* Flash User Row bit mask. */
#define NVMCTRL_FLUSERROW_bp  3  /* Flash User Row bit position. */
#define NVMCTRL_FLTEST1_bm  0x10  /* Test space 2 bit mask. */
#define NVMCTRL_FLTEST1_bp  4  /* Test space 2 bit position. */
#define NVMCTRL_FLTEST2_bm  0x80  /* Test space 2 bit mask. */
#define NVMCTRL_FLTEST2_bp  7  /* Test space 2 bit position. */

/* NVMCTRL.TESTCTRLB  bit masks and bit positions */
#define NVMCTRL_BGREQ_bm  0x01  /* Bandgap Request bit mask. */
#define NVMCTRL_BGREQ_bp  0  /* Bandgap Request bit position. */
#define NVMCTRL_CPREGDIS_bm  0x02  /* Charge Pump Regulator Disable bit mask. */
#define NVMCTRL_CPREGDIS_bp  1  /* Charge Pump Regulator Disable bit position. */
#define NVMCTRL_VRAMPDIS_bm  0x04  /* Voltage ramping for programming operations bit mask. */
#define NVMCTRL_VRAMPDIS_bp  2  /* Voltage ramping for programming operations bit position. */
#define NVMCTRL_WEAKERASE_bm  0x10  /* Weak erase enable bit mask. */
#define NVMCTRL_WEAKERASE_bp  4  /* Weak erase enable bit position. */
#define NVMCTRL_WRITEONE_bm  0x20  /* Write 1 behavior bit mask. */
#define NVMCTRL_WRITEONE_bp  5  /* Write 1 behavior bit position. */
#define NVMCTRL_NVMEN_bm  0x80  /* NVM enable override bit mask. */
#define NVMCTRL_NVMEN_bp  7  /* NVM enable override bit position. */

/* NVMCTRL.TESTCTRLC  bit masks and bit positions */
#define NVMCTRL_TESTEN_bm  0x04  /* Test Enable bit mask. */
#define NVMCTRL_TESTEN_bp  2  /* Test Enable bit position. */
#define NVMCTRL_REFPROG_bm  0x08  /* Reference Programming bit mask. */
#define NVMCTRL_REFPROG_bp  3  /* Reference Programming bit position. */
#define NVMCTRL_BODREQ_bm  0x10  /* BOD Request Enable bit mask. */
#define NVMCTRL_BODREQ_bp  4  /* BOD Request Enable bit position. */
#define NVMCTRL_HALFROW_bm  0x20  /* Half-row Programming bit mask. */
#define NVMCTRL_HALFROW_bp  5  /* Half-row Programming bit position. */

/* NVMCTRL.TESTCTRLD  bit masks and bit positions */
#define NVMCTRL_ICELLSEL_gm  0x07  /* Cell Current Select group mask. */
#define NVMCTRL_ICELLSEL_gp  0  /* Cell Current Select group position. */
#define NVMCTRL_ICELLSEL_0_bm  (1<<0)  /* Cell Current Select bit 0 mask. */
#define NVMCTRL_ICELLSEL_0_bp  0  /* Cell Current Select bit 0 position. */
#define NVMCTRL_ICELLSEL_1_bm  (1<<1)  /* Cell Current Select bit 1 mask. */
#define NVMCTRL_ICELLSEL_1_bp  1  /* Cell Current Select bit 1 position. */
#define NVMCTRL_ICELLSEL_2_bm  (1<<2)  /* Cell Current Select bit 2 mask. */
#define NVMCTRL_ICELLSEL_2_bp  2  /* Cell Current Select bit 2 position. */
#define NVMCTRL_ICELLSRC_gm  0x18  /* Cell Current Source Select group mask. */
#define NVMCTRL_ICELLSRC_gp  3  /* Cell Current Source Select group position. */
#define NVMCTRL_ICELLSRC_0_bm  (1<<3)  /* Cell Current Source Select bit 0 mask. */
#define NVMCTRL_ICELLSRC_0_bp  3  /* Cell Current Source Select bit 0 position. */
#define NVMCTRL_ICELLSRC_1_bm  (1<<4)  /* Cell Current Source Select bit 1 mask. */
#define NVMCTRL_ICELLSRC_1_bp  4  /* Cell Current Source Select bit 1 position. */
#define NVMCTRL_ICELLEN_bm  0x20  /* Cell Current Enable bit mask. */
#define NVMCTRL_ICELLEN_bp  5  /* Cell Current Enable bit position. */

/* NVMCTRL.TESTCTRLE  bit masks and bit positions */
#define NVMCTRL_EVENROW_bm  0x01  /* Even Rows selected bit mask. */
#define NVMCTRL_EVENROW_bp  0  /* Even Rows selected bit position. */
#define NVMCTRL_ODDROW_bm  0x02  /* Odd Rows selected bit mask. */
#define NVMCTRL_ODDROW_bp  1  /* Odd Rows selected bit position. */
#define NVMCTRL_EVENCOL_bm  0x04  /* Even Columns selected bit mask. */
#define NVMCTRL_EVENCOL_bp  2  /* Even Columns selected bit position. */
#define NVMCTRL_ODDCOL_bm  0x08  /* Odd Columns selected bit mask. */
#define NVMCTRL_ODDCOL_bp  3  /* Odd Columns selected bit position. */
#define NVMCTRL_SKIPERASE_bm  0x10  /* Skip Erase operation bit mask. */
#define NVMCTRL_SKIPERASE_bp  4  /* Skip Erase operation bit position. */
#define NVMCTRL_SKIPWRITE_bm  0x20  /* Skip Write operation bit mask. */
#define NVMCTRL_SKIPWRITE_bp  5  /* Skip Write operation bit position. */

/* NVMCTRL.TESTCTRLF  bit masks and bit positions */
#define NVMCTRL_MARGINSEL_gm  0x07  /* Margin Mode Select group mask. */
#define NVMCTRL_MARGINSEL_gp  0  /* Margin Mode Select group position. */
#define NVMCTRL_MARGINSEL_0_bm  (1<<0)  /* Margin Mode Select bit 0 mask. */
#define NVMCTRL_MARGINSEL_0_bp  0  /* Margin Mode Select bit 0 position. */
#define NVMCTRL_MARGINSEL_1_bm  (1<<1)  /* Margin Mode Select bit 1 mask. */
#define NVMCTRL_MARGINSEL_1_bp  1  /* Margin Mode Select bit 1 position. */
#define NVMCTRL_MARGINSEL_2_bm  (1<<2)  /* Margin Mode Select bit 2 mask. */
#define NVMCTRL_MARGINSEL_2_bp  2  /* Margin Mode Select bit 2 position. */
#define NVMCTRL_EXTTIMED_bm  0x10  /* Programmign Externally Timed bit mask. */
#define NVMCTRL_EXTTIMED_bp  4  /* Programmign Externally Timed bit position. */
#define NVMCTRL_IREFMAR_gm  0xC0  /* Reference Current group mask. */
#define NVMCTRL_IREFMAR_gp  6  /* Reference Current group position. */
#define NVMCTRL_IREFMAR_0_bm  (1<<6)  /* Reference Current bit 0 mask. */
#define NVMCTRL_IREFMAR_0_bp  6  /* Reference Current bit 0 position. */
#define NVMCTRL_IREFMAR_1_bm  (1<<7)  /* Reference Current bit 1 mask. */
#define NVMCTRL_IREFMAR_1_bp  7  /* Reference Current bit 1 position. */

/* NVMCTRL.TESTCTRLG  bit masks and bit positions */
#define NVMCTRL_EEBIT_bm  0x01  /* EEPROM Bit Line Override bit mask. */
#define NVMCTRL_EEBIT_bp  0  /* EEPROM Bit Line Override bit position. */
#define NVMCTRL_EEWORD_bm  0x02  /* EEPROM Word Line Override bit mask. */
#define NVMCTRL_EEWORD_bp  1  /* EEPROM Word Line Override bit position. */
#define NVMCTRL_EELINE_bm  0x04  /* EEPROM Word/Bit Line Override bit mask. */
#define NVMCTRL_EELINE_bp  2  /* EEPROM Word/Bit Line Override bit position. */
#define NVMCTRL_FLBIT_bm  0x08  /* Flash Bit Line Override bit mask. */
#define NVMCTRL_FLBIT_bp  3  /* Flash Bit Line Override bit position. */
#define NVMCTRL_FLWORD_bm  0x10  /* Flash Word Line Override bit mask. */
#define NVMCTRL_FLWORD_bp  4  /* Flash Word Line Override bit position. */
#define NVMCTRL_FLLINE_bm  0x20  /* Flash Word/Bit Line Override Enable bit mask. */
#define NVMCTRL_FLLINE_bp  5  /* Flash Word/Bit Line Override Enable bit position. */
#define NVMCTRL_SRCLINE_bm  0x80  /* Source Line regulation bit mask. */
#define NVMCTRL_SRCLINE_bp  7  /* Source Line regulation bit position. */

/* NVMCTRL.TESTCTRLH  bit masks and bit positions */
#define NVMCTRL_IMARGIN_gm  0x3F  /* Margin read current calibration group mask. */
#define NVMCTRL_IMARGIN_gp  0  /* Margin read current calibration group position. */
#define NVMCTRL_IMARGIN_0_bm  (1<<0)  /* Margin read current calibration bit 0 mask. */
#define NVMCTRL_IMARGIN_0_bp  0  /* Margin read current calibration bit 0 position. */
#define NVMCTRL_IMARGIN_1_bm  (1<<1)  /* Margin read current calibration bit 1 mask. */
#define NVMCTRL_IMARGIN_1_bp  1  /* Margin read current calibration bit 1 position. */
#define NVMCTRL_IMARGIN_2_bm  (1<<2)  /* Margin read current calibration bit 2 mask. */
#define NVMCTRL_IMARGIN_2_bp  2  /* Margin read current calibration bit 2 position. */
#define NVMCTRL_IMARGIN_3_bm  (1<<3)  /* Margin read current calibration bit 3 mask. */
#define NVMCTRL_IMARGIN_3_bp  3  /* Margin read current calibration bit 3 position. */
#define NVMCTRL_IMARGIN_4_bm  (1<<4)  /* Margin read current calibration bit 4 mask. */
#define NVMCTRL_IMARGIN_4_bp  4  /* Margin read current calibration bit 4 position. */
#define NVMCTRL_IMARGIN_5_bm  (1<<5)  /* Margin read current calibration bit 5 mask. */
#define NVMCTRL_IMARGIN_5_bp  5  /* Margin read current calibration bit 5 position. */

/* NVMCTRL.TESTCTRLI  bit masks and bit positions */
#define NVMCTRL_VPPBYPASS_bm  0x01  /* VPP bypass enable bit mask. */
#define NVMCTRL_VPPBYPASS_bp  0  /* VPP bypass enable bit position. */
#define NVMCTRL_ODDEVENDIS_bm  0x02  /* Odd/Even select disable bit mask. */
#define NVMCTRL_ODDEVENDIS_bp  1  /* Odd/Even select disable bit position. */
#define NVMCTRL_ANAHV_gm  0x70  /* Analog high voltage test channel group mask. */
#define NVMCTRL_ANAHV_gp  4  /* Analog high voltage test channel group position. */
#define NVMCTRL_ANAHV_0_bm  (1<<4)  /* Analog high voltage test channel bit 0 mask. */
#define NVMCTRL_ANAHV_0_bp  4  /* Analog high voltage test channel bit 0 position. */
#define NVMCTRL_ANAHV_1_bm  (1<<5)  /* Analog high voltage test channel bit 1 mask. */
#define NVMCTRL_ANAHV_1_bp  5  /* Analog high voltage test channel bit 1 position. */
#define NVMCTRL_ANAHV_2_bm  (1<<6)  /* Analog high voltage test channel bit 2 mask. */
#define NVMCTRL_ANAHV_2_bp  6  /* Analog high voltage test channel bit 2 position. */

/* NVMCTRL.TESTCTRLJ  bit masks and bit positions */
#define NVMCTRL_ANA2_gm  0x07  /* Analog Test Channel 2 group mask. */
#define NVMCTRL_ANA2_gp  0  /* Analog Test Channel 2 group position. */
#define NVMCTRL_ANA2_0_bm  (1<<0)  /* Analog Test Channel 2 bit 0 mask. */
#define NVMCTRL_ANA2_0_bp  0  /* Analog Test Channel 2 bit 0 position. */
#define NVMCTRL_ANA2_1_bm  (1<<1)  /* Analog Test Channel 2 bit 1 mask. */
#define NVMCTRL_ANA2_1_bp  1  /* Analog Test Channel 2 bit 1 position. */
#define NVMCTRL_ANA2_2_bm  (1<<2)  /* Analog Test Channel 2 bit 2 mask. */
#define NVMCTRL_ANA2_2_bp  2  /* Analog Test Channel 2 bit 2 position. */
#define NVMCTRL_ANA3_gm  0x38  /* Analog Test Channel 3 group mask. */
#define NVMCTRL_ANA3_gp  3  /* Analog Test Channel 3 group position. */
#define NVMCTRL_ANA3_0_bm  (1<<3)  /* Analog Test Channel 3 bit 0 mask. */
#define NVMCTRL_ANA3_0_bp  3  /* Analog Test Channel 3 bit 0 position. */
#define NVMCTRL_ANA3_1_bm  (1<<4)  /* Analog Test Channel 3 bit 1 mask. */
#define NVMCTRL_ANA3_1_bp  4  /* Analog Test Channel 3 bit 1 position. */
#define NVMCTRL_ANA3_2_bm  (1<<5)  /* Analog Test Channel 3 bit 2 mask. */
#define NVMCTRL_ANA3_2_bp  5  /* Analog Test Channel 3 bit 2 position. */

/* NVMCTRL.TESTCTRLK  bit masks and bit positions */
#define NVMCTRL_ANA0_gm  0x07  /* Analog Test Channel 0 group mask. */
#define NVMCTRL_ANA0_gp  0  /* Analog Test Channel 0 group position. */
#define NVMCTRL_ANA0_0_bm  (1<<0)  /* Analog Test Channel 0 bit 0 mask. */
#define NVMCTRL_ANA0_0_bp  0  /* Analog Test Channel 0 bit 0 position. */
#define NVMCTRL_ANA0_1_bm  (1<<1)  /* Analog Test Channel 0 bit 1 mask. */
#define NVMCTRL_ANA0_1_bp  1  /* Analog Test Channel 0 bit 1 position. */
#define NVMCTRL_ANA0_2_bm  (1<<2)  /* Analog Test Channel 0 bit 2 mask. */
#define NVMCTRL_ANA0_2_bp  2  /* Analog Test Channel 0 bit 2 position. */
#define NVMCTRL_ANA1_gm  0x70  /* Analog Test Chennel 1 group mask. */
#define NVMCTRL_ANA1_gp  4  /* Analog Test Chennel 1 group position. */
#define NVMCTRL_ANA1_0_bm  (1<<4)  /* Analog Test Chennel 1 bit 0 mask. */
#define NVMCTRL_ANA1_0_bp  4  /* Analog Test Chennel 1 bit 0 position. */
#define NVMCTRL_ANA1_1_bm  (1<<5)  /* Analog Test Chennel 1 bit 1 mask. */
#define NVMCTRL_ANA1_1_bp  5  /* Analog Test Chennel 1 bit 1 position. */
#define NVMCTRL_ANA1_2_bm  (1<<6)  /* Analog Test Chennel 1 bit 2 mask. */
#define NVMCTRL_ANA1_2_bp  6  /* Analog Test Chennel 1 bit 2 position. */

/* NVMCTRL.TESTCTRLL  bit masks and bit positions */
#define NVMCTRL_EELOCK_bm  0x01  /* EEPROM Lock Fuses bit mask. */
#define NVMCTRL_EELOCK_bp  0  /* EEPROM Lock Fuses bit position. */
#define NVMCTRL_EEHIDDEN_bm  0x02  /* EEPROM Hidden Fuses bit mask. */
#define NVMCTRL_EEHIDDEN_bp  1  /* EEPROM Hidden Fuses bit position. */
#define NVMCTRL_EEFUSE0_bm  0x04  /* EEPROM User Fuses byte 0-7 bit mask. */
#define NVMCTRL_EEFUSE0_bp  2  /* EEPROM User Fuses byte 0-7 bit position. */
#define NVMCTRL_EEFUSE1_bm  0x08  /* EEPROM User Fuses byte 8-15 bit mask. */
#define NVMCTRL_EEFUSE1_bp  3  /* EEPROM User Fuses byte 8-15 bit position. */
#define NVMCTRL_EECALIB0_bm  0x10  /* EEPROM Calibration Bytes 0-7 bit mask. */
#define NVMCTRL_EECALIB0_bp  4  /* EEPROM Calibration Bytes 0-7 bit position. */
#define NVMCTRL_EECALIB1_bm  0x20  /* EEPROM Calibration Bytes 8-15 bit mask. */
#define NVMCTRL_EECALIB1_bp  5  /* EEPROM Calibration Bytes 8-15 bit position. */
#define NVMCTRL_EECALIB2_bm  0x40  /* EEPROM Calibration Bytes 16-23 bit mask. */
#define NVMCTRL_EECALIB2_bp  6  /* EEPROM Calibration Bytes 16-23 bit position. */
#define NVMCTRL_EECALIB3_bm  0x80  /* EEPROM Calibration Bytes 24-31 bit mask. */
#define NVMCTRL_EECALIB3_bp  7  /* EEPROM Calibration Bytes 24-31 bit position. */

/* NVMCTRL.CALA  bit masks and bit positions */
#define NVMCTRL_ERASETIME_gm  0x0F  /* Write Time group mask. */
#define NVMCTRL_ERASETIME_gp  0  /* Write Time group position. */
#define NVMCTRL_ERASETIME_0_bm  (1<<0)  /* Write Time bit 0 mask. */
#define NVMCTRL_ERASETIME_0_bp  0  /* Write Time bit 0 position. */
#define NVMCTRL_ERASETIME_1_bm  (1<<1)  /* Write Time bit 1 mask. */
#define NVMCTRL_ERASETIME_1_bp  1  /* Write Time bit 1 position. */
#define NVMCTRL_ERASETIME_2_bm  (1<<2)  /* Write Time bit 2 mask. */
#define NVMCTRL_ERASETIME_2_bp  2  /* Write Time bit 2 position. */
#define NVMCTRL_ERASETIME_3_bm  (1<<3)  /* Write Time bit 3 mask. */
#define NVMCTRL_ERASETIME_3_bp  3  /* Write Time bit 3 position. */
#define NVMCTRL_WRITETIME_gm  0xF0  /* Erase Time group mask. */
#define NVMCTRL_WRITETIME_gp  4  /* Erase Time group position. */
#define NVMCTRL_WRITETIME_0_bm  (1<<4)  /* Erase Time bit 0 mask. */
#define NVMCTRL_WRITETIME_0_bp  4  /* Erase Time bit 0 position. */
#define NVMCTRL_WRITETIME_1_bm  (1<<5)  /* Erase Time bit 1 mask. */
#define NVMCTRL_WRITETIME_1_bp  5  /* Erase Time bit 1 position. */
#define NVMCTRL_WRITETIME_2_bm  (1<<6)  /* Erase Time bit 2 mask. */
#define NVMCTRL_WRITETIME_2_bp  6  /* Erase Time bit 2 position. */
#define NVMCTRL_WRITETIME_3_bm  (1<<7)  /* Erase Time bit 3 mask. */
#define NVMCTRL_WRITETIME_3_bp  7  /* Erase Time bit 3 position. */

/* NVMCTRL.CALB  bit masks and bit positions */
#define NVMCTRL_WRITELVL_gm  0x0F  /* Write Voltage Level group mask. */
#define NVMCTRL_WRITELVL_gp  0  /* Write Voltage Level group position. */
#define NVMCTRL_WRITELVL_0_bm  (1<<0)  /* Write Voltage Level bit 0 mask. */
#define NVMCTRL_WRITELVL_0_bp  0  /* Write Voltage Level bit 0 position. */
#define NVMCTRL_WRITELVL_1_bm  (1<<1)  /* Write Voltage Level bit 1 mask. */
#define NVMCTRL_WRITELVL_1_bp  1  /* Write Voltage Level bit 1 position. */
#define NVMCTRL_WRITELVL_2_bm  (1<<2)  /* Write Voltage Level bit 2 mask. */
#define NVMCTRL_WRITELVL_2_bp  2  /* Write Voltage Level bit 2 position. */
#define NVMCTRL_WRITELVL_3_bm  (1<<3)  /* Write Voltage Level bit 3 mask. */
#define NVMCTRL_WRITELVL_3_bp  3  /* Write Voltage Level bit 3 position. */
#define NVMCTRL_ERASELVL_gm  0xF0  /* Erase Voltage Level group mask. */
#define NVMCTRL_ERASELVL_gp  4  /* Erase Voltage Level group position. */
#define NVMCTRL_ERASELVL_0_bm  (1<<4)  /* Erase Voltage Level bit 0 mask. */
#define NVMCTRL_ERASELVL_0_bp  4  /* Erase Voltage Level bit 0 position. */
#define NVMCTRL_ERASELVL_1_bm  (1<<5)  /* Erase Voltage Level bit 1 mask. */
#define NVMCTRL_ERASELVL_1_bp  5  /* Erase Voltage Level bit 1 position. */
#define NVMCTRL_ERASELVL_2_bm  (1<<6)  /* Erase Voltage Level bit 2 mask. */
#define NVMCTRL_ERASELVL_2_bp  6  /* Erase Voltage Level bit 2 position. */
#define NVMCTRL_ERASELVL_3_bm  (1<<7)  /* Erase Voltage Level bit 3 mask. */
#define NVMCTRL_ERASELVL_3_bp  7  /* Erase Voltage Level bit 3 position. */

/* NVMCTRL.CALC  bit masks and bit positions */
#define NVMCTRL_BITLINE_gm  0x07  /* Bit Line Voltage Calibration group mask. */
#define NVMCTRL_BITLINE_gp  0  /* Bit Line Voltage Calibration group position. */
#define NVMCTRL_BITLINE_0_bm  (1<<0)  /* Bit Line Voltage Calibration bit 0 mask. */
#define NVMCTRL_BITLINE_0_bp  0  /* Bit Line Voltage Calibration bit 0 position. */
#define NVMCTRL_BITLINE_1_bm  (1<<1)  /* Bit Line Voltage Calibration bit 1 mask. */
#define NVMCTRL_BITLINE_1_bp  1  /* Bit Line Voltage Calibration bit 1 position. */
#define NVMCTRL_BITLINE_2_bm  (1<<2)  /* Bit Line Voltage Calibration bit 2 mask. */
#define NVMCTRL_BITLINE_2_bp  2  /* Bit Line Voltage Calibration bit 2 position. */
#define NVMCTRL_FLIREF_gm  0x38  /* Flash Reference Current group mask. */
#define NVMCTRL_FLIREF_gp  3  /* Flash Reference Current group position. */
#define NVMCTRL_FLIREF_0_bm  (1<<3)  /* Flash Reference Current bit 0 mask. */
#define NVMCTRL_FLIREF_0_bp  3  /* Flash Reference Current bit 0 position. */
#define NVMCTRL_FLIREF_1_bm  (1<<4)  /* Flash Reference Current bit 1 mask. */
#define NVMCTRL_FLIREF_1_bp  4  /* Flash Reference Current bit 1 position. */
#define NVMCTRL_FLIREF_2_bm  (1<<5)  /* Flash Reference Current bit 2 mask. */
#define NVMCTRL_FLIREF_2_bp  5  /* Flash Reference Current bit 2 position. */

/* NVMCTRL.CALD  bit masks and bit positions */
#define NVMCTRL_WRITERAMP_gm  0x0F  /* Write Voltage Ramp Calibration group mask. */
#define NVMCTRL_WRITERAMP_gp  0  /* Write Voltage Ramp Calibration group position. */
#define NVMCTRL_WRITERAMP_0_bm  (1<<0)  /* Write Voltage Ramp Calibration bit 0 mask. */
#define NVMCTRL_WRITERAMP_0_bp  0  /* Write Voltage Ramp Calibration bit 0 position. */
#define NVMCTRL_WRITERAMP_1_bm  (1<<1)  /* Write Voltage Ramp Calibration bit 1 mask. */
#define NVMCTRL_WRITERAMP_1_bp  1  /* Write Voltage Ramp Calibration bit 1 position. */
#define NVMCTRL_WRITERAMP_2_bm  (1<<2)  /* Write Voltage Ramp Calibration bit 2 mask. */
#define NVMCTRL_WRITERAMP_2_bp  2  /* Write Voltage Ramp Calibration bit 2 position. */
#define NVMCTRL_WRITERAMP_3_bm  (1<<3)  /* Write Voltage Ramp Calibration bit 3 mask. */
#define NVMCTRL_WRITERAMP_3_bp  3  /* Write Voltage Ramp Calibration bit 3 position. */
#define NVMCTRL_ERASERAMP_gm  0xF0  /* Erase Voltage Ramp Calibration group mask. */
#define NVMCTRL_ERASERAMP_gp  4  /* Erase Voltage Ramp Calibration group position. */
#define NVMCTRL_ERASERAMP_0_bm  (1<<4)  /* Erase Voltage Ramp Calibration bit 0 mask. */
#define NVMCTRL_ERASERAMP_0_bp  4  /* Erase Voltage Ramp Calibration bit 0 position. */
#define NVMCTRL_ERASERAMP_1_bm  (1<<5)  /* Erase Voltage Ramp Calibration bit 1 mask. */
#define NVMCTRL_ERASERAMP_1_bp  5  /* Erase Voltage Ramp Calibration bit 1 position. */
#define NVMCTRL_ERASERAMP_2_bm  (1<<6)  /* Erase Voltage Ramp Calibration bit 2 mask. */
#define NVMCTRL_ERASERAMP_2_bp  6  /* Erase Voltage Ramp Calibration bit 2 position. */
#define NVMCTRL_ERASERAMP_3_bm  (1<<7)  /* Erase Voltage Ramp Calibration bit 3 mask. */
#define NVMCTRL_ERASERAMP_3_bp  7  /* Erase Voltage Ramp Calibration bit 3 position. */

/* NVMCTRL.CALE  bit masks and bit positions */
#define NVMCTRL_BIASTIME_gm  0x07  /* Bias Start-up Time group mask. */
#define NVMCTRL_BIASTIME_gp  0  /* Bias Start-up Time group position. */
#define NVMCTRL_BIASTIME_0_bm  (1<<0)  /* Bias Start-up Time bit 0 mask. */
#define NVMCTRL_BIASTIME_0_bp  0  /* Bias Start-up Time bit 0 position. */
#define NVMCTRL_BIASTIME_1_bm  (1<<1)  /* Bias Start-up Time bit 1 mask. */
#define NVMCTRL_BIASTIME_1_bp  1  /* Bias Start-up Time bit 1 position. */
#define NVMCTRL_BIASTIME_2_bm  (1<<2)  /* Bias Start-up Time bit 2 mask. */
#define NVMCTRL_BIASTIME_2_bp  2  /* Bias Start-up Time bit 2 position. */
#define NVMCTRL_DISCHGTIME_gm  0x38  /* VPP Discharge Time group mask. */
#define NVMCTRL_DISCHGTIME_gp  3  /* VPP Discharge Time group position. */
#define NVMCTRL_DISCHGTIME_0_bm  (1<<3)  /* VPP Discharge Time bit 0 mask. */
#define NVMCTRL_DISCHGTIME_0_bp  3  /* VPP Discharge Time bit 0 position. */
#define NVMCTRL_DISCHGTIME_1_bm  (1<<4)  /* VPP Discharge Time bit 1 mask. */
#define NVMCTRL_DISCHGTIME_1_bp  4  /* VPP Discharge Time bit 1 position. */
#define NVMCTRL_DISCHGTIME_2_bm  (1<<5)  /* VPP Discharge Time bit 2 mask. */
#define NVMCTRL_DISCHGTIME_2_bp  5  /* VPP Discharge Time bit 2 position. */

/* NVMCTRL.CALF  bit masks and bit positions */
#define NVMCTRL_EEIREF_gm  0x07  /* EEPROM Reference Current Calibration group mask. */
#define NVMCTRL_EEIREF_gp  0  /* EEPROM Reference Current Calibration group position. */
#define NVMCTRL_EEIREF_0_bm  (1<<0)  /* EEPROM Reference Current Calibration bit 0 mask. */
#define NVMCTRL_EEIREF_0_bp  0  /* EEPROM Reference Current Calibration bit 0 position. */
#define NVMCTRL_EEIREF_1_bm  (1<<1)  /* EEPROM Reference Current Calibration bit 1 mask. */
#define NVMCTRL_EEIREF_1_bp  1  /* EEPROM Reference Current Calibration bit 1 position. */
#define NVMCTRL_EEIREF_2_bm  (1<<2)  /* EEPROM Reference Current Calibration bit 2 mask. */
#define NVMCTRL_EEIREF_2_bp  2  /* EEPROM Reference Current Calibration bit 2 position. */
#define NVMCTRL_CPFRQ_gm  0x30  /* Charge Pump Oscillator Frequency group mask. */
#define NVMCTRL_CPFRQ_gp  4  /* Charge Pump Oscillator Frequency group position. */
#define NVMCTRL_CPFRQ_0_bm  (1<<4)  /* Charge Pump Oscillator Frequency bit 0 mask. */
#define NVMCTRL_CPFRQ_0_bp  4  /* Charge Pump Oscillator Frequency bit 0 position. */
#define NVMCTRL_CPFRQ_1_bm  (1<<5)  /* Charge Pump Oscillator Frequency bit 1 mask. */
#define NVMCTRL_CPFRQ_1_bp  5  /* Charge Pump Oscillator Frequency bit 1 position. */
#define NVMCTRL_WORDLINE_gm  0xC0  /* Word Line Programming Voltage Calibration group mask. */
#define NVMCTRL_WORDLINE_gp  6  /* Word Line Programming Voltage Calibration group position. */
#define NVMCTRL_WORDLINE_0_bm  (1<<6)  /* Word Line Programming Voltage Calibration bit 0 mask. */
#define NVMCTRL_WORDLINE_0_bp  6  /* Word Line Programming Voltage Calibration bit 0 position. */
#define NVMCTRL_WORDLINE_1_bm  (1<<7)  /* Word Line Programming Voltage Calibration bit 1 mask. */
#define NVMCTRL_WORDLINE_1_bp  7  /* Word Line Programming Voltage Calibration bit 1 position. */

/* NVMCTRL.CALG  bit masks and bit positions */
#define NVMCTRL_FLIPROG_gm  0x0F  /* Flash Programming Current Calibration group mask. */
#define NVMCTRL_FLIPROG_gp  0  /* Flash Programming Current Calibration group position. */
#define NVMCTRL_FLIPROG_0_bm  (1<<0)  /* Flash Programming Current Calibration bit 0 mask. */
#define NVMCTRL_FLIPROG_0_bp  0  /* Flash Programming Current Calibration bit 0 position. */
#define NVMCTRL_FLIPROG_1_bm  (1<<1)  /* Flash Programming Current Calibration bit 1 mask. */
#define NVMCTRL_FLIPROG_1_bp  1  /* Flash Programming Current Calibration bit 1 position. */
#define NVMCTRL_FLIPROG_2_bm  (1<<2)  /* Flash Programming Current Calibration bit 2 mask. */
#define NVMCTRL_FLIPROG_2_bp  2  /* Flash Programming Current Calibration bit 2 position. */
#define NVMCTRL_FLIPROG_3_bm  (1<<3)  /* Flash Programming Current Calibration bit 3 mask. */
#define NVMCTRL_FLIPROG_3_bp  3  /* Flash Programming Current Calibration bit 3 position. */
#define NVMCTRL_EEIPROG_gm  0xF0  /* EEPROM Programming Current Calibration group mask. */
#define NVMCTRL_EEIPROG_gp  4  /* EEPROM Programming Current Calibration group position. */
#define NVMCTRL_EEIPROG_0_bm  (1<<4)  /* EEPROM Programming Current Calibration bit 0 mask. */
#define NVMCTRL_EEIPROG_0_bp  4  /* EEPROM Programming Current Calibration bit 0 position. */
#define NVMCTRL_EEIPROG_1_bm  (1<<5)  /* EEPROM Programming Current Calibration bit 1 mask. */
#define NVMCTRL_EEIPROG_1_bp  5  /* EEPROM Programming Current Calibration bit 1 position. */
#define NVMCTRL_EEIPROG_2_bm  (1<<6)  /* EEPROM Programming Current Calibration bit 2 mask. */
#define NVMCTRL_EEIPROG_2_bp  6  /* EEPROM Programming Current Calibration bit 2 position. */
#define NVMCTRL_EEIPROG_3_bm  (1<<7)  /* EEPROM Programming Current Calibration bit 3 mask. */
#define NVMCTRL_EEIPROG_3_bp  7  /* EEPROM Programming Current Calibration bit 3 position. */


/* PORT - I/O Ports */
/* PORT.INTFLAGS  bit masks and bit positions */
#define PORT_INT_gm  0xFF  /* Pin Interrupt Flag group mask. */
#define PORT_INT_gp  0  /* Pin Interrupt Flag group position. */
#define PORT_INT_0_bm  (1<<0)  /* Pin Interrupt Flag bit 0 mask. */
#define PORT_INT_0_bp  0  /* Pin Interrupt Flag bit 0 position. */
#define PORT_INT0_bm  PORT_INT_0_bm  /* This define is deprecated and should not be used */
#define PORT_INT0_bp  PORT_INT_0_bp  /* This define is deprecated and should not be used */
#define PORT_INT_1_bm  (1<<1)  /* Pin Interrupt Flag bit 1 mask. */
#define PORT_INT_1_bp  1  /* Pin Interrupt Flag bit 1 position. */
#define PORT_INT1_bm  PORT_INT_1_bm  /* This define is deprecated and should not be used */
#define PORT_INT1_bp  PORT_INT_1_bp  /* This define is deprecated and should not be used */
#define PORT_INT_2_bm  (1<<2)  /* Pin Interrupt Flag bit 2 mask. */
#define PORT_INT_2_bp  2  /* Pin Interrupt Flag bit 2 position. */
#define PORT_INT2_bm  PORT_INT_2_bm  /* This define is deprecated and should not be used */
#define PORT_INT2_bp  PORT_INT_2_bp  /* This define is deprecated and should not be used */
#define PORT_INT_3_bm  (1<<3)  /* Pin Interrupt Flag bit 3 mask. */
#define PORT_INT_3_bp  3  /* Pin Interrupt Flag bit 3 position. */
#define PORT_INT3_bm  PORT_INT_3_bm  /* This define is deprecated and should not be used */
#define PORT_INT3_bp  PORT_INT_3_bp  /* This define is deprecated and should not be used */
#define PORT_INT_4_bm  (1<<4)  /* Pin Interrupt Flag bit 4 mask. */
#define PORT_INT_4_bp  4  /* Pin Interrupt Flag bit 4 position. */
#define PORT_INT4_bm  PORT_INT_4_bm  /* This define is deprecated and should not be used */
#define PORT_INT4_bp  PORT_INT_4_bp  /* This define is deprecated and should not be used */
#define PORT_INT_5_bm  (1<<5)  /* Pin Interrupt Flag bit 5 mask. */
#define PORT_INT_5_bp  5  /* Pin Interrupt Flag bit 5 position. */
#define PORT_INT5_bm  PORT_INT_5_bm  /* This define is deprecated and should not be used */
#define PORT_INT5_bp  PORT_INT_5_bp  /* This define is deprecated and should not be used */
#define PORT_INT_6_bm  (1<<6)  /* Pin Interrupt Flag bit 6 mask. */
#define PORT_INT_6_bp  6  /* Pin Interrupt Flag bit 6 position. */
#define PORT_INT6_bm  PORT_INT_6_bm  /* This define is deprecated and should not be used */
#define PORT_INT6_bp  PORT_INT_6_bp  /* This define is deprecated and should not be used */
#define PORT_INT_7_bm  (1<<7)  /* Pin Interrupt Flag bit 7 mask. */
#define PORT_INT_7_bp  7  /* Pin Interrupt Flag bit 7 position. */
#define PORT_INT7_bm  PORT_INT_7_bm  /* This define is deprecated and should not be used */
#define PORT_INT7_bp  PORT_INT_7_bp  /* This define is deprecated and should not be used */

/* PORT.PORTCTRL  bit masks and bit positions */
#define PORT_SRL_bm  0x01  /* Slew Rate Limit Enable bit mask. */
#define PORT_SRL_bp  0  /* Slew Rate Limit Enable bit position. */

/* PORT.PINCONFIG  bit masks and bit positions */
#define PORT_ISC_gm  0x07  /* Input/Sense Configuration group mask. */
#define PORT_ISC_gp  0  /* Input/Sense Configuration group position. */
#define PORT_ISC_0_bm  (1<<0)  /* Input/Sense Configuration bit 0 mask. */
#define PORT_ISC_0_bp  0  /* Input/Sense Configuration bit 0 position. */
#define PORT_ISC_1_bm  (1<<1)  /* Input/Sense Configuration bit 1 mask. */
#define PORT_ISC_1_bp  1  /* Input/Sense Configuration bit 1 position. */
#define PORT_ISC_2_bm  (1<<2)  /* Input/Sense Configuration bit 2 mask. */
#define PORT_ISC_2_bp  2  /* Input/Sense Configuration bit 2 position. */
#define PORT_PULLUPEN_bm  0x08  /* Pullup enable bit mask. */
#define PORT_PULLUPEN_bp  3  /* Pullup enable bit position. */
#define PORT_INLVL_bm  0x40  /* Input Level Select bit mask. */
#define PORT_INLVL_bp  6  /* Input Level Select bit position. */
#define PORT_INVEN_bm  0x80  /* Inverted I/O Enable bit mask. */
#define PORT_INVEN_bp  7  /* Inverted I/O Enable bit position. */

/* PORT.PIN0CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN1CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN2CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN3CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN4CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN5CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN6CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN7CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */


/* PORTMUX - Port Multiplexer */
/* PORTMUX.EVSYSROUTEA  bit masks and bit positions */
#define PORTMUX_EVOUTA_bm  0x01  /* Event Output A bit mask. */
#define PORTMUX_EVOUTA_bp  0  /* Event Output A bit position. */
#define PORTMUX_EVOUTB_bm  0x02  /* Event Output B bit mask. */
#define PORTMUX_EVOUTB_bp  1  /* Event Output B bit position. */
#define PORTMUX_EVOUTC_bm  0x04  /* Event Output C bit mask. */
#define PORTMUX_EVOUTC_bp  2  /* Event Output C bit position. */
#define PORTMUX_EVOUTD_bm  0x08  /* Event Output D bit mask. */
#define PORTMUX_EVOUTD_bp  3  /* Event Output D bit position. */
#define PORTMUX_EVOUTE_bm  0x10  /* Event Output E bit mask. */
#define PORTMUX_EVOUTE_bp  4  /* Event Output E bit position. */
#define PORTMUX_EVOUTF_bm  0x20  /* Event Output F bit mask. */
#define PORTMUX_EVOUTF_bp  5  /* Event Output F bit position. */
#define PORTMUX_EVOUTG_bm  0x40  /* Event Output G bit mask. */
#define PORTMUX_EVOUTG_bp  6  /* Event Output G bit position. */
#define PORTMUX_EXTBRK_bm  0x80  /* External Break bit mask. */
#define PORTMUX_EXTBRK_bp  7  /* External Break bit position. */

/* PORTMUX.CCLROUTEA  bit masks and bit positions */
#define PORTMUX_LUT0_bm  0x01  /*  bit mask. */
#define PORTMUX_LUT0_bp  0  /*  bit position. */
#define PORTMUX_LUT1_bm  0x02  /*  bit mask. */
#define PORTMUX_LUT1_bp  1  /*  bit position. */
#define PORTMUX_LUT2_bm  0x04  /*  bit mask. */
#define PORTMUX_LUT2_bp  2  /*  bit position. */
#define PORTMUX_LUT3_bm  0x08  /*  bit mask. */
#define PORTMUX_LUT3_bp  3  /*  bit position. */

/* PORTMUX.USARTROUTEA  bit masks and bit positions */
#define PORTMUX_USART0_gm  0x03  /*  group mask. */
#define PORTMUX_USART0_gp  0  /*  group position. */
#define PORTMUX_USART0_0_bm  (1<<0)  /* | bit 0 mask. */
#define PORTMUX_USART0_0_bp  0  /*  bit 0 position. */
#define PORTMUX_USART0_1_bm  (1<<1)  /* | bit 1 mask. */
#define PORTMUX_USART0_1_bp  1  /*  bit 1 position. */

/* PORTMUX.SPIROUTEA  bit masks and bit positions */
#define PORTMUX_SPI0_gm  0x03  /*  group mask. */
#define PORTMUX_SPI0_gp  0  /*  group position. */
#define PORTMUX_SPI0_0_bm  (1<<0)  /* | bit 0 mask. */
#define PORTMUX_SPI0_0_bp  0  /*  bit 0 position. */
#define PORTMUX_SPI0_1_bm  (1<<1)  /* | bit 1 mask. */
#define PORTMUX_SPI0_1_bp  1  /*  bit 1 position. */

/* PORTMUX.TWIROUTEA  bit masks and bit positions */
#define PORTMUX_TWI0_gm  0x03  /* Port Multiplexer TWI0 group mask. */
#define PORTMUX_TWI0_gp  0  /* Port Multiplexer TWI0 group position. */
#define PORTMUX_TWI0_0_bm  (1<<0)  /* Port Multiplexer TWI0 bit 0 mask. */
#define PORTMUX_TWI0_0_bp  0  /* Port Multiplexer TWI0 bit 0 position. */
#define PORTMUX_TWI0_1_bm  (1<<1)  /* Port Multiplexer TWI0 bit 1 mask. */
#define PORTMUX_TWI0_1_bp  1  /* Port Multiplexer TWI0 bit 1 position. */

/* PORTMUX.TCEROUTEA  bit masks and bit positions */
#define PORTMUX_TCE0_gm  0x07  /*  group mask. */
#define PORTMUX_TCE0_gp  0  /*  group position. */
#define PORTMUX_TCE0_0_bm  (1<<0)  /* | bit 0 mask. */
#define PORTMUX_TCE0_0_bp  0  /*  bit 0 position. */
#define PORTMUX_TCE0_1_bm  (1<<1)  /* | bit 1 mask. */
#define PORTMUX_TCE0_1_bp  1  /*  bit 1 position. */
#define PORTMUX_TCE0_2_bm  (1<<2)  /* | bit 2 mask. */
#define PORTMUX_TCE0_2_bp  2  /*  bit 2 position. */

/* PORTMUX.TCBROUTEA  bit masks and bit positions */
#define PORTMUX_TCB0_bm  0x01  /*  bit mask. */
#define PORTMUX_TCB0_bp  0  /*  bit position. */
#define PORTMUX_TCB1_bm  0x02  /*  bit mask. */
#define PORTMUX_TCB1_bp  1  /*  bit position. */

/* PORTMUX.TCDROUTEA  bit masks and bit positions */
#define PORTMUX_TCD0_gm  0x07  /*  group mask. */
#define PORTMUX_TCD0_gp  0  /*  group position. */
#define PORTMUX_TCD0_0_bm  (1<<0)  /* | bit 0 mask. */
#define PORTMUX_TCD0_0_bp  0  /*  bit 0 position. */
#define PORTMUX_TCD0_1_bm  (1<<1)  /* | bit 1 mask. */
#define PORTMUX_TCD0_1_bp  1  /*  bit 1 position. */
#define PORTMUX_TCD0_2_bm  (1<<2)  /* | bit 2 mask. */
#define PORTMUX_TCD0_2_bp  2  /*  bit 2 position. */

/* PORTMUX.ACROUTEA  bit masks and bit positions */
#define PORTMUX_AC0_bm  0x01  /* Analog Comparator 0 bit mask. */
#define PORTMUX_AC0_bp  0  /* Analog Comparator 0 bit position. */
#define PORTMUX_AC1_bm  0x02  /* Analog Comparator 1 bit mask. */
#define PORTMUX_AC1_bp  1  /* Analog Comparator 1 bit position. */

/* PORTMUX.TCFROUTEA  bit masks and bit positions */
#define PORTMUX_TCF0_gm  0x03  /* TCF0 Routing group mask. */
#define PORTMUX_TCF0_gp  0  /* TCF0 Routing group position. */
#define PORTMUX_TCF0_0_bm  (1<<0)  /* TCF0 Routing bit 0 mask. */
#define PORTMUX_TCF0_0_bp  0  /* TCF0 Routing bit 0 position. */
#define PORTMUX_TCF0_1_bm  (1<<1)  /* TCF0 Routing bit 1 mask. */
#define PORTMUX_TCF0_1_bp  1  /* TCF0 Routing bit 1 position. */

/* PORTMUX.ZCDROUTEA  bit masks and bit positions */
#define PORTMUX_ZCD0_bm  0x01  /* Port Multiplexer ZCD0 bit mask. */
#define PORTMUX_ZCD0_bp  0  /* Port Multiplexer ZCD0 bit position. */

/* PORTMUX.EEXROUTEA  bit masks and bit positions */
#define PORTMUX_EEXCLK_bm  0x01  /* EEX Clock bit mask. */
#define PORTMUX_EEXCLK_bp  0  /* EEX Clock bit position. */
#define PORTMUX_EEXDI_bm  0x02  /* EEX Digital Input bit mask. */
#define PORTMUX_EEXDI_bp  1  /* EEX Digital Input bit position. */
#define PORTMUX_EEXDO_bm  0x04  /* EEX Digital Output bit mask. */
#define PORTMUX_EEXDO_bp  2  /* EEX Digital Output bit position. */


/* RSTCTRL - Reset controller */
/* RSTCTRL.RSTFR  bit masks and bit positions */
#define RSTCTRL_PORF_bm  0x01  /* Power on Reset flag bit mask. */
#define RSTCTRL_PORF_bp  0  /* Power on Reset flag bit position. */
#define RSTCTRL_BORF_bm  0x02  /* Brown out detector Reset flag bit mask. */
#define RSTCTRL_BORF_bp  1  /* Brown out detector Reset flag bit position. */
#define RSTCTRL_EXTRF_bm  0x04  /* External Reset flag bit mask. */
#define RSTCTRL_EXTRF_bp  2  /* External Reset flag bit position. */
#define RSTCTRL_WDRF_bm  0x08  /* Watch dog Reset flag bit mask. */
#define RSTCTRL_WDRF_bp  3  /* Watch dog Reset flag bit position. */
#define RSTCTRL_SWRF_bm  0x10  /* Software Reset flag bit mask. */
#define RSTCTRL_SWRF_bp  4  /* Software Reset flag bit position. */
#define RSTCTRL_UPDIRF_bm  0x20  /* UPDI Reset flag bit mask. */
#define RSTCTRL_UPDIRF_bp  5  /* UPDI Reset flag bit position. */

/* RSTCTRL.SWRR  bit masks and bit positions */
#define RSTCTRL_SWRST_bm  0x01  /* Software reset enable bit mask. */
#define RSTCTRL_SWRST_bp  0  /* Software reset enable bit position. */

/* RSTCTRL.BOOTCTRL  bit masks and bit positions */
#define RSTCTRL_SYSBOOTEN_bm  0x01  /* System boot enable bit mask. */
#define RSTCTRL_SYSBOOTEN_bp  0  /* System boot enable bit position. */
#define RSTCTRL_EXTRSTSEN_gm  0x06  /* External reset startup enable group mask. */
#define RSTCTRL_EXTRSTSEN_gp  1  /* External reset startup enable group position. */
#define RSTCTRL_EXTRSTSEN_0_bm  (1<<1)  /* External reset startup enable bit 0 mask. */
#define RSTCTRL_EXTRSTSEN_0_bp  1  /* External reset startup enable bit 0 position. */
#define RSTCTRL_EXTRSTSEN_1_bm  (1<<2)  /* External reset startup enable bit 1 mask. */
#define RSTCTRL_EXTRSTSEN_1_bp  2  /* External reset startup enable bit 1 position. */
#define RSTCTRL_PDISYNC_bm  0x80  /* PDI in sync mode bit mask. */
#define RSTCTRL_PDISYNC_bp  7  /* PDI in sync mode bit position. */

/* RSTCTRL.TEST  bit masks and bit positions */
#define RSTCTRL_PORTEST_bm  0x20  /* POR Test bit mask. */
#define RSTCTRL_PORTEST_bp  5  /* POR Test bit position. */
#define RSTCTRL_RSTMASK_bm  0x40  /* RST Mask bit mask. */
#define RSTCTRL_RSTMASK_bp  6  /* RST Mask bit position. */
#define RSTCTRL_PADMASK_bm  0x80  /* PAD Mask bit mask. */
#define RSTCTRL_PADMASK_bp  7  /* PAD Mask bit position. */


/* RTC - Real-Time Counter */
/* RTC.CTRLA  bit masks and bit positions */
#define RTC_RTCEN_bm  0x01  /* Enable bit mask. */
#define RTC_RTCEN_bp  0  /* Enable bit position. */
#define RTC_CORREN_bm  0x04  /* Correction enable bit mask. */
#define RTC_CORREN_bp  2  /* Correction enable bit position. */
#define RTC_PRESCALER_gm  0x78  /* Prescaling Factor group mask. */
#define RTC_PRESCALER_gp  3  /* Prescaling Factor group position. */
#define RTC_PRESCALER_0_bm  (1<<3)  /* Prescaling Factor bit 0 mask. */
#define RTC_PRESCALER_0_bp  3  /* Prescaling Factor bit 0 position. */
#define RTC_PRESCALER_1_bm  (1<<4)  /* Prescaling Factor bit 1 mask. */
#define RTC_PRESCALER_1_bp  4  /* Prescaling Factor bit 1 position. */
#define RTC_PRESCALER_2_bm  (1<<5)  /* Prescaling Factor bit 2 mask. */
#define RTC_PRESCALER_2_bp  5  /* Prescaling Factor bit 2 position. */
#define RTC_PRESCALER_3_bm  (1<<6)  /* Prescaling Factor bit 3 mask. */
#define RTC_PRESCALER_3_bp  6  /* Prescaling Factor bit 3 position. */
#define RTC_RUNSTDBY_bm  0x80  /* Run In Standby bit mask. */
#define RTC_RUNSTDBY_bp  7  /* Run In Standby bit position. */

/* RTC.STATUS  bit masks and bit positions */
#define RTC_CTRLABUSY_bm  0x01  /* CTRLA Synchronization Busy Flag bit mask. */
#define RTC_CTRLABUSY_bp  0  /* CTRLA Synchronization Busy Flag bit position. */
#define RTC_CNTBUSY_bm  0x02  /* Count Synchronization Busy Flag bit mask. */
#define RTC_CNTBUSY_bp  1  /* Count Synchronization Busy Flag bit position. */
#define RTC_PERBUSY_bm  0x04  /* Period Synchronization Busy Flag bit mask. */
#define RTC_PERBUSY_bp  2  /* Period Synchronization Busy Flag bit position. */
#define RTC_CMPBUSY_bm  0x08  /* Comparator Synchronization Busy Flag bit mask. */
#define RTC_CMPBUSY_bp  3  /* Comparator Synchronization Busy Flag bit position. */

/* RTC.INTCTRL  bit masks and bit positions */
#define RTC_OVF_bm  0x01  /* Overflow Interrupt enable bit mask. */
#define RTC_OVF_bp  0  /* Overflow Interrupt enable bit position. */
#define RTC_CMP_bm  0x02  /* Compare Match Interrupt enable bit mask. */
#define RTC_CMP_bp  1  /* Compare Match Interrupt enable bit position. */

/* RTC.INTFLAGS  bit masks and bit positions */
/* RTC_OVF  is already defined. */
/* RTC_CMP  is already defined. */

/* RTC.DBGCTRL  bit masks and bit positions */
#define RTC_DBGRUN_bm  0x01  /* Run in debug bit mask. */
#define RTC_DBGRUN_bp  0  /* Run in debug bit position. */

/* RTC.CALIB  bit masks and bit positions */
#define RTC_ERROR_gm  0x7F  /* Error Correction Value group mask. */
#define RTC_ERROR_gp  0  /* Error Correction Value group position. */
#define RTC_ERROR_0_bm  (1<<0)  /* Error Correction Value bit 0 mask. */
#define RTC_ERROR_0_bp  0  /* Error Correction Value bit 0 position. */
#define RTC_ERROR_1_bm  (1<<1)  /* Error Correction Value bit 1 mask. */
#define RTC_ERROR_1_bp  1  /* Error Correction Value bit 1 position. */
#define RTC_ERROR_2_bm  (1<<2)  /* Error Correction Value bit 2 mask. */
#define RTC_ERROR_2_bp  2  /* Error Correction Value bit 2 position. */
#define RTC_ERROR_3_bm  (1<<3)  /* Error Correction Value bit 3 mask. */
#define RTC_ERROR_3_bp  3  /* Error Correction Value bit 3 position. */
#define RTC_ERROR_4_bm  (1<<4)  /* Error Correction Value bit 4 mask. */
#define RTC_ERROR_4_bp  4  /* Error Correction Value bit 4 position. */
#define RTC_ERROR_5_bm  (1<<5)  /* Error Correction Value bit 5 mask. */
#define RTC_ERROR_5_bp  5  /* Error Correction Value bit 5 position. */
#define RTC_ERROR_6_bm  (1<<6)  /* Error Correction Value bit 6 mask. */
#define RTC_ERROR_6_bp  6  /* Error Correction Value bit 6 position. */
#define RTC_SIGN_bm  0x80  /* Error Correction Sign Bit bit mask. */
#define RTC_SIGN_bp  7  /* Error Correction Sign Bit bit position. */

/* RTC.CLKSEL  bit masks and bit positions */
#define RTC_CLKSEL_gm  0x03  /* Clock Select group mask. */
#define RTC_CLKSEL_gp  0  /* Clock Select group position. */
#define RTC_CLKSEL_0_bm  (1<<0)  /* Clock Select bit 0 mask. */
#define RTC_CLKSEL_0_bp  0  /* Clock Select bit 0 position. */
#define RTC_CLKSEL_1_bm  (1<<1)  /* Clock Select bit 1 mask. */
#define RTC_CLKSEL_1_bp  1  /* Clock Select bit 1 position. */

/* RTC.PITCTRLA  bit masks and bit positions */
#define RTC_PITEN_bm  0x01  /* Enable bit mask. */
#define RTC_PITEN_bp  0  /* Enable bit position. */
#define RTC_PERIOD_gm  0x78  /* Period group mask. */
#define RTC_PERIOD_gp  3  /* Period group position. */
#define RTC_PERIOD_0_bm  (1<<3)  /* Period bit 0 mask. */
#define RTC_PERIOD_0_bp  3  /* Period bit 0 position. */
#define RTC_PERIOD_1_bm  (1<<4)  /* Period bit 1 mask. */
#define RTC_PERIOD_1_bp  4  /* Period bit 1 position. */
#define RTC_PERIOD_2_bm  (1<<5)  /* Period bit 2 mask. */
#define RTC_PERIOD_2_bp  5  /* Period bit 2 position. */
#define RTC_PERIOD_3_bm  (1<<6)  /* Period bit 3 mask. */
#define RTC_PERIOD_3_bp  6  /* Period bit 3 position. */

/* RTC.PITSTATUS  bit masks and bit positions */
#define RTC_CTRLBUSY_bm  0x01  /* CTRLA Synchronization Busy Flag bit mask. */
#define RTC_CTRLBUSY_bp  0  /* CTRLA Synchronization Busy Flag bit position. */

/* RTC.PITINTCTRL  bit masks and bit positions */
#define RTC_PI_bm  0x01  /* Periodic Interrupt bit mask. */
#define RTC_PI_bp  0  /* Periodic Interrupt bit position. */

/* RTC.PITINTFLAGS  bit masks and bit positions */
/* RTC_PI  is already defined. */

/* RTC.PITDBGCTRL  bit masks and bit positions */
/* RTC_DBGRUN  is already defined. */

/* RTC.PITEVGENCTRLA  bit masks and bit positions */
#define RTC_EVGEN0SEL_gm  0x0F  /* Event Generation 0 Select group mask. */
#define RTC_EVGEN0SEL_gp  0  /* Event Generation 0 Select group position. */
#define RTC_EVGEN0SEL_0_bm  (1<<0)  /* Event Generation 0 Select bit 0 mask. */
#define RTC_EVGEN0SEL_0_bp  0  /* Event Generation 0 Select bit 0 position. */
#define RTC_EVGEN0SEL_1_bm  (1<<1)  /* Event Generation 0 Select bit 1 mask. */
#define RTC_EVGEN0SEL_1_bp  1  /* Event Generation 0 Select bit 1 position. */
#define RTC_EVGEN0SEL_2_bm  (1<<2)  /* Event Generation 0 Select bit 2 mask. */
#define RTC_EVGEN0SEL_2_bp  2  /* Event Generation 0 Select bit 2 position. */
#define RTC_EVGEN0SEL_3_bm  (1<<3)  /* Event Generation 0 Select bit 3 mask. */
#define RTC_EVGEN0SEL_3_bp  3  /* Event Generation 0 Select bit 3 position. */
#define RTC_EVGEN1SEL_gm  0xF0  /* Event Generation 1 Select group mask. */
#define RTC_EVGEN1SEL_gp  4  /* Event Generation 1 Select group position. */
#define RTC_EVGEN1SEL_0_bm  (1<<4)  /* Event Generation 1 Select bit 0 mask. */
#define RTC_EVGEN1SEL_0_bp  4  /* Event Generation 1 Select bit 0 position. */
#define RTC_EVGEN1SEL_1_bm  (1<<5)  /* Event Generation 1 Select bit 1 mask. */
#define RTC_EVGEN1SEL_1_bp  5  /* Event Generation 1 Select bit 1 position. */
#define RTC_EVGEN1SEL_2_bm  (1<<6)  /* Event Generation 1 Select bit 2 mask. */
#define RTC_EVGEN1SEL_2_bp  6  /* Event Generation 1 Select bit 2 position. */
#define RTC_EVGEN1SEL_3_bm  (1<<7)  /* Event Generation 1 Select bit 3 mask. */
#define RTC_EVGEN1SEL_3_bp  7  /* Event Generation 1 Select bit 3 position. */


/* SIGROW - Signature row */
/* SIGROW.TEMPSENSE0  bit masks and bit positions */
#define SIGROW_TEMPSENSE0_gm  0xFFFF  /*  group mask. */
#define SIGROW_TEMPSENSE0_gp  0  /*  group position. */
#define SIGROW_TEMPSENSE0_0_bm  (1<<0)  /* | bit 0 mask. */
#define SIGROW_TEMPSENSE0_0_bp  0  /*  bit 0 position. */
#define SIGROW_TEMPSENSE0_1_bm  (1<<1)  /* | bit 1 mask. */
#define SIGROW_TEMPSENSE0_1_bp  1  /*  bit 1 position. */
#define SIGROW_TEMPSENSE0_2_bm  (1<<2)  /* | bit 2 mask. */
#define SIGROW_TEMPSENSE0_2_bp  2  /*  bit 2 position. */
#define SIGROW_TEMPSENSE0_3_bm  (1<<3)  /* | bit 3 mask. */
#define SIGROW_TEMPSENSE0_3_bp  3  /*  bit 3 position. */
#define SIGROW_TEMPSENSE0_4_bm  (1<<4)  /* | bit 4 mask. */
#define SIGROW_TEMPSENSE0_4_bp  4  /*  bit 4 position. */
#define SIGROW_TEMPSENSE0_5_bm  (1<<5)  /* | bit 5 mask. */
#define SIGROW_TEMPSENSE0_5_bp  5  /*  bit 5 position. */
#define SIGROW_TEMPSENSE0_6_bm  (1<<6)  /* | bit 6 mask. */
#define SIGROW_TEMPSENSE0_6_bp  6  /*  bit 6 position. */
#define SIGROW_TEMPSENSE0_7_bm  (1<<7)  /* | bit 7 mask. */
#define SIGROW_TEMPSENSE0_7_bp  7  /*  bit 7 position. */
#define SIGROW_TEMPSENSE0_8_bm  (1<<8)  /* | bit 8 mask. */
#define SIGROW_TEMPSENSE0_8_bp  8  /*  bit 8 position. */
#define SIGROW_TEMPSENSE0_9_bm  (1<<9)  /* | bit 9 mask. */
#define SIGROW_TEMPSENSE0_9_bp  9  /*  bit 9 position. */
#define SIGROW_TEMPSENSE0_10_bm  (1<<10)  /* | bit 10 mask. */
#define SIGROW_TEMPSENSE0_10_bp  10  /*  bit 10 position. */
#define SIGROW_TEMPSENSE0_11_bm  (1<<11)  /* | bit 11 mask. */
#define SIGROW_TEMPSENSE0_11_bp  11  /*  bit 11 position. */
#define SIGROW_TEMPSENSE0_12_bm  (1<<12)  /* | bit 12 mask. */
#define SIGROW_TEMPSENSE0_12_bp  12  /*  bit 12 position. */
#define SIGROW_TEMPSENSE0_13_bm  (1<<13)  /* | bit 13 mask. */
#define SIGROW_TEMPSENSE0_13_bp  13  /*  bit 13 position. */
#define SIGROW_TEMPSENSE0_14_bm  (1<<14)  /* | bit 14 mask. */
#define SIGROW_TEMPSENSE0_14_bp  14  /*  bit 14 position. */
#define SIGROW_TEMPSENSE0_15_bm  (1<<15)  /* | bit 15 mask. */
#define SIGROW_TEMPSENSE0_15_bp  15  /*  bit 15 position. */

/* SIGROW.TEMPSENSE1  bit masks and bit positions */
#define SIGROW_TEMPSENSE1_gm  0xFFFF  /*  group mask. */
#define SIGROW_TEMPSENSE1_gp  0  /*  group position. */
#define SIGROW_TEMPSENSE1_0_bm  (1<<0)  /* | bit 0 mask. */
#define SIGROW_TEMPSENSE1_0_bp  0  /*  bit 0 position. */
#define SIGROW_TEMPSENSE1_1_bm  (1<<1)  /* | bit 1 mask. */
#define SIGROW_TEMPSENSE1_1_bp  1  /*  bit 1 position. */
#define SIGROW_TEMPSENSE1_2_bm  (1<<2)  /* | bit 2 mask. */
#define SIGROW_TEMPSENSE1_2_bp  2  /*  bit 2 position. */
#define SIGROW_TEMPSENSE1_3_bm  (1<<3)  /* | bit 3 mask. */
#define SIGROW_TEMPSENSE1_3_bp  3  /*  bit 3 position. */
#define SIGROW_TEMPSENSE1_4_bm  (1<<4)  /* | bit 4 mask. */
#define SIGROW_TEMPSENSE1_4_bp  4  /*  bit 4 position. */
#define SIGROW_TEMPSENSE1_5_bm  (1<<5)  /* | bit 5 mask. */
#define SIGROW_TEMPSENSE1_5_bp  5  /*  bit 5 position. */
#define SIGROW_TEMPSENSE1_6_bm  (1<<6)  /* | bit 6 mask. */
#define SIGROW_TEMPSENSE1_6_bp  6  /*  bit 6 position. */
#define SIGROW_TEMPSENSE1_7_bm  (1<<7)  /* | bit 7 mask. */
#define SIGROW_TEMPSENSE1_7_bp  7  /*  bit 7 position. */
#define SIGROW_TEMPSENSE1_8_bm  (1<<8)  /* | bit 8 mask. */
#define SIGROW_TEMPSENSE1_8_bp  8  /*  bit 8 position. */
#define SIGROW_TEMPSENSE1_9_bm  (1<<9)  /* | bit 9 mask. */
#define SIGROW_TEMPSENSE1_9_bp  9  /*  bit 9 position. */
#define SIGROW_TEMPSENSE1_10_bm  (1<<10)  /* | bit 10 mask. */
#define SIGROW_TEMPSENSE1_10_bp  10  /*  bit 10 position. */
#define SIGROW_TEMPSENSE1_11_bm  (1<<11)  /* | bit 11 mask. */
#define SIGROW_TEMPSENSE1_11_bp  11  /*  bit 11 position. */
#define SIGROW_TEMPSENSE1_12_bm  (1<<12)  /* | bit 12 mask. */
#define SIGROW_TEMPSENSE1_12_bp  12  /*  bit 12 position. */
#define SIGROW_TEMPSENSE1_13_bm  (1<<13)  /* | bit 13 mask. */
#define SIGROW_TEMPSENSE1_13_bp  13  /*  bit 13 position. */
#define SIGROW_TEMPSENSE1_14_bm  (1<<14)  /* | bit 14 mask. */
#define SIGROW_TEMPSENSE1_14_bp  14  /*  bit 14 position. */
#define SIGROW_TEMPSENSE1_15_bm  (1<<15)  /* | bit 15 mask. */
#define SIGROW_TEMPSENSE1_15_bp  15  /*  bit 15 position. */


/* SLPCTRL - Sleep Controller */
/* SLPCTRL.CTRLA  bit masks and bit positions */
#define SLPCTRL_SEN_bm  0x01  /* Sleep enable bit mask. */
#define SLPCTRL_SEN_bp  0  /* Sleep enable bit position. */
#define SLPCTRL_SMODE_gm  0x06  /* Sleep mode group mask. */
#define SLPCTRL_SMODE_gp  1  /* Sleep mode group position. */
#define SLPCTRL_SMODE_0_bm  (1<<1)  /* Sleep mode bit 0 mask. */
#define SLPCTRL_SMODE_0_bp  1  /* Sleep mode bit 0 position. */
#define SLPCTRL_SMODE_1_bm  (1<<2)  /* Sleep mode bit 1 mask. */
#define SLPCTRL_SMODE_1_bp  2  /* Sleep mode bit 1 position. */

/* SLPCTRL.VREGCTRL  bit masks and bit positions */
#define SLPCTRL_PMODE_gm  0x07  /* Performance Mode group mask. */
#define SLPCTRL_PMODE_gp  0  /* Performance Mode group position. */
#define SLPCTRL_PMODE_0_bm  (1<<0)  /* Performance Mode bit 0 mask. */
#define SLPCTRL_PMODE_0_bp  0  /* Performance Mode bit 0 position. */
#define SLPCTRL_PMODE_1_bm  (1<<1)  /* Performance Mode bit 1 mask. */
#define SLPCTRL_PMODE_1_bp  1  /* Performance Mode bit 1 position. */
#define SLPCTRL_PMODE_2_bm  (1<<2)  /* Performance Mode bit 2 mask. */
#define SLPCTRL_PMODE_2_bp  2  /* Performance Mode bit 2 position. */
#define SLPCTRL_HTBB_bm  0x10  /* High Temperature Back Bias bit mask. */
#define SLPCTRL_HTBB_bp  4  /* High Temperature Back Bias bit position. */
#define SLPCTRL_LOWLAT_bm  0x80  /* Low Latency start-up from deep sleep bit mask. */
#define SLPCTRL_LOWLAT_bp  7  /* Low Latency start-up from deep sleep bit position. */

/* SLPCTRL.CALLDO  bit masks and bit positions */
#define SLPCTRL_LDOLVL_gm  0x07  /* LDO Level group mask. */
#define SLPCTRL_LDOLVL_gp  0  /* LDO Level group position. */
#define SLPCTRL_LDOLVL_0_bm  (1<<0)  /* LDO Level bit 0 mask. */
#define SLPCTRL_LDOLVL_0_bp  0  /* LDO Level bit 0 position. */
#define SLPCTRL_LDOLVL_1_bm  (1<<1)  /* LDO Level bit 1 mask. */
#define SLPCTRL_LDOLVL_1_bp  1  /* LDO Level bit 1 position. */
#define SLPCTRL_LDOLVL_2_bm  (1<<2)  /* LDO Level bit 2 mask. */
#define SLPCTRL_LDOLVL_2_bp  2  /* LDO Level bit 2 position. */
#define SLPCTRL_VCOREEN_bm  0x08  /* Core Voltage Output Enable bit mask. */
#define SLPCTRL_VCOREEN_bp  3  /* Core Voltage Output Enable bit position. */
#define SLPCTRL_EOSLVL_gm  0x70  /* EOS Level group mask. */
#define SLPCTRL_EOSLVL_gp  4  /* EOS Level group position. */
#define SLPCTRL_EOSLVL_0_bm  (1<<4)  /* EOS Level bit 0 mask. */
#define SLPCTRL_EOSLVL_0_bp  4  /* EOS Level bit 0 position. */
#define SLPCTRL_EOSLVL_1_bm  (1<<5)  /* EOS Level bit 1 mask. */
#define SLPCTRL_EOSLVL_1_bp  5  /* EOS Level bit 1 position. */
#define SLPCTRL_EOSLVL_2_bm  (1<<6)  /* EOS Level bit 2 mask. */
#define SLPCTRL_EOSLVL_2_bp  6  /* EOS Level bit 2 position. */
#define SLPCTRL_EOSEN_bm  0x80  /* EOS Enable bit mask. */
#define SLPCTRL_EOSEN_bp  7  /* EOS Enable bit position. */

/* SLPCTRL.CALULP  bit masks and bit positions */
#define SLPCTRL_ULP1V8LVL_gm  0x07  /* VREG ULP 1.8V Level group mask. */
#define SLPCTRL_ULP1V8LVL_gp  0  /* VREG ULP 1.8V Level group position. */
#define SLPCTRL_ULP1V8LVL_0_bm  (1<<0)  /* VREG ULP 1.8V Level bit 0 mask. */
#define SLPCTRL_ULP1V8LVL_0_bp  0  /* VREG ULP 1.8V Level bit 0 position. */
#define SLPCTRL_ULP1V8LVL_1_bm  (1<<1)  /* VREG ULP 1.8V Level bit 1 mask. */
#define SLPCTRL_ULP1V8LVL_1_bp  1  /* VREG ULP 1.8V Level bit 1 position. */
#define SLPCTRL_ULP1V8LVL_2_bm  (1<<2)  /* VREG ULP 1.8V Level bit 2 mask. */
#define SLPCTRL_ULP1V8LVL_2_bp  2  /* VREG ULP 1.8V Level bit 2 position. */
#define SLPCTRL_ULP1V8RNG_bm  0x08  /* VREG ULP 1.8V Range bit mask. */
#define SLPCTRL_ULP1V8RNG_bp  3  /* VREG ULP 1.8V Range bit position. */
#define SLPCTRL_ULP1V5LVL_gm  0x70  /* VREG ULP 1.5V Level group mask. */
#define SLPCTRL_ULP1V5LVL_gp  4  /* VREG ULP 1.5V Level group position. */
#define SLPCTRL_ULP1V5LVL_0_bm  (1<<4)  /* VREG ULP 1.5V Level bit 0 mask. */
#define SLPCTRL_ULP1V5LVL_0_bp  4  /* VREG ULP 1.5V Level bit 0 position. */
#define SLPCTRL_ULP1V5LVL_1_bm  (1<<5)  /* VREG ULP 1.5V Level bit 1 mask. */
#define SLPCTRL_ULP1V5LVL_1_bp  5  /* VREG ULP 1.5V Level bit 1 position. */
#define SLPCTRL_ULP1V5LVL_2_bm  (1<<6)  /* VREG ULP 1.5V Level bit 2 mask. */
#define SLPCTRL_ULP1V5LVL_2_bp  6  /* VREG ULP 1.5V Level bit 2 position. */
#define SLPCTRL_ULP1V5RNG_bm  0x80  /* VREG ULP 1.5V Range bit mask. */
#define SLPCTRL_ULP1V5RNG_bp  7  /* VREG ULP 1.5V Range bit position. */

/* SLPCTRL.CALBB  bit masks and bit positions */
#define SLPCTRL_ULP0V3LVL_gm  0x07  /* VREG ULP 0.3V Level group mask. */
#define SLPCTRL_ULP0V3LVL_gp  0  /* VREG ULP 0.3V Level group position. */
#define SLPCTRL_ULP0V3LVL_0_bm  (1<<0)  /* VREG ULP 0.3V Level bit 0 mask. */
#define SLPCTRL_ULP0V3LVL_0_bp  0  /* VREG ULP 0.3V Level bit 0 position. */
#define SLPCTRL_ULP0V3LVL_1_bm  (1<<1)  /* VREG ULP 0.3V Level bit 1 mask. */
#define SLPCTRL_ULP0V3LVL_1_bp  1  /* VREG ULP 0.3V Level bit 1 position. */
#define SLPCTRL_ULP0V3LVL_2_bm  (1<<2)  /* VREG ULP 0.3V Level bit 2 mask. */
#define SLPCTRL_ULP0V3LVL_2_bp  2  /* VREG ULP 0.3V Level bit 2 position. */
#define SLPCTRL_ULP0V3EN_bm  0x10  /* VREG ULP 0.3V Enable bit mask. */
#define SLPCTRL_ULP0V3EN_bp  4  /* VREG ULP 0.3V Enable bit position. */

/* SLPCTRL.TESTLDOA  bit masks and bit positions */
#define SLPCTRL_TESTEN_bm  0x01  /* VREG Test Enable bit mask. */
#define SLPCTRL_TESTEN_bp  0  /* VREG Test Enable bit position. */
#define SLPCTRL_LOADEN_bm  0x02  /* VREG Load Enable bit mask. */
#define SLPCTRL_LOADEN_bp  1  /* VREG Load Enable bit position. */
#define SLPCTRL_TRACKEN_bm  0x04  /* Tracking Mode Enable bit mask. */
#define SLPCTRL_TRACKEN_bp  2  /* Tracking Mode Enable bit position. */
#define SLPCTRL_TRACKDIS_bm  0x08  /* Tracking Detector Disable bit mask. */
#define SLPCTRL_TRACKDIS_bp  3  /* Tracking Detector Disable bit position. */
#define SLPCTRL_LPMODE_gm  0x30  /* LDO Low-power mode Enable group mask. */
#define SLPCTRL_LPMODE_gp  4  /* LDO Low-power mode Enable group position. */
#define SLPCTRL_LPMODE_0_bm  (1<<4)  /* LDO Low-power mode Enable bit 0 mask. */
#define SLPCTRL_LPMODE_0_bp  4  /* LDO Low-power mode Enable bit 0 position. */
#define SLPCTRL_LPMODE_1_bm  (1<<5)  /* LDO Low-power mode Enable bit 1 mask. */
#define SLPCTRL_LPMODE_1_bp  5  /* LDO Low-power mode Enable bit 1 position. */
#define SLPCTRL_HPMODE_gm  0xC0  /* LDO High-power mode group mask. */
#define SLPCTRL_HPMODE_gp  6  /* LDO High-power mode group position. */
#define SLPCTRL_HPMODE_0_bm  (1<<6)  /* LDO High-power mode bit 0 mask. */
#define SLPCTRL_HPMODE_0_bp  6  /* LDO High-power mode bit 0 position. */
#define SLPCTRL_HPMODE_1_bm  (1<<7)  /* LDO High-power mode bit 1 mask. */
#define SLPCTRL_HPMODE_1_bp  7  /* LDO High-power mode bit 1 position. */

/* SLPCTRL.TESTLDOB  bit masks and bit positions */
#define SLPCTRL_LOAD_gm  0x07  /* LDO Load Value group mask. */
#define SLPCTRL_LOAD_gp  0  /* LDO Load Value group position. */
#define SLPCTRL_LOAD_0_bm  (1<<0)  /* LDO Load Value bit 0 mask. */
#define SLPCTRL_LOAD_0_bp  0  /* LDO Load Value bit 0 position. */
#define SLPCTRL_LOAD_1_bm  (1<<1)  /* LDO Load Value bit 1 mask. */
#define SLPCTRL_LOAD_1_bp  1  /* LDO Load Value bit 1 position. */
#define SLPCTRL_LOAD_2_bm  (1<<2)  /* LDO Load Value bit 2 mask. */
#define SLPCTRL_LOAD_2_bp  2  /* LDO Load Value bit 2 position. */

/* SLPCTRL.TESTULP  bit masks and bit positions */
#define SLPCTRL_ULP0V3DIS_bm  0x01  /* Disable 0.3V Regulator bit mask. */
#define SLPCTRL_ULP0V3DIS_bp  0  /* Disable 0.3V Regulator bit position. */
#define SLPCTRL_ULP1V5DIS_bm  0x02  /* Disable 1.5V Regulator bit mask. */
#define SLPCTRL_ULP1V5DIS_bp  1  /* Disable 1.5V Regulator bit position. */
#define SLPCTRL_ULP1V8DIS_bm  0x04  /* Disable 1.8V Regulator bit mask. */
#define SLPCTRL_ULP1V8DIS_bp  2  /* Disable 1.8V Regulator bit position. */
#define SLPCTRL_ULPTRANS_bm  0x08  /* Trancient Enhancer bit mask. */
#define SLPCTRL_ULPTRANS_bp  3  /* Trancient Enhancer bit position. */
#define SLPCTRL_SWTEN_bm  0x20  /* Regulator Switch Override Enable bit mask. */
#define SLPCTRL_SWTEN_bp  5  /* Regulator Switch Override Enable bit position. */
#define SLPCTRL_SW1EN_bm  0x40  /* Regulator Switch 1 bit mask. */
#define SLPCTRL_SW1EN_bp  6  /* Regulator Switch 1 bit position. */
#define SLPCTRL_SW3EN_bm  0x80  /* Regulator Switch 3 bit mask. */
#define SLPCTRL_SW3EN_bp  7  /* Regulator Switch 3 bit position. */

/* SLPCTRL.TESTCMP  bit masks and bit positions */
#define SLPCTRL_FCMPSEL_bm  0x01  /* Fast Comparator Selection bit mask. */
#define SLPCTRL_FCMPSEL_bp  0  /* Fast Comparator Selection bit position. */
#define SLPCTRL_FCMPPOL_bm  0x02  /* Fast Comparator Polarity bit mask. */
#define SLPCTRL_FCMPPOL_bp  1  /* Fast Comparator Polarity bit position. */
#define SLPCTRL_FCMPLTRST_bm  0x04  /* Fast Comaprator Reset bit mask. */
#define SLPCTRL_FCMPLTRST_bp  2  /* Fast Comaprator Reset bit position. */
#define SLPCTRL_EOSCMPEN_bm  0x40  /* EOS Comparator Enable bit mask. */
#define SLPCTRL_EOSCMPEN_bp  6  /* EOS Comparator Enable bit position. */
#define SLPCTRL_EOSFBEN_bm  0x80  /* EOS Feedback Enble bit mask. */
#define SLPCTRL_EOSFBEN_bp  7  /* EOS Feedback Enble bit position. */

/* SLPCTRL.TESTSTATUS  bit masks and bit positions */
#define SLPCTRL_ULPBB_bm  0x01  /* ULP0V3 and ULP1V5 enabled bit mask. */
#define SLPCTRL_ULPBB_bp  0  /* ULP0V3 and ULP1V5 enabled bit position. */
#define SLPCTRL_ULP1V8_bm  0x02  /* ULP0V3 enabled bit mask. */
#define SLPCTRL_ULP1V8_bp  1  /* ULP0V3 enabled bit position. */
#define SLPCTRL_LDOLP_bm  0x04  /* LDO enabled in LP mode bit mask. */
#define SLPCTRL_LDOLP_bp  2  /* LDO enabled in LP mode bit position. */
#define SLPCTRL_LDOHP_bm  0x08  /* LDO enabled in HP mode bit mask. */
#define SLPCTRL_LDOHP_bp  3  /* LDO enabled in HP mode bit position. */
#define SLPCTRL_UPDATEEN_bm  0x80  /* Status updated enable bit mask. */
#define SLPCTRL_UPDATEEN_bp  7  /* Status updated enable bit position. */


/* SPI - Serial Peripheral Interface */
/* SPI.CTRLA  bit masks and bit positions */
#define SPI_ENABLE_bm  0x01  /* Enable Module bit mask. */
#define SPI_ENABLE_bp  0  /* Enable Module bit position. */
#define SPI_PRESC_gm  0x06  /* Prescaler group mask. */
#define SPI_PRESC_gp  1  /* Prescaler group position. */
#define SPI_PRESC_0_bm  (1<<1)  /* Prescaler bit 0 mask. */
#define SPI_PRESC_0_bp  1  /* Prescaler bit 0 position. */
#define SPI_PRESC_1_bm  (1<<2)  /* Prescaler bit 1 mask. */
#define SPI_PRESC_1_bp  2  /* Prescaler bit 1 position. */
#define SPI_CLK2X_bm  0x10  /* Enable Double Speed bit mask. */
#define SPI_CLK2X_bp  4  /* Enable Double Speed bit position. */
#define SPI_MASTER_bm  0x20  /* Master Operation Enable bit mask. */
#define SPI_MASTER_bp  5  /* Master Operation Enable bit position. */
#define SPI_DORD_bm  0x40  /* Data Order Setting bit mask. */
#define SPI_DORD_bp  6  /* Data Order Setting bit position. */

/* SPI.CTRLB  bit masks and bit positions */
#define SPI_MODE_gm  0x03  /* SPI Mode group mask. */
#define SPI_MODE_gp  0  /* SPI Mode group position. */
#define SPI_MODE_0_bm  (1<<0)  /* SPI Mode bit 0 mask. */
#define SPI_MODE_0_bp  0  /* SPI Mode bit 0 position. */
#define SPI_MODE_1_bm  (1<<1)  /* SPI Mode bit 1 mask. */
#define SPI_MODE_1_bp  1  /* SPI Mode bit 1 position. */
#define SPI_SSD_bm  0x04  /* Slave Select Disable bit mask. */
#define SPI_SSD_bp  2  /* Slave Select Disable bit position. */
#define SPI_BUFWR_bm  0x40  /* Buffer Mode Wait for Receive bit mask. */
#define SPI_BUFWR_bp  6  /* Buffer Mode Wait for Receive bit position. */
#define SPI_BUFEN_bm  0x80  /* Buffer Mode Enable bit mask. */
#define SPI_BUFEN_bp  7  /* Buffer Mode Enable bit position. */

/* SPI.INTCTRL  bit masks and bit positions */
#define SPI_IE_bm  0x01  /* Interrupt Enable bit mask. */
#define SPI_IE_bp  0  /* Interrupt Enable bit position. */
#define SPI_SSIE_bm  0x10  /* Slave Select Trigger Interrupt Enable bit mask. */
#define SPI_SSIE_bp  4  /* Slave Select Trigger Interrupt Enable bit position. */
#define SPI_DREIE_bm  0x20  /* Data Register Empty Interrupt Enable bit mask. */
#define SPI_DREIE_bp  5  /* Data Register Empty Interrupt Enable bit position. */
#define SPI_TXCIE_bm  0x40  /* Transfer Complete Interrupt Enable bit mask. */
#define SPI_TXCIE_bp  6  /* Transfer Complete Interrupt Enable bit position. */
#define SPI_RXCIE_bm  0x80  /* Receive Complete Interrupt Enable bit mask. */
#define SPI_RXCIE_bp  7  /* Receive Complete Interrupt Enable bit position. */

/* SPI.INTFLAGS  bit masks and bit positions */
#define SPI_BUFOVF_bm  0x01  /* Buffer Overflow bit mask. */
#define SPI_BUFOVF_bp  0  /* Buffer Overflow bit position. */
#define SPI_SSIF_bm  0x10  /* Slave Select Trigger Interrupt Flag bit mask. */
#define SPI_SSIF_bp  4  /* Slave Select Trigger Interrupt Flag bit position. */
#define SPI_DREIF_bm  0x20  /* Data Register Empty Interrupt Flag bit mask. */
#define SPI_DREIF_bp  5  /* Data Register Empty Interrupt Flag bit position. */
#define SPI_TXCIF_bm  0x40  /* Transfer Complete Interrupt Flag bit mask. */
#define SPI_TXCIF_bp  6  /* Transfer Complete Interrupt Flag bit position. */
#define SPI_WRCOL_bm  0x40  /* Write Collision bit mask. */
#define SPI_WRCOL_bp  6  /* Write Collision bit position. */
#define SPI_RXCIF_bm  0x80  /* Receive Complete Interrupt Flag bit mask. */
#define SPI_RXCIF_bp  7  /* Receive Complete Interrupt Flag bit position. */
#define SPI_IF_bm  0x80  /* Interrupt Flag bit mask. */
#define SPI_IF_bp  7  /* Interrupt Flag bit position. */


/* SYSCFG - System Configuration Registers */
/* SYSCFG.ASI  bit masks and bit positions */
#define SYSCFG_TESTUNLOCK_bm  0x10  /* Test unlock bit mask. */
#define SYSCFG_TESTUNLOCK_bp  4  /* Test unlock bit position. */
#define SYSCFG_ERASEFAIL_bm  0x20  /* Erase failed bit mask. */
#define SYSCFG_ERASEFAIL_bp  5  /* Erase failed bit position. */
#define SYSCFG_USERROW_bm  0x40  /* User Row bit mask. */
#define SYSCFG_USERROW_bp  6  /* User Row bit position. */
#define SYSCFG_PROGEN_bm  0x80  /* Programmig Enabled bit mask. */
#define SYSCFG_PROGEN_bp  7  /* Programmig Enabled bit position. */

/* SYSCFG.EXTBRK  bit masks and bit positions */
#define SYSCFG_ENEXTBRK_bm  0x01  /* External break enable bit mask. */
#define SYSCFG_ENEXTBRK_bp  0  /* External break enable bit position. */

/* SYSCFG.FRESH  bit masks and bit positions */
#define SYSCFG_FRESH_gm  0xFF  /* Fersh from fab group mask. */
#define SYSCFG_FRESH_gp  0  /* Fersh from fab group position. */
#define SYSCFG_FRESH_0_bm  (1<<0)  /* Fersh from fab bit 0 mask. */
#define SYSCFG_FRESH_0_bp  0  /* Fersh from fab bit 0 position. */
#define SYSCFG_FRESH_1_bm  (1<<1)  /* Fersh from fab bit 1 mask. */
#define SYSCFG_FRESH_1_bp  1  /* Fersh from fab bit 1 position. */
#define SYSCFG_FRESH_2_bm  (1<<2)  /* Fersh from fab bit 2 mask. */
#define SYSCFG_FRESH_2_bp  2  /* Fersh from fab bit 2 position. */
#define SYSCFG_FRESH_3_bm  (1<<3)  /* Fersh from fab bit 3 mask. */
#define SYSCFG_FRESH_3_bp  3  /* Fersh from fab bit 3 position. */
#define SYSCFG_FRESH_4_bm  (1<<4)  /* Fersh from fab bit 4 mask. */
#define SYSCFG_FRESH_4_bp  4  /* Fersh from fab bit 4 position. */
#define SYSCFG_FRESH_5_bm  (1<<5)  /* Fersh from fab bit 5 mask. */
#define SYSCFG_FRESH_5_bp  5  /* Fersh from fab bit 5 position. */
#define SYSCFG_FRESH_6_bm  (1<<6)  /* Fersh from fab bit 6 mask. */
#define SYSCFG_FRESH_6_bp  6  /* Fersh from fab bit 6 position. */
#define SYSCFG_FRESH_7_bm  (1<<7)  /* Fersh from fab bit 7 mask. */
#define SYSCFG_FRESH_7_bp  7  /* Fersh from fab bit 7 position. */

/* SYSCFG.SYSCFG0  bit masks and bit positions */
#define SYSCFG_EESAVE_bm  0x01  /* EEPROM Save bit mask. */
#define SYSCFG_EESAVE_bp  0  /* EEPROM Save bit position. */
#define SYSCFG_RSTPINCFG_gm  0x0C  /* Reset Pin configuration group mask. */
#define SYSCFG_RSTPINCFG_gp  2  /* Reset Pin configuration group position. */
#define SYSCFG_RSTPINCFG_0_bm  (1<<2)  /* Reset Pin configuration bit 0 mask. */
#define SYSCFG_RSTPINCFG_0_bp  2  /* Reset Pin configuration bit 0 position. */
#define SYSCFG_RSTPINCFG_1_bm  (1<<3)  /* Reset Pin configuration bit 1 mask. */
#define SYSCFG_RSTPINCFG_1_bp  3  /* Reset Pin configuration bit 1 position. */
#define SYSCFG_CRC32_bm  0x20  /* CRC32 enable bit mask. */
#define SYSCFG_CRC32_bp  5  /* CRC32 enable bit position. */
#define SYSCFG_CRCCFG_gm  0xC0  /* CRC Configuration group mask. */
#define SYSCFG_CRCCFG_gp  6  /* CRC Configuration group position. */
#define SYSCFG_CRCCFG_0_bm  (1<<6)  /* CRC Configuration bit 0 mask. */
#define SYSCFG_CRCCFG_0_bp  6  /* CRC Configuration bit 0 position. */
#define SYSCFG_CRCCFG_1_bm  (1<<7)  /* CRC Configuration bit 1 mask. */
#define SYSCFG_CRCCFG_1_bp  7  /* CRC Configuration bit 1 position. */

/* SYSCFG.HVDSTATUS  bit masks and bit positions */
#define SYSCFG_ASIKEYVALID_bm  0x01  /* ASI key valid bit mask. */
#define SYSCFG_ASIKEYVALID_bp  0  /* ASI key valid bit position. */
#define SYSCFG_PORFLAG_bm  0x02  /* POR flag bit mask. */
#define SYSCFG_PORFLAG_bp  1  /* POR flag bit position. */
#define SYSCFG_PDIPADSYNC_bm  0x08  /* PDI pad sync bit mask. */
#define SYSCFG_PDIPADSYNC_bp  3  /* PDI pad sync bit position. */
#define SYSCFG_PDIHVENABLE_bm  0x10  /* PDI HV enable bit mask. */
#define SYSCFG_PDIHVENABLE_bp  4  /* PDI HV enable bit position. */

/* SYSCFG.HVDCTRL  bit masks and bit positions */
/* SYSCFG_PORFLAG  is already defined. */

/* SYSCFG.TESTCTRLA  bit masks and bit positions */
#define SYSCFG_TDEN_gm  0x03  /* Temperature diode enable group mask. */
#define SYSCFG_TDEN_gp  0  /* Temperature diode enable group position. */
#define SYSCFG_TDEN_0_bm  (1<<0)  /* Temperature diode enable bit 0 mask. */
#define SYSCFG_TDEN_0_bp  0  /* Temperature diode enable bit 0 position. */
#define SYSCFG_TDEN_1_bm  (1<<1)  /* Temperature diode enable bit 1 mask. */
#define SYSCFG_TDEN_1_bp  1  /* Temperature diode enable bit 1 position. */
#define SYSCFG_TDSRC_bm  0x04  /* Temperature diode output source bit mask. */
#define SYSCFG_TDSRC_bp  2  /* Temperature diode output source bit position. */
#define SYSCFG_TDOUT_bm  0x08  /* Temperature diode output selection bit mask. */
#define SYSCFG_TDOUT_bp  3  /* Temperature diode output selection bit position. */

/* SYSCFG.TESTCTRLB  bit masks and bit positions */
#define SYSCFG_EXECMODE_gm  0x07  /* Code execution mode group mask. */
#define SYSCFG_EXECMODE_gp  0  /* Code execution mode group position. */
#define SYSCFG_EXECMODE_0_bm  (1<<0)  /* Code execution mode bit 0 mask. */
#define SYSCFG_EXECMODE_0_bp  0  /* Code execution mode bit 0 position. */
#define SYSCFG_EXECMODE_1_bm  (1<<1)  /* Code execution mode bit 1 mask. */
#define SYSCFG_EXECMODE_1_bp  1  /* Code execution mode bit 1 position. */
#define SYSCFG_EXECMODE_2_bm  (1<<2)  /* Code execution mode bit 2 mask. */
#define SYSCFG_EXECMODE_2_bp  2  /* Code execution mode bit 2 position. */
#define SYSCFG_EEXDATA_bm  0x10  /* External execution data bit mask. */
#define SYSCFG_EEXDATA_bp  4  /* External execution data bit position. */
#define SYSCFG_HVDIS_bm  0x80  /* High voltage detection disable bit mask. */
#define SYSCFG_HVDIS_bp  7  /* High voltage detection disable bit position. */

/* SYSCFG.TESTCTRLC  bit masks and bit positions */
#define SYSCFG_RAMERST_bm  0x01  /* RAM erase start bit mask. */
#define SYSCFG_RAMERST_bp  0  /* RAM erase start bit position. */
#define SYSCFG_RAMERDONE_bm  0x02  /* RAM erase done bit mask. */
#define SYSCFG_RAMERDONE_bp  1  /* RAM erase done bit position. */

/* SYSCFG.MEMSIZE0  bit masks and bit positions */
#define SYSCFG_FLASHSIZE_gm  0x03  /* Flash size configuration group mask. */
#define SYSCFG_FLASHSIZE_gp  0  /* Flash size configuration group position. */
#define SYSCFG_FLASHSIZE_0_bm  (1<<0)  /* Flash size configuration bit 0 mask. */
#define SYSCFG_FLASHSIZE_0_bp  0  /* Flash size configuration bit 0 position. */
#define SYSCFG_FLASHSIZE_1_bm  (1<<1)  /* Flash size configuration bit 1 mask. */
#define SYSCFG_FLASHSIZE_1_bp  1  /* Flash size configuration bit 1 position. */
#define SYSCFG_EESIZE_gm  0x0C  /* EEPROM size configuration group mask. */
#define SYSCFG_EESIZE_gp  2  /* EEPROM size configuration group position. */
#define SYSCFG_EESIZE_0_bm  (1<<2)  /* EEPROM size configuration bit 0 mask. */
#define SYSCFG_EESIZE_0_bp  2  /* EEPROM size configuration bit 0 position. */
#define SYSCFG_EESIZE_1_bm  (1<<3)  /* EEPROM size configuration bit 1 mask. */
#define SYSCFG_EESIZE_1_bp  3  /* EEPROM size configuration bit 1 position. */
#define SYSCFG_RAMSIZE_gm  0x30  /* RAM size configuration group mask. */
#define SYSCFG_RAMSIZE_gp  4  /* RAM size configuration group position. */
#define SYSCFG_RAMSIZE_0_bm  (1<<4)  /* RAM size configuration bit 0 mask. */
#define SYSCFG_RAMSIZE_0_bp  4  /* RAM size configuration bit 0 position. */
#define SYSCFG_RAMSIZE_1_bm  (1<<5)  /* RAM size configuration bit 1 mask. */
#define SYSCFG_RAMSIZE_1_bp  5  /* RAM size configuration bit 1 position. */
#define SYSCFG_CPUISRQADDR_bm  0x80  /* CPU single interrupt address bit mask. */
#define SYSCFG_CPUISRQADDR_bp  7  /* CPU single interrupt address bit position. */

/* SYSCFG.MEMSIZE1  bit masks and bit positions */
#define SYSCFG_FLASHPAGESIZE_gm  0x03  /* Flash Page size config group mask. */
#define SYSCFG_FLASHPAGESIZE_gp  0  /* Flash Page size config group position. */
#define SYSCFG_FLASHPAGESIZE_0_bm  (1<<0)  /* Flash Page size config bit 0 mask. */
#define SYSCFG_FLASHPAGESIZE_0_bp  0  /* Flash Page size config bit 0 position. */
#define SYSCFG_FLASHPAGESIZE_1_bm  (1<<1)  /* Flash Page size config bit 1 mask. */
#define SYSCFG_FLASHPAGESIZE_1_bp  1  /* Flash Page size config bit 1 position. */
#define SYSCFG_EEPAGESIZE_gm  0x0C  /* EEPROM Page size config group mask. */
#define SYSCFG_EEPAGESIZE_gp  2  /* EEPROM Page size config group position. */
#define SYSCFG_EEPAGESIZE_0_bm  (1<<2)  /* EEPROM Page size config bit 0 mask. */
#define SYSCFG_EEPAGESIZE_0_bp  2  /* EEPROM Page size config bit 0 position. */
#define SYSCFG_EEPAGESIZE_1_bm  (1<<3)  /* EEPROM Page size config bit 1 mask. */
#define SYSCFG_EEPAGESIZE_1_bp  3  /* EEPROM Page size config bit 1 position. */

/* SYSCFG.PINCNT  bit masks and bit positions */
#define SYSCFG_PACKAGE_gm  0x0F  /* Package config group mask. */
#define SYSCFG_PACKAGE_gp  0  /* Package config group position. */
#define SYSCFG_PACKAGE_0_bm  (1<<0)  /* Package config bit 0 mask. */
#define SYSCFG_PACKAGE_0_bp  0  /* Package config bit 0 position. */
#define SYSCFG_PACKAGE_1_bm  (1<<1)  /* Package config bit 1 mask. */
#define SYSCFG_PACKAGE_1_bp  1  /* Package config bit 1 position. */
#define SYSCFG_PACKAGE_2_bm  (1<<2)  /* Package config bit 2 mask. */
#define SYSCFG_PACKAGE_2_bp  2  /* Package config bit 2 position. */
#define SYSCFG_PACKAGE_3_bm  (1<<3)  /* Package config bit 3 mask. */
#define SYSCFG_PACKAGE_3_bp  3  /* Package config bit 3 position. */

/* SYSCFG.CONFIG0  bit masks and bit positions */
#define SYSCFG_CPUCACHEN_bm  0x01  /* CPU Cache Enable bit mask. */
#define SYSCFG_CPUCACHEN_bp  0  /* CPU Cache Enable bit position. */
#define SYSCFG_SYSBOOTCRCEN_bm  0x02  /* CRC in boot enable bit mask. */
#define SYSCFG_SYSBOOTCRCEN_bp  1  /* CRC in boot enable bit position. */

/* SYSCFG.CONFIG1  bit masks and bit positions */
#define SYSCFG_PTCEN_bm  0x01  /* PTC enable fuse bit mask. */
#define SYSCFG_PTCEN_bp  0  /* PTC enable fuse bit position. */

/* SYSCFG.OCDMSTATUS  bit masks and bit positions */
#define SYSCFG_OCDMR_bm  0x01  /* OCD Message Read bit mask. */
#define SYSCFG_OCDMR_bp  0  /* OCD Message Read bit position. */


/* TCB - 16-bit Timer/Counter Type B */
/* TCB.CTRLA  bit masks and bit positions */
#define TCB_ENABLE_bm  0x01  /* Enable bit mask. */
#define TCB_ENABLE_bp  0  /* Enable bit position. */
#define TCB_CLKSEL_gm  0x0E  /* Clock Select group mask. */
#define TCB_CLKSEL_gp  1  /* Clock Select group position. */
#define TCB_CLKSEL_0_bm  (1<<1)  /* Clock Select bit 0 mask. */
#define TCB_CLKSEL_0_bp  1  /* Clock Select bit 0 position. */
#define TCB_CLKSEL_1_bm  (1<<2)  /* Clock Select bit 1 mask. */
#define TCB_CLKSEL_1_bp  2  /* Clock Select bit 1 position. */
#define TCB_CLKSEL_2_bm  (1<<3)  /* Clock Select bit 2 mask. */
#define TCB_CLKSEL_2_bp  3  /* Clock Select bit 2 position. */
#define TCB_SYNCUPD_bm  0x10  /* Synchronize Update bit mask. */
#define TCB_SYNCUPD_bp  4  /* Synchronize Update bit position. */
#define TCB_CASCADE_bm  0x20  /* Cascade two timers bit mask. */
#define TCB_CASCADE_bp  5  /* Cascade two timers bit position. */
#define TCB_RUNSTDBY_bm  0x40  /* Run Standby bit mask. */
#define TCB_RUNSTDBY_bp  6  /* Run Standby bit position. */

/* TCB.CTRLB  bit masks and bit positions */
#define TCB_CNTMODE_gm  0x07  /* Timer Mode group mask. */
#define TCB_CNTMODE_gp  0  /* Timer Mode group position. */
#define TCB_CNTMODE_0_bm  (1<<0)  /* Timer Mode bit 0 mask. */
#define TCB_CNTMODE_0_bp  0  /* Timer Mode bit 0 position. */
#define TCB_CNTMODE_1_bm  (1<<1)  /* Timer Mode bit 1 mask. */
#define TCB_CNTMODE_1_bp  1  /* Timer Mode bit 1 position. */
#define TCB_CNTMODE_2_bm  (1<<2)  /* Timer Mode bit 2 mask. */
#define TCB_CNTMODE_2_bp  2  /* Timer Mode bit 2 position. */
#define TCB_CCMPEN_bm  0x10  /* Pin Output Enable bit mask. */
#define TCB_CCMPEN_bp  4  /* Pin Output Enable bit position. */
#define TCB_CCMPINIT_bm  0x20  /* Pin Initial State bit mask. */
#define TCB_CCMPINIT_bp  5  /* Pin Initial State bit position. */
#define TCB_ASYNC_bm  0x40  /* Asynchronous Enable bit mask. */
#define TCB_ASYNC_bp  6  /* Asynchronous Enable bit position. */
#define TCB_EVGEN_bm  0x80  /* Event Generation bit mask. */
#define TCB_EVGEN_bp  7  /* Event Generation bit position. */

/* TCB.CTRLC  bit masks and bit positions */
#define TCB_CNTSIZE_gm  0x07  /* Counter Size group mask. */
#define TCB_CNTSIZE_gp  0  /* Counter Size group position. */
#define TCB_CNTSIZE_0_bm  (1<<0)  /* Counter Size bit 0 mask. */
#define TCB_CNTSIZE_0_bp  0  /* Counter Size bit 0 position. */
#define TCB_CNTSIZE_1_bm  (1<<1)  /* Counter Size bit 1 mask. */
#define TCB_CNTSIZE_1_bp  1  /* Counter Size bit 1 position. */
#define TCB_CNTSIZE_2_bm  (1<<2)  /* Counter Size bit 2 mask. */
#define TCB_CNTSIZE_2_bp  2  /* Counter Size bit 2 position. */

/* TCB.EVCTRL  bit masks and bit positions */
#define TCB_CAPTEI_bm  0x01  /* Event Input Enable bit mask. */
#define TCB_CAPTEI_bp  0  /* Event Input Enable bit position. */
#define TCB_EDGE_bm  0x10  /* Event Edge bit mask. */
#define TCB_EDGE_bp  4  /* Event Edge bit position. */
#define TCB_FILTER_bm  0x40  /* Input Capture Noise Cancellation Filter bit mask. */
#define TCB_FILTER_bp  6  /* Input Capture Noise Cancellation Filter bit position. */

/* TCB.INTCTRL  bit masks and bit positions */
#define TCB_CAPT_bm  0x01  /* Capture or Timeout bit mask. */
#define TCB_CAPT_bp  0  /* Capture or Timeout bit position. */
#define TCB_OVF_bm  0x02  /* Overflow bit mask. */
#define TCB_OVF_bp  1  /* Overflow bit position. */

/* TCB.INTFLAGS  bit masks and bit positions */
/* TCB_CAPT  is already defined. */
/* TCB_OVF  is already defined. */

/* TCB.STATUS  bit masks and bit positions */
#define TCB_RUN_bm  0x01  /* Run bit mask. */
#define TCB_RUN_bp  0  /* Run bit position. */

/* TCB.DBGCTRL  bit masks and bit positions */
#define TCB_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCB_DBGRUN_bp  0  /* Debug Run bit position. */


/* TCE - 16-bit Timer/Counter Type E */
/* TCE.CTRLA  bit masks and bit positions */
#define TCE_ENABLE_bm  0x01  /* Module Enable bit mask. */
#define TCE_ENABLE_bp  0  /* Module Enable bit position. */
#define TCE_CLKSEL_gm  0x0E  /* Clock Selection group mask. */
#define TCE_CLKSEL_gp  1  /* Clock Selection group position. */
#define TCE_CLKSEL_0_bm  (1<<1)  /* Clock Selection bit 0 mask. */
#define TCE_CLKSEL_0_bp  1  /* Clock Selection bit 0 position. */
#define TCE_CLKSEL_1_bm  (1<<2)  /* Clock Selection bit 1 mask. */
#define TCE_CLKSEL_1_bp  2  /* Clock Selection bit 1 position. */
#define TCE_CLKSEL_2_bm  (1<<3)  /* Clock Selection bit 2 mask. */
#define TCE_CLKSEL_2_bp  3  /* Clock Selection bit 2 position. */
#define TCE_RUNSTDBY_bm  0x80  /* Run in Standby bit mask. */
#define TCE_RUNSTDBY_bp  7  /* Run in Standby bit position. */

/* TCE.CTRLB  bit masks and bit positions */
#define TCE_WGMODE_gm  0x07  /* Waveform generation mode group mask. */
#define TCE_WGMODE_gp  0  /* Waveform generation mode group position. */
#define TCE_WGMODE_0_bm  (1<<0)  /* Waveform generation mode bit 0 mask. */
#define TCE_WGMODE_0_bp  0  /* Waveform generation mode bit 0 position. */
#define TCE_WGMODE_1_bm  (1<<1)  /* Waveform generation mode bit 1 mask. */
#define TCE_WGMODE_1_bp  1  /* Waveform generation mode bit 1 position. */
#define TCE_WGMODE_2_bm  (1<<2)  /* Waveform generation mode bit 2 mask. */
#define TCE_WGMODE_2_bp  2  /* Waveform generation mode bit 2 position. */
#define TCE_ALUPD_bm  0x08  /* Auto Lock Update bit mask. */
#define TCE_ALUPD_bp  3  /* Auto Lock Update bit position. */
#define TCE_CMP0EN_bm  0x10  /* Compare 0 Enable bit mask. */
#define TCE_CMP0EN_bp  4  /* Compare 0 Enable bit position. */
#define TCE_CMP1EN_bm  0x20  /* Compare 1 Enable bit mask. */
#define TCE_CMP1EN_bp  5  /* Compare 1 Enable bit position. */
#define TCE_CMP2EN_bm  0x40  /* Compare 2 Enable bit mask. */
#define TCE_CMP2EN_bp  6  /* Compare 2 Enable bit position. */
#define TCE_CMP3EN_bm  0x80  /* Compare 3 Enable bit mask. */
#define TCE_CMP3EN_bp  7  /* Compare 3 Enable bit position. */

/* TCE.CTRLC  bit masks and bit positions */
#define TCE_CMP0OV_bm  0x01  /* Compare 0 Waveform Output Value bit mask. */
#define TCE_CMP0OV_bp  0  /* Compare 0 Waveform Output Value bit position. */
#define TCE_CMP1OV_bm  0x02  /* Compare 1 Waveform Output Value bit mask. */
#define TCE_CMP1OV_bp  1  /* Compare 1 Waveform Output Value bit position. */
#define TCE_CMP2OV_bm  0x04  /* Compare 2 Waveform Output Value bit mask. */
#define TCE_CMP2OV_bp  2  /* Compare 2 Waveform Output Value bit position. */
#define TCE_CMP3OV_bm  0x08  /* Compare 3 Waveform Output Value bit mask. */
#define TCE_CMP3OV_bp  3  /* Compare 3 Waveform Output Value bit position. */
#define TCE_CMP0POL_bm  0x10  /* Compare 0 Polarity bit mask. */
#define TCE_CMP0POL_bp  4  /* Compare 0 Polarity bit position. */
#define TCE_CMP1POL_bm  0x20  /* Compare 1 Polarity bit mask. */
#define TCE_CMP1POL_bp  5  /* Compare 1 Polarity bit position. */
#define TCE_CMP2POL_bm  0x40  /* Compare 2 Polarity bit mask. */
#define TCE_CMP2POL_bp  6  /* Compare 2 Polarity bit position. */
#define TCE_CMP3POL_bm  0x80  /* Compare 3 Polarity bit mask. */
#define TCE_CMP3POL_bp  7  /* Compare 3 Polarity bit position. */

/* TCE.CTRLD  bit masks and bit positions */
#define TCE_SCALE_bm  0x04  /* Scaled Write bit mask. */
#define TCE_SCALE_bp  2  /* Scaled Write bit position. */
#define TCE_AMPEN_bm  0x08  /* Amplitude Control Enable bit mask. */
#define TCE_AMPEN_bp  3  /* Amplitude Control Enable bit position. */
#define TCE_SCALEMODE_gm  0x30  /* Scaling Mode group mask. */
#define TCE_SCALEMODE_gp  4  /* Scaling Mode group position. */
#define TCE_SCALEMODE_0_bm  (1<<4)  /* Scaling Mode bit 0 mask. */
#define TCE_SCALEMODE_0_bp  4  /* Scaling Mode bit 0 position. */
#define TCE_SCALEMODE_1_bm  (1<<5)  /* Scaling Mode bit 1 mask. */
#define TCE_SCALEMODE_1_bp  5  /* Scaling Mode bit 1 position. */
#define TCE_HREN_gm  0xC0  /* High Resolution Enable group mask. */
#define TCE_HREN_gp  6  /* High Resolution Enable group position. */
#define TCE_HREN_0_bm  (1<<6)  /* High Resolution Enable bit 0 mask. */
#define TCE_HREN_0_bp  6  /* High Resolution Enable bit 0 position. */
#define TCE_HREN_1_bm  (1<<7)  /* High Resolution Enable bit 1 mask. */
#define TCE_HREN_1_bp  7  /* High Resolution Enable bit 1 position. */

/* TCE.CTRLECLR  bit masks and bit positions */
#define TCE_DIR_bm  0x01  /* Direction bit mask. */
#define TCE_DIR_bp  0  /* Direction bit position. */
#define TCE_LUPD_bm  0x02  /* Lock Update bit mask. */
#define TCE_LUPD_bp  1  /* Lock Update bit position. */
#define TCE_CMD_gm  0x0C  /* Command group mask. */
#define TCE_CMD_gp  2  /* Command group position. */
#define TCE_CMD_0_bm  (1<<2)  /* Command bit 0 mask. */
#define TCE_CMD_0_bp  2  /* Command bit 0 position. */
#define TCE_CMD_1_bm  (1<<3)  /* Command bit 1 mask. */
#define TCE_CMD_1_bp  3  /* Command bit 1 position. */

/* TCE.CTRLESET  bit masks and bit positions */
/* TCE_DIR  is already defined. */
/* TCE_LUPD  is already defined. */
/* TCE_CMD  is already defined. */

/* TCE.CTRLFCLR  bit masks and bit positions */
#define TCE_PERBV_bm  0x01  /* Period Buffer Valid bit mask. */
#define TCE_PERBV_bp  0  /* Period Buffer Valid bit position. */
#define TCE_CMP0BV_bm  0x02  /* Compare 0 Buffer Valid bit mask. */
#define TCE_CMP0BV_bp  1  /* Compare 0 Buffer Valid bit position. */
#define TCE_CMP1BV_bm  0x04  /* Compare 1 Buffer Valid bit mask. */
#define TCE_CMP1BV_bp  2  /* Compare 1 Buffer Valid bit position. */
#define TCE_CMP2BV_bm  0x08  /* Compare 2 Buffer Valid bit mask. */
#define TCE_CMP2BV_bp  3  /* Compare 2 Buffer Valid bit position. */
#define TCE_CMP3BV_bm  0x10  /* Compare 3 Buffer Valid bit mask. */
#define TCE_CMP3BV_bp  4  /* Compare 3 Buffer Valid bit position. */

/* TCE.CTRLFSET  bit masks and bit positions */
/* TCE_PERBV  is already defined. */
/* TCE_CMP0BV  is already defined. */
/* TCE_CMP1BV  is already defined. */
/* TCE_CMP2BV  is already defined. */
/* TCE_CMP3BV  is already defined. */

/* TCE.EVGENCTRL  bit masks and bit positions */
#define TCE_CMP0EV_bm  0x10  /* Compare 0 Event bit mask. */
#define TCE_CMP0EV_bp  4  /* Compare 0 Event bit position. */
#define TCE_CMP1EV_bm  0x20  /* Compare 1 Event bit mask. */
#define TCE_CMP1EV_bp  5  /* Compare 1 Event bit position. */
#define TCE_CMP2EV_bm  0x40  /* Compare 2 Event bit mask. */
#define TCE_CMP2EV_bp  6  /* Compare 2 Event bit position. */
#define TCE_CMP3EV_bm  0x80  /* Compare 3 Event bit mask. */
#define TCE_CMP3EV_bp  7  /* Compare 3 Event bit position. */

/* TCE.EVCTRL  bit masks and bit positions */
#define TCE_CNTAEI_bm  0x01  /* Count on Event Input A bit mask. */
#define TCE_CNTAEI_bp  0  /* Count on Event Input A bit position. */
#define TCE_EVACTA_gm  0x0E  /* Event Action A group mask. */
#define TCE_EVACTA_gp  1  /* Event Action A group position. */
#define TCE_EVACTA_0_bm  (1<<1)  /* Event Action A bit 0 mask. */
#define TCE_EVACTA_0_bp  1  /* Event Action A bit 0 position. */
#define TCE_EVACTA_1_bm  (1<<2)  /* Event Action A bit 1 mask. */
#define TCE_EVACTA_1_bp  2  /* Event Action A bit 1 position. */
#define TCE_EVACTA_2_bm  (1<<3)  /* Event Action A bit 2 mask. */
#define TCE_EVACTA_2_bp  3  /* Event Action A bit 2 position. */
#define TCE_CNTBEI_bm  0x10  /* Count on Event Input B bit mask. */
#define TCE_CNTBEI_bp  4  /* Count on Event Input B bit position. */
#define TCE_EVACTB_gm  0xE0  /* Event Action B group mask. */
#define TCE_EVACTB_gp  5  /* Event Action B group position. */
#define TCE_EVACTB_0_bm  (1<<5)  /* Event Action B bit 0 mask. */
#define TCE_EVACTB_0_bp  5  /* Event Action B bit 0 position. */
#define TCE_EVACTB_1_bm  (1<<6)  /* Event Action B bit 1 mask. */
#define TCE_EVACTB_1_bp  6  /* Event Action B bit 1 position. */
#define TCE_EVACTB_2_bm  (1<<7)  /* Event Action B bit 2 mask. */
#define TCE_EVACTB_2_bp  7  /* Event Action B bit 2 position. */

/* TCE.INTCTRL  bit masks and bit positions */
#define TCE_OVF_bm  0x01  /* Overflow Interrupt Enable bit mask. */
#define TCE_OVF_bp  0  /* Overflow Interrupt Enable bit position. */
#define TCE_CMP0_bm  0x10  /* Compare 0 Interrupt Enable bit mask. */
#define TCE_CMP0_bp  4  /* Compare 0 Interrupt Enable bit position. */
#define TCE_CMP1_bm  0x20  /* Compare 1 Interrupt Enable bit mask. */
#define TCE_CMP1_bp  5  /* Compare 1 Interrupt Enable bit position. */
#define TCE_CMP2_bm  0x40  /* Compare 2 Interrupt Enable bit mask. */
#define TCE_CMP2_bp  6  /* Compare 2 Interrupt Enable bit position. */
#define TCE_CMP3_bm  0x80  /* Compare 3 Interrupt Enable bit mask. */
#define TCE_CMP3_bp  7  /* Compare 3 Interrupt Enable bit position. */

/* TCE.INTFLAGS  bit masks and bit positions */
/* TCE_OVF  is already defined. */
/* TCE_CMP0  is already defined. */
/* TCE_CMP1  is already defined. */
/* TCE_CMP2  is already defined. */
/* TCE_CMP3  is already defined. */

/* TCE.DBGCTRL  bit masks and bit positions */
#define TCE_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCE_DBGRUN_bp  0  /* Debug Run bit position. */


/* TCF - 24-bit Timer/Counter for frequency generation */
/* TCF.CTRLA  bit masks and bit positions */
#define TCF_ENABLE_bm  0x01  /* Enable bit mask. */
#define TCF_ENABLE_bp  0  /* Enable bit position. */
#define TCF_PRESC_gm  0x0E  /* Clock Prescaler group mask. */
#define TCF_PRESC_gp  1  /* Clock Prescaler group position. */
#define TCF_PRESC_0_bm  (1<<1)  /* Clock Prescaler bit 0 mask. */
#define TCF_PRESC_0_bp  1  /* Clock Prescaler bit 0 position. */
#define TCF_PRESC_1_bm  (1<<2)  /* Clock Prescaler bit 1 mask. */
#define TCF_PRESC_1_bp  2  /* Clock Prescaler bit 1 position. */
#define TCF_PRESC_2_bm  (1<<3)  /* Clock Prescaler bit 2 mask. */
#define TCF_PRESC_2_bp  3  /* Clock Prescaler bit 2 position. */
#define TCF_RUNSTDBY_bm  0x80  /* Run Standby bit mask. */
#define TCF_RUNSTDBY_bp  7  /* Run Standby bit position. */

/* TCF.CTRLB  bit masks and bit positions */
#define TCF_WGMODE_gm  0x07  /* Waveform Generation Mode group mask. */
#define TCF_WGMODE_gp  0  /* Waveform Generation Mode group position. */
#define TCF_WGMODE_0_bm  (1<<0)  /* Waveform Generation Mode bit 0 mask. */
#define TCF_WGMODE_0_bp  0  /* Waveform Generation Mode bit 0 position. */
#define TCF_WGMODE_1_bm  (1<<1)  /* Waveform Generation Mode bit 1 mask. */
#define TCF_WGMODE_1_bp  1  /* Waveform Generation Mode bit 1 position. */
#define TCF_WGMODE_2_bm  (1<<2)  /* Waveform Generation Mode bit 2 mask. */
#define TCF_WGMODE_2_bp  2  /* Waveform Generation Mode bit 2 position. */
#define TCF_CLKSEL_gm  0x38  /* Clock Select group mask. */
#define TCF_CLKSEL_gp  3  /* Clock Select group position. */
#define TCF_CLKSEL_0_bm  (1<<3)  /* Clock Select bit 0 mask. */
#define TCF_CLKSEL_0_bp  3  /* Clock Select bit 0 position. */
#define TCF_CLKSEL_1_bm  (1<<4)  /* Clock Select bit 1 mask. */
#define TCF_CLKSEL_1_bp  4  /* Clock Select bit 1 position. */
#define TCF_CLKSEL_2_bm  (1<<5)  /* Clock Select bit 2 mask. */
#define TCF_CLKSEL_2_bp  5  /* Clock Select bit 2 position. */
#define TCF_CMP0EV_bm  0x40  /* Compare 0 Event Generation bit mask. */
#define TCF_CMP0EV_bp  6  /* Compare 0 Event Generation bit position. */
#define TCF_CMP1EV_bm  0x80  /* Compare 1 Event Generation bit mask. */
#define TCF_CMP1EV_bp  7  /* Compare 1 Event Generation bit position. */

/* TCF.CTRLC  bit masks and bit positions */
#define TCF_WO0EN_bm  0x01  /* Waveform Output 0 Enable bit mask. */
#define TCF_WO0EN_bp  0  /* Waveform Output 0 Enable bit position. */
#define TCF_WO1EN_bm  0x02  /* Waveform Output 1 Enable bit mask. */
#define TCF_WO1EN_bp  1  /* Waveform Output 1 Enable bit position. */
#define TCF_WO0POL_bm  0x04  /* Waveform Output 0 Polarity bit mask. */
#define TCF_WO0POL_bp  2  /* Waveform Output 0 Polarity bit position. */
#define TCF_WO1POL_bm  0x08  /* Waveform Output 1 Polarity bit mask. */
#define TCF_WO1POL_bp  3  /* Waveform Output 1 Polarity bit position. */
#define TCF_WGPULSE_gm  0x70  /* Waveform Generation Pulse Length group mask. */
#define TCF_WGPULSE_gp  4  /* Waveform Generation Pulse Length group position. */
#define TCF_WGPULSE_0_bm  (1<<4)  /* Waveform Generation Pulse Length bit 0 mask. */
#define TCF_WGPULSE_0_bp  4  /* Waveform Generation Pulse Length bit 0 position. */
#define TCF_WGPULSE_1_bm  (1<<5)  /* Waveform Generation Pulse Length bit 1 mask. */
#define TCF_WGPULSE_1_bp  5  /* Waveform Generation Pulse Length bit 1 position. */
#define TCF_WGPULSE_2_bm  (1<<6)  /* Waveform Generation Pulse Length bit 2 mask. */
#define TCF_WGPULSE_2_bp  6  /* Waveform Generation Pulse Length bit 2 position. */

/* TCF.CTRLD  bit masks and bit positions */
#define TCF_CMD_gm  0x03  /* Command group mask. */
#define TCF_CMD_gp  0  /* Command group position. */
#define TCF_CMD_0_bm  (1<<0)  /* Command bit 0 mask. */
#define TCF_CMD_0_bp  0  /* Command bit 0 position. */
#define TCF_CMD_1_bm  (1<<1)  /* Command bit 1 mask. */
#define TCF_CMD_1_bp  1  /* Command bit 1 position. */

/* TCF.EVCTRL  bit masks and bit positions */
#define TCF_CNTAEI_bm  0x01  /* Event A Input Enable bit mask. */
#define TCF_CNTAEI_bp  0  /* Event A Input Enable bit position. */
#define TCF_EVACTA_gm  0x06  /* Event Action A group mask. */
#define TCF_EVACTA_gp  1  /* Event Action A group position. */
#define TCF_EVACTA_0_bm  (1<<1)  /* Event Action A bit 0 mask. */
#define TCF_EVACTA_0_bp  1  /* Event Action A bit 0 position. */
#define TCF_EVACTA_1_bm  (1<<2)  /* Event Action A bit 1 mask. */
#define TCF_EVACTA_1_bp  2  /* Event Action A bit 1 position. */
#define TCF_FILTERA_bm  0x08  /* Event A Filter bit mask. */
#define TCF_FILTERA_bp  3  /* Event A Filter bit position. */

/* TCF.INTCTRL  bit masks and bit positions */
#define TCF_OVF_bm  0x01  /* Overflow bit mask. */
#define TCF_OVF_bp  0  /* Overflow bit position. */
#define TCF_CMP0_bm  0x02  /* Compare 0 Interrupt Enable bit mask. */
#define TCF_CMP0_bp  1  /* Compare 0 Interrupt Enable bit position. */
#define TCF_CMP1_bm  0x04  /* Compare 1 Interrupt Enable bit mask. */
#define TCF_CMP1_bp  2  /* Compare 1 Interrupt Enable bit position. */

/* TCF.INTFLAGS  bit masks and bit positions */
/* TCF_OVF  is already defined. */
/* TCF_CMP0  is already defined. */
/* TCF_CMP1  is already defined. */

/* TCF.STATUS  bit masks and bit positions */
#define TCF_CTRLABUSY_bm  0x02  /* Control A Synchronization Busy bit mask. */
#define TCF_CTRLABUSY_bp  1  /* Control A Synchronization Busy bit position. */
#define TCF_CTRLCBUSY_bm  0x04  /* Control B Synchronization Busy bit mask. */
#define TCF_CTRLCBUSY_bp  2  /* Control B Synchronization Busy bit position. */
#define TCF_CTRLDBUSY_bm  0x08  /* Control D Synchronization Busy bit mask. */
#define TCF_CTRLDBUSY_bp  3  /* Control D Synchronization Busy bit position. */
#define TCF_CNTBUSY_bm  0x10  /* Counter Synchronization Busy bit mask. */
#define TCF_CNTBUSY_bp  4  /* Counter Synchronization Busy bit position. */
#define TCF_PERBUSY_bm  0x20  /* Period Synchronization Busy bit mask. */
#define TCF_PERBUSY_bp  5  /* Period Synchronization Busy bit position. */
#define TCF_CMP0BUSY_bm  0x40  /* Compare 0 Synchronization Busy bit mask. */
#define TCF_CMP0BUSY_bp  6  /* Compare 0 Synchronization Busy bit position. */
#define TCF_CMP1BUSY_bm  0x80  /* Compare 1 Synchronization Busy bit mask. */
#define TCF_CMP1BUSY_bp  7  /* Compare 1 Synchronization Busy bit position. */

/* TCF.DBGCTRL  bit masks and bit positions */
#define TCF_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCF_DBGRUN_bp  0  /* Debug Run bit position. */

/* TCF.CNT  bit masks and bit positions */
#define TCF_CNT_gm  0xFFFFF  /* Counter group mask. */
#define TCF_CNT_gp  0  /* Counter group position. */
#define TCF_CNT_0_bm  (1<<0)  /* Counter bit 0 mask. */
#define TCF_CNT_0_bp  0  /* Counter bit 0 position. */
#define TCF_CNT_1_bm  (1<<1)  /* Counter bit 1 mask. */
#define TCF_CNT_1_bp  1  /* Counter bit 1 position. */
#define TCF_CNT_2_bm  (1<<2)  /* Counter bit 2 mask. */
#define TCF_CNT_2_bp  2  /* Counter bit 2 position. */
#define TCF_CNT_3_bm  (1<<3)  /* Counter bit 3 mask. */
#define TCF_CNT_3_bp  3  /* Counter bit 3 position. */
#define TCF_CNT_4_bm  (1<<4)  /* Counter bit 4 mask. */
#define TCF_CNT_4_bp  4  /* Counter bit 4 position. */
#define TCF_CNT_5_bm  (1<<5)  /* Counter bit 5 mask. */
#define TCF_CNT_5_bp  5  /* Counter bit 5 position. */
#define TCF_CNT_6_bm  (1<<6)  /* Counter bit 6 mask. */
#define TCF_CNT_6_bp  6  /* Counter bit 6 position. */
#define TCF_CNT_7_bm  (1<<7)  /* Counter bit 7 mask. */
#define TCF_CNT_7_bp  7  /* Counter bit 7 position. */
#define TCF_CNT_8_bm  (1<<8)  /* Counter bit 8 mask. */
#define TCF_CNT_8_bp  8  /* Counter bit 8 position. */
#define TCF_CNT_9_bm  (1<<9)  /* Counter bit 9 mask. */
#define TCF_CNT_9_bp  9  /* Counter bit 9 position. */
#define TCF_CNT_10_bm  (1<<10)  /* Counter bit 10 mask. */
#define TCF_CNT_10_bp  10  /* Counter bit 10 position. */
#define TCF_CNT_11_bm  (1<<11)  /* Counter bit 11 mask. */
#define TCF_CNT_11_bp  11  /* Counter bit 11 position. */
#define TCF_CNT_12_bm  (1<<12)  /* Counter bit 12 mask. */
#define TCF_CNT_12_bp  12  /* Counter bit 12 position. */
#define TCF_CNT_13_bm  (1<<13)  /* Counter bit 13 mask. */
#define TCF_CNT_13_bp  13  /* Counter bit 13 position. */
#define TCF_CNT_14_bm  (1<<14)  /* Counter bit 14 mask. */
#define TCF_CNT_14_bp  14  /* Counter bit 14 position. */
#define TCF_CNT_15_bm  (1<<15)  /* Counter bit 15 mask. */
#define TCF_CNT_15_bp  15  /* Counter bit 15 position. */
#define TCF_CNT_16_bm  (1<<16)  /* Counter bit 16 mask. */
#define TCF_CNT_16_bp  16  /* Counter bit 16 position. */
#define TCF_CNT_17_bm  (1<<17)  /* Counter bit 17 mask. */
#define TCF_CNT_17_bp  17  /* Counter bit 17 position. */
#define TCF_CNT_18_bm  (1<<18)  /* Counter bit 18 mask. */
#define TCF_CNT_18_bp  18  /* Counter bit 18 position. */
#define TCF_CNT_19_bm  (1<<19)  /* Counter bit 19 mask. */
#define TCF_CNT_19_bp  19  /* Counter bit 19 position. */

/* TCF.CMP  bit masks and bit positions */
#define TCF_CMP_gm  0xFFFFF  /* Compare group mask. */
#define TCF_CMP_gp  0  /* Compare group position. */
#define TCF_CMP_0_bm  (1<<0)  /* Compare bit 0 mask. */
#define TCF_CMP_0_bp  0  /* Compare bit 0 position. */
#define TCF_CMP_1_bm  (1<<1)  /* Compare bit 1 mask. */
#define TCF_CMP_1_bp  1  /* Compare bit 1 position. */
#define TCF_CMP_2_bm  (1<<2)  /* Compare bit 2 mask. */
#define TCF_CMP_2_bp  2  /* Compare bit 2 position. */
#define TCF_CMP_3_bm  (1<<3)  /* Compare bit 3 mask. */
#define TCF_CMP_3_bp  3  /* Compare bit 3 position. */
#define TCF_CMP_4_bm  (1<<4)  /* Compare bit 4 mask. */
#define TCF_CMP_4_bp  4  /* Compare bit 4 position. */
#define TCF_CMP_5_bm  (1<<5)  /* Compare bit 5 mask. */
#define TCF_CMP_5_bp  5  /* Compare bit 5 position. */
#define TCF_CMP_6_bm  (1<<6)  /* Compare bit 6 mask. */
#define TCF_CMP_6_bp  6  /* Compare bit 6 position. */
#define TCF_CMP_7_bm  (1<<7)  /* Compare bit 7 mask. */
#define TCF_CMP_7_bp  7  /* Compare bit 7 position. */
#define TCF_CMP_8_bm  (1<<8)  /* Compare bit 8 mask. */
#define TCF_CMP_8_bp  8  /* Compare bit 8 position. */
#define TCF_CMP_9_bm  (1<<9)  /* Compare bit 9 mask. */
#define TCF_CMP_9_bp  9  /* Compare bit 9 position. */
#define TCF_CMP_10_bm  (1<<10)  /* Compare bit 10 mask. */
#define TCF_CMP_10_bp  10  /* Compare bit 10 position. */
#define TCF_CMP_11_bm  (1<<11)  /* Compare bit 11 mask. */
#define TCF_CMP_11_bp  11  /* Compare bit 11 position. */
#define TCF_CMP_12_bm  (1<<12)  /* Compare bit 12 mask. */
#define TCF_CMP_12_bp  12  /* Compare bit 12 position. */
#define TCF_CMP_13_bm  (1<<13)  /* Compare bit 13 mask. */
#define TCF_CMP_13_bp  13  /* Compare bit 13 position. */
#define TCF_CMP_14_bm  (1<<14)  /* Compare bit 14 mask. */
#define TCF_CMP_14_bp  14  /* Compare bit 14 position. */
#define TCF_CMP_15_bm  (1<<15)  /* Compare bit 15 mask. */
#define TCF_CMP_15_bp  15  /* Compare bit 15 position. */
#define TCF_CMP_16_bm  (1<<16)  /* Compare bit 16 mask. */
#define TCF_CMP_16_bp  16  /* Compare bit 16 position. */
#define TCF_CMP_17_bm  (1<<17)  /* Compare bit 17 mask. */
#define TCF_CMP_17_bp  17  /* Compare bit 17 position. */
#define TCF_CMP_18_bm  (1<<18)  /* Compare bit 18 mask. */
#define TCF_CMP_18_bp  18  /* Compare bit 18 position. */
#define TCF_CMP_19_bm  (1<<19)  /* Compare bit 19 mask. */
#define TCF_CMP_19_bp  19  /* Compare bit 19 position. */


/* TWI - Two-Wire Interface */
/* TWI.CTRLA  bit masks and bit positions */
#define TWI_FMPEN_bm  0x02  /* Fast-mode Plus Enable bit mask. */
#define TWI_FMPEN_bp  1  /* Fast-mode Plus Enable bit position. */
#define TWI_SDAHOLD_gm  0x0C  /* SDA Hold Time group mask. */
#define TWI_SDAHOLD_gp  2  /* SDA Hold Time group position. */
#define TWI_SDAHOLD_0_bm  (1<<2)  /* SDA Hold Time bit 0 mask. */
#define TWI_SDAHOLD_0_bp  2  /* SDA Hold Time bit 0 position. */
#define TWI_SDAHOLD_1_bm  (1<<3)  /* SDA Hold Time bit 1 mask. */
#define TWI_SDAHOLD_1_bp  3  /* SDA Hold Time bit 1 position. */
#define TWI_SDASETUP_bm  0x10  /* SDA Setup Time bit mask. */
#define TWI_SDASETUP_bp  4  /* SDA Setup Time bit position. */
#define TWI_INPUTLVL_bm  0x40  /* Input voltage transition level bit mask. */
#define TWI_INPUTLVL_bp  6  /* Input voltage transition level bit position. */

/* TWI.DBGCTRL  bit masks and bit positions */
#define TWI_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TWI_DBGRUN_bp  0  /* Debug Run bit position. */

/* TWI.MCTRLA  bit masks and bit positions */
#define TWI_ENABLE_bm  0x01  /* Enable bit mask. */
#define TWI_ENABLE_bp  0  /* Enable bit position. */
#define TWI_SMEN_bm  0x02  /* Smart Mode Enable bit mask. */
#define TWI_SMEN_bp  1  /* Smart Mode Enable bit position. */
#define TWI_TIMEOUT_gm  0x0C  /* Inactive Bus Time-Out group mask. */
#define TWI_TIMEOUT_gp  2  /* Inactive Bus Time-Out group position. */
#define TWI_TIMEOUT_0_bm  (1<<2)  /* Inactive Bus Time-Out bit 0 mask. */
#define TWI_TIMEOUT_0_bp  2  /* Inactive Bus Time-Out bit 0 position. */
#define TWI_TIMEOUT_1_bm  (1<<3)  /* Inactive Bus Time-Out bit 1 mask. */
#define TWI_TIMEOUT_1_bp  3  /* Inactive Bus Time-Out bit 1 position. */
#define TWI_QCEN_bm  0x10  /* Quick Command Enable bit mask. */
#define TWI_QCEN_bp  4  /* Quick Command Enable bit position. */
#define TWI_WIEN_bm  0x40  /* Write Interrupt Enable bit mask. */
#define TWI_WIEN_bp  6  /* Write Interrupt Enable bit position. */
#define TWI_RIEN_bm  0x80  /* Read Interrupt Enable bit mask. */
#define TWI_RIEN_bp  7  /* Read Interrupt Enable bit position. */

/* TWI.MCTRLB  bit masks and bit positions */
#define TWI_MCMD_gm  0x03  /* Command group mask. */
#define TWI_MCMD_gp  0  /* Command group position. */
#define TWI_MCMD_0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_MCMD_0_bp  0  /* Command bit 0 position. */
#define TWI_MCMD_1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_MCMD_1_bp  1  /* Command bit 1 position. */
#define TWI_ACKACT_bm  0x04  /* Acknowledge Action bit mask. */
#define TWI_ACKACT_bp  2  /* Acknowledge Action bit position. */
#define TWI_FLUSH_bm  0x08  /* Flush bit mask. */
#define TWI_FLUSH_bp  3  /* Flush bit position. */

/* TWI.MSTATUS  bit masks and bit positions */
#define TWI_BUSSTATE_gm  0x03  /* Bus State group mask. */
#define TWI_BUSSTATE_gp  0  /* Bus State group position. */
#define TWI_BUSSTATE_0_bm  (1<<0)  /* Bus State bit 0 mask. */
#define TWI_BUSSTATE_0_bp  0  /* Bus State bit 0 position. */
#define TWI_BUSSTATE_1_bm  (1<<1)  /* Bus State bit 1 mask. */
#define TWI_BUSSTATE_1_bp  1  /* Bus State bit 1 position. */
#define TWI_BUSERR_bm  0x04  /* Bus Error bit mask. */
#define TWI_BUSERR_bp  2  /* Bus Error bit position. */
#define TWI_ARBLOST_bm  0x08  /* Arbitration Lost bit mask. */
#define TWI_ARBLOST_bp  3  /* Arbitration Lost bit position. */
#define TWI_RXACK_bm  0x10  /* Received Acknowledge bit mask. */
#define TWI_RXACK_bp  4  /* Received Acknowledge bit position. */
#define TWI_CLKHOLD_bm  0x20  /* Clock Hold bit mask. */
#define TWI_CLKHOLD_bp  5  /* Clock Hold bit position. */
#define TWI_WIF_bm  0x40  /* Write Interrupt Flag bit mask. */
#define TWI_WIF_bp  6  /* Write Interrupt Flag bit position. */
#define TWI_RIF_bm  0x80  /* Read Interrupt Flag bit mask. */
#define TWI_RIF_bp  7  /* Read Interrupt Flag bit position. */

/* TWI.MBAUD  bit masks and bit positions */
#define TWI_BAUD_gm  0xFF  /* Baud Rate group mask. */
#define TWI_BAUD_gp  0  /* Baud Rate group position. */
#define TWI_BAUD_0_bm  (1<<0)  /* Baud Rate bit 0 mask. */
#define TWI_BAUD_0_bp  0  /* Baud Rate bit 0 position. */
#define TWI_BAUD_1_bm  (1<<1)  /* Baud Rate bit 1 mask. */
#define TWI_BAUD_1_bp  1  /* Baud Rate bit 1 position. */
#define TWI_BAUD_2_bm  (1<<2)  /* Baud Rate bit 2 mask. */
#define TWI_BAUD_2_bp  2  /* Baud Rate bit 2 position. */
#define TWI_BAUD_3_bm  (1<<3)  /* Baud Rate bit 3 mask. */
#define TWI_BAUD_3_bp  3  /* Baud Rate bit 3 position. */
#define TWI_BAUD_4_bm  (1<<4)  /* Baud Rate bit 4 mask. */
#define TWI_BAUD_4_bp  4  /* Baud Rate bit 4 position. */
#define TWI_BAUD_5_bm  (1<<5)  /* Baud Rate bit 5 mask. */
#define TWI_BAUD_5_bp  5  /* Baud Rate bit 5 position. */
#define TWI_BAUD_6_bm  (1<<6)  /* Baud Rate bit 6 mask. */
#define TWI_BAUD_6_bp  6  /* Baud Rate bit 6 position. */
#define TWI_BAUD_7_bm  (1<<7)  /* Baud Rate bit 7 mask. */
#define TWI_BAUD_7_bp  7  /* Baud Rate bit 7 position. */

/* TWI.MADDR  bit masks and bit positions */
#define TWI_ADDR_gm  0xFF  /* Address group mask. */
#define TWI_ADDR_gp  0  /* Address group position. */
#define TWI_ADDR_0_bm  (1<<0)  /* Address bit 0 mask. */
#define TWI_ADDR_0_bp  0  /* Address bit 0 position. */
#define TWI_ADDR_1_bm  (1<<1)  /* Address bit 1 mask. */
#define TWI_ADDR_1_bp  1  /* Address bit 1 position. */
#define TWI_ADDR_2_bm  (1<<2)  /* Address bit 2 mask. */
#define TWI_ADDR_2_bp  2  /* Address bit 2 position. */
#define TWI_ADDR_3_bm  (1<<3)  /* Address bit 3 mask. */
#define TWI_ADDR_3_bp  3  /* Address bit 3 position. */
#define TWI_ADDR_4_bm  (1<<4)  /* Address bit 4 mask. */
#define TWI_ADDR_4_bp  4  /* Address bit 4 position. */
#define TWI_ADDR_5_bm  (1<<5)  /* Address bit 5 mask. */
#define TWI_ADDR_5_bp  5  /* Address bit 5 position. */
#define TWI_ADDR_6_bm  (1<<6)  /* Address bit 6 mask. */
#define TWI_ADDR_6_bp  6  /* Address bit 6 position. */
#define TWI_ADDR_7_bm  (1<<7)  /* Address bit 7 mask. */
#define TWI_ADDR_7_bp  7  /* Address bit 7 position. */

/* TWI.MDATA  bit masks and bit positions */
#define TWI_DATA_gm  0xFF  /* Data group mask. */
#define TWI_DATA_gp  0  /* Data group position. */
#define TWI_DATA_0_bm  (1<<0)  /* Data bit 0 mask. */
#define TWI_DATA_0_bp  0  /* Data bit 0 position. */
#define TWI_DATA_1_bm  (1<<1)  /* Data bit 1 mask. */
#define TWI_DATA_1_bp  1  /* Data bit 1 position. */
#define TWI_DATA_2_bm  (1<<2)  /* Data bit 2 mask. */
#define TWI_DATA_2_bp  2  /* Data bit 2 position. */
#define TWI_DATA_3_bm  (1<<3)  /* Data bit 3 mask. */
#define TWI_DATA_3_bp  3  /* Data bit 3 position. */
#define TWI_DATA_4_bm  (1<<4)  /* Data bit 4 mask. */
#define TWI_DATA_4_bp  4  /* Data bit 4 position. */
#define TWI_DATA_5_bm  (1<<5)  /* Data bit 5 mask. */
#define TWI_DATA_5_bp  5  /* Data bit 5 position. */
#define TWI_DATA_6_bm  (1<<6)  /* Data bit 6 mask. */
#define TWI_DATA_6_bp  6  /* Data bit 6 position. */
#define TWI_DATA_7_bm  (1<<7)  /* Data bit 7 mask. */
#define TWI_DATA_7_bp  7  /* Data bit 7 position. */

/* TWI.SCTRLA  bit masks and bit positions */
/* TWI_ENABLE  is already defined. */
/* TWI_SMEN  is already defined. */
#define TWI_PMEN_bm  0x04  /* Address Recognition Mode bit mask. */
#define TWI_PMEN_bp  2  /* Address Recognition Mode bit position. */
#define TWI_PIEN_bm  0x20  /* Stop Interrupt Enable bit mask. */
#define TWI_PIEN_bp  5  /* Stop Interrupt Enable bit position. */
#define TWI_APIEN_bm  0x40  /* Address or Stop Interrupt Enable bit mask. */
#define TWI_APIEN_bp  6  /* Address or Stop Interrupt Enable bit position. */
#define TWI_DIEN_bm  0x80  /* Data Interrupt Enable bit mask. */
#define TWI_DIEN_bp  7  /* Data Interrupt Enable bit position. */

/* TWI.SCTRLB  bit masks and bit positions */
#define TWI_SCMD_gm  0x03  /* Command group mask. */
#define TWI_SCMD_gp  0  /* Command group position. */
#define TWI_SCMD_0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_SCMD_0_bp  0  /* Command bit 0 position. */
#define TWI_SCMD_1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_SCMD_1_bp  1  /* Command bit 1 position. */
/* TWI_ACKACT  is already defined. */

/* TWI.SSTATUS  bit masks and bit positions */
#define TWI_AP_bm  0x01  /* Address or Stop bit mask. */
#define TWI_AP_bp  0  /* Address or Stop bit position. */
#define TWI_DIR_bm  0x02  /* Read/Write Direction bit mask. */
#define TWI_DIR_bp  1  /* Read/Write Direction bit position. */
/* TWI_BUSERR  is already defined. */
#define TWI_COLL_bm  0x08  /* Collision bit mask. */
#define TWI_COLL_bp  3  /* Collision bit position. */
/* TWI_RXACK  is already defined. */
/* TWI_CLKHOLD  is already defined. */
#define TWI_APIF_bm  0x40  /* Address or Stop Interrupt Flag bit mask. */
#define TWI_APIF_bp  6  /* Address or Stop Interrupt Flag bit position. */
#define TWI_DIF_bm  0x80  /* Data Interrupt Flag bit mask. */
#define TWI_DIF_bp  7  /* Data Interrupt Flag bit position. */

/* TWI.SADDR  bit masks and bit positions */
/* TWI_ADDR  is already defined. */

/* TWI.SDATA  bit masks and bit positions */
/* TWI_DATA  is already defined. */

/* TWI.SADDRMASK  bit masks and bit positions */
#define TWI_ADDREN_bm  0x01  /* Address Mask Enable bit mask. */
#define TWI_ADDREN_bp  0  /* Address Mask Enable bit position. */
#define TWI_ADDRMASK_gm  0xFE  /* Address Mask group mask. */
#define TWI_ADDRMASK_gp  1  /* Address Mask group position. */
#define TWI_ADDRMASK_0_bm  (1<<1)  /* Address Mask bit 0 mask. */
#define TWI_ADDRMASK_0_bp  1  /* Address Mask bit 0 position. */
#define TWI_ADDRMASK_1_bm  (1<<2)  /* Address Mask bit 1 mask. */
#define TWI_ADDRMASK_1_bp  2  /* Address Mask bit 1 position. */
#define TWI_ADDRMASK_2_bm  (1<<3)  /* Address Mask bit 2 mask. */
#define TWI_ADDRMASK_2_bp  3  /* Address Mask bit 2 position. */
#define TWI_ADDRMASK_3_bm  (1<<4)  /* Address Mask bit 3 mask. */
#define TWI_ADDRMASK_3_bp  4  /* Address Mask bit 3 position. */
#define TWI_ADDRMASK_4_bm  (1<<5)  /* Address Mask bit 4 mask. */
#define TWI_ADDRMASK_4_bp  5  /* Address Mask bit 4 position. */
#define TWI_ADDRMASK_5_bm  (1<<6)  /* Address Mask bit 5 mask. */
#define TWI_ADDRMASK_5_bp  6  /* Address Mask bit 5 position. */
#define TWI_ADDRMASK_6_bm  (1<<7)  /* Address Mask bit 6 mask. */
#define TWI_ADDRMASK_6_bp  7  /* Address Mask bit 6 position. */

/* TWI.TESTCTRL  bit masks and bit positions */
#define TWI_SCLDUTY_gm  0x07  /* SCL Duty Cycle Adjustment group mask. */
#define TWI_SCLDUTY_gp  0  /* SCL Duty Cycle Adjustment group position. */
#define TWI_SCLDUTY_0_bm  (1<<0)  /* SCL Duty Cycle Adjustment bit 0 mask. */
#define TWI_SCLDUTY_0_bp  0  /* SCL Duty Cycle Adjustment bit 0 position. */
#define TWI_SCLDUTY_1_bm  (1<<1)  /* SCL Duty Cycle Adjustment bit 1 mask. */
#define TWI_SCLDUTY_1_bp  1  /* SCL Duty Cycle Adjustment bit 1 position. */
#define TWI_SCLDUTY_2_bm  (1<<2)  /* SCL Duty Cycle Adjustment bit 2 mask. */
#define TWI_SCLDUTY_2_bp  2  /* SCL Duty Cycle Adjustment bit 2 position. */
#define TWI_SCL6040_bm  0x08  /* SCL 60% low time bit mask. */
#define TWI_SCL6040_bp  3  /* SCL 60% low time bit position. */
#define TWI_GPIODRV_bm  0x10  /* GPIo Driver bit mask. */
#define TWI_GPIODRV_bp  4  /* GPIo Driver bit position. */
#define TWI_HDTEST_bm  0x20  /* Hold Delay Test Mode bit mask. */
#define TWI_HDTEST_bp  5  /* Hold Delay Test Mode bit position. */
#define TWI_PADTEST_bm  0x80  /* PadTest Mode Enable bit mask. */
#define TWI_PADTEST_bp  7  /* PadTest Mode Enable bit position. */


/* USART - Universal Synchronous and Asynchronous Receiver and Transmitter */
/* USART.RXDATAL  bit masks and bit positions */
#define USART_DATA_gm  0xFF  /* RX Data group mask. */
#define USART_DATA_gp  0  /* RX Data group position. */
#define USART_DATA_0_bm  (1<<0)  /* RX Data bit 0 mask. */
#define USART_DATA_0_bp  0  /* RX Data bit 0 position. */
#define USART_DATA_1_bm  (1<<1)  /* RX Data bit 1 mask. */
#define USART_DATA_1_bp  1  /* RX Data bit 1 position. */
#define USART_DATA_2_bm  (1<<2)  /* RX Data bit 2 mask. */
#define USART_DATA_2_bp  2  /* RX Data bit 2 position. */
#define USART_DATA_3_bm  (1<<3)  /* RX Data bit 3 mask. */
#define USART_DATA_3_bp  3  /* RX Data bit 3 position. */
#define USART_DATA_4_bm  (1<<4)  /* RX Data bit 4 mask. */
#define USART_DATA_4_bp  4  /* RX Data bit 4 position. */
#define USART_DATA_5_bm  (1<<5)  /* RX Data bit 5 mask. */
#define USART_DATA_5_bp  5  /* RX Data bit 5 position. */
#define USART_DATA_6_bm  (1<<6)  /* RX Data bit 6 mask. */
#define USART_DATA_6_bp  6  /* RX Data bit 6 position. */
#define USART_DATA_7_bm  (1<<7)  /* RX Data bit 7 mask. */
#define USART_DATA_7_bp  7  /* RX Data bit 7 position. */

/* USART.RXDATAH  bit masks and bit positions */
#define USART_DATA8_bm  0x01  /* Receiver Data Register bit mask. */
#define USART_DATA8_bp  0  /* Receiver Data Register bit position. */
#define USART_PERR_bm  0x02  /* Parity Error bit mask. */
#define USART_PERR_bp  1  /* Parity Error bit position. */
#define USART_FERR_bm  0x04  /* Frame Error bit mask. */
#define USART_FERR_bp  2  /* Frame Error bit position. */
#define USART_BUFOVF_bm  0x40  /* Buffer Overflow bit mask. */
#define USART_BUFOVF_bp  6  /* Buffer Overflow bit position. */
#define USART_RXCIF_bm  0x80  /* Receive Complete Interrupt Flag bit mask. */
#define USART_RXCIF_bp  7  /* Receive Complete Interrupt Flag bit position. */

/* USART.TXDATAL  bit masks and bit positions */
/* USART_DATA  is already defined. */

/* USART.TXDATAH  bit masks and bit positions */
/* USART_DATA8  is already defined. */

/* USART.STATUS  bit masks and bit positions */
#define USART_WFB_bm  0x01  /* Wait For Break bit mask. */
#define USART_WFB_bp  0  /* Wait For Break bit position. */
#define USART_BDF_bm  0x02  /* Break Detected Flag bit mask. */
#define USART_BDF_bp  1  /* Break Detected Flag bit position. */
#define USART_ISFIF_bm  0x08  /* Inconsistent Sync Field Interrupt Flag bit mask. */
#define USART_ISFIF_bp  3  /* Inconsistent Sync Field Interrupt Flag bit position. */
#define USART_RXSIF_bm  0x10  /* Receive Start Interrupt bit mask. */
#define USART_RXSIF_bp  4  /* Receive Start Interrupt bit position. */
#define USART_DREIF_bm  0x20  /* Data Register Empty Flag bit mask. */
#define USART_DREIF_bp  5  /* Data Register Empty Flag bit position. */
#define USART_TXCIF_bm  0x40  /* Transmit Interrupt Flag bit mask. */
#define USART_TXCIF_bp  6  /* Transmit Interrupt Flag bit position. */
/* USART_RXCIF  is already defined. */

/* USART.CTRLA  bit masks and bit positions */
#define USART_RS485_bm  0x01  /* RS485 Mode internal transmitter bit mask. */
#define USART_RS485_bp  0  /* RS485 Mode internal transmitter bit position. */
#define USART_ABEIE_bm  0x04  /* Auto-baud Error Interrupt Enable bit mask. */
#define USART_ABEIE_bp  2  /* Auto-baud Error Interrupt Enable bit position. */
#define USART_LBME_bm  0x08  /* Loop-back Mode Enable bit mask. */
#define USART_LBME_bp  3  /* Loop-back Mode Enable bit position. */
#define USART_RXSIE_bm  0x10  /* Receiver Start Frame Interrupt Enable bit mask. */
#define USART_RXSIE_bp  4  /* Receiver Start Frame Interrupt Enable bit position. */
#define USART_DREIE_bm  0x20  /* Data Register Empty Interrupt Enable bit mask. */
#define USART_DREIE_bp  5  /* Data Register Empty Interrupt Enable bit position. */
#define USART_TXCIE_bm  0x40  /* Transmit Complete Interrupt Enable bit mask. */
#define USART_TXCIE_bp  6  /* Transmit Complete Interrupt Enable bit position. */
#define USART_RXCIE_bm  0x80  /* Receive Complete Interrupt Enable bit mask. */
#define USART_RXCIE_bp  7  /* Receive Complete Interrupt Enable bit position. */

/* USART.CTRLB  bit masks and bit positions */
#define USART_MPCM_bm  0x01  /* Multi-processor Communication Mode bit mask. */
#define USART_MPCM_bp  0  /* Multi-processor Communication Mode bit position. */
#define USART_RXMODE_gm  0x06  /* Receiver Mode group mask. */
#define USART_RXMODE_gp  1  /* Receiver Mode group position. */
#define USART_RXMODE_0_bm  (1<<1)  /* Receiver Mode bit 0 mask. */
#define USART_RXMODE_0_bp  1  /* Receiver Mode bit 0 position. */
#define USART_RXMODE_1_bm  (1<<2)  /* Receiver Mode bit 1 mask. */
#define USART_RXMODE_1_bp  2  /* Receiver Mode bit 1 position. */
#define USART_ODME_bm  0x08  /* Open Drain Mode Enable bit mask. */
#define USART_ODME_bp  3  /* Open Drain Mode Enable bit position. */
#define USART_SFDEN_bm  0x10  /* Start Frame Detection Enable bit mask. */
#define USART_SFDEN_bp  4  /* Start Frame Detection Enable bit position. */
#define USART_TXEN_bm  0x40  /* Transmitter Enable bit mask. */
#define USART_TXEN_bp  6  /* Transmitter Enable bit position. */
#define USART_RXEN_bm  0x80  /* Reciever enable bit mask. */
#define USART_RXEN_bp  7  /* Reciever enable bit position. */

/* USART.CTRLC  bit masks and bit positions */
#define USART_UCPHA_bm  0x02  /* SPI Host Mode, Clock Phase bit mask. */
#define USART_UCPHA_bp  1  /* SPI Host Mode, Clock Phase bit position. */
#define USART_UDORD_bm  0x04  /* SPI Host Mode, Data Order bit mask. */
#define USART_UDORD_bp  2  /* SPI Host Mode, Data Order bit position. */
#define USART_CHSIZE_gm  0x07  /* Character Size group mask. */
#define USART_CHSIZE_gp  0  /* Character Size group position. */
#define USART_CHSIZE_0_bm  (1<<0)  /* Character Size bit 0 mask. */
#define USART_CHSIZE_0_bp  0  /* Character Size bit 0 position. */
#define USART_CHSIZE_1_bm  (1<<1)  /* Character Size bit 1 mask. */
#define USART_CHSIZE_1_bp  1  /* Character Size bit 1 position. */
#define USART_CHSIZE_2_bm  (1<<2)  /* Character Size bit 2 mask. */
#define USART_CHSIZE_2_bp  2  /* Character Size bit 2 position. */
#define USART_SBMODE_bm  0x08  /* Stop Bit Mode bit mask. */
#define USART_SBMODE_bp  3  /* Stop Bit Mode bit position. */
#define USART_PMODE_gm  0x30  /* Parity Mode group mask. */
#define USART_PMODE_gp  4  /* Parity Mode group position. */
#define USART_PMODE_0_bm  (1<<4)  /* Parity Mode bit 0 mask. */
#define USART_PMODE_0_bp  4  /* Parity Mode bit 0 position. */
#define USART_PMODE_1_bm  (1<<5)  /* Parity Mode bit 1 mask. */
#define USART_PMODE_1_bp  5  /* Parity Mode bit 1 position. */
#define USART_CMODE_gm  0xC0  /* Communication Mode group mask. */
#define USART_CMODE_gp  6  /* Communication Mode group position. */
#define USART_CMODE_0_bm  (1<<6)  /* Communication Mode bit 0 mask. */
#define USART_CMODE_0_bp  6  /* Communication Mode bit 0 position. */
#define USART_CMODE_1_bm  (1<<7)  /* Communication Mode bit 1 mask. */
#define USART_CMODE_1_bp  7  /* Communication Mode bit 1 position. */

/* USART.CTRLD  bit masks and bit positions */
#define USART_ABW_gm  0xC0  /* Auto Baud Window group mask. */
#define USART_ABW_gp  6  /* Auto Baud Window group position. */
#define USART_ABW_0_bm  (1<<6)  /* Auto Baud Window bit 0 mask. */
#define USART_ABW_0_bp  6  /* Auto Baud Window bit 0 position. */
#define USART_ABW_1_bm  (1<<7)  /* Auto Baud Window bit 1 mask. */
#define USART_ABW_1_bp  7  /* Auto Baud Window bit 1 position. */

/* USART.DBGCTRL  bit masks and bit positions */
#define USART_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define USART_DBGRUN_bp  0  /* Debug Run bit position. */
#define USART_ABMBP_bm  0x80  /* Autobaud majority voter bypass bit mask. */
#define USART_ABMBP_bp  7  /* Autobaud majority voter bypass bit position. */

/* USART.EVCTRL  bit masks and bit positions */
#define USART_IREI_bm  0x01  /* IrDA Event Input Enable bit mask. */
#define USART_IREI_bp  0  /* IrDA Event Input Enable bit position. */

/* USART.TXPLCTRL  bit masks and bit positions */
#define USART_TXPL_gm  0xFF  /* Transmit pulse length group mask. */
#define USART_TXPL_gp  0  /* Transmit pulse length group position. */
#define USART_TXPL_0_bm  (1<<0)  /* Transmit pulse length bit 0 mask. */
#define USART_TXPL_0_bp  0  /* Transmit pulse length bit 0 position. */
#define USART_TXPL_1_bm  (1<<1)  /* Transmit pulse length bit 1 mask. */
#define USART_TXPL_1_bp  1  /* Transmit pulse length bit 1 position. */
#define USART_TXPL_2_bm  (1<<2)  /* Transmit pulse length bit 2 mask. */
#define USART_TXPL_2_bp  2  /* Transmit pulse length bit 2 position. */
#define USART_TXPL_3_bm  (1<<3)  /* Transmit pulse length bit 3 mask. */
#define USART_TXPL_3_bp  3  /* Transmit pulse length bit 3 position. */
#define USART_TXPL_4_bm  (1<<4)  /* Transmit pulse length bit 4 mask. */
#define USART_TXPL_4_bp  4  /* Transmit pulse length bit 4 position. */
#define USART_TXPL_5_bm  (1<<5)  /* Transmit pulse length bit 5 mask. */
#define USART_TXPL_5_bp  5  /* Transmit pulse length bit 5 position. */
#define USART_TXPL_6_bm  (1<<6)  /* Transmit pulse length bit 6 mask. */
#define USART_TXPL_6_bp  6  /* Transmit pulse length bit 6 position. */
#define USART_TXPL_7_bm  (1<<7)  /* Transmit pulse length bit 7 mask. */
#define USART_TXPL_7_bp  7  /* Transmit pulse length bit 7 position. */

/* USART.RXPLCTRL  bit masks and bit positions */
#define USART_RXPL_gm  0x7F  /* Receiver Pulse Lenght group mask. */
#define USART_RXPL_gp  0  /* Receiver Pulse Lenght group position. */
#define USART_RXPL_0_bm  (1<<0)  /* Receiver Pulse Lenght bit 0 mask. */
#define USART_RXPL_0_bp  0  /* Receiver Pulse Lenght bit 0 position. */
#define USART_RXPL_1_bm  (1<<1)  /* Receiver Pulse Lenght bit 1 mask. */
#define USART_RXPL_1_bp  1  /* Receiver Pulse Lenght bit 1 position. */
#define USART_RXPL_2_bm  (1<<2)  /* Receiver Pulse Lenght bit 2 mask. */
#define USART_RXPL_2_bp  2  /* Receiver Pulse Lenght bit 2 position. */
#define USART_RXPL_3_bm  (1<<3)  /* Receiver Pulse Lenght bit 3 mask. */
#define USART_RXPL_3_bp  3  /* Receiver Pulse Lenght bit 3 position. */
#define USART_RXPL_4_bm  (1<<4)  /* Receiver Pulse Lenght bit 4 mask. */
#define USART_RXPL_4_bp  4  /* Receiver Pulse Lenght bit 4 position. */
#define USART_RXPL_5_bm  (1<<5)  /* Receiver Pulse Lenght bit 5 mask. */
#define USART_RXPL_5_bp  5  /* Receiver Pulse Lenght bit 5 position. */
#define USART_RXPL_6_bm  (1<<6)  /* Receiver Pulse Lenght bit 6 mask. */
#define USART_RXPL_6_bp  6  /* Receiver Pulse Lenght bit 6 position. */



/* VPORT - Virtual Ports */
/* VPORT.INTFLAGS  bit masks and bit positions */
#define VPORT_INT_gm  0xFF  /* Pin Interrupt Flag group mask. */
#define VPORT_INT_gp  0  /* Pin Interrupt Flag group position. */
#define VPORT_INT_0_bm  (1<<0)  /* Pin Interrupt Flag bit 0 mask. */
#define VPORT_INT_0_bp  0  /* Pin Interrupt Flag bit 0 position. */
#define VPORT_INT_1_bm  (1<<1)  /* Pin Interrupt Flag bit 1 mask. */
#define VPORT_INT_1_bp  1  /* Pin Interrupt Flag bit 1 position. */
#define VPORT_INT_2_bm  (1<<2)  /* Pin Interrupt Flag bit 2 mask. */
#define VPORT_INT_2_bp  2  /* Pin Interrupt Flag bit 2 position. */
#define VPORT_INT_3_bm  (1<<3)  /* Pin Interrupt Flag bit 3 mask. */
#define VPORT_INT_3_bp  3  /* Pin Interrupt Flag bit 3 position. */
#define VPORT_INT_4_bm  (1<<4)  /* Pin Interrupt Flag bit 4 mask. */
#define VPORT_INT_4_bp  4  /* Pin Interrupt Flag bit 4 position. */
#define VPORT_INT_5_bm  (1<<5)  /* Pin Interrupt Flag bit 5 mask. */
#define VPORT_INT_5_bp  5  /* Pin Interrupt Flag bit 5 position. */
#define VPORT_INT_6_bm  (1<<6)  /* Pin Interrupt Flag bit 6 mask. */
#define VPORT_INT_6_bp  6  /* Pin Interrupt Flag bit 6 position. */
#define VPORT_INT_7_bm  (1<<7)  /* Pin Interrupt Flag bit 7 mask. */
#define VPORT_INT_7_bp  7  /* Pin Interrupt Flag bit 7 position. */


/* WDT - Watch-Dog Timer */
/* WDT.CTRLA  bit masks and bit positions */
#define WDT_PERIOD_gm  0x0F  /* Period group mask. */
#define WDT_PERIOD_gp  0  /* Period group position. */
#define WDT_PERIOD_0_bm  (1<<0)  /* Period bit 0 mask. */
#define WDT_PERIOD_0_bp  0  /* Period bit 0 position. */
#define WDT_PERIOD_1_bm  (1<<1)  /* Period bit 1 mask. */
#define WDT_PERIOD_1_bp  1  /* Period bit 1 position. */
#define WDT_PERIOD_2_bm  (1<<2)  /* Period bit 2 mask. */
#define WDT_PERIOD_2_bp  2  /* Period bit 2 position. */
#define WDT_PERIOD_3_bm  (1<<3)  /* Period bit 3 mask. */
#define WDT_PERIOD_3_bp  3  /* Period bit 3 position. */
#define WDT_WINDOW_gm  0xF0  /* Window group mask. */
#define WDT_WINDOW_gp  4  /* Window group position. */
#define WDT_WINDOW_0_bm  (1<<4)  /* Window bit 0 mask. */
#define WDT_WINDOW_0_bp  4  /* Window bit 0 position. */
#define WDT_WINDOW_1_bm  (1<<5)  /* Window bit 1 mask. */
#define WDT_WINDOW_1_bp  5  /* Window bit 1 position. */
#define WDT_WINDOW_2_bm  (1<<6)  /* Window bit 2 mask. */
#define WDT_WINDOW_2_bp  6  /* Window bit 2 position. */
#define WDT_WINDOW_3_bm  (1<<7)  /* Window bit 3 mask. */
#define WDT_WINDOW_3_bp  7  /* Window bit 3 position. */

/* WDT.STATUS  bit masks and bit positions */
#define WDT_SYNCBUSY_bm  0x01  /* Syncronization busy bit mask. */
#define WDT_SYNCBUSY_bp  0  /* Syncronization busy bit position. */
#define WDT_LOCK_bm  0x80  /* Lock enable bit mask. */
#define WDT_LOCK_bp  7  /* Lock enable bit position. */


/* WEX - Waveform Extension */
/* WEX.CTRLA  bit masks and bit positions */
#define WEX_DTI0EN_bm  0x01  /* Dead-Time Insertion CMP0 Enable bit mask. */
#define WEX_DTI0EN_bp  0  /* Dead-Time Insertion CMP0 Enable bit position. */
#define WEX_DTI1EN_bm  0x02  /* Dead-Time Insertion CMP1 Enable bit mask. */
#define WEX_DTI1EN_bp  1  /* Dead-Time Insertion CMP1 Enable bit position. */
#define WEX_DTI2EN_bm  0x04  /* Dead-Time Insertion CMP2 Enable bit mask. */
#define WEX_DTI2EN_bp  2  /* Dead-Time Insertion CMP2 Enable bit position. */
#define WEX_DTI3EN_bm  0x08  /* Dead-Time Insertion CMP3 Enable bit mask. */
#define WEX_DTI3EN_bp  3  /* Dead-Time Insertion CMP3 Enable bit position. */
#define WEX_INMX_gm  0x70  /* Input Matrix group mask. */
#define WEX_INMX_gp  4  /* Input Matrix group position. */
#define WEX_INMX_0_bm  (1<<4)  /* Input Matrix bit 0 mask. */
#define WEX_INMX_0_bp  4  /* Input Matrix bit 0 position. */
#define WEX_INMX_1_bm  (1<<5)  /* Input Matrix bit 1 mask. */
#define WEX_INMX_1_bp  5  /* Input Matrix bit 1 position. */
#define WEX_INMX_2_bm  (1<<6)  /* Input Matrix bit 2 mask. */
#define WEX_INMX_2_bp  6  /* Input Matrix bit 2 position. */
#define WEX_PGM_bm  0x80  /* Pattern Generation Mode bit mask. */
#define WEX_PGM_bp  7  /* Pattern Generation Mode bit position. */

/* WEX.CTRLB  bit masks and bit positions */
#define WEX_UPDSRC_gm  0x03  /* Update Source group mask. */
#define WEX_UPDSRC_gp  0  /* Update Source group position. */
#define WEX_UPDSRC_0_bm  (1<<0)  /* Update Source bit 0 mask. */
#define WEX_UPDSRC_0_bp  0  /* Update Source bit 0 position. */
#define WEX_UPDSRC_1_bm  (1<<1)  /* Update Source bit 1 mask. */
#define WEX_UPDSRC_1_bp  1  /* Update Source bit 1 position. */

/* WEX.CTRLC  bit masks and bit positions */
#define WEX_CMD_gm  0x07  /* Command group mask. */
#define WEX_CMD_gp  0  /* Command group position. */
#define WEX_CMD_0_bm  (1<<0)  /* Command bit 0 mask. */
#define WEX_CMD_0_bp  0  /* Command bit 0 position. */
#define WEX_CMD_1_bm  (1<<1)  /* Command bit 1 mask. */
#define WEX_CMD_1_bp  1  /* Command bit 1 position. */
#define WEX_CMD_2_bm  (1<<2)  /* Command bit 2 mask. */
#define WEX_CMD_2_bp  2  /* Command bit 2 position. */

/* WEX.EVCTRLA  bit masks and bit positions */
#define WEX_FAULTEI_bm  0x01  /* Fault Event Input Enable bit mask. */
#define WEX_FAULTEI_bp  0  /* Fault Event Input Enable bit position. */
#define WEX_BLANK_bm  0x02  /* Fault Event Blanking Enable bit mask. */
#define WEX_BLANK_bp  1  /* Fault Event Blanking Enable bit position. */
#define WEX_FILTER_gm  0x1C  /* Fault Event Filter Enable group mask. */
#define WEX_FILTER_gp  2  /* Fault Event Filter Enable group position. */
#define WEX_FILTER_0_bm  (1<<2)  /* Fault Event Filter Enable bit 0 mask. */
#define WEX_FILTER_0_bp  2  /* Fault Event Filter Enable bit 0 position. */
#define WEX_FILTER_1_bm  (1<<3)  /* Fault Event Filter Enable bit 1 mask. */
#define WEX_FILTER_1_bp  3  /* Fault Event Filter Enable bit 1 position. */
#define WEX_FILTER_2_bm  (1<<4)  /* Fault Event Filter Enable bit 2 mask. */
#define WEX_FILTER_2_bp  4  /* Fault Event Filter Enable bit 2 position. */

/* WEX.EVCTRLB  bit masks and bit positions */
/* WEX_FAULTEI  is already defined. */
/* WEX_BLANK  is already defined. */
/* WEX_FILTER  is already defined. */

/* WEX.EVCTRLC  bit masks and bit positions */
/* WEX_FAULTEI  is already defined. */
/* WEX_BLANK  is already defined. */
/* WEX_FILTER  is already defined. */

/* WEX.BUFCTRL  bit masks and bit positions */
#define WEX_DTLSBV_bm  0x01  /* Dead-time Low Side Buffer Valid bit mask. */
#define WEX_DTLSBV_bp  0  /* Dead-time Low Side Buffer Valid bit position. */
#define WEX_DTHSBV_bm  0x02  /* Dead-time High Side Buffer Valid bit mask. */
#define WEX_DTHSBV_bp  1  /* Dead-time High Side Buffer Valid bit position. */
#define WEX_SWAPBV_bm  0x04  /* Swap Buffer Valid bit mask. */
#define WEX_SWAPBV_bp  2  /* Swap Buffer Valid bit position. */
#define WEX_PGMOVRBV_bm  0x08  /* PGM Override Buffer Valid bit mask. */
#define WEX_PGMOVRBV_bp  3  /* PGM Override Buffer Valid bit position. */
#define WEX_PGMOUTBV_bm  0x10  /* PGM Output Value Buffer Valid bit mask. */
#define WEX_PGMOUTBV_bp  4  /* PGM Output Value Buffer Valid bit position. */

/* WEX.BLANKCTRL  bit masks and bit positions */
#define WEX_BLANKSRC_bm  0x01  /* Blanking Trigger Source bit mask. */
#define WEX_BLANKSRC_bp  0  /* Blanking Trigger Source bit position. */
#define WEX_BLANKTRIG_gm  0x1C  /* Blanking Trigger group mask. */
#define WEX_BLANKTRIG_gp  2  /* Blanking Trigger group position. */
#define WEX_BLANKTRIG_0_bm  (1<<2)  /* Blanking Trigger bit 0 mask. */
#define WEX_BLANKTRIG_0_bp  2  /* Blanking Trigger bit 0 position. */
#define WEX_BLANKTRIG_1_bm  (1<<3)  /* Blanking Trigger bit 1 mask. */
#define WEX_BLANKTRIG_1_bp  3  /* Blanking Trigger bit 1 position. */
#define WEX_BLANKTRIG_2_bm  (1<<4)  /* Blanking Trigger bit 2 mask. */
#define WEX_BLANKTRIG_2_bp  4  /* Blanking Trigger bit 2 position. */
#define WEX_BLANKPRESC_gm  0x60  /* Blanking Prescaler group mask. */
#define WEX_BLANKPRESC_gp  5  /* Blanking Prescaler group position. */
#define WEX_BLANKPRESC_0_bm  (1<<5)  /* Blanking Prescaler bit 0 mask. */
#define WEX_BLANKPRESC_0_bp  5  /* Blanking Prescaler bit 0 position. */
#define WEX_BLANKPRESC_1_bm  (1<<6)  /* Blanking Prescaler bit 1 mask. */
#define WEX_BLANKPRESC_1_bp  6  /* Blanking Prescaler bit 1 position. */

/* WEX.FAULTCTRL  bit masks and bit positions */
#define WEX_FDACT_gm  0x03  /* Fault Detection Action group mask. */
#define WEX_FDACT_gp  0  /* Fault Detection Action group position. */
#define WEX_FDACT_0_bm  (1<<0)  /* Fault Detection Action bit 0 mask. */
#define WEX_FDACT_0_bp  0  /* Fault Detection Action bit 0 position. */
#define WEX_FDACT_1_bm  (1<<1)  /* Fault Detection Action bit 1 mask. */
#define WEX_FDACT_1_bp  1  /* Fault Detection Action bit 1 position. */
#define WEX_FDMODE_bm  0x04  /* Fault Detection Restart Mode bit mask. */
#define WEX_FDMODE_bp  2  /* Fault Detection Restart Mode bit position. */
#define WEX_FDDBD_bm  0x80  /* Fault Detection on Debug Break Detection bit mask. */
#define WEX_FDDBD_bp  7  /* Fault Detection on Debug Break Detection bit position. */

/* WEX.FAULTDRV  bit masks and bit positions */
#define WEX_FAULTDRV0_bm  0x01  /* Fault Drive Enable Bit 0 bit mask. */
#define WEX_FAULTDRV0_bp  0  /* Fault Drive Enable Bit 0 bit position. */
#define WEX_FAULTDRV1_bm  0x02  /* Fault Drive Enable Bit 1 bit mask. */
#define WEX_FAULTDRV1_bp  1  /* Fault Drive Enable Bit 1 bit position. */
#define WEX_FAULTDRV2_bm  0x04  /* Fault Drive Enable Bit 2 bit mask. */
#define WEX_FAULTDRV2_bp  2  /* Fault Drive Enable Bit 2 bit position. */
#define WEX_FAULTDRV3_bm  0x08  /* Fault Drive Enable Bit 3 bit mask. */
#define WEX_FAULTDRV3_bp  3  /* Fault Drive Enable Bit 3 bit position. */
#define WEX_FAULTDRV4_bm  0x10  /* Fault Drive Enable Bit 4 bit mask. */
#define WEX_FAULTDRV4_bp  4  /* Fault Drive Enable Bit 4 bit position. */
#define WEX_FAULTDRV5_bm  0x20  /* Fault Drive Enable Bit 5 bit mask. */
#define WEX_FAULTDRV5_bp  5  /* Fault Drive Enable Bit 5 bit position. */
#define WEX_FAULTDRV6_bm  0x40  /* Fault Drive Enable Bit 6 bit mask. */
#define WEX_FAULTDRV6_bp  6  /* Fault Drive Enable Bit 6 bit position. */
#define WEX_FAULTDRV7_bm  0x80  /* Fault Drive Enable Bit 7 bit mask. */
#define WEX_FAULTDRV7_bp  7  /* Fault Drive Enable Bit 7 bit position. */

/* WEX.FAULTOUT  bit masks and bit positions */
#define WEX_FAULTOUT0_bm  0x01  /* Fault Output Value Bit 0 bit mask. */
#define WEX_FAULTOUT0_bp  0  /* Fault Output Value Bit 0 bit position. */
#define WEX_FAULTOUT1_bm  0x02  /* Fault Output Value Bit 1 bit mask. */
#define WEX_FAULTOUT1_bp  1  /* Fault Output Value Bit 1 bit position. */
#define WEX_FAULTOUT2_bm  0x04  /* Fault Output Value Bit 2 bit mask. */
#define WEX_FAULTOUT2_bp  2  /* Fault Output Value Bit 2 bit position. */
#define WEX_FAULTOUT3_bm  0x08  /* Fault Output Value Bit 3 bit mask. */
#define WEX_FAULTOUT3_bp  3  /* Fault Output Value Bit 3 bit position. */
#define WEX_FAULTOUT4_bm  0x10  /* Fault Output Value Bit 4 bit mask. */
#define WEX_FAULTOUT4_bp  4  /* Fault Output Value Bit 4 bit position. */
#define WEX_FAULTOUT5_bm  0x20  /* Fault Output Value Bit 5 bit mask. */
#define WEX_FAULTOUT5_bp  5  /* Fault Output Value Bit 5 bit position. */
#define WEX_FAULTOUT6_bm  0x40  /* Fault Output Value Bit 6 bit mask. */
#define WEX_FAULTOUT6_bp  6  /* Fault Output Value Bit 6 bit position. */
#define WEX_FAULTOUT7_bm  0x80  /* Fault Output Value Bit 7 bit mask. */
#define WEX_FAULTOUT7_bp  7  /* Fault Output Value Bit 7 bit position. */

/* WEX.INTCTRL  bit masks and bit positions */
#define WEX_FAULTDET_bm  0x01  /* Fault Detection Interrupt Enable bit mask. */
#define WEX_FAULTDET_bp  0  /* Fault Detection Interrupt Enable bit position. */

/* WEX.INTFLAGS  bit masks and bit positions */
/* WEX_FAULTDET  is already defined. */
#define WEX_FDFEVA_bm  0x04  /* Fault Detection Flag Event Input A bit mask. */
#define WEX_FDFEVA_bp  2  /* Fault Detection Flag Event Input A bit position. */
#define WEX_FDFEVB_bm  0x08  /* Fault Detection Flag Event Input B bit mask. */
#define WEX_FDFEVB_bp  3  /* Fault Detection Flag Event Input B bit position. */
#define WEX_FDFEVC_bm  0x10  /* Fault Detection Flag Event Input C bit mask. */
#define WEX_FDFEVC_bp  4  /* Fault Detection Flag Event Input C bit position. */

/* WEX.STATUS  bit masks and bit positions */
#define WEX_FDSTATE_bm  0x01  /* Fault Detection State bit mask. */
#define WEX_FDSTATE_bp  0  /* Fault Detection State bit position. */
#define WEX_FDSEVA_bm  0x04  /* Fault Detection State Event A bit mask. */
#define WEX_FDSEVA_bp  2  /* Fault Detection State Event A bit position. */
#define WEX_FDSEVB_bm  0x08  /* Fault Detection State Event B bit mask. */
#define WEX_FDSEVB_bp  3  /* Fault Detection State Event B bit position. */
#define WEX_FDSEVC_bm  0x10  /* Fault Detection State Event C bit mask. */
#define WEX_FDSEVC_bp  4  /* Fault Detection State Event C bit position. */
#define WEX_BLANKSTATE_bm  0x80  /* Blanking State bit mask. */
#define WEX_BLANKSTATE_bp  7  /* Blanking State bit position. */

/* WEX.SWAP  bit masks and bit positions */
#define WEX_SWAP_gm  0x0F  /* Swap DTI Output Pairs group mask. */
#define WEX_SWAP_gp  0  /* Swap DTI Output Pairs group position. */
#define WEX_SWAP_0_bm  (1<<0)  /* Swap DTI Output Pairs bit 0 mask. */
#define WEX_SWAP_0_bp  0  /* Swap DTI Output Pairs bit 0 position. */
#define WEX_SWAP_1_bm  (1<<1)  /* Swap DTI Output Pairs bit 1 mask. */
#define WEX_SWAP_1_bp  1  /* Swap DTI Output Pairs bit 1 position. */
#define WEX_SWAP_2_bm  (1<<2)  /* Swap DTI Output Pairs bit 2 mask. */
#define WEX_SWAP_2_bp  2  /* Swap DTI Output Pairs bit 2 position. */
#define WEX_SWAP_3_bm  (1<<3)  /* Swap DTI Output Pairs bit 3 mask. */
#define WEX_SWAP_3_bp  3  /* Swap DTI Output Pairs bit 3 position. */

/* WEX.PGMOVR  bit masks and bit positions */
#define WEX_PGMOVR0_bm  0x01  /* Pattern Generation Override Enable Bit 0 bit mask. */
#define WEX_PGMOVR0_bp  0  /* Pattern Generation Override Enable Bit 0 bit position. */
#define WEX_PGMOVR1_bm  0x02  /* Pattern Generation Override Enable Bit 1 bit mask. */
#define WEX_PGMOVR1_bp  1  /* Pattern Generation Override Enable Bit 1 bit position. */
#define WEX_PGMOVR2_bm  0x04  /* Pattern Generation Override Enable Bit 2 bit mask. */
#define WEX_PGMOVR2_bp  2  /* Pattern Generation Override Enable Bit 2 bit position. */
#define WEX_PGMOVR3_bm  0x08  /* Pattern Generation Override Enable Bit 3 bit mask. */
#define WEX_PGMOVR3_bp  3  /* Pattern Generation Override Enable Bit 3 bit position. */
#define WEX_PGMOVR4_bm  0x10  /* Pattern Generation Override Enable Bit 4 bit mask. */
#define WEX_PGMOVR4_bp  4  /* Pattern Generation Override Enable Bit 4 bit position. */
#define WEX_PGMOVR5_bm  0x20  /* Pattern Generation Override Enable Bit 5 bit mask. */
#define WEX_PGMOVR5_bp  5  /* Pattern Generation Override Enable Bit 5 bit position. */
#define WEX_PGMOVR6_bm  0x40  /* Pattern Generation Override Enable Bit 6 bit mask. */
#define WEX_PGMOVR6_bp  6  /* Pattern Generation Override Enable Bit 6 bit position. */
#define WEX_PGMOVR7_bm  0x80  /* Pattern Generation Override Enable Bit 7 bit mask. */
#define WEX_PGMOVR7_bp  7  /* Pattern Generation Override Enable Bit 7 bit position. */

/* WEX.PGMOUT  bit masks and bit positions */
#define WEX_PGMOUT0_bm  0x01  /* Pattern Generation Output Value Bit 0 bit mask. */
#define WEX_PGMOUT0_bp  0  /* Pattern Generation Output Value Bit 0 bit position. */
#define WEX_PGMOUT1_bm  0x02  /* Pattern Generation Output Value Bit 1 bit mask. */
#define WEX_PGMOUT1_bp  1  /* Pattern Generation Output Value Bit 1 bit position. */
#define WEX_PGMOUT2_bm  0x04  /* Pattern Generation Output Value Bit 2 bit mask. */
#define WEX_PGMOUT2_bp  2  /* Pattern Generation Output Value Bit 2 bit position. */
#define WEX_PGMOUT3_bm  0x08  /* Pattern Generation Output Value Bit 3 bit mask. */
#define WEX_PGMOUT3_bp  3  /* Pattern Generation Output Value Bit 3 bit position. */
#define WEX_PGMOUT4_bm  0x10  /* Pattern Generation Output Value Bit 4 bit mask. */
#define WEX_PGMOUT4_bp  4  /* Pattern Generation Output Value Bit 4 bit position. */
#define WEX_PGMOUT5_bm  0x20  /* Pattern Generation Output Value Bit 5 bit mask. */
#define WEX_PGMOUT5_bp  5  /* Pattern Generation Output Value Bit 5 bit position. */
#define WEX_PGMOUT6_bm  0x40  /* Pattern Generation Output Value Bit 6 bit mask. */
#define WEX_PGMOUT6_bp  6  /* Pattern Generation Output Value Bit 6 bit position. */
#define WEX_PGMOUT7_bm  0x80  /* Pattern Generation Output Value Bit 7 bit mask. */
#define WEX_PGMOUT7_bp  7  /* Pattern Generation Output Value Bit 7 bit position. */

/* WEX.OUTOVEN  bit masks and bit positions */
#define WEX_OUTOVEN_gm  0xFF  /* Output Override Enable group mask. */
#define WEX_OUTOVEN_gp  0  /* Output Override Enable group position. */
#define WEX_OUTOVEN_0_bm  (1<<0)  /* Output Override Enable bit 0 mask. */
#define WEX_OUTOVEN_0_bp  0  /* Output Override Enable bit 0 position. */
#define WEX_OUTOVEN_1_bm  (1<<1)  /* Output Override Enable bit 1 mask. */
#define WEX_OUTOVEN_1_bp  1  /* Output Override Enable bit 1 position. */
#define WEX_OUTOVEN_2_bm  (1<<2)  /* Output Override Enable bit 2 mask. */
#define WEX_OUTOVEN_2_bp  2  /* Output Override Enable bit 2 position. */
#define WEX_OUTOVEN_3_bm  (1<<3)  /* Output Override Enable bit 3 mask. */
#define WEX_OUTOVEN_3_bp  3  /* Output Override Enable bit 3 position. */
#define WEX_OUTOVEN_4_bm  (1<<4)  /* Output Override Enable bit 4 mask. */
#define WEX_OUTOVEN_4_bp  4  /* Output Override Enable bit 4 position. */
#define WEX_OUTOVEN_5_bm  (1<<5)  /* Output Override Enable bit 5 mask. */
#define WEX_OUTOVEN_5_bp  5  /* Output Override Enable bit 5 position. */
#define WEX_OUTOVEN_6_bm  (1<<6)  /* Output Override Enable bit 6 mask. */
#define WEX_OUTOVEN_6_bp  6  /* Output Override Enable bit 6 position. */
#define WEX_OUTOVEN_7_bm  (1<<7)  /* Output Override Enable bit 7 mask. */
#define WEX_OUTOVEN_7_bp  7  /* Output Override Enable bit 7 position. */

/* WEX.SWAPBUF  bit masks and bit positions */
#define WEX_SWAPBUF_gm  0x0F  /* Swap DTI Output Pairs Buffer group mask. */
#define WEX_SWAPBUF_gp  0  /* Swap DTI Output Pairs Buffer group position. */
#define WEX_SWAPBUF_0_bm  (1<<0)  /* Swap DTI Output Pairs Buffer bit 0 mask. */
#define WEX_SWAPBUF_0_bp  0  /* Swap DTI Output Pairs Buffer bit 0 position. */
#define WEX_SWAPBUF_1_bm  (1<<1)  /* Swap DTI Output Pairs Buffer bit 1 mask. */
#define WEX_SWAPBUF_1_bp  1  /* Swap DTI Output Pairs Buffer bit 1 position. */
#define WEX_SWAPBUF_2_bm  (1<<2)  /* Swap DTI Output Pairs Buffer bit 2 mask. */
#define WEX_SWAPBUF_2_bp  2  /* Swap DTI Output Pairs Buffer bit 2 position. */
#define WEX_SWAPBUF_3_bm  (1<<3)  /* Swap DTI Output Pairs Buffer bit 3 mask. */
#define WEX_SWAPBUF_3_bp  3  /* Swap DTI Output Pairs Buffer bit 3 position. */

/* WEX.PGMOVRBUF  bit masks and bit positions */
#define WEX_PGMOVRBUF0_bm  0x01  /* Pattern Generation Override Enable Buffer Bit 0 bit mask. */
#define WEX_PGMOVRBUF0_bp  0  /* Pattern Generation Override Enable Buffer Bit 0 bit position. */
#define WEX_PGMOVRBUF1_bm  0x02  /* Pattern Generation Override Enable Buffer Bit 1 bit mask. */
#define WEX_PGMOVRBUF1_bp  1  /* Pattern Generation Override Enable Buffer Bit 1 bit position. */
#define WEX_PGMOVRBUF2_bm  0x04  /* Pattern Generation Override Enable Buffer Bit 2 bit mask. */
#define WEX_PGMOVRBUF2_bp  2  /* Pattern Generation Override Enable Buffer Bit 2 bit position. */
#define WEX_PGMOVRBUF3_bm  0x08  /* Pattern Generation Override Enable Buffer Bit 3 bit mask. */
#define WEX_PGMOVRBUF3_bp  3  /* Pattern Generation Override Enable Buffer Bit 3 bit position. */
#define WEX_PGMOVRBUF4_bm  0x10  /* Pattern Generation Override Enable Buffer Bit 4 bit mask. */
#define WEX_PGMOVRBUF4_bp  4  /* Pattern Generation Override Enable Buffer Bit 4 bit position. */
#define WEX_PGMOVRBUF5_bm  0x20  /* Pattern Generation Override Enable Buffer Bit 5 bit mask. */
#define WEX_PGMOVRBUF5_bp  5  /* Pattern Generation Override Enable Buffer Bit 5 bit position. */
#define WEX_PGMOVRBUF6_bm  0x40  /* Pattern Generation Override Enable Buffer Bit 6 bit mask. */
#define WEX_PGMOVRBUF6_bp  6  /* Pattern Generation Override Enable Buffer Bit 6 bit position. */
#define WEX_PGMOVRBUF7_bm  0x80  /* Pattern Generation Override Enable Buffer Bit 7 bit mask. */
#define WEX_PGMOVRBUF7_bp  7  /* Pattern Generation Override Enable Buffer Bit 7 bit position. */

/* WEX.PGMOUTBUF  bit masks and bit positions */
#define WEX_PGMOUTBUF0_bm  0x01  /* Pattern Generation Output Value Buffer Bit 0 bit mask. */
#define WEX_PGMOUTBUF0_bp  0  /* Pattern Generation Output Value Buffer Bit 0 bit position. */
#define WEX_PGMOUTBUF1_bm  0x02  /* Pattern Generation Output Value Buffer Bit 1 bit mask. */
#define WEX_PGMOUTBUF1_bp  1  /* Pattern Generation Output Value Buffer Bit 1 bit position. */
#define WEX_PGMOUTBUF2_bm  0x04  /* Pattern Generation Output Value Buffer Bit 2 bit mask. */
#define WEX_PGMOUTBUF2_bp  2  /* Pattern Generation Output Value Buffer Bit 2 bit position. */
#define WEX_PGMOUTBUF3_bm  0x08  /* Pattern Generation Output Value Buffer Bit 3 bit mask. */
#define WEX_PGMOUTBUF3_bp  3  /* Pattern Generation Output Value Buffer Bit 3 bit position. */
#define WEX_PGMOUTBUF4_bm  0x10  /* Pattern Generation Output Value Buffer Bit 4 bit mask. */
#define WEX_PGMOUTBUF4_bp  4  /* Pattern Generation Output Value Buffer Bit 4 bit position. */
#define WEX_PGMOUTBUF5_bm  0x20  /* Pattern Generation Output Value Buffer Bit 5 bit mask. */
#define WEX_PGMOUTBUF5_bp  5  /* Pattern Generation Output Value Buffer Bit 5 bit position. */
#define WEX_PGMOUTBUF6_bm  0x40  /* Pattern Generation Output Value Buffer Bit 6 bit mask. */
#define WEX_PGMOUTBUF6_bp  6  /* Pattern Generation Output Value Buffer Bit 6 bit position. */
#define WEX_PGMOUTBUF7_bm  0x80  /* Pattern Generation Output Value Buffer Bit 7 bit mask. */
#define WEX_PGMOUTBUF7_bp  7  /* Pattern Generation Output Value Buffer Bit 7 bit position. */


/* ========== Generic Port Pins ========== */
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

/* NMI interrupt vectors */
#define NMI_vect_num  1
#define NMI_vect      _VECTOR(1)  /*  */

/* RTC interrupt vectors */
#define RTC_CNT_vect_num  3
#define RTC_CNT_vect      _VECTOR(3)  /*  */
#define RTC_PIT_vect_num  4
#define RTC_PIT_vect      _VECTOR(4)  /*  */

/* CCL interrupt vectors */
#define CCL_CCL_vect_num  5
#define CCL_CCL_vect      _VECTOR(5)  /*  */

/* PORTA interrupt vectors */
#define PORTA_PORT_vect_num  6
#define PORTA_PORT_vect      _VECTOR(6)  /*  */

/* WEX0 interrupt vectors */
#define WEX0_FAULT_vect_num  7
#define WEX0_FAULT_vect      _VECTOR(7)  /*  */

/* TCE0 interrupt vectors */
#define TCE0_OVF_vect_num  8
#define TCE0_OVF_vect      _VECTOR(8)  /*  */
#define TCE0_CMP0_vect_num  9
#define TCE0_CMP0_vect      _VECTOR(9)  /*  */
#define TCE0_CMP1_vect_num  10
#define TCE0_CMP1_vect      _VECTOR(10)  /*  */
#define TCE0_CMP2_vect_num  11
#define TCE0_CMP2_vect      _VECTOR(11)  /*  */
#define TCE0_CMP3_vect_num  12
#define TCE0_CMP3_vect      _VECTOR(12)  /*  */

/* TCB0 interrupt vectors */
#define TCB0_INT_vect_num  13
#define TCB0_INT_vect      _VECTOR(13)  /*  */

/* TCB1 interrupt vectors */
#define TCB1_INT_vect_num  14
#define TCB1_INT_vect      _VECTOR(14)  /*  */

/* TWI0 interrupt vectors */
#define TWI0_TWIS_vect_num  15
#define TWI0_TWIS_vect      _VECTOR(15)  /*  */
#define TWI0_TWIM_vect_num  16
#define TWI0_TWIM_vect      _VECTOR(16)  /*  */

/* SPI0 interrupt vectors */
#define SPI0_INT_vect_num  17
#define SPI0_INT_vect      _VECTOR(17)  /*  */

/* USART0 interrupt vectors */
#define USART0_RXC_vect_num  18
#define USART0_RXC_vect      _VECTOR(18)  /*  */
#define USART0_DRE_vect_num  19
#define USART0_DRE_vect      _VECTOR(19)  /*  */
#define USART0_TXC_vect_num  20
#define USART0_TXC_vect      _VECTOR(20)  /*  */

/* PORTD interrupt vectors */
#define PORTD_PORT_vect_num  21
#define PORTD_PORT_vect      _VECTOR(21)  /*  */

/* TCF0 interrupt vectors */
#define TCF0_INT_vect_num  22
#define TCF0_INT_vect      _VECTOR(22)  /*  */

/* AC0 interrupt vectors */
#define AC0_AC_vect_num  23
#define AC0_AC_vect      _VECTOR(23)  /*  */

/* AC1 interrupt vectors */
#define AC1_AC_vect_num  27
#define AC1_AC_vect      _VECTOR(27)  /*  */

/* PORTC interrupt vectors */
#define PORTC_PORT_vect_num  28
#define PORTC_PORT_vect      _VECTOR(28)  /*  */

/* PORTF interrupt vectors */
#define PORTF_PORT_vect_num  29
#define PORTF_PORT_vect      _VECTOR(29)  /*  */

/* NVMCTRL interrupt vectors */
#define NVMCTRL_READY_vect_num  30
#define NVMCTRL_READY_vect      _VECTOR(30)  /*  */

/* FPGA interrupt vectors */
#define FPGA_FIM_vect_num  31
#define FPGA_FIM_vect      _VECTOR(31)  /*  */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (32 * _VECTOR_SIZE)


/* ========== Constants ========== */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define DATAMEM_START     (0x0000)
#  define DATAMEM_SIZE      (131072)
#else
#  define DATAMEM_START     (0x0000U)
#  define DATAMEM_SIZE      (131072U)
#endif
#define DATAMEM_END       (DATAMEM_START + DATAMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define IO_START     (0x0000)
#  define IO_SIZE      (4159)
#  define IO_PAGE_SIZE (0)
#else
#  define IO_START     (0x0000U)
#  define IO_SIZE      (4159U)
#  define IO_PAGE_SIZE (0U)
#endif
#define IO_END       (IO_START + IO_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define LOCKBITS_START     (0x1040)
#  define LOCKBITS_SIZE      (4)
#  define LOCKBITS_PAGE_SIZE (1)
#else
#  define LOCKBITS_START     (0x1040U)
#  define LOCKBITS_SIZE      (4U)
#  define LOCKBITS_PAGE_SIZE (1U)
#endif
#define LOCKBITS_END       (LOCKBITS_START + LOCKBITS_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define FUSES_START     (0x1050)
#  define FUSES_SIZE      (16)
#  define FUSES_PAGE_SIZE (1)
#else
#  define FUSES_START     (0x1050U)
#  define FUSES_SIZE      (16U)
#  define FUSES_PAGE_SIZE (1U)
#endif
#define FUSES_END       (FUSES_START + FUSES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SIGNATURES_START     (0x1080)
#  define SIGNATURES_SIZE      (3)
#  define SIGNATURES_PAGE_SIZE (128)
#else
#  define SIGNATURES_START     (0x1080U)
#  define SIGNATURES_SIZE      (3U)
#  define SIGNATURES_PAGE_SIZE (128U)
#endif
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROD_SIGNATURES_START     (0x1083)
#  define PROD_SIGNATURES_SIZE      (125)
#  define PROD_SIGNATURES_PAGE_SIZE (128)
#else
#  define PROD_SIGNATURES_START     (0x1083U)
#  define PROD_SIGNATURES_SIZE      (125U)
#  define PROD_SIGNATURES_PAGE_SIZE (128U)
#endif
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define USER_SIGNATURES_START     (0x1200)
#  define USER_SIGNATURES_SIZE      (32)
#  define USER_SIGNATURES_PAGE_SIZE (32)
#else
#  define USER_SIGNATURES_START     (0x1200U)
#  define USER_SIGNATURES_SIZE      (32U)
#  define USER_SIGNATURES_PAGE_SIZE (32U)
#endif
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define EEPROM_START     (0x1400)
#  define EEPROM_SIZE      (512)
#  define EEPROM_PAGE_SIZE (1)
#else
#  define EEPROM_START     (0x1400U)
#  define EEPROM_SIZE      (512U)
#  define EEPROM_PAGE_SIZE (1U)
#endif
#define EEPROM_END       (EEPROM_START + EEPROM_SIZE - 1)

/* Added MAPPED_EEPROM segment names for avr-libc */
#define MAPPED_EEPROM_START     (EEPROM_START)
#define MAPPED_EEPROM_SIZE      (EEPROM_SIZE)
#define MAPPED_EEPROM_PAGE_SIZE (EEPROM_PAGE_SIZE)
#define MAPPED_EEPROM_END       (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define VGA_START     (0x2000)
#  define VGA_SIZE      (4096)
#  define VGA_PAGE_SIZE (0)
#else
#  define VGA_START     (0x2000U)
#  define VGA_SIZE      (4096U)
#  define VGA_PAGE_SIZE (0U)
#endif
#define VGA_END       (VGA_START + VGA_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define INTERNAL_SRAM_START     (0x4000)
#  define INTERNAL_SRAM_SIZE      (16384)
#  define INTERNAL_SRAM_PAGE_SIZE (0)
#else
#  define INTERNAL_SRAM_START     (0x4000U)
#  define INTERNAL_SRAM_SIZE      (16384U)
#  define INTERNAL_SRAM_PAGE_SIZE (0U)
#endif
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define MAPPED_PROGMEM_START     (0x8000)
#  define MAPPED_PROGMEM_SIZE      (32768)
#  define MAPPED_PROGMEM_PAGE_SIZE (512)
#else
#  define MAPPED_PROGMEM_START     (0x8000U)
#  define MAPPED_PROGMEM_SIZE      (32768U)
#  define MAPPED_PROGMEM_PAGE_SIZE (512U)
#endif
#define MAPPED_PROGMEM_END       (MAPPED_PROGMEM_START + MAPPED_PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_START     (0x0000)
#  define PROGMEM_SIZE      (131072)
#  define PROGMEM_PAGE_SIZE (512)
#else
#  define PROGMEM_START     (0x0000U)
#  define PROGMEM_SIZE      (131072U)
#  define PROGMEM_PAGE_SIZE (512U)
#endif
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END
#define E2END        EEPROM_END
#define E2PAGESIZE   EEPROM_PAGE_SIZE

/* ========== Fuses ========== */
#define FUSE_MEMORY_SIZE 16

/* Fuse Byte 0 (WDTCFG) */
#define FUSE_PERIOD0  (unsigned char)_BV(0)  /* Watchdog Timeout Period Bit 0 */
#define FUSE_PERIOD1  (unsigned char)_BV(1)  /* Watchdog Timeout Period Bit 1 */
#define FUSE_PERIOD2  (unsigned char)_BV(2)  /* Watchdog Timeout Period Bit 2 */
#define FUSE_PERIOD3  (unsigned char)_BV(3)  /* Watchdog Timeout Period Bit 3 */
#define FUSE_WINDOW0  (unsigned char)_BV(4)  /* Watchdog Window Timeout Period Bit 0 */
#define FUSE_WINDOW1  (unsigned char)_BV(5)  /* Watchdog Window Timeout Period Bit 1 */
#define FUSE_WINDOW2  (unsigned char)_BV(6)  /* Watchdog Window Timeout Period Bit 2 */
#define FUSE_WINDOW3  (unsigned char)_BV(7)  /* Watchdog Window Timeout Period Bit 3 */
#define FUSE0_DEFAULT  (0x0)
#define FUSE_WDTCFG_DEFAULT  (0x0)

/* Fuse Byte 1 (BODCFG) */
#define FUSE_SLEEP0  (unsigned char)_BV(0)  /* BOD Operation in Sleep Mode Bit 0 */
#define FUSE_SLEEP1  (unsigned char)_BV(1)  /* BOD Operation in Sleep Mode Bit 1 */
#define FUSE_ACTIVE0  (unsigned char)_BV(2)  /* BOD Operation in Active Mode Bit 0 */
#define FUSE_ACTIVE1  (unsigned char)_BV(3)  /* BOD Operation in Active Mode Bit 1 */
#define FUSE_SAMPFREQ  (unsigned char)_BV(4)  /* BOD Sample Frequency */
#define FUSE_LVL0  (unsigned char)_BV(5)  /* BOD Level Bit 0 */
#define FUSE_LVL1  (unsigned char)_BV(6)  /* BOD Level Bit 1 */
#define FUSE_LVL2  (unsigned char)_BV(7)  /* BOD Level Bit 2 */
#define FUSE1_DEFAULT  (0x0)
#define FUSE_BODCFG_DEFAULT  (0x0)

/* Fuse Byte 2 (OSCCFG) */
#define FUSE_CLKSEL0  (unsigned char)_BV(0)  /* Frequency Select Bit 0 */
#define FUSE_CLKSEL1  (unsigned char)_BV(1)  /* Frequency Select Bit 1 */
#define FUSE_CLKSEL2  (unsigned char)_BV(2)  /* Frequency Select Bit 2 */
#define FUSE_OSCLOCK  (unsigned char)_BV(7)  /* Oscillator Lock */
#define FUSE2_DEFAULT  (0x0)
#define FUSE_OSCCFG_DEFAULT  (0x0)

/* Fuse Byte 3 Reserved */

/* Fuse Byte 4 Reserved */

/* Fuse Byte 5 (SYSCFG0) */
#define FUSE_EESAVE  (unsigned char)_BV(0)  /* EEPROM Save */
#define FUSE_RSTPINCFG0  (unsigned char)_BV(2)  /* Reset Pin Configuration Bit 0 */
#define FUSE_RSTPINCFG1  (unsigned char)_BV(3)  /* Reset Pin Configuration Bit 1 */
#define FUSE_CRCSEL  (unsigned char)_BV(5)  /* CRC Select */
#define FUSE_CRCSRC0  (unsigned char)_BV(6)  /* CRC Source Bit 0 */
#define FUSE_CRCSRC1  (unsigned char)_BV(7)  /* CRC Source Bit 1 */
#define FUSE5_DEFAULT  (0xC0)
#define FUSE_SYSCFG0_DEFAULT  (0xC0)

/* Fuse Byte 6 (SYSCFG1) */
#define FUSE_SUT0  (unsigned char)_BV(0)  /* Startup Time Bit 0 */
#define FUSE_SUT1  (unsigned char)_BV(1)  /* Startup Time Bit 1 */
#define FUSE_SUT2  (unsigned char)_BV(2)  /* Startup Time Bit 2 */
#define FUSE6_DEFAULT  (0x0)
#define FUSE_SYSCFG1_DEFAULT  (0x0)

/* Fuse Byte 7 (CODESIZE) */
#define FUSE7_DEFAULT  (0x0)
#define FUSE_CODESIZE_DEFAULT  (0x0)

/* Fuse Byte 8 (BOOTSIZE) */
#define FUSE8_DEFAULT  (0x0)
#define FUSE_BOOTSIZE_DEFAULT  (0x0)

/* ========== Lock Bits ========== */
#define __LOCK_BITS_EXIST
#ifdef LOCKBITS_DEFAULT
#undef LOCKBITS_DEFAULT
#endif //LOCKBITS_DEFAULT
#define LOCKBITS_DEFAULT  (0x5CC5C55C)

/* ========== Signature ========== */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x9F
#define SIGNATURE_2 0x01

#endif /* #ifdef _AVR_AVRFPGAV2_H_INCLUDED */

