/*
 * Copyright (C) 2025, Microchip Technology Inc. and its subsidiaries ("Microchip")
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
#  define _AVR_IOXXX_H_ "ioavr64ec48.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_AVR64EC48_H_INCLUDED
#define _AVR_AVR64EC48_H_INCLUDED

/* Ungrouped common registers */
#define CCP  _SFR_MEM8(0x0034)  /* Configuration Change Protection */
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
    register8_t MUXCTRL;  /* Multiplexer Control */
    register8_t REFSCALE;  /* Reference Scaling */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t reserved_1[1];
} AC_t;

/* Comparator State select */
typedef enum AC_CMP_enum
{
    AC_CMP_LOW_gc = (0x00<<0),  /* Comparator output is low */
    AC_CMP_HIGH_gc = (0x01<<0)  /* Comparator output is high */
} AC_CMP_t;

/* Initial value select */
typedef enum AC_INITVAL_enum
{
    AC_INITVAL_LOW_gc = (0x00<<4),  /* Output initialized to 0 */
    AC_INITVAL_HIGH_gc = (0x01<<4)  /* Output initialized to 1 */
} AC_INITVAL_t;

/* Interrupt Modes select */
typedef enum AC_INTMODE_enum
{
    AC_INTMODE_BOTHEDGES_gc = (0x00<<4),  /* Positive and negative input crosses */
    AC_INTMODE_NEGEDGE_gc = (0x02<<4),  /* Positive input goes below negative input */
    AC_INTMODE_POSEDGE_gc = (0x03<<4)  /* Positive input goes above negative input */
} AC_INTMODE_t;

/* Negative Input MUX Selection */
typedef enum AC_MUXNEG_enum
{
    AC_MUXNEG_AINN0_gc = (0x00<<0),  /* Negative Pin 0 */
    AC_MUXNEG_AINN1_gc = (0x01<<0),  /* Negative Pin 1 */
    AC_MUXNEG_AINN2_gc = (0x02<<0),  /* Negative Pin 2 */
    AC_MUXNEG_REFSCALE_gc = (0x07<<0)  /* Reference Scaler */
} AC_MUXNEG_t;

/* Positive Input MUX Selection */
typedef enum AC_MUXPOS_enum
{
    AC_MUXPOS_AINP0_gc = (0x00<<4),  /* Positive Pin 0 */
    AC_MUXPOS_AINP1_gc = (0x01<<4),  /* Positive Pin 1 */
    AC_MUXPOS_AINP2_gc = (0x02<<4),  /* Positive Pin 2 */
    AC_MUXPOS_AINP3_gc = (0x03<<4),  /* Positive Pin 3 */
    AC_MUXPOS_AINP5_gc = (0x05<<4),  /* Positive Pin 5 */
    AC_MUXPOS_AINP6_gc = (0x06<<4),  /* Positive Pin 6 */
    AC_MUXPOS_VDDDIV10_gc = (0x08<<4),  /* VDD/10 */
    AC_MUXPOS_VDDIO2DIV10_gc = (0x09<<4)  /* VDDIO2/10 */
} AC_MUXPOS_t;

/* Comparator operation range select */
typedef enum AC_RANGE_enum
{
    AC_RANGE_FULL_gc = (0x00<<6),  /* Full common mode range */
    AC_RANGE_LOW_gc = (0x02<<6),  /* Common mode range GND to (VDD-1V) */
    AC_RANGE_HIGH_gc = (0x03<<6)  /* Common mode range 1V to VDD */
} AC_RANGE_t;

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
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status register */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t CTRLE;  /* Control E */
    register8_t CTRLF;  /* Control F */
    register8_t COMMAND;  /* Command register */
    register8_t PGACTRL;  /* PGA Control */
    register8_t MUXPOS;  /* Positive Input Multiplexer */
    register8_t MUXNEG;  /* Negative Input Multiplexer */
    register8_t PGAMUXPOS;  /* PGA Positive Input Multiplexer */
    register8_t PGAMUXNEG;  /* PGA Negative Input Multiplexer */
    _DWORDREGISTER(RESULT);  /* Result */
    _WORDREGISTER(SAMPLE);  /* Sample */
    register8_t reserved_1[2];
    _WORDREGISTER(PGARESULT);  /* PGA Result */
    register8_t reserved_2[2];
    _WORDREGISTER(WINLT);  /* Window Low Threshold */
    _WORDREGISTER(WINHT);  /* Window High Threshold */
    register8_t OPASAMPDUR;  /* Opamp Sample Duration */
    register8_t reserved_3[11];
    register8_t TEMP0;  /* Temporary Data 0 */
    register8_t TEMP1;  /* Temporary Data 1 */
    register8_t TEMP2;  /* Temporary Data 2 */
    register8_t reserved_4[17];
} ADC_t;

/* Gain select */
typedef enum ADC_GAIN_enum
{
    ADC_GAIN_1X_gc = (0x00<<5),  /* 1x gain */
    ADC_GAIN_2X_gc = (0x01<<5),  /* 2x gain */
    ADC_GAIN_4X_gc = (0x02<<5),  /* 4x gain */
    ADC_GAIN_8X_gc = (0x03<<5),  /* 8x gain */
    ADC_GAIN_16X_gc = (0x04<<5)  /* 16x gain */
} ADC_GAIN_t;

/* Mode select */
typedef enum ADC_MODE_enum
{
    ADC_MODE_SINGLE_8BIT_gc = (0x00<<4),  /* Single Conversion with 8-bit resolution */
    ADC_MODE_SINGLE_12BIT_gc = (0x01<<4),  /* Single Conversion with 12-bit resolution */
    ADC_MODE_SERIES_gc = (0x02<<4),  /* Series with accumulation, separate trigger for every 12-bit conversion */
    ADC_MODE_SERIES_SCALING_gc = (0x03<<4),  /* Series with accumulation and scaling, separate trigger for every 12-bit conversion */
    ADC_MODE_BURST_gc = (0x04<<4),  /* Burst with accumulation, one trigger will run SAMPNUM 12-bit conversions */
    ADC_MODE_BURST_SCALING_gc = (0x05<<4),  /* Burst with accumulation and scaling, one trigger will run SAMPNUM 12-bit conversions */
    ADC_MODE_SIMULTANEOUS_gc = (0x06<<4)  /* Two simultaneous samples, one by the ADC and the other by the PGA, 12-bit conversions */
} ADC_MODE_t;

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
    ADC_MUXNEG_AIN16_gc = (0x10<<0),  /* ADC input pin 16 */
    ADC_MUXNEG_AIN17_gc = (0x11<<0),  /* ADC input pin 17 */
    ADC_MUXNEG_AIN18_gc = (0x12<<0),  /* ADC input pin 18 */
    ADC_MUXNEG_AIN19_gc = (0x13<<0),  /* ADC input pin 19 */
    ADC_MUXNEG_AIN20_gc = (0x14<<0),  /* ADC input pin 20 */
    ADC_MUXNEG_AIN21_gc = (0x15<<0),  /* ADC input pin 21 */
    ADC_MUXNEG_AIN22_gc = (0x16<<0),  /* ADC input pin 22 */
    ADC_MUXNEG_AIN23_gc = (0x17<<0),  /* ADC input pin 23 */
    ADC_MUXNEG_AIN24_gc = (0x18<<0),  /* ADC input pin 24 */
    ADC_MUXNEG_AIN25_gc = (0x19<<0),  /* ADC input pin 25 */
    ADC_MUXNEG_AIN26_gc = (0x1A<<0),  /* ADC input pin 26 */
    ADC_MUXNEG_AIN27_gc = (0x1B<<0),  /* ADC input pin 27 */
    ADC_MUXNEG_GND_gc = (0x30<<0),  /* Ground */
    ADC_MUXNEG_VREFP_gc = (0x31<<0),  /* Positive Reference */
    ADC_MUXNEG_DAC0_gc = (0x34<<0),  /* DAC0 Output */
    ADC_MUXNEG_PGA_gc = (0x3F<<0)  /* PGA Negative Output */
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
    ADC_MUXPOS_AIN16_gc = (0x10<<0),  /* ADC input pin 16 */
    ADC_MUXPOS_AIN17_gc = (0x11<<0),  /* ADC input pin 17 */
    ADC_MUXPOS_AIN18_gc = (0x12<<0),  /* ADC input pin 18 */
    ADC_MUXPOS_AIN19_gc = (0x13<<0),  /* ADC input pin 19 */
    ADC_MUXPOS_AIN20_gc = (0x14<<0),  /* ADC input pin 20 */
    ADC_MUXPOS_AIN21_gc = (0x15<<0),  /* ADC input pin 21 */
    ADC_MUXPOS_AIN22_gc = (0x16<<0),  /* ADC input pin 22 */
    ADC_MUXPOS_AIN23_gc = (0x17<<0),  /* ADC input pin 23 */
    ADC_MUXPOS_AIN24_gc = (0x18<<0),  /* ADC input pin 24 */
    ADC_MUXPOS_AIN25_gc = (0x19<<0),  /* ADC input pin 25 */
    ADC_MUXPOS_AIN26_gc = (0x1A<<0),  /* ADC input pin 26 */
    ADC_MUXPOS_AIN27_gc = (0x1B<<0),  /* ADC input pin 27 */
    ADC_MUXPOS_GND_gc = (0x30<<0),  /* Ground */
    ADC_MUXPOS_TEMPSENSE_gc = (0x31<<0),  /* Temperature Sensor */
    ADC_MUXPOS_VDDDIV10_gc = (0x32<<0),  /* VDD Divided by 10 */
    ADC_MUXPOS_VDDIO2DIV10_gc = (0x33<<0),  /* VDDIO2 Divided by 10 */
    ADC_MUXPOS_DAC0_gc = (0x34<<0),  /* DAC0 Output */
    ADC_MUXPOS_AC0REF_gc = (0x35<<0),  /* AC0 Reference Scaler */
    ADC_MUXPOS_OPAMP0_gc = (0x38<<0),  /* OPAMP0 Output (AIN2) */
    ADC_MUXPOS_OPAMP1_gc = (0x39<<0),  /* OPAMP1 Output (AIN5) */
    ADC_MUXPOS_PGA_gc = (0x3F<<0)  /* PGA Positive Output */
} ADC_MUXPOS_t;

/* PGA BIAS Select */
typedef enum ADC_PGABIASSEL_enum
{
    ADC_PGABIASSEL_100PCT_gc = (0x00<<3),  /* 100% BIAS current. */
    ADC_PGABIASSEL_75PCT_gc = (0x01<<3),  /* 75% BIAS current. Usable for CLK_ADC<4.5MHz */
    ADC_PGABIASSEL_50PCT_gc = (0x02<<3),  /* 50% BIAS current. Usable for CLK_ADC<3MHz */
    ADC_PGABIASSEL_25PCT_gc = (0x03<<3)  /* 25% BIAS current. Usable for CLK_ADC<1.5MHz */
} ADC_PGABIASSEL_t;

/* PGA Analog Channel Selection Bits */
typedef enum ADC_PGAMUXNEG_enum
{
    ADC_PGAMUXNEG_AIN0_gc = (0x00<<0),  /* ADC input pin 0 */
    ADC_PGAMUXNEG_AIN1_gc = (0x01<<0),  /* ADC input pin 1 */
    ADC_PGAMUXNEG_AIN2_gc = (0x02<<0),  /* ADC input pin 2 */
    ADC_PGAMUXNEG_AIN3_gc = (0x03<<0),  /* ADC input pin 3 */
    ADC_PGAMUXNEG_AIN4_gc = (0x04<<0),  /* ADC input pin 4 */
    ADC_PGAMUXNEG_AIN5_gc = (0x05<<0),  /* ADC input pin 5 */
    ADC_PGAMUXNEG_AIN6_gc = (0x06<<0),  /* ADC input pin 6 */
    ADC_PGAMUXNEG_AIN7_gc = (0x07<<0),  /* ADC input pin 7 */
    ADC_PGAMUXNEG_AIN8_gc = (0x08<<0),  /* ADC input pin 8 */
    ADC_PGAMUXNEG_AIN9_gc = (0x09<<0),  /* ADC input pin 9 */
    ADC_PGAMUXNEG_AIN10_gc = (0x0A<<0),  /* ADC input pin 10 */
    ADC_PGAMUXNEG_AIN11_gc = (0x0B<<0),  /* ADC input pin 11 */
    ADC_PGAMUXNEG_AIN16_gc = (0x10<<0),  /* ADC input pin 16 */
    ADC_PGAMUXNEG_AIN17_gc = (0x11<<0),  /* ADC input pin 17 */
    ADC_PGAMUXNEG_AIN18_gc = (0x12<<0),  /* ADC input pin 18 */
    ADC_PGAMUXNEG_AIN19_gc = (0x13<<0),  /* ADC input pin 19 */
    ADC_PGAMUXNEG_AIN20_gc = (0x14<<0),  /* ADC input pin 20 */
    ADC_PGAMUXNEG_AIN21_gc = (0x15<<0),  /* ADC input pin 21 */
    ADC_PGAMUXNEG_AIN22_gc = (0x16<<0),  /* ADC input pin 22 */
    ADC_PGAMUXNEG_AIN23_gc = (0x17<<0),  /* ADC input pin 23 */
    ADC_PGAMUXNEG_AIN24_gc = (0x18<<0),  /* ADC input pin 24 */
    ADC_PGAMUXNEG_AIN25_gc = (0x19<<0),  /* ADC input pin 25 */
    ADC_PGAMUXNEG_AIN26_gc = (0x1A<<0),  /* ADC input pin 26 */
    ADC_PGAMUXNEG_AIN27_gc = (0x1B<<0),  /* ADC input pin 27 */
    ADC_PGAMUXNEG_GND_gc = (0x30<<0),  /* Ground */
    ADC_PGAMUXNEG_VREFP_gc = (0x31<<0),  /* Positive Reference */
    ADC_PGAMUXNEG_DAC0_gc = (0x34<<0)  /* DAC0 Output */
} ADC_PGAMUXNEG_t;

/* PGA Analog Channel Selection Bits */
typedef enum ADC_PGAMUXPOS_enum
{
    ADC_PGAMUXPOS_AIN0_gc = (0x00<<0),  /* ADC input pin 0 */
    ADC_PGAMUXPOS_AIN1_gc = (0x01<<0),  /* ADC input pin 1 */
    ADC_PGAMUXPOS_AIN2_gc = (0x02<<0),  /* ADC input pin 2 (OPAMP0) */
    ADC_PGAMUXPOS_AIN3_gc = (0x03<<0),  /* ADC input pin 3 */
    ADC_PGAMUXPOS_AIN4_gc = (0x04<<0),  /* ADC input pin 4 */
    ADC_PGAMUXPOS_AIN5_gc = (0x05<<0),  /* ADC input pin 5 (OPAMP1) */
    ADC_PGAMUXPOS_AIN6_gc = (0x06<<0),  /* ADC input pin 6 (DAC0) */
    ADC_PGAMUXPOS_AIN7_gc = (0x07<<0),  /* ADC input pin 7 */
    ADC_PGAMUXPOS_AIN8_gc = (0x08<<0),  /* ADC input pin 8 */
    ADC_PGAMUXPOS_AIN9_gc = (0x09<<0),  /* ADC input pin 9 */
    ADC_PGAMUXPOS_AIN10_gc = (0x0A<<0),  /* ADC input pin 10 */
    ADC_PGAMUXPOS_AIN11_gc = (0x0B<<0),  /* ADC input pin 11 */
    ADC_PGAMUXPOS_AIN16_gc = (0x10<<0),  /* ADC input pin 16 */
    ADC_PGAMUXPOS_AIN17_gc = (0x11<<0),  /* ADC input pin 17 */
    ADC_PGAMUXPOS_AIN18_gc = (0x12<<0),  /* ADC input pin 18 */
    ADC_PGAMUXPOS_AIN19_gc = (0x13<<0),  /* ADC input pin 19 */
    ADC_PGAMUXPOS_AIN20_gc = (0x14<<0),  /* ADC input pin 20 */
    ADC_PGAMUXPOS_AIN21_gc = (0x15<<0),  /* ADC input pin 21 */
    ADC_PGAMUXPOS_AIN22_gc = (0x16<<0),  /* ADC input pin 22 */
    ADC_PGAMUXPOS_AIN23_gc = (0x17<<0),  /* ADC input pin 23 */
    ADC_PGAMUXPOS_AIN24_gc = (0x18<<0),  /* ADC input pin 24 */
    ADC_PGAMUXPOS_AIN25_gc = (0x19<<0),  /* ADC input pin 25 */
    ADC_PGAMUXPOS_AIN26_gc = (0x1A<<0),  /* ADC input pin 26 */
    ADC_PGAMUXPOS_AIN27_gc = (0x1B<<0),  /* ADC input pin 27 */
    ADC_PGAMUXPOS_GND_gc = (0x30<<0),  /* Ground */
    ADC_PGAMUXPOS_TEMPSENSE_gc = (0x31<<0),  /* Temperature Sensor */
    ADC_PGAMUXPOS_VDDDIV10_gc = (0x32<<0),  /* VDD Divided by 10 */
    ADC_PGAMUXPOS_VDDIO2DIV10_gc = (0x33<<0),  /* VDDIO2 Divided by 10 */
    ADC_PGAMUXPOS_DAC0_gc = (0x34<<0),  /* DAC0 Output */
    ADC_PGAMUXPOS_AC0REF_gc = (0x35<<0),  /* AC0 Reference Scaler */
    ADC_PGAMUXPOS_OPAMP0_gc = (0x38<<0),  /* OPAMP0 Output (AIN2) */
    ADC_PGAMUXPOS_OPAMP1_gc = (0x39<<0)  /* OPAMP1 Output (AIN5) */
} ADC_PGAMUXPOS_t;

/* Prescaler Value select */
typedef enum ADC_PRESC_enum
{
    ADC_PRESC_DIV2_gc = (0x00<<0),  /* System clock divided by 2 */
    ADC_PRESC_DIV4_gc = (0x01<<0),  /* System clock divided by 4 */
    ADC_PRESC_DIV6_gc = (0x02<<0),  /* System clock divided by 6 */
    ADC_PRESC_DIV8_gc = (0x03<<0),  /* System clock divided by 8 */
    ADC_PRESC_DIV10_gc = (0x04<<0),  /* System clock divided by 10 */
    ADC_PRESC_DIV12_gc = (0x05<<0),  /* System clock divided by 12 */
    ADC_PRESC_DIV14_gc = (0x06<<0),  /* System clock divided by 14 */
    ADC_PRESC_DIV16_gc = (0x07<<0),  /* System clock divided by 16 */
    ADC_PRESC_DIV20_gc = (0x08<<0),  /* System clock divided by 20 */
    ADC_PRESC_DIV24_gc = (0x09<<0),  /* System clock divided by 24 */
    ADC_PRESC_DIV28_gc = (0x0A<<0),  /* System clock divided by 28 */
    ADC_PRESC_DIV32_gc = (0x0B<<0),  /* System clock divided by 32 */
    ADC_PRESC_DIV40_gc = (0x0C<<0),  /* System clock divided by 40 */
    ADC_PRESC_DIV48_gc = (0x0D<<0),  /* System clock divided by 48 */
    ADC_PRESC_DIV56_gc = (0x0E<<0),  /* System clock divided by 56 */
    ADC_PRESC_DIV64_gc = (0x0F<<0)  /* System clock divided by 64 */
} ADC_PRESC_t;

/* Sample numbers select */
typedef enum ADC_SAMPNUM_enum
{
    ADC_SAMPNUM_NONE_gc = (0x00<<0),  /* No accumulation */
    ADC_SAMPNUM_ACC2_gc = (0x01<<0),  /* 2 samples accumulated */
    ADC_SAMPNUM_ACC4_gc = (0x02<<0),  /* 4 samples accumulated */
    ADC_SAMPNUM_ACC8_gc = (0x03<<0),  /* 8 samples accumulated */
    ADC_SAMPNUM_ACC16_gc = (0x04<<0),  /* 16 samples accumulated */
    ADC_SAMPNUM_ACC32_gc = (0x05<<0),  /* 32 samples accumulated */
    ADC_SAMPNUM_ACC64_gc = (0x06<<0),  /* 64 samples accumulated */
    ADC_SAMPNUM_ACC128_gc = (0x07<<0),  /* 128 samples accumulated */
    ADC_SAMPNUM_ACC256_gc = (0x08<<0),  /* 256 samples accumulated */
    ADC_SAMPNUM_ACC512_gc = (0x09<<0),  /* 512 samples accumulated */
    ADC_SAMPNUM_ACC1024_gc = (0x0A<<0)  /* 1024 samples accumulated */
} ADC_SAMPNUM_t;

/* Start command select */
typedef enum ADC_START_enum
{
    ADC_START_STOP_gc = (0x00<<0),  /* Stop an ongoing conversion */
    ADC_START_IMMEDIATE_gc = (0x01<<0),  /* Start a conversion immediately. This will be set back to STOP when the first conversion is done, unless Free-Running mode is enabled */
    ADC_START_MUXPOS_WRITE_gc = (0x02<<0),  /* Start when MUXPOS register is written */
    ADC_START_MUXNEG_WRITE_gc = (0x03<<0),  /* Start when MUXNEG register is written */
    ADC_START_EVENT_TRIGGER_gc = (0x04<<0),  /* Start when an event is received */
    ADC_START_PGAMUXPOS_WRITE_gc = (0x06<<0),  /* Start when PGAMUXPOS register is written */
    ADC_START_PGAMUXNEG_WRITE_gc = (0x07<<0)  /* Start when PGAMUXNEG register is written */
} ADC_START_t;

/* Negative Reference Selection */
typedef enum ADC_VREFNEG_enum
{
    ADC_VREFNEG_GND_gc = (0x00<<4),  /* Internal GND */
    ADC_VREFNEG_EXTVREFGND0_gc = (0x01<<4)  /* External Reference */
} ADC_VREFNEG_t;

/* Positive Reference Selection */
typedef enum ADC_VREFPOS_enum
{
    ADC_VREFPOS_VDD_gc = (0x00<<0),  /* Internal VDD */
    ADC_VREFPOS_EXTVREF0_gc = (0x02<<0),  /* External Reference */
    ADC_VREFPOS_1V024_gc = (0x04<<0),  /* Internal 1.024V Reference */
    ADC_VREFPOS_2V048_gc = (0x05<<0),  /* Internal 2.048V Reference */
    ADC_VREFPOS_4V096_gc = (0x06<<0),  /* Internal 4.096V Reference */
    ADC_VREFPOS_2V500_gc = (0x07<<0)  /* Internal 2.500V Reference */
} ADC_VREFPOS_t;

/* Window Comparator Mode select */
typedef enum ADC_WINCM_enum
{
    ADC_WINCM_NONE_gc = (0x00<<0),  /* No Window Comparison */
    ADC_WINCM_BELOW_gc = (0x01<<0),  /* Below Window */
    ADC_WINCM_ABOVE_gc = (0x02<<0),  /* Above Window */
    ADC_WINCM_INSIDE_gc = (0x03<<0),  /* Inside Window */
    ADC_WINCM_OUTSIDE_gc = (0x04<<0)  /* Outside Window */
} ADC_WINCM_t;

/* Window Mode Source select */
typedef enum ADC_WINSRC_enum
{
    ADC_WINSRC_RESULT_gc = (0x00<<3),  /* Result register used as Window Comparator Source */
    ADC_WINSRC_SAMPLE_gc = (0x01<<3),  /* Sample register used as Window Comparator Source */
    ADC_WINSRC_PGARESULT_gc = (0x02<<3)  /* PGA Sample register used as Window Comparator Source */
} ADC_WINSRC_t;

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
    register8_t reserved_1[6];
    register8_t VLMCTRLA;  /* Voltage level monitor Control */
    register8_t INTCTRL;  /* Voltage level monitor interrupt Control */
    register8_t INTFLAGS;  /* Voltage level monitor interrupt Flags */
    register8_t STATUS;  /* Voltage level monitor status */
    register8_t reserved_2[4];
} BOD_t;

/* Operation in active mode select */
typedef enum BOD_ACTIVE_enum
{
    BOD_ACTIVE_DISABLE_gc = (0x00<<2),  /* Disabled */
    BOD_ACTIVE_ENABLED_gc = (0x01<<2),  /* Enabled in continuous mode */
    BOD_ACTIVE_SAMPLED_gc = (0x02<<2),  /* Enabled in sampled mode */
    BOD_ACTIVE_ENABLEWAIT_gc = (0x03<<2)  /* Enabled in continuous mode. Execution halted at wake-up until BOD is running */
} BOD_ACTIVE_t;

/* Bod level select */
typedef enum BOD_LVL_enum
{
    BOD_LVL_BODLEVEL0_gc = (0x00<<0),  /* 1.75 V Only used for chip erase */
    BOD_LVL_BODLEVEL1_gc = (0x01<<0),  /* 1.9 V */
    BOD_LVL_BODLEVEL2_gc = (0x02<<0),  /* 2.6 V */
    BOD_LVL_BODLEVEL3_gc = (0x03<<0)  /* 4.3 V */
} BOD_LVL_t;

/* Sample frequency select */
typedef enum BOD_SAMPFREQ_enum
{
    BOD_SAMPFREQ_128HZ_gc = (0x00<<4),  /* Sampling frequency is 128 Hz */
    BOD_SAMPFREQ_32HZ_gc = (0x01<<4)  /* Sample frequency is 32 Hz */
} BOD_SAMPFREQ_t;

/* Operation in sleep mode select */
typedef enum BOD_SLEEP_enum
{
    BOD_SLEEP_DISABLE_gc = (0x00<<0),  /* Disabled */
    BOD_SLEEP_ENABLE_gc = (0x01<<0),  /* Enabled in continuous mode */
    BOD_SLEEP_SAMPLE_gc = (0x02<<0)  /* Enabled in sampled mode */
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
BOOTROW - Boot Row
--------------------------------------------------------------------------
*/

/* Boot Row */
typedef struct BOOTROW_struct
{
    register8_t BOOTROW[64];  /* Boot Row */
} BOOTROW_t;


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
    CCL_CLKSRC_OSC1K_gc = (0x06<<1),  /* Internal 32.768 kHz oscillator divided by 32 */
    CCL_CLKSRC_PLL_gc = (0x07<<1)  /* PLL */
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
    CCL_INSEL0_AC0_gc = (0x06<<0),  /* AC0 OUT input source */
    CCL_INSEL0_USART0_gc = (0x07<<0),  /* USART0 TxD input source */
    CCL_INSEL0_SPI0_gc = (0x08<<0),  /* SPI0 MOSI input source */
    CCL_INSEL0_TCE0_gc = (0x09<<0),  /* TCE0 WO0 input source */
    CCL_INSEL0_TCB0_gc = (0x0A<<0),  /* TCB0 WO input source */
    CCL_INSEL0_TCB1_gc = (0x0B<<0),  /* TCB1 WO input source */
    CCL_INSEL0_TCF0_gc = (0x0C<<0)  /* TCF0 WO0 input source */
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
    CCL_INSEL1_AC0_gc = (0x06<<4),  /* AC0 OUT input source */
    CCL_INSEL1_USART1_gc = (0x07<<4),  /* USART1 TxD input source */
    CCL_INSEL1_SPI0_gc = (0x08<<4),  /* SPI0 MOSI input source */
    CCL_INSEL1_TCE0_gc = (0x09<<4),  /* TCE0 WO1 input source */
    CCL_INSEL1_TCB1_gc = (0x0A<<4),  /* TCB1 WO input source */
    CCL_INSEL1_TCB2_gc = (0x0B<<4),  /* TCB2 WO1 input source */
    CCL_INSEL1_TCF0_gc = (0x0C<<4)  /* TCF0 WO1 input source */
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
    CCL_INSEL2_USART2_gc = (0x07<<0),  /* USART2 TxD input source */
    CCL_INSEL2_SPI0_gc = (0x08<<0),  /* SPI0 MOSI input source */
    CCL_INSEL2_TCE0_gc = (0x09<<0),  /* TCE0 WO2 input source */
    CCL_INSEL2_TCB2_gc = (0x0A<<0),  /* TCB2 WO input source */
    CCL_INSEL2_TCB3_gc = (0x0B<<0),  /* TCB3 WO0 input source */
    CCL_INSEL2_TCF0_gc = (0x0C<<0)  /* TCF0 WO0 input source */
} CCL_INSEL2_t;

/* Interrupt Mode for LUT0 select */
typedef enum CCL_INTMODE0_enum
{
    CCL_INTMODE0_INTDISABLE_gc = (0x00<<0),  /* Interrupt disabled */
    CCL_INTMODE0_RISING_gc = (0x01<<0),  /* Sense rising edge */
    CCL_INTMODE0_FALLING_gc = (0x02<<0),  /* Sense falling edge */
    CCL_INTMODE0_BOTH_gc = (0x03<<0)  /* Sense both edges */
} CCL_INTMODE0_t;

/* Interrupt Mode for LUT1 select */
typedef enum CCL_INTMODE1_enum
{
    CCL_INTMODE1_INTDISABLE_gc = (0x00<<2),  /* Interrupt disabled */
    CCL_INTMODE1_RISING_gc = (0x01<<2),  /* Sense rising edge */
    CCL_INTMODE1_FALLING_gc = (0x02<<2),  /* Sense falling edge */
    CCL_INTMODE1_BOTH_gc = (0x03<<2)  /* Sense both edges */
} CCL_INTMODE1_t;

/* Interrupt Mode for LUT2 select */
typedef enum CCL_INTMODE2_enum
{
    CCL_INTMODE2_INTDISABLE_gc = (0x00<<4),  /* Interrupt disabled */
    CCL_INTMODE2_RISING_gc = (0x01<<4),  /* Sense rising edge */
    CCL_INTMODE2_FALLING_gc = (0x02<<4),  /* Sense falling edge */
    CCL_INTMODE2_BOTH_gc = (0x03<<4)  /* Sense both edges */
} CCL_INTMODE2_t;

/* Interrupt Mode for LUT3 select */
typedef enum CCL_INTMODE3_enum
{
    CCL_INTMODE3_INTDISABLE_gc = (0x00<<6),  /* Interrupt disabled */
    CCL_INTMODE3_RISING_gc = (0x01<<6),  /* Sense rising edge */
    CCL_INTMODE3_FALLING_gc = (0x02<<6),  /* Sense falling edge */
    CCL_INTMODE3_BOTH_gc = (0x03<<6)  /* Sense both edges */
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
    register8_t MCLKCTRLC;  /* MCLK Control C */
    register8_t MCLKINTCTRL;  /* MCLK Interrupt Control */
    register8_t MCLKINTFLAGS;  /* MCLK Interrupt Flags */
    register8_t MCLKSTATUS;  /* MCLK Status */
    register8_t MCLKTIMEBASE;  /* MCLK Timebase */
    register8_t reserved_1[1];
    register8_t OSCHFCTRLA;  /* OSCHF Control A */
    register8_t OSCHFTUNE;  /* OSCHF Tune */
    register8_t reserved_2[14];
    register8_t OSC32KCTRLA;  /* OSC32K Control A */
    register8_t reserved_3[3];
    register8_t XOSC32KCTRLA;  /* XOSC32K Control A */
    register8_t reserved_4[3];
    register8_t XOSCHFCTRLA;  /* XTALHF Control A */
    register8_t reserved_5[31];
} CLKCTRL_t;

/* Automatic Oscillator Tune select */
typedef enum CLKCTRL_AUTOTUNE_enum
{
    CLKCTRL_AUTOTUNE_OFF_gc = (0x00<<0),  /* Disabled */
    CLKCTRL_AUTOTUNE_XOSC32K_gc = (0x01<<0)  /* Tune against 32.768 kHz Crystal Oscillator */
} CLKCTRL_AUTOTUNE_t;

/* CFD Source select */
typedef enum CLKCTRL_CFDSRC_enum
{
    CLKCTRL_CFDSRC_CLKMAIN_gc = (0x00<<2),  /* Main Clock */
    CLKCTRL_CFDSRC_XOSCHF_gc = (0x01<<2),  /* High Frequency Crystal Oscillator */
    CLKCTRL_CFDSRC_XOSC32K_gc = (0x02<<2)  /* 32.768 kHz Crystal Oscillator */
} CLKCTRL_CFDSRC_t;

/* Clock select */
typedef enum CLKCTRL_CLKSEL_enum
{
    CLKCTRL_CLKSEL_OSCHF_gc = (0x00<<0),  /* Internal high-frequency oscillator */
    CLKCTRL_CLKSEL_OSC32K_gc = (0x01<<0),  /* Internal 32.768 kHz oscillator */
    CLKCTRL_CLKSEL_XOSC32K_gc = (0x02<<0),  /* 32.768 kHz crystal oscillator */
    CLKCTRL_CLKSEL_EXTCLK_gc = (0x03<<0)  /* External clock or XOSCHF */
} CLKCTRL_CLKSEL_t;

/* Crystal startup time select */
typedef enum CLKCTRL_CSUT_enum
{
    CLKCTRL_CSUT_1K_gc = (0x00<<4),  /* 1k cycles */
    CLKCTRL_CSUT_16K_gc = (0x01<<4),  /* 16k cycles */
    CLKCTRL_CSUT_32K_gc = (0x02<<4),  /* 32k cycles */
    CLKCTRL_CSUT_64K_gc = (0x03<<4)  /* 64k cycles */
} CLKCTRL_CSUT_t;

/* Crystal startup time select */
typedef enum CLKCTRL_CSUTHF_enum
{
    CLKCTRL_CSUTHF_256_gc = (0x00<<4),  /* 256 XOSCHF cycles */
    CLKCTRL_CSUTHF_1K_gc = (0x01<<4),  /* 1k XOSCHF cycles */
    CLKCTRL_CSUTHF_4K_gc = (0x02<<4)  /* 4k XOSCHF cycles */
} CLKCTRL_CSUTHF_t;

/* Interrupt Type select */
typedef enum CLKCTRL_INTTYPE_enum
{
    CLKCTRL_INTTYPE_INT_gc = (0x00<<7),  /* Regular interrupt */
    CLKCTRL_INTTYPE_NMI_gc = (0x01<<7)  /* Non-maskable interrupt */
} CLKCTRL_INTTYPE_t;

/* Prescaler B Division select */
typedef enum CLKCTRL_PBDIV_enum
{
    CLKCTRL_PBDIV_NONE_gc = (0x00<<5),  /* No Division. */
    CLKCTRL_PBDIV_DIV4_gc = (0x01<<5)  /* Divide by 4. */
} CLKCTRL_PBDIV_t;

/* Prescaler division select */
typedef enum CLKCTRL_PDIV_enum
{
    CLKCTRL_PDIV_DIV2_gc = (0x00<<1),  /* Divide by 2 */
    CLKCTRL_PDIV_DIV4_gc = (0x01<<1),  /* Divide by 4 */
    CLKCTRL_PDIV_DIV8_gc = (0x02<<1),  /* Divide by 8 */
    CLKCTRL_PDIV_DIV16_gc = (0x03<<1),  /* Divide by 16 */
    CLKCTRL_PDIV_DIV32_gc = (0x04<<1),  /* Divide by 32 */
    CLKCTRL_PDIV_DIV64_gc = (0x05<<1),  /* Divide by 64 */
    CLKCTRL_PDIV_DIV6_gc = (0x08<<1),  /* Divide by 6 */
    CLKCTRL_PDIV_DIV10_gc = (0x09<<1),  /* Divide by 10 */
    CLKCTRL_PDIV_DIV12_gc = (0x0A<<1),  /* Divide by 12 */
    CLKCTRL_PDIV_DIV24_gc = (0x0B<<1),  /* Divide by 24 */
    CLKCTRL_PDIV_DIV48_gc = (0x0C<<1)  /* Divide by 48 */
} CLKCTRL_PDIV_t;

/* Power mode select */
typedef enum CLKCTRL_PMODE_enum
{
    CLKCTRL_PMODE_LOW_gc = (0x00<<1),  /* Low Power Mode */
    CLKCTRL_PMODE_MEDIUM_gc = (0x01<<1),  /* Medium Power Mode */
    CLKCTRL_PMODE_HIGH_gc = (0x02<<1)  /* High Power Mode */
} CLKCTRL_PMODE_t;

/* Source Select */
typedef enum CLKCTRL_SEL_enum
{
    CLKCTRL_SEL_XTAL_gc = (0x00<<3),  /* External Crystal connected to the XTAL32K1 and XTAL32K2 pins */
    CLKCTRL_SEL_EXTCLK_gc = (0x01<<3)  /* External clock on XTAL32K1 pin */
} CLKCTRL_SEL_t;

/* External source select */
typedef enum CLKCTRL_SELHF_enum
{
    CLKCTRL_SELHF_XTAL_gc = (0x00<<1),  /* External Crystal */
    CLKCTRL_SELHF_EXTCLK_gc = (0x01<<1)  /* External clock on XTALHF1 pin */
} CLKCTRL_SELHF_t;

