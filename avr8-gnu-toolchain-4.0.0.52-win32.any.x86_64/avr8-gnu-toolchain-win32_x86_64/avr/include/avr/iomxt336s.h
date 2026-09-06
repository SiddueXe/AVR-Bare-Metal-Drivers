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
#  define _AVR_IOXXX_H_ "iomxt336s.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_ATMXT336S_H_INCLUDED
#define _AVR_ATMXT336S_H_INCLUDED

/* Ungrouped common registers */
#define CCP  _SFR_MEM8(0x0034)  /* Configuration Change Protection */
#define RAMPD  _SFR_MEM8(0x0038)  /* Ramp D */
#define RAMPX  _SFR_MEM8(0x0039)  /* Ramp X */
#define RAMPY  _SFR_MEM8(0x003A)  /* Ramp Y */
#define RAMPZ  _SFR_MEM8(0x003B)  /* Ramp Z */
#define EIND  _SFR_MEM8(0x003C)  /* Extended Indirect Jump */
#define SPL  _SFR_MEM8(0x003D)  /* Stack Pointer Low */
#define SPH  _SFR_MEM8(0x003E)  /* Stack Pointer High */
#define SREG  _SFR_MEM8(0x003F)  /* Status Register */

#define GPIOR  _SFR_MEM8(0x0000)  /* General Purpose IO Register */

/* Deprecated */
#define GPIO  _SFR_MEM8(0x0000)  /* General Purpose IO Register */

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
CLK - Clock System
--------------------------------------------------------------------------
*/

/* Clock System */
typedef struct CLK_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t PSCTRL;  /* Prescaler Control Register */
    register8_t LOCK;  /* Lock register */
    register8_t RTCCTRL;  /* RTC Control Register */
} CLK_t;


/* Power Reduction */
typedef struct PR_struct
{
    register8_t PRGEN;  /* General Power Reduction */
    register8_t PRPA;  /* Power Reduction Port A */
    register8_t PRPB;  /* Power Reduction Port B */
    register8_t PRPC;  /* Power Reduction Port C */
    register8_t PRPD;  /* Power Reduction Port D */
    register8_t PRPE;  /* Power Reduction Port E */
    register8_t PRPF;  /* Power Reduction Port F */
} PR_t;


/* Power Control */
typedef struct PWR_struct
{
    register8_t PWRCR;  /* Power Control Register */
    register8_t PWRSR;  /* Power Status Register */
} PWR_t;

/* Prescaler A Division Factor */
typedef enum CLK_PSADIV_enum
{
    CLK_PSADIV_1_gc = (0x00<<2),  /* Divide by 1 */
    CLK_PSADIV_2_gc = (0x01<<2),  /* Divide by 2 */
    CLK_PSADIV_4_gc = (0x03<<2),  /* Divide by 4 */
    CLK_PSADIV_8_gc = (0x05<<2),  /* Divide by 8 */
    CLK_PSADIV_16_gc = (0x07<<2),  /* Divide by 16 */
    CLK_PSADIV_32_gc = (0x09<<2),  /* Divide by 32 */
    CLK_PSADIV_64_gc = (0x0B<<2),  /* Divide by 64 */
    CLK_PSADIV_128_gc = (0x0D<<2),  /* Divide by 128 */
    CLK_PSADIV_256_gc = (0x0F<<2),  /* Divide by 256 */
    CLK_PSADIV_512_gc = (0x11<<2),  /* Divide by 512 */
} CLK_PSADIV_t;

/* Prescaler B and C Division Factor */
typedef enum CLK_PSBCDIV_enum
{
    CLK_PSBCDIV_1_1_gc = (0x00<<0),  /* Divide B by 1 and C by 1 */
    CLK_PSBCDIV_1_2_gc = (0x01<<0),  /* Divide B by 1 and C by 2 */
    CLK_PSBCDIV_4_1_gc = (0x02<<0),  /* Divide B by 4 and C by 1 */
    CLK_PSBCDIV_2_2_gc = (0x03<<0),  /* Divide B by 2 and C by 2 */
} CLK_PSBCDIV_t;

/* RTC Clock Source */
typedef enum CLK_RTCSRC_enum
{
    CLK_RTCSRC_ULP_gc = (0x00<<1),  /* 1kHz from internal 32kHz ULP */
    CLK_RTCSRC_TOSC_gc = (0x01<<1),  /* 1kHz from 32kHz crystal oscillator on TOSC */
    CLK_RTCSRC_RCOSC_gc = (0x02<<1),  /* 1kHz from internal 32kHz RC oscillator */
    CLK_RTCSRC_TOSC32_gc = (0x05<<1),  /* 32kHz from 32kHz crystal oscillator on TOSC */
} CLK_RTCSRC_t;

/* System Clock Selection */
typedef enum CLK_SCLKSEL_enum
{
    CLK_SCLKSEL_RC2M_gc = (0x00<<0),  /* Internal 2MHz RC Oscillator */
    CLK_SCLKSEL_RC24M_gc = (0x01<<0),  /* Internal 24MHz RC Oscillator */
    CLK_SCLKSEL_RC32K_gc = (0x02<<0),  /* Internal 32kHz RC Oscillator */
    CLK_SCLKSEL_XOSC_gc = (0x03<<0),  /* External Crystal Oscillator or Clock */
    CLK_SCLKSEL_PLL_gc = (0x04<<0),  /* Phase Locked Loop */
} CLK_SCLKSEL_t;

/*
--------------------------------------------------------------------------
CPU - CPU
--------------------------------------------------------------------------
*/

#define CORE_VERSION  V3XJ

/* CCP signatures */
typedef enum CCP_enum
{
    CCP_SPM_gc = (0x9D<<0),  /* SPM Instruction Protection */
    CCP_IOREG_gc = (0xD8<<0),  /* IO Register Protection */
} CCP_t;

/*
--------------------------------------------------------------------------
CTE - CTE Module
--------------------------------------------------------------------------
*/

/* CTM Module */
typedef struct CTEMS_struct
{
    register8_t MSCRA;  /* Micro Sequencer Control Register A */
    register8_t MSCRB;  /* Micro Sequencer Control Register B */
    register8_t reserved_1[1];
    register8_t MSPSEL;  /* Micro Sequencer Page Select Register */
    register8_t MSSRACLR;  /* Micro Sequencer Status Register A Clear */
    register8_t MSSRASET;  /* Micro Sequencer Status Register A Set */
    register8_t MSSRB;  /* Micro Sequencer Status Register B */
    register8_t MSSRC;  /* Micro Sequencer Status Register C */
    register8_t MSSRD;  /* Micro Sequencer Status Register D */
    register8_t reserved_2[1];
    register8_t MSCCR;  /* Micro Sequencer Condition Code Register */
    register8_t reserved_3[2];
    _WORDREGISTER(MSLRR);  /* MS Link/Repeat Register */
    register8_t reserved_4[1];
    _WORDREGISTER(MSPC);  /* MS Program Counter */
    register8_t MSHIF;  /* MS Host Interface */
    register8_t reserved_5[1];
    register8_t MSIR0;  /* MS Instruction Register 0 */
    register8_t MSIR1;  /* MS Instruction Register 1 */
    register8_t MSIR2;  /* MS Instruction Register 2 */
    register8_t MSIR3;  /* MS Instruction Register 3 */
    _WORDREGISTER(MSIRBUF);  /* MS Instruction Register Buffer */
    _WORDREGISTER(MSR0);  /* MS R0 in register file */
} CTEMS_t;


/* CTE Module */
typedef struct CTE_struct
{
    register8_t ADCYCHR;  /* ADC Y-Channel Register */
    register8_t INTCRC;  /* Integrator Control Register C */
    register8_t ADCSRACLR;  /* ADC Status Register A Clear */
    register8_t ADCSRASET;  /* ADC Status Register A Set */
    register8_t INTCRBCLR;  /* Integrator Control Register B Clear */
    register8_t INTCRBSET;  /* Integrator Control Register B Set */
    register8_t INTCRECLR;  /* Integrator Control Register E Clear */
    register8_t INTCRESET;  /* Integrator Control Register E Set */
    register8_t INTXCHR;  /* Integrator X-Channel Register */
    register8_t INTOEN;  /* Integrator Output Enable Register */
    register8_t TIMMOECMP;  /* Integrator Master Output Enable Timer Compare Register */
    register8_t HVCRA;  /* HV Control Register A */
    register8_t TIMAPER;  /* Timer A Period Register */
    register8_t TIMBPER;  /* Timer B Period Register */
    register8_t TIMCPER;  /* Timer C Period Register */
    register8_t TIMMOEPER;  /* Integrator Master Output Enable Timer Period Register */
    register8_t TIMRSTPER;  /* Integrator Reset Timer Period Register */
    register8_t INTDONE;  /* Integrator Done Register */
    register8_t INTTRIGA;  /* Integrator Trigger Register */
    register8_t INTTRIGB;  /* Integrator Trigger Register */
    register8_t INTGAIN0;  /* Integrator Gain 0 */
    register8_t INTGAIN1;  /* Integrator Gain 1 */
    register8_t INTGAIN2;  /* Integrator Gain 2 */
    register8_t INTGAIN3;  /* Integrator Gain 3 */
    register8_t GCAFSRA;  /* GCAF Status Register A */
    register8_t reserved_1[1];
    register8_t GCAFHDLCNT;  /* Headroom Detect Low Counter */
    register8_t GCAFHDHCNT;  /* Headroom Detect High Counter */
    register8_t reserved_2[2];
    register8_t GCAFMCEN;  /* GCAF Multi-Cut Enable */
    register8_t GCAFCCCLIM;  /* GCAF Computation Complete Counter Limit */
    register8_t PIFXPORTA;  /* Port Interface X-lines PORT A */
    register8_t PIFXPORTB;  /* Port Interface X-lines PORT B */
    register8_t PIFYPORT;  /* Port Interface Y-lines PORT */
    register8_t PIFXDDRA;  /* Port Interface X-lines DDR A */
    register8_t PIFXDDRB;  /* Port Interface X-lines DDR B */
    register8_t PIFYDDR;  /* Port Interface Y-lines DDR */
    register8_t PIFXPINA;  /* Port Interface X-lines PIN A */
    register8_t PIFXPINB;  /* Port Interface X-lines PIN B */
    register8_t PIFYPIN;  /* Port Interface Y-lines PIN */
    register8_t PIFXTGLA;  /* Port Interface X-lines Toggle A */
    register8_t PIFXTGLB;  /* Port Interface X-lines Toggle B */
    register8_t PIFYTGL;  /* Port Interface Y-lines Toggle */
    register8_t PIFILA;  /* Port Interface Interleave Register A */
    register8_t PIFILB;  /* Port Interface Interleave Register B */
    register8_t PIFILE;  /* Port Interface Interleave Register Even */
    register8_t PIFILO;  /* Port Interface Interleave Register Odd */
    register8_t reserved_3[16];
    register8_t ADCCRA;  /* ADC Control Register A */
    register8_t ADCCRB;  /* ADC Control Register B */
    register8_t reserved_4[1];
    register8_t ADCINTCAL;  /* ADC and Integrator Calibration Register */
    register8_t ADCRES;  /* ADC Result */
    register8_t ADCINTTEST;  /* ADC and Integrator Test Register */
    register8_t ADCSHVBCAL;  /* ADC and S/H VBias Calibration Register */
    register8_t reserved_5[1];
    register8_t INTCRA;  /* Integrator Control Register A */
    register8_t INTCRD;  /* Integrator Control Register D */
    register8_t INTEN;  /* Integrator Enable Register */
    register8_t INTMASKEN;  /* Integrator Mask Enable Register */
    register8_t SHEN;  /* S/H Enable Register */
    register8_t BIASCR;  /* Bias Control Register */
    register8_t reserved_6[1];
    register8_t HVSEQT;  /* HV Sequence Timing */
    register8_t HDCRA;  /* Headroom Detector Control Register A */
    register8_t HDEN;  /* Headroom Detector Enable Register */
    register8_t HDLOW;  /* Headroom Detector Low Level Output */
    register8_t HDHIGH;  /* Headroom Detector High Level Output */
    register8_t reserved_7[4];
    register8_t GCAFCRA;  /* GCAF Control Register A */
    register8_t GCAFCRB;  /* GCAF Control Register B */
    register8_t reserved_8[1];
    register8_t GCAFBASELIM;  /* GCAF Base Address and Grass Cut Limit */
    register8_t GCAFPCLL;  /* GCAF Pre-Cut Lower Limit */
    register8_t GCAFPCUL;  /* GCAF Pre-Cut Upper Limit */
    register8_t reserved_9[2];
    register8_t PIFXENA;  /* Port Interface X-line Enable A */
    register8_t PIFXENB;  /* Port Interface X-line Enable B */
    register8_t PIFYEN;  /* Port Interface Y-line Enable */
    register8_t PIFXDDRA_SHADOW;  /* Port Interface X-lines DDR A */
    register8_t PIFXDDRB_SHADOW;  /* Port Interface X-lines DDR B */
    register8_t PIFYDDR_SHADOW;  /* Port Interface Y-lines DDR */
    register8_t PIFXSRLA;  /* Port Interface X-line Slew-Rate Limitation A  */
    register8_t PIFXSRLB;  /* Port Interface X-line Slew-Rate Limitation B  */
    register8_t PIFYSRL;  /* Port Interface Y-line Slew-Rate Limitation */
    register8_t reserved_10[23];
    register8_t CTTEMP;  /* CapTouch Temporary Register */
    register8_t CTCRA;  /* CapTouch Control Register A */
    register8_t reserved_11[30];
    CTEMS_t MS0;  /* Micro sequencer 0 control registers */
    register8_t reserved_12[4];
    CTEMS_t MS1;  /* Micro sequencer 1 control registers */
} CTE_t;

/* Interrupt Level */
typedef enum CTE_CTEMS_MSIL_enum
{
    CTE_CTEMS_MSIL_DIS_gc = (0x00<<1),  /* Disabled */
    CTE_CTEMS_MSIL_LOW_gc = (0x01<<1),  /* Low priority */
    CTE_CTEMS_MSIL_MED_gc = (0x02<<1),  /* Medium priority */
    CTE_CTEMS_MSIL_HI_gc = (0x03<<1),  /* High priority */
} CTE_CTEMS_MSIL_t;

/* Timer/Counter Clock Source */
typedef enum CTE_CTEMS_MSTCCS_enum
{
    CTE_CTEMS_MSTCCS_OFF_gc = (0x00<<0),  /* OFF */
    CTE_CTEMS_MSTCCS_OSC_gc = (0x01<<0),  /* f_osc */
    CTE_CTEMS_MSTCCS_OSC_DIV2_gc = (0x02<<0),  /* f_osc/2 */
    CTE_CTEMS_MSTCCS_OSC_DIV4_gc = (0x03<<0),  /* f_osc/4 */
    CTE_CTEMS_MSTCCS_OSC_DIV8_gc = (0x04<<0),  /* f_osc/8 */
    CTE_CTEMS_MSTCCS_OSC_DIV16_gc = (0x05<<0),  /* f_osc/16 */
    CTE_CTEMS_MSTCCS_OSC_DIV32_gc = (0x06<<0),  /* f_osc/32 */
    CTE_CTEMS_MSTCCS_OSC_DIV64_gc = (0x07<<0),  /* f_osc/64 */
    CTE_CTEMS_MSTCCS_OSC_DIV128_gc = (0x08<<0),  /* f_osc/128 */
    CTE_CTEMS_MSTCCS_OSC_DIV256_gc = (0x09<<0),  /* f_osc/256 */
    CTE_CTEMS_MSTCCS_RESERVED_0A_gc = (0x0A<<0),  /* Reserved */
    CTE_CTEMS_MSTCCS_RESERVED_0B_gc = (0x0B<<0),  /* Reserved */
    CTE_CTEMS_MSTCCS_RESERVED_0C_gc = (0x0C<<0),  /* Reserved */
    CTE_CTEMS_MSTCCS_RESERVED_0D_gc = (0x0D<<0),  /* Reserved */
    CTE_CTEMS_MSTCCS_EV0_gc = (0x0E<<0),  /* Event uSequencer 0 */
    CTE_CTEMS_MSTCCS_EV1_gc = (0x0F<<0),  /* Event uSequencer 1 */
} CTE_CTEMS_MSTCCS_t;

/* ADC Reference Voltage */
typedef enum CTE_ADCREFSEL_enum
{
    CTE_ADCREFSEL_1BGR_gc = (0x00<<6),  /* 1V Bandgap Reference */
    CTE_ADCREFSEL_46AV_gc = (0x01<<6),  /* 0.46 * AVcc */
    CTE_ADCREFSEL_50AV_gc = (0x02<<6),  /* 0.50 * AVcc */
    CTE_ADCREFSEL_66AV_gc = (0x03<<6),  /* 0.66 * AVcc */
} CTE_ADCREFSEL_t;

/* Maximum ADC speed */
typedef enum CTE_ADCSPEED_enum
{
    CTE_ADCSPEED_1MPS_gc = (0x00<<0),  /* 1 Msps */
    CTE_ADCSPEED_2MPS_gc = (0x01<<0),  /* 2 Msps */
    CTE_ADCSPEED_3MPS_gc = (0x02<<0),  /* 3 Msps */
    CTE_ADCSPEED_4MPS_gc = (0x03<<0),  /* 4 Msps */
} CTE_ADCSPEED_t;

/* ADC Startup Mode */
typedef enum CTE_ADCSUM_enum
{
    CTE_ADCSUM_ADC1_gc = (0x00<<7),  /* S/H started before ADC to minimize peak current */
    CTE_ADCSUM_ADC2_gc = (0x01<<7),  /* S/H and ADC started in parallel to minimize startup time */
} CTE_ADCSUM_t;

/* GCAF Average Filter Accumulator Mode */
typedef enum CTE_GCAFACCM_enum
{
    CTE_GCAFACCM_DIS_gc = (0x00<<6),  /* Disabled */
    CTE_GCAFACCM_RES_gc = (0x01<<6),  /* Reserved */
    CTE_GCAFACCM_ACC_gc = (0x02<<6),  /* Accumulate always */
    CTE_GCAFACCM_LIM_gc = (0x03<<6),  /* Accumulate only samples which are within the given limits */
} CTE_GCAFACCM_t;

/* GCAF Addressing Mode */
typedef enum CTE_GCAFAM_enum
{
    CTE_GCAFAM_NORM_gc = (0x00<<5),  /* Normal */
    CTE_GCAFAM_XFLIP_gc = (0x01<<5),  /* X flip */
    CTE_GCAFAM_YFLIP_gc = (0x02<<5),  /* Y flip */
    CTE_GCAFAM_XYFLIP_gc = (0x03<<5),  /* X and Y flip */
    CTE_GCAFAM_TRANS_gc = (0x04<<5),  /* Transpose */
    CTE_GCAFAM_XTRANS_gc = (0x05<<5),  /* X flip and transpose */
    CTE_GCAFAM_YTRANS_gc = (0x06<<5),  /* Y flip and transpose */
    CTE_GCAFAM_XYTRANS_gc = (0x07<<5),  /* X and Y flip and transpose */
} CTE_GCAFAM_t;

/* GCAF Median Filter Mode */
typedef enum CTE_GCAFMEDM_enum
{
    CTE_GCAFMEDM_DIS_gc = (0x00<<1),  /* Disabled */
    CTE_GCAFMEDM_MED3_gc = (0x01<<1),  /* Median of 3 samples */
    CTE_GCAFMEDM_MED4P_gc = (0x02<<1),  /* Median of 4 samples and previous median */
    CTE_GCAFMEDM_MED5_gc = (0x03<<1),  /* Median of 5 samples */
    CTE_GCAFMEDM_MED4A_gc = (0x04<<1),  /* Median of 4 samples. Average of two mid samples of four sorted samples. */
    CTE_GCAFMEDM_RES1_gc = (0x05<<1),  /* Reserved1 */
    CTE_GCAFMEDM_RES2_gc = (0x06<<1),  /* Reserved2 */
    CTE_GCAFMEDM_RES3_gc = (0x07<<1),  /* Reserved3 */
} CTE_GCAFMEDM_t;

/* Integrator Gain */
typedef enum CTE_INT0GAIN_enum
{
    CTE_INT0GAIN_INT1_gc = (0x00<<0),  /* 1/64 */
    CTE_INT0GAIN_INT2_gc = (0x01<<0),  /* 1/64 */
    CTE_INT0GAIN_INT3_gc = (0x02<<0),  /* 2/64 */
    CTE_INT0GAIN_INT4_gc = (0x03<<0),  /* 3/64 */
    CTE_INT0GAIN_INT5_gc = (0x04<<0),  /* 4/64 */
    CTE_INT0GAIN_INT6_gc = (0x05<<0),  /* 6/64 */
    CTE_INT0GAIN_INT7_gc = (0x06<<0),  /* 1/8 */
    CTE_INT0GAIN_INT8_gc = (0x07<<0),  /* 1/8+4/64 */
    CTE_INT0GAIN_INT9_gc = (0x08<<0),  /* 2/8 */
    CTE_INT0GAIN_INT10_gc = (0x09<<0),  /* 3/8 */
    CTE_INT0GAIN_INT11_gc = (0x0A<<0),  /* 4/8 */
    CTE_INT0GAIN_INT12_gc = (0x0B<<0),  /* 5/8 */
    CTE_INT0GAIN_INT13_gc = (0x0C<<0),  /* 6/8 */
    CTE_INT0GAIN_INT14_gc = (0x0D<<0),  /* 6/8 */
    CTE_INT0GAIN_INT15_gc = (0x0E<<0),  /* 6/8 */
    CTE_INT0GAIN_INT16_gc = (0x0F<<0),  /* 6/8 */
} CTE_INT0GAIN_t;

/* Integrator Gain */
typedef enum CTE_INT12GAIN_enum
{
    CTE_INT12GAIN_INT1_gc = (0x00<<0),  /* 1/64 */
    CTE_INT12GAIN_INT2_gc = (0x01<<0),  /* 1/64 */
    CTE_INT12GAIN_INT3_gc = (0x02<<0),  /* 2/64 */
    CTE_INT12GAIN_INT4_gc = (0x03<<0),  /* 3/64 */
    CTE_INT12GAIN_INT5_gc = (0x04<<0),  /* 4/64 */
    CTE_INT12GAIN_INT6_gc = (0x05<<0),  /* 6/64 */
    CTE_INT12GAIN_INT7_gc = (0x06<<0),  /* 1/8 */
    CTE_INT12GAIN_INT8_gc = (0x07<<0),  /* 1/8+4/64 */
    CTE_INT12GAIN_INT9_gc = (0x08<<0),  /* 2/8 */
    CTE_INT12GAIN_INT10_gc = (0x09<<0),  /* 3/8 */
    CTE_INT12GAIN_INT11_gc = (0x0A<<0),  /* 4/8 */
    CTE_INT12GAIN_INT12_gc = (0x0B<<0),  /* 5/8 */
    CTE_INT12GAIN_INT13_gc = (0x0C<<0),  /* 6/8 */
    CTE_INT12GAIN_INT14_gc = (0x0D<<0),  /* 6/8 */
    CTE_INT12GAIN_INT15_gc = (0x0E<<0),  /* 6/8 */
    CTE_INT12GAIN_INT16_gc = (0x0F<<0),  /* 6/8 */
} CTE_INT12GAIN_t;

/* Integrator Gain */
typedef enum CTE_INT13GAIN_enum
{
    CTE_INT13GAIN_INT1_gc = (0x00<<4),  /* 1/64 */
    CTE_INT13GAIN_INT2_gc = (0x01<<4),  /* 1/64 */
    CTE_INT13GAIN_INT3_gc = (0x02<<4),  /* 2/64 */
    CTE_INT13GAIN_INT4_gc = (0x03<<4),  /* 3/64 */
    CTE_INT13GAIN_INT5_gc = (0x04<<4),  /* 4/64 */
    CTE_INT13GAIN_INT6_gc = (0x05<<4),  /* 6/64 */
    CTE_INT13GAIN_INT7_gc = (0x06<<4),  /* 1/8 */
    CTE_INT13GAIN_INT8_gc = (0x07<<4),  /* 1/8+4/64 */
    CTE_INT13GAIN_INT9_gc = (0x08<<4),  /* 2/8 */
    CTE_INT13GAIN_INT10_gc = (0x09<<4),  /* 3/8 */
    CTE_INT13GAIN_INT11_gc = (0x0A<<4),  /* 4/8 */
    CTE_INT13GAIN_INT12_gc = (0x0B<<4),  /* 5/8 */
    CTE_INT13GAIN_INT13_gc = (0x0C<<4),  /* 6/8 */
    CTE_INT13GAIN_INT14_gc = (0x0D<<4),  /* 6/8 */
    CTE_INT13GAIN_INT15_gc = (0x0E<<4),  /* 6/8 */
    CTE_INT13GAIN_INT16_gc = (0x0F<<4),  /* 6/8 */
} CTE_INT13GAIN_t;

/* Integrator Gain */
typedef enum CTE_INT1GAIN_enum
{
    CTE_INT1GAIN_INT1_gc = (0x00<<4),  /* 1/64 */
    CTE_INT1GAIN_INT2_gc = (0x01<<4),  /* 1/64 */
    CTE_INT1GAIN_INT3_gc = (0x02<<4),  /* 2/64 */
    CTE_INT1GAIN_INT4_gc = (0x03<<4),  /* 3/64 */
    CTE_INT1GAIN_INT5_gc = (0x04<<4),  /* 4/64 */
    CTE_INT1GAIN_INT6_gc = (0x05<<4),  /* 6/64 */
    CTE_INT1GAIN_INT7_gc = (0x06<<4),  /* 1/8 */
    CTE_INT1GAIN_INT8_gc = (0x07<<4),  /* 1/8+4/64 */
    CTE_INT1GAIN_INT9_gc = (0x08<<4),  /* 2/8 */
    CTE_INT1GAIN_INT10_gc = (0x09<<4),  /* 3/8 */
    CTE_INT1GAIN_INT11_gc = (0x0A<<4),  /* 4/8 */
    CTE_INT1GAIN_INT12_gc = (0x0B<<4),  /* 5/8 */
    CTE_INT1GAIN_INT13_gc = (0x0C<<4),  /* 6/8 */
    CTE_INT1GAIN_INT14_gc = (0x0D<<4),  /* 6/8 */
    CTE_INT1GAIN_INT15_gc = (0x0E<<4),  /* 6/8 */
    CTE_INT1GAIN_INT16_gc = (0x0F<<4),  /* 6/8 */
} CTE_INT1GAIN_t;

/* Integrator Gain */
typedef enum CTE_INT4GAIN_enum
{
    CTE_INT4GAIN_INT1_gc = (0x00<<0),  /* 1/64 */
    CTE_INT4GAIN_INT2_gc = (0x01<<0),  /* 1/64 */
    CTE_INT4GAIN_INT3_gc = (0x02<<0),  /* 2/64 */
    CTE_INT4GAIN_INT4_gc = (0x03<<0),  /* 3/64 */
    CTE_INT4GAIN_INT5_gc = (0x04<<0),  /* 4/64 */
    CTE_INT4GAIN_INT6_gc = (0x05<<0),  /* 6/64 */
    CTE_INT4GAIN_INT7_gc = (0x06<<0),  /* 1/8 */
    CTE_INT4GAIN_INT8_gc = (0x07<<0),  /* 1/8+4/64 */
    CTE_INT4GAIN_INT9_gc = (0x08<<0),  /* 2/8 */
    CTE_INT4GAIN_INT10_gc = (0x09<<0),  /* 3/8 */
    CTE_INT4GAIN_INT11_gc = (0x0A<<0),  /* 4/8 */
    CTE_INT4GAIN_INT12_gc = (0x0B<<0),  /* 5/8 */
    CTE_INT4GAIN_INT13_gc = (0x0C<<0),  /* 6/8 */
    CTE_INT4GAIN_INT14_gc = (0x0D<<0),  /* 6/8 */
    CTE_INT4GAIN_INT15_gc = (0x0E<<0),  /* 6/8 */
    CTE_INT4GAIN_INT16_gc = (0x0F<<0),  /* 6/8 */
} CTE_INT4GAIN_t;

/* Integrator Gain */
typedef enum CTE_INT5GAIN_enum
{
    CTE_INT5GAIN_INT1_gc = (0x00<<4),  /* 1/64 */
    CTE_INT5GAIN_INT2_gc = (0x01<<4),  /* 1/64 */
    CTE_INT5GAIN_INT3_gc = (0x02<<4),  /* 2/64 */
    CTE_INT5GAIN_INT4_gc = (0x03<<4),  /* 3/64 */
    CTE_INT5GAIN_INT5_gc = (0x04<<4),  /* 4/64 */
    CTE_INT5GAIN_INT6_gc = (0x05<<4),  /* 6/64 */
    CTE_INT5GAIN_INT7_gc = (0x06<<4),  /* 1/8 */
    CTE_INT5GAIN_INT8_gc = (0x07<<4),  /* 1/8+4/64 */
    CTE_INT5GAIN_INT9_gc = (0x08<<4),  /* 2/8 */
    CTE_INT5GAIN_INT10_gc = (0x09<<4),  /* 3/8 */
    CTE_INT5GAIN_INT11_gc = (0x0A<<4),  /* 4/8 */
    CTE_INT5GAIN_INT12_gc = (0x0B<<4),  /* 5/8 */
    CTE_INT5GAIN_INT13_gc = (0x0C<<4),  /* 6/8 */
    CTE_INT5GAIN_INT14_gc = (0x0D<<4),  /* 6/8 */
    CTE_INT5GAIN_INT15_gc = (0x0E<<4),  /* 6/8 */
    CTE_INT5GAIN_INT16_gc = (0x0F<<4),  /* 6/8 */
} CTE_INT5GAIN_t;

/* Integrator Gain */
typedef enum CTE_INT8GAIN_enum
{
    CTE_INT8GAIN_INT1_gc = (0x00<<0),  /* 1/64 */
    CTE_INT8GAIN_INT2_gc = (0x01<<0),  /* 1/64 */
    CTE_INT8GAIN_INT3_gc = (0x02<<0),  /* 2/64 */
    CTE_INT8GAIN_INT4_gc = (0x03<<0),  /* 3/64 */
    CTE_INT8GAIN_INT5_gc = (0x04<<0),  /* 4/64 */
    CTE_INT8GAIN_INT6_gc = (0x05<<0),  /* 6/64 */
    CTE_INT8GAIN_INT7_gc = (0x06<<0),  /* 1/8 */
    CTE_INT8GAIN_INT8_gc = (0x07<<0),  /* 1/8+4/64 */
    CTE_INT8GAIN_INT9_gc = (0x08<<0),  /* 2/8 */
    CTE_INT8GAIN_INT10_gc = (0x09<<0),  /* 3/8 */
    CTE_INT8GAIN_INT11_gc = (0x0A<<0),  /* 4/8 */
    CTE_INT8GAIN_INT12_gc = (0x0B<<0),  /* 5/8 */
    CTE_INT8GAIN_INT13_gc = (0x0C<<0),  /* 6/8 */
    CTE_INT8GAIN_INT14_gc = (0x0D<<0),  /* 6/8 */
    CTE_INT8GAIN_INT15_gc = (0x0E<<0),  /* 6/8 */
    CTE_INT8GAIN_INT16_gc = (0x0F<<0),  /* 6/8 */
} CTE_INT8GAIN_t;

/* Integrator Gain */
typedef enum CTE_INT9GAIN_enum
{
    CTE_INT9GAIN_INT1_gc = (0x00<<4),  /* 1/64 */
    CTE_INT9GAIN_INT2_gc = (0x01<<4),  /* 1/64 */
    CTE_INT9GAIN_INT3_gc = (0x02<<4),  /* 2/64 */
    CTE_INT9GAIN_INT4_gc = (0x03<<4),  /* 3/64 */
    CTE_INT9GAIN_INT5_gc = (0x04<<4),  /* 4/64 */
    CTE_INT9GAIN_INT6_gc = (0x05<<4),  /* 6/64 */
    CTE_INT9GAIN_INT7_gc = (0x06<<4),  /* 1/8 */
    CTE_INT9GAIN_INT8_gc = (0x07<<4),  /* 1/8+4/64 */
    CTE_INT9GAIN_INT9_gc = (0x08<<4),  /* 2/8 */
    CTE_INT9GAIN_INT10_gc = (0x09<<4),  /* 3/8 */
    CTE_INT9GAIN_INT11_gc = (0x0A<<4),  /* 4/8 */
    CTE_INT9GAIN_INT12_gc = (0x0B<<4),  /* 5/8 */
    CTE_INT9GAIN_INT13_gc = (0x0C<<4),  /* 6/8 */
    CTE_INT9GAIN_INT14_gc = (0x0D<<4),  /* 6/8 */
    CTE_INT9GAIN_INT15_gc = (0x0E<<4),  /* 6/8 */
    CTE_INT9GAIN_INT16_gc = (0x0F<<4),  /* 6/8 */
} CTE_INT9GAIN_t;

/*
--------------------------------------------------------------------------
DFLL - DFLL
--------------------------------------------------------------------------
*/

/* DFLL */
typedef struct DFLL_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t reserved_1[1];
    register8_t CALA;  /* Calibration Register A */
    register8_t CALB;  /* Calibration Register B */
    register8_t COMP0;  /* Oscillator Compare Register 0 */
    register8_t COMP1;  /* Oscillator Compare Register 1 */
    register8_t COMP2;  /* Oscillator Compare Register 2 */
    register8_t reserved_2[1];
} DFLL_t;


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
    register8_t JTAGUID;  /* JTAG User ID */
    register8_t reserved_1[1];
    register8_t MCUCR;  /* MCU Control */
    register8_t reserved_2[1];
    register8_t EVSYSLOCK;  /* Event System Lock */
    register8_t AWEXLOCK;  /* AWEX Lock */
    register8_t reserved_3[2];
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
} NVM_t;


/* Lock Bits */
typedef struct NVM_LOCKBITS_struct
{
    register8_t LOCK_BITS;  /* Lock Bits (Changed from LOCKBITS to avoid avr-libc collision) */
} NVM_LOCKBITS_t;


/* Fuses */
typedef struct NVM_FUSES_struct
{
    register8_t reserved_1[4];
    register8_t FUSEBYTE4;  /* Start-up Configuration */
    register8_t FUSEBYTE5;  /* BOD Level */
} NVM_FUSES_t;


/* Production Signatures */
typedef struct NVM_PROD_SIGNATURES_struct
{
    register8_t RC24MCALB;  /* RCOSC 24MHz Calibration Value B */
    register8_t RC24MCALA;  /* RCOSC 24MHz Calibration Value A */
    register8_t FUSEBYTE1;  /* Fuse Byte 1 Value */
    register8_t FUSE_EEH5;  /* FUSE_EEH5 */
    register8_t RC32K;  /* RC 32kHz Calibration Value */
    register8_t FUSE_EEH6;  /* FUSE_EEH6 */
    register8_t FUSEBYTE2;  /* Fuse Byte 2 Value */
    register8_t FUSE_EEH4;  /* FUSE_EEH4 */
    register8_t LOTNUM0;  /* Lot Number at sort, byte 0, ASCII */
    register8_t LOTNUM1;  /* Lot Number at sort, byte 1, ASCII */
    register8_t LOTNUM2;  /* Lot Number at sort, byte 2, ASCII */
    register8_t LOTNUM3;  /* Lot Number at sort, byte 3, ASCII */
    register8_t LOTNUM4;  /* Lot Number at sort, byte 4, ASCII */
    register8_t LOTNUM5;  /* Lot Number at sort, byte 5, ASCII */
    register8_t LOTNUM6;  /* Lot Number at sort, byte 6, ASCII */
    register8_t LOTNUM7;  /* Lot Number at sort, byte 7, ASCII */
    register8_t WAFNUM;  /* Wafer Number */
    register8_t reserved_1[1];
    register8_t COORDX0;  /* Wafer Coordinate X, byte 0 */
    register8_t COORDX1;  /* Wafer Coordinate X, byte 1 */
    register8_t COORDY0;  /* Wafer Coordinate Y, byte 0 */
    register8_t COORDY1;  /* Wafer Coordinate Y, byte 1 */
    register8_t LOTNUM8;  /* Lot Number at sort, byte 8, ASCII */
    register8_t LOTNUM9;  /* Lot Number at sort, byte 9, ASCII */
    register8_t LOTNUM10;  /* Lot Number at sort, byte 10, ASCII */
    register8_t LOTNUM11;  /* Lot Number at sort, byte 11, ASCII */
    register8_t reserved_2[30];
    register8_t BGCAL0;  /* BOD Bandgap Calibration Byte 0 */
    register8_t BGCAL1;  /* BOD Bandgap Calibration Byte 1 */
    register8_t BGCAL2;  /* BOD Bandgap Calibration Byte 2 */
    register8_t reserved_3[1];
    register8_t XLINE_BIAS_250_H;  /* X-line Bias Calibration 250 High */
    register8_t XLINE_BIAS_250_L;  /* X-line Bias Calibration 250 Low */
    register8_t XLINE_BIAS_350_H;  /* X-line Bias Calibration 350 High */
    register8_t XLINE_BIAS_350_L;  /* X-line Bias Calibration 350 Low */
    register8_t XLINE_BIAS_500_H;  /* X-line Bias Calibration 500 High */
    register8_t XLINE_BIAS_500_L;  /* X-line Bias Calibration 500 Low */
    register8_t YLINE_INT_BIAS;  /* Y-line Integrator Bias */
    register8_t YLINEINT_CAP;  /* Y-line Integrator Capacitor */
    register8_t ADC10_CAL;  /* ADC10 Calibration Byte */
    register8_t ADCSHVBCALH;  /* ADCSHVBCALH */
    register8_t ADCSHVBCALL;  /* ADCSHVBCALL */
    register8_t YLINE_INT_BIAS_150;  /* Y-line Integrator Bias 150 */
    register8_t reserved_4[8];
    register8_t UID0_RANDOM_BYTE0;  /* UID0_RANDOM_BYTE0 */
    register8_t UID0_RANDOM_BYTE1;  /* UID0_RANDOM_BYTE1 */
    register8_t UID2_IP_HASH_BYTE0;  /* UID2_IP_HASH_BYTE0 */
    register8_t UID3_SITE;  /* UID3_SITE */
    register8_t UID3_UTC_Byte0;  /* UID3_UTC_Byte0 */
    register8_t UID4_UTC_Byte1;  /* UID4_UTC_Byte1 */
    register8_t UID5_UTC_Byte2;  /* UID5_UTC_Byte2 */
    register8_t UID6_UTC_Byte3;  /* UID6_UTC_Byte3 */
    register8_t reserved_5[84];
    register8_t BGEXTREME0_WS;  /* Bandgap Extreme Value 0 */
    register8_t BGEXTREME1_WS;  /* Bandgap Extreme Value 1 */
    register8_t BGEXTREME2_WS;  /* Bandgap Extreme Value 2 */
    register8_t BGEXTREME3_WS;  /* Bandgap Extreme Value 3 */
    register8_t reserved_6[78];
    register8_t CRCMASKL;  /* CRCMASK[7:0] */
    register8_t CRCMASKH;  /* CRCMASK[15:8] */
} NVM_PROD_SIGNATURES_t;

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
    NVM_CMD_READ_FUSES_gc = (0x07<<0),  /* Read fuse byte */
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
    NVM_CMD_WRITE_BOOT_PAGE_gc = (0x2C<<0),  /* Write Boot Section page */
    NVM_CMD_ERASE_WRITE_BOOT_PAGE_gc = (0x2D<<0),  /* Erase-and-write Boot Section page */
    NVM_CMD_APP_CRC_gc = (0x38<<0),  /* Generate Application section CRC */
    NVM_CMD_BOOT_CRC_gc = (0x39<<0),  /* Generate Boot Section CRC */
    NVM_CMD_FLASH_RANGE_CRC_gc = (0x3A<<0),  /* Generate Flash Range CRC */
} NVM_CMD_t;

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

