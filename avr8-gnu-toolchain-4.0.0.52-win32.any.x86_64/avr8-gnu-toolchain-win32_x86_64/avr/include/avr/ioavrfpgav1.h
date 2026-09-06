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
#  define _AVR_IOXXX_H_ "ioavrfpgav1.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_AVRFPGAV1_H_INCLUDED
#define _AVR_AVRFPGAV1_H_INCLUDED

/* Ungrouped common registers */
#define CCP  _SFR_MEM8(0x0034)  /* Configuration Change Protection */
#define RAMPZ  _SFR_MEM8(0x003B)  /* Extended Z-pointer Register */
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
    register8_t reserved_1[1];
    register8_t DACREFL;  /* Reference scale control */
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
typedef enum AC_INTMODE_enum
{
    AC_INTMODE_ABOVE_gc = (0x00<<4),  /* Entering window state above */
    AC_INTMODE_INSIDE_gc = (0x01<<4),  /* Entering window state inside */
    AC_INTMODE_BELOW_gc = (0x02<<4),  /* Entering window state below */
    AC_INTMODE_OUTSIDE_gc = (0x03<<4)  /* Entering window state above or below */
} AC_INTMODE_t;

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
    AC_MUXPOS_AINP3_gc = (0x03<<3)  /* Positive Pin3 */
} AC_MUXPOS_t;

/* Power profile select */
typedef enum AC_POWER_enum
{
    AC_POWER_PROFILE0_gc = (0x00<<3),  /* Power profile 0, lowest consumption and highest response time. */
    AC_POWER_PROFILE1_gc = (0x01<<3),  /* Power profile 1 */
    AC_POWER_PROFILE2_gc = (0x02<<3),  /* Power profile 2 */
    AC_POWER_PROFILE3_gc = (0x03<<3)  /* Power profile 3 */
} AC_POWER_t;

/* Window selection mode */
typedef enum AC_WINSEL_enum
{
    AC_WINSEL_DISABLED_gc = (0x00<<0),  /* Window function disabled */
    AC_WINSEL_UPSEL1_gc = (0x01<<0),  /* Select ACn+1 as upper limit in window compare. */
    AC_WINSEL_UPSEL2_gc = (0x02<<0)  /* Select ACn+2 as upper limit in window compare. */
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
ADC - Analog to Digital Converter
--------------------------------------------------------------------------
*/

/* Analog to Digital Converter */
typedef struct ADC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLE;  /* Control E */
    register8_t SAMPCTRL;  /* Sample Control */
    register8_t reserved_1[2];
    register8_t MUXPOS;  /* Positive mux input */
    register8_t MUXNEG;  /* Negative mux input */
    register8_t COMMAND;  /* Command */
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t TEMP;  /* Temporary Data */
    _WORDREGISTER(RES);  /* ADC Accumulator Result */
    _WORDREGISTER(WINLT);  /* Window comparator low threshold */
    _WORDREGISTER(WINHT);  /* Window comparator high threshold */
    register8_t reserved_2[8];
    register8_t CAL;  /* Calibration */
} ADC_t;

/* Initial Delay Selection */
typedef enum ADC_INITDLY_enum
{
    ADC_INITDLY_DLY0_gc = (0x00<<5),  /* Delay 0 CLK_ADC cycles */
    ADC_INITDLY_DLY16_gc = (0x01<<5),  /* Delay 16 CLK_ADC cycles */
    ADC_INITDLY_DLY32_gc = (0x02<<5),  /* Delay 32 CLK_ADC cycles */
    ADC_INITDLY_DLY64_gc = (0x03<<5),  /* Delay 64 CLK_ADC cycles */
    ADC_INITDLY_DLY128_gc = (0x04<<5),  /* Delay 128 CLK_ADC cycles */
    ADC_INITDLY_DLY256_gc = (0x05<<5)  /* Delay 256 CLK_ADC cycles */
} ADC_INITDLY_t;

/* Analog Channel Selection Bits */
typedef enum ADC_MUXNEG_enum
{
    ADC_MUXNEG_AIN0_gc = (0x00<<0),  /* ADC input pin 0 */
    ADC_MUXNEG_AIN1_gc = (0x01<<0),  /* ADC input pin 1 */
    ADC_MUXNEG_AIN2_gc = (0x02<<0),  /* ADC input pin 2 */
    ADC_MUXNEG_AIN3_gc = (0x03<<0),  /* ADC input pin 3 */
    ADC_MUXNEG_AIN4_gc = (0x04<<0),  /* ADC input pin 4 */
    ADC_MUXNEG_AIN5_gc = (0x05<<0),  /* ADC input pin 5 */
    ADC_MUXNEG_AIN6_gc = (0x06<<0),  /* ADC input pin 6 */
    ADC_MUXNEG_AIN7_gc = (0x07<<0),  /* ADC input pin 7 */
    ADC_MUXNEG_AIN8_gc = (0x08<<0),  /* ADC input pin 8 */
    ADC_MUXNEG_AIN9_gc = (0x09<<0),  /* ADC input pin 9 */
    ADC_MUXNEG_AIN10_gc = (0x0A<<0),  /* ADC input pin 10 */
    ADC_MUXNEG_AIN11_gc = (0x0B<<0),  /* ADC input pin 11 */
    ADC_MUXNEG_AIN12_gc = (0x0C<<0),  /* ADC input pin 12 */
    ADC_MUXNEG_AIN13_gc = (0x0D<<0),  /* ADC input pin 13 */
    ADC_MUXNEG_AIN14_gc = (0x0E<<0),  /* ADC input pin 14 */
    ADC_MUXNEG_AIN15_gc = (0x0F<<0),  /* ADC input pin 15 */
    ADC_MUXNEG_GND_gc = (0x40<<0),  /* Ground */
    ADC_MUXNEG_DAC0_gc = (0x48<<0)  /* DAC0 */
} ADC_MUXNEG_t;

/* Analog Channel Selection Bits */
typedef enum ADC_MUXPOS_enum
{
    ADC_MUXPOS_AIN0_gc = (0x00<<0),  /* ADC input pin 0 */
    ADC_MUXPOS_AIN1_gc = (0x01<<0),  /* ADC input pin 1 */
    ADC_MUXPOS_AIN2_gc = (0x02<<0),  /* ADC input pin 2 */
    ADC_MUXPOS_AIN3_gc = (0x03<<0),  /* ADC input pin 3 */
    ADC_MUXPOS_AIN4_gc = (0x04<<0),  /* ADC input pin 4 */
    ADC_MUXPOS_AIN5_gc = (0x05<<0),  /* ADC input pin 5 */
    ADC_MUXPOS_AIN6_gc = (0x06<<0),  /* ADC input pin 6 */
    ADC_MUXPOS_AIN7_gc = (0x07<<0),  /* ADC input pin 7 */
    ADC_MUXPOS_AIN8_gc = (0x08<<0),  /* ADC input pin 8 */
    ADC_MUXPOS_AIN9_gc = (0x09<<0),  /* ADC input pin 9 */
    ADC_MUXPOS_AIN10_gc = (0x0A<<0),  /* ADC input pin 10 */
    ADC_MUXPOS_AIN11_gc = (0x0B<<0),  /* ADC input pin 11 */
    ADC_MUXPOS_AIN12_gc = (0x0C<<0),  /* ADC input pin 12 */
    ADC_MUXPOS_AIN13_gc = (0x0D<<0),  /* ADC input pin 13 */
    ADC_MUXPOS_AIN14_gc = (0x0E<<0),  /* ADC input pin 14 */
    ADC_MUXPOS_AIN15_gc = (0x0F<<0),  /* ADC input pin 15 */
    ADC_MUXPOS_AIN16_gc = (0x10<<0),  /* ADC input pin 16 */
    ADC_MUXPOS_AIN17_gc = (0x11<<0),  /* ADC input pin 17 */
    ADC_MUXPOS_AIN18_gc = (0x12<<0),  /* ADC input pin 18 */
    ADC_MUXPOS_AIN19_gc = (0x13<<0),  /* ADC input pin 19 */
    ADC_MUXPOS_AIN20_gc = (0x14<<0),  /* ADC input pin 20 */
    ADC_MUXPOS_AIN21_gc = (0x15<<0),  /* ADC input pin 21 */
    ADC_MUXPOS_GND_gc = (0x40<<0),  /* Ground */
    ADC_MUXPOS_TEMPSENSE_gc = (0x42<<0),  /* Temperature sensor */
    ADC_MUXPOS_DAC0_gc = (0x48<<0),  /* DAC0 */
    ADC_MUXPOS_DACREF0_gc = (0x49<<0),  /* DACREF0 */
    ADC_MUXPOS_DACREF1_gc = (0x4A<<0),  /* DACREF1 */
    ADC_MUXPOS_DACREF2_gc = (0x4B<<0)  /* DACREF2 */
} ADC_MUXPOS_t;

/* Clock Pre-scaler select */
typedef enum ADC_PRESC_enum
{
    ADC_PRESC_DIV2_gc = (0x00<<0),  /* CLK_PER divided by 2 */
    ADC_PRESC_DIV4_gc = (0x01<<0),  /* CLK_PER divided by 4 */
    ADC_PRESC_DIV8_gc = (0x02<<0),  /* CLK_PER divided by 8 */
    ADC_PRESC_DIV12_gc = (0x03<<0),  /* CLK_PER divided by 12 */
    ADC_PRESC_DIV16_gc = (0x04<<0),  /* CLK_PER divided by 16 */
    ADC_PRESC_DIV20_gc = (0x05<<0),  /* CLK_PER divided by 20 */
    ADC_PRESC_DIV24_gc = (0x06<<0),  /* CLK_PER divided by 24 */
    ADC_PRESC_DIV28_gc = (0x07<<0),  /* CLK_PER divided by 28 */
    ADC_PRESC_DIV32_gc = (0x08<<0),  /* CLK_PER divided by 32 */
    ADC_PRESC_DIV48_gc = (0x09<<0),  /* CLK_PER divided by 48 */
    ADC_PRESC_DIV64_gc = (0x0A<<0),  /* CLK_PER divided by 64 */
    ADC_PRESC_DIV96_gc = (0x0B<<0),  /* CLK_PER divided by 96 */
    ADC_PRESC_DIV128_gc = (0x0C<<0),  /* CLK_PER divided by 128 */
    ADC_PRESC_DIV256_gc = (0x0D<<0)  /* CLK_PER divided by 256 */
} ADC_PRESC_t;

/* Resolution selection */
typedef enum ADC_RESSEL_enum
{
    ADC_RESSEL_12BIT_gc = (0x00<<2),  /* 12-bit mode */
    ADC_RESSEL_10BIT_gc = (0x01<<2)  /* 10-bit mode */
} ADC_RESSEL_t;

/* Sampling Delay Selection */
typedef enum ADC_SAMPDLY_enum
{
    ADC_SAMPDLY_DLY0_gc = (0x00<<0),  /* Delay 0 CLK_ADC cycles */
    ADC_SAMPDLY_DLY1_gc = (0x01<<0),  /* Delay 1 CLK_ADC cycles */
    ADC_SAMPDLY_DLY2_gc = (0x02<<0),  /* Delay 2 CLK_ADC cycles */
    ADC_SAMPDLY_DLY3_gc = (0x03<<0),  /* Delay 3 CLK_ADC cycles */
    ADC_SAMPDLY_DLY4_gc = (0x04<<0),  /* Delay 4 CLK_ADC cycles */
    ADC_SAMPDLY_DLY5_gc = (0x05<<0),  /* Delay 5 CLK_ADC cycles */
    ADC_SAMPDLY_DLY6_gc = (0x06<<0),  /* Delay 6 CLK_ADC cycles */
    ADC_SAMPDLY_DLY7_gc = (0x07<<0),  /* Delay 7 CLK_ADC cycles */
    ADC_SAMPDLY_DLY8_gc = (0x08<<0),  /* Delay 8 CLK_ADC cycles */
    ADC_SAMPDLY_DLY9_gc = (0x09<<0),  /* Delay 9 CLK_ADC cycles */
    ADC_SAMPDLY_DLY10_gc = (0x0A<<0),  /* Delay 10 CLK_ADC cycles */
    ADC_SAMPDLY_DLY11_gc = (0x0B<<0),  /* Delay 11 CLK_ADC cycles */
    ADC_SAMPDLY_DLY12_gc = (0x0C<<0),  /* Delay 12 CLK_ADC cycles */
    ADC_SAMPDLY_DLY13_gc = (0x0D<<0),  /* Delay 13 CLK_ADC cycles */
    ADC_SAMPDLY_DLY14_gc = (0x0E<<0),  /* Delay 14 CLK_ADC cycles */
    ADC_SAMPDLY_DLY15_gc = (0x0F<<0)  /* Delay 15 CLK_ADC cycles */
} ADC_SAMPDLY_t;

/* Accumulation Samples select */
typedef enum ADC_SAMPNUM_enum
{
    ADC_SAMPNUM_NONE_gc = (0x00<<0),  /* No accumulation */
    ADC_SAMPNUM_ACC2_gc = (0x01<<0),  /* 2 results accumulated */
    ADC_SAMPNUM_ACC4_gc = (0x02<<0),  /* 4 results accumulated */
    ADC_SAMPNUM_ACC8_gc = (0x03<<0),  /* 8 results accumulated */
    ADC_SAMPNUM_ACC16_gc = (0x04<<0),  /* 16 results accumulated */
    ADC_SAMPNUM_ACC32_gc = (0x05<<0),  /* 32 results accumulated */
    ADC_SAMPNUM_ACC64_gc = (0x06<<0),  /* 64 results accumulated */
    ADC_SAMPNUM_ACC128_gc = (0x07<<0)  /* 128 results accumulated */
} ADC_SAMPNUM_t;

/* Window Comparator Mode select */
typedef enum ADC_WINCM_enum
{
    ADC_WINCM_NONE_gc = (0x00<<0),  /* No Window Comparison */
    ADC_WINCM_BELOW_gc = (0x01<<0),  /* Below Window */
    ADC_WINCM_ABOVE_gc = (0x02<<0),  /* Above Window */
    ADC_WINCM_INSIDE_gc = (0x03<<0),  /* Inside Window */
    ADC_WINCM_OUTSIDE_gc = (0x04<<0)  /* Outside Window */
} ADC_WINCM_t;

/*
--------------------------------------------------------------------------
BANDGAP - Bandgap
--------------------------------------------------------------------------
*/

/* Bandgap */
typedef struct BANDGAP_struct
{
    register8_t BGMCAL0;  /* Control */
    register8_t BGMCAL1;  /* Bandgap Main Calibration 1 */
    register8_t BGXCAL0;  /* Bandgap Auxiliary Calibration 0 */
    register8_t BGXCAL1;  /* Bandgap Auxiliary Calibration 1 */
    register8_t BGCFG0;  /* Bandgap cfg */
    register8_t TEST;  /* Temprature Calibration */
    register8_t STATUS;  /* Status */
} BANDGAP_t;

/* FORCE select */
typedef enum BANDGAP_FORCE_enum
{
    BANDGAP_FORCE_DEFAULT_gc = (0x00<<0),  /* Bandgap is controlled through request system */
    BANDGAP_FORCE_OFF_gc = (0x02<<0),  /* Force Bandgap OFF */
    BANDGAP_FORCE_ON_gc = (0x03<<0)  /* Force Bandgap ON */
} BANDGAP_FORCE_t;

/*
--------------------------------------------------------------------------
BOD - Bod interface
--------------------------------------------------------------------------
*/

/* Bod interface */
typedef struct BOD_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CALIB;  /* Calibration */
    register8_t TSTATUS;  /* Test status */
    register8_t TEST;  /* Test */
    register8_t reserved_1[3];
    register8_t VLMCTRLA;  /* Voltage level monitor Control */
    register8_t INTCTRL;  /* Voltage level monitor interrupt Control */
    register8_t INTFLAGS;  /* Voltage level monitor interrupt Flags */
    register8_t STATUS;  /* Voltage level monitor status */
    register8_t reserved_2[4];
} BOD_t;

/* Operation in active mode select */
typedef enum BOD_ACTIVE_enum
{
    BOD_ACTIVE_DIS_gc = (0x00<<2),  /* Disabled */
    BOD_ACTIVE_ENABLED_gc = (0x01<<2),  /* Enabled */
    BOD_ACTIVE_SAMPLED_gc = (0x02<<2),  /* Sampled */
    BOD_ACTIVE_ENWAKE_gc = (0x03<<2)  /* Enabled with wake-up halted until BOD is ready */
} BOD_ACTIVE_t;

/* Hysterises select */
typedef enum BOD_HYST_enum
{
    BOD_HYST_OFF_gc = (0x00<<3),  /* No hysteresis */
    BOD_HYST_SMALL_gc = (0x01<<3),  /* Small */
    BOD_HYST_MEDIUM_gc = (0x02<<3),  /* Medium */
    BOD_HYST_LARGE_gc = (0x03<<3)  /* Large */
} BOD_HYST_t;

/* Bod level select */
typedef enum BOD_LVL_enum
{
    BOD_LVL_BODLEVEL0_gc = (0x00<<0),  /* 1.9 V */
    BOD_LVL_BODLEVEL1_gc = (0x01<<0),  /* 2.45 V */
    BOD_LVL_BODLEVEL2_gc = (0x02<<0),  /* 2.7 V */
    BOD_LVL_BODLEVEL3_gc = (0x03<<0)  /* 2.85 V */
} BOD_LVL_t;

/* Sample frequency select */
typedef enum BOD_SAMPFREQ_enum
{
    BOD_SAMPFREQ_128HZ_gc = (0x00<<4),  /* 128Hz sampling frequency */
    BOD_SAMPFREQ_32HZ_gc = (0x01<<4)  /* 32Hz sampling frequency */
} BOD_SAMPFREQ_t;

/* Operation in sleep mode select */
typedef enum BOD_SLEEP_enum
{
    BOD_SLEEP_DIS_gc = (0x00<<0),  /* Disabled */
    BOD_SLEEP_ENABLED_gc = (0x01<<0),  /* Enabled */
    BOD_SLEEP_SAMPLED_gc = (0x02<<0)  /* Sampled */
} BOD_SLEEP_t;

/* Configuration select */
typedef enum BOD_VLMCFG_enum
{
    BOD_VLMCFG_FALLING_gc = (0x00<<1),  /* VDD falls below VLM threshold */
    BOD_VLMCFG_RISING_gc = (0x01<<1),  /* VDD rises above VLM threshold */
    BOD_VLMCFG_BOTH_gc = (0x02<<1)  /* VDD crosses VLM threshold */
} BOD_VLMCFG_t;

/* voltage level monitor level select */
typedef enum BOD_VLMLVL_enum
{
    BOD_VLMLVL_OFF_gc = (0x00<<0),  /* VLM Disabled */
    BOD_VLMLVL_5ABOVE_gc = (0x01<<0),  /* VLM threshold 5% above BOD level */
    BOD_VLMLVL_15ABOVE_gc = (0x02<<0),  /* VLM threshold 15% above BOD level */
    BOD_VLMLVL_25ABOVE_gc = (0x03<<0)  /* VLM threshold 25% above BOD level */
} BOD_VLMLVL_t;

/* Voltage level monitor status select */
typedef enum BOD_VLMS_enum
{
    BOD_VLMS_ABOVE_gc = (0x00<<0),  /* The voltage is above the VLM threshold level */
    BOD_VLMS_BELOW_gc = (0x01<<0)  /* The voltage is below the VLM threshold level */
} BOD_VLMS_t;

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
    register8_t SEQCTRL2;  /* Sequential Control 2 */
    register8_t reserved_1[1];
    register8_t INTCTRL0;  /* Interrupt Control 0 */
    register8_t INTCTRL1;  /* Interrupt Control 1 */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t LUT0CTRLA;  /* LUT Control 0 A */
    register8_t LUT0CTRLB;  /* LUT Control 0 B */
    register8_t LUT0CTRLC;  /* LUT Control 0 C */
    register8_t TRUTH0;  /* Truth 0 */
    register8_t LUT1CTRLA;  /* LUT Control 1 A */
    register8_t LUT1CTRLB;  /* LUT Control 1 B */
    register8_t LUT1CTRLC;  /* LUT Control 1 C */
    register8_t TRUTH1;  /* Truth 1 */
    register8_t LUT2CTRLA;  /* LUT Control 2 A */
    register8_t LUT2CTRLB;  /* LUT Control 2 B */
    register8_t LUT2CTRLC;  /* LUT Control 2 C */
    register8_t TRUTH2;  /* Truth 2 */
    register8_t LUT3CTRLA;  /* LUT Control 3 A */
    register8_t LUT3CTRLB;  /* LUT Control 3 B */
    register8_t LUT3CTRLC;  /* LUT Control 3 C */
    register8_t TRUTH3;  /* Truth 3 */
    register8_t LUT4CTRLA;  /* LUT Control 4 A */
    register8_t LUT4CTRLB;  /* LUT Control 4 B */
    register8_t LUT4CTRLC;  /* LUT Control 4 C */
    register8_t TRUTH4;  /* Truth 4 */
    register8_t LUT5CTRLA;  /* LUT Control 5 A */
    register8_t LUT5CTRLB;  /* LUT Control 5 B */
    register8_t LUT5CTRLC;  /* LUT Control 5 C */
    register8_t TRUTH5;  /* Truth 5 */
    register8_t reserved_2[32];
} CCL_t;

/* Clock Source Selection */
typedef enum CCL_CLKSRC_enum
{
    CCL_CLKSRC_CLKPER_gc = (0x00<<1),  /* CLK_PER is clocking the LUT */
    CCL_CLKSRC_IN2_gc = (0x01<<1),  /* IN[2] is clocking the LUT */
    CCL_CLKSRC_DCO_gc = (0x02<<1),  /* DCO is clocking the LUT */
    CCL_CLKSRC_OSC32K_gc = (0x03<<1),  /* 32kHz oscillator is clocking the LUT */
    CCL_CLKSRC_OSC1K_gc = (0x04<<1),  /* 32kHz oscillator after DIV32 is clocking the LUT */
    CCL_CLKSRC_OSCULP32K_gc = (0x05<<1),  /* 32kHz oscillator is clocking the LUT */
    CCL_CLKSRC_OSCULP1K_gc = (0x06<<1)  /* 32kHz oscillator after DIV32 is clocking the LUT */
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
    CCL_INSEL0_FEEDBACK_gc = (0x01<<0),  /* Feedback input source */
    CCL_INSEL0_LINK_gc = (0x02<<0),  /* Linked LUT input source */
    CCL_INSEL0_EVENTA_gc = (0x03<<0),  /* Event input source A */
    CCL_INSEL0_EVENTB_gc = (0x04<<0),  /* Event input source B */
    CCL_INSEL0_IO_gc = (0x05<<0),  /* IO pin LUTn-IN0 input source */
    CCL_INSEL0_AC0_gc = (0x06<<0),  /* AC0 OUT input source */
    CCL_INSEL0_USART0_gc = (0x08<<0),  /* USART0 TXD input source */
    CCL_INSEL0_SPI0_gc = (0x09<<0),  /* SPI0 MOSI input source */
    CCL_INSEL0_TCA0_gc = (0x0A<<0),  /* TCA0 WO0 input source */
    CCL_INSEL0_TCA1_gc = (0x0B<<0),  /* TCA1 WO0 input source */
    CCL_INSEL0_TCB0_gc = (0x0C<<0),  /* TCB0 WO input source */
    CCL_INSEL0_TCD0_gc = (0x0D<<0)  /* TCD0 WOA input source */
} CCL_INSEL0_t;

/* LUT Input 1 Source Selection */
typedef enum CCL_INSEL1_enum
{
    CCL_INSEL1_MASK_gc = (0x00<<4),  /* Masked input */
    CCL_INSEL1_FEEDBACK_gc = (0x01<<4),  /* Feedback input source */
    CCL_INSEL1_LINK_gc = (0x02<<4),  /* Linked LUT input source */
    CCL_INSEL1_EVENTA_gc = (0x03<<4),  /* Event input source A */
    CCL_INSEL1_EVENTB_gc = (0x04<<4),  /* Event input source B */
    CCL_INSEL1_IO_gc = (0x05<<4),  /* IO pin LUTn-N1 input source */
    CCL_INSEL1_AC0_gc = (0x06<<4),  /* AC0 OUT input source */
    CCL_INSEL1_USART1_gc = (0x08<<4),  /* USART1 TXD input source */
    CCL_INSEL1_SPI0_gc = (0x09<<4),  /* SPI0 MOSI input source */
    CCL_INSEL1_TCA0_gc = (0x0A<<4),  /* TCA0 WO1 input source */
    CCL_INSEL1_TCA1_gc = (0x0B<<4),  /* TCA1 WO1 input source */
    CCL_INSEL1_TCB1_gc = (0x0C<<4),  /* TCB1 WO input source */
    CCL_INSEL1_TCD0_gc = (0x0D<<4)  /* TCD0 WOB input source */
} CCL_INSEL1_t;

/* LUT Input 2 Source Selection */
typedef enum CCL_INSEL2_enum
{
    CCL_INSEL2_MASK_gc = (0x00<<0),  /* Masked input */
    CCL_INSEL2_FEEDBACK_gc = (0x01<<0),  /* Feedback input source */
    CCL_INSEL2_LINK_gc = (0x02<<0),  /* Linked LUT input source */
    CCL_INSEL2_EVENTA_gc = (0x03<<0),  /* Event input source A */
    CCL_INSEL2_EVENTB_gc = (0x04<<0),  /* Event input source B */
    CCL_INSEL2_IO_gc = (0x05<<0),  /* IO pin LUTn-IN2 input source */
    CCL_INSEL2_AC0_gc = (0x06<<0),  /* AC0 OUT input source */
    CCL_INSEL2_USART2_gc = (0x08<<0),  /* USART2 TXD input source */
    CCL_INSEL2_SPI0_gc = (0x09<<0),  /* SPI0 SCK input source */
    CCL_INSEL2_TCA0_gc = (0x0A<<0),  /* TCA0 WO2 input source */
    CCL_INSEL2_TCA1_gc = (0x0B<<0),  /* TCA1 WO2 input source */
    CCL_INSEL2_TCB2_gc = (0x0C<<0),  /* TCB2 WO input source */
    CCL_INSEL2_TCD0_gc = (0x0D<<0)  /* TCD0 WOC input source */
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

/* Interrupt Mode for LUT4 select */
typedef enum CCL_INTMODE4_enum
{
    CCL_INTMODE4_BOTH_gc = (0x00<<0),  /* Sense both edges */
    CCL_INTMODE4_FALLING_gc = (0x01<<0),  /* Sense falling edge */
    CCL_INTMODE4_RISING_gc = (0x02<<0),  /* Sense rising edge */
    CCL_INTMODE4_INTDISABLE_gc = (0x03<<0)  /* Interrupt disabled */
} CCL_INTMODE4_t;

/* Interrupt Mode for LUT5 select */
typedef enum CCL_INTMODE5_enum
{
    CCL_INTMODE5_BOTH_gc = (0x00<<2),  /* Sense both edges */
    CCL_INTMODE5_FALLING_gc = (0x01<<2),  /* Sense falling edge */
    CCL_INTMODE5_RISING_gc = (0x02<<2),  /* Sense rising edge */
    CCL_INTMODE5_INTDISABLE_gc = (0x03<<2)  /* Interrupt disabled */
} CCL_INTMODE5_t;

/* Sequential Selection */
typedef enum CCL_SEQSEL0_enum
{
    CCL_SEQSEL0_DISABLE_gc = (0x00<<0),  /* Sequential logic disabled */
    CCL_SEQSEL0_DFF_gc = (0x01<<0),  /* D FlipFlop */
    CCL_SEQSEL0_JK_gc = (0x02<<0),  /* JK FlipFlop */
    CCL_SEQSEL0_LATCH_gc = (0x03<<0),  /* D Latch */
    CCL_SEQSEL0_RS_gc = (0x04<<0)  /* RS Latch */
} CCL_SEQSEL0_t;

/* Sequential Selection */
typedef enum CCL_SEQSEL1_enum
{
    CCL_SEQSEL1_DISABLE_gc = (0x00<<0),  /* Sequential logic disabled */
    CCL_SEQSEL1_DFF_gc = (0x01<<0),  /* D FlipFlop */
    CCL_SEQSEL1_JK_gc = (0x02<<0),  /* JK FlipFlop */
    CCL_SEQSEL1_LATCH_gc = (0x03<<0),  /* D Latch */
    CCL_SEQSEL1_RS_gc = (0x04<<0)  /* RS Latch */
} CCL_SEQSEL1_t;

/* Sequential Selection */
typedef enum CCL_SEQSEL2_enum
{
    CCL_SEQSEL2_DISABLE_gc = (0x00<<0),  /* Sequential logic disabled */
    CCL_SEQSEL2_DFF_gc = (0x01<<0),  /* D FlipFlop */
    CCL_SEQSEL2_JK_gc = (0x02<<0),  /* JK FlipFlop */
    CCL_SEQSEL2_LATCH_gc = (0x03<<0),  /* D Latch */
    CCL_SEQSEL2_RS_gc = (0x04<<0)  /* RS Latch */
} CCL_SEQSEL2_t;

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
typedef enum CLKCTRL_FRQSEL_enum
{
    CLKCTRL_FRQSEL_1M_gc = (0x00<<2),  /* 1 MHz system clock */
    CLKCTRL_FRQSEL_2M_gc = (0x01<<2),  /* 2 MHz system clock */
    CLKCTRL_FRQSEL_3M_gc = (0x02<<2),  /* 3 MHz system clock */
    CLKCTRL_FRQSEL_4M_gc = (0x03<<2),  /* 4 MHz system clock (default) */
    CLKCTRL_FRQSEL_8M_gc = (0x05<<2),  /* 8 MHz system clock */
    CLKCTRL_FRQSEL_12M_gc = (0x06<<2),  /* 12 MHz system clock */
    CLKCTRL_FRQSEL_16M_gc = (0x07<<2),  /* 16 MHz system clock */
    CLKCTRL_FRQSEL_20M_gc = (0x08<<2),  /* 20 MHz system clock */
    CLKCTRL_FRQSEL_24M_gc = (0x09<<2),  /* 24 MHz system clock */
    CLKCTRL_FRQSEL_28M_gc = (0x0A<<2),  /* 28 MHz system clock */
    CLKCTRL_FRQSEL_32M_gc = (0x0B<<2)  /* 32 MHz system clock */
} CLKCTRL_FRQSEL_t;

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
DAC - Digital to Analog Converter
--------------------------------------------------------------------------
*/

/* Digital to Analog Converter */
typedef struct DAC_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t reserved_1[1];
    _WORDREGISTER(DATA);  /* DATA Register */
    register8_t reserved_2[3];
    register8_t TEST;  /* TEST Register */
} DAC_t;

/* Buffer Range select */
typedef enum DAC_BUFRANGE_enum
{
    DAC_BUFRANGE_NORMAL_gc = (0x00<<5),  /* Output buffer in normal output drive range */
    DAC_BUFRANGE_EXTENDED_gc = (0x01<<5)  /* Output buffer use extra current to increase output drive range */
} DAC_BUFRANGE_t;

/* Feedback select */
typedef enum DAC_FEEDBACK_enum
{
    DAC_FEEDBACK_NORMAL_gc = (0x00<<0),  /* Unity gain configuration. Buffer feedback (VIN) from DACOUT pin. */
    DAC_FEEDBACK_EXTERNAL_gc = (0x01<<0)  /* Flexible loop configuration. Buffer feedback (VIN) from alternate pin. */
} DAC_FEEDBACK_t;

/* Pumpout select */
typedef enum DAC_PUMPOUT_enum
{
    DAC_PUMPOUT_ENABLE_gc = (0x00<<1),  /* Pump voltage not available */
    DAC_PUMPOUT_DISABLE_gc = (0x01<<1)  /* Pump voltage available on analog test bus */
} DAC_PUMPOUT_t;

/*
--------------------------------------------------------------------------
EVSYS - Event System
--------------------------------------------------------------------------
*/

/* Event System */
typedef struct EVSYS_struct
{
    register8_t SWEVENTA;  /* Software Event A */
    register8_t SWEVENTB;  /* Software Event B */
    register8_t reserved_1[14];
    register8_t CHANNEL0;  /* Multiplexer Channel 0 */
    register8_t CHANNEL1;  /* Multiplexer Channel 1 */
    register8_t CHANNEL2;  /* Multiplexer Channel 2 */
    register8_t CHANNEL3;  /* Multiplexer Channel 3 */
    register8_t CHANNEL4;  /* Multiplexer Channel 4 */
    register8_t CHANNEL5;  /* Multiplexer Channel 5 */
    register8_t CHANNEL6;  /* Multiplexer Channel 6 */
    register8_t CHANNEL7;  /* Multiplexer Channel 7 */
    register8_t CHANNEL8;  /* Multiplexer Channel 8 */
    register8_t CHANNEL9;  /* Multiplexer Channel 9 */
    register8_t reserved_2[6];
    register8_t USERCCLLUT0A;  /* User 0 - CCL0 Event A */
    register8_t USERCCLLUT0B;  /* User 1 - CCL0 Event B */
    register8_t USERCCLLUT1A;  /* User 2 - CCL1 Event A */
    register8_t USERCCLLUT1B;  /* User 3 - CCL1 Event B */
    register8_t USERCCLLUT2A;  /* User 4 - CCL2 Event A */
    register8_t USERCCLLUT2B;  /* User 5 - CCL2 Event B */
    register8_t USERCCLLUT3A;  /* User 6 - CCL3 Event A */
    register8_t USERCCLLUT3B;  /* User 7 - CCL3 Event B */
    register8_t USERCCLLUT4A;  /* User 8 - CCL4 Event A */
    register8_t USERCCLLUT4B;  /* User 9 - CCL4 Event B */
    register8_t USERCCLLUT5A;  /* User 10 - CCL5 Event A */
    register8_t USERCCLLUT5B;  /* User 11 - CCL5 Event B */
    register8_t USERADC0START;  /* User 12 - ADC0 */
    register8_t USERPTCSTART;  /* User 13 - PTC */
    register8_t USEREVSYSEVOUTA;  /* User 14 - EVOUTA */
    register8_t USEREVSYSEVOUTB;  /* User 15 - EVOUTB */
    register8_t USEREVSYSEVOUTC;  /* User 16 - EVOUTC */
    register8_t USEREVSYSEVOUTD;  /* User 17 - EVOUTD */
    register8_t USEREVSYSEVOUTE;  /* User 18 - EVOUTE */
    register8_t USEREVSYSEVOUTF;  /* User 19 - EVOUTF */
    register8_t USEREVSYSEVOUTG;  /* User 20 - EVOUTG */
    register8_t USERUSART0IRDA;  /* User 21 - USART0 */
    register8_t USERUSART1IRDA;  /* User 22 - USART1 */
    register8_t USERUSART2IRDA;  /* User 23 - USART2 */
    register8_t USERUSART3IRDA;  /* User 24 - USART3 */
    register8_t USERUSART4IRDA;  /* User 25 - USART4 */
    register8_t USERUSART5IRDA;  /* User 26 - USART5 */
    register8_t USERTCA0CNTA;  /* User 27 - TCA0 Event A */
    register8_t USERTCA0CNTB;  /* User 28 - TCA0 Event B */
    register8_t USERTCA1CNTA;  /* User 29 - TCA1 Event A */
    register8_t USERTCA1CNTB;  /* User 30 - TCA1 Event B */
    register8_t USERTCB0CAPT;  /* User 31 - TCB0 Event A */
    register8_t USERTCB0COUNT;  /* User 32 - TCB0 Event B */
    register8_t USERTCB1CAPT;  /* User 33 - TCB1 Event A */
    register8_t USERTCB1COUNT;  /* User 34 - TCB1 Event B */
    register8_t USERTCB2CAPT;  /* User 35 - TCB2 Event A */
    register8_t USERTCB2COUNT;  /* User 36 - TCB2 Event B */
    register8_t USERTCB3CAPT;  /* User 37 - TCB3 Event A */
    register8_t USERTCB3COUNT;  /* User 38 - TCB3 Event B */
    register8_t USERTCB4CAPT;  /* User 39 - TCB4 Event A */
    register8_t USERTCB4COUNT;  /* User 40 - TCB4 Event B */
    register8_t USERTCD0INPUTA;  /* User 41 - TCD0 Event A */
    register8_t USERTCD0INPUTB;  /* User 42 - TCD0 Event B */
    register8_t USEROSCTEST;  /* User 43 - OSCTEST */
} EVSYS_t;

/* Channel 0 generator select */
typedef enum EVSYS_CHANNEL0_enum
{
    EVSYS_CHANNEL0_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL0_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI sync character */
    EVSYS_CHANNEL0_OSCTEST_gc = (0x02<<0),  /* Oscillator test event */
    EVSYS_CHANNEL0_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL0_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL0_RTC_PIT_DIV8192_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL0_RTC_PIT_DIV4096_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL0_RTC_PIT_DIV2048_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL0_RTC_PIT_DIV1024_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL0_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL0_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL0_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL0_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL0_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL0_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL0_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL0_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL0_AC2_OUT_gc = (0x22<<0),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL0_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL0_PTC_RESRDY_gc = (0x28<<0),  /* PTC Result Ready */
    EVSYS_CHANNEL0_ZCD0_gc = (0x30<<0),  /* Zero Cross Detect 0 out */
    EVSYS_CHANNEL0_ZCD1_gc = (0x31<<0),  /* Zero Cross Detect 1 out */
    EVSYS_CHANNEL0_ZCD2_gc = (0x32<<0),  /* Zero Cross Detect 2 out */
    EVSYS_CHANNEL0_PORTA_PIN0_gc = (0x40<<0),  /* Port A Pin 0 */
    EVSYS_CHANNEL0_PORTA_PIN1_gc = (0x41<<0),  /* Port A Pin 1 */
    EVSYS_CHANNEL0_PORTA_PIN2_gc = (0x42<<0),  /* Port A Pin 2 */
    EVSYS_CHANNEL0_PORTA_PIN3_gc = (0x43<<0),  /* Port A Pin 3 */
    EVSYS_CHANNEL0_PORTA_PIN4_gc = (0x44<<0),  /* Port A Pin 4 */
    EVSYS_CHANNEL0_PORTA_PIN5_gc = (0x45<<0),  /* Port A Pin 5 */
    EVSYS_CHANNEL0_PORTA_PIN6_gc = (0x46<<0),  /* Port A Pin 6 */
    EVSYS_CHANNEL0_PORTA_PIN7_gc = (0x47<<0),  /* Port A Pin 7 */
    EVSYS_CHANNEL0_PORTB_PIN0_gc = (0x48<<0),  /* Port B Pin 0 */
    EVSYS_CHANNEL0_PORTB_PIN1_gc = (0x49<<0),  /* Port B Pin 1 */
    EVSYS_CHANNEL0_PORTB_PIN2_gc = (0x4A<<0),  /* Port B Pin 2 */
    EVSYS_CHANNEL0_PORTB_PIN3_gc = (0x4B<<0),  /* Port B Pin 3 */
    EVSYS_CHANNEL0_PORTB_PIN4_gc = (0x4C<<0),  /* Port B Pin 4 */
    EVSYS_CHANNEL0_PORTB_PIN5_gc = (0x4D<<0),  /* Port B Pin 5 */
    EVSYS_CHANNEL0_PORTB_PIN6_gc = (0x4E<<0),  /* Port B Pin 6 */
    EVSYS_CHANNEL0_PORTB_PIN7_gc = (0x4F<<0),  /* Port B Pin 7 */
    EVSYS_CHANNEL0_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL0_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL0_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL0_USART3_XCK_gc = (0x63<<0),  /* USART 3 XCK */
    EVSYS_CHANNEL0_USART4_XCK_gc = (0x64<<0),  /* USART 4 XCK */
    EVSYS_CHANNEL0_USART5_XCK_gc = (0x65<<0),  /* USART 5 XCK */
    EVSYS_CHANNEL0_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL0_SPI1_SCK_gc = (0x69<<0),  /* SPI 1 SCK */
    EVSYS_CHANNEL0_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL0_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL0_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL0_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL0_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL0_TCA1_OVF_LUNF_gc = (0x88<<0),  /* Timer/Counter A1 overflow / low byte timer underflow */
    EVSYS_CHANNEL0_TCA1_HUNF_gc = (0x89<<0),  /* Timer/Counter A1 high byte timer underflow */
    EVSYS_CHANNEL0_TCA1_CMP0_LCMP0_gc = (0x8C<<0),  /* Timer/Counter A1 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL0_TCA1_CMP1_LCMP1_gc = (0x8D<<0),  /* Timer/Counter A1 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL0_TCA1_CMP2_LCMP2_gc = (0x8E<<0),  /* Timer/Counter A1 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL0_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL0_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL0_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL0_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL0_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL0_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL0_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL0_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL0_TCB4_CAPT_gc = (0xA8<<0),  /* Timer/Counter B4 capture */
    EVSYS_CHANNEL0_TCB4_OVF_gc = (0xA9<<0),  /* Timer/Counter B4 overflow */
    EVSYS_CHANNEL0_TCD0_CMPBCLR_gc = (0xB0<<0),  /* Timer/Counter D0 event 0 */
    EVSYS_CHANNEL0_TCD0_CMPASET_gc = (0xB1<<0),  /* Timer/Counter D0 event 1 */
    EVSYS_CHANNEL0_TCD0_CMPBSET_gc = (0xB2<<0),  /* Timer/Counter D0 event 2 */
    EVSYS_CHANNEL0_TCD0_PROGEV_gc = (0xB3<<0)  /* Timer/Counter D0 event 3 */
} EVSYS_CHANNEL0_t;

/* Channel 1 generator select */
typedef enum EVSYS_CHANNEL1_enum
{
    EVSYS_CHANNEL1_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL1_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI sync character */
    EVSYS_CHANNEL1_TESTCH0_gc = (0x02<<0),  /* Test Channel 0 */
    EVSYS_CHANNEL1_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL1_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL1_RTC_PIT_DIV512_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL1_RTC_PIT_DIV256_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL1_RTC_PIT_DIV128_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL1_RTC_PIT_DIV64_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL1_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL1_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL1_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL1_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL1_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL1_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL1_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL1_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL1_AC2_OUT_gc = (0x22<<0),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL1_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL1_PTC_RESRDY_gc = (0x28<<0),  /* PTC Result Ready */
    EVSYS_CHANNEL1_ZCD0_gc = (0x30<<0),  /* Zero Cross Detect 0 out */
    EVSYS_CHANNEL1_ZCD1_gc = (0x31<<0),  /* Zero Cross Detect 1 out */
    EVSYS_CHANNEL1_ZCD2_gc = (0x32<<0),  /* Zero Cross Detect 2 out */
    EVSYS_CHANNEL1_PORTA_PIN0_gc = (0x40<<0),  /* Port A Pin 0 */
    EVSYS_CHANNEL1_PORTA_PIN1_gc = (0x41<<0),  /* Port A Pin 1 */
    EVSYS_CHANNEL1_PORTA_PIN2_gc = (0x42<<0),  /* Port A Pin 2 */
    EVSYS_CHANNEL1_PORTA_PIN3_gc = (0x43<<0),  /* Port A Pin 3 */
    EVSYS_CHANNEL1_PORTA_PIN4_gc = (0x44<<0),  /* Port A Pin 4 */
    EVSYS_CHANNEL1_PORTA_PIN5_gc = (0x45<<0),  /* Port A Pin 5 */
    EVSYS_CHANNEL1_PORTA_PIN6_gc = (0x46<<0),  /* Port A Pin 6 */
    EVSYS_CHANNEL1_PORTA_PIN7_gc = (0x47<<0),  /* Port A Pin 7 */
    EVSYS_CHANNEL1_PORTB_PIN0_gc = (0x48<<0),  /* Port B Pin 0 */
    EVSYS_CHANNEL1_PORTB_PIN1_gc = (0x49<<0),  /* Port B Pin 1 */
    EVSYS_CHANNEL1_PORTB_PIN2_gc = (0x4A<<0),  /* Port B Pin 2 */
    EVSYS_CHANNEL1_PORTB_PIN3_gc = (0x4B<<0),  /* Port B Pin 3 */
    EVSYS_CHANNEL1_PORTB_PIN4_gc = (0x4C<<0),  /* Port B Pin 4 */
    EVSYS_CHANNEL1_PORTB_PIN5_gc = (0x4D<<0),  /* Port B Pin 5 */
    EVSYS_CHANNEL1_PORTB_PIN6_gc = (0x4E<<0),  /* Port B Pin 6 */
    EVSYS_CHANNEL1_PORTB_PIN7_gc = (0x4F<<0),  /* Port B Pin 7 */
    EVSYS_CHANNEL1_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL1_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL1_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL1_USART3_XCK_gc = (0x63<<0),  /* USART 3 XCK */
    EVSYS_CHANNEL1_USART4_XCK_gc = (0x64<<0),  /* USART 4 XCK */
    EVSYS_CHANNEL1_USART5_XCK_gc = (0x65<<0),  /* USART 5 XCK */
    EVSYS_CHANNEL1_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL1_SPI1_SCK_gc = (0x69<<0),  /* SPI 1 SCK */
    EVSYS_CHANNEL1_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL1_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL1_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL1_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL1_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL1_TCA1_OVF_LUNF_gc = (0x88<<0),  /* Timer/Counter A1 overflow / low byte timer underflow */
    EVSYS_CHANNEL1_TCA1_HUNF_gc = (0x89<<0),  /* Timer/Counter A1 high byte timer underflow */
    EVSYS_CHANNEL1_TCA1_CMP0_LCMP0_gc = (0x8C<<0),  /* Timer/Counter A1 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL1_TCA1_CMP1_LCMP1_gc = (0x8D<<0),  /* Timer/Counter A1 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL1_TCA1_CMP2_LCMP2_gc = (0x8E<<0),  /* Timer/Counter A1 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL1_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL1_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL1_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL1_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL1_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL1_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL1_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL1_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL1_TCB4_CAPT_gc = (0xA8<<0),  /* Timer/Counter B4 capture */
    EVSYS_CHANNEL1_TCB4_OVF_gc = (0xA9<<0),  /* Timer/Counter B4 overflow */
    EVSYS_CHANNEL1_TCD0_CMPBCLR_gc = (0xB0<<0),  /* Timer/Counter D0 event 0 */
    EVSYS_CHANNEL1_TCD0_CMPASET_gc = (0xB1<<0),  /* Timer/Counter D0 event 1 */
    EVSYS_CHANNEL1_TCD0_CMPBSET_gc = (0xB2<<0),  /* Timer/Counter D0 event 2 */
    EVSYS_CHANNEL1_TCD0_PROGEV_gc = (0xB3<<0)  /* Timer/Counter D0 event 3 */
} EVSYS_CHANNEL1_t;

/* Channel 2 generator select */
typedef enum EVSYS_CHANNEL2_enum
{
    EVSYS_CHANNEL2_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL2_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI sync character */
    EVSYS_CHANNEL2_TESTCH1_gc = (0x02<<0),  /* Test Channel 1 */
    EVSYS_CHANNEL2_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL2_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL2_RTC_PIT_DIV8192_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL2_RTC_PIT_DIV4096_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL2_RTC_PIT_DIV2048_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL2_RTC_PIT_DIV1024_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL2_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL2_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL2_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL2_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL2_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL2_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL2_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL2_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL2_AC2_OUT_gc = (0x22<<0),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL2_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL2_PTC_RESRDY_gc = (0x28<<0),  /* PTC Result Ready */
    EVSYS_CHANNEL2_ZCD0_gc = (0x30<<0),  /* Zero Cross Detect 0 out */
    EVSYS_CHANNEL2_ZCD1_gc = (0x31<<0),  /* Zero Cross Detect 1 out */
    EVSYS_CHANNEL2_ZCD2_gc = (0x32<<0),  /* Zero Cross Detect 2 out */
    EVSYS_CHANNEL2_PORTC_PIN0_gc = (0x40<<0),  /* Port C Pin 0 */
    EVSYS_CHANNEL2_PORTC_PIN1_gc = (0x41<<0),  /* Port C Pin 1 */
    EVSYS_CHANNEL2_PORTC_PIN2_gc = (0x42<<0),  /* Port C Pin 2 */
    EVSYS_CHANNEL2_PORTC_PIN3_gc = (0x43<<0),  /* Port C Pin 3 */
    EVSYS_CHANNEL2_PORTC_PIN4_gc = (0x44<<0),  /* Port C Pin 4 */
    EVSYS_CHANNEL2_PORTC_PIN5_gc = (0x45<<0),  /* Port C Pin 5 */
    EVSYS_CHANNEL2_PORTC_PIN6_gc = (0x46<<0),  /* Port C Pin 6 */
    EVSYS_CHANNEL2_PORTC_PIN7_gc = (0x47<<0),  /* Port C Pin 7 */
    EVSYS_CHANNEL2_PORTD_PIN0_gc = (0x48<<0),  /* Port D Pin 0 */
    EVSYS_CHANNEL2_PORTD_PIN1_gc = (0x49<<0),  /* Port D Pin 1 */
    EVSYS_CHANNEL2_PORTD_PIN2_gc = (0x4A<<0),  /* Port D Pin 2 */
    EVSYS_CHANNEL2_PORTD_PIN3_gc = (0x4B<<0),  /* Port D Pin 3 */
    EVSYS_CHANNEL2_PORTD_PIN4_gc = (0x4C<<0),  /* Port D Pin 4 */
    EVSYS_CHANNEL2_PORTD_PIN5_gc = (0x4D<<0),  /* Port D Pin 5 */
    EVSYS_CHANNEL2_PORTD_PIN6_gc = (0x4E<<0),  /* Port D Pin 6 */
    EVSYS_CHANNEL2_PORTD_PIN7_gc = (0x4F<<0),  /* Port D Pin 7 */
    EVSYS_CHANNEL2_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL2_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL2_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL2_USART3_XCK_gc = (0x63<<0),  /* USART 3 XCK */
    EVSYS_CHANNEL2_USART4_XCK_gc = (0x64<<0),  /* USART 4 XCK */
    EVSYS_CHANNEL2_USART5_XCK_gc = (0x65<<0),  /* USART 5 XCK */
    EVSYS_CHANNEL2_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL2_SPI1_SCK_gc = (0x69<<0),  /* SPI 1 SCK */
    EVSYS_CHANNEL2_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL2_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL2_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL2_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL2_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL2_TCA1_OVF_LUNF_gc = (0x88<<0),  /* Timer/Counter A1 overflow / low byte timer underflow */
    EVSYS_CHANNEL2_TCA1_HUNF_gc = (0x89<<0),  /* Timer/Counter A1 high byte timer underflow */
    EVSYS_CHANNEL2_TCA1_CMP0_LCMP0_gc = (0x8C<<0),  /* Timer/Counter A1 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL2_TCA1_CMP1_LCMP1_gc = (0x8D<<0),  /* Timer/Counter A1 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL2_TCA1_CMP2_LCMP2_gc = (0x8E<<0),  /* Timer/Counter A1 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL2_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL2_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL2_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL2_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL2_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL2_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL2_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL2_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL2_TCB4_CAPT_gc = (0xA8<<0),  /* Timer/Counter B4 capture */
    EVSYS_CHANNEL2_TCB4_OVF_gc = (0xA9<<0),  /* Timer/Counter B4 overflow */
    EVSYS_CHANNEL2_TCD0_CMPBCLR_gc = (0xB0<<0),  /* Timer/Counter D0 event 0 */
    EVSYS_CHANNEL2_TCD0_CMPASET_gc = (0xB1<<0),  /* Timer/Counter D0 event 1 */
    EVSYS_CHANNEL2_TCD0_CMPBSET_gc = (0xB2<<0),  /* Timer/Counter D0 event 2 */
    EVSYS_CHANNEL2_TCD0_PROGEV_gc = (0xB3<<0)  /* Timer/Counter D0 event 3 */
} EVSYS_CHANNEL2_t;

/* Channel 3 generator select */
typedef enum EVSYS_CHANNEL3_enum
{
    EVSYS_CHANNEL3_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL3_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI sync character */
    EVSYS_CHANNEL3_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL3_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL3_RTC_PIT_DIV512_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL3_RTC_PIT_DIV256_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL3_RTC_PIT_DIV128_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL3_RTC_PIT_DIV64_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL3_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL3_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL3_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL3_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL3_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL3_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL3_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL3_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL3_AC2_OUT_gc = (0x22<<0),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL3_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL3_PTC_RESRDY_gc = (0x28<<0),  /* PTC Result Ready */
    EVSYS_CHANNEL3_ZCD0_gc = (0x30<<0),  /* Zero Cross Detect 0 out */
    EVSYS_CHANNEL3_ZCD1_gc = (0x31<<0),  /* Zero Cross Detect 1 out */
    EVSYS_CHANNEL3_ZCD2_gc = (0x32<<0),  /* Zero Cross Detect 2 out */
    EVSYS_CHANNEL3_PORTC_PIN0_gc = (0x40<<0),  /* Port C Pin 0 */
    EVSYS_CHANNEL3_PORTC_PIN1_gc = (0x41<<0),  /* Port C Pin 1 */
    EVSYS_CHANNEL3_PORTC_PIN2_gc = (0x42<<0),  /* Port C Pin 2 */
    EVSYS_CHANNEL3_PORTC_PIN3_gc = (0x43<<0),  /* Port C Pin 3 */
    EVSYS_CHANNEL3_PORTC_PIN4_gc = (0x44<<0),  /* Port C Pin 4 */
    EVSYS_CHANNEL3_PORTC_PIN5_gc = (0x45<<0),  /* Port C Pin 5 */
    EVSYS_CHANNEL3_PORTC_PIN6_gc = (0x46<<0),  /* Port C Pin 6 */
    EVSYS_CHANNEL3_PORTC_PIN7_gc = (0x47<<0),  /* Port C Pin 7 */
    EVSYS_CHANNEL3_PORTD_PIN0_gc = (0x48<<0),  /* Port D Pin 0 */
    EVSYS_CHANNEL3_PORTD_PIN1_gc = (0x49<<0),  /* Port D Pin 1 */
    EVSYS_CHANNEL3_PORTD_PIN2_gc = (0x4A<<0),  /* Port D Pin 2 */
    EVSYS_CHANNEL3_PORTD_PIN3_gc = (0x4B<<0),  /* Port D Pin 3 */
    EVSYS_CHANNEL3_PORTD_PIN4_gc = (0x4C<<0),  /* Port D Pin 4 */
    EVSYS_CHANNEL3_PORTD_PIN5_gc = (0x4D<<0),  /* Port D Pin 5 */
    EVSYS_CHANNEL3_PORTD_PIN6_gc = (0x4E<<0),  /* Port D Pin 6 */
    EVSYS_CHANNEL3_PORTD_PIN7_gc = (0x4F<<0),  /* Port D Pin 7 */
    EVSYS_CHANNEL3_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL3_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL3_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL3_USART3_XCK_gc = (0x63<<0),  /* USART 3 XCK */
    EVSYS_CHANNEL3_USART4_XCK_gc = (0x64<<0),  /* USART 4 XCK */
    EVSYS_CHANNEL3_USART5_XCK_gc = (0x65<<0),  /* USART 5 XCK */
    EVSYS_CHANNEL3_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL3_SPI1_SCK_gc = (0x69<<0),  /* SPI 1 SCK */
    EVSYS_CHANNEL3_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL3_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL3_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL3_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL3_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL3_TCA1_OVF_LUNF_gc = (0x88<<0),  /* Timer/Counter A1 overflow / low byte timer underflow */
    EVSYS_CHANNEL3_TCA1_HUNF_gc = (0x89<<0),  /* Timer/Counter A1 high byte timer underflow */
    EVSYS_CHANNEL3_TCA1_CMP0_LCMP0_gc = (0x8C<<0),  /* Timer/Counter A1 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL3_TCA1_CMP1_LCMP1_gc = (0x8D<<0),  /* Timer/Counter A1 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL3_TCA1_CMP2_LCMP2_gc = (0x8E<<0),  /* Timer/Counter A1 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL3_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL3_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL3_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL3_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL3_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL3_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL3_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL3_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL3_TCB4_CAPT_gc = (0xA8<<0),  /* Timer/Counter B4 capture */
    EVSYS_CHANNEL3_TCB4_OVF_gc = (0xA9<<0),  /* Timer/Counter B4 overflow */
    EVSYS_CHANNEL3_TCD0_CMPBCLR_gc = (0xB0<<0),  /* Timer/Counter D0 event 0 */
    EVSYS_CHANNEL3_TCD0_CMPASET_gc = (0xB1<<0),  /* Timer/Counter D0 event 1 */
    EVSYS_CHANNEL3_TCD0_CMPBSET_gc = (0xB2<<0),  /* Timer/Counter D0 event 2 */
    EVSYS_CHANNEL3_TCD0_PROGEV_gc = (0xB3<<0)  /* Timer/Counter D0 event 3 */
} EVSYS_CHANNEL3_t;

/* Channel 4 generator select */
typedef enum EVSYS_CHANNEL4_enum
{
    EVSYS_CHANNEL4_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL4_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI sync character */
    EVSYS_CHANNEL4_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL4_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL4_RTC_PIT_DIV8192_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL4_RTC_PIT_DIV4096_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL4_RTC_PIT_DIV2048_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL4_RTC_PIT_DIV1024_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL4_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL4_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL4_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL4_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL4_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL4_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL4_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL4_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL4_AC2_OUT_gc = (0x22<<0),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL4_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL4_PTC_RESRDY_gc = (0x28<<0),  /* PTC Result Ready */
    EVSYS_CHANNEL4_ZCD0_gc = (0x30<<0),  /* Zero Cross Detect 0 out */
    EVSYS_CHANNEL4_ZCD1_gc = (0x31<<0),  /* Zero Cross Detect 1 out */
    EVSYS_CHANNEL4_ZCD2_gc = (0x32<<0),  /* Zero Cross Detect 2 out */
    EVSYS_CHANNEL4_PORTE_PIN0_gc = (0x40<<0),  /* Port E Pin 0 */
    EVSYS_CHANNEL4_PORTE_PIN1_gc = (0x41<<0),  /* Port E Pin 1 */
    EVSYS_CHANNEL4_PORTE_PIN2_gc = (0x42<<0),  /* Port E Pin 2 */
    EVSYS_CHANNEL4_PORTE_PIN3_gc = (0x43<<0),  /* Port E Pin 3 */
    EVSYS_CHANNEL4_PORTE_PIN4_gc = (0x44<<0),  /* Port E Pin 4 */
    EVSYS_CHANNEL4_PORTE_PIN5_gc = (0x45<<0),  /* Port E Pin 5 */
    EVSYS_CHANNEL4_PORTE_PIN6_gc = (0x46<<0),  /* Port E Pin 6 */
    EVSYS_CHANNEL4_PORTE_PIN7_gc = (0x47<<0),  /* Port E Pin 7 */
    EVSYS_CHANNEL4_PORTF_PIN0_gc = (0x48<<0),  /* Port F Pin 0 */
    EVSYS_CHANNEL4_PORTF_PIN1_gc = (0x49<<0),  /* Port F Pin 1 */
    EVSYS_CHANNEL4_PORTF_PIN2_gc = (0x4A<<0),  /* Port F Pin 2 */
    EVSYS_CHANNEL4_PORTF_PIN3_gc = (0x4B<<0),  /* Port F Pin 3 */
    EVSYS_CHANNEL4_PORTF_PIN4_gc = (0x4C<<0),  /* Port F Pin 4 */
    EVSYS_CHANNEL4_PORTF_PIN5_gc = (0x4D<<0),  /* Port F Pin 5 */
    EVSYS_CHANNEL4_PORTF_PIN6_gc = (0x4E<<0),  /* Port F Pin 6 */
    EVSYS_CHANNEL4_PORTF_PIN7_gc = (0x4F<<0),  /* Port F Pin 7 */
    EVSYS_CHANNEL4_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL4_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL4_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL4_USART3_XCK_gc = (0x63<<0),  /* USART 3 XCK */
    EVSYS_CHANNEL4_USART4_XCK_gc = (0x64<<0),  /* USART 4 XCK */
    EVSYS_CHANNEL4_USART5_XCK_gc = (0x65<<0),  /* USART 5 XCK */
    EVSYS_CHANNEL4_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL4_SPI1_SCK_gc = (0x69<<0),  /* SPI 1 SCK */
    EVSYS_CHANNEL4_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL4_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL4_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL4_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL4_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL4_TCA1_OVF_LUNF_gc = (0x88<<0),  /* Timer/Counter A1 overflow / low byte timer underflow */
    EVSYS_CHANNEL4_TCA1_HUNF_gc = (0x89<<0),  /* Timer/Counter A1 high byte timer underflow */
    EVSYS_CHANNEL4_TCA1_CMP0_LCMP0_gc = (0x8C<<0),  /* Timer/Counter A1 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL4_TCA1_CMP1_LCMP1_gc = (0x8D<<0),  /* Timer/Counter A1 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL4_TCA1_CMP2_LCMP2_gc = (0x8E<<0),  /* Timer/Counter A1 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL4_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL4_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL4_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL4_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL4_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL4_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL4_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL4_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL4_TCB4_CAPT_gc = (0xA8<<0),  /* Timer/Counter B4 capture */
    EVSYS_CHANNEL4_TCB4_OVF_gc = (0xA9<<0),  /* Timer/Counter B4 overflow */
    EVSYS_CHANNEL4_TCD0_CMPBCLR_gc = (0xB0<<0),  /* Timer/Counter D0 event 0 */
    EVSYS_CHANNEL4_TCD0_CMPASET_gc = (0xB1<<0),  /* Timer/Counter D0 event 1 */
    EVSYS_CHANNEL4_TCD0_CMPBSET_gc = (0xB2<<0),  /* Timer/Counter D0 event 2 */
    EVSYS_CHANNEL4_TCD0_PROGEV_gc = (0xB3<<0)  /* Timer/Counter D0 event 3 */
} EVSYS_CHANNEL4_t;

/* Channel 5 generator select */
typedef enum EVSYS_CHANNEL5_enum
{
    EVSYS_CHANNEL5_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL5_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI sync character */
    EVSYS_CHANNEL5_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL5_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL5_RTC_PIT_DIV512_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL5_RTC_PIT_DIV256_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL5_RTC_PIT_DIV128_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL5_RTC_PIT_DIV64_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL5_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL5_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL5_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL5_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL5_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL5_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL5_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL5_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL5_AC2_OUT_gc = (0x22<<0),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL5_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL5_PTC_RESRDY_gc = (0x28<<0),  /* PTC Result Ready */
    EVSYS_CHANNEL5_ZCD0_gc = (0x30<<0),  /* Zero Cross Detect 0 out */
    EVSYS_CHANNEL5_ZCD1_gc = (0x31<<0),  /* Zero Cross Detect 1 out */
    EVSYS_CHANNEL5_ZCD2_gc = (0x32<<0),  /* Zero Cross Detect 2 out */
    EVSYS_CHANNEL5_PORTE_PIN0_gc = (0x40<<0),  /* Port E Pin 0 */
    EVSYS_CHANNEL5_PORTE_PIN1_gc = (0x41<<0),  /* Port E Pin 1 */
    EVSYS_CHANNEL5_PORTE_PIN2_gc = (0x42<<0),  /* Port E Pin 2 */
    EVSYS_CHANNEL5_PORTE_PIN3_gc = (0x43<<0),  /* Port E Pin 3 */
    EVSYS_CHANNEL5_PORTE_PIN4_gc = (0x44<<0),  /* Port E Pin 4 */
    EVSYS_CHANNEL5_PORTE_PIN5_gc = (0x45<<0),  /* Port E Pin 5 */
    EVSYS_CHANNEL5_PORTE_PIN6_gc = (0x46<<0),  /* Port E Pin 6 */
    EVSYS_CHANNEL5_PORTA_PIN7_gc = (0x47<<0),  /* Port E Pin 7 */
    EVSYS_CHANNEL5_PORTF_PIN0_gc = (0x48<<0),  /* Port F Pin 0 */
    EVSYS_CHANNEL5_PORTF_PIN1_gc = (0x49<<0),  /* Port F Pin 1 */
    EVSYS_CHANNEL5_PORTF_PIN2_gc = (0x4A<<0),  /* Port F Pin 2 */
    EVSYS_CHANNEL5_PORTF_PIN3_gc = (0x4B<<0),  /* Port F Pin 3 */
    EVSYS_CHANNEL5_PORTF_PIN4_gc = (0x4C<<0),  /* Port F Pin 4 */
    EVSYS_CHANNEL5_PORTF_PIN5_gc = (0x4D<<0),  /* Port F Pin 5 */
    EVSYS_CHANNEL5_PORTF_PIN6_gc = (0x4E<<0),  /* Port F Pin 6 */
    EVSYS_CHANNEL5_PORTF_PIN7_gc = (0x4F<<0),  /* Port F Pin 7 */
    EVSYS_CHANNEL5_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL5_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL5_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL5_USART3_XCK_gc = (0x63<<0),  /* USART 3 XCK */
    EVSYS_CHANNEL5_USART4_XCK_gc = (0x64<<0),  /* USART 4 XCK */
    EVSYS_CHANNEL5_USART5_XCK_gc = (0x65<<0),  /* USART 5 XCK */
    EVSYS_CHANNEL5_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL5_SPI1_SCK_gc = (0x69<<0),  /* SPI 1 SCK */
    EVSYS_CHANNEL5_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL5_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL5_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL5_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL5_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL5_TCA1_OVF_LUNF_gc = (0x88<<0),  /* Timer/Counter A1 overflow / low byte timer underflow */
    EVSYS_CHANNEL5_TCA1_HUNF_gc = (0x89<<0),  /* Timer/Counter A1 high byte timer underflow */
    EVSYS_CHANNEL5_TCA1_CMP0_LCMP0_gc = (0x8C<<0),  /* Timer/Counter A1 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL5_TCA1_CMP1_LCMP1_gc = (0x8D<<0),  /* Timer/Counter A1 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL5_TCA1_CMP2_LCMP2_gc = (0x8E<<0),  /* Timer/Counter A1 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL5_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL5_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL5_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL5_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL5_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL5_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL5_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL5_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL5_TCB4_CAPT_gc = (0xA8<<0),  /* Timer/Counter B4 capture */
    EVSYS_CHANNEL5_TCB4_OVF_gc = (0xA9<<0),  /* Timer/Counter B4 overflow */
    EVSYS_CHANNEL5_TCD0_CMPBCLR_gc = (0xB0<<0),  /* Timer/Counter D0 event 0 */
    EVSYS_CHANNEL5_TCD0_CMPASET_gc = (0xB1<<0),  /* Timer/Counter D0 event 1 */
    EVSYS_CHANNEL5_TCD0_CMPBSET_gc = (0xB2<<0),  /* Timer/Counter D0 event 2 */
    EVSYS_CHANNEL5_TCD0_PROGEV_gc = (0xB3<<0)  /* Timer/Counter D0 event 3 */
} EVSYS_CHANNEL5_t;

/* Channel 6 generator select */
typedef enum EVSYS_CHANNEL6_enum
{
    EVSYS_CHANNEL6_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL6_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI sync character */
    EVSYS_CHANNEL6_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL6_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL6_RTC_PIT_DIV8192_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL6_RTC_PIT_DIV4096_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL6_RTC_PIT_DIV2048_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL6_RTC_PIT_DIV1024_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL6_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL6_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL6_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL6_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL6_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL6_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL6_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL6_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL6_AC2_OUT_gc = (0x22<<0),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL6_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL6_PTC_RESRDY_gc = (0x28<<0),  /* PTC Result Ready */
    EVSYS_CHANNEL6_ZCD0_gc = (0x30<<0),  /* Zero Cross Detect 0 out */
    EVSYS_CHANNEL6_ZCD1_gc = (0x31<<0),  /* Zero Cross Detect 1 out */
    EVSYS_CHANNEL6_ZCD2_gc = (0x32<<0),  /* Zero Cross Detect 2 out */
    EVSYS_CHANNEL6_PORTG_PIN0_gc = (0x40<<0),  /* Port G Pin 0 */
    EVSYS_CHANNEL6_PORTG_PIN1_gc = (0x41<<0),  /* Port G Pin 1 */
    EVSYS_CHANNEL6_PORTG_PIN2_gc = (0x42<<0),  /* Port G Pin 2 */
    EVSYS_CHANNEL6_PORTG_PIN3_gc = (0x43<<0),  /* Port G Pin 3 */
    EVSYS_CHANNEL6_PORTG_PIN4_gc = (0x44<<0),  /* Port G Pin 4 */
    EVSYS_CHANNEL6_PORTG_PIN5_gc = (0x45<<0),  /* Port G Pin 5 */
    EVSYS_CHANNEL6_PORTG_PIN6_gc = (0x46<<0),  /* Port G Pin 6 */
    EVSYS_CHANNEL6_PORTG_PIN7_gc = (0x47<<0),  /* Port G Pin 7 */
    EVSYS_CHANNEL6_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL6_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL6_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL6_USART3_XCK_gc = (0x63<<0),  /* USART 3 XCK */
    EVSYS_CHANNEL6_USART4_XCK_gc = (0x64<<0),  /* USART 4 XCK */
    EVSYS_CHANNEL6_USART5_XCK_gc = (0x65<<0),  /* USART 5 XCK */
    EVSYS_CHANNEL6_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL6_SPI1_SCK_gc = (0x69<<0),  /* SPI 1 SCK */
    EVSYS_CHANNEL6_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL6_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL6_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL6_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL6_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL6_TCA1_OVF_LUNF_gc = (0x88<<0),  /* Timer/Counter A1 overflow / low byte timer underflow */
    EVSYS_CHANNEL6_TCA1_HUNF_gc = (0x89<<0),  /* Timer/Counter A1 high byte timer underflow */
    EVSYS_CHANNEL6_TCA1_CMP0_LCMP0_gc = (0x8C<<0),  /* Timer/Counter A1 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL6_TCA1_CMP1_LCMP1_gc = (0x8D<<0),  /* Timer/Counter A1 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL6_TCA1_CMP2_LCMP2_gc = (0x8E<<0),  /* Timer/Counter A1 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL6_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL6_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL6_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL6_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL6_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL6_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL6_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL6_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL6_TCB4_CAPT_gc = (0xA8<<0),  /* Timer/Counter B4 capture */
    EVSYS_CHANNEL6_TCB4_OVF_gc = (0xA9<<0),  /* Timer/Counter B4 overflow */
    EVSYS_CHANNEL6_TCD0_CMPBCLR_gc = (0xB0<<0),  /* Timer/Counter D0 event 0 */
    EVSYS_CHANNEL6_TCD0_CMPASET_gc = (0xB1<<0),  /* Timer/Counter D0 event 1 */
    EVSYS_CHANNEL6_TCD0_CMPBSET_gc = (0xB2<<0),  /* Timer/Counter D0 event 2 */
    EVSYS_CHANNEL6_TCD0_PROGEV_gc = (0xB3<<0)  /* Timer/Counter D0 event 3 */
} EVSYS_CHANNEL6_t;

/* Channel 7 generator select */
typedef enum EVSYS_CHANNEL7_enum
{
    EVSYS_CHANNEL7_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL7_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI sync character */
    EVSYS_CHANNEL7_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL7_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL7_RTC_PIT_DIV512_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL7_RTC_PIT_DIV256_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL7_RTC_PIT_DIV128_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL7_RTC_PIT_DIV64_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL7_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL7_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL7_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL7_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL7_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL7_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL7_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL7_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL7_AC2_OUT_gc = (0x22<<0),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL7_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL7_PTC_RESRDY_gc = (0x28<<0),  /* PTC Result Ready */
    EVSYS_CHANNEL7_ZCD0_gc = (0x30<<0),  /* Zero Cross Detect 0 out */
    EVSYS_CHANNEL7_ZCD1_gc = (0x31<<0),  /* Zero Cross Detect 1 out */
    EVSYS_CHANNEL7_ZCD2_gc = (0x32<<0),  /* Zero Cross Detect 2 out */
    EVSYS_CHANNEL7_PORTG_PIN0_gc = (0x40<<0),  /* Port G Pin 0 */
    EVSYS_CHANNEL7_PORTG_PIN1_gc = (0x41<<0),  /* Port G Pin 1 */
    EVSYS_CHANNEL7_PORTG_PIN2_gc = (0x42<<0),  /* Port G Pin 2 */
    EVSYS_CHANNEL7_PORTG_PIN3_gc = (0x43<<0),  /* Port G Pin 3 */
    EVSYS_CHANNEL7_PORTG_PIN4_gc = (0x44<<0),  /* Port G Pin 4 */
    EVSYS_CHANNEL7_PORTG_PIN5_gc = (0x45<<0),  /* Port G Pin 5 */
    EVSYS_CHANNEL7_PORTG_PIN6_gc = (0x46<<0),  /* Port G Pin 6 */
    EVSYS_CHANNEL7_PORTG_PIN7_gc = (0x47<<0),  /* Port G Pin 7 */
    EVSYS_CHANNEL7_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL7_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL7_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL7_USART3_XCK_gc = (0x63<<0),  /* USART 3 XCK */
    EVSYS_CHANNEL7_USART4_XCK_gc = (0x64<<0),  /* USART 4 XCK */
    EVSYS_CHANNEL7_USART5_XCK_gc = (0x65<<0),  /* USART 5 XCK */
    EVSYS_CHANNEL7_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL7_SPI1_SCK_gc = (0x69<<0),  /* SPI 1 SCK */
    EVSYS_CHANNEL7_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL7_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL7_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL7_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL7_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL7_TCA1_OVF_LUNF_gc = (0x88<<0),  /* Timer/Counter A1 overflow / low byte timer underflow */
    EVSYS_CHANNEL7_TCA1_HUNF_gc = (0x89<<0),  /* Timer/Counter A1 high byte timer underflow */
    EVSYS_CHANNEL7_TCA1_CMP0_LCMP0_gc = (0x8C<<0),  /* Timer/Counter A1 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL7_TCA1_CMP1_LCMP1_gc = (0x8D<<0),  /* Timer/Counter A1 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL7_TCA1_CMP2_LCMP2_gc = (0x8E<<0),  /* Timer/Counter A1 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL7_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL7_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL7_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL7_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL7_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL7_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL7_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL7_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL7_TCB4_CAPT_gc = (0xA8<<0),  /* Timer/Counter B4 capture */
    EVSYS_CHANNEL7_TCB4_OVF_gc = (0xA9<<0),  /* Timer/Counter B4 overflow */
    EVSYS_CHANNEL7_TCD0_CMPBCLR_gc = (0xB0<<0),  /* Timer/Counter D0 event 0 */
    EVSYS_CHANNEL7_TCD0_CMPASET_gc = (0xB1<<0),  /* Timer/Counter D0 event 1 */
    EVSYS_CHANNEL7_TCD0_CMPBSET_gc = (0xB2<<0),  /* Timer/Counter D0 event 2 */
    EVSYS_CHANNEL7_TCD0_PROGEV_gc = (0xB3<<0)  /* Timer/Counter D0 event 3 */
} EVSYS_CHANNEL7_t;

/* Channel 8 generator select */
typedef enum EVSYS_CHANNEL8_enum
{
    EVSYS_CHANNEL8_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL8_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI sync character */
    EVSYS_CHANNEL8_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL8_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL8_RTC_PIT_DIV8192_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL8_RTC_PIT_DIV4096_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL8_RTC_PIT_DIV2048_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL8_RTC_PIT_DIV1024_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL8_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL8_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL8_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL8_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL8_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL8_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL8_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL8_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL8_AC2_OUT_gc = (0x22<<0),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL8_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL8_PTC_RESRDY_gc = (0x28<<0),  /* PTC Result Ready */
    EVSYS_CHANNEL8_ZCD0_gc = (0x30<<0),  /* Zero Cross Detect 0 out */
    EVSYS_CHANNEL8_ZCD1_gc = (0x31<<0),  /* Zero Cross Detect 1 out */
    EVSYS_CHANNEL8_ZCD2_gc = (0x32<<0),  /* Zero Cross Detect 2 out */
    EVSYS_CHANNEL8_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL8_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL8_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL8_USART3_XCK_gc = (0x63<<0),  /* USART 3 XCK */
    EVSYS_CHANNEL8_USART4_XCK_gc = (0x64<<0),  /* USART 4 XCK */
    EVSYS_CHANNEL8_USART5_XCK_gc = (0x65<<0),  /* USART 5 XCK */
    EVSYS_CHANNEL8_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL8_SPI1_SCK_gc = (0x69<<0),  /* SPI 1 SCK */
    EVSYS_CHANNEL8_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL8_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL8_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL8_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL8_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL8_TCA1_OVF_LUNF_gc = (0x88<<0),  /* Timer/Counter A1 overflow / low byte timer underflow */
    EVSYS_CHANNEL8_TCA1_HUNF_gc = (0x89<<0),  /* Timer/Counter A1 high byte timer underflow */
    EVSYS_CHANNEL8_TCA1_CMP0_LCMP0_gc = (0x8C<<0),  /* Timer/Counter A1 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL8_TCA1_CMP1_LCMP1_gc = (0x8D<<0),  /* Timer/Counter A1 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL8_TCA1_CMP2_LCMP2_gc = (0x8E<<0),  /* Timer/Counter A1 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL8_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL8_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL8_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL8_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL8_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL8_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL8_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL8_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL8_TCB4_CAPT_gc = (0xA8<<0),  /* Timer/Counter B4 capture */
    EVSYS_CHANNEL8_TCB4_OVF_gc = (0xA9<<0),  /* Timer/Counter B4 overflow */
    EVSYS_CHANNEL8_TCD0_CMPBCLR_gc = (0xB0<<0),  /* Timer/Counter D0 event 0 */
    EVSYS_CHANNEL8_TCD0_CMPASET_gc = (0xB1<<0),  /* Timer/Counter D0 event 1 */
    EVSYS_CHANNEL8_TCD0_CMPBSET_gc = (0xB2<<0),  /* Timer/Counter D0 event 2 */
    EVSYS_CHANNEL8_TCD0_PROGEV_gc = (0xB3<<0)  /* Timer/Counter D0 event 3 */
} EVSYS_CHANNEL8_t;

/* Channel 9 generator select */
typedef enum EVSYS_CHANNEL9_enum
{
    EVSYS_CHANNEL9_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL9_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI sync character */
    EVSYS_CHANNEL9_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL9_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL9_RTC_PIT_DIV8192_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL9_RTC_PIT_DIV4096_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL9_RTC_PIT_DIV2048_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL9_RTC_PIT_DIV1024_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL9_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL9_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL9_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL9_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL9_CCL_LUT4_gc = (0x14<<0),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL9_CCL_LUT5_gc = (0x15<<0),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL9_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL9_AC1_OUT_gc = (0x21<<0),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL9_AC2_OUT_gc = (0x22<<0),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL9_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL9_PTC_RESRDY_gc = (0x28<<0),  /* PTC Result Ready */
    EVSYS_CHANNEL9_ZCD0_gc = (0x30<<0),  /* Zero Cross Detect 0 out */
    EVSYS_CHANNEL9_ZCD1_gc = (0x31<<0),  /* Zero Cross Detect 1 out */
    EVSYS_CHANNEL9_ZCD2_gc = (0x32<<0),  /* Zero Cross Detect 2 out */
    EVSYS_CHANNEL9_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL9_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL9_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL9_USART3_XCK_gc = (0x63<<0),  /* USART 3 XCK */
    EVSYS_CHANNEL9_USART4_XCK_gc = (0x64<<0),  /* USART 4 XCK */
    EVSYS_CHANNEL9_USART5_XCK_gc = (0x65<<0),  /* USART 5 XCK */
    EVSYS_CHANNEL9_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL9_SPI1_SCK_gc = (0x69<<0),  /* SPI 1 SCK */
    EVSYS_CHANNEL9_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL9_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL9_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL9_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL9_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL9_TCA1_OVF_LUNF_gc = (0x88<<0),  /* Timer/Counter A1 overflow / low byte timer underflow */
    EVSYS_CHANNEL9_TCA1_HUNF_gc = (0x89<<0),  /* Timer/Counter A1 high byte timer underflow */
    EVSYS_CHANNEL9_TCA1_CMP0_LCMP0_gc = (0x8C<<0),  /* Timer/Counter A1 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL9_TCA1_CMP1_LCMP1_gc = (0x8D<<0),  /* Timer/Counter A1 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL9_TCA1_CMP2_LCMP2_gc = (0x8E<<0),  /* Timer/Counter A1 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL9_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL9_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL9_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL9_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL9_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL9_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL9_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL9_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL9_TCB4_CAPT_gc = (0xA8<<0),  /* Timer/Counter B4 capture */
    EVSYS_CHANNEL9_TCB4_OVF_gc = (0xA9<<0),  /* Timer/Counter B4 overflow */
    EVSYS_CHANNEL9_TCD0_CMPBCLR_gc = (0xB0<<0),  /* Timer/Counter D0 event 0 */
    EVSYS_CHANNEL9_TCD0_CMPASET_gc = (0xB1<<0),  /* Timer/Counter D0 event 1 */
    EVSYS_CHANNEL9_TCD0_CMPBSET_gc = (0xB2<<0),  /* Timer/Counter D0 event 2 */
    EVSYS_CHANNEL9_TCD0_PROGEV_gc = (0xB3<<0)  /* Timer/Counter D0 event 3 */
} EVSYS_CHANNEL9_t;

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

/* Software event on channel select */
typedef enum EVSYS_SWEVENTB_enum
{
    EVSYS_SWEVENTB_CH8_gc = (0x00<<0),  /* Software event on channel 8 */
    EVSYS_SWEVENTB_CH9_gc = (0x01<<0)  /* Software event on channel 9 */
} EVSYS_SWEVENTB_t;

/* User channel select */
typedef enum EVSYS_USER_enum
{
    EVSYS_USER_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_USER_CHANNEL0_gc = (0x01<<0),  /* Connect user to event channel 0 */
    EVSYS_USER_CHANNEL1_gc = (0x02<<0),  /* Connect user to event channel 1 */
    EVSYS_USER_CHANNEL2_gc = (0x03<<0),  /* Connect user to event channel 2 */
    EVSYS_USER_CHANNEL3_gc = (0x04<<0),  /* Connect user to event channel 3 */
    EVSYS_USER_CHANNEL4_gc = (0x05<<0),  /* Connect user to event channel 4 */
    EVSYS_USER_CHANNEL5_gc = (0x06<<0),  /* Connect user to event channel 5 */
    EVSYS_USER_CHANNEL6_gc = (0x07<<0),  /* Connect user to event channel 6 */
    EVSYS_USER_CHANNEL7_gc = (0x08<<0),  /* Connect user to event channel 7 */
    EVSYS_USER_CHANNEL8_gc = (0x09<<0),  /* Connect user to event channel 8 */
    EVSYS_USER_CHANNEL9_gc = (0x0A<<0)  /* Connect user to event channel 9 */
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
NVMBIST - BIST in the NVMCTRL module
--------------------------------------------------------------------------
*/

/* BIST in the NVMCTRL module */
typedef struct NVMBIST_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t ADDRPAT;  /* Address pattern */
    register8_t DATAPAT;  /* Data pattern */
    register8_t STATUS;  /* Status */
    _WORDREGISTER(CNT);  /* Count */
    _DWORDREGISTER(END);  /* End */
    register8_t reserved_1[6];
} NVMBIST_t;

/* Address mode select */
typedef enum NVMBIST_AMODE_enum
{
    NVMBIST_AMODE_NORMAL_gc = (0x00<<4),  /* No special address pattern */
    NVMBIST_AMODE_COMPLEMENT_gc = (0x04<<4)  /* Post complement address */
} NVMBIST_AMODE_t;

/* Command select */
typedef enum NVMBIST_CMD_enum
{
    NVMBIST_CMD_NOCMD_gc = (0x00<<0),  /* No effect */
    NVMBIST_CMD_START_gc = (0x01<<0),  /* Start BIST testing */
    NVMBIST_CMD_CONTINUE_gc = (0x02<<0),  /* Continue BIST testing */
    NVMBIST_CMD_BREAK_gc = (0x03<<0)  /* Stop BIST and go to BREAK state */
} NVMBIST_CMD_t;

/* Data check pattern select */
typedef enum NVMBIST_PATTERN_enum
{
    NVMBIST_PATTERN_ZERO_gc = (0x00<<0),  /* Entire memory written to 0 */
    NVMBIST_PATTERN_CHECKERBOARD_gc = (0x01<<0),  /* Physical checkerboard in flash, first location 0 */
    NVMBIST_PATTERN_CHECKERINV_gc = (0x02<<0),  /* Physical checkerboard in flash, first location 1 */
    NVMBIST_PATTERN_ONE_gc = (0x03<<0)  /* Entire flash erased or written to 1 */
} NVMBIST_PATTERN_t;

/* FSM State select */
typedef enum NVMBIST_STATE_enum
{
    NVMBIST_STATE_IDLE_gc = (0x00<<0),  /* Reset state */
    NVMBIST_STATE_BREAK_gc = (0x01<<0),  /* Break command used */
    NVMBIST_STATE_FAILED0_gc = (0x04<<0),  /* Test failed, data from last address */
    NVMBIST_STATE_FAILED1_gc = (0x05<<0),  /* Test failed, data from address-1 */
    NVMBIST_STATE_FAILED2_gc = (0x06<<0),  /* Test failed, data from address-2 */
    NVMBIST_STATE_SUCCESS_gc = (0x07<<0),  /* Test success */
    NVMBIST_STATE_START0_gc = (0x08<<0),  /* Startup, fetching first data */
    NVMBIST_STATE_START1_gc = (0x09<<0),  /* Startup, fetching second data */
    NVMBIST_STATE_RESTART0_gc = (0x0A<<0),  /* Re-start from BREAK or FAILED2 */
    NVMBIST_STATE_RESTART1_gc = (0x0B<<0),  /* Re-start from FAILED1 */
    NVMBIST_STATE_RUNNING_gc = (0x0C<<0),  /* Test running */
    NVMBIST_STATE_FINISH0_gc = (0x0E<<0),  /* Check last word */
    NVMBIST_STATE_FINISH1_gc = (0x0F<<0)  /* Count faults in last word */
} NVMBIST_STATE_t;

/* X address mode select */
typedef enum NVMBIST_XMODE_enum
{
    NVMBIST_XMODE_STATIC_gc = (0x00<<0),  /* X static */
    NVMBIST_XMODE_CARRY_gc = (0x01<<0),  /* Carry/borrow from Y */
    NVMBIST_XMODE_INC_gc = (0x02<<0),  /* X increment each cycle */
    NVMBIST_XMODE_DEC_gc = (0x03<<0)  /* X decrement each cycle */
} NVMBIST_XMODE_t;

/* Y address mode select */
typedef enum NVMBIST_YMODE_enum
{
    NVMBIST_YMODE_STATIC_gc = (0x00<<2),  /* Y static */
    NVMBIST_YMODE_CARRY_gc = (0x01<<2),  /* Carry/borrow from X */
    NVMBIST_YMODE_INC_gc = (0x02<<2),  /* Y increment each cycle */
    NVMBIST_YMODE_DEC_gc = (0x03<<2)  /* Y decrement each cycle */
} NVMBIST_YMODE_t;

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
OSCTEST - Oscillator test interface
--------------------------------------------------------------------------
*/

/* Oscillator test interface */
typedef struct OSCTEST_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t reserved_1[1];
} OSCTEST_t;

/* Prescaler select */
typedef enum OSCTEST_PRESCSEL_enum
{
    OSCTEST_PRESCSEL_1X_gc = (0x00<<4),  /* 1x */
    OSCTEST_PRESCSEL_2X_gc = (0x01<<4),  /* 2x */
    OSCTEST_PRESCSEL_4X_gc = (0x02<<4),  /* 4x */
    OSCTEST_PRESCSEL_8X_gc = (0x03<<4),  /* 8x */
    OSCTEST_PRESCSEL_16X_gc = (0x04<<4),  /* 16x */
    OSCTEST_PRESCSEL_32X_gc = (0x05<<4),  /* 32x */
    OSCTEST_PRESCSEL_64X_gc = (0x06<<4),  /* 64x */
    OSCTEST_PRESCSEL_128X_gc = (0x07<<4)  /* 128x */
} OSCTEST_PRESCSEL_t;

/* Sorce select */
typedef enum OSCTEST_SRCSEL_enum
{
    OSCTEST_SRCSEL_OFF_gc = (0x00<<0),  /* No oscillator selected */
    OSCTEST_SRCSEL_EVENT_gc = (0x01<<0),  /* Async event */
    OSCTEST_SRCSEL_EXTCLK_gc = (0x02<<0),  /* External clock */
    OSCTEST_SRCSEL_OSCPDI_gc = (0x03<<0),  /* PDI oscillator */
    OSCTEST_SRCSEL_OSCHF_gc = (0x04<<0),  /* High-frequency oscillator */
    OSCTEST_SRCSEL_OSC32K_gc = (0x05<<0),  /* 32.768kHz internal osciillator */
    OSCTEST_SRCSEL_XOSC32K_gc = (0x06<<0),  /* 32.768kHz crystal oscillator */
    OSCTEST_SRCSEL_PLL_gc = (0x07<<0),  /* PLL */
    OSCTEST_SRCSEL_OSC600K_gc = (0x08<<0),  /* 600 kHz oscillator */
    OSCTEST_SRCSEL_OSCHF1M_gc = (0x09<<0),  /* 1MHz from internal high-frequency oscillator */
    OSCTEST_SRCSEL_CLKMAIN_gc = (0x0A<<0),  /* Main clock */
    OSCTEST_SRCSEL_DACBUF_gc = (0x0B<<0)  /* Clock inside DAC output buffer */
} OSCTEST_SRCSEL_t;

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
    register8_t PINCTRLLD;  /* Pin Control Load */
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
    register8_t USARTROUTEB;  /* USART route B */
    register8_t SPIROUTEA;  /* SPI route A */
    register8_t TWIROUTEA;  /* TWI route A */
    register8_t TCAROUTEA;  /* TCA route A */
    register8_t TCBROUTEA;  /* TCB route A */
    register8_t TCDROUTEA;  /* TCD route A */
    register8_t ACROUTEA;  /* AC route A */
    register8_t ZCDROUTEA;  /* ZCD route A */
    register8_t reserved_1[4];
    register8_t EEXROUTEA;  /* EEX route A */
} PORTMUX_t;

/* External Break select */
typedef enum PORTMUX_EXTBRK_enum
{
    PORTMUX_EXTBRK_DEFAULT_gc = (0x00<<7),  /* Default pin */
    PORTMUX_EXTBRK_ALTERNATE_gc = (0x01<<7)  /* Alternate pin */
} PORTMUX_EXTBRK_t;

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
    register8_t reserved_3[10];
} RTC_t;

/* Clock Select */
typedef enum RTC_CLKSEL_enum
{
    RTC_CLKSEL_OSC32K_gc = (0x00<<0),  /* Internal 32.768 kHz oscillator */
    RTC_CLKSEL_OSC1K_gc = (0x01<<0),  /* Internal 1.024 kHz oscillator */
    RTC_CLKSEL_XOSC32K_gc = (0x02<<0),  /* 32.768 kHz crystal oscillator */
    RTC_CLKSEL_EXTCLK_gc = (0x03<<0)  /* External Clock */
} RTC_CLKSEL_t;

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
    register8_t VREGCTRL;  /* VREGCTRL */
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
    SLPCTRL_PMODE_AUTO_gc = (0x00<<0),  /* AUTO */
    SLPCTRL_PMODE_FULL_gc = (0x01<<0),  /* FULL */
    SLPCTRL_PMODE_REDUCED_gc = (0x02<<0),  /* REDUCED */
    SLPCTRL_PMODE_AUTOLF_gc = (0x03<<0)  /* AUTOLF */
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
TCA - 16-bit Timer/Counter Type A
--------------------------------------------------------------------------
*/

/* 16-bit Timer/Counter Type A - 16-bit Timer/Counter Type A - Single Mode */
typedef struct TCA_SINGLE_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLECLR;  /* Control E Clear */
    register8_t CTRLESET;  /* Control E Set */
    register8_t CTRLFCLR;  /* Control F Clear */
    register8_t CTRLFSET;  /* Control F Set */
    register8_t reserved_1[1];
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_2[2];
    register8_t DBGCTRL;  /* Degbug Control */
    register8_t TEMP;  /* Temporary data for 16-bit Access */
    register8_t reserved_3[16];
    _WORDREGISTER(CNT);  /* Count */
    register8_t reserved_4[4];
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CMP0);  /* Compare 0 */
    _WORDREGISTER(CMP1);  /* Compare 1 */
    _WORDREGISTER(CMP2);  /* Compare 2 */
    register8_t reserved_5[8];
    _WORDREGISTER(PERBUF);  /* Period Buffer */
    _WORDREGISTER(CMP0BUF);  /* Compare 0 Buffer */
    _WORDREGISTER(CMP1BUF);  /* Compare 1 Buffer */
    _WORDREGISTER(CMP2BUF);  /* Compare 2 Buffer */
    register8_t reserved_6[2];
} TCA_SINGLE_t;

/* 16-bit Timer/Counter Type A - 16-bit Timer/Counter Type A - Split Mode */
typedef struct TCA_SPLIT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLECLR;  /* Control E Clear */
    register8_t CTRLESET;  /* Control E Set */
    register8_t reserved_1[4];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_2[2];
    register8_t DBGCTRL;  /* Degbug Control */
    register8_t reserved_3[17];
    register8_t LCNT;  /* Low Count */
    register8_t HCNT;  /* High Count */
    register8_t reserved_4[4];
    register8_t LPER;  /* Low Period */
    register8_t HPER;  /* High Period */
    register8_t LCMP0;  /* Low Compare */
    register8_t HCMP0;  /* High Compare */
    register8_t LCMP1;  /* Low Compare */
    register8_t HCMP1;  /* High Compare */
    register8_t LCMP2;  /* Low Compare */
    register8_t HCMP2;  /* High Compare */
    register8_t reserved_5[18];
} TCA_SPLIT_t;

/* 16-bit Timer/Counter Type A */
typedef union TCA_union
{
    TCA_SINGLE_t SINGLE;  /* 16-bit Timer/Counter Type A - Single Mode */
    TCA_SPLIT_t SPLIT;  /* 16-bit Timer/Counter Type A - Split Mode */
} TCA_t;

/* Clock Selection */
typedef enum TCA_SINGLE_CLKSEL_enum
{
    TCA_SINGLE_CLKSEL_DIV1_gc = (0x00<<1),  /* System Clock */
    TCA_SINGLE_CLKSEL_DIV2_gc = (0x01<<1),  /* System Clock / 2 */
    TCA_SINGLE_CLKSEL_DIV4_gc = (0x02<<1),  /* System Clock / 4 */
    TCA_SINGLE_CLKSEL_DIV8_gc = (0x03<<1),  /* System Clock / 8 */
    TCA_SINGLE_CLKSEL_DIV16_gc = (0x04<<1),  /* System Clock / 16 */
    TCA_SINGLE_CLKSEL_DIV64_gc = (0x05<<1),  /* System Clock / 64 */
    TCA_SINGLE_CLKSEL_DIV256_gc = (0x06<<1),  /* System Clock / 256 */
    TCA_SINGLE_CLKSEL_DIV1024_gc = (0x07<<1)  /* System Clock / 1024 */
} TCA_SINGLE_CLKSEL_t;

/* Command select */
typedef enum TCA_SINGLE_CMD_enum
{
    TCA_SINGLE_CMD_NONE_gc = (0x00<<2),  /* No Command */
    TCA_SINGLE_CMD_UPDATE_gc = (0x01<<2),  /* Force Update */
    TCA_SINGLE_CMD_RESTART_gc = (0x02<<2),  /* Force Restart */
    TCA_SINGLE_CMD_RESET_gc = (0x03<<2)  /* Force Hard Reset */
} TCA_SINGLE_CMD_t;

/* Direction select */
typedef enum TCA_SINGLE_DIR_enum
{
    TCA_SINGLE_DIR_UP_gc = (0x00<<0),  /* Count up */
    TCA_SINGLE_DIR_DOWN_gc = (0x01<<0)  /* Count down */
} TCA_SINGLE_DIR_t;

/* Event Action A select */
typedef enum TCA_SINGLE_EVACTA_enum
{
    TCA_SINGLE_EVACTA_CNT_POSEDGE_gc = (0x00<<1),  /* Count on positive edge event */
    TCA_SINGLE_EVACTA_CNT_ANYEDGE_gc = (0x01<<1),  /* Count on any edge event */
    TCA_SINGLE_EVACTA_CNT_HIGHLVL_gc = (0x02<<1),  /* Count on prescaled clock while event line is 1. */
    TCA_SINGLE_EVACTA_UPDOWN_gc = (0x03<<1)  /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
} TCA_SINGLE_EVACTA_t;

/* Event Action B select */
typedef enum TCA_SINGLE_EVACTB_enum
{
    TCA_SINGLE_EVACTB_UPDOWN_gc = (0x03<<5),  /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
    TCA_SINGLE_EVACTB_RESTART_POSEDGE_gc = (0x04<<5),  /* Restart counter at positive edge event */
    TCA_SINGLE_EVACTB_RESTART_ANYEDGE_gc = (0x05<<5),  /* Restart counter on any edge event */
    TCA_SINGLE_EVACTB_RESTART_HIGHLVL_gc = (0x06<<5)  /* Restart counter while event line is 1. */
} TCA_SINGLE_EVACTB_t;

/* Waveform generation mode select */
typedef enum TCA_SINGLE_WGMODE_enum
{
    TCA_SINGLE_WGMODE_NORMAL_gc = (0x00<<0),  /* Normal Mode */
    TCA_SINGLE_WGMODE_FRQ_gc = (0x01<<0),  /* Frequency Generation Mode */
    TCA_SINGLE_WGMODE_SINGLESLOPE_gc = (0x03<<0),  /* Single Slope PWM */
    TCA_SINGLE_WGMODE_DSTOP_gc = (0x05<<0),  /* Dual Slope PWM, overflow on TOP */
    TCA_SINGLE_WGMODE_DSBOTH_gc = (0x06<<0),  /* Dual Slope PWM, overflow on TOP and BOTTOM */
    TCA_SINGLE_WGMODE_DSBOTTOM_gc = (0x07<<0)  /* Dual Slope PWM, overflow on BOTTOM */
} TCA_SINGLE_WGMODE_t;

/* Clock Selection */
typedef enum TCA_SPLIT_CLKSEL_enum
{
    TCA_SPLIT_CLKSEL_DIV1_gc = (0x00<<1),  /* System Clock */
    TCA_SPLIT_CLKSEL_DIV2_gc = (0x01<<1),  /* System Clock / 2 */
    TCA_SPLIT_CLKSEL_DIV4_gc = (0x02<<1),  /* System Clock / 4 */
    TCA_SPLIT_CLKSEL_DIV8_gc = (0x03<<1),  /* System Clock / 8 */
    TCA_SPLIT_CLKSEL_DIV16_gc = (0x04<<1),  /* System Clock / 16 */
    TCA_SPLIT_CLKSEL_DIV64_gc = (0x05<<1),  /* System Clock / 64 */
    TCA_SPLIT_CLKSEL_DIV256_gc = (0x06<<1),  /* System Clock / 256 */
    TCA_SPLIT_CLKSEL_DIV1024_gc = (0x07<<1)  /* System Clock / 1024 */
} TCA_SPLIT_CLKSEL_t;

/* Command select */
typedef enum TCA_SPLIT_CMD_enum
{
    TCA_SPLIT_CMD_NONE_gc = (0x00<<2),  /* No Command */
    TCA_SPLIT_CMD_UPDATE_gc = (0x01<<2),  /* Force Update */
    TCA_SPLIT_CMD_RESTART_gc = (0x02<<2),  /* Force Restart */
    TCA_SPLIT_CMD_RESET_gc = (0x03<<2)  /* Force Hard Reset */
} TCA_SPLIT_CMD_t;

/* Command Enable select */
typedef enum TCA_SPLIT_CMDEN_enum
{
    TCA_SPLIT_CMDEN_NONE_gc = (0x00<<0),  /* None */
    TCA_SPLIT_CMDEN_BOTH_gc = (0x03<<0)  /* Both low byte and high byte counter */
} TCA_SPLIT_CMDEN_t;

/*
--------------------------------------------------------------------------
TCB - 16-bit Timer Type B
--------------------------------------------------------------------------
*/

/* 16-bit Timer Type B */
typedef struct TCB_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control Register B */
    register8_t reserved_1[2];
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
    TCB_CLKSEL_DIV1_gc = (0x00<<1),  /* CLK_PEP */
    TCB_CLKSEL_DIV2_gc = (0x01<<1),  /* CLK_PER/2 */
    TCB_CLKSEL_TCA0_gc = (0x02<<1),  /* Use CLK_TCA from TCA0 */
    TCB_CLKSEL_TCA1_gc = (0x03<<1),  /* Use CLK_TCA from TCA1 */
    TCB_CLKSEL_TCA2_gc = (0x04<<1),  /* Use CLK_TCA from TCA2 */
    TCB_CLKSEL_TCA3_gc = (0x05<<1),  /* Use CLK_TCA from TCA3 */
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

/*
--------------------------------------------------------------------------
TCD - Timer Counter D
--------------------------------------------------------------------------
*/

/* Timer Counter D */
typedef struct TCD_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLE;  /* Control E */
    register8_t reserved_1[3];
    register8_t EVCTRLA;  /* EVCTRLA */
    register8_t EVCTRLB;  /* EVCTRLB */
    register8_t reserved_2[2];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t reserved_3[1];
    register8_t INPUTCTRLA;  /* Input Control A */
    register8_t INPUTCTRLB;  /* Input Control B */
    register8_t FAULTCTRL;  /* Fault Control */
    register8_t reserved_4[1];
    register8_t DLYCTRL;  /* Delay Control */
    register8_t DLYVAL;  /* Delay value */
    register8_t reserved_5[2];
    register8_t DITCTRL;  /* Dither Control A */
    register8_t DITVAL;  /* Dither value */
    register8_t reserved_6[4];
    register8_t DBGCTRL;  /* Debug Control */
    register8_t reserved_7[3];
    _WORDREGISTER(CAPTUREA);  /* Capture A */
    _WORDREGISTER(CAPTUREB);  /* Capture B */
    register8_t reserved_8[2];
    _WORDREGISTER(CMPASET);  /* Compare A Set */
    _WORDREGISTER(CMPACLR);  /* Compare A Clear */
    _WORDREGISTER(CMPBSET);  /* Compare B Set */
    _WORDREGISTER(CMPBCLR);  /* Compare B Clear */
    register8_t reserved_9[16];
} TCD_t;

/* event action select */
typedef enum TCD_ACTION_enum
{
    TCD_ACTION_FAULT_gc = (0x00<<2),  /* Event trigger a fault */
    TCD_ACTION_CAPTURE_gc = (0x01<<2)  /* Event trigger a fault and capture */
} TCD_ACTION_t;

/* event config select */
typedef enum TCD_CFG_enum
{
    TCD_CFG_NEITHER_gc = (0x00<<6),  /* Neither Filter nor Asynchronous Event is enabled */
    TCD_CFG_FILTER_gc = (0x01<<6),  /* Input Capture Noise Cancellation Filter enabled */
    TCD_CFG_ASYNC_gc = (0x02<<6)  /* Asynchronous Event output qualification enabled */
} TCD_CFG_t;

/* clock select */
typedef enum TCD_CLKSEL_enum
{
    TCD_CLKSEL_OSCHF_gc = (0x00<<5),  /* High-frequency oscillator */
    TCD_CLKSEL_PLL_gc = (0x01<<5),  /* PLL oscillator */
    TCD_CLKSEL_EXTCLK_gc = (0x02<<5),  /* External clock */
    TCD_CLKSEL_CLKPER_gc = (0x03<<5)  /* System clock */
} TCD_CLKSEL_t;

/* Compare C output select */
typedef enum TCD_CMPCSEL_enum
{
    TCD_CMPCSEL_PWMA_gc = (0x00<<6),  /* PWM A output */
    TCD_CMPCSEL_PWMB_gc = (0x01<<6)  /* PWM B output */
} TCD_CMPCSEL_t;

/* Compare D output select */
typedef enum TCD_CMPDSEL_enum
{
    TCD_CMPDSEL_PWMA_gc = (0x00<<7),  /* PWM A output */
    TCD_CMPDSEL_PWMB_gc = (0x01<<7)  /* PWM B output */
} TCD_CMPDSEL_t;

/* counter prescaler select */
typedef enum TCD_CNTPRES_enum
{
    TCD_CNTPRES_DIV1_gc = (0x00<<3),  /* Sync clock divided by 1 */
    TCD_CNTPRES_DIV4_gc = (0x01<<3),  /* Sync clock divided by 4 */
    TCD_CNTPRES_DIV32_gc = (0x02<<3)  /* Sync clock divided by 32 */
} TCD_CNTPRES_t;

/* dither select */
typedef enum TCD_DITHERSEL_enum
{
    TCD_DITHERSEL_ONTIMEB_gc = (0x00<<0),  /* On-time ramp B */
    TCD_DITHERSEL_ONTIMEAB_gc = (0x01<<0),  /* On-time ramp A and B */
    TCD_DITHERSEL_DEADTIMEB_gc = (0x02<<0),  /* Dead-time rampB */
    TCD_DITHERSEL_DEADTIMEAB_gc = (0x03<<0)  /* Dead-time ramp A and B */
} TCD_DITHERSEL_t;

/* Delay prescaler select */
typedef enum TCD_DLYPRESC_enum
{
    TCD_DLYPRESC_DIV1_gc = (0x00<<4),  /* No prescaling */
    TCD_DLYPRESC_DIV2_gc = (0x01<<4),  /* Prescale with 2 */
    TCD_DLYPRESC_DIV4_gc = (0x02<<4),  /* Prescale with 4 */
    TCD_DLYPRESC_DIV8_gc = (0x03<<4)  /* Prescale with 8 */
} TCD_DLYPRESC_t;

/* Delay select */
typedef enum TCD_DLYSEL_enum
{
    TCD_DLYSEL_OFF_gc = (0x00<<0),  /* No delay */
    TCD_DLYSEL_INBLANK_gc = (0x01<<0),  /* Input blanking enabled */
    TCD_DLYSEL_EVENT_gc = (0x02<<0)  /* Event delay enabled */
} TCD_DLYSEL_t;

/* Delay trigger select */
typedef enum TCD_DLYTRIG_enum
{
    TCD_DLYTRIG_CMPASET_gc = (0x00<<2),  /* Compare A set */
    TCD_DLYTRIG_CMPACLR_gc = (0x01<<2),  /* Compare A clear */
    TCD_DLYTRIG_CMPBSET_gc = (0x02<<2),  /* Compare B set */
    TCD_DLYTRIG_CMPBCLR_gc = (0x03<<2)  /* Compare B clear */
} TCD_DLYTRIG_t;

/* edge select */
typedef enum TCD_EDGE_enum
{
    TCD_EDGE_FALL_LOW_gc = (0x00<<4),  /* The falling edge or low level of event generates retrigger or fault action */
    TCD_EDGE_RISE_HIGH_gc = (0x01<<4)  /* The rising edge or high level of event generates retrigger or fault action */
} TCD_EDGE_t;

/* Input mode select */
typedef enum TCD_INPUTMODE_enum
{
    TCD_INPUTMODE_NONE_gc = (0x00<<0),  /* Input has no actions */
    TCD_INPUTMODE_JMPWAIT_gc = (0x01<<0),  /* Stop output, jump to opposite compare cycle and wait */
    TCD_INPUTMODE_EXECWAIT_gc = (0x02<<0),  /* Stop output, execute opposite compare cycle and wait */
    TCD_INPUTMODE_EXECFAULT_gc = (0x03<<0),  /* stop output, execute opposite compare cycle while fault active */
    TCD_INPUTMODE_FREQ_gc = (0x04<<0),  /* Stop all outputs, maintain frequency */
    TCD_INPUTMODE_EXECDT_gc = (0x05<<0),  /* Stop all outputs, execute dead time while fault active */
    TCD_INPUTMODE_WAIT_gc = (0x06<<0),  /* Stop all outputs, jump to next compare cycle and wait */
    TCD_INPUTMODE_WAITSW_gc = (0x07<<0),  /* Stop all outputs, wait for software action */
    TCD_INPUTMODE_EDGETRIG_gc = (0x08<<0),  /* Stop output on edge, jump to next compare cycle */
    TCD_INPUTMODE_EDGETRIGFREQ_gc = (0x09<<0),  /* Stop output on edge, maintain frequency */
    TCD_INPUTMODE_LVLTRIGFREQ_gc = (0x0A<<0)  /* Stop output at level, maintain frequency */
} TCD_INPUTMODE_t;

/* Synchronization prescaler select */
typedef enum TCD_SYNCPRES_enum
{
    TCD_SYNCPRES_DIV1_gc = (0x00<<1),  /* Selected clock source divided by 1 */
    TCD_SYNCPRES_DIV2_gc = (0x01<<1),  /* Selected clock source divided by 2 */
    TCD_SYNCPRES_DIV4_gc = (0x02<<1),  /* Selected clock source divided by 4 */
    TCD_SYNCPRES_DIV8_gc = (0x03<<1)  /* Selected clock source divided by 8 */
} TCD_SYNCPRES_t;

/* Waveform generation mode select */
typedef enum TCD_WGMODE_enum
{
    TCD_WGMODE_ONERAMP_gc = (0x00<<0),  /* One ramp mode */
    TCD_WGMODE_TWORAMP_gc = (0x01<<0),  /* Two ramp mode */
    TCD_WGMODE_FOURRAMP_gc = (0x02<<0),  /* Four ramp mode */
    TCD_WGMODE_DS_gc = (0x03<<0)  /* Dual slope mode */
} TCD_WGMODE_t;

/*
--------------------------------------------------------------------------
TESTWIRE - Test Wire
--------------------------------------------------------------------------
*/

/* Test Wire */
typedef struct TESTWIRE_struct
{
    register8_t DTW0CTRL;  /* Digital Test Wire 0 Control */
    register8_t DTW0ROUTE;  /* Digital Test Wire 0 Pin Routing */
    register8_t DTW1CTRL;  /* Digital Test Wire 1 Control */
    register8_t DTW1ROUTE;  /* Digital Test Wire 1 Pin Routing */
    register8_t DTW2CTRL;  /* Digital Test Wire 2 Control */
    register8_t DTW2ROUTE;  /* Digital Test Wire 2 Pin Routing */
    register8_t DTW3CTRL;  /* Digital Test Wire 3 Control */
    register8_t DTW3ROUTE;  /* Digital Test Wire 3 Pin Routing */
    register8_t ATWICTRL;  /* Analog Test Wire Input Pin Control */
    register8_t ATWIROUTE;  /* Analog Test Wire Output Pin Routing */
    register8_t ATWOCTRL;  /* Analog Test Wire Output Pin Control */
    register8_t ATWOROUTE;  /* Analog Test Wire Output Pin Routing */
    register8_t reserved_1[4];
} TESTWIRE_t;


/*
--------------------------------------------------------------------------
TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

/* Two-Wire Interface */
typedef struct TWI_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t DUALCTRL;  /* Dual Control */
    register8_t DBGCTRL;  /* Debug Control Register */
    register8_t MCTRLA;  /* Master Control A */
    register8_t MCTRLB;  /* Master Control B */
    register8_t MSTATUS;  /* Master Status */
    register8_t MBAUD;  /* Master Baud Rate Control */
    register8_t MADDR;  /* Master Address */
    register8_t MDATA;  /* Master Data */
    register8_t SCTRLA;  /* Slave Control A */
    register8_t SCTRLB;  /* Slave Control B */
    register8_t SSTATUS;  /* Slave Status */
    register8_t SADDR;  /* Slave Address */
    register8_t SDATA;  /* Slave Data */
    register8_t SADDRMASK;  /* Slave Address Mask */
    register8_t TEST;  /* Test Configuration */
} TWI_t;

/* Acknowledge Action select */
typedef enum TWI_ACKACT_enum
{
    TWI_ACKACT_ACK_gc = (0x00<<2),  /* Send ACK */
    TWI_ACKACT_NACK_gc = (0x01<<2)  /* Send NACK */
} TWI_ACKACT_t;

/* Slave Address or Stop select */
typedef enum TWI_AP_enum
{
    TWI_AP_STOP_gc = (0x00<<0),  /* Stop condition generated APIF */
    TWI_AP_ADR_gc = (0x01<<0)  /* Address detection generated APIF */
} TWI_AP_t;

/* Bus State select */
typedef enum TWI_BUSSTATE_enum
{
    TWI_BUSSTATE_UNKNOWN_gc = (0x00<<0),  /* Unknown Bus State */
    TWI_BUSSTATE_IDLE_gc = (0x01<<0),  /* Bus is Idle */
    TWI_BUSSTATE_OWNER_gc = (0x02<<0),  /* This Module Controls The Bus */
    TWI_BUSSTATE_BUSY_gc = (0x03<<0)  /* The Bus is Busy */
} TWI_BUSSTATE_t;

/* Input Voltage Transition Level select */
typedef enum TWI_INPUTLVL_enum
{
    TWI_INPUTLVL_I2C_gc = (0x00<<6),  /* I2C input voltage transition level */
    TWI_INPUTLVL_SMBUS_gc = (0x01<<6)  /* SMBus 3.0 input voltage transition level */
} TWI_INPUTLVL_t;

/* Command select */
typedef enum TWI_MCMD_enum
{
    TWI_MCMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_MCMD_REPSTART_gc = (0x01<<0),  /* Issue Repeated Start Condition */
    TWI_MCMD_RECVTRANS_gc = (0x02<<0),  /* Receive or Transmit Data, depending on DIR */
    TWI_MCMD_STOP_gc = (0x03<<0)  /* Issue Stop Condition */
} TWI_MCMD_t;

/* Command select */
typedef enum TWI_SCMD_enum
{
    TWI_SCMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_SCMD_COMPTRANS_gc = (0x02<<0),  /* Used To Complete a Transaction */
    TWI_SCMD_RESPONSE_gc = (0x03<<0)  /* Used in Response to Address/Data Interrupt */
} TWI_SCMD_t;

/* SDA Hold Time select */
typedef enum TWI_SDAHOLD_enum
{
    TWI_SDAHOLD_OFF_gc = (0x00<<2),  /* SDA hold time off */
    TWI_SDAHOLD_50NS_gc = (0x01<<2),  /* Typical 50ns hold time */
    TWI_SDAHOLD_300NS_gc = (0x02<<2),  /* Typical 300ns hold time */
    TWI_SDAHOLD_500NS_gc = (0x03<<2)  /* Typical 500ns hold time */
} TWI_SDAHOLD_t;

/* SDA Setup Time select */
typedef enum TWI_SDASETUP_enum
{
    TWI_SDASETUP_4CYC_gc = (0x00<<4),  /* SDA setup time is 4 clock cycles */
    TWI_SDASETUP_8CYC_gc = (0x01<<4)  /* SDA setup time is 8 clock cycles */
} TWI_SDASETUP_t;

/* Inactive Bus Timeout select */
typedef enum TWI_TIMEOUT_enum
{
    TWI_TIMEOUT_DISABLED_gc = (0x00<<2),  /* Bus Timeout Disabled */
    TWI_TIMEOUT_50US_gc = (0x01<<2),  /* 50 Microseconds */
    TWI_TIMEOUT_100US_gc = (0x02<<2),  /* 100 Microseconds */
    TWI_TIMEOUT_200US_gc = (0x03<<2)  /* 200 Microseconds */
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
    USART_CMODE_MSPI_gc = (0x03<<6)  /* Master SPI Mode */
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
    USART_RS485_OFF_gc = (0x00<<0),  /* RS485 Mode disabled */
    USART_RS485_EXT_gc = (0x01<<0),  /* RS485 Mode External drive */
    USART_RS485_INT_gc = (0x02<<0)  /* RS485 Mode Internal drive */
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
USB - USB Device Controller
--------------------------------------------------------------------------
*/

#define USB_MAX_ENDPOINTS  16

/* USB Device Controller EP */
typedef struct USB_EP_struct
{
    register8_t STATUS;  /* Endpoint Status */
    register8_t CTRL;  /* Endpoint Control */
    _WORDREGISTER(CNT);  /* Endpoint Byte Count */
    _WORDREGISTER(DATAPTR);  /* Endpoint Data Pointer */
    _WORDREGISTER(MCNT);  /* Endpoint Multi-packet Byte Count */
} USB_EP_t;

/* USB Device Controller EP_PAIR */
typedef struct USB_EP_PAIR_struct
{
    USB_EP_t OUT;  /* USB Device Controller OUT */
    USB_EP_t IN;  /* USB Device Controller IN */
} USB_EP_PAIR_t;

/* USB Device Controller EP_TABLE */
typedef struct USB_EP_TABLE_struct
{
    register8_t FIFO[32];  /* FIFO Pointer Table */
    USB_EP_PAIR_t EP[16];  /* USB Device Controller EP */
    _WORDREGISTER(FRAMENUM);  /* FRAMENUM count */
} USB_EP_TABLE_t;

/* USB Device Controller STATUS */
typedef struct USB_STATUS_struct
{
    register8_t OUTCLR;  /* Endpoint n OUT Status Clear */
    register8_t OUTSET;  /* Endpoint n OUT Status Set */
    register8_t INCLR;  /* Endpoint n IN Status Clear */
    register8_t INSET;  /* Endpoint n IN Status Set */
} USB_STATUS_t;

/* USB Device Controller */
typedef struct USB_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t BUSSTATE;  /* Bus State */
    register8_t ADDR;  /* Address */
    register8_t FIFOWP;  /* FIFO Write Pointer */
    register8_t FIFORP;  /* FIFO Read Pointer */
    _WORDREGISTER(EPPTR);  /* Endpoint Configuration Table Pointer */
    register8_t INTCTRLA;  /* Interrupt Control A */
    register8_t INTCTRLB;  /* Interrupt Control B */
    register8_t INTFLAGSA;  /* Interrupt Flags A */
    register8_t INTFLAGSB;  /* Interrupt Flags B */
    register8_t TESTCTRL;  /* Test Control */
    register8_t TESTSTATUS;  /* Test Status */
    register8_t reserved_1[50];
    USB_STATUS_t STATUS[16];  /* USB Device Controller STATUS */
} USB_t;

/* Data Size default select */
typedef enum USB_BUFSIZE_DEFAULT_enum
{
    USB_BUFSIZE_DEFAULT_BUF8_gc = (0x00<<0),  /* 8 bytes buffer size */
    USB_BUFSIZE_DEFAULT_BUF16_gc = (0x01<<0),  /* 16 bytes buffer size */
    USB_BUFSIZE_DEFAULT_BUF32_gc = (0x02<<0),  /* 32 bytes buffer size */
    USB_BUFSIZE_DEFAULT_BUF64_gc = (0x03<<0)  /* 64 bytes buffer size */
} USB_BUFSIZE_DEFAULT_t;

/* Data Size isochronous select */
typedef enum USB_BUFSIZE_ISO_enum
{
    USB_BUFSIZE_ISO_BUF8_gc = (0x00<<0),  /* 8 bytes buffer size */
    USB_BUFSIZE_ISO_BUF16_gc = (0x01<<0),  /* 16 bytes buffer size */
    USB_BUFSIZE_ISO_BUF32_gc = (0x02<<0),  /* 32 bytes buffer size */
    USB_BUFSIZE_ISO_BUF64_gc = (0x03<<0),  /* 64 bytes buffer size */
    USB_BUFSIZE_ISO_BUF128_gc = (0x04<<0),  /* 128 bytes buffer size */
    USB_BUFSIZE_ISO_BUF256_gc = (0x05<<0),  /* 256 bytes buffer size */
    USB_BUFSIZE_ISO_BUF512_gc = (0x06<<0),  /* 512 bytes buffer size */
    USB_BUFSIZE_ISO_BUF1023_gc = (0x07<<0)  /* 1023 bytes buffer size */
} USB_BUFSIZE_ISO_t;

/* Data Toggle select */
typedef enum USB_TOGGLE_enum
{
    USB_TOGGLE_DATA0_gc = (0x00<<0),  /* DATA0 PID in next transaction */
    USB_TOGGLE_DATA1_gc = (0x01<<0)  /* DATA1 PID in next transaction */
} USB_TOGGLE_t;

/* Endpoint type select */
typedef enum USB_TYPE_enum
{
    USB_TYPE_DISABLE_gc = (0x00<<6),  /* Endpoint Disabled */
    USB_TYPE_CONTROL_gc = (0x01<<6),  /* Control */
    USB_TYPE_BULKINT_gc = (0x02<<6),  /* Bulk or Interrupt */
    USB_TYPE_ISO_gc = (0x03<<6)  /* Isochronous */
} USB_TYPE_t;

/* Endpoint Direction select */
typedef enum USB_DIR_enum
{
    USB_DIR_OUT_gc = (0x00<<3),  /* OUT Endpoint */
    USB_DIR_IN_gc = (0x01<<3)  /* In Endpoint */
} USB_DIR_t;

/*
--------------------------------------------------------------------------
USERROW - User Row
--------------------------------------------------------------------------
*/

/* User Row */
typedef struct USERROW_struct
{
    register8_t USERROW0;  /* User Row Byte 0 */
    register8_t USERROW1;  /* User Row Byte 1 */
    register8_t USERROW2;  /* User Row Byte 2 */
    register8_t USERROW3;  /* User Row Byte 3 */
    register8_t USERROW4;  /* User Row Byte 4 */
    register8_t USERROW5;  /* User Row Byte 5 */
    register8_t USERROW6;  /* User Row Byte 6 */
    register8_t USERROW7;  /* User Row Byte 7 */
    register8_t USERROW8;  /* User Row Byte 8 */
    register8_t USERROW9;  /* User Row Byte 9 */
    register8_t USERROW10;  /* User Row Byte 10 */
    register8_t USERROW11;  /* User Row Byte 11 */
    register8_t USERROW12;  /* User Row Byte 12 */
    register8_t USERROW13;  /* User Row Byte 13 */
    register8_t USERROW14;  /* User Row Byte 14 */
    register8_t USERROW15;  /* User Row Byte 15 */
    register8_t USERROW16;  /* User Row Byte 16 */
    register8_t USERROW17;  /* User Row Byte 17 */
    register8_t USERROW18;  /* User Row Byte 18 */
    register8_t USERROW19;  /* User Row Byte 19 */
    register8_t USERROW20;  /* User Row Byte 20 */
    register8_t USERROW21;  /* User Row Byte 21 */
    register8_t USERROW22;  /* User Row Byte 22 */
    register8_t USERROW23;  /* User Row Byte 23 */
    register8_t USERROW24;  /* User Row Byte 24 */
    register8_t USERROW25;  /* User Row Byte 25 */
    register8_t USERROW26;  /* User Row Byte 26 */
    register8_t USERROW27;  /* User Row Byte 27 */
    register8_t USERROW28;  /* User Row Byte 28 */
    register8_t USERROW29;  /* User Row Byte 29 */
    register8_t USERROW30;  /* User Row Byte 30 */
    register8_t USERROW31;  /* User Row Byte 31 */
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
VREF - Voltage reference
--------------------------------------------------------------------------
*/

/* Voltage reference */
typedef struct VREF_struct
{
    register8_t ADC0REF;  /* ADC0 Reference */
    register8_t reserved_1[1];
    register8_t DAC0REF;  /* DAC0 Reference */
    register8_t reserved_2[1];
    register8_t ACREF;  /* AC Reference */
    register8_t reserved_3[1];
    register8_t CALIB;  /* Calibration */
    register8_t TEST;  /* Test */
} VREF_t;

/* Enable offset compensation select */
typedef enum VREF_ACCOMP_enum
{
    VREF_ACCOMP_DISABLE_gc = (0x00<<4),  /* Disable offset compensation */
    VREF_ACCOMP_ENABLE_gc = (0x01<<4)  /* Enable offset compensation */
} VREF_ACCOMP_t;

/* Enable offset compensation select */
typedef enum VREF_ADC0COMP_enum
{
    VREF_ADC0COMP_DISABLE_gc = (0x00<<2),  /* Disable offset compensation */
    VREF_ADC0COMP_ENABLE_gc = (0x01<<2)  /* Enable offset compensation */
} VREF_ADC0COMP_t;

/* ADC0 offset cancellation select */
typedef enum VREF_ADC0OFFSET_enum
{
    VREF_ADC0OFFSET_DISABLE_gc = (0x00<<6),  /* Offset cancellation disabled */
    VREF_ADC0OFFSET_AUTO_gc = (0x01<<6)  /* Offset cancellation enabled when ADC0 is not converting */
} VREF_ADC0OFFSET_t;

/* Enable offset compensation select */
typedef enum VREF_DAC0COMP_enum
{
    VREF_DAC0COMP_DISABLE_gc = (0x00<<3),  /* Disable offset compensation */
    VREF_DAC0COMP_ENABLE_gc = (0x01<<3)  /* Enable offset compensation */
} VREF_DAC0COMP_t;

/* Reference select */
typedef enum VREF_REFSEL_enum
{
    VREF_REFSEL_1V024_gc = (0x00<<0),  /* Internal 1.024V reference */
    VREF_REFSEL_2V048_gc = (0x01<<0),  /* Internal 2.048V reference */
    VREF_REFSEL_4V096_gc = (0x02<<0),  /* Internal 4.096V reference */
    VREF_REFSEL_2V500_gc = (0x03<<0),  /* Internal 2.500V reference */
    VREF_REFSEL_VDD_gc = (0x05<<0),  /* VDD as reference */
    VREF_REFSEL_VREFA_gc = (0x06<<0)  /* External referance on VREFA pin */
} VREF_REFSEL_t;

/* VREFA reference connection select */
typedef enum VREF_VREFASEL_enum
{
    VREF_VREFASEL_DIRECT_gc = (0x00<<1),  /* VREFA is connected directly to peripheral and bypassing AZBUF */
    VREF_VREFASEL_BUFFERED_gc = (0x01<<1)  /* VREFA is connected through Auto-Zero buffer */
} VREF_VREFASEL_t;

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
ZCD - Zero Cross Detect
--------------------------------------------------------------------------
*/

/* Zero Cross Detect */
typedef struct ZCD_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t reserved_1[1];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t STATUS;  /* Status */
    register8_t reserved_2[4];
} ZCD_t;

/* Interrupt Mode select */
typedef enum ZCD_INTMODE_enum
{
    ZCD_INTMODE_NONE_gc = (0x00<<0),  /* No interrupt */
    ZCD_INTMODE_RISING_gc = (0x01<<0),  /* Interrupt on rising input signal */
    ZCD_INTMODE_FALLING_gc = (0x02<<0),  /* Interrupt on falling input signal */
    ZCD_INTMODE_BOTH_gc = (0x03<<0)  /* Interrupt on both rising and falling input signal */
} ZCD_INTMODE_t;

/* Invert signal from pin select */
typedef enum ZCD_INVERT_enum
{
    ZCD_INVERT_BOTHEDGE_gc = (0x00<<3),  /* Any Edge */
    ZCD_INVERT_NEGEDGE_gc = (0x02<<3),  /* Negative Edge */
    ZCD_INVERT_POSEDGE_gc = (0x03<<3)  /* Positive Edge */
} ZCD_INVERT_t;

/* ZCD State select */
typedef enum ZCD_STATE_enum
{
    ZCD_STATE_LOW_gc = (0x00<<4),  /* Output is 0 */
    ZCD_STATE_HIGH_gc = (0x01<<4)  /* Output is 1 */
} ZCD_STATE_t;
/*
==========================================================================
IO Module Instances. Mapped to memory.
==========================================================================
*/

#define VPORTA              (*(VPORT_t *) 0x0000) /* Virtual Ports */
#define VPORTB              (*(VPORT_t *) 0x0004) /* Virtual Ports */
#define VPORTC              (*(VPORT_t *) 0x0008) /* Virtual Ports */
#define VPORTD              (*(VPORT_t *) 0x000C) /* Virtual Ports */
#define VPORTE              (*(VPORT_t *) 0x0010) /* Virtual Ports */
#define VPORTF              (*(VPORT_t *) 0x0014) /* Virtual Ports */
#define VPORTG              (*(VPORT_t *) 0x0018) /* Virtual Ports */
#define RSTCTRL           (*(RSTCTRL_t *) 0x0040) /* Reset controller */
#define SLPCTRL           (*(SLPCTRL_t *) 0x0050) /* Sleep Controller */
#define CLKCTRL           (*(CLKCTRL_t *) 0x0060) /* Clock controller */
#define BOD                   (*(BOD_t *) 0x00A0) /* Bod interface */
#define VREF                 (*(VREF_t *) 0x00B0) /* Voltage reference */
#define WDT                   (*(WDT_t *) 0x0100) /* Watch-Dog Timer */
#define CPUINT             (*(CPUINT_t *) 0x0110) /* Interrupt Controller */
#define CRCSCAN           (*(CRCSCAN_t *) 0x0120) /* CRCSCAN */
#define RTC                   (*(RTC_t *) 0x0140) /* Real-Time Counter */
#define CCL                   (*(CCL_t *) 0x01C0) /* Configurable Custom Logic */
#define EVSYS               (*(EVSYS_t *) 0x0200) /* Event System */
#define USB0                  (*(USB_t *) 0x0280) /* USB Device Controller */
#define PORTA                (*(PORT_t *) 0x0400) /* I/O Ports */
#define PORTB                (*(PORT_t *) 0x0420) /* I/O Ports */
#define PORTC                (*(PORT_t *) 0x0440) /* I/O Ports */
#define PORTD                (*(PORT_t *) 0x0460) /* I/O Ports */
#define PORTE                (*(PORT_t *) 0x0480) /* I/O Ports */
#define PORTMUX           (*(PORTMUX_t *) 0x05E0) /* Port Multiplexer */
#define ADC0                  (*(ADC_t *) 0x0600) /* Analog to Digital Converter */
#define AC0                    (*(AC_t *) 0x0680) /* Analog Comparator */
#define AC1                    (*(AC_t *) 0x0688) /* Analog Comparator */
#define AC2                    (*(AC_t *) 0x0690) /* Analog Comparator */
#define DAC0                  (*(DAC_t *) 0x06A0) /* Digital to Analog Converter */
#define ZCD0                  (*(ZCD_t *) 0x06C0) /* Zero Cross Detect */
#define ZCD1                  (*(ZCD_t *) 0x06C8) /* Zero Cross Detect */
#define ZCD2                  (*(ZCD_t *) 0x06D0) /* Zero Cross Detect */
#define USART0              (*(USART_t *) 0x0800) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART1              (*(USART_t *) 0x0820) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART2              (*(USART_t *) 0x0840) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART3              (*(USART_t *) 0x0860) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART4              (*(USART_t *) 0x0880) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART5              (*(USART_t *) 0x08A0) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define TWI0                  (*(TWI_t *) 0x0900) /* Two-Wire Interface */
#define TWI1                  (*(TWI_t *) 0x0920) /* Two-Wire Interface */
#define SPI0                  (*(SPI_t *) 0x0940) /* Serial Peripheral Interface */
#define SPI1                  (*(SPI_t *) 0x0960) /* Serial Peripheral Interface */
#define TCA0                  (*(TCA_t *) 0x0A00) /* 16-bit Timer/Counter Type A */
#define TCA1                  (*(TCA_t *) 0x0A40) /* 16-bit Timer/Counter Type A */
#define TCB0                  (*(TCB_t *) 0x0B00) /* 16-bit Timer Type B */
#define TCB1                  (*(TCB_t *) 0x0B10) /* 16-bit Timer Type B */
#define TCB2                  (*(TCB_t *) 0x0B20) /* 16-bit Timer Type B */
#define TCB3                  (*(TCB_t *) 0x0B30) /* 16-bit Timer Type B */
#define TCB4                  (*(TCB_t *) 0x0B40) /* 16-bit Timer Type B */
#define TCD0                  (*(TCD_t *) 0x0B80) /* Timer Counter D */
#define FPGA                  (*(FIM_t *) 0x0E40) /* FPGA Interface Module */
#define NVMBIST           (*(NVMBIST_t *) 0x0E80) /* BIST in the NVMCTRL module */
#define TESTWIRE         (*(TESTWIRE_t *) 0x0E90) /* Test Wire */
#define BANDGAP           (*(BANDGAP_t *) 0x0EA0) /* Bandgap */
#define OSCTEST           (*(OSCTEST_t *) 0x0EA8) /* Oscillator test interface */
#define SYSCFG             (*(SYSCFG_t *) 0x0F00) /* System Configuration Registers */
#define NVMCTRL           (*(NVMCTRL_t *) 0x1000) /* Non-volatile Memory Controller */
#define LOCK                 (*(LOCK_t *) 0x1040) /* Lockbit */
#define FUSE                 (*(FUSE_t *) 0x1050) /* Fuses */
#define USERROW           (*(USERROW_t *) 0x1080) /* User Row */
#define SIGROW             (*(SIGROW_t *) 0x1100) /* Signature row */

#endif /* !defined (__ASSEMBLER__) */


/* ========== Flattened fully qualified IO register names ========== */


/* VPORT (VPORTA) - Virtual Ports */
#define VPORTA_DIR  _SFR_MEM8(0x0000)
#define VPORTA_OUT  _SFR_MEM8(0x0001)
#define VPORTA_IN  _SFR_MEM8(0x0002)
#define VPORTA_INTFLAGS  _SFR_MEM8(0x0003)


/* VPORT (VPORTB) - Virtual Ports */
#define VPORTB_DIR  _SFR_MEM8(0x0004)
#define VPORTB_OUT  _SFR_MEM8(0x0005)
#define VPORTB_IN  _SFR_MEM8(0x0006)
#define VPORTB_INTFLAGS  _SFR_MEM8(0x0007)


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


/* VPORT (VPORTE) - Virtual Ports */
#define VPORTE_DIR  _SFR_MEM8(0x0010)
#define VPORTE_OUT  _SFR_MEM8(0x0011)
#define VPORTE_IN  _SFR_MEM8(0x0012)
#define VPORTE_INTFLAGS  _SFR_MEM8(0x0013)


/* VPORT (VPORTF) - Virtual Ports */
#define VPORTF_DIR  _SFR_MEM8(0x0014)
#define VPORTF_OUT  _SFR_MEM8(0x0015)
#define VPORTF_IN  _SFR_MEM8(0x0016)
#define VPORTF_INTFLAGS  _SFR_MEM8(0x0017)


/* VPORT (VPORTG) - Virtual Ports */
#define VPORTG_DIR  _SFR_MEM8(0x0018)
#define VPORTG_OUT  _SFR_MEM8(0x0019)
#define VPORTG_IN  _SFR_MEM8(0x001A)
#define VPORTG_INTFLAGS  _SFR_MEM8(0x001B)


/* GPR (GPIO) - General Purpose Registers */
#define GPIO_GPR0  _SFR_MEM8(0x001C)
#define GPIO_GPR1  _SFR_MEM8(0x001D)
#define GPIO_GPR2  _SFR_MEM8(0x001E)
#define GPIO_GPR3  _SFR_MEM8(0x001F)


/* CPU - CPU */
#define CPU_CCP  _SFR_MEM8(0x0034)
#define CPU_RAMPZ  _SFR_MEM8(0x003B)
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


/* BOD - Bod interface */
#define BOD_CTRLA  _SFR_MEM8(0x00A0)
#define BOD_CTRLB  _SFR_MEM8(0x00A1)
#define BOD_CALIB  _SFR_MEM8(0x00A2)
#define BOD_TSTATUS  _SFR_MEM8(0x00A3)
#define BOD_TEST  _SFR_MEM8(0x00A4)
#define BOD_VLMCTRLA  _SFR_MEM8(0x00A8)
#define BOD_INTCTRL  _SFR_MEM8(0x00A9)
#define BOD_INTFLAGS  _SFR_MEM8(0x00AA)
#define BOD_STATUS  _SFR_MEM8(0x00AB)


/* VREF - Voltage reference */
#define VREF_ADC0REF  _SFR_MEM8(0x00B0)
#define VREF_DAC0REF  _SFR_MEM8(0x00B2)
#define VREF_ACREF  _SFR_MEM8(0x00B4)
#define VREF_CALIB  _SFR_MEM8(0x00B6)
#define VREF_TEST  _SFR_MEM8(0x00B7)


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


/* CCL - Configurable Custom Logic */
#define CCL_CTRLA  _SFR_MEM8(0x01C0)
#define CCL_SEQCTRL0  _SFR_MEM8(0x01C1)
#define CCL_SEQCTRL1  _SFR_MEM8(0x01C2)
#define CCL_SEQCTRL2  _SFR_MEM8(0x01C3)
#define CCL_INTCTRL0  _SFR_MEM8(0x01C5)
#define CCL_INTCTRL1  _SFR_MEM8(0x01C6)
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
#define CCL_LUT4CTRLA  _SFR_MEM8(0x01D8)
#define CCL_LUT4CTRLB  _SFR_MEM8(0x01D9)
#define CCL_LUT4CTRLC  _SFR_MEM8(0x01DA)
#define CCL_TRUTH4  _SFR_MEM8(0x01DB)
#define CCL_LUT5CTRLA  _SFR_MEM8(0x01DC)
#define CCL_LUT5CTRLB  _SFR_MEM8(0x01DD)
#define CCL_LUT5CTRLC  _SFR_MEM8(0x01DE)
#define CCL_TRUTH5  _SFR_MEM8(0x01DF)


/* EVSYS - Event System */
#define EVSYS_SWEVENTA  _SFR_MEM8(0x0200)
#define EVSYS_SWEVENTB  _SFR_MEM8(0x0201)
#define EVSYS_CHANNEL0  _SFR_MEM8(0x0210)
#define EVSYS_CHANNEL1  _SFR_MEM8(0x0211)
#define EVSYS_CHANNEL2  _SFR_MEM8(0x0212)
#define EVSYS_CHANNEL3  _SFR_MEM8(0x0213)
#define EVSYS_CHANNEL4  _SFR_MEM8(0x0214)
#define EVSYS_CHANNEL5  _SFR_MEM8(0x0215)
#define EVSYS_CHANNEL6  _SFR_MEM8(0x0216)
#define EVSYS_CHANNEL7  _SFR_MEM8(0x0217)
#define EVSYS_CHANNEL8  _SFR_MEM8(0x0218)
#define EVSYS_CHANNEL9  _SFR_MEM8(0x0219)
#define EVSYS_USERCCLLUT0A  _SFR_MEM8(0x0220)
#define EVSYS_USERCCLLUT0B  _SFR_MEM8(0x0221)
#define EVSYS_USERCCLLUT1A  _SFR_MEM8(0x0222)
#define EVSYS_USERCCLLUT1B  _SFR_MEM8(0x0223)
#define EVSYS_USERCCLLUT2A  _SFR_MEM8(0x0224)
#define EVSYS_USERCCLLUT2B  _SFR_MEM8(0x0225)
#define EVSYS_USERCCLLUT3A  _SFR_MEM8(0x0226)
#define EVSYS_USERCCLLUT3B  _SFR_MEM8(0x0227)
#define EVSYS_USERCCLLUT4A  _SFR_MEM8(0x0228)
#define EVSYS_USERCCLLUT4B  _SFR_MEM8(0x0229)
#define EVSYS_USERCCLLUT5A  _SFR_MEM8(0x022A)
#define EVSYS_USERCCLLUT5B  _SFR_MEM8(0x022B)
#define EVSYS_USERADC0START  _SFR_MEM8(0x022C)
#define EVSYS_USERPTCSTART  _SFR_MEM8(0x022D)
#define EVSYS_USEREVSYSEVOUTA  _SFR_MEM8(0x022E)
#define EVSYS_USEREVSYSEVOUTB  _SFR_MEM8(0x022F)
#define EVSYS_USEREVSYSEVOUTC  _SFR_MEM8(0x0230)
#define EVSYS_USEREVSYSEVOUTD  _SFR_MEM8(0x0231)
#define EVSYS_USEREVSYSEVOUTE  _SFR_MEM8(0x0232)
#define EVSYS_USEREVSYSEVOUTF  _SFR_MEM8(0x0233)
#define EVSYS_USEREVSYSEVOUTG  _SFR_MEM8(0x0234)
#define EVSYS_USERUSART0IRDA  _SFR_MEM8(0x0235)
#define EVSYS_USERUSART1IRDA  _SFR_MEM8(0x0236)
#define EVSYS_USERUSART2IRDA  _SFR_MEM8(0x0237)
#define EVSYS_USERUSART3IRDA  _SFR_MEM8(0x0238)
#define EVSYS_USERUSART4IRDA  _SFR_MEM8(0x0239)
#define EVSYS_USERUSART5IRDA  _SFR_MEM8(0x023A)
#define EVSYS_USERTCA0CNTA  _SFR_MEM8(0x023B)
#define EVSYS_USERTCA0CNTB  _SFR_MEM8(0x023C)
#define EVSYS_USERTCA1CNTA  _SFR_MEM8(0x023D)
#define EVSYS_USERTCA1CNTB  _SFR_MEM8(0x023E)
#define EVSYS_USERTCB0CAPT  _SFR_MEM8(0x023F)
#define EVSYS_USERTCB0COUNT  _SFR_MEM8(0x0240)
#define EVSYS_USERTCB1CAPT  _SFR_MEM8(0x0241)
#define EVSYS_USERTCB1COUNT  _SFR_MEM8(0x0242)
#define EVSYS_USERTCB2CAPT  _SFR_MEM8(0x0243)
#define EVSYS_USERTCB2COUNT  _SFR_MEM8(0x0244)
#define EVSYS_USERTCB3CAPT  _SFR_MEM8(0x0245)
#define EVSYS_USERTCB3COUNT  _SFR_MEM8(0x0246)
#define EVSYS_USERTCB4CAPT  _SFR_MEM8(0x0247)
#define EVSYS_USERTCB4COUNT  _SFR_MEM8(0x0248)
#define EVSYS_USERTCD0INPUTA  _SFR_MEM8(0x0249)
#define EVSYS_USERTCD0INPUTB  _SFR_MEM8(0x024A)
#define EVSYS_USEROSCTEST  _SFR_MEM8(0x024B)


/* USB (USB0) - USB Device Controller */
#define USB0_CTRLA  _SFR_MEM8(0x0280)
#define USB0_CTRLB  _SFR_MEM8(0x0281)
#define USB0_BUSSTATE  _SFR_MEM8(0x0282)
#define USB0_ADDR  _SFR_MEM8(0x0283)
#define USB0_FIFOWP  _SFR_MEM8(0x0284)
#define USB0_FIFORP  _SFR_MEM8(0x0285)
#define USB0_EPPTR  _SFR_MEM16(0x0286)
#define USB0_EPPTRL  _SFR_MEM8(0x0286)
#define USB0_EPPTRH  _SFR_MEM8(0x0287)
#define USB0_INTCTRLA  _SFR_MEM8(0x0288)
#define USB0_INTCTRLB  _SFR_MEM8(0x0289)
#define USB0_INTFLAGSA  _SFR_MEM8(0x028A)
#define USB0_INTFLAGSB  _SFR_MEM8(0x028B)
#define USB0_TESTCTRL  _SFR_MEM8(0x028C)
#define USB0_TESTSTATUS  _SFR_MEM8(0x028D)
#define USB0_STATUS0_OUTCLR  _SFR_MEM8(0x02C0)
#define USB0_STATUS0_OUTSET  _SFR_MEM8(0x02C1)
#define USB0_STATUS0_INCLR  _SFR_MEM8(0x02C2)
#define USB0_STATUS0_INSET  _SFR_MEM8(0x02C3)
#define USB0_STATUS1_OUTCLR  _SFR_MEM8(0x02C4)
#define USB0_STATUS1_OUTSET  _SFR_MEM8(0x02C5)
#define USB0_STATUS1_INCLR  _SFR_MEM8(0x02C6)
#define USB0_STATUS1_INSET  _SFR_MEM8(0x02C7)
#define USB0_STATUS2_OUTCLR  _SFR_MEM8(0x02C8)
#define USB0_STATUS2_OUTSET  _SFR_MEM8(0x02C9)
#define USB0_STATUS2_INCLR  _SFR_MEM8(0x02CA)
#define USB0_STATUS2_INSET  _SFR_MEM8(0x02CB)
#define USB0_STATUS3_OUTCLR  _SFR_MEM8(0x02CC)
#define USB0_STATUS3_OUTSET  _SFR_MEM8(0x02CD)
#define USB0_STATUS3_INCLR  _SFR_MEM8(0x02CE)
#define USB0_STATUS3_INSET  _SFR_MEM8(0x02CF)
#define USB0_STATUS4_OUTCLR  _SFR_MEM8(0x02D0)
#define USB0_STATUS4_OUTSET  _SFR_MEM8(0x02D1)
#define USB0_STATUS4_INCLR  _SFR_MEM8(0x02D2)
#define USB0_STATUS4_INSET  _SFR_MEM8(0x02D3)
#define USB0_STATUS5_OUTCLR  _SFR_MEM8(0x02D4)
#define USB0_STATUS5_OUTSET  _SFR_MEM8(0x02D5)
#define USB0_STATUS5_INCLR  _SFR_MEM8(0x02D6)
#define USB0_STATUS5_INSET  _SFR_MEM8(0x02D7)
#define USB0_STATUS6_OUTCLR  _SFR_MEM8(0x02D8)
#define USB0_STATUS6_OUTSET  _SFR_MEM8(0x02D9)
#define USB0_STATUS6_INCLR  _SFR_MEM8(0x02DA)
#define USB0_STATUS6_INSET  _SFR_MEM8(0x02DB)
#define USB0_STATUS7_OUTCLR  _SFR_MEM8(0x02DC)
#define USB0_STATUS7_OUTSET  _SFR_MEM8(0x02DD)
#define USB0_STATUS7_INCLR  _SFR_MEM8(0x02DE)
#define USB0_STATUS7_INSET  _SFR_MEM8(0x02DF)
#define USB0_STATUS8_OUTCLR  _SFR_MEM8(0x02E0)
#define USB0_STATUS8_OUTSET  _SFR_MEM8(0x02E1)
#define USB0_STATUS8_INCLR  _SFR_MEM8(0x02E2)
#define USB0_STATUS8_INSET  _SFR_MEM8(0x02E3)
#define USB0_STATUS9_OUTCLR  _SFR_MEM8(0x02E4)
#define USB0_STATUS9_OUTSET  _SFR_MEM8(0x02E5)
#define USB0_STATUS9_INCLR  _SFR_MEM8(0x02E6)
#define USB0_STATUS9_INSET  _SFR_MEM8(0x02E7)
#define USB0_STATUS10_OUTCLR  _SFR_MEM8(0x02E8)
#define USB0_STATUS10_OUTSET  _SFR_MEM8(0x02E9)
#define USB0_STATUS10_INCLR  _SFR_MEM8(0x02EA)
#define USB0_STATUS10_INSET  _SFR_MEM8(0x02EB)
#define USB0_STATUS11_OUTCLR  _SFR_MEM8(0x02EC)
#define USB0_STATUS11_OUTSET  _SFR_MEM8(0x02ED)
#define USB0_STATUS11_INCLR  _SFR_MEM8(0x02EE)
#define USB0_STATUS11_INSET  _SFR_MEM8(0x02EF)
#define USB0_STATUS12_OUTCLR  _SFR_MEM8(0x02F0)
#define USB0_STATUS12_OUTSET  _SFR_MEM8(0x02F1)
#define USB0_STATUS12_INCLR  _SFR_MEM8(0x02F2)
#define USB0_STATUS12_INSET  _SFR_MEM8(0x02F3)
#define USB0_STATUS13_OUTCLR  _SFR_MEM8(0x02F4)
#define USB0_STATUS13_OUTSET  _SFR_MEM8(0x02F5)
#define USB0_STATUS13_INCLR  _SFR_MEM8(0x02F6)
#define USB0_STATUS13_INSET  _SFR_MEM8(0x02F7)
#define USB0_STATUS14_OUTCLR  _SFR_MEM8(0x02F8)
#define USB0_STATUS14_OUTSET  _SFR_MEM8(0x02F9)
#define USB0_STATUS14_INCLR  _SFR_MEM8(0x02FA)
#define USB0_STATUS14_INSET  _SFR_MEM8(0x02FB)
#define USB0_STATUS15_OUTCLR  _SFR_MEM8(0x02FC)
#define USB0_STATUS15_OUTSET  _SFR_MEM8(0x02FD)
#define USB0_STATUS15_INCLR  _SFR_MEM8(0x02FE)
#define USB0_STATUS15_INSET  _SFR_MEM8(0x02FF)




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
#define PORTA_PINCTRLLD  _SFR_MEM8(0x040C)
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


/* PORT (PORTB) - I/O Ports */
#define PORTB_DIR  _SFR_MEM8(0x0420)
#define PORTB_DIRSET  _SFR_MEM8(0x0421)
#define PORTB_DIRCLR  _SFR_MEM8(0x0422)
#define PORTB_DIRTGL  _SFR_MEM8(0x0423)
#define PORTB_OUT  _SFR_MEM8(0x0424)
#define PORTB_OUTSET  _SFR_MEM8(0x0425)
#define PORTB_OUTCLR  _SFR_MEM8(0x0426)
#define PORTB_OUTTGL  _SFR_MEM8(0x0427)
#define PORTB_IN  _SFR_MEM8(0x0428)
#define PORTB_INTFLAGS  _SFR_MEM8(0x0429)
#define PORTB_PORTCTRL  _SFR_MEM8(0x042A)
#define PORTB_PINCONFIG  _SFR_MEM8(0x042B)
#define PORTB_PINCTRLLD  _SFR_MEM8(0x042C)
#define PORTB_PINCTRLSET  _SFR_MEM8(0x042D)
#define PORTB_PINCTRLCLR  _SFR_MEM8(0x042E)
#define PORTB_PIN0CTRL  _SFR_MEM8(0x0430)
#define PORTB_PIN1CTRL  _SFR_MEM8(0x0431)
#define PORTB_PIN2CTRL  _SFR_MEM8(0x0432)
#define PORTB_PIN3CTRL  _SFR_MEM8(0x0433)
#define PORTB_PIN4CTRL  _SFR_MEM8(0x0434)
#define PORTB_PIN5CTRL  _SFR_MEM8(0x0435)
#define PORTB_PIN6CTRL  _SFR_MEM8(0x0436)
#define PORTB_PIN7CTRL  _SFR_MEM8(0x0437)


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
#define PORTC_PINCTRLLD  _SFR_MEM8(0x044C)
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
#define PORTD_PINCTRLLD  _SFR_MEM8(0x046C)
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


/* PORT (PORTE) - I/O Ports */
#define PORTE_DIR  _SFR_MEM8(0x0480)
#define PORTE_DIRSET  _SFR_MEM8(0x0481)
#define PORTE_DIRCLR  _SFR_MEM8(0x0482)
#define PORTE_DIRTGL  _SFR_MEM8(0x0483)
#define PORTE_OUT  _SFR_MEM8(0x0484)
#define PORTE_OUTSET  _SFR_MEM8(0x0485)
#define PORTE_OUTCLR  _SFR_MEM8(0x0486)
#define PORTE_OUTTGL  _SFR_MEM8(0x0487)
#define PORTE_IN  _SFR_MEM8(0x0488)
#define PORTE_INTFLAGS  _SFR_MEM8(0x0489)
#define PORTE_PORTCTRL  _SFR_MEM8(0x048A)
#define PORTE_PINCONFIG  _SFR_MEM8(0x048B)
#define PORTE_PINCTRLLD  _SFR_MEM8(0x048C)
#define PORTE_PINCTRLSET  _SFR_MEM8(0x048D)
#define PORTE_PINCTRLCLR  _SFR_MEM8(0x048E)
#define PORTE_PIN0CTRL  _SFR_MEM8(0x0490)
#define PORTE_PIN1CTRL  _SFR_MEM8(0x0491)
#define PORTE_PIN2CTRL  _SFR_MEM8(0x0492)
#define PORTE_PIN3CTRL  _SFR_MEM8(0x0493)
#define PORTE_PIN4CTRL  _SFR_MEM8(0x0494)
#define PORTE_PIN5CTRL  _SFR_MEM8(0x0495)
#define PORTE_PIN6CTRL  _SFR_MEM8(0x0496)
#define PORTE_PIN7CTRL  _SFR_MEM8(0x0497)


/* PORTMUX - Port Multiplexer */
#define PORTMUX_EVSYSROUTEA  _SFR_MEM8(0x05E0)
#define PORTMUX_CCLROUTEA  _SFR_MEM8(0x05E1)
#define PORTMUX_USARTROUTEA  _SFR_MEM8(0x05E2)
#define PORTMUX_USARTROUTEB  _SFR_MEM8(0x05E3)
#define PORTMUX_SPIROUTEA  _SFR_MEM8(0x05E4)
#define PORTMUX_TWIROUTEA  _SFR_MEM8(0x05E5)
#define PORTMUX_TCAROUTEA  _SFR_MEM8(0x05E6)
#define PORTMUX_TCBROUTEA  _SFR_MEM8(0x05E7)
#define PORTMUX_TCDROUTEA  _SFR_MEM8(0x05E8)
#define PORTMUX_ACROUTEA  _SFR_MEM8(0x05E9)
#define PORTMUX_ZCDROUTEA  _SFR_MEM8(0x05EA)
#define PORTMUX_EEXROUTEA  _SFR_MEM8(0x05EF)


/* ADC (ADC0) - Analog to Digital Converter */
#define ADC0_CTRLA  _SFR_MEM8(0x0600)
#define ADC0_CTRLB  _SFR_MEM8(0x0601)
#define ADC0_CTRLC  _SFR_MEM8(0x0602)
#define ADC0_CTRLD  _SFR_MEM8(0x0603)
#define ADC0_CTRLE  _SFR_MEM8(0x0604)
#define ADC0_SAMPCTRL  _SFR_MEM8(0x0605)
#define ADC0_MUXPOS  _SFR_MEM8(0x0608)
#define ADC0_MUXNEG  _SFR_MEM8(0x0609)
#define ADC0_COMMAND  _SFR_MEM8(0x060A)
#define ADC0_EVCTRL  _SFR_MEM8(0x060B)
#define ADC0_INTCTRL  _SFR_MEM8(0x060C)
#define ADC0_INTFLAGS  _SFR_MEM8(0x060D)
#define ADC0_DBGCTRL  _SFR_MEM8(0x060E)
#define ADC0_TEMP  _SFR_MEM8(0x060F)
#define ADC0_RES  _SFR_MEM16(0x0610)
#define ADC0_RESL  _SFR_MEM8(0x0610)
#define ADC0_RESH  _SFR_MEM8(0x0611)
#define ADC0_WINLT  _SFR_MEM16(0x0612)
#define ADC0_WINLTL  _SFR_MEM8(0x0612)
#define ADC0_WINLTH  _SFR_MEM8(0x0613)
#define ADC0_WINHT  _SFR_MEM16(0x0614)
#define ADC0_WINHTL  _SFR_MEM8(0x0614)
#define ADC0_WINHTH  _SFR_MEM8(0x0615)
#define ADC0_CAL  _SFR_MEM8(0x061E)


/* AC (AC0) - Analog Comparator */
#define AC0_CTRLA  _SFR_MEM8(0x0680)
#define AC0_CTRLB  _SFR_MEM8(0x0681)
#define AC0_MUXCTRL  _SFR_MEM8(0x0682)
#define AC0_DACREFL  _SFR_MEM8(0x0684)
#define AC0_DACREF  _SFR_MEM8(0x0685)
#define AC0_INTCTRL  _SFR_MEM8(0x0686)
#define AC0_STATUS  _SFR_MEM8(0x0687)


/* AC (AC1) - Analog Comparator */
#define AC1_CTRLA  _SFR_MEM8(0x0688)
#define AC1_CTRLB  _SFR_MEM8(0x0689)
#define AC1_MUXCTRL  _SFR_MEM8(0x068A)
#define AC1_DACREFL  _SFR_MEM8(0x068C)
#define AC1_DACREF  _SFR_MEM8(0x068D)
#define AC1_INTCTRL  _SFR_MEM8(0x068E)
#define AC1_STATUS  _SFR_MEM8(0x068F)


/* AC (AC2) - Analog Comparator */
#define AC2_CTRLA  _SFR_MEM8(0x0690)
#define AC2_CTRLB  _SFR_MEM8(0x0691)
#define AC2_MUXCTRL  _SFR_MEM8(0x0692)
#define AC2_DACREFL  _SFR_MEM8(0x0694)
#define AC2_DACREF  _SFR_MEM8(0x0695)
#define AC2_INTCTRL  _SFR_MEM8(0x0696)
#define AC2_STATUS  _SFR_MEM8(0x0697)


/* DAC (DAC0) - Digital to Analog Converter */
#define DAC0_CTRLA  _SFR_MEM8(0x06A0)
#define DAC0_DATA  _SFR_MEM16(0x06A2)
#define DAC0_DATAL  _SFR_MEM8(0x06A2)
#define DAC0_DATAH  _SFR_MEM8(0x06A3)
#define DAC0_TEST  _SFR_MEM8(0x06A7)


/* ZCD (ZCD0) - Zero Cross Detect */
#define ZCD0_CTRLA  _SFR_MEM8(0x06C0)
#define ZCD0_INTCTRL  _SFR_MEM8(0x06C2)
#define ZCD0_STATUS  _SFR_MEM8(0x06C3)


/* ZCD (ZCD1) - Zero Cross Detect */
#define ZCD1_CTRLA  _SFR_MEM8(0x06C8)
#define ZCD1_INTCTRL  _SFR_MEM8(0x06CA)
#define ZCD1_STATUS  _SFR_MEM8(0x06CB)


/* ZCD (ZCD2) - Zero Cross Detect */
#define ZCD2_CTRLA  _SFR_MEM8(0x06D0)
#define ZCD2_INTCTRL  _SFR_MEM8(0x06D2)
#define ZCD2_STATUS  _SFR_MEM8(0x06D3)


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


/* USART (USART1) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART1_RXDATAL  _SFR_MEM8(0x0820)
#define USART1_RXDATAH  _SFR_MEM8(0x0821)
#define USART1_TXDATAL  _SFR_MEM8(0x0822)
#define USART1_TXDATAH  _SFR_MEM8(0x0823)
#define USART1_STATUS  _SFR_MEM8(0x0824)
#define USART1_CTRLA  _SFR_MEM8(0x0825)
#define USART1_CTRLB  _SFR_MEM8(0x0826)
#define USART1_CTRLC  _SFR_MEM8(0x0827)
#define USART1_BAUD  _SFR_MEM16(0x0828)
#define USART1_BAUDL  _SFR_MEM8(0x0828)
#define USART1_BAUDH  _SFR_MEM8(0x0829)
#define USART1_CTRLD  _SFR_MEM8(0x082A)
#define USART1_DBGCTRL  _SFR_MEM8(0x082B)
#define USART1_EVCTRL  _SFR_MEM8(0x082C)
#define USART1_TXPLCTRL  _SFR_MEM8(0x082D)
#define USART1_RXPLCTRL  _SFR_MEM8(0x082E)


/* USART (USART2) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART2_RXDATAL  _SFR_MEM8(0x0840)
#define USART2_RXDATAH  _SFR_MEM8(0x0841)
#define USART2_TXDATAL  _SFR_MEM8(0x0842)
#define USART2_TXDATAH  _SFR_MEM8(0x0843)
#define USART2_STATUS  _SFR_MEM8(0x0844)
#define USART2_CTRLA  _SFR_MEM8(0x0845)
#define USART2_CTRLB  _SFR_MEM8(0x0846)
#define USART2_CTRLC  _SFR_MEM8(0x0847)
#define USART2_BAUD  _SFR_MEM16(0x0848)
#define USART2_BAUDL  _SFR_MEM8(0x0848)
#define USART2_BAUDH  _SFR_MEM8(0x0849)
#define USART2_CTRLD  _SFR_MEM8(0x084A)
#define USART2_DBGCTRL  _SFR_MEM8(0x084B)
#define USART2_EVCTRL  _SFR_MEM8(0x084C)
#define USART2_TXPLCTRL  _SFR_MEM8(0x084D)
#define USART2_RXPLCTRL  _SFR_MEM8(0x084E)


/* USART (USART3) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART3_RXDATAL  _SFR_MEM8(0x0860)
#define USART3_RXDATAH  _SFR_MEM8(0x0861)
#define USART3_TXDATAL  _SFR_MEM8(0x0862)
#define USART3_TXDATAH  _SFR_MEM8(0x0863)
#define USART3_STATUS  _SFR_MEM8(0x0864)
#define USART3_CTRLA  _SFR_MEM8(0x0865)
#define USART3_CTRLB  _SFR_MEM8(0x0866)
#define USART3_CTRLC  _SFR_MEM8(0x0867)
#define USART3_BAUD  _SFR_MEM16(0x0868)
#define USART3_BAUDL  _SFR_MEM8(0x0868)
#define USART3_BAUDH  _SFR_MEM8(0x0869)
#define USART3_CTRLD  _SFR_MEM8(0x086A)
#define USART3_DBGCTRL  _SFR_MEM8(0x086B)
#define USART3_EVCTRL  _SFR_MEM8(0x086C)
#define USART3_TXPLCTRL  _SFR_MEM8(0x086D)
#define USART3_RXPLCTRL  _SFR_MEM8(0x086E)


/* USART (USART4) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART4_RXDATAL  _SFR_MEM8(0x0880)
#define USART4_RXDATAH  _SFR_MEM8(0x0881)
#define USART4_TXDATAL  _SFR_MEM8(0x0882)
#define USART4_TXDATAH  _SFR_MEM8(0x0883)
#define USART4_STATUS  _SFR_MEM8(0x0884)
#define USART4_CTRLA  _SFR_MEM8(0x0885)
#define USART4_CTRLB  _SFR_MEM8(0x0886)
#define USART4_CTRLC  _SFR_MEM8(0x0887)
#define USART4_BAUD  _SFR_MEM16(0x0888)
#define USART4_BAUDL  _SFR_MEM8(0x0888)
#define USART4_BAUDH  _SFR_MEM8(0x0889)
#define USART4_CTRLD  _SFR_MEM8(0x088A)
#define USART4_DBGCTRL  _SFR_MEM8(0x088B)
#define USART4_EVCTRL  _SFR_MEM8(0x088C)
#define USART4_TXPLCTRL  _SFR_MEM8(0x088D)
#define USART4_RXPLCTRL  _SFR_MEM8(0x088E)


/* USART (USART5) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART5_RXDATAL  _SFR_MEM8(0x08A0)
#define USART5_RXDATAH  _SFR_MEM8(0x08A1)
#define USART5_TXDATAL  _SFR_MEM8(0x08A2)
#define USART5_TXDATAH  _SFR_MEM8(0x08A3)
#define USART5_STATUS  _SFR_MEM8(0x08A4)
#define USART5_CTRLA  _SFR_MEM8(0x08A5)
#define USART5_CTRLB  _SFR_MEM8(0x08A6)
#define USART5_CTRLC  _SFR_MEM8(0x08A7)
#define USART5_BAUD  _SFR_MEM16(0x08A8)
#define USART5_BAUDL  _SFR_MEM8(0x08A8)
#define USART5_BAUDH  _SFR_MEM8(0x08A9)
#define USART5_CTRLD  _SFR_MEM8(0x08AA)
#define USART5_DBGCTRL  _SFR_MEM8(0x08AB)
#define USART5_EVCTRL  _SFR_MEM8(0x08AC)
#define USART5_TXPLCTRL  _SFR_MEM8(0x08AD)
#define USART5_RXPLCTRL  _SFR_MEM8(0x08AE)


/* TWI (TWI0) - Two-Wire Interface */
#define TWI0_CTRLA  _SFR_MEM8(0x0900)
#define TWI0_DUALCTRL  _SFR_MEM8(0x0901)
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
#define TWI0_TEST  _SFR_MEM8(0x090F)


/* TWI (TWI1) - Two-Wire Interface */
#define TWI1_CTRLA  _SFR_MEM8(0x0920)
#define TWI1_DUALCTRL  _SFR_MEM8(0x0921)
#define TWI1_DBGCTRL  _SFR_MEM8(0x0922)
#define TWI1_MCTRLA  _SFR_MEM8(0x0923)
#define TWI1_MCTRLB  _SFR_MEM8(0x0924)
#define TWI1_MSTATUS  _SFR_MEM8(0x0925)
#define TWI1_MBAUD  _SFR_MEM8(0x0926)
#define TWI1_MADDR  _SFR_MEM8(0x0927)
#define TWI1_MDATA  _SFR_MEM8(0x0928)
#define TWI1_SCTRLA  _SFR_MEM8(0x0929)
#define TWI1_SCTRLB  _SFR_MEM8(0x092A)
#define TWI1_SSTATUS  _SFR_MEM8(0x092B)
#define TWI1_SADDR  _SFR_MEM8(0x092C)
#define TWI1_SDATA  _SFR_MEM8(0x092D)
#define TWI1_SADDRMASK  _SFR_MEM8(0x092E)
#define TWI1_TEST  _SFR_MEM8(0x092F)


/* SPI (SPI0) - Serial Peripheral Interface */
#define SPI0_CTRLA  _SFR_MEM8(0x0940)
#define SPI0_CTRLB  _SFR_MEM8(0x0941)
#define SPI0_INTCTRL  _SFR_MEM8(0x0942)
#define SPI0_INTFLAGS  _SFR_MEM8(0x0943)
#define SPI0_DATA  _SFR_MEM8(0x0944)


/* SPI (SPI1) - Serial Peripheral Interface */
#define SPI1_CTRLA  _SFR_MEM8(0x0960)
#define SPI1_CTRLB  _SFR_MEM8(0x0961)
#define SPI1_INTCTRL  _SFR_MEM8(0x0962)
#define SPI1_INTFLAGS  _SFR_MEM8(0x0963)
#define SPI1_DATA  _SFR_MEM8(0x0964)


/* TCA (TCA0) - 16-bit Timer/Counter Type A - 16-bit Timer/Counter Type A - Single Mode */
#define TCA0_SINGLE_CTRLA  _SFR_MEM8(0x0A00)
#define TCA0_SINGLE_CTRLB  _SFR_MEM8(0x0A01)
#define TCA0_SINGLE_CTRLC  _SFR_MEM8(0x0A02)
#define TCA0_SINGLE_CTRLD  _SFR_MEM8(0x0A03)
#define TCA0_SINGLE_CTRLECLR  _SFR_MEM8(0x0A04)
#define TCA0_SINGLE_CTRLESET  _SFR_MEM8(0x0A05)
#define TCA0_SINGLE_CTRLFCLR  _SFR_MEM8(0x0A06)
#define TCA0_SINGLE_CTRLFSET  _SFR_MEM8(0x0A07)
#define TCA0_SINGLE_EVCTRL  _SFR_MEM8(0x0A09)
#define TCA0_SINGLE_INTCTRL  _SFR_MEM8(0x0A0A)
#define TCA0_SINGLE_INTFLAGS  _SFR_MEM8(0x0A0B)
#define TCA0_SINGLE_DBGCTRL  _SFR_MEM8(0x0A0E)
#define TCA0_SINGLE_TEMP  _SFR_MEM8(0x0A0F)
#define TCA0_SINGLE_CNT  _SFR_MEM16(0x0A20)
#define TCA0_SINGLE_CNTL  _SFR_MEM8(0x0A20)
#define TCA0_SINGLE_CNTH  _SFR_MEM8(0x0A21)
#define TCA0_SINGLE_PER  _SFR_MEM16(0x0A26)
#define TCA0_SINGLE_PERL  _SFR_MEM8(0x0A26)
#define TCA0_SINGLE_PERH  _SFR_MEM8(0x0A27)
#define TCA0_SINGLE_CMP0  _SFR_MEM16(0x0A28)
#define TCA0_SINGLE_CMP0L  _SFR_MEM8(0x0A28)
#define TCA0_SINGLE_CMP0H  _SFR_MEM8(0x0A29)
#define TCA0_SINGLE_CMP1  _SFR_MEM16(0x0A2A)
#define TCA0_SINGLE_CMP1L  _SFR_MEM8(0x0A2A)
#define TCA0_SINGLE_CMP1H  _SFR_MEM8(0x0A2B)
#define TCA0_SINGLE_CMP2  _SFR_MEM16(0x0A2C)
#define TCA0_SINGLE_CMP2L  _SFR_MEM8(0x0A2C)
#define TCA0_SINGLE_CMP2H  _SFR_MEM8(0x0A2D)
#define TCA0_SINGLE_PERBUF  _SFR_MEM16(0x0A36)
#define TCA0_SINGLE_PERBUFL  _SFR_MEM8(0x0A36)
#define TCA0_SINGLE_PERBUFH  _SFR_MEM8(0x0A37)
#define TCA0_SINGLE_CMP0BUF  _SFR_MEM16(0x0A38)
#define TCA0_SINGLE_CMP0BUFL  _SFR_MEM8(0x0A38)
#define TCA0_SINGLE_CMP0BUFH  _SFR_MEM8(0x0A39)
#define TCA0_SINGLE_CMP1BUF  _SFR_MEM16(0x0A3A)
#define TCA0_SINGLE_CMP1BUFL  _SFR_MEM8(0x0A3A)
#define TCA0_SINGLE_CMP1BUFH  _SFR_MEM8(0x0A3B)
#define TCA0_SINGLE_CMP2BUF  _SFR_MEM16(0x0A3C)
#define TCA0_SINGLE_CMP2BUFL  _SFR_MEM8(0x0A3C)
#define TCA0_SINGLE_CMP2BUFH  _SFR_MEM8(0x0A3D)


/* TCA (TCA0) - 16-bit Timer/Counter Type A - 16-bit Timer/Counter Type A - Split Mode */
#define TCA0_SPLIT_CTRLA  _SFR_MEM8(0x0A00)
#define TCA0_SPLIT_CTRLB  _SFR_MEM8(0x0A01)
#define TCA0_SPLIT_CTRLC  _SFR_MEM8(0x0A02)
#define TCA0_SPLIT_CTRLD  _SFR_MEM8(0x0A03)
#define TCA0_SPLIT_CTRLECLR  _SFR_MEM8(0x0A04)
#define TCA0_SPLIT_CTRLESET  _SFR_MEM8(0x0A05)
#define TCA0_SPLIT_INTCTRL  _SFR_MEM8(0x0A0A)
#define TCA0_SPLIT_INTFLAGS  _SFR_MEM8(0x0A0B)
#define TCA0_SPLIT_DBGCTRL  _SFR_MEM8(0x0A0E)
#define TCA0_SPLIT_LCNT  _SFR_MEM8(0x0A20)
#define TCA0_SPLIT_HCNT  _SFR_MEM8(0x0A21)
#define TCA0_SPLIT_LPER  _SFR_MEM8(0x0A26)
#define TCA0_SPLIT_HPER  _SFR_MEM8(0x0A27)
#define TCA0_SPLIT_LCMP0  _SFR_MEM8(0x0A28)
#define TCA0_SPLIT_HCMP0  _SFR_MEM8(0x0A29)
#define TCA0_SPLIT_LCMP1  _SFR_MEM8(0x0A2A)
#define TCA0_SPLIT_HCMP1  _SFR_MEM8(0x0A2B)
#define TCA0_SPLIT_LCMP2  _SFR_MEM8(0x0A2C)
#define TCA0_SPLIT_HCMP2  _SFR_MEM8(0x0A2D)


/* TCA (TCA1) - 16-bit Timer/Counter Type A - 16-bit Timer/Counter Type A - Single Mode */
#define TCA1_SINGLE_CTRLA  _SFR_MEM8(0x0A40)
#define TCA1_SINGLE_CTRLB  _SFR_MEM8(0x0A41)
#define TCA1_SINGLE_CTRLC  _SFR_MEM8(0x0A42)
#define TCA1_SINGLE_CTRLD  _SFR_MEM8(0x0A43)
#define TCA1_SINGLE_CTRLECLR  _SFR_MEM8(0x0A44)
#define TCA1_SINGLE_CTRLESET  _SFR_MEM8(0x0A45)
#define TCA1_SINGLE_CTRLFCLR  _SFR_MEM8(0x0A46)
#define TCA1_SINGLE_CTRLFSET  _SFR_MEM8(0x0A47)
#define TCA1_SINGLE_EVCTRL  _SFR_MEM8(0x0A49)
#define TCA1_SINGLE_INTCTRL  _SFR_MEM8(0x0A4A)
#define TCA1_SINGLE_INTFLAGS  _SFR_MEM8(0x0A4B)
#define TCA1_SINGLE_DBGCTRL  _SFR_MEM8(0x0A4E)
#define TCA1_SINGLE_TEMP  _SFR_MEM8(0x0A4F)
#define TCA1_SINGLE_CNT  _SFR_MEM16(0x0A60)
#define TCA1_SINGLE_CNTL  _SFR_MEM8(0x0A60)
#define TCA1_SINGLE_CNTH  _SFR_MEM8(0x0A61)
#define TCA1_SINGLE_PER  _SFR_MEM16(0x0A66)
#define TCA1_SINGLE_PERL  _SFR_MEM8(0x0A66)
#define TCA1_SINGLE_PERH  _SFR_MEM8(0x0A67)
#define TCA1_SINGLE_CMP0  _SFR_MEM16(0x0A68)
#define TCA1_SINGLE_CMP0L  _SFR_MEM8(0x0A68)
#define TCA1_SINGLE_CMP0H  _SFR_MEM8(0x0A69)
#define TCA1_SINGLE_CMP1  _SFR_MEM16(0x0A6A)
#define TCA1_SINGLE_CMP1L  _SFR_MEM8(0x0A6A)
#define TCA1_SINGLE_CMP1H  _SFR_MEM8(0x0A6B)
#define TCA1_SINGLE_CMP2  _SFR_MEM16(0x0A6C)
#define TCA1_SINGLE_CMP2L  _SFR_MEM8(0x0A6C)
#define TCA1_SINGLE_CMP2H  _SFR_MEM8(0x0A6D)
#define TCA1_SINGLE_PERBUF  _SFR_MEM16(0x0A76)
#define TCA1_SINGLE_PERBUFL  _SFR_MEM8(0x0A76)
#define TCA1_SINGLE_PERBUFH  _SFR_MEM8(0x0A77)
#define TCA1_SINGLE_CMP0BUF  _SFR_MEM16(0x0A78)
#define TCA1_SINGLE_CMP0BUFL  _SFR_MEM8(0x0A78)
#define TCA1_SINGLE_CMP0BUFH  _SFR_MEM8(0x0A79)
#define TCA1_SINGLE_CMP1BUF  _SFR_MEM16(0x0A7A)
#define TCA1_SINGLE_CMP1BUFL  _SFR_MEM8(0x0A7A)
#define TCA1_SINGLE_CMP1BUFH  _SFR_MEM8(0x0A7B)
#define TCA1_SINGLE_CMP2BUF  _SFR_MEM16(0x0A7C)
#define TCA1_SINGLE_CMP2BUFL  _SFR_MEM8(0x0A7C)
#define TCA1_SINGLE_CMP2BUFH  _SFR_MEM8(0x0A7D)


/* TCA (TCA1) - 16-bit Timer/Counter Type A - 16-bit Timer/Counter Type A - Split Mode */
#define TCA1_SPLIT_CTRLA  _SFR_MEM8(0x0A40)
#define TCA1_SPLIT_CTRLB  _SFR_MEM8(0x0A41)
#define TCA1_SPLIT_CTRLC  _SFR_MEM8(0x0A42)
#define TCA1_SPLIT_CTRLD  _SFR_MEM8(0x0A43)
#define TCA1_SPLIT_CTRLECLR  _SFR_MEM8(0x0A44)
#define TCA1_SPLIT_CTRLESET  _SFR_MEM8(0x0A45)
#define TCA1_SPLIT_INTCTRL  _SFR_MEM8(0x0A4A)
#define TCA1_SPLIT_INTFLAGS  _SFR_MEM8(0x0A4B)
#define TCA1_SPLIT_DBGCTRL  _SFR_MEM8(0x0A4E)
#define TCA1_SPLIT_LCNT  _SFR_MEM8(0x0A60)
#define TCA1_SPLIT_HCNT  _SFR_MEM8(0x0A61)
#define TCA1_SPLIT_LPER  _SFR_MEM8(0x0A66)
#define TCA1_SPLIT_HPER  _SFR_MEM8(0x0A67)
#define TCA1_SPLIT_LCMP0  _SFR_MEM8(0x0A68)
#define TCA1_SPLIT_HCMP0  _SFR_MEM8(0x0A69)
#define TCA1_SPLIT_LCMP1  _SFR_MEM8(0x0A6A)
#define TCA1_SPLIT_HCMP1  _SFR_MEM8(0x0A6B)
#define TCA1_SPLIT_LCMP2  _SFR_MEM8(0x0A6C)
#define TCA1_SPLIT_HCMP2  _SFR_MEM8(0x0A6D)


/* TCB (TCB0) - 16-bit Timer Type B */
#define TCB0_CTRLA  _SFR_MEM8(0x0B00)
#define TCB0_CTRLB  _SFR_MEM8(0x0B01)
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


/* TCB (TCB1) - 16-bit Timer Type B */
#define TCB1_CTRLA  _SFR_MEM8(0x0B10)
#define TCB1_CTRLB  _SFR_MEM8(0x0B11)
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


/* TCB (TCB2) - 16-bit Timer Type B */
#define TCB2_CTRLA  _SFR_MEM8(0x0B20)
#define TCB2_CTRLB  _SFR_MEM8(0x0B21)
#define TCB2_EVCTRL  _SFR_MEM8(0x0B24)
#define TCB2_INTCTRL  _SFR_MEM8(0x0B25)
#define TCB2_INTFLAGS  _SFR_MEM8(0x0B26)
#define TCB2_STATUS  _SFR_MEM8(0x0B27)
#define TCB2_DBGCTRL  _SFR_MEM8(0x0B28)
#define TCB2_TEMP  _SFR_MEM8(0x0B29)
#define TCB2_CNT  _SFR_MEM16(0x0B2A)
#define TCB2_CNTL  _SFR_MEM8(0x0B2A)
#define TCB2_CNTH  _SFR_MEM8(0x0B2B)
#define TCB2_CCMP  _SFR_MEM16(0x0B2C)
#define TCB2_CCMPL  _SFR_MEM8(0x0B2C)
#define TCB2_CCMPH  _SFR_MEM8(0x0B2D)


/* TCB (TCB3) - 16-bit Timer Type B */
#define TCB3_CTRLA  _SFR_MEM8(0x0B30)
#define TCB3_CTRLB  _SFR_MEM8(0x0B31)
#define TCB3_EVCTRL  _SFR_MEM8(0x0B34)
#define TCB3_INTCTRL  _SFR_MEM8(0x0B35)
#define TCB3_INTFLAGS  _SFR_MEM8(0x0B36)
#define TCB3_STATUS  _SFR_MEM8(0x0B37)
#define TCB3_DBGCTRL  _SFR_MEM8(0x0B38)
#define TCB3_TEMP  _SFR_MEM8(0x0B39)
#define TCB3_CNT  _SFR_MEM16(0x0B3A)
#define TCB3_CNTL  _SFR_MEM8(0x0B3A)
#define TCB3_CNTH  _SFR_MEM8(0x0B3B)
#define TCB3_CCMP  _SFR_MEM16(0x0B3C)
#define TCB3_CCMPL  _SFR_MEM8(0x0B3C)
#define TCB3_CCMPH  _SFR_MEM8(0x0B3D)


/* TCB (TCB4) - 16-bit Timer Type B */
#define TCB4_CTRLA  _SFR_MEM8(0x0B40)
#define TCB4_CTRLB  _SFR_MEM8(0x0B41)
#define TCB4_EVCTRL  _SFR_MEM8(0x0B44)
#define TCB4_INTCTRL  _SFR_MEM8(0x0B45)
#define TCB4_INTFLAGS  _SFR_MEM8(0x0B46)
#define TCB4_STATUS  _SFR_MEM8(0x0B47)
#define TCB4_DBGCTRL  _SFR_MEM8(0x0B48)
#define TCB4_TEMP  _SFR_MEM8(0x0B49)
#define TCB4_CNT  _SFR_MEM16(0x0B4A)
#define TCB4_CNTL  _SFR_MEM8(0x0B4A)
#define TCB4_CNTH  _SFR_MEM8(0x0B4B)
#define TCB4_CCMP  _SFR_MEM16(0x0B4C)
#define TCB4_CCMPL  _SFR_MEM8(0x0B4C)
#define TCB4_CCMPH  _SFR_MEM8(0x0B4D)


/* TCD (TCD0) - Timer Counter D */
#define TCD0_CTRLA  _SFR_MEM8(0x0B80)
#define TCD0_CTRLB  _SFR_MEM8(0x0B81)
#define TCD0_CTRLC  _SFR_MEM8(0x0B82)
#define TCD0_CTRLD  _SFR_MEM8(0x0B83)
#define TCD0_CTRLE  _SFR_MEM8(0x0B84)
#define TCD0_EVCTRLA  _SFR_MEM8(0x0B88)
#define TCD0_EVCTRLB  _SFR_MEM8(0x0B89)
#define TCD0_INTCTRL  _SFR_MEM8(0x0B8C)
#define TCD0_INTFLAGS  _SFR_MEM8(0x0B8D)
#define TCD0_STATUS  _SFR_MEM8(0x0B8E)
#define TCD0_INPUTCTRLA  _SFR_MEM8(0x0B90)
#define TCD0_INPUTCTRLB  _SFR_MEM8(0x0B91)
#define TCD0_FAULTCTRL  _SFR_MEM8(0x0B92)
#define TCD0_DLYCTRL  _SFR_MEM8(0x0B94)
#define TCD0_DLYVAL  _SFR_MEM8(0x0B95)
#define TCD0_DITCTRL  _SFR_MEM8(0x0B98)
#define TCD0_DITVAL  _SFR_MEM8(0x0B99)
#define TCD0_DBGCTRL  _SFR_MEM8(0x0B9E)
#define TCD0_CAPTUREA  _SFR_MEM16(0x0BA2)
#define TCD0_CAPTUREAL  _SFR_MEM8(0x0BA2)
#define TCD0_CAPTUREAH  _SFR_MEM8(0x0BA3)
#define TCD0_CAPTUREB  _SFR_MEM16(0x0BA4)
#define TCD0_CAPTUREBL  _SFR_MEM8(0x0BA4)
#define TCD0_CAPTUREBH  _SFR_MEM8(0x0BA5)
#define TCD0_CMPASET  _SFR_MEM16(0x0BA8)
#define TCD0_CMPASETL  _SFR_MEM8(0x0BA8)
#define TCD0_CMPASETH  _SFR_MEM8(0x0BA9)
#define TCD0_CMPACLR  _SFR_MEM16(0x0BAA)
#define TCD0_CMPACLRL  _SFR_MEM8(0x0BAA)
#define TCD0_CMPACLRH  _SFR_MEM8(0x0BAB)
#define TCD0_CMPBSET  _SFR_MEM16(0x0BAC)
#define TCD0_CMPBSETL  _SFR_MEM8(0x0BAC)
#define TCD0_CMPBSETH  _SFR_MEM8(0x0BAD)
#define TCD0_CMPBCLR  _SFR_MEM16(0x0BAE)
#define TCD0_CMPBCLRL  _SFR_MEM8(0x0BAE)
#define TCD0_CMPBCLRH  _SFR_MEM8(0x0BAF)


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


/* NVMBIST - BIST in the NVMCTRL module */
#define NVMBIST_CTRLA  _SFR_MEM8(0x0E80)
#define NVMBIST_ADDRPAT  _SFR_MEM8(0x0E81)
#define NVMBIST_DATAPAT  _SFR_MEM8(0x0E82)
#define NVMBIST_STATUS  _SFR_MEM8(0x0E83)
#define NVMBIST_CNT  _SFR_MEM16(0x0E84)
#define NVMBIST_CNTL  _SFR_MEM8(0x0E84)
#define NVMBIST_CNTH  _SFR_MEM8(0x0E85)
#define NVMBIST_END  _SFR_MEM32(0x0E86)
#define NVMBIST_END0  _SFR_MEM8(0x0E86)
#define NVMBIST_END1  _SFR_MEM8(0x0E87)
#define NVMBIST_END2  _SFR_MEM8(0x0E88)
#define NVMBIST_END3  _SFR_MEM8(0x0E89)


/* TESTWIRE - Test Wire */
#define TESTWIRE_DTW0CTRL  _SFR_MEM8(0x0E90)
#define TESTWIRE_DTW0ROUTE  _SFR_MEM8(0x0E91)
#define TESTWIRE_DTW1CTRL  _SFR_MEM8(0x0E92)
#define TESTWIRE_DTW1ROUTE  _SFR_MEM8(0x0E93)
#define TESTWIRE_DTW2CTRL  _SFR_MEM8(0x0E94)
#define TESTWIRE_DTW2ROUTE  _SFR_MEM8(0x0E95)
#define TESTWIRE_DTW3CTRL  _SFR_MEM8(0x0E96)
#define TESTWIRE_DTW3ROUTE  _SFR_MEM8(0x0E97)
#define TESTWIRE_ATWICTRL  _SFR_MEM8(0x0E98)
#define TESTWIRE_ATWIROUTE  _SFR_MEM8(0x0E99)
#define TESTWIRE_ATWOCTRL  _SFR_MEM8(0x0E9A)
#define TESTWIRE_ATWOROUTE  _SFR_MEM8(0x0E9B)


/* BANDGAP - Bandgap */
#define BANDGAP_BGMCAL0  _SFR_MEM8(0x0EA0)
#define BANDGAP_BGMCAL1  _SFR_MEM8(0x0EA1)
#define BANDGAP_BGXCAL0  _SFR_MEM8(0x0EA2)
#define BANDGAP_BGXCAL1  _SFR_MEM8(0x0EA3)
#define BANDGAP_BGCFG0  _SFR_MEM8(0x0EA4)
#define BANDGAP_TEST  _SFR_MEM8(0x0EA5)
#define BANDGAP_STATUS  _SFR_MEM8(0x0EA6)


/* OSCTEST - Oscillator test interface */
#define OSCTEST_CTRLA  _SFR_MEM8(0x0EA8)


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


/* USERROW - User Row */
#define USERROW_USERROW0  _SFR_MEM8(0x1080)
#define USERROW_USERROW1  _SFR_MEM8(0x1081)
#define USERROW_USERROW2  _SFR_MEM8(0x1082)
#define USERROW_USERROW3  _SFR_MEM8(0x1083)
#define USERROW_USERROW4  _SFR_MEM8(0x1084)
#define USERROW_USERROW5  _SFR_MEM8(0x1085)
#define USERROW_USERROW6  _SFR_MEM8(0x1086)
#define USERROW_USERROW7  _SFR_MEM8(0x1087)
#define USERROW_USERROW8  _SFR_MEM8(0x1088)
#define USERROW_USERROW9  _SFR_MEM8(0x1089)
#define USERROW_USERROW10  _SFR_MEM8(0x108A)
#define USERROW_USERROW11  _SFR_MEM8(0x108B)
#define USERROW_USERROW12  _SFR_MEM8(0x108C)
#define USERROW_USERROW13  _SFR_MEM8(0x108D)
#define USERROW_USERROW14  _SFR_MEM8(0x108E)
#define USERROW_USERROW15  _SFR_MEM8(0x108F)
#define USERROW_USERROW16  _SFR_MEM8(0x1090)
#define USERROW_USERROW17  _SFR_MEM8(0x1091)
#define USERROW_USERROW18  _SFR_MEM8(0x1092)
#define USERROW_USERROW19  _SFR_MEM8(0x1093)
#define USERROW_USERROW20  _SFR_MEM8(0x1094)
#define USERROW_USERROW21  _SFR_MEM8(0x1095)
#define USERROW_USERROW22  _SFR_MEM8(0x1096)
#define USERROW_USERROW23  _SFR_MEM8(0x1097)
#define USERROW_USERROW24  _SFR_MEM8(0x1098)
#define USERROW_USERROW25  _SFR_MEM8(0x1099)
#define USERROW_USERROW26  _SFR_MEM8(0x109A)
#define USERROW_USERROW27  _SFR_MEM8(0x109B)
#define USERROW_USERROW28  _SFR_MEM8(0x109C)
#define USERROW_USERROW29  _SFR_MEM8(0x109D)
#define USERROW_USERROW30  _SFR_MEM8(0x109E)
#define USERROW_USERROW31  _SFR_MEM8(0x109F)


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

/* AC.DACREFL  bit masks and bit positions */
#define AC_DACREFL_gm  0xC0  /* Dac Reference Low group mask. */
#define AC_DACREFL_gp  6  /* Dac Reference Low group position. */
#define AC_DACREFL_0_bm  (1<<6)  /* Dac Reference Low bit 0 mask. */
#define AC_DACREFL_0_bp  6  /* Dac Reference Low bit 0 position. */
#define AC_DACREFL_1_bm  (1<<7)  /* Dac Reference Low bit 1 mask. */
#define AC_DACREFL_1_bp  7  /* Dac Reference Low bit 1 position. */

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
#define AC_CMP_bm  0x01  /* Analog Comparator 0 Interrupt Enable bit mask. */
#define AC_CMP_bp  0  /* Analog Comparator 0 Interrupt Enable bit position. */
#define AC_INTMODE_gm  0x30  /* Interrupt Mode group mask. */
#define AC_INTMODE_gp  4  /* Interrupt Mode group position. */
#define AC_INTMODE_0_bm  (1<<4)  /* Interrupt Mode bit 0 mask. */
#define AC_INTMODE_0_bp  4  /* Interrupt Mode bit 0 position. */
#define AC_INTMODE_1_bm  (1<<5)  /* Interrupt Mode bit 1 mask. */
#define AC_INTMODE_1_bp  5  /* Interrupt Mode bit 1 position. */

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


/* ADC - Analog to Digital Converter */
/* ADC.CTRLA  bit masks and bit positions */
#define ADC_ENABLE_bm  0x01  /* ADC Enable bit mask. */
#define ADC_ENABLE_bp  0  /* ADC Enable bit position. */
#define ADC_FREERUN_bm  0x02  /* Free running mode bit mask. */
#define ADC_FREERUN_bp  1  /* Free running mode bit position. */
#define ADC_RESSEL_gm  0x0C  /* Resolution selection group mask. */
#define ADC_RESSEL_gp  2  /* Resolution selection group position. */
#define ADC_RESSEL_0_bm  (1<<2)  /* Resolution selection bit 0 mask. */
#define ADC_RESSEL_0_bp  2  /* Resolution selection bit 0 position. */
#define ADC_RESSEL0_bm  ADC_RESSEL_0_bm  /* This define is deprecated and should not be used */
#define ADC_RESSEL0_bp  ADC_RESSEL_0_bp  /* This define is deprecated and should not be used */
#define ADC_RESSEL_1_bm  (1<<3)  /* Resolution selection bit 1 mask. */
#define ADC_RESSEL_1_bp  3  /* Resolution selection bit 1 position. */
#define ADC_RESSEL1_bm  ADC_RESSEL_1_bm  /* This define is deprecated and should not be used */
#define ADC_RESSEL1_bp  ADC_RESSEL_1_bp  /* This define is deprecated and should not be used */
#define ADC_LEFTADJ_bm  0x10  /* Left adjust result bit mask. */
#define ADC_LEFTADJ_bp  4  /* Left adjust result bit position. */
#define ADC_CONVMODE_bm  0x20  /* Conversion mode bit mask. */
#define ADC_CONVMODE_bp  5  /* Conversion mode bit position. */
#define ADC_RUNSTBY_bm  0x80  /* Run standby mode bit mask. */
#define ADC_RUNSTBY_bp  7  /* Run standby mode bit position. */

/* ADC.CTRLB  bit masks and bit positions */
#define ADC_SAMPNUM_gm  0x07  /* Accumulation Samples group mask. */
#define ADC_SAMPNUM_gp  0  /* Accumulation Samples group position. */
#define ADC_SAMPNUM_0_bm  (1<<0)  /* Accumulation Samples bit 0 mask. */
#define ADC_SAMPNUM_0_bp  0  /* Accumulation Samples bit 0 position. */
#define ADC_SAMPNUM_1_bm  (1<<1)  /* Accumulation Samples bit 1 mask. */
#define ADC_SAMPNUM_1_bp  1  /* Accumulation Samples bit 1 position. */
#define ADC_SAMPNUM_2_bm  (1<<2)  /* Accumulation Samples bit 2 mask. */
#define ADC_SAMPNUM_2_bp  2  /* Accumulation Samples bit 2 position. */

/* ADC.CTRLC  bit masks and bit positions */
#define ADC_PRESC_gm  0x0F  /* Clock Pre-scaler group mask. */
#define ADC_PRESC_gp  0  /* Clock Pre-scaler group position. */
#define ADC_PRESC_0_bm  (1<<0)  /* Clock Pre-scaler bit 0 mask. */
#define ADC_PRESC_0_bp  0  /* Clock Pre-scaler bit 0 position. */
#define ADC_PRESC_1_bm  (1<<1)  /* Clock Pre-scaler bit 1 mask. */
#define ADC_PRESC_1_bp  1  /* Clock Pre-scaler bit 1 position. */
#define ADC_PRESC_2_bm  (1<<2)  /* Clock Pre-scaler bit 2 mask. */
#define ADC_PRESC_2_bp  2  /* Clock Pre-scaler bit 2 position. */
#define ADC_PRESC_3_bm  (1<<3)  /* Clock Pre-scaler bit 3 mask. */
#define ADC_PRESC_3_bp  3  /* Clock Pre-scaler bit 3 position. */

/* ADC.CTRLD  bit masks and bit positions */
#define ADC_SAMPDLY_gm  0x0F  /* Sampling Delay Selection group mask. */
#define ADC_SAMPDLY_gp  0  /* Sampling Delay Selection group position. */
#define ADC_SAMPDLY_0_bm  (1<<0)  /* Sampling Delay Selection bit 0 mask. */
#define ADC_SAMPDLY_0_bp  0  /* Sampling Delay Selection bit 0 position. */
#define ADC_SAMPDLY_1_bm  (1<<1)  /* Sampling Delay Selection bit 1 mask. */
#define ADC_SAMPDLY_1_bp  1  /* Sampling Delay Selection bit 1 position. */
#define ADC_SAMPDLY_2_bm  (1<<2)  /* Sampling Delay Selection bit 2 mask. */
#define ADC_SAMPDLY_2_bp  2  /* Sampling Delay Selection bit 2 position. */
#define ADC_SAMPDLY_3_bm  (1<<3)  /* Sampling Delay Selection bit 3 mask. */
#define ADC_SAMPDLY_3_bp  3  /* Sampling Delay Selection bit 3 position. */
#define ADC_INITDLY_gm  0xE0  /* Initial Delay Selection group mask. */
#define ADC_INITDLY_gp  5  /* Initial Delay Selection group position. */
#define ADC_INITDLY_0_bm  (1<<5)  /* Initial Delay Selection bit 0 mask. */
#define ADC_INITDLY_0_bp  5  /* Initial Delay Selection bit 0 position. */
#define ADC_INITDLY_1_bm  (1<<6)  /* Initial Delay Selection bit 1 mask. */
#define ADC_INITDLY_1_bp  6  /* Initial Delay Selection bit 1 position. */
#define ADC_INITDLY_2_bm  (1<<7)  /* Initial Delay Selection bit 2 mask. */
#define ADC_INITDLY_2_bp  7  /* Initial Delay Selection bit 2 position. */

/* ADC.CTRLE  bit masks and bit positions */
#define ADC_WINCM_gm  0x07  /* Window Comparator Mode group mask. */
#define ADC_WINCM_gp  0  /* Window Comparator Mode group position. */
#define ADC_WINCM_0_bm  (1<<0)  /* Window Comparator Mode bit 0 mask. */
#define ADC_WINCM_0_bp  0  /* Window Comparator Mode bit 0 position. */
#define ADC_WINCM_1_bm  (1<<1)  /* Window Comparator Mode bit 1 mask. */
#define ADC_WINCM_1_bp  1  /* Window Comparator Mode bit 1 position. */
#define ADC_WINCM_2_bm  (1<<2)  /* Window Comparator Mode bit 2 mask. */
#define ADC_WINCM_2_bp  2  /* Window Comparator Mode bit 2 position. */

/* ADC.SAMPCTRL  bit masks and bit positions */
#define ADC_SAMPLEN_gm  0xFF  /* Sample lenght group mask. */
#define ADC_SAMPLEN_gp  0  /* Sample lenght group position. */
#define ADC_SAMPLEN_0_bm  (1<<0)  /* Sample lenght bit 0 mask. */
#define ADC_SAMPLEN_0_bp  0  /* Sample lenght bit 0 position. */
#define ADC_SAMPLEN_1_bm  (1<<1)  /* Sample lenght bit 1 mask. */
#define ADC_SAMPLEN_1_bp  1  /* Sample lenght bit 1 position. */
#define ADC_SAMPLEN_2_bm  (1<<2)  /* Sample lenght bit 2 mask. */
#define ADC_SAMPLEN_2_bp  2  /* Sample lenght bit 2 position. */
#define ADC_SAMPLEN_3_bm  (1<<3)  /* Sample lenght bit 3 mask. */
#define ADC_SAMPLEN_3_bp  3  /* Sample lenght bit 3 position. */
#define ADC_SAMPLEN_4_bm  (1<<4)  /* Sample lenght bit 4 mask. */
#define ADC_SAMPLEN_4_bp  4  /* Sample lenght bit 4 position. */
#define ADC_SAMPLEN_5_bm  (1<<5)  /* Sample lenght bit 5 mask. */
#define ADC_SAMPLEN_5_bp  5  /* Sample lenght bit 5 position. */
#define ADC_SAMPLEN_6_bm  (1<<6)  /* Sample lenght bit 6 mask. */
#define ADC_SAMPLEN_6_bp  6  /* Sample lenght bit 6 position. */
#define ADC_SAMPLEN_7_bm  (1<<7)  /* Sample lenght bit 7 mask. */
#define ADC_SAMPLEN_7_bp  7  /* Sample lenght bit 7 position. */

/* ADC.MUXPOS  bit masks and bit positions */
#define ADC_MUXPOS_gm  0x7F  /* Analog Channel Selection Bits group mask. */
#define ADC_MUXPOS_gp  0  /* Analog Channel Selection Bits group position. */
#define ADC_MUXPOS_0_bm  (1<<0)  /* Analog Channel Selection Bits bit 0 mask. */
#define ADC_MUXPOS_0_bp  0  /* Analog Channel Selection Bits bit 0 position. */
#define ADC_MUXPOS_1_bm  (1<<1)  /* Analog Channel Selection Bits bit 1 mask. */
#define ADC_MUXPOS_1_bp  1  /* Analog Channel Selection Bits bit 1 position. */
#define ADC_MUXPOS_2_bm  (1<<2)  /* Analog Channel Selection Bits bit 2 mask. */
#define ADC_MUXPOS_2_bp  2  /* Analog Channel Selection Bits bit 2 position. */
#define ADC_MUXPOS_3_bm  (1<<3)  /* Analog Channel Selection Bits bit 3 mask. */
#define ADC_MUXPOS_3_bp  3  /* Analog Channel Selection Bits bit 3 position. */
#define ADC_MUXPOS_4_bm  (1<<4)  /* Analog Channel Selection Bits bit 4 mask. */
#define ADC_MUXPOS_4_bp  4  /* Analog Channel Selection Bits bit 4 position. */
#define ADC_MUXPOS_5_bm  (1<<5)  /* Analog Channel Selection Bits bit 5 mask. */
#define ADC_MUXPOS_5_bp  5  /* Analog Channel Selection Bits bit 5 position. */
#define ADC_MUXPOS_6_bm  (1<<6)  /* Analog Channel Selection Bits bit 6 mask. */
#define ADC_MUXPOS_6_bp  6  /* Analog Channel Selection Bits bit 6 position. */

/* ADC.MUXNEG  bit masks and bit positions */
#define ADC_MUXNEG_gm  0x7F  /* Analog Channel Selection Bits group mask. */
#define ADC_MUXNEG_gp  0  /* Analog Channel Selection Bits group position. */
#define ADC_MUXNEG_0_bm  (1<<0)  /* Analog Channel Selection Bits bit 0 mask. */
#define ADC_MUXNEG_0_bp  0  /* Analog Channel Selection Bits bit 0 position. */
#define ADC_MUXNEG_1_bm  (1<<1)  /* Analog Channel Selection Bits bit 1 mask. */
#define ADC_MUXNEG_1_bp  1  /* Analog Channel Selection Bits bit 1 position. */
#define ADC_MUXNEG_2_bm  (1<<2)  /* Analog Channel Selection Bits bit 2 mask. */
#define ADC_MUXNEG_2_bp  2  /* Analog Channel Selection Bits bit 2 position. */
#define ADC_MUXNEG_3_bm  (1<<3)  /* Analog Channel Selection Bits bit 3 mask. */
#define ADC_MUXNEG_3_bp  3  /* Analog Channel Selection Bits bit 3 position. */
#define ADC_MUXNEG_4_bm  (1<<4)  /* Analog Channel Selection Bits bit 4 mask. */
#define ADC_MUXNEG_4_bp  4  /* Analog Channel Selection Bits bit 4 position. */
#define ADC_MUXNEG_5_bm  (1<<5)  /* Analog Channel Selection Bits bit 5 mask. */
#define ADC_MUXNEG_5_bp  5  /* Analog Channel Selection Bits bit 5 position. */
#define ADC_MUXNEG_6_bm  (1<<6)  /* Analog Channel Selection Bits bit 6 mask. */
#define ADC_MUXNEG_6_bp  6  /* Analog Channel Selection Bits bit 6 position. */

/* ADC.COMMAND  bit masks and bit positions */
#define ADC_STCONV_bm  0x01  /* Start Conversion bit mask. */
#define ADC_STCONV_bp  0  /* Start Conversion bit position. */
#define ADC_SPCONV_bm  0x02  /* Stop Conversion bit mask. */
#define ADC_SPCONV_bp  1  /* Stop Conversion bit position. */

/* ADC.EVCTRL  bit masks and bit positions */
#define ADC_STARTEI_bm  0x01  /* Start Event Input Enable bit mask. */
#define ADC_STARTEI_bp  0  /* Start Event Input Enable bit position. */

/* ADC.INTCTRL  bit masks and bit positions */
#define ADC_RESRDY_bm  0x01  /* Result Ready Interrupt Enable bit mask. */
#define ADC_RESRDY_bp  0  /* Result Ready Interrupt Enable bit position. */
#define ADC_WCMP_bm  0x02  /* Window Comparator Interrupt Enable bit mask. */
#define ADC_WCMP_bp  1  /* Window Comparator Interrupt Enable bit position. */

/* ADC.INTFLAGS  bit masks and bit positions */
/* ADC_RESRDY  is already defined. */
/* ADC_WCMP  is already defined. */

/* ADC.DBGCTRL  bit masks and bit positions */
#define ADC_DBGRUN_bm  0x01  /* Debug run bit mask. */
#define ADC_DBGRUN_bp  0  /* Debug run bit position. */

/* ADC.TEMP  bit masks and bit positions */
#define ADC_TEMP_gm  0xFF  /* Temporary group mask. */
#define ADC_TEMP_gp  0  /* Temporary group position. */
#define ADC_TEMP_0_bm  (1<<0)  /* Temporary bit 0 mask. */
#define ADC_TEMP_0_bp  0  /* Temporary bit 0 position. */
#define ADC_TEMP_1_bm  (1<<1)  /* Temporary bit 1 mask. */
#define ADC_TEMP_1_bp  1  /* Temporary bit 1 position. */
#define ADC_TEMP_2_bm  (1<<2)  /* Temporary bit 2 mask. */
#define ADC_TEMP_2_bp  2  /* Temporary bit 2 position. */
#define ADC_TEMP_3_bm  (1<<3)  /* Temporary bit 3 mask. */
#define ADC_TEMP_3_bp  3  /* Temporary bit 3 position. */
#define ADC_TEMP_4_bm  (1<<4)  /* Temporary bit 4 mask. */
#define ADC_TEMP_4_bp  4  /* Temporary bit 4 position. */
#define ADC_TEMP_5_bm  (1<<5)  /* Temporary bit 5 mask. */
#define ADC_TEMP_5_bp  5  /* Temporary bit 5 position. */
#define ADC_TEMP_6_bm  (1<<6)  /* Temporary bit 6 mask. */
#define ADC_TEMP_6_bp  6  /* Temporary bit 6 position. */
#define ADC_TEMP_7_bm  (1<<7)  /* Temporary bit 7 mask. */
#define ADC_TEMP_7_bp  7  /* Temporary bit 7 position. */

/* ADC.CAL  bit masks and bit positions */
#define ADC_DIFFCFG_bm  0x01  /* Differential mode config bit mask. */
#define ADC_DIFFCFG_bp  0  /* Differential mode config bit position. */
#define ADC_PUMPEN_bm  0x02  /* ADC pump enable bit mask. */
#define ADC_PUMPEN_bp  1  /* ADC pump enable bit position. */
#define ADC_AMPDIS_bm  0x04  /* Internal amplification disable bit mask. */
#define ADC_AMPDIS_bp  2  /* Internal amplification disable bit position. */


/* BANDGAP - Bandgap */
/* BANDGAP.BGMCAL0  bit masks and bit positions */
#define BANDGAP_VCAL_gm  0x3F  /* Bandgap Main Calibration 0 group mask. */
#define BANDGAP_VCAL_gp  0  /* Bandgap Main Calibration 0 group position. */
#define BANDGAP_VCAL_0_bm  (1<<0)  /* Bandgap Main Calibration 0 bit 0 mask. */
#define BANDGAP_VCAL_0_bp  0  /* Bandgap Main Calibration 0 bit 0 position. */
#define BANDGAP_VCAL_1_bm  (1<<1)  /* Bandgap Main Calibration 0 bit 1 mask. */
#define BANDGAP_VCAL_1_bp  1  /* Bandgap Main Calibration 0 bit 1 position. */
#define BANDGAP_VCAL_2_bm  (1<<2)  /* Bandgap Main Calibration 0 bit 2 mask. */
#define BANDGAP_VCAL_2_bp  2  /* Bandgap Main Calibration 0 bit 2 position. */
#define BANDGAP_VCAL_3_bm  (1<<3)  /* Bandgap Main Calibration 0 bit 3 mask. */
#define BANDGAP_VCAL_3_bp  3  /* Bandgap Main Calibration 0 bit 3 position. */
#define BANDGAP_VCAL_4_bm  (1<<4)  /* Bandgap Main Calibration 0 bit 4 mask. */
#define BANDGAP_VCAL_4_bp  4  /* Bandgap Main Calibration 0 bit 4 position. */
#define BANDGAP_VCAL_5_bm  (1<<5)  /* Bandgap Main Calibration 0 bit 5 mask. */
#define BANDGAP_VCAL_5_bp  5  /* Bandgap Main Calibration 0 bit 5 position. */

/* BANDGAP.BGMCAL1  bit masks and bit positions */
#define BANDGAP_ICAL_gm  0x0F  /* Current Calibration group mask. */
#define BANDGAP_ICAL_gp  0  /* Current Calibration group position. */
#define BANDGAP_ICAL_0_bm  (1<<0)  /* Current Calibration bit 0 mask. */
#define BANDGAP_ICAL_0_bp  0  /* Current Calibration bit 0 position. */
#define BANDGAP_ICAL_1_bm  (1<<1)  /* Current Calibration bit 1 mask. */
#define BANDGAP_ICAL_1_bp  1  /* Current Calibration bit 1 position. */
#define BANDGAP_ICAL_2_bm  (1<<2)  /* Current Calibration bit 2 mask. */
#define BANDGAP_ICAL_2_bp  2  /* Current Calibration bit 2 position. */
#define BANDGAP_ICAL_3_bm  (1<<3)  /* Current Calibration bit 3 mask. */
#define BANDGAP_ICAL_3_bp  3  /* Current Calibration bit 3 position. */
#define BANDGAP_RANGE_bm  0x10  /* Range bit mask. */
#define BANDGAP_RANGE_bp  4  /* Range bit position. */
#define BANDGAP_TCAL_gm  0xE0  /* Temperature Calibration group mask. */
#define BANDGAP_TCAL_gp  5  /* Temperature Calibration group position. */
#define BANDGAP_TCAL_0_bm  (1<<5)  /* Temperature Calibration bit 0 mask. */
#define BANDGAP_TCAL_0_bp  5  /* Temperature Calibration bit 0 position. */
#define BANDGAP_TCAL_1_bm  (1<<6)  /* Temperature Calibration bit 1 mask. */
#define BANDGAP_TCAL_1_bp  6  /* Temperature Calibration bit 1 position. */
#define BANDGAP_TCAL_2_bm  (1<<7)  /* Temperature Calibration bit 2 mask. */
#define BANDGAP_TCAL_2_bp  7  /* Temperature Calibration bit 2 position. */

/* BANDGAP.BGXCAL0  bit masks and bit positions */
/* BANDGAP_VCAL  is already defined. */

/* BANDGAP.BGXCAL1  bit masks and bit positions */
/* BANDGAP_ICAL  is already defined. */
/* BANDGAP_TCAL  is already defined. */

/* BANDGAP.BGCFG0  bit masks and bit positions */
#define BANDGAP_MODE_gm  0x03  /* Mode group mask. */
#define BANDGAP_MODE_gp  0  /* Mode group position. */
#define BANDGAP_MODE_0_bm  (1<<0)  /* Mode bit 0 mask. */
#define BANDGAP_MODE_0_bp  0  /* Mode bit 0 position. */
#define BANDGAP_MODE_1_bm  (1<<1)  /* Mode bit 1 mask. */
#define BANDGAP_MODE_1_bp  1  /* Mode bit 1 position. */
#define BANDGAP_STABLESEL_gm  0x0C  /* Main Bandgap Stable Selection group mask. */
#define BANDGAP_STABLESEL_gp  2  /* Main Bandgap Stable Selection group position. */
#define BANDGAP_STABLESEL_0_bm  (1<<2)  /* Main Bandgap Stable Selection bit 0 mask. */
#define BANDGAP_STABLESEL_0_bp  2  /* Main Bandgap Stable Selection bit 0 position. */
#define BANDGAP_STABLESEL_1_bm  (1<<3)  /* Main Bandgap Stable Selection bit 1 mask. */
#define BANDGAP_STABLESEL_1_bp  3  /* Main Bandgap Stable Selection bit 1 position. */

/* BANDGAP.TEST  bit masks and bit positions */
#define BANDGAP_FORCE_gm  0x03  /* FORCE group mask. */
#define BANDGAP_FORCE_gp  0  /* FORCE group position. */
#define BANDGAP_FORCE_0_bm  (1<<0)  /* FORCE bit 0 mask. */
#define BANDGAP_FORCE_0_bp  0  /* FORCE bit 0 position. */
#define BANDGAP_FORCE_1_bm  (1<<1)  /* FORCE bit 1 mask. */
#define BANDGAP_FORCE_1_bp  1  /* FORCE bit 1 position. */
#define BANDGAP_BUF0DIS_bm  0x04  /* BUF0DIS bit mask. */
#define BANDGAP_BUF0DIS_bp  2  /* BUF0DIS bit position. */
#define BANDGAP_BUF1DIS_bm  0x08  /* BUF1DIS bit mask. */
#define BANDGAP_BUF1DIS_bp  3  /* BUF1DIS bit position. */
#define BANDGAP_RESLADEN_bm  0x10  /* RESLADEN bit mask. */
#define BANDGAP_RESLADEN_bp  4  /* RESLADEN bit position. */
#define BANDGAP_BGXOVER_bm  0x20  /* BGXOVER bit mask. */
#define BANDGAP_BGXOVER_bp  5  /* BGXOVER bit position. */


/* BOD - Bod interface */
/* BOD.CTRLA  bit masks and bit positions */
#define BOD_SLEEP_gm  0x03  /* Operation in sleep mode group mask. */
#define BOD_SLEEP_gp  0  /* Operation in sleep mode group position. */
#define BOD_SLEEP_0_bm  (1<<0)  /* Operation in sleep mode bit 0 mask. */
#define BOD_SLEEP_0_bp  0  /* Operation in sleep mode bit 0 position. */
#define BOD_SLEEP_1_bm  (1<<1)  /* Operation in sleep mode bit 1 mask. */
#define BOD_SLEEP_1_bp  1  /* Operation in sleep mode bit 1 position. */
#define BOD_ACTIVE_gm  0x0C  /* Operation in active mode group mask. */
#define BOD_ACTIVE_gp  2  /* Operation in active mode group position. */
#define BOD_ACTIVE_0_bm  (1<<2)  /* Operation in active mode bit 0 mask. */
#define BOD_ACTIVE_0_bp  2  /* Operation in active mode bit 0 position. */
#define BOD_ACTIVE_1_bm  (1<<3)  /* Operation in active mode bit 1 mask. */
#define BOD_ACTIVE_1_bp  3  /* Operation in active mode bit 1 position. */
#define BOD_SAMPFREQ_bm  0x10  /* Sample frequency bit mask. */
#define BOD_SAMPFREQ_bp  4  /* Sample frequency bit position. */

/* BOD.CTRLB  bit masks and bit positions */
#define BOD_LVL_gm  0x07  /* Bod level group mask. */
#define BOD_LVL_gp  0  /* Bod level group position. */
#define BOD_LVL_0_bm  (1<<0)  /* Bod level bit 0 mask. */
#define BOD_LVL_0_bp  0  /* Bod level bit 0 position. */
#define BOD_LVL_1_bm  (1<<1)  /* Bod level bit 1 mask. */
#define BOD_LVL_1_bp  1  /* Bod level bit 1 position. */
#define BOD_LVL_2_bm  (1<<2)  /* Bod level bit 2 mask. */
#define BOD_LVL_2_bp  2  /* Bod level bit 2 position. */

/* BOD.CALIB  bit masks and bit positions */
#define BOD_CAL_gm  0x07  /* Bod calibration group mask. */
#define BOD_CAL_gp  0  /* Bod calibration group position. */
#define BOD_CAL_0_bm  (1<<0)  /* Bod calibration bit 0 mask. */
#define BOD_CAL_0_bp  0  /* Bod calibration bit 0 position. */
#define BOD_CAL_1_bm  (1<<1)  /* Bod calibration bit 1 mask. */
#define BOD_CAL_1_bp  1  /* Bod calibration bit 1 position. */
#define BOD_CAL_2_bm  (1<<2)  /* Bod calibration bit 2 mask. */
#define BOD_CAL_2_bp  2  /* Bod calibration bit 2 position. */
#define BOD_HYST_gm  0x18  /* Hysterises group mask. */
#define BOD_HYST_gp  3  /* Hysterises group position. */
#define BOD_HYST_0_bm  (1<<3)  /* Hysterises bit 0 mask. */
#define BOD_HYST_0_bp  3  /* Hysterises bit 0 position. */
#define BOD_HYST_1_bm  (1<<4)  /* Hysterises bit 1 mask. */
#define BOD_HYST_1_bp  4  /* Hysterises bit 1 position. */

/* BOD.TSTATUS  bit masks and bit positions */
#define BOD_BODDET_bm  0x01  /* Bod detect bit mask. */
#define BOD_BODDET_bp  0  /* Bod detect bit position. */
#define BOD_BODRDY_bm  0x02  /* Bod ready bit mask. */
#define BOD_BODRDY_bp  1  /* Bod ready bit position. */

/* BOD.TEST  bit masks and bit positions */
#define BOD_RSTDIS_bm  0x01  /* Reset Disable bit mask. */
#define BOD_RSTDIS_bp  0  /* Reset Disable bit position. */
#define BOD_FORCEVLM_bm  0x02  /* Force VLM bit mask. */
#define BOD_FORCEVLM_bp  1  /* Force VLM bit position. */
#define BOD_FORCEBOD_bm  0x04  /* Force BOD bit mask. */
#define BOD_FORCEBOD_bp  2  /* Force BOD bit position. */

/* BOD.VLMCTRLA  bit masks and bit positions */
#define BOD_VLMLVL_gm  0x03  /* voltage level monitor level group mask. */
#define BOD_VLMLVL_gp  0  /* voltage level monitor level group position. */
#define BOD_VLMLVL_0_bm  (1<<0)  /* voltage level monitor level bit 0 mask. */
#define BOD_VLMLVL_0_bp  0  /* voltage level monitor level bit 0 position. */
#define BOD_VLMLVL_1_bm  (1<<1)  /* voltage level monitor level bit 1 mask. */
#define BOD_VLMLVL_1_bp  1  /* voltage level monitor level bit 1 position. */

/* BOD.INTCTRL  bit masks and bit positions */
#define BOD_VLMIE_bm  0x01  /* voltage level monitor interrrupt enable bit mask. */
#define BOD_VLMIE_bp  0  /* voltage level monitor interrrupt enable bit position. */
#define BOD_VLMCFG_gm  0x06  /* Configuration group mask. */
#define BOD_VLMCFG_gp  1  /* Configuration group position. */
#define BOD_VLMCFG_0_bm  (1<<1)  /* Configuration bit 0 mask. */
#define BOD_VLMCFG_0_bp  1  /* Configuration bit 0 position. */
#define BOD_VLMCFG_1_bm  (1<<2)  /* Configuration bit 1 mask. */
#define BOD_VLMCFG_1_bp  2  /* Configuration bit 1 position. */

/* BOD.INTFLAGS  bit masks and bit positions */
#define BOD_VLMIF_bm  0x01  /* Voltage level monitor interrupt flag bit mask. */
#define BOD_VLMIF_bp  0  /* Voltage level monitor interrupt flag bit position. */

/* BOD.STATUS  bit masks and bit positions */
#define BOD_VLMS_bm  0x01  /* Voltage level monitor status bit mask. */
#define BOD_VLMS_bp  0  /* Voltage level monitor status bit position. */


/* CCL - Configurable Custom Logic */
/* CCL.CTRLA  bit masks and bit positions */
#define CCL_ENABLE_bm  0x01  /* Enable bit mask. */
#define CCL_ENABLE_bp  0  /* Enable bit position. */
#define CCL_RUNSTDBY_bm  0x40  /* Run in Standby bit mask. */
#define CCL_RUNSTDBY_bp  6  /* Run in Standby bit position. */

/* CCL.SEQCTRL0  bit masks and bit positions */
#define CCL_SEQSEL0_gm  0x07  /* Sequential Selection group mask. */
#define CCL_SEQSEL0_gp  0  /* Sequential Selection group position. */
#define CCL_SEQSEL0_0_bm  (1<<0)  /* Sequential Selection bit 0 mask. */
#define CCL_SEQSEL0_0_bp  0  /* Sequential Selection bit 0 position. */
#define CCL_SEQSEL0_1_bm  (1<<1)  /* Sequential Selection bit 1 mask. */
#define CCL_SEQSEL0_1_bp  1  /* Sequential Selection bit 1 position. */
#define CCL_SEQSEL0_2_bm  (1<<2)  /* Sequential Selection bit 2 mask. */
#define CCL_SEQSEL0_2_bp  2  /* Sequential Selection bit 2 position. */

/* CCL.SEQCTRL1  bit masks and bit positions */
#define CCL_SEQSEL1_gm  0x07  /* Sequential Selection group mask. */
#define CCL_SEQSEL1_gp  0  /* Sequential Selection group position. */
#define CCL_SEQSEL1_0_bm  (1<<0)  /* Sequential Selection bit 0 mask. */
#define CCL_SEQSEL1_0_bp  0  /* Sequential Selection bit 0 position. */
#define CCL_SEQSEL1_1_bm  (1<<1)  /* Sequential Selection bit 1 mask. */
#define CCL_SEQSEL1_1_bp  1  /* Sequential Selection bit 1 position. */
#define CCL_SEQSEL1_2_bm  (1<<2)  /* Sequential Selection bit 2 mask. */
#define CCL_SEQSEL1_2_bp  2  /* Sequential Selection bit 2 position. */

/* CCL.SEQCTRL2  bit masks and bit positions */
#define CCL_SEQSEL2_gm  0x07  /* Sequential Selection group mask. */
#define CCL_SEQSEL2_gp  0  /* Sequential Selection group position. */
#define CCL_SEQSEL2_0_bm  (1<<0)  /* Sequential Selection bit 0 mask. */
#define CCL_SEQSEL2_0_bp  0  /* Sequential Selection bit 0 position. */
#define CCL_SEQSEL2_1_bm  (1<<1)  /* Sequential Selection bit 1 mask. */
#define CCL_SEQSEL2_1_bp  1  /* Sequential Selection bit 1 position. */
#define CCL_SEQSEL2_2_bm  (1<<2)  /* Sequential Selection bit 2 mask. */
#define CCL_SEQSEL2_2_bp  2  /* Sequential Selection bit 2 position. */

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

/* CCL.INTCTRL1  bit masks and bit positions */
#define CCL_INTMODE4_gm  0x03  /* Interrupt Mode for LUT4 group mask. */
#define CCL_INTMODE4_gp  0  /* Interrupt Mode for LUT4 group position. */
#define CCL_INTMODE4_0_bm  (1<<0)  /* Interrupt Mode for LUT4 bit 0 mask. */
#define CCL_INTMODE4_0_bp  0  /* Interrupt Mode for LUT4 bit 0 position. */
#define CCL_INTMODE4_1_bm  (1<<1)  /* Interrupt Mode for LUT4 bit 1 mask. */
#define CCL_INTMODE4_1_bp  1  /* Interrupt Mode for LUT4 bit 1 position. */
#define CCL_INTMODE5_gm  0x0C  /* Interrupt Mode for LUT5 group mask. */
#define CCL_INTMODE5_gp  2  /* Interrupt Mode for LUT5 group position. */
#define CCL_INTMODE5_0_bm  (1<<2)  /* Interrupt Mode for LUT5 bit 0 mask. */
#define CCL_INTMODE5_0_bp  2  /* Interrupt Mode for LUT5 bit 0 position. */
#define CCL_INTMODE5_1_bm  (1<<3)  /* Interrupt Mode for LUT5 bit 1 mask. */
#define CCL_INTMODE5_1_bp  3  /* Interrupt Mode for LUT5 bit 1 position. */

/* CCL.INTFLAGS  bit masks and bit positions */
#define CCL_INT_gm  0xFF  /* Interrupt Flags group mask. */
#define CCL_INT_gp  0  /* Interrupt Flags group position. */
#define CCL_INT_0_bm  (1<<0)  /* Interrupt Flags bit 0 mask. */
#define CCL_INT_0_bp  0  /* Interrupt Flags bit 0 position. */
#define CCL_INT0_bm  CCL_INT_0_bm  /* This define is deprecated and should not be used */
#define CCL_INT0_bp  CCL_INT_0_bp  /* This define is deprecated and should not be used */
#define CCL_INT_1_bm  (1<<1)  /* Interrupt Flags bit 1 mask. */
#define CCL_INT_1_bp  1  /* Interrupt Flags bit 1 position. */
#define CCL_INT1_bm  CCL_INT_1_bm  /* This define is deprecated and should not be used */
#define CCL_INT1_bp  CCL_INT_1_bp  /* This define is deprecated and should not be used */
#define CCL_INT_2_bm  (1<<2)  /* Interrupt Flags bit 2 mask. */
#define CCL_INT_2_bp  2  /* Interrupt Flags bit 2 position. */
#define CCL_INT2_bm  CCL_INT_2_bm  /* This define is deprecated and should not be used */
#define CCL_INT2_bp  CCL_INT_2_bp  /* This define is deprecated and should not be used */
#define CCL_INT_3_bm  (1<<3)  /* Interrupt Flags bit 3 mask. */
#define CCL_INT_3_bp  3  /* Interrupt Flags bit 3 position. */
#define CCL_INT3_bm  CCL_INT_3_bm  /* This define is deprecated and should not be used */
#define CCL_INT3_bp  CCL_INT_3_bp  /* This define is deprecated and should not be used */
#define CCL_INT_4_bm  (1<<4)  /* Interrupt Flags bit 4 mask. */
#define CCL_INT_4_bp  4  /* Interrupt Flags bit 4 position. */
#define CCL_INT4_bm  CCL_INT_4_bm  /* This define is deprecated and should not be used */
#define CCL_INT4_bp  CCL_INT_4_bp  /* This define is deprecated and should not be used */
#define CCL_INT_5_bm  (1<<5)  /* Interrupt Flags bit 5 mask. */
#define CCL_INT_5_bp  5  /* Interrupt Flags bit 5 position. */
#define CCL_INT5_bm  CCL_INT_5_bm  /* This define is deprecated and should not be used */
#define CCL_INT5_bp  CCL_INT_5_bp  /* This define is deprecated and should not be used */
#define CCL_INT_6_bm  (1<<6)  /* Interrupt Flags bit 6 mask. */
#define CCL_INT_6_bp  6  /* Interrupt Flags bit 6 position. */
#define CCL_INT6_bm  CCL_INT_6_bm  /* This define is deprecated and should not be used */
#define CCL_INT6_bp  CCL_INT_6_bp  /* This define is deprecated and should not be used */
#define CCL_INT_7_bm  (1<<7)  /* Interrupt Flags bit 7 mask. */
#define CCL_INT_7_bp  7  /* Interrupt Flags bit 7 position. */
#define CCL_INT7_bm  CCL_INT_7_bm  /* This define is deprecated and should not be used */
#define CCL_INT7_bp  CCL_INT_7_bp  /* This define is deprecated and should not be used */

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

/* CCL.LUT4CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT4CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT4CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */

/* CCL.LUT5CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT5CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT5CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */


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
#define CLKCTRL_FRQSEL_gm  0x3C  /* Frequency select group mask. */
#define CLKCTRL_FRQSEL_gp  2  /* Frequency select group position. */
#define CLKCTRL_FRQSEL_0_bm  (1<<2)  /* Frequency select bit 0 mask. */
#define CLKCTRL_FRQSEL_0_bp  2  /* Frequency select bit 0 position. */
#define CLKCTRL_FRQSEL_1_bm  (1<<3)  /* Frequency select bit 1 mask. */
#define CLKCTRL_FRQSEL_1_bp  3  /* Frequency select bit 1 position. */
#define CLKCTRL_FRQSEL_2_bm  (1<<4)  /* Frequency select bit 2 mask. */
#define CLKCTRL_FRQSEL_2_bp  4  /* Frequency select bit 2 position. */
#define CLKCTRL_FRQSEL_3_bm  (1<<5)  /* Frequency select bit 3 mask. */
#define CLKCTRL_FRQSEL_3_bp  5  /* Frequency select bit 3 position. */
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


/* DAC - Digital to Analog Converter */
/* DAC.CTRLA  bit masks and bit positions */
#define DAC_ENABLE_bm  0x01  /* DAC Enable bit mask. */
#define DAC_ENABLE_bp  0  /* DAC Enable bit position. */
#define DAC_BUFRANGE_bm  0x20  /* Buffer Range bit mask. */
#define DAC_BUFRANGE_bp  5  /* Buffer Range bit position. */
#define DAC_OUTEN_bm  0x40  /* Output Buffer Enable bit mask. */
#define DAC_OUTEN_bp  6  /* Output Buffer Enable bit position. */
#define DAC_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define DAC_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */

/* DAC.DATA  bit masks and bit positions */
#define DAC_DATA_gm  0xFFC0  /* Data group mask. */
#define DAC_DATA_gp  6  /* Data group position. */
#define DAC_DATA_0_bm  (1<<6)  /* Data bit 0 mask. */
#define DAC_DATA_0_bp  6  /* Data bit 0 position. */
#define DAC_DATA_1_bm  (1<<7)  /* Data bit 1 mask. */
#define DAC_DATA_1_bp  7  /* Data bit 1 position. */
#define DAC_DATA_2_bm  (1<<8)  /* Data bit 2 mask. */
#define DAC_DATA_2_bp  8  /* Data bit 2 position. */
#define DAC_DATA_3_bm  (1<<9)  /* Data bit 3 mask. */
#define DAC_DATA_3_bp  9  /* Data bit 3 position. */
#define DAC_DATA_4_bm  (1<<10)  /* Data bit 4 mask. */
#define DAC_DATA_4_bp  10  /* Data bit 4 position. */
#define DAC_DATA_5_bm  (1<<11)  /* Data bit 5 mask. */
#define DAC_DATA_5_bp  11  /* Data bit 5 position. */
#define DAC_DATA_6_bm  (1<<12)  /* Data bit 6 mask. */
#define DAC_DATA_6_bp  12  /* Data bit 6 position. */
#define DAC_DATA_7_bm  (1<<13)  /* Data bit 7 mask. */
#define DAC_DATA_7_bp  13  /* Data bit 7 position. */
#define DAC_DATA_8_bm  (1<<14)  /* Data bit 8 mask. */
#define DAC_DATA_8_bp  14  /* Data bit 8 position. */
#define DAC_DATA_9_bm  (1<<15)  /* Data bit 9 mask. */
#define DAC_DATA_9_bp  15  /* Data bit 9 position. */

/* DAC.TEST  bit masks and bit positions */
#define DAC_FEEDBACK_bm  0x01  /* Feedback bit mask. */
#define DAC_FEEDBACK_bp  0  /* Feedback bit position. */
#define DAC_PUMPOUT_bm  0x02  /* Pumpout bit mask. */
#define DAC_PUMPOUT_bp  1  /* Pumpout bit position. */
#define DAC_PUMPDIS_bm  0x04  /* Pump disable bit mask. */
#define DAC_PUMPDIS_bp  2  /* Pump disable bit position. */


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

/* EVSYS.SWEVENTB  bit masks and bit positions */
#define EVSYS_SWEVENTB_gm  0x03  /* Software event on channel select group mask. */
#define EVSYS_SWEVENTB_gp  0  /* Software event on channel select group position. */
#define EVSYS_SWEVENTB_0_bm  (1<<0)  /* Software event on channel select bit 0 mask. */
#define EVSYS_SWEVENTB_0_bp  0  /* Software event on channel select bit 0 position. */
#define EVSYS_SWEVENTB_1_bm  (1<<1)  /* Software event on channel select bit 1 mask. */
#define EVSYS_SWEVENTB_1_bp  1  /* Software event on channel select bit 1 position. */

/* EVSYS.CHANNEL0  bit masks and bit positions */
#define EVSYS_CHANNEL0_gm  0xFF  /* Channel 0 generator select group mask. */
#define EVSYS_CHANNEL0_gp  0  /* Channel 0 generator select group position. */
#define EVSYS_CHANNEL0_0_bm  (1<<0)  /* Channel 0 generator select bit 0 mask. */
#define EVSYS_CHANNEL0_0_bp  0  /* Channel 0 generator select bit 0 position. */
#define EVSYS_CHANNEL0_1_bm  (1<<1)  /* Channel 0 generator select bit 1 mask. */
#define EVSYS_CHANNEL0_1_bp  1  /* Channel 0 generator select bit 1 position. */
#define EVSYS_CHANNEL0_2_bm  (1<<2)  /* Channel 0 generator select bit 2 mask. */
#define EVSYS_CHANNEL0_2_bp  2  /* Channel 0 generator select bit 2 position. */
#define EVSYS_CHANNEL0_3_bm  (1<<3)  /* Channel 0 generator select bit 3 mask. */
#define EVSYS_CHANNEL0_3_bp  3  /* Channel 0 generator select bit 3 position. */
#define EVSYS_CHANNEL0_4_bm  (1<<4)  /* Channel 0 generator select bit 4 mask. */
#define EVSYS_CHANNEL0_4_bp  4  /* Channel 0 generator select bit 4 position. */
#define EVSYS_CHANNEL0_5_bm  (1<<5)  /* Channel 0 generator select bit 5 mask. */
#define EVSYS_CHANNEL0_5_bp  5  /* Channel 0 generator select bit 5 position. */
#define EVSYS_CHANNEL0_6_bm  (1<<6)  /* Channel 0 generator select bit 6 mask. */
#define EVSYS_CHANNEL0_6_bp  6  /* Channel 0 generator select bit 6 position. */
#define EVSYS_CHANNEL0_7_bm  (1<<7)  /* Channel 0 generator select bit 7 mask. */
#define EVSYS_CHANNEL0_7_bp  7  /* Channel 0 generator select bit 7 position. */

/* EVSYS.CHANNEL1  bit masks and bit positions */
#define EVSYS_CHANNEL1_gm  0xFF  /* Channel 1 generator select group mask. */
#define EVSYS_CHANNEL1_gp  0  /* Channel 1 generator select group position. */
#define EVSYS_CHANNEL1_0_bm  (1<<0)  /* Channel 1 generator select bit 0 mask. */
#define EVSYS_CHANNEL1_0_bp  0  /* Channel 1 generator select bit 0 position. */
#define EVSYS_CHANNEL1_1_bm  (1<<1)  /* Channel 1 generator select bit 1 mask. */
#define EVSYS_CHANNEL1_1_bp  1  /* Channel 1 generator select bit 1 position. */
#define EVSYS_CHANNEL1_2_bm  (1<<2)  /* Channel 1 generator select bit 2 mask. */
#define EVSYS_CHANNEL1_2_bp  2  /* Channel 1 generator select bit 2 position. */
#define EVSYS_CHANNEL1_3_bm  (1<<3)  /* Channel 1 generator select bit 3 mask. */
#define EVSYS_CHANNEL1_3_bp  3  /* Channel 1 generator select bit 3 position. */
#define EVSYS_CHANNEL1_4_bm  (1<<4)  /* Channel 1 generator select bit 4 mask. */
#define EVSYS_CHANNEL1_4_bp  4  /* Channel 1 generator select bit 4 position. */
#define EVSYS_CHANNEL1_5_bm  (1<<5)  /* Channel 1 generator select bit 5 mask. */
#define EVSYS_CHANNEL1_5_bp  5  /* Channel 1 generator select bit 5 position. */
#define EVSYS_CHANNEL1_6_bm  (1<<6)  /* Channel 1 generator select bit 6 mask. */
#define EVSYS_CHANNEL1_6_bp  6  /* Channel 1 generator select bit 6 position. */
#define EVSYS_CHANNEL1_7_bm  (1<<7)  /* Channel 1 generator select bit 7 mask. */
#define EVSYS_CHANNEL1_7_bp  7  /* Channel 1 generator select bit 7 position. */

/* EVSYS.CHANNEL2  bit masks and bit positions */
#define EVSYS_CHANNEL2_gm  0xFF  /* Channel 2 generator select group mask. */
#define EVSYS_CHANNEL2_gp  0  /* Channel 2 generator select group position. */
#define EVSYS_CHANNEL2_0_bm  (1<<0)  /* Channel 2 generator select bit 0 mask. */
#define EVSYS_CHANNEL2_0_bp  0  /* Channel 2 generator select bit 0 position. */
#define EVSYS_CHANNEL2_1_bm  (1<<1)  /* Channel 2 generator select bit 1 mask. */
#define EVSYS_CHANNEL2_1_bp  1  /* Channel 2 generator select bit 1 position. */
#define EVSYS_CHANNEL2_2_bm  (1<<2)  /* Channel 2 generator select bit 2 mask. */
#define EVSYS_CHANNEL2_2_bp  2  /* Channel 2 generator select bit 2 position. */
#define EVSYS_CHANNEL2_3_bm  (1<<3)  /* Channel 2 generator select bit 3 mask. */
#define EVSYS_CHANNEL2_3_bp  3  /* Channel 2 generator select bit 3 position. */
#define EVSYS_CHANNEL2_4_bm  (1<<4)  /* Channel 2 generator select bit 4 mask. */
#define EVSYS_CHANNEL2_4_bp  4  /* Channel 2 generator select bit 4 position. */
#define EVSYS_CHANNEL2_5_bm  (1<<5)  /* Channel 2 generator select bit 5 mask. */
#define EVSYS_CHANNEL2_5_bp  5  /* Channel 2 generator select bit 5 position. */
#define EVSYS_CHANNEL2_6_bm  (1<<6)  /* Channel 2 generator select bit 6 mask. */
#define EVSYS_CHANNEL2_6_bp  6  /* Channel 2 generator select bit 6 position. */
#define EVSYS_CHANNEL2_7_bm  (1<<7)  /* Channel 2 generator select bit 7 mask. */
#define EVSYS_CHANNEL2_7_bp  7  /* Channel 2 generator select bit 7 position. */

/* EVSYS.CHANNEL3  bit masks and bit positions */
#define EVSYS_CHANNEL3_gm  0xFF  /* Channel 3 generator select group mask. */
#define EVSYS_CHANNEL3_gp  0  /* Channel 3 generator select group position. */
#define EVSYS_CHANNEL3_0_bm  (1<<0)  /* Channel 3 generator select bit 0 mask. */
#define EVSYS_CHANNEL3_0_bp  0  /* Channel 3 generator select bit 0 position. */
#define EVSYS_CHANNEL3_1_bm  (1<<1)  /* Channel 3 generator select bit 1 mask. */
#define EVSYS_CHANNEL3_1_bp  1  /* Channel 3 generator select bit 1 position. */
#define EVSYS_CHANNEL3_2_bm  (1<<2)  /* Channel 3 generator select bit 2 mask. */
#define EVSYS_CHANNEL3_2_bp  2  /* Channel 3 generator select bit 2 position. */
#define EVSYS_CHANNEL3_3_bm  (1<<3)  /* Channel 3 generator select bit 3 mask. */
#define EVSYS_CHANNEL3_3_bp  3  /* Channel 3 generator select bit 3 position. */
#define EVSYS_CHANNEL3_4_bm  (1<<4)  /* Channel 3 generator select bit 4 mask. */
#define EVSYS_CHANNEL3_4_bp  4  /* Channel 3 generator select bit 4 position. */
#define EVSYS_CHANNEL3_5_bm  (1<<5)  /* Channel 3 generator select bit 5 mask. */
#define EVSYS_CHANNEL3_5_bp  5  /* Channel 3 generator select bit 5 position. */
#define EVSYS_CHANNEL3_6_bm  (1<<6)  /* Channel 3 generator select bit 6 mask. */
#define EVSYS_CHANNEL3_6_bp  6  /* Channel 3 generator select bit 6 position. */
#define EVSYS_CHANNEL3_7_bm  (1<<7)  /* Channel 3 generator select bit 7 mask. */
#define EVSYS_CHANNEL3_7_bp  7  /* Channel 3 generator select bit 7 position. */

/* EVSYS.CHANNEL4  bit masks and bit positions */
#define EVSYS_CHANNEL4_gm  0xFF  /* Channel 4 generator select group mask. */
#define EVSYS_CHANNEL4_gp  0  /* Channel 4 generator select group position. */
#define EVSYS_CHANNEL4_0_bm  (1<<0)  /* Channel 4 generator select bit 0 mask. */
#define EVSYS_CHANNEL4_0_bp  0  /* Channel 4 generator select bit 0 position. */
#define EVSYS_CHANNEL4_1_bm  (1<<1)  /* Channel 4 generator select bit 1 mask. */
#define EVSYS_CHANNEL4_1_bp  1  /* Channel 4 generator select bit 1 position. */
#define EVSYS_CHANNEL4_2_bm  (1<<2)  /* Channel 4 generator select bit 2 mask. */
#define EVSYS_CHANNEL4_2_bp  2  /* Channel 4 generator select bit 2 position. */
#define EVSYS_CHANNEL4_3_bm  (1<<3)  /* Channel 4 generator select bit 3 mask. */
#define EVSYS_CHANNEL4_3_bp  3  /* Channel 4 generator select bit 3 position. */
#define EVSYS_CHANNEL4_4_bm  (1<<4)  /* Channel 4 generator select bit 4 mask. */
#define EVSYS_CHANNEL4_4_bp  4  /* Channel 4 generator select bit 4 position. */
#define EVSYS_CHANNEL4_5_bm  (1<<5)  /* Channel 4 generator select bit 5 mask. */
#define EVSYS_CHANNEL4_5_bp  5  /* Channel 4 generator select bit 5 position. */
#define EVSYS_CHANNEL4_6_bm  (1<<6)  /* Channel 4 generator select bit 6 mask. */
#define EVSYS_CHANNEL4_6_bp  6  /* Channel 4 generator select bit 6 position. */
#define EVSYS_CHANNEL4_7_bm  (1<<7)  /* Channel 4 generator select bit 7 mask. */
#define EVSYS_CHANNEL4_7_bp  7  /* Channel 4 generator select bit 7 position. */

/* EVSYS.CHANNEL5  bit masks and bit positions */
#define EVSYS_CHANNEL5_gm  0xFF  /* Channel 5 generator select group mask. */
#define EVSYS_CHANNEL5_gp  0  /* Channel 5 generator select group position. */
#define EVSYS_CHANNEL5_0_bm  (1<<0)  /* Channel 5 generator select bit 0 mask. */
#define EVSYS_CHANNEL5_0_bp  0  /* Channel 5 generator select bit 0 position. */
#define EVSYS_CHANNEL5_1_bm  (1<<1)  /* Channel 5 generator select bit 1 mask. */
#define EVSYS_CHANNEL5_1_bp  1  /* Channel 5 generator select bit 1 position. */
#define EVSYS_CHANNEL5_2_bm  (1<<2)  /* Channel 5 generator select bit 2 mask. */
#define EVSYS_CHANNEL5_2_bp  2  /* Channel 5 generator select bit 2 position. */
#define EVSYS_CHANNEL5_3_bm  (1<<3)  /* Channel 5 generator select bit 3 mask. */
#define EVSYS_CHANNEL5_3_bp  3  /* Channel 5 generator select bit 3 position. */
#define EVSYS_CHANNEL5_4_bm  (1<<4)  /* Channel 5 generator select bit 4 mask. */
#define EVSYS_CHANNEL5_4_bp  4  /* Channel 5 generator select bit 4 position. */
#define EVSYS_CHANNEL5_5_bm  (1<<5)  /* Channel 5 generator select bit 5 mask. */
#define EVSYS_CHANNEL5_5_bp  5  /* Channel 5 generator select bit 5 position. */
#define EVSYS_CHANNEL5_6_bm  (1<<6)  /* Channel 5 generator select bit 6 mask. */
#define EVSYS_CHANNEL5_6_bp  6  /* Channel 5 generator select bit 6 position. */
#define EVSYS_CHANNEL5_7_bm  (1<<7)  /* Channel 5 generator select bit 7 mask. */
#define EVSYS_CHANNEL5_7_bp  7  /* Channel 5 generator select bit 7 position. */

/* EVSYS.CHANNEL6  bit masks and bit positions */
#define EVSYS_CHANNEL6_gm  0xFF  /* Channel 6 generator select group mask. */
#define EVSYS_CHANNEL6_gp  0  /* Channel 6 generator select group position. */
#define EVSYS_CHANNEL6_0_bm  (1<<0)  /* Channel 6 generator select bit 0 mask. */
#define EVSYS_CHANNEL6_0_bp  0  /* Channel 6 generator select bit 0 position. */
#define EVSYS_CHANNEL6_1_bm  (1<<1)  /* Channel 6 generator select bit 1 mask. */
#define EVSYS_CHANNEL6_1_bp  1  /* Channel 6 generator select bit 1 position. */
#define EVSYS_CHANNEL6_2_bm  (1<<2)  /* Channel 6 generator select bit 2 mask. */
#define EVSYS_CHANNEL6_2_bp  2  /* Channel 6 generator select bit 2 position. */
#define EVSYS_CHANNEL6_3_bm  (1<<3)  /* Channel 6 generator select bit 3 mask. */
#define EVSYS_CHANNEL6_3_bp  3  /* Channel 6 generator select bit 3 position. */
#define EVSYS_CHANNEL6_4_bm  (1<<4)  /* Channel 6 generator select bit 4 mask. */
#define EVSYS_CHANNEL6_4_bp  4  /* Channel 6 generator select bit 4 position. */
#define EVSYS_CHANNEL6_5_bm  (1<<5)  /* Channel 6 generator select bit 5 mask. */
#define EVSYS_CHANNEL6_5_bp  5  /* Channel 6 generator select bit 5 position. */
#define EVSYS_CHANNEL6_6_bm  (1<<6)  /* Channel 6 generator select bit 6 mask. */
#define EVSYS_CHANNEL6_6_bp  6  /* Channel 6 generator select bit 6 position. */
#define EVSYS_CHANNEL6_7_bm  (1<<7)  /* Channel 6 generator select bit 7 mask. */
#define EVSYS_CHANNEL6_7_bp  7  /* Channel 6 generator select bit 7 position. */

/* EVSYS.CHANNEL7  bit masks and bit positions */
#define EVSYS_CHANNEL7_gm  0xFF  /* Channel 7 generator select group mask. */
#define EVSYS_CHANNEL7_gp  0  /* Channel 7 generator select group position. */
#define EVSYS_CHANNEL7_0_bm  (1<<0)  /* Channel 7 generator select bit 0 mask. */
#define EVSYS_CHANNEL7_0_bp  0  /* Channel 7 generator select bit 0 position. */
#define EVSYS_CHANNEL7_1_bm  (1<<1)  /* Channel 7 generator select bit 1 mask. */
#define EVSYS_CHANNEL7_1_bp  1  /* Channel 7 generator select bit 1 position. */
#define EVSYS_CHANNEL7_2_bm  (1<<2)  /* Channel 7 generator select bit 2 mask. */
#define EVSYS_CHANNEL7_2_bp  2  /* Channel 7 generator select bit 2 position. */
#define EVSYS_CHANNEL7_3_bm  (1<<3)  /* Channel 7 generator select bit 3 mask. */
#define EVSYS_CHANNEL7_3_bp  3  /* Channel 7 generator select bit 3 position. */
#define EVSYS_CHANNEL7_4_bm  (1<<4)  /* Channel 7 generator select bit 4 mask. */
#define EVSYS_CHANNEL7_4_bp  4  /* Channel 7 generator select bit 4 position. */
#define EVSYS_CHANNEL7_5_bm  (1<<5)  /* Channel 7 generator select bit 5 mask. */
#define EVSYS_CHANNEL7_5_bp  5  /* Channel 7 generator select bit 5 position. */
#define EVSYS_CHANNEL7_6_bm  (1<<6)  /* Channel 7 generator select bit 6 mask. */
#define EVSYS_CHANNEL7_6_bp  6  /* Channel 7 generator select bit 6 position. */
#define EVSYS_CHANNEL7_7_bm  (1<<7)  /* Channel 7 generator select bit 7 mask. */
#define EVSYS_CHANNEL7_7_bp  7  /* Channel 7 generator select bit 7 position. */

/* EVSYS.CHANNEL8  bit masks and bit positions */
#define EVSYS_CHANNEL8_gm  0xFF  /* Channel 8 generator select group mask. */
#define EVSYS_CHANNEL8_gp  0  /* Channel 8 generator select group position. */
#define EVSYS_CHANNEL8_0_bm  (1<<0)  /* Channel 8 generator select bit 0 mask. */
#define EVSYS_CHANNEL8_0_bp  0  /* Channel 8 generator select bit 0 position. */
#define EVSYS_CHANNEL8_1_bm  (1<<1)  /* Channel 8 generator select bit 1 mask. */
#define EVSYS_CHANNEL8_1_bp  1  /* Channel 8 generator select bit 1 position. */
#define EVSYS_CHANNEL8_2_bm  (1<<2)  /* Channel 8 generator select bit 2 mask. */
#define EVSYS_CHANNEL8_2_bp  2  /* Channel 8 generator select bit 2 position. */
#define EVSYS_CHANNEL8_3_bm  (1<<3)  /* Channel 8 generator select bit 3 mask. */
#define EVSYS_CHANNEL8_3_bp  3  /* Channel 8 generator select bit 3 position. */
#define EVSYS_CHANNEL8_4_bm  (1<<4)  /* Channel 8 generator select bit 4 mask. */
#define EVSYS_CHANNEL8_4_bp  4  /* Channel 8 generator select bit 4 position. */
#define EVSYS_CHANNEL8_5_bm  (1<<5)  /* Channel 8 generator select bit 5 mask. */
#define EVSYS_CHANNEL8_5_bp  5  /* Channel 8 generator select bit 5 position. */
#define EVSYS_CHANNEL8_6_bm  (1<<6)  /* Channel 8 generator select bit 6 mask. */
#define EVSYS_CHANNEL8_6_bp  6  /* Channel 8 generator select bit 6 position. */
#define EVSYS_CHANNEL8_7_bm  (1<<7)  /* Channel 8 generator select bit 7 mask. */
#define EVSYS_CHANNEL8_7_bp  7  /* Channel 8 generator select bit 7 position. */

/* EVSYS.CHANNEL9  bit masks and bit positions */
#define EVSYS_CHANNEL9_gm  0xFF  /* Channel 9 generator select group mask. */
#define EVSYS_CHANNEL9_gp  0  /* Channel 9 generator select group position. */
#define EVSYS_CHANNEL9_0_bm  (1<<0)  /* Channel 9 generator select bit 0 mask. */
#define EVSYS_CHANNEL9_0_bp  0  /* Channel 9 generator select bit 0 position. */
#define EVSYS_CHANNEL9_1_bm  (1<<1)  /* Channel 9 generator select bit 1 mask. */
#define EVSYS_CHANNEL9_1_bp  1  /* Channel 9 generator select bit 1 position. */
#define EVSYS_CHANNEL9_2_bm  (1<<2)  /* Channel 9 generator select bit 2 mask. */
#define EVSYS_CHANNEL9_2_bp  2  /* Channel 9 generator select bit 2 position. */
#define EVSYS_CHANNEL9_3_bm  (1<<3)  /* Channel 9 generator select bit 3 mask. */
#define EVSYS_CHANNEL9_3_bp  3  /* Channel 9 generator select bit 3 position. */
#define EVSYS_CHANNEL9_4_bm  (1<<4)  /* Channel 9 generator select bit 4 mask. */
#define EVSYS_CHANNEL9_4_bp  4  /* Channel 9 generator select bit 4 position. */
#define EVSYS_CHANNEL9_5_bm  (1<<5)  /* Channel 9 generator select bit 5 mask. */
#define EVSYS_CHANNEL9_5_bp  5  /* Channel 9 generator select bit 5 position. */
#define EVSYS_CHANNEL9_6_bm  (1<<6)  /* Channel 9 generator select bit 6 mask. */
#define EVSYS_CHANNEL9_6_bp  6  /* Channel 9 generator select bit 6 position. */
#define EVSYS_CHANNEL9_7_bm  (1<<7)  /* Channel 9 generator select bit 7 mask. */
#define EVSYS_CHANNEL9_7_bp  7  /* Channel 9 generator select bit 7 position. */

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

/* EVSYS.USERCCLLUT4A  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT4B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT5A  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT5B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERADC0START  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERPTCSTART  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTB  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTC  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTD  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTE  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTF  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTG  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERUSART0IRDA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERUSART1IRDA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERUSART2IRDA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERUSART3IRDA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERUSART4IRDA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERUSART5IRDA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCA0CNTA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCA0CNTB  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCA1CNTA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCA1CNTB  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB0CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB0COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB1CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB1COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB2CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB2COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB3CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB3COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB4CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB4COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCD0INPUTA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCD0INPUTB  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEROSCTEST  bit masks and bit positions */
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


/* NVMBIST - BIST in the NVMCTRL module */
/* NVMBIST.CTRLA  bit masks and bit positions */
#define NVMBIST_CMD_gm  0x07  /* Command group mask. */
#define NVMBIST_CMD_gp  0  /* Command group position. */
#define NVMBIST_CMD_0_bm  (1<<0)  /* Command bit 0 mask. */
#define NVMBIST_CMD_0_bp  0  /* Command bit 0 position. */
#define NVMBIST_CMD_1_bm  (1<<1)  /* Command bit 1 mask. */
#define NVMBIST_CMD_1_bp  1  /* Command bit 1 position. */
#define NVMBIST_CMD_2_bm  (1<<2)  /* Command bit 2 mask. */
#define NVMBIST_CMD_2_bp  2  /* Command bit 2 position. */
#define NVMBIST_SAF_bm  0x08  /* Stop at fault bit mask. */
#define NVMBIST_SAF_bp  3  /* Stop at fault bit position. */

/* NVMBIST.ADDRPAT  bit masks and bit positions */
#define NVMBIST_XMODE_gm  0x03  /* X address mode group mask. */
#define NVMBIST_XMODE_gp  0  /* X address mode group position. */
#define NVMBIST_XMODE_0_bm  (1<<0)  /* X address mode bit 0 mask. */
#define NVMBIST_XMODE_0_bp  0  /* X address mode bit 0 position. */
#define NVMBIST_XMODE_1_bm  (1<<1)  /* X address mode bit 1 mask. */
#define NVMBIST_XMODE_1_bp  1  /* X address mode bit 1 position. */
#define NVMBIST_YMODE_gm  0x0C  /* Y address mode group mask. */
#define NVMBIST_YMODE_gp  2  /* Y address mode group position. */
#define NVMBIST_YMODE_0_bm  (1<<2)  /* Y address mode bit 0 mask. */
#define NVMBIST_YMODE_0_bp  2  /* Y address mode bit 0 position. */
#define NVMBIST_YMODE_1_bm  (1<<3)  /* Y address mode bit 1 mask. */
#define NVMBIST_YMODE_1_bp  3  /* Y address mode bit 1 position. */
#define NVMBIST_AMODE_gm  0x70  /* Address mode group mask. */
#define NVMBIST_AMODE_gp  4  /* Address mode group position. */
#define NVMBIST_AMODE_0_bm  (1<<4)  /* Address mode bit 0 mask. */
#define NVMBIST_AMODE_0_bp  4  /* Address mode bit 0 position. */
#define NVMBIST_AMODE_1_bm  (1<<5)  /* Address mode bit 1 mask. */
#define NVMBIST_AMODE_1_bp  5  /* Address mode bit 1 position. */
#define NVMBIST_AMODE_2_bm  (1<<6)  /* Address mode bit 2 mask. */
#define NVMBIST_AMODE_2_bp  6  /* Address mode bit 2 position. */

/* NVMBIST.DATAPAT  bit masks and bit positions */
#define NVMBIST_PATTERN_gm  0x03  /* Data check pattern group mask. */
#define NVMBIST_PATTERN_gp  0  /* Data check pattern group position. */
#define NVMBIST_PATTERN_0_bm  (1<<0)  /* Data check pattern bit 0 mask. */
#define NVMBIST_PATTERN_0_bp  0  /* Data check pattern bit 0 position. */
#define NVMBIST_PATTERN_1_bm  (1<<1)  /* Data check pattern bit 1 mask. */
#define NVMBIST_PATTERN_1_bp  1  /* Data check pattern bit 1 position. */

/* NVMBIST.STATUS  bit masks and bit positions */
#define NVMBIST_STATE_gm  0x0F  /* FSM State group mask. */
#define NVMBIST_STATE_gp  0  /* FSM State group position. */
#define NVMBIST_STATE_0_bm  (1<<0)  /* FSM State bit 0 mask. */
#define NVMBIST_STATE_0_bp  0  /* FSM State bit 0 position. */
#define NVMBIST_STATE_1_bm  (1<<1)  /* FSM State bit 1 mask. */
#define NVMBIST_STATE_1_bp  1  /* FSM State bit 1 position. */
#define NVMBIST_STATE_2_bm  (1<<2)  /* FSM State bit 2 mask. */
#define NVMBIST_STATE_2_bp  2  /* FSM State bit 2 position. */
#define NVMBIST_STATE_3_bm  (1<<3)  /* FSM State bit 3 mask. */
#define NVMBIST_STATE_3_bp  3  /* FSM State bit 3 position. */

/* NVMBIST.CNT  bit masks and bit positions */
#define NVMBIST_CNT_gm  0x7FF  /* Faults counter group mask. */
#define NVMBIST_CNT_gp  0  /* Faults counter group position. */
#define NVMBIST_CNT_0_bm  (1<<0)  /* Faults counter bit 0 mask. */
#define NVMBIST_CNT_0_bp  0  /* Faults counter bit 0 position. */
#define NVMBIST_CNT_1_bm  (1<<1)  /* Faults counter bit 1 mask. */
#define NVMBIST_CNT_1_bp  1  /* Faults counter bit 1 position. */
#define NVMBIST_CNT_2_bm  (1<<2)  /* Faults counter bit 2 mask. */
#define NVMBIST_CNT_2_bp  2  /* Faults counter bit 2 position. */
#define NVMBIST_CNT_3_bm  (1<<3)  /* Faults counter bit 3 mask. */
#define NVMBIST_CNT_3_bp  3  /* Faults counter bit 3 position. */
#define NVMBIST_CNT_4_bm  (1<<4)  /* Faults counter bit 4 mask. */
#define NVMBIST_CNT_4_bp  4  /* Faults counter bit 4 position. */
#define NVMBIST_CNT_5_bm  (1<<5)  /* Faults counter bit 5 mask. */
#define NVMBIST_CNT_5_bp  5  /* Faults counter bit 5 position. */
#define NVMBIST_CNT_6_bm  (1<<6)  /* Faults counter bit 6 mask. */
#define NVMBIST_CNT_6_bp  6  /* Faults counter bit 6 position. */
#define NVMBIST_CNT_7_bm  (1<<7)  /* Faults counter bit 7 mask. */
#define NVMBIST_CNT_7_bp  7  /* Faults counter bit 7 position. */
#define NVMBIST_CNT_8_bm  (1<<8)  /* Faults counter bit 8 mask. */
#define NVMBIST_CNT_8_bp  8  /* Faults counter bit 8 position. */
#define NVMBIST_CNT_9_bm  (1<<9)  /* Faults counter bit 9 mask. */
#define NVMBIST_CNT_9_bp  9  /* Faults counter bit 9 position. */
#define NVMBIST_CNT_10_bm  (1<<10)  /* Faults counter bit 10 mask. */
#define NVMBIST_CNT_10_bp  10  /* Faults counter bit 10 position. */

/* NVMBIST.END  bit masks and bit positions */
#define NVMBIST_END_gm  0xFFFFFF  /* End group mask. */
#define NVMBIST_END_gp  0  /* End group position. */
#define NVMBIST_END_0_bm  (1<<0)  /* End bit 0 mask. */
#define NVMBIST_END_0_bp  0  /* End bit 0 position. */
#define NVMBIST_END_1_bm  (1<<1)  /* End bit 1 mask. */
#define NVMBIST_END_1_bp  1  /* End bit 1 position. */
#define NVMBIST_END_2_bm  (1<<2)  /* End bit 2 mask. */
#define NVMBIST_END_2_bp  2  /* End bit 2 position. */
#define NVMBIST_END_3_bm  (1<<3)  /* End bit 3 mask. */
#define NVMBIST_END_3_bp  3  /* End bit 3 position. */
#define NVMBIST_END_4_bm  (1<<4)  /* End bit 4 mask. */
#define NVMBIST_END_4_bp  4  /* End bit 4 position. */
#define NVMBIST_END_5_bm  (1<<5)  /* End bit 5 mask. */
#define NVMBIST_END_5_bp  5  /* End bit 5 position. */
#define NVMBIST_END_6_bm  (1<<6)  /* End bit 6 mask. */
#define NVMBIST_END_6_bp  6  /* End bit 6 position. */
#define NVMBIST_END_7_bm  (1<<7)  /* End bit 7 mask. */
#define NVMBIST_END_7_bp  7  /* End bit 7 position. */
#define NVMBIST_END_8_bm  (1<<8)  /* End bit 8 mask. */
#define NVMBIST_END_8_bp  8  /* End bit 8 position. */
#define NVMBIST_END_9_bm  (1<<9)  /* End bit 9 mask. */
#define NVMBIST_END_9_bp  9  /* End bit 9 position. */
#define NVMBIST_END_10_bm  (1<<10)  /* End bit 10 mask. */
#define NVMBIST_END_10_bp  10  /* End bit 10 position. */
#define NVMBIST_END_11_bm  (1<<11)  /* End bit 11 mask. */
#define NVMBIST_END_11_bp  11  /* End bit 11 position. */
#define NVMBIST_END_12_bm  (1<<12)  /* End bit 12 mask. */
#define NVMBIST_END_12_bp  12  /* End bit 12 position. */
#define NVMBIST_END_13_bm  (1<<13)  /* End bit 13 mask. */
#define NVMBIST_END_13_bp  13  /* End bit 13 position. */
#define NVMBIST_END_14_bm  (1<<14)  /* End bit 14 mask. */
#define NVMBIST_END_14_bp  14  /* End bit 14 position. */
#define NVMBIST_END_15_bm  (1<<15)  /* End bit 15 mask. */
#define NVMBIST_END_15_bp  15  /* End bit 15 position. */
#define NVMBIST_END_16_bm  (1<<16)  /* End bit 16 mask. */
#define NVMBIST_END_16_bp  16  /* End bit 16 position. */
#define NVMBIST_END_17_bm  (1<<17)  /* End bit 17 mask. */
#define NVMBIST_END_17_bp  17  /* End bit 17 position. */
#define NVMBIST_END_18_bm  (1<<18)  /* End bit 18 mask. */
#define NVMBIST_END_18_bp  18  /* End bit 18 position. */
#define NVMBIST_END_19_bm  (1<<19)  /* End bit 19 mask. */
#define NVMBIST_END_19_bp  19  /* End bit 19 position. */
#define NVMBIST_END_20_bm  (1<<20)  /* End bit 20 mask. */
#define NVMBIST_END_20_bp  20  /* End bit 20 position. */
#define NVMBIST_END_21_bm  (1<<21)  /* End bit 21 mask. */
#define NVMBIST_END_21_bp  21  /* End bit 21 position. */
#define NVMBIST_END_22_bm  (1<<22)  /* End bit 22 mask. */
#define NVMBIST_END_22_bp  22  /* End bit 22 position. */
#define NVMBIST_END_23_bm  (1<<23)  /* End bit 23 mask. */
#define NVMBIST_END_23_bp  23  /* End bit 23 position. */


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


/* OSCTEST - Oscillator test interface */
/* OSCTEST.CTRLA  bit masks and bit positions */
#define OSCTEST_SRCSEL_gm  0x0F  /* Sorce select group mask. */
#define OSCTEST_SRCSEL_gp  0  /* Sorce select group position. */
#define OSCTEST_SRCSEL_0_bm  (1<<0)  /* Sorce select bit 0 mask. */
#define OSCTEST_SRCSEL_0_bp  0  /* Sorce select bit 0 position. */
#define OSCTEST_SRCSEL_1_bm  (1<<1)  /* Sorce select bit 1 mask. */
#define OSCTEST_SRCSEL_1_bp  1  /* Sorce select bit 1 position. */
#define OSCTEST_SRCSEL_2_bm  (1<<2)  /* Sorce select bit 2 mask. */
#define OSCTEST_SRCSEL_2_bp  2  /* Sorce select bit 2 position. */
#define OSCTEST_SRCSEL_3_bm  (1<<3)  /* Sorce select bit 3 mask. */
#define OSCTEST_SRCSEL_3_bp  3  /* Sorce select bit 3 position. */
#define OSCTEST_PRESCSEL_gm  0x70  /* Prescaler select group mask. */
#define OSCTEST_PRESCSEL_gp  4  /* Prescaler select group position. */
#define OSCTEST_PRESCSEL_0_bm  (1<<4)  /* Prescaler select bit 0 mask. */
#define OSCTEST_PRESCSEL_0_bp  4  /* Prescaler select bit 0 position. */
#define OSCTEST_PRESCSEL_1_bm  (1<<5)  /* Prescaler select bit 1 mask. */
#define OSCTEST_PRESCSEL_1_bp  5  /* Prescaler select bit 1 position. */
#define OSCTEST_PRESCSEL_2_bm  (1<<6)  /* Prescaler select bit 2 mask. */
#define OSCTEST_PRESCSEL_2_bp  6  /* Prescaler select bit 2 position. */


/* PORT - I/O Ports */
/* PORT.INTFLAGS  bit masks and bit positions */
#define PORT_INT_gm  0xFF  /* Pin Interrupt group mask. */
#define PORT_INT_gp  0  /* Pin Interrupt group position. */
#define PORT_INT_0_bm  (1<<0)  /* Pin Interrupt bit 0 mask. */
#define PORT_INT_0_bp  0  /* Pin Interrupt bit 0 position. */
#define PORT_INT0_bm  PORT_INT_0_bm  /* This define is deprecated and should not be used */
#define PORT_INT0_bp  PORT_INT_0_bp  /* This define is deprecated and should not be used */
#define PORT_INT_1_bm  (1<<1)  /* Pin Interrupt bit 1 mask. */
#define PORT_INT_1_bp  1  /* Pin Interrupt bit 1 position. */
#define PORT_INT1_bm  PORT_INT_1_bm  /* This define is deprecated and should not be used */
#define PORT_INT1_bp  PORT_INT_1_bp  /* This define is deprecated and should not be used */
#define PORT_INT_2_bm  (1<<2)  /* Pin Interrupt bit 2 mask. */
#define PORT_INT_2_bp  2  /* Pin Interrupt bit 2 position. */
#define PORT_INT2_bm  PORT_INT_2_bm  /* This define is deprecated and should not be used */
#define PORT_INT2_bp  PORT_INT_2_bp  /* This define is deprecated and should not be used */
#define PORT_INT_3_bm  (1<<3)  /* Pin Interrupt bit 3 mask. */
#define PORT_INT_3_bp  3  /* Pin Interrupt bit 3 position. */
#define PORT_INT3_bm  PORT_INT_3_bm  /* This define is deprecated and should not be used */
#define PORT_INT3_bp  PORT_INT_3_bp  /* This define is deprecated and should not be used */
#define PORT_INT_4_bm  (1<<4)  /* Pin Interrupt bit 4 mask. */
#define PORT_INT_4_bp  4  /* Pin Interrupt bit 4 position. */
#define PORT_INT4_bm  PORT_INT_4_bm  /* This define is deprecated and should not be used */
#define PORT_INT4_bp  PORT_INT_4_bp  /* This define is deprecated and should not be used */
#define PORT_INT_5_bm  (1<<5)  /* Pin Interrupt bit 5 mask. */
#define PORT_INT_5_bp  5  /* Pin Interrupt bit 5 position. */
#define PORT_INT5_bm  PORT_INT_5_bm  /* This define is deprecated and should not be used */
#define PORT_INT5_bp  PORT_INT_5_bp  /* This define is deprecated and should not be used */
#define PORT_INT_6_bm  (1<<6)  /* Pin Interrupt bit 6 mask. */
#define PORT_INT_6_bp  6  /* Pin Interrupt bit 6 position. */
#define PORT_INT6_bm  PORT_INT_6_bm  /* This define is deprecated and should not be used */
#define PORT_INT6_bp  PORT_INT_6_bp  /* This define is deprecated and should not be used */
#define PORT_INT_7_bm  (1<<7)  /* Pin Interrupt bit 7 mask. */
#define PORT_INT_7_bp  7  /* Pin Interrupt bit 7 position. */
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
#define PORT_INVEN_bm  0x80  /* Inverted I/O Enable bit mask. */
#define PORT_INVEN_bp  7  /* Inverted I/O Enable bit position. */

/* PORT.PINCTRLLD  bit masks and bit positions */
#define PORT_PINCTRLLD_gm  0xFF  /* Pin control load mask group mask. */
#define PORT_PINCTRLLD_gp  0  /* Pin control load mask group position. */
#define PORT_PINCTRLLD_0_bm  (1<<0)  /* Pin control load mask bit 0 mask. */
#define PORT_PINCTRLLD_0_bp  0  /* Pin control load mask bit 0 position. */
#define PORT_PINCTRLLD_1_bm  (1<<1)  /* Pin control load mask bit 1 mask. */
#define PORT_PINCTRLLD_1_bp  1  /* Pin control load mask bit 1 position. */
#define PORT_PINCTRLLD_2_bm  (1<<2)  /* Pin control load mask bit 2 mask. */
#define PORT_PINCTRLLD_2_bp  2  /* Pin control load mask bit 2 position. */
#define PORT_PINCTRLLD_3_bm  (1<<3)  /* Pin control load mask bit 3 mask. */
#define PORT_PINCTRLLD_3_bp  3  /* Pin control load mask bit 3 position. */
#define PORT_PINCTRLLD_4_bm  (1<<4)  /* Pin control load mask bit 4 mask. */
#define PORT_PINCTRLLD_4_bp  4  /* Pin control load mask bit 4 position. */
#define PORT_PINCTRLLD_5_bm  (1<<5)  /* Pin control load mask bit 5 mask. */
#define PORT_PINCTRLLD_5_bp  5  /* Pin control load mask bit 5 position. */
#define PORT_PINCTRLLD_6_bm  (1<<6)  /* Pin control load mask bit 6 mask. */
#define PORT_PINCTRLLD_6_bp  6  /* Pin control load mask bit 6 position. */
#define PORT_PINCTRLLD_7_bm  (1<<7)  /* Pin control load mask bit 7 mask. */
#define PORT_PINCTRLLD_7_bp  7  /* Pin control load mask bit 7 position. */

/* PORT.PINCTRLSET  bit masks and bit positions */
#define PORT_PINCTRLSET_gm  0xFF  /* Pin control set mask group mask. */
#define PORT_PINCTRLSET_gp  0  /* Pin control set mask group position. */
#define PORT_PINCTRLSET_0_bm  (1<<0)  /* Pin control set mask bit 0 mask. */
#define PORT_PINCTRLSET_0_bp  0  /* Pin control set mask bit 0 position. */
#define PORT_PINCTRLSET_1_bm  (1<<1)  /* Pin control set mask bit 1 mask. */
#define PORT_PINCTRLSET_1_bp  1  /* Pin control set mask bit 1 position. */
#define PORT_PINCTRLSET_2_bm  (1<<2)  /* Pin control set mask bit 2 mask. */
#define PORT_PINCTRLSET_2_bp  2  /* Pin control set mask bit 2 position. */
#define PORT_PINCTRLSET_3_bm  (1<<3)  /* Pin control set mask bit 3 mask. */
#define PORT_PINCTRLSET_3_bp  3  /* Pin control set mask bit 3 position. */
#define PORT_PINCTRLSET_4_bm  (1<<4)  /* Pin control set mask bit 4 mask. */
#define PORT_PINCTRLSET_4_bp  4  /* Pin control set mask bit 4 position. */
#define PORT_PINCTRLSET_5_bm  (1<<5)  /* Pin control set mask bit 5 mask. */
#define PORT_PINCTRLSET_5_bp  5  /* Pin control set mask bit 5 position. */
#define PORT_PINCTRLSET_6_bm  (1<<6)  /* Pin control set mask bit 6 mask. */
#define PORT_PINCTRLSET_6_bp  6  /* Pin control set mask bit 6 position. */
#define PORT_PINCTRLSET_7_bm  (1<<7)  /* Pin control set mask bit 7 mask. */
#define PORT_PINCTRLSET_7_bp  7  /* Pin control set mask bit 7 position. */

/* PORT.PINCTRLCLR  bit masks and bit positions */
#define PORT_PINCTRLCLR_gm  0xFF  /* Pin control clear mask group mask. */
#define PORT_PINCTRLCLR_gp  0  /* Pin control clear mask group position. */
#define PORT_PINCTRLCLR_0_bm  (1<<0)  /* Pin control clear mask bit 0 mask. */
#define PORT_PINCTRLCLR_0_bp  0  /* Pin control clear mask bit 0 position. */
#define PORT_PINCTRLCLR_1_bm  (1<<1)  /* Pin control clear mask bit 1 mask. */
#define PORT_PINCTRLCLR_1_bp  1  /* Pin control clear mask bit 1 position. */
#define PORT_PINCTRLCLR_2_bm  (1<<2)  /* Pin control clear mask bit 2 mask. */
#define PORT_PINCTRLCLR_2_bp  2  /* Pin control clear mask bit 2 position. */
#define PORT_PINCTRLCLR_3_bm  (1<<3)  /* Pin control clear mask bit 3 mask. */
#define PORT_PINCTRLCLR_3_bp  3  /* Pin control clear mask bit 3 position. */
#define PORT_PINCTRLCLR_4_bm  (1<<4)  /* Pin control clear mask bit 4 mask. */
#define PORT_PINCTRLCLR_4_bp  4  /* Pin control clear mask bit 4 position. */
#define PORT_PINCTRLCLR_5_bm  (1<<5)  /* Pin control clear mask bit 5 mask. */
#define PORT_PINCTRLCLR_5_bp  5  /* Pin control clear mask bit 5 position. */
#define PORT_PINCTRLCLR_6_bm  (1<<6)  /* Pin control clear mask bit 6 mask. */
#define PORT_PINCTRLCLR_6_bp  6  /* Pin control clear mask bit 6 position. */
#define PORT_PINCTRLCLR_7_bm  (1<<7)  /* Pin control clear mask bit 7 mask. */
#define PORT_PINCTRLCLR_7_bp  7  /* Pin control clear mask bit 7 position. */

/* PORT.PIN0CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN1CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN2CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN3CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN4CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN5CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN6CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN7CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
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
#define PORTMUX_LUT0_bm  0x01  /* LUT0 bit mask. */
#define PORTMUX_LUT0_bp  0  /* LUT0 bit position. */
#define PORTMUX_LUT1_bm  0x02  /* LUT1 bit mask. */
#define PORTMUX_LUT1_bp  1  /* LUT1 bit position. */
#define PORTMUX_LUT2_bm  0x04  /* LUT2 bit mask. */
#define PORTMUX_LUT2_bp  2  /* LUT2 bit position. */
#define PORTMUX_LUT3_bm  0x08  /* LUT3 bit mask. */
#define PORTMUX_LUT3_bp  3  /* LUT3 bit position. */
#define PORTMUX_LUT4_bm  0x10  /* LUT4 bit mask. */
#define PORTMUX_LUT4_bp  4  /* LUT4 bit position. */
#define PORTMUX_LUT5_bm  0x20  /* LUT5 bit mask. */
#define PORTMUX_LUT5_bp  5  /* LUT5 bit position. */

/* PORTMUX.USARTROUTEA  bit masks and bit positions */
#define PORTMUX_USART0_gm  0x03  /* USART0 group mask. */
#define PORTMUX_USART0_gp  0  /* USART0 group position. */
#define PORTMUX_USART0_0_bm  (1<<0)  /* USART0 bit 0 mask. */
#define PORTMUX_USART0_0_bp  0  /* USART0 bit 0 position. */
#define PORTMUX_USART0_1_bm  (1<<1)  /* USART0 bit 1 mask. */
#define PORTMUX_USART0_1_bp  1  /* USART0 bit 1 position. */
#define PORTMUX_USART1_gm  0x0C  /* USART1 group mask. */
#define PORTMUX_USART1_gp  2  /* USART1 group position. */
#define PORTMUX_USART1_0_bm  (1<<2)  /* USART1 bit 0 mask. */
#define PORTMUX_USART1_0_bp  2  /* USART1 bit 0 position. */
#define PORTMUX_USART1_1_bm  (1<<3)  /* USART1 bit 1 mask. */
#define PORTMUX_USART1_1_bp  3  /* USART1 bit 1 position. */
#define PORTMUX_USART2_gm  0x30  /* USART2 group mask. */
#define PORTMUX_USART2_gp  4  /* USART2 group position. */
#define PORTMUX_USART2_0_bm  (1<<4)  /* USART2 bit 0 mask. */
#define PORTMUX_USART2_0_bp  4  /* USART2 bit 0 position. */
#define PORTMUX_USART2_1_bm  (1<<5)  /* USART2 bit 1 mask. */
#define PORTMUX_USART2_1_bp  5  /* USART2 bit 1 position. */
#define PORTMUX_USART3_gm  0xC0  /* USART3 group mask. */
#define PORTMUX_USART3_gp  6  /* USART3 group position. */
#define PORTMUX_USART3_0_bm  (1<<6)  /* USART3 bit 0 mask. */
#define PORTMUX_USART3_0_bp  6  /* USART3 bit 0 position. */
#define PORTMUX_USART3_1_bm  (1<<7)  /* USART3 bit 1 mask. */
#define PORTMUX_USART3_1_bp  7  /* USART3 bit 1 position. */

/* PORTMUX.USARTROUTEB  bit masks and bit positions */
#define PORTMUX_USART4_gm  0x03  /* Port Multiplexer USART4 group mask. */
#define PORTMUX_USART4_gp  0  /* Port Multiplexer USART4 group position. */
#define PORTMUX_USART4_0_bm  (1<<0)  /* Port Multiplexer USART4 bit 0 mask. */
#define PORTMUX_USART4_0_bp  0  /* Port Multiplexer USART4 bit 0 position. */
#define PORTMUX_USART4_1_bm  (1<<1)  /* Port Multiplexer USART4 bit 1 mask. */
#define PORTMUX_USART4_1_bp  1  /* Port Multiplexer USART4 bit 1 position. */
#define PORTMUX_USART5_gm  0x0C  /* Port Multiplexer USART5 group mask. */
#define PORTMUX_USART5_gp  2  /* Port Multiplexer USART5 group position. */
#define PORTMUX_USART5_0_bm  (1<<2)  /* Port Multiplexer USART5 bit 0 mask. */
#define PORTMUX_USART5_0_bp  2  /* Port Multiplexer USART5 bit 0 position. */
#define PORTMUX_USART5_1_bm  (1<<3)  /* Port Multiplexer USART5 bit 1 mask. */
#define PORTMUX_USART5_1_bp  3  /* Port Multiplexer USART5 bit 1 position. */

/* PORTMUX.SPIROUTEA  bit masks and bit positions */
#define PORTMUX_SPI0_gm  0x03  /* SPI0 group mask. */
#define PORTMUX_SPI0_gp  0  /* SPI0 group position. */
#define PORTMUX_SPI0_0_bm  (1<<0)  /* SPI0 bit 0 mask. */
#define PORTMUX_SPI0_0_bp  0  /* SPI0 bit 0 position. */
#define PORTMUX_SPI0_1_bm  (1<<1)  /* SPI0 bit 1 mask. */
#define PORTMUX_SPI0_1_bp  1  /* SPI0 bit 1 position. */
#define PORTMUX_SPI1_gm  0x0C  /* SPI1 group mask. */
#define PORTMUX_SPI1_gp  2  /* SPI1 group position. */
#define PORTMUX_SPI1_0_bm  (1<<2)  /* SPI1 bit 0 mask. */
#define PORTMUX_SPI1_0_bp  2  /* SPI1 bit 0 position. */
#define PORTMUX_SPI1_1_bm  (1<<3)  /* SPI1 bit 1 mask. */
#define PORTMUX_SPI1_1_bp  3  /* SPI1 bit 1 position. */

/* PORTMUX.TWIROUTEA  bit masks and bit positions */
#define PORTMUX_TWI0_gm  0x03  /* Port Multiplexer TWI0 group mask. */
#define PORTMUX_TWI0_gp  0  /* Port Multiplexer TWI0 group position. */
#define PORTMUX_TWI0_0_bm  (1<<0)  /* Port Multiplexer TWI0 bit 0 mask. */
#define PORTMUX_TWI0_0_bp  0  /* Port Multiplexer TWI0 bit 0 position. */
#define PORTMUX_TWI0_1_bm  (1<<1)  /* Port Multiplexer TWI0 bit 1 mask. */
#define PORTMUX_TWI0_1_bp  1  /* Port Multiplexer TWI0 bit 1 position. */
#define PORTMUX_TWI1_gm  0x0C  /* Port Multiplexer TWI1 group mask. */
#define PORTMUX_TWI1_gp  2  /* Port Multiplexer TWI1 group position. */
#define PORTMUX_TWI1_0_bm  (1<<2)  /* Port Multiplexer TWI1 bit 0 mask. */
#define PORTMUX_TWI1_0_bp  2  /* Port Multiplexer TWI1 bit 0 position. */
#define PORTMUX_TWI1_1_bm  (1<<3)  /* Port Multiplexer TWI1 bit 1 mask. */
#define PORTMUX_TWI1_1_bp  3  /* Port Multiplexer TWI1 bit 1 position. */

/* PORTMUX.TCAROUTEA  bit masks and bit positions */
#define PORTMUX_TCA0_gm  0x07  /* TCA0 group mask. */
#define PORTMUX_TCA0_gp  0  /* TCA0 group position. */
#define PORTMUX_TCA0_0_bm  (1<<0)  /* TCA0 bit 0 mask. */
#define PORTMUX_TCA0_0_bp  0  /* TCA0 bit 0 position. */
#define PORTMUX_TCA0_1_bm  (1<<1)  /* TCA0 bit 1 mask. */
#define PORTMUX_TCA0_1_bp  1  /* TCA0 bit 1 position. */
#define PORTMUX_TCA0_2_bm  (1<<2)  /* TCA0 bit 2 mask. */
#define PORTMUX_TCA0_2_bp  2  /* TCA0 bit 2 position. */
#define PORTMUX_TCA1_gm  0x38  /* TCA1 group mask. */
#define PORTMUX_TCA1_gp  3  /* TCA1 group position. */
#define PORTMUX_TCA1_0_bm  (1<<3)  /* TCA1 bit 0 mask. */
#define PORTMUX_TCA1_0_bp  3  /* TCA1 bit 0 position. */
#define PORTMUX_TCA1_1_bm  (1<<4)  /* TCA1 bit 1 mask. */
#define PORTMUX_TCA1_1_bp  4  /* TCA1 bit 1 position. */
#define PORTMUX_TCA1_2_bm  (1<<5)  /* TCA1 bit 2 mask. */
#define PORTMUX_TCA1_2_bp  5  /* TCA1 bit 2 position. */

/* PORTMUX.TCBROUTEA  bit masks and bit positions */
#define PORTMUX_TCB0_bm  0x01  /* TCB0 bit mask. */
#define PORTMUX_TCB0_bp  0  /* TCB0 bit position. */
#define PORTMUX_TCB1_bm  0x02  /* TCB1 bit mask. */
#define PORTMUX_TCB1_bp  1  /* TCB1 bit position. */
#define PORTMUX_TCB2_bm  0x04  /* TCB2 bit mask. */
#define PORTMUX_TCB2_bp  2  /* TCB2 bit position. */
#define PORTMUX_TCB3_bm  0x08  /* TCB3 bit mask. */
#define PORTMUX_TCB3_bp  3  /* TCB3 bit position. */
#define PORTMUX_TCB4_bm  0x10  /* TCB4 bit mask. */
#define PORTMUX_TCB4_bp  4  /* TCB4 bit position. */

/* PORTMUX.TCDROUTEA  bit masks and bit positions */
#define PORTMUX_TCD0_gm  0x07  /* TCD0 group mask. */
#define PORTMUX_TCD0_gp  0  /* TCD0 group position. */
#define PORTMUX_TCD0_0_bm  (1<<0)  /* TCD0 bit 0 mask. */
#define PORTMUX_TCD0_0_bp  0  /* TCD0 bit 0 position. */
#define PORTMUX_TCD0_1_bm  (1<<1)  /* TCD0 bit 1 mask. */
#define PORTMUX_TCD0_1_bp  1  /* TCD0 bit 1 position. */
#define PORTMUX_TCD0_2_bm  (1<<2)  /* TCD0 bit 2 mask. */
#define PORTMUX_TCD0_2_bp  2  /* TCD0 bit 2 position. */

/* PORTMUX.ACROUTEA  bit masks and bit positions */
#define PORTMUX_AC0_bm  0x01  /* Analog Comparator 0 bit mask. */
#define PORTMUX_AC0_bp  0  /* Analog Comparator 0 bit position. */
#define PORTMUX_AC1_bm  0x02  /* Analog Comparator 1 bit mask. */
#define PORTMUX_AC1_bp  1  /* Analog Comparator 1 bit position. */
#define PORTMUX_AC2_bm  0x04  /* Analog Comparator 2 bit mask. */
#define PORTMUX_AC2_bp  2  /* Analog Comparator 2 bit position. */

/* PORTMUX.ZCDROUTEA  bit masks and bit positions */
#define PORTMUX_ZCD0_bm  0x01  /* Port Multiplexer ZCD0 bit mask. */
#define PORTMUX_ZCD0_bp  0  /* Port Multiplexer ZCD0 bit position. */
#define PORTMUX_ZCD1_bm  0x02  /* Port Multiplexer ZCD1 bit mask. */
#define PORTMUX_ZCD1_bp  1  /* Port Multiplexer ZCD1 bit position. */
#define PORTMUX_ZCD2_bm  0x04  /* Port Multiplexer ZCD2 bit mask. */
#define PORTMUX_ZCD2_bp  2  /* Port Multiplexer ZCD2 bit position. */

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


/* SIGROW - Signature row */
/* SIGROW.TEMPSENSE0  bit masks and bit positions */
#define SIGROW_TEMPSENSE0_gm  0xFFFF  /* Temperature Calibration 0 group mask. */
#define SIGROW_TEMPSENSE0_gp  0  /* Temperature Calibration 0 group position. */
#define SIGROW_TEMPSENSE0_0_bm  (1<<0)  /* Temperature Calibration 0 bit 0 mask. */
#define SIGROW_TEMPSENSE0_0_bp  0  /* Temperature Calibration 0 bit 0 position. */
#define SIGROW_TEMPSENSE0_1_bm  (1<<1)  /* Temperature Calibration 0 bit 1 mask. */
#define SIGROW_TEMPSENSE0_1_bp  1  /* Temperature Calibration 0 bit 1 position. */
#define SIGROW_TEMPSENSE0_2_bm  (1<<2)  /* Temperature Calibration 0 bit 2 mask. */
#define SIGROW_TEMPSENSE0_2_bp  2  /* Temperature Calibration 0 bit 2 position. */
#define SIGROW_TEMPSENSE0_3_bm  (1<<3)  /* Temperature Calibration 0 bit 3 mask. */
#define SIGROW_TEMPSENSE0_3_bp  3  /* Temperature Calibration 0 bit 3 position. */
#define SIGROW_TEMPSENSE0_4_bm  (1<<4)  /* Temperature Calibration 0 bit 4 mask. */
#define SIGROW_TEMPSENSE0_4_bp  4  /* Temperature Calibration 0 bit 4 position. */
#define SIGROW_TEMPSENSE0_5_bm  (1<<5)  /* Temperature Calibration 0 bit 5 mask. */
#define SIGROW_TEMPSENSE0_5_bp  5  /* Temperature Calibration 0 bit 5 position. */
#define SIGROW_TEMPSENSE0_6_bm  (1<<6)  /* Temperature Calibration 0 bit 6 mask. */
#define SIGROW_TEMPSENSE0_6_bp  6  /* Temperature Calibration 0 bit 6 position. */
#define SIGROW_TEMPSENSE0_7_bm  (1<<7)  /* Temperature Calibration 0 bit 7 mask. */
#define SIGROW_TEMPSENSE0_7_bp  7  /* Temperature Calibration 0 bit 7 position. */
#define SIGROW_TEMPSENSE0_8_bm  (1<<8)  /* Temperature Calibration 0 bit 8 mask. */
#define SIGROW_TEMPSENSE0_8_bp  8  /* Temperature Calibration 0 bit 8 position. */
#define SIGROW_TEMPSENSE0_9_bm  (1<<9)  /* Temperature Calibration 0 bit 9 mask. */
#define SIGROW_TEMPSENSE0_9_bp  9  /* Temperature Calibration 0 bit 9 position. */
#define SIGROW_TEMPSENSE0_10_bm  (1<<10)  /* Temperature Calibration 0 bit 10 mask. */
#define SIGROW_TEMPSENSE0_10_bp  10  /* Temperature Calibration 0 bit 10 position. */
#define SIGROW_TEMPSENSE0_11_bm  (1<<11)  /* Temperature Calibration 0 bit 11 mask. */
#define SIGROW_TEMPSENSE0_11_bp  11  /* Temperature Calibration 0 bit 11 position. */
#define SIGROW_TEMPSENSE0_12_bm  (1<<12)  /* Temperature Calibration 0 bit 12 mask. */
#define SIGROW_TEMPSENSE0_12_bp  12  /* Temperature Calibration 0 bit 12 position. */
#define SIGROW_TEMPSENSE0_13_bm  (1<<13)  /* Temperature Calibration 0 bit 13 mask. */
#define SIGROW_TEMPSENSE0_13_bp  13  /* Temperature Calibration 0 bit 13 position. */
#define SIGROW_TEMPSENSE0_14_bm  (1<<14)  /* Temperature Calibration 0 bit 14 mask. */
#define SIGROW_TEMPSENSE0_14_bp  14  /* Temperature Calibration 0 bit 14 position. */
#define SIGROW_TEMPSENSE0_15_bm  (1<<15)  /* Temperature Calibration 0 bit 15 mask. */
#define SIGROW_TEMPSENSE0_15_bp  15  /* Temperature Calibration 0 bit 15 position. */

/* SIGROW.TEMPSENSE1  bit masks and bit positions */
#define SIGROW_TEMPSENSE1_gm  0xFFFF  /* Temperature Calibration 1 group mask. */
#define SIGROW_TEMPSENSE1_gp  0  /* Temperature Calibration 1 group position. */
#define SIGROW_TEMPSENSE1_0_bm  (1<<0)  /* Temperature Calibration 1 bit 0 mask. */
#define SIGROW_TEMPSENSE1_0_bp  0  /* Temperature Calibration 1 bit 0 position. */
#define SIGROW_TEMPSENSE1_1_bm  (1<<1)  /* Temperature Calibration 1 bit 1 mask. */
#define SIGROW_TEMPSENSE1_1_bp  1  /* Temperature Calibration 1 bit 1 position. */
#define SIGROW_TEMPSENSE1_2_bm  (1<<2)  /* Temperature Calibration 1 bit 2 mask. */
#define SIGROW_TEMPSENSE1_2_bp  2  /* Temperature Calibration 1 bit 2 position. */
#define SIGROW_TEMPSENSE1_3_bm  (1<<3)  /* Temperature Calibration 1 bit 3 mask. */
#define SIGROW_TEMPSENSE1_3_bp  3  /* Temperature Calibration 1 bit 3 position. */
#define SIGROW_TEMPSENSE1_4_bm  (1<<4)  /* Temperature Calibration 1 bit 4 mask. */
#define SIGROW_TEMPSENSE1_4_bp  4  /* Temperature Calibration 1 bit 4 position. */
#define SIGROW_TEMPSENSE1_5_bm  (1<<5)  /* Temperature Calibration 1 bit 5 mask. */
#define SIGROW_TEMPSENSE1_5_bp  5  /* Temperature Calibration 1 bit 5 position. */
#define SIGROW_TEMPSENSE1_6_bm  (1<<6)  /* Temperature Calibration 1 bit 6 mask. */
#define SIGROW_TEMPSENSE1_6_bp  6  /* Temperature Calibration 1 bit 6 position. */
#define SIGROW_TEMPSENSE1_7_bm  (1<<7)  /* Temperature Calibration 1 bit 7 mask. */
#define SIGROW_TEMPSENSE1_7_bp  7  /* Temperature Calibration 1 bit 7 position. */
#define SIGROW_TEMPSENSE1_8_bm  (1<<8)  /* Temperature Calibration 1 bit 8 mask. */
#define SIGROW_TEMPSENSE1_8_bp  8  /* Temperature Calibration 1 bit 8 position. */
#define SIGROW_TEMPSENSE1_9_bm  (1<<9)  /* Temperature Calibration 1 bit 9 mask. */
#define SIGROW_TEMPSENSE1_9_bp  9  /* Temperature Calibration 1 bit 9 position. */
#define SIGROW_TEMPSENSE1_10_bm  (1<<10)  /* Temperature Calibration 1 bit 10 mask. */
#define SIGROW_TEMPSENSE1_10_bp  10  /* Temperature Calibration 1 bit 10 position. */
#define SIGROW_TEMPSENSE1_11_bm  (1<<11)  /* Temperature Calibration 1 bit 11 mask. */
#define SIGROW_TEMPSENSE1_11_bp  11  /* Temperature Calibration 1 bit 11 position. */
#define SIGROW_TEMPSENSE1_12_bm  (1<<12)  /* Temperature Calibration 1 bit 12 mask. */
#define SIGROW_TEMPSENSE1_12_bp  12  /* Temperature Calibration 1 bit 12 position. */
#define SIGROW_TEMPSENSE1_13_bm  (1<<13)  /* Temperature Calibration 1 bit 13 mask. */
#define SIGROW_TEMPSENSE1_13_bp  13  /* Temperature Calibration 1 bit 13 position. */
#define SIGROW_TEMPSENSE1_14_bm  (1<<14)  /* Temperature Calibration 1 bit 14 mask. */
#define SIGROW_TEMPSENSE1_14_bp  14  /* Temperature Calibration 1 bit 14 position. */
#define SIGROW_TEMPSENSE1_15_bm  (1<<15)  /* Temperature Calibration 1 bit 15 mask. */
#define SIGROW_TEMPSENSE1_15_bp  15  /* Temperature Calibration 1 bit 15 position. */


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


/* TCA - 16-bit Timer/Counter Type A */
/* TCA_SINGLE.CTRLA  bit masks and bit positions */
#define TCA_SINGLE_ENABLE_bm  0x01  /* Module Enable bit mask. */
#define TCA_SINGLE_ENABLE_bp  0  /* Module Enable bit position. */
#define TCA_SINGLE_CLKSEL_gm  0x0E  /* Clock Selection group mask. */
#define TCA_SINGLE_CLKSEL_gp  1  /* Clock Selection group position. */
#define TCA_SINGLE_CLKSEL_0_bm  (1<<1)  /* Clock Selection bit 0 mask. */
#define TCA_SINGLE_CLKSEL_0_bp  1  /* Clock Selection bit 0 position. */
#define TCA_SINGLE_CLKSEL_1_bm  (1<<2)  /* Clock Selection bit 1 mask. */
#define TCA_SINGLE_CLKSEL_1_bp  2  /* Clock Selection bit 1 position. */
#define TCA_SINGLE_CLKSEL_2_bm  (1<<3)  /* Clock Selection bit 2 mask. */
#define TCA_SINGLE_CLKSEL_2_bp  3  /* Clock Selection bit 2 position. */
#define TCA_SINGLE_RUNSTDBY_bm  0x80  /* Run in Standby bit mask. */
#define TCA_SINGLE_RUNSTDBY_bp  7  /* Run in Standby bit position. */

/* TCA_SINGLE.CTRLB  bit masks and bit positions */
#define TCA_SINGLE_WGMODE_gm  0x07  /* Waveform generation mode group mask. */
#define TCA_SINGLE_WGMODE_gp  0  /* Waveform generation mode group position. */
#define TCA_SINGLE_WGMODE_0_bm  (1<<0)  /* Waveform generation mode bit 0 mask. */
#define TCA_SINGLE_WGMODE_0_bp  0  /* Waveform generation mode bit 0 position. */
#define TCA_SINGLE_WGMODE_1_bm  (1<<1)  /* Waveform generation mode bit 1 mask. */
#define TCA_SINGLE_WGMODE_1_bp  1  /* Waveform generation mode bit 1 position. */
#define TCA_SINGLE_WGMODE_2_bm  (1<<2)  /* Waveform generation mode bit 2 mask. */
#define TCA_SINGLE_WGMODE_2_bp  2  /* Waveform generation mode bit 2 position. */
#define TCA_SINGLE_ALUPD_bm  0x08  /* Auto Lock Update bit mask. */
#define TCA_SINGLE_ALUPD_bp  3  /* Auto Lock Update bit position. */
#define TCA_SINGLE_CMP0EN_bm  0x10  /* Compare 0 Enable bit mask. */
#define TCA_SINGLE_CMP0EN_bp  4  /* Compare 0 Enable bit position. */
#define TCA_SINGLE_CMP1EN_bm  0x20  /* Compare 1 Enable bit mask. */
#define TCA_SINGLE_CMP1EN_bp  5  /* Compare 1 Enable bit position. */
#define TCA_SINGLE_CMP2EN_bm  0x40  /* Compare 2 Enable bit mask. */
#define TCA_SINGLE_CMP2EN_bp  6  /* Compare 2 Enable bit position. */

/* TCA_SINGLE.CTRLC  bit masks and bit positions */
#define TCA_SINGLE_CMP0OV_bm  0x01  /* Compare 0 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP0OV_bp  0  /* Compare 0 Waveform Output Value bit position. */
#define TCA_SINGLE_CMP1OV_bm  0x02  /* Compare 1 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP1OV_bp  1  /* Compare 1 Waveform Output Value bit position. */
#define TCA_SINGLE_CMP2OV_bm  0x04  /* Compare 2 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP2OV_bp  2  /* Compare 2 Waveform Output Value bit position. */

/* TCA_SINGLE.CTRLD  bit masks and bit positions */
#define TCA_SINGLE_SPLITM_bm  0x01  /* Split Mode Enable bit mask. */
#define TCA_SINGLE_SPLITM_bp  0  /* Split Mode Enable bit position. */

/* TCA_SINGLE.CTRLECLR  bit masks and bit positions */
#define TCA_SINGLE_DIR_bm  0x01  /* Direction bit mask. */
#define TCA_SINGLE_DIR_bp  0  /* Direction bit position. */
#define TCA_SINGLE_LUPD_bm  0x02  /* Lock Update bit mask. */
#define TCA_SINGLE_LUPD_bp  1  /* Lock Update bit position. */
#define TCA_SINGLE_CMD_gm  0x0C  /* Command group mask. */
#define TCA_SINGLE_CMD_gp  2  /* Command group position. */
#define TCA_SINGLE_CMD_0_bm  (1<<2)  /* Command bit 0 mask. */
#define TCA_SINGLE_CMD_0_bp  2  /* Command bit 0 position. */
#define TCA_SINGLE_CMD_1_bm  (1<<3)  /* Command bit 1 mask. */
#define TCA_SINGLE_CMD_1_bp  3  /* Command bit 1 position. */

/* TCA_SINGLE.CTRLESET  bit masks and bit positions */
/* TCA_SINGLE_DIR  is already defined. */
/* TCA_SINGLE_LUPD  is already defined. */
/* TCA_SINGLE_CMD  is already defined. */

/* TCA_SINGLE.CTRLFCLR  bit masks and bit positions */
#define TCA_SINGLE_PERBV_bm  0x01  /* Period Buffer Valid bit mask. */
#define TCA_SINGLE_PERBV_bp  0  /* Period Buffer Valid bit position. */
#define TCA_SINGLE_CMP0BV_bm  0x02  /* Compare 0 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP0BV_bp  1  /* Compare 0 Buffer Valid bit position. */
#define TCA_SINGLE_CMP1BV_bm  0x04  /* Compare 1 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP1BV_bp  2  /* Compare 1 Buffer Valid bit position. */
#define TCA_SINGLE_CMP2BV_bm  0x08  /* Compare 2 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP2BV_bp  3  /* Compare 2 Buffer Valid bit position. */

/* TCA_SINGLE.CTRLFSET  bit masks and bit positions */
/* TCA_SINGLE_PERBV  is already defined. */
/* TCA_SINGLE_CMP0BV  is already defined. */
/* TCA_SINGLE_CMP1BV  is already defined. */
/* TCA_SINGLE_CMP2BV  is already defined. */

/* TCA_SINGLE.EVCTRL  bit masks and bit positions */
#define TCA_SINGLE_CNTAEI_bm  0x01  /* Count on Event Input A bit mask. */
#define TCA_SINGLE_CNTAEI_bp  0  /* Count on Event Input A bit position. */
#define TCA_SINGLE_EVACTA_gm  0x0E  /* Event Action A group mask. */
#define TCA_SINGLE_EVACTA_gp  1  /* Event Action A group position. */
#define TCA_SINGLE_EVACTA_0_bm  (1<<1)  /* Event Action A bit 0 mask. */
#define TCA_SINGLE_EVACTA_0_bp  1  /* Event Action A bit 0 position. */
#define TCA_SINGLE_EVACTA_1_bm  (1<<2)  /* Event Action A bit 1 mask. */
#define TCA_SINGLE_EVACTA_1_bp  2  /* Event Action A bit 1 position. */
#define TCA_SINGLE_EVACTA_2_bm  (1<<3)  /* Event Action A bit 2 mask. */
#define TCA_SINGLE_EVACTA_2_bp  3  /* Event Action A bit 2 position. */
#define TCA_SINGLE_CNTBEI_bm  0x10  /* Count on Event Input B bit mask. */
#define TCA_SINGLE_CNTBEI_bp  4  /* Count on Event Input B bit position. */
#define TCA_SINGLE_EVACTB_gm  0xE0  /* Event Action B group mask. */
#define TCA_SINGLE_EVACTB_gp  5  /* Event Action B group position. */
#define TCA_SINGLE_EVACTB_0_bm  (1<<5)  /* Event Action B bit 0 mask. */
#define TCA_SINGLE_EVACTB_0_bp  5  /* Event Action B bit 0 position. */
#define TCA_SINGLE_EVACTB_1_bm  (1<<6)  /* Event Action B bit 1 mask. */
#define TCA_SINGLE_EVACTB_1_bp  6  /* Event Action B bit 1 position. */
#define TCA_SINGLE_EVACTB_2_bm  (1<<7)  /* Event Action B bit 2 mask. */
#define TCA_SINGLE_EVACTB_2_bp  7  /* Event Action B bit 2 position. */

/* TCA_SINGLE.INTCTRL  bit masks and bit positions */
#define TCA_SINGLE_OVF_bm  0x01  /* Overflow Interrupt bit mask. */
#define TCA_SINGLE_OVF_bp  0  /* Overflow Interrupt bit position. */
#define TCA_SINGLE_CMP0_bm  0x10  /* Compare 0 Interrupt bit mask. */
#define TCA_SINGLE_CMP0_bp  4  /* Compare 0 Interrupt bit position. */
#define TCA_SINGLE_CMP1_bm  0x20  /* Compare 1 Interrupt bit mask. */
#define TCA_SINGLE_CMP1_bp  5  /* Compare 1 Interrupt bit position. */
#define TCA_SINGLE_CMP2_bm  0x40  /* Compare 2 Interrupt bit mask. */
#define TCA_SINGLE_CMP2_bp  6  /* Compare 2 Interrupt bit position. */

/* TCA_SINGLE.INTFLAGS  bit masks and bit positions */
/* TCA_SINGLE_OVF  is already defined. */
/* TCA_SINGLE_CMP0  is already defined. */
/* TCA_SINGLE_CMP1  is already defined. */
/* TCA_SINGLE_CMP2  is already defined. */

/* TCA_SINGLE.DBGCTRL  bit masks and bit positions */
#define TCA_SINGLE_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCA_SINGLE_DBGRUN_bp  0  /* Debug Run bit position. */

/* TCA_SPLIT.CTRLA  bit masks and bit positions */
#define TCA_SPLIT_ENABLE_bm  0x01  /* Module Enable bit mask. */
#define TCA_SPLIT_ENABLE_bp  0  /* Module Enable bit position. */
#define TCA_SPLIT_CLKSEL_gm  0x0E  /* Clock Selection group mask. */
#define TCA_SPLIT_CLKSEL_gp  1  /* Clock Selection group position. */
#define TCA_SPLIT_CLKSEL_0_bm  (1<<1)  /* Clock Selection bit 0 mask. */
#define TCA_SPLIT_CLKSEL_0_bp  1  /* Clock Selection bit 0 position. */
#define TCA_SPLIT_CLKSEL_1_bm  (1<<2)  /* Clock Selection bit 1 mask. */
#define TCA_SPLIT_CLKSEL_1_bp  2  /* Clock Selection bit 1 position. */
#define TCA_SPLIT_CLKSEL_2_bm  (1<<3)  /* Clock Selection bit 2 mask. */
#define TCA_SPLIT_CLKSEL_2_bp  3  /* Clock Selection bit 2 position. */
#define TCA_SPLIT_RUNSTDBY_bm  0x80  /* Run in Standby bit mask. */
#define TCA_SPLIT_RUNSTDBY_bp  7  /* Run in Standby bit position. */

/* TCA_SPLIT.CTRLB  bit masks and bit positions */
#define TCA_SPLIT_LCMP0EN_bm  0x01  /* Low Compare 0 Enable bit mask. */
#define TCA_SPLIT_LCMP0EN_bp  0  /* Low Compare 0 Enable bit position. */
#define TCA_SPLIT_LCMP1EN_bm  0x02  /* Low Compare 1 Enable bit mask. */
#define TCA_SPLIT_LCMP1EN_bp  1  /* Low Compare 1 Enable bit position. */
#define TCA_SPLIT_LCMP2EN_bm  0x04  /* Low Compare 2 Enable bit mask. */
#define TCA_SPLIT_LCMP2EN_bp  2  /* Low Compare 2 Enable bit position. */
#define TCA_SPLIT_HCMP0EN_bm  0x10  /* High Compare 0 Enable bit mask. */
#define TCA_SPLIT_HCMP0EN_bp  4  /* High Compare 0 Enable bit position. */
#define TCA_SPLIT_HCMP1EN_bm  0x20  /* High Compare 1 Enable bit mask. */
#define TCA_SPLIT_HCMP1EN_bp  5  /* High Compare 1 Enable bit position. */
#define TCA_SPLIT_HCMP2EN_bm  0x40  /* High Compare 2 Enable bit mask. */
#define TCA_SPLIT_HCMP2EN_bp  6  /* High Compare 2 Enable bit position. */

/* TCA_SPLIT.CTRLC  bit masks and bit positions */
#define TCA_SPLIT_LCMP0OV_bm  0x01  /* Low Compare 0 Output Value bit mask. */
#define TCA_SPLIT_LCMP0OV_bp  0  /* Low Compare 0 Output Value bit position. */
#define TCA_SPLIT_LCMP1OV_bm  0x02  /* Low Compare 1 Output Value bit mask. */
#define TCA_SPLIT_LCMP1OV_bp  1  /* Low Compare 1 Output Value bit position. */
#define TCA_SPLIT_LCMP2OV_bm  0x04  /* Low Compare 2 Output Value bit mask. */
#define TCA_SPLIT_LCMP2OV_bp  2  /* Low Compare 2 Output Value bit position. */
#define TCA_SPLIT_HCMP0OV_bm  0x10  /* High Compare 0 Output Value bit mask. */
#define TCA_SPLIT_HCMP0OV_bp  4  /* High Compare 0 Output Value bit position. */
#define TCA_SPLIT_HCMP1OV_bm  0x20  /* High Compare 1 Output Value bit mask. */
#define TCA_SPLIT_HCMP1OV_bp  5  /* High Compare 1 Output Value bit position. */
#define TCA_SPLIT_HCMP2OV_bm  0x40  /* High Compare 2 Output Value bit mask. */
#define TCA_SPLIT_HCMP2OV_bp  6  /* High Compare 2 Output Value bit position. */

/* TCA_SPLIT.CTRLD  bit masks and bit positions */
#define TCA_SPLIT_SPLITM_bm  0x01  /* Split Mode Enable bit mask. */
#define TCA_SPLIT_SPLITM_bp  0  /* Split Mode Enable bit position. */

/* TCA_SPLIT.CTRLECLR  bit masks and bit positions */
#define TCA_SPLIT_CMDEN_gm  0x03  /* Command Enable group mask. */
#define TCA_SPLIT_CMDEN_gp  0  /* Command Enable group position. */
#define TCA_SPLIT_CMDEN_0_bm  (1<<0)  /* Command Enable bit 0 mask. */
#define TCA_SPLIT_CMDEN_0_bp  0  /* Command Enable bit 0 position. */
#define TCA_SPLIT_CMDEN_1_bm  (1<<1)  /* Command Enable bit 1 mask. */
#define TCA_SPLIT_CMDEN_1_bp  1  /* Command Enable bit 1 position. */
#define TCA_SPLIT_CMD_gm  0x0C  /* Command group mask. */
#define TCA_SPLIT_CMD_gp  2  /* Command group position. */
#define TCA_SPLIT_CMD_0_bm  (1<<2)  /* Command bit 0 mask. */
#define TCA_SPLIT_CMD_0_bp  2  /* Command bit 0 position. */
#define TCA_SPLIT_CMD_1_bm  (1<<3)  /* Command bit 1 mask. */
#define TCA_SPLIT_CMD_1_bp  3  /* Command bit 1 position. */

/* TCA_SPLIT.CTRLESET  bit masks and bit positions */
/* TCA_SPLIT_CMD  is already defined. */

/* TCA_SPLIT.INTCTRL  bit masks and bit positions */
#define TCA_SPLIT_LUNF_bm  0x01  /* Low Underflow Interrupt Enable bit mask. */
#define TCA_SPLIT_LUNF_bp  0  /* Low Underflow Interrupt Enable bit position. */
#define TCA_SPLIT_HUNF_bm  0x02  /* High Underflow Interrupt Enable bit mask. */
#define TCA_SPLIT_HUNF_bp  1  /* High Underflow Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP0_bm  0x10  /* Low Compare 0 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP0_bp  4  /* Low Compare 0 Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP1_bm  0x20  /* Low Compare 1 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP1_bp  5  /* Low Compare 1 Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP2_bm  0x40  /* Low Compare 2 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP2_bp  6  /* Low Compare 2 Interrupt Enable bit position. */

/* TCA_SPLIT.INTFLAGS  bit masks and bit positions */
/* TCA_SPLIT_LUNF  is already defined. */
/* TCA_SPLIT_HUNF  is already defined. */
/* TCA_SPLIT_LCMP0  is already defined. */
/* TCA_SPLIT_LCMP1  is already defined. */
/* TCA_SPLIT_LCMP2  is already defined. */

/* TCA_SPLIT.DBGCTRL  bit masks and bit positions */
#define TCA_SPLIT_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCA_SPLIT_DBGRUN_bp  0  /* Debug Run bit position. */


/* TCB - 16-bit Timer Type B */
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


/* TCD - Timer Counter D */
/* TCD.CTRLA  bit masks and bit positions */
#define TCD_ENABLE_bm  0x01  /* Enable bit mask. */
#define TCD_ENABLE_bp  0  /* Enable bit position. */
#define TCD_SYNCPRES_gm  0x06  /* Synchronization prescaler group mask. */
#define TCD_SYNCPRES_gp  1  /* Synchronization prescaler group position. */
#define TCD_SYNCPRES_0_bm  (1<<1)  /* Synchronization prescaler bit 0 mask. */
#define TCD_SYNCPRES_0_bp  1  /* Synchronization prescaler bit 0 position. */
#define TCD_SYNCPRES_1_bm  (1<<2)  /* Synchronization prescaler bit 1 mask. */
#define TCD_SYNCPRES_1_bp  2  /* Synchronization prescaler bit 1 position. */
#define TCD_CNTPRES_gm  0x18  /* counter prescaler group mask. */
#define TCD_CNTPRES_gp  3  /* counter prescaler group position. */
#define TCD_CNTPRES_0_bm  (1<<3)  /* counter prescaler bit 0 mask. */
#define TCD_CNTPRES_0_bp  3  /* counter prescaler bit 0 position. */
#define TCD_CNTPRES_1_bm  (1<<4)  /* counter prescaler bit 1 mask. */
#define TCD_CNTPRES_1_bp  4  /* counter prescaler bit 1 position. */
#define TCD_CLKSEL_gm  0x60  /* clock select group mask. */
#define TCD_CLKSEL_gp  5  /* clock select group position. */
#define TCD_CLKSEL_0_bm  (1<<5)  /* clock select bit 0 mask. */
#define TCD_CLKSEL_0_bp  5  /* clock select bit 0 position. */
#define TCD_CLKSEL_1_bm  (1<<6)  /* clock select bit 1 mask. */
#define TCD_CLKSEL_1_bp  6  /* clock select bit 1 position. */

/* TCD.CTRLB  bit masks and bit positions */
#define TCD_WGMODE_gm  0x03  /* Waveform generation mode group mask. */
#define TCD_WGMODE_gp  0  /* Waveform generation mode group position. */
#define TCD_WGMODE_0_bm  (1<<0)  /* Waveform generation mode bit 0 mask. */
#define TCD_WGMODE_0_bp  0  /* Waveform generation mode bit 0 position. */
#define TCD_WGMODE_1_bm  (1<<1)  /* Waveform generation mode bit 1 mask. */
#define TCD_WGMODE_1_bp  1  /* Waveform generation mode bit 1 position. */

/* TCD.CTRLC  bit masks and bit positions */
#define TCD_CMPOVR_bm  0x01  /* Compare output value override bit mask. */
#define TCD_CMPOVR_bp  0  /* Compare output value override bit position. */
#define TCD_AUPDATE_bm  0x02  /* Auto update bit mask. */
#define TCD_AUPDATE_bp  1  /* Auto update bit position. */
#define TCD_FIFTY_bm  0x08  /* Fifty percent waveform bit mask. */
#define TCD_FIFTY_bp  3  /* Fifty percent waveform bit position. */
#define TCD_CMPCSEL_bm  0x40  /* Compare C output select bit mask. */
#define TCD_CMPCSEL_bp  6  /* Compare C output select bit position. */
#define TCD_CMPDSEL_bm  0x80  /* Compare D output select bit mask. */
#define TCD_CMPDSEL_bp  7  /* Compare D output select bit position. */

/* TCD.CTRLD  bit masks and bit positions */
#define TCD_CMPAVAL_gm  0x0F  /* Compare A value group mask. */
#define TCD_CMPAVAL_gp  0  /* Compare A value group position. */
#define TCD_CMPAVAL_0_bm  (1<<0)  /* Compare A value bit 0 mask. */
#define TCD_CMPAVAL_0_bp  0  /* Compare A value bit 0 position. */
#define TCD_CMPAVAL_1_bm  (1<<1)  /* Compare A value bit 1 mask. */
#define TCD_CMPAVAL_1_bp  1  /* Compare A value bit 1 position. */
#define TCD_CMPAVAL_2_bm  (1<<2)  /* Compare A value bit 2 mask. */
#define TCD_CMPAVAL_2_bp  2  /* Compare A value bit 2 position. */
#define TCD_CMPAVAL_3_bm  (1<<3)  /* Compare A value bit 3 mask. */
#define TCD_CMPAVAL_3_bp  3  /* Compare A value bit 3 position. */
#define TCD_CMPBVAL_gm  0xF0  /* Compare B value group mask. */
#define TCD_CMPBVAL_gp  4  /* Compare B value group position. */
#define TCD_CMPBVAL_0_bm  (1<<4)  /* Compare B value bit 0 mask. */
#define TCD_CMPBVAL_0_bp  4  /* Compare B value bit 0 position. */
#define TCD_CMPBVAL_1_bm  (1<<5)  /* Compare B value bit 1 mask. */
#define TCD_CMPBVAL_1_bp  5  /* Compare B value bit 1 position. */
#define TCD_CMPBVAL_2_bm  (1<<6)  /* Compare B value bit 2 mask. */
#define TCD_CMPBVAL_2_bp  6  /* Compare B value bit 2 position. */
#define TCD_CMPBVAL_3_bm  (1<<7)  /* Compare B value bit 3 mask. */
#define TCD_CMPBVAL_3_bp  7  /* Compare B value bit 3 position. */

/* TCD.CTRLE  bit masks and bit positions */
#define TCD_SYNCEOC_bm  0x01  /* synchronize end of cycle strobe bit mask. */
#define TCD_SYNCEOC_bp  0  /* synchronize end of cycle strobe bit position. */
#define TCD_SYNC_bm  0x02  /* synchronize strobe bit mask. */
#define TCD_SYNC_bp  1  /* synchronize strobe bit position. */
#define TCD_RESTART_bm  0x04  /* Restart strobe bit mask. */
#define TCD_RESTART_bp  2  /* Restart strobe bit position. */
#define TCD_SCAPTUREA_bm  0x08  /* Software Capture A Strobe bit mask. */
#define TCD_SCAPTUREA_bp  3  /* Software Capture A Strobe bit position. */
#define TCD_SCAPTUREB_bm  0x10  /* Software Capture B Strobe bit mask. */
#define TCD_SCAPTUREB_bp  4  /* Software Capture B Strobe bit position. */
#define TCD_DISEOC_bm  0x80  /* Disable at end of cycle bit mask. */
#define TCD_DISEOC_bp  7  /* Disable at end of cycle bit position. */

/* TCD.EVCTRLA  bit masks and bit positions */
#define TCD_TRIGEI_bm  0x01  /* Trigger event enable bit mask. */
#define TCD_TRIGEI_bp  0  /* Trigger event enable bit position. */
#define TCD_ACTION_bm  0x04  /* event action bit mask. */
#define TCD_ACTION_bp  2  /* event action bit position. */
#define TCD_EDGE_bm  0x10  /* edge select bit mask. */
#define TCD_EDGE_bp  4  /* edge select bit position. */
#define TCD_CFG_gm  0xC0  /* event config group mask. */
#define TCD_CFG_gp  6  /* event config group position. */
#define TCD_CFG_0_bm  (1<<6)  /* event config bit 0 mask. */
#define TCD_CFG_0_bp  6  /* event config bit 0 position. */
#define TCD_CFG_1_bm  (1<<7)  /* event config bit 1 mask. */
#define TCD_CFG_1_bp  7  /* event config bit 1 position. */

/* TCD.EVCTRLB  bit masks and bit positions */
/* TCD_TRIGEI  is already defined. */
/* TCD_ACTION  is already defined. */
/* TCD_EDGE  is already defined. */
/* TCD_CFG  is already defined. */

/* TCD.INTCTRL  bit masks and bit positions */
#define TCD_OVF_bm  0x01  /* Overflow interrupt enable bit mask. */
#define TCD_OVF_bp  0  /* Overflow interrupt enable bit position. */
#define TCD_TRIGA_bm  0x04  /* Trigger A interrupt enable bit mask. */
#define TCD_TRIGA_bp  2  /* Trigger A interrupt enable bit position. */
#define TCD_TRIGB_bm  0x08  /* Trigger B interrupt enable bit mask. */
#define TCD_TRIGB_bp  3  /* Trigger B interrupt enable bit position. */

/* TCD.INTFLAGS  bit masks and bit positions */
/* TCD_OVF  is already defined. */
/* TCD_TRIGA  is already defined. */
/* TCD_TRIGB  is already defined. */

/* TCD.STATUS  bit masks and bit positions */
#define TCD_ENRDY_bm  0x01  /* Enable ready bit mask. */
#define TCD_ENRDY_bp  0  /* Enable ready bit position. */
#define TCD_CMDRDY_bm  0x02  /* Command ready bit mask. */
#define TCD_CMDRDY_bp  1  /* Command ready bit position. */
#define TCD_PWMACTA_bm  0x40  /* PWM activity on A bit mask. */
#define TCD_PWMACTA_bp  6  /* PWM activity on A bit position. */
#define TCD_PWMACTB_bm  0x80  /* PWM activity on B bit mask. */
#define TCD_PWMACTB_bp  7  /* PWM activity on B bit position. */

/* TCD.INPUTCTRLA  bit masks and bit positions */
#define TCD_INPUTMODE_gm  0x0F  /* Input mode group mask. */
#define TCD_INPUTMODE_gp  0  /* Input mode group position. */
#define TCD_INPUTMODE_0_bm  (1<<0)  /* Input mode bit 0 mask. */
#define TCD_INPUTMODE_0_bp  0  /* Input mode bit 0 position. */
#define TCD_INPUTMODE_1_bm  (1<<1)  /* Input mode bit 1 mask. */
#define TCD_INPUTMODE_1_bp  1  /* Input mode bit 1 position. */
#define TCD_INPUTMODE_2_bm  (1<<2)  /* Input mode bit 2 mask. */
#define TCD_INPUTMODE_2_bp  2  /* Input mode bit 2 position. */
#define TCD_INPUTMODE_3_bm  (1<<3)  /* Input mode bit 3 mask. */
#define TCD_INPUTMODE_3_bp  3  /* Input mode bit 3 position. */

/* TCD.INPUTCTRLB  bit masks and bit positions */
/* TCD_INPUTMODE  is already defined. */

/* TCD.FAULTCTRL  bit masks and bit positions */
#define TCD_CMPA_bm  0x01  /* Compare A value bit mask. */
#define TCD_CMPA_bp  0  /* Compare A value bit position. */
#define TCD_CMPB_bm  0x02  /* Compare B value bit mask. */
#define TCD_CMPB_bp  1  /* Compare B value bit position. */
#define TCD_CMPC_bm  0x04  /* Compare C value bit mask. */
#define TCD_CMPC_bp  2  /* Compare C value bit position. */
#define TCD_CMPD_bm  0x08  /* Compare D vaule bit mask. */
#define TCD_CMPD_bp  3  /* Compare D vaule bit position. */
#define TCD_CMPAEN_bm  0x10  /* Compare A enable bit mask. */
#define TCD_CMPAEN_bp  4  /* Compare A enable bit position. */
#define TCD_CMPBEN_bm  0x20  /* Compare B enable bit mask. */
#define TCD_CMPBEN_bp  5  /* Compare B enable bit position. */
#define TCD_CMPCEN_bm  0x40  /* Compare C enable bit mask. */
#define TCD_CMPCEN_bp  6  /* Compare C enable bit position. */
#define TCD_CMPDEN_bm  0x80  /* Compare D enable bit mask. */
#define TCD_CMPDEN_bp  7  /* Compare D enable bit position. */

/* TCD.DLYCTRL  bit masks and bit positions */
#define TCD_DLYSEL_gm  0x03  /* Delay select group mask. */
#define TCD_DLYSEL_gp  0  /* Delay select group position. */
#define TCD_DLYSEL_0_bm  (1<<0)  /* Delay select bit 0 mask. */
#define TCD_DLYSEL_0_bp  0  /* Delay select bit 0 position. */
#define TCD_DLYSEL_1_bm  (1<<1)  /* Delay select bit 1 mask. */
#define TCD_DLYSEL_1_bp  1  /* Delay select bit 1 position. */
#define TCD_DLYTRIG_gm  0x0C  /* Delay trigger group mask. */
#define TCD_DLYTRIG_gp  2  /* Delay trigger group position. */
#define TCD_DLYTRIG_0_bm  (1<<2)  /* Delay trigger bit 0 mask. */
#define TCD_DLYTRIG_0_bp  2  /* Delay trigger bit 0 position. */
#define TCD_DLYTRIG_1_bm  (1<<3)  /* Delay trigger bit 1 mask. */
#define TCD_DLYTRIG_1_bp  3  /* Delay trigger bit 1 position. */
#define TCD_DLYPRESC_gm  0x30  /* Delay prescaler group mask. */
#define TCD_DLYPRESC_gp  4  /* Delay prescaler group position. */
#define TCD_DLYPRESC_0_bm  (1<<4)  /* Delay prescaler bit 0 mask. */
#define TCD_DLYPRESC_0_bp  4  /* Delay prescaler bit 0 position. */
#define TCD_DLYPRESC_1_bm  (1<<5)  /* Delay prescaler bit 1 mask. */
#define TCD_DLYPRESC_1_bp  5  /* Delay prescaler bit 1 position. */

/* TCD.DLYVAL  bit masks and bit positions */
#define TCD_DLYVAL_gm  0xFF  /* Delay value group mask. */
#define TCD_DLYVAL_gp  0  /* Delay value group position. */
#define TCD_DLYVAL_0_bm  (1<<0)  /* Delay value bit 0 mask. */
#define TCD_DLYVAL_0_bp  0  /* Delay value bit 0 position. */
#define TCD_DLYVAL_1_bm  (1<<1)  /* Delay value bit 1 mask. */
#define TCD_DLYVAL_1_bp  1  /* Delay value bit 1 position. */
#define TCD_DLYVAL_2_bm  (1<<2)  /* Delay value bit 2 mask. */
#define TCD_DLYVAL_2_bp  2  /* Delay value bit 2 position. */
#define TCD_DLYVAL_3_bm  (1<<3)  /* Delay value bit 3 mask. */
#define TCD_DLYVAL_3_bp  3  /* Delay value bit 3 position. */
#define TCD_DLYVAL_4_bm  (1<<4)  /* Delay value bit 4 mask. */
#define TCD_DLYVAL_4_bp  4  /* Delay value bit 4 position. */
#define TCD_DLYVAL_5_bm  (1<<5)  /* Delay value bit 5 mask. */
#define TCD_DLYVAL_5_bp  5  /* Delay value bit 5 position. */
#define TCD_DLYVAL_6_bm  (1<<6)  /* Delay value bit 6 mask. */
#define TCD_DLYVAL_6_bp  6  /* Delay value bit 6 position. */
#define TCD_DLYVAL_7_bm  (1<<7)  /* Delay value bit 7 mask. */
#define TCD_DLYVAL_7_bp  7  /* Delay value bit 7 position. */

/* TCD.DITCTRL  bit masks and bit positions */
#define TCD_DITHERSEL_gm  0x03  /* dither select group mask. */
#define TCD_DITHERSEL_gp  0  /* dither select group position. */
#define TCD_DITHERSEL_0_bm  (1<<0)  /* dither select bit 0 mask. */
#define TCD_DITHERSEL_0_bp  0  /* dither select bit 0 position. */
#define TCD_DITHERSEL_1_bm  (1<<1)  /* dither select bit 1 mask. */
#define TCD_DITHERSEL_1_bp  1  /* dither select bit 1 position. */

/* TCD.DITVAL  bit masks and bit positions */
#define TCD_DITHER_gm  0x0F  /* Dither value group mask. */
#define TCD_DITHER_gp  0  /* Dither value group position. */
#define TCD_DITHER_0_bm  (1<<0)  /* Dither value bit 0 mask. */
#define TCD_DITHER_0_bp  0  /* Dither value bit 0 position. */
#define TCD_DITHER_1_bm  (1<<1)  /* Dither value bit 1 mask. */
#define TCD_DITHER_1_bp  1  /* Dither value bit 1 position. */
#define TCD_DITHER_2_bm  (1<<2)  /* Dither value bit 2 mask. */
#define TCD_DITHER_2_bp  2  /* Dither value bit 2 position. */
#define TCD_DITHER_3_bm  (1<<3)  /* Dither value bit 3 mask. */
#define TCD_DITHER_3_bp  3  /* Dither value bit 3 position. */

/* TCD.DBGCTRL  bit masks and bit positions */
#define TCD_DBGRUN_bm  0x01  /* Debug run bit mask. */
#define TCD_DBGRUN_bp  0  /* Debug run bit position. */
#define TCD_FAULTDET_bm  0x04  /* Fault detection bit mask. */
#define TCD_FAULTDET_bp  2  /* Fault detection bit position. */



/* TWI - Two-Wire Interface */
/* TWI.CTRLA  bit masks and bit positions */
#define TWI_FMPEN_DEFAULT_bm  0x02  /* FM Plus Enable bit mask. */
#define TWI_FMPEN_DEFAULT_bp  1  /* FM Plus Enable bit position. */
#define TWI_FMPEN_TEST_bm  0x02  /* Fm Plus Enable bit mask. */
#define TWI_FMPEN_TEST_bp  1  /* Fm Plus Enable bit position. */
#define TWI_SCLIN_bm  0x04  /* SCL In bit mask. */
#define TWI_SCLIN_bp  2  /* SCL In bit position. */
#define TWI_SDAIN_bm  0x08  /* SDA In bit mask. */
#define TWI_SDAIN_bp  3  /* SDA In bit position. */
#define TWI_SDAHOLD_gm  0x0C  /* SDA Hold Time group mask. */
#define TWI_SDAHOLD_gp  2  /* SDA Hold Time group position. */
#define TWI_SDAHOLD_0_bm  (1<<2)  /* SDA Hold Time bit 0 mask. */
#define TWI_SDAHOLD_0_bp  2  /* SDA Hold Time bit 0 position. */
#define TWI_SDAHOLD_1_bm  (1<<3)  /* SDA Hold Time bit 1 mask. */
#define TWI_SDAHOLD_1_bp  3  /* SDA Hold Time bit 1 position. */
#define TWI_SDASETUP_bm  0x10  /* SDA Setup Time bit mask. */
#define TWI_SDASETUP_bp  4  /* SDA Setup Time bit position. */
#define TWI_SDAOUT_bm  0x10  /* SDA Out Value bit mask. */
#define TWI_SDAOUT_bp  4  /* SDA Out Value bit position. */
#define TWI_INPUTLVL_bm  0x40  /* Input Voltage Transition Level bit mask. */
#define TWI_INPUTLVL_bp  6  /* Input Voltage Transition Level bit position. */

/* TWI.DUALCTRL  bit masks and bit positions */
#define TWI_ENABLE_DEFAULT_bm  0x01  /* Dual Control Enable bit mask. */
#define TWI_ENABLE_DEFAULT_bp  0  /* Dual Control Enable bit position. */
#define TWI_ENABLE_TEST_bm  0x01  /* Dual Control Enable bit mask. */
#define TWI_ENABLE_TEST_bp  0  /* Dual Control Enable bit position. */
/* TWI_FMPEN_DEFAULT  is already defined. */
/* TWI_FMPEN_TEST  is already defined. */
/* TWI_SCLIN  is already defined. */
/* TWI_SDAIN  is already defined. */
/* TWI_SDAHOLD  is already defined. */
/* TWI_INPUTLVL  is already defined. */

/* TWI.DBGCTRL  bit masks and bit positions */
#define TWI_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TWI_DBGRUN_bp  0  /* Debug Run bit position. */
#define TWI_SCLOUT_bm  0x01  /* SCL Out Value bit mask. */
#define TWI_SCLOUT_bp  0  /* SCL Out Value bit position. */

/* TWI.MCTRLA  bit masks and bit positions */
#define TWI_ENABLE_bm  0x01  /* Enable TWI Master bit mask. */
#define TWI_ENABLE_bp  0  /* Enable TWI Master bit position. */
#define TWI_SMEN_bm  0x02  /* Smart Mode Enable bit mask. */
#define TWI_SMEN_bp  1  /* Smart Mode Enable bit position. */
#define TWI_TIMEOUT_gm  0x0C  /* Inactive Bus Timeout group mask. */
#define TWI_TIMEOUT_gp  2  /* Inactive Bus Timeout group position. */
#define TWI_TIMEOUT_0_bm  (1<<2)  /* Inactive Bus Timeout bit 0 mask. */
#define TWI_TIMEOUT_0_bp  2  /* Inactive Bus Timeout bit 0 position. */
#define TWI_TIMEOUT_1_bm  (1<<3)  /* Inactive Bus Timeout bit 1 mask. */
#define TWI_TIMEOUT_1_bp  3  /* Inactive Bus Timeout bit 1 position. */
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

/* TWI.SCTRLA  bit masks and bit positions */
/* TWI_ENABLE  is already defined. */
/* TWI_SMEN  is already defined. */
#define TWI_PMEN_bm  0x04  /* Promiscuous Mode Enable bit mask. */
#define TWI_PMEN_bp  2  /* Promiscuous Mode Enable bit position. */
#define TWI_PIEN_bm  0x20  /* Stop Interrupt Enable bit mask. */
#define TWI_PIEN_bp  5  /* Stop Interrupt Enable bit position. */
#define TWI_APIEN_bm  0x40  /* Address/Stop Interrupt Enable bit mask. */
#define TWI_APIEN_bp  6  /* Address/Stop Interrupt Enable bit position. */
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
#define TWI_AP_bm  0x01  /* Slave Address or Stop bit mask. */
#define TWI_AP_bp  0  /* Slave Address or Stop bit position. */
#define TWI_DIR_bm  0x02  /* Read/Write Direction bit mask. */
#define TWI_DIR_bp  1  /* Read/Write Direction bit position. */
/* TWI_BUSERR  is already defined. */
#define TWI_COLL_bm  0x08  /* Collision bit mask. */
#define TWI_COLL_bp  3  /* Collision bit position. */
/* TWI_RXACK  is already defined. */
/* TWI_CLKHOLD  is already defined. */
#define TWI_APIF_bm  0x40  /* Address/Stop Interrupt Flag bit mask. */
#define TWI_APIF_bp  6  /* Address/Stop Interrupt Flag bit position. */
#define TWI_DIF_bm  0x80  /* Data Interrupt Flag bit mask. */
#define TWI_DIF_bp  7  /* Data Interrupt Flag bit position. */

/* TWI.SADDRMASK  bit masks and bit positions */
#define TWI_ADDREN_bm  0x01  /* Address Enable bit mask. */
#define TWI_ADDREN_bp  0  /* Address Enable bit position. */
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

/* TWI.TEST  bit masks and bit positions */
#define TWI_TESTEN_bm  0x01  /* TWI Test Mode Enable bit mask. */
#define TWI_TESTEN_bp  0  /* TWI Test Mode Enable bit position. */


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
#define USART_RS485_gm  0x03  /* RS485 Mode internal transmitter group mask. */
#define USART_RS485_gp  0  /* RS485 Mode internal transmitter group position. */
#define USART_RS485_0_bm  (1<<0)  /* RS485 Mode internal transmitter bit 0 mask. */
#define USART_RS485_0_bp  0  /* RS485 Mode internal transmitter bit 0 position. */
#define USART_RS485_1_bm  (1<<1)  /* RS485 Mode internal transmitter bit 1 mask. */
#define USART_RS485_1_bp  1  /* RS485 Mode internal transmitter bit 1 position. */
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
#define USART_UCPHA_bm  0x02  /* SPI Master Mode, Clock Phase bit mask. */
#define USART_UCPHA_bp  1  /* SPI Master Mode, Clock Phase bit position. */
#define USART_UDORD_bm  0x04  /* SPI Master Mode, Data Order bit mask. */
#define USART_UDORD_bp  2  /* SPI Master Mode, Data Order bit position. */
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


/* USB - USB Device Controller */
/* USB.CTRLA  bit masks and bit positions */
#define USB_MAXEP_gm  0x0F  /* Maximum Endpoint Address group mask. */
#define USB_MAXEP_gp  0  /* Maximum Endpoint Address group position. */
#define USB_MAXEP_0_bm  (1<<0)  /* Maximum Endpoint Address bit 0 mask. */
#define USB_MAXEP_0_bp  0  /* Maximum Endpoint Address bit 0 position. */
#define USB_MAXEP_1_bm  (1<<1)  /* Maximum Endpoint Address bit 1 mask. */
#define USB_MAXEP_1_bp  1  /* Maximum Endpoint Address bit 1 position. */
#define USB_MAXEP_2_bm  (1<<2)  /* Maximum Endpoint Address bit 2 mask. */
#define USB_MAXEP_2_bp  2  /* Maximum Endpoint Address bit 2 position. */
#define USB_MAXEP_3_bm  (1<<3)  /* Maximum Endpoint Address bit 3 mask. */
#define USB_MAXEP_3_bp  3  /* Maximum Endpoint Address bit 3 position. */
#define USB_STFRNUM_bm  0x10  /* Store Frame Number Enable bit mask. */
#define USB_STFRNUM_bp  4  /* Store Frame Number Enable bit position. */
#define USB_FIFOEN_bm  0x20  /* Transaction Complete FIFO Enable bit mask. */
#define USB_FIFOEN_bp  5  /* Transaction Complete FIFO Enable bit position. */
#define USB_ENABLE_bm  0x80  /* USB Enable bit mask. */
#define USB_ENABLE_bp  7  /* USB Enable bit position. */

/* USB.CTRLB  bit masks and bit positions */
#define USB_ATTACH_bm  0x01  /* Attach bit mask. */
#define USB_ATTACH_bp  0  /* Attach bit position. */
#define USB_GNAK_bm  0x02  /* Respond with NAK on all Endpoints bit mask. */
#define USB_GNAK_bp  1  /* Respond with NAK on all Endpoints bit position. */
#define USB_GNAUTO_bm  0x04  /* Set GNAK Automatically after SETUP bit mask. */
#define USB_GNAUTO_bp  2  /* Set GNAK Automatically after SETUP bit position. */
#define USB_URESUME_bm  0x08  /* Send Upstream Resume bit mask. */
#define USB_URESUME_bp  3  /* Send Upstream Resume bit position. */

/* USB.BUSSTATE  bit masks and bit positions */
#define USB_BUSRST_bm  0x01  /* Bus Reset bit mask. */
#define USB_BUSRST_bp  0  /* Bus Reset bit position. */
#define USB_SUSPENDED_bm  0x02  /* Bus Suspended bit mask. */
#define USB_SUSPENDED_bp  1  /* Bus Suspended bit position. */
#define USB_DRESUME_bm  0x04  /* Downstram Resume bit mask. */
#define USB_DRESUME_bp  2  /* Downstram Resume bit position. */
/* USB_URESUME  is already defined. */
#define USB_WTRSM_bm  0x10  /* Wait Time Resume bit mask. */
#define USB_WTRSM_bp  4  /* Wait Time Resume bit position. */

/* USB.ADDR  bit masks and bit positions */
#define USB_ADDR_gm  0x7F  /* Device Address group mask. */
#define USB_ADDR_gp  0  /* Device Address group position. */
#define USB_ADDR_0_bm  (1<<0)  /* Device Address bit 0 mask. */
#define USB_ADDR_0_bp  0  /* Device Address bit 0 position. */
#define USB_ADDR_1_bm  (1<<1)  /* Device Address bit 1 mask. */
#define USB_ADDR_1_bp  1  /* Device Address bit 1 position. */
#define USB_ADDR_2_bm  (1<<2)  /* Device Address bit 2 mask. */
#define USB_ADDR_2_bp  2  /* Device Address bit 2 position. */
#define USB_ADDR_3_bm  (1<<3)  /* Device Address bit 3 mask. */
#define USB_ADDR_3_bp  3  /* Device Address bit 3 position. */
#define USB_ADDR_4_bm  (1<<4)  /* Device Address bit 4 mask. */
#define USB_ADDR_4_bp  4  /* Device Address bit 4 position. */
#define USB_ADDR_5_bm  (1<<5)  /* Device Address bit 5 mask. */
#define USB_ADDR_5_bp  5  /* Device Address bit 5 position. */
#define USB_ADDR_6_bm  (1<<6)  /* Device Address bit 6 mask. */
#define USB_ADDR_6_bp  6  /* Device Address bit 6 position. */

/* USB.FIFOWP  bit masks and bit positions */
#define USB_FIFOWP_gm  0x1F  /* FIFO Write Pointer group mask. */
#define USB_FIFOWP_gp  0  /* FIFO Write Pointer group position. */
#define USB_FIFOWP_0_bm  (1<<0)  /* FIFO Write Pointer bit 0 mask. */
#define USB_FIFOWP_0_bp  0  /* FIFO Write Pointer bit 0 position. */
#define USB_FIFOWP_1_bm  (1<<1)  /* FIFO Write Pointer bit 1 mask. */
#define USB_FIFOWP_1_bp  1  /* FIFO Write Pointer bit 1 position. */
#define USB_FIFOWP_2_bm  (1<<2)  /* FIFO Write Pointer bit 2 mask. */
#define USB_FIFOWP_2_bp  2  /* FIFO Write Pointer bit 2 position. */
#define USB_FIFOWP_3_bm  (1<<3)  /* FIFO Write Pointer bit 3 mask. */
#define USB_FIFOWP_3_bp  3  /* FIFO Write Pointer bit 3 position. */
#define USB_FIFOWP_4_bm  (1<<4)  /* FIFO Write Pointer bit 4 mask. */
#define USB_FIFOWP_4_bp  4  /* FIFO Write Pointer bit 4 position. */

/* USB.FIFORP  bit masks and bit positions */
#define USB_FIFORP_gm  0x1F  /* FIFO Read Pointer group mask. */
#define USB_FIFORP_gp  0  /* FIFO Read Pointer group position. */
#define USB_FIFORP_0_bm  (1<<0)  /* FIFO Read Pointer bit 0 mask. */
#define USB_FIFORP_0_bp  0  /* FIFO Read Pointer bit 0 position. */
#define USB_FIFORP_1_bm  (1<<1)  /* FIFO Read Pointer bit 1 mask. */
#define USB_FIFORP_1_bp  1  /* FIFO Read Pointer bit 1 position. */
#define USB_FIFORP_2_bm  (1<<2)  /* FIFO Read Pointer bit 2 mask. */
#define USB_FIFORP_2_bp  2  /* FIFO Read Pointer bit 2 position. */
#define USB_FIFORP_3_bm  (1<<3)  /* FIFO Read Pointer bit 3 mask. */
#define USB_FIFORP_3_bp  3  /* FIFO Read Pointer bit 3 position. */
#define USB_FIFORP_4_bm  (1<<4)  /* FIFO Read Pointer bit 4 mask. */
#define USB_FIFORP_4_bp  4  /* FIFO Read Pointer bit 4 position. */

/* USB.EPPTR  bit masks and bit positions */
#define USB_EPPTR_gm  0xFFFF  /* Endpoint Configuration Table Pointer group mask. */
#define USB_EPPTR_gp  0  /* Endpoint Configuration Table Pointer group position. */
#define USB_EPPTR_0_bm  (1<<0)  /* Endpoint Configuration Table Pointer bit 0 mask. */
#define USB_EPPTR_0_bp  0  /* Endpoint Configuration Table Pointer bit 0 position. */
#define USB_EPPTR_1_bm  (1<<1)  /* Endpoint Configuration Table Pointer bit 1 mask. */
#define USB_EPPTR_1_bp  1  /* Endpoint Configuration Table Pointer bit 1 position. */
#define USB_EPPTR_2_bm  (1<<2)  /* Endpoint Configuration Table Pointer bit 2 mask. */
#define USB_EPPTR_2_bp  2  /* Endpoint Configuration Table Pointer bit 2 position. */
#define USB_EPPTR_3_bm  (1<<3)  /* Endpoint Configuration Table Pointer bit 3 mask. */
#define USB_EPPTR_3_bp  3  /* Endpoint Configuration Table Pointer bit 3 position. */
#define USB_EPPTR_4_bm  (1<<4)  /* Endpoint Configuration Table Pointer bit 4 mask. */
#define USB_EPPTR_4_bp  4  /* Endpoint Configuration Table Pointer bit 4 position. */
#define USB_EPPTR_5_bm  (1<<5)  /* Endpoint Configuration Table Pointer bit 5 mask. */
#define USB_EPPTR_5_bp  5  /* Endpoint Configuration Table Pointer bit 5 position. */
#define USB_EPPTR_6_bm  (1<<6)  /* Endpoint Configuration Table Pointer bit 6 mask. */
#define USB_EPPTR_6_bp  6  /* Endpoint Configuration Table Pointer bit 6 position. */
#define USB_EPPTR_7_bm  (1<<7)  /* Endpoint Configuration Table Pointer bit 7 mask. */
#define USB_EPPTR_7_bp  7  /* Endpoint Configuration Table Pointer bit 7 position. */
#define USB_EPPTR_8_bm  (1<<8)  /* Endpoint Configuration Table Pointer bit 8 mask. */
#define USB_EPPTR_8_bp  8  /* Endpoint Configuration Table Pointer bit 8 position. */
#define USB_EPPTR_9_bm  (1<<9)  /* Endpoint Configuration Table Pointer bit 9 mask. */
#define USB_EPPTR_9_bp  9  /* Endpoint Configuration Table Pointer bit 9 position. */
#define USB_EPPTR_10_bm  (1<<10)  /* Endpoint Configuration Table Pointer bit 10 mask. */
#define USB_EPPTR_10_bp  10  /* Endpoint Configuration Table Pointer bit 10 position. */
#define USB_EPPTR_11_bm  (1<<11)  /* Endpoint Configuration Table Pointer bit 11 mask. */
#define USB_EPPTR_11_bp  11  /* Endpoint Configuration Table Pointer bit 11 position. */
#define USB_EPPTR_12_bm  (1<<12)  /* Endpoint Configuration Table Pointer bit 12 mask. */
#define USB_EPPTR_12_bp  12  /* Endpoint Configuration Table Pointer bit 12 position. */
#define USB_EPPTR_13_bm  (1<<13)  /* Endpoint Configuration Table Pointer bit 13 mask. */
#define USB_EPPTR_13_bp  13  /* Endpoint Configuration Table Pointer bit 13 position. */
#define USB_EPPTR_14_bm  (1<<14)  /* Endpoint Configuration Table Pointer bit 14 mask. */
#define USB_EPPTR_14_bp  14  /* Endpoint Configuration Table Pointer bit 14 position. */
#define USB_EPPTR_15_bm  (1<<15)  /* Endpoint Configuration Table Pointer bit 15 mask. */
#define USB_EPPTR_15_bp  15  /* Endpoint Configuration Table Pointer bit 15 position. */

/* USB.INTCTRLA  bit masks and bit positions */
#define USB_OVF_bm  0x02  /* Overflow Interrupt Enable bit mask. */
#define USB_OVF_bp  1  /* Overflow Interrupt Enable bit position. */
#define USB_UNF_bm  0x04  /* Underflow Interrupt Enable bit mask. */
#define USB_UNF_bp  2  /* Underflow Interrupt Enable bit position. */
#define USB_STALLED_bm  0x08  /* STALL Interrupt Enable bit mask. */
#define USB_STALLED_bp  3  /* STALL Interrupt Enable bit position. */
#define USB_RESET_bm  0x10  /* Reset Interrupt Enable bit mask. */
#define USB_RESET_bp  4  /* Reset Interrupt Enable bit position. */
#define USB_RESUME_bm  0x20  /* Resume Interrupt Enable bit mask. */
#define USB_RESUME_bp  5  /* Resume Interrupt Enable bit position. */
#define USB_SUSPEND_bm  0x40  /* Suspend Interrupt Enable bit mask. */
#define USB_SUSPEND_bp  6  /* Suspend Interrupt Enable bit position. */
#define USB_SOF_bm  0x80  /* Start Of Frame Interrupt Enable bit mask. */
#define USB_SOF_bp  7  /* Start Of Frame Interrupt Enable bit position. */

/* USB.INTCTRLB  bit masks and bit positions */
#define USB_SETUP_bm  0x01  /* SETUP Transaction Complete Interrupt Enable bit mask. */
#define USB_SETUP_bp  0  /* SETUP Transaction Complete Interrupt Enable bit position. */
#define USB_GNDONE_bm  0x02  /* GNAK Operation Done Interrupt Enable bit mask. */
#define USB_GNDONE_bp  1  /* GNAK Operation Done Interrupt Enable bit position. */
#define USB_TRNCOMPL_bm  0x20  /* Transaction Complete Interrupt Enable bit mask. */
#define USB_TRNCOMPL_bp  5  /* Transaction Complete Interrupt Enable bit position. */

/* USB.INTFLAGSA  bit masks and bit positions */
/* USB_OVF  is already defined. */
/* USB_UNF  is already defined. */
/* USB_STALLED  is already defined. */
/* USB_RESET  is already defined. */
/* USB_RESUME  is already defined. */
/* USB_SUSPEND  is already defined. */
/* USB_SOF  is already defined. */

/* USB.INTFLAGSB  bit masks and bit positions */
/* USB_SETUP  is already defined. */
/* USB_GNDONE  is already defined. */
#define USB_RMWBUSY_bm  0x04  /* RMW Busy Flag bit mask. */
#define USB_RMWBUSY_bp  2  /* RMW Busy Flag bit position. */
/* USB_TRNCOMPL  is already defined. */

/* USB.TESTCTRL  bit masks and bit positions */
#define USB_TESTEN_bm  0x01  /*  bit mask. */
#define USB_TESTEN_bp  0  /*  bit position. */
#define USB_XTEST_gm  0x0E  /*  group mask. */
#define USB_XTEST_gp  1  /*  group position. */
#define USB_XTEST_0_bm  (1<<1)  /* | bit 0 mask. */
#define USB_XTEST_0_bp  1  /*  bit 0 position. */
#define USB_XTEST_1_bm  (1<<2)  /* | bit 1 mask. */
#define USB_XTEST_1_bp  2  /*  bit 1 position. */
#define USB_XTEST_2_bm  (1<<3)  /* | bit 2 mask. */
#define USB_XTEST_2_bp  3  /*  bit 2 position. */
/* USB_ATTACH  is already defined. */
#define USB_HIGHRES_bm  0x20  /*  bit mask. */
#define USB_HIGHRES_bp  5  /*  bit position. */

/* USB.TESTSTATUS  bit masks and bit positions */
#define USB_DP_bm  0x01  /*  bit mask. */
#define USB_DP_bp  0  /*  bit position. */
#define USB_DM_bm  0x02  /*  bit mask. */
#define USB_DM_bp  1  /*  bit position. */
#define USB_RCV_bm  0x04  /*  bit mask. */
#define USB_RCV_bp  2  /*  bit position. */


/* USB.STATUS  bit masks and bit positions */
#define USB_TOGGLE_bm  0x01  /* Data Toggle bit mask. */
#define USB_TOGGLE_bp  0  /* Data Toggle bit position. */
#define USB_BUSNAK_bm  0x02  /* Data Buffer NAK bit mask. */
#define USB_BUSNAK_bp  1  /* Data Buffer NAK bit position. */
/* USB_STALLED  is already defined. */
#define USB_EPSETUP_bm  0x10  /* EP Setup Complete bit mask. */
#define USB_EPSETUP_bp  4  /* EP Setup Complete bit position. */
/* USB_TRNCOMPL  is already defined. */
#define USB_UNFOVF_bm  0x40  /* Underflow/Overflow EP bit mask. */
#define USB_UNFOVF_bp  6  /* Underflow/Overflow EP bit position. */
#define USB_CRC_bm  0x80  /* CRC Error bit mask. */
#define USB_CRC_bp  7  /* CRC Error bit position. */

/* USB.CTRL  bit masks and bit positions */
#define USB_BUFSIZE_DEFAULT_gm  0x03  /* Data Size default group mask. */
#define USB_BUFSIZE_DEFAULT_gp  0  /* Data Size default group position. */
#define USB_BUFSIZE_DEFAULT_0_bm  (1<<0)  /* Data Size default bit 0 mask. */
#define USB_BUFSIZE_DEFAULT_0_bp  0  /* Data Size default bit 0 position. */
#define USB_BUFSIZE_DEFAULT_1_bm  (1<<1)  /* Data Size default bit 1 mask. */
#define USB_BUFSIZE_DEFAULT_1_bp  1  /* Data Size default bit 1 position. */
#define USB_DOSTALL_bm  0x04  /* Endpoint will respond with STALL bit mask. */
#define USB_DOSTALL_bp  2  /* Endpoint will respond with STALL bit position. */
#define USB_BUFSIZE_ISO_gm  0x07  /* Data Size isochronous group mask. */
#define USB_BUFSIZE_ISO_gp  0  /* Data Size isochronous group position. */
#define USB_BUFSIZE_ISO_0_bm  (1<<0)  /* Data Size isochronous bit 0 mask. */
#define USB_BUFSIZE_ISO_0_bp  0  /* Data Size isochronous bit 0 position. */
#define USB_BUFSIZE_ISO_1_bm  (1<<1)  /* Data Size isochronous bit 1 mask. */
#define USB_BUFSIZE_ISO_1_bp  1  /* Data Size isochronous bit 1 position. */
#define USB_BUFSIZE_ISO_2_bm  (1<<2)  /* Data Size isochronous bit 2 mask. */
#define USB_BUFSIZE_ISO_2_bp  2  /* Data Size isochronous bit 2 position. */
#define USB_TCDSBL_bm  0x08  /* TRNCOMPL Interrupt Disable bit mask. */
#define USB_TCDSBL_bp  3  /* TRNCOMPL Interrupt Disable bit position. */
#define USB_AZLP_bm  0x10  /* Automatic zero length packet bit mask. */
#define USB_AZLP_bp  4  /* Automatic zero length packet bit position. */
#define USB_MULTIPKT_bm  0x20  /* Multipacket transfer enable bit mask. */
#define USB_MULTIPKT_bp  5  /* Multipacket transfer enable bit position. */
#define USB_TYPE_gm  0xC0  /* Endpoint type group mask. */
#define USB_TYPE_gp  6  /* Endpoint type group position. */
#define USB_TYPE_0_bm  (1<<6)  /* Endpoint type bit 0 mask. */
#define USB_TYPE_0_bp  6  /* Endpoint type bit 0 position. */
#define USB_TYPE_1_bm  (1<<7)  /* Endpoint type bit 1 mask. */
#define USB_TYPE_1_bp  7  /* Endpoint type bit 1 position. */

/* USB.CNT  bit masks and bit positions */
#define USB_CNT_gm  0xFFFF  /* Endpoint Byte Count group mask. */
#define USB_CNT_gp  0  /* Endpoint Byte Count group position. */
#define USB_CNT_0_bm  (1<<0)  /* Endpoint Byte Count bit 0 mask. */
#define USB_CNT_0_bp  0  /* Endpoint Byte Count bit 0 position. */
#define USB_CNT_1_bm  (1<<1)  /* Endpoint Byte Count bit 1 mask. */
#define USB_CNT_1_bp  1  /* Endpoint Byte Count bit 1 position. */
#define USB_CNT_2_bm  (1<<2)  /* Endpoint Byte Count bit 2 mask. */
#define USB_CNT_2_bp  2  /* Endpoint Byte Count bit 2 position. */
#define USB_CNT_3_bm  (1<<3)  /* Endpoint Byte Count bit 3 mask. */
#define USB_CNT_3_bp  3  /* Endpoint Byte Count bit 3 position. */
#define USB_CNT_4_bm  (1<<4)  /* Endpoint Byte Count bit 4 mask. */
#define USB_CNT_4_bp  4  /* Endpoint Byte Count bit 4 position. */
#define USB_CNT_5_bm  (1<<5)  /* Endpoint Byte Count bit 5 mask. */
#define USB_CNT_5_bp  5  /* Endpoint Byte Count bit 5 position. */
#define USB_CNT_6_bm  (1<<6)  /* Endpoint Byte Count bit 6 mask. */
#define USB_CNT_6_bp  6  /* Endpoint Byte Count bit 6 position. */
#define USB_CNT_7_bm  (1<<7)  /* Endpoint Byte Count bit 7 mask. */
#define USB_CNT_7_bp  7  /* Endpoint Byte Count bit 7 position. */
#define USB_CNT_8_bm  (1<<8)  /* Endpoint Byte Count bit 8 mask. */
#define USB_CNT_8_bp  8  /* Endpoint Byte Count bit 8 position. */
#define USB_CNT_9_bm  (1<<9)  /* Endpoint Byte Count bit 9 mask. */
#define USB_CNT_9_bp  9  /* Endpoint Byte Count bit 9 position. */
#define USB_CNT_10_bm  (1<<10)  /* Endpoint Byte Count bit 10 mask. */
#define USB_CNT_10_bp  10  /* Endpoint Byte Count bit 10 position. */
#define USB_CNT_11_bm  (1<<11)  /* Endpoint Byte Count bit 11 mask. */
#define USB_CNT_11_bp  11  /* Endpoint Byte Count bit 11 position. */
#define USB_CNT_12_bm  (1<<12)  /* Endpoint Byte Count bit 12 mask. */
#define USB_CNT_12_bp  12  /* Endpoint Byte Count bit 12 position. */
#define USB_CNT_13_bm  (1<<13)  /* Endpoint Byte Count bit 13 mask. */
#define USB_CNT_13_bp  13  /* Endpoint Byte Count bit 13 position. */
#define USB_CNT_14_bm  (1<<14)  /* Endpoint Byte Count bit 14 mask. */
#define USB_CNT_14_bp  14  /* Endpoint Byte Count bit 14 position. */
#define USB_CNT_15_bm  (1<<15)  /* Endpoint Byte Count bit 15 mask. */
#define USB_CNT_15_bp  15  /* Endpoint Byte Count bit 15 position. */

/* USB.DATAPTR  bit masks and bit positions */
#define USB_DATAPTR_gm  0xFFFF  /* Endpoint data pointer group mask. */
#define USB_DATAPTR_gp  0  /* Endpoint data pointer group position. */
#define USB_DATAPTR_0_bm  (1<<0)  /* Endpoint data pointer bit 0 mask. */
#define USB_DATAPTR_0_bp  0  /* Endpoint data pointer bit 0 position. */
#define USB_DATAPTR_1_bm  (1<<1)  /* Endpoint data pointer bit 1 mask. */
#define USB_DATAPTR_1_bp  1  /* Endpoint data pointer bit 1 position. */
#define USB_DATAPTR_2_bm  (1<<2)  /* Endpoint data pointer bit 2 mask. */
#define USB_DATAPTR_2_bp  2  /* Endpoint data pointer bit 2 position. */
#define USB_DATAPTR_3_bm  (1<<3)  /* Endpoint data pointer bit 3 mask. */
#define USB_DATAPTR_3_bp  3  /* Endpoint data pointer bit 3 position. */
#define USB_DATAPTR_4_bm  (1<<4)  /* Endpoint data pointer bit 4 mask. */
#define USB_DATAPTR_4_bp  4  /* Endpoint data pointer bit 4 position. */
#define USB_DATAPTR_5_bm  (1<<5)  /* Endpoint data pointer bit 5 mask. */
#define USB_DATAPTR_5_bp  5  /* Endpoint data pointer bit 5 position. */
#define USB_DATAPTR_6_bm  (1<<6)  /* Endpoint data pointer bit 6 mask. */
#define USB_DATAPTR_6_bp  6  /* Endpoint data pointer bit 6 position. */
#define USB_DATAPTR_7_bm  (1<<7)  /* Endpoint data pointer bit 7 mask. */
#define USB_DATAPTR_7_bp  7  /* Endpoint data pointer bit 7 position. */
#define USB_DATAPTR_8_bm  (1<<8)  /* Endpoint data pointer bit 8 mask. */
#define USB_DATAPTR_8_bp  8  /* Endpoint data pointer bit 8 position. */
#define USB_DATAPTR_9_bm  (1<<9)  /* Endpoint data pointer bit 9 mask. */
#define USB_DATAPTR_9_bp  9  /* Endpoint data pointer bit 9 position. */
#define USB_DATAPTR_10_bm  (1<<10)  /* Endpoint data pointer bit 10 mask. */
#define USB_DATAPTR_10_bp  10  /* Endpoint data pointer bit 10 position. */
#define USB_DATAPTR_11_bm  (1<<11)  /* Endpoint data pointer bit 11 mask. */
#define USB_DATAPTR_11_bp  11  /* Endpoint data pointer bit 11 position. */
#define USB_DATAPTR_12_bm  (1<<12)  /* Endpoint data pointer bit 12 mask. */
#define USB_DATAPTR_12_bp  12  /* Endpoint data pointer bit 12 position. */
#define USB_DATAPTR_13_bm  (1<<13)  /* Endpoint data pointer bit 13 mask. */
#define USB_DATAPTR_13_bp  13  /* Endpoint data pointer bit 13 position. */
#define USB_DATAPTR_14_bm  (1<<14)  /* Endpoint data pointer bit 14 mask. */
#define USB_DATAPTR_14_bp  14  /* Endpoint data pointer bit 14 position. */
#define USB_DATAPTR_15_bm  (1<<15)  /* Endpoint data pointer bit 15 mask. */
#define USB_DATAPTR_15_bp  15  /* Endpoint data pointer bit 15 position. */

/* USB.MCNT  bit masks and bit positions */
#define USB_MCNT_gm  0xFFFF  /* Multi-packet byte count group mask. */
#define USB_MCNT_gp  0  /* Multi-packet byte count group position. */
#define USB_MCNT_0_bm  (1<<0)  /* Multi-packet byte count bit 0 mask. */
#define USB_MCNT_0_bp  0  /* Multi-packet byte count bit 0 position. */
#define USB_MCNT_1_bm  (1<<1)  /* Multi-packet byte count bit 1 mask. */
#define USB_MCNT_1_bp  1  /* Multi-packet byte count bit 1 position. */
#define USB_MCNT_2_bm  (1<<2)  /* Multi-packet byte count bit 2 mask. */
#define USB_MCNT_2_bp  2  /* Multi-packet byte count bit 2 position. */
#define USB_MCNT_3_bm  (1<<3)  /* Multi-packet byte count bit 3 mask. */
#define USB_MCNT_3_bp  3  /* Multi-packet byte count bit 3 position. */
#define USB_MCNT_4_bm  (1<<4)  /* Multi-packet byte count bit 4 mask. */
#define USB_MCNT_4_bp  4  /* Multi-packet byte count bit 4 position. */
#define USB_MCNT_5_bm  (1<<5)  /* Multi-packet byte count bit 5 mask. */
#define USB_MCNT_5_bp  5  /* Multi-packet byte count bit 5 position. */
#define USB_MCNT_6_bm  (1<<6)  /* Multi-packet byte count bit 6 mask. */
#define USB_MCNT_6_bp  6  /* Multi-packet byte count bit 6 position. */
#define USB_MCNT_7_bm  (1<<7)  /* Multi-packet byte count bit 7 mask. */
#define USB_MCNT_7_bp  7  /* Multi-packet byte count bit 7 position. */
#define USB_MCNT_8_bm  (1<<8)  /* Multi-packet byte count bit 8 mask. */
#define USB_MCNT_8_bp  8  /* Multi-packet byte count bit 8 position. */
#define USB_MCNT_9_bm  (1<<9)  /* Multi-packet byte count bit 9 mask. */
#define USB_MCNT_9_bp  9  /* Multi-packet byte count bit 9 position. */
#define USB_MCNT_10_bm  (1<<10)  /* Multi-packet byte count bit 10 mask. */
#define USB_MCNT_10_bp  10  /* Multi-packet byte count bit 10 position. */
#define USB_MCNT_11_bm  (1<<11)  /* Multi-packet byte count bit 11 mask. */
#define USB_MCNT_11_bp  11  /* Multi-packet byte count bit 11 position. */
#define USB_MCNT_12_bm  (1<<12)  /* Multi-packet byte count bit 12 mask. */
#define USB_MCNT_12_bp  12  /* Multi-packet byte count bit 12 position. */
#define USB_MCNT_13_bm  (1<<13)  /* Multi-packet byte count bit 13 mask. */
#define USB_MCNT_13_bp  13  /* Multi-packet byte count bit 13 position. */
#define USB_MCNT_14_bm  (1<<14)  /* Multi-packet byte count bit 14 mask. */
#define USB_MCNT_14_bp  14  /* Multi-packet byte count bit 14 position. */
#define USB_MCNT_15_bm  (1<<15)  /* Multi-packet byte count bit 15 mask. */
#define USB_MCNT_15_bp  15  /* Multi-packet byte count bit 15 position. */



/* USB.FIFO  bit masks and bit positions */
#define USB_DIR_bm  0x08  /* Endpoint Direction bit mask. */
#define USB_DIR_bp  3  /* Endpoint Direction bit position. */
#define USB_EPNUM_gm  0xF0  /* Endpoint Number group mask. */
#define USB_EPNUM_gp  4  /* Endpoint Number group position. */
#define USB_EPNUM_0_bm  (1<<4)  /* Endpoint Number bit 0 mask. */
#define USB_EPNUM_0_bp  4  /* Endpoint Number bit 0 position. */
#define USB_EPNUM_1_bm  (1<<5)  /* Endpoint Number bit 1 mask. */
#define USB_EPNUM_1_bp  5  /* Endpoint Number bit 1 position. */
#define USB_EPNUM_2_bm  (1<<6)  /* Endpoint Number bit 2 mask. */
#define USB_EPNUM_2_bp  6  /* Endpoint Number bit 2 position. */
#define USB_EPNUM_3_bm  (1<<7)  /* Endpoint Number bit 3 mask. */
#define USB_EPNUM_3_bp  7  /* Endpoint Number bit 3 position. */

/* USB.FRAMENUM  bit masks and bit positions */
#define USB_FRAMENUM_gm  0x7FF  /* Frame Number group mask. */
#define USB_FRAMENUM_gp  0  /* Frame Number group position. */
#define USB_FRAMENUM_0_bm  (1<<0)  /* Frame Number bit 0 mask. */
#define USB_FRAMENUM_0_bp  0  /* Frame Number bit 0 position. */
#define USB_FRAMENUM_1_bm  (1<<1)  /* Frame Number bit 1 mask. */
#define USB_FRAMENUM_1_bp  1  /* Frame Number bit 1 position. */
#define USB_FRAMENUM_2_bm  (1<<2)  /* Frame Number bit 2 mask. */
#define USB_FRAMENUM_2_bp  2  /* Frame Number bit 2 position. */
#define USB_FRAMENUM_3_bm  (1<<3)  /* Frame Number bit 3 mask. */
#define USB_FRAMENUM_3_bp  3  /* Frame Number bit 3 position. */
#define USB_FRAMENUM_4_bm  (1<<4)  /* Frame Number bit 4 mask. */
#define USB_FRAMENUM_4_bp  4  /* Frame Number bit 4 position. */
#define USB_FRAMENUM_5_bm  (1<<5)  /* Frame Number bit 5 mask. */
#define USB_FRAMENUM_5_bp  5  /* Frame Number bit 5 position. */
#define USB_FRAMENUM_6_bm  (1<<6)  /* Frame Number bit 6 mask. */
#define USB_FRAMENUM_6_bp  6  /* Frame Number bit 6 position. */
#define USB_FRAMENUM_7_bm  (1<<7)  /* Frame Number bit 7 mask. */
#define USB_FRAMENUM_7_bp  7  /* Frame Number bit 7 position. */
#define USB_FRAMENUM_8_bm  (1<<8)  /* Frame Number bit 8 mask. */
#define USB_FRAMENUM_8_bp  8  /* Frame Number bit 8 position. */
#define USB_FRAMENUM_9_bm  (1<<9)  /* Frame Number bit 9 mask. */
#define USB_FRAMENUM_9_bp  9  /* Frame Number bit 9 position. */
#define USB_FRAMENUM_10_bm  (1<<10)  /* Frame Number bit 10 mask. */
#define USB_FRAMENUM_10_bp  10  /* Frame Number bit 10 position. */
#define USB_FRAMEERR_bm  0x8000  /* Frame Error bit mask. */
#define USB_FRAMEERR_bp  15  /* Frame Error bit position. */


/* USB.OUTCLR  bit masks and bit positions */
#define USB_RMWSTATUS_gm  0xFF  /* Read-Modify-Write Endpoint STATUS group mask. */
#define USB_RMWSTATUS_gp  0  /* Read-Modify-Write Endpoint STATUS group position. */
#define USB_RMWSTATUS_0_bm  (1<<0)  /* Read-Modify-Write Endpoint STATUS bit 0 mask. */
#define USB_RMWSTATUS_0_bp  0  /* Read-Modify-Write Endpoint STATUS bit 0 position. */
#define USB_RMWSTATUS_1_bm  (1<<1)  /* Read-Modify-Write Endpoint STATUS bit 1 mask. */
#define USB_RMWSTATUS_1_bp  1  /* Read-Modify-Write Endpoint STATUS bit 1 position. */
#define USB_RMWSTATUS_2_bm  (1<<2)  /* Read-Modify-Write Endpoint STATUS bit 2 mask. */
#define USB_RMWSTATUS_2_bp  2  /* Read-Modify-Write Endpoint STATUS bit 2 position. */
#define USB_RMWSTATUS_3_bm  (1<<3)  /* Read-Modify-Write Endpoint STATUS bit 3 mask. */
#define USB_RMWSTATUS_3_bp  3  /* Read-Modify-Write Endpoint STATUS bit 3 position. */
#define USB_RMWSTATUS_4_bm  (1<<4)  /* Read-Modify-Write Endpoint STATUS bit 4 mask. */
#define USB_RMWSTATUS_4_bp  4  /* Read-Modify-Write Endpoint STATUS bit 4 position. */
#define USB_RMWSTATUS_5_bm  (1<<5)  /* Read-Modify-Write Endpoint STATUS bit 5 mask. */
#define USB_RMWSTATUS_5_bp  5  /* Read-Modify-Write Endpoint STATUS bit 5 position. */
#define USB_RMWSTATUS_6_bm  (1<<6)  /* Read-Modify-Write Endpoint STATUS bit 6 mask. */
#define USB_RMWSTATUS_6_bp  6  /* Read-Modify-Write Endpoint STATUS bit 6 position. */
#define USB_RMWSTATUS_7_bm  (1<<7)  /* Read-Modify-Write Endpoint STATUS bit 7 mask. */
#define USB_RMWSTATUS_7_bp  7  /* Read-Modify-Write Endpoint STATUS bit 7 position. */

/* USB.OUTSET  bit masks and bit positions */
/* USB_RMWSTATUS  is already defined. */

/* USB.INCLR  bit masks and bit positions */
/* USB_RMWSTATUS  is already defined. */

/* USB.INSET  bit masks and bit positions */
/* USB_RMWSTATUS  is already defined. */



/* VPORT - Virtual Ports */
/* VPORT.INTFLAGS  bit masks and bit positions */
#define VPORT_INT_gm  0xFF  /* Pin Interrupt group mask. */
#define VPORT_INT_gp  0  /* Pin Interrupt group position. */
#define VPORT_INT_0_bm  (1<<0)  /* Pin Interrupt bit 0 mask. */
#define VPORT_INT_0_bp  0  /* Pin Interrupt bit 0 position. */
#define VPORT_INT_1_bm  (1<<1)  /* Pin Interrupt bit 1 mask. */
#define VPORT_INT_1_bp  1  /* Pin Interrupt bit 1 position. */
#define VPORT_INT_2_bm  (1<<2)  /* Pin Interrupt bit 2 mask. */
#define VPORT_INT_2_bp  2  /* Pin Interrupt bit 2 position. */
#define VPORT_INT_3_bm  (1<<3)  /* Pin Interrupt bit 3 mask. */
#define VPORT_INT_3_bp  3  /* Pin Interrupt bit 3 position. */
#define VPORT_INT_4_bm  (1<<4)  /* Pin Interrupt bit 4 mask. */
#define VPORT_INT_4_bp  4  /* Pin Interrupt bit 4 position. */
#define VPORT_INT_5_bm  (1<<5)  /* Pin Interrupt bit 5 mask. */
#define VPORT_INT_5_bp  5  /* Pin Interrupt bit 5 position. */
#define VPORT_INT_6_bm  (1<<6)  /* Pin Interrupt bit 6 mask. */
#define VPORT_INT_6_bp  6  /* Pin Interrupt bit 6 position. */
#define VPORT_INT_7_bm  (1<<7)  /* Pin Interrupt bit 7 mask. */
#define VPORT_INT_7_bp  7  /* Pin Interrupt bit 7 position. */


/* VREF - Voltage reference */
/* VREF.ADC0REF  bit masks and bit positions */
#define VREF_REFSEL_gm  0x07  /* Reference select group mask. */
#define VREF_REFSEL_gp  0  /* Reference select group position. */
#define VREF_REFSEL_0_bm  (1<<0)  /* Reference select bit 0 mask. */
#define VREF_REFSEL_0_bp  0  /* Reference select bit 0 position. */
#define VREF_REFSEL_1_bm  (1<<1)  /* Reference select bit 1 mask. */
#define VREF_REFSEL_1_bp  1  /* Reference select bit 1 position. */
#define VREF_REFSEL_2_bm  (1<<2)  /* Reference select bit 2 mask. */
#define VREF_REFSEL_2_bp  2  /* Reference select bit 2 position. */
#define VREF_ALWAYSON_bm  0x80  /* Always on bit mask. */
#define VREF_ALWAYSON_bp  7  /* Always on bit position. */

/* VREF.DAC0REF  bit masks and bit positions */
/* VREF_REFSEL  is already defined. */
/* VREF_ALWAYSON  is already defined. */

/* VREF.ACREF  bit masks and bit positions */
/* VREF_REFSEL  is already defined. */
/* VREF_ALWAYSON  is already defined. */

/* VREF.CALIB  bit masks and bit positions */
#define VREF_VREFASEL_bm  0x02  /* VREFA reference connection bit mask. */
#define VREF_VREFASEL_bp  1  /* VREFA reference connection bit position. */
#define VREF_ADC0COMP_bm  0x04  /* Enable offset compensation bit mask. */
#define VREF_ADC0COMP_bp  2  /* Enable offset compensation bit position. */
#define VREF_DAC0COMP_bm  0x08  /* Enable offset compensation bit mask. */
#define VREF_DAC0COMP_bp  3  /* Enable offset compensation bit position. */
#define VREF_ACCOMP_bm  0x10  /* Enable offset compensation bit mask. */
#define VREF_ACCOMP_bp  4  /* Enable offset compensation bit position. */
#define VREF_QBIAS_bm  0x20  /* Quarter bias for ADC reference buffer bit mask. */
#define VREF_QBIAS_bp  5  /* Quarter bias for ADC reference buffer bit position. */
#define VREF_ADC0OFFSET_bm  0x40  /* ADC0 offset cancellation bit mask. */
#define VREF_ADC0OFFSET_bp  6  /* ADC0 offset cancellation bit position. */

/* VREF.TEST  bit masks and bit positions */
#define VREF_AZDIS_bm  0x01  /* AZDIS bit mask. */
#define VREF_AZDIS_bp  0  /* AZDIS bit position. */


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


/* ZCD - Zero Cross Detect */
/* ZCD.CTRLA  bit masks and bit positions */
#define ZCD_ENABLE_bm  0x01  /* Enable bit mask. */
#define ZCD_ENABLE_bp  0  /* Enable bit position. */
#define ZCD_INVERT_bm  0x08  /* Invert signal from pin bit mask. */
#define ZCD_INVERT_bp  3  /* Invert signal from pin bit position. */
#define ZCD_OUTEN_bm  0x40  /* Output Pad Enable bit mask. */
#define ZCD_OUTEN_bp  6  /* Output Pad Enable bit position. */
#define ZCD_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define ZCD_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */

/* ZCD.INTCTRL  bit masks and bit positions */
#define ZCD_INTMODE_gm  0x03  /* Interrupt Mode group mask. */
#define ZCD_INTMODE_gp  0  /* Interrupt Mode group position. */
#define ZCD_INTMODE_0_bm  (1<<0)  /* Interrupt Mode bit 0 mask. */
#define ZCD_INTMODE_0_bp  0  /* Interrupt Mode bit 0 position. */
#define ZCD_INTMODE_1_bm  (1<<1)  /* Interrupt Mode bit 1 mask. */
#define ZCD_INTMODE_1_bp  1  /* Interrupt Mode bit 1 position. */

/* ZCD.STATUS  bit masks and bit positions */
#define ZCD_CROSSIF_bm  0x01  /* ZCD Interrupt Flag bit mask. */
#define ZCD_CROSSIF_bp  0  /* ZCD Interrupt Flag bit position. */
#define ZCD_STATE_bm  0x10  /* ZCD State bit mask. */
#define ZCD_STATE_bp  4  /* ZCD State bit position. */


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

/* BOD interrupt vectors */
#define BOD_VLM_vect_num  2
#define BOD_VLM_vect      _VECTOR(2)  /*  */

/* RTC interrupt vectors */
#define RTC_CNT_vect_num  5
#define RTC_CNT_vect      _VECTOR(5)  /*  */
#define RTC_PIT_vect_num  6
#define RTC_PIT_vect      _VECTOR(6)  /*  */

/* CCL interrupt vectors */
#define CCL_CCL_vect_num  7
#define CCL_CCL_vect      _VECTOR(7)  /*  */

/* PORTA interrupt vectors */
#define PORTA_PORT_vect_num  8
#define PORTA_PORT_vect      _VECTOR(8)  /*  */

/* TCA0 interrupt vectors */
#define TCA0_LUNF_vect_num  9
#define TCA0_LUNF_vect      _VECTOR(9)  /*  */
#define TCA0_OVF_vect_num  9
#define TCA0_OVF_vect      _VECTOR(9)  /*  */
#define TCA0_HUNF_vect_num  10
#define TCA0_HUNF_vect      _VECTOR(10)  /*  */
#define TCA0_CMP0_vect_num  11
#define TCA0_CMP0_vect      _VECTOR(11)  /*  */
#define TCA0_LCMP0_vect_num  11
#define TCA0_LCMP0_vect      _VECTOR(11)  /*  */
#define TCA0_CMP1_vect_num  12
#define TCA0_CMP1_vect      _VECTOR(12)  /*  */
#define TCA0_LCMP1_vect_num  12
#define TCA0_LCMP1_vect      _VECTOR(12)  /*  */
#define TCA0_CMP2_vect_num  13
#define TCA0_CMP2_vect      _VECTOR(13)  /*  */
#define TCA0_LCMP2_vect_num  13
#define TCA0_LCMP2_vect      _VECTOR(13)  /*  */

/* TCB0 interrupt vectors */
#define TCB0_INT_vect_num  14
#define TCB0_INT_vect      _VECTOR(14)  /*  */

/* TCB1 interrupt vectors */
#define TCB1_INT_vect_num  15
#define TCB1_INT_vect      _VECTOR(15)  /*  */

/* TCD0 interrupt vectors */
#define TCD0_OVF_vect_num  16
#define TCD0_OVF_vect      _VECTOR(16)  /*  */
#define TCD0_TRIG_vect_num  17
#define TCD0_TRIG_vect      _VECTOR(17)  /*  */

/* TWI0 interrupt vectors */
#define TWI0_TWIS_vect_num  18
#define TWI0_TWIS_vect      _VECTOR(18)  /*  */
#define TWI0_TWIM_vect_num  19
#define TWI0_TWIM_vect      _VECTOR(19)  /*  */

/* SPI0 interrupt vectors */
#define SPI0_INT_vect_num  20
#define SPI0_INT_vect      _VECTOR(20)  /*  */

/* USART0 interrupt vectors */
#define USART0_RXC_vect_num  21
#define USART0_RXC_vect      _VECTOR(21)  /*  */
#define USART0_DRE_vect_num  22
#define USART0_DRE_vect      _VECTOR(22)  /*  */
#define USART0_TXC_vect_num  23
#define USART0_TXC_vect      _VECTOR(23)  /*  */

/* PORTD interrupt vectors */
#define PORTD_PORT_vect_num  24
#define PORTD_PORT_vect      _VECTOR(24)  /*  */

/* AC0 interrupt vectors */
#define AC0_AC_vect_num  25
#define AC0_AC_vect      _VECTOR(25)  /*  */

/* ADC0 interrupt vectors */
#define ADC0_RESRDY_vect_num  26
#define ADC0_RESRDY_vect      _VECTOR(26)  /*  */
#define ADC0_WCMP_vect_num  27
#define ADC0_WCMP_vect      _VECTOR(27)  /*  */

/* ZCD0 interrupt vectors */
#define ZCD0_ZCD_vect_num  28
#define ZCD0_ZCD_vect      _VECTOR(28)  /*  */

/* AC1 interrupt vectors */
#define AC1_AC_vect_num  29
#define AC1_AC_vect      _VECTOR(29)  /*  */

/* PORTC interrupt vectors */
#define PORTC_PORT_vect_num  30
#define PORTC_PORT_vect      _VECTOR(30)  /*  */

/* TCB2 interrupt vectors */
#define TCB2_INT_vect_num  31
#define TCB2_INT_vect      _VECTOR(31)  /*  */

/* USART1 interrupt vectors */
#define USART1_RXC_vect_num  32
#define USART1_RXC_vect      _VECTOR(32)  /*  */
#define USART1_DRE_vect_num  33
#define USART1_DRE_vect      _VECTOR(33)  /*  */
#define USART1_TXC_vect_num  34
#define USART1_TXC_vect      _VECTOR(34)  /*  */

/* NVMCTRL interrupt vectors */
#define NVMCTRL_EE_vect_num  36
#define NVMCTRL_EE_vect      _VECTOR(36)  /*  */

/* SPI1 interrupt vectors */
#define SPI1_INT_vect_num  37
#define SPI1_INT_vect      _VECTOR(37)  /*  */

/* USART2 interrupt vectors */
#define USART2_RXC_vect_num  38
#define USART2_RXC_vect      _VECTOR(38)  /*  */
#define USART2_DRE_vect_num  39
#define USART2_DRE_vect      _VECTOR(39)  /*  */
#define USART2_TXC_vect_num  40
#define USART2_TXC_vect      _VECTOR(40)  /*  */

/* AC2 interrupt vectors */
#define AC2_AC_vect_num  41
#define AC2_AC_vect      _VECTOR(41)  /*  */

/* TWI1 interrupt vectors */
#define TWI1_TWIS_vect_num  42
#define TWI1_TWIS_vect      _VECTOR(42)  /*  */
#define TWI1_TWIM_vect_num  43
#define TWI1_TWIM_vect      _VECTOR(43)  /*  */

/* TCB3 interrupt vectors */
#define TCB3_INT_vect_num  44
#define TCB3_INT_vect      _VECTOR(44)  /*  */

/* PORTB interrupt vectors */
#define PORTB_PORT_vect_num  45
#define PORTB_PORT_vect      _VECTOR(45)  /*  */

/* PORTE interrupt vectors */
#define PORTE_PORT_vect_num  46
#define PORTE_PORT_vect      _VECTOR(46)  /*  */

/* TCA1 interrupt vectors */
#define TCA1_LUNF_vect_num  47
#define TCA1_LUNF_vect      _VECTOR(47)  /*  */
#define TCA1_OVF_vect_num  47
#define TCA1_OVF_vect      _VECTOR(47)  /*  */
#define TCA1_HUNF_vect_num  48
#define TCA1_HUNF_vect      _VECTOR(48)  /*  */
#define TCA1_CMP0_vect_num  49
#define TCA1_CMP0_vect      _VECTOR(49)  /*  */
#define TCA1_LCMP0_vect_num  49
#define TCA1_LCMP0_vect      _VECTOR(49)  /*  */
#define TCA1_CMP1_vect_num  50
#define TCA1_CMP1_vect      _VECTOR(50)  /*  */
#define TCA1_LCMP1_vect_num  50
#define TCA1_LCMP1_vect      _VECTOR(50)  /*  */
#define TCA1_CMP2_vect_num  51
#define TCA1_CMP2_vect      _VECTOR(51)  /*  */
#define TCA1_LCMP2_vect_num  51
#define TCA1_LCMP2_vect      _VECTOR(51)  /*  */

/* ZCD1 interrupt vectors */
#define ZCD1_ZCD_vect_num  52
#define ZCD1_ZCD_vect      _VECTOR(52)  /*  */

/* USART3 interrupt vectors */
#define USART3_RXC_vect_num  53
#define USART3_RXC_vect      _VECTOR(53)  /*  */
#define USART3_DRE_vect_num  54
#define USART3_DRE_vect      _VECTOR(54)  /*  */
#define USART3_TXC_vect_num  55
#define USART3_TXC_vect      _VECTOR(55)  /*  */

/* USART4 interrupt vectors */
#define USART4_RXC_vect_num  56
#define USART4_RXC_vect      _VECTOR(56)  /*  */
#define USART4_DRE_vect_num  57
#define USART4_DRE_vect      _VECTOR(57)  /*  */
#define USART4_TXC_vect_num  58
#define USART4_TXC_vect      _VECTOR(58)  /*  */

/* ZCD2 interrupt vectors */
#define ZCD2_ZCD_vect_num  60
#define ZCD2_ZCD_vect      _VECTOR(60)  /*  */

/* TCB4 interrupt vectors */
#define TCB4_INT_vect_num  61
#define TCB4_INT_vect      _VECTOR(61)  /*  */

/* USART5 interrupt vectors */
#define USART5_RXC_vect_num  62
#define USART5_RXC_vect      _VECTOR(62)  /*  */
#define USART5_DRE_vect_num  63
#define USART5_DRE_vect      _VECTOR(63)  /*  */
#define USART5_TXC_vect_num  64
#define USART5_TXC_vect      _VECTOR(64)  /*  */

/* FPGA interrupt vectors */
#define FPGA_FPGA_vect_num  65
#define FPGA_FPGA_vect      _VECTOR(65)  /*  */

/* USB0 interrupt vectors */
#define USB0_BUSEVENT_vect_num  66
#define USB0_BUSEVENT_vect      _VECTOR(66)  /*  */
#define USB0_TRNCOMPL_vect_num  67
#define USB0_TRNCOMPL_vect      _VECTOR(67)  /*  */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (68 * _VECTOR_SIZE)


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
#  define USER_SIGNATURES_START     (0x1080)
#  define USER_SIGNATURES_SIZE      (32)
#  define USER_SIGNATURES_PAGE_SIZE (32)
#else
#  define USER_SIGNATURES_START     (0x1080U)
#  define USER_SIGNATURES_SIZE      (32U)
#  define USER_SIGNATURES_PAGE_SIZE (32U)
#endif
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SIGNATURES_START     (0x1100)
#  define SIGNATURES_SIZE      (3)
#  define SIGNATURES_PAGE_SIZE (128)
#else
#  define SIGNATURES_START     (0x1100U)
#  define SIGNATURES_SIZE      (3U)
#  define SIGNATURES_PAGE_SIZE (128U)
#endif
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROD_SIGNATURES_START     (0x1103)
#  define PROD_SIGNATURES_SIZE      (125)
#  define PROD_SIGNATURES_PAGE_SIZE (128)
#else
#  define PROD_SIGNATURES_START     (0x1103U)
#  define PROD_SIGNATURES_SIZE      (125U)
#  define PROD_SIGNATURES_PAGE_SIZE (128U)
#endif
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

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
#define SIGNATURE_1 0x97
#define SIGNATURE_2 0xFF

#endif /* #ifdef _AVR_AVRFPGAV1_H_INCLUDED */