/*
--------------------------------------------------------------------------
CPU - CPU
--------------------------------------------------------------------------
*/

#define CORE_VERSION  V4S

/* CCP signature select */
typedef enum CCP_enum
{
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
    register8_t reserved_1[12];
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
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUSA;  /* Status A */
    register8_t SCANADR;  /* Scan Address */
    register8_t DATA;  /* Input Data */
    register8_t reserved_1[1];
    _DWORDREGISTER(CRC);  /* CRC Result */
    register8_t reserved_2[4];
} CRCSCAN_t;

/* CRC Mode Select */
typedef enum CRCSCAN_CRCSEL_enum
{
    CRCSCAN_CRCSEL_CRC16_gc = (0x00<<3),  /* The CRC is performed using CRC16 */
    CRCSCAN_CRCSEL_CRC32_gc = (0x01<<3)  /* The CRC is performed using CRC32 */
} CRCSCAN_CRCSEL_t;

/* Enable Periodic Timer select */
typedef enum CRCSCAN_PEREN_enum
{
    CRCSCAN_PEREN_DISABLE_gc = (0x00<<4),  /* The periodic timer is disabled */
    CRCSCAN_PEREN_ENABLE_gc = (0x01<<4)  /* The periodic timer is enabled */
} CRCSCAN_PEREN_t;

/* CRC Source select */
typedef enum CRCSCAN_SRC_enum
{
    CRCSCAN_SRC_BOOT_gc = (0x00<<5),  /* The CRC is performed on the boot section of Flash */
    CRCSCAN_SRC_CODE_gc = (0x01<<5),  /* The CRC is performed on the application code section of Flash */
    CRCSCAN_SRC_DATA_gc = (0x02<<5),  /* The CRC is performed on the application data section of Flash */
    CRCSCAN_SRC_MANUAL_gc = (0x03<<5)  /* Manual mode, CRC is performed on data written to DATA */
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
    register8_t EVCTRL;  /* Event Control */
    register8_t reserved_2[2];
    register8_t STATUS;  /* Status */
    _WORDREGISTER(DATA);  /* Data Register */
} DAC_t;

/* On and Off Event Input Enable select */
typedef enum DAC_ONOFFEI_enum
{
    DAC_ONOFFEI_ALWAYSON_gc = (0x00<<2),  /* DAC is always on */
    DAC_ONOFFEI_LEVEL_gc = (0x01<<2),  /* Level-triggered on/off. State controlled by ON event input. OFF event input is unused. */
    DAC_ONOFFEI_EDGE0_gc = (0x02<<2),  /* Edge triggered on/off. Separate event input for on and off. DAC is off before first event. */
    DAC_ONOFFEI_EDGE1_gc = (0x03<<2)  /* Edge triggered on/off. Separate event input for on and off. DAC is on before first event. */
} DAC_ONOFFEI_t;

/* Output Buffer Range select */
typedef enum DAC_OUTRANGE_enum
{
    DAC_OUTRANGE_AUTO_gc = (0x00<<4),  /* Output buffer automatically choose best range */
    DAC_OUTRANGE_LOW_gc = (0x02<<4),  /* Output buffer configured to low range */
    DAC_OUTRANGE_HIGH_gc = (0x03<<4)  /* Output buffer configured to high range */
} DAC_OUTRANGE_t;

/*
--------------------------------------------------------------------------
DIVA - Divide Accelerator
--------------------------------------------------------------------------
*/

/* Divide Accelerator */
typedef struct DIVA_struct
{
    register8_t DIVCTRL;  /* Divider Control */
    register8_t SHIFTCTRL;  /* Shift Control */
    register8_t reserved_1[1];
    register8_t STATUS;  /* Status */
    register8_t reserved_2[4];
    _DWORDREGISTER(DIVIDEND);  /* Dividend Value */
    _DWORDREGISTER(DIVISOR);  /* Divisor Value */
    _DWORDREGISTER(RESULT);  /* Result of Operation */
    _DWORDREGISTER(REMAINDER);  /* Remainder of Operation */
    register8_t reserved_3[8];
} DIVA_t;

/* Divide Operation select */
typedef enum DIVA_DIVOP_enum
{
    DIVA_DIVOP_DIV8_gc = (0x00<<0),  /* 8-bit division */
    DIVA_DIVOP_DIV16_gc = (0x01<<0),  /* 16-bit division */
    DIVA_DIVOP_DIV32_gc = (0x02<<0),  /* 32-bit division */
    DIVA_DIVOP_MOD8_gc = (0x04<<0),  /* 8-bit modulo */
    DIVA_DIVOP_MOD16_gc = (0x05<<0),  /* 16-bit modulo */
    DIVA_DIVOP_MOD32_gc = (0x06<<0)  /* 32-bit modulo */
} DIVA_DIVOP_t;

/* Shift operation select */
typedef enum DIVA_SHOP_enum
{
    DIVA_SHOP_ROR_gc = (0x00<<5),  /* Rotate right */
    DIVA_SHOP_LSL_gc = (0x01<<5),  /* Logical shift left. Vacated bits are cleared */
    DIVA_SHOP_LSR_gc = (0x02<<5),  /* Logical shift right. Vacated bits are cleared */
    DIVA_SHOP_ASR_gc = (0x03<<5)  /* Arithmetic shift right. Vacated bits are filled with sign bit. Register value is treated as two's complement signed values */
} DIVA_SHOP_t;

/* Signed Operation select */
typedef enum DIVA_SIGN_enum
{
    DIVA_SIGN_UNSIGNED_gc = (0x00<<6),  /* Unsigned operation */
    DIVA_SIGN_SIGNED_gc = (0x01<<6)  /* Signed operation */
} DIVA_SIGN_t;

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
    register8_t USERADC0START;  /* ADC0 Start */
    register8_t USERDAC0ENABLE;  /* DAC0 Enable */
    register8_t USERDAC0DISABLE;  /* DAC0 Disable */
    register8_t USERDAC0TRIG;  /* DAC0 Trigger new conversion */
    register8_t USEROPAMP0ENABLE;  /* OPAMP0 Enable */
    register8_t USEROPAMP0DISABLE;  /* OPAMP0 Disable */
    register8_t USEROPAMP0DUMP;  /* OPAMP0 Dump Integrator */
    register8_t USEROPAMP0DRIVE;  /* OPAMP0 Drive in Normal Mode */
    register8_t USEROPAMP1ENABLE;  /* OPAMP1 Enable */
    register8_t USEROPAMP1DISABLE;  /* OPAMP1 Disable */
    register8_t USEROPAMP1DUMP;  /* OPAMP1 Dump Integrator */
    register8_t USEROPAMP1DRIVE;  /* OPAMP1 Drive in Normal Mode */
    register8_t USEREVSYSEVOUTA;  /* EVOUTA */
    register8_t USEREVSYSEVOUTB;  /* EVOUTB */
    register8_t USEREVSYSEVOUTC;  /* EVOUTC */
    register8_t USEREVSYSEVOUTD;  /* EVOUTD */
    register8_t USEREVSYSEVOUTE;  /* EVOUTE */
    register8_t USEREVSYSEVOUTF;  /* EVOUTF */
    register8_t USERUSART0RXD;  /* USART0 RXD Event */
    register8_t USERUSART1RXD;  /* USART1 RXD Event */
    register8_t USERTCE0CNTA;  /* TCE0 Event A */
    register8_t USERTCE0CNTB;  /* TCE0 Event B */
    register8_t USERTCB0CAPT;  /* TCB0 Capture Event */
    register8_t USERTCB0COUNT;  /* TCB0 Count Event */
    register8_t USERTCB1CAPT;  /* TCB1 Capture Event */
    register8_t USERTCB1COUNT;  /* TCB1 Count Event */
    register8_t USERTCB2CAPT;  /* TCB2 Capture Event */
    register8_t USERTCB2COUNT;  /* TCB2 Count Event */
    register8_t USERTCB3CAPT;  /* TCB3 Capture Event */
    register8_t USERTCB3COUNT;  /* TCB3 Count Event */
    register8_t USERTCF0COUNT;  /* TCF0 Clock Event */
    register8_t USERTCF0ACTION;  /* TCF0 Action Event */
} EVSYS_t;

/* Channel generator select */
typedef enum EVSYS_CHANNEL_enum
{
    EVSYS_CHANNEL_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI SYNCH character */
    EVSYS_CHANNEL_MVIO_VDDIO2OK_gc = (0x05<<0),  /* VDDIO2 OK */
    EVSYS_CHANNEL_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL_RTC_EVGEN0_gc = (0x08<<0),  /* Event output 0 */
    EVSYS_CHANNEL_RTC_EVGEN1_gc = (0x09<<0),  /* Event output 1 */
    EVSYS_CHANNEL_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL_ADC0_RES_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL_ADC0_SAMP_gc = (0x25<<0),  /* ADC 0 Sample Ready */
    EVSYS_CHANNEL_ADC0_WCMP_gc = (0x26<<0),  /* ADC 0 Window Compare */
    EVSYS_CHANNEL_OPAMP0_READY_gc = (0x34<<0),  /* OPAMP 0 Ready */
    EVSYS_CHANNEL_OPAMP1_READY_gc = (0x35<<0),  /* OPAMP 1 Ready */
    EVSYS_CHANNEL_PORTA_EV0_gc = (0x40<<0),  /* Port A Event 0 */
    EVSYS_CHANNEL_PORTA_EV1_gc = (0x41<<0),  /* Port A Event 1 */
    EVSYS_CHANNEL_PORTB_EV0_gc = (0x42<<0),  /* Port B Event 0 */
    EVSYS_CHANNEL_PORTB_EV1_gc = (0x43<<0),  /* Port B Event 1 */
    EVSYS_CHANNEL_PORTC_EV0_gc = (0x44<<0),  /* Port C Event 0 */
    EVSYS_CHANNEL_PORTC_EV1_gc = (0x45<<0),  /* Port C Event 1 */
    EVSYS_CHANNEL_PORTD_EV0_gc = (0x46<<0),  /* Port D Event 0 */
    EVSYS_CHANNEL_PORTD_EV1_gc = (0x47<<0),  /* Port D Event 1 */
    EVSYS_CHANNEL_PORTE_EV0_gc = (0x48<<0),  /* Port E Event 0 */
    EVSYS_CHANNEL_PORTE_EV1_gc = (0x49<<0),  /* Port E Event 1 */
    EVSYS_CHANNEL_PORTF_EV0_gc = (0x4A<<0),  /* Port F Event 0 */
    EVSYS_CHANNEL_PORTF_EV1_gc = (0x4B<<0),  /* Port F Event 1 */
    EVSYS_CHANNEL_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL_TCE0_OVF_gc = (0x80<<0),  /* Timer/Counter E0 overflow */
    EVSYS_CHANNEL_TCE0_CMP0_gc = (0x84<<0),  /* Timer/Counter E0 compare 0 */
    EVSYS_CHANNEL_TCE0_CMP1_gc = (0x85<<0),  /* Timer/Counter E0 compare 1 */
    EVSYS_CHANNEL_TCE0_CMP2_gc = (0x86<<0),  /* Timer/Counter E0 compare 2 */
    EVSYS_CHANNEL_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL_TCB0_OVF_gc = (0xA1<<0),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL_TCB1_OVF_gc = (0xA3<<0),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL_TCB2_OVF_gc = (0xA5<<0),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL_TCB3_CAPT_gc = (0xA6<<0),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL_TCB3_OVF_gc = (0xA7<<0),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL_TCF0_OVF_gc = (0xB8<<0),  /* Timer/Counter F0 Overflow */
    EVSYS_CHANNEL_TCF0_CMP0_gc = (0xB9<<0),  /* Timer/Counter F0 compare 0 */
    EVSYS_CHANNEL_TCF0_CMP1_gc = (0xBA<<0),  /* Timer/Counter F0 compare 1 */
    EVSYS_CHANNEL_TCF0_CMP0ASY_gc = (0xBB<<0),  /* Timer/Counter F0 compare 0 asy */
    EVSYS_CHANNEL_TCF0_CMP1ASY_gc = (0xBC<<0)  /* Timer/Counter F0 compare 1 asy */
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
FUSE - Fuses
--------------------------------------------------------------------------
*/

/* Fuses */
typedef struct FUSE_struct
{
    register8_t WDTCFG;  /* Watchdog Configuration */
    register8_t BODCFG;  /* BOD Configuration */
    register8_t OSCCFG;  /* Oscillator Configuration */
    register8_t PINCFG;  /* Pin Configuration */
    register8_t HWMONCFG;  /* Hardware Configuration Monitor */
    register8_t SYSCFG0;  /* System Configuration 0 */
    register8_t SYSCFG1;  /* System Configuration 1 */
    register8_t CODESIZE;  /* Code Section Size */
    register8_t BOOTSIZE;  /* Boot Section Size */
    register8_t reserved_1[1];
    _WORDREGISTER(PDICFG);  /* UPDI Protection */
} FUSE_t;

/* avr-libc typedef for avr/fuse.h */
typedef FUSE_t NVM_FUSES_t;

/* BOD Operation in Active and Idle Sleep Modes select */
typedef enum ACTIVE_enum
{
    ACTIVE_DISABLE_gc = (0x00<<2),  /* Disabled */
    ACTIVE_ENABLED_gc = (0x01<<2),  /* Enabled in continuous mode */
    ACTIVE_SAMPLED_gc = (0x02<<2),  /* Enabled in sampled mode */
    ACTIVE_ENABLEWAIT_gc = (0x03<<2)  /* Enabled in continuous mode. Execution halted at wake-up until BOD is running */
} ACTIVE_t;

/* CPU hardware monitor select */
typedef enum CPUMON_enum
{
    CPUMON_DISABLE_gc = (0x00<<0),  /* Check for illegal opcode is disabled */
    CPUMON_ENABLE_gc = (0x01<<0)  /* Check for illegal opcode is enabled */
} CPUMON_t;

/* CRC polynomial selection */
typedef enum CRCSEL_enum
{
    CRCSEL_CRC16_gc = (0x00<<6),  /* Enable CRC16 */
    CRCSEL_CRC32_gc = (0x01<<6)  /* Enable CRC32 */
} CRCSEL_t;

/* PDI Protection Activation Key select */
typedef enum KEY_enum
{
    KEY_NOTACT_gc = (0x00<<4),  /* Not Active */
    KEY_NVMACT_gc = (0xB45<<4)  /* NVM Protection Active */
} KEY_t;

/* PDI Protection Level select */
typedef enum LEVEL_enum
{
    LEVEL_NVMACCDIS_gc = (0x02<<0),  /* NVM Access through UPDI disabled */
    LEVEL_BASIC_gc = (0x03<<0)  /* UPDI and UPDI pins working normally */
} LEVEL_t;

/* BOD Level select */
typedef enum LVL_enum
{
    LVL_BODLEVEL0_gc = (0x00<<5),  /* 1.75 V Only used for chip erase */
    LVL_BODLEVEL1_gc = (0x01<<5),  /* 1.9 V */
    LVL_BODLEVEL2_gc = (0x02<<5),  /* 2.6 V */
    LVL_BODLEVEL3_gc = (0x03<<5)  /* 4.3 V */
} LVL_t;

/* MVIO System Configuration select */
typedef enum MVSYSCFG_enum
{
    MVSYSCFG_DUAL_gc = (0x00<<2),  /* Device used in a dual supply configuration */
    MVSYSCFG_SINGLE_gc = (0x01<<2)  /* Device used in a single supply configuration */
} MVSYSCFG_t;

/* High-frequency Oscillator Frequency select */
typedef enum OSCHFFRQ_enum
{
    OSCHFFRQ_20M_gc = (0x00<<3),  /* OSCHF running at 20 MHz */
    OSCHFFRQ_16M_gc = (0x01<<3)  /* OSCHF running at 16 MHz */
} OSCHFFRQ_t;

/* Watchdog Timeout Period select */
typedef enum PERIOD_enum
{
    PERIOD_OFF_gc = (0x00<<0),  /* Off */
    PERIOD_8CLK_gc = (0x01<<0),  /* 8 cycles (8ms) */
    PERIOD_16CLK_gc = (0x02<<0),  /* 16 cycles (16ms) */
    PERIOD_32CLK_gc = (0x03<<0),  /* 32 cycles (32ms) */
    PERIOD_64CLK_gc = (0x04<<0),  /* 64 cycles (64ms) */
    PERIOD_128CLK_gc = (0x05<<0),  /* 128 cycles (0.128s) */
    PERIOD_256CLK_gc = (0x06<<0),  /* 256 cycles (0.256s) */
    PERIOD_512CLK_gc = (0x07<<0),  /* 512 cycles (0.512s) */
    PERIOD_1KCLK_gc = (0x08<<0),  /* 1K cycles (1.0s) */
    PERIOD_2KCLK_gc = (0x09<<0),  /* 2K cycles (2.0s) */
    PERIOD_4KCLK_gc = (0x0A<<0),  /* 4K cycles (4.1s) */
    PERIOD_8KCLK_gc = (0x0B<<0)  /* 8K cycles (8.2s) */
} PERIOD_t;

/* Configuration of Reset pin at startup select */
typedef enum RSTPINCFG_enum
{
    RSTPINCFG_INPUT_gc = (0x00<<0),  /* PF6 configures as input pin */
    RSTPINCFG_RESET_gc = (0x01<<0)  /* External reset with pull-up enabled on PF6 */
} RSTPINCFG_t;

/* BOD Sample Frequency select */
typedef enum SAMPFREQ_enum
{
    SAMPFREQ_128HZ_gc = (0x00<<4),  /* Sampling frequency is 128 Hz */
    SAMPFREQ_32HZ_gc = (0x01<<4)  /* Sample frequency is 32 Hz */
} SAMPFREQ_t;

/* BOD Operation in Power Down and Standby Sleep Modes select */
typedef enum SLEEP_enum
{
    SLEEP_DISABLE_gc = (0x00<<0),  /* Disabled */
    SLEEP_ENABLE_gc = (0x01<<0),  /* Enabled in continuous mode */
    SLEEP_SAMPLE_gc = (0x02<<0)  /* Enabled in sampled mode */
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

/* Configuration of UPDI pin at startup select */
typedef enum UPDIPINCFG_enum
{
    UPDIPINCFG_GPIO_gc = (0x00<<1),  /* UPDI pin is configured as GPIO */
    UPDIPINCFG_UPDI_gc = (0x01<<1)  /* UPDI pin is configured as UPDI pin with pull up enabled on PF7 */
} UPDIPINCFG_t;

/* Watchdog Window Timeout Period select */
typedef enum WINDOW_enum
{
    WINDOW_OFF_gc = (0x00<<4),  /* Off */
    WINDOW_8CLK_gc = (0x01<<4),  /* 8 cycles (8ms) */
    WINDOW_16CLK_gc = (0x02<<4),  /* 16 cycles (16ms) */
    WINDOW_32CLK_gc = (0x03<<4),  /* 32 cycles (32ms) */
    WINDOW_64CLK_gc = (0x04<<4),  /* 64 cycles (64ms) */
    WINDOW_128CLK_gc = (0x05<<4),  /* 128 cycles (0.128s) */
    WINDOW_256CLK_gc = (0x06<<4),  /* 256 cycles (0.256s) */
    WINDOW_512CLK_gc = (0x07<<4),  /* 512 cycles (0.512s) */
    WINDOW_1KCLK_gc = (0x08<<4),  /* 1K cycles (1.0s) */
    WINDOW_2KCLK_gc = (0x09<<4),  /* 2K cycles (2.0s) */
    WINDOW_4KCLK_gc = (0x0A<<4),  /* 4K cycles (4.1s) */
    WINDOW_8KCLK_gc = (0x0B<<4)  /* 8K cycles (8.2s) */
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
LOCK - Lockbits
--------------------------------------------------------------------------
*/

/* Lockbits */
typedef struct LOCK_struct
{
    _DWORDREGISTER(KEY);  /* Lock Key Bits */
} LOCK_t;

/* Lock Key select */
typedef enum LOCK_KEY_enum
{
    LOCK_KEY_NOLOCK_gc = (0x5CC5C55C<<0),  /* No locks */
    LOCK_KEY_RWLOCK_gc = (0xA33A3AA3<<0)  /* Read and write lock */
} LOCK_KEY_t;

/*
--------------------------------------------------------------------------
MVIO - Multi-Voltage I/O
--------------------------------------------------------------------------
*/

/* Multi-Voltage I/O */
typedef struct MVIO_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t reserved_1[1];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t reserved_2[11];
} MVIO_t;

/* Operation mode select */
typedef enum MVIO_MODE_enum
{
    MVIO_MODE_DUAL_gc = (0x00<<0),  /* MVIO operating in dual supply mode */
    MVIO_MODE_SINGLE_gc = (0x01<<0)  /* MIVIO operating in single supply mode */
} MVIO_MODE_t;

/* VDDIO2 Configuration select */
typedef enum MVIO_VDDIO2CFG_enum
{
    MVIO_VDDIO2CFG_NORMAL_gc = (0x00<<2),  /* VDDIO2 with voltage protection enabled */
    MVIO_VDDIO2CFG_LOWPOWER_gc = (0x01<<2),  /* VDDIO2 with voltage protection disabled */
    MVIO_VDDIO2CFG_VDDIO2OFF_gc = (0x02<<2)  /* VDDIO2 domain is disabled. I/O pins are not available */
} MVIO_VDDIO2CFG_t;

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
    register8_t CTRLC;  /* Control C */
    register8_t reserved_1[1];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t reserved_2[1];
    _WORDREGISTER(DATA);  /* Data */
    register8_t reserved_3[2];
    _DWORDREGISTER(ADDR);  /* Address */
    register8_t reserved_4[48];
} NVMCTRL_t;

/* Command select */
typedef enum NVMCTRL_CMD_enum
{
    NVMCTRL_CMD_NOCMD_gc = (0x00<<0),  /* No Command */
    NVMCTRL_CMD_NOOP_gc = (0x01<<0),  /* No Operation */
    NVMCTRL_CMD_FLPW_gc = (0x04<<0),  /* Flash Page Write */
    NVMCTRL_CMD_FLPERW_gc = (0x05<<0),  /* Flash Page Erase and Write */
    NVMCTRL_CMD_FLPER_gc = (0x08<<0),  /* Flash Page Erase */
    NVMCTRL_CMD_FLMPER2_gc = (0x09<<0),  /* Flash 2-page erase enable */
    NVMCTRL_CMD_FLMPER4_gc = (0x0A<<0),  /* Flash 4-page erase enable */
    NVMCTRL_CMD_FLMPER8_gc = (0x0B<<0),  /* Flash 8-page erase enable */
    NVMCTRL_CMD_FLMPER16_gc = (0x0C<<0),  /* Flash 16-page erase enable */
    NVMCTRL_CMD_FLMPER32_gc = (0x0D<<0),  /* Flash 32-page erase enable */
    NVMCTRL_CMD_FLPBCLR_gc = (0x0F<<0),  /* Flash Page Buffer Clear */
    NVMCTRL_CMD_EEPW_gc = (0x14<<0),  /* EEPROM Page Write */
    NVMCTRL_CMD_EEPERW_gc = (0x15<<0),  /* EEPROM Page Erase and Write */
    NVMCTRL_CMD_EEPER_gc = (0x17<<0),  /* EEPROM Page Erase */
    NVMCTRL_CMD_EEPBCLR_gc = (0x1F<<0),  /* EEPROM Page Buffer Clear */
    NVMCTRL_CMD_CHER_gc = (0x20<<0),  /* Chip Erase Command (UPDI only) */
    NVMCTRL_CMD_EECHER_gc = (0x30<<0)  /* EEPROM Erase Command (UPDI only) */
} NVMCTRL_CMD_t;

/* Write error select */
typedef enum NVMCTRL_ERROR_enum
{
    NVMCTRL_ERROR_NOERROR_gc = (0x00<<4),  /* No Error */
    NVMCTRL_ERROR_WRITEPROTECT_gc = (0x02<<4),  /* Attempt to program write protected area */
    NVMCTRL_ERROR_CMDCOLLISION_gc = (0x03<<4),  /* Selecting new write command while write command already seleted */
    NVMCTRL_ERROR_WRONGSECTION_gc = (0x04<<4)  /* Address cannot be written with selected command */
} NVMCTRL_ERROR_t;

/* Flash Mapping in Data space select */
typedef enum NVMCTRL_FLMAP_enum
{
    NVMCTRL_FLMAP_SECTION0_gc = (0x00<<4),  /* Flash section 0, 0 - 32KB */
    NVMCTRL_FLMAP_SECTION1_gc = (0x01<<4),  /* Flash section 1, 32 - 64KB */
    NVMCTRL_FLMAP_SECTION2_gc = (0x02<<4),  /* Flash section 2, 64 - 96KB */
    NVMCTRL_FLMAP_SECTION3_gc = (0x03<<4)  /* Flash section 3, 96 - 128KB */
} NVMCTRL_FLMAP_t;

/*
--------------------------------------------------------------------------
OPAMP - Operational Amplifier System
--------------------------------------------------------------------------
*/

/* Operational Amplifier System */
typedef struct OPAMP_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t reserved_1[14];
    register8_t OP0CTRLA;  /* Op Amp 0 Control A */
    register8_t OP0STATUS;  /* Op Amp 0 Status */
    register8_t OP0RESMUX;  /* Op Amp 0 Resistor Ladder Multiplexer */
    register8_t OP0INMUX;  /* Op Amp 0 Input Multiplexer */
    register8_t OP0SETTLE;  /* Op Amp 0 Settle */
    register8_t OP0CAL;  /* Op Amp 0 Calibration */
    register8_t reserved_2[2];
    register8_t OP1CTRLA;  /* Op Amp 1 Control A */
    register8_t OP1STATUS;  /* Op Amp 1 Status */
    register8_t OP1RESMUX;  /* Op Amp 1 Resistor Ladder Multiplexer */
    register8_t OP1INMUX;  /* Op Amp 1 Input Multiplexer */
    register8_t OP1SETTLE;  /* Op Amp 1 Settle */
    register8_t OP1CAL;  /* Op Amp 1 Calibration */
    register8_t reserved_3[34];
} OPAMP_t;

/* Output Mode select */
typedef enum OPAMP_OP0CTRLA_OUTMODE_enum
{
    OPAMP_OP0CTRLA_OUTMODE_OFF_gc = (0x00<<2),  /* Output Driver Off */
    OPAMP_OP0CTRLA_OUTMODE_NORMAL_gc = (0x01<<2)  /* Output Driver in Normal Mode */
} OPAMP_OP0CTRLA_OUTMODE_t;

/* Negative Input Multiplexer select */
typedef enum OPAMP_OP0INMUX_MUXNEG_enum
{
    OPAMP_OP0INMUX_MUXNEG_INN0_gc = (0x00<<4),  /* Negative input pin 0 for OPn */
    OPAMP_OP0INMUX_MUXNEG_WIP_gc = (0x01<<4),  /* Wiper from OPn's resistor ladder */
    OPAMP_OP0INMUX_MUXNEG_INN1_gc = (0x02<<4),  /* Negative input pin 1 for OPn, DAC0 output */
    OPAMP_OP0INMUX_MUXNEG_GND_gc = (0x03<<4),  /* Ground */
    OPAMP_OP0INMUX_MUXNEG_VDDDIV2_gc = (0x04<<4),  /* VDD/2 */
    OPAMP_OP0INMUX_MUXNEG_OUT_gc = (0x05<<4)  /* OPn output (unity gain) */
} OPAMP_OP0INMUX_MUXNEG_t;

/* Positive Input Multiplexer select */
typedef enum OPAMP_OP0INMUX_MUXPOS_enum
{
    OPAMP_OP0INMUX_MUXPOS_INP0_gc = (0x00<<0),  /* Positive input pin 0 for OPn */
    OPAMP_OP0INMUX_MUXPOS_WIP_gc = (0x01<<0),  /* Wiper from OPn's resistor ladder */
    OPAMP_OP0INMUX_MUXPOS_INP1_gc = (0x02<<0),  /* Positive input pin 1 for OPn, DAC0 output */
    OPAMP_OP0INMUX_MUXPOS_GND_gc = (0x03<<0),  /* Ground */
    OPAMP_OP0INMUX_MUXPOS_VDDDIV2_gc = (0x04<<0),  /* VDD/2 */
    OPAMP_OP0INMUX_MUXPOS_LINKOUT_gc = (0x05<<0),  /* OP[n-1] output */
    OPAMP_OP0INMUX_MUXPOS_INP2_gc = (0x07<<0),  /* Positive input pin 2 for OPn */
    OPAMP_OP0INMUX_MUXPOS_DAC0UB_gc = (0x08<<0),  /* DAC0 output unbuffered */
    OPAMP_OP0INMUX_MUXPOS_PGAPOS_gc = (0x0A<<0),  /* PGA positive output */
    OPAMP_OP0INMUX_MUXPOS_PGANEG_gc = (0x0B<<0)  /* PGA negative output */
} OPAMP_OP0INMUX_MUXPOS_t;

/* Multiplexer Bottom select */
typedef enum OPAMP_OP0RESMUX_MUXBOT_enum
{
    OPAMP_OP0RESMUX_MUXBOT_OFF_gc = (0x00<<2),  /* Multiplexer off */
    OPAMP_OP0RESMUX_MUXBOT_INP0_gc = (0x01<<2),  /* Positive input pin 0 for OPn */
    OPAMP_OP0RESMUX_MUXBOT_INN0_gc = (0x02<<2),  /* Negative input pin 0 for OPn */
    OPAMP_OP0RESMUX_MUXBOT_INP1_gc = (0x03<<2),  /* Positive input pin 1 for OPn, DAC0 Output */
    OPAMP_OP0RESMUX_MUXBOT_LINKOUT_gc = (0x04<<2),  /* Link OP[n-1] output */
    OPAMP_OP0RESMUX_MUXBOT_GND_gc = (0x05<<2),  /* Ground */
    OPAMP_OP0RESMUX_MUXBOT_INP2_gc = (0x07<<2)  /* Positive input pin 2 for OPn */
} OPAMP_OP0RESMUX_MUXBOT_t;

/* Multiplexer Top select */
typedef enum OPAMP_OP0RESMUX_MUXTOP_enum
{
    OPAMP_OP0RESMUX_MUXTOP_OFF_gc = (0x00<<0),  /* Multiplexer off */
    OPAMP_OP0RESMUX_MUXTOP_OUT_gc = (0x01<<0),  /* OPn output */
    OPAMP_OP0RESMUX_MUXTOP_VDD_gc = (0x02<<0)  /* VDD */
} OPAMP_OP0RESMUX_MUXTOP_t;

/* Multiplexer Wiper selector */
typedef enum OPAMP_OP0RESMUX_MUXWIP_enum
{
    OPAMP_OP0RESMUX_MUXWIP_WIP0_gc = (0x00<<5),  /* R1 = 15R, R2 = 1R, R2/R1 = 0.07 */
    OPAMP_OP0RESMUX_MUXWIP_WIP1_gc = (0x01<<5),  /* R1 = 14R, R2 = 2R, R2/R1 = 0.14 */
    OPAMP_OP0RESMUX_MUXWIP_WIP2_gc = (0x02<<5),  /* R1 = 12R, R2 = 4R, R2/R1 = 0.33 */
    OPAMP_OP0RESMUX_MUXWIP_WIP3_gc = (0x03<<5),  /* R1 = 8R, R2 = 8R, R2/R1 = 1 */
    OPAMP_OP0RESMUX_MUXWIP_WIP4_gc = (0x04<<5),  /* R1 = 6R, R2 = 10R, R2/R1 = 1.67 */
    OPAMP_OP0RESMUX_MUXWIP_WIP5_gc = (0x05<<5),  /* R1 = 4R, R2 = 12R, R2/R1 = 3 */
    OPAMP_OP0RESMUX_MUXWIP_WIP6_gc = (0x06<<5),  /* R1 = 2R, R2 = 14R, R2/R1 = 7 */
    OPAMP_OP0RESMUX_MUXWIP_WIP7_gc = (0x07<<5)  /* R1 = 1R, R2 = 15R, R2/R1 = 15 */
} OPAMP_OP0RESMUX_MUXWIP_t;

/* Calibration ongoing select */
typedef enum OPAMP_OP0STATUS_CALBUSY_enum
{
    OPAMP_OP0STATUS_CALBUSY_OFF_gc = (0x00<<4),  /* No calibration started or completed */
    OPAMP_OP0STATUS_CALBUSY_RUNNING_gc = (0x01<<4)  /* Self calibration is running */
} OPAMP_OP0STATUS_CALBUSY_t;

/* Output Mode select */
typedef enum OPAMP_OP1CTRLA_OUTMODE_enum
{
    OPAMP_OP1CTRLA_OUTMODE_OFF_gc = (0x00<<2),  /* Output Driver Off */
    OPAMP_OP1CTRLA_OUTMODE_NORMAL_gc = (0x01<<2)  /* Output Driver in Normal Mode */
} OPAMP_OP1CTRLA_OUTMODE_t;

/* Negative Input Multiplexer select */
typedef enum OPAMP_OP1INMUX_MUXNEG_enum
{
    OPAMP_OP1INMUX_MUXNEG_INN0_gc = (0x00<<4),  /* Negative input pin 0 for OPn */
    OPAMP_OP1INMUX_MUXNEG_WIP_gc = (0x01<<4),  /* Wiper from OPn's resistor ladder */
    OPAMP_OP1INMUX_MUXNEG_INN1_gc = (0x02<<4),  /* Negative input pin 1 for OPn, DAC0 output */
    OPAMP_OP1INMUX_MUXNEG_GND_gc = (0x03<<4),  /* Ground */
    OPAMP_OP1INMUX_MUXNEG_VDDDIV2_gc = (0x04<<4),  /* VDD/2 */
    OPAMP_OP1INMUX_MUXNEG_OUT_gc = (0x05<<4)  /* OPn output (unity gain) */
} OPAMP_OP1INMUX_MUXNEG_t;

/* Positive Input Multiplexer select */
typedef enum OPAMP_OP1INMUX_MUXPOS_enum
{
    OPAMP_OP1INMUX_MUXPOS_INP0_gc = (0x00<<0),  /* Positive input pin 0 for OPn */
    OPAMP_OP1INMUX_MUXPOS_WIP_gc = (0x01<<0),  /* Wiper from OPn's resistor ladder */
    OPAMP_OP1INMUX_MUXPOS_INP1_gc = (0x02<<0),  /* Positive input pin 1 for OPn, DAC0 output */
    OPAMP_OP1INMUX_MUXPOS_GND_gc = (0x03<<0),  /* Ground */
    OPAMP_OP1INMUX_MUXPOS_VDDDIV2_gc = (0x04<<0),  /* VDD/2 */
    OPAMP_OP1INMUX_MUXPOS_LINKOUT_gc = (0x05<<0),  /* OP[n-1] output */
    OPAMP_OP1INMUX_MUXPOS_INP2_gc = (0x07<<0),  /* Positive input pin 2 for OPn */
    OPAMP_OP1INMUX_MUXPOS_DAC0UB_gc = (0x08<<0),  /* DAC0 output unbuffered */
    OPAMP_OP1INMUX_MUXPOS_PGAPOS_gc = (0x0A<<0),  /* PGA positive output */
    OPAMP_OP1INMUX_MUXPOS_PGANEG_gc = (0x0B<<0)  /* PGA negative output */
} OPAMP_OP1INMUX_MUXPOS_t;

/* Multiplexer Bottom select */
typedef enum OPAMP_OP1RESMUX_MUXBOT_enum
{
    OPAMP_OP1RESMUX_MUXBOT_OFF_gc = (0x00<<2),  /* Multiplexer off */
    OPAMP_OP1RESMUX_MUXBOT_INP0_gc = (0x01<<2),  /* Positive input pin 0 for OPn */
    OPAMP_OP1RESMUX_MUXBOT_INN0_gc = (0x02<<2),  /* Negative input pin 0 for OPn */
    OPAMP_OP1RESMUX_MUXBOT_INP1_gc = (0x03<<2),  /* Positive input pin 1 for OPn, DAC0 Output */
    OPAMP_OP1RESMUX_MUXBOT_LINKOUT_gc = (0x04<<2),  /* Link OP[n-1] output */
    OPAMP_OP1RESMUX_MUXBOT_GND_gc = (0x05<<2),  /* Ground */
    OPAMP_OP1RESMUX_MUXBOT_INP2_gc = (0x07<<2)  /* Positive input pin 2 for OPn */
} OPAMP_OP1RESMUX_MUXBOT_t;