/* Boot lock bits - application section */
typedef enum NVM_LOCKBITS_BLBA_enum
{
    NVM_LOCKBITS_BLBA_RWLOCK_gc = (0x00<<4),  /* Read and write not allowed */
    NVM_LOCKBITS_BLBA_RLOCK_gc = (0x01<<4),  /* Read not allowed */
    NVM_LOCKBITS_BLBA_WLOCK_gc = (0x02<<4),  /* Write not allowed */
    NVM_LOCKBITS_BLBA_NOLOCK_gc = (0x03<<4),  /* No locks */
} NVM_LOCKBITS_BLBA_t;

/* Boot lock bits - application table section */
typedef enum NVM_LOCKBITS_BLBAT_enum
{
    NVM_LOCKBITS_BLBAT_RWLOCK_gc = (0x00<<2),  /* Read and write not allowed */
    NVM_LOCKBITS_BLBAT_RLOCK_gc = (0x01<<2),  /* Read not allowed */
    NVM_LOCKBITS_BLBAT_WLOCK_gc = (0x02<<2),  /* Write not allowed */
    NVM_LOCKBITS_BLBAT_NOLOCK_gc = (0x03<<2),  /* No locks */
} NVM_LOCKBITS_BLBAT_t;

/* Boot lock bits - boot setcion */
typedef enum NVM_LOCKBITS_BLBB_enum
{
    NVM_LOCKBITS_BLBB_RWLOCK_gc = (0x00<<6),  /* Read and write not allowed */
    NVM_LOCKBITS_BLBB_RLOCK_gc = (0x01<<6),  /* Read not allowed */
    NVM_LOCKBITS_BLBB_WLOCK_gc = (0x02<<6),  /* Write not allowed */
    NVM_LOCKBITS_BLBB_NOLOCK_gc = (0x03<<6),  /* No locks */
} NVM_LOCKBITS_BLBB_t;

/* Lock bits */
typedef enum NVM_LOCKBITS_LB_enum
{
    NVM_LOCKBITS_LB_RWLOCK_gc = (0x00<<0),  /* Read and write not allowed */
    NVM_LOCKBITS_LB_WLOCK_gc = (0x02<<0),  /* Write not allowed */
    NVM_LOCKBITS_LB_NOLOCK_gc = (0x03<<0),  /* No locks */
} NVM_LOCKBITS_LB_t;

/* BOD operation */
typedef enum NVM_FUSES_BODACT_enum
{
    NVM_FUSES_BODACT_INSAMPLEDMODE_gc = (0x01<<4),  /* BOD enabled in sampled mode */
    NVM_FUSES_BODACT_CONTINOUSLY_gc = (0x02<<4),  /* BOD enabled continuously */
    NVM_FUSES_BODACT_DISABLED_gc = (0x03<<4),  /* BOD Disabled */
} NVM_FUSES_BODACT_t;

/* Brownout Detection Voltage Level */
typedef enum NVM_FUSES_BODLVL_enum
{
    NVM_FUSES_BODLVL_3V0_gc = (0x00<<0),  /* 3.0 V */
    NVM_FUSES_BODLVL_2V8_gc = (0x01<<0),  /* 2.8 V */
    NVM_FUSES_BODLVL_2V6_gc = (0x02<<0),  /* 2.6 V */
    NVM_FUSES_BODLVL_2V4_gc = (0x03<<0),  /* 2.4 V */
    NVM_FUSES_BODLVL_2V2_gc = (0x04<<0),  /* 2.2 V */
    NVM_FUSES_BODLVL_2V0_gc = (0x05<<0),  /* 2.0 V */
    NVM_FUSES_BODLVL_1V8_gc = (0x06<<0),  /* 1.8 V */
    NVM_FUSES_BODLVL_1V6_gc = (0x07<<0),  /* 1.6 V */
} NVM_FUSES_BODLVL_t;

/* Start-up Time */
typedef enum NVM_FUSES_SUT_enum
{
    NVM_FUSES_SUT_64MS_gc = (0x00<<2),  /* 64 ms */
    NVM_FUSES_SUT_4MS_gc = (0x01<<2),  /* 4 ms */
    NVM_FUSES_SUT_0MS_gc = (0x03<<2),  /* 0 ms */
} NVM_FUSES_SUT_t;

/*
--------------------------------------------------------------------------
OSC - Oscillator
--------------------------------------------------------------------------
*/

/* Oscillator */
typedef struct OSC_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t STATUS;  /* Status Register */
    register8_t CLOCKINCTRL;  /* CLOCKIN Control Register */
    register8_t XOSCFAIL;  /* External Oscillator Failure Detection Register */
    register8_t RC32KCAL;  /* 32kHz Internal Oscillator Calibration Register */
    register8_t PLLCTRL;  /* PLL Control REgister */
    register8_t DFLLCTRL;  /* DFLL Control Register */
} OSC_t;

/* PLL Clock Source */
typedef enum OSC_PLLSRC_enum
{
    OSC_PLLSRC_RC2M_gc = (0x00<<6),  /* Internal 2MHz RC Oscillator */
    OSC_PLLSRC_RC32M_gc = (0x02<<6),  /* Internal 32MHz RC Oscillator */
    OSC_PLLSRC_XOSC_gc = (0x03<<6),  /* External Oscillator */
} OSC_PLLSRC_t;

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
PORT - Port Configuration
--------------------------------------------------------------------------
*/

/* I/O port Configuration */
typedef struct PORTCFG_struct
{
    register8_t MPCMASK;  /* Multi-pin Configuration Mask */
    register8_t reserved_1[1];
    register8_t VPCTRLA;  /* Virtual Port Control Register A */
    register8_t VPCTRLB;  /* Virtual Port Control Register B */
    register8_t CLKEVOUT;  /* Clock Out Register */
} PORTCFG_t;


/* Virtual Port */
typedef struct VPORT_struct
{
    register8_t DIR;  /* I/O Port Data Direction */
    register8_t OUT;  /* I/O Port Output */
    register8_t IN;  /* I/O Port Input */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
} VPORT_t;


/* I/O Ports */
typedef struct PORT_struct
{
    register8_t DIR;  /* I/O Port Data Direction */
    register8_t DIRSET;  /* I/O Port Data Direction Set */
    register8_t DIRCLR;  /* I/O Port Data Direction Clear */
    register8_t DIRTGL;  /* I/O Port Data Direction Toggle */
    register8_t OUT;  /* I/O Port Output */
    register8_t OUTSET;  /* I/O Port Output Set */
    register8_t OUTCLR;  /* I/O Port Output Clear */
    register8_t OUTTGL;  /* I/O Port Output Toggle */
    register8_t IN;  /* I/O port Input */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t INT0MASK;  /* Port Interrupt 0 Mask */
    register8_t INT1MASK;  /* Port Interrupt 1 Mask */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t reserved_1[3];
    register8_t PIN0CTRL;  /* Pin 0 Control Register */
    register8_t PIN1CTRL;  /* Pin 1 Control Register */
    register8_t PIN2CTRL;  /* Pin 2 Control Register */
    register8_t PIN3CTRL;  /* Pin 3 Control Register */
    register8_t PIN4CTRL;  /* Pin 4 Control Register */
    register8_t PIN5CTRL;  /* Pin 5 Control Register */
    register8_t PIN6CTRL;  /* Pin 6 Control Register */
    register8_t PIN7CTRL;  /* Pin 7 Control Register */
} PORT_t;


/* I/O Ports, disableable */
typedef struct PORT_T_struct
{
    register8_t DIR;  /* I/O Port Data Direction */
    register8_t DIRSET;  /* I/O Port Data Direction Set */
    register8_t DIRCLR;  /* I/O Port Data Direction Clear */
    register8_t DIRTGL;  /* I/O Port Data Direction Toggle */
    register8_t OUT;  /* I/O Port Output */
    register8_t OUTSET;  /* I/O Port Output Set */
    register8_t OUTCLR;  /* I/O Port Output Clear */
    register8_t OUTTGL;  /* I/O Port Output Toggle */
    register8_t IN;  /* I/O port Input */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t INT0MASK;  /* Port Interrupt 0 Mask */
    register8_t INT1MASK;  /* Port Interrupt 1 Mask */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t IDISABLE;  /* Interrupt Disable */
    register8_t PULL_UP;  /* Pull-up Enable */
    register8_t reserved_1[1];
    register8_t PIN0DISABLE;  /* Pin 0 Disable Register */
    register8_t PIN1DISABLE;  /* Pin 1 Disable Register */
    register8_t PIN2DISABLE;  /* Pin 2 Disable Register */
    register8_t PIN3DISABLE;  /* Pin 3 Disable Register */
    register8_t PIN4DISABLE;  /* Pin 4 Disable Register */
    register8_t PIN5DISABLE;  /* Pin 5 Disable Register */
    register8_t PIN6DISABLE;  /* Pin 6 Disable Register */
    register8_t PIN7DISABLE;  /* Pin 7 Disable Register */
} PORT_T_t;

/* Virtual Port 0 Mapping */
typedef enum PORTCFG_VP0MAP_enum
{
    PORTCFG_VP0MAP_PORTA_gc = (0x00<<0),  /* Mapped To PORTA */
    PORTCFG_VP0MAP_PORTB_gc = (0x01<<0),  /* Mapped To PORTB */
    PORTCFG_VP0MAP_PORTC_gc = (0x02<<0),  /* Mapped To PORTC */
    PORTCFG_VP0MAP_PORTD_gc = (0x03<<0),  /* Mapped To PORTD */
    PORTCFG_VP0MAP_PORTE_gc = (0x04<<0),  /* Mapped To PORTE */
    PORTCFG_VP0MAP_PORTF_gc = (0x05<<0),  /* Mapped To PORTF */
    PORTCFG_VP0MAP_PORTG_gc = (0x06<<0),  /* Mapped To PORTG */
    PORTCFG_VP0MAP_PORTH_gc = (0x07<<0),  /* Mapped To PORTH */
    PORTCFG_VP0MAP_PORTJ_gc = (0x08<<0),  /* Mapped To PORTJ */
    PORTCFG_VP0MAP_PORTK_gc = (0x09<<0),  /* Mapped To PORTK */
    PORTCFG_VP0MAP_PORTL_gc = (0x0A<<0),  /* Mapped To PORTL */
    PORTCFG_VP0MAP_PORTM_gc = (0x0B<<0),  /* Mapped To PORTM */
    PORTCFG_VP0MAP_PORTN_gc = (0x0C<<0),  /* Mapped To PORTN */
    PORTCFG_VP0MAP_PORTP_gc = (0x0D<<0),  /* Mapped To PORTP */
    PORTCFG_VP0MAP_PORTQ_gc = (0x0E<<0),  /* Mapped To PORTQ */
    PORTCFG_VP0MAP_PORTR_gc = (0x0F<<0),  /* Mapped To PORTR */
} PORTCFG_VP0MAP_t;

/* Virtual Port 1 Mapping */
typedef enum PORTCFG_VP1MAP_enum
{
    PORTCFG_VP1MAP_PORTA_gc = (0x00<<4),  /* Mapped To PORTA */
    PORTCFG_VP1MAP_PORTB_gc = (0x01<<4),  /* Mapped To PORTB */
    PORTCFG_VP1MAP_PORTC_gc = (0x02<<4),  /* Mapped To PORTC */
    PORTCFG_VP1MAP_PORTD_gc = (0x03<<4),  /* Mapped To PORTD */
    PORTCFG_VP1MAP_PORTE_gc = (0x04<<4),  /* Mapped To PORTE */
    PORTCFG_VP1MAP_PORTF_gc = (0x05<<4),  /* Mapped To PORTF */
    PORTCFG_VP1MAP_PORTG_gc = (0x06<<4),  /* Mapped To PORTG */
    PORTCFG_VP1MAP_PORTH_gc = (0x07<<4),  /* Mapped To PORTH */
    PORTCFG_VP1MAP_PORTJ_gc = (0x08<<4),  /* Mapped To PORTJ */
    PORTCFG_VP1MAP_PORTK_gc = (0x09<<4),  /* Mapped To PORTK */
    PORTCFG_VP1MAP_PORTL_gc = (0x0A<<4),  /* Mapped To PORTL */
    PORTCFG_VP1MAP_PORTM_gc = (0x0B<<4),  /* Mapped To PORTM */
    PORTCFG_VP1MAP_PORTN_gc = (0x0C<<4),  /* Mapped To PORTN */
    PORTCFG_VP1MAP_PORTP_gc = (0x0D<<4),  /* Mapped To PORTP */
    PORTCFG_VP1MAP_PORTQ_gc = (0x0E<<4),  /* Mapped To PORTQ */
    PORTCFG_VP1MAP_PORTR_gc = (0x0F<<4),  /* Mapped To PORTR */
} PORTCFG_VP1MAP_t;

/* Virtual Port 2 Mapping */
typedef enum PORTCFG_VP2MAP_enum
{
    PORTCFG_VP2MAP_PORTA_gc = (0x00<<0),  /* Mapped To PORTA */
    PORTCFG_VP2MAP_PORTB_gc = (0x01<<0),  /* Mapped To PORTB */
    PORTCFG_VP2MAP_PORTC_gc = (0x02<<0),  /* Mapped To PORTC */
    PORTCFG_VP2MAP_PORTD_gc = (0x03<<0),  /* Mapped To PORTD */
    PORTCFG_VP2MAP_PORTE_gc = (0x04<<0),  /* Mapped To PORTE */
    PORTCFG_VP2MAP_PORTF_gc = (0x05<<0),  /* Mapped To PORTF */
    PORTCFG_VP2MAP_PORTG_gc = (0x06<<0),  /* Mapped To PORTG */
    PORTCFG_VP2MAP_PORTH_gc = (0x07<<0),  /* Mapped To PORTH */
    PORTCFG_VP2MAP_PORTJ_gc = (0x08<<0),  /* Mapped To PORTJ */
    PORTCFG_VP2MAP_PORTK_gc = (0x09<<0),  /* Mapped To PORTK */
    PORTCFG_VP2MAP_PORTL_gc = (0x0A<<0),  /* Mapped To PORTL */
    PORTCFG_VP2MAP_PORTM_gc = (0x0B<<0),  /* Mapped To PORTM */
    PORTCFG_VP2MAP_PORTN_gc = (0x0C<<0),  /* Mapped To PORTN */
    PORTCFG_VP2MAP_PORTP_gc = (0x0D<<0),  /* Mapped To PORTP */
    PORTCFG_VP2MAP_PORTQ_gc = (0x0E<<0),  /* Mapped To PORTQ */
    PORTCFG_VP2MAP_PORTR_gc = (0x0F<<0),  /* Mapped To PORTR */
} PORTCFG_VP2MAP_t;

/* Virtual Port 3 Mapping */
typedef enum PORTCFG_VP3MAP_enum
{
    PORTCFG_VP3MAP_PORTA_gc = (0x00<<4),  /* Mapped To PORTA */
    PORTCFG_VP3MAP_PORTB_gc = (0x01<<4),  /* Mapped To PORTB */
    PORTCFG_VP3MAP_PORTC_gc = (0x02<<4),  /* Mapped To PORTC */
    PORTCFG_VP3MAP_PORTD_gc = (0x03<<4),  /* Mapped To PORTD */
    PORTCFG_VP3MAP_PORTE_gc = (0x04<<4),  /* Mapped To PORTE */
    PORTCFG_VP3MAP_PORTF_gc = (0x05<<4),  /* Mapped To PORTF */
    PORTCFG_VP3MAP_PORTG_gc = (0x06<<4),  /* Mapped To PORTG */
    PORTCFG_VP3MAP_PORTH_gc = (0x07<<4),  /* Mapped To PORTH */
    PORTCFG_VP3MAP_PORTJ_gc = (0x08<<4),  /* Mapped To PORTJ */
    PORTCFG_VP3MAP_PORTK_gc = (0x09<<4),  /* Mapped To PORTK */
    PORTCFG_VP3MAP_PORTL_gc = (0x0A<<4),  /* Mapped To PORTL */
    PORTCFG_VP3MAP_PORTM_gc = (0x0B<<4),  /* Mapped To PORTM */
    PORTCFG_VP3MAP_PORTN_gc = (0x0C<<4),  /* Mapped To PORTN */
    PORTCFG_VP3MAP_PORTP_gc = (0x0D<<4),  /* Mapped To PORTP */
    PORTCFG_VP3MAP_PORTQ_gc = (0x0E<<4),  /* Mapped To PORTQ */
    PORTCFG_VP3MAP_PORTR_gc = (0x0F<<4),  /* Mapped To PORTR */
} PORTCFG_VP3MAP_t;

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

/* Port Interrupt 0 Level */
typedef enum PORT_T_INT0LVL_enum
{
    PORT_T_INT0LVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    PORT_T_INT0LVL_LO_gc = (0x01<<0),  /* Low Level */
    PORT_T_INT0LVL_MED_gc = (0x02<<0),  /* Medium Level */
    PORT_T_INT0LVL_HI_gc = (0x03<<0),  /* High Level */
} PORT_T_INT0LVL_t;

/* Port Interrupt 1 Level */
typedef enum PORT_T_INT1LVL_enum
{
    PORT_T_INT1LVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    PORT_T_INT1LVL_LO_gc = (0x01<<2),  /* Low Level */
    PORT_T_INT1LVL_MED_gc = (0x02<<2),  /* Medium Level */
    PORT_T_INT1LVL_HI_gc = (0x03<<2),  /* High Level */
} PORT_T_INT1LVL_t;

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
} RST_t;


/*
--------------------------------------------------------------------------
RTC - Real-Time Counter
--------------------------------------------------------------------------
*/

/* Real-Time Counter */
typedef struct RTC_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t STATUS;  /* Status Register */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t TEMP;  /* Temporary register */
    register8_t reserved_1[3];
    _WORDREGISTER(CNT);  /* Count Register */
    _WORDREGISTER(PER);  /* Period Register */
    _WORDREGISTER(COMP);  /* Compare Register */
} RTC_t;

/* Compare Interrupt level */
typedef enum RTC_COMPINTLVL_enum
{
    RTC_COMPINTLVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    RTC_COMPINTLVL_LO_gc = (0x01<<2),  /* Low Level */
    RTC_COMPINTLVL_MED_gc = (0x02<<2),  /* Medium Level */
    RTC_COMPINTLVL_HI_gc = (0x03<<2),  /* High Level */
} RTC_COMPINTLVL_t;

/* Overflow Interrupt level */
typedef enum RTC_OVFINTLVL_enum
{
    RTC_OVFINTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    RTC_OVFINTLVL_LO_gc = (0x01<<0),  /* Low Level */
    RTC_OVFINTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    RTC_OVFINTLVL_HI_gc = (0x03<<0),  /* High Level */
} RTC_OVFINTLVL_t;

/* Prescaler Factor */
typedef enum RTC_PRESCALER_enum
{
    RTC_PRESCALER_OFF_gc = (0x00<<0),  /* RTC Off */
    RTC_PRESCALER_DIV1_gc = (0x01<<0),  /* RTC Clock */
    RTC_PRESCALER_DIV2_gc = (0x02<<0),  /* RTC Clock / 2 */
    RTC_PRESCALER_DIV8_gc = (0x03<<0),  /* RTC Clock / 8 */
    RTC_PRESCALER_DIV16_gc = (0x04<<0),  /* RTC Clock / 16 */
    RTC_PRESCALER_DIV64_gc = (0x05<<0),  /* RTC Clock / 64 */
    RTC_PRESCALER_DIV256_gc = (0x06<<0),  /* RTC Clock / 256 */
    RTC_PRESCALER_DIV1024_gc = (0x07<<0),  /* RTC Clock / 1024 */
} RTC_PRESCALER_t;

/*
--------------------------------------------------------------------------
SLEEP - Sleep Controller
--------------------------------------------------------------------------
*/

/* Sleep Controller */
typedef struct SLEEP_struct
{
    register8_t CTRL;  /* Control Register */
} SLEEP_t;

/* Sleep Mode */
typedef enum SLEEP_SMODE_enum
{
    SLEEP_SMODE_IDLE_gc = (0x00<<1),  /* Idle mode */
    SLEEP_SMODE_PDOWN_gc = (0x02<<1),  /* Power-down Mode */
    SLEEP_SMODE_PSAVE_gc = (0x03<<1),  /* Power-save Mode */
    SLEEP_SMODE_STDBY_gc = (0x06<<1),  /* Standby Mode */
    SLEEP_SMODE_ESTDBY_gc = (0x07<<1),  /* Extended Standby Mode */
} SLEEP_SMODE_t;

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)
#define SLEEP_MODE_EXT_STANDBY (0x07<<1)
/*
--------------------------------------------------------------------------
SPI - Serial Peripheral Interface
--------------------------------------------------------------------------
*/

/* Serial Peripheral Interface */
typedef struct SPI_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t STATUS;  /* Status Register */
    register8_t DATA;  /* Data Register */
} SPI_t;

/* Interrupt level */
typedef enum SPI_INTLVL_enum
{
    SPI_INTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    SPI_INTLVL_LO_gc = (0x01<<0),  /* Low Level */
    SPI_INTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    SPI_INTLVL_HI_gc = (0x03<<0),  /* High Level */
} SPI_INTLVL_t;

/* SPI Mode */
typedef enum SPI_MODE_enum
{
    SPI_MODE_0_gc = (0x00<<2),  /* SPI Mode 0 */
    SPI_MODE_1_gc = (0x01<<2),  /* SPI Mode 1 */
    SPI_MODE_2_gc = (0x02<<2),  /* SPI Mode 2 */
    SPI_MODE_3_gc = (0x03<<2),  /* SPI Mode 3 */
} SPI_MODE_t;

/* Prescaler setting */
typedef enum SPI_PRESCALER_enum
{
    SPI_PRESCALER_DIV4_gc = (0x00<<0),  /* System Clock / 4 */
    SPI_PRESCALER_DIV16_gc = (0x01<<0),  /* System Clock / 16 */
    SPI_PRESCALER_DIV64_gc = (0x02<<0),  /* System Clock / 64 */
    SPI_PRESCALER_DIV128_gc = (0x03<<0),  /* System Clock / 128 */
} SPI_PRESCALER_t;

/*
--------------------------------------------------------------------------
TC - 16-bit Timer/Counter With PWM
--------------------------------------------------------------------------
*/

/* 16-bit Timer/Counter 0 */
typedef struct TC0_struct
{
    register8_t CTRLA;  /* Control  Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t CTRLC;  /* Control register C */
    register8_t CTRLD;  /* Control Register D */
    register8_t CTRLE;  /* Control Register E */
    register8_t reserved_1[1];
    register8_t INTCTRLA;  /* Interrupt Control Register A */
    register8_t INTCTRLB;  /* Interrupt Control Register B */
    register8_t CTRLFCLR;  /* Control Register F Clear */
    register8_t CTRLFSET;  /* Control Register F Set */
    register8_t CTRLGCLR;  /* Control Register G Clear */
    register8_t CTRLGSET;  /* Control Register G Set */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t reserved_2[2];
    register8_t TEMP;  /* Temporary Register For 16-bit Access */
    register8_t reserved_3[16];
    _WORDREGISTER(CNT);  /* Count */
    register8_t reserved_4[4];
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CCA);  /* Compare or Capture A */
    _WORDREGISTER(CCB);  /* Compare or Capture B */
    _WORDREGISTER(CCC);  /* Compare or Capture C */
    _WORDREGISTER(CCD);  /* Compare or Capture D */
    register8_t reserved_5[6];
    _WORDREGISTER(PERBUF);  /* Period Buffer */
    _WORDREGISTER(CCABUF);  /* Compare Or Capture A Buffer */
    _WORDREGISTER(CCBBUF);  /* Compare Or Capture B Buffer */
    _WORDREGISTER(CCCBUF);  /* Compare Or Capture C Buffer */
    _WORDREGISTER(CCDBUF);  /* Compare Or Capture D Buffer */
} TC0_t;


/* 16-bit Timer/Counter 1 */
typedef struct TC1_struct
{
    register8_t CTRLA;  /* Control  Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t CTRLC;  /* Control register C */
    register8_t CTRLD;  /* Control Register D */
    register8_t CTRLE;  /* Control Register E */
    register8_t reserved_1[1];
    register8_t INTCTRLA;  /* Interrupt Control Register A */
    register8_t INTCTRLB;  /* Interrupt Control Register B */
    register8_t CTRLFCLR;  /* Control Register F Clear */
    register8_t CTRLFSET;  /* Control Register F Set */
    register8_t CTRLGCLR;  /* Control Register G Clear */
    register8_t CTRLGSET;  /* Control Register G Set */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t reserved_2[2];
    register8_t TEMP;  /* Temporary Register For 16-bit Access */
    register8_t reserved_3[16];
    _WORDREGISTER(CNT);  /* Count */
    register8_t reserved_4[4];
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CCA);  /* Compare or Capture A */
    _WORDREGISTER(CCB);  /* Compare or Capture B */
    register8_t reserved_5[10];
    _WORDREGISTER(PERBUF);  /* Period Buffer */
    _WORDREGISTER(CCABUF);  /* Compare Or Capture A Buffer */
    _WORDREGISTER(CCBBUF);  /* Compare Or Capture B Buffer */
} TC1_t;

/* Compare or Capture A Interrupt Level */
typedef enum TC_CCAINTLVL_enum
{
    TC_CCAINTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    TC_CCAINTLVL_LO_gc = (0x01<<0),  /* Low Level */
    TC_CCAINTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    TC_CCAINTLVL_HI_gc = (0x03<<0),  /* High Level */
} TC_CCAINTLVL_t;

/* Compare or Capture B Interrupt Level */
typedef enum TC_CCBINTLVL_enum
{
    TC_CCBINTLVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    TC_CCBINTLVL_LO_gc = (0x01<<2),  /* Low Level */
    TC_CCBINTLVL_MED_gc = (0x02<<2),  /* Medium Level */
    TC_CCBINTLVL_HI_gc = (0x03<<2),  /* High Level */
} TC_CCBINTLVL_t;

/* Compare or Capture C Interrupt Level */
typedef enum TC_CCCINTLVL_enum
{
    TC_CCCINTLVL_OFF_gc = (0x00<<4),  /* Interrupt Disabled */
    TC_CCCINTLVL_LO_gc = (0x01<<4),  /* Low Level */
    TC_CCCINTLVL_MED_gc = (0x02<<4),  /* Medium Level */
    TC_CCCINTLVL_HI_gc = (0x03<<4),  /* High Level */
} TC_CCCINTLVL_t;

/* Compare or Capture D Interrupt Level */
typedef enum TC_CCDINTLVL_enum
{
    TC_CCDINTLVL_OFF_gc = (0x00<<6),  /* Interrupt Disabled */
    TC_CCDINTLVL_LO_gc = (0x01<<6),  /* Low Level */
    TC_CCDINTLVL_MED_gc = (0x02<<6),  /* Medium Level */
    TC_CCDINTLVL_HI_gc = (0x03<<6),  /* High Level */
} TC_CCDINTLVL_t;

/* Clock Selection */
typedef enum TC_CLKSEL_enum
{
    TC_CLKSEL_OFF_gc = (0x00<<0),  /* Timer Off */
    TC_CLKSEL_DIV1_gc = (0x01<<0),  /* System Clock */
    TC_CLKSEL_DIV2_gc = (0x02<<0),  /* System Clock / 2 */
    TC_CLKSEL_DIV4_gc = (0x03<<0),  /* System Clock / 4 */
    TC_CLKSEL_DIV8_gc = (0x04<<0),  /* System Clock / 8 */
    TC_CLKSEL_DIV64_gc = (0x05<<0),  /* System Clock / 64 */
    TC_CLKSEL_DIV256_gc = (0x06<<0),  /* System Clock / 256 */
    TC_CLKSEL_DIV1024_gc = (0x07<<0),  /* System Clock / 1024 */
    TC_CLKSEL_EVCH0_gc = (0x08<<0),  /* Event Channel 0 */
    TC_CLKSEL_EVCH1_gc = (0x09<<0),  /* Event Channel 1 */
    TC_CLKSEL_EVCH2_gc = (0x0A<<0),  /* Event Channel 2 */
    TC_CLKSEL_EVCH3_gc = (0x0B<<0),  /* Event Channel 3 */
    TC_CLKSEL_EVCH4_gc = (0x0C<<0),  /* Event Channel 4 */
    TC_CLKSEL_EVCH5_gc = (0x0D<<0),  /* Event Channel 5 */
    TC_CLKSEL_EVCH6_gc = (0x0E<<0),  /* Event Channel 6 */
    TC_CLKSEL_EVCH7_gc = (0x0F<<0),  /* Event Channel 7 */
} TC_CLKSEL_t;

/* Timer/Counter Command */
typedef enum TC_CMD_enum
{
    TC_CMD_NONE_gc = (0x00<<2),  /* No Command */
    TC_CMD_UPDATE_gc = (0x01<<2),  /* Force Update */
    TC_CMD_RESTART_gc = (0x02<<2),  /* Force Restart */
    TC_CMD_RESET_gc = (0x03<<2),  /* Force Hard Reset */
} TC_CMD_t;

/* Error Interrupt Level */
typedef enum TC_ERRINTLVL_enum
{
    TC_ERRINTLVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    TC_ERRINTLVL_LO_gc = (0x01<<2),  /* Low Level */
    TC_ERRINTLVL_MED_gc = (0x02<<2),  /* Medium Level */
    TC_ERRINTLVL_HI_gc = (0x03<<2),  /* High Level */
} TC_ERRINTLVL_t;

/* Event Action */
typedef enum TC_EVACT_enum
{
    TC_EVACT_OFF_gc = (0x00<<5),  /* No Event Action */
    TC_EVACT_CAPT_gc = (0x01<<5),  /* Input Capture */
    TC_EVACT_UPDOWN_gc = (0x02<<5),  /* Externally Controlled Up/Down Count */
    TC_EVACT_QDEC_gc = (0x03<<5),  /* Quadrature Decode */
    TC_EVACT_RESTART_gc = (0x04<<5),  /* Restart */
    TC_EVACT_FRQ_gc = (0x05<<5),  /* Frequency Capture */
    TC_EVACT_PW_gc = (0x06<<5),  /* Pulse-width Capture */
} TC_EVACT_t;

/* Event Selection */
typedef enum TC_EVSEL_enum
{
    TC_EVSEL_OFF_gc = (0x00<<0),  /* No Event Source */
    TC_EVSEL_CH0_gc = (0x08<<0),  /* Event Channel 0 */
    TC_EVSEL_CH1_gc = (0x09<<0),  /* Event Channel 1 */
    TC_EVSEL_CH2_gc = (0x0A<<0),  /* Event Channel 2 */
    TC_EVSEL_CH3_gc = (0x0B<<0),  /* Event Channel 3 */
    TC_EVSEL_CH4_gc = (0x0C<<0),  /* Event Channel 4 */
    TC_EVSEL_CH5_gc = (0x0D<<0),  /* Event Channel 5 */
    TC_EVSEL_CH6_gc = (0x0E<<0),  /* Event Channel 6 */
    TC_EVSEL_CH7_gc = (0x0F<<0),  /* Event Channel 7 */
} TC_EVSEL_t;

/* Overflow Interrupt Level */
typedef enum TC_OVFINTLVL_enum
{
    TC_OVFINTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    TC_OVFINTLVL_LO_gc = (0x01<<0),  /* Low Level */
    TC_OVFINTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    TC_OVFINTLVL_HI_gc = (0x03<<0),  /* High Level */
} TC_OVFINTLVL_t;

/* Waveform Generation Mode */
typedef enum TC_WGMODE_enum
{
    TC_WGMODE_NORMAL_gc = (0x00<<0),  /* Normal Mode */
    TC_WGMODE_FRQ_gc = (0x01<<0),  /* Frequency Generation Mode */
    TC_WGMODE_SINGLESLOPE_gc = (0x03<<0),  /* Single Slope */
    TC_WGMODE_SS_gc = (0x03<<0),  /* Single Slope */
    TC_WGMODE_DSTOP_gc = (0x05<<0),  /* Dual Slope, Update on TOP */
    TC_WGMODE_DS_T_gc = (0x05<<0),  /* Dual Slope, Update on TOP */
    TC_WGMODE_DSBOTH_gc = (0x06<<0),  /* Dual Slope, Update on both TOP and BOTTOM */
    TC_WGMODE_DS_TB_gc = (0x06<<0),  /* Dual Slope, Update on both TOP and BOTTOM */
    TC_WGMODE_DSBOTTOM_gc = (0x07<<0),  /* Dual Slope, Update on BOTTOM */
    TC_WGMODE_DS_B_gc = (0x07<<0),  /* Dual Slope, Update on BOTTOM */
} TC_WGMODE_t;

/*
--------------------------------------------------------------------------
TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

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
    TWI_MASTER_t MASTER;  /* TWI master module */
    TWI_SLAVE_t SLAVE;  /* TWI slave module */
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

/* SDA hold time */
typedef enum TWI_SDAHOLD_enum
{
    TWI_SDAHOLD_OFF_gc = (0x00<<1),  /* SDA hold time off */
    TWI_SDAHOLD_50NS_gc = (0x01<<1),  /* Typical 50ns hold time */
    TWI_SDAHOLD_300NS_gc = (0x02<<1),  /* Typical 300ns hold time */
    TWI_SDAHOLD_400NS_gc = (0x03<<1),  /* Typical 400ns hold time */
} TWI_SDAHOLD_t;

/*
--------------------------------------------------------------------------
USART - Universal Asynchronous Receiver-Transmitter
--------------------------------------------------------------------------
*/

/* Universal Synchronous/Asynchronous Receiver/Transmitter */
typedef struct USART_struct
{
    register8_t DATA;  /* Data Register */
    register8_t STATUS;  /* Status Register */
    register8_t reserved_1[1];
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t CTRLC;  /* Control Register C */
    register8_t BAUDCTRLA;  /* Baud Rate Control Register A */
    register8_t BAUDCTRLB;  /* Baud Rate Control Register B */
} USART_t;

/* Character Size */
typedef enum USART_CHSIZE_enum
{
    USART_CHSIZE_5BIT_gc = (0x00<<0),  /* Character size: 5 bit */
    USART_CHSIZE_6BIT_gc = (0x01<<0),  /* Character size: 6 bit */
    USART_CHSIZE_7BIT_gc = (0x02<<0),  /* Character size: 7 bit */
    USART_CHSIZE_8BIT_gc = (0x03<<0),  /* Character size: 8 bit */
    USART_CHSIZE_9BIT_gc = (0x07<<0),  /* Character size: 9 bit */
} USART_CHSIZE_t;

/* Communication Mode */
typedef enum USART_CMODE_enum
{
    USART_CMODE_ASYNCHRONOUS_gc = (0x00<<6),  /* Asynchronous Mode */
    USART_CMODE_SYNCHRONOUS_gc = (0x01<<6),  /* Synchronous Mode */
    USART_CMODE_IRDA_gc = (0x02<<6),  /* IrDA Mode */
    USART_CMODE_MSPI_gc = (0x03<<6),  /* Master SPI Mode */
} USART_CMODE_t;

/* Data Register Empty Interrupt level */
typedef enum USART_DREINTLVL_enum
{
    USART_DREINTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    USART_DREINTLVL_LO_gc = (0x01<<0),  /* Low Level */
    USART_DREINTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    USART_DREINTLVL_HI_gc = (0x03<<0),  /* High Level */
} USART_DREINTLVL_t;

/* Parity Mode */
typedef enum USART_PMODE_enum
{
    USART_PMODE_DISABLED_gc = (0x00<<4),  /* No Parity */
    USART_PMODE_EVEN_gc = (0x02<<4),  /* Even Parity */
    USART_PMODE_ODD_gc = (0x03<<4),  /* Odd Parity */
} USART_PMODE_t;

/* Receive Complete Interrupt level */
typedef enum USART_RXCINTLVL_enum
{
    USART_RXCINTLVL_OFF_gc = (0x00<<4),  /* Interrupt Disabled */
    USART_RXCINTLVL_LO_gc = (0x01<<4),  /* Low Level */
    USART_RXCINTLVL_MED_gc = (0x02<<4),  /* Medium Level */
    USART_RXCINTLVL_HI_gc = (0x03<<4),  /* High Level */
} USART_RXCINTLVL_t;

/* Transmit Complete Interrupt level */
typedef enum USART_TXCINTLVL_enum
{
    USART_TXCINTLVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    USART_TXCINTLVL_LO_gc = (0x01<<2),  /* Low Level */
    USART_TXCINTLVL_MED_gc = (0x02<<2),  /* Medium Level */
    USART_TXCINTLVL_HI_gc = (0x03<<2),  /* High Level */
} USART_TXCINTLVL_t;

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
} WDT_t;

/* Period setting */
typedef enum WDT_PER_enum
{
    WDT_PER_8CLK_gc = (0x00<<2),  /* 8 cycles (8ms @ 3.3V) */
    WDT_PER_16CLK_gc = (0x01<<2),  /* 16 cycles (16ms @ 3.3V) */
    WDT_PER_32CLK_gc = (0x02<<2),  /* 32 cycles (32ms @ 3.3V) */
    WDT_PER_64CLK_gc = (0x03<<2),  /* 64 cycles (64ms @ 3.3V) */
    WDT_PER_128CLK_gc = (0x04<<2),  /* 128 cycles (0.128s @ 3.3V) */
    WDT_PER_256CLK_gc = (0x05<<2),  /* 256 cycles (0.256s @ 3.3V) */
    WDT_PER_512CLK_gc = (0x06<<2),  /* 512 cycles (0.512s @ 3.3V) */
    WDT_PER_1KCLK_gc = (0x07<<2),  /* 1K cycles (1s @ 3.3V) */
    WDT_PER_2KCLK_gc = (0x08<<2),  /* 2K cycles (2s @ 3.3V) */
    WDT_PER_4KCLK_gc = (0x09<<2),  /* 4K cycles (4s @ 3.3V) */
    WDT_PER_8KCLK_gc = (0x0A<<2),  /* 8K cycles (8s @ 3.3V) */
} WDT_PER_t;