/* Multiplexer Top select */
typedef enum OPAMP_OP1RESMUX_MUXTOP_enum
{
    OPAMP_OP1RESMUX_MUXTOP_OFF_gc = (0x00<<0),  /* Multiplexer off */
    OPAMP_OP1RESMUX_MUXTOP_OUT_gc = (0x01<<0),  /* OPn output */
    OPAMP_OP1RESMUX_MUXTOP_VDD_gc = (0x02<<0)  /* VDD */
} OPAMP_OP1RESMUX_MUXTOP_t;

/* Multiplexer Wiper selector */
typedef enum OPAMP_OP1RESMUX_MUXWIP_enum
{
    OPAMP_OP1RESMUX_MUXWIP_WIP0_gc = (0x00<<5),  /* R1 = 15R, R2 = 1R, R2/R1 = 0.07 */
    OPAMP_OP1RESMUX_MUXWIP_WIP1_gc = (0x01<<5),  /* R1 = 14R, R2 = 2R, R2/R1 = 0.14 */
    OPAMP_OP1RESMUX_MUXWIP_WIP2_gc = (0x02<<5),  /* R1 = 12R, R2 = 4R, R2/R1 = 0.33 */
    OPAMP_OP1RESMUX_MUXWIP_WIP3_gc = (0x03<<5),  /* R1 = 8R, R2 = 8R, R2/R1 = 1 */
    OPAMP_OP1RESMUX_MUXWIP_WIP4_gc = (0x04<<5),  /* R1 = 6R, R2 = 10R, R2/R1 = 1.67 */
    OPAMP_OP1RESMUX_MUXWIP_WIP5_gc = (0x05<<5),  /* R1 = 4R, R2 = 12R, R2/R1 = 3 */
    OPAMP_OP1RESMUX_MUXWIP_WIP6_gc = (0x06<<5),  /* R1 = 2R, R2 = 14R, R2/R1 = 7 */
    OPAMP_OP1RESMUX_MUXWIP_WIP7_gc = (0x07<<5)  /* R1 = 1R, R2 = 15R, R2/R1 = 15 */
} OPAMP_OP1RESMUX_MUXWIP_t;

/* Calibration ongoing select */
typedef enum OPAMP_OP1STATUS_CALBUSY_enum
{
    OPAMP_OP1STATUS_CALBUSY_OFF_gc = (0x00<<4),  /* No calibration started or completed */
    OPAMP_OP1STATUS_CALBUSY_RUNNING_gc = (0x01<<4)  /* Self calibration is running */
} OPAMP_OP1STATUS_CALBUSY_t;

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
    register8_t EVGENCTRLA;  /* Event Generation Control A */
    register8_t reserved_2[7];
} PORT_t;

/* Event Generator 0 Select */
typedef enum PORT_EVGEN0SEL_enum
{
    PORT_EVGEN0SEL_PIN0_gc = (0x00<<0),  /* Pin 0 used as event generator */
    PORT_EVGEN0SEL_PIN1_gc = (0x01<<0),  /* Pin 1 used as event generator */
    PORT_EVGEN0SEL_PIN2_gc = (0x02<<0),  /* Pin 2 used as event generator */
    PORT_EVGEN0SEL_PIN3_gc = (0x03<<0),  /* Pin 3 used as event generator */
    PORT_EVGEN0SEL_PIN4_gc = (0x04<<0),  /* Pin 4 used as event generator */
    PORT_EVGEN0SEL_PIN5_gc = (0x05<<0),  /* Pin 5 used as event generator */
    PORT_EVGEN0SEL_PIN6_gc = (0x06<<0),  /* Pin 6 used as event generator */
    PORT_EVGEN0SEL_PIN7_gc = (0x07<<0)  /* Pin 7 used as event generator */
} PORT_EVGEN0SEL_t;

/* Event Generator 1 Select */
typedef enum PORT_EVGEN1SEL_enum
{
    PORT_EVGEN1SEL_PIN0_gc = (0x00<<4),  /* Pin 0 used as event generator */
    PORT_EVGEN1SEL_PIN1_gc = (0x01<<4),  /* Pin 1 used as event generator */
    PORT_EVGEN1SEL_PIN2_gc = (0x02<<4),  /* Pin 2 used as event generator */
    PORT_EVGEN1SEL_PIN3_gc = (0x03<<4),  /* Pin 3 used as event generator */
    PORT_EVGEN1SEL_PIN4_gc = (0x04<<4),  /* Pin 4 used as event generator */
    PORT_EVGEN1SEL_PIN5_gc = (0x05<<4),  /* Pin 5 used as event generator */
    PORT_EVGEN1SEL_PIN6_gc = (0x06<<4),  /* Pin 6 used as event generator */
    PORT_EVGEN1SEL_PIN7_gc = (0x07<<4)  /* Pin 7 used as event generator */
} PORT_EVGEN1SEL_t;

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
    register8_t ACROUTEA;  /* AC route A */
    register8_t reserved_3[1];
    register8_t TCFROUTE;  /* TCF Route A */
    register8_t reserved_4[19];
} PORTMUX_t;

/* Analog Comparator 0 Output select */
typedef enum PORTMUX_AC0_enum
{
    PORTMUX_AC0_DEFAULT_gc = (0x00<<0),  /* OUT: PA7 */
    PORTMUX_AC0_ALT1_gc = (0x01<<0)  /* OUT: PC6 */
} PORTMUX_AC0_t;

/* Event Output A select */
typedef enum PORTMUX_EVOUTA_enum
{
    PORTMUX_EVOUTA_DEFAULT_gc = (0x00<<0),  /* EVOUTA: PA2 */
    PORTMUX_EVOUTA_ALT1_gc = (0x01<<0)  /* EVOUTA: PA7 */
} PORTMUX_EVOUTA_t;

/* Event Output C select */
typedef enum PORTMUX_EVOUTC_enum
{
    PORTMUX_EVOUTC_DEFAULT_gc = (0x00<<2),  /* EVOUTC: PC2 */
    PORTMUX_EVOUTC_ALT1_gc = (0x01<<2)  /* EVOUTC: PC7 */
} PORTMUX_EVOUTC_t;

/* Event Output D select */
typedef enum PORTMUX_EVOUTD_enum
{
    PORTMUX_EVOUTD_DEFAULT_gc = (0x00<<3),  /* EVOUTD: PD2 */
    PORTMUX_EVOUTD_ALT1_gc = (0x01<<3)  /* EVOUTD: PD7 */
} PORTMUX_EVOUTD_t;

/* Event Output F select */
typedef enum PORTMUX_EVOUTF_enum
{
    PORTMUX_EVOUTF_DEFAULT_gc = (0x00<<5),  /* EVOUTF: PF2 */
    PORTMUX_EVOUTF_ALT1_gc = (0x01<<5)  /* EVOUTF: PF7 */
} PORTMUX_EVOUTF_t;

/* CCL Look-Up Table 0 Signals select */
typedef enum PORTMUX_LUT0_enum
{
    PORTMUX_LUT0_DEFAULT_gc = (0x00<<0),  /* In: PA0, PA1, PA2. Out: PA3. */
    PORTMUX_LUT0_ALT1_gc = (0x01<<0)  /* In: PA0, PA1, PA2. Out: PA6. */
} PORTMUX_LUT0_t;

/* CCL Look-Up Table 1 Signals select */
typedef enum PORTMUX_LUT1_enum
{
    PORTMUX_LUT1_DEFAULT_gc = (0x00<<1),  /* In: PC0, PC1, PC2. Out: PC3. */
    PORTMUX_LUT1_ALT1_gc = (0x01<<1)  /* In: PC0, PC1, PC2. Out: PC6. */
} PORTMUX_LUT1_t;

/* CCL Look-Up Table 2 Signals select */
typedef enum PORTMUX_LUT2_enum
{
    PORTMUX_LUT2_DEFAULT_gc = (0x00<<2),  /* In: PD0, PD1, PD2. Out: PD3. */
    PORTMUX_LUT2_ALT1_gc = (0x01<<2)  /* In: PD0, PD1, PD2. Out: PD6. */
} PORTMUX_LUT2_t;

/* SPI0 Signals select */
typedef enum PORTMUX_SPI0_enum
{
    PORTMUX_SPI0_DEFAULT_gc = (0x00<<0),  /* MOSI: PA4, MISO: PA5, SCK: PA6, SS: PA7 */
    PORTMUX_SPI0_ALT1_gc = (0x01<<0),  /* MOSI: PE0, MISO: PE1, SCK: PE2, SS: PE3 */
    PORTMUX_SPI0_ALT3_gc = (0x03<<0),  /* MOSI: PA0, MISO: PA1, SCK: PC0, SS: PC1 */
    PORTMUX_SPI0_ALT4_gc = (0x04<<0),  /* MOSI: PD4, MISO: PD5, SCK: PD6, SS: PD7 */
    PORTMUX_SPI0_ALT5_gc = (0x05<<0),  /* MOSI: PC0, MISO: PC1, SCK: PC2, SS: PC3 */
    PORTMUX_SPI0_ALT6_gc = (0x06<<0),  /* MOSI: PC1, MISO: PC2, SCK: PC3, SS: PF7 */
    PORTMUX_SPI0_NONE_gc = (0x07<<0)  /* Not connected to any pins */
} PORTMUX_SPI0_t;

/* TCB0 Output select */
typedef enum PORTMUX_TCB0_enum
{
    PORTMUX_TCB0_DEFAULT_gc = (0x00<<0),  /* WO: PA2 */
    PORTMUX_TCB0_ALT1_gc = (0x01<<0)  /* WO: PF4 */
} PORTMUX_TCB0_t;

/* TCB1 Output select */
typedef enum PORTMUX_TCB1_enum
{
    PORTMUX_TCB1_DEFAULT_gc = (0x00<<1),  /* WO: PA3 */
    PORTMUX_TCB1_ALT1_gc = (0x01<<1)  /* WO: PF5 */
} PORTMUX_TCB1_t;

/* TCB2 Output select */
typedef enum PORTMUX_TCB2_enum
{
    PORTMUX_TCB2_DEFAULT_gc = (0x00<<2),  /* WO: PC0 */
    PORTMUX_TCB2_ALT1_gc = (0x01<<2)  /* WO: PB4 */
} PORTMUX_TCB2_t;

/* TCB3 Output select */
typedef enum PORTMUX_TCB3_enum
{
    PORTMUX_TCB3_DEFAULT_gc = (0x00<<3),  /* WO: PB5 */
    PORTMUX_TCB3_ALT1_gc = (0x01<<3)  /* WO: PC1 */
} PORTMUX_TCB3_t;

/* TCE0 Signals select */
typedef enum PORTMUX_TCE0_enum
{
    PORTMUX_TCE0_PORTA_gc = (0x00<<0),  /* WOn: PA0, PA1, PA2 */
    PORTMUX_TCE0_PORTB_gc = (0x01<<0),  /* WOn: PB0, PB1, PB2 */
    PORTMUX_TCE0_PORTC_gc = (0x02<<0),  /* WOn: PC0, PC1, PC2 */
    PORTMUX_TCE0_PORTD_gc = (0x03<<0),  /* WOn: PD0, PD1, PD2 */
    PORTMUX_TCE0_PORTE_gc = (0x04<<0),  /* WOn: PE0, PE1, PE2 */
    PORTMUX_TCE0_PORTF_gc = (0x05<<0)  /* WOn: PF0, PF1, PF2 */
} PORTMUX_TCE0_t;

/* TCF0 Output select */
typedef enum PORTMUX_TCF0_enum
{
    PORTMUX_TCF0_DEFAULT_gc = (0x00<<0),  /* WOn: PA0, PA1 */
    PORTMUX_TCF0_ALT1_gc = (0x01<<0),  /* WOn: PA6, PA7 */
    PORTMUX_TCF0_ALT2_gc = (0x02<<0)  /* WOn: PF4, PF5 */
} PORTMUX_TCF0_t;

/* TWI0 Signals select */
typedef enum PORTMUX_TWI0_enum
{
    PORTMUX_TWI0_DEFAULT_gc = (0x00<<0),  /* SDA: PA2, SCL: PA3. Dual mode: SDA: PC2, SCL: PC3. */
    PORTMUX_TWI0_ALT1_gc = (0x01<<0),  /* SDA: PA2, SCL: PA3. Dual mode: SDA: PC6, SCL: PC7. */
    PORTMUX_TWI0_ALT2_gc = (0x02<<0),  /* SDA: PC2, SCL: PC3. Dual mode: SDA: PC6, SCL: PC7. */
    PORTMUX_TWI0_ALT3_gc = (0x03<<0)  /* SDA: PA0, SCL: PA1. Dual mode: SDA: PC2, SCL: PC3. */
} PORTMUX_TWI0_t;

/* USART0 Routing select */
typedef enum PORTMUX_USART0_enum
{
    PORTMUX_USART0_DEFAULT_gc = (0x00<<0),  /* TxD: PA0, RxD: PA1, AUX0: PA2, AUX1: PA3 */
    PORTMUX_USART0_ALT1_gc = (0x01<<0),  /* TxD: PA4, RxD: PA5, AUX0: PA6, AUX1: PA7 */
    PORTMUX_USART0_ALT2_gc = (0x02<<0),  /* TxD: PA2, RxD: PA3, AUX0: -, AUX1: - */
    PORTMUX_USART0_ALT3_gc = (0x03<<0),  /* TxD: PD4, RxD: PD5, AUX0: PD6, AUX1: PD7 */
    PORTMUX_USART0_ALT4_gc = (0x04<<0),  /* TxD: PC1, RxD: PC2, AUX0: PC3, AUX1: - */
    PORTMUX_USART0_NONE_gc = (0x07<<0)  /* Not connected to any pins */
} PORTMUX_USART0_t;

/* USART1 Routing select */
typedef enum PORTMUX_USART1_enum
{
    PORTMUX_USART1_DEFAULT_gc = (0x00<<3),  /* TxD: PC0, RxD: PC1, AUX0: PC2, AUX1: PC3 */
    PORTMUX_USART1_ALT1_gc = (0x01<<3),  /* TxD: PC4, RxD: PC5, AUX0: PC6, AUX1: PC7 */
    PORTMUX_USART1_ALT2_gc = (0x02<<3),  /* TxD: PD6, RxD: PD7, AUX0: -, AUX1: - */
    PORTMUX_USART1_NONE_gc = (0x03<<3)  /* Not connected to any pins */
} PORTMUX_USART1_t;

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
    register8_t reserved_1[14];
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
    register8_t ACREFRISE;  /* AC Reference Scaler Rise */
    register8_t ACREFFALL;  /* AC Reference Scaler Fall */
    register8_t reserved_2[6];
    register8_t SERNUM0;  /* Serial Number Byte 0 */
    register8_t SERNUM1;  /* Serial Number Byte 1 */
    register8_t SERNUM2;  /* Serial Number Byte 2 */
    register8_t SERNUM3;  /* Serial Number Byte 3 */
    register8_t SERNUM4;  /* Serial Number Byte 4 */
    register8_t SERNUM5;  /* Serial Number Byte 5 */
    register8_t SERNUM6;  /* Serial Number Byte 6 */
    register8_t SERNUM7;  /* Serial Number Byte 7 */
    register8_t SERNUM8;  /* Serial Number Byte 8 */
    register8_t SERNUM9;  /* Serial Number Byte 9 */
    register8_t SERNUM10;  /* Serial Number Byte 10 */
    register8_t SERNUM11;  /* Serial Number Byte 11 */
    register8_t SERNUM12;  /* Serial Number Byte 12 */
    register8_t SERNUM13;  /* Serial Number Byte 13 */
    register8_t SERNUM14;  /* Serial Number Byte 14 */
    register8_t SERNUM15;  /* Serial Number Byte 15 */
    register8_t reserved_3[96];
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
    register8_t reserved_1[15];
} SLPCTRL_t;

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
    register8_t reserved_1[11];
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
    SPI_PRESC_DIV4_gc = (0x00<<1),  /* CLK_PER / 4 */
    SPI_PRESC_DIV16_gc = (0x01<<1),  /* CLK_PER / 16 */
    SPI_PRESC_DIV64_gc = (0x02<<1),  /* CLK_PER / 64 */
    SPI_PRESC_DIV128_gc = (0x03<<1)  /* CLK_PER / 128 */
} SPI_PRESC_t;

/*
--------------------------------------------------------------------------
SYSCFG - System Configuration Registers
--------------------------------------------------------------------------
*/

/* System Configuration Registers */
typedef struct SYSCFG_struct
{
    register8_t reserved_1[1];
    register8_t REVID;  /* Revision ID */
    register8_t reserved_2[5];
    register8_t VDDCTRL;  /* VDD Range Control */
    register8_t reserved_3[24];
} SYSCFG_t;

/* VDDIO2 Range select */
typedef enum SYSCFG_VDDIO2R_enum
{
    SYSCFG_VDDIO2R_LOW_gc = (0x00<<1),  /* VDD in range 1.8V to 3.6V */
    SYSCFG_VDDIO2R_HIGH_gc = (0x01<<1)  /* VDD in range 2.4V to 5.5V */
} SYSCFG_VDDIO2R_t;

/* VDD Range select */
typedef enum SYSCFG_VDDR_enum
{
    SYSCFG_VDDR_LOW_gc = (0x00<<0),  /* VDD in range 1.8V to 3.6V */
    SYSCFG_VDDR_HIGH_gc = (0x01<<0)  /* VDD in range 2.4V to 5.5V */
} SYSCFG_VDDR_t;

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
    TCB_CLKSEL_DIV8_gc = (0x02<<1),  /* CLK_PER/8 */
    TCB_CLKSEL_DIV64_gc = (0x03<<1),  /* CLK_PER/64 */
    TCB_CLKSEL_DIV1024_gc = (0x04<<1),  /* CLK_PER/1024 */
    TCB_CLKSEL_TCE0_gc = (0x05<<1),  /* Use CLK_TCE from TCE0 */
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
    register8_t reserved_1[1];
    register8_t CTRLECLR;  /* Control E Clear */
    register8_t CTRLESET;  /* Control E Set */
    register8_t CTRLFCLR;  /* Control F Clear */
    register8_t CTRLFSET;  /* Control F Set */
    register8_t EVGENCTRL;  /* Event Generation Control */
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_2[2];
    register8_t DBGCTRL;  /* Debug Control */
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
    TCE_CMP0EV_WAVEFORM_gc = (0x01<<4)  /* Event output for CMP is equal to waveform */
} TCE_CMP0EV_t;

/* Compare # Event select */
typedef enum TCE_CMP1EV_enum
{
    TCE_CMP1EV_PULSE_gc = (0x00<<5),  /* Event output for CMP is a pulse */
    TCE_CMP1EV_WAVEFORM_gc = (0x01<<5)  /* Event output for CMP is equal to waveform */
} TCE_CMP1EV_t;

/* Compare # Event select */
typedef enum TCE_CMP2EV_enum
{
    TCE_CMP2EV_PULSE_gc = (0x00<<6),  /* Event output for CMP is a pulse */
    TCE_CMP2EV_WAVEFORM_gc = (0x01<<6)  /* Event output for CMP is equal to waveform */
} TCE_CMP2EV_t;

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
    register8_t CTRLE;  /* Control E */
    register8_t reserved_1[1];
    register8_t EVCTRL;  /* Event Control */
    register8_t reserved_2[1];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t reserved_3[2];
    register8_t DBGCTRL;  /* Debug Control */
    register8_t reserved_4[2];
    _DWORDREGISTER(CNT);  /* Count */
    _DWORDREGISTER(CMP);  /* Compare */
    register8_t reserved_5[8];
} TCF_t;

/* Clock Select */
typedef enum TCF_CLKSEL_enum
{
    TCF_CLKSEL_CLKPER_gc = (0x00<<3),  /* Peripheral Clock */
    TCF_CLKSEL_EVENT_gc = (0x01<<3),  /* Event as clock source */
    TCF_CLKSEL_OSCHF_gc = (0x02<<3),  /* Internal High Frequency Oscillator */
    TCF_CLKSEL_OSC32K_gc = (0x03<<3),  /* Internal 32.768 kHz Oscillator */
    TCF_CLKSEL_XOSCHF_gc = (0x04<<3),  /* High Frequency Crystal Oscillator */
    TCF_CLKSEL_XOSC32K_gc = (0x05<<3)  /* 32.768 kHz Crystal Oscillator */
} TCF_CLKSEL_t;

/* Command select */
typedef enum TCF_CMD_enum
{
    TCF_CMD_NONE_gc = (0x00<<0),  /* No command */
    TCF_CMD_UPDATE_gc = (0x01<<0),  /* Force synchronization update */
    TCF_CMD_RESTART_gc = (0x02<<0),  /* Force restart of counter */
    TCF_CMD_CAPTURE_gc = (0x04<<0),  /* Force capture of current counter value. CMP0 flag will be set when capture complete. */
    TCF_CMD_ONESHOT_gc = (0x05<<0)  /* Restart with one-shot. In capture mode, counter will stop when capture complete according to event setting. In other modes it will stop at overflow. */
} TCF_CMD_t;

/* Compare # Event Generation select */
typedef enum TCF_CMP0EV_enum
{
    TCF_CMP0EV_PULSE_gc = (0x00<<6),  /* An event pulse is generated when there is a match or overflow */
    TCF_CMP0EV_WAVEFORM_gc = (0x01<<6)  /* The event output is equal to the waveform output */
} TCF_CMP0EV_t;

/* Compare # Event Generation select */
typedef enum TCF_CMP1EV_enum
{
    TCF_CMP1EV_PULSE_gc = (0x00<<7),  /* An event pulse is generated when there is a match or overflow */
    TCF_CMP1EV_WAVEFORM_gc = (0x01<<7)  /* The event output is equal to the waveform output */
} TCF_CMP1EV_t;

/* Counter Operation Mode select */
typedef enum TCF_CNTMODE_enum
{
    TCF_CNTMODE_FRQ_gc = (0x00<<0),  /* Frequency */
    TCF_CNTMODE_NCOPF_gc = (0x01<<0),  /* Numerically Controlled Oscillator Pulse Frequency */
    TCF_CNTMODE_NCOFDC_gc = (0x02<<0),  /* Numerically Controlled Oscillator Fixed Duty Cycle */
    TCF_CNTMODE_CAPTPW_gc = (0x03<<0),  /* Capture Pulse Width */
    TCF_CNTMODE_CAPTPWFRQ_gc = (0x04<<0),  /* Capture Pulse Width and Frequency */
    TCF_CNTMODE_PWM8_gc = (0x07<<0)  /* 8-bit PWM mode */
} TCF_CNTMODE_t;

/* Event edge select */
typedef enum TCF_EDGE_enum
{
    TCF_EDGE_RISE_gc = (0x00<<4),  /* Rising edge or high level */
    TCF_EDGE_FALL_gc = (0x01<<4)  /* Falling edge or low level */
} TCF_EDGE_t;

/* Event Action A select */
typedef enum TCF_EVACTA_enum
{
    TCF_EVACTA_RESTART_gc = (0x00<<1),  /* Restart Counter */
    TCF_EVACTA_BLANK_gc = (0x01<<1)  /* Mask waveform output to '0' */
} TCF_EVACTA_t;

/* Prescaler Select */
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

/* Timeout value select */
typedef enum TCF_TIMEOUT_enum
{
    TCF_TIMEOUT_MAX_gc = (0x00<<0),  /* Timeout when CNT = 0x00FF FFFF */
    TCF_TIMEOUT_9BIT_gc = (0x01<<0),  /* Timeout when CNT = 0x0000 01FF */
    TCF_TIMEOUT_10BIT_gc = (0x02<<0),  /* Timeout when CNT = 0x0000 03FF */
    TCF_TIMEOUT_11BIT_gc = (0x03<<0),  /* Timeout when CNT = 0x0000 07FF */
    TCF_TIMEOUT_12BIT_gc = (0x04<<0),  /* Timeout when CNT = 0x0000 0FFF */
    TCF_TIMEOUT_13BIT_gc = (0x05<<0),  /* Timeout when CNT = 0x0000 1FFF */
    TCF_TIMEOUT_14BIT_gc = (0x06<<0),  /* Timeout when CNT = 0x0000 3FFF */
    TCF_TIMEOUT_15BIT_gc = (0x07<<0),  /* Timeout when CNT = 0x0000 7FFF */
    TCF_TIMEOUT_16BIT_gc = (0x08<<0),  /* Timeout when CNT = 0x0000 FFFF */
    TCF_TIMEOUT_17BIT_gc = (0x09<<0),  /* Timeout when CNT = 0x0001 FFFF */
    TCF_TIMEOUT_18BIT_gc = (0x0A<<0),  /* Timeout when CNT = 0x0003 FFFF */
    TCF_TIMEOUT_19BIT_gc = (0x0B<<0),  /* Timeout when CNT = 0x0007 FFFF */
    TCF_TIMEOUT_20BIT_gc = (0x0C<<0),  /* Timeout when CNT = 0x000F FFFF */
    TCF_TIMEOUT_21BIT_gc = (0x0D<<0),  /* Timeout when CNT = 0x001F FFFF */
    TCF_TIMEOUT_22BIT_gc = (0x0E<<0),  /* Timeout when CNT = 0x003F FFFF */
    TCF_TIMEOUT_23BIT_gc = (0x0F<<0)  /* Timeout when CNT = 0x007F FFFF */
} TCF_TIMEOUT_t;

/* Waveform Generation Pulse Length select */
typedef enum TCF_WGPULSE_enum
{
    TCF_WGPULSE_CLK1_gc = (0x00<<4),  /* High pulse duration is 1 clock period */
    TCF_WGPULSE_CLK2_gc = (0x01<<4),  /* High pulse duration is 2 clock periods */
    TCF_WGPULSE_CLK4_gc = (0x02<<4),  /* High pulse duration is 4 clock periods */
    TCF_WGPULSE_CLK8_gc = (0x03<<4),  /* High pulse duration is 8 clock periods */
    TCF_WGPULSE_CLK16_gc = (0x04<<4),  /* High pulse duration is 16 clock periods */
    TCF_WGPULSE_CLK32_gc = (0x05<<4),  /* High pulse duration is 32 clock periods */
    TCF_WGPULSE_CLK64_gc = (0x06<<4),  /* High pulse duration is 64 clock periods */
    TCF_WGPULSE_CLK128_gc = (0x07<<4)  /* High pulse duration is 128 clock periods */
} TCF_WGPULSE_t;

/*
--------------------------------------------------------------------------
TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

/* Two-Wire Interface */
typedef struct TWI_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t DUALCTRL;  /* Dual Mode Control */
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
    register8_t reserved_1[1];
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

/* Fast-mode Enable select */
typedef enum TWI_FMEN_enum
{
    TWI_FMEN_OFF_gc = (0x00<<0),  /* SCL duty cycle operating according to Sm specification */
    TWI_FMEN_ON_gc = (0x01<<0)  /* SCL duty cycle operating according to Fm specification */
} TWI_FMEN_t;

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
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLE;  /* Control E */
    register8_t CTRLF;  /* Control F */
    register8_t CTRLG;  /* Control G */
    register8_t COMMAND;  /* Command */
    register8_t reserved_1[1];
    register8_t EVCTRL;  /* Event Control */
    _WORDREGISTER(BAUD);  /* Baud Rate */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t reserved_2[1];
    register8_t RXDATAL;  /* Receive Data Low Byte */
    register8_t RXDATAH;  /* Receive Data */
    register8_t TXDATAL;  /* Transmit Data Low Byte */
    register8_t TXDATAH;  /* Transmit Data High Byte */
    register8_t reserved_3[4];
    register8_t AUXDATA0;  /* Auxiliary Data 0 */
    register8_t AUXDATA1;  /* Auxiliary Data 1 */
    register8_t AUXDATA2;  /* Auxiliary Data 2 */
    register8_t reserved_4[4];
    register8_t DBGCTRL;  /* Debug Control */
} USART_t;

/* Auto Baud Window select */
typedef enum USART_ABW_enum
{
    USART_ABW_WDW0_gc = (0x00<<6),  /* 18% tolerance */
    USART_ABW_WDW1_gc = (0x01<<6),  /* 15% tolerance */
    USART_ABW_WDW2_gc = (0x02<<6),  /* 21% tolerance */
    USART_ABW_WDW3_gc = (0x03<<6)  /* 25% tolerance */
} USART_ABW_t;

/* Break Length select */
typedef enum USART_BRKLEN_enum
{
    USART_BRKLEN_13BIT_gc = (0x00<<0),  /* Break field transmission is 13 bit time */
    USART_BRKLEN_17BIT_gc = (0x01<<0),  /* Break field transmission is 17 bit time */
    USART_BRKLEN_21BIT_gc = (0x02<<0),  /* Break field transmission is 21 bit time */
    USART_BRKLEN_26BIT_gc = (0x03<<0)  /* Break field transmission is 26 bit time */
} USART_BRKLEN_t;

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
    USART_CMODE_ASYNCHRONOUS_gc = (0x00<<1),  /* Asynchronous Mode */
    USART_CMODE_SYNCCLIENT_gc = (0x01<<1),  /* Synchronous USART, client mode */
    USART_CMODE_SYNCHOST_gc = (0x02<<1),  /* Synchronous USART, host mode */
    USART_CMODE_SPIHOST_gc = (0x03<<1)  /* SPI Host Mode */
} USART_CMODE_t;

/* Clock Phase select */
typedef enum USART_CPHA_enum
{
    USART_CPHA_LEADEDGE_gc = (0x00<<5),  /* Data is sampled on leading/first edge of SCK */
    USART_CPHA_TRAILEDGE_gc = (0x01<<5)  /* Data is sampled on trailing/last edge of SCK */
} USART_CPHA_t;

/* Communication Signals select */
typedef enum USART_CSIG_enum
{
    USART_CSIG_NORMAL_gc = (0x00<<5),  /* Normal Asynchronous USART, Synchronous USART or SPI Host */
    USART_CSIG_RS485_gc = (0x01<<5),  /* Asynchronous USART in RS485 mode */
    USART_CSIG_HANDSHAKE_gc = (0x02<<5),  /* Asynchronous USART with Hardware Handshake */
    USART_CSIG_CLKDIS_gc = (0x03<<5)  /* SPI Host or Synchronous USART host without Clock Output */
} USART_CSIG_t;

/* Data Order select */
typedef enum USART_DORD_enum
{
    USART_DORD_LSB_gc = (0x00<<6),  /* LSb of the data word is transmitted first */
    USART_DORD_MSB_gc = (0x01<<6)  /* MSb of the data word is transmitted first */
} USART_DORD_t;

/* Frame Format select */
typedef enum USART_FORM_enum
{
    USART_FORM_NORMAL_gc = (0x00<<0),  /* Normal USART frame */
    USART_FORM_AUTOBAUD_gc = (0x01<<0),  /* Auto-baud mode */
    USART_FORM_LINHOST_gc = (0x04<<0),  /* LIN Host mode */
    USART_FORM_LINCLIENT_gc = (0x05<<0)  /* LIN Client mode */
} USART_FORM_t;

/* Guard Time select */
typedef enum USART_GUARD_enum
{
    USART_GUARD_1BIT_gc = (0x00<<2),  /* Guard time is 1 bit time */
    USART_GUARD_4BIT_gc = (0x01<<2),  /* Guard time is 4 bit times */
    USART_GUARD_8BIT_gc = (0x02<<2),  /* Guard time is 8 bit times */
    USART_GUARD_14BIT_gc = (0x03<<2)  /* Guard time is 14 bit times */
} USART_GUARD_t;

/* LIN Command select */
typedef enum USART_LINCMD_enum
{
    USART_LINCMD_NORMAL_gc = (0x00<<0),  /* Normal USART frame */
    USART_LINCMD_BREAK_gc = (0x01<<0),  /* BREAK field transmitted when TXDATA is written */
    USART_LINCMD_HEADER_gc = (0x02<<0)  /* BREAK and SYNC and identifier are auto tramsmitted when TXDATA is writtent with identifier */
} USART_LINCMD_t;

/* Parity Mode select */
typedef enum USART_PMODE_enum
{
    USART_PMODE_DISABLED_gc = (0x00<<4),  /* No Parity */
    USART_PMODE_EVEN_gc = (0x02<<4),  /* Even Parity */
    USART_PMODE_ODD_gc = (0x03<<4)  /* Odd Parity */
} USART_PMODE_t;

/* Protocol Converter select */
typedef enum USART_PROTCONV_enum
{
    USART_PROTCONV_NONE_gc = (0x00<<0),  /* Protocol conversion disabled. Normal data */
    USART_PROTCONV_FIXED_gc = (0x01<<0),  /* Single char for both '0' and '1'. Frame error set if values don't match */
    USART_PROTCONV_MASKED_gc = (0x02<<0),  /* CHARMASK works as a mask */
    USART_PROTCONV_DUAL_gc = (0x03<<0)  /* CHARMASK defines second value for '1' */
} USART_PROTCONV_t;

/* Sample Rate select */
typedef enum USART_SAMPR_enum
{
    USART_SAMPR_16X_gc = (0x00<<3),  /* 16x oversampling */
    USART_SAMPR_8X_gc = (0x01<<3)  /* 8x oversampling (double speed) */
} USART_SAMPR_t;

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
    register8_t USERROW32;  /* User Row Byte 32 */
    register8_t USERROW33;  /* User Row Byte 33 */
    register8_t USERROW34;  /* User Row Byte 34 */
    register8_t USERROW35;  /* User Row Byte 35 */
    register8_t USERROW36;  /* User Row Byte 36 */
    register8_t USERROW37;  /* User Row Byte 37 */
    register8_t USERROW38;  /* User Row Byte 38 */
    register8_t USERROW39;  /* User Row Byte 39 */
    register8_t USERROW40;  /* User Row Byte 40 */
    register8_t USERROW41;  /* User Row Byte 41 */
    register8_t USERROW42;  /* User Row Byte 42 */
    register8_t USERROW43;  /* User Row Byte 43 */
    register8_t USERROW44;  /* User Row Byte 44 */
    register8_t USERROW45;  /* User Row Byte 45 */
    register8_t USERROW46;  /* User Row Byte 46 */
    register8_t USERROW47;  /* User Row Byte 47 */
    register8_t USERROW48;  /* User Row Byte 48 */
    register8_t USERROW49;  /* User Row Byte 49 */
    register8_t USERROW50;  /* User Row Byte 50 */
    register8_t USERROW51;  /* User Row Byte 51 */
    register8_t USERROW52;  /* User Row Byte 52 */
    register8_t USERROW53;  /* User Row Byte 53 */
    register8_t USERROW54;  /* User Row Byte 54 */
    register8_t USERROW55;  /* User Row Byte 55 */
    register8_t USERROW56;  /* User Row Byte 56 */
    register8_t USERROW57;  /* User Row Byte 57 */
    register8_t USERROW58;  /* User Row Byte 58 */
    register8_t USERROW59;  /* User Row Byte 59 */
    register8_t USERROW60;  /* User Row Byte 60 */
    register8_t USERROW61;  /* User Row Byte 61 */
    register8_t USERROW62;  /* User Row Byte 62 */
    register8_t USERROW63;  /* User Row Byte 63 */
} USERROW_t;


/*
--------------------------------------------------------------------------
VDIVA - Virtual Divide Accelerator
--------------------------------------------------------------------------
*/

/* Virtual Divide Accelerator */
typedef struct VDIVA_struct
{
    register8_t DIVCTRL;  /* Divider Control */
    register8_t SHIFTCTRL;  /* Shift Control */
    register8_t reserved_1[1];
    register8_t STATUS;  /* Status */
    register8_t reserved_2[4];
    _DWORDREGISTER(RESULT);  /* Result of Operation (R) / Dividend Value (W) */
    _DWORDREGISTER(REMAINDER);  /* Remainder of Operation (R) / Divisor Value (W) */
} VDIVA_t;

/* Divide Operation select */
typedef enum VDIVA_DIVOP_enum
{
    VDIVA_DIVOP_DIV8_gc = (0x00<<0),  /* 8-bit division */
    VDIVA_DIVOP_DIV16_gc = (0x01<<0),  /* 16-bit division */
    VDIVA_DIVOP_DIV32_gc = (0x02<<0),  /* 32-bit division */
    VDIVA_DIVOP_MOD8_gc = (0x04<<0),  /* 8-bit modulo */
    VDIVA_DIVOP_MOD16_gc = (0x05<<0),  /* 16-bit modulo */
    VDIVA_DIVOP_MOD32_gc = (0x06<<0)  /* 32-bit modulo */
} VDIVA_DIVOP_t;

/* Shift operation select */
typedef enum VDIVA_SHOP_enum
{
    VDIVA_SHOP_ROR_gc = (0x00<<5),  /* Rotate right */
    VDIVA_SHOP_LSL_gc = (0x01<<5),  /* Logical shift left. Vacated bits are cleared */
    VDIVA_SHOP_LSR_gc = (0x02<<5),  /* Logical shift right. Vacated bits are cleared */
    VDIVA_SHOP_ASR_gc = (0x03<<5)  /* Arithmetic shift right. Vacated bits are filled with sign bit. Register value is treated as two's complement signed values */
} VDIVA_SHOP_t;

/* Signed Operation select */
typedef enum VDIVA_SIGN_enum
{
    VDIVA_SIGN_UNSIGNED_gc = (0x00<<6),  /* Unsigned operation */
    VDIVA_SIGN_SIGNED_gc = (0x01<<6)  /* Signed operation */
} VDIVA_SIGN_t;

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
    register8_t reserved_1[2];
    register8_t DAC0REF;  /* DAC0 Reference */
    register8_t reserved_2[1];
    register8_t ACREF;  /* AC Reference */
} VREF_t;

/* Reference select */
typedef enum VREF_REFSEL_enum
{
    VREF_REFSEL_1V024_gc = (0x00<<0),  /* Internal 1.024V reference */
    VREF_REFSEL_2V048_gc = (0x01<<0),  /* Internal 2.048V reference */
    VREF_REFSEL_4V096_gc = (0x02<<0),  /* Internal 4.096V reference */
    VREF_REFSEL_2V500_gc = (0x03<<0),  /* Internal 2.500V reference */
    VREF_REFSEL_VDD_gc = (0x05<<0),  /* VDD as reference */
    VREF_REFSEL_VREFA_gc = (0x06<<0)  /* External reference on VREFA pin */
} VREF_REFSEL_t;

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
    register8_t reserved_1[14];
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
#define GPR                   (*(GPR_t *) 0x001C) /* General Purpose Registers */
#define VDIVA               (*(VDIVA_t *) 0x0020) /* Virtual Divide Accelerator */
#define RSTCTRL           (*(RSTCTRL_t *) 0x0040) /* Reset controller */
#define SLPCTRL           (*(SLPCTRL_t *) 0x0050) /* Sleep Controller */
#define CLKCTRL           (*(CLKCTRL_t *) 0x0060) /* Clock controller */
#define BOD                   (*(BOD_t *) 0x00A0) /* Bod interface */
#define VREF                 (*(VREF_t *) 0x00B0) /* Voltage reference */
#define MVIO                 (*(MVIO_t *) 0x00C0) /* Multi-Voltage I/O */
#define WDT                   (*(WDT_t *) 0x0100) /* Watch-Dog Timer */
#define CPUINT             (*(CPUINT_t *) 0x0110) /* Interrupt Controller */
#define CRCSCAN           (*(CRCSCAN_t *) 0x0120) /* CRCSCAN */
#define RTC                   (*(RTC_t *) 0x0140) /* Real-Time Counter */
#define CCL                   (*(CCL_t *) 0x01C0) /* Configurable Custom Logic */
#define EVSYS               (*(EVSYS_t *) 0x0200) /* Event System */
#define DIVA                 (*(DIVA_t *) 0x02E0) /* Divide Accelerator */
#define PORTA                (*(PORT_t *) 0x0400) /* I/O Ports */
#define PORTB                (*(PORT_t *) 0x0420) /* I/O Ports */
#define PORTC                (*(PORT_t *) 0x0440) /* I/O Ports */
#define PORTD                (*(PORT_t *) 0x0460) /* I/O Ports */
#define PORTE                (*(PORT_t *) 0x0480) /* I/O Ports */
#define PORTF                (*(PORT_t *) 0x04A0) /* I/O Ports */
#define PORTMUX           (*(PORTMUX_t *) 0x05E0) /* Port Multiplexer */
#define ADC0                  (*(ADC_t *) 0x0600) /* Analog to Digital Converter */
#define AC0                    (*(AC_t *) 0x0680) /* Analog Comparator */
#define DAC0                  (*(DAC_t *) 0x06A0) /* Digital to Analog Converter */
#define OPAMP               (*(OPAMP_t *) 0x0700) /* Operational Amplifier System */
#define USART0              (*(USART_t *) 0x0800) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART1              (*(USART_t *) 0x0820) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define TWI0                  (*(TWI_t *) 0x0900) /* Two-Wire Interface */
#define SPI0                  (*(SPI_t *) 0x0940) /* Serial Peripheral Interface */
#define TCE0                  (*(TCE_t *) 0x0A00) /* 16-bit Timer/Counter Type E */
#define TCB0                  (*(TCB_t *) 0x0B00) /* 16-bit Timer/Counter Type B */
#define TCB1                  (*(TCB_t *) 0x0B10) /* 16-bit Timer/Counter Type B */
#define TCB2                  (*(TCB_t *) 0x0B20) /* 16-bit Timer/Counter Type B */
#define TCB3                  (*(TCB_t *) 0x0B30) /* 16-bit Timer/Counter Type B */
#define TCF0                  (*(TCF_t *) 0x0C00) /* 24-bit Timer/Counter for frequency generation */
#define SYSCFG             (*(SYSCFG_t *) 0x0F00) /* System Configuration Registers */
#define NVMCTRL           (*(NVMCTRL_t *) 0x1000) /* Non-volatile Memory Controller */
#define LOCK                 (*(LOCK_t *) 0x1040) /* Lockbits */
#define FUSE                 (*(FUSE_t *) 0x1050) /* Fuses */
#define SIGROW             (*(SIGROW_t *) 0x1080) /* Signature row */
#define BOOTROW           (*(BOOTROW_t *) 0x1100) /* Boot Row */
#define USERROW           (*(USERROW_t *) 0x1200) /* User Row */

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


/* GPR - General Purpose Registers */
#define GPR_GPR0  _SFR_MEM8(0x001C)
#define GPR_GPR1  _SFR_MEM8(0x001D)
#define GPR_GPR2  _SFR_MEM8(0x001E)
#define GPR_GPR3  _SFR_MEM8(0x001F)


/* VDIVA - Virtual Divide Accelerator */
#define VDIVA_DIVCTRL  _SFR_MEM8(0x0020)
#define VDIVA_SHIFTCTRL  _SFR_MEM8(0x0021)
#define VDIVA_STATUS  _SFR_MEM8(0x0023)
#define VDIVA_RESULT  _SFR_MEM32(0x0028)
#define VDIVA_RESULT0  _SFR_MEM8(0x0028)
#define VDIVA_RESULT1  _SFR_MEM8(0x0029)
#define VDIVA_RESULT2  _SFR_MEM8(0x002A)
#define VDIVA_RESULT3  _SFR_MEM8(0x002B)
#define VDIVA_REMAINDER  _SFR_MEM32(0x002C)
#define VDIVA_REMAINDER0  _SFR_MEM8(0x002C)
#define VDIVA_REMAINDER1  _SFR_MEM8(0x002D)
#define VDIVA_REMAINDER2  _SFR_MEM8(0x002E)
#define VDIVA_REMAINDER3  _SFR_MEM8(0x002F)


/* CPU - CPU */
#define CPU_SPLIM  _SFR_MEM16(0x0030)
#define CPU_SPLIML  _SFR_MEM8(0x0030)
#define CPU_SPLIMH  _SFR_MEM8(0x0031)
#define CPU_CCP  _SFR_MEM8(0x0034)
#define CPU_CTRLA  _SFR_MEM8(0x0035)
#define CPU_INTFLAGS  _SFR_MEM8(0x0036)
#define CPU_SP  _SFR_MEM16(0x003D)
#define CPU_SPL  _SFR_MEM8(0x003D)
#define CPU_SPH  _SFR_MEM8(0x003E)
#define CPU_SREG  _SFR_MEM8(0x003F)


/* RSTCTRL - Reset controller */
#define RSTCTRL_RSTFR  _SFR_MEM8(0x0040)
#define RSTCTRL_SWRR  _SFR_MEM8(0x0041)


/* SLPCTRL - Sleep Controller */
#define SLPCTRL_CTRLA  _SFR_MEM8(0x0050)


/* CLKCTRL - Clock controller */
#define CLKCTRL_MCLKCTRLA  _SFR_MEM8(0x0060)
#define CLKCTRL_MCLKCTRLB  _SFR_MEM8(0x0061)
#define CLKCTRL_MCLKCTRLC  _SFR_MEM8(0x0062)
#define CLKCTRL_MCLKINTCTRL  _SFR_MEM8(0x0063)
#define CLKCTRL_MCLKINTFLAGS  _SFR_MEM8(0x0064)
#define CLKCTRL_MCLKSTATUS  _SFR_MEM8(0x0065)
#define CLKCTRL_MCLKTIMEBASE  _SFR_MEM8(0x0066)
#define CLKCTRL_OSCHFCTRLA  _SFR_MEM8(0x0068)
#define CLKCTRL_OSCHFTUNE  _SFR_MEM8(0x0069)
#define CLKCTRL_OSC32KCTRLA  _SFR_MEM8(0x0078)
#define CLKCTRL_XOSC32KCTRLA  _SFR_MEM8(0x007C)
#define CLKCTRL_XOSCHFCTRLA  _SFR_MEM8(0x0080)


/* BOD - Bod interface */
#define BOD_CTRLA  _SFR_MEM8(0x00A0)
#define BOD_CTRLB  _SFR_MEM8(0x00A1)
#define BOD_VLMCTRLA  _SFR_MEM8(0x00A8)
#define BOD_INTCTRL  _SFR_MEM8(0x00A9)
#define BOD_INTFLAGS  _SFR_MEM8(0x00AA)
#define BOD_STATUS  _SFR_MEM8(0x00AB)


/* VREF - Voltage reference */
#define VREF_DAC0REF  _SFR_MEM8(0x00B2)
#define VREF_ACREF  _SFR_MEM8(0x00B4)


/* MVIO - Multi-Voltage I/O */
#define MVIO_CTRLA  _SFR_MEM8(0x00C0)
#define MVIO_INTCTRL  _SFR_MEM8(0x00C2)
#define MVIO_INTFLAGS  _SFR_MEM8(0x00C3)
#define MVIO_STATUS  _SFR_MEM8(0x00C4)


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
#define CRCSCAN_INTCTRL  _SFR_MEM8(0x0122)
#define CRCSCAN_INTFLAGS  _SFR_MEM8(0x0123)
#define CRCSCAN_STATUSA  _SFR_MEM8(0x0124)
#define CRCSCAN_SCANADR  _SFR_MEM8(0x0125)
#define CRCSCAN_DATA  _SFR_MEM8(0x0126)
#define CRCSCAN_CRC  _SFR_MEM32(0x0128)
#define CRCSCAN_CRC0  _SFR_MEM8(0x0128)
#define CRCSCAN_CRC1  _SFR_MEM8(0x0129)
#define CRCSCAN_CRC2  _SFR_MEM8(0x012A)
#define CRCSCAN_CRC3  _SFR_MEM8(0x012B)


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
#define EVSYS_USERDAC0ENABLE  _SFR_MEM8(0x0229)
#define EVSYS_USERDAC0DISABLE  _SFR_MEM8(0x022A)
#define EVSYS_USERDAC0TRIG  _SFR_MEM8(0x022B)
#define EVSYS_USEROPAMP0ENABLE  _SFR_MEM8(0x022C)
#define EVSYS_USEROPAMP0DISABLE  _SFR_MEM8(0x022D)
#define EVSYS_USEROPAMP0DUMP  _SFR_MEM8(0x022E)
#define EVSYS_USEROPAMP0DRIVE  _SFR_MEM8(0x022F)
#define EVSYS_USEROPAMP1ENABLE  _SFR_MEM8(0x0230)
#define EVSYS_USEROPAMP1DISABLE  _SFR_MEM8(0x0231)
#define EVSYS_USEROPAMP1DUMP  _SFR_MEM8(0x0232)
#define EVSYS_USEROPAMP1DRIVE  _SFR_MEM8(0x0233)
#define EVSYS_USEREVSYSEVOUTA  _SFR_MEM8(0x0234)
#define EVSYS_USEREVSYSEVOUTB  _SFR_MEM8(0x0235)
#define EVSYS_USEREVSYSEVOUTC  _SFR_MEM8(0x0236)
#define EVSYS_USEREVSYSEVOUTD  _SFR_MEM8(0x0237)
#define EVSYS_USEREVSYSEVOUTE  _SFR_MEM8(0x0238)
#define EVSYS_USEREVSYSEVOUTF  _SFR_MEM8(0x0239)
#define EVSYS_USERUSART0RXD  _SFR_MEM8(0x023A)
#define EVSYS_USERUSART1RXD  _SFR_MEM8(0x023B)
#define EVSYS_USERTCE0CNTA  _SFR_MEM8(0x023C)
#define EVSYS_USERTCE0CNTB  _SFR_MEM8(0x023D)
#define EVSYS_USERTCB0CAPT  _SFR_MEM8(0x023E)
#define EVSYS_USERTCB0COUNT  _SFR_MEM8(0x023F)
#define EVSYS_USERTCB1CAPT  _SFR_MEM8(0x0240)
#define EVSYS_USERTCB1COUNT  _SFR_MEM8(0x0241)
#define EVSYS_USERTCB2CAPT  _SFR_MEM8(0x0242)
#define EVSYS_USERTCB2COUNT  _SFR_MEM8(0x0243)
#define EVSYS_USERTCB3CAPT  _SFR_MEM8(0x0244)
#define EVSYS_USERTCB3COUNT  _SFR_MEM8(0x0245)
#define EVSYS_USERTCF0COUNT  _SFR_MEM8(0x0246)
#define EVSYS_USERTCF0ACTION  _SFR_MEM8(0x0247)


/* DIVA - Divide Accelerator */
#define DIVA_DIVCTRL  _SFR_MEM8(0x02E0)
#define DIVA_SHIFTCTRL  _SFR_MEM8(0x02E1)
#define DIVA_STATUS  _SFR_MEM8(0x02E3)
#define DIVA_DIVIDEND  _SFR_MEM32(0x02E8)
#define DIVA_DIVIDEND0  _SFR_MEM8(0x02E8)
#define DIVA_DIVIDEND1  _SFR_MEM8(0x02E9)
#define DIVA_DIVIDEND2  _SFR_MEM8(0x02EA)
#define DIVA_DIVIDEND3  _SFR_MEM8(0x02EB)
#define DIVA_DIVISOR  _SFR_MEM32(0x02EC)
#define DIVA_DIVISOR0  _SFR_MEM8(0x02EC)
#define DIVA_DIVISOR1  _SFR_MEM8(0x02ED)
#define DIVA_DIVISOR2  _SFR_MEM8(0x02EE)
#define DIVA_DIVISOR3  _SFR_MEM8(0x02EF)
#define DIVA_RESULT  _SFR_MEM32(0x02F0)
#define DIVA_RESULT0  _SFR_MEM8(0x02F0)
#define DIVA_RESULT1  _SFR_MEM8(0x02F1)
#define DIVA_RESULT2  _SFR_MEM8(0x02F2)
#define DIVA_RESULT3  _SFR_MEM8(0x02F3)
#define DIVA_REMAINDER  _SFR_MEM32(0x02F4)
#define DIVA_REMAINDER0  _SFR_MEM8(0x02F4)
#define DIVA_REMAINDER1  _SFR_MEM8(0x02F5)
#define DIVA_REMAINDER2  _SFR_MEM8(0x02F6)
#define DIVA_REMAINDER3  _SFR_MEM8(0x02F7)


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
#define PORTA_EVGENCTRLA  _SFR_MEM8(0x0418)


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
#define PORTB_PINCTRLUPD  _SFR_MEM8(0x042C)
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
#define PORTB_EVGENCTRLA  _SFR_MEM8(0x0438)


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
#define PORTC_EVGENCTRLA  _SFR_MEM8(0x0458)


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
#define PORTD_EVGENCTRLA  _SFR_MEM8(0x0478)


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
#define PORTE_PINCTRLUPD  _SFR_MEM8(0x048C)
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
#define PORTE_EVGENCTRLA  _SFR_MEM8(0x0498)


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
#define PORTF_EVGENCTRLA  _SFR_MEM8(0x04B8)


/* PORTMUX - Port Multiplexer */
#define PORTMUX_EVSYSROUTEA  _SFR_MEM8(0x05E0)
#define PORTMUX_CCLROUTEA  _SFR_MEM8(0x05E1)
#define PORTMUX_USARTROUTEA  _SFR_MEM8(0x05E2)
#define PORTMUX_SPIROUTEA  _SFR_MEM8(0x05E5)
#define PORTMUX_TWIROUTEA  _SFR_MEM8(0x05E6)
#define PORTMUX_TCEROUTEA  _SFR_MEM8(0x05E7)
#define PORTMUX_TCBROUTEA  _SFR_MEM8(0x05E8)
#define PORTMUX_ACROUTEA  _SFR_MEM8(0x05EA)
#define PORTMUX_TCFROUTE  _SFR_MEM8(0x05EC)


/* ADC (ADC0) - Analog to Digital Converter */
#define ADC0_CTRLA  _SFR_MEM8(0x0600)
#define ADC0_CTRLB  _SFR_MEM8(0x0601)
#define ADC0_CTRLC  _SFR_MEM8(0x0602)
#define ADC0_CTRLD  _SFR_MEM8(0x0603)
#define ADC0_INTCTRL  _SFR_MEM8(0x0604)
#define ADC0_INTFLAGS  _SFR_MEM8(0x0605)
#define ADC0_STATUS  _SFR_MEM8(0x0606)
#define ADC0_DBGCTRL  _SFR_MEM8(0x0607)
#define ADC0_CTRLE  _SFR_MEM8(0x0608)
#define ADC0_CTRLF  _SFR_MEM8(0x0609)
#define ADC0_COMMAND  _SFR_MEM8(0x060A)
#define ADC0_PGACTRL  _SFR_MEM8(0x060B)
#define ADC0_MUXPOS  _SFR_MEM8(0x060C)
#define ADC0_MUXNEG  _SFR_MEM8(0x060D)
#define ADC0_PGAMUXPOS  _SFR_MEM8(0x060E)
#define ADC0_PGAMUXNEG  _SFR_MEM8(0x060F)
#define ADC0_RESULT  _SFR_MEM32(0x0610)
#define ADC0_RESULT0  _SFR_MEM8(0x0610)
#define ADC0_RESULT1  _SFR_MEM8(0x0611)
#define ADC0_RESULT2  _SFR_MEM8(0x0612)
#define ADC0_RESULT3  _SFR_MEM8(0x0613)
#define ADC0_SAMPLE  _SFR_MEM16(0x0614)
#define ADC0_SAMPLEL  _SFR_MEM8(0x0614)
#define ADC0_SAMPLEH  _SFR_MEM8(0x0615)
#define ADC0_PGARESULT  _SFR_MEM16(0x0618)
#define ADC0_PGARESULTL  _SFR_MEM8(0x0618)
#define ADC0_PGARESULTH  _SFR_MEM8(0x0619)
#define ADC0_WINLT  _SFR_MEM16(0x061C)
#define ADC0_WINLTL  _SFR_MEM8(0x061C)
#define ADC0_WINLTH  _SFR_MEM8(0x061D)
#define ADC0_WINHT  _SFR_MEM16(0x061E)
#define ADC0_WINHTL  _SFR_MEM8(0x061E)
#define ADC0_WINHTH  _SFR_MEM8(0x061F)
#define ADC0_OPASAMPDUR  _SFR_MEM8(0x0620)
#define ADC0_TEMP0  _SFR_MEM8(0x062C)
#define ADC0_TEMP1  _SFR_MEM8(0x062D)
#define ADC0_TEMP2  _SFR_MEM8(0x062E)


/* AC (AC0) - Analog Comparator */
#define AC0_CTRLA  _SFR_MEM8(0x0680)
#define AC0_CTRLB  _SFR_MEM8(0x0681)
#define AC0_MUXCTRL  _SFR_MEM8(0x0682)
#define AC0_REFSCALE  _SFR_MEM8(0x0683)
#define AC0_INTCTRL  _SFR_MEM8(0x0684)
#define AC0_INTFLAGS  _SFR_MEM8(0x0685)
#define AC0_STATUS  _SFR_MEM8(0x0686)


/* DAC (DAC0) - Digital to Analog Converter */
#define DAC0_CTRLA  _SFR_MEM8(0x06A0)
#define DAC0_EVCTRL  _SFR_MEM8(0x06A2)
#define DAC0_STATUS  _SFR_MEM8(0x06A5)
#define DAC0_DATA  _SFR_MEM16(0x06A6)
#define DAC0_DATAL  _SFR_MEM8(0x06A6)
#define DAC0_DATAH  _SFR_MEM8(0x06A7)


/* OPAMP - Operational Amplifier System */
#define OPAMP_CTRLA  _SFR_MEM8(0x0700)
#define OPAMP_DBGCTRL  _SFR_MEM8(0x0701)
#define OPAMP_OP0CTRLA  _SFR_MEM8(0x0710)
#define OPAMP_OP0STATUS  _SFR_MEM8(0x0711)
#define OPAMP_OP0RESMUX  _SFR_MEM8(0x0712)
#define OPAMP_OP0INMUX  _SFR_MEM8(0x0713)
#define OPAMP_OP0SETTLE  _SFR_MEM8(0x0714)
#define OPAMP_OP0CAL  _SFR_MEM8(0x0715)
#define OPAMP_OP1CTRLA  _SFR_MEM8(0x0718)
#define OPAMP_OP1STATUS  _SFR_MEM8(0x0719)
#define OPAMP_OP1RESMUX  _SFR_MEM8(0x071A)
#define OPAMP_OP1INMUX  _SFR_MEM8(0x071B)
#define OPAMP_OP1SETTLE  _SFR_MEM8(0x071C)
#define OPAMP_OP1CAL  _SFR_MEM8(0x071D)


/* USART (USART0) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART0_CTRLA  _SFR_MEM8(0x0800)
#define USART0_CTRLB  _SFR_MEM8(0x0801)
#define USART0_CTRLC  _SFR_MEM8(0x0802)
#define USART0_CTRLD  _SFR_MEM8(0x0803)
#define USART0_CTRLE  _SFR_MEM8(0x0804)
#define USART0_CTRLF  _SFR_MEM8(0x0805)
#define USART0_CTRLG  _SFR_MEM8(0x0806)
#define USART0_COMMAND  _SFR_MEM8(0x0807)
#define USART0_EVCTRL  _SFR_MEM8(0x0809)
#define USART0_BAUD  _SFR_MEM16(0x080A)
#define USART0_BAUDL  _SFR_MEM8(0x080A)
#define USART0_BAUDH  _SFR_MEM8(0x080B)
#define USART0_INTCTRL  _SFR_MEM8(0x080C)
#define USART0_INTFLAGS  _SFR_MEM8(0x080D)
#define USART0_STATUS  _SFR_MEM8(0x080E)
#define USART0_RXDATAL  _SFR_MEM8(0x0810)
#define USART0_RXDATAH  _SFR_MEM8(0x0811)
#define USART0_TXDATAL  _SFR_MEM8(0x0812)
#define USART0_TXDATAH  _SFR_MEM8(0x0813)
#define USART0_AUXDATA0  _SFR_MEM8(0x0818)
#define USART0_AUXDATA1  _SFR_MEM8(0x0819)
#define USART0_AUXDATA2  _SFR_MEM8(0x081A)
#define USART0_DBGCTRL  _SFR_MEM8(0x081F)


/* USART (USART1) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART1_CTRLA  _SFR_MEM8(0x0820)
#define USART1_CTRLB  _SFR_MEM8(0x0821)
#define USART1_CTRLC  _SFR_MEM8(0x0822)
#define USART1_CTRLD  _SFR_MEM8(0x0823)
#define USART1_CTRLE  _SFR_MEM8(0x0824)
#define USART1_CTRLF  _SFR_MEM8(0x0825)
#define USART1_CTRLG  _SFR_MEM8(0x0826)
#define USART1_COMMAND  _SFR_MEM8(0x0827)
#define USART1_EVCTRL  _SFR_MEM8(0x0829)
#define USART1_BAUD  _SFR_MEM16(0x082A)
#define USART1_BAUDL  _SFR_MEM8(0x082A)
#define USART1_BAUDH  _SFR_MEM8(0x082B)
#define USART1_INTCTRL  _SFR_MEM8(0x082C)
#define USART1_INTFLAGS  _SFR_MEM8(0x082D)
#define USART1_STATUS  _SFR_MEM8(0x082E)
#define USART1_RXDATAL  _SFR_MEM8(0x0830)
#define USART1_RXDATAH  _SFR_MEM8(0x0831)
#define USART1_TXDATAL  _SFR_MEM8(0x0832)
#define USART1_TXDATAH  _SFR_MEM8(0x0833)
#define USART1_AUXDATA0  _SFR_MEM8(0x0838)
#define USART1_AUXDATA1  _SFR_MEM8(0x0839)
#define USART1_AUXDATA2  _SFR_MEM8(0x083A)
#define USART1_DBGCTRL  _SFR_MEM8(0x083F)


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


/* TCB (TCB2) - 16-bit Timer/Counter Type B */
#define TCB2_CTRLA  _SFR_MEM8(0x0B20)
#define TCB2_CTRLB  _SFR_MEM8(0x0B21)
#define TCB2_CTRLC  _SFR_MEM8(0x0B22)
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


/* TCB (TCB3) - 16-bit Timer/Counter Type B */
#define TCB3_CTRLA  _SFR_MEM8(0x0B30)
#define TCB3_CTRLB  _SFR_MEM8(0x0B31)
#define TCB3_CTRLC  _SFR_MEM8(0x0B32)
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


/* TCF (TCF0) - 24-bit Timer/Counter for frequency generation */
#define TCF0_CTRLA  _SFR_MEM8(0x0C00)
#define TCF0_CTRLB  _SFR_MEM8(0x0C01)
#define TCF0_CTRLC  _SFR_MEM8(0x0C02)
#define TCF0_CTRLD  _SFR_MEM8(0x0C03)
#define TCF0_CTRLE  _SFR_MEM8(0x0C04)
#define TCF0_EVCTRL  _SFR_MEM8(0x0C06)
#define TCF0_INTCTRL  _SFR_MEM8(0x0C08)
#define TCF0_INTFLAGS  _SFR_MEM8(0x0C09)
#define TCF0_STATUS  _SFR_MEM8(0x0C0A)
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


/* SYSCFG - System Configuration Registers */
#define SYSCFG_REVID  _SFR_MEM8(0x0F01)
#define SYSCFG_VDDCTRL  _SFR_MEM8(0x0F07)


/* NVMCTRL - Non-volatile Memory Controller */
#define NVMCTRL_CTRLA  _SFR_MEM8(0x1000)
#define NVMCTRL_CTRLB  _SFR_MEM8(0x1001)
#define NVMCTRL_CTRLC  _SFR_MEM8(0x1002)
#define NVMCTRL_INTCTRL  _SFR_MEM8(0x1004)
#define NVMCTRL_INTFLAGS  _SFR_MEM8(0x1005)
#define NVMCTRL_STATUS  _SFR_MEM8(0x1006)
#define NVMCTRL_DATA  _SFR_MEM16(0x1008)
#define NVMCTRL_DATAL  _SFR_MEM8(0x1008)
#define NVMCTRL_DATAH  _SFR_MEM8(0x1009)
#define NVMCTRL_ADDR  _SFR_MEM32(0x100C)
#define NVMCTRL_ADDR0  _SFR_MEM8(0x100C)
#define NVMCTRL_ADDR1  _SFR_MEM8(0x100D)
#define NVMCTRL_ADDR2  _SFR_MEM8(0x100E)
#define NVMCTRL_ADDR3  _SFR_MEM8(0x100F)


/* LOCK - Lockbits */
#define LOCK_KEY  _SFR_MEM32(0x1040)
#define LOCK_KEY0  _SFR_MEM8(0x1040)
#define LOCK_KEY1  _SFR_MEM8(0x1041)
#define LOCK_KEY2  _SFR_MEM8(0x1042)
#define LOCK_KEY3  _SFR_MEM8(0x1043)


/* FUSE - Fuses */
#define FUSE_WDTCFG  _SFR_MEM8(0x1050)
#define FUSE_BODCFG  _SFR_MEM8(0x1051)
#define FUSE_OSCCFG  _SFR_MEM8(0x1052)
#define FUSE_PINCFG  _SFR_MEM8(0x1053)
#define FUSE_HWMONCFG  _SFR_MEM8(0x1054)
#define FUSE_SYSCFG0  _SFR_MEM8(0x1055)
#define FUSE_SYSCFG1  _SFR_MEM8(0x1056)
#define FUSE_CODESIZE  _SFR_MEM8(0x1057)
#define FUSE_BOOTSIZE  _SFR_MEM8(0x1058)
#define FUSE_PDICFG  _SFR_MEM16(0x105A)
#define FUSE_PDICFGL  _SFR_MEM8(0x105A)
#define FUSE_PDICFGH  _SFR_MEM8(0x105B)


/* SIGROW - Signature row */
#define SIGROW_DEVICEID0  _SFR_MEM8(0x1080)
#define SIGROW_DEVICEID1  _SFR_MEM8(0x1081)
#define SIGROW_DEVICEID2  _SFR_MEM8(0x1082)
#define SIGROW_TEMPSENSE0  _SFR_MEM16(0x1084)
#define SIGROW_TEMPSENSE0L  _SFR_MEM8(0x1084)
#define SIGROW_TEMPSENSE0H  _SFR_MEM8(0x1085)
#define SIGROW_TEMPSENSE1  _SFR_MEM16(0x1086)
#define SIGROW_TEMPSENSE1L  _SFR_MEM8(0x1086)
#define SIGROW_TEMPSENSE1H  _SFR_MEM8(0x1087)
#define SIGROW_ACREFRISE  _SFR_MEM8(0x1088)
#define SIGROW_ACREFFALL  _SFR_MEM8(0x1089)
#define SIGROW_SERNUM0  _SFR_MEM8(0x1090)
#define SIGROW_SERNUM1  _SFR_MEM8(0x1091)
#define SIGROW_SERNUM2  _SFR_MEM8(0x1092)
#define SIGROW_SERNUM3  _SFR_MEM8(0x1093)
#define SIGROW_SERNUM4  _SFR_MEM8(0x1094)
#define SIGROW_SERNUM5  _SFR_MEM8(0x1095)
#define SIGROW_SERNUM6  _SFR_MEM8(0x1096)
#define SIGROW_SERNUM7  _SFR_MEM8(0x1097)
#define SIGROW_SERNUM8  _SFR_MEM8(0x1098)
#define SIGROW_SERNUM9  _SFR_MEM8(0x1099)
#define SIGROW_SERNUM10  _SFR_MEM8(0x109A)
#define SIGROW_SERNUM11  _SFR_MEM8(0x109B)
#define SIGROW_SERNUM12  _SFR_MEM8(0x109C)
#define SIGROW_SERNUM13  _SFR_MEM8(0x109D)
#define SIGROW_SERNUM14  _SFR_MEM8(0x109E)
#define SIGROW_SERNUM15  _SFR_MEM8(0x109F)


/* BOOTROW - Boot Row */
#define BOOTROW_BOOTROW  _SFR_MEM8(0x1100)


/* USERROW - User Row */
#define USERROW_USERROW0  _SFR_MEM8(0x1200)
#define USERROW_USERROW1  _SFR_MEM8(0x1201)
#define USERROW_USERROW2  _SFR_MEM8(0x1202)
#define USERROW_USERROW3  _SFR_MEM8(0x1203)
#define USERROW_USERROW4  _SFR_MEM8(0x1204)
#define USERROW_USERROW5  _SFR_MEM8(0x1205)
#define USERROW_USERROW6  _SFR_MEM8(0x1206)
#define USERROW_USERROW7  _SFR_MEM8(0x1207)
#define USERROW_USERROW8  _SFR_MEM8(0x1208)
#define USERROW_USERROW9  _SFR_MEM8(0x1209)
#define USERROW_USERROW10  _SFR_MEM8(0x120A)
#define USERROW_USERROW11  _SFR_MEM8(0x120B)
#define USERROW_USERROW12  _SFR_MEM8(0x120C)
#define USERROW_USERROW13  _SFR_MEM8(0x120D)
#define USERROW_USERROW14  _SFR_MEM8(0x120E)
#define USERROW_USERROW15  _SFR_MEM8(0x120F)
#define USERROW_USERROW16  _SFR_MEM8(0x1210)
#define USERROW_USERROW17  _SFR_MEM8(0x1211)
#define USERROW_USERROW18  _SFR_MEM8(0x1212)
#define USERROW_USERROW19  _SFR_MEM8(0x1213)
#define USERROW_USERROW20  _SFR_MEM8(0x1214)
#define USERROW_USERROW21  _SFR_MEM8(0x1215)
#define USERROW_USERROW22  _SFR_MEM8(0x1216)
#define USERROW_USERROW23  _SFR_MEM8(0x1217)
#define USERROW_USERROW24  _SFR_MEM8(0x1218)
#define USERROW_USERROW25  _SFR_MEM8(0x1219)
#define USERROW_USERROW26  _SFR_MEM8(0x121A)
#define USERROW_USERROW27  _SFR_MEM8(0x121B)
#define USERROW_USERROW28  _SFR_MEM8(0x121C)
#define USERROW_USERROW29  _SFR_MEM8(0x121D)
#define USERROW_USERROW30  _SFR_MEM8(0x121E)
#define USERROW_USERROW31  _SFR_MEM8(0x121F)
#define USERROW_USERROW32  _SFR_MEM8(0x1220)
#define USERROW_USERROW33  _SFR_MEM8(0x1221)
#define USERROW_USERROW34  _SFR_MEM8(0x1222)
#define USERROW_USERROW35  _SFR_MEM8(0x1223)
#define USERROW_USERROW36  _SFR_MEM8(0x1224)
#define USERROW_USERROW37  _SFR_MEM8(0x1225)
#define USERROW_USERROW38  _SFR_MEM8(0x1226)
#define USERROW_USERROW39  _SFR_MEM8(0x1227)
#define USERROW_USERROW40  _SFR_MEM8(0x1228)
#define USERROW_USERROW41  _SFR_MEM8(0x1229)
#define USERROW_USERROW42  _SFR_MEM8(0x122A)
#define USERROW_USERROW43  _SFR_MEM8(0x122B)
#define USERROW_USERROW44  _SFR_MEM8(0x122C)
#define USERROW_USERROW45  _SFR_MEM8(0x122D)
#define USERROW_USERROW46  _SFR_MEM8(0x122E)
#define USERROW_USERROW47  _SFR_MEM8(0x122F)
#define USERROW_USERROW48  _SFR_MEM8(0x1230)
#define USERROW_USERROW49  _SFR_MEM8(0x1231)
#define USERROW_USERROW50  _SFR_MEM8(0x1232)
#define USERROW_USERROW51  _SFR_MEM8(0x1233)
#define USERROW_USERROW52  _SFR_MEM8(0x1234)
#define USERROW_USERROW53  _SFR_MEM8(0x1235)
#define USERROW_USERROW54  _SFR_MEM8(0x1236)
#define USERROW_USERROW55  _SFR_MEM8(0x1237)
#define USERROW_USERROW56  _SFR_MEM8(0x1238)
#define USERROW_USERROW57  _SFR_MEM8(0x1239)
#define USERROW_USERROW58  _SFR_MEM8(0x123A)
#define USERROW_USERROW59  _SFR_MEM8(0x123B)
#define USERROW_USERROW60  _SFR_MEM8(0x123C)
#define USERROW_USERROW61  _SFR_MEM8(0x123D)
#define USERROW_USERROW62  _SFR_MEM8(0x123E)
#define USERROW_USERROW63  _SFR_MEM8(0x123F)



/*================== Bitfield Definitions ================== */

/* AC - Analog Comparator */
/* AC.CTRLA  bit masks and bit positions */
#define AC_ENABLE_bm  0x01  /* Enable bit mask. */
#define AC_ENABLE_bp  0  /* Enable bit position. */
#define AC_INITVAL_bm  0x10  /* Initial value bit mask. */
#define AC_INITVAL_bp  4  /* Initial value bit position. */
#define AC_INVERT_bm  0x20  /* Invert Comparator Output bit mask. */
#define AC_INVERT_bp  5  /* Invert Comparator Output bit position. */
#define AC_OUTEN_bm  0x40  /* Output Pad Enable bit mask. */
#define AC_OUTEN_bp  6  /* Output Pad Enable bit position. */
#define AC_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define AC_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */

/* AC.CTRLB  bit masks and bit positions */
#define AC_RANGE_gm  0xC0  /* Comparator operation range group mask. */
#define AC_RANGE_gp  6  /* Comparator operation range group position. */
#define AC_RANGE_0_bm  (1<<6)  /* Comparator operation range bit 0 mask. */
#define AC_RANGE_0_bp  6  /* Comparator operation range bit 0 position. */
#define AC_RANGE_1_bm  (1<<7)  /* Comparator operation range bit 1 mask. */
#define AC_RANGE_1_bp  7  /* Comparator operation range bit 1 position. */