/* Closed window period */
typedef enum WDT_WPER_enum
{
    WDT_WPER_8CLK_gc = (0x00<<2),  /* 8 cycles (8ms @ 3.3V) */
    WDT_WPER_16CLK_gc = (0x01<<2),  /* 16 cycles (16ms @ 3.3V) */
    WDT_WPER_32CLK_gc = (0x02<<2),  /* 32 cycles (32ms @ 3.3V) */
    WDT_WPER_64CLK_gc = (0x03<<2),  /* 64 cycles (64ms @ 3.3V) */
    WDT_WPER_128CLK_gc = (0x04<<2),  /* 128 cycles (0.128s @ 3.3V) */
    WDT_WPER_256CLK_gc = (0x05<<2),  /* 256 cycles (0.256s @ 3.3V) */
    WDT_WPER_512CLK_gc = (0x06<<2),  /* 512 cycles (0.512s @ 3.3V) */
    WDT_WPER_1KCLK_gc = (0x07<<2),  /* 1K cycles (1s @ 3.3V) */
    WDT_WPER_2KCLK_gc = (0x08<<2),  /* 2K cycles (2s @ 3.3V) */
    WDT_WPER_4KCLK_gc = (0x09<<2),  /* 4K cycles (4s @ 3.3V) */
    WDT_WPER_8KCLK_gc = (0x0A<<2),  /* 8K cycles (8s @ 3.3V) */
} WDT_WPER_t;

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
#define CLK                   (*(CLK_t *) 0x0040) /* Clock System */
#define SLEEP               (*(SLEEP_t *) 0x0048) /* Sleep Controller */
#define OSC                   (*(OSC_t *) 0x0050) /* Oscillator */
#define DFLLRC32M            (*(DFLL_t *) 0x0060) /* DFLL */
#define PR                     (*(PR_t *) 0x0070) /* Power Reduction */
#define RST                   (*(RST_t *) 0x0078) /* Reset */
#define WDT                   (*(WDT_t *) 0x0080) /* Watch-Dog Timer */
#define MCU                   (*(MCU_t *) 0x0090) /* MCU Control */
#define PMIC                 (*(PMIC_t *) 0x00A0) /* Programmable Multi-level Interrupt Controller */
#define PORTCFG           (*(PORTCFG_t *) 0x00B0) /* I/O port Configuration */
#define NVM                   (*(NVM_t *) 0x01C0) /* Non-volatile Memory Controller */
#define PWR                   (*(PWR_t *) 0x01F0) /* Power Control */
#define RTC                   (*(RTC_t *) 0x0400) /* Real-Time Counter */
#define TWIC                  (*(TWI_t *) 0x0480) /* Two-Wire Interface */
#define PORTC                (*(PORT_t *) 0x0640) /* I/O Ports */
#define PORTH              (*(PORT_T_t *) 0x06E0) /* I/O Ports, disableable */
#define PORTJ              (*(PORT_T_t *) 0x0700) /* I/O Ports, disableable */
#define PORTK              (*(PORT_T_t *) 0x0720) /* I/O Ports, disableable */
#define PORTL              (*(PORT_T_t *) 0x0740) /* I/O Ports, disableable */
#define PORTM              (*(PORT_T_t *) 0x0760) /* I/O Ports, disableable */
#define TCC0                  (*(TC0_t *) 0x0800) /* 16-bit Timer/Counter 0 */
#define TCC1                  (*(TC1_t *) 0x0840) /* 16-bit Timer/Counter 1 */
#define USARTC0             (*(USART_t *) 0x08A0) /* Universal Synchronous/Asynchronous Receiver/Transmitter */
#define SPIC                  (*(SPI_t *) 0x08C0) /* Serial Peripheral Interface */
#define CTE                   (*(CTE_t *) 0x0C00) /* CTE Module */

#endif /* !defined (__ASSEMBLER__) */


/* ========== Flattened fully qualified IO register names ========== */


/* GPIO - General Purpose IO Registers */
#define GPIO_GPIOR  _SFR_MEM8(0x0000)


/* Deprecated */
#define GPIO_GPIO  _SFR_MEM8(0x0000)


/* NVM_FUSES (FUSE) - Fuses */
#define FUSE_FUSEBYTE4  _SFR_MEM8(0x0004)
#define FUSE_FUSEBYTE5  _SFR_MEM8(0x0005)


/* NVM_LOCKBITS (LOCKBIT) - Lock Bits */
#define LOCKBIT_LOCKBITS  _SFR_MEM8(0x0000)


/* NVM_PROD_SIGNATURES (PROD_SIGNATURES) - Production Signatures */
#define PRODSIGNATURES_RC24MCALB  _SFR_MEM8(0x0000)
#define PRODSIGNATURES_RC24MCALA  _SFR_MEM8(0x0001)
#define PRODSIGNATURES_FUSEBYTE1  _SFR_MEM8(0x0002)
#define PRODSIGNATURES_FUSE_EEH5  _SFR_MEM8(0x0003)
#define PRODSIGNATURES_RC32K  _SFR_MEM8(0x0004)
#define PRODSIGNATURES_FUSE_EEH6  _SFR_MEM8(0x0005)
#define PRODSIGNATURES_FUSEBYTE2  _SFR_MEM8(0x0006)
#define PRODSIGNATURES_FUSE_EEH4  _SFR_MEM8(0x0007)
#define PRODSIGNATURES_LOTNUM0  _SFR_MEM8(0x0008)
#define PRODSIGNATURES_LOTNUM1  _SFR_MEM8(0x0009)
#define PRODSIGNATURES_LOTNUM2  _SFR_MEM8(0x000A)
#define PRODSIGNATURES_LOTNUM3  _SFR_MEM8(0x000B)
#define PRODSIGNATURES_LOTNUM4  _SFR_MEM8(0x000C)
#define PRODSIGNATURES_LOTNUM5  _SFR_MEM8(0x000D)
#define PRODSIGNATURES_LOTNUM6  _SFR_MEM8(0x000E)
#define PRODSIGNATURES_LOTNUM7  _SFR_MEM8(0x000F)
#define PRODSIGNATURES_WAFNUM  _SFR_MEM8(0x0010)
#define PRODSIGNATURES_COORDX0  _SFR_MEM8(0x0012)
#define PRODSIGNATURES_COORDX1  _SFR_MEM8(0x0013)
#define PRODSIGNATURES_COORDY0  _SFR_MEM8(0x0014)
#define PRODSIGNATURES_COORDY1  _SFR_MEM8(0x0015)
#define PRODSIGNATURES_LOTNUM8  _SFR_MEM8(0x0016)
#define PRODSIGNATURES_LOTNUM9  _SFR_MEM8(0x0017)
#define PRODSIGNATURES_LOTNUM10  _SFR_MEM8(0x0018)
#define PRODSIGNATURES_LOTNUM11  _SFR_MEM8(0x0019)
#define PRODSIGNATURES_BGCAL0  _SFR_MEM8(0x0038)
#define PRODSIGNATURES_BGCAL1  _SFR_MEM8(0x0039)
#define PRODSIGNATURES_BGCAL2  _SFR_MEM8(0x003A)
#define PRODSIGNATURES_XLINE_BIAS_250_H  _SFR_MEM8(0x003C)
#define PRODSIGNATURES_XLINE_BIAS_250_L  _SFR_MEM8(0x003D)
#define PRODSIGNATURES_XLINE_BIAS_350_H  _SFR_MEM8(0x003E)
#define PRODSIGNATURES_XLINE_BIAS_350_L  _SFR_MEM8(0x003F)
#define PRODSIGNATURES_XLINE_BIAS_500_H  _SFR_MEM8(0x0040)
#define PRODSIGNATURES_XLINE_BIAS_500_L  _SFR_MEM8(0x0041)
#define PRODSIGNATURES_YLINE_INT_BIAS  _SFR_MEM8(0x0042)
#define PRODSIGNATURES_YLINEINT_CAP  _SFR_MEM8(0x0043)
#define PRODSIGNATURES_ADC10_CAL  _SFR_MEM8(0x0044)
#define PRODSIGNATURES_ADCSHVBCALH  _SFR_MEM8(0x0045)
#define PRODSIGNATURES_ADCSHVBCALL  _SFR_MEM8(0x0046)
#define PRODSIGNATURES_YLINE_INT_BIAS_150  _SFR_MEM8(0x0047)
#define PRODSIGNATURES_UID0_RANDOM_BYTE0  _SFR_MEM8(0x0050)
#define PRODSIGNATURES_UID0_RANDOM_BYTE1  _SFR_MEM8(0x0051)
#define PRODSIGNATURES_UID2_IP_HASH_BYTE0  _SFR_MEM8(0x0052)
#define PRODSIGNATURES_UID3_SITE  _SFR_MEM8(0x0053)
#define PRODSIGNATURES_UID3_UTC_Byte0  _SFR_MEM8(0x0054)
#define PRODSIGNATURES_UID4_UTC_Byte1  _SFR_MEM8(0x0055)
#define PRODSIGNATURES_UID5_UTC_Byte2  _SFR_MEM8(0x0056)
#define PRODSIGNATURES_UID6_UTC_Byte3  _SFR_MEM8(0x0057)
#define PRODSIGNATURES_BGEXTREME0_WS  _SFR_MEM8(0x00AC)
#define PRODSIGNATURES_BGEXTREME1_WS  _SFR_MEM8(0x00AD)
#define PRODSIGNATURES_BGEXTREME2_WS  _SFR_MEM8(0x00AE)
#define PRODSIGNATURES_BGEXTREME3_WS  _SFR_MEM8(0x00AF)
#define PRODSIGNATURES_CRCMASKL  _SFR_MEM8(0x00FE)
#define PRODSIGNATURES_CRCMASKH  _SFR_MEM8(0x00FF)


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


/* CLK - Clock System */
#define CLK_CTRL  _SFR_MEM8(0x0040)
#define CLK_PSCTRL  _SFR_MEM8(0x0041)
#define CLK_LOCK  _SFR_MEM8(0x0042)
#define CLK_RTCCTRL  _SFR_MEM8(0x0043)


/* SLEEP - Sleep Controller */
#define SLEEP_CTRL  _SFR_MEM8(0x0048)


/* OSC - Oscillator */
#define OSC_CTRL  _SFR_MEM8(0x0050)
#define OSC_STATUS  _SFR_MEM8(0x0051)
#define OSC_CLOCKINCTRL  _SFR_MEM8(0x0052)
#define OSC_XOSCFAIL  _SFR_MEM8(0x0053)
#define OSC_RC32KCAL  _SFR_MEM8(0x0054)
#define OSC_PLLCTRL  _SFR_MEM8(0x0055)
#define OSC_DFLLCTRL  _SFR_MEM8(0x0056)


/* DFLL (DFLLRC32M) - DFLL */
#define DFLLRC32M_CTRL  _SFR_MEM8(0x0060)
#define DFLLRC32M_CALA  _SFR_MEM8(0x0062)
#define DFLLRC32M_CALB  _SFR_MEM8(0x0063)
#define DFLLRC32M_COMP0  _SFR_MEM8(0x0064)
#define DFLLRC32M_COMP1  _SFR_MEM8(0x0065)
#define DFLLRC32M_COMP2  _SFR_MEM8(0x0066)


/* PR - Power Reduction */
#define PR_PRGEN  _SFR_MEM8(0x0070)
#define PR_PRPA  _SFR_MEM8(0x0071)
#define PR_PRPB  _SFR_MEM8(0x0072)
#define PR_PRPC  _SFR_MEM8(0x0073)
#define PR_PRPD  _SFR_MEM8(0x0074)
#define PR_PRPE  _SFR_MEM8(0x0075)
#define PR_PRPF  _SFR_MEM8(0x0076)


/* RST - Reset */
#define RST_STATUS  _SFR_MEM8(0x0078)
#define RST_CTRL  _SFR_MEM8(0x0079)


/* WDT - Watch-Dog Timer */
#define WDT_CTRL  _SFR_MEM8(0x0080)
#define WDT_WINCTRL  _SFR_MEM8(0x0081)
#define WDT_STATUS  _SFR_MEM8(0x0082)


/* MCU - MCU Control */
#define MCU_DEVID0  _SFR_MEM8(0x0090)
#define MCU_DEVID1  _SFR_MEM8(0x0091)
#define MCU_DEVID2  _SFR_MEM8(0x0092)
#define MCU_REVID  _SFR_MEM8(0x0093)
#define MCU_JTAGUID  _SFR_MEM8(0x0094)
#define MCU_MCUCR  _SFR_MEM8(0x0096)
#define MCU_EVSYSLOCK  _SFR_MEM8(0x0098)
#define MCU_AWEXLOCK  _SFR_MEM8(0x0099)


/* PMIC - Programmable Multi-level Interrupt Controller */
#define PMIC_STATUS  _SFR_MEM8(0x00A0)
#define PMIC_INTPRI  _SFR_MEM8(0x00A1)
#define PMIC_CTRL  _SFR_MEM8(0x00A2)


/* PORTCFG (PORT_CFG) - I/O port Configuration */
#define PORTCFG_MPCMASK  _SFR_MEM8(0x00B0)
#define PORTCFG_VPCTRLA  _SFR_MEM8(0x00B2)
#define PORTCFG_VPCTRLB  _SFR_MEM8(0x00B3)
#define PORTCFG_CLKEVOUT  _SFR_MEM8(0x00B4)


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


/* PWR - Power Control */
#define PWR_PWRCR  _SFR_MEM8(0x01F0)
#define PWR_PWRSR  _SFR_MEM8(0x01F1)


/* RTC - Real-Time Counter */
#define RTC_CTRL  _SFR_MEM8(0x0400)
#define RTC_STATUS  _SFR_MEM8(0x0401)
#define RTC_INTCTRL  _SFR_MEM8(0x0402)
#define RTC_INTFLAGS  _SFR_MEM8(0x0403)
#define RTC_TEMP  _SFR_MEM8(0x0404)
#define RTC_CNT  _SFR_MEM16(0x0408)
#define RTC_CNTL  _SFR_MEM8(0x0408)
#define RTC_CNTH  _SFR_MEM8(0x0409)
#define RTC_PER  _SFR_MEM16(0x040A)
#define RTC_PERL  _SFR_MEM8(0x040A)
#define RTC_PERH  _SFR_MEM8(0x040B)
#define RTC_COMP  _SFR_MEM16(0x040C)
#define RTC_COMPL  _SFR_MEM8(0x040C)
#define RTC_COMPH  _SFR_MEM8(0x040D)


/* TWI (TWIC) - Two-Wire Interface */
#define TWIC_CTRL  _SFR_MEM8(0x0480)
#define TWIC_MASTER_CTRLA  _SFR_MEM8(0x0481)
#define TWIC_MASTER_CTRLB  _SFR_MEM8(0x0482)
#define TWIC_MASTER_CTRLC  _SFR_MEM8(0x0483)
#define TWIC_MASTER_STATUS  _SFR_MEM8(0x0484)
#define TWIC_MASTER_BAUD  _SFR_MEM8(0x0485)
#define TWIC_MASTER_ADDR  _SFR_MEM8(0x0486)
#define TWIC_MASTER_DATA  _SFR_MEM8(0x0487)


#define TWIC_SLAVE_CTRLA  _SFR_MEM8(0x0488)
#define TWIC_SLAVE_CTRLB  _SFR_MEM8(0x0489)
#define TWIC_SLAVE_STATUS  _SFR_MEM8(0x048A)
#define TWIC_SLAVE_ADDR  _SFR_MEM8(0x048B)
#define TWIC_SLAVE_DATA  _SFR_MEM8(0x048C)
#define TWIC_SLAVE_ADDRMASK  _SFR_MEM8(0x048D)




/* PORT (PORTC) - I/O Ports */
#define PORTC_DIR  _SFR_MEM8(0x0640)
#define PORTC_DIRSET  _SFR_MEM8(0x0641)
#define PORTC_DIRCLR  _SFR_MEM8(0x0642)
#define PORTC_DIRTGL  _SFR_MEM8(0x0643)
#define PORTC_OUT  _SFR_MEM8(0x0644)
#define PORTC_OUTSET  _SFR_MEM8(0x0645)
#define PORTC_OUTCLR  _SFR_MEM8(0x0646)
#define PORTC_OUTTGL  _SFR_MEM8(0x0647)
#define PORTC_IN  _SFR_MEM8(0x0648)
#define PORTC_INTCTRL  _SFR_MEM8(0x0649)
#define PORTC_INT0MASK  _SFR_MEM8(0x064A)
#define PORTC_INT1MASK  _SFR_MEM8(0x064B)
#define PORTC_INTFLAGS  _SFR_MEM8(0x064C)
#define PORTC_PIN0CTRL  _SFR_MEM8(0x0650)
#define PORTC_PIN1CTRL  _SFR_MEM8(0x0651)
#define PORTC_PIN2CTRL  _SFR_MEM8(0x0652)
#define PORTC_PIN3CTRL  _SFR_MEM8(0x0653)
#define PORTC_PIN4CTRL  _SFR_MEM8(0x0654)
#define PORTC_PIN5CTRL  _SFR_MEM8(0x0655)
#define PORTC_PIN6CTRL  _SFR_MEM8(0x0656)
#define PORTC_PIN7CTRL  _SFR_MEM8(0x0657)


/* PORT_T (PORTH) - I/O Ports, disableable */
#define PORTH_DIR  _SFR_MEM8(0x06E0)
#define PORTH_DIRSET  _SFR_MEM8(0x06E1)
#define PORTH_DIRCLR  _SFR_MEM8(0x06E2)
#define PORTH_DIRTGL  _SFR_MEM8(0x06E3)
#define PORTH_OUT  _SFR_MEM8(0x06E4)
#define PORTH_OUTSET  _SFR_MEM8(0x06E5)
#define PORTH_OUTCLR  _SFR_MEM8(0x06E6)
#define PORTH_OUTTGL  _SFR_MEM8(0x06E7)
#define PORTH_IN  _SFR_MEM8(0x06E8)
#define PORTH_INTCTRL  _SFR_MEM8(0x06E9)
#define PORTH_INT0MASK  _SFR_MEM8(0x06EA)
#define PORTH_INT1MASK  _SFR_MEM8(0x06EB)
#define PORTH_INTFLAGS  _SFR_MEM8(0x06EC)
#define PORTH_IDISABLE  _SFR_MEM8(0x06ED)
#define PORTH_PULL_UP  _SFR_MEM8(0x06EE)
#define PORTH_PIN0DISABLE  _SFR_MEM8(0x06F0)
#define PORTH_PIN1DISABLE  _SFR_MEM8(0x06F1)
#define PORTH_PIN2DISABLE  _SFR_MEM8(0x06F2)
#define PORTH_PIN3DISABLE  _SFR_MEM8(0x06F3)
#define PORTH_PIN4DISABLE  _SFR_MEM8(0x06F4)
#define PORTH_PIN5DISABLE  _SFR_MEM8(0x06F5)
#define PORTH_PIN6DISABLE  _SFR_MEM8(0x06F6)
#define PORTH_PIN7DISABLE  _SFR_MEM8(0x06F7)


/* PORT_T (PORTJ) - I/O Ports, disableable */
#define PORTJ_DIR  _SFR_MEM8(0x0700)
#define PORTJ_DIRSET  _SFR_MEM8(0x0701)
#define PORTJ_DIRCLR  _SFR_MEM8(0x0702)
#define PORTJ_DIRTGL  _SFR_MEM8(0x0703)
#define PORTJ_OUT  _SFR_MEM8(0x0704)
#define PORTJ_OUTSET  _SFR_MEM8(0x0705)
#define PORTJ_OUTCLR  _SFR_MEM8(0x0706)
#define PORTJ_OUTTGL  _SFR_MEM8(0x0707)
#define PORTJ_IN  _SFR_MEM8(0x0708)
#define PORTJ_INTCTRL  _SFR_MEM8(0x0709)
#define PORTJ_INT0MASK  _SFR_MEM8(0x070A)
#define PORTJ_INT1MASK  _SFR_MEM8(0x070B)
#define PORTJ_INTFLAGS  _SFR_MEM8(0x070C)
#define PORTJ_IDISABLE  _SFR_MEM8(0x070D)
#define PORTJ_PULL_UP  _SFR_MEM8(0x070E)
#define PORTJ_PIN0DISABLE  _SFR_MEM8(0x0710)
#define PORTJ_PIN1DISABLE  _SFR_MEM8(0x0711)
#define PORTJ_PIN2DISABLE  _SFR_MEM8(0x0712)
#define PORTJ_PIN3DISABLE  _SFR_MEM8(0x0713)
#define PORTJ_PIN4DISABLE  _SFR_MEM8(0x0714)
#define PORTJ_PIN5DISABLE  _SFR_MEM8(0x0715)
#define PORTJ_PIN6DISABLE  _SFR_MEM8(0x0716)
#define PORTJ_PIN7DISABLE  _SFR_MEM8(0x0717)


/* PORT_T (PORTK) - I/O Ports, disableable */
#define PORTK_DIR  _SFR_MEM8(0x0720)
#define PORTK_DIRSET  _SFR_MEM8(0x0721)
#define PORTK_DIRCLR  _SFR_MEM8(0x0722)
#define PORTK_DIRTGL  _SFR_MEM8(0x0723)
#define PORTK_OUT  _SFR_MEM8(0x0724)
#define PORTK_OUTSET  _SFR_MEM8(0x0725)
#define PORTK_OUTCLR  _SFR_MEM8(0x0726)
#define PORTK_OUTTGL  _SFR_MEM8(0x0727)
#define PORTK_IN  _SFR_MEM8(0x0728)
#define PORTK_INTCTRL  _SFR_MEM8(0x0729)
#define PORTK_INT0MASK  _SFR_MEM8(0x072A)
#define PORTK_INT1MASK  _SFR_MEM8(0x072B)
#define PORTK_INTFLAGS  _SFR_MEM8(0x072C)
#define PORTK_IDISABLE  _SFR_MEM8(0x072D)
#define PORTK_PULL_UP  _SFR_MEM8(0x072E)
#define PORTK_PIN0DISABLE  _SFR_MEM8(0x0730)
#define PORTK_PIN1DISABLE  _SFR_MEM8(0x0731)
#define PORTK_PIN2DISABLE  _SFR_MEM8(0x0732)
#define PORTK_PIN3DISABLE  _SFR_MEM8(0x0733)
#define PORTK_PIN4DISABLE  _SFR_MEM8(0x0734)
#define PORTK_PIN5DISABLE  _SFR_MEM8(0x0735)
#define PORTK_PIN6DISABLE  _SFR_MEM8(0x0736)
#define PORTK_PIN7DISABLE  _SFR_MEM8(0x0737)


/* PORT_T (PORTL) - I/O Ports, disableable */
#define PORTL_DIR  _SFR_MEM8(0x0740)
#define PORTL_DIRSET  _SFR_MEM8(0x0741)
#define PORTL_DIRCLR  _SFR_MEM8(0x0742)
#define PORTL_DIRTGL  _SFR_MEM8(0x0743)
#define PORTL_OUT  _SFR_MEM8(0x0744)
#define PORTL_OUTSET  _SFR_MEM8(0x0745)
#define PORTL_OUTCLR  _SFR_MEM8(0x0746)
#define PORTL_OUTTGL  _SFR_MEM8(0x0747)
#define PORTL_IN  _SFR_MEM8(0x0748)
#define PORTL_INTCTRL  _SFR_MEM8(0x0749)
#define PORTL_INT0MASK  _SFR_MEM8(0x074A)
#define PORTL_INT1MASK  _SFR_MEM8(0x074B)
#define PORTL_INTFLAGS  _SFR_MEM8(0x074C)
#define PORTL_IDISABLE  _SFR_MEM8(0x074D)
#define PORTL_PULL_UP  _SFR_MEM8(0x074E)
#define PORTL_PIN0DISABLE  _SFR_MEM8(0x0750)
#define PORTL_PIN1DISABLE  _SFR_MEM8(0x0751)
#define PORTL_PIN2DISABLE  _SFR_MEM8(0x0752)
#define PORTL_PIN3DISABLE  _SFR_MEM8(0x0753)
#define PORTL_PIN4DISABLE  _SFR_MEM8(0x0754)
#define PORTL_PIN5DISABLE  _SFR_MEM8(0x0755)
#define PORTL_PIN6DISABLE  _SFR_MEM8(0x0756)
#define PORTL_PIN7DISABLE  _SFR_MEM8(0x0757)


/* PORT_T (PORTM) - I/O Ports, disableable */
#define PORTM_DIR  _SFR_MEM8(0x0760)
#define PORTM_DIRSET  _SFR_MEM8(0x0761)
#define PORTM_DIRCLR  _SFR_MEM8(0x0762)
#define PORTM_DIRTGL  _SFR_MEM8(0x0763)
#define PORTM_OUT  _SFR_MEM8(0x0764)
#define PORTM_OUTSET  _SFR_MEM8(0x0765)
#define PORTM_OUTCLR  _SFR_MEM8(0x0766)
#define PORTM_OUTTGL  _SFR_MEM8(0x0767)
#define PORTM_IN  _SFR_MEM8(0x0768)
#define PORTM_INTCTRL  _SFR_MEM8(0x0769)
#define PORTM_INT0MASK  _SFR_MEM8(0x076A)
#define PORTM_INT1MASK  _SFR_MEM8(0x076B)
#define PORTM_INTFLAGS  _SFR_MEM8(0x076C)
#define PORTM_IDISABLE  _SFR_MEM8(0x076D)
#define PORTM_PULL_UP  _SFR_MEM8(0x076E)
#define PORTM_PIN0DISABLE  _SFR_MEM8(0x0770)
#define PORTM_PIN1DISABLE  _SFR_MEM8(0x0771)
#define PORTM_PIN2DISABLE  _SFR_MEM8(0x0772)
#define PORTM_PIN3DISABLE  _SFR_MEM8(0x0773)
#define PORTM_PIN4DISABLE  _SFR_MEM8(0x0774)
#define PORTM_PIN5DISABLE  _SFR_MEM8(0x0775)
#define PORTM_PIN6DISABLE  _SFR_MEM8(0x0776)
#define PORTM_PIN7DISABLE  _SFR_MEM8(0x0777)


/* TC0 (TCC0) - 16-bit Timer/Counter 0 */
#define TCC0_CTRLA  _SFR_MEM8(0x0800)
#define TCC0_CTRLB  _SFR_MEM8(0x0801)
#define TCC0_CTRLC  _SFR_MEM8(0x0802)
#define TCC0_CTRLD  _SFR_MEM8(0x0803)
#define TCC0_CTRLE  _SFR_MEM8(0x0804)
#define TCC0_INTCTRLA  _SFR_MEM8(0x0806)
#define TCC0_INTCTRLB  _SFR_MEM8(0x0807)
#define TCC0_CTRLFCLR  _SFR_MEM8(0x0808)
#define TCC0_CTRLFSET  _SFR_MEM8(0x0809)
#define TCC0_CTRLGCLR  _SFR_MEM8(0x080A)
#define TCC0_CTRLGSET  _SFR_MEM8(0x080B)
#define TCC0_INTFLAGS  _SFR_MEM8(0x080C)
#define TCC0_TEMP  _SFR_MEM8(0x080F)
#define TCC0_CNT  _SFR_MEM16(0x0820)
#define TCC0_CNTL  _SFR_MEM8(0x0820)
#define TCC0_CNTH  _SFR_MEM8(0x0821)
#define TCC0_PER  _SFR_MEM16(0x0826)
#define TCC0_PERL  _SFR_MEM8(0x0826)
#define TCC0_PERH  _SFR_MEM8(0x0827)
#define TCC0_CCA  _SFR_MEM16(0x0828)
#define TCC0_CCAL  _SFR_MEM8(0x0828)
#define TCC0_CCAH  _SFR_MEM8(0x0829)
#define TCC0_CCB  _SFR_MEM16(0x082A)
#define TCC0_CCBL  _SFR_MEM8(0x082A)
#define TCC0_CCBH  _SFR_MEM8(0x082B)
#define TCC0_CCC  _SFR_MEM16(0x082C)
#define TCC0_CCCL  _SFR_MEM8(0x082C)
#define TCC0_CCCH  _SFR_MEM8(0x082D)
#define TCC0_CCD  _SFR_MEM16(0x082E)
#define TCC0_CCDL  _SFR_MEM8(0x082E)
#define TCC0_CCDH  _SFR_MEM8(0x082F)
#define TCC0_PERBUF  _SFR_MEM16(0x0836)
#define TCC0_PERBUFL  _SFR_MEM8(0x0836)
#define TCC0_PERBUFH  _SFR_MEM8(0x0837)
#define TCC0_CCABUF  _SFR_MEM16(0x0838)
#define TCC0_CCABUFL  _SFR_MEM8(0x0838)
#define TCC0_CCABUFH  _SFR_MEM8(0x0839)
#define TCC0_CCBBUF  _SFR_MEM16(0x083A)
#define TCC0_CCBBUFL  _SFR_MEM8(0x083A)
#define TCC0_CCBBUFH  _SFR_MEM8(0x083B)
#define TCC0_CCCBUF  _SFR_MEM16(0x083C)
#define TCC0_CCCBUFL  _SFR_MEM8(0x083C)
#define TCC0_CCCBUFH  _SFR_MEM8(0x083D)
#define TCC0_CCDBUF  _SFR_MEM16(0x083E)
#define TCC0_CCDBUFL  _SFR_MEM8(0x083E)
#define TCC0_CCDBUFH  _SFR_MEM8(0x083F)


/* TC1 (TCC1) - 16-bit Timer/Counter 1 */
#define TCC1_CTRLA  _SFR_MEM8(0x0840)
#define TCC1_CTRLB  _SFR_MEM8(0x0841)
#define TCC1_CTRLC  _SFR_MEM8(0x0842)
#define TCC1_CTRLD  _SFR_MEM8(0x0843)
#define TCC1_CTRLE  _SFR_MEM8(0x0844)
#define TCC1_INTCTRLA  _SFR_MEM8(0x0846)
#define TCC1_INTCTRLB  _SFR_MEM8(0x0847)
#define TCC1_CTRLFCLR  _SFR_MEM8(0x0848)
#define TCC1_CTRLFSET  _SFR_MEM8(0x0849)
#define TCC1_CTRLGCLR  _SFR_MEM8(0x084A)
#define TCC1_CTRLGSET  _SFR_MEM8(0x084B)
#define TCC1_INTFLAGS  _SFR_MEM8(0x084C)
#define TCC1_TEMP  _SFR_MEM8(0x084F)
#define TCC1_CNT  _SFR_MEM16(0x0860)
#define TCC1_CNTL  _SFR_MEM8(0x0860)
#define TCC1_CNTH  _SFR_MEM8(0x0861)
#define TCC1_PER  _SFR_MEM16(0x0866)
#define TCC1_PERL  _SFR_MEM8(0x0866)
#define TCC1_PERH  _SFR_MEM8(0x0867)
#define TCC1_CCA  _SFR_MEM16(0x0868)
#define TCC1_CCAL  _SFR_MEM8(0x0868)
#define TCC1_CCAH  _SFR_MEM8(0x0869)
#define TCC1_CCB  _SFR_MEM16(0x086A)
#define TCC1_CCBL  _SFR_MEM8(0x086A)
#define TCC1_CCBH  _SFR_MEM8(0x086B)
#define TCC1_PERBUF  _SFR_MEM16(0x0876)
#define TCC1_PERBUFL  _SFR_MEM8(0x0876)
#define TCC1_PERBUFH  _SFR_MEM8(0x0877)
#define TCC1_CCABUF  _SFR_MEM16(0x0878)
#define TCC1_CCABUFL  _SFR_MEM8(0x0878)
#define TCC1_CCABUFH  _SFR_MEM8(0x0879)
#define TCC1_CCBBUF  _SFR_MEM16(0x087A)
#define TCC1_CCBBUFL  _SFR_MEM8(0x087A)
#define TCC1_CCBBUFH  _SFR_MEM8(0x087B)


/* USART (USARTC0) - Universal Synchronous/Asynchronous Receiver/Transmitter */
#define USARTC0_DATA  _SFR_MEM8(0x08A0)
#define USARTC0_STATUS  _SFR_MEM8(0x08A1)
#define USARTC0_CTRLA  _SFR_MEM8(0x08A3)
#define USARTC0_CTRLB  _SFR_MEM8(0x08A4)
#define USARTC0_CTRLC  _SFR_MEM8(0x08A5)
#define USARTC0_BAUDCTRLA  _SFR_MEM8(0x08A6)
#define USARTC0_BAUDCTRLB  _SFR_MEM8(0x08A7)


/* SPI (SPIC) - Serial Peripheral Interface */
#define SPIC_CTRL  _SFR_MEM8(0x08C0)
#define SPIC_INTCTRL  _SFR_MEM8(0x08C1)
#define SPIC_STATUS  _SFR_MEM8(0x08C2)
#define SPIC_DATA  _SFR_MEM8(0x08C3)


/* CTE - CTE Module */
#define CTE_ADCYCHR  _SFR_MEM8(0x0C00)
#define CTE_INTCRC  _SFR_MEM8(0x0C01)
#define CTE_ADCSRACLR  _SFR_MEM8(0x0C02)
#define CTE_ADCSRASET  _SFR_MEM8(0x0C03)
#define CTE_INTCRBCLR  _SFR_MEM8(0x0C04)
#define CTE_INTCRBSET  _SFR_MEM8(0x0C05)
#define CTE_INTCRECLR  _SFR_MEM8(0x0C06)
#define CTE_INTCRESET  _SFR_MEM8(0x0C07)
#define CTE_INTXCHR  _SFR_MEM8(0x0C08)
#define CTE_INTOEN  _SFR_MEM8(0x0C09)
#define CTE_TIMMOECMP  _SFR_MEM8(0x0C0A)
#define CTE_HVCRA  _SFR_MEM8(0x0C0B)
#define CTE_TIMAPER  _SFR_MEM8(0x0C0C)
#define CTE_TIMBPER  _SFR_MEM8(0x0C0D)
#define CTE_TIMCPER  _SFR_MEM8(0x0C0E)
#define CTE_TIMMOEPER  _SFR_MEM8(0x0C0F)
#define CTE_TIMRSTPER  _SFR_MEM8(0x0C10)
#define CTE_INTDONE  _SFR_MEM8(0x0C11)
#define CTE_INTTRIGA  _SFR_MEM8(0x0C12)
#define CTE_INTTRIGB  _SFR_MEM8(0x0C13)
#define CTE_INTGAIN0  _SFR_MEM8(0x0C14)
#define CTE_INTGAIN1  _SFR_MEM8(0x0C15)
#define CTE_INTGAIN2  _SFR_MEM8(0x0C16)
#define CTE_INTGAIN3  _SFR_MEM8(0x0C17)
#define CTE_GCAFSRA  _SFR_MEM8(0x0C18)
#define CTE_GCAFHDLCNT  _SFR_MEM8(0x0C1A)
#define CTE_GCAFHDHCNT  _SFR_MEM8(0x0C1B)
#define CTE_GCAFMCEN  _SFR_MEM8(0x0C1E)
#define CTE_GCAFCCCLIM  _SFR_MEM8(0x0C1F)
#define CTE_PIFXPORTA  _SFR_MEM8(0x0C20)
#define CTE_PIFXPORTB  _SFR_MEM8(0x0C21)
#define CTE_PIFYPORT  _SFR_MEM8(0x0C22)
#define CTE_PIFXDDRA  _SFR_MEM8(0x0C23)
#define CTE_PIFXDDRB  _SFR_MEM8(0x0C24)
#define CTE_PIFYDDR  _SFR_MEM8(0x0C25)
#define CTE_PIFXPINA  _SFR_MEM8(0x0C26)
#define CTE_PIFXPINB  _SFR_MEM8(0x0C27)
#define CTE_PIFYPIN  _SFR_MEM8(0x0C28)
#define CTE_PIFXTGLA  _SFR_MEM8(0x0C29)
#define CTE_PIFXTGLB  _SFR_MEM8(0x0C2A)
#define CTE_PIFYTGL  _SFR_MEM8(0x0C2B)
#define CTE_PIFILA  _SFR_MEM8(0x0C2C)
#define CTE_PIFILB  _SFR_MEM8(0x0C2D)
#define CTE_PIFILE  _SFR_MEM8(0x0C2E)
#define CTE_PIFILO  _SFR_MEM8(0x0C2F)
#define CTE_ADCCRA  _SFR_MEM8(0x0C40)
#define CTE_ADCCRB  _SFR_MEM8(0x0C41)
#define CTE_ADCINTCAL  _SFR_MEM8(0x0C43)
#define CTE_ADCRES  _SFR_MEM8(0x0C44)
#define CTE_ADCINTTEST  _SFR_MEM8(0x0C45)
#define CTE_ADCSHVBCAL  _SFR_MEM8(0x0C46)
#define CTE_INTCRA  _SFR_MEM8(0x0C48)
#define CTE_INTCRD  _SFR_MEM8(0x0C49)
#define CTE_INTEN  _SFR_MEM8(0x0C4A)
#define CTE_INTMASKEN  _SFR_MEM8(0x0C4B)
#define CTE_SHEN  _SFR_MEM8(0x0C4C)
#define CTE_BIASCR  _SFR_MEM8(0x0C4D)
#define CTE_HVSEQT  _SFR_MEM8(0x0C4F)
#define CTE_HDCRA  _SFR_MEM8(0x0C50)
#define CTE_HDEN  _SFR_MEM8(0x0C51)
#define CTE_HDLOW  _SFR_MEM8(0x0C52)
#define CTE_HDHIGH  _SFR_MEM8(0x0C53)
#define CTE_GCAFCRA  _SFR_MEM8(0x0C58)
#define CTE_GCAFCRB  _SFR_MEM8(0x0C59)
#define CTE_GCAFBASELIM  _SFR_MEM8(0x0C5B)
#define CTE_GCAFPCLL  _SFR_MEM8(0x0C5C)
#define CTE_GCAFPCUL  _SFR_MEM8(0x0C5D)
#define CTE_PIFXENA  _SFR_MEM8(0x0C60)
#define CTE_PIFXENB  _SFR_MEM8(0x0C61)
#define CTE_PIFYEN  _SFR_MEM8(0x0C62)
#define CTE_PIFXDDRA_SHADOW  _SFR_MEM8(0x0C63)
#define CTE_PIFXDDRB_SHADOW  _SFR_MEM8(0x0C64)
#define CTE_PIFYDDR_SHADOW  _SFR_MEM8(0x0C65)
#define CTE_PIFXSRLA  _SFR_MEM8(0x0C66)
#define CTE_PIFXSRLB  _SFR_MEM8(0x0C67)
#define CTE_PIFYSRL  _SFR_MEM8(0x0C68)
#define CTE_CTTEMP  _SFR_MEM8(0x0C80)
#define CTE_CTCRA  _SFR_MEM8(0x0C81)
#define CTE_MS0_MSCRA  _SFR_MEM8(0x0CA0)
#define CTE_MS0_MSCRB  _SFR_MEM8(0x0CA1)
#define CTE_MS0_MSPSEL  _SFR_MEM8(0x0CA3)
#define CTE_MS0_MSSRACLR  _SFR_MEM8(0x0CA4)
#define CTE_MS0_MSSRASET  _SFR_MEM8(0x0CA5)
#define CTE_MS0_MSSRB  _SFR_MEM8(0x0CA6)
#define CTE_MS0_MSSRC  _SFR_MEM8(0x0CA7)
#define CTE_MS0_MSSRD  _SFR_MEM8(0x0CA8)
#define CTE_MS0_MSCCR  _SFR_MEM8(0x0CAA)
#define CTE_MS0_MSLRR  _SFR_MEM16(0x0CAD)
#define CTE_MS0_MSPC  _SFR_MEM16(0x0CB0)
#define CTE_MS0_MSHIF  _SFR_MEM8(0x0CB2)
#define CTE_MS0_MSIR0  _SFR_MEM8(0x0CB4)
#define CTE_MS0_MSIR1  _SFR_MEM8(0x0CB5)
#define CTE_MS0_MSIR2  _SFR_MEM8(0x0CB6)
#define CTE_MS0_MSIR3  _SFR_MEM8(0x0CB7)
#define CTE_MS0_MSIRBUF  _SFR_MEM16(0x0CB8)
#define CTE_MS0_MSR0  _SFR_MEM16(0x0CBA)