/* AC.MUXCTRL  bit masks and bit positions */
#define AC_MUXNEG_gm  0x0F  /* Negative Input MUX Selection group mask. */
#define AC_MUXNEG_gp  0  /* Negative Input MUX Selection group position. */
#define AC_MUXNEG_0_bm  (1<<0)  /* Negative Input MUX Selection bit 0 mask. */
#define AC_MUXNEG_0_bp  0  /* Negative Input MUX Selection bit 0 position. */
#define AC_MUXNEG_1_bm  (1<<1)  /* Negative Input MUX Selection bit 1 mask. */
#define AC_MUXNEG_1_bp  1  /* Negative Input MUX Selection bit 1 position. */
#define AC_MUXNEG_2_bm  (1<<2)  /* Negative Input MUX Selection bit 2 mask. */
#define AC_MUXNEG_2_bp  2  /* Negative Input MUX Selection bit 2 position. */
#define AC_MUXNEG_3_bm  (1<<3)  /* Negative Input MUX Selection bit 3 mask. */
#define AC_MUXNEG_3_bp  3  /* Negative Input MUX Selection bit 3 position. */
#define AC_MUXPOS_gm  0xF0  /* Positive Input MUX Selection group mask. */
#define AC_MUXPOS_gp  4  /* Positive Input MUX Selection group position. */
#define AC_MUXPOS_0_bm  (1<<4)  /* Positive Input MUX Selection bit 0 mask. */
#define AC_MUXPOS_0_bp  4  /* Positive Input MUX Selection bit 0 position. */
#define AC_MUXPOS_1_bm  (1<<5)  /* Positive Input MUX Selection bit 1 mask. */
#define AC_MUXPOS_1_bp  5  /* Positive Input MUX Selection bit 1 position. */
#define AC_MUXPOS_2_bm  (1<<6)  /* Positive Input MUX Selection bit 2 mask. */
#define AC_MUXPOS_2_bp  6  /* Positive Input MUX Selection bit 2 position. */
#define AC_MUXPOS_3_bm  (1<<7)  /* Positive Input MUX Selection bit 3 mask. */
#define AC_MUXPOS_3_bp  7  /* Positive Input MUX Selection bit 3 position. */

/* AC.INTCTRL  bit masks and bit positions */
#define AC_CMP_bm  0x01  /* Interrupt Enable bit mask. */
#define AC_CMP_bp  0  /* Interrupt Enable bit position. */
#define AC_INTMODE_gm  0x30  /* Interrupt Modes group mask. */
#define AC_INTMODE_gp  4  /* Interrupt Modes group position. */
#define AC_INTMODE_0_bm  (1<<4)  /* Interrupt Modes bit 0 mask. */
#define AC_INTMODE_0_bp  4  /* Interrupt Modes bit 0 position. */
#define AC_INTMODE_1_bm  (1<<5)  /* Interrupt Modes bit 1 mask. */
#define AC_INTMODE_1_bp  5  /* Interrupt Modes bit 1 position. */

/* AC.INTFLAGS  bit masks and bit positions */
/* AC_CMP  is already defined. */

/* AC.STATUS  bit masks and bit positions */
/* AC_CMP  is already defined. */


/* ADC - Analog to Digital Converter */
/* ADC.CTRLA  bit masks and bit positions */
#define ADC_ENABLE_bm  0x01  /* ADC Enable bit mask. */
#define ADC_ENABLE_bp  0  /* ADC Enable bit position. */
#define ADC_RES13_bm  0x10  /* 13-bit Resolution bit mask. */
#define ADC_RES13_bp  4  /* 13-bit Resolution bit position. */
#define ADC_LOWLAT_bm  0x20  /* Low Latency bit mask. */
#define ADC_LOWLAT_bp  5  /* Low Latency bit position. */
#define ADC_RUNSTDBY_bm  0x80  /* Run in Standby bit mask. */
#define ADC_RUNSTDBY_bp  7  /* Run in Standby bit position. */

/* ADC.CTRLB  bit masks and bit positions */
#define ADC_PRESC_gm  0x0F  /* Prescaler Value group mask. */
#define ADC_PRESC_gp  0  /* Prescaler Value group position. */
#define ADC_PRESC_0_bm  (1<<0)  /* Prescaler Value bit 0 mask. */
#define ADC_PRESC_0_bp  0  /* Prescaler Value bit 0 position. */
#define ADC_PRESC_1_bm  (1<<1)  /* Prescaler Value bit 1 mask. */
#define ADC_PRESC_1_bp  1  /* Prescaler Value bit 1 position. */
#define ADC_PRESC_2_bm  (1<<2)  /* Prescaler Value bit 2 mask. */
#define ADC_PRESC_2_bp  2  /* Prescaler Value bit 2 position. */
#define ADC_PRESC_3_bm  (1<<3)  /* Prescaler Value bit 3 mask. */
#define ADC_PRESC_3_bp  3  /* Prescaler Value bit 3 position. */

/* ADC.CTRLC  bit masks and bit positions */
#define ADC_VREFPOS_gm  0x07  /* Positive Reference Selection group mask. */
#define ADC_VREFPOS_gp  0  /* Positive Reference Selection group position. */
#define ADC_VREFPOS_0_bm  (1<<0)  /* Positive Reference Selection bit 0 mask. */
#define ADC_VREFPOS_0_bp  0  /* Positive Reference Selection bit 0 position. */
#define ADC_VREFPOS_1_bm  (1<<1)  /* Positive Reference Selection bit 1 mask. */
#define ADC_VREFPOS_1_bp  1  /* Positive Reference Selection bit 1 position. */
#define ADC_VREFPOS_2_bm  (1<<2)  /* Positive Reference Selection bit 2 mask. */
#define ADC_VREFPOS_2_bp  2  /* Positive Reference Selection bit 2 position. */
#define ADC_VREFNEG_bm  0x10  /* Negative Reference Selection bit mask. */
#define ADC_VREFNEG_bp  4  /* Negative Reference Selection bit position. */

/* ADC.CTRLD  bit masks and bit positions */
#define ADC_WINCM_gm  0x07  /* Window Comparator Mode group mask. */
#define ADC_WINCM_gp  0  /* Window Comparator Mode group position. */
#define ADC_WINCM_0_bm  (1<<0)  /* Window Comparator Mode bit 0 mask. */
#define ADC_WINCM_0_bp  0  /* Window Comparator Mode bit 0 position. */
#define ADC_WINCM_1_bm  (1<<1)  /* Window Comparator Mode bit 1 mask. */
#define ADC_WINCM_1_bp  1  /* Window Comparator Mode bit 1 position. */
#define ADC_WINCM_2_bm  (1<<2)  /* Window Comparator Mode bit 2 mask. */
#define ADC_WINCM_2_bp  2  /* Window Comparator Mode bit 2 position. */
#define ADC_WINSRC_gm  0x18  /* Window Mode Source group mask. */
#define ADC_WINSRC_gp  3  /* Window Mode Source group position. */
#define ADC_WINSRC_0_bm  (1<<3)  /* Window Mode Source bit 0 mask. */
#define ADC_WINSRC_0_bp  3  /* Window Mode Source bit 0 position. */
#define ADC_WINSRC_1_bm  (1<<4)  /* Window Mode Source bit 1 mask. */
#define ADC_WINSRC_1_bp  4  /* Window Mode Source bit 1 position. */

/* ADC.INTCTRL  bit masks and bit positions */
#define ADC_RESRDY_bm  0x01  /* Result Ready Interrupt Enable bit mask. */
#define ADC_RESRDY_bp  0  /* Result Ready Interrupt Enable bit position. */
#define ADC_SAMPRDY_bm  0x02  /* Sample Ready Interrupt Enable bit mask. */
#define ADC_SAMPRDY_bp  1  /* Sample Ready Interrupt Enable bit position. */
#define ADC_WCMP_bm  0x04  /* Window Comparator Interrupt Enable bit mask. */
#define ADC_WCMP_bp  2  /* Window Comparator Interrupt Enable bit position. */
#define ADC_RESOVR_bm  0x08  /* Result Overwrite Interrupt Enable bit mask. */
#define ADC_RESOVR_bp  3  /* Result Overwrite Interrupt Enable bit position. */
#define ADC_SAMPOVR_bm  0x10  /* Sample Overwrite Interrupt Enable bit mask. */
#define ADC_SAMPOVR_bp  4  /* Sample Overwrite Interrupt Enable bit position. */
#define ADC_TRIGOVR_bm  0x20  /* Trigger Overrun Interrupt Enable bit mask. */
#define ADC_TRIGOVR_bp  5  /* Trigger Overrun Interrupt Enable bit position. */

/* ADC.INTFLAGS  bit masks and bit positions */
/* ADC_RESRDY  is already defined. */
/* ADC_SAMPRDY  is already defined. */
/* ADC_WCMP  is already defined. */
/* ADC_RESOVR  is already defined. */
/* ADC_SAMPOVR  is already defined. */
/* ADC_TRIGOVR  is already defined. */

/* ADC.STATUS  bit masks and bit positions */
#define ADC_ADCBUSY_bm  0x01  /* ADC Busy bit mask. */
#define ADC_ADCBUSY_bp  0  /* ADC Busy bit position. */

/* ADC.DBGCTRL  bit masks and bit positions */
#define ADC_DBGRUN_bm  0x01  /* Run in Debug Mode bit mask. */
#define ADC_DBGRUN_bp  0  /* Run in Debug Mode bit position. */

/* ADC.CTRLE  bit masks and bit positions */
#define ADC_SAMPDUR_gm  0xFF  /* Sample Duration group mask. */
#define ADC_SAMPDUR_gp  0  /* Sample Duration group position. */
#define ADC_SAMPDUR_0_bm  (1<<0)  /* Sample Duration bit 0 mask. */
#define ADC_SAMPDUR_0_bp  0  /* Sample Duration bit 0 position. */
#define ADC_SAMPDUR_1_bm  (1<<1)  /* Sample Duration bit 1 mask. */
#define ADC_SAMPDUR_1_bp  1  /* Sample Duration bit 1 position. */
#define ADC_SAMPDUR_2_bm  (1<<2)  /* Sample Duration bit 2 mask. */
#define ADC_SAMPDUR_2_bp  2  /* Sample Duration bit 2 position. */
#define ADC_SAMPDUR_3_bm  (1<<3)  /* Sample Duration bit 3 mask. */
#define ADC_SAMPDUR_3_bp  3  /* Sample Duration bit 3 position. */
#define ADC_SAMPDUR_4_bm  (1<<4)  /* Sample Duration bit 4 mask. */
#define ADC_SAMPDUR_4_bp  4  /* Sample Duration bit 4 position. */
#define ADC_SAMPDUR_5_bm  (1<<5)  /* Sample Duration bit 5 mask. */
#define ADC_SAMPDUR_5_bp  5  /* Sample Duration bit 5 position. */
#define ADC_SAMPDUR_6_bm  (1<<6)  /* Sample Duration bit 6 mask. */
#define ADC_SAMPDUR_6_bp  6  /* Sample Duration bit 6 position. */
#define ADC_SAMPDUR_7_bm  (1<<7)  /* Sample Duration bit 7 mask. */
#define ADC_SAMPDUR_7_bp  7  /* Sample Duration bit 7 position. */

/* ADC.CTRLF  bit masks and bit positions */
#define ADC_SAMPNUM_gm  0x0F  /* Sample numbers group mask. */
#define ADC_SAMPNUM_gp  0  /* Sample numbers group position. */
#define ADC_SAMPNUM_0_bm  (1<<0)  /* Sample numbers bit 0 mask. */
#define ADC_SAMPNUM_0_bp  0  /* Sample numbers bit 0 position. */
#define ADC_SAMPNUM_1_bm  (1<<1)  /* Sample numbers bit 1 mask. */
#define ADC_SAMPNUM_1_bp  1  /* Sample numbers bit 1 position. */
#define ADC_SAMPNUM_2_bm  (1<<2)  /* Sample numbers bit 2 mask. */
#define ADC_SAMPNUM_2_bp  2  /* Sample numbers bit 2 position. */
#define ADC_SAMPNUM_3_bm  (1<<3)  /* Sample numbers bit 3 mask. */
#define ADC_SAMPNUM_3_bp  3  /* Sample numbers bit 3 position. */
#define ADC_LEFTADJ_bm  0x10  /* Left Adjust bit mask. */
#define ADC_LEFTADJ_bp  4  /* Left Adjust bit position. */
#define ADC_FREERUN_bm  0x20  /* Free-Running mode bit mask. */
#define ADC_FREERUN_bp  5  /* Free-Running mode bit position. */
#define ADC_CHOPPING_bm  0x40  /* Sign Chopping bit mask. */
#define ADC_CHOPPING_bp  6  /* Sign Chopping bit position. */

/* ADC.COMMAND  bit masks and bit positions */
#define ADC_START_gm  0x07  /* Start command group mask. */
#define ADC_START_gp  0  /* Start command group position. */
#define ADC_START_0_bm  (1<<0)  /* Start command bit 0 mask. */
#define ADC_START_0_bp  0  /* Start command bit 0 position. */
#define ADC_START_1_bm  (1<<1)  /* Start command bit 1 mask. */
#define ADC_START_1_bp  1  /* Start command bit 1 position. */
#define ADC_START_2_bm  (1<<2)  /* Start command bit 2 mask. */
#define ADC_START_2_bp  2  /* Start command bit 2 position. */
#define ADC_MODE_gm  0x70  /* Mode group mask. */
#define ADC_MODE_gp  4  /* Mode group position. */
#define ADC_MODE_0_bm  (1<<4)  /* Mode bit 0 mask. */
#define ADC_MODE_0_bp  4  /* Mode bit 0 position. */
#define ADC_MODE_1_bm  (1<<5)  /* Mode bit 1 mask. */
#define ADC_MODE_1_bp  5  /* Mode bit 1 position. */
#define ADC_MODE_2_bm  (1<<6)  /* Mode bit 2 mask. */
#define ADC_MODE_2_bp  6  /* Mode bit 2 position. */
#define ADC_DIFF_bm  0x80  /* Differential mode bit mask. */
#define ADC_DIFF_bp  7  /* Differential mode bit position. */

/* ADC.PGACTRL  bit masks and bit positions */
#define ADC_PGAEN_bm  0x01  /* PGA Enable bit mask. */
#define ADC_PGAEN_bp  0  /* PGA Enable bit position. */
#define ADC_OPAGAINEN_bm  0x02  /* OPAMP Gain Enable bit mask. */
#define ADC_OPAGAINEN_bp  1  /* OPAMP Gain Enable bit position. */
#define ADC_PGABIASSEL_gm  0x18  /* PGA BIAS Select group mask. */
#define ADC_PGABIASSEL_gp  3  /* PGA BIAS Select group position. */
#define ADC_PGABIASSEL_0_bm  (1<<3)  /* PGA BIAS Select bit 0 mask. */
#define ADC_PGABIASSEL_0_bp  3  /* PGA BIAS Select bit 0 position. */
#define ADC_PGABIASSEL_1_bm  (1<<4)  /* PGA BIAS Select bit 1 mask. */
#define ADC_PGABIASSEL_1_bp  4  /* PGA BIAS Select bit 1 position. */
#define ADC_GAIN_gm  0xE0  /* Gain group mask. */
#define ADC_GAIN_gp  5  /* Gain group position. */
#define ADC_GAIN_0_bm  (1<<5)  /* Gain bit 0 mask. */
#define ADC_GAIN_0_bp  5  /* Gain bit 0 position. */
#define ADC_GAIN_1_bm  (1<<6)  /* Gain bit 1 mask. */
#define ADC_GAIN_1_bp  6  /* Gain bit 1 position. */
#define ADC_GAIN_2_bm  (1<<7)  /* Gain bit 2 mask. */
#define ADC_GAIN_2_bp  7  /* Gain bit 2 position. */

/* ADC.MUXPOS  bit masks and bit positions */
#define ADC_MUXPOS_gm  0x3F  /* Analog Channel Selection Bits group mask. */
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

/* ADC.MUXNEG  bit masks and bit positions */
#define ADC_MUXNEG_gm  0x3F  /* Analog Channel Selection Bits group mask. */
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

/* ADC.PGAMUXPOS  bit masks and bit positions */
#define ADC_PGAMUXPOS_gm  0x3F  /* PGA Analog Channel Selection Bits group mask. */
#define ADC_PGAMUXPOS_gp  0  /* PGA Analog Channel Selection Bits group position. */
#define ADC_PGAMUXPOS_0_bm  (1<<0)  /* PGA Analog Channel Selection Bits bit 0 mask. */
#define ADC_PGAMUXPOS_0_bp  0  /* PGA Analog Channel Selection Bits bit 0 position. */
#define ADC_PGAMUXPOS_1_bm  (1<<1)  /* PGA Analog Channel Selection Bits bit 1 mask. */
#define ADC_PGAMUXPOS_1_bp  1  /* PGA Analog Channel Selection Bits bit 1 position. */
#define ADC_PGAMUXPOS_2_bm  (1<<2)  /* PGA Analog Channel Selection Bits bit 2 mask. */
#define ADC_PGAMUXPOS_2_bp  2  /* PGA Analog Channel Selection Bits bit 2 position. */
#define ADC_PGAMUXPOS_3_bm  (1<<3)  /* PGA Analog Channel Selection Bits bit 3 mask. */
#define ADC_PGAMUXPOS_3_bp  3  /* PGA Analog Channel Selection Bits bit 3 position. */
#define ADC_PGAMUXPOS_4_bm  (1<<4)  /* PGA Analog Channel Selection Bits bit 4 mask. */
#define ADC_PGAMUXPOS_4_bp  4  /* PGA Analog Channel Selection Bits bit 4 position. */
#define ADC_PGAMUXPOS_5_bm  (1<<5)  /* PGA Analog Channel Selection Bits bit 5 mask. */
#define ADC_PGAMUXPOS_5_bp  5  /* PGA Analog Channel Selection Bits bit 5 position. */

/* ADC.PGAMUXNEG  bit masks and bit positions */
#define ADC_PGAMUXNEG_gm  0x3F  /* PGA Analog Channel Selection Bits group mask. */
#define ADC_PGAMUXNEG_gp  0  /* PGA Analog Channel Selection Bits group position. */
#define ADC_PGAMUXNEG_0_bm  (1<<0)  /* PGA Analog Channel Selection Bits bit 0 mask. */
#define ADC_PGAMUXNEG_0_bp  0  /* PGA Analog Channel Selection Bits bit 0 position. */
#define ADC_PGAMUXNEG_1_bm  (1<<1)  /* PGA Analog Channel Selection Bits bit 1 mask. */
#define ADC_PGAMUXNEG_1_bp  1  /* PGA Analog Channel Selection Bits bit 1 position. */
#define ADC_PGAMUXNEG_2_bm  (1<<2)  /* PGA Analog Channel Selection Bits bit 2 mask. */
#define ADC_PGAMUXNEG_2_bp  2  /* PGA Analog Channel Selection Bits bit 2 position. */
#define ADC_PGAMUXNEG_3_bm  (1<<3)  /* PGA Analog Channel Selection Bits bit 3 mask. */
#define ADC_PGAMUXNEG_3_bp  3  /* PGA Analog Channel Selection Bits bit 3 position. */
#define ADC_PGAMUXNEG_4_bm  (1<<4)  /* PGA Analog Channel Selection Bits bit 4 mask. */
#define ADC_PGAMUXNEG_4_bp  4  /* PGA Analog Channel Selection Bits bit 4 position. */
#define ADC_PGAMUXNEG_5_bm  (1<<5)  /* PGA Analog Channel Selection Bits bit 5 mask. */
#define ADC_PGAMUXNEG_5_bp  5  /* PGA Analog Channel Selection Bits bit 5 position. */


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
#define CCL_SEQSEL_gm  0x0F  /* Sequential Selection group mask. */
#define CCL_SEQSEL_gp  0  /* Sequential Selection group position. */
#define CCL_SEQSEL_0_bm  (1<<0)  /* Sequential Selection bit 0 mask. */
#define CCL_SEQSEL_0_bp  0  /* Sequential Selection bit 0 position. */
#define CCL_SEQSEL_1_bm  (1<<1)  /* Sequential Selection bit 1 mask. */
#define CCL_SEQSEL_1_bp  1  /* Sequential Selection bit 1 position. */
#define CCL_SEQSEL_2_bm  (1<<2)  /* Sequential Selection bit 2 mask. */
#define CCL_SEQSEL_2_bp  2  /* Sequential Selection bit 2 position. */
#define CCL_SEQSEL_3_bm  (1<<3)  /* Sequential Selection bit 3 mask. */
#define CCL_SEQSEL_3_bp  3  /* Sequential Selection bit 3 position. */

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
#define CLKCTRL_CLKSEL_gm  0x0F  /* Clock select group mask. */
#define CLKCTRL_CLKSEL_gp  0  /* Clock select group position. */
#define CLKCTRL_CLKSEL_0_bm  (1<<0)  /* Clock select bit 0 mask. */
#define CLKCTRL_CLKSEL_0_bp  0  /* Clock select bit 0 position. */
#define CLKCTRL_CLKSEL_1_bm  (1<<1)  /* Clock select bit 1 mask. */
#define CLKCTRL_CLKSEL_1_bp  1  /* Clock select bit 1 position. */
#define CLKCTRL_CLKSEL_2_bm  (1<<2)  /* Clock select bit 2 mask. */
#define CLKCTRL_CLKSEL_2_bp  2  /* Clock select bit 2 position. */
#define CLKCTRL_CLKSEL_3_bm  (1<<3)  /* Clock select bit 3 mask. */
#define CLKCTRL_CLKSEL_3_bp  3  /* Clock select bit 3 position. */
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
#define CLKCTRL_PBDIV_bm  0x20  /* Prescaler B Division bit mask. */
#define CLKCTRL_PBDIV_bp  5  /* Prescaler B Division bit position. */

/* CLKCTRL.MCLKCTRLC  bit masks and bit positions */
#define CLKCTRL_CFDEN_bm  0x01  /* Clock Failure Detect Enable bit mask. */
#define CLKCTRL_CFDEN_bp  0  /* Clock Failure Detect Enable bit position. */
#define CLKCTRL_CFDTST_bm  0x02  /* CFD Test bit mask. */
#define CLKCTRL_CFDTST_bp  1  /* CFD Test bit position. */
#define CLKCTRL_CFDSRC_gm  0x0C  /* CFD Source group mask. */
#define CLKCTRL_CFDSRC_gp  2  /* CFD Source group position. */
#define CLKCTRL_CFDSRC_0_bm  (1<<2)  /* CFD Source bit 0 mask. */
#define CLKCTRL_CFDSRC_0_bp  2  /* CFD Source bit 0 position. */
#define CLKCTRL_CFDSRC_1_bm  (1<<3)  /* CFD Source bit 1 mask. */
#define CLKCTRL_CFDSRC_1_bp  3  /* CFD Source bit 1 position. */

/* CLKCTRL.MCLKINTCTRL  bit masks and bit positions */
#define CLKCTRL_CFD_bm  0x01  /* Interrupt Enable bit mask. */
#define CLKCTRL_CFD_bp  0  /* Interrupt Enable bit position. */
#define CLKCTRL_INTTYPE_bm  0x80  /* Interrupt Type bit mask. */
#define CLKCTRL_INTTYPE_bp  7  /* Interrupt Type bit position. */

/* CLKCTRL.MCLKINTFLAGS  bit masks and bit positions */
/* CLKCTRL_CFD  is already defined. */

/* CLKCTRL.MCLKSTATUS  bit masks and bit positions */
#define CLKCTRL_SOSC_bm  0x01  /* System Oscillator changing bit mask. */
#define CLKCTRL_SOSC_bp  0  /* System Oscillator changing bit position. */
#define CLKCTRL_OSCHFS_bm  0x02  /* High frequency oscillator status bit mask. */
#define CLKCTRL_OSCHFS_bp  1  /* High frequency oscillator status bit position. */
#define CLKCTRL_OSC32KS_bm  0x04  /* 32KHz oscillator status bit mask. */
#define CLKCTRL_OSC32KS_bp  2  /* 32KHz oscillator status bit position. */
#define CLKCTRL_XOSC32KS_bm  0x08  /* 32.768 kHz Crystal Oscillator status bit mask. */
#define CLKCTRL_XOSC32KS_bp  3  /* 32.768 kHz Crystal Oscillator status bit position. */
#define CLKCTRL_EXTS_bm  0x10  /* External Clock status / XOSCHF status bit mask. */
#define CLKCTRL_EXTS_bp  4  /* External Clock status / XOSCHF status bit position. */

/* CLKCTRL.MCLKTIMEBASE  bit masks and bit positions */
#define CLKCTRL_TIMEBASE_gm  0x1F  /* Timebase group mask. */
#define CLKCTRL_TIMEBASE_gp  0  /* Timebase group position. */
#define CLKCTRL_TIMEBASE_0_bm  (1<<0)  /* Timebase bit 0 mask. */
#define CLKCTRL_TIMEBASE_0_bp  0  /* Timebase bit 0 position. */
#define CLKCTRL_TIMEBASE_1_bm  (1<<1)  /* Timebase bit 1 mask. */
#define CLKCTRL_TIMEBASE_1_bp  1  /* Timebase bit 1 position. */
#define CLKCTRL_TIMEBASE_2_bm  (1<<2)  /* Timebase bit 2 mask. */
#define CLKCTRL_TIMEBASE_2_bp  2  /* Timebase bit 2 position. */
#define CLKCTRL_TIMEBASE_3_bm  (1<<3)  /* Timebase bit 3 mask. */
#define CLKCTRL_TIMEBASE_3_bp  3  /* Timebase bit 3 position. */
#define CLKCTRL_TIMEBASE_4_bm  (1<<4)  /* Timebase bit 4 mask. */
#define CLKCTRL_TIMEBASE_4_bp  4  /* Timebase bit 4 position. */

/* CLKCTRL.OSCHFCTRLA  bit masks and bit positions */
#define CLKCTRL_AUTOTUNE_gm  0x03  /* Automatic Oscillator Tune group mask. */
#define CLKCTRL_AUTOTUNE_gp  0  /* Automatic Oscillator Tune group position. */
#define CLKCTRL_AUTOTUNE_0_bm  (1<<0)  /* Automatic Oscillator Tune bit 0 mask. */
#define CLKCTRL_AUTOTUNE_0_bp  0  /* Automatic Oscillator Tune bit 0 position. */
#define CLKCTRL_AUTOTUNE_1_bm  (1<<1)  /* Automatic Oscillator Tune bit 1 mask. */
#define CLKCTRL_AUTOTUNE_1_bp  1  /* Automatic Oscillator Tune bit 1 position. */
#define CLKCTRL_RUNSTDBY_bm  0x80  /* Run in standby bit mask. */
#define CLKCTRL_RUNSTDBY_bp  7  /* Run in standby bit position. */

/* CLKCTRL.OSCHFTUNE  bit masks and bit positions */
#define CLKCTRL_TUNE_gm  0xFF  /* Oscillator Tune group mask. */
#define CLKCTRL_TUNE_gp  0  /* Oscillator Tune group position. */
#define CLKCTRL_TUNE_0_bm  (1<<0)  /* Oscillator Tune bit 0 mask. */
#define CLKCTRL_TUNE_0_bp  0  /* Oscillator Tune bit 0 position. */
#define CLKCTRL_TUNE_1_bm  (1<<1)  /* Oscillator Tune bit 1 mask. */
#define CLKCTRL_TUNE_1_bp  1  /* Oscillator Tune bit 1 position. */
#define CLKCTRL_TUNE_2_bm  (1<<2)  /* Oscillator Tune bit 2 mask. */
#define CLKCTRL_TUNE_2_bp  2  /* Oscillator Tune bit 2 position. */
#define CLKCTRL_TUNE_3_bm  (1<<3)  /* Oscillator Tune bit 3 mask. */
#define CLKCTRL_TUNE_3_bp  3  /* Oscillator Tune bit 3 position. */
#define CLKCTRL_TUNE_4_bm  (1<<4)  /* Oscillator Tune bit 4 mask. */
#define CLKCTRL_TUNE_4_bp  4  /* Oscillator Tune bit 4 position. */
#define CLKCTRL_TUNE_5_bm  (1<<5)  /* Oscillator Tune bit 5 mask. */
#define CLKCTRL_TUNE_5_bp  5  /* Oscillator Tune bit 5 position. */
#define CLKCTRL_TUNE_6_bm  (1<<6)  /* Oscillator Tune bit 6 mask. */
#define CLKCTRL_TUNE_6_bp  6  /* Oscillator Tune bit 6 position. */
#define CLKCTRL_TUNE_7_bm  (1<<7)  /* Oscillator Tune bit 7 mask. */
#define CLKCTRL_TUNE_7_bp  7  /* Oscillator Tune bit 7 position. */

/* CLKCTRL.OSC32KCTRLA  bit masks and bit positions */
/* CLKCTRL_RUNSTDBY  is already defined. */

/* CLKCTRL.XOSC32KCTRLA  bit masks and bit positions */
#define CLKCTRL_ENABLE_bm  0x01  /* Enable bit mask. */
#define CLKCTRL_ENABLE_bp  0  /* Enable bit position. */
#define CLKCTRL_PMODE_gm  0x06  /* Power mode group mask. */
#define CLKCTRL_PMODE_gp  1  /* Power mode group position. */
#define CLKCTRL_PMODE_0_bm  (1<<1)  /* Power mode bit 0 mask. */
#define CLKCTRL_PMODE_0_bp  1  /* Power mode bit 0 position. */
#define CLKCTRL_PMODE_1_bm  (1<<2)  /* Power mode bit 1 mask. */
#define CLKCTRL_PMODE_1_bp  2  /* Power mode bit 1 position. */
#define CLKCTRL_SEL_bm  0x08  /* Source Select bit mask. */
#define CLKCTRL_SEL_bp  3  /* Source Select bit position. */
#define CLKCTRL_CSUT_gm  0x30  /* Crystal startup time group mask. */
#define CLKCTRL_CSUT_gp  4  /* Crystal startup time group position. */
#define CLKCTRL_CSUT_0_bm  (1<<4)  /* Crystal startup time bit 0 mask. */
#define CLKCTRL_CSUT_0_bp  4  /* Crystal startup time bit 0 position. */
#define CLKCTRL_CSUT_1_bm  (1<<5)  /* Crystal startup time bit 1 mask. */
#define CLKCTRL_CSUT_1_bp  5  /* Crystal startup time bit 1 position. */
/* CLKCTRL_RUNSTDBY  is already defined. */

/* CLKCTRL.XOSCHFCTRLA  bit masks and bit positions */
/* CLKCTRL_ENABLE  is already defined. */
#define CLKCTRL_SELHF_bm  0x02  /* External source select bit mask. */
#define CLKCTRL_SELHF_bp  1  /* External source select bit position. */
#define CLKCTRL_CSUTHF_gm  0x30  /* Crystal startup time group mask. */
#define CLKCTRL_CSUTHF_gp  4  /* Crystal startup time group position. */
#define CLKCTRL_CSUTHF_0_bm  (1<<4)  /* Crystal startup time bit 0 mask. */
#define CLKCTRL_CSUTHF_0_bp  4  /* Crystal startup time bit 0 position. */
#define CLKCTRL_CSUTHF_1_bm  (1<<5)  /* Crystal startup time bit 1 mask. */
#define CLKCTRL_CSUTHF_1_bp  5  /* Crystal startup time bit 1 position. */
/* CLKCTRL_RUNSTDBY  is already defined. */


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

/* CPU.CTRLA  bit masks and bit positions */
#define CPU_SPLOCK_bm  0x01  /* SPLIM Lock bit mask. */
#define CPU_SPLOCK_bp  0  /* SPLIM Lock bit position. */

/* CPU.INTFLAGS  bit masks and bit positions */
#define CPU_OPC_bm  0x01  /* Illegal Opcode Error bit mask. */
#define CPU_OPC_bp  0  /* Illegal Opcode Error bit position. */
#define CPU_SPLIM_bm  0x04  /* Stack Pointer Limit Error bit mask. */
#define CPU_SPLIM_bp  2  /* Stack Pointer Limit Error bit position. */

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
#define CRCSCAN_ENABLE_bm  0x01  /* Enable CRCSCAN bit mask. */
#define CRCSCAN_ENABLE_bp  0  /* Enable CRCSCAN bit position. */
#define CRCSCAN_NMIEN_bm  0x02  /* Enable NMI Trigger bit mask. */
#define CRCSCAN_NMIEN_bp  1  /* Enable NMI Trigger bit position. */
#define CRCSCAN_CRCSEL_bm  0x08  /* CRC Mode Select bit mask. */
#define CRCSCAN_CRCSEL_bp  3  /* CRC Mode Select bit position. */
#define CRCSCAN_PEREN_bm  0x10  /* Enable Periodic Timer bit mask. */
#define CRCSCAN_PEREN_bp  4  /* Enable Periodic Timer bit position. */
#define CRCSCAN_SRC_gm  0x60  /* CRC Source group mask. */
#define CRCSCAN_SRC_gp  5  /* CRC Source group position. */
#define CRCSCAN_SRC_0_bm  (1<<5)  /* CRC Source bit 0 mask. */
#define CRCSCAN_SRC_0_bp  5  /* CRC Source bit 0 position. */
#define CRCSCAN_SRC_1_bm  (1<<6)  /* CRC Source bit 1 mask. */
#define CRCSCAN_SRC_1_bp  6  /* CRC Source bit 1 position. */
#define CRCSCAN_RESET_bm  0x80  /* Reset CRCSCAN bit mask. */
#define CRCSCAN_RESET_bp  7  /* Reset CRCSCAN bit position. */

/* CRCSCAN.CTRLB  bit masks and bit positions */
#define CRCSCAN_EINJ_bm  0x01  /* Inject CRC error bit mask. */
#define CRCSCAN_EINJ_bp  0  /* Inject CRC error bit position. */

/* CRCSCAN.INTCTRL  bit masks and bit positions */
#define CRCSCAN_DONE_bm  0x01  /* Scan Done Interrupt Enable bit mask. */
#define CRCSCAN_DONE_bp  0  /* Scan Done Interrupt Enable bit position. */
#define CRCSCAN_PERIOD_bm  0x02  /* Scan Period Done Interrupt Enable bit mask. */
#define CRCSCAN_PERIOD_bp  1  /* Scan Period Done Interrupt Enable bit position. */

/* CRCSCAN.INTFLAGS  bit masks and bit positions */
/* CRCSCAN_DONE  is already defined. */
/* CRCSCAN_PERIOD  is already defined. */

/* CRCSCAN.STATUSA  bit masks and bit positions */
#define CRCSCAN_ERROR_bm  0x01  /* Error Signal driving NMI bit mask. */
#define CRCSCAN_ERROR_bp  0  /* Error Signal driving NMI bit position. */
#define CRCSCAN_BUSY_bm  0x02  /* CRC BUSY bit mask. */
#define CRCSCAN_BUSY_bp  1  /* CRC BUSY bit position. */
#define CRCSCAN_OK_bm  0x04  /* CRC OK bit mask. */
#define CRCSCAN_OK_bp  2  /* CRC OK bit position. */

/* CRCSCAN.SCANADR  bit masks and bit positions */
#define CRCSCAN_SCANADR_gm  0xFF  /* Address Being Scanned group mask. */
#define CRCSCAN_SCANADR_gp  0  /* Address Being Scanned group position. */
#define CRCSCAN_SCANADR_0_bm  (1<<0)  /* Address Being Scanned bit 0 mask. */
#define CRCSCAN_SCANADR_0_bp  0  /* Address Being Scanned bit 0 position. */
#define CRCSCAN_SCANADR_1_bm  (1<<1)  /* Address Being Scanned bit 1 mask. */
#define CRCSCAN_SCANADR_1_bp  1  /* Address Being Scanned bit 1 position. */
#define CRCSCAN_SCANADR_2_bm  (1<<2)  /* Address Being Scanned bit 2 mask. */
#define CRCSCAN_SCANADR_2_bp  2  /* Address Being Scanned bit 2 position. */
#define CRCSCAN_SCANADR_3_bm  (1<<3)  /* Address Being Scanned bit 3 mask. */
#define CRCSCAN_SCANADR_3_bp  3  /* Address Being Scanned bit 3 position. */
#define CRCSCAN_SCANADR_4_bm  (1<<4)  /* Address Being Scanned bit 4 mask. */
#define CRCSCAN_SCANADR_4_bp  4  /* Address Being Scanned bit 4 position. */
#define CRCSCAN_SCANADR_5_bm  (1<<5)  /* Address Being Scanned bit 5 mask. */
#define CRCSCAN_SCANADR_5_bp  5  /* Address Being Scanned bit 5 position. */
#define CRCSCAN_SCANADR_6_bm  (1<<6)  /* Address Being Scanned bit 6 mask. */
#define CRCSCAN_SCANADR_6_bp  6  /* Address Being Scanned bit 6 position. */
#define CRCSCAN_SCANADR_7_bm  (1<<7)  /* Address Being Scanned bit 7 mask. */
#define CRCSCAN_SCANADR_7_bp  7  /* Address Being Scanned bit 7 position. */

/* CRCSCAN.DATA  bit masks and bit positions */
#define CRCSCAN_DATA_gm  0xFF  /* Input Data group mask. */
#define CRCSCAN_DATA_gp  0  /* Input Data group position. */
#define CRCSCAN_DATA_0_bm  (1<<0)  /* Input Data bit 0 mask. */
#define CRCSCAN_DATA_0_bp  0  /* Input Data bit 0 position. */
#define CRCSCAN_DATA_1_bm  (1<<1)  /* Input Data bit 1 mask. */
#define CRCSCAN_DATA_1_bp  1  /* Input Data bit 1 position. */
#define CRCSCAN_DATA_2_bm  (1<<2)  /* Input Data bit 2 mask. */
#define CRCSCAN_DATA_2_bp  2  /* Input Data bit 2 position. */
#define CRCSCAN_DATA_3_bm  (1<<3)  /* Input Data bit 3 mask. */
#define CRCSCAN_DATA_3_bp  3  /* Input Data bit 3 position. */
#define CRCSCAN_DATA_4_bm  (1<<4)  /* Input Data bit 4 mask. */
#define CRCSCAN_DATA_4_bp  4  /* Input Data bit 4 position. */
#define CRCSCAN_DATA_5_bm  (1<<5)  /* Input Data bit 5 mask. */
#define CRCSCAN_DATA_5_bp  5  /* Input Data bit 5 position. */
#define CRCSCAN_DATA_6_bm  (1<<6)  /* Input Data bit 6 mask. */
#define CRCSCAN_DATA_6_bp  6  /* Input Data bit 6 position. */
#define CRCSCAN_DATA_7_bm  (1<<7)  /* Input Data bit 7 mask. */
#define CRCSCAN_DATA_7_bp  7  /* Input Data bit 7 position. */

/* CRCSCAN.CRC  bit masks and bit positions */
#define CRCSCAN_CRC_gm  0xFFFFFFFF  /* CRC Result group mask. */
#define CRCSCAN_CRC_gp  0  /* CRC Result group position. */
#define CRCSCAN_CRC_0_bm  (1<<0)  /* CRC Result bit 0 mask. */
#define CRCSCAN_CRC_0_bp  0  /* CRC Result bit 0 position. */
#define CRCSCAN_CRC_1_bm  (1<<1)  /* CRC Result bit 1 mask. */
#define CRCSCAN_CRC_1_bp  1  /* CRC Result bit 1 position. */
#define CRCSCAN_CRC_2_bm  (1<<2)  /* CRC Result bit 2 mask. */
#define CRCSCAN_CRC_2_bp  2  /* CRC Result bit 2 position. */
#define CRCSCAN_CRC_3_bm  (1<<3)  /* CRC Result bit 3 mask. */
#define CRCSCAN_CRC_3_bp  3  /* CRC Result bit 3 position. */
#define CRCSCAN_CRC_4_bm  (1<<4)  /* CRC Result bit 4 mask. */
#define CRCSCAN_CRC_4_bp  4  /* CRC Result bit 4 position. */
#define CRCSCAN_CRC_5_bm  (1<<5)  /* CRC Result bit 5 mask. */
#define CRCSCAN_CRC_5_bp  5  /* CRC Result bit 5 position. */
#define CRCSCAN_CRC_6_bm  (1<<6)  /* CRC Result bit 6 mask. */
#define CRCSCAN_CRC_6_bp  6  /* CRC Result bit 6 position. */
#define CRCSCAN_CRC_7_bm  (1<<7)  /* CRC Result bit 7 mask. */
#define CRCSCAN_CRC_7_bp  7  /* CRC Result bit 7 position. */
#define CRCSCAN_CRC_8_bm  (1<<8)  /* CRC Result bit 8 mask. */
#define CRCSCAN_CRC_8_bp  8  /* CRC Result bit 8 position. */
#define CRCSCAN_CRC_9_bm  (1<<9)  /* CRC Result bit 9 mask. */
#define CRCSCAN_CRC_9_bp  9  /* CRC Result bit 9 position. */
#define CRCSCAN_CRC_10_bm  (1<<10)  /* CRC Result bit 10 mask. */
#define CRCSCAN_CRC_10_bp  10  /* CRC Result bit 10 position. */
#define CRCSCAN_CRC_11_bm  (1<<11)  /* CRC Result bit 11 mask. */
#define CRCSCAN_CRC_11_bp  11  /* CRC Result bit 11 position. */
#define CRCSCAN_CRC_12_bm  (1<<12)  /* CRC Result bit 12 mask. */
#define CRCSCAN_CRC_12_bp  12  /* CRC Result bit 12 position. */
#define CRCSCAN_CRC_13_bm  (1<<13)  /* CRC Result bit 13 mask. */
#define CRCSCAN_CRC_13_bp  13  /* CRC Result bit 13 position. */
#define CRCSCAN_CRC_14_bm  (1<<14)  /* CRC Result bit 14 mask. */
#define CRCSCAN_CRC_14_bp  14  /* CRC Result bit 14 position. */
#define CRCSCAN_CRC_15_bm  (1<<15)  /* CRC Result bit 15 mask. */
#define CRCSCAN_CRC_15_bp  15  /* CRC Result bit 15 position. */
#define CRCSCAN_CRC_16_bm  (1<<16)  /* CRC Result bit 16 mask. */
#define CRCSCAN_CRC_16_bp  16  /* CRC Result bit 16 position. */
#define CRCSCAN_CRC_17_bm  (1<<17)  /* CRC Result bit 17 mask. */
#define CRCSCAN_CRC_17_bp  17  /* CRC Result bit 17 position. */
#define CRCSCAN_CRC_18_bm  (1<<18)  /* CRC Result bit 18 mask. */
#define CRCSCAN_CRC_18_bp  18  /* CRC Result bit 18 position. */
#define CRCSCAN_CRC_19_bm  (1<<19)  /* CRC Result bit 19 mask. */
#define CRCSCAN_CRC_19_bp  19  /* CRC Result bit 19 position. */
#define CRCSCAN_CRC_20_bm  (1<<20)  /* CRC Result bit 20 mask. */
#define CRCSCAN_CRC_20_bp  20  /* CRC Result bit 20 position. */
#define CRCSCAN_CRC_21_bm  (1<<21)  /* CRC Result bit 21 mask. */
#define CRCSCAN_CRC_21_bp  21  /* CRC Result bit 21 position. */
#define CRCSCAN_CRC_22_bm  (1<<22)  /* CRC Result bit 22 mask. */
#define CRCSCAN_CRC_22_bp  22  /* CRC Result bit 22 position. */
#define CRCSCAN_CRC_23_bm  (1<<23)  /* CRC Result bit 23 mask. */
#define CRCSCAN_CRC_23_bp  23  /* CRC Result bit 23 position. */
#define CRCSCAN_CRC_24_bm  (1<<24)  /* CRC Result bit 24 mask. */
#define CRCSCAN_CRC_24_bp  24  /* CRC Result bit 24 position. */
#define CRCSCAN_CRC_25_bm  (1<<25)  /* CRC Result bit 25 mask. */
#define CRCSCAN_CRC_25_bp  25  /* CRC Result bit 25 position. */
#define CRCSCAN_CRC_26_bm  (1<<26)  /* CRC Result bit 26 mask. */
#define CRCSCAN_CRC_26_bp  26  /* CRC Result bit 26 position. */
#define CRCSCAN_CRC_27_bm  (1<<27)  /* CRC Result bit 27 mask. */
#define CRCSCAN_CRC_27_bp  27  /* CRC Result bit 27 position. */
#define CRCSCAN_CRC_28_bm  (1<<28)  /* CRC Result bit 28 mask. */
#define CRCSCAN_CRC_28_bp  28  /* CRC Result bit 28 position. */
#define CRCSCAN_CRC_29_bm  (1<<29)  /* CRC Result bit 29 mask. */
#define CRCSCAN_CRC_29_bp  29  /* CRC Result bit 29 position. */
#define CRCSCAN_CRC_30_bm  (1<<30)  /* CRC Result bit 30 mask. */
#define CRCSCAN_CRC_30_bp  30  /* CRC Result bit 30 position. */
#define CRCSCAN_CRC_31_bm  (1<<31)  /* CRC Result bit 31 mask. */
#define CRCSCAN_CRC_31_bp  31  /* CRC Result bit 31 position. */


/* DAC - Digital to Analog Converter */
/* DAC.CTRLA  bit masks and bit positions */
#define DAC_ENABLE_bm  0x01  /* DAC Enable bit mask. */
#define DAC_ENABLE_bp  0  /* DAC Enable bit position. */
#define DAC_LEFTADJ_bm  0x04  /* Left Adjust Data bit mask. */
#define DAC_LEFTADJ_bp  2  /* Left Adjust Data bit position. */
#define DAC_OUTRANGE_gm  0x30  /* Output Buffer Range group mask. */
#define DAC_OUTRANGE_gp  4  /* Output Buffer Range group position. */
#define DAC_OUTRANGE_0_bm  (1<<4)  /* Output Buffer Range bit 0 mask. */
#define DAC_OUTRANGE_0_bp  4  /* Output Buffer Range bit 0 position. */
#define DAC_OUTRANGE_1_bm  (1<<5)  /* Output Buffer Range bit 1 mask. */
#define DAC_OUTRANGE_1_bp  5  /* Output Buffer Range bit 1 position. */
#define DAC_OUTEN_bm  0x40  /* Output Buffer Enable bit mask. */
#define DAC_OUTEN_bp  6  /* Output Buffer Enable bit position. */
#define DAC_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define DAC_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */

/* DAC.EVCTRL  bit masks and bit positions */
#define DAC_TRIGEI_bm  0x01  /* Trigger Event Input Enable bit mask. */
#define DAC_TRIGEI_bp  0  /* Trigger Event Input Enable bit position. */
#define DAC_ONOFFEI_gm  0x0C  /* On and Off Event Input Enable group mask. */
#define DAC_ONOFFEI_gp  2  /* On and Off Event Input Enable group position. */
#define DAC_ONOFFEI_0_bm  (1<<2)  /* On and Off Event Input Enable bit 0 mask. */
#define DAC_ONOFFEI_0_bp  2  /* On and Off Event Input Enable bit 0 position. */
#define DAC_ONOFFEI_1_bm  (1<<3)  /* On and Off Event Input Enable bit 1 mask. */
#define DAC_ONOFFEI_1_bp  3  /* On and Off Event Input Enable bit 1 position. */

/* DAC.STATUS  bit masks and bit positions */
#define DAC_BUFRDY_bm  0x01  /* Data Buffer Ready bit mask. */
#define DAC_BUFRDY_bp  0  /* Data Buffer Ready bit position. */
#define DAC_STATE_bm  0x80  /* DAC State bit mask. */
#define DAC_STATE_bp  7  /* DAC State bit position. */

/* DAC.DATA  bit masks and bit positions */
#define DAC_DATA_gm  0x3FF  /* Data group mask. */
#define DAC_DATA_gp  0  /* Data group position. */
#define DAC_DATA_0_bm  (1<<0)  /* Data bit 0 mask. */
#define DAC_DATA_0_bp  0  /* Data bit 0 position. */
#define DAC_DATA_1_bm  (1<<1)  /* Data bit 1 mask. */
#define DAC_DATA_1_bp  1  /* Data bit 1 position. */
#define DAC_DATA_2_bm  (1<<2)  /* Data bit 2 mask. */
#define DAC_DATA_2_bp  2  /* Data bit 2 position. */
#define DAC_DATA_3_bm  (1<<3)  /* Data bit 3 mask. */
#define DAC_DATA_3_bp  3  /* Data bit 3 position. */
#define DAC_DATA_4_bm  (1<<4)  /* Data bit 4 mask. */
#define DAC_DATA_4_bp  4  /* Data bit 4 position. */
#define DAC_DATA_5_bm  (1<<5)  /* Data bit 5 mask. */
#define DAC_DATA_5_bp  5  /* Data bit 5 position. */
#define DAC_DATA_6_bm  (1<<6)  /* Data bit 6 mask. */
#define DAC_DATA_6_bp  6  /* Data bit 6 position. */
#define DAC_DATA_7_bm  (1<<7)  /* Data bit 7 mask. */
#define DAC_DATA_7_bp  7  /* Data bit 7 position. */
#define DAC_DATA_8_bm  (1<<8)  /* Data bit 8 mask. */
#define DAC_DATA_8_bp  8  /* Data bit 8 position. */
#define DAC_DATA_9_bm  (1<<9)  /* Data bit 9 mask. */
#define DAC_DATA_9_bp  9  /* Data bit 9 position. */


/* DIVA - Divide Accelerator */
/* DIVA.DIVCTRL  bit masks and bit positions */
#define DIVA_DIVOP_gm  0x0F  /* Divide Operation group mask. */
#define DIVA_DIVOP_gp  0  /* Divide Operation group position. */
#define DIVA_DIVOP_0_bm  (1<<0)  /* Divide Operation bit 0 mask. */
#define DIVA_DIVOP_0_bp  0  /* Divide Operation bit 0 position. */
#define DIVA_DIVOP_1_bm  (1<<1)  /* Divide Operation bit 1 mask. */
#define DIVA_DIVOP_1_bp  1  /* Divide Operation bit 1 position. */
#define DIVA_DIVOP_2_bm  (1<<2)  /* Divide Operation bit 2 mask. */
#define DIVA_DIVOP_2_bp  2  /* Divide Operation bit 2 position. */
#define DIVA_DIVOP_3_bm  (1<<3)  /* Divide Operation bit 3 mask. */
#define DIVA_DIVOP_3_bp  3  /* Divide Operation bit 3 position. */
#define DIVA_SIGN_bm  0x40  /* Signed Operation bit mask. */
#define DIVA_SIGN_bp  6  /* Signed Operation bit position. */
#define DIVA_LEADZERO_bm  0x80  /* Leading Zero Optimization bit mask. */
#define DIVA_LEADZERO_bp  7  /* Leading Zero Optimization bit position. */

/* DIVA.SHIFTCTRL  bit masks and bit positions */
#define DIVA_SHNUM_gm  0x1F  /* Number of shift or rotate operations group mask. */
#define DIVA_SHNUM_gp  0  /* Number of shift or rotate operations group position. */
#define DIVA_SHNUM_0_bm  (1<<0)  /* Number of shift or rotate operations bit 0 mask. */
#define DIVA_SHNUM_0_bp  0  /* Number of shift or rotate operations bit 0 position. */
#define DIVA_SHNUM_1_bm  (1<<1)  /* Number of shift or rotate operations bit 1 mask. */
#define DIVA_SHNUM_1_bp  1  /* Number of shift or rotate operations bit 1 position. */
#define DIVA_SHNUM_2_bm  (1<<2)  /* Number of shift or rotate operations bit 2 mask. */
#define DIVA_SHNUM_2_bp  2  /* Number of shift or rotate operations bit 2 position. */
#define DIVA_SHNUM_3_bm  (1<<3)  /* Number of shift or rotate operations bit 3 mask. */
#define DIVA_SHNUM_3_bp  3  /* Number of shift or rotate operations bit 3 position. */
#define DIVA_SHNUM_4_bm  (1<<4)  /* Number of shift or rotate operations bit 4 mask. */
#define DIVA_SHNUM_4_bp  4  /* Number of shift or rotate operations bit 4 position. */
#define DIVA_SHOP_gm  0x60  /* Shift operation group mask. */
#define DIVA_SHOP_gp  5  /* Shift operation group position. */
#define DIVA_SHOP_0_bm  (1<<5)  /* Shift operation bit 0 mask. */
#define DIVA_SHOP_0_bp  5  /* Shift operation bit 0 position. */
#define DIVA_SHOP_1_bm  (1<<6)  /* Shift operation bit 1 mask. */
#define DIVA_SHOP_1_bp  6  /* Shift operation bit 1 position. */
#define DIVA_XORPREV_bm  0x80  /* XOR with previous result bit mask. */
#define DIVA_XORPREV_bp  7  /* XOR with previous result bit position. */

/* DIVA.STATUS  bit masks and bit positions */
#define DIVA_BUSY_bm  0x01  /* Accelerator Busy bit mask. */
#define DIVA_BUSY_bp  0  /* Accelerator Busy bit position. */
#define DIVA_DBZ_bm  0x02  /* Divide-by-Zero bit mask. */
#define DIVA_DBZ_bp  1  /* Divide-by-Zero bit position. */


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

/* EVSYS.USERUSART0RXD  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERUSART1RXD  bit masks and bit positions */
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

/* EVSYS.USERTCB2CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB2COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB3CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB3COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCF0COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCF0ACTION  bit masks and bit positions */
/* EVSYS_USER  is already defined. */


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
#define FUSE_SLEEP_gm  0x03  /* BOD Operation in Power Down and Standby Sleep Modes group mask. */
#define FUSE_SLEEP_gp  0  /* BOD Operation in Power Down and Standby Sleep Modes group position. */
#define FUSE_SLEEP_0_bm  (1<<0)  /* BOD Operation in Power Down and Standby Sleep Modes bit 0 mask. */
#define FUSE_SLEEP_0_bp  0  /* BOD Operation in Power Down and Standby Sleep Modes bit 0 position. */
#define FUSE_SLEEP_1_bm  (1<<1)  /* BOD Operation in Power Down and Standby Sleep Modes bit 1 mask. */
#define FUSE_SLEEP_1_bp  1  /* BOD Operation in Power Down and Standby Sleep Modes bit 1 position. */
#define FUSE_ACTIVE_gm  0x0C  /* BOD Operation in Active and Idle Sleep Modes group mask. */
#define FUSE_ACTIVE_gp  2  /* BOD Operation in Active and Idle Sleep Modes group position. */
#define FUSE_ACTIVE_0_bm  (1<<2)  /* BOD Operation in Active and Idle Sleep Modes bit 0 mask. */
#define FUSE_ACTIVE_0_bp  2  /* BOD Operation in Active and Idle Sleep Modes bit 0 position. */
#define FUSE_ACTIVE_1_bm  (1<<3)  /* BOD Operation in Active and Idle Sleep Modes bit 1 mask. */
#define FUSE_ACTIVE_1_bp  3  /* BOD Operation in Active and Idle Sleep Modes bit 1 position. */
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
#define FUSE_OSCHFFRQ_bm  0x08  /* High-frequency Oscillator Frequency bit mask. */
#define FUSE_OSCHFFRQ_bp  3  /* High-frequency Oscillator Frequency bit position. */

/* FUSE.PINCFG  bit masks and bit positions */
#define FUSE_RSTPINCFG_bm  0x01  /* Configuration of Reset pin at startup bit mask. */
#define FUSE_RSTPINCFG_bp  0  /* Configuration of Reset pin at startup bit position. */
#define FUSE_UPDIPINCFG_bm  0x02  /* Configuration of UPDI pin at startup bit mask. */
#define FUSE_UPDIPINCFG_bp  1  /* Configuration of UPDI pin at startup bit position. */
#define FUSE_MVSYSCFG_bm  0x04  /* MVIO System Configuration bit mask. */
#define FUSE_MVSYSCFG_bp  2  /* MVIO System Configuration bit position. */

/* FUSE.HWMONCFG  bit masks and bit positions */
#define FUSE_CPUMON_bm  0x01  /* CPU hardware monitor bit mask. */
#define FUSE_CPUMON_bp  0  /* CPU hardware monitor bit position. */

/* FUSE.SYSCFG0  bit masks and bit positions */
#define FUSE_EESAVE_bm  0x01  /* EEPROM saved during chip erase bit mask. */
#define FUSE_EESAVE_bp  0  /* EEPROM saved during chip erase bit position. */
#define FUSE_BOOTROWSAVE_bm  0x02  /* BOOTROW saved during chip erase bit mask. */
#define FUSE_BOOTROWSAVE_bp  1  /* BOOTROW saved during chip erase bit position. */
#define FUSE_CRCSEL_bm  0x40  /* CRC polynomial selection bit mask. */
#define FUSE_CRCSEL_bp  6  /* CRC polynomial selection bit position. */
#define FUSE_CRCBOOT_bm  0x80  /* CRC Check on BOOT during system initialization bit mask. */
#define FUSE_CRCBOOT_bp  7  /* CRC Check on BOOT during system initialization bit position. */

/* FUSE.SYSCFG1  bit masks and bit positions */
#define FUSE_SUT_gm  0x07  /* Startup Time group mask. */
#define FUSE_SUT_gp  0  /* Startup Time group position. */
#define FUSE_SUT_0_bm  (1<<0)  /* Startup Time bit 0 mask. */
#define FUSE_SUT_0_bp  0  /* Startup Time bit 0 position. */
#define FUSE_SUT_1_bm  (1<<1)  /* Startup Time bit 1 mask. */
#define FUSE_SUT_1_bp  1  /* Startup Time bit 1 position. */
#define FUSE_SUT_2_bm  (1<<2)  /* Startup Time bit 2 mask. */
#define FUSE_SUT_2_bp  2  /* Startup Time bit 2 position. */

/* FUSE.PDICFG  bit masks and bit positions */
#define FUSE_LEVEL_gm  0x03  /* PDI Protection Level group mask. */
#define FUSE_LEVEL_gp  0  /* PDI Protection Level group position. */
#define FUSE_LEVEL_0_bm  (1<<0)  /* PDI Protection Level bit 0 mask. */
#define FUSE_LEVEL_0_bp  0  /* PDI Protection Level bit 0 position. */
#define FUSE_LEVEL_1_bm  (1<<1)  /* PDI Protection Level bit 1 mask. */
#define FUSE_LEVEL_1_bp  1  /* PDI Protection Level bit 1 position. */
#define FUSE_KEY_gm  0xFFF0  /* PDI Protection Activation Key group mask. */
#define FUSE_KEY_gp  4  /* PDI Protection Activation Key group position. */
#define FUSE_KEY_0_bm  (1<<4)  /* PDI Protection Activation Key bit 0 mask. */
#define FUSE_KEY_0_bp  4  /* PDI Protection Activation Key bit 0 position. */
#define FUSE_KEY_1_bm  (1<<5)  /* PDI Protection Activation Key bit 1 mask. */
#define FUSE_KEY_1_bp  5  /* PDI Protection Activation Key bit 1 position. */
#define FUSE_KEY_2_bm  (1<<6)  /* PDI Protection Activation Key bit 2 mask. */
#define FUSE_KEY_2_bp  6  /* PDI Protection Activation Key bit 2 position. */
#define FUSE_KEY_3_bm  (1<<7)  /* PDI Protection Activation Key bit 3 mask. */
#define FUSE_KEY_3_bp  7  /* PDI Protection Activation Key bit 3 position. */
#define FUSE_KEY_4_bm  (1<<8)  /* PDI Protection Activation Key bit 4 mask. */
#define FUSE_KEY_4_bp  8  /* PDI Protection Activation Key bit 4 position. */
#define FUSE_KEY_5_bm  (1<<9)  /* PDI Protection Activation Key bit 5 mask. */
#define FUSE_KEY_5_bp  9  /* PDI Protection Activation Key bit 5 position. */
#define FUSE_KEY_6_bm  (1<<10)  /* PDI Protection Activation Key bit 6 mask. */
#define FUSE_KEY_6_bp  10  /* PDI Protection Activation Key bit 6 position. */
#define FUSE_KEY_7_bm  (1<<11)  /* PDI Protection Activation Key bit 7 mask. */
#define FUSE_KEY_7_bp  11  /* PDI Protection Activation Key bit 7 position. */
#define FUSE_KEY_8_bm  (1<<12)  /* PDI Protection Activation Key bit 8 mask. */
#define FUSE_KEY_8_bp  12  /* PDI Protection Activation Key bit 8 position. */
#define FUSE_KEY_9_bm  (1<<13)  /* PDI Protection Activation Key bit 9 mask. */
#define FUSE_KEY_9_bp  13  /* PDI Protection Activation Key bit 9 position. */
#define FUSE_KEY_10_bm  (1<<14)  /* PDI Protection Activation Key bit 10 mask. */
#define FUSE_KEY_10_bp  14  /* PDI Protection Activation Key bit 10 position. */
#define FUSE_KEY_11_bm  (1<<15)  /* PDI Protection Activation Key bit 11 mask. */
#define FUSE_KEY_11_bp  15  /* PDI Protection Activation Key bit 11 position. */



/* LOCK - Lockbits */
/* LOCK.KEY  bit masks and bit positions */
#define LOCK_KEY_gm  0xFFFFFFFF  /* Lock Key group mask. */
#define LOCK_KEY_gp  0  /* Lock Key group position. */
#define LOCK_KEY_0_bm  (1<<0)  /* Lock Key bit 0 mask. */
#define LOCK_KEY_0_bp  0  /* Lock Key bit 0 position. */
#define LOCK_KEY_1_bm  (1<<1)  /* Lock Key bit 1 mask. */
#define LOCK_KEY_1_bp  1  /* Lock Key bit 1 position. */
#define LOCK_KEY_2_bm  (1<<2)  /* Lock Key bit 2 mask. */
#define LOCK_KEY_2_bp  2  /* Lock Key bit 2 position. */
#define LOCK_KEY_3_bm  (1<<3)  /* Lock Key bit 3 mask. */
#define LOCK_KEY_3_bp  3  /* Lock Key bit 3 position. */
#define LOCK_KEY_4_bm  (1<<4)  /* Lock Key bit 4 mask. */
#define LOCK_KEY_4_bp  4  /* Lock Key bit 4 position. */
#define LOCK_KEY_5_bm  (1<<5)  /* Lock Key bit 5 mask. */
#define LOCK_KEY_5_bp  5  /* Lock Key bit 5 position. */
#define LOCK_KEY_6_bm  (1<<6)  /* Lock Key bit 6 mask. */
#define LOCK_KEY_6_bp  6  /* Lock Key bit 6 position. */
#define LOCK_KEY_7_bm  (1<<7)  /* Lock Key bit 7 mask. */
#define LOCK_KEY_7_bp  7  /* Lock Key bit 7 position. */
#define LOCK_KEY_8_bm  (1<<8)  /* Lock Key bit 8 mask. */
#define LOCK_KEY_8_bp  8  /* Lock Key bit 8 position. */
#define LOCK_KEY_9_bm  (1<<9)  /* Lock Key bit 9 mask. */
#define LOCK_KEY_9_bp  9  /* Lock Key bit 9 position. */
#define LOCK_KEY_10_bm  (1<<10)  /* Lock Key bit 10 mask. */
#define LOCK_KEY_10_bp  10  /* Lock Key bit 10 position. */
#define LOCK_KEY_11_bm  (1<<11)  /* Lock Key bit 11 mask. */
#define LOCK_KEY_11_bp  11  /* Lock Key bit 11 position. */
#define LOCK_KEY_12_bm  (1<<12)  /* Lock Key bit 12 mask. */
#define LOCK_KEY_12_bp  12  /* Lock Key bit 12 position. */
#define LOCK_KEY_13_bm  (1<<13)  /* Lock Key bit 13 mask. */
#define LOCK_KEY_13_bp  13  /* Lock Key bit 13 position. */
#define LOCK_KEY_14_bm  (1<<14)  /* Lock Key bit 14 mask. */
#define LOCK_KEY_14_bp  14  /* Lock Key bit 14 position. */
#define LOCK_KEY_15_bm  (1<<15)  /* Lock Key bit 15 mask. */
#define LOCK_KEY_15_bp  15  /* Lock Key bit 15 position. */
#define LOCK_KEY_16_bm  (1<<16)  /* Lock Key bit 16 mask. */
#define LOCK_KEY_16_bp  16  /* Lock Key bit 16 position. */
#define LOCK_KEY_17_bm  (1<<17)  /* Lock Key bit 17 mask. */
#define LOCK_KEY_17_bp  17  /* Lock Key bit 17 position. */
#define LOCK_KEY_18_bm  (1<<18)  /* Lock Key bit 18 mask. */
#define LOCK_KEY_18_bp  18  /* Lock Key bit 18 position. */
#define LOCK_KEY_19_bm  (1<<19)  /* Lock Key bit 19 mask. */
#define LOCK_KEY_19_bp  19  /* Lock Key bit 19 position. */
#define LOCK_KEY_20_bm  (1<<20)  /* Lock Key bit 20 mask. */
#define LOCK_KEY_20_bp  20  /* Lock Key bit 20 position. */
#define LOCK_KEY_21_bm  (1<<21)  /* Lock Key bit 21 mask. */
#define LOCK_KEY_21_bp  21  /* Lock Key bit 21 position. */
#define LOCK_KEY_22_bm  (1<<22)  /* Lock Key bit 22 mask. */
#define LOCK_KEY_22_bp  22  /* Lock Key bit 22 position. */
#define LOCK_KEY_23_bm  (1<<23)  /* Lock Key bit 23 mask. */
#define LOCK_KEY_23_bp  23  /* Lock Key bit 23 position. */
#define LOCK_KEY_24_bm  (1<<24)  /* Lock Key bit 24 mask. */
#define LOCK_KEY_24_bp  24  /* Lock Key bit 24 position. */
#define LOCK_KEY_25_bm  (1<<25)  /* Lock Key bit 25 mask. */
#define LOCK_KEY_25_bp  25  /* Lock Key bit 25 position. */
#define LOCK_KEY_26_bm  (1<<26)  /* Lock Key bit 26 mask. */
#define LOCK_KEY_26_bp  26  /* Lock Key bit 26 position. */
#define LOCK_KEY_27_bm  (1<<27)  /* Lock Key bit 27 mask. */
#define LOCK_KEY_27_bp  27  /* Lock Key bit 27 position. */
#define LOCK_KEY_28_bm  (1<<28)  /* Lock Key bit 28 mask. */
#define LOCK_KEY_28_bp  28  /* Lock Key bit 28 position. */
#define LOCK_KEY_29_bm  (1<<29)  /* Lock Key bit 29 mask. */
#define LOCK_KEY_29_bp  29  /* Lock Key bit 29 position. */
#define LOCK_KEY_30_bm  (1<<30)  /* Lock Key bit 30 mask. */
#define LOCK_KEY_30_bp  30  /* Lock Key bit 30 position. */
#define LOCK_KEY_31_bm  (1<<31)  /* Lock Key bit 31 mask. */
#define LOCK_KEY_31_bp  31  /* Lock Key bit 31 position. */


/* MVIO - Multi-Voltage I/O */
/* MVIO.CTRLA  bit masks and bit positions */
#define MVIO_MODE_bm  0x01  /* Operation mode bit mask. */
#define MVIO_MODE_bp  0  /* Operation mode bit position. */
#define MVIO_VDDIO2CFG_gm  0x0C  /* VDDIO2 Configuration group mask. */
#define MVIO_VDDIO2CFG_gp  2  /* VDDIO2 Configuration group position. */
#define MVIO_VDDIO2CFG_0_bm  (1<<2)  /* VDDIO2 Configuration bit 0 mask. */
#define MVIO_VDDIO2CFG_0_bp  2  /* VDDIO2 Configuration bit 0 position. */
#define MVIO_VDDIO2CFG_1_bm  (1<<3)  /* VDDIO2 Configuration bit 1 mask. */
#define MVIO_VDDIO2CFG_1_bp  3  /* VDDIO2 Configuration bit 1 position. */

/* MVIO.INTCTRL  bit masks and bit positions */
#define MVIO_VDDIO2_bm  0x01  /* VDDIO2 Interrupt Enable bit mask. */
#define MVIO_VDDIO2_bp  0  /* VDDIO2 Interrupt Enable bit position. */
#define MVIO_ERROR_bm  0x02  /* VDDIO2 Error Interrupt Enable bit mask. */
#define MVIO_ERROR_bp  1  /* VDDIO2 Error Interrupt Enable bit position. */

/* MVIO.INTFLAGS  bit masks and bit positions */
/* MVIO_VDDIO2  is already defined. */
/* MVIO_ERROR  is already defined. */

/* MVIO.STATUS  bit masks and bit positions */
/* MVIO_VDDIO2  is already defined. */
/* MVIO_ERROR  is already defined. */


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
#define NVMCTRL_EEWP_bm  0x08  /* EEPROM Write Protect bit mask. */
#define NVMCTRL_EEWP_bp  3  /* EEPROM Write Protect bit position. */
#define NVMCTRL_FLMAP_gm  0x30  /* Flash Mapping in Data space group mask. */
#define NVMCTRL_FLMAP_gp  4  /* Flash Mapping in Data space group position. */
#define NVMCTRL_FLMAP_0_bm  (1<<4)  /* Flash Mapping in Data space bit 0 mask. */
#define NVMCTRL_FLMAP_0_bp  4  /* Flash Mapping in Data space bit 0 position. */
#define NVMCTRL_FLMAP_1_bm  (1<<5)  /* Flash Mapping in Data space bit 1 mask. */
#define NVMCTRL_FLMAP_1_bp  5  /* Flash Mapping in Data space bit 1 position. */
#define NVMCTRL_FLMAPLOCK_bm  0x80  /* Flash Mapping Lock bit mask. */
#define NVMCTRL_FLMAPLOCK_bp  7  /* Flash Mapping Lock bit position. */

/* NVMCTRL.CTRLC  bit masks and bit positions */
#define NVMCTRL_UROWWP_bm  0x01  /* User Row Write Protect bit mask. */
#define NVMCTRL_UROWWP_bp  0  /* User Row Write Protect bit position. */
#define NVMCTRL_BOOTROWWP_bm  0x02  /* Boot Row Write Protect bit mask. */
#define NVMCTRL_BOOTROWWP_bp  1  /* Boot Row Write Protect bit position. */

/* NVMCTRL.INTCTRL  bit masks and bit positions */
#define NVMCTRL_EEREADY_bm  0x01  /* EEPROM Ready bit mask. */
#define NVMCTRL_EEREADY_bp  0  /* EEPROM Ready bit position. */
#define NVMCTRL_FLREADY_bm  0x02  /* Flash Ready bit mask. */
#define NVMCTRL_FLREADY_bp  1  /* Flash Ready bit position. */

/* NVMCTRL.INTFLAGS  bit masks and bit positions */
/* NVMCTRL_EEREADY  is already defined. */
/* NVMCTRL_FLREADY  is already defined. */

/* NVMCTRL.STATUS  bit masks and bit positions */
#define NVMCTRL_EEBUSY_bm  0x01  /* EEPROM busy bit mask. */
#define NVMCTRL_EEBUSY_bp  0  /* EEPROM busy bit position. */
#define NVMCTRL_FLBUSY_bm  0x02  /* Flash busy bit mask. */
#define NVMCTRL_FLBUSY_bp  1  /* Flash busy bit position. */
#define NVMCTRL_ERROR_gm  0x70  /* Write error group mask. */
#define NVMCTRL_ERROR_gp  4  /* Write error group position. */
#define NVMCTRL_ERROR_0_bm  (1<<4)  /* Write error bit 0 mask. */
#define NVMCTRL_ERROR_0_bp  4  /* Write error bit 0 position. */
#define NVMCTRL_ERROR_1_bm  (1<<5)  /* Write error bit 1 mask. */
#define NVMCTRL_ERROR_1_bp  5  /* Write error bit 1 position. */
#define NVMCTRL_ERROR_2_bm  (1<<6)  /* Write error bit 2 mask. */
#define NVMCTRL_ERROR_2_bp  6  /* Write error bit 2 position. */