#define CTE_MS1_MSCRA  _SFR_MEM8(0x0CC0)
#define CTE_MS1_MSCRB  _SFR_MEM8(0x0CC1)
#define CTE_MS1_MSPSEL  _SFR_MEM8(0x0CC3)
#define CTE_MS1_MSSRACLR  _SFR_MEM8(0x0CC4)
#define CTE_MS1_MSSRASET  _SFR_MEM8(0x0CC5)
#define CTE_MS1_MSSRB  _SFR_MEM8(0x0CC6)
#define CTE_MS1_MSSRC  _SFR_MEM8(0x0CC7)
#define CTE_MS1_MSSRD  _SFR_MEM8(0x0CC8)
#define CTE_MS1_MSCCR  _SFR_MEM8(0x0CCA)
#define CTE_MS1_MSLRR  _SFR_MEM16(0x0CCD)
#define CTE_MS1_MSPC  _SFR_MEM16(0x0CD0)
#define CTE_MS1_MSHIF  _SFR_MEM8(0x0CD2)
#define CTE_MS1_MSIR0  _SFR_MEM8(0x0CD4)
#define CTE_MS1_MSIR1  _SFR_MEM8(0x0CD5)
#define CTE_MS1_MSIR2  _SFR_MEM8(0x0CD6)
#define CTE_MS1_MSIR3  _SFR_MEM8(0x0CD7)
#define CTE_MS1_MSIRBUF  _SFR_MEM16(0x0CD8)
#define CTE_MS1_MSR0  _SFR_MEM16(0x0CDA)





/*================== Bitfield Definitions ================== */

/* CLK - Clock System */
/* CLK.CTRL  bit masks and bit positions */
#define CLK_SCLKSEL_gm  0x07  /* System Clock Selection group mask. */
#define CLK_SCLKSEL_gp  0  /* System Clock Selection group position. */
#define CLK_SCLKSEL0_bm  (1<<0)  /* System Clock Selection bit 0 mask. */
#define CLK_SCLKSEL0_bp  0  /* System Clock Selection bit 0 position. */
#define CLK_SCLKSEL1_bm  (1<<1)  /* System Clock Selection bit 1 mask. */
#define CLK_SCLKSEL1_bp  1  /* System Clock Selection bit 1 position. */
#define CLK_SCLKSEL2_bm  (1<<2)  /* System Clock Selection bit 2 mask. */
#define CLK_SCLKSEL2_bp  2  /* System Clock Selection bit 2 position. */

/* CLK.PSCTRL  bit masks and bit positions */
#define CLK_PSBCDIV_gm  0x03  /* Prescaler B and C Division factor group mask. */
#define CLK_PSBCDIV_gp  0  /* Prescaler B and C Division factor group position. */
#define CLK_PSBCDIV0_bm  (1<<0)  /* Prescaler B and C Division factor bit 0 mask. */
#define CLK_PSBCDIV0_bp  0  /* Prescaler B and C Division factor bit 0 position. */
#define CLK_PSBCDIV1_bm  (1<<1)  /* Prescaler B and C Division factor bit 1 mask. */
#define CLK_PSBCDIV1_bp  1  /* Prescaler B and C Division factor bit 1 position. */
#define CLK_PSADIV_gm  0x7C  /* Prescaler A Division Factor group mask. */
#define CLK_PSADIV_gp  2  /* Prescaler A Division Factor group position. */
#define CLK_PSADIV0_bm  (1<<2)  /* Prescaler A Division Factor bit 0 mask. */
#define CLK_PSADIV0_bp  2  /* Prescaler A Division Factor bit 0 position. */
#define CLK_PSADIV1_bm  (1<<3)  /* Prescaler A Division Factor bit 1 mask. */
#define CLK_PSADIV1_bp  3  /* Prescaler A Division Factor bit 1 position. */
#define CLK_PSADIV2_bm  (1<<4)  /* Prescaler A Division Factor bit 2 mask. */
#define CLK_PSADIV2_bp  4  /* Prescaler A Division Factor bit 2 position. */
#define CLK_PSADIV3_bm  (1<<5)  /* Prescaler A Division Factor bit 3 mask. */
#define CLK_PSADIV3_bp  5  /* Prescaler A Division Factor bit 3 position. */
#define CLK_PSADIV4_bm  (1<<6)  /* Prescaler A Division Factor bit 4 mask. */
#define CLK_PSADIV4_bp  6  /* Prescaler A Division Factor bit 4 position. */

/* CLK.LOCK  bit masks and bit positions */
#define CLK_LOCK_bm  0x01  /* Clock System Lock bit mask. */
#define CLK_LOCK_bp  0  /* Clock System Lock bit position. */

/* CLK.RTCCTRL  bit masks and bit positions */
#define CLK_RTCEN_bm  0x01  /* RTC Clock Source Enable bit mask. */
#define CLK_RTCEN_bp  0  /* RTC Clock Source Enable bit position. */
#define CLK_RTCSRC_gm  0x0E  /* RTC Clock Source group mask. */
#define CLK_RTCSRC_gp  1  /* RTC Clock Source group position. */
#define CLK_RTCSRC0_bm  (1<<1)  /* RTC Clock Source bit 0 mask. */
#define CLK_RTCSRC0_bp  1  /* RTC Clock Source bit 0 position. */
#define CLK_RTCSRC1_bm  (1<<2)  /* RTC Clock Source bit 1 mask. */
#define CLK_RTCSRC1_bp  2  /* RTC Clock Source bit 1 position. */
#define CLK_RTCSRC2_bm  (1<<3)  /* RTC Clock Source bit 2 mask. */
#define CLK_RTCSRC2_bp  3  /* RTC Clock Source bit 2 position. */

/* PR.PRGEN  bit masks and bit positions */
#define PR_DMA_bm  0x01  /* DMA-Controller bit mask. */
#define PR_DMA_bp  0  /* DMA-Controller bit position. */
#define PR_EVSYS_bm  0x02  /* Event System bit mask. */
#define PR_EVSYS_bp  1  /* Event System bit position. */
#define PR_RTC_bm  0x04  /* Real-time Counter bit mask. */
#define PR_RTC_bp  2  /* Real-time Counter bit position. */
#define PR_EBI_bm  0x08  /* External Bus Interface bit mask. */
#define PR_EBI_bp  3  /* External Bus Interface bit position. */
#define PR_AES_bm  0x10  /* AES bit mask. */
#define PR_AES_bp  4  /* AES bit position. */
#define PR_CTM_bm  0x20  /* CTM bit mask. */
#define PR_CTM_bp  5  /* CTM bit position. */

/* PR.PRPA  bit masks and bit positions */
#define PR_AC_bm  0x01  /* Port A Analog Comparator bit mask. */
#define PR_AC_bp  0  /* Port A Analog Comparator bit position. */
#define PR_ADC_bm  0x02  /* Port A ADC bit mask. */
#define PR_ADC_bp  1  /* Port A ADC bit position. */
#define PR_DAC_bm  0x04  /* Port A DAC bit mask. */
#define PR_DAC_bp  2  /* Port A DAC bit position. */

/* PR.PRPB  bit masks and bit positions */
/* PR_AC  is already defined. */
/* PR_ADC  is already defined. */
/* PR_DAC  is already defined. */

/* PR.PRPC  bit masks and bit positions */
#define PR_TC0_bm  0x01  /* Port C Timer/Counter0 bit mask. */
#define PR_TC0_bp  0  /* Port C Timer/Counter0 bit position. */
#define PR_TC1_bm  0x02  /* Port C Timer/Counter1 bit mask. */
#define PR_TC1_bp  1  /* Port C Timer/Counter1 bit position. */
#define PR_HIRES_bm  0x04  /* Port C AWEX bit mask. */
#define PR_HIRES_bp  2  /* Port C AWEX bit position. */
#define PR_SPI_bm  0x08  /* Port C SPI bit mask. */
#define PR_SPI_bp  3  /* Port C SPI bit position. */
#define PR_USART0_bm  0x10  /* Port C USART0 bit mask. */
#define PR_USART0_bp  4  /* Port C USART0 bit position. */
#define PR_USART1_bm  0x20  /* Port C USART1 bit mask. */
#define PR_USART1_bp  5  /* Port C USART1 bit position. */
#define PR_TWI_bm  0x40  /* Port C Two-wire Interface bit mask. */
#define PR_TWI_bp  6  /* Port C Two-wire Interface bit position. */

/* PR.PRPD  bit masks and bit positions */
/* PR_TC0  is already defined. */
/* PR_TC1  is already defined. */
/* PR_HIRES  is already defined. */
/* PR_SPI  is already defined. */
/* PR_USART0  is already defined. */
/* PR_USART1  is already defined. */
/* PR_TWI  is already defined. */

/* PR.PRPE  bit masks and bit positions */
/* PR_TC0  is already defined. */
/* PR_TC1  is already defined. */
/* PR_HIRES  is already defined. */
/* PR_SPI  is already defined. */
/* PR_USART0  is already defined. */
/* PR_USART1  is already defined. */
/* PR_TWI  is already defined. */

/* PR.PRPF  bit masks and bit positions */
/* PR_TC0  is already defined. */
/* PR_TC1  is already defined. */
/* PR_HIRES  is already defined. */
/* PR_SPI  is already defined. */
/* PR_USART0  is already defined. */
/* PR_USART1  is already defined. */
/* PR_TWI  is already defined. */

/* PWR.PWRCR  bit masks and bit positions */
#define PWR_PWRLVLSEN_bm  0x01  /* Power Control Level Shifter Enable bit mask. */
#define PWR_PWRLVLSEN_bp  0  /* Power Control Level Shifter Enable bit position. */
#define PWR_PWRLVLSDIS_bm  0x02  /* Power Control Level Shifter Disable bit mask. */
#define PWR_PWRLVLSDIS_bp  1  /* Power Control Level Shifter Disable bit position. */
#define PWR_PWRBODEN_bm  0x80  /* Power Control BOD Enable bit mask. */
#define PWR_PWRBODEN_bp  7  /* Power Control BOD Enable bit position. */

/* PWR.PWRSR  bit masks and bit positions */
#define PWR_PWROK_bm  0x01  /* Power OK bit mask. */
#define PWR_PWROK_bp  0  /* Power OK bit position. */
#define PWR_PWRRSTDONE_bm  0x02  /* Power Control Reset Done bit mask. */
#define PWR_PWRRSTDONE_bp  1  /* Power Control Reset Done bit position. */
#define PWR_PWRLVLSS_bm  0x04  /* Power Controller Levelshifter Status bit mask. */
#define PWR_PWRLVLSS_bp  2  /* Power Controller Levelshifter Status bit position. */

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

/* CTE - CTE Module */
/* CTEMS.MSCRA  bit masks and bit positions */
#define CTEMS_MSBE_bm  0x01  /* MS Break Enable bit mask. */
#define CTEMS_MSBE_bp  0  /* MS Break Enable bit position. */
#define CTEMS_MSIL_gm  0x06  /* MS Interrupt Level group mask. */
#define CTEMS_MSIL_gp  1  /* MS Interrupt Level group position. */
#define CTEMS_MSIL0_bm  (1<<1)  /* MS Interrupt Level bit 0 mask. */
#define CTEMS_MSIL0_bp  1  /* MS Interrupt Level bit 0 position. */
#define CTEMS_MSIL1_bm  (1<<2)  /* MS Interrupt Level bit 1 mask. */
#define CTEMS_MSIL1_bp  2  /* MS Interrupt Level bit 1 position. */
#define CTEMS_MSIOAE_bm  0x08  /* MS I/O Access Enable bit mask. */
#define CTEMS_MSIOAE_bp  3  /* MS I/O Access Enable bit position. */
#define CTEMS_MSSEXT_bm  0x10  /* MS Sign extend bit mask. */
#define CTEMS_MSSEXT_bp  4  /* MS Sign extend bit position. */
#define CTEMS_MSDDZC_bm  0x20  /* MS Disable division by zero check bit mask. */
#define CTEMS_MSDDZC_bp  5  /* MS Disable division by zero check bit position. */
#define CTEMS_MSSSAT6_bm  0x40  /* MS Signed SAT6 bit mask. */
#define CTEMS_MSSSAT6_bp  6  /* MS Signed SAT6 bit position. */

/* CTEMS.MSCRB  bit masks and bit positions */
#define CTEMS_MSTCCS_gm  0x0F  /* MS Timer/Counter Clock Select group mask. */
#define CTEMS_MSTCCS_gp  0  /* MS Timer/Counter Clock Select group position. */
#define CTEMS_MSTCCS0_bm  (1<<0)  /* MS Timer/Counter Clock Select bit 0 mask. */
#define CTEMS_MSTCCS0_bp  0  /* MS Timer/Counter Clock Select bit 0 position. */
#define CTEMS_MSTCCS1_bm  (1<<1)  /* MS Timer/Counter Clock Select bit 1 mask. */
#define CTEMS_MSTCCS1_bp  1  /* MS Timer/Counter Clock Select bit 1 position. */
#define CTEMS_MSTCCS2_bm  (1<<2)  /* MS Timer/Counter Clock Select bit 2 mask. */
#define CTEMS_MSTCCS2_bp  2  /* MS Timer/Counter Clock Select bit 2 position. */
#define CTEMS_MSTCCS3_bm  (1<<3)  /* MS Timer/Counter Clock Select bit 3 mask. */
#define CTEMS_MSTCCS3_bp  3  /* MS Timer/Counter Clock Select bit 3 position. */
#define CTEMS_MSTCRE_bm  0x10  /* MS Timer/Counter Reload Enable bit mask. */
#define CTEMS_MSTCRE_bp  4  /* MS Timer/Counter Reload Enable bit position. */

/* CTEMS.MSPSEL  bit masks and bit positions */
#define CTEMS_MSPAGE_bm  0x01  /* MS Page bit mask. */
#define CTEMS_MSPAGE_bp  0  /* MS Page bit position. */

/* CTEMS.MSSRACLR  bit masks and bit positions */
#define CTEMS_MSTCUNF_bm  0x01  /* MS Timer/Counter Underflow Flag bit mask. */
#define CTEMS_MSTCUNF_bp  0  /* MS Timer/Counter Underflow Flag bit position. */
#define CTEMS_MSHSF_gm  0x1E  /* MS Handshake Flags group mask. */
#define CTEMS_MSHSF_gp  1  /* MS Handshake Flags group position. */
#define CTEMS_MSHSF0_bm  (1<<1)  /* MS Handshake Flags bit 0 mask. */
#define CTEMS_MSHSF0_bp  1  /* MS Handshake Flags bit 0 position. */
#define CTEMS_MSHSF1_bm  (1<<2)  /* MS Handshake Flags bit 1 mask. */
#define CTEMS_MSHSF1_bp  2  /* MS Handshake Flags bit 1 position. */
#define CTEMS_MSHSF2_bm  (1<<3)  /* MS Handshake Flags bit 2 mask. */
#define CTEMS_MSHSF2_bp  3  /* MS Handshake Flags bit 2 position. */
#define CTEMS_MSHSF3_bm  (1<<4)  /* MS Handshake Flags bit 3 mask. */
#define CTEMS_MSHSF3_bp  4  /* MS Handshake Flags bit 3 position. */
#define CTEMS_GCAFCCCNZ_bm  0x20  /* GCAF Computation Complete Counter Not Zero bit mask. */
#define CTEMS_GCAFCCCNZ_bp  5  /* GCAF Computation Complete Counter Not Zero bit position. */
#define CTEMS_GCAFCCCZ_bm  0x40  /* GCAF Computation Complete Counter Zero bit mask. */
#define CTEMS_GCAFCCCZ_bp  6  /* GCAF Computation Complete Counter Zero bit position. */
#define CTEMS_MSADCSYNC_bm  0x80  /* MS ADC Synchronization bit mask. */
#define CTEMS_MSADCSYNC_bp  7  /* MS ADC Synchronization bit position. */

/* CTEMS.MSSRASET  bit masks and bit positions */
/* CTEMS_MSTCUNF  is already defined. */
/* CTEMS_MSHSF  is already defined. */
/* CTEMS_GCAFCCCNZ  is already defined. */
/* CTEMS_GCAFCCCZ  is already defined. */
/* CTEMS_MSADCSYNC  is already defined. */

/* CTEMS.MSSRB  bit masks and bit positions */
/* CTEMS_MSTCUNF  is already defined. */
#define CTEMS_PIFXPIN_gm  0x3E  /* Port Interface X-line Pins group mask. */
#define CTEMS_PIFXPIN_gp  1  /* Port Interface X-line Pins group position. */
#define CTEMS_PIFXPIN0_bm  (1<<1)  /* Port Interface X-line Pins bit 0 mask. */
#define CTEMS_PIFXPIN0_bp  1  /* Port Interface X-line Pins bit 0 position. */
#define CTEMS_PIFXPIN1_bm  (1<<2)  /* Port Interface X-line Pins bit 1 mask. */
#define CTEMS_PIFXPIN1_bp  2  /* Port Interface X-line Pins bit 1 position. */
#define CTEMS_PIFXPIN2_bm  (1<<3)  /* Port Interface X-line Pins bit 2 mask. */
#define CTEMS_PIFXPIN2_bp  3  /* Port Interface X-line Pins bit 2 position. */
#define CTEMS_PIFXPIN3_bm  (1<<4)  /* Port Interface X-line Pins bit 3 mask. */
#define CTEMS_PIFXPIN3_bp  4  /* Port Interface X-line Pins bit 3 position. */
#define CTEMS_PIFXPIN4_bm  (1<<5)  /* Port Interface X-line Pins bit 4 mask. */
#define CTEMS_PIFXPIN4_bp  5  /* Port Interface X-line Pins bit 4 position. */
#define CTEMS_PIFPC2_bm  0x40  /* Port Interface Port C pin 2 bit mask. */
#define CTEMS_PIFPC2_bp  6  /* Port Interface Port C pin 2 bit position. */
#define CTEMS_PIFPC6_bm  0x80  /* Port Interface Port C pin 6 bit mask. */
#define CTEMS_PIFPC6_bp  7  /* Port Interface Port C pin 6 bit position. */

/* CTEMS.MSSRC  bit masks and bit positions */
/* CTEMS_MSTCUNF  is already defined. */
#define CTEMS_TIMADONE_bm  0x02  /* Timer A Done bit mask. */
#define CTEMS_TIMADONE_bp  1  /* Timer A Done bit position. */
#define CTEMS_TIMBDONE_bm  0x04  /* Timer B Done bit mask. */
#define CTEMS_TIMBDONE_bp  2  /* Timer B Done bit position. */
#define CTEMS_TIMCDONE_bm  0x08  /* Timer C Done bit mask. */
#define CTEMS_TIMCDONE_bp  3  /* Timer C Done bit position. */
#define CTEMS_INTMOEDONE_bm  0x10  /* Integrator Master Output Enable Timer Done bit mask. */
#define CTEMS_INTMOEDONE_bp  4  /* Integrator Master Output Enable Timer Done bit position. */
#define CTEMS_INTRSTDONE_bm  0x20  /* Integrator Reset Timer Done bit mask. */
#define CTEMS_INTRSTDONE_bp  5  /* Integrator Reset Timer Done bit position. */
#define CTEMS_SHADCDONE_bm  0x40  /* S/H and ADC Trigger bit mask. */
#define CTEMS_SHADCDONE_bp  6  /* S/H and ADC Trigger bit position. */
#define CTEMS_ALLDONE_bm  0x80  /* All Timers Done bit mask. */
#define CTEMS_ALLDONE_bp  7  /* All Timers Done bit position. */

/* CTEMS.MSSRD  bit masks and bit positions */
/* CTEMS_MSTCUNF  is already defined. */
/* CTEMS_MSHSF  is already defined. */
#define CTEMS_GCAFCCCWL_bm  0x20  /* GCAF Computation Counter Within Limits bit mask. */
#define CTEMS_GCAFCCCWL_bp  5  /* GCAF Computation Counter Within Limits bit position. */
#define CTEMS_GCAFIDLE_bm  0x40  /* GCAF Idle bit mask. */
#define CTEMS_GCAFIDLE_bp  6  /* GCAF Idle bit position. */

/* CTEMS.MSCCR  bit masks and bit positions */
#define CTEMS_ZB_bm  0x01  /* Zero Byte bit mask. */
#define CTEMS_ZB_bp  0  /* Zero Byte bit position. */
#define CTEMS_CB_bm  0x02  /* Carry Byte bit mask. */
#define CTEMS_CB_bp  1  /* Carry Byte bit position. */
#define CTEMS_SB_bm  0x04  /* Signed Byte bit mask. */
#define CTEMS_SB_bp  2  /* Signed Byte bit position. */
#define CTEMS_ZW_bm  0x08  /* Zero Word bit mask. */
#define CTEMS_ZW_bp  3  /* Zero Word bit position. */
#define CTEMS_CW_bm  0x10  /* Carry Word bit mask. */
#define CTEMS_CW_bp  4  /* Carry Word bit position. */
#define CTEMS_SW_bm  0x20  /* Signed Word bit mask. */
#define CTEMS_SW_bp  5  /* Signed Word bit position. */
#define CTEMS_T_gm  0xC0  /* Temporary flags group mask. */
#define CTEMS_T_gp  6  /* Temporary flags group position. */
#define CTEMS_T0_bm  (1<<6)  /* Temporary flags bit 0 mask. */
#define CTEMS_T0_bp  6  /* Temporary flags bit 0 position. */
#define CTEMS_T1_bm  (1<<7)  /* Temporary flags bit 1 mask. */
#define CTEMS_T1_bp  7  /* Temporary flags bit 1 position. */



/* CTEMS.MSHIF  bit masks and bit positions */
#define CTEMS_MSRUN_bm  0x01  /* MS Run bit mask. */
#define CTEMS_MSRUN_bp  0  /* MS Run bit position. */
#define CTEMS_MSSS_bm  0x02  /* MS Single Step bit mask. */
#define CTEMS_MSSS_bp  1  /* MS Single Step bit position. */
#define CTEMS_MSIF_bm  0x04  /* MS Interrupt Flag bit mask. */
#define CTEMS_MSIF_bp  2  /* MS Interrupt Flag bit position. */







/* CTE.ADCYCHR  bit masks and bit positions */
#define CTE_ADCYCH_gm  0x0F  /* ADC Y-Channel group mask. */
#define CTE_ADCYCH_gp  0  /* ADC Y-Channel group position. */
#define CTE_ADCYCH0_bm  (1<<0)  /* ADC Y-Channel bit 0 mask. */
#define CTE_ADCYCH0_bp  0  /* ADC Y-Channel bit 0 position. */
#define CTE_ADCYCH1_bm  (1<<1)  /* ADC Y-Channel bit 1 mask. */
#define CTE_ADCYCH1_bp  1  /* ADC Y-Channel bit 1 position. */
#define CTE_ADCYCH2_bm  (1<<2)  /* ADC Y-Channel bit 2 mask. */
#define CTE_ADCYCH2_bp  2  /* ADC Y-Channel bit 2 position. */
#define CTE_ADCYCH3_bm  (1<<3)  /* ADC Y-Channel bit 3 mask. */
#define CTE_ADCYCH3_bp  3  /* ADC Y-Channel bit 3 position. */
#define CTE_ADCSC_bm  0x10  /* ADC Single Channel Conversion bit mask. */
#define CTE_ADCSC_bp  4  /* ADC Single Channel Conversion bit position. */
#define CTE_ADCAUX_bm  0x20  /* ADC Auxiliary Channel Select bit mask. */
#define CTE_ADCAUX_bp  5  /* ADC Auxiliary Channel Select bit position. */

/* CTE.INTCRC  bit masks and bit positions */
#define CTE_INTRSTLVL_gm  0x07  /* Integrator Reset Level group mask. */
#define CTE_INTRSTLVL_gp  0  /* Integrator Reset Level group position. */
#define CTE_INTRSTLVL0_bm  (1<<0)  /* Integrator Reset Level bit 0 mask. */
#define CTE_INTRSTLVL0_bp  0  /* Integrator Reset Level bit 0 position. */
#define CTE_INTRSTLVL1_bm  (1<<1)  /* Integrator Reset Level bit 1 mask. */
#define CTE_INTRSTLVL1_bp  1  /* Integrator Reset Level bit 1 position. */
#define CTE_INTRSTLVL2_bm  (1<<2)  /* Integrator Reset Level bit 2 mask. */
#define CTE_INTRSTLVL2_bp  2  /* Integrator Reset Level bit 2 position. */

/* CTE.ADCSRACLR  bit masks and bit positions */
#define CTE_ADCLC_bm  0x01  /* ADC Last Conversion Result bit mask. */
#define CTE_ADCLC_bp  0  /* ADC Last Conversion Result bit position. */
#define CTE_ADCLCX_bm  0x02  /* ADC Last Conversion Result in X-line bit mask. */
#define CTE_ADCLCX_bp  1  /* ADC Last Conversion Result in X-line bit position. */
#define CTE_ADCVC_bm  0x04  /* ADC Valid Conversion Result bit mask. */
#define CTE_ADCVC_bp  2  /* ADC Valid Conversion Result bit position. */
#define CTE_ADCPS_bm  0x08  /* ADC Power Save bit mask. */
#define CTE_ADCPS_bp  3  /* ADC Power Save bit position. */
#define CTE_ADCBUSY_bm  0x10  /* ADC Busy bit mask. */
#define CTE_ADCBUSY_bp  4  /* ADC Busy bit position. */
#define CTE_ADCPIPEBUSY_bm  0x20  /* ADC Pipeline Busy bit mask. */
#define CTE_ADCPIPEBUSY_bp  5  /* ADC Pipeline Busy bit position. */
#define CTE_ADCANAPIPEBUSY_bm  0x40  /* ADC Analog Pipeline Busy bit mask. */
#define CTE_ADCANAPIPEBUSY_bp  6  /* ADC Analog Pipeline Busy bit position. */

/* CTE.ADCSRASET  bit masks and bit positions */
/* CTE_ADCLC  is already defined. */
/* CTE_ADCLCX  is already defined. */
/* CTE_ADCVC  is already defined. */
/* CTE_ADCPS  is already defined. */
/* CTE_ADCBUSY  is already defined. */
/* CTE_ADCPIPEBUSY  is already defined. */
/* CTE_ADCANAPIPEBUSY  is already defined. */

/* CTE.INTCRBCLR  bit masks and bit positions */
#define CTE_INTSIGN_bm  0x01  /* Integrator Sign bit mask. */
#define CTE_INTSIGN_bp  0  /* Integrator Sign bit position. */
#define CTE_TIMA_bm  0x02  /* Timer A Output bit mask. */
#define CTE_TIMA_bp  1  /* Timer A Output bit position. */
#define CTE_TIMB_bm  0x04  /* Timer B Output bit mask. */
#define CTE_TIMB_bp  2  /* Timer B Output bit position. */
#define CTE_TIMC_bm  0x08  /* Timer C Output bit mask. */
#define CTE_TIMC_bp  3  /* Timer C Output bit position. */
#define CTE_INTMOE_bm  0x10  /* Integrator Master Output Enable bit mask. */
#define CTE_INTMOE_bp  4  /* Integrator Master Output Enable bit position. */
#define CTE_INTRST_bm  0x20  /* Integrator Reset bit mask. */
#define CTE_INTRST_bp  5  /* Integrator Reset bit position. */
#define CTE_SHADC_bm  0x40  /* S/H and ADC Pending bit mask. */
#define CTE_SHADC_bp  6  /* S/H and ADC Pending bit position. */
#define CTE_INTID_bm  0x80  /* Integrator input disable bit mask. */
#define CTE_INTID_bp  7  /* Integrator input disable bit position. */

/* CTE.INTCRBSET  bit masks and bit positions */
/* CTE_INTSIGN  is already defined. */
/* CTE_TIMA  is already defined. */
/* CTE_TIMB  is already defined. */
/* CTE_TIMC  is already defined. */
/* CTE_INTMOE  is already defined. */
/* CTE_INTRST  is already defined. */
/* CTE_SHADC  is already defined. */
/* CTE_INTID  is already defined. */

/* CTE.INTCRECLR  bit masks and bit positions */
#define CTE_INTYONX_gm  0x03  /* Integrator Y on X group mask. */
#define CTE_INTYONX_gp  0  /* Integrator Y on X group position. */
#define CTE_INTYONX0_bm  (1<<0)  /* Integrator Y on X bit 0 mask. */
#define CTE_INTYONX0_bp  0  /* Integrator Y on X bit 0 position. */
#define CTE_INTYONX1_bm  (1<<1)  /* Integrator Y on X bit 1 mask. */
#define CTE_INTYONX1_bp  1  /* Integrator Y on X bit 1 position. */
#define CTE_INTBYPASSX_bm  0x04  /* Integrator Bypass X-line bit mask. */
#define CTE_INTBYPASSX_bp  2  /* Integrator Bypass X-line bit position. */
#define CTE_INTBYPASSY_bm  0x08  /* Integrator Bypass Y-line bit mask. */
#define CTE_INTBYPASSY_bp  3  /* Integrator Bypass Y-line bit position. */
#define CTE_INTDIBUFX_bm  0x10  /* Integrator Dummy Input Buffer connect to X-line bit mask. */
#define CTE_INTDIBUFX_bp  4  /* Integrator Dummy Input Buffer connect to X-line bit position. */
#define CTE_INTSCCSNEN_bm  0x20  /* Integrator Selfcap NMOS Current Source Enable bit mask. */
#define CTE_INTSCCSNEN_bp  5  /* Integrator Selfcap NMOS Current Source Enable bit position. */
#define CTE_INTSCCSPEN_bm  0x40  /* Integrator Selfcap PMOS Current Source Enable bit mask. */
#define CTE_INTSCCSPEN_bp  6  /* Integrator Selfcap PMOS Current Source Enable bit position. */
#define CTE_INTSCPROX_bm  0x80  /* Integrator Selfcap Proximity Mode bit mask. */
#define CTE_INTSCPROX_bp  7  /* Integrator Selfcap Proximity Mode bit position. */

/* CTE.INTCRESET  bit masks and bit positions */
/* CTE_INTYONX  is already defined. */
/* CTE_INTBYPASSX  is already defined. */
/* CTE_INTBYPASSY  is already defined. */
/* CTE_INTDIBUFX  is already defined. */
/* CTE_INTSCCSNEN  is already defined. */
/* CTE_INTSCCSPEN  is already defined. */
/* CTE_INTSCPROX  is already defined. */

/* CTE.INTXCHR  bit masks and bit positions */
#define CTE_INTXCH_gm  0x3F  /* Integrator X-Channel group mask. */
#define CTE_INTXCH_gp  0  /* Integrator X-Channel group position. */
#define CTE_INTXCH0_bm  (1<<0)  /* Integrator X-Channel bit 0 mask. */
#define CTE_INTXCH0_bp  0  /* Integrator X-Channel bit 0 position. */
#define CTE_INTXCH1_bm  (1<<1)  /* Integrator X-Channel bit 1 mask. */
#define CTE_INTXCH1_bp  1  /* Integrator X-Channel bit 1 position. */
#define CTE_INTXCH2_bm  (1<<2)  /* Integrator X-Channel bit 2 mask. */
#define CTE_INTXCH2_bp  2  /* Integrator X-Channel bit 2 position. */
#define CTE_INTXCH3_bm  (1<<3)  /* Integrator X-Channel bit 3 mask. */
#define CTE_INTXCH3_bp  3  /* Integrator X-Channel bit 3 position. */
#define CTE_INTXCH4_bm  (1<<4)  /* Integrator X-Channel bit 4 mask. */
#define CTE_INTXCH4_bp  4  /* Integrator X-Channel bit 4 position. */
#define CTE_INTXCH5_bm  (1<<5)  /* Integrator X-Channel bit 5 mask. */
#define CTE_INTXCH5_bp  5  /* Integrator X-Channel bit 5 position. */

/* CTE.INTOEN  bit masks and bit positions */
#define CTE_INTOEN_7_0_gm  0xFF  /* Integrator X-Channel Output Enable group mask. */
#define CTE_INTOEN_7_0_gp  0  /* Integrator X-Channel Output Enable group position. */
#define CTE_INTOEN_7_00_bm  (1<<0)  /* Integrator X-Channel Output Enable bit 0 mask. */
#define CTE_INTOEN_7_00_bp  0  /* Integrator X-Channel Output Enable bit 0 position. */
#define CTE_INTOEN_7_01_bm  (1<<1)  /* Integrator X-Channel Output Enable bit 1 mask. */
#define CTE_INTOEN_7_01_bp  1  /* Integrator X-Channel Output Enable bit 1 position. */
#define CTE_INTOEN_7_02_bm  (1<<2)  /* Integrator X-Channel Output Enable bit 2 mask. */
#define CTE_INTOEN_7_02_bp  2  /* Integrator X-Channel Output Enable bit 2 position. */
#define CTE_INTOEN_7_03_bm  (1<<3)  /* Integrator X-Channel Output Enable bit 3 mask. */
#define CTE_INTOEN_7_03_bp  3  /* Integrator X-Channel Output Enable bit 3 position. */
#define CTE_INTOEN_7_04_bm  (1<<4)  /* Integrator X-Channel Output Enable bit 4 mask. */
#define CTE_INTOEN_7_04_bp  4  /* Integrator X-Channel Output Enable bit 4 position. */
#define CTE_INTOEN_7_05_bm  (1<<5)  /* Integrator X-Channel Output Enable bit 5 mask. */
#define CTE_INTOEN_7_05_bp  5  /* Integrator X-Channel Output Enable bit 5 position. */
#define CTE_INTOEN_7_06_bm  (1<<6)  /* Integrator X-Channel Output Enable bit 6 mask. */
#define CTE_INTOEN_7_06_bp  6  /* Integrator X-Channel Output Enable bit 6 position. */
#define CTE_INTOEN_7_07_bm  (1<<7)  /* Integrator X-Channel Output Enable bit 7 mask. */
#define CTE_INTOEN_7_07_bp  7  /* Integrator X-Channel Output Enable bit 7 position. */

/* CTE.TIMMOECMP  bit masks and bit positions */
#define CTE_TIMMOECMP_7_0_gm  0xFF  /*  group mask. */
#define CTE_TIMMOECMP_7_0_gp  0  /*  group position. */
#define CTE_TIMMOECMP_7_00_bm  (1<<0)  /*  bit 0 mask. */
#define CTE_TIMMOECMP_7_00_bp  0  /*  bit 0 position. */
#define CTE_TIMMOECMP_7_01_bm  (1<<1)  /*  bit 1 mask. */
#define CTE_TIMMOECMP_7_01_bp  1  /*  bit 1 position. */
#define CTE_TIMMOECMP_7_02_bm  (1<<2)  /*  bit 2 mask. */
#define CTE_TIMMOECMP_7_02_bp  2  /*  bit 2 position. */
#define CTE_TIMMOECMP_7_03_bm  (1<<3)  /*  bit 3 mask. */
#define CTE_TIMMOECMP_7_03_bp  3  /*  bit 3 position. */
#define CTE_TIMMOECMP_7_04_bm  (1<<4)  /*  bit 4 mask. */
#define CTE_TIMMOECMP_7_04_bp  4  /*  bit 4 position. */
#define CTE_TIMMOECMP_7_05_bm  (1<<5)  /*  bit 5 mask. */
#define CTE_TIMMOECMP_7_05_bp  5  /*  bit 5 position. */
#define CTE_TIMMOECMP_7_06_bm  (1<<6)  /*  bit 6 mask. */
#define CTE_TIMMOECMP_7_06_bp  6  /*  bit 6 position. */
#define CTE_TIMMOECMP_7_07_bm  (1<<7)  /*  bit 7 mask. */
#define CTE_TIMMOECMP_7_07_bp  7  /*  bit 7 position. */

/* CTE.HVCRA  bit masks and bit positions */
#define CTE_HVPEN_bm  0x01  /* HV Pump Enable bit mask. */
#define CTE_HVPEN_bp  0  /* HV Pump Enable bit position. */
#define CTE_HVSWEN_bm  0x02  /* HV Switch Enable bit mask. */
#define CTE_HVSWEN_bp  1  /* HV Switch Enable bit position. */
#define CTE_HVSEQEN_bm  0x04  /* HV Sequencer Enable bit mask. */
#define CTE_HVSEQEN_bp  2  /* HV Sequencer Enable bit position. */

/* CTE.TIMAPER  bit masks and bit positions */
#define CTE_TIMAPER_7_0_gm  0xFF  /* Timer A Period bit 7-0 group mask. */
#define CTE_TIMAPER_7_0_gp  0  /* Timer A Period bit 7-0 group position. */
#define CTE_TIMAPER_7_00_bm  (1<<0)  /* Timer A Period bit 7-0 bit 0 mask. */
#define CTE_TIMAPER_7_00_bp  0  /* Timer A Period bit 7-0 bit 0 position. */
#define CTE_TIMAPER_7_01_bm  (1<<1)  /* Timer A Period bit 7-0 bit 1 mask. */
#define CTE_TIMAPER_7_01_bp  1  /* Timer A Period bit 7-0 bit 1 position. */
#define CTE_TIMAPER_7_02_bm  (1<<2)  /* Timer A Period bit 7-0 bit 2 mask. */
#define CTE_TIMAPER_7_02_bp  2  /* Timer A Period bit 7-0 bit 2 position. */
#define CTE_TIMAPER_7_03_bm  (1<<3)  /* Timer A Period bit 7-0 bit 3 mask. */
#define CTE_TIMAPER_7_03_bp  3  /* Timer A Period bit 7-0 bit 3 position. */
#define CTE_TIMAPER_7_04_bm  (1<<4)  /* Timer A Period bit 7-0 bit 4 mask. */
#define CTE_TIMAPER_7_04_bp  4  /* Timer A Period bit 7-0 bit 4 position. */
#define CTE_TIMAPER_7_05_bm  (1<<5)  /* Timer A Period bit 7-0 bit 5 mask. */
#define CTE_TIMAPER_7_05_bp  5  /* Timer A Period bit 7-0 bit 5 position. */
#define CTE_TIMAPER_7_06_bm  (1<<6)  /* Timer A Period bit 7-0 bit 6 mask. */
#define CTE_TIMAPER_7_06_bp  6  /* Timer A Period bit 7-0 bit 6 position. */
#define CTE_TIMAPER_7_07_bm  (1<<7)  /* Timer A Period bit 7-0 bit 7 mask. */
#define CTE_TIMAPER_7_07_bp  7  /* Timer A Period bit 7-0 bit 7 position. */

/* CTE.TIMBPER  bit masks and bit positions */
#define CTE_TIMBPER_7_0_gm  0xFF  /* Timer B Period bit 7-0 group mask. */
#define CTE_TIMBPER_7_0_gp  0  /* Timer B Period bit 7-0 group position. */
#define CTE_TIMBPER_7_00_bm  (1<<0)  /* Timer B Period bit 7-0 bit 0 mask. */
#define CTE_TIMBPER_7_00_bp  0  /* Timer B Period bit 7-0 bit 0 position. */
#define CTE_TIMBPER_7_01_bm  (1<<1)  /* Timer B Period bit 7-0 bit 1 mask. */
#define CTE_TIMBPER_7_01_bp  1  /* Timer B Period bit 7-0 bit 1 position. */
#define CTE_TIMBPER_7_02_bm  (1<<2)  /* Timer B Period bit 7-0 bit 2 mask. */
#define CTE_TIMBPER_7_02_bp  2  /* Timer B Period bit 7-0 bit 2 position. */
#define CTE_TIMBPER_7_03_bm  (1<<3)  /* Timer B Period bit 7-0 bit 3 mask. */
#define CTE_TIMBPER_7_03_bp  3  /* Timer B Period bit 7-0 bit 3 position. */
#define CTE_TIMBPER_7_04_bm  (1<<4)  /* Timer B Period bit 7-0 bit 4 mask. */
#define CTE_TIMBPER_7_04_bp  4  /* Timer B Period bit 7-0 bit 4 position. */
#define CTE_TIMBPER_7_05_bm  (1<<5)  /* Timer B Period bit 7-0 bit 5 mask. */
#define CTE_TIMBPER_7_05_bp  5  /* Timer B Period bit 7-0 bit 5 position. */
#define CTE_TIMBPER_7_06_bm  (1<<6)  /* Timer B Period bit 7-0 bit 6 mask. */
#define CTE_TIMBPER_7_06_bp  6  /* Timer B Period bit 7-0 bit 6 position. */
#define CTE_TIMBPER_7_07_bm  (1<<7)  /* Timer B Period bit 7-0 bit 7 mask. */
#define CTE_TIMBPER_7_07_bp  7  /* Timer B Period bit 7-0 bit 7 position. */

/* CTE.TIMCPER  bit masks and bit positions */
#define CTE_TIMCPER_7_0_gm  0xFF  /* Timer C Period bit 7-0 group mask. */
#define CTE_TIMCPER_7_0_gp  0  /* Timer C Period bit 7-0 group position. */
#define CTE_TIMCPER_7_00_bm  (1<<0)  /* Timer C Period bit 7-0 bit 0 mask. */
#define CTE_TIMCPER_7_00_bp  0  /* Timer C Period bit 7-0 bit 0 position. */
#define CTE_TIMCPER_7_01_bm  (1<<1)  /* Timer C Period bit 7-0 bit 1 mask. */
#define CTE_TIMCPER_7_01_bp  1  /* Timer C Period bit 7-0 bit 1 position. */
#define CTE_TIMCPER_7_02_bm  (1<<2)  /* Timer C Period bit 7-0 bit 2 mask. */
#define CTE_TIMCPER_7_02_bp  2  /* Timer C Period bit 7-0 bit 2 position. */
#define CTE_TIMCPER_7_03_bm  (1<<3)  /* Timer C Period bit 7-0 bit 3 mask. */
#define CTE_TIMCPER_7_03_bp  3  /* Timer C Period bit 7-0 bit 3 position. */
#define CTE_TIMCPER_7_04_bm  (1<<4)  /* Timer C Period bit 7-0 bit 4 mask. */
#define CTE_TIMCPER_7_04_bp  4  /* Timer C Period bit 7-0 bit 4 position. */
#define CTE_TIMCPER_7_05_bm  (1<<5)  /* Timer C Period bit 7-0 bit 5 mask. */
#define CTE_TIMCPER_7_05_bp  5  /* Timer C Period bit 7-0 bit 5 position. */
#define CTE_TIMCPER_7_06_bm  (1<<6)  /* Timer C Period bit 7-0 bit 6 mask. */
#define CTE_TIMCPER_7_06_bp  6  /* Timer C Period bit 7-0 bit 6 position. */
#define CTE_TIMCPER_7_07_bm  (1<<7)  /* Timer C Period bit 7-0 bit 7 mask. */
#define CTE_TIMCPER_7_07_bp  7  /* Timer C Period bit 7-0 bit 7 position. */

/* CTE.TIMMOEPER  bit masks and bit positions */
#define CTE_TIMMOEPER_7_0_gm  0xFF  /* Integrator Master Output Enable Timer Period bit 7-0 group mask. */
#define CTE_TIMMOEPER_7_0_gp  0  /* Integrator Master Output Enable Timer Period bit 7-0 group position. */
#define CTE_TIMMOEPER_7_00_bm  (1<<0)  /* Integrator Master Output Enable Timer Period bit 7-0 bit 0 mask. */
#define CTE_TIMMOEPER_7_00_bp  0  /* Integrator Master Output Enable Timer Period bit 7-0 bit 0 position. */
#define CTE_TIMMOEPER_7_01_bm  (1<<1)  /* Integrator Master Output Enable Timer Period bit 7-0 bit 1 mask. */
#define CTE_TIMMOEPER_7_01_bp  1  /* Integrator Master Output Enable Timer Period bit 7-0 bit 1 position. */
#define CTE_TIMMOEPER_7_02_bm  (1<<2)  /* Integrator Master Output Enable Timer Period bit 7-0 bit 2 mask. */
#define CTE_TIMMOEPER_7_02_bp  2  /* Integrator Master Output Enable Timer Period bit 7-0 bit 2 position. */
#define CTE_TIMMOEPER_7_03_bm  (1<<3)  /* Integrator Master Output Enable Timer Period bit 7-0 bit 3 mask. */
#define CTE_TIMMOEPER_7_03_bp  3  /* Integrator Master Output Enable Timer Period bit 7-0 bit 3 position. */
#define CTE_TIMMOEPER_7_04_bm  (1<<4)  /* Integrator Master Output Enable Timer Period bit 7-0 bit 4 mask. */
#define CTE_TIMMOEPER_7_04_bp  4  /* Integrator Master Output Enable Timer Period bit 7-0 bit 4 position. */
#define CTE_TIMMOEPER_7_05_bm  (1<<5)  /* Integrator Master Output Enable Timer Period bit 7-0 bit 5 mask. */
#define CTE_TIMMOEPER_7_05_bp  5  /* Integrator Master Output Enable Timer Period bit 7-0 bit 5 position. */
#define CTE_TIMMOEPER_7_06_bm  (1<<6)  /* Integrator Master Output Enable Timer Period bit 7-0 bit 6 mask. */
#define CTE_TIMMOEPER_7_06_bp  6  /* Integrator Master Output Enable Timer Period bit 7-0 bit 6 position. */
#define CTE_TIMMOEPER_7_07_bm  (1<<7)  /* Integrator Master Output Enable Timer Period bit 7-0 bit 7 mask. */
#define CTE_TIMMOEPER_7_07_bp  7  /* Integrator Master Output Enable Timer Period bit 7-0 bit 7 position. */

/* CTE.TIMRSTPER  bit masks and bit positions */
#define CTE_TIMRSTPER_7_0_gm  0xFF  /* Integrator Reset Timer Period bit 7-0 group mask. */
#define CTE_TIMRSTPER_7_0_gp  0  /* Integrator Reset Timer Period bit 7-0 group position. */
#define CTE_TIMRSTPER_7_00_bm  (1<<0)  /* Integrator Reset Timer Period bit 7-0 bit 0 mask. */
#define CTE_TIMRSTPER_7_00_bp  0  /* Integrator Reset Timer Period bit 7-0 bit 0 position. */
#define CTE_TIMRSTPER_7_01_bm  (1<<1)  /* Integrator Reset Timer Period bit 7-0 bit 1 mask. */
#define CTE_TIMRSTPER_7_01_bp  1  /* Integrator Reset Timer Period bit 7-0 bit 1 position. */
#define CTE_TIMRSTPER_7_02_bm  (1<<2)  /* Integrator Reset Timer Period bit 7-0 bit 2 mask. */
#define CTE_TIMRSTPER_7_02_bp  2  /* Integrator Reset Timer Period bit 7-0 bit 2 position. */
#define CTE_TIMRSTPER_7_03_bm  (1<<3)  /* Integrator Reset Timer Period bit 7-0 bit 3 mask. */
#define CTE_TIMRSTPER_7_03_bp  3  /* Integrator Reset Timer Period bit 7-0 bit 3 position. */
#define CTE_TIMRSTPER_7_04_bm  (1<<4)  /* Integrator Reset Timer Period bit 7-0 bit 4 mask. */
#define CTE_TIMRSTPER_7_04_bp  4  /* Integrator Reset Timer Period bit 7-0 bit 4 position. */
#define CTE_TIMRSTPER_7_05_bm  (1<<5)  /* Integrator Reset Timer Period bit 7-0 bit 5 mask. */
#define CTE_TIMRSTPER_7_05_bp  5  /* Integrator Reset Timer Period bit 7-0 bit 5 position. */
#define CTE_TIMRSTPER_7_06_bm  (1<<6)  /* Integrator Reset Timer Period bit 7-0 bit 6 mask. */
#define CTE_TIMRSTPER_7_06_bp  6  /* Integrator Reset Timer Period bit 7-0 bit 6 position. */
#define CTE_TIMRSTPER_7_07_bm  (1<<7)  /* Integrator Reset Timer Period bit 7-0 bit 7 mask. */
#define CTE_TIMRSTPER_7_07_bp  7  /* Integrator Reset Timer Period bit 7-0 bit 7 position. */

/* CTE.INTDONE  bit masks and bit positions */
#define CTE_TIMADONE_bm  0x02  /* Timer A Done bit mask. */
#define CTE_TIMADONE_bp  1  /* Timer A Done bit position. */
#define CTE_TIMBDONE_bm  0x04  /* Timer B Done bit mask. */
#define CTE_TIMBDONE_bp  2  /* Timer B Done bit position. */
#define CTE_TIMCDONE_bm  0x08  /* Timer C Done bit mask. */
#define CTE_TIMCDONE_bp  3  /* Timer C Done bit position. */
#define CTE_INTMOEDONE_bm  0x10  /* Integrator Master Output Enable Time Done bit mask. */
#define CTE_INTMOEDONE_bp  4  /* Integrator Master Output Enable Time Done bit position. */
#define CTE_INTRSTDONE_bm  0x20  /* Integrator Reset Timer Done bit mask. */
#define CTE_INTRSTDONE_bp  5  /* Integrator Reset Timer Done bit position. */
#define CTE_SHADCDONE_bm  0x40  /* S/H and ADC Inverted Trigger bit mask. */
#define CTE_SHADCDONE_bp  6  /* S/H and ADC Inverted Trigger bit position. */
#define CTE_ALLDONE_bm  0x80  /* All Timers Done bit mask. */
#define CTE_ALLDONE_bp  7  /* All Timers Done bit position. */

/* CTE.INTTRIGA  bit masks and bit positions */
#define CTE_INTPORTTGL_bm  0x01  /* Integrator Port Toggle bit mask. */
#define CTE_INTPORTTGL_bp  0  /* Integrator Port Toggle bit position. */
#define CTE_TIMATRIG_bm  0x02  /* Timer A Trigger bit mask. */
#define CTE_TIMATRIG_bp  1  /* Timer A Trigger bit position. */
#define CTE_TIMBTRIG_bm  0x04  /* Timer B Trigger bit mask. */
#define CTE_TIMBTRIG_bp  2  /* Timer B Trigger bit position. */
#define CTE_TIMCTRIG_bm  0x08  /* Timer C Trigger bit mask. */
#define CTE_TIMCTRIG_bp  3  /* Timer C Trigger bit position. */
#define CTE_INTMOETRIG_bm  0x10  /* Integrator Master Output Enable Trigger bit mask. */
#define CTE_INTMOETRIG_bp  4  /* Integrator Master Output Enable Trigger bit position. */
#define CTE_INTRSTTRIG_bm  0x20  /* Integrator Reset Trigger bit mask. */
#define CTE_INTRSTTRIG_bp  5  /* Integrator Reset Trigger bit position. */
#define CTE_SHADCTRIG_bm  0x40  /* S/H and ADC Trigger bit mask. */
#define CTE_SHADCTRIG_bp  6  /* S/H and ADC Trigger bit position. */
#define CTE_INTXRDY_bm  0x80  /* Integrator X-line Ready bit mask. */
#define CTE_INTXRDY_bp  7  /* Integrator X-line Ready bit position. */

/* CTE.INTTRIGB  bit masks and bit positions */
/* CTE_INTPORTTGL  is already defined. */
/* CTE_TIMATRIG  is already defined. */
/* CTE_TIMBTRIG  is already defined. */
/* CTE_TIMCTRIG  is already defined. */
/* CTE_INTMOETRIG  is already defined. */
/* CTE_INTRSTTRIG  is already defined. */
#define CTE_HVSEQXLTRIG_bm  0x40  /* High Voltage Sequencer X-Line Trigger bit mask. */
#define CTE_HVSEQXLTRIG_bp  6  /* High Voltage Sequencer X-Line Trigger bit position. */
#define CTE_SRCAPRST_bm  0x80  /* Slew Rate Capacitor Reset bit mask. */
#define CTE_SRCAPRST_bp  7  /* Slew Rate Capacitor Reset bit position. */

/* CTE.INTGAIN0  bit masks and bit positions */
#define CTE_INT0GAIN_gm  0x0F  /* Integrator 0 Gain group mask. */
#define CTE_INT0GAIN_gp  0  /* Integrator 0 Gain group position. */
#define CTE_INT0GAIN0_bm  (1<<0)  /* Integrator 0 Gain bit 0 mask. */
#define CTE_INT0GAIN0_bp  0  /* Integrator 0 Gain bit 0 position. */
#define CTE_INT0GAIN1_bm  (1<<1)  /* Integrator 0 Gain bit 1 mask. */
#define CTE_INT0GAIN1_bp  1  /* Integrator 0 Gain bit 1 position. */
#define CTE_INT0GAIN2_bm  (1<<2)  /* Integrator 0 Gain bit 2 mask. */
#define CTE_INT0GAIN2_bp  2  /* Integrator 0 Gain bit 2 position. */
#define CTE_INT0GAIN3_bm  (1<<3)  /* Integrator 0 Gain bit 3 mask. */
#define CTE_INT0GAIN3_bp  3  /* Integrator 0 Gain bit 3 position. */
#define CTE_INT1GAIN_gm  0xF0  /* Integrator 1 Gain group mask. */
#define CTE_INT1GAIN_gp  4  /* Integrator 1 Gain group position. */
#define CTE_INT1GAIN0_bm  (1<<4)  /* Integrator 1 Gain bit 0 mask. */
#define CTE_INT1GAIN0_bp  4  /* Integrator 1 Gain bit 0 position. */
#define CTE_INT1GAIN1_bm  (1<<5)  /* Integrator 1 Gain bit 1 mask. */
#define CTE_INT1GAIN1_bp  5  /* Integrator 1 Gain bit 1 position. */
#define CTE_INT1GAIN2_bm  (1<<6)  /* Integrator 1 Gain bit 2 mask. */
#define CTE_INT1GAIN2_bp  6  /* Integrator 1 Gain bit 2 position. */
#define CTE_INT1GAIN3_bm  (1<<7)  /* Integrator 1 Gain bit 3 mask. */
#define CTE_INT1GAIN3_bp  7  /* Integrator 1 Gain bit 3 position. */

/* CTE.INTGAIN1  bit masks and bit positions */
#define CTE_INT4GAIN_gm  0x0F  /* Integrator 4 Gain group mask. */
#define CTE_INT4GAIN_gp  0  /* Integrator 4 Gain group position. */
#define CTE_INT4GAIN0_bm  (1<<0)  /* Integrator 4 Gain bit 0 mask. */
#define CTE_INT4GAIN0_bp  0  /* Integrator 4 Gain bit 0 position. */
#define CTE_INT4GAIN1_bm  (1<<1)  /* Integrator 4 Gain bit 1 mask. */
#define CTE_INT4GAIN1_bp  1  /* Integrator 4 Gain bit 1 position. */
#define CTE_INT4GAIN2_bm  (1<<2)  /* Integrator 4 Gain bit 2 mask. */
#define CTE_INT4GAIN2_bp  2  /* Integrator 4 Gain bit 2 position. */
#define CTE_INT4GAIN3_bm  (1<<3)  /* Integrator 4 Gain bit 3 mask. */
#define CTE_INT4GAIN3_bp  3  /* Integrator 4 Gain bit 3 position. */
#define CTE_INT5GAIN_gm  0xF0  /* Integrator 5 Gain group mask. */
#define CTE_INT5GAIN_gp  4  /* Integrator 5 Gain group position. */
#define CTE_INT5GAIN0_bm  (1<<4)  /* Integrator 5 Gain bit 0 mask. */
#define CTE_INT5GAIN0_bp  4  /* Integrator 5 Gain bit 0 position. */
#define CTE_INT5GAIN1_bm  (1<<5)  /* Integrator 5 Gain bit 1 mask. */
#define CTE_INT5GAIN1_bp  5  /* Integrator 5 Gain bit 1 position. */
#define CTE_INT5GAIN2_bm  (1<<6)  /* Integrator 5 Gain bit 2 mask. */
#define CTE_INT5GAIN2_bp  6  /* Integrator 5 Gain bit 2 position. */
#define CTE_INT5GAIN3_bm  (1<<7)  /* Integrator 5 Gain bit 3 mask. */
#define CTE_INT5GAIN3_bp  7  /* Integrator 5 Gain bit 3 position. */

/* CTE.INTGAIN2  bit masks and bit positions */
#define CTE_INT8GAIN_gm  0x0F  /* Integrator 8 Gain group mask. */
#define CTE_INT8GAIN_gp  0  /* Integrator 8 Gain group position. */
#define CTE_INT8GAIN0_bm  (1<<0)  /* Integrator 8 Gain bit 0 mask. */
#define CTE_INT8GAIN0_bp  0  /* Integrator 8 Gain bit 0 position. */
#define CTE_INT8GAIN1_bm  (1<<1)  /* Integrator 8 Gain bit 1 mask. */
#define CTE_INT8GAIN1_bp  1  /* Integrator 8 Gain bit 1 position. */
#define CTE_INT8GAIN2_bm  (1<<2)  /* Integrator 8 Gain bit 2 mask. */
#define CTE_INT8GAIN2_bp  2  /* Integrator 8 Gain bit 2 position. */
#define CTE_INT8GAIN3_bm  (1<<3)  /* Integrator 8 Gain bit 3 mask. */
#define CTE_INT8GAIN3_bp  3  /* Integrator 8 Gain bit 3 position. */
#define CTE_INT9GAIN_gm  0xF0  /* Integrator 9 Gain group mask. */
#define CTE_INT9GAIN_gp  4  /* Integrator 9 Gain group position. */
#define CTE_INT9GAIN0_bm  (1<<4)  /* Integrator 9 Gain bit 0 mask. */
#define CTE_INT9GAIN0_bp  4  /* Integrator 9 Gain bit 0 position. */
#define CTE_INT9GAIN1_bm  (1<<5)  /* Integrator 9 Gain bit 1 mask. */
#define CTE_INT9GAIN1_bp  5  /* Integrator 9 Gain bit 1 position. */
#define CTE_INT9GAIN2_bm  (1<<6)  /* Integrator 9 Gain bit 2 mask. */
#define CTE_INT9GAIN2_bp  6  /* Integrator 9 Gain bit 2 position. */
#define CTE_INT9GAIN3_bm  (1<<7)  /* Integrator 9 Gain bit 3 mask. */
#define CTE_INT9GAIN3_bp  7  /* Integrator 9 Gain bit 3 position. */

/* CTE.INTGAIN3  bit masks and bit positions */
#define CTE_INT12GAIN_gm  0x0F  /* Integrator 12 Gain group mask. */
#define CTE_INT12GAIN_gp  0  /* Integrator 12 Gain group position. */
#define CTE_INT12GAIN0_bm  (1<<0)  /* Integrator 12 Gain bit 0 mask. */
#define CTE_INT12GAIN0_bp  0  /* Integrator 12 Gain bit 0 position. */
#define CTE_INT12GAIN1_bm  (1<<1)  /* Integrator 12 Gain bit 1 mask. */
#define CTE_INT12GAIN1_bp  1  /* Integrator 12 Gain bit 1 position. */
#define CTE_INT12GAIN2_bm  (1<<2)  /* Integrator 12 Gain bit 2 mask. */
#define CTE_INT12GAIN2_bp  2  /* Integrator 12 Gain bit 2 position. */
#define CTE_INT12GAIN3_bm  (1<<3)  /* Integrator 12 Gain bit 3 mask. */
#define CTE_INT12GAIN3_bp  3  /* Integrator 12 Gain bit 3 position. */
#define CTE_INT13GAIN_gm  0xF0  /* Integrator 13 Gain group mask. */
#define CTE_INT13GAIN_gp  4  /* Integrator 13 Gain group position. */
#define CTE_INT13GAIN0_bm  (1<<4)  /* Integrator 13 Gain bit 0 mask. */
#define CTE_INT13GAIN0_bp  4  /* Integrator 13 Gain bit 0 position. */
#define CTE_INT13GAIN1_bm  (1<<5)  /* Integrator 13 Gain bit 1 mask. */
#define CTE_INT13GAIN1_bp  5  /* Integrator 13 Gain bit 1 position. */
#define CTE_INT13GAIN2_bm  (1<<6)  /* Integrator 13 Gain bit 2 mask. */
#define CTE_INT13GAIN2_bp  6  /* Integrator 13 Gain bit 2 position. */
#define CTE_INT13GAIN3_bm  (1<<7)  /* Integrator 13 Gain bit 3 mask. */
#define CTE_INT13GAIN3_bp  7  /* Integrator 13 Gain bit 3 position. */

/* CTE.GCAFSRA  bit masks and bit positions */
#define CTE_GCAFCCC_gm  0x7F  /* GCAF Computation Complete Counter group mask. */
#define CTE_GCAFCCC_gp  0  /* GCAF Computation Complete Counter group position. */
#define CTE_GCAFCCC0_bm  (1<<0)  /* GCAF Computation Complete Counter bit 0 mask. */
#define CTE_GCAFCCC0_bp  0  /* GCAF Computation Complete Counter bit 0 position. */
#define CTE_GCAFCCC1_bm  (1<<1)  /* GCAF Computation Complete Counter bit 1 mask. */
#define CTE_GCAFCCC1_bp  1  /* GCAF Computation Complete Counter bit 1 position. */
#define CTE_GCAFCCC2_bm  (1<<2)  /* GCAF Computation Complete Counter bit 2 mask. */
#define CTE_GCAFCCC2_bp  2  /* GCAF Computation Complete Counter bit 2 position. */
#define CTE_GCAFCCC3_bm  (1<<3)  /* GCAF Computation Complete Counter bit 3 mask. */
#define CTE_GCAFCCC3_bp  3  /* GCAF Computation Complete Counter bit 3 position. */
#define CTE_GCAFCCC4_bm  (1<<4)  /* GCAF Computation Complete Counter bit 4 mask. */
#define CTE_GCAFCCC4_bp  4  /* GCAF Computation Complete Counter bit 4 position. */
#define CTE_GCAFCCC5_bm  (1<<5)  /* GCAF Computation Complete Counter bit 5 mask. */
#define CTE_GCAFCCC5_bp  5  /* GCAF Computation Complete Counter bit 5 position. */
#define CTE_GCAFCCC6_bm  (1<<6)  /* GCAF Computation Complete Counter bit 6 mask. */
#define CTE_GCAFCCC6_bp  6  /* GCAF Computation Complete Counter bit 6 position. */
#define CTE_GCAFCCCM_bm  0x80  /* GCAF Computation Complete Counter Mode bit mask. */
#define CTE_GCAFCCCM_bp  7  /* GCAF Computation Complete Counter Mode bit position. */

/* CTE.GCAFHDLCNT  bit masks and bit positions */
#define CTE_GCAFHDLCNT_gm  0xFF  /* Headroom Detect Low Counter group mask. */
#define CTE_GCAFHDLCNT_gp  0  /* Headroom Detect Low Counter group position. */
#define CTE_GCAFHDLCNT0_bm  (1<<0)  /* Headroom Detect Low Counter bit 0 mask. */
#define CTE_GCAFHDLCNT0_bp  0  /* Headroom Detect Low Counter bit 0 position. */
#define CTE_GCAFHDLCNT1_bm  (1<<1)  /* Headroom Detect Low Counter bit 1 mask. */
#define CTE_GCAFHDLCNT1_bp  1  /* Headroom Detect Low Counter bit 1 position. */
#define CTE_GCAFHDLCNT2_bm  (1<<2)  /* Headroom Detect Low Counter bit 2 mask. */
#define CTE_GCAFHDLCNT2_bp  2  /* Headroom Detect Low Counter bit 2 position. */
#define CTE_GCAFHDLCNT3_bm  (1<<3)  /* Headroom Detect Low Counter bit 3 mask. */
#define CTE_GCAFHDLCNT3_bp  3  /* Headroom Detect Low Counter bit 3 position. */
#define CTE_GCAFHDLCNT4_bm  (1<<4)  /* Headroom Detect Low Counter bit 4 mask. */
#define CTE_GCAFHDLCNT4_bp  4  /* Headroom Detect Low Counter bit 4 position. */
#define CTE_GCAFHDLCNT5_bm  (1<<5)  /* Headroom Detect Low Counter bit 5 mask. */
#define CTE_GCAFHDLCNT5_bp  5  /* Headroom Detect Low Counter bit 5 position. */
#define CTE_GCAFHDLCNT6_bm  (1<<6)  /* Headroom Detect Low Counter bit 6 mask. */
#define CTE_GCAFHDLCNT6_bp  6  /* Headroom Detect Low Counter bit 6 position. */
#define CTE_GCAFHDLCNT7_bm  (1<<7)  /* Headroom Detect Low Counter bit 7 mask. */
#define CTE_GCAFHDLCNT7_bp  7  /* Headroom Detect Low Counter bit 7 position. */

/* CTE.GCAFHDHCNT  bit masks and bit positions */
#define CTE_GCAFHDHCNT_gm  0xFF  /* Headroom Detect High Counter group mask. */
#define CTE_GCAFHDHCNT_gp  0  /* Headroom Detect High Counter group position. */
#define CTE_GCAFHDHCNT0_bm  (1<<0)  /* Headroom Detect High Counter bit 0 mask. */
#define CTE_GCAFHDHCNT0_bp  0  /* Headroom Detect High Counter bit 0 position. */
#define CTE_GCAFHDHCNT1_bm  (1<<1)  /* Headroom Detect High Counter bit 1 mask. */
#define CTE_GCAFHDHCNT1_bp  1  /* Headroom Detect High Counter bit 1 position. */
#define CTE_GCAFHDHCNT2_bm  (1<<2)  /* Headroom Detect High Counter bit 2 mask. */
#define CTE_GCAFHDHCNT2_bp  2  /* Headroom Detect High Counter bit 2 position. */
#define CTE_GCAFHDHCNT3_bm  (1<<3)  /* Headroom Detect High Counter bit 3 mask. */
#define CTE_GCAFHDHCNT3_bp  3  /* Headroom Detect High Counter bit 3 position. */
#define CTE_GCAFHDHCNT4_bm  (1<<4)  /* Headroom Detect High Counter bit 4 mask. */
#define CTE_GCAFHDHCNT4_bp  4  /* Headroom Detect High Counter bit 4 position. */
#define CTE_GCAFHDHCNT5_bm  (1<<5)  /* Headroom Detect High Counter bit 5 mask. */
#define CTE_GCAFHDHCNT5_bp  5  /* Headroom Detect High Counter bit 5 position. */
#define CTE_GCAFHDHCNT6_bm  (1<<6)  /* Headroom Detect High Counter bit 6 mask. */
#define CTE_GCAFHDHCNT6_bp  6  /* Headroom Detect High Counter bit 6 position. */
#define CTE_GCAFHDHCNT7_bm  (1<<7)  /* Headroom Detect High Counter bit 7 mask. */
#define CTE_GCAFHDHCNT7_bp  7  /* Headroom Detect High Counter bit 7 position. */

/* CTE.GCAFMCEN  bit masks and bit positions */
#define CTE_GCAFMCEN_7_0_gm  0xFF  /* GCAF Multi-Cut Enable group mask. */
#define CTE_GCAFMCEN_7_0_gp  0  /* GCAF Multi-Cut Enable group position. */
#define CTE_GCAFMCEN_7_00_bm  (1<<0)  /* GCAF Multi-Cut Enable bit 0 mask. */
#define CTE_GCAFMCEN_7_00_bp  0  /* GCAF Multi-Cut Enable bit 0 position. */
#define CTE_GCAFMCEN_7_01_bm  (1<<1)  /* GCAF Multi-Cut Enable bit 1 mask. */
#define CTE_GCAFMCEN_7_01_bp  1  /* GCAF Multi-Cut Enable bit 1 position. */
#define CTE_GCAFMCEN_7_02_bm  (1<<2)  /* GCAF Multi-Cut Enable bit 2 mask. */
#define CTE_GCAFMCEN_7_02_bp  2  /* GCAF Multi-Cut Enable bit 2 position. */
#define CTE_GCAFMCEN_7_03_bm  (1<<3)  /* GCAF Multi-Cut Enable bit 3 mask. */
#define CTE_GCAFMCEN_7_03_bp  3  /* GCAF Multi-Cut Enable bit 3 position. */
#define CTE_GCAFMCEN_7_04_bm  (1<<4)  /* GCAF Multi-Cut Enable bit 4 mask. */
#define CTE_GCAFMCEN_7_04_bp  4  /* GCAF Multi-Cut Enable bit 4 position. */
#define CTE_GCAFMCEN_7_05_bm  (1<<5)  /* GCAF Multi-Cut Enable bit 5 mask. */
#define CTE_GCAFMCEN_7_05_bp  5  /* GCAF Multi-Cut Enable bit 5 position. */
#define CTE_GCAFMCEN_7_06_bm  (1<<6)  /* GCAF Multi-Cut Enable bit 6 mask. */
#define CTE_GCAFMCEN_7_06_bp  6  /* GCAF Multi-Cut Enable bit 6 position. */
#define CTE_GCAFMCEN_7_07_bm  (1<<7)  /* GCAF Multi-Cut Enable bit 7 mask. */
#define CTE_GCAFMCEN_7_07_bp  7  /* GCAF Multi-Cut Enable bit 7 position. */

/* CTE.GCAFCCCLIM  bit masks and bit positions */
#define CTE_GCAFCCCLIM_gm  0x7F  /* GCAF Computation Complete Counter Limit group mask. */
#define CTE_GCAFCCCLIM_gp  0  /* GCAF Computation Complete Counter Limit group position. */
#define CTE_GCAFCCCLIM0_bm  (1<<0)  /* GCAF Computation Complete Counter Limit bit 0 mask. */
#define CTE_GCAFCCCLIM0_bp  0  /* GCAF Computation Complete Counter Limit bit 0 position. */
#define CTE_GCAFCCCLIM1_bm  (1<<1)  /* GCAF Computation Complete Counter Limit bit 1 mask. */
#define CTE_GCAFCCCLIM1_bp  1  /* GCAF Computation Complete Counter Limit bit 1 position. */
#define CTE_GCAFCCCLIM2_bm  (1<<2)  /* GCAF Computation Complete Counter Limit bit 2 mask. */
#define CTE_GCAFCCCLIM2_bp  2  /* GCAF Computation Complete Counter Limit bit 2 position. */
#define CTE_GCAFCCCLIM3_bm  (1<<3)  /* GCAF Computation Complete Counter Limit bit 3 mask. */
#define CTE_GCAFCCCLIM3_bp  3  /* GCAF Computation Complete Counter Limit bit 3 position. */
#define CTE_GCAFCCCLIM4_bm  (1<<4)  /* GCAF Computation Complete Counter Limit bit 4 mask. */
#define CTE_GCAFCCCLIM4_bp  4  /* GCAF Computation Complete Counter Limit bit 4 position. */
#define CTE_GCAFCCCLIM5_bm  (1<<5)  /* GCAF Computation Complete Counter Limit bit 5 mask. */
#define CTE_GCAFCCCLIM5_bp  5  /* GCAF Computation Complete Counter Limit bit 5 position. */
#define CTE_GCAFCCCLIM6_bm  (1<<6)  /* GCAF Computation Complete Counter Limit bit 6 mask. */
#define CTE_GCAFCCCLIM6_bp  6  /* GCAF Computation Complete Counter Limit bit 6 position. */

















/* CTE.ADCCRA  bit masks and bit positions */
#define CTE_ADCPRESC_gm  0x1F  /* ADC Prescaler group mask. */
#define CTE_ADCPRESC_gp  0  /* ADC Prescaler group position. */
#define CTE_ADCPRESC0_bm  (1<<0)  /* ADC Prescaler bit 0 mask. */
#define CTE_ADCPRESC0_bp  0  /* ADC Prescaler bit 0 position. */
#define CTE_ADCPRESC1_bm  (1<<1)  /* ADC Prescaler bit 1 mask. */
#define CTE_ADCPRESC1_bp  1  /* ADC Prescaler bit 1 position. */
#define CTE_ADCPRESC2_bm  (1<<2)  /* ADC Prescaler bit 2 mask. */
#define CTE_ADCPRESC2_bp  2  /* ADC Prescaler bit 2 position. */
#define CTE_ADCPRESC3_bm  (1<<3)  /* ADC Prescaler bit 3 mask. */
#define CTE_ADCPRESC3_bp  3  /* ADC Prescaler bit 3 position. */
#define CTE_ADCPRESC4_bm  (1<<4)  /* ADC Prescaler bit 4 mask. */
#define CTE_ADCPRESC4_bp  4  /* ADC Prescaler bit 4 position. */
#define CTE_ADCAPS_bm  0x20  /* ADC Auto Power Save bit mask. */
#define CTE_ADCAPS_bp  5  /* ADC Auto Power Save bit position. */
#define CTE_ADCREFSEL_gm  0xC0  /* ADC Reference Select group mask. */
#define CTE_ADCREFSEL_gp  6  /* ADC Reference Select group position. */
#define CTE_ADCREFSEL0_bm  (1<<6)  /* ADC Reference Select bit 0 mask. */
#define CTE_ADCREFSEL0_bp  6  /* ADC Reference Select bit 0 position. */
#define CTE_ADCREFSEL1_bm  (1<<7)  /* ADC Reference Select bit 1 mask. */
#define CTE_ADCREFSEL1_bp  7  /* ADC Reference Select bit 1 position. */

/* CTE.ADCCRB  bit masks and bit positions */
#define CTE_ADCSPEED_gm  0x03  /* ADC Speed Setting group mask. */
#define CTE_ADCSPEED_gp  0  /* ADC Speed Setting group position. */
#define CTE_ADCSPEED0_bm  (1<<0)  /* ADC Speed Setting bit 0 mask. */
#define CTE_ADCSPEED0_bp  0  /* ADC Speed Setting bit 0 position. */
#define CTE_ADCSPEED1_bm  (1<<1)  /* ADC Speed Setting bit 1 mask. */
#define CTE_ADCSPEED1_bp  1  /* ADC Speed Setting bit 1 position. */
#define CTE_ADCPUEN_bm  0x04  /* ADC Pull Enable bit mask. */
#define CTE_ADCPUEN_bp  2  /* ADC Pull Enable bit position. */
#define CTE_SHSPEED_gm  0x18  /* S/H Speed Setting group mask. */
#define CTE_SHSPEED_gp  3  /* S/H Speed Setting group position. */
#define CTE_SHSPEED0_bm  (1<<3)  /* S/H Speed Setting bit 0 mask. */
#define CTE_SHSPEED0_bp  3  /* S/H Speed Setting bit 0 position. */
#define CTE_SHSPEED1_bm  (1<<4)  /* S/H Speed Setting bit 1 mask. */
#define CTE_SHSPEED1_bp  4  /* S/H Speed Setting bit 1 position. */
#define CTE_SHDCS_bm  0x40  /* S/H Dynamic Current Scaling bit mask. */
#define CTE_SHDCS_bp  6  /* S/H Dynamic Current Scaling bit position. */
#define CTE_ADCSUM_bm  0x80  /* ADC Startup Mode bit mask. */
#define CTE_ADCSUM_bp  7  /* ADC Startup Mode bit position. */

/* CTE.ADCINTCAL  bit masks and bit positions */
#define CTE_ADCCAL_gm  0xFF  /* ADC Calibration group mask. */
#define CTE_ADCCAL_gp  0  /* ADC Calibration group position. */
#define CTE_ADCCAL0_bm  (1<<0)  /* ADC Calibration bit 0 mask. */
#define CTE_ADCCAL0_bp  0  /* ADC Calibration bit 0 position. */
#define CTE_ADCCAL1_bm  (1<<1)  /* ADC Calibration bit 1 mask. */
#define CTE_ADCCAL1_bp  1  /* ADC Calibration bit 1 position. */
#define CTE_ADCCAL2_bm  (1<<2)  /* ADC Calibration bit 2 mask. */
#define CTE_ADCCAL2_bp  2  /* ADC Calibration bit 2 position. */
#define CTE_ADCCAL3_bm  (1<<3)  /* ADC Calibration bit 3 mask. */
#define CTE_ADCCAL3_bp  3  /* ADC Calibration bit 3 position. */
#define CTE_ADCCAL4_bm  (1<<4)  /* ADC Calibration bit 4 mask. */
#define CTE_ADCCAL4_bp  4  /* ADC Calibration bit 4 position. */
#define CTE_ADCCAL5_bm  (1<<5)  /* ADC Calibration bit 5 mask. */
#define CTE_ADCCAL5_bp  5  /* ADC Calibration bit 5 position. */
#define CTE_ADCCAL6_bm  (1<<6)  /* ADC Calibration bit 6 mask. */
#define CTE_ADCCAL6_bp  6  /* ADC Calibration bit 6 position. */
#define CTE_ADCCAL7_bm  (1<<7)  /* ADC Calibration bit 7 mask. */
#define CTE_ADCCAL7_bp  7  /* ADC Calibration bit 7 position. */