/* NVMCTRL.ADDR  bit masks and bit positions */
#define NVMCTRL_ADDR_gm  0xFFFFFF  /* Address group mask. */
#define NVMCTRL_ADDR_gp  0  /* Address group position. */
#define NVMCTRL_ADDR_0_bm  (1<<0)  /* Address bit 0 mask. */
#define NVMCTRL_ADDR_0_bp  0  /* Address bit 0 position. */
#define NVMCTRL_ADDR_1_bm  (1<<1)  /* Address bit 1 mask. */
#define NVMCTRL_ADDR_1_bp  1  /* Address bit 1 position. */
#define NVMCTRL_ADDR_2_bm  (1<<2)  /* Address bit 2 mask. */
#define NVMCTRL_ADDR_2_bp  2  /* Address bit 2 position. */
#define NVMCTRL_ADDR_3_bm  (1<<3)  /* Address bit 3 mask. */
#define NVMCTRL_ADDR_3_bp  3  /* Address bit 3 position. */
#define NVMCTRL_ADDR_4_bm  (1<<4)  /* Address bit 4 mask. */
#define NVMCTRL_ADDR_4_bp  4  /* Address bit 4 position. */
#define NVMCTRL_ADDR_5_bm  (1<<5)  /* Address bit 5 mask. */
#define NVMCTRL_ADDR_5_bp  5  /* Address bit 5 position. */
#define NVMCTRL_ADDR_6_bm  (1<<6)  /* Address bit 6 mask. */
#define NVMCTRL_ADDR_6_bp  6  /* Address bit 6 position. */
#define NVMCTRL_ADDR_7_bm  (1<<7)  /* Address bit 7 mask. */
#define NVMCTRL_ADDR_7_bp  7  /* Address bit 7 position. */
#define NVMCTRL_ADDR_8_bm  (1<<8)  /* Address bit 8 mask. */
#define NVMCTRL_ADDR_8_bp  8  /* Address bit 8 position. */
#define NVMCTRL_ADDR_9_bm  (1<<9)  /* Address bit 9 mask. */
#define NVMCTRL_ADDR_9_bp  9  /* Address bit 9 position. */
#define NVMCTRL_ADDR_10_bm  (1<<10)  /* Address bit 10 mask. */
#define NVMCTRL_ADDR_10_bp  10  /* Address bit 10 position. */
#define NVMCTRL_ADDR_11_bm  (1<<11)  /* Address bit 11 mask. */
#define NVMCTRL_ADDR_11_bp  11  /* Address bit 11 position. */
#define NVMCTRL_ADDR_12_bm  (1<<12)  /* Address bit 12 mask. */
#define NVMCTRL_ADDR_12_bp  12  /* Address bit 12 position. */
#define NVMCTRL_ADDR_13_bm  (1<<13)  /* Address bit 13 mask. */
#define NVMCTRL_ADDR_13_bp  13  /* Address bit 13 position. */
#define NVMCTRL_ADDR_14_bm  (1<<14)  /* Address bit 14 mask. */
#define NVMCTRL_ADDR_14_bp  14  /* Address bit 14 position. */
#define NVMCTRL_ADDR_15_bm  (1<<15)  /* Address bit 15 mask. */
#define NVMCTRL_ADDR_15_bp  15  /* Address bit 15 position. */
#define NVMCTRL_ADDR_16_bm  (1<<16)  /* Address bit 16 mask. */
#define NVMCTRL_ADDR_16_bp  16  /* Address bit 16 position. */
#define NVMCTRL_ADDR_17_bm  (1<<17)  /* Address bit 17 mask. */
#define NVMCTRL_ADDR_17_bp  17  /* Address bit 17 position. */
#define NVMCTRL_ADDR_18_bm  (1<<18)  /* Address bit 18 mask. */
#define NVMCTRL_ADDR_18_bp  18  /* Address bit 18 position. */
#define NVMCTRL_ADDR_19_bm  (1<<19)  /* Address bit 19 mask. */
#define NVMCTRL_ADDR_19_bp  19  /* Address bit 19 position. */
#define NVMCTRL_ADDR_20_bm  (1<<20)  /* Address bit 20 mask. */
#define NVMCTRL_ADDR_20_bp  20  /* Address bit 20 position. */
#define NVMCTRL_ADDR_21_bm  (1<<21)  /* Address bit 21 mask. */
#define NVMCTRL_ADDR_21_bp  21  /* Address bit 21 position. */
#define NVMCTRL_ADDR_22_bm  (1<<22)  /* Address bit 22 mask. */
#define NVMCTRL_ADDR_22_bp  22  /* Address bit 22 position. */
#define NVMCTRL_ADDR_23_bm  (1<<23)  /* Address bit 23 mask. */
#define NVMCTRL_ADDR_23_bp  23  /* Address bit 23 position. */


/* OPAMP - Operational Amplifier System */
/* OPAMP.CTRLA  bit masks and bit positions */
#define OPAMP_ENABLE_bm  0x01  /* Op Amp System Enable bit mask. */
#define OPAMP_ENABLE_bp  0  /* Op Amp System Enable bit position. */

/* OPAMP.DBGCTRL  bit masks and bit positions */
#define OPAMP_DBGRUN_bm  0x01  /* Run in Debug Mode bit mask. */
#define OPAMP_DBGRUN_bp  0  /* Run in Debug Mode bit position. */

/* OPAMP.OP0CTRLA  bit masks and bit positions */
#define OPAMP_ALWAYSON_bm  0x01  /* Always On bit mask. */
#define OPAMP_ALWAYSON_bp  0  /* Always On bit position. */
#define OPAMP_EVENTEN_bm  0x02  /* Enable Events bit mask. */
#define OPAMP_EVENTEN_bp  1  /* Enable Events bit position. */
#define OPAMP_OUTMODE_bm  0x04  /* Output Mode bit mask. */
#define OPAMP_OUTMODE_bp  2  /* Output Mode bit position. */
#define OPAMP_CALIBEN_bm  0x40  /* Calibration Enable bit mask. */
#define OPAMP_CALIBEN_bp  6  /* Calibration Enable bit position. */
#define OPAMP_RUNSTBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define OPAMP_RUNSTBY_bp  7  /* Run in Standby Mode bit position. */

/* OPAMP.OP0STATUS  bit masks and bit positions */
#define OPAMP_SETTLED_bm  0x01  /* Settled bit mask. */
#define OPAMP_SETTLED_bp  0  /* Settled bit position. */
#define OPAMP_CALBUSY_bm  0x10  /* Calibration ongoing bit mask. */
#define OPAMP_CALBUSY_bp  4  /* Calibration ongoing bit position. */

/* OPAMP.OP0RESMUX  bit masks and bit positions */
#define OPAMP_MUXTOP_gm  0x03  /* Multiplexer Top group mask. */
#define OPAMP_MUXTOP_gp  0  /* Multiplexer Top group position. */
#define OPAMP_MUXTOP_0_bm  (1<<0)  /* Multiplexer Top bit 0 mask. */
#define OPAMP_MUXTOP_0_bp  0  /* Multiplexer Top bit 0 position. */
#define OPAMP_MUXTOP_1_bm  (1<<1)  /* Multiplexer Top bit 1 mask. */
#define OPAMP_MUXTOP_1_bp  1  /* Multiplexer Top bit 1 position. */
#define OPAMP_MUXBOT_gm  0x1C  /* Multiplexer Bottom group mask. */
#define OPAMP_MUXBOT_gp  2  /* Multiplexer Bottom group position. */
#define OPAMP_MUXBOT_0_bm  (1<<2)  /* Multiplexer Bottom bit 0 mask. */
#define OPAMP_MUXBOT_0_bp  2  /* Multiplexer Bottom bit 0 position. */
#define OPAMP_MUXBOT_1_bm  (1<<3)  /* Multiplexer Bottom bit 1 mask. */
#define OPAMP_MUXBOT_1_bp  3  /* Multiplexer Bottom bit 1 position. */
#define OPAMP_MUXBOT_2_bm  (1<<4)  /* Multiplexer Bottom bit 2 mask. */
#define OPAMP_MUXBOT_2_bp  4  /* Multiplexer Bottom bit 2 position. */
#define OPAMP_MUXWIP_gm  0xE0  /* Multiplexer Wiper selector group mask. */
#define OPAMP_MUXWIP_gp  5  /* Multiplexer Wiper selector group position. */
#define OPAMP_MUXWIP_0_bm  (1<<5)  /* Multiplexer Wiper selector bit 0 mask. */
#define OPAMP_MUXWIP_0_bp  5  /* Multiplexer Wiper selector bit 0 position. */
#define OPAMP_MUXWIP_1_bm  (1<<6)  /* Multiplexer Wiper selector bit 1 mask. */
#define OPAMP_MUXWIP_1_bp  6  /* Multiplexer Wiper selector bit 1 position. */
#define OPAMP_MUXWIP_2_bm  (1<<7)  /* Multiplexer Wiper selector bit 2 mask. */
#define OPAMP_MUXWIP_2_bp  7  /* Multiplexer Wiper selector bit 2 position. */

/* OPAMP.OP0INMUX  bit masks and bit positions */
#define OPAMP_MUXPOS_gm  0x0F  /* Positive Input Multiplexer group mask. */
#define OPAMP_MUXPOS_gp  0  /* Positive Input Multiplexer group position. */
#define OPAMP_MUXPOS_0_bm  (1<<0)  /* Positive Input Multiplexer bit 0 mask. */
#define OPAMP_MUXPOS_0_bp  0  /* Positive Input Multiplexer bit 0 position. */
#define OPAMP_MUXPOS_1_bm  (1<<1)  /* Positive Input Multiplexer bit 1 mask. */
#define OPAMP_MUXPOS_1_bp  1  /* Positive Input Multiplexer bit 1 position. */
#define OPAMP_MUXPOS_2_bm  (1<<2)  /* Positive Input Multiplexer bit 2 mask. */
#define OPAMP_MUXPOS_2_bp  2  /* Positive Input Multiplexer bit 2 position. */
#define OPAMP_MUXPOS_3_bm  (1<<3)  /* Positive Input Multiplexer bit 3 mask. */
#define OPAMP_MUXPOS_3_bp  3  /* Positive Input Multiplexer bit 3 position. */
#define OPAMP_MUXNEG_gm  0xF0  /* Negative Input Multiplexer group mask. */
#define OPAMP_MUXNEG_gp  4  /* Negative Input Multiplexer group position. */
#define OPAMP_MUXNEG_0_bm  (1<<4)  /* Negative Input Multiplexer bit 0 mask. */
#define OPAMP_MUXNEG_0_bp  4  /* Negative Input Multiplexer bit 0 position. */
#define OPAMP_MUXNEG_1_bm  (1<<5)  /* Negative Input Multiplexer bit 1 mask. */
#define OPAMP_MUXNEG_1_bp  5  /* Negative Input Multiplexer bit 1 position. */
#define OPAMP_MUXNEG_2_bm  (1<<6)  /* Negative Input Multiplexer bit 2 mask. */
#define OPAMP_MUXNEG_2_bp  6  /* Negative Input Multiplexer bit 2 position. */
#define OPAMP_MUXNEG_3_bm  (1<<7)  /* Negative Input Multiplexer bit 3 mask. */
#define OPAMP_MUXNEG_3_bp  7  /* Negative Input Multiplexer bit 3 position. */

/* OPAMP.OP0SETTLE  bit masks and bit positions */
#define OPAMP_SETTLE_gm  0x7F  /* Settle Time group mask. */
#define OPAMP_SETTLE_gp  0  /* Settle Time group position. */
#define OPAMP_SETTLE_0_bm  (1<<0)  /* Settle Time bit 0 mask. */
#define OPAMP_SETTLE_0_bp  0  /* Settle Time bit 0 position. */
#define OPAMP_SETTLE_1_bm  (1<<1)  /* Settle Time bit 1 mask. */
#define OPAMP_SETTLE_1_bp  1  /* Settle Time bit 1 position. */
#define OPAMP_SETTLE_2_bm  (1<<2)  /* Settle Time bit 2 mask. */
#define OPAMP_SETTLE_2_bp  2  /* Settle Time bit 2 position. */
#define OPAMP_SETTLE_3_bm  (1<<3)  /* Settle Time bit 3 mask. */
#define OPAMP_SETTLE_3_bp  3  /* Settle Time bit 3 position. */
#define OPAMP_SETTLE_4_bm  (1<<4)  /* Settle Time bit 4 mask. */
#define OPAMP_SETTLE_4_bp  4  /* Settle Time bit 4 position. */
#define OPAMP_SETTLE_5_bm  (1<<5)  /* Settle Time bit 5 mask. */
#define OPAMP_SETTLE_5_bp  5  /* Settle Time bit 5 position. */
#define OPAMP_SETTLE_6_bm  (1<<6)  /* Settle Time bit 6 mask. */
#define OPAMP_SETTLE_6_bp  6  /* Settle Time bit 6 position. */

/* OPAMP.OP0CAL  bit masks and bit positions */
#define OPAMP_CAL_gm  0xFF  /* Calibration (for input offset voltage) group mask. */
#define OPAMP_CAL_gp  0  /* Calibration (for input offset voltage) group position. */
#define OPAMP_CAL_0_bm  (1<<0)  /* Calibration (for input offset voltage) bit 0 mask. */
#define OPAMP_CAL_0_bp  0  /* Calibration (for input offset voltage) bit 0 position. */
#define OPAMP_CAL_1_bm  (1<<1)  /* Calibration (for input offset voltage) bit 1 mask. */
#define OPAMP_CAL_1_bp  1  /* Calibration (for input offset voltage) bit 1 position. */
#define OPAMP_CAL_2_bm  (1<<2)  /* Calibration (for input offset voltage) bit 2 mask. */
#define OPAMP_CAL_2_bp  2  /* Calibration (for input offset voltage) bit 2 position. */
#define OPAMP_CAL_3_bm  (1<<3)  /* Calibration (for input offset voltage) bit 3 mask. */
#define OPAMP_CAL_3_bp  3  /* Calibration (for input offset voltage) bit 3 position. */
#define OPAMP_CAL_4_bm  (1<<4)  /* Calibration (for input offset voltage) bit 4 mask. */
#define OPAMP_CAL_4_bp  4  /* Calibration (for input offset voltage) bit 4 position. */
#define OPAMP_CAL_5_bm  (1<<5)  /* Calibration (for input offset voltage) bit 5 mask. */
#define OPAMP_CAL_5_bp  5  /* Calibration (for input offset voltage) bit 5 position. */
#define OPAMP_CAL_6_bm  (1<<6)  /* Calibration (for input offset voltage) bit 6 mask. */
#define OPAMP_CAL_6_bp  6  /* Calibration (for input offset voltage) bit 6 position. */
#define OPAMP_CAL_7_bm  (1<<7)  /* Calibration (for input offset voltage) bit 7 mask. */
#define OPAMP_CAL_7_bp  7  /* Calibration (for input offset voltage) bit 7 position. */

/* OPAMP.OP1CTRLA  bit masks and bit positions */
/* OPAMP_ALWAYSON  is already defined. */
/* OPAMP_EVENTEN  is already defined. */
/* OPAMP_OUTMODE  is already defined. */
/* OPAMP_CALIBEN  is already defined. */
/* OPAMP_RUNSTBY  is already defined. */

/* OPAMP.OP1STATUS  bit masks and bit positions */
/* OPAMP_SETTLED  is already defined. */
/* OPAMP_CALBUSY  is already defined. */

/* OPAMP.OP1RESMUX  bit masks and bit positions */
/* OPAMP_MUXTOP  is already defined. */
/* OPAMP_MUXBOT  is already defined. */
/* OPAMP_MUXWIP  is already defined. */

/* OPAMP.OP1INMUX  bit masks and bit positions */
/* OPAMP_MUXPOS  is already defined. */
/* OPAMP_MUXNEG  is already defined. */

/* OPAMP.OP1SETTLE  bit masks and bit positions */
/* OPAMP_SETTLE  is already defined. */

/* OPAMP.OP1CAL  bit masks and bit positions */
/* OPAMP_CAL  is already defined. */


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

/* PORT.EVGENCTRLA  bit masks and bit positions */
#define PORT_EVGEN0SEL_gm  0x07  /* Event Generator 0 Select group mask. */
#define PORT_EVGEN0SEL_gp  0  /* Event Generator 0 Select group position. */
#define PORT_EVGEN0SEL_0_bm  (1<<0)  /* Event Generator 0 Select bit 0 mask. */
#define PORT_EVGEN0SEL_0_bp  0  /* Event Generator 0 Select bit 0 position. */
#define PORT_EVGEN0SEL_1_bm  (1<<1)  /* Event Generator 0 Select bit 1 mask. */
#define PORT_EVGEN0SEL_1_bp  1  /* Event Generator 0 Select bit 1 position. */
#define PORT_EVGEN0SEL_2_bm  (1<<2)  /* Event Generator 0 Select bit 2 mask. */
#define PORT_EVGEN0SEL_2_bp  2  /* Event Generator 0 Select bit 2 position. */
#define PORT_EVGEN1SEL_gm  0x70  /* Event Generator 1 Select group mask. */
#define PORT_EVGEN1SEL_gp  4  /* Event Generator 1 Select group position. */
#define PORT_EVGEN1SEL_0_bm  (1<<4)  /* Event Generator 1 Select bit 0 mask. */
#define PORT_EVGEN1SEL_0_bp  4  /* Event Generator 1 Select bit 0 position. */
#define PORT_EVGEN1SEL_1_bm  (1<<5)  /* Event Generator 1 Select bit 1 mask. */
#define PORT_EVGEN1SEL_1_bp  5  /* Event Generator 1 Select bit 1 position. */
#define PORT_EVGEN1SEL_2_bm  (1<<6)  /* Event Generator 1 Select bit 2 mask. */
#define PORT_EVGEN1SEL_2_bp  6  /* Event Generator 1 Select bit 2 position. */


/* PORTMUX - Port Multiplexer */
/* PORTMUX.EVSYSROUTEA  bit masks and bit positions */
#define PORTMUX_EVOUTA_bm  0x01  /* Event Output A bit mask. */
#define PORTMUX_EVOUTA_bp  0  /* Event Output A bit position. */
#define PORTMUX_EVOUTC_bm  0x04  /* Event Output C bit mask. */
#define PORTMUX_EVOUTC_bp  2  /* Event Output C bit position. */
#define PORTMUX_EVOUTD_bm  0x08  /* Event Output D bit mask. */
#define PORTMUX_EVOUTD_bp  3  /* Event Output D bit position. */
#define PORTMUX_EVOUTF_bm  0x20  /* Event Output F bit mask. */
#define PORTMUX_EVOUTF_bp  5  /* Event Output F bit position. */

/* PORTMUX.CCLROUTEA  bit masks and bit positions */
#define PORTMUX_LUT0_bm  0x01  /* CCL Look-Up Table 0 Signals bit mask. */
#define PORTMUX_LUT0_bp  0  /* CCL Look-Up Table 0 Signals bit position. */
#define PORTMUX_LUT1_bm  0x02  /* CCL Look-Up Table 1 Signals bit mask. */
#define PORTMUX_LUT1_bp  1  /* CCL Look-Up Table 1 Signals bit position. */
#define PORTMUX_LUT2_bm  0x04  /* CCL Look-Up Table 2 Signals bit mask. */
#define PORTMUX_LUT2_bp  2  /* CCL Look-Up Table 2 Signals bit position. */

/* PORTMUX.USARTROUTEA  bit masks and bit positions */
#define PORTMUX_USART0_gm  0x07  /* USART0 Routing group mask. */
#define PORTMUX_USART0_gp  0  /* USART0 Routing group position. */
#define PORTMUX_USART0_0_bm  (1<<0)  /* USART0 Routing bit 0 mask. */
#define PORTMUX_USART0_0_bp  0  /* USART0 Routing bit 0 position. */
#define PORTMUX_USART0_1_bm  (1<<1)  /* USART0 Routing bit 1 mask. */
#define PORTMUX_USART0_1_bp  1  /* USART0 Routing bit 1 position. */
#define PORTMUX_USART0_2_bm  (1<<2)  /* USART0 Routing bit 2 mask. */
#define PORTMUX_USART0_2_bp  2  /* USART0 Routing bit 2 position. */
#define PORTMUX_USART1_gm  0x18  /* USART1 Routing group mask. */
#define PORTMUX_USART1_gp  3  /* USART1 Routing group position. */
#define PORTMUX_USART1_0_bm  (1<<3)  /* USART1 Routing bit 0 mask. */
#define PORTMUX_USART1_0_bp  3  /* USART1 Routing bit 0 position. */
#define PORTMUX_USART1_1_bm  (1<<4)  /* USART1 Routing bit 1 mask. */
#define PORTMUX_USART1_1_bp  4  /* USART1 Routing bit 1 position. */

/* PORTMUX.SPIROUTEA  bit masks and bit positions */
#define PORTMUX_SPI0_gm  0x07  /* SPI0 Signals group mask. */
#define PORTMUX_SPI0_gp  0  /* SPI0 Signals group position. */
#define PORTMUX_SPI0_0_bm  (1<<0)  /* SPI0 Signals bit 0 mask. */
#define PORTMUX_SPI0_0_bp  0  /* SPI0 Signals bit 0 position. */
#define PORTMUX_SPI0_1_bm  (1<<1)  /* SPI0 Signals bit 1 mask. */
#define PORTMUX_SPI0_1_bp  1  /* SPI0 Signals bit 1 position. */
#define PORTMUX_SPI0_2_bm  (1<<2)  /* SPI0 Signals bit 2 mask. */
#define PORTMUX_SPI0_2_bp  2  /* SPI0 Signals bit 2 position. */

/* PORTMUX.TWIROUTEA  bit masks and bit positions */
#define PORTMUX_TWI0_gm  0x03  /* TWI0 Signals group mask. */
#define PORTMUX_TWI0_gp  0  /* TWI0 Signals group position. */
#define PORTMUX_TWI0_0_bm  (1<<0)  /* TWI0 Signals bit 0 mask. */
#define PORTMUX_TWI0_0_bp  0  /* TWI0 Signals bit 0 position. */
#define PORTMUX_TWI0_1_bm  (1<<1)  /* TWI0 Signals bit 1 mask. */
#define PORTMUX_TWI0_1_bp  1  /* TWI0 Signals bit 1 position. */

/* PORTMUX.TCEROUTEA  bit masks and bit positions */
#define PORTMUX_TCE0_gm  0x0F  /* TCE0 Signals group mask. */
#define PORTMUX_TCE0_gp  0  /* TCE0 Signals group position. */
#define PORTMUX_TCE0_0_bm  (1<<0)  /* TCE0 Signals bit 0 mask. */
#define PORTMUX_TCE0_0_bp  0  /* TCE0 Signals bit 0 position. */
#define PORTMUX_TCE0_1_bm  (1<<1)  /* TCE0 Signals bit 1 mask. */
#define PORTMUX_TCE0_1_bp  1  /* TCE0 Signals bit 1 position. */
#define PORTMUX_TCE0_2_bm  (1<<2)  /* TCE0 Signals bit 2 mask. */
#define PORTMUX_TCE0_2_bp  2  /* TCE0 Signals bit 2 position. */
#define PORTMUX_TCE0_3_bm  (1<<3)  /* TCE0 Signals bit 3 mask. */
#define PORTMUX_TCE0_3_bp  3  /* TCE0 Signals bit 3 position. */

/* PORTMUX.TCBROUTEA  bit masks and bit positions */
#define PORTMUX_TCB0_bm  0x01  /* TCB0 Output bit mask. */
#define PORTMUX_TCB0_bp  0  /* TCB0 Output bit position. */
#define PORTMUX_TCB1_bm  0x02  /* TCB1 Output bit mask. */
#define PORTMUX_TCB1_bp  1  /* TCB1 Output bit position. */
#define PORTMUX_TCB2_bm  0x04  /* TCB2 Output bit mask. */
#define PORTMUX_TCB2_bp  2  /* TCB2 Output bit position. */
#define PORTMUX_TCB3_bm  0x08  /* TCB3 Output bit mask. */
#define PORTMUX_TCB3_bp  3  /* TCB3 Output bit position. */

/* PORTMUX.ACROUTEA  bit masks and bit positions */
#define PORTMUX_AC0_bm  0x01  /* Analog Comparator 0 Output bit mask. */
#define PORTMUX_AC0_bp  0  /* Analog Comparator 0 Output bit position. */

/* PORTMUX.TCFROUTE  bit masks and bit positions */
#define PORTMUX_TCF0_gm  0x03  /* TCF0 Output group mask. */
#define PORTMUX_TCF0_gp  0  /* TCF0 Output group position. */
#define PORTMUX_TCF0_0_bm  (1<<0)  /* TCF0 Output bit 0 mask. */
#define PORTMUX_TCF0_0_bp  0  /* TCF0 Output bit 0 position. */
#define PORTMUX_TCF0_1_bm  (1<<1)  /* TCF0 Output bit 1 mask. */
#define PORTMUX_TCF0_1_bp  1  /* TCF0 Output bit 1 position. */


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
#define RSTCTRL_SWRE_bm  0x01  /* Software Reset Enable bit mask. */
#define RSTCTRL_SWRE_bp  0  /* Software Reset Enable bit position. */


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
#define SPI_MASTER_bm  0x20  /* Host Operation Enable bit mask. */
#define SPI_MASTER_bp  5  /* Host Operation Enable bit position. */
#define SPI_DORD_bm  0x40  /* Data Order Setting bit mask. */
#define SPI_DORD_bp  6  /* Data Order Setting bit position. */

/* SPI.CTRLB  bit masks and bit positions */
#define SPI_MODE_gm  0x03  /* SPI Mode group mask. */
#define SPI_MODE_gp  0  /* SPI Mode group position. */
#define SPI_MODE_0_bm  (1<<0)  /* SPI Mode bit 0 mask. */
#define SPI_MODE_0_bp  0  /* SPI Mode bit 0 position. */
#define SPI_MODE_1_bm  (1<<1)  /* SPI Mode bit 1 mask. */
#define SPI_MODE_1_bp  1  /* SPI Mode bit 1 position. */
#define SPI_SSD_bm  0x04  /* SPI Select Disable bit mask. */
#define SPI_SSD_bp  2  /* SPI Select Disable bit position. */
#define SPI_BUFWR_bm  0x40  /* Buffer Mode Wait for Receive bit mask. */
#define SPI_BUFWR_bp  6  /* Buffer Mode Wait for Receive bit position. */
#define SPI_BUFEN_bm  0x80  /* Buffer Mode Enable bit mask. */
#define SPI_BUFEN_bp  7  /* Buffer Mode Enable bit position. */

/* SPI.INTCTRL  bit masks and bit positions */
#define SPI_IE_bm  0x01  /* Interrupt Enable bit mask. */
#define SPI_IE_bp  0  /* Interrupt Enable bit position. */
#define SPI_SSIE_bm  0x10  /* SPI Select Trigger Interrupt Enable bit mask. */
#define SPI_SSIE_bp  4  /* SPI Select Trigger Interrupt Enable bit position. */
#define SPI_DREIE_bm  0x20  /* Data Register Empty Interrupt Enable bit mask. */
#define SPI_DREIE_bp  5  /* Data Register Empty Interrupt Enable bit position. */
#define SPI_TXCIE_bm  0x40  /* Transfer Complete Interrupt Enable bit mask. */
#define SPI_TXCIE_bp  6  /* Transfer Complete Interrupt Enable bit position. */
#define SPI_RXCIE_bm  0x80  /* Receive Complete Interrupt Enable bit mask. */
#define SPI_RXCIE_bp  7  /* Receive Complete Interrupt Enable bit position. */

/* SPI.INTFLAGS  bit masks and bit positions */
#define SPI_BUFOVF_bm  0x01  /* Buffer Overflow bit mask. */
#define SPI_BUFOVF_bp  0  /* Buffer Overflow bit position. */
#define SPI_SSIF_bm  0x10  /* SPI Select Trigger Interrupt Flag bit mask. */
#define SPI_SSIF_bp  4  /* SPI Select Trigger Interrupt Flag bit position. */
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
/* SYSCFG.REVID  bit masks and bit positions */
#define SYSCFG_MINOR_gm  0x0F  /* Minor Revision group mask. */
#define SYSCFG_MINOR_gp  0  /* Minor Revision group position. */
#define SYSCFG_MINOR_0_bm  (1<<0)  /* Minor Revision bit 0 mask. */
#define SYSCFG_MINOR_0_bp  0  /* Minor Revision bit 0 position. */
#define SYSCFG_MINOR_1_bm  (1<<1)  /* Minor Revision bit 1 mask. */
#define SYSCFG_MINOR_1_bp  1  /* Minor Revision bit 1 position. */
#define SYSCFG_MINOR_2_bm  (1<<2)  /* Minor Revision bit 2 mask. */
#define SYSCFG_MINOR_2_bp  2  /* Minor Revision bit 2 position. */
#define SYSCFG_MINOR_3_bm  (1<<3)  /* Minor Revision bit 3 mask. */
#define SYSCFG_MINOR_3_bp  3  /* Minor Revision bit 3 position. */
#define SYSCFG_MAJOR_gm  0xF0  /* Major Revision group mask. */
#define SYSCFG_MAJOR_gp  4  /* Major Revision group position. */
#define SYSCFG_MAJOR_0_bm  (1<<4)  /* Major Revision bit 0 mask. */
#define SYSCFG_MAJOR_0_bp  4  /* Major Revision bit 0 position. */
#define SYSCFG_MAJOR_1_bm  (1<<5)  /* Major Revision bit 1 mask. */
#define SYSCFG_MAJOR_1_bp  5  /* Major Revision bit 1 position. */
#define SYSCFG_MAJOR_2_bm  (1<<6)  /* Major Revision bit 2 mask. */
#define SYSCFG_MAJOR_2_bp  6  /* Major Revision bit 2 position. */
#define SYSCFG_MAJOR_3_bm  (1<<7)  /* Major Revision bit 3 mask. */
#define SYSCFG_MAJOR_3_bp  7  /* Major Revision bit 3 position. */

/* SYSCFG.VDDCTRL  bit masks and bit positions */
#define SYSCFG_VDDR_bm  0x01  /* VDD Range bit mask. */
#define SYSCFG_VDDR_bp  0  /* VDD Range bit position. */
#define SYSCFG_VDDIO2R_bm  0x02  /* VDDIO2 Range bit mask. */
#define SYSCFG_VDDIO2R_bp  1  /* VDDIO2 Range bit position. */


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

/* TCE.CTRLC  bit masks and bit positions */
#define TCE_CMP0OV_bm  0x01  /* Compare 0 Waveform Output Value bit mask. */
#define TCE_CMP0OV_bp  0  /* Compare 0 Waveform Output Value bit position. */
#define TCE_CMP1OV_bm  0x02  /* Compare 1 Waveform Output Value bit mask. */
#define TCE_CMP1OV_bp  1  /* Compare 1 Waveform Output Value bit position. */
#define TCE_CMP2OV_bm  0x04  /* Compare 2 Waveform Output Value bit mask. */
#define TCE_CMP2OV_bp  2  /* Compare 2 Waveform Output Value bit position. */
#define TCE_CMP0POL_bm  0x10  /* Compare 0 Polarity bit mask. */
#define TCE_CMP0POL_bp  4  /* Compare 0 Polarity bit position. */
#define TCE_CMP1POL_bm  0x20  /* Compare 1 Polarity bit mask. */
#define TCE_CMP1POL_bp  5  /* Compare 1 Polarity bit position. */
#define TCE_CMP2POL_bm  0x40  /* Compare 2 Polarity bit mask. */
#define TCE_CMP2POL_bp  6  /* Compare 2 Polarity bit position. */

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

/* TCE.CTRLFSET  bit masks and bit positions */
/* TCE_PERBV  is already defined. */
/* TCE_CMP0BV  is already defined. */
/* TCE_CMP1BV  is already defined. */
/* TCE_CMP2BV  is already defined. */

/* TCE.EVGENCTRL  bit masks and bit positions */
#define TCE_CMP0EV_bm  0x10  /* Compare 0 Event bit mask. */
#define TCE_CMP0EV_bp  4  /* Compare 0 Event bit position. */
#define TCE_CMP1EV_bm  0x20  /* Compare 1 Event bit mask. */
#define TCE_CMP1EV_bp  5  /* Compare 1 Event bit position. */
#define TCE_CMP2EV_bm  0x40  /* Compare 2 Event bit mask. */
#define TCE_CMP2EV_bp  6  /* Compare 2 Event bit position. */

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

/* TCE.INTFLAGS  bit masks and bit positions */
/* TCE_OVF  is already defined. */
/* TCE_CMP0  is already defined. */
/* TCE_CMP1  is already defined. */
/* TCE_CMP2  is already defined. */

/* TCE.DBGCTRL  bit masks and bit positions */
#define TCE_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCE_DBGRUN_bp  0  /* Debug Run bit position. */


/* TCF - 24-bit Timer/Counter for frequency generation */
/* TCF.CTRLA  bit masks and bit positions */
#define TCF_ENABLE_bm  0x01  /* Enable bit mask. */
#define TCF_ENABLE_bp  0  /* Enable bit position. */
#define TCF_PRESC_gm  0x0E  /* Prescaler Select group mask. */
#define TCF_PRESC_gp  1  /* Prescaler Select group position. */
#define TCF_PRESC_0_bm  (1<<1)  /* Prescaler Select bit 0 mask. */
#define TCF_PRESC_0_bp  1  /* Prescaler Select bit 0 position. */
#define TCF_PRESC_1_bm  (1<<2)  /* Prescaler Select bit 1 mask. */
#define TCF_PRESC_1_bp  2  /* Prescaler Select bit 1 position. */
#define TCF_PRESC_2_bm  (1<<3)  /* Prescaler Select bit 2 mask. */
#define TCF_PRESC_2_bp  3  /* Prescaler Select bit 2 position. */
#define TCF_RUNSTDBY_bm  0x80  /* Run Standby bit mask. */
#define TCF_RUNSTDBY_bp  7  /* Run Standby bit position. */

/* TCF.CTRLB  bit masks and bit positions */
#define TCF_CNTMODE_gm  0x07  /* Counter Operation Mode group mask. */
#define TCF_CNTMODE_gp  0  /* Counter Operation Mode group position. */
#define TCF_CNTMODE_0_bm  (1<<0)  /* Counter Operation Mode bit 0 mask. */
#define TCF_CNTMODE_0_bp  0  /* Counter Operation Mode bit 0 position. */
#define TCF_CNTMODE_1_bm  (1<<1)  /* Counter Operation Mode bit 1 mask. */
#define TCF_CNTMODE_1_bp  1  /* Counter Operation Mode bit 1 position. */
#define TCF_CNTMODE_2_bm  (1<<2)  /* Counter Operation Mode bit 2 mask. */
#define TCF_CNTMODE_2_bp  2  /* Counter Operation Mode bit 2 position. */
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
#define TCF_CMD_gm  0x07  /* Command group mask. */
#define TCF_CMD_gp  0  /* Command group position. */
#define TCF_CMD_0_bm  (1<<0)  /* Command bit 0 mask. */
#define TCF_CMD_0_bp  0  /* Command bit 0 position. */
#define TCF_CMD_1_bm  (1<<1)  /* Command bit 1 mask. */
#define TCF_CMD_1_bp  1  /* Command bit 1 position. */
#define TCF_CMD_2_bm  (1<<2)  /* Command bit 2 mask. */
#define TCF_CMD_2_bp  2  /* Command bit 2 position. */

/* TCF.CTRLE  bit masks and bit positions */
#define TCF_TIMEOUT_gm  0x0F  /* Timeout value group mask. */
#define TCF_TIMEOUT_gp  0  /* Timeout value group position. */
#define TCF_TIMEOUT_0_bm  (1<<0)  /* Timeout value bit 0 mask. */
#define TCF_TIMEOUT_0_bp  0  /* Timeout value bit 0 position. */
#define TCF_TIMEOUT_1_bm  (1<<1)  /* Timeout value bit 1 mask. */
#define TCF_TIMEOUT_1_bp  1  /* Timeout value bit 1 position. */
#define TCF_TIMEOUT_2_bm  (1<<2)  /* Timeout value bit 2 mask. */
#define TCF_TIMEOUT_2_bp  2  /* Timeout value bit 2 position. */
#define TCF_TIMEOUT_3_bm  (1<<3)  /* Timeout value bit 3 mask. */
#define TCF_TIMEOUT_3_bp  3  /* Timeout value bit 3 position. */

/* TCF.EVCTRL  bit masks and bit positions */
#define TCF_CNTAEI_bm  0x01  /* Counter Event A Input Enable bit mask. */
#define TCF_CNTAEI_bp  0  /* Counter Event A Input Enable bit position. */
#define TCF_EVACTA_gm  0x06  /* Event Action A group mask. */
#define TCF_EVACTA_gp  1  /* Event Action A group position. */
#define TCF_EVACTA_0_bm  (1<<1)  /* Event Action A bit 0 mask. */
#define TCF_EVACTA_0_bp  1  /* Event Action A bit 0 position. */
#define TCF_EVACTA_1_bm  (1<<2)  /* Event Action A bit 1 mask. */
#define TCF_EVACTA_1_bp  2  /* Event Action A bit 1 position. */
#define TCF_FILTERA_bm  0x08  /* Event Filter A bit mask. */
#define TCF_FILTERA_bp  3  /* Event Filter A bit position. */
#define TCF_EDGE_bm  0x10  /* Event edge bit mask. */
#define TCF_EDGE_bp  4  /* Event edge bit position. */

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
#define TCF_CNT_gm  0xFFFFFF  /* Counter group mask. */
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
#define TCF_CNT_20_bm  (1<<20)  /* Counter bit 20 mask. */
#define TCF_CNT_20_bp  20  /* Counter bit 20 position. */
#define TCF_CNT_21_bm  (1<<21)  /* Counter bit 21 mask. */
#define TCF_CNT_21_bp  21  /* Counter bit 21 position. */
#define TCF_CNT_22_bm  (1<<22)  /* Counter bit 22 mask. */
#define TCF_CNT_22_bp  22  /* Counter bit 22 position. */
#define TCF_CNT_23_bm  (1<<23)  /* Counter bit 23 mask. */
#define TCF_CNT_23_bp  23  /* Counter bit 23 position. */