/* CTE.ADCRES  bit masks and bit positions */
#define CTE_ADCRES_7_0_gm  0xFF  /* ADC Conversion Result bit 7-0 group mask. */
#define CTE_ADCRES_7_0_gp  0  /* ADC Conversion Result bit 7-0 group position. */
#define CTE_ADCRES_7_00_bm  (1<<0)  /* ADC Conversion Result bit 7-0 bit 0 mask. */
#define CTE_ADCRES_7_00_bp  0  /* ADC Conversion Result bit 7-0 bit 0 position. */
#define CTE_ADCRES_7_01_bm  (1<<1)  /* ADC Conversion Result bit 7-0 bit 1 mask. */
#define CTE_ADCRES_7_01_bp  1  /* ADC Conversion Result bit 7-0 bit 1 position. */
#define CTE_ADCRES_7_02_bm  (1<<2)  /* ADC Conversion Result bit 7-0 bit 2 mask. */
#define CTE_ADCRES_7_02_bp  2  /* ADC Conversion Result bit 7-0 bit 2 position. */
#define CTE_ADCRES_7_03_bm  (1<<3)  /* ADC Conversion Result bit 7-0 bit 3 mask. */
#define CTE_ADCRES_7_03_bp  3  /* ADC Conversion Result bit 7-0 bit 3 position. */
#define CTE_ADCRES_7_04_bm  (1<<4)  /* ADC Conversion Result bit 7-0 bit 4 mask. */
#define CTE_ADCRES_7_04_bp  4  /* ADC Conversion Result bit 7-0 bit 4 position. */
#define CTE_ADCRES_7_05_bm  (1<<5)  /* ADC Conversion Result bit 7-0 bit 5 mask. */
#define CTE_ADCRES_7_05_bp  5  /* ADC Conversion Result bit 7-0 bit 5 position. */
#define CTE_ADCRES_7_06_bm  (1<<6)  /* ADC Conversion Result bit 7-0 bit 6 mask. */
#define CTE_ADCRES_7_06_bp  6  /* ADC Conversion Result bit 7-0 bit 6 position. */
#define CTE_ADCRES_7_07_bm  (1<<7)  /* ADC Conversion Result bit 7-0 bit 7 mask. */
#define CTE_ADCRES_7_07_bp  7  /* ADC Conversion Result bit 7-0 bit 7 position. */

/* CTE.ADCINTTEST  bit masks and bit positions */
#define CTE_ADCTSPEN_bm  0x01  /* ADC Test Switch Positive Enable bit mask. */
#define CTE_ADCTSPEN_bp  0  /* ADC Test Switch Positive Enable bit position. */
#define CTE_ADCTSNEN_bm  0x02  /* ADC Test Switch Negative Enable bit mask. */
#define CTE_ADCTSNEN_bp  1  /* ADC Test Switch Negative Enable bit position. */
#define CTE_ADCBTESTEN_bm  0x04  /* ADC Bias Test Enable bit mask. */
#define CTE_ADCBTESTEN_bp  2  /* ADC Bias Test Enable bit position. */
#define CTE_ADCFV_bm  0x08  /* ADC Force Valid Result bit mask. */
#define CTE_ADCFV_bp  3  /* ADC Force Valid Result bit position. */
#define CTE_INTBIST_bm  0x10  /* Integrator Built-In Self Test bit mask. */
#define CTE_INTBIST_bp  4  /* Integrator Built-In Self Test bit position. */
#define CTE_INTTESTALL_bm  0x20  /* Integrator Test All bit mask. */
#define CTE_INTTESTALL_bp  5  /* Integrator Test All bit position. */

/* CTE.ADCSHVBCAL  bit masks and bit positions */
#define CTE_ADCVBCAL_gm  0x0F  /* ADC VBias Calibration group mask. */
#define CTE_ADCVBCAL_gp  0  /* ADC VBias Calibration group position. */
#define CTE_ADCVBCAL0_bm  (1<<0)  /* ADC VBias Calibration bit 0 mask. */
#define CTE_ADCVBCAL0_bp  0  /* ADC VBias Calibration bit 0 position. */
#define CTE_ADCVBCAL1_bm  (1<<1)  /* ADC VBias Calibration bit 1 mask. */
#define CTE_ADCVBCAL1_bp  1  /* ADC VBias Calibration bit 1 position. */
#define CTE_ADCVBCAL2_bm  (1<<2)  /* ADC VBias Calibration bit 2 mask. */
#define CTE_ADCVBCAL2_bp  2  /* ADC VBias Calibration bit 2 position. */
#define CTE_ADCVBCAL3_bm  (1<<3)  /* ADC VBias Calibration bit 3 mask. */
#define CTE_ADCVBCAL3_bp  3  /* ADC VBias Calibration bit 3 position. */
#define CTE_ADCVBSEL_bm  0x10  /* ADC VBias Select bit mask. */
#define CTE_ADCVBSEL_bp  4  /* ADC VBias Select bit position. */
#define CTE_SHVBCAL_gm  0xE0  /* S/H VBias Calibration group mask. */
#define CTE_SHVBCAL_gp  5  /* S/H VBias Calibration group position. */
#define CTE_SHVBCAL0_bm  (1<<5)  /* S/H VBias Calibration bit 0 mask. */
#define CTE_SHVBCAL0_bp  5  /* S/H VBias Calibration bit 0 position. */
#define CTE_SHVBCAL1_bm  (1<<6)  /* S/H VBias Calibration bit 1 mask. */
#define CTE_SHVBCAL1_bp  6  /* S/H VBias Calibration bit 1 position. */
#define CTE_SHVBCAL2_bm  (1<<7)  /* S/H VBias Calibration bit 2 mask. */
#define CTE_SHVBCAL2_bp  7  /* S/H VBias Calibration bit 2 position. */

/* CTE.INTCRA  bit masks and bit positions */
#define CTE_INTMEN_bm  0x01  /* Integrator Master Enable bit mask. */
#define CTE_INTMEN_bp  0  /* Integrator Master Enable bit position. */
#define CTE_INTARST_bm  0x02  /* Integrator Automatic Reset bit mask. */
#define CTE_INTARST_bp  1  /* Integrator Automatic Reset bit position. */
#define CTE_INTAST_bm  0x04  /* Integrator Automatic Sign Toggle bit mask. */
#define CTE_INTAST_bp  2  /* Integrator Automatic Sign Toggle bit position. */
#define CTE_INTINCBIAS_bm  0x40  /* Integrator Increase Bias bit mask. */
#define CTE_INTINCBIAS_bp  6  /* Integrator Increase Bias bit position. */
#define CTE_INTXCHINC_bm  0x80  /* Integrator X-Channel Increment bit mask. */
#define CTE_INTXCHINC_bp  7  /* Integrator X-Channel Increment bit position. */

/* CTE.INTCRD  bit masks and bit positions */
/* CTE_INTYONX  is already defined. */
/* CTE_INTBYPASSX  is already defined. */
/* CTE_INTBYPASSY  is already defined. */
/* CTE_INTDIBUFX  is already defined. */
#define CTE_BIASY30U_bm  0x20  /* Y-line Bias Nominal Value30uA bit mask. */
#define CTE_BIASY30U_bp  5  /* Y-line Bias Nominal Value30uA bit position. */
#define CTE_INTY0TIEN_bm  0x40  /* Integrator Y0 Test Input Enable bit mask. */
#define CTE_INTY0TIEN_bp  6  /* Integrator Y0 Test Input Enable bit position. */
#define CTE_INTY1TIEN_bm  0x80  /* Integrator Y1 Test Input Enable bit mask. */
#define CTE_INTY1TIEN_bp  7  /* Integrator Y1 Test Input Enable bit position. */

/* CTE.INTEN  bit masks and bit positions */
#define CTE_INTEN_7_0_gm  0xFF  /* Integrator Enable group mask. */
#define CTE_INTEN_7_0_gp  0  /* Integrator Enable group position. */
#define CTE_INTEN_7_00_bm  (1<<0)  /* Integrator Enable bit 0 mask. */
#define CTE_INTEN_7_00_bp  0  /* Integrator Enable bit 0 position. */
#define CTE_INTEN_7_01_bm  (1<<1)  /* Integrator Enable bit 1 mask. */
#define CTE_INTEN_7_01_bp  1  /* Integrator Enable bit 1 position. */
#define CTE_INTEN_7_02_bm  (1<<2)  /* Integrator Enable bit 2 mask. */
#define CTE_INTEN_7_02_bp  2  /* Integrator Enable bit 2 position. */
#define CTE_INTEN_7_03_bm  (1<<3)  /* Integrator Enable bit 3 mask. */
#define CTE_INTEN_7_03_bp  3  /* Integrator Enable bit 3 position. */
#define CTE_INTEN_7_04_bm  (1<<4)  /* Integrator Enable bit 4 mask. */
#define CTE_INTEN_7_04_bp  4  /* Integrator Enable bit 4 position. */
#define CTE_INTEN_7_05_bm  (1<<5)  /* Integrator Enable bit 5 mask. */
#define CTE_INTEN_7_05_bp  5  /* Integrator Enable bit 5 position. */
#define CTE_INTEN_7_06_bm  (1<<6)  /* Integrator Enable bit 6 mask. */
#define CTE_INTEN_7_06_bp  6  /* Integrator Enable bit 6 position. */
#define CTE_INTEN_7_07_bm  (1<<7)  /* Integrator Enable bit 7 mask. */
#define CTE_INTEN_7_07_bp  7  /* Integrator Enable bit 7 position. */

/* CTE.INTMASKEN  bit masks and bit positions */
#define CTE_INTMASKEN_7_0_gm  0xFF  /* Integrator Mask Enable group mask. */
#define CTE_INTMASKEN_7_0_gp  0  /* Integrator Mask Enable group position. */
#define CTE_INTMASKEN_7_00_bm  (1<<0)  /* Integrator Mask Enable bit 0 mask. */
#define CTE_INTMASKEN_7_00_bp  0  /* Integrator Mask Enable bit 0 position. */
#define CTE_INTMASKEN_7_01_bm  (1<<1)  /* Integrator Mask Enable bit 1 mask. */
#define CTE_INTMASKEN_7_01_bp  1  /* Integrator Mask Enable bit 1 position. */
#define CTE_INTMASKEN_7_02_bm  (1<<2)  /* Integrator Mask Enable bit 2 mask. */
#define CTE_INTMASKEN_7_02_bp  2  /* Integrator Mask Enable bit 2 position. */
#define CTE_INTMASKEN_7_03_bm  (1<<3)  /* Integrator Mask Enable bit 3 mask. */
#define CTE_INTMASKEN_7_03_bp  3  /* Integrator Mask Enable bit 3 position. */
#define CTE_INTMASKEN_7_04_bm  (1<<4)  /* Integrator Mask Enable bit 4 mask. */
#define CTE_INTMASKEN_7_04_bp  4  /* Integrator Mask Enable bit 4 position. */
#define CTE_INTMASKEN_7_05_bm  (1<<5)  /* Integrator Mask Enable bit 5 mask. */
#define CTE_INTMASKEN_7_05_bp  5  /* Integrator Mask Enable bit 5 position. */
#define CTE_INTMASKEN_7_06_bm  (1<<6)  /* Integrator Mask Enable bit 6 mask. */
#define CTE_INTMASKEN_7_06_bp  6  /* Integrator Mask Enable bit 6 position. */
#define CTE_INTMASKEN_7_07_bm  (1<<7)  /* Integrator Mask Enable bit 7 mask. */
#define CTE_INTMASKEN_7_07_bp  7  /* Integrator Mask Enable bit 7 position. */

/* CTE.SHEN  bit masks and bit positions */
#define CTE_SHEN_7_0_gm  0xFF  /* S/H Enable group mask. */
#define CTE_SHEN_7_0_gp  0  /* S/H Enable group position. */
#define CTE_SHEN_7_00_bm  (1<<0)  /* S/H Enable bit 0 mask. */
#define CTE_SHEN_7_00_bp  0  /* S/H Enable bit 0 position. */
#define CTE_SHEN_7_01_bm  (1<<1)  /* S/H Enable bit 1 mask. */
#define CTE_SHEN_7_01_bp  1  /* S/H Enable bit 1 position. */
#define CTE_SHEN_7_02_bm  (1<<2)  /* S/H Enable bit 2 mask. */
#define CTE_SHEN_7_02_bp  2  /* S/H Enable bit 2 position. */
#define CTE_SHEN_7_03_bm  (1<<3)  /* S/H Enable bit 3 mask. */
#define CTE_SHEN_7_03_bp  3  /* S/H Enable bit 3 position. */
#define CTE_SHEN_7_04_bm  (1<<4)  /* S/H Enable bit 4 mask. */
#define CTE_SHEN_7_04_bp  4  /* S/H Enable bit 4 position. */
#define CTE_SHEN_7_05_bm  (1<<5)  /* S/H Enable bit 5 mask. */
#define CTE_SHEN_7_05_bp  5  /* S/H Enable bit 5 position. */
#define CTE_SHEN_7_06_bm  (1<<6)  /* S/H Enable bit 6 mask. */
#define CTE_SHEN_7_06_bp  6  /* S/H Enable bit 6 position. */
#define CTE_SHEN_7_07_bm  (1<<7)  /* S/H Enable bit 7 mask. */
#define CTE_SHEN_7_07_bp  7  /* S/H Enable bit 7 position. */

/* CTE.BIASCR  bit masks and bit positions */
#define CTE_BIASXPVAL_gm  0x1F  /* X-line PMOS Bias Value group mask. */
#define CTE_BIASXPVAL_gp  0  /* X-line PMOS Bias Value group position. */
#define CTE_BIASXPVAL0_bm  (1<<0)  /* X-line PMOS Bias Value bit 0 mask. */
#define CTE_BIASXPVAL0_bp  0  /* X-line PMOS Bias Value bit 0 position. */
#define CTE_BIASXPVAL1_bm  (1<<1)  /* X-line PMOS Bias Value bit 1 mask. */
#define CTE_BIASXPVAL1_bp  1  /* X-line PMOS Bias Value bit 1 position. */
#define CTE_BIASXPVAL2_bm  (1<<2)  /* X-line PMOS Bias Value bit 2 mask. */
#define CTE_BIASXPVAL2_bp  2  /* X-line PMOS Bias Value bit 2 position. */
#define CTE_BIASXPVAL3_bm  (1<<3)  /* X-line PMOS Bias Value bit 3 mask. */
#define CTE_BIASXPVAL3_bp  3  /* X-line PMOS Bias Value bit 3 position. */
#define CTE_BIASXPVAL4_bm  (1<<4)  /* X-line PMOS Bias Value bit 4 mask. */
#define CTE_BIASXPVAL4_bp  4  /* X-line PMOS Bias Value bit 4 position. */
#define CTE_BIASXNVAL_2_0_gm  0xE0  /* X-line NMOS Bias Value bit 2-0 group mask. */
#define CTE_BIASXNVAL_2_0_gp  5  /* X-line NMOS Bias Value bit 2-0 group position. */
#define CTE_BIASXNVAL_2_00_bm  (1<<5)  /* X-line NMOS Bias Value bit 2-0 bit 0 mask. */
#define CTE_BIASXNVAL_2_00_bp  5  /* X-line NMOS Bias Value bit 2-0 bit 0 position. */
#define CTE_BIASXNVAL_2_01_bm  (1<<6)  /* X-line NMOS Bias Value bit 2-0 bit 1 mask. */
#define CTE_BIASXNVAL_2_01_bp  6  /* X-line NMOS Bias Value bit 2-0 bit 1 position. */
#define CTE_BIASXNVAL_2_02_bm  (1<<7)  /* X-line NMOS Bias Value bit 2-0 bit 2 mask. */
#define CTE_BIASXNVAL_2_02_bp  7  /* X-line NMOS Bias Value bit 2-0 bit 2 position. */

/* CTE.HVSEQT  bit masks and bit positions */
#define CTE_HVHOT_gm  0xFF  /* HV Sequencer Hold Off Time group mask. */
#define CTE_HVHOT_gp  0  /* HV Sequencer Hold Off Time group position. */
#define CTE_HVHOT0_bm  (1<<0)  /* HV Sequencer Hold Off Time bit 0 mask. */
#define CTE_HVHOT0_bp  0  /* HV Sequencer Hold Off Time bit 0 position. */
#define CTE_HVHOT1_bm  (1<<1)  /* HV Sequencer Hold Off Time bit 1 mask. */
#define CTE_HVHOT1_bp  1  /* HV Sequencer Hold Off Time bit 1 position. */
#define CTE_HVHOT2_bm  (1<<2)  /* HV Sequencer Hold Off Time bit 2 mask. */
#define CTE_HVHOT2_bp  2  /* HV Sequencer Hold Off Time bit 2 position. */
#define CTE_HVHOT3_bm  (1<<3)  /* HV Sequencer Hold Off Time bit 3 mask. */
#define CTE_HVHOT3_bp  3  /* HV Sequencer Hold Off Time bit 3 position. */
#define CTE_HVHOT4_bm  (1<<4)  /* HV Sequencer Hold Off Time bit 4 mask. */
#define CTE_HVHOT4_bp  4  /* HV Sequencer Hold Off Time bit 4 position. */
#define CTE_HVHOT5_bm  (1<<5)  /* HV Sequencer Hold Off Time bit 5 mask. */
#define CTE_HVHOT5_bp  5  /* HV Sequencer Hold Off Time bit 5 position. */
#define CTE_HVHOT6_bm  (1<<6)  /* HV Sequencer Hold Off Time bit 6 mask. */
#define CTE_HVHOT6_bp  6  /* HV Sequencer Hold Off Time bit 6 position. */
#define CTE_HVHOT7_bm  (1<<7)  /* HV Sequencer Hold Off Time bit 7 mask. */
#define CTE_HVHOT7_bp  7  /* HV Sequencer Hold Off Time bit 7 position. */

/* CTE.HDCRA  bit masks and bit positions */
#define CTE_HDHYST_bm  0x01  /* Headroom Detector Hysteresis bit mask. */
#define CTE_HDHYST_bp  0  /* Headroom Detector Hysteresis bit position. */
#define CTE_HDHBIAS_bm  0x02  /* Headroom Detector High Bias bit mask. */
#define CTE_HDHBIAS_bp  1  /* Headroom Detector High Bias bit position. */
#define CTE_HDLLVL_gm  0x1C  /* Headroom Detector Low Level Configuration group mask. */
#define CTE_HDLLVL_gp  2  /* Headroom Detector Low Level Configuration group position. */
#define CTE_HDLLVL0_bm  (1<<2)  /* Headroom Detector Low Level Configuration bit 0 mask. */
#define CTE_HDLLVL0_bp  2  /* Headroom Detector Low Level Configuration bit 0 position. */
#define CTE_HDLLVL1_bm  (1<<3)  /* Headroom Detector Low Level Configuration bit 1 mask. */
#define CTE_HDLLVL1_bp  3  /* Headroom Detector Low Level Configuration bit 1 position. */
#define CTE_HDLLVL2_bm  (1<<4)  /* Headroom Detector Low Level Configuration bit 2 mask. */
#define CTE_HDLLVL2_bp  4  /* Headroom Detector Low Level Configuration bit 2 position. */
#define CTE_HDHLVL_gm  0xE0  /* Headroom Detector High Level Configuration group mask. */
#define CTE_HDHLVL_gp  5  /* Headroom Detector High Level Configuration group position. */
#define CTE_HDHLVL0_bm  (1<<5)  /* Headroom Detector High Level Configuration bit 0 mask. */
#define CTE_HDHLVL0_bp  5  /* Headroom Detector High Level Configuration bit 0 position. */
#define CTE_HDHLVL1_bm  (1<<6)  /* Headroom Detector High Level Configuration bit 1 mask. */
#define CTE_HDHLVL1_bp  6  /* Headroom Detector High Level Configuration bit 1 position. */
#define CTE_HDHLVL2_bm  (1<<7)  /* Headroom Detector High Level Configuration bit 2 mask. */
#define CTE_HDHLVL2_bp  7  /* Headroom Detector High Level Configuration bit 2 position. */

/* CTE.HDEN  bit masks and bit positions */
#define CTE_HDEN_7_0_gm  0xFF  /* Headroom Detector Enable group mask. */
#define CTE_HDEN_7_0_gp  0  /* Headroom Detector Enable group position. */
#define CTE_HDEN_7_00_bm  (1<<0)  /* Headroom Detector Enable bit 0 mask. */
#define CTE_HDEN_7_00_bp  0  /* Headroom Detector Enable bit 0 position. */
#define CTE_HDEN_7_01_bm  (1<<1)  /* Headroom Detector Enable bit 1 mask. */
#define CTE_HDEN_7_01_bp  1  /* Headroom Detector Enable bit 1 position. */
#define CTE_HDEN_7_02_bm  (1<<2)  /* Headroom Detector Enable bit 2 mask. */
#define CTE_HDEN_7_02_bp  2  /* Headroom Detector Enable bit 2 position. */
#define CTE_HDEN_7_03_bm  (1<<3)  /* Headroom Detector Enable bit 3 mask. */
#define CTE_HDEN_7_03_bp  3  /* Headroom Detector Enable bit 3 position. */
#define CTE_HDEN_7_04_bm  (1<<4)  /* Headroom Detector Enable bit 4 mask. */
#define CTE_HDEN_7_04_bp  4  /* Headroom Detector Enable bit 4 position. */
#define CTE_HDEN_7_05_bm  (1<<5)  /* Headroom Detector Enable bit 5 mask. */
#define CTE_HDEN_7_05_bp  5  /* Headroom Detector Enable bit 5 position. */
#define CTE_HDEN_7_06_bm  (1<<6)  /* Headroom Detector Enable bit 6 mask. */
#define CTE_HDEN_7_06_bp  6  /* Headroom Detector Enable bit 6 position. */
#define CTE_HDEN_7_07_bm  (1<<7)  /* Headroom Detector Enable bit 7 mask. */
#define CTE_HDEN_7_07_bp  7  /* Headroom Detector Enable bit 7 position. */

/* CTE.HDLOW  bit masks and bit positions */
#define CTE_HDLOW_7_0_gm  0xFF  /* Headroom Detector Low Level Output group mask. */
#define CTE_HDLOW_7_0_gp  0  /* Headroom Detector Low Level Output group position. */
#define CTE_HDLOW_7_00_bm  (1<<0)  /* Headroom Detector Low Level Output bit 0 mask. */
#define CTE_HDLOW_7_00_bp  0  /* Headroom Detector Low Level Output bit 0 position. */
#define CTE_HDLOW_7_01_bm  (1<<1)  /* Headroom Detector Low Level Output bit 1 mask. */
#define CTE_HDLOW_7_01_bp  1  /* Headroom Detector Low Level Output bit 1 position. */
#define CTE_HDLOW_7_02_bm  (1<<2)  /* Headroom Detector Low Level Output bit 2 mask. */
#define CTE_HDLOW_7_02_bp  2  /* Headroom Detector Low Level Output bit 2 position. */
#define CTE_HDLOW_7_03_bm  (1<<3)  /* Headroom Detector Low Level Output bit 3 mask. */
#define CTE_HDLOW_7_03_bp  3  /* Headroom Detector Low Level Output bit 3 position. */
#define CTE_HDLOW_7_04_bm  (1<<4)  /* Headroom Detector Low Level Output bit 4 mask. */
#define CTE_HDLOW_7_04_bp  4  /* Headroom Detector Low Level Output bit 4 position. */
#define CTE_HDLOW_7_05_bm  (1<<5)  /* Headroom Detector Low Level Output bit 5 mask. */
#define CTE_HDLOW_7_05_bp  5  /* Headroom Detector Low Level Output bit 5 position. */
#define CTE_HDLOW_7_06_bm  (1<<6)  /* Headroom Detector Low Level Output bit 6 mask. */
#define CTE_HDLOW_7_06_bp  6  /* Headroom Detector Low Level Output bit 6 position. */
#define CTE_HDLOW_7_07_bm  (1<<7)  /* Headroom Detector Low Level Output bit 7 mask. */
#define CTE_HDLOW_7_07_bp  7  /* Headroom Detector Low Level Output bit 7 position. */

/* CTE.HDHIGH  bit masks and bit positions */
#define CTE_HDHIGH_7_0_gm  0xFF  /* Headroom Detector High Level Output group mask. */
#define CTE_HDHIGH_7_0_gp  0  /* Headroom Detector High Level Output group position. */
#define CTE_HDHIGH_7_00_bm  (1<<0)  /* Headroom Detector High Level Output bit 0 mask. */
#define CTE_HDHIGH_7_00_bp  0  /* Headroom Detector High Level Output bit 0 position. */
#define CTE_HDHIGH_7_01_bm  (1<<1)  /* Headroom Detector High Level Output bit 1 mask. */
#define CTE_HDHIGH_7_01_bp  1  /* Headroom Detector High Level Output bit 1 position. */
#define CTE_HDHIGH_7_02_bm  (1<<2)  /* Headroom Detector High Level Output bit 2 mask. */
#define CTE_HDHIGH_7_02_bp  2  /* Headroom Detector High Level Output bit 2 position. */
#define CTE_HDHIGH_7_03_bm  (1<<3)  /* Headroom Detector High Level Output bit 3 mask. */
#define CTE_HDHIGH_7_03_bp  3  /* Headroom Detector High Level Output bit 3 position. */
#define CTE_HDHIGH_7_04_bm  (1<<4)  /* Headroom Detector High Level Output bit 4 mask. */
#define CTE_HDHIGH_7_04_bp  4  /* Headroom Detector High Level Output bit 4 position. */
#define CTE_HDHIGH_7_05_bm  (1<<5)  /* Headroom Detector High Level Output bit 5 mask. */
#define CTE_HDHIGH_7_05_bp  5  /* Headroom Detector High Level Output bit 5 position. */
#define CTE_HDHIGH_7_06_bm  (1<<6)  /* Headroom Detector High Level Output bit 6 mask. */
#define CTE_HDHIGH_7_06_bp  6  /* Headroom Detector High Level Output bit 6 position. */
#define CTE_HDHIGH_7_07_bm  (1<<7)  /* Headroom Detector High Level Output bit 7 mask. */
#define CTE_HDHIGH_7_07_bp  7  /* Headroom Detector High Level Output bit 7 position. */

/* CTE.GCAFCRA  bit masks and bit positions */
#define CTE_GCAFEN_bm  0x01  /* GCAF Enable bit mask. */
#define CTE_GCAFEN_bp  0  /* GCAF Enable bit position. */
#define CTE_GCAFMEDM_gm  0x0E  /* GCAF Median Mode group mask. */
#define CTE_GCAFMEDM_gp  1  /* GCAF Median Mode group position. */
#define CTE_GCAFMEDM0_bm  (1<<1)  /* GCAF Median Mode bit 0 mask. */
#define CTE_GCAFMEDM0_bp  1  /* GCAF Median Mode bit 0 position. */
#define CTE_GCAFMEDM1_bm  (1<<2)  /* GCAF Median Mode bit 1 mask. */
#define CTE_GCAFMEDM1_bp  2  /* GCAF Median Mode bit 1 position. */
#define CTE_GCAFMEDM2_bm  (1<<3)  /* GCAF Median Mode bit 2 mask. */
#define CTE_GCAFMEDM2_bp  3  /* GCAF Median Mode bit 2 position. */
#define CTE_GCAFMCMEN_bm  0x10  /* GCAF Multi-Cut Master Enable bit mask. */
#define CTE_GCAFMCMEN_bp  4  /* GCAF Multi-Cut Master Enable bit position. */
#define CTE_GCAFPCEN_bm  0x20  /* GCAF Pre-Cut Enable bit mask. */
#define CTE_GCAFPCEN_bp  5  /* GCAF Pre-Cut Enable bit position. */
#define CTE_GCAFACCM_gm  0xC0  /* GCAF Accumulate Mode group mask. */
#define CTE_GCAFACCM_gp  6  /* GCAF Accumulate Mode group position. */
#define CTE_GCAFACCM0_bm  (1<<6)  /* GCAF Accumulate Mode bit 0 mask. */
#define CTE_GCAFACCM0_bp  6  /* GCAF Accumulate Mode bit 0 position. */
#define CTE_GCAFACCM1_bm  (1<<7)  /* GCAF Accumulate Mode bit 1 mask. */
#define CTE_GCAFACCM1_bp  7  /* GCAF Accumulate Mode bit 1 position. */

/* CTE.GCAFCRB  bit masks and bit positions */
#define CTE_GCAFYDIM_gm  0x1F  /* GCAF Result Table Y Dimension group mask. */
#define CTE_GCAFYDIM_gp  0  /* GCAF Result Table Y Dimension group position. */
#define CTE_GCAFYDIM0_bm  (1<<0)  /* GCAF Result Table Y Dimension bit 0 mask. */
#define CTE_GCAFYDIM0_bp  0  /* GCAF Result Table Y Dimension bit 0 position. */
#define CTE_GCAFYDIM1_bm  (1<<1)  /* GCAF Result Table Y Dimension bit 1 mask. */
#define CTE_GCAFYDIM1_bp  1  /* GCAF Result Table Y Dimension bit 1 position. */
#define CTE_GCAFYDIM2_bm  (1<<2)  /* GCAF Result Table Y Dimension bit 2 mask. */
#define CTE_GCAFYDIM2_bp  2  /* GCAF Result Table Y Dimension bit 2 position. */
#define CTE_GCAFYDIM3_bm  (1<<3)  /* GCAF Result Table Y Dimension bit 3 mask. */
#define CTE_GCAFYDIM3_bp  3  /* GCAF Result Table Y Dimension bit 3 position. */
#define CTE_GCAFYDIM4_bm  (1<<4)  /* GCAF Result Table Y Dimension bit 4 mask. */
#define CTE_GCAFYDIM4_bp  4  /* GCAF Result Table Y Dimension bit 4 position. */
#define CTE_GCAFAM_gm  0xE0  /* GCAF Addressing Mode group mask. */
#define CTE_GCAFAM_gp  5  /* GCAF Addressing Mode group position. */
#define CTE_GCAFAM0_bm  (1<<5)  /* GCAF Addressing Mode bit 0 mask. */
#define CTE_GCAFAM0_bp  5  /* GCAF Addressing Mode bit 0 position. */
#define CTE_GCAFAM1_bm  (1<<6)  /* GCAF Addressing Mode bit 1 mask. */
#define CTE_GCAFAM1_bp  6  /* GCAF Addressing Mode bit 1 position. */
#define CTE_GCAFAM2_bm  (1<<7)  /* GCAF Addressing Mode bit 2 mask. */
#define CTE_GCAFAM2_bp  7  /* GCAF Addressing Mode bit 2 position. */

/* CTE.GCAFBASELIM  bit masks and bit positions */
#define CTE_GCAFLIM_gm  0xFF  /* GCAF Grass Cut Limit group mask. */
#define CTE_GCAFLIM_gp  0  /* GCAF Grass Cut Limit group position. */
#define CTE_GCAFLIM0_bm  (1<<0)  /* GCAF Grass Cut Limit bit 0 mask. */
#define CTE_GCAFLIM0_bp  0  /* GCAF Grass Cut Limit bit 0 position. */
#define CTE_GCAFLIM1_bm  (1<<1)  /* GCAF Grass Cut Limit bit 1 mask. */
#define CTE_GCAFLIM1_bp  1  /* GCAF Grass Cut Limit bit 1 position. */
#define CTE_GCAFLIM2_bm  (1<<2)  /* GCAF Grass Cut Limit bit 2 mask. */
#define CTE_GCAFLIM2_bp  2  /* GCAF Grass Cut Limit bit 2 position. */
#define CTE_GCAFLIM3_bm  (1<<3)  /* GCAF Grass Cut Limit bit 3 mask. */
#define CTE_GCAFLIM3_bp  3  /* GCAF Grass Cut Limit bit 3 position. */
#define CTE_GCAFLIM4_bm  (1<<4)  /* GCAF Grass Cut Limit bit 4 mask. */
#define CTE_GCAFLIM4_bp  4  /* GCAF Grass Cut Limit bit 4 position. */
#define CTE_GCAFLIM5_bm  (1<<5)  /* GCAF Grass Cut Limit bit 5 mask. */
#define CTE_GCAFLIM5_bp  5  /* GCAF Grass Cut Limit bit 5 position. */
#define CTE_GCAFLIM6_bm  (1<<6)  /* GCAF Grass Cut Limit bit 6 mask. */
#define CTE_GCAFLIM6_bp  6  /* GCAF Grass Cut Limit bit 6 position. */
#define CTE_GCAFLIM7_bm  (1<<7)  /* GCAF Grass Cut Limit bit 7 mask. */
#define CTE_GCAFLIM7_bp  7  /* GCAF Grass Cut Limit bit 7 position. */

/* CTE.GCAFPCLL  bit masks and bit positions */
#define CTE_GCAFPCLL_7_0_gm  0xFF  /* GCAF Pre-Cut Lower Limit group mask. */
#define CTE_GCAFPCLL_7_0_gp  0  /* GCAF Pre-Cut Lower Limit group position. */
#define CTE_GCAFPCLL_7_00_bm  (1<<0)  /* GCAF Pre-Cut Lower Limit bit 0 mask. */
#define CTE_GCAFPCLL_7_00_bp  0  /* GCAF Pre-Cut Lower Limit bit 0 position. */
#define CTE_GCAFPCLL_7_01_bm  (1<<1)  /* GCAF Pre-Cut Lower Limit bit 1 mask. */
#define CTE_GCAFPCLL_7_01_bp  1  /* GCAF Pre-Cut Lower Limit bit 1 position. */
#define CTE_GCAFPCLL_7_02_bm  (1<<2)  /* GCAF Pre-Cut Lower Limit bit 2 mask. */
#define CTE_GCAFPCLL_7_02_bp  2  /* GCAF Pre-Cut Lower Limit bit 2 position. */
#define CTE_GCAFPCLL_7_03_bm  (1<<3)  /* GCAF Pre-Cut Lower Limit bit 3 mask. */
#define CTE_GCAFPCLL_7_03_bp  3  /* GCAF Pre-Cut Lower Limit bit 3 position. */
#define CTE_GCAFPCLL_7_04_bm  (1<<4)  /* GCAF Pre-Cut Lower Limit bit 4 mask. */
#define CTE_GCAFPCLL_7_04_bp  4  /* GCAF Pre-Cut Lower Limit bit 4 position. */
#define CTE_GCAFPCLL_7_05_bm  (1<<5)  /* GCAF Pre-Cut Lower Limit bit 5 mask. */
#define CTE_GCAFPCLL_7_05_bp  5  /* GCAF Pre-Cut Lower Limit bit 5 position. */
#define CTE_GCAFPCLL_7_06_bm  (1<<6)  /* GCAF Pre-Cut Lower Limit bit 6 mask. */
#define CTE_GCAFPCLL_7_06_bp  6  /* GCAF Pre-Cut Lower Limit bit 6 position. */
#define CTE_GCAFPCLL_7_07_bm  (1<<7)  /* GCAF Pre-Cut Lower Limit bit 7 mask. */
#define CTE_GCAFPCLL_7_07_bp  7  /* GCAF Pre-Cut Lower Limit bit 7 position. */

/* CTE.GCAFPCUL  bit masks and bit positions */
#define CTE_GCAFPCUL_7_0_gm  0xFF  /* GCAF Pre-Cut Upper Limit group mask. */
#define CTE_GCAFPCUL_7_0_gp  0  /* GCAF Pre-Cut Upper Limit group position. */
#define CTE_GCAFPCUL_7_00_bm  (1<<0)  /* GCAF Pre-Cut Upper Limit bit 0 mask. */
#define CTE_GCAFPCUL_7_00_bp  0  /* GCAF Pre-Cut Upper Limit bit 0 position. */
#define CTE_GCAFPCUL_7_01_bm  (1<<1)  /* GCAF Pre-Cut Upper Limit bit 1 mask. */
#define CTE_GCAFPCUL_7_01_bp  1  /* GCAF Pre-Cut Upper Limit bit 1 position. */
#define CTE_GCAFPCUL_7_02_bm  (1<<2)  /* GCAF Pre-Cut Upper Limit bit 2 mask. */
#define CTE_GCAFPCUL_7_02_bp  2  /* GCAF Pre-Cut Upper Limit bit 2 position. */
#define CTE_GCAFPCUL_7_03_bm  (1<<3)  /* GCAF Pre-Cut Upper Limit bit 3 mask. */
#define CTE_GCAFPCUL_7_03_bp  3  /* GCAF Pre-Cut Upper Limit bit 3 position. */
#define CTE_GCAFPCUL_7_04_bm  (1<<4)  /* GCAF Pre-Cut Upper Limit bit 4 mask. */
#define CTE_GCAFPCUL_7_04_bp  4  /* GCAF Pre-Cut Upper Limit bit 4 position. */
#define CTE_GCAFPCUL_7_05_bm  (1<<5)  /* GCAF Pre-Cut Upper Limit bit 5 mask. */
#define CTE_GCAFPCUL_7_05_bp  5  /* GCAF Pre-Cut Upper Limit bit 5 position. */
#define CTE_GCAFPCUL_7_06_bm  (1<<6)  /* GCAF Pre-Cut Upper Limit bit 6 mask. */
#define CTE_GCAFPCUL_7_06_bp  6  /* GCAF Pre-Cut Upper Limit bit 6 position. */
#define CTE_GCAFPCUL_7_07_bm  (1<<7)  /* GCAF Pre-Cut Upper Limit bit 7 mask. */
#define CTE_GCAFPCUL_7_07_bp  7  /* GCAF Pre-Cut Upper Limit bit 7 position. */











/* CTE.CTCRA  bit masks and bit positions */
#define CTE_CT32WE_bm  0x08  /* CapTouch 32-bit Write Enable of data memory 2 bit mask. */
#define CTE_CT32WE_bp  3  /* CapTouch 32-bit Write Enable of data memory 2 bit position. */

/* DFLL - DFLL */
/* DFLL.CTRL  bit masks and bit positions */
#define DFLL_ENABLE_bm  0x01  /* DFLL Enable bit mask. */
#define DFLL_ENABLE_bp  0  /* DFLL Enable bit position. */

/* DFLL.CALA  bit masks and bit positions */
#define DFLL_CALL_gm  0x7F  /* DFLL Calibration bits [6:0] group mask. */
#define DFLL_CALL_gp  0  /* DFLL Calibration bits [6:0] group position. */
#define DFLL_CALL0_bm  (1<<0)  /* DFLL Calibration bits [6:0] bit 0 mask. */
#define DFLL_CALL0_bp  0  /* DFLL Calibration bits [6:0] bit 0 position. */
#define DFLL_CALL1_bm  (1<<1)  /* DFLL Calibration bits [6:0] bit 1 mask. */
#define DFLL_CALL1_bp  1  /* DFLL Calibration bits [6:0] bit 1 position. */
#define DFLL_CALL2_bm  (1<<2)  /* DFLL Calibration bits [6:0] bit 2 mask. */
#define DFLL_CALL2_bp  2  /* DFLL Calibration bits [6:0] bit 2 position. */
#define DFLL_CALL3_bm  (1<<3)  /* DFLL Calibration bits [6:0] bit 3 mask. */
#define DFLL_CALL3_bp  3  /* DFLL Calibration bits [6:0] bit 3 position. */
#define DFLL_CALL4_bm  (1<<4)  /* DFLL Calibration bits [6:0] bit 4 mask. */
#define DFLL_CALL4_bp  4  /* DFLL Calibration bits [6:0] bit 4 position. */
#define DFLL_CALL5_bm  (1<<5)  /* DFLL Calibration bits [6:0] bit 5 mask. */
#define DFLL_CALL5_bp  5  /* DFLL Calibration bits [6:0] bit 5 position. */
#define DFLL_CALL6_bm  (1<<6)  /* DFLL Calibration bits [6:0] bit 6 mask. */
#define DFLL_CALL6_bp  6  /* DFLL Calibration bits [6:0] bit 6 position. */

/* DFLL.CALB  bit masks and bit positions */
#define DFLL_CALH_gm  0x3F  /* DFLL Calibration bits [12:7] group mask. */
#define DFLL_CALH_gp  0  /* DFLL Calibration bits [12:7] group position. */
#define DFLL_CALH0_bm  (1<<0)  /* DFLL Calibration bits [12:7] bit 0 mask. */
#define DFLL_CALH0_bp  0  /* DFLL Calibration bits [12:7] bit 0 position. */
#define DFLL_CALH1_bm  (1<<1)  /* DFLL Calibration bits [12:7] bit 1 mask. */
#define DFLL_CALH1_bp  1  /* DFLL Calibration bits [12:7] bit 1 position. */
#define DFLL_CALH2_bm  (1<<2)  /* DFLL Calibration bits [12:7] bit 2 mask. */
#define DFLL_CALH2_bp  2  /* DFLL Calibration bits [12:7] bit 2 position. */
#define DFLL_CALH3_bm  (1<<3)  /* DFLL Calibration bits [12:7] bit 3 mask. */
#define DFLL_CALH3_bp  3  /* DFLL Calibration bits [12:7] bit 3 position. */
#define DFLL_CALH4_bm  (1<<4)  /* DFLL Calibration bits [12:7] bit 4 mask. */
#define DFLL_CALH4_bp  4  /* DFLL Calibration bits [12:7] bit 4 position. */
#define DFLL_CALH5_bm  (1<<5)  /* DFLL Calibration bits [12:7] bit 5 mask. */
#define DFLL_CALH5_bp  5  /* DFLL Calibration bits [12:7] bit 5 position. */










/* MCU - MCU Control */
/* MCU.MCUCR  bit masks and bit positions */
#define MCU_JTAGD_bm  0x01  /* JTAG Disable bit mask. */
#define MCU_JTAGD_bp  0  /* JTAG Disable bit position. */

/* MCU.EVSYSLOCK  bit masks and bit positions */
#define MCU_EVSYS0LOCK_bm  0x01  /* Event Channel 0-3 Lock bit mask. */
#define MCU_EVSYS0LOCK_bp  0  /* Event Channel 0-3 Lock bit position. */
#define MCU_EVSYS1LOCK_bm  0x10  /* Event Channel 4-7 Lock bit mask. */
#define MCU_EVSYS1LOCK_bp  4  /* Event Channel 4-7 Lock bit position. */

/* MCU.AWEXLOCK  bit masks and bit positions */
#define MCU_AWEXCLOCK_bm  0x01  /* AWeX on T/C C0 Lock bit mask. */
#define MCU_AWEXCLOCK_bp  0  /* AWeX on T/C C0 Lock bit position. */
#define MCU_AWEXELOCK_bm  0x04  /* AWeX on T/C E0 Lock bit mask. */
#define MCU_AWEXELOCK_bp  2  /* AWeX on T/C E0 Lock bit position. */







/* NVM - Non Volatile Memory Controller */
/* NVM.CMD  bit masks and bit positions */
#define NVM_CMD_gm  0xFF  /* Command group mask. */
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
#define NVM_CMD7_bm  (1<<7)  /* Command bit 7 mask. */
#define NVM_CMD7_bp  7  /* Command bit 7 position. */

/* NVM.CTRLA  bit masks and bit positions */
#define NVM_CMDEX_bm  0x01  /* Command Execute bit mask. */
#define NVM_CMDEX_bp  0  /* Command Execute bit position. */

/* NVM.CTRLB  bit masks and bit positions */
#define NVM_SPMLOCK_bm  0x01  /* SPM Lock bit mask. */
#define NVM_SPMLOCK_bp  0  /* SPM Lock bit position. */
#define NVM_FPRM_bm  0x04  /* Flash Power Reduction Enable bit mask. */
#define NVM_FPRM_bp  2  /* Flash Power Reduction Enable bit position. */

/* NVM.INTCTRL  bit masks and bit positions */
#define NVM_SPMLVL_gm  0x0C  /* SPM Interrupt Level group mask. */
#define NVM_SPMLVL_gp  2  /* SPM Interrupt Level group position. */
#define NVM_SPMLVL0_bm  (1<<2)  /* SPM Interrupt Level bit 0 mask. */
#define NVM_SPMLVL0_bp  2  /* SPM Interrupt Level bit 0 position. */
#define NVM_SPMLVL1_bm  (1<<3)  /* SPM Interrupt Level bit 1 mask. */
#define NVM_SPMLVL1_bp  3  /* SPM Interrupt Level bit 1 position. */

/* NVM.STATUS  bit masks and bit positions */
#define NVM_FLOAD_bm  0x01  /* Flash Page Buffer Active Loading bit mask. */
#define NVM_FLOAD_bp  0  /* Flash Page Buffer Active Loading bit position. */
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

/* NVM_FUSES.FUSEBYTE4  bit masks and bit positions */
#define NVM_FUSES_WDLOCK_bm  0x02  /* Watchdog Timer Lock bit mask. */
#define NVM_FUSES_WDLOCK_bp  1  /* Watchdog Timer Lock bit position. */
#define NVM_FUSES_SUT_gm  0x0C  /* Start-up Time group mask. */
#define NVM_FUSES_SUT_gp  2  /* Start-up Time group position. */
#define NVM_FUSES_SUT0_bm  (1<<2)  /* Start-up Time bit 0 mask. */
#define NVM_FUSES_SUT0_bp  2  /* Start-up Time bit 0 position. */
#define NVM_FUSES_SUT1_bm  (1<<3)  /* Start-up Time bit 1 mask. */
#define NVM_FUSES_SUT1_bp  3  /* Start-up Time bit 1 position. */
#define NVM_FUSES_RSTDISBL_bm  0x10  /* Reset Disable bit mask. */
#define NVM_FUSES_RSTDISBL_bp  4  /* Reset Disable bit position. */

/* NVM_FUSES.FUSEBYTE5  bit masks and bit positions */
#define NVM_FUSES_BODLVL_gm  0x07  /* Brownout Detection Voltage Level group mask. */
#define NVM_FUSES_BODLVL_gp  0  /* Brownout Detection Voltage Level group position. */
#define NVM_FUSES_BODLVL0_bm  (1<<0)  /* Brownout Detection Voltage Level bit 0 mask. */
#define NVM_FUSES_BODLVL0_bp  0  /* Brownout Detection Voltage Level bit 0 position. */
#define NVM_FUSES_BODLVL1_bm  (1<<1)  /* Brownout Detection Voltage Level bit 1 mask. */
#define NVM_FUSES_BODLVL1_bp  1  /* Brownout Detection Voltage Level bit 1 position. */
#define NVM_FUSES_BODLVL2_bm  (1<<2)  /* Brownout Detection Voltage Level bit 2 mask. */
#define NVM_FUSES_BODLVL2_bp  2  /* Brownout Detection Voltage Level bit 2 position. */
#define NVM_FUSES_BODACT_gm  0x30  /* BOD Operation in Active Mode group mask. */
#define NVM_FUSES_BODACT_gp  4  /* BOD Operation in Active Mode group position. */
#define NVM_FUSES_BODACT0_bm  (1<<4)  /* BOD Operation in Active Mode bit 0 mask. */
#define NVM_FUSES_BODACT0_bp  4  /* BOD Operation in Active Mode bit 0 position. */
#define NVM_FUSES_BODACT1_bm  (1<<5)  /* BOD Operation in Active Mode bit 1 mask. */
#define NVM_FUSES_BODACT1_bp  5  /* BOD Operation in Active Mode bit 1 position. */
#define NVM_FUSES_BGCALSEL_gm  0xC0  /* Bandgap Calibration Select group mask. */
#define NVM_FUSES_BGCALSEL_gp  6  /* Bandgap Calibration Select group position. */
#define NVM_FUSES_BGCALSEL0_bm  (1<<6)  /* Bandgap Calibration Select bit 0 mask. */
#define NVM_FUSES_BGCALSEL0_bp  6  /* Bandgap Calibration Select bit 0 position. */
#define NVM_FUSES_BGCALSEL1_bm  (1<<7)  /* Bandgap Calibration Select bit 1 mask. */
#define NVM_FUSES_BGCALSEL1_bp  7  /* Bandgap Calibration Select bit 1 position. */























































/* OSC - Oscillator */
/* OSC.CTRL  bit masks and bit positions */
#define OSC_RC2MEN_bm  0x01  /* Internal 2MHz RC Oscillator Enable bit mask. */
#define OSC_RC2MEN_bp  0  /* Internal 2MHz RC Oscillator Enable bit position. */
#define OSC_RC32MEN_bm  0x02  /* Internal 32MHz RC Oscillator Enable bit mask. */
#define OSC_RC32MEN_bp  1  /* Internal 32MHz RC Oscillator Enable bit position. */
#define OSC_RC32KEN_bm  0x04  /* Internal 32kHz RC Oscillator Enable bit mask. */
#define OSC_RC32KEN_bp  2  /* Internal 32kHz RC Oscillator Enable bit position. */
#define OSC_XOSCEN_bm  0x08  /* External Oscillator Enable bit mask. */
#define OSC_XOSCEN_bp  3  /* External Oscillator Enable bit position. */
#define OSC_PLLEN_bm  0x10  /* PLL Enable bit mask. */
#define OSC_PLLEN_bp  4  /* PLL Enable bit position. */

/* OSC.STATUS  bit masks and bit positions */
#define OSC_RC2MRDY_bm  0x01  /* Internal 2MHz RC Oscillator Ready bit mask. */
#define OSC_RC2MRDY_bp  0  /* Internal 2MHz RC Oscillator Ready bit position. */
#define OSC_RC32MRDY_bm  0x02  /* Internal 32MHz RC Oscillator Ready bit mask. */
#define OSC_RC32MRDY_bp  1  /* Internal 32MHz RC Oscillator Ready bit position. */
#define OSC_RC32KRDY_bm  0x04  /* Internal 32kHz RC Oscillator Ready bit mask. */
#define OSC_RC32KRDY_bp  2  /* Internal 32kHz RC Oscillator Ready bit position. */
#define OSC_XOSCRDY_bm  0x08  /* External Oscillator Ready bit mask. */
#define OSC_XOSCRDY_bp  3  /* External Oscillator Ready bit position. */
#define OSC_PLLRDY_bm  0x10  /* PLL Ready bit mask. */
#define OSC_PLLRDY_bp  4  /* PLL Ready bit position. */

/* OSC.CLOCKINCTRL  bit masks and bit positions */
#define OSC_CLOCKINSEL_gm  0xE0  /* External Clock Input Select group mask. */
#define OSC_CLOCKINSEL_gp  5  /* External Clock Input Select group position. */
#define OSC_CLOCKINSEL0_bm  (1<<5)  /* External Clock Input Select bit 0 mask. */
#define OSC_CLOCKINSEL0_bp  5  /* External Clock Input Select bit 0 position. */
#define OSC_CLOCKINSEL1_bm  (1<<6)  /* External Clock Input Select bit 1 mask. */
#define OSC_CLOCKINSEL1_bp  6  /* External Clock Input Select bit 1 position. */
#define OSC_CLOCKINSEL2_bm  (1<<7)  /* External Clock Input Select bit 2 mask. */
#define OSC_CLOCKINSEL2_bp  7  /* External Clock Input Select bit 2 position. */

/* OSC.XOSCFAIL  bit masks and bit positions */
#define OSC_XOSCFDEN_bm  0x01  /* Failure Detection Enable bit mask. */
#define OSC_XOSCFDEN_bp  0  /* Failure Detection Enable bit position. */
#define OSC_XOSCFDIF_bm  0x02  /* Failure Detection Interrupt Flag bit mask. */
#define OSC_XOSCFDIF_bp  1  /* Failure Detection Interrupt Flag bit position. */


/* OSC.PLLCTRL  bit masks and bit positions */
#define OSC_PLLFAC_gm  0x1F  /* Multiplication Factor group mask. */
#define OSC_PLLFAC_gp  0  /* Multiplication Factor group position. */
#define OSC_PLLFAC0_bm  (1<<0)  /* Multiplication Factor bit 0 mask. */
#define OSC_PLLFAC0_bp  0  /* Multiplication Factor bit 0 position. */
#define OSC_PLLFAC1_bm  (1<<1)  /* Multiplication Factor bit 1 mask. */
#define OSC_PLLFAC1_bp  1  /* Multiplication Factor bit 1 position. */
#define OSC_PLLFAC2_bm  (1<<2)  /* Multiplication Factor bit 2 mask. */
#define OSC_PLLFAC2_bp  2  /* Multiplication Factor bit 2 position. */
#define OSC_PLLFAC3_bm  (1<<3)  /* Multiplication Factor bit 3 mask. */
#define OSC_PLLFAC3_bp  3  /* Multiplication Factor bit 3 position. */
#define OSC_PLLFAC4_bm  (1<<4)  /* Multiplication Factor bit 4 mask. */
#define OSC_PLLFAC4_bp  4  /* Multiplication Factor bit 4 position. */
#define OSC_PLLSRC_gm  0xC0  /* Clock Source group mask. */
#define OSC_PLLSRC_gp  6  /* Clock Source group position. */
#define OSC_PLLSRC0_bm  (1<<6)  /* Clock Source bit 0 mask. */
#define OSC_PLLSRC0_bp  6  /* Clock Source bit 0 position. */
#define OSC_PLLSRC1_bm  (1<<7)  /* Clock Source bit 1 mask. */
#define OSC_PLLSRC1_bp  7  /* Clock Source bit 1 position. */

/* OSC.DFLLCTRL  bit masks and bit positions */
#define OSC_RC2MCREF_bm  0x01  /* 2MHz Calibration Reference bit mask. */
#define OSC_RC2MCREF_bp  0  /* 2MHz Calibration Reference bit position. */
#define OSC_RC32MCREF_bm  0x02  /* 32MHz Calibration Reference bit mask. */
#define OSC_RC32MCREF_bp  1  /* 32MHz Calibration Reference bit position. */

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


/* PORT - Port Configuration */
/* PORTCFG.VPCTRLA  bit masks and bit positions */
#define PORTCFG_VP0MAP_gm  0x0F  /* Virtual Port 0 Mapping group mask. */
#define PORTCFG_VP0MAP_gp  0  /* Virtual Port 0 Mapping group position. */
#define PORTCFG_VP0MAP0_bm  (1<<0)  /* Virtual Port 0 Mapping bit 0 mask. */
#define PORTCFG_VP0MAP0_bp  0  /* Virtual Port 0 Mapping bit 0 position. */
#define PORTCFG_VP0MAP1_bm  (1<<1)  /* Virtual Port 0 Mapping bit 1 mask. */
#define PORTCFG_VP0MAP1_bp  1  /* Virtual Port 0 Mapping bit 1 position. */
#define PORTCFG_VP0MAP2_bm  (1<<2)  /* Virtual Port 0 Mapping bit 2 mask. */
#define PORTCFG_VP0MAP2_bp  2  /* Virtual Port 0 Mapping bit 2 position. */
#define PORTCFG_VP0MAP3_bm  (1<<3)  /* Virtual Port 0 Mapping bit 3 mask. */
#define PORTCFG_VP0MAP3_bp  3  /* Virtual Port 0 Mapping bit 3 position. */
#define PORTCFG_VP1MAP_gm  0xF0  /* Virtual Port 1 Mapping group mask. */
#define PORTCFG_VP1MAP_gp  4  /* Virtual Port 1 Mapping group position. */
#define PORTCFG_VP1MAP0_bm  (1<<4)  /* Virtual Port 1 Mapping bit 0 mask. */
#define PORTCFG_VP1MAP0_bp  4  /* Virtual Port 1 Mapping bit 0 position. */
#define PORTCFG_VP1MAP1_bm  (1<<5)  /* Virtual Port 1 Mapping bit 1 mask. */
#define PORTCFG_VP1MAP1_bp  5  /* Virtual Port 1 Mapping bit 1 position. */
#define PORTCFG_VP1MAP2_bm  (1<<6)  /* Virtual Port 1 Mapping bit 2 mask. */
#define PORTCFG_VP1MAP2_bp  6  /* Virtual Port 1 Mapping bit 2 position. */
#define PORTCFG_VP1MAP3_bm  (1<<7)  /* Virtual Port 1 Mapping bit 3 mask. */
#define PORTCFG_VP1MAP3_bp  7  /* Virtual Port 1 Mapping bit 3 position. */

/* PORTCFG.VPCTRLB  bit masks and bit positions */
#define PORTCFG_VP2MAP_gm  0x0F  /* Virtual Port 2 Mapping group mask. */
#define PORTCFG_VP2MAP_gp  0  /* Virtual Port 2 Mapping group position. */
#define PORTCFG_VP2MAP0_bm  (1<<0)  /* Virtual Port 2 Mapping bit 0 mask. */
#define PORTCFG_VP2MAP0_bp  0  /* Virtual Port 2 Mapping bit 0 position. */
#define PORTCFG_VP2MAP1_bm  (1<<1)  /* Virtual Port 2 Mapping bit 1 mask. */
#define PORTCFG_VP2MAP1_bp  1  /* Virtual Port 2 Mapping bit 1 position. */
#define PORTCFG_VP2MAP2_bm  (1<<2)  /* Virtual Port 2 Mapping bit 2 mask. */
#define PORTCFG_VP2MAP2_bp  2  /* Virtual Port 2 Mapping bit 2 position. */
#define PORTCFG_VP2MAP3_bm  (1<<3)  /* Virtual Port 2 Mapping bit 3 mask. */
#define PORTCFG_VP2MAP3_bp  3  /* Virtual Port 2 Mapping bit 3 position. */
#define PORTCFG_VP3MAP_gm  0xF0  /* Virtual Port 3 Mapping group mask. */
#define PORTCFG_VP3MAP_gp  4  /* Virtual Port 3 Mapping group position. */
#define PORTCFG_VP3MAP0_bm  (1<<4)  /* Virtual Port 3 Mapping bit 0 mask. */
#define PORTCFG_VP3MAP0_bp  4  /* Virtual Port 3 Mapping bit 0 position. */
#define PORTCFG_VP3MAP1_bm  (1<<5)  /* Virtual Port 3 Mapping bit 1 mask. */
#define PORTCFG_VP3MAP1_bp  5  /* Virtual Port 3 Mapping bit 1 position. */
#define PORTCFG_VP3MAP2_bm  (1<<6)  /* Virtual Port 3 Mapping bit 2 mask. */
#define PORTCFG_VP3MAP2_bp  6  /* Virtual Port 3 Mapping bit 2 position. */
#define PORTCFG_VP3MAP3_bm  (1<<7)  /* Virtual Port 3 Mapping bit 3 mask. */
#define PORTCFG_VP3MAP3_bp  7  /* Virtual Port 3 Mapping bit 3 position. */

/* PORTCFG.CLKEVOUT  bit masks and bit positions */
#define PORTCFG_CLKOUT_bm  0x01  /* Clock Output Port bit mask. */
#define PORTCFG_CLKOUT_bp  0  /* Clock Output Port bit position. */




/* VPORT.INTFLAGS  bit masks and bit positions */
#define VPORT_INT0IF_bm  0x01  /* Port Interrupt 0 Flag bit mask. */
#define VPORT_INT0IF_bp  0  /* Port Interrupt 0 Flag bit position. */
#define VPORT_INT1IF_bm  0x02  /* Port Interrupt 1 Flag bit mask. */
#define VPORT_INT1IF_bp  1  /* Port Interrupt 1 Flag bit position. */










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










/* PORT_T.INTCTRL  bit masks and bit positions */
#define PORT_T_INT0LVL_gm  0x03  /* Port Interrupt 0 Level group mask. */
#define PORT_T_INT0LVL_gp  0  /* Port Interrupt 0 Level group position. */
#define PORT_T_INT0LVL0_bm  (1<<0)  /* Port Interrupt 0 Level bit 0 mask. */
#define PORT_T_INT0LVL0_bp  0  /* Port Interrupt 0 Level bit 0 position. */
#define PORT_T_INT0LVL1_bm  (1<<1)  /* Port Interrupt 0 Level bit 1 mask. */
#define PORT_T_INT0LVL1_bp  1  /* Port Interrupt 0 Level bit 1 position. */
#define PORT_T_INT1LVL_gm  0x0C  /* Port Interrupt 1 Level group mask. */
#define PORT_T_INT1LVL_gp  2  /* Port Interrupt 1 Level group position. */
#define PORT_T_INT1LVL0_bm  (1<<2)  /* Port Interrupt 1 Level bit 0 mask. */
#define PORT_T_INT1LVL0_bp  2  /* Port Interrupt 1 Level bit 0 position. */
#define PORT_T_INT1LVL1_bm  (1<<3)  /* Port Interrupt 1 Level bit 1 mask. */
#define PORT_T_INT1LVL1_bp  3  /* Port Interrupt 1 Level bit 1 position. */



/* PORT_T.INTFLAGS  bit masks and bit positions */
#define PORT_T_INT0IF_bm  0x01  /* Port Interrupt 0 Flag bit mask. */
#define PORT_T_INT0IF_bp  0  /* Port Interrupt 0 Flag bit position. */
#define PORT_T_INT1IF_bm  0x02  /* Port Interrupt 1 Flag bit mask. */
#define PORT_T_INT1IF_bp  1  /* Port Interrupt 1 Flag bit position. */











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
#define RST_SRF_bm  0x20  /* Software Reset Flag bit mask. */
#define RST_SRF_bp  5  /* Software Reset Flag bit position. */
#define RST_SDRF_bm  0x40  /* Spike Detection Reset Flag bit mask. */
#define RST_SDRF_bp  6  /* Spike Detection Reset Flag bit position. */

/* RST.CTRL  bit masks and bit positions */
#define RST_SWRST_bm  0x01  /* Software Reset bit mask. */
#define RST_SWRST_bp  0  /* Software Reset bit position. */

/* RTC - Real-Time Counter */
/* RTC.CTRL  bit masks and bit positions */
#define RTC_PRESCALER_gm  0x07  /* Prescaling Factor group mask. */
#define RTC_PRESCALER_gp  0  /* Prescaling Factor group position. */
#define RTC_PRESCALER0_bm  (1<<0)  /* Prescaling Factor bit 0 mask. */
#define RTC_PRESCALER0_bp  0  /* Prescaling Factor bit 0 position. */
#define RTC_PRESCALER1_bm  (1<<1)  /* Prescaling Factor bit 1 mask. */
#define RTC_PRESCALER1_bp  1  /* Prescaling Factor bit 1 position. */
#define RTC_PRESCALER2_bm  (1<<2)  /* Prescaling Factor bit 2 mask. */
#define RTC_PRESCALER2_bp  2  /* Prescaling Factor bit 2 position. */

/* RTC.STATUS  bit masks and bit positions */
#define RTC_SYNCBUSY_bm  0x01  /* Synchronization Busy Flag bit mask. */
#define RTC_SYNCBUSY_bp  0  /* Synchronization Busy Flag bit position. */

/* RTC.INTCTRL  bit masks and bit positions */
#define RTC_OVFINTLVL_gm  0x03  /* Overflow Interrupt Level group mask. */
#define RTC_OVFINTLVL_gp  0  /* Overflow Interrupt Level group position. */
#define RTC_OVFINTLVL0_bm  (1<<0)  /* Overflow Interrupt Level bit 0 mask. */
#define RTC_OVFINTLVL0_bp  0  /* Overflow Interrupt Level bit 0 position. */
#define RTC_OVFINTLVL1_bm  (1<<1)  /* Overflow Interrupt Level bit 1 mask. */
#define RTC_OVFINTLVL1_bp  1  /* Overflow Interrupt Level bit 1 position. */
#define RTC_COMPINTLVL_gm  0x0C  /* Compare Match Interrupt Level group mask. */
#define RTC_COMPINTLVL_gp  2  /* Compare Match Interrupt Level group position. */
#define RTC_COMPINTLVL0_bm  (1<<2)  /* Compare Match Interrupt Level bit 0 mask. */
#define RTC_COMPINTLVL0_bp  2  /* Compare Match Interrupt Level bit 0 position. */
#define RTC_COMPINTLVL1_bm  (1<<3)  /* Compare Match Interrupt Level bit 1 mask. */
#define RTC_COMPINTLVL1_bp  3  /* Compare Match Interrupt Level bit 1 position. */

/* RTC.INTFLAGS  bit masks and bit positions */
#define RTC_OVFIF_bm  0x01  /* Overflow Interrupt Flag bit mask. */
#define RTC_OVFIF_bp  0  /* Overflow Interrupt Flag bit position. */
#define RTC_COMPIF_bm  0x02  /* Compare Match Interrupt Flag bit mask. */
#define RTC_COMPIF_bp  1  /* Compare Match Interrupt Flag bit position. */





/* SLEEP - Sleep Controller */
/* SLEEP.CTRL  bit masks and bit positions */
#define SLEEP_SEN_bm  0x01  /* Sleep Enable bit mask. */
#define SLEEP_SEN_bp  0  /* Sleep Enable bit position. */
#define SLEEP_SMODE_gm  0x0E  /* Sleep Mode group mask. */
#define SLEEP_SMODE_gp  1  /* Sleep Mode group position. */
#define SLEEP_SMODE0_bm  (1<<1)  /* Sleep Mode bit 0 mask. */
#define SLEEP_SMODE0_bp  1  /* Sleep Mode bit 0 position. */
#define SLEEP_SMODE1_bm  (1<<2)  /* Sleep Mode bit 1 mask. */
#define SLEEP_SMODE1_bp  2  /* Sleep Mode bit 1 position. */
#define SLEEP_SMODE2_bm  (1<<3)  /* Sleep Mode bit 2 mask. */
#define SLEEP_SMODE2_bp  3  /* Sleep Mode bit 2 position. */

/* SPI - Serial Peripheral Interface */
/* SPI.CTRL  bit masks and bit positions */
#define SPI_PRESCALER_gm  0x03  /* Prescaler group mask. */
#define SPI_PRESCALER_gp  0  /* Prescaler group position. */
#define SPI_PRESCALER0_bm  (1<<0)  /* Prescaler bit 0 mask. */
#define SPI_PRESCALER0_bp  0  /* Prescaler bit 0 position. */
#define SPI_PRESCALER1_bm  (1<<1)  /* Prescaler bit 1 mask. */
#define SPI_PRESCALER1_bp  1  /* Prescaler bit 1 position. */
#define SPI_MODE_gm  0x0C  /* SPI Mode group mask. */
#define SPI_MODE_gp  2  /* SPI Mode group position. */
#define SPI_MODE0_bm  (1<<2)  /* SPI Mode bit 0 mask. */
#define SPI_MODE0_bp  2  /* SPI Mode bit 0 position. */
#define SPI_MODE1_bm  (1<<3)  /* SPI Mode bit 1 mask. */
#define SPI_MODE1_bp  3  /* SPI Mode bit 1 position. */
#define SPI_MASTER_bm  0x10  /* Master Operation Enable bit mask. */
#define SPI_MASTER_bp  4  /* Master Operation Enable bit position. */
#define SPI_DORD_bm  0x20  /* Data Order Setting bit mask. */
#define SPI_DORD_bp  5  /* Data Order Setting bit position. */
#define SPI_ENABLE_bm  0x40  /* Enable Module bit mask. */
#define SPI_ENABLE_bp  6  /* Enable Module bit position. */
#define SPI_CLK2X_bm  0x80  /* Enable Double Speed bit mask. */
#define SPI_CLK2X_bp  7  /* Enable Double Speed bit position. */

/* SPI.INTCTRL  bit masks and bit positions */
#define SPI_INTLVL_gm  0x03  /* Interrupt level group mask. */
#define SPI_INTLVL_gp  0  /* Interrupt level group position. */
#define SPI_INTLVL0_bm  (1<<0)  /* Interrupt level bit 0 mask. */
#define SPI_INTLVL0_bp  0  /* Interrupt level bit 0 position. */
#define SPI_INTLVL1_bm  (1<<1)  /* Interrupt level bit 1 mask. */
#define SPI_INTLVL1_bp  1  /* Interrupt level bit 1 position. */

/* SPI.STATUS  bit masks and bit positions */
#define SPI_WRCOL_bm  0x40  /* Write Collision bit mask. */
#define SPI_WRCOL_bp  6  /* Write Collision bit position. */
#define SPI_IF_bm  0x80  /* Interrupt Flag bit mask. */
#define SPI_IF_bp  7  /* Interrupt Flag bit position. */


/* TC - 16-bit Timer/Counter With PWM */
/* TC0.CTRLA  bit masks and bit positions */
#define TC0_CLKSEL_gm  0x0F  /* Clock Selection group mask. */
#define TC0_CLKSEL_gp  0  /* Clock Selection group position. */
#define TC0_CLKSEL0_bm  (1<<0)  /* Clock Selection bit 0 mask. */
#define TC0_CLKSEL0_bp  0  /* Clock Selection bit 0 position. */
#define TC0_CLKSEL1_bm  (1<<1)  /* Clock Selection bit 1 mask. */
#define TC0_CLKSEL1_bp  1  /* Clock Selection bit 1 position. */
#define TC0_CLKSEL2_bm  (1<<2)  /* Clock Selection bit 2 mask. */
#define TC0_CLKSEL2_bp  2  /* Clock Selection bit 2 position. */
#define TC0_CLKSEL3_bm  (1<<3)  /* Clock Selection bit 3 mask. */
#define TC0_CLKSEL3_bp  3  /* Clock Selection bit 3 position. */

/* TC0.CTRLB  bit masks and bit positions */
#define TC0_WGMODE_gm  0x07  /* Waveform generation mode group mask. */
#define TC0_WGMODE_gp  0  /* Waveform generation mode group position. */
#define TC0_WGMODE0_bm  (1<<0)  /* Waveform generation mode bit 0 mask. */
#define TC0_WGMODE0_bp  0  /* Waveform generation mode bit 0 position. */
#define TC0_WGMODE1_bm  (1<<1)  /* Waveform generation mode bit 1 mask. */
#define TC0_WGMODE1_bp  1  /* Waveform generation mode bit 1 position. */
#define TC0_WGMODE2_bm  (1<<2)  /* Waveform generation mode bit 2 mask. */
#define TC0_WGMODE2_bp  2  /* Waveform generation mode bit 2 position. */
#define TC0_CCAEN_bm  0x10  /* Compare or Capture A Enable bit mask. */
#define TC0_CCAEN_bp  4  /* Compare or Capture A Enable bit position. */
#define TC0_CCBEN_bm  0x20  /* Compare or Capture B Enable bit mask. */
#define TC0_CCBEN_bp  5  /* Compare or Capture B Enable bit position. */
#define TC0_CCCEN_bm  0x40  /* Compare or Capture C Enable bit mask. */
#define TC0_CCCEN_bp  6  /* Compare or Capture C Enable bit position. */
#define TC0_CCDEN_bm  0x80  /* Compare or Capture D Enable bit mask. */
#define TC0_CCDEN_bp  7  /* Compare or Capture D Enable bit position. */

/* TC0.CTRLC  bit masks and bit positions */
#define TC0_CMPA_bm  0x01  /* Compare A Output Value bit mask. */
#define TC0_CMPA_bp  0  /* Compare A Output Value bit position. */
#define TC0_CMPB_bm  0x02  /* Compare B Output Value bit mask. */
#define TC0_CMPB_bp  1  /* Compare B Output Value bit position. */
#define TC0_CMPC_bm  0x04  /* Compare C Output Value bit mask. */
#define TC0_CMPC_bp  2  /* Compare C Output Value bit position. */
#define TC0_CMPD_bm  0x08  /* Compare D Output Value bit mask. */
#define TC0_CMPD_bp  3  /* Compare D Output Value bit position. */

/* TC0.CTRLD  bit masks and bit positions */
#define TC0_EVSEL_gm  0x0F  /* Event Source Select group mask. */
#define TC0_EVSEL_gp  0  /* Event Source Select group position. */
#define TC0_EVSEL0_bm  (1<<0)  /* Event Source Select bit 0 mask. */
#define TC0_EVSEL0_bp  0  /* Event Source Select bit 0 position. */
#define TC0_EVSEL1_bm  (1<<1)  /* Event Source Select bit 1 mask. */
#define TC0_EVSEL1_bp  1  /* Event Source Select bit 1 position. */
#define TC0_EVSEL2_bm  (1<<2)  /* Event Source Select bit 2 mask. */
#define TC0_EVSEL2_bp  2  /* Event Source Select bit 2 position. */
#define TC0_EVSEL3_bm  (1<<3)  /* Event Source Select bit 3 mask. */
#define TC0_EVSEL3_bp  3  /* Event Source Select bit 3 position. */
#define TC0_EVDLY_bm  0x10  /* Event Delay bit mask. */
#define TC0_EVDLY_bp  4  /* Event Delay bit position. */
#define TC0_EVACT_gm  0xE0  /* Event Action group mask. */
#define TC0_EVACT_gp  5  /* Event Action group position. */
#define TC0_EVACT0_bm  (1<<5)  /* Event Action bit 0 mask. */
#define TC0_EVACT0_bp  5  /* Event Action bit 0 position. */
#define TC0_EVACT1_bm  (1<<6)  /* Event Action bit 1 mask. */
#define TC0_EVACT1_bp  6  /* Event Action bit 1 position. */
#define TC0_EVACT2_bm  (1<<7)  /* Event Action bit 2 mask. */
#define TC0_EVACT2_bp  7  /* Event Action bit 2 position. */

/* TC0.CTRLE  bit masks and bit positions */
#define TC0_BYTEM_bm  0x01  /* Byte Mode bit mask. */
#define TC0_BYTEM_bp  0  /* Byte Mode bit position. */

/* TC0.INTCTRLA  bit masks and bit positions */
#define TC0_OVFINTLVL_gm  0x03  /* Overflow interrupt level group mask. */
#define TC0_OVFINTLVL_gp  0  /* Overflow interrupt level group position. */
#define TC0_OVFINTLVL0_bm  (1<<0)  /* Overflow interrupt level bit 0 mask. */
#define TC0_OVFINTLVL0_bp  0  /* Overflow interrupt level bit 0 position. */
#define TC0_OVFINTLVL1_bm  (1<<1)  /* Overflow interrupt level bit 1 mask. */
#define TC0_OVFINTLVL1_bp  1  /* Overflow interrupt level bit 1 position. */
#define TC0_ERRINTLVL_gm  0x0C  /* Error Interrupt Level group mask. */
#define TC0_ERRINTLVL_gp  2  /* Error Interrupt Level group position. */
#define TC0_ERRINTLVL0_bm  (1<<2)  /* Error Interrupt Level bit 0 mask. */
#define TC0_ERRINTLVL0_bp  2  /* Error Interrupt Level bit 0 position. */
#define TC0_ERRINTLVL1_bm  (1<<3)  /* Error Interrupt Level bit 1 mask. */
#define TC0_ERRINTLVL1_bp  3  /* Error Interrupt Level bit 1 position. */

/* TC0.INTCTRLB  bit masks and bit positions */
#define TC0_CCAINTLVL_gm  0x03  /* Compare or Capture A Interrupt Level group mask. */
#define TC0_CCAINTLVL_gp  0  /* Compare or Capture A Interrupt Level group position. */
#define TC0_CCAINTLVL0_bm  (1<<0)  /* Compare or Capture A Interrupt Level bit 0 mask. */
#define TC0_CCAINTLVL0_bp  0  /* Compare or Capture A Interrupt Level bit 0 position. */
#define TC0_CCAINTLVL1_bm  (1<<1)  /* Compare or Capture A Interrupt Level bit 1 mask. */
#define TC0_CCAINTLVL1_bp  1  /* Compare or Capture A Interrupt Level bit 1 position. */
#define TC0_CCBINTLVL_gm  0x0C  /* Compare or Capture B Interrupt Level group mask. */
#define TC0_CCBINTLVL_gp  2  /* Compare or Capture B Interrupt Level group position. */
#define TC0_CCBINTLVL0_bm  (1<<2)  /* Compare or Capture B Interrupt Level bit 0 mask. */
#define TC0_CCBINTLVL0_bp  2  /* Compare or Capture B Interrupt Level bit 0 position. */
#define TC0_CCBINTLVL1_bm  (1<<3)  /* Compare or Capture B Interrupt Level bit 1 mask. */
#define TC0_CCBINTLVL1_bp  3  /* Compare or Capture B Interrupt Level bit 1 position. */
#define TC0_CCCINTLVL_gm  0x30  /* Compare or Capture C Interrupt Level group mask. */
#define TC0_CCCINTLVL_gp  4  /* Compare or Capture C Interrupt Level group position. */
#define TC0_CCCINTLVL0_bm  (1<<4)  /* Compare or Capture C Interrupt Level bit 0 mask. */
#define TC0_CCCINTLVL0_bp  4  /* Compare or Capture C Interrupt Level bit 0 position. */
#define TC0_CCCINTLVL1_bm  (1<<5)  /* Compare or Capture C Interrupt Level bit 1 mask. */
#define TC0_CCCINTLVL1_bp  5  /* Compare or Capture C Interrupt Level bit 1 position. */
#define TC0_CCDINTLVL_gm  0xC0  /* Compare or Capture D Interrupt Level group mask. */
#define TC0_CCDINTLVL_gp  6  /* Compare or Capture D Interrupt Level group position. */
#define TC0_CCDINTLVL0_bm  (1<<6)  /* Compare or Capture D Interrupt Level bit 0 mask. */
#define TC0_CCDINTLVL0_bp  6  /* Compare or Capture D Interrupt Level bit 0 position. */
#define TC0_CCDINTLVL1_bm  (1<<7)  /* Compare or Capture D Interrupt Level bit 1 mask. */
#define TC0_CCDINTLVL1_bp  7  /* Compare or Capture D Interrupt Level bit 1 position. */