/* TCF.CMP  bit masks and bit positions */
#define TCF_CMP_gm  0xFFFFFF  /* Compare value group mask. */
#define TCF_CMP_gp  0  /* Compare value group position. */
#define TCF_CMP_0_bm  (1<<0)  /* Compare value bit 0 mask. */
#define TCF_CMP_0_bp  0  /* Compare value bit 0 position. */
#define TCF_CMP_1_bm  (1<<1)  /* Compare value bit 1 mask. */
#define TCF_CMP_1_bp  1  /* Compare value bit 1 position. */
#define TCF_CMP_2_bm  (1<<2)  /* Compare value bit 2 mask. */
#define TCF_CMP_2_bp  2  /* Compare value bit 2 position. */
#define TCF_CMP_3_bm  (1<<3)  /* Compare value bit 3 mask. */
#define TCF_CMP_3_bp  3  /* Compare value bit 3 position. */
#define TCF_CMP_4_bm  (1<<4)  /* Compare value bit 4 mask. */
#define TCF_CMP_4_bp  4  /* Compare value bit 4 position. */
#define TCF_CMP_5_bm  (1<<5)  /* Compare value bit 5 mask. */
#define TCF_CMP_5_bp  5  /* Compare value bit 5 position. */
#define TCF_CMP_6_bm  (1<<6)  /* Compare value bit 6 mask. */
#define TCF_CMP_6_bp  6  /* Compare value bit 6 position. */
#define TCF_CMP_7_bm  (1<<7)  /* Compare value bit 7 mask. */
#define TCF_CMP_7_bp  7  /* Compare value bit 7 position. */
#define TCF_CMP_8_bm  (1<<8)  /* Compare value bit 8 mask. */
#define TCF_CMP_8_bp  8  /* Compare value bit 8 position. */
#define TCF_CMP_9_bm  (1<<9)  /* Compare value bit 9 mask. */
#define TCF_CMP_9_bp  9  /* Compare value bit 9 position. */
#define TCF_CMP_10_bm  (1<<10)  /* Compare value bit 10 mask. */
#define TCF_CMP_10_bp  10  /* Compare value bit 10 position. */
#define TCF_CMP_11_bm  (1<<11)  /* Compare value bit 11 mask. */
#define TCF_CMP_11_bp  11  /* Compare value bit 11 position. */
#define TCF_CMP_12_bm  (1<<12)  /* Compare value bit 12 mask. */
#define TCF_CMP_12_bp  12  /* Compare value bit 12 position. */
#define TCF_CMP_13_bm  (1<<13)  /* Compare value bit 13 mask. */
#define TCF_CMP_13_bp  13  /* Compare value bit 13 position. */
#define TCF_CMP_14_bm  (1<<14)  /* Compare value bit 14 mask. */
#define TCF_CMP_14_bp  14  /* Compare value bit 14 position. */
#define TCF_CMP_15_bm  (1<<15)  /* Compare value bit 15 mask. */
#define TCF_CMP_15_bp  15  /* Compare value bit 15 position. */
#define TCF_CMP_16_bm  (1<<16)  /* Compare value bit 16 mask. */
#define TCF_CMP_16_bp  16  /* Compare value bit 16 position. */
#define TCF_CMP_17_bm  (1<<17)  /* Compare value bit 17 mask. */
#define TCF_CMP_17_bp  17  /* Compare value bit 17 position. */
#define TCF_CMP_18_bm  (1<<18)  /* Compare value bit 18 mask. */
#define TCF_CMP_18_bp  18  /* Compare value bit 18 position. */
#define TCF_CMP_19_bm  (1<<19)  /* Compare value bit 19 mask. */
#define TCF_CMP_19_bp  19  /* Compare value bit 19 position. */
#define TCF_CMP_20_bm  (1<<20)  /* Compare value bit 20 mask. */
#define TCF_CMP_20_bp  20  /* Compare value bit 20 position. */
#define TCF_CMP_21_bm  (1<<21)  /* Compare value bit 21 mask. */
#define TCF_CMP_21_bp  21  /* Compare value bit 21 position. */
#define TCF_CMP_22_bm  (1<<22)  /* Compare value bit 22 mask. */
#define TCF_CMP_22_bp  22  /* Compare value bit 22 position. */
#define TCF_CMP_23_bm  (1<<23)  /* Compare value bit 23 mask. */
#define TCF_CMP_23_bp  23  /* Compare value bit 23 position. */


/* TWI - Two-Wire Interface */
/* TWI.CTRLA  bit masks and bit positions */
#define TWI_FMEN_bm  0x01  /* Fast-mode Enable bit mask. */
#define TWI_FMEN_bp  0  /* Fast-mode Enable bit position. */
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

/* TWI.DUALCTRL  bit masks and bit positions */
#define TWI_ENABLE_bm  0x01  /* Enable bit mask. */
#define TWI_ENABLE_bp  0  /* Enable bit position. */
/* TWI_FMPEN  is already defined. */
/* TWI_SDAHOLD  is already defined. */
/* TWI_INPUTLVL  is already defined. */

/* TWI.DBGCTRL  bit masks and bit positions */
#define TWI_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TWI_DBGRUN_bp  0  /* Debug Run bit position. */

/* TWI.MCTRLA  bit masks and bit positions */
/* TWI_ENABLE  is already defined. */
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


/* USART - Universal Synchronous and Asynchronous Receiver and Transmitter */
/* USART.CTRLA  bit masks and bit positions */
#define USART_ENABLE_bm  0x01  /* Enable bit mask. */
#define USART_ENABLE_bp  0  /* Enable bit position. */
#define USART_CMODE_gm  0x06  /* Communication Mode group mask. */
#define USART_CMODE_gp  1  /* Communication Mode group position. */
#define USART_CMODE_0_bm  (1<<1)  /* Communication Mode bit 0 mask. */
#define USART_CMODE_0_bp  1  /* Communication Mode bit 0 position. */
#define USART_CMODE_1_bm  (1<<2)  /* Communication Mode bit 1 mask. */
#define USART_CMODE_1_bp  2  /* Communication Mode bit 1 position. */
#define USART_CSIG_gm  0x60  /* Communication Signals group mask. */
#define USART_CSIG_gp  5  /* Communication Signals group position. */
#define USART_CSIG_0_bm  (1<<5)  /* Communication Signals bit 0 mask. */
#define USART_CSIG_0_bp  5  /* Communication Signals bit 0 position. */
#define USART_CSIG_1_bm  (1<<6)  /* Communication Signals bit 1 mask. */
#define USART_CSIG_1_bp  6  /* Communication Signals bit 1 position. */

/* USART.CTRLB  bit masks and bit positions */
#define USART_TXEN_bm  0x01  /* Transmitter enable bit mask. */
#define USART_TXEN_bp  0  /* Transmitter enable bit position. */
#define USART_RXEN_bm  0x02  /* Receiver enable bit mask. */
#define USART_RXEN_bp  1  /* Receiver enable bit position. */

/* USART.CTRLC  bit masks and bit positions */
#define USART_FORM_gm  0x07  /* Frame Format group mask. */
#define USART_FORM_gp  0  /* Frame Format group position. */
#define USART_FORM_0_bm  (1<<0)  /* Frame Format bit 0 mask. */
#define USART_FORM_0_bp  0  /* Frame Format bit 0 position. */
#define USART_FORM_1_bm  (1<<1)  /* Frame Format bit 1 mask. */
#define USART_FORM_1_bp  1  /* Frame Format bit 1 position. */
#define USART_FORM_2_bm  (1<<2)  /* Frame Format bit 2 mask. */
#define USART_FORM_2_bp  2  /* Frame Format bit 2 position. */
#define USART_SAMPR_bm  0x08  /* Sample Rate bit mask. */
#define USART_SAMPR_bp  3  /* Sample Rate bit position. */
#define USART_CPHA_bm  0x20  /* Clock Phase bit mask. */
#define USART_CPHA_bp  5  /* Clock Phase bit position. */
#define USART_DORD_bm  0x40  /* Data Order bit mask. */
#define USART_DORD_bp  6  /* Data Order bit position. */

/* USART.CTRLD  bit masks and bit positions */
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

/* USART.CTRLE  bit masks and bit positions */
#define USART_MPCM_bm  0x01  /* Multi-processor Communication Mode bit mask. */
#define USART_MPCM_bp  0  /* Multi-processor Communication Mode bit position. */
#define USART_LBME_bm  0x02  /* Loop-back Mode Enable bit mask. */
#define USART_LBME_bp  1  /* Loop-back Mode Enable bit position. */
#define USART_ODME_bm  0x04  /* Open Drain Mode Enable bit mask. */
#define USART_ODME_bp  2  /* Open Drain Mode Enable bit position. */
#define USART_SFDEN_bm  0x08  /* Start Frame Detection Enable bit mask. */
#define USART_SFDEN_bp  3  /* Start Frame Detection Enable bit position. */
#define USART_COLDEN_bm  0x10  /* Collision Detection Enable bit mask. */
#define USART_COLDEN_bp  4  /* Collision Detection Enable bit position. */

/* USART.CTRLF  bit masks and bit positions */
#define USART_BRKLEN_gm  0x03  /* Break Length group mask. */
#define USART_BRKLEN_gp  0  /* Break Length group position. */
#define USART_BRKLEN_0_bm  (1<<0)  /* Break Length bit 0 mask. */
#define USART_BRKLEN_0_bp  0  /* Break Length bit 0 position. */
#define USART_BRKLEN_1_bm  (1<<1)  /* Break Length bit 1 mask. */
#define USART_BRKLEN_1_bp  1  /* Break Length bit 1 position. */
#define USART_GUARD_gm  0x0C  /* Guard Time group mask. */
#define USART_GUARD_gp  2  /* Guard Time group position. */
#define USART_GUARD_0_bm  (1<<2)  /* Guard Time bit 0 mask. */
#define USART_GUARD_0_bp  2  /* Guard Time bit 0 position. */
#define USART_GUARD_1_bm  (1<<3)  /* Guard Time bit 1 mask. */
#define USART_GUARD_1_bp  3  /* Guard Time bit 1 position. */
#define USART_INTDLY_gm  0xF0  /* Inter-byte Delay group mask. */
#define USART_INTDLY_gp  4  /* Inter-byte Delay group position. */
#define USART_INTDLY_0_bm  (1<<4)  /* Inter-byte Delay bit 0 mask. */
#define USART_INTDLY_0_bp  4  /* Inter-byte Delay bit 0 position. */
#define USART_INTDLY_1_bm  (1<<5)  /* Inter-byte Delay bit 1 mask. */
#define USART_INTDLY_1_bp  5  /* Inter-byte Delay bit 1 position. */
#define USART_INTDLY_2_bm  (1<<6)  /* Inter-byte Delay bit 2 mask. */
#define USART_INTDLY_2_bp  6  /* Inter-byte Delay bit 2 position. */
#define USART_INTDLY_3_bm  (1<<7)  /* Inter-byte Delay bit 3 mask. */
#define USART_INTDLY_3_bp  7  /* Inter-byte Delay bit 3 position. */

/* USART.CTRLG  bit masks and bit positions */
#define USART_PROTCONV_gm  0x07  /* Protocol Converter group mask. */
#define USART_PROTCONV_gp  0  /* Protocol Converter group position. */
#define USART_PROTCONV_0_bm  (1<<0)  /* Protocol Converter bit 0 mask. */
#define USART_PROTCONV_0_bp  0  /* Protocol Converter bit 0 position. */
#define USART_PROTCONV_1_bm  (1<<1)  /* Protocol Converter bit 1 mask. */
#define USART_PROTCONV_1_bp  1  /* Protocol Converter bit 1 position. */
#define USART_PROTCONV_2_bm  (1<<2)  /* Protocol Converter bit 2 mask. */
#define USART_PROTCONV_2_bp  2  /* Protocol Converter bit 2 position. */
#define USART_ENC_bm  0x10  /* Encoding bit mask. */
#define USART_ENC_bp  4  /* Encoding bit position. */
#define USART_ABW_gm  0xC0  /* Auto Baud Window group mask. */
#define USART_ABW_gp  6  /* Auto Baud Window group position. */
#define USART_ABW_0_bm  (1<<6)  /* Auto Baud Window bit 0 mask. */
#define USART_ABW_0_bp  6  /* Auto Baud Window bit 0 position. */
#define USART_ABW_1_bm  (1<<7)  /* Auto Baud Window bit 1 mask. */
#define USART_ABW_1_bp  7  /* Auto Baud Window bit 1 position. */

/* USART.COMMAND  bit masks and bit positions */
#define USART_LINCMD_gm  0x03  /* LIN Command group mask. */
#define USART_LINCMD_gp  0  /* LIN Command group position. */
#define USART_LINCMD_0_bm  (1<<0)  /* LIN Command bit 0 mask. */
#define USART_LINCMD_0_bp  0  /* LIN Command bit 0 position. */
#define USART_LINCMD_1_bm  (1<<1)  /* LIN Command bit 1 mask. */
#define USART_LINCMD_1_bp  1  /* LIN Command bit 1 position. */
#define USART_WFBRK_bm  0x04  /* Wait for BREAK bit mask. */
#define USART_WFBRK_bp  2  /* Wait for BREAK bit position. */

/* USART.EVCTRL  bit masks and bit positions */
#define USART_RXEI_bm  0x01  /* Receive Event Input Enable bit mask. */
#define USART_RXEI_bp  0  /* Receive Event Input Enable bit position. */

/* USART.INTCTRL  bit masks and bit positions */
#define USART_DRE_bm  0x01  /* Data Register Empty Interrupt Enable bit mask. */
#define USART_DRE_bp  0  /* Data Register Empty Interrupt Enable bit position. */
#define USART_TXC_bm  0x02  /* Transmit Complete Interrupt Enable bit mask. */
#define USART_TXC_bp  1  /* Transmit Complete Interrupt Enable bit position. */
#define USART_RXC_bm  0x04  /* Receive Complete Interrupt Enable bit mask. */
#define USART_RXC_bp  2  /* Receive Complete Interrupt Enable bit position. */
#define USART_RXS_bm  0x08  /* Receiver Start Frame Interrupt Enable bit mask. */
#define USART_RXS_bp  3  /* Receiver Start Frame Interrupt Enable bit position. */
#define USART_RXBRK_bm  0x10  /* Receive Break Interrupt Enable bit mask. */
#define USART_RXBRK_bp  4  /* Receive Break Interrupt Enable bit position. */
#define USART_CTSIC_bm  0x40  /* Clear to Send Input Change Interrupt Enable bit mask. */
#define USART_CTSIC_bp  6  /* Clear to Send Input Change Interrupt Enable bit position. */
#define USART_ERROR_bm  0x80  /* Error Interrupt Enable bit mask. */
#define USART_ERROR_bp  7  /* Error Interrupt Enable bit position. */

/* USART.INTFLAGS  bit masks and bit positions */
/* USART_DRE  is already defined. */
/* USART_TXC  is already defined. */
/* USART_RXC  is already defined. */
/* USART_RXS  is already defined. */
/* USART_RXBRK  is already defined. */
/* USART_CTSIC  is already defined. */
/* USART_ERROR  is already defined. */

/* USART.STATUS  bit masks and bit positions */
#define USART_ISF_bm  0x01  /* Inconsistent Sync Field bit mask. */
#define USART_ISF_bp  0  /* Inconsistent Sync Field bit position. */
#define USART_COLL_bm  0x02  /* Collision Detected bit mask. */
#define USART_COLL_bp  1  /* Collision Detected bit position. */
#define USART_PERR_bm  0x08  /* Parity Error bit mask. */
#define USART_PERR_bp  3  /* Parity Error bit position. */
#define USART_FERR_bm  0x10  /* Frame Error bit mask. */
#define USART_FERR_bp  4  /* Frame Error bit position. */
#define USART_BUFOVF_bm  0x20  /* Buffer Overflow bit mask. */
#define USART_BUFOVF_bp  5  /* Buffer Overflow bit position. */
#define USART_CTS_bm  0x40  /* Clear to Send bit mask. */
#define USART_CTS_bp  6  /* Clear to Send bit position. */
#define USART_RXACTIVE_bm  0x80  /* Receive Active bit mask. */
#define USART_RXACTIVE_bp  7  /* Receive Active bit position. */

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
/* USART_RXC  is already defined. */
/* USART_PERR  is already defined. */
/* USART_FERR  is already defined. */
/* USART_BUFOVF  is already defined. */

/* USART.TXDATAL  bit masks and bit positions */
/* USART_DATA  is already defined. */

/* USART.TXDATAH  bit masks and bit positions */
/* USART_DATA8  is already defined. */

/* USART.DBGCTRL  bit masks and bit positions */
#define USART_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define USART_DBGRUN_bp  0  /* Debug Run bit position. */



/* VDIVA - Virtual Divide Accelerator */
/* VDIVA.DIVCTRL  bit masks and bit positions */
#define VDIVA_DIVOP_gm  0x0F  /* Divide Operation group mask. */
#define VDIVA_DIVOP_gp  0  /* Divide Operation group position. */
#define VDIVA_DIVOP_0_bm  (1<<0)  /* Divide Operation bit 0 mask. */
#define VDIVA_DIVOP_0_bp  0  /* Divide Operation bit 0 position. */
#define VDIVA_DIVOP_1_bm  (1<<1)  /* Divide Operation bit 1 mask. */
#define VDIVA_DIVOP_1_bp  1  /* Divide Operation bit 1 position. */
#define VDIVA_DIVOP_2_bm  (1<<2)  /* Divide Operation bit 2 mask. */
#define VDIVA_DIVOP_2_bp  2  /* Divide Operation bit 2 position. */
#define VDIVA_DIVOP_3_bm  (1<<3)  /* Divide Operation bit 3 mask. */
#define VDIVA_DIVOP_3_bp  3  /* Divide Operation bit 3 position. */
#define VDIVA_SIGN_bm  0x40  /* Signed Operation bit mask. */
#define VDIVA_SIGN_bp  6  /* Signed Operation bit position. */
#define VDIVA_LEADZERO_bm  0x80  /* Leading Zero Optimization bit mask. */
#define VDIVA_LEADZERO_bp  7  /* Leading Zero Optimization bit position. */

/* VDIVA.SHIFTCTRL  bit masks and bit positions */
#define VDIVA_SHNUM_gm  0x1F  /* Number of shift or rotate operations group mask. */
#define VDIVA_SHNUM_gp  0  /* Number of shift or rotate operations group position. */
#define VDIVA_SHNUM_0_bm  (1<<0)  /* Number of shift or rotate operations bit 0 mask. */
#define VDIVA_SHNUM_0_bp  0  /* Number of shift or rotate operations bit 0 position. */
#define VDIVA_SHNUM_1_bm  (1<<1)  /* Number of shift or rotate operations bit 1 mask. */
#define VDIVA_SHNUM_1_bp  1  /* Number of shift or rotate operations bit 1 position. */
#define VDIVA_SHNUM_2_bm  (1<<2)  /* Number of shift or rotate operations bit 2 mask. */
#define VDIVA_SHNUM_2_bp  2  /* Number of shift or rotate operations bit 2 position. */
#define VDIVA_SHNUM_3_bm  (1<<3)  /* Number of shift or rotate operations bit 3 mask. */
#define VDIVA_SHNUM_3_bp  3  /* Number of shift or rotate operations bit 3 position. */
#define VDIVA_SHNUM_4_bm  (1<<4)  /* Number of shift or rotate operations bit 4 mask. */
#define VDIVA_SHNUM_4_bp  4  /* Number of shift or rotate operations bit 4 position. */
#define VDIVA_SHOP_gm  0x60  /* Shift operation group mask. */
#define VDIVA_SHOP_gp  5  /* Shift operation group position. */
#define VDIVA_SHOP_0_bm  (1<<5)  /* Shift operation bit 0 mask. */
#define VDIVA_SHOP_0_bp  5  /* Shift operation bit 0 position. */
#define VDIVA_SHOP_1_bm  (1<<6)  /* Shift operation bit 1 mask. */
#define VDIVA_SHOP_1_bp  6  /* Shift operation bit 1 position. */
#define VDIVA_XORPREV_bm  0x80  /* XOR with previous result bit mask. */
#define VDIVA_XORPREV_bp  7  /* XOR with previous result bit position. */

/* VDIVA.STATUS  bit masks and bit positions */
#define VDIVA_BUSY_bm  0x01  /* Accelerator Busy bit mask. */
#define VDIVA_BUSY_bp  0  /* Accelerator Busy bit position. */
#define VDIVA_DBZ_bm  0x02  /* Divide-by-Zero bit mask. */
#define VDIVA_DBZ_bp  1  /* Divide-by-Zero bit position. */


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


/* VREF - Voltage reference */
/* VREF.DAC0REF  bit masks and bit positions */
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

/* VREF.ACREF  bit masks and bit positions */
/* VREF_REFSEL  is already defined. */
/* VREF_ALWAYSON  is already defined. */


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

/* CRCSCAN interrupt vectors */
#define CRCSCAN_INT_vect_num  3
#define CRCSCAN_INT_vect      _VECTOR(3)  /*  */

/* MVIO interrupt vectors */
#define MVIO_MVIO_vect_num  4
#define MVIO_MVIO_vect      _VECTOR(4)  /*  */

/* CLKCTRL interrupt vectors */
#define CLKCTRL_CFD_vect_num  5
#define CLKCTRL_CFD_vect      _VECTOR(5)  /*  */

/* RTC interrupt vectors */
#define RTC_CNT_vect_num  6
#define RTC_CNT_vect      _VECTOR(6)  /*  */
#define RTC_PIT_vect_num  7
#define RTC_PIT_vect      _VECTOR(7)  /*  */

/* CCL interrupt vectors */
#define CCL_CCL_vect_num  8
#define CCL_CCL_vect      _VECTOR(8)  /*  */

/* PORTA interrupt vectors */
#define PORTA_PORT_vect_num  9
#define PORTA_PORT_vect      _VECTOR(9)  /*  */

/* TCE0 interrupt vectors */
#define TCE0_OVF_vect_num  10
#define TCE0_OVF_vect      _VECTOR(10)  /*  */
#define TCE0_CMP0_vect_num  11
#define TCE0_CMP0_vect      _VECTOR(11)  /*  */
#define TCE0_CMP1_vect_num  12
#define TCE0_CMP1_vect      _VECTOR(12)  /*  */
#define TCE0_CMP2_vect_num  13
#define TCE0_CMP2_vect      _VECTOR(13)  /*  */

/* TCB0 interrupt vectors */
#define TCB0_INT_vect_num  14
#define TCB0_INT_vect      _VECTOR(14)  /*  */

/* TCB1 interrupt vectors */
#define TCB1_INT_vect_num  15
#define TCB1_INT_vect      _VECTOR(15)  /*  */

/* TWI0 interrupt vectors */
#define TWI0_TWIM_vect_num  16
#define TWI0_TWIM_vect      _VECTOR(16)  /*  */
#define TWI0_TWIS_vect_num  17
#define TWI0_TWIS_vect      _VECTOR(17)  /*  */

/* SPI0 interrupt vectors */
#define SPI0_INT_vect_num  18
#define SPI0_INT_vect      _VECTOR(18)  /*  */

/* USART0 interrupt vectors */
#define USART0_ERROR_vect_num  19
#define USART0_ERROR_vect      _VECTOR(19)  /*  */
#define USART0_RXC_vect_num  20
#define USART0_RXC_vect      _VECTOR(20)  /*  */
#define USART0_DRE_vect_num  21
#define USART0_DRE_vect      _VECTOR(21)  /*  */
#define USART0_TXC_vect_num  22
#define USART0_TXC_vect      _VECTOR(22)  /*  */

/* PORTD interrupt vectors */
#define PORTD_PORT_vect_num  23
#define PORTD_PORT_vect      _VECTOR(23)  /*  */

/* TCF0 interrupt vectors */
#define TCF0_TC_vect_num  24
#define TCF0_TC_vect      _VECTOR(24)  /*  */

/* AC0 interrupt vectors */
#define AC0_CMP_vect_num  25
#define AC0_CMP_vect      _VECTOR(25)  /*  */

/* ADC0 interrupt vectors */
#define ADC0_ERROR_vect_num  26
#define ADC0_ERROR_vect      _VECTOR(26)  /*  */
#define ADC0_RESRDY_vect_num  27
#define ADC0_RESRDY_vect      _VECTOR(27)  /*  */
#define ADC0_SAMPRDY_vect_num  28
#define ADC0_SAMPRDY_vect      _VECTOR(28)  /*  */

/* PORTC interrupt vectors */
#define PORTC_PORT_vect_num  29
#define PORTC_PORT_vect      _VECTOR(29)  /*  */

/* TCB2 interrupt vectors */
#define TCB2_INT_vect_num  30
#define TCB2_INT_vect      _VECTOR(30)  /*  */

/* USART1 interrupt vectors */
#define USART1_ERROR_vect_num  31
#define USART1_ERROR_vect      _VECTOR(31)  /*  */
#define USART1_RXC_vect_num  32
#define USART1_RXC_vect      _VECTOR(32)  /*  */
#define USART1_DRE_vect_num  33
#define USART1_DRE_vect      _VECTOR(33)  /*  */
#define USART1_TXC_vect_num  34
#define USART1_TXC_vect      _VECTOR(34)  /*  */

/* PORTF interrupt vectors */
#define PORTF_PORT_vect_num  35
#define PORTF_PORT_vect      _VECTOR(35)  /*  */

/* NVMCTRL interrupt vectors */
#define NVMCTRL_NVMREADY_vect_num  36
#define NVMCTRL_NVMREADY_vect      _VECTOR(36)  /*  */

/* TCB3 interrupt vectors */
#define TCB3_INT_vect_num  37
#define TCB3_INT_vect      _VECTOR(37)  /*  */

/* PORTB interrupt vectors */
#define PORTB_PORT_vect_num  38
#define PORTB_PORT_vect      _VECTOR(38)  /*  */

/* PORTE interrupt vectors */
#define PORTE_PORT_vect_num  39
#define PORTE_PORT_vect      _VECTOR(39)  /*  */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (40 * _VECTOR_SIZE)


/* ========== Constants ========== */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define DATAMEM_START     (0x0000)
#  define DATAMEM_SIZE      (65536)
#else
#  define DATAMEM_START     (0x0000U)
#  define DATAMEM_SIZE      (65536U)
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
#  define LOCKBITS_PAGE_SIZE (4)
#else
#  define LOCKBITS_START     (0x1040U)
#  define LOCKBITS_SIZE      (4U)
#  define LOCKBITS_PAGE_SIZE (4U)
#endif
#define LOCKBITS_END       (LOCKBITS_START + LOCKBITS_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define FUSES_START     (0x1050)
#  define FUSES_SIZE      (16)
#  define FUSES_PAGE_SIZE (8)
#else
#  define FUSES_START     (0x1050U)
#  define FUSES_SIZE      (16U)
#  define FUSES_PAGE_SIZE (8U)
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
#  define BOOTROW_START     (0x1100)
#  define BOOTROW_SIZE      (64)
#  define BOOTROW_PAGE_SIZE (64)
#else
#  define BOOTROW_START     (0x1100U)
#  define BOOTROW_SIZE      (64U)
#  define BOOTROW_PAGE_SIZE (64U)
#endif
#define BOOTROW_END       (BOOTROW_START + BOOTROW_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define USER_SIGNATURES_START     (0x1200)
#  define USER_SIGNATURES_SIZE      (64)
#  define USER_SIGNATURES_PAGE_SIZE (64)
#else
#  define USER_SIGNATURES_START     (0x1200U)
#  define USER_SIGNATURES_SIZE      (64U)
#  define USER_SIGNATURES_PAGE_SIZE (64U)
#endif
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define EEPROM_START     (0x1400)
#  define EEPROM_SIZE      (512)
#  define EEPROM_PAGE_SIZE (8)
#else
#  define EEPROM_START     (0x1400U)
#  define EEPROM_SIZE      (512U)
#  define EEPROM_PAGE_SIZE (8U)
#endif
#define EEPROM_END       (EEPROM_START + EEPROM_SIZE - 1)

/* Added MAPPED_EEPROM segment names for avr-libc */
#define MAPPED_EEPROM_START     (EEPROM_START)
#define MAPPED_EEPROM_SIZE      (EEPROM_SIZE)
#define MAPPED_EEPROM_PAGE_SIZE (EEPROM_PAGE_SIZE)
#define MAPPED_EEPROM_END       (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define INTERNAL_SRAM_START     (0x6800)
#  define INTERNAL_SRAM_SIZE      (6144)
#  define INTERNAL_SRAM_PAGE_SIZE (0)
#else
#  define INTERNAL_SRAM_START     (0x6800U)
#  define INTERNAL_SRAM_SIZE      (6144U)
#  define INTERNAL_SRAM_PAGE_SIZE (0U)
#endif
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define MAPPED_PROGMEM_START     (0x8000)
#  define MAPPED_PROGMEM_SIZE      (32768)
#  define MAPPED_PROGMEM_PAGE_SIZE (128)
#else
#  define MAPPED_PROGMEM_START     (0x8000U)
#  define MAPPED_PROGMEM_SIZE      (32768U)
#  define MAPPED_PROGMEM_PAGE_SIZE (128U)
#endif
#define MAPPED_PROGMEM_END       (MAPPED_PROGMEM_START + MAPPED_PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_START     (0x0000)
#  define PROGMEM_SIZE      (65536)
#  define PROGMEM_PAGE_SIZE (128)
#else
#  define PROGMEM_START     (0x0000U)
#  define PROGMEM_SIZE      (65536U)
#  define PROGMEM_PAGE_SIZE (128U)
#endif
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_NRWW_START     (0x0000)
#  define PROGMEM_NRWW_SIZE      (8192)
#  define PROGMEM_NRWW_PAGE_SIZE (128)
#else
#  define PROGMEM_NRWW_START     (0x0000U)
#  define PROGMEM_NRWW_SIZE      (8192U)
#  define PROGMEM_NRWW_PAGE_SIZE (128U)
#endif
#define PROGMEM_NRWW_END       (PROGMEM_NRWW_START + PROGMEM_NRWW_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_RWW_START     (0x2000)
#  define PROGMEM_RWW_SIZE      (57344)
#  define PROGMEM_RWW_PAGE_SIZE (128)
#else
#  define PROGMEM_RWW_START     (0x2000U)
#  define PROGMEM_RWW_SIZE      (57344U)
#  define PROGMEM_RWW_PAGE_SIZE (128U)
#endif
#define PROGMEM_RWW_END       (PROGMEM_RWW_START + PROGMEM_RWW_SIZE - 1)

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
#define FUSE_SLEEP0  (unsigned char)_BV(0)  /* BOD Operation in Power Down and Standby Sleep Modes Bit 0 */
#define FUSE_SLEEP1  (unsigned char)_BV(1)  /* BOD Operation in Power Down and Standby Sleep Modes Bit 1 */
#define FUSE_ACTIVE0  (unsigned char)_BV(2)  /* BOD Operation in Active and Idle Sleep Modes Bit 0 */
#define FUSE_ACTIVE1  (unsigned char)_BV(3)  /* BOD Operation in Active and Idle Sleep Modes Bit 1 */
#define FUSE_SAMPFREQ  (unsigned char)_BV(4)  /* BOD Sample Frequency */
#define FUSE_LVL0  (unsigned char)_BV(5)  /* BOD Level Bit 0 */
#define FUSE_LVL1  (unsigned char)_BV(6)  /* BOD Level Bit 1 */
#define FUSE_LVL2  (unsigned char)_BV(7)  /* BOD Level Bit 2 */
#define FUSE1_DEFAULT  (0x0)
#define FUSE_BODCFG_DEFAULT  (0x0)

/* Fuse Byte 2 (OSCCFG) */
#define FUSE_OSCHFFRQ  (unsigned char)_BV(3)  /* High-frequency Oscillator Frequency */
#define FUSE2_DEFAULT  (0x0)
#define FUSE_OSCCFG_DEFAULT  (0x0)

/* Fuse Byte 3 (PINCFG) */
#define FUSE_RSTPINCFG  (unsigned char)_BV(0)  /* Configuration of Reset pin at startup */
#define FUSE_UPDIPINCFG  (unsigned char)_BV(1)  /* Configuration of UPDI pin at startup */
#define FUSE_MVSYSCFG  (unsigned char)_BV(2)  /* MVIO System Configuration */
#define FUSE3_DEFAULT  (0x2)
#define FUSE_PINCFG_DEFAULT  (0x2)

/* Fuse Byte 4 (HWMONCFG) */
#define FUSE_CPUMON  (unsigned char)_BV(0)  /* CPU hardware monitor */
#define FUSE4_DEFAULT  (0x0)
#define FUSE_HWMONCFG_DEFAULT  (0x0)

/* Fuse Byte 5 (SYSCFG0) */
#define FUSE_EESAVE  (unsigned char)_BV(0)  /* EEPROM saved during chip erase */
#define FUSE_BOOTROWSAVE  (unsigned char)_BV(1)  /* BOOTROW saved during chip erase */
#define FUSE_CRCSEL  (unsigned char)_BV(6)  /* CRC polynomial selection */
#define FUSE_CRCBOOT  (unsigned char)_BV(7)  /* CRC Check on BOOT during system initialization */
#define FUSE5_DEFAULT  (0x80)
#define FUSE_SYSCFG0_DEFAULT  (0x80)

/* Fuse Byte 6 (SYSCFG1) */
#define FUSE_SUT0  (unsigned char)_BV(0)  /* Startup Time Bit 0 */
#define FUSE_SUT1  (unsigned char)_BV(1)  /* Startup Time Bit 1 */
#define FUSE_SUT2  (unsigned char)_BV(2)  /* Startup Time Bit 2 */
#define FUSE6_DEFAULT  (0x7)
#define FUSE_SYSCFG1_DEFAULT  (0x7)

/* Fuse Byte 7 (CODESIZE) */
#define FUSE7_DEFAULT  (0x0)
#define FUSE_CODESIZE_DEFAULT  (0x0)

/* Fuse Byte 8 (BOOTSIZE) */
#define FUSE8_DEFAULT  (0x0)
#define FUSE_BOOTSIZE_DEFAULT  (0x0)

/* Fuse Byte 9 Reserved */

/* Fuse Byte 10 (PDICFG) */
#define FUSE_LEVEL0  (unsigned char)_BV(0)  /* PDI Protection Level Bit 0 */
#define FUSE_LEVEL1  (unsigned char)_BV(1)  /* PDI Protection Level Bit 1 */
#define FUSE_KEY0  (unsigned char)_BV(4)  /* PDI Protection Activation Key Bit 0 */
#define FUSE_KEY1  (unsigned char)_BV(5)  /* PDI Protection Activation Key Bit 1 */
#define FUSE_KEY2  (unsigned char)_BV(6)  /* PDI Protection Activation Key Bit 2 */
#define FUSE_KEY3  (unsigned char)_BV(7)  /* PDI Protection Activation Key Bit 3 */
#define FUSE_KEY4  (unsigned char)_BV(8)  /* PDI Protection Activation Key Bit 4 */
#define FUSE_KEY5  (unsigned char)_BV(9)  /* PDI Protection Activation Key Bit 5 */
#define FUSE_KEY6  (unsigned char)_BV(10)  /* PDI Protection Activation Key Bit 6 */
#define FUSE_KEY7  (unsigned char)_BV(11)  /* PDI Protection Activation Key Bit 7 */
#define FUSE_KEY8  (unsigned char)_BV(12)  /* PDI Protection Activation Key Bit 8 */
#define FUSE_KEY9  (unsigned char)_BV(13)  /* PDI Protection Activation Key Bit 9 */
#define FUSE_KEY10  (unsigned char)_BV(14)  /* PDI Protection Activation Key Bit 10 */
#define FUSE_KEY11  (unsigned char)_BV(15)  /* PDI Protection Activation Key Bit 11 */
#define FUSE10_DEFAULT  (0x3)
#define FUSE_PDICFG_DEFAULT  (0x3)

/* ========== Lock Bits ========== */
#define __LOCK_KEY_EXIST
#ifdef LOCKBITS_DEFAULT
#undef LOCKBITS_DEFAULT
#endif //LOCKBITS_DEFAULT
#define LOCKBITS_DEFAULT  (0x5CC5C55C)

/* ========== Signature ========== */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x96
#define SIGNATURE_2 0x28

#endif /* #ifdef _AVR_AVR64EC48_H_INCLUDED */