/* TC0.CTRLFCLR  bit masks and bit positions */
#define TC0_DIR_bm  0x01  /* Direction bit mask. */
#define TC0_DIR_bp  0  /* Direction bit position. */
#define TC0_LUPD_bm  0x02  /* Lock Update bit mask. */
#define TC0_LUPD_bp  1  /* Lock Update bit position. */
#define TC0_CMD_gm  0x0C  /* Command group mask. */
#define TC0_CMD_gp  2  /* Command group position. */
#define TC0_CMD0_bm  (1<<2)  /* Command bit 0 mask. */
#define TC0_CMD0_bp  2  /* Command bit 0 position. */
#define TC0_CMD1_bm  (1<<3)  /* Command bit 1 mask. */
#define TC0_CMD1_bp  3  /* Command bit 1 position. */

/* TC0.CTRLFSET  bit masks and bit positions */
/* TC0_DIR  is already defined. */
/* TC0_LUPD  is already defined. */
/* TC0_CMD  is already defined. */

/* TC0.CTRLGCLR  bit masks and bit positions */
#define TC0_PERBV_bm  0x01  /* Period Buffer Valid bit mask. */
#define TC0_PERBV_bp  0  /* Period Buffer Valid bit position. */
#define TC0_CCABV_bm  0x02  /* Compare or Capture A Buffer Valid bit mask. */
#define TC0_CCABV_bp  1  /* Compare or Capture A Buffer Valid bit position. */
#define TC0_CCBBV_bm  0x04  /* Compare or Capture B Buffer Valid bit mask. */
#define TC0_CCBBV_bp  2  /* Compare or Capture B Buffer Valid bit position. */
#define TC0_CCCBV_bm  0x08  /* Compare or Capture C Buffer Valid bit mask. */
#define TC0_CCCBV_bp  3  /* Compare or Capture C Buffer Valid bit position. */
#define TC0_CCDBV_bm  0x10  /* Compare or Capture D Buffer Valid bit mask. */
#define TC0_CCDBV_bp  4  /* Compare or Capture D Buffer Valid bit position. */

/* TC0.CTRLGSET  bit masks and bit positions */
/* TC0_PERBV  is already defined. */
/* TC0_CCABV  is already defined. */
/* TC0_CCBBV  is already defined. */
/* TC0_CCCBV  is already defined. */
/* TC0_CCDBV  is already defined. */

/* TC0.INTFLAGS  bit masks and bit positions */
#define TC0_OVFIF_bm  0x01  /* Overflow Interrupt Flag bit mask. */
#define TC0_OVFIF_bp  0  /* Overflow Interrupt Flag bit position. */
#define TC0_ERRIF_bm  0x02  /* Error Interrupt Flag bit mask. */
#define TC0_ERRIF_bp  1  /* Error Interrupt Flag bit position. */
#define TC0_CCAIF_bm  0x10  /* Compare or Capture A Interrupt Flag bit mask. */
#define TC0_CCAIF_bp  4  /* Compare or Capture A Interrupt Flag bit position. */
#define TC0_CCBIF_bm  0x20  /* Compare or Capture B Interrupt Flag bit mask. */
#define TC0_CCBIF_bp  5  /* Compare or Capture B Interrupt Flag bit position. */
#define TC0_CCCIF_bm  0x40  /* Compare or Capture C Interrupt Flag bit mask. */
#define TC0_CCCIF_bp  6  /* Compare or Capture C Interrupt Flag bit position. */
#define TC0_CCDIF_bm  0x80  /* Compare or Capture D Interrupt Flag bit mask. */
#define TC0_CCDIF_bp  7  /* Compare or Capture D Interrupt Flag bit position. */













/* TC1.CTRLA  bit masks and bit positions */
#define TC1_CLKSEL_gm  0x0F  /* Clock Selection group mask. */
#define TC1_CLKSEL_gp  0  /* Clock Selection group position. */
#define TC1_CLKSEL0_bm  (1<<0)  /* Clock Selection bit 0 mask. */
#define TC1_CLKSEL0_bp  0  /* Clock Selection bit 0 position. */
#define TC1_CLKSEL1_bm  (1<<1)  /* Clock Selection bit 1 mask. */
#define TC1_CLKSEL1_bp  1  /* Clock Selection bit 1 position. */
#define TC1_CLKSEL2_bm  (1<<2)  /* Clock Selection bit 2 mask. */
#define TC1_CLKSEL2_bp  2  /* Clock Selection bit 2 position. */
#define TC1_CLKSEL3_bm  (1<<3)  /* Clock Selection bit 3 mask. */
#define TC1_CLKSEL3_bp  3  /* Clock Selection bit 3 position. */

/* TC1.CTRLB  bit masks and bit positions */
#define TC1_WGMODE_gm  0x07  /* Waveform generation mode group mask. */
#define TC1_WGMODE_gp  0  /* Waveform generation mode group position. */
#define TC1_WGMODE0_bm  (1<<0)  /* Waveform generation mode bit 0 mask. */
#define TC1_WGMODE0_bp  0  /* Waveform generation mode bit 0 position. */
#define TC1_WGMODE1_bm  (1<<1)  /* Waveform generation mode bit 1 mask. */
#define TC1_WGMODE1_bp  1  /* Waveform generation mode bit 1 position. */
#define TC1_WGMODE2_bm  (1<<2)  /* Waveform generation mode bit 2 mask. */
#define TC1_WGMODE2_bp  2  /* Waveform generation mode bit 2 position. */
#define TC1_CCAEN_bm  0x10  /* Compare or Capture A Enable bit mask. */
#define TC1_CCAEN_bp  4  /* Compare or Capture A Enable bit position. */
#define TC1_CCBEN_bm  0x20  /* Compare or Capture B Enable bit mask. */
#define TC1_CCBEN_bp  5  /* Compare or Capture B Enable bit position. */

/* TC1.CTRLC  bit masks and bit positions */
#define TC1_CMPA_bm  0x01  /* Compare A Output Value bit mask. */
#define TC1_CMPA_bp  0  /* Compare A Output Value bit position. */
#define TC1_CMPB_bm  0x02  /* Compare B Output Value bit mask. */
#define TC1_CMPB_bp  1  /* Compare B Output Value bit position. */

/* TC1.CTRLD  bit masks and bit positions */
#define TC1_EVSEL_gm  0x0F  /* Event Source Select group mask. */
#define TC1_EVSEL_gp  0  /* Event Source Select group position. */
#define TC1_EVSEL0_bm  (1<<0)  /* Event Source Select bit 0 mask. */
#define TC1_EVSEL0_bp  0  /* Event Source Select bit 0 position. */
#define TC1_EVSEL1_bm  (1<<1)  /* Event Source Select bit 1 mask. */
#define TC1_EVSEL1_bp  1  /* Event Source Select bit 1 position. */
#define TC1_EVSEL2_bm  (1<<2)  /* Event Source Select bit 2 mask. */
#define TC1_EVSEL2_bp  2  /* Event Source Select bit 2 position. */
#define TC1_EVSEL3_bm  (1<<3)  /* Event Source Select bit 3 mask. */
#define TC1_EVSEL3_bp  3  /* Event Source Select bit 3 position. */
#define TC1_EVDLY_bm  0x10  /* Event Delay bit mask. */
#define TC1_EVDLY_bp  4  /* Event Delay bit position. */
#define TC1_EVACT_gm  0xE0  /* Event Action group mask. */
#define TC1_EVACT_gp  5  /* Event Action group position. */
#define TC1_EVACT0_bm  (1<<5)  /* Event Action bit 0 mask. */
#define TC1_EVACT0_bp  5  /* Event Action bit 0 position. */
#define TC1_EVACT1_bm  (1<<6)  /* Event Action bit 1 mask. */
#define TC1_EVACT1_bp  6  /* Event Action bit 1 position. */
#define TC1_EVACT2_bm  (1<<7)  /* Event Action bit 2 mask. */
#define TC1_EVACT2_bp  7  /* Event Action bit 2 position. */

/* TC1.CTRLE  bit masks and bit positions */
#define TC1_BYTEM_bm  0x01  /* Byte Mode bit mask. */
#define TC1_BYTEM_bp  0  /* Byte Mode bit position. */

/* TC1.INTCTRLA  bit masks and bit positions */
#define TC1_OVFINTLVL_gm  0x03  /* Overflow interrupt level group mask. */
#define TC1_OVFINTLVL_gp  0  /* Overflow interrupt level group position. */
#define TC1_OVFINTLVL0_bm  (1<<0)  /* Overflow interrupt level bit 0 mask. */
#define TC1_OVFINTLVL0_bp  0  /* Overflow interrupt level bit 0 position. */
#define TC1_OVFINTLVL1_bm  (1<<1)  /* Overflow interrupt level bit 1 mask. */
#define TC1_OVFINTLVL1_bp  1  /* Overflow interrupt level bit 1 position. */
#define TC1_ERRINTLVL_gm  0x0C  /* Error Interrupt Level group mask. */
#define TC1_ERRINTLVL_gp  2  /* Error Interrupt Level group position. */
#define TC1_ERRINTLVL0_bm  (1<<2)  /* Error Interrupt Level bit 0 mask. */
#define TC1_ERRINTLVL0_bp  2  /* Error Interrupt Level bit 0 position. */
#define TC1_ERRINTLVL1_bm  (1<<3)  /* Error Interrupt Level bit 1 mask. */
#define TC1_ERRINTLVL1_bp  3  /* Error Interrupt Level bit 1 position. */

/* TC1.INTCTRLB  bit masks and bit positions */
#define TC1_CCAINTLVL_gm  0x03  /* Compare or Capture A Interrupt Level group mask. */
#define TC1_CCAINTLVL_gp  0  /* Compare or Capture A Interrupt Level group position. */
#define TC1_CCAINTLVL0_bm  (1<<0)  /* Compare or Capture A Interrupt Level bit 0 mask. */
#define TC1_CCAINTLVL0_bp  0  /* Compare or Capture A Interrupt Level bit 0 position. */
#define TC1_CCAINTLVL1_bm  (1<<1)  /* Compare or Capture A Interrupt Level bit 1 mask. */
#define TC1_CCAINTLVL1_bp  1  /* Compare or Capture A Interrupt Level bit 1 position. */
#define TC1_CCBINTLVL_gm  0x0C  /* Compare or Capture B Interrupt Level group mask. */
#define TC1_CCBINTLVL_gp  2  /* Compare or Capture B Interrupt Level group position. */
#define TC1_CCBINTLVL0_bm  (1<<2)  /* Compare or Capture B Interrupt Level bit 0 mask. */
#define TC1_CCBINTLVL0_bp  2  /* Compare or Capture B Interrupt Level bit 0 position. */
#define TC1_CCBINTLVL1_bm  (1<<3)  /* Compare or Capture B Interrupt Level bit 1 mask. */
#define TC1_CCBINTLVL1_bp  3  /* Compare or Capture B Interrupt Level bit 1 position. */

/* TC1.CTRLFCLR  bit masks and bit positions */
#define TC1_DIR_bm  0x01  /* Direction bit mask. */
#define TC1_DIR_bp  0  /* Direction bit position. */
#define TC1_LUPD_bm  0x02  /* Lock Update bit mask. */
#define TC1_LUPD_bp  1  /* Lock Update bit position. */
#define TC1_CMD_gm  0x0C  /* Command group mask. */
#define TC1_CMD_gp  2  /* Command group position. */
#define TC1_CMD0_bm  (1<<2)  /* Command bit 0 mask. */
#define TC1_CMD0_bp  2  /* Command bit 0 position. */
#define TC1_CMD1_bm  (1<<3)  /* Command bit 1 mask. */
#define TC1_CMD1_bp  3  /* Command bit 1 position. */

/* TC1.CTRLFSET  bit masks and bit positions */
/* TC1_DIR  is already defined. */
/* TC1_LUPD  is already defined. */
/* TC1_CMD  is already defined. */

/* TC1.CTRLGCLR  bit masks and bit positions */
#define TC1_PERBV_bm  0x01  /* Period Buffer Valid bit mask. */
#define TC1_PERBV_bp  0  /* Period Buffer Valid bit position. */
#define TC1_CCABV_bm  0x02  /* Compare or Capture A Buffer Valid bit mask. */
#define TC1_CCABV_bp  1  /* Compare or Capture A Buffer Valid bit position. */
#define TC1_CCBBV_bm  0x04  /* Compare or Capture B Buffer Valid bit mask. */
#define TC1_CCBBV_bp  2  /* Compare or Capture B Buffer Valid bit position. */

/* TC1.CTRLGSET  bit masks and bit positions */
/* TC1_PERBV  is already defined. */
/* TC1_CCABV  is already defined. */
/* TC1_CCBBV  is already defined. */

/* TC1.INTFLAGS  bit masks and bit positions */
#define TC1_OVFIF_bm  0x01  /* Overflow Interrupt Flag bit mask. */
#define TC1_OVFIF_bp  0  /* Overflow Interrupt Flag bit position. */
#define TC1_ERRIF_bm  0x02  /* Error Interrupt Flag bit mask. */
#define TC1_ERRIF_bp  1  /* Error Interrupt Flag bit position. */
#define TC1_CCAIF_bm  0x10  /* Compare or Capture A Interrupt Flag bit mask. */
#define TC1_CCAIF_bp  4  /* Compare or Capture A Interrupt Flag bit position. */
#define TC1_CCBIF_bm  0x20  /* Compare or Capture B Interrupt Flag bit mask. */
#define TC1_CCBIF_bp  5  /* Compare or Capture B Interrupt Flag bit position. */









/* TWI - Two-Wire Interface */
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
#define TWI_MASTER_TIMEOUT_gm  0x0C  /* Inactive Bus timeout group mask. */
#define TWI_MASTER_TIMEOUT_gp  2  /* Inactive Bus timeout group position. */
#define TWI_MASTER_TIMEOUT0_bm  (1<<2)  /* Inactive Bus timeout bit 0 mask. */
#define TWI_MASTER_TIMEOUT0_bp  2  /* Inactive Bus timeout bit 0 position. */
#define TWI_MASTER_TIMEOUT1_bm  (1<<3)  /* Inactive Bus timeout bit 1 mask. */
#define TWI_MASTER_TIMEOUT1_bp  3  /* Inactive Bus timeout bit 1 position. */

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

/* TWI.CTRL  bit masks and bit positions */
#define TWI_EDIEN_bm  0x01  /* External Driver Interface Enable bit mask. */
#define TWI_EDIEN_bp  0  /* External Driver Interface Enable bit position. */
#define TWI_SDAHOLD_gm  0x06  /* SDA Hold Time Enable group mask. */
#define TWI_SDAHOLD_gp  1  /* SDA Hold Time Enable group position. */
#define TWI_SDAHOLD0_bm  (1<<1)  /* SDA Hold Time Enable bit 0 mask. */
#define TWI_SDAHOLD0_bp  1  /* SDA Hold Time Enable bit 0 position. */
#define TWI_SDAHOLD1_bm  (1<<2)  /* SDA Hold Time Enable bit 1 mask. */
#define TWI_SDAHOLD1_bp  2  /* SDA Hold Time Enable bit 1 position. */


/* USART - Universal Asynchronous Receiver-Transmitter */
/* USART.STATUS  bit masks and bit positions */
#define USART_RXB8_bm  0x01  /* Receive Bit 8 bit mask. */
#define USART_RXB8_bp  0  /* Receive Bit 8 bit position. */
#define USART_PERR_bm  0x04  /* Parity Error bit mask. */
#define USART_PERR_bp  2  /* Parity Error bit position. */
#define USART_BUFOVF_bm  0x08  /* Buffer Overflow bit mask. */
#define USART_BUFOVF_bp  3  /* Buffer Overflow bit position. */
#define USART_FERR_bm  0x10  /* Frame Error bit mask. */
#define USART_FERR_bp  4  /* Frame Error bit position. */
#define USART_DREIF_bm  0x20  /* Data Register Empty Flag bit mask. */
#define USART_DREIF_bp  5  /* Data Register Empty Flag bit position. */
#define USART_TXCIF_bm  0x40  /* Transmit Interrupt Flag bit mask. */
#define USART_TXCIF_bp  6  /* Transmit Interrupt Flag bit position. */
#define USART_RXCIF_bm  0x80  /* Receive Interrupt Flag bit mask. */
#define USART_RXCIF_bp  7  /* Receive Interrupt Flag bit position. */

/* USART.CTRLA  bit masks and bit positions */
#define USART_DREINTLVL_gm  0x03  /* Data Register Empty Interrupt Level group mask. */
#define USART_DREINTLVL_gp  0  /* Data Register Empty Interrupt Level group position. */
#define USART_DREINTLVL0_bm  (1<<0)  /* Data Register Empty Interrupt Level bit 0 mask. */
#define USART_DREINTLVL0_bp  0  /* Data Register Empty Interrupt Level bit 0 position. */
#define USART_DREINTLVL1_bm  (1<<1)  /* Data Register Empty Interrupt Level bit 1 mask. */
#define USART_DREINTLVL1_bp  1  /* Data Register Empty Interrupt Level bit 1 position. */
#define USART_TXCINTLVL_gm  0x0C  /* Transmit Interrupt Level group mask. */
#define USART_TXCINTLVL_gp  2  /* Transmit Interrupt Level group position. */
#define USART_TXCINTLVL0_bm  (1<<2)  /* Transmit Interrupt Level bit 0 mask. */
#define USART_TXCINTLVL0_bp  2  /* Transmit Interrupt Level bit 0 position. */
#define USART_TXCINTLVL1_bm  (1<<3)  /* Transmit Interrupt Level bit 1 mask. */
#define USART_TXCINTLVL1_bp  3  /* Transmit Interrupt Level bit 1 position. */
#define USART_RXCINTLVL_gm  0x30  /* Receive Interrupt Level group mask. */
#define USART_RXCINTLVL_gp  4  /* Receive Interrupt Level group position. */
#define USART_RXCINTLVL0_bm  (1<<4)  /* Receive Interrupt Level bit 0 mask. */
#define USART_RXCINTLVL0_bp  4  /* Receive Interrupt Level bit 0 position. */
#define USART_RXCINTLVL1_bm  (1<<5)  /* Receive Interrupt Level bit 1 mask. */
#define USART_RXCINTLVL1_bp  5  /* Receive Interrupt Level bit 1 position. */

/* USART.CTRLB  bit masks and bit positions */
#define USART_TXB8_bm  0x01  /* Transmit bit 8 bit mask. */
#define USART_TXB8_bp  0  /* Transmit bit 8 bit position. */
#define USART_MPCM_bm  0x02  /* Multi-processor Communication Mode bit mask. */
#define USART_MPCM_bp  1  /* Multi-processor Communication Mode bit position. */
#define USART_CLK2X_bm  0x04  /* Double transmission speed bit mask. */
#define USART_CLK2X_bp  2  /* Double transmission speed bit position. */
#define USART_TXEN_bm  0x08  /* Transmitter Enable bit mask. */
#define USART_TXEN_bp  3  /* Transmitter Enable bit position. */
#define USART_RXEN_bm  0x10  /* Receiver Enable bit mask. */
#define USART_RXEN_bp  4  /* Receiver Enable bit position. */

/* USART.CTRLC  bit masks and bit positions */
#define USART_UCPHA_bm  0x02  /* SPI Master Mode, Clock Phase bit mask. */
#define USART_UCPHA_bp  1  /* SPI Master Mode, Clock Phase bit position. */
#define USART_UDORD_bm  0x04  /* SPI Master Mode, Data Order bit mask. */
#define USART_UDORD_bp  2  /* SPI Master Mode, Data Order bit position. */
#define USART_CHSIZE_gm  0x07  /* Character Size group mask. */
#define USART_CHSIZE_gp  0  /* Character Size group position. */
#define USART_CHSIZE0_bm  (1<<0)  /* Character Size bit 0 mask. */
#define USART_CHSIZE0_bp  0  /* Character Size bit 0 position. */
#define USART_CHSIZE1_bm  (1<<1)  /* Character Size bit 1 mask. */
#define USART_CHSIZE1_bp  1  /* Character Size bit 1 position. */
#define USART_CHSIZE2_bm  (1<<2)  /* Character Size bit 2 mask. */
#define USART_CHSIZE2_bp  2  /* Character Size bit 2 position. */
#define USART_SBMODE_bm  0x08  /* Stop Bit Mode bit mask. */
#define USART_SBMODE_bp  3  /* Stop Bit Mode bit position. */
#define USART_PMODE_gm  0x30  /* Parity Mode group mask. */
#define USART_PMODE_gp  4  /* Parity Mode group position. */
#define USART_PMODE0_bm  (1<<4)  /* Parity Mode bit 0 mask. */
#define USART_PMODE0_bp  4  /* Parity Mode bit 0 position. */
#define USART_PMODE1_bm  (1<<5)  /* Parity Mode bit 1 mask. */
#define USART_PMODE1_bp  5  /* Parity Mode bit 1 position. */
#define USART_CMODE_gm  0xC0  /* Communication Mode group mask. */
#define USART_CMODE_gp  6  /* Communication Mode group position. */
#define USART_CMODE0_bm  (1<<6)  /* Communication Mode bit 0 mask. */
#define USART_CMODE0_bp  6  /* Communication Mode bit 0 position. */
#define USART_CMODE1_bm  (1<<7)  /* Communication Mode bit 1 mask. */
#define USART_CMODE1_bp  7  /* Communication Mode bit 1 position. */

/* USART.BAUDCTRLA  bit masks and bit positions */
#define USART_BSEL_gm  0xFF  /* Baud Rate Selection Bits [7:0] group mask. */
#define USART_BSEL_gp  0  /* Baud Rate Selection Bits [7:0] group position. */
#define USART_BSEL0_bm  (1<<0)  /* Baud Rate Selection Bits [7:0] bit 0 mask. */
#define USART_BSEL0_bp  0  /* Baud Rate Selection Bits [7:0] bit 0 position. */
#define USART_BSEL1_bm  (1<<1)  /* Baud Rate Selection Bits [7:0] bit 1 mask. */
#define USART_BSEL1_bp  1  /* Baud Rate Selection Bits [7:0] bit 1 position. */
#define USART_BSEL2_bm  (1<<2)  /* Baud Rate Selection Bits [7:0] bit 2 mask. */
#define USART_BSEL2_bp  2  /* Baud Rate Selection Bits [7:0] bit 2 position. */
#define USART_BSEL3_bm  (1<<3)  /* Baud Rate Selection Bits [7:0] bit 3 mask. */
#define USART_BSEL3_bp  3  /* Baud Rate Selection Bits [7:0] bit 3 position. */
#define USART_BSEL4_bm  (1<<4)  /* Baud Rate Selection Bits [7:0] bit 4 mask. */
#define USART_BSEL4_bp  4  /* Baud Rate Selection Bits [7:0] bit 4 position. */
#define USART_BSEL5_bm  (1<<5)  /* Baud Rate Selection Bits [7:0] bit 5 mask. */
#define USART_BSEL5_bp  5  /* Baud Rate Selection Bits [7:0] bit 5 position. */
#define USART_BSEL6_bm  (1<<6)  /* Baud Rate Selection Bits [7:0] bit 6 mask. */
#define USART_BSEL6_bp  6  /* Baud Rate Selection Bits [7:0] bit 6 position. */
#define USART_BSEL7_bm  (1<<7)  /* Baud Rate Selection Bits [7:0] bit 7 mask. */
#define USART_BSEL7_bp  7  /* Baud Rate Selection Bits [7:0] bit 7 position. */

/* USART.BAUDCTRLB  bit masks and bit positions */
/* USART_BSEL  is already defined. */
#define USART_BSCALE_gm  0xF0  /* Baud Rate Scale group mask. */
#define USART_BSCALE_gp  4  /* Baud Rate Scale group position. */
#define USART_BSCALE0_bm  (1<<4)  /* Baud Rate Scale bit 0 mask. */
#define USART_BSCALE0_bp  4  /* Baud Rate Scale bit 0 position. */
#define USART_BSCALE1_bm  (1<<5)  /* Baud Rate Scale bit 1 mask. */
#define USART_BSCALE1_bp  5  /* Baud Rate Scale bit 1 position. */
#define USART_BSCALE2_bm  (1<<6)  /* Baud Rate Scale bit 2 mask. */
#define USART_BSCALE2_bp  6  /* Baud Rate Scale bit 2 position. */
#define USART_BSCALE3_bm  (1<<7)  /* Baud Rate Scale bit 3 mask. */
#define USART_BSCALE3_bp  7  /* Baud Rate Scale bit 3 position. */

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

/* PORTC interrupt vectors */
#define PORTC_INT0_vect_num  1
#define PORTC_INT0_vect      _VECTOR(1)  /* External Interrupt 0 */
#define PORTC_INT1_vect_num  2
#define PORTC_INT1_vect      _VECTOR(2)  /* External Interrupt 1 */

/* RTC interrupt vectors */
#define RTC_OVF_vect_num  3
#define RTC_OVF_vect      _VECTOR(3)  /* Overflow Interrupt */
#define RTC_COMP_vect_num  4
#define RTC_COMP_vect      _VECTOR(4)  /* Compare Interrupt */

/* TWIC interrupt vectors */
#define TWIC_TWIS_vect_num  5
#define TWIC_TWIS_vect      _VECTOR(5)  /* TWI Slave Interrupt */
#define TWIC_TWIM_vect_num  6
#define TWIC_TWIM_vect      _VECTOR(6)  /* TWI Master Interrupt */

/* TCC0 interrupt vectors */
#define TCC0_OVF_vect_num  7
#define TCC0_OVF_vect      _VECTOR(7)  /* Overflow Interrupt */
#define TCC0_ERR_vect_num  8
#define TCC0_ERR_vect      _VECTOR(8)  /* Error Interrupt */
#define TCC0_CCA_vect_num  9
#define TCC0_CCA_vect      _VECTOR(9)  /* Compare or Capture A Interrupt */
#define TCC0_CCB_vect_num  10
#define TCC0_CCB_vect      _VECTOR(10)  /* Compare or Capture B Interrupt */
#define TCC0_CCC_vect_num  11
#define TCC0_CCC_vect      _VECTOR(11)  /* Compare or Capture C Interrupt */
#define TCC0_CCD_vect_num  12
#define TCC0_CCD_vect      _VECTOR(12)  /* Compare or Capture D Interrupt */

/* TCC1 interrupt vectors */
#define TCC1_OVF_vect_num  13
#define TCC1_OVF_vect      _VECTOR(13)  /* Overflow Interrupt */
#define TCC1_ERR_vect_num  14
#define TCC1_ERR_vect      _VECTOR(14)  /* Error Interrupt */
#define TCC1_CCA_vect_num  15
#define TCC1_CCA_vect      _VECTOR(15)  /* Compare or Capture A Interrupt */
#define TCC1_CCB_vect_num  16
#define TCC1_CCB_vect      _VECTOR(16)  /* Compare or Capture B Interrupt */

/* SPIC interrupt vectors */
#define SPIC_INT_vect_num  17
#define SPIC_INT_vect      _VECTOR(17)  /* SPI Interrupt */

/* USARTC0 interrupt vectors */
#define USARTC0_RXC_vect_num  18
#define USARTC0_RXC_vect      _VECTOR(18)  /* Reception Complete Interrupt */
#define USARTC0_DRE_vect_num  19
#define USARTC0_DRE_vect      _VECTOR(19)  /* Data Register Empty Interrupt */
#define USARTC0_TXC_vect_num  20
#define USARTC0_TXC_vect      _VECTOR(20)  /* Transmission Complete Interrupt */

/* CTE interrupt vectors */
#define CTE_MS0_vect_num  24
#define CTE_MS0_vect      _VECTOR(24)  /* uSequencer 0 Interrupt */
#define CTE_MS1_vect_num  25
#define CTE_MS1_vect      _VECTOR(25)  /* uSequencer 1 Interrupt */

/* NVM interrupt vectors */
#define NVM_SPM_vect_num  28
#define NVM_SPM_vect      _VECTOR(28)  /* SPM Interrupt */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (29 * _VECTOR_SIZE)


/* ========== Constants ========== */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_START     (0x0000)
#  define PROGMEM_SIZE      (53248)
#else
#  define PROGMEM_START     (0x0000U)
#  define PROGMEM_SIZE      (53248U)
#endif
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define APP_SECTION_START     (0x0000)
#  define APP_SECTION_SIZE      (49152)
#  define APP_SECTION_PAGE_SIZE (256)
#else
#  define APP_SECTION_START     (0x0000U)
#  define APP_SECTION_SIZE      (49152U)
#  define APP_SECTION_PAGE_SIZE (256U)
#endif
#define APP_SECTION_END       (APP_SECTION_START + APP_SECTION_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define APPTABLE_SECTION_START     (0xB000)
#  define APPTABLE_SECTION_SIZE      (4096)
#  define APPTABLE_SECTION_PAGE_SIZE (256)
#else
#  define APPTABLE_SECTION_START     (0xB000U)
#  define APPTABLE_SECTION_SIZE      (4096U)
#  define APPTABLE_SECTION_PAGE_SIZE (256U)
#endif
#define APPTABLE_SECTION_END       (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define BOOT_SECTION_START     (0xC000)
#  define BOOT_SECTION_SIZE      (4096)
#  define BOOT_SECTION_PAGE_SIZE (256)
#else
#  define BOOT_SECTION_START     (0xC000U)
#  define BOOT_SECTION_SIZE      (4096U)
#  define BOOT_SECTION_PAGE_SIZE (256U)
#endif
#define BOOT_SECTION_END       (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define DATAMEM_START     (0x0000)
#  define DATAMEM_SIZE      (14336)
#else
#  define DATAMEM_START     (0x0000U)
#  define DATAMEM_SIZE      (14336U)
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
#  define INTERNAL_SRAM_SIZE      (22528)
#  define INTERNAL_SRAM_PAGE_SIZE (0)
#else
#  define INTERNAL_SRAM_START     (0x2000U)
#  define INTERNAL_SRAM_SIZE      (22528U)
#  define INTERNAL_SRAM_PAGE_SIZE (0U)
#endif
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CPU_RAM_START     (0x2000)
#  define CPU_RAM_SIZE      (4096)
#  define CPU_RAM_PAGE_SIZE (0)
#else
#  define CPU_RAM_START     (0x2000U)
#  define CPU_RAM_SIZE      (4096U)
#  define CPU_RAM_PAGE_SIZE (0U)
#endif
#define CPU_RAM_END       (CPU_RAM_START + CPU_RAM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_IO_START     (0x3000)
#  define CTE_IO_SIZE      (1536)
#  define CTE_IO_PAGE_SIZE (0)
#else
#  define CTE_IO_START     (0x3000U)
#  define CTE_IO_SIZE      (1536U)
#  define CTE_IO_PAGE_SIZE (0U)
#endif
#define CTE_IO_END       (CTE_IO_START + CTE_IO_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_D0_START     (0x3800)
#  define CTE_D0_SIZE      (1024)
#  define CTE_D0_PAGE_SIZE (0)
#else
#  define CTE_D0_START     (0x3800U)
#  define CTE_D0_SIZE      (1024U)
#  define CTE_D0_PAGE_SIZE (0U)
#endif
#define CTE_D0_END       (CTE_D0_START + CTE_D0_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_I1_START     (0x4000)
#  define CTE_I1_SIZE      (2048)
#  define CTE_I1_PAGE_SIZE (0)
#else
#  define CTE_I1_START     (0x4000U)
#  define CTE_I1_SIZE      (2048U)
#  define CTE_I1_PAGE_SIZE (0U)
#endif
#define CTE_I1_END       (CTE_I1_START + CTE_I1_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_D1_START     (0x6000)
#  define CTE_D1_SIZE      (4096)
#  define CTE_D1_PAGE_SIZE (0)
#else
#  define CTE_D1_START     (0x6000U)
#  define CTE_D1_SIZE      (4096U)
#  define CTE_D1_PAGE_SIZE (0U)
#endif
#define CTE_D1_END       (CTE_D1_START + CTE_D1_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_D2_START     (0x7000)
#  define CTE_D2_SIZE      (2048)
#  define CTE_D2_PAGE_SIZE (0)
#else
#  define CTE_D2_START     (0x7000U)
#  define CTE_D2_SIZE      (2048U)
#  define CTE_D2_PAGE_SIZE (0U)
#endif
#define CTE_D2_END       (CTE_D2_START + CTE_D2_SIZE - 1)

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
#  define FUSES_SIZE      (6)
#  define FUSES_PAGE_SIZE (0)
#else
#  define FUSES_START     (0x0000U)
#  define FUSES_SIZE      (6U)
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
#  define USER_SIGNATURES_SIZE      (256)
#  define USER_SIGNATURES_PAGE_SIZE (256)
#else
#  define USER_SIGNATURES_START     (0x0000U)
#  define USER_SIGNATURES_SIZE      (256U)
#  define USER_SIGNATURES_PAGE_SIZE (256U)
#endif
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROD_SIGNATURES_START     (0x0000)
#  define PROD_SIGNATURES_SIZE      (256)
#  define PROD_SIGNATURES_PAGE_SIZE (256)
#else
#  define PROD_SIGNATURES_START     (0x0000U)
#  define PROD_SIGNATURES_SIZE      (256U)
#  define PROD_SIGNATURES_PAGE_SIZE (256U)
#endif
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SPM_PAGESIZE 256
#else
#  define SPM_PAGESIZE 256U
#endif
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END


/* ========== Fuses ========== */
#define FUSE_MEMORY_SIZE 6

/* Fuse Byte 0 Reserved */

/* Fuse Byte 1 Reserved */

/* Fuse Byte 2 Reserved */

/* Fuse Byte 3 Reserved */

/* Fuse Byte 4 (FUSEBYTE4) */
#define FUSE_WDLOCK  (unsigned char)~_BV(1)  /* Watchdog Timer Lock */
#define FUSE_SUT0  (unsigned char)~_BV(2)  /* Start-up Time Bit 0 */
#define FUSE_SUT1  (unsigned char)~_BV(3)  /* Start-up Time Bit 1 */
#define FUSE_RSTDISBL  (unsigned char)~_BV(4)  /* Reset Disable */
#define FUSE4_DEFAULT  (0xFF)
#define FUSE_FUSEBYTE4_DEFAULT  (0xFF)

/* Fuse Byte 5 (FUSEBYTE5) */
#define FUSE_BODLVL0  (unsigned char)~_BV(0)  /* Brownout Detection Voltage Level Bit 0 */
#define FUSE_BODLVL1  (unsigned char)~_BV(1)  /* Brownout Detection Voltage Level Bit 1 */
#define FUSE_BODLVL2  (unsigned char)~_BV(2)  /* Brownout Detection Voltage Level Bit 2 */
#define FUSE_BODACT0  (unsigned char)~_BV(4)  /* BOD Operation in Active Mode Bit 0 */
#define FUSE_BODACT1  (unsigned char)~_BV(5)  /* BOD Operation in Active Mode Bit 1 */
#define FUSE_BGCALSEL0  (unsigned char)~_BV(6)  /* Bandgap Calibration Select Bit 0 */
#define FUSE_BGCALSEL1  (unsigned char)~_BV(7)  /* Bandgap Calibration Select Bit 1 */
#define FUSE5_DEFAULT  (0xFF)
#define FUSE_FUSEBYTE5_DEFAULT  (0xFF)

/* ========== Lock Bits ========== */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_APPLICATION_TABLE_BITS_EXIST
#define __BOOT_LOCK_APPLICATION_BITS_EXIST
#define __BOOT_LOCK_BOOT_BITS_EXIST

/* ========== Signature ========== */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x95
#define SIGNATURE_2 0x48

/* ========== Power Reduction Condition Definitions ========== */

/* PR.PRGEN */
#define __AVR_HAVE_PRGEN	(PR_CTM_bm|PR_AES_bm|PR_EBI_bm|PR_RTC_bm|PR_EVSYS_bm|PR_DMA_bm)
#define __AVR_HAVE_PRGEN_CTM
#define __AVR_HAVE_PRGEN_AES
#define __AVR_HAVE_PRGEN_EBI
#define __AVR_HAVE_PRGEN_RTC
#define __AVR_HAVE_PRGEN_EVSYS
#define __AVR_HAVE_PRGEN_DMA

/* PR.PRPA */
#define __AVR_HAVE_PRPA	(PR_DAC_bm|PR_ADC_bm|PR_AC_bm)
#define __AVR_HAVE_PRPA_DAC
#define __AVR_HAVE_PRPA_ADC
#define __AVR_HAVE_PRPA_AC

/* PR.PRPB */
#define __AVR_HAVE_PRPB	(PR_DAC_bm|PR_ADC_bm|PR_AC_bm)
#define __AVR_HAVE_PRPB_DAC
#define __AVR_HAVE_PRPB_ADC
#define __AVR_HAVE_PRPB_AC

/* PR.PRPC */
#define __AVR_HAVE_PRPC	(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm)
#define __AVR_HAVE_PRPC_TWI
#define __AVR_HAVE_PRPC_USART1
#define __AVR_HAVE_PRPC_USART0
#define __AVR_HAVE_PRPC_SPI
#define __AVR_HAVE_PRPC_HIRES
#define __AVR_HAVE_PRPC_TC1
#define __AVR_HAVE_PRPC_TC0

/* PR.PRPD */
#define __AVR_HAVE_PRPD	(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm)
#define __AVR_HAVE_PRPD_TWI
#define __AVR_HAVE_PRPD_USART1
#define __AVR_HAVE_PRPD_USART0
#define __AVR_HAVE_PRPD_SPI
#define __AVR_HAVE_PRPD_HIRES
#define __AVR_HAVE_PRPD_TC1
#define __AVR_HAVE_PRPD_TC0

/* PR.PRPE */
#define __AVR_HAVE_PRPE	(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm)
#define __AVR_HAVE_PRPE_TWI
#define __AVR_HAVE_PRPE_USART1
#define __AVR_HAVE_PRPE_USART0
#define __AVR_HAVE_PRPE_SPI
#define __AVR_HAVE_PRPE_HIRES
#define __AVR_HAVE_PRPE_TC1
#define __AVR_HAVE_PRPE_TC0

/* PR.PRPF */
#define __AVR_HAVE_PRPF	(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm)
#define __AVR_HAVE_PRPF_TWI
#define __AVR_HAVE_PRPF_USART1
#define __AVR_HAVE_PRPF_USART0
#define __AVR_HAVE_PRPF_SPI
#define __AVR_HAVE_PRPF_HIRES
#define __AVR_HAVE_PRPF_TC1
#define __AVR_HAVE_PRPF_TC0


#endif /* #ifdef _AVR_ATMXT336S_H_INCLUDED */

