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
#  define _AVR_IOXXX_H_ "iomxt540sreva.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_ATMXT540SREVA_H_INCLUDED
#define _AVR_ATMXT540SREVA_H_INCLUDED

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
    register8_t PWRCRVDDIO;  /* VDDIO Power Control Register */
    register8_t PWRSRVDDIO;  /* VDDIO Power Status Register */
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
    CLK_SCLKSEL_RC32M_gc = (0x01<<0),  /* Internal 32MHz RC Oscillator */
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

/* CTE Micro Sequencer */
typedef struct CTEMS_struct
{
    _WORDREGISTER(MSACCAL);  /* MS Accumulator A Low Register */
    _WORDREGISTER(MSACCAH);  /* MS Accumulator A High Register */
    _WORDREGISTER(MSACCBL);  /* MS Accumulator B Low Register (only for MS1) */
    _WORDREGISTER(MSACCBH);  /* MS Accumulator B High Register (only for MS1) */
    _WORDREGISTER(MSACCCNTA);  /* MS Accumulator Counter A Register */
    _WORDREGISTER(MSACCCNTB);  /* MS Accumulator Counter B Register (only for MS1) */
    _WORDREGISTER(MSMAXA);  /* MS Max A */
    _WORDREGISTER(MSMAXB);  /* MS Max B */
    _WORDREGISTER(MSMINA);  /* MS Min A */
    _WORDREGISTER(MSMINB);  /* MS Min B */
    _WORDREGISTER(MSSHIFTRA);  /* MS Shift Register A */
    _WORDREGISTER(MSSHIFTRB);  /* MS Shift Register B (only for MS1) */
    _WORDREGISTER(MSACCSR);  /* MS Accumulator Status Register */
    _WORDREGISTER(MSCRCCLR);  /* MS Control Register C Clear */
    _WORDREGISTER(MSCRCSET);  /* MS Control Register C Set */
    register8_t reserved_1[66];
    _WORDREGISTER(MSCRA);  /* MS Control Register A */
    _WORDREGISTER(MSCRB);  /* MS Control Register B (T/C control) */
    register8_t reserved_2[4];
    _WORDREGISTER(MSSRACLR);  /* MS Status Register A Clear */
    _WORDREGISTER(MSSRASET);  /* MS Status Register A Set */
    _WORDREGISTER(MSSRB);  /* MS Status (Read only) Register B */
    _WORDREGISTER(MSSRC);  /* MS Status (Read only) Register C */
    _WORDREGISTER(MSSRD);  /* MS Status (Read only) Register D */
    _WORDREGISTER(MSSRE);  /* MS Status (Read only) Register E */
    _WORDREGISTER(MSCCR);  /* MS Condition Code Register */
    register8_t reserved_3[4];
    _WORDREGISTER(MSLINK);  /* MS Link Register */
    register8_t reserved_4[4];
} CTEMS_t;


/* CTE Module */
typedef struct CTE_struct
{
    _WORDREGISTER(ADCYCHR);  /* ADC Y Channel Register */
    _WORDREGISTER(INTCRC);  /* Integrator Control Register C */
    _WORDREGISTER(ADCSRACLR);  /* ADC Status Register A Clear */
    _WORDREGISTER(ADCSRASET);  /* ADC Status Register A Set */
    _WORDREGISTER(INTCRBCLR);  /* Integrator Control Register B Clear */
    _WORDREGISTER(INTCRBSET);  /* Integrator Control Register B Set */
    _WORDREGISTER(INTCRECLR);  /* Integrator Control Register E Clear */
    _WORDREGISTER(INTCRESET);  /* Integrator Control Register E Set */
    _WORDREGISTER(INTXCHR);  /* Integrator X Channel Register */
    _WORDREGISTER(INTOENA);  /* Integrator Output Enable A */
    _WORDREGISTER(INTOENB);  /* Integrator Output Enable B */
    _WORDREGISTER(TIMMOECMP);  /* Timer Master Output Enable Compare */
    _WORDREGISTER(HVCRA);  /* High Voltage Control Register A */
    _WORDREGISTER(TIMAPER);  /* Timer A Period Register */
    _WORDREGISTER(TIMBPER);  /* Timer B Period Register */
    _WORDREGISTER(TIMCPER);  /* Timer C Period Register */
    _WORDREGISTER(TIMMOEPER);  /* Timer Master Output Enable Period Register */
    _WORDREGISTER(TIMRSTPER);  /* Timer Reset Period Register */
    _WORDREGISTER(INTDONE);  /* Integrator Done */
    _WORDREGISTER(INTTRIGA);  /* Integrator Trigger Register A */
    _WORDREGISTER(INTTRIGB);  /* Integrator Trigger Register B */
    register8_t reserved_1[2];
    _WORDREGISTER(INTCRFCLR);  /* Integrator Control Register F Clear */
    _WORDREGISTER(INTCRFSET);  /* Integrator Control Register F Set */
    _WORDREGISTER(GCAFSRA);  /* GCAF Status Register A. */
    _WORDREGISTER(GCAFHDLCNT);  /* GCAF Headroom detector Low Counter */
    _WORDREGISTER(GCAFHDHCNT);  /* GCAF Headroom detector High Counter */
    _WORDREGISTER(GCAFCCCLIM);  /* GCAF Computation Complete Counter Limit. */
    _WORDREGISTER(PIFXPORTA);  /* Port Interface X-lines PORT, 0-15 */
    _WORDREGISTER(PIFXPORTB);  /* Port Interface X-lines PORT, 16-30 */
    _WORDREGISTER(PIFYPORTA);  /* Port Interface Y-lines PORT, 0-15 */
    _WORDREGISTER(PIFYPORTB);  /* Port Interface Y-lines PORT, 16-18 */
    _WORDREGISTER(PIFXDDRA);  /* Port Interface X-lines DDR, 0-15 */
    _WORDREGISTER(PIFXDDRB);  /* Port Interface X-lines DDR, 16-30 */
    _WORDREGISTER(PIFYDDRA);  /* Port Interface Y-lines DDR, 0-15 */
    _WORDREGISTER(PIFYDDRB);  /* Port Interface Y-lines DDR, 16-18 */
    _WORDREGISTER(PIFXTGLA);  /* Port Interface X-lines Toggle, 0-15 */
    _WORDREGISTER(PIFXTGLB);  /* Port Interface X-lines Toggle, 16-30 */
    _WORDREGISTER(PIFYTGLA);  /* Port Interface Y-lines Toggle, 0-15 */
    _WORDREGISTER(PIFYTGLB);  /* Port Interface Y-lines Toggle, 16-18 */
    _WORDREGISTER(PIFILA);  /* Interleave register access [15:0] (A) */
    _WORDREGISTER(PIFILB);  /* Interleave register access [31:16] (B) */
    _WORDREGISTER(PIFILE);  /* Interleave register access [30, 28, ..., 0] (Even) */
    _WORDREGISTER(PIFILO);  /* Interleave register access [31, 29, ..., 1] (Odd) */
    register8_t reserved_2[40];
    _WORDREGISTER(ADCCRA);  /* ADC Control Register A */
    _WORDREGISTER(ADCCRB);  /* ADC Control Register B */
    _WORDREGISTER(ADCINTCAL);  /* ADC and Integrator Calibration Register */
    _WORDREGISTER(ADCRES);  /* ADC Result Register */
    _WORDREGISTER(ADCINTTEST);  /* ADC Integrator Test Register */
    _WORDREGISTER(ADCSHVBCAL);  /* ADC and SH */
    _WORDREGISTER(INTCRA);  /* Integrator Control Register A */
    _WORDREGISTER(INTCRD);  /* Integrator Control Register D */
    _WORDREGISTER(INTENA);  /* Integrator Enable Register A */
    _WORDREGISTER(INTENB);  /* Integrator Enable Register B */
    _WORDREGISTER(INTMASKENA);  /* Integrator Mask Enable Register A */
    _WORDREGISTER(INTMASKENB);  /* Integrator Mask Enable Register B */
    _WORDREGISTER(SHENA);  /* Sample-and-Hold Enable Register A */
    _WORDREGISTER(SHENB);  /* Sample-and-Hold Enable Register B */
    _WORDREGISTER(BIASCR);  /* Bias Control Register */
    _WORDREGISTER(HVSEQT);  /* High Voltage Sequencer Timing */
    _WORDREGISTER(INTXCHMAX);  /* Maximum X-channel Number */
    register8_t reserved_3[12];
    _WORDREGISTER(INTCAPRSTCR);  /* Integrator Cap Reset Control Register */
    _WORDREGISTER(INTGAIN0);  /* Integrator Gain Register 0 */
    _WORDREGISTER(INTGAIN1);  /* Integrator Gain Register 1 */
    _WORDREGISTER(INTGAIN2);  /* Integrator Gain Register 2 */
    _WORDREGISTER(INTGAIN3);  /* Integrator Gain Register 3 */
    _WORDREGISTER(INTGAIN4);  /* Integrator Gain Register 4 */
    register8_t reserved_4[6];
    _WORDREGISTER(TIMACMP);  /* Timer A Compare Register */
    _WORDREGISTER(TIMBCMP);  /* Timer B Compare Register */
    _WORDREGISTER(PADYCHCOMPA);  /* Enable the selfcap current source at pad_ichargecomp A */
    _WORDREGISTER(PADYCHCOMPB);  /* Enable the selfcap current source at pad_ichargecomp B */
    _WORDREGISTER(PADBNY1);  /* Pad bn y1 */
    _WORDREGISTER(PADBPY1);  /* Pad bp y1 */
    _WORDREGISTER(PADY1);  /* Enable [n/p]mos and extra[n/p] y1 */
    _WORDREGISTER(XYBIAS);  /* XY line bias control */
    _WORDREGISTER(PADSCOEXA);  /* Pad Self Cap Output Enable X A */
    _WORDREGISTER(PADSCOEXB);  /* Pad Self Cap Output Enable X B */
    _WORDREGISTER(PADSCOEYA);  /* Pad Self Cap Output Enable Y A */
    _WORDREGISTER(PADSCOEYB);  /* Pad Self Cap Output Enable Y B */
    _WORDREGISTER(PADYONXENA);  /* Pad YonX Enable A */
    _WORDREGISTER(PADYONXENB);  /* Pad YonX Enable B */
    _WORDREGISTER(PADXONXENA);  /* Pad XonX Enable A */
    _WORDREGISTER(PADXONXENB);  /* Pad XonX Enable B */
    _WORDREGISTER(PADYONYENA);  /* Pad YonY Enable A */
    _WORDREGISTER(PADYONYENB);  /* Pad YonY Enable B */
    _WORDREGISTER(PADPROXENXA);  /* Pad Proximity Enable X A */
    _WORDREGISTER(PADPROXENXB);  /* Pad Proximity Enable X B */
    _WORDREGISTER(PADPROXENYA);  /* Pad Proximity Enable Y A */
    _WORDREGISTER(PADPROXENYB);  /* Pad Proximity Enable Y B */
    _WORDREGISTER(PADXRSTA);  /* Pad X Reset A */
    _WORDREGISTER(PADXRSTB);  /* Pad X Reset B */
    _WORDREGISTER(PADXRESENA);  /* Pad xres Enable A */
    _WORDREGISTER(PADXRESENB);  /* Pad xres Enable B */
    _WORDREGISTER(PADYRESENA);  /* Pad yres Enable A */
    _WORDREGISTER(PADYRESENB);  /* Pad yres Enable B */
    _WORDREGISTER(PADSCICALENA);  /* Pad sc ical Enable A */
    _WORDREGISTER(PADSCICALENB);  /* Pad sc ical Enable B */
    _WORDREGISTER(PADINTENA);  /* Pad int Enable A */
    _WORDREGISTER(PADINTENB);  /* Pad int Enable B */
    _WORDREGISTER(PADSCX0);  /* Pad Self Cap Control Registers X 0 */
    _WORDREGISTER(PADSCX1);  /* Pad Self Cap Control Registers X 1 */
    _WORDREGISTER(PADSCX2);  /* Pad Self Cap Control Registers X 2 */
    _WORDREGISTER(PADSCX3);  /* Pad Self Cap Control Registers X 3 */
    _WORDREGISTER(PADSCX4);  /* Pad Self Cap Control Registers X 4 */
    _WORDREGISTER(PADSCX5);  /* Pad Self Cap Control Registers X 5 */
    _WORDREGISTER(PADSCX6);  /* Pad Self Cap Control Registers X 6 */
    _WORDREGISTER(PADSCX7);  /* Pad Self Cap Control Registers X 7 */
    _WORDREGISTER(PADSCX8);  /* Pad Self Cap Control Registers X 8 */
    _WORDREGISTER(PADSCX9);  /* Pad Self Cap Control Registers X 9 */
    _WORDREGISTER(PADSCX10);  /* Pad Self Cap Control Registers X 10 */
    _WORDREGISTER(PADSCX11);  /* Pad Self Cap Control Registers X 11 */
    _WORDREGISTER(PADSCX12);  /* Pad Self Cap Control Registers X 12 */
    _WORDREGISTER(PADSCX13);  /* Pad Self Cap Control Registers X 13 */
    _WORDREGISTER(PADSCX14);  /* Pad Self Cap Control Registers X 14 */
    _WORDREGISTER(PADSCX15);  /* Pad Self Cap Control Registers X 15 */
    _WORDREGISTER(PADSCX16);  /* Pad Self Cap Control Registers X 16 */
    _WORDREGISTER(PADSCX17);  /* Pad Self Cap Control Registers X 17 */
    _WORDREGISTER(PADSCX18);  /* Pad Self Cap Control Registers X 18 */
    _WORDREGISTER(PADSCX19);  /* Pad Self Cap Control Registers X 19 */
    _WORDREGISTER(PADSCX20);  /* Pad Self Cap Control Registers X 20 */
    _WORDREGISTER(PADSCX21);  /* Pad Self Cap Control Registers X 21 */
    _WORDREGISTER(PADSCX22);  /* Pad Self Cap Control Registers X 22 */
    _WORDREGISTER(PADSCX23);  /* Pad Self Cap Control Registers X 23 */
    _WORDREGISTER(PADSCX24);  /* Pad Self Cap Control Registers X 24 */
    _WORDREGISTER(PADSCX25);  /* Pad Self Cap Control Registers X 25 */
    _WORDREGISTER(PADSCX26);  /* Pad Self Cap Control Registers X 26 */
    _WORDREGISTER(PADSCX27);  /* Pad Self Cap Control Registers X 27 */
    _WORDREGISTER(PADSCX28);  /* Pad Self Cap Control Registers X 28 */
    _WORDREGISTER(PADSCX29);  /* Pad Self Cap Control Registers X 29 */
    _WORDREGISTER(PADSCX30);  /* Pad Self Cap Control Registers X 30 */
    _WORDREGISTER(PADSCX31);  /* Pad Self Cap Control Registers X 31 */
    _WORDREGISTER(PADSCX32);  /* Pad Self Cap Control Registers X 32 */
    _WORDREGISTER(PADSCX33);  /* Pad Self Cap Control Registers X 33 */
    _WORDREGISTER(PADSCX34);  /* Pad Self Cap Control Registers X 34 */
    _WORDREGISTER(PADSCX35);  /* Pad Self Cap Control Registers X 35 */
    _WORDREGISTER(PADSCX36);  /* Pad Self Cap Control Registers X 36 */
    _WORDREGISTER(PADSCX37);  /* Pad Self Cap Control Registers X 37 */
    _WORDREGISTER(PADSCX38);  /* Pad Self Cap Control Registers X 38 */
    _WORDREGISTER(PADSCX39);  /* Pad Self Cap Control Registers X 39 */
    _WORDREGISTER(PADSCX40);  /* Pad Self Cap Control Registers X 40 */
    _WORDREGISTER(PADSCX41);  /* Pad Self Cap Control Registers X 41 */
    _WORDREGISTER(PADSCX42);  /* Pad Self Cap Control Registers X 42 */
    _WORDREGISTER(PADSCX43);  /* Pad Self Cap Control Registers X 43 */
    _WORDREGISTER(PADSCX44);  /* Pad Self Cap Control Registers X 44 */
    _WORDREGISTER(PADSCX45);  /* Pad Self Cap Control Registers X 45 */
    _WORDREGISTER(PADSCX46);  /* Pad Self Cap Control Registers X 46 */
    _WORDREGISTER(PADSCX47);  /* Pad Self Cap Control Registers X 47 */
    _WORDREGISTER(PADSCX48);  /* Pad Self Cap Control Registers X 48 */
    _WORDREGISTER(PADSCX49);  /* Pad Self Cap Control Registers X 49 */
    _WORDREGISTER(PADSCX50);  /* Pad Self Cap Control Registers X 50 */
    _WORDREGISTER(PADSCX51);  /* Pad Self Cap Control Registers X 51 */
    _WORDREGISTER(PADSCX52);  /* Pad Self Cap Control Registers X 52 */
    _WORDREGISTER(PADSCX53);  /* Pad Self Cap Control Registers X 53 */
    _WORDREGISTER(PADSCX54);  /* Pad Self Cap Control Registers X 54 */
    _WORDREGISTER(PADSCX55);  /* Pad Self Cap Control Registers X 55 */
    _WORDREGISTER(PADSCX56);  /* Pad Self Cap Control Registers X 56 */
    _WORDREGISTER(PADSCX57);  /* Pad Self Cap Control Registers X 57 */
    _WORDREGISTER(PADSCX58);  /* Pad Self Cap Control Registers X 58 */
    _WORDREGISTER(PADSCX59);  /* Pad Self Cap Control Registers X 59 */
    register8_t reserved_5[8];
    _WORDREGISTER(PADSCY0);  /* Pad Self Cap Control Registers Y 0 */
    _WORDREGISTER(PADSCY1);  /* Pad Self Cap Control Registers Y 1 */
    _WORDREGISTER(PADSCY2);  /* Pad Self Cap Control Registers Y 2 */
    _WORDREGISTER(PADSCY3);  /* Pad Self Cap Control Registers Y 3 */
    _WORDREGISTER(PADSCY4);  /* Pad Self Cap Control Registers Y 4 */
    _WORDREGISTER(PADSCY5);  /* Pad Self Cap Control Registers Y 5 */
    _WORDREGISTER(PADSCY6);  /* Pad Self Cap Control Registers Y 6 */
    _WORDREGISTER(PADSCY7);  /* Pad Self Cap Control Registers Y 7 */
    _WORDREGISTER(PADSCY8);  /* Pad Self Cap Control Registers Y 8 */
    _WORDREGISTER(PADSCY9);  /* Pad Self Cap Control Registers Y 9 */
    _WORDREGISTER(PADSCY10);  /* Pad Self Cap Control Registers Y 10 */
    _WORDREGISTER(PADSCY11);  /* Pad Self Cap Control Registers Y 11 */
    _WORDREGISTER(PADSCY12);  /* Pad Self Cap Control Registers Y 12 */
    _WORDREGISTER(PADSCY13);  /* Pad Self Cap Control Registers Y 13 */
    _WORDREGISTER(PADSCY14);  /* Pad Self Cap Control Registers Y 14 */
    _WORDREGISTER(PADSCY15);  /* Pad Self Cap Control Registers Y 15 */
    _WORDREGISTER(PADSCY16);  /* Pad Self Cap Control Registers Y 16 */
    _WORDREGISTER(PADSCY17);  /* Pad Self Cap Control Registers Y 17 */
    _WORDREGISTER(PADSCY18);  /* Pad Self Cap Control Registers Y 18 */
    _WORDREGISTER(PADSCY19);  /* Pad Self Cap Control Registers Y 19 */
    _WORDREGISTER(PADSCY20);  /* Pad Self Cap Control Registers Y 20 */
    _WORDREGISTER(PADSCY21);  /* Pad Self Cap Control Registers Y 21 */
    _WORDREGISTER(PADSCY22);  /* Pad Self Cap Control Registers Y 22 */
    _WORDREGISTER(PADSCY23);  /* Pad Self Cap Control Registers Y 23 */
    _WORDREGISTER(PADSCY24);  /* Pad Self Cap Control Registers Y 24 */
    _WORDREGISTER(PADSCY25);  /* Pad Self Cap Control Registers Y 25 */
    _WORDREGISTER(PADSCY26);  /* Pad Self Cap Control Registers Y 26 */
    _WORDREGISTER(PADSCY27);  /* Pad Self Cap Control Registers Y 27 */
    _WORDREGISTER(PADSCY28);  /* Pad Self Cap Control Registers Y 28 */
    _WORDREGISTER(PADSCY29);  /* Pad Self Cap Control Registers Y 29 */
    _WORDREGISTER(PADSCY30);  /* Pad Self Cap Control Registers Y 30 */
    _WORDREGISTER(PADSCY31);  /* Pad Self Cap Control Registers Y 31 */
    _WORDREGISTER(PADSCY32);  /* Pad Self Cap Control Registers Y 32 */
    _WORDREGISTER(PADSCY33);  /* Pad Self Cap Control Registers Y 33 */
    _WORDREGISTER(PADSCY34);  /* Pad Self Cap Control Registers Y 34 */
    _WORDREGISTER(PADSCY35);  /* Pad Self Cap Control Registers Y 35 */
    register8_t reserved_6[8];
    _WORDREGISTER(PADHVSWENA);  /* Pad hvsw Enable A */
    _WORDREGISTER(PADHVSWENB);  /* Pad hvsw Enable B */
    _WORDREGISTER(PADBNX1);  /* Pad bn x1 */
    _WORDREGISTER(PADBPX1);  /* Pad bp x1 */
    _WORDREGISTER(PADX1);  /* Enable [n/p]mos and extra[n/p] x1 */
    _WORDREGISTER(PADBNX2);  /* Pad bn x2 */
    _WORDREGISTER(PADBPX2);  /* Pad bp x2 */
    _WORDREGISTER(PADX2);  /* Enable [n/p]mos and extra[n/p] x2 */
    _WORDREGISTER(PADSCTESTENA);  /* Pad Selfcap Test Enable A */
    _WORDREGISTER(PADSCTESTENB);  /* Pad Selfcap Test Enable B */
    register8_t reserved_7[28];
    _WORDREGISTER(GCAFCRA);  /* GCAF Control Register A. */
    _WORDREGISTER(GCAFCRB);  /* GCAF Control Register B. */
    _WORDREGISTER(GCAFMCENA);  /* GCAF Multi-cut enable A. */
    _WORDREGISTER(GCAFMCENB);  /* GCAF Multi-cut enable B. */
    _WORDREGISTER(GCAFBASELIM);  /* GCAF Base Address and Delta Limit. */
    _WORDREGISTER(GCAFPCLL);  /* GCAF Pre-cut lower limit. */
    _WORDREGISTER(GCAFPCUL);  /* GCAF Pre-cut upper limit. */
    _WORDREGISTER(GCAFWFCR);  /* GCAF Window Function Control Register */
    _WORDREGISTER(GCAFADCMIN);  /* GCAF Minimum ADC Result */
    _WORDREGISTER(GCAFADCMAX);  /* GCAF Maximum ADC Result */
    register8_t reserved_8[44];
    _WORDREGISTER(PIFXENA);  /* Port Interface X-line Enable, 0-15 */
    _WORDREGISTER(PIFXENB);  /* Port Interface X-line Enable, 16-30 */
    _WORDREGISTER(PIFYENA);  /* Port Interface Y-line Enable, 0-15 */
    _WORDREGISTER(PIFYENB);  /* Port Interface Y-line Enable, 16-18 */
    _WORDREGISTER(PIFXPINA);  /* Port Interface X-lines PIN, 0-15 */
    _WORDREGISTER(PIFXPINB);  /* Port Interface X-lines PIN, 16-30 */
    _WORDREGISTER(PIFYPINA);  /* Port Interface Y-lines PIN, 0-15 */
    _WORDREGISTER(PIFYPINB);  /* Port Interface Y-lines PIN, 16-18 */
    _WORDREGISTER(PIFXSRLA);  /* Port Interface X-line Slew Rate Limit Enable, 0-15 */
    _WORDREGISTER(PIFXSRLB);  /* Port Interface X-line Slew Rate Limit Enable, 16-30 */
    _WORDREGISTER(PIFYSRLA);  /* Port Interface Y-line Slew Rate Limit Enable, 0-15 */
    _WORDREGISTER(PIFYSRLB);  /* Port Interface Y-line Slew Rate Limit Enable, 16-18 */
    register8_t reserved_9[40];
    CTEMS_t MS0;  /* Micro sequencer 0 control registers */
    CTEMS_t MS1;  /* Micro sequencer 1 control registers */
    register8_t MS0PCL;  /* MS PC Low */
    register8_t MS0PCH;  /* MS PC High */
    register8_t MS0HIF;  /* MS Host Interface */
    register8_t reserved_10[1];
    register8_t MS0IR0;  /* MS Instruction Register 0 */
    register8_t MS0IR1;  /* MS Instruction Register 1 */
    register8_t MS0IR2;  /* MS Instruction Register 2 */
    register8_t MS0IR3;  /* MS Instruction Register 3 */
    register8_t MS0IRBUFL;  /* MS Instruction Register Buffer (low) */
    register8_t MS0IRBUFH;  /* MS Instruction Register Buffer (high) */
    register8_t MS0R0L;  /* MS R0 in register file (low) */
    register8_t MS0R0H;  /* MS R0 in register file (high) */
    register8_t MS0REPEATL;  /* MS Repeat Register (low) */
    register8_t MS0REPEATH;  /* MS Repeat Register (high) */
    register8_t reserved_11[2];
    register8_t MS1PCL;  /* MS PC Low */
    register8_t MS1PCH;  /* MS PC High */
    register8_t MS1HIF;  /* MS Host Interface */
    register8_t reserved_12[1];
    register8_t MS1IR0;  /* MS Instruction Register 0 */
    register8_t MS1IR1;  /* MS Instruction Register 1 */
    register8_t MS1IR2;  /* MS Instruction Register 2 */
    register8_t MS1IR3;  /* MS Instruction Register 3 */
    register8_t MS1IRBUFL;  /* MS Instruction Register Buffer (low) */
    register8_t MS1IRBUFH;  /* MS Instruction Register Buffer (high) */
    register8_t MS1R0L;  /* MS R0 in register file (low) */
    register8_t MS1R0H;  /* MS R0 in register file (high) */
    register8_t MS1REPEATL;  /* MS Repeat Register (low) */
    register8_t MS1REPEATH;  /* MS Repeat Register (high) */
    register8_t reserved_13[2];
    register8_t CTTEMP;  /* Temp register for 16-bit writes from CPU to uS */
    register8_t CTCRA;  /* CapTouch Control Register A */
    register8_t DMAPSCLR;  /* CapTouch Double Mapping register clr */
    register8_t DMAPSSET;  /* CapTouch Double Mapping register set */
    register8_t reserved_14[92];
} CTE_t;


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
    register8_t RC32MCALB;  /* RCOSC 32MHz Calibration Value B */
    register8_t RC32MCALA;  /* RCOSC 32MHz Calibration Value A */
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
    register8_t YLINE_INT_CAP;  /* Y-line Integrator Capacitor */
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
#define PORTN              (*(PORT_T_t *) 0x0780) /* I/O Ports, disableable */
#define PORTP              (*(PORT_T_t *) 0x07A0) /* I/O Ports, disableable */
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
#define PRODSIGNATURES_RC32MCALB  _SFR_MEM8(0x0000)
#define PRODSIGNATURES_RC32MCALA  _SFR_MEM8(0x0001)
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
#define PRODSIGNATURES_YLINE_INT_CAP  _SFR_MEM8(0x0043)
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
#define PWR_PWRCRVDDIO  _SFR_MEM8(0x01F2)
#define PWR_PWRSRVDDIO  _SFR_MEM8(0x01F3)


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


/* PORT_T (PORTN) - I/O Ports, disableable */
#define PORTN_DIR  _SFR_MEM8(0x0780)
#define PORTN_DIRSET  _SFR_MEM8(0x0781)
#define PORTN_DIRCLR  _SFR_MEM8(0x0782)
#define PORTN_DIRTGL  _SFR_MEM8(0x0783)
#define PORTN_OUT  _SFR_MEM8(0x0784)
#define PORTN_OUTSET  _SFR_MEM8(0x0785)
#define PORTN_OUTCLR  _SFR_MEM8(0x0786)
#define PORTN_OUTTGL  _SFR_MEM8(0x0787)
#define PORTN_IN  _SFR_MEM8(0x0788)
#define PORTN_INTCTRL  _SFR_MEM8(0x0789)
#define PORTN_INT0MASK  _SFR_MEM8(0x078A)
#define PORTN_INT1MASK  _SFR_MEM8(0x078B)
#define PORTN_INTFLAGS  _SFR_MEM8(0x078C)
#define PORTN_IDISABLE  _SFR_MEM8(0x078D)
#define PORTN_PULL_UP  _SFR_MEM8(0x078E)
#define PORTN_PIN0DISABLE  _SFR_MEM8(0x0790)
#define PORTN_PIN1DISABLE  _SFR_MEM8(0x0791)
#define PORTN_PIN2DISABLE  _SFR_MEM8(0x0792)
#define PORTN_PIN3DISABLE  _SFR_MEM8(0x0793)
#define PORTN_PIN4DISABLE  _SFR_MEM8(0x0794)
#define PORTN_PIN5DISABLE  _SFR_MEM8(0x0795)
#define PORTN_PIN6DISABLE  _SFR_MEM8(0x0796)
#define PORTN_PIN7DISABLE  _SFR_MEM8(0x0797)


/* PORT_T (PORTP) - I/O Ports, disableable */
#define PORTP_DIR  _SFR_MEM8(0x07A0)
#define PORTP_DIRSET  _SFR_MEM8(0x07A1)
#define PORTP_DIRCLR  _SFR_MEM8(0x07A2)
#define PORTP_DIRTGL  _SFR_MEM8(0x07A3)
#define PORTP_OUT  _SFR_MEM8(0x07A4)
#define PORTP_OUTSET  _SFR_MEM8(0x07A5)
#define PORTP_OUTCLR  _SFR_MEM8(0x07A6)
#define PORTP_OUTTGL  _SFR_MEM8(0x07A7)
#define PORTP_IN  _SFR_MEM8(0x07A8)
#define PORTP_INTCTRL  _SFR_MEM8(0x07A9)
#define PORTP_INT0MASK  _SFR_MEM8(0x07AA)
#define PORTP_INT1MASK  _SFR_MEM8(0x07AB)
#define PORTP_INTFLAGS  _SFR_MEM8(0x07AC)
#define PORTP_IDISABLE  _SFR_MEM8(0x07AD)
#define PORTP_PULL_UP  _SFR_MEM8(0x07AE)
#define PORTP_PIN0DISABLE  _SFR_MEM8(0x07B0)
#define PORTP_PIN1DISABLE  _SFR_MEM8(0x07B1)
#define PORTP_PIN2DISABLE  _SFR_MEM8(0x07B2)
#define PORTP_PIN3DISABLE  _SFR_MEM8(0x07B3)
#define PORTP_PIN4DISABLE  _SFR_MEM8(0x07B4)
#define PORTP_PIN5DISABLE  _SFR_MEM8(0x07B5)
#define PORTP_PIN6DISABLE  _SFR_MEM8(0x07B6)
#define PORTP_PIN7DISABLE  _SFR_MEM8(0x07B7)


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
#define CTE_ADCYCHR  _SFR_MEM16(0x0C00)
#define CTE_ADCYCHRL  _SFR_MEM8(0x0C00)
#define CTE_ADCYCHRH  _SFR_MEM8(0x0C01)
#define CTE_INTCRC  _SFR_MEM16(0x0C02)
#define CTE_INTCRCL  _SFR_MEM8(0x0C02)
#define CTE_INTCRCH  _SFR_MEM8(0x0C03)
#define CTE_ADCSRACLR  _SFR_MEM16(0x0C04)
#define CTE_ADCSRACLRL  _SFR_MEM8(0x0C04)
#define CTE_ADCSRACLRH  _SFR_MEM8(0x0C05)
#define CTE_ADCSRASET  _SFR_MEM16(0x0C06)
#define CTE_ADCSRASETL  _SFR_MEM8(0x0C06)
#define CTE_ADCSRASETH  _SFR_MEM8(0x0C07)
#define CTE_INTCRBCLR  _SFR_MEM16(0x0C08)
#define CTE_INTCRBCLRL  _SFR_MEM8(0x0C08)
#define CTE_INTCRBCLRH  _SFR_MEM8(0x0C09)
#define CTE_INTCRBSET  _SFR_MEM16(0x0C0A)
#define CTE_INTCRBSETL  _SFR_MEM8(0x0C0A)
#define CTE_INTCRBSETH  _SFR_MEM8(0x0C0B)
#define CTE_INTCRECLR  _SFR_MEM16(0x0C0C)
#define CTE_INTCRECLRL  _SFR_MEM8(0x0C0C)
#define CTE_INTCRECLRH  _SFR_MEM8(0x0C0D)
#define CTE_INTCRESET  _SFR_MEM16(0x0C0E)
#define CTE_INTCRESETL  _SFR_MEM8(0x0C0E)
#define CTE_INTCRESETH  _SFR_MEM8(0x0C0F)
#define CTE_INTXCHR  _SFR_MEM16(0x0C10)
#define CTE_INTXCHRL  _SFR_MEM8(0x0C10)
#define CTE_INTXCHRH  _SFR_MEM8(0x0C11)
#define CTE_INTOENA  _SFR_MEM16(0x0C12)
#define CTE_INTOENAL  _SFR_MEM8(0x0C12)
#define CTE_INTOENAH  _SFR_MEM8(0x0C13)
#define CTE_INTOENB  _SFR_MEM16(0x0C14)
#define CTE_INTOENBL  _SFR_MEM8(0x0C14)
#define CTE_INTOENBH  _SFR_MEM8(0x0C15)
#define CTE_TIMMOECMP  _SFR_MEM16(0x0C16)
#define CTE_TIMMOECMPL  _SFR_MEM8(0x0C16)
#define CTE_TIMMOECMPH  _SFR_MEM8(0x0C17)
#define CTE_HVCRA  _SFR_MEM16(0x0C18)
#define CTE_HVCRAL  _SFR_MEM8(0x0C18)
#define CTE_HVCRAH  _SFR_MEM8(0x0C19)
#define CTE_TIMAPER  _SFR_MEM16(0x0C1A)
#define CTE_TIMAPERL  _SFR_MEM8(0x0C1A)
#define CTE_TIMAPERH  _SFR_MEM8(0x0C1B)
#define CTE_TIMBPER  _SFR_MEM16(0x0C1C)
#define CTE_TIMBPERL  _SFR_MEM8(0x0C1C)
#define CTE_TIMBPERH  _SFR_MEM8(0x0C1D)
#define CTE_TIMCPER  _SFR_MEM16(0x0C1E)
#define CTE_TIMCPERL  _SFR_MEM8(0x0C1E)
#define CTE_TIMCPERH  _SFR_MEM8(0x0C1F)
#define CTE_TIMMOEPER  _SFR_MEM16(0x0C20)
#define CTE_TIMMOEPERL  _SFR_MEM8(0x0C20)
#define CTE_TIMMOEPERH  _SFR_MEM8(0x0C21)
#define CTE_TIMRSTPER  _SFR_MEM16(0x0C22)
#define CTE_TIMRSTPERL  _SFR_MEM8(0x0C22)
#define CTE_TIMRSTPERH  _SFR_MEM8(0x0C23)
#define CTE_INTDONE  _SFR_MEM16(0x0C24)
#define CTE_INTDONEL  _SFR_MEM8(0x0C24)
#define CTE_INTDONEH  _SFR_MEM8(0x0C25)
#define CTE_INTTRIGA  _SFR_MEM16(0x0C26)
#define CTE_INTTRIGAL  _SFR_MEM8(0x0C26)
#define CTE_INTTRIGAH  _SFR_MEM8(0x0C27)
#define CTE_INTTRIGB  _SFR_MEM16(0x0C28)
#define CTE_INTTRIGBL  _SFR_MEM8(0x0C28)
#define CTE_INTTRIGBH  _SFR_MEM8(0x0C29)
#define CTE_INTCRFCLR  _SFR_MEM16(0x0C2C)
#define CTE_INTCRFCLRL  _SFR_MEM8(0x0C2C)
#define CTE_INTCRFCLRH  _SFR_MEM8(0x0C2D)
#define CTE_INTCRFSET  _SFR_MEM16(0x0C2E)
#define CTE_INTCRFSETL  _SFR_MEM8(0x0C2E)
#define CTE_INTCRFSETH  _SFR_MEM8(0x0C2F)
#define CTE_GCAFSRA  _SFR_MEM16(0x0C30)
#define CTE_GCAFSRAL  _SFR_MEM8(0x0C30)
#define CTE_GCAFSRAH  _SFR_MEM8(0x0C31)
#define CTE_GCAFHDLCNT  _SFR_MEM16(0x0C32)
#define CTE_GCAFHDLCNTL  _SFR_MEM8(0x0C32)
#define CTE_GCAFHDLCNTH  _SFR_MEM8(0x0C33)
#define CTE_GCAFHDHCNT  _SFR_MEM16(0x0C34)
#define CTE_GCAFHDHCNTL  _SFR_MEM8(0x0C34)
#define CTE_GCAFHDHCNTH  _SFR_MEM8(0x0C35)
#define CTE_GCAFCCCLIM  _SFR_MEM16(0x0C36)
#define CTE_GCAFCCCLIML  _SFR_MEM8(0x0C36)
#define CTE_GCAFCCCLIMH  _SFR_MEM8(0x0C37)
#define CTE_PIFXPORTA  _SFR_MEM16(0x0C38)
#define CTE_PIFXPORTAL  _SFR_MEM8(0x0C38)
#define CTE_PIFXPORTAH  _SFR_MEM8(0x0C39)
#define CTE_PIFXPORTB  _SFR_MEM16(0x0C3A)
#define CTE_PIFXPORTBL  _SFR_MEM8(0x0C3A)
#define CTE_PIFXPORTBH  _SFR_MEM8(0x0C3B)
#define CTE_PIFYPORTA  _SFR_MEM16(0x0C3C)
#define CTE_PIFYPORTAL  _SFR_MEM8(0x0C3C)
#define CTE_PIFYPORTAH  _SFR_MEM8(0x0C3D)
#define CTE_PIFYPORTB  _SFR_MEM16(0x0C3E)
#define CTE_PIFYPORTBL  _SFR_MEM8(0x0C3E)
#define CTE_PIFYPORTBH  _SFR_MEM8(0x0C3F)
#define CTE_PIFXDDRA  _SFR_MEM16(0x0C40)
#define CTE_PIFXDDRAL  _SFR_MEM8(0x0C40)
#define CTE_PIFXDDRAH  _SFR_MEM8(0x0C41)
#define CTE_PIFXDDRB  _SFR_MEM16(0x0C42)
#define CTE_PIFXDDRBL  _SFR_MEM8(0x0C42)
#define CTE_PIFXDDRBH  _SFR_MEM8(0x0C43)
#define CTE_PIFYDDRA  _SFR_MEM16(0x0C44)
#define CTE_PIFYDDRAL  _SFR_MEM8(0x0C44)
#define CTE_PIFYDDRAH  _SFR_MEM8(0x0C45)
#define CTE_PIFYDDRB  _SFR_MEM16(0x0C46)
#define CTE_PIFYDDRBL  _SFR_MEM8(0x0C46)
#define CTE_PIFYDDRBH  _SFR_MEM8(0x0C47)
#define CTE_PIFXTGLA  _SFR_MEM16(0x0C48)
#define CTE_PIFXTGLAL  _SFR_MEM8(0x0C48)
#define CTE_PIFXTGLAH  _SFR_MEM8(0x0C49)
#define CTE_PIFXTGLB  _SFR_MEM16(0x0C4A)
#define CTE_PIFXTGLBL  _SFR_MEM8(0x0C4A)
#define CTE_PIFXTGLBH  _SFR_MEM8(0x0C4B)
#define CTE_PIFYTGLA  _SFR_MEM16(0x0C4C)
#define CTE_PIFYTGLAL  _SFR_MEM8(0x0C4C)
#define CTE_PIFYTGLAH  _SFR_MEM8(0x0C4D)
#define CTE_PIFYTGLB  _SFR_MEM16(0x0C4E)
#define CTE_PIFYTGLBL  _SFR_MEM8(0x0C4E)
#define CTE_PIFYTGLBH  _SFR_MEM8(0x0C4F)
#define CTE_PIFILA  _SFR_MEM16(0x0C50)
#define CTE_PIFILAL  _SFR_MEM8(0x0C50)
#define CTE_PIFILAH  _SFR_MEM8(0x0C51)
#define CTE_PIFILB  _SFR_MEM16(0x0C52)
#define CTE_PIFILBL  _SFR_MEM8(0x0C52)
#define CTE_PIFILBH  _SFR_MEM8(0x0C53)
#define CTE_PIFILE  _SFR_MEM16(0x0C54)
#define CTE_PIFILEL  _SFR_MEM8(0x0C54)
#define CTE_PIFILEH  _SFR_MEM8(0x0C55)
#define CTE_PIFILO  _SFR_MEM16(0x0C56)
#define CTE_PIFILOL  _SFR_MEM8(0x0C56)
#define CTE_PIFILOH  _SFR_MEM8(0x0C57)
#define CTE_ADCCRA  _SFR_MEM16(0x0C80)
#define CTE_ADCCRAL  _SFR_MEM8(0x0C80)
#define CTE_ADCCRAH  _SFR_MEM8(0x0C81)
#define CTE_ADCCRB  _SFR_MEM16(0x0C82)
#define CTE_ADCCRBL  _SFR_MEM8(0x0C82)
#define CTE_ADCCRBH  _SFR_MEM8(0x0C83)
#define CTE_ADCINTCAL  _SFR_MEM16(0x0C84)
#define CTE_ADCINTCALL  _SFR_MEM8(0x0C84)
#define CTE_ADCINTCALH  _SFR_MEM8(0x0C85)
#define CTE_ADCRES  _SFR_MEM16(0x0C86)
#define CTE_ADCRESL  _SFR_MEM8(0x0C86)
#define CTE_ADCRESH  _SFR_MEM8(0x0C87)
#define CTE_ADCINTTEST  _SFR_MEM16(0x0C88)
#define CTE_ADCINTTESTL  _SFR_MEM8(0x0C88)
#define CTE_ADCINTTESTH  _SFR_MEM8(0x0C89)
#define CTE_ADCSHVBCAL  _SFR_MEM16(0x0C8A)
#define CTE_ADCSHVBCALL  _SFR_MEM8(0x0C8A)
#define CTE_ADCSHVBCALH  _SFR_MEM8(0x0C8B)
#define CTE_INTCRA  _SFR_MEM16(0x0C8C)
#define CTE_INTCRAL  _SFR_MEM8(0x0C8C)
#define CTE_INTCRAH  _SFR_MEM8(0x0C8D)
#define CTE_INTCRD  _SFR_MEM16(0x0C8E)
#define CTE_INTCRDL  _SFR_MEM8(0x0C8E)
#define CTE_INTCRDH  _SFR_MEM8(0x0C8F)
#define CTE_INTENA  _SFR_MEM16(0x0C90)
#define CTE_INTENAL  _SFR_MEM8(0x0C90)
#define CTE_INTENAH  _SFR_MEM8(0x0C91)
#define CTE_INTENB  _SFR_MEM16(0x0C92)
#define CTE_INTENBL  _SFR_MEM8(0x0C92)
#define CTE_INTENBH  _SFR_MEM8(0x0C93)
#define CTE_INTMASKENA  _SFR_MEM16(0x0C94)
#define CTE_INTMASKENAL  _SFR_MEM8(0x0C94)
#define CTE_INTMASKENAH  _SFR_MEM8(0x0C95)
#define CTE_INTMASKENB  _SFR_MEM16(0x0C96)
#define CTE_INTMASKENBL  _SFR_MEM8(0x0C96)
#define CTE_INTMASKENBH  _SFR_MEM8(0x0C97)
#define CTE_SHENA  _SFR_MEM16(0x0C98)
#define CTE_SHENAL  _SFR_MEM8(0x0C98)
#define CTE_SHENAH  _SFR_MEM8(0x0C99)
#define CTE_SHENB  _SFR_MEM16(0x0C9A)
#define CTE_SHENBL  _SFR_MEM8(0x0C9A)
#define CTE_SHENBH  _SFR_MEM8(0x0C9B)
#define CTE_BIASCR  _SFR_MEM16(0x0C9C)
#define CTE_BIASCRL  _SFR_MEM8(0x0C9C)
#define CTE_BIASCRH  _SFR_MEM8(0x0C9D)
#define CTE_HVSEQT  _SFR_MEM16(0x0C9E)
#define CTE_HVSEQTL  _SFR_MEM8(0x0C9E)
#define CTE_HVSEQTH  _SFR_MEM8(0x0C9F)
#define CTE_INTXCHMAX  _SFR_MEM16(0x0CA0)
#define CTE_INTXCHMAXL  _SFR_MEM8(0x0CA0)
#define CTE_INTXCHMAXH  _SFR_MEM8(0x0CA1)
#define CTE_INTCAPRSTCR  _SFR_MEM16(0x0CAE)
#define CTE_INTCAPRSTCRL  _SFR_MEM8(0x0CAE)
#define CTE_INTCAPRSTCRH  _SFR_MEM8(0x0CAF)
#define CTE_INTGAIN0  _SFR_MEM16(0x0CB0)
#define CTE_INTGAIN0L  _SFR_MEM8(0x0CB0)
#define CTE_INTGAIN0H  _SFR_MEM8(0x0CB1)
#define CTE_INTGAIN1  _SFR_MEM16(0x0CB2)
#define CTE_INTGAIN1L  _SFR_MEM8(0x0CB2)
#define CTE_INTGAIN1H  _SFR_MEM8(0x0CB3)
#define CTE_INTGAIN2  _SFR_MEM16(0x0CB4)
#define CTE_INTGAIN2L  _SFR_MEM8(0x0CB4)
#define CTE_INTGAIN2H  _SFR_MEM8(0x0CB5)
#define CTE_INTGAIN3  _SFR_MEM16(0x0CB6)
#define CTE_INTGAIN3L  _SFR_MEM8(0x0CB6)
#define CTE_INTGAIN3H  _SFR_MEM8(0x0CB7)
#define CTE_INTGAIN4  _SFR_MEM16(0x0CB8)
#define CTE_INTGAIN4L  _SFR_MEM8(0x0CB8)
#define CTE_INTGAIN4H  _SFR_MEM8(0x0CB9)
#define CTE_TIMACMP  _SFR_MEM16(0x0CC0)
#define CTE_TIMACMPL  _SFR_MEM8(0x0CC0)
#define CTE_TIMACMPH  _SFR_MEM8(0x0CC1)
#define CTE_TIMBCMP  _SFR_MEM16(0x0CC2)
#define CTE_TIMBCMPL  _SFR_MEM8(0x0CC2)
#define CTE_TIMBCMPH  _SFR_MEM8(0x0CC3)
#define CTE_PADYCHCOMPA  _SFR_MEM16(0x0CC4)
#define CTE_PADYCHCOMPAL  _SFR_MEM8(0x0CC4)
#define CTE_PADYCHCOMPAH  _SFR_MEM8(0x0CC5)
#define CTE_PADYCHCOMPB  _SFR_MEM16(0x0CC6)
#define CTE_PADYCHCOMPBL  _SFR_MEM8(0x0CC6)
#define CTE_PADYCHCOMPBH  _SFR_MEM8(0x0CC7)
#define CTE_PADBNY1  _SFR_MEM16(0x0CC8)
#define CTE_PADBNY1L  _SFR_MEM8(0x0CC8)
#define CTE_PADBNY1H  _SFR_MEM8(0x0CC9)
#define CTE_PADBPY1  _SFR_MEM16(0x0CCA)
#define CTE_PADBPY1L  _SFR_MEM8(0x0CCA)
#define CTE_PADBPY1H  _SFR_MEM8(0x0CCB)
#define CTE_PADY1  _SFR_MEM16(0x0CCC)
#define CTE_PADY1L  _SFR_MEM8(0x0CCC)
#define CTE_PADY1H  _SFR_MEM8(0x0CCD)
#define CTE_XYBIAS  _SFR_MEM16(0x0CCE)
#define CTE_XYBIASL  _SFR_MEM8(0x0CCE)
#define CTE_XYBIASH  _SFR_MEM8(0x0CCF)
#define CTE_PADSCOEXA  _SFR_MEM16(0x0CD0)
#define CTE_PADSCOEXAL  _SFR_MEM8(0x0CD0)
#define CTE_PADSCOEXAH  _SFR_MEM8(0x0CD1)
#define CTE_PADSCOEXB  _SFR_MEM16(0x0CD2)
#define CTE_PADSCOEXBL  _SFR_MEM8(0x0CD2)
#define CTE_PADSCOEXBH  _SFR_MEM8(0x0CD3)
#define CTE_PADSCOEYA  _SFR_MEM16(0x0CD4)
#define CTE_PADSCOEYAL  _SFR_MEM8(0x0CD4)
#define CTE_PADSCOEYAH  _SFR_MEM8(0x0CD5)
#define CTE_PADSCOEYB  _SFR_MEM16(0x0CD6)
#define CTE_PADSCOEYBL  _SFR_MEM8(0x0CD6)
#define CTE_PADSCOEYBH  _SFR_MEM8(0x0CD7)
#define CTE_PADYONXENA  _SFR_MEM16(0x0CD8)
#define CTE_PADYONXENAL  _SFR_MEM8(0x0CD8)
#define CTE_PADYONXENAH  _SFR_MEM8(0x0CD9)
#define CTE_PADYONXENB  _SFR_MEM16(0x0CDA)
#define CTE_PADYONXENBL  _SFR_MEM8(0x0CDA)
#define CTE_PADYONXENBH  _SFR_MEM8(0x0CDB)
#define CTE_PADXONXENA  _SFR_MEM16(0x0CDC)
#define CTE_PADXONXENAL  _SFR_MEM8(0x0CDC)
#define CTE_PADXONXENAH  _SFR_MEM8(0x0CDD)
#define CTE_PADXONXENB  _SFR_MEM16(0x0CDE)
#define CTE_PADXONXENBL  _SFR_MEM8(0x0CDE)
#define CTE_PADXONXENBH  _SFR_MEM8(0x0CDF)
#define CTE_PADYONYENA  _SFR_MEM16(0x0CE0)
#define CTE_PADYONYENAL  _SFR_MEM8(0x0CE0)
#define CTE_PADYONYENAH  _SFR_MEM8(0x0CE1)
#define CTE_PADYONYENB  _SFR_MEM16(0x0CE2)
#define CTE_PADYONYENBL  _SFR_MEM8(0x0CE2)
#define CTE_PADYONYENBH  _SFR_MEM8(0x0CE3)
#define CTE_PADPROXENXA  _SFR_MEM16(0x0CE4)
#define CTE_PADPROXENXAL  _SFR_MEM8(0x0CE4)
#define CTE_PADPROXENXAH  _SFR_MEM8(0x0CE5)
#define CTE_PADPROXENXB  _SFR_MEM16(0x0CE6)
#define CTE_PADPROXENXBL  _SFR_MEM8(0x0CE6)
#define CTE_PADPROXENXBH  _SFR_MEM8(0x0CE7)
#define CTE_PADPROXENYA  _SFR_MEM16(0x0CE8)
#define CTE_PADPROXENYAL  _SFR_MEM8(0x0CE8)
#define CTE_PADPROXENYAH  _SFR_MEM8(0x0CE9)
#define CTE_PADPROXENYB  _SFR_MEM16(0x0CEA)
#define CTE_PADPROXENYBL  _SFR_MEM8(0x0CEA)
#define CTE_PADPROXENYBH  _SFR_MEM8(0x0CEB)
#define CTE_PADXRSTA  _SFR_MEM16(0x0CEC)
#define CTE_PADXRSTAL  _SFR_MEM8(0x0CEC)
#define CTE_PADXRSTAH  _SFR_MEM8(0x0CED)
#define CTE_PADXRSTB  _SFR_MEM16(0x0CEE)
#define CTE_PADXRSTBL  _SFR_MEM8(0x0CEE)
#define CTE_PADXRSTBH  _SFR_MEM8(0x0CEF)
#define CTE_PADXRESENA  _SFR_MEM16(0x0CF0)
#define CTE_PADXRESENAL  _SFR_MEM8(0x0CF0)
#define CTE_PADXRESENAH  _SFR_MEM8(0x0CF1)
#define CTE_PADXRESENB  _SFR_MEM16(0x0CF2)
#define CTE_PADXRESENBL  _SFR_MEM8(0x0CF2)
#define CTE_PADXRESENBH  _SFR_MEM8(0x0CF3)
#define CTE_PADYRESENA  _SFR_MEM16(0x0CF4)
#define CTE_PADYRESENAL  _SFR_MEM8(0x0CF4)
#define CTE_PADYRESENAH  _SFR_MEM8(0x0CF5)
#define CTE_PADYRESENB  _SFR_MEM16(0x0CF6)
#define CTE_PADYRESENBL  _SFR_MEM8(0x0CF6)
#define CTE_PADYRESENBH  _SFR_MEM8(0x0CF7)
#define CTE_PADSCICALENA  _SFR_MEM16(0x0CF8)
#define CTE_PADSCICALENAL  _SFR_MEM8(0x0CF8)
#define CTE_PADSCICALENAH  _SFR_MEM8(0x0CF9)
#define CTE_PADSCICALENB  _SFR_MEM16(0x0CFA)
#define CTE_PADSCICALENBL  _SFR_MEM8(0x0CFA)
#define CTE_PADSCICALENBH  _SFR_MEM8(0x0CFB)
#define CTE_PADINTENA  _SFR_MEM16(0x0CFC)
#define CTE_PADINTENAL  _SFR_MEM8(0x0CFC)
#define CTE_PADINTENAH  _SFR_MEM8(0x0CFD)
#define CTE_PADINTENB  _SFR_MEM16(0x0CFE)
#define CTE_PADINTENBL  _SFR_MEM8(0x0CFE)
#define CTE_PADINTENBH  _SFR_MEM8(0x0CFF)
#define CTE_PADSCX0  _SFR_MEM16(0x0D00)
#define CTE_PADSCX0L  _SFR_MEM8(0x0D00)
#define CTE_PADSCX0H  _SFR_MEM8(0x0D01)
#define CTE_PADSCX1  _SFR_MEM16(0x0D02)
#define CTE_PADSCX1L  _SFR_MEM8(0x0D02)
#define CTE_PADSCX1H  _SFR_MEM8(0x0D03)
#define CTE_PADSCX2  _SFR_MEM16(0x0D04)
#define CTE_PADSCX2L  _SFR_MEM8(0x0D04)
#define CTE_PADSCX2H  _SFR_MEM8(0x0D05)
#define CTE_PADSCX3  _SFR_MEM16(0x0D06)
#define CTE_PADSCX3L  _SFR_MEM8(0x0D06)
#define CTE_PADSCX3H  _SFR_MEM8(0x0D07)
#define CTE_PADSCX4  _SFR_MEM16(0x0D08)
#define CTE_PADSCX4L  _SFR_MEM8(0x0D08)
#define CTE_PADSCX4H  _SFR_MEM8(0x0D09)
#define CTE_PADSCX5  _SFR_MEM16(0x0D0A)
#define CTE_PADSCX5L  _SFR_MEM8(0x0D0A)
#define CTE_PADSCX5H  _SFR_MEM8(0x0D0B)
#define CTE_PADSCX6  _SFR_MEM16(0x0D0C)
#define CTE_PADSCX6L  _SFR_MEM8(0x0D0C)
#define CTE_PADSCX6H  _SFR_MEM8(0x0D0D)
#define CTE_PADSCX7  _SFR_MEM16(0x0D0E)
#define CTE_PADSCX7L  _SFR_MEM8(0x0D0E)
#define CTE_PADSCX7H  _SFR_MEM8(0x0D0F)
#define CTE_PADSCX8  _SFR_MEM16(0x0D10)
#define CTE_PADSCX8L  _SFR_MEM8(0x0D10)
#define CTE_PADSCX8H  _SFR_MEM8(0x0D11)
#define CTE_PADSCX9  _SFR_MEM16(0x0D12)
#define CTE_PADSCX9L  _SFR_MEM8(0x0D12)
#define CTE_PADSCX9H  _SFR_MEM8(0x0D13)
#define CTE_PADSCX10  _SFR_MEM16(0x0D14)
#define CTE_PADSCX10L  _SFR_MEM8(0x0D14)
#define CTE_PADSCX10H  _SFR_MEM8(0x0D15)
#define CTE_PADSCX11  _SFR_MEM16(0x0D16)
#define CTE_PADSCX11L  _SFR_MEM8(0x0D16)
#define CTE_PADSCX11H  _SFR_MEM8(0x0D17)
#define CTE_PADSCX12  _SFR_MEM16(0x0D18)
#define CTE_PADSCX12L  _SFR_MEM8(0x0D18)
#define CTE_PADSCX12H  _SFR_MEM8(0x0D19)
#define CTE_PADSCX13  _SFR_MEM16(0x0D1A)
#define CTE_PADSCX13L  _SFR_MEM8(0x0D1A)
#define CTE_PADSCX13H  _SFR_MEM8(0x0D1B)
#define CTE_PADSCX14  _SFR_MEM16(0x0D1C)
#define CTE_PADSCX14L  _SFR_MEM8(0x0D1C)
#define CTE_PADSCX14H  _SFR_MEM8(0x0D1D)
#define CTE_PADSCX15  _SFR_MEM16(0x0D1E)
#define CTE_PADSCX15L  _SFR_MEM8(0x0D1E)
#define CTE_PADSCX15H  _SFR_MEM8(0x0D1F)
#define CTE_PADSCX16  _SFR_MEM16(0x0D20)
#define CTE_PADSCX16L  _SFR_MEM8(0x0D20)
#define CTE_PADSCX16H  _SFR_MEM8(0x0D21)
#define CTE_PADSCX17  _SFR_MEM16(0x0D22)
#define CTE_PADSCX17L  _SFR_MEM8(0x0D22)
#define CTE_PADSCX17H  _SFR_MEM8(0x0D23)
#define CTE_PADSCX18  _SFR_MEM16(0x0D24)
#define CTE_PADSCX18L  _SFR_MEM8(0x0D24)
#define CTE_PADSCX18H  _SFR_MEM8(0x0D25)
#define CTE_PADSCX19  _SFR_MEM16(0x0D26)
#define CTE_PADSCX19L  _SFR_MEM8(0x0D26)
#define CTE_PADSCX19H  _SFR_MEM8(0x0D27)
#define CTE_PADSCX20  _SFR_MEM16(0x0D28)
#define CTE_PADSCX20L  _SFR_MEM8(0x0D28)
#define CTE_PADSCX20H  _SFR_MEM8(0x0D29)
#define CTE_PADSCX21  _SFR_MEM16(0x0D2A)
#define CTE_PADSCX21L  _SFR_MEM8(0x0D2A)
#define CTE_PADSCX21H  _SFR_MEM8(0x0D2B)
#define CTE_PADSCX22  _SFR_MEM16(0x0D2C)
#define CTE_PADSCX22L  _SFR_MEM8(0x0D2C)
#define CTE_PADSCX22H  _SFR_MEM8(0x0D2D)
#define CTE_PADSCX23  _SFR_MEM16(0x0D2E)
#define CTE_PADSCX23L  _SFR_MEM8(0x0D2E)
#define CTE_PADSCX23H  _SFR_MEM8(0x0D2F)
#define CTE_PADSCX24  _SFR_MEM16(0x0D30)
#define CTE_PADSCX24L  _SFR_MEM8(0x0D30)
#define CTE_PADSCX24H  _SFR_MEM8(0x0D31)
#define CTE_PADSCX25  _SFR_MEM16(0x0D32)
#define CTE_PADSCX25L  _SFR_MEM8(0x0D32)
#define CTE_PADSCX25H  _SFR_MEM8(0x0D33)
#define CTE_PADSCX26  _SFR_MEM16(0x0D34)
#define CTE_PADSCX26L  _SFR_MEM8(0x0D34)
#define CTE_PADSCX26H  _SFR_MEM8(0x0D35)
#define CTE_PADSCX27  _SFR_MEM16(0x0D36)
#define CTE_PADSCX27L  _SFR_MEM8(0x0D36)
#define CTE_PADSCX27H  _SFR_MEM8(0x0D37)
#define CTE_PADSCX28  _SFR_MEM16(0x0D38)
#define CTE_PADSCX28L  _SFR_MEM8(0x0D38)
#define CTE_PADSCX28H  _SFR_MEM8(0x0D39)
#define CTE_PADSCX29  _SFR_MEM16(0x0D3A)
#define CTE_PADSCX29L  _SFR_MEM8(0x0D3A)
#define CTE_PADSCX29H  _SFR_MEM8(0x0D3B)
#define CTE_PADSCX30  _SFR_MEM16(0x0D3C)
#define CTE_PADSCX30L  _SFR_MEM8(0x0D3C)
#define CTE_PADSCX30H  _SFR_MEM8(0x0D3D)
#define CTE_PADSCX31  _SFR_MEM16(0x0D3E)
#define CTE_PADSCX31L  _SFR_MEM8(0x0D3E)
#define CTE_PADSCX31H  _SFR_MEM8(0x0D3F)
#define CTE_PADSCX32  _SFR_MEM16(0x0D40)
#define CTE_PADSCX32L  _SFR_MEM8(0x0D40)
#define CTE_PADSCX32H  _SFR_MEM8(0x0D41)
#define CTE_PADSCX33  _SFR_MEM16(0x0D42)
#define CTE_PADSCX33L  _SFR_MEM8(0x0D42)
#define CTE_PADSCX33H  _SFR_MEM8(0x0D43)
#define CTE_PADSCX34  _SFR_MEM16(0x0D44)
#define CTE_PADSCX34L  _SFR_MEM8(0x0D44)
#define CTE_PADSCX34H  _SFR_MEM8(0x0D45)
#define CTE_PADSCX35  _SFR_MEM16(0x0D46)
#define CTE_PADSCX35L  _SFR_MEM8(0x0D46)
#define CTE_PADSCX35H  _SFR_MEM8(0x0D47)
#define CTE_PADSCX36  _SFR_MEM16(0x0D48)
#define CTE_PADSCX36L  _SFR_MEM8(0x0D48)
#define CTE_PADSCX36H  _SFR_MEM8(0x0D49)
#define CTE_PADSCX37  _SFR_MEM16(0x0D4A)
#define CTE_PADSCX37L  _SFR_MEM8(0x0D4A)
#define CTE_PADSCX37H  _SFR_MEM8(0x0D4B)
#define CTE_PADSCX38  _SFR_MEM16(0x0D4C)
#define CTE_PADSCX38L  _SFR_MEM8(0x0D4C)
#define CTE_PADSCX38H  _SFR_MEM8(0x0D4D)
#define CTE_PADSCX39  _SFR_MEM16(0x0D4E)
#define CTE_PADSCX39L  _SFR_MEM8(0x0D4E)
#define CTE_PADSCX39H  _SFR_MEM8(0x0D4F)
#define CTE_PADSCX40  _SFR_MEM16(0x0D50)
#define CTE_PADSCX40L  _SFR_MEM8(0x0D50)
#define CTE_PADSCX40H  _SFR_MEM8(0x0D51)
#define CTE_PADSCX41  _SFR_MEM16(0x0D52)
#define CTE_PADSCX41L  _SFR_MEM8(0x0D52)
#define CTE_PADSCX41H  _SFR_MEM8(0x0D53)
#define CTE_PADSCX42  _SFR_MEM16(0x0D54)
#define CTE_PADSCX42L  _SFR_MEM8(0x0D54)
#define CTE_PADSCX42H  _SFR_MEM8(0x0D55)
#define CTE_PADSCX43  _SFR_MEM16(0x0D56)
#define CTE_PADSCX43L  _SFR_MEM8(0x0D56)
#define CTE_PADSCX43H  _SFR_MEM8(0x0D57)
#define CTE_PADSCX44  _SFR_MEM16(0x0D58)
#define CTE_PADSCX44L  _SFR_MEM8(0x0D58)
#define CTE_PADSCX44H  _SFR_MEM8(0x0D59)
#define CTE_PADSCX45  _SFR_MEM16(0x0D5A)
#define CTE_PADSCX45L  _SFR_MEM8(0x0D5A)
#define CTE_PADSCX45H  _SFR_MEM8(0x0D5B)
#define CTE_PADSCX46  _SFR_MEM16(0x0D5C)
#define CTE_PADSCX46L  _SFR_MEM8(0x0D5C)
#define CTE_PADSCX46H  _SFR_MEM8(0x0D5D)
#define CTE_PADSCX47  _SFR_MEM16(0x0D5E)
#define CTE_PADSCX47L  _SFR_MEM8(0x0D5E)
#define CTE_PADSCX47H  _SFR_MEM8(0x0D5F)
#define CTE_PADSCX48  _SFR_MEM16(0x0D60)
#define CTE_PADSCX48L  _SFR_MEM8(0x0D60)
#define CTE_PADSCX48H  _SFR_MEM8(0x0D61)
#define CTE_PADSCX49  _SFR_MEM16(0x0D62)
#define CTE_PADSCX49L  _SFR_MEM8(0x0D62)
#define CTE_PADSCX49H  _SFR_MEM8(0x0D63)
#define CTE_PADSCX50  _SFR_MEM16(0x0D64)
#define CTE_PADSCX50L  _SFR_MEM8(0x0D64)
#define CTE_PADSCX50H  _SFR_MEM8(0x0D65)
#define CTE_PADSCX51  _SFR_MEM16(0x0D66)
#define CTE_PADSCX51L  _SFR_MEM8(0x0D66)
#define CTE_PADSCX51H  _SFR_MEM8(0x0D67)
#define CTE_PADSCX52  _SFR_MEM16(0x0D68)
#define CTE_PADSCX52L  _SFR_MEM8(0x0D68)
#define CTE_PADSCX52H  _SFR_MEM8(0x0D69)
#define CTE_PADSCX53  _SFR_MEM16(0x0D6A)
#define CTE_PADSCX53L  _SFR_MEM8(0x0D6A)
#define CTE_PADSCX53H  _SFR_MEM8(0x0D6B)
#define CTE_PADSCX54  _SFR_MEM16(0x0D6C)
#define CTE_PADSCX54L  _SFR_MEM8(0x0D6C)
#define CTE_PADSCX54H  _SFR_MEM8(0x0D6D)
#define CTE_PADSCX55  _SFR_MEM16(0x0D6E)
#define CTE_PADSCX55L  _SFR_MEM8(0x0D6E)
#define CTE_PADSCX55H  _SFR_MEM8(0x0D6F)
#define CTE_PADSCX56  _SFR_MEM16(0x0D70)
#define CTE_PADSCX56L  _SFR_MEM8(0x0D70)
#define CTE_PADSCX56H  _SFR_MEM8(0x0D71)
#define CTE_PADSCX57  _SFR_MEM16(0x0D72)
#define CTE_PADSCX57L  _SFR_MEM8(0x0D72)
#define CTE_PADSCX57H  _SFR_MEM8(0x0D73)
#define CTE_PADSCX58  _SFR_MEM16(0x0D74)
#define CTE_PADSCX58L  _SFR_MEM8(0x0D74)
#define CTE_PADSCX58H  _SFR_MEM8(0x0D75)
#define CTE_PADSCX59  _SFR_MEM16(0x0D76)
#define CTE_PADSCX59L  _SFR_MEM8(0x0D76)
#define CTE_PADSCX59H  _SFR_MEM8(0x0D77)
#define CTE_PADSCY0  _SFR_MEM16(0x0D80)
#define CTE_PADSCY0L  _SFR_MEM8(0x0D80)
#define CTE_PADSCY0H  _SFR_MEM8(0x0D81)
#define CTE_PADSCY1  _SFR_MEM16(0x0D82)
#define CTE_PADSCY1L  _SFR_MEM8(0x0D82)
#define CTE_PADSCY1H  _SFR_MEM8(0x0D83)
#define CTE_PADSCY2  _SFR_MEM16(0x0D84)
#define CTE_PADSCY2L  _SFR_MEM8(0x0D84)
#define CTE_PADSCY2H  _SFR_MEM8(0x0D85)
#define CTE_PADSCY3  _SFR_MEM16(0x0D86)
#define CTE_PADSCY3L  _SFR_MEM8(0x0D86)
#define CTE_PADSCY3H  _SFR_MEM8(0x0D87)
#define CTE_PADSCY4  _SFR_MEM16(0x0D88)
#define CTE_PADSCY4L  _SFR_MEM8(0x0D88)
#define CTE_PADSCY4H  _SFR_MEM8(0x0D89)
#define CTE_PADSCY5  _SFR_MEM16(0x0D8A)
#define CTE_PADSCY5L  _SFR_MEM8(0x0D8A)
#define CTE_PADSCY5H  _SFR_MEM8(0x0D8B)
#define CTE_PADSCY6  _SFR_MEM16(0x0D8C)
#define CTE_PADSCY6L  _SFR_MEM8(0x0D8C)
#define CTE_PADSCY6H  _SFR_MEM8(0x0D8D)
#define CTE_PADSCY7  _SFR_MEM16(0x0D8E)
#define CTE_PADSCY7L  _SFR_MEM8(0x0D8E)
#define CTE_PADSCY7H  _SFR_MEM8(0x0D8F)
#define CTE_PADSCY8  _SFR_MEM16(0x0D90)
#define CTE_PADSCY8L  _SFR_MEM8(0x0D90)
#define CTE_PADSCY8H  _SFR_MEM8(0x0D91)
#define CTE_PADSCY9  _SFR_MEM16(0x0D92)
#define CTE_PADSCY9L  _SFR_MEM8(0x0D92)
#define CTE_PADSCY9H  _SFR_MEM8(0x0D93)
#define CTE_PADSCY10  _SFR_MEM16(0x0D94)
#define CTE_PADSCY10L  _SFR_MEM8(0x0D94)
#define CTE_PADSCY10H  _SFR_MEM8(0x0D95)
#define CTE_PADSCY11  _SFR_MEM16(0x0D96)
#define CTE_PADSCY11L  _SFR_MEM8(0x0D96)
#define CTE_PADSCY11H  _SFR_MEM8(0x0D97)
#define CTE_PADSCY12  _SFR_MEM16(0x0D98)
#define CTE_PADSCY12L  _SFR_MEM8(0x0D98)
#define CTE_PADSCY12H  _SFR_MEM8(0x0D99)
#define CTE_PADSCY13  _SFR_MEM16(0x0D9A)
#define CTE_PADSCY13L  _SFR_MEM8(0x0D9A)
#define CTE_PADSCY13H  _SFR_MEM8(0x0D9B)
#define CTE_PADSCY14  _SFR_MEM16(0x0D9C)
#define CTE_PADSCY14L  _SFR_MEM8(0x0D9C)
#define CTE_PADSCY14H  _SFR_MEM8(0x0D9D)
#define CTE_PADSCY15  _SFR_MEM16(0x0D9E)
#define CTE_PADSCY15L  _SFR_MEM8(0x0D9E)
#define CTE_PADSCY15H  _SFR_MEM8(0x0D9F)
#define CTE_PADSCY16  _SFR_MEM16(0x0DA0)
#define CTE_PADSCY16L  _SFR_MEM8(0x0DA0)
#define CTE_PADSCY16H  _SFR_MEM8(0x0DA1)
#define CTE_PADSCY17  _SFR_MEM16(0x0DA2)
#define CTE_PADSCY17L  _SFR_MEM8(0x0DA2)
#define CTE_PADSCY17H  _SFR_MEM8(0x0DA3)
#define CTE_PADSCY18  _SFR_MEM16(0x0DA4)
#define CTE_PADSCY18L  _SFR_MEM8(0x0DA4)
#define CTE_PADSCY18H  _SFR_MEM8(0x0DA5)
#define CTE_PADSCY19  _SFR_MEM16(0x0DA6)
#define CTE_PADSCY19L  _SFR_MEM8(0x0DA6)
#define CTE_PADSCY19H  _SFR_MEM8(0x0DA7)
#define CTE_PADSCY20  _SFR_MEM16(0x0DA8)
#define CTE_PADSCY20L  _SFR_MEM8(0x0DA8)
#define CTE_PADSCY20H  _SFR_MEM8(0x0DA9)
#define CTE_PADSCY21  _SFR_MEM16(0x0DAA)
#define CTE_PADSCY21L  _SFR_MEM8(0x0DAA)
#define CTE_PADSCY21H  _SFR_MEM8(0x0DAB)
#define CTE_PADSCY22  _SFR_MEM16(0x0DAC)
#define CTE_PADSCY22L  _SFR_MEM8(0x0DAC)
#define CTE_PADSCY22H  _SFR_MEM8(0x0DAD)
#define CTE_PADSCY23  _SFR_MEM16(0x0DAE)
#define CTE_PADSCY23L  _SFR_MEM8(0x0DAE)
#define CTE_PADSCY23H  _SFR_MEM8(0x0DAF)
#define CTE_PADSCY24  _SFR_MEM16(0x0DB0)
#define CTE_PADSCY24L  _SFR_MEM8(0x0DB0)
#define CTE_PADSCY24H  _SFR_MEM8(0x0DB1)
#define CTE_PADSCY25  _SFR_MEM16(0x0DB2)
#define CTE_PADSCY25L  _SFR_MEM8(0x0DB2)
#define CTE_PADSCY25H  _SFR_MEM8(0x0DB3)
#define CTE_PADSCY26  _SFR_MEM16(0x0DB4)
#define CTE_PADSCY26L  _SFR_MEM8(0x0DB4)
#define CTE_PADSCY26H  _SFR_MEM8(0x0DB5)
#define CTE_PADSCY27  _SFR_MEM16(0x0DB6)
#define CTE_PADSCY27L  _SFR_MEM8(0x0DB6)
#define CTE_PADSCY27H  _SFR_MEM8(0x0DB7)
#define CTE_PADSCY28  _SFR_MEM16(0x0DB8)
#define CTE_PADSCY28L  _SFR_MEM8(0x0DB8)
#define CTE_PADSCY28H  _SFR_MEM8(0x0DB9)
#define CTE_PADSCY29  _SFR_MEM16(0x0DBA)
#define CTE_PADSCY29L  _SFR_MEM8(0x0DBA)
#define CTE_PADSCY29H  _SFR_MEM8(0x0DBB)
#define CTE_PADSCY30  _SFR_MEM16(0x0DBC)
#define CTE_PADSCY30L  _SFR_MEM8(0x0DBC)
#define CTE_PADSCY30H  _SFR_MEM8(0x0DBD)
#define CTE_PADSCY31  _SFR_MEM16(0x0DBE)
#define CTE_PADSCY31L  _SFR_MEM8(0x0DBE)
#define CTE_PADSCY31H  _SFR_MEM8(0x0DBF)
#define CTE_PADSCY32  _SFR_MEM16(0x0DC0)
#define CTE_PADSCY32L  _SFR_MEM8(0x0DC0)
#define CTE_PADSCY32H  _SFR_MEM8(0x0DC1)
#define CTE_PADSCY33  _SFR_MEM16(0x0DC2)
#define CTE_PADSCY33L  _SFR_MEM8(0x0DC2)
#define CTE_PADSCY33H  _SFR_MEM8(0x0DC3)
#define CTE_PADSCY34  _SFR_MEM16(0x0DC4)
#define CTE_PADSCY34L  _SFR_MEM8(0x0DC4)
#define CTE_PADSCY34H  _SFR_MEM8(0x0DC5)
#define CTE_PADSCY35  _SFR_MEM16(0x0DC6)
#define CTE_PADSCY35L  _SFR_MEM8(0x0DC6)
#define CTE_PADSCY35H  _SFR_MEM8(0x0DC7)
#define CTE_PADHVSWENA  _SFR_MEM16(0x0DD0)
#define CTE_PADHVSWENAL  _SFR_MEM8(0x0DD0)
#define CTE_PADHVSWENAH  _SFR_MEM8(0x0DD1)
#define CTE_PADHVSWENB  _SFR_MEM16(0x0DD2)
#define CTE_PADHVSWENBL  _SFR_MEM8(0x0DD2)
#define CTE_PADHVSWENBH  _SFR_MEM8(0x0DD3)
#define CTE_PADBNX1  _SFR_MEM16(0x0DD4)
#define CTE_PADBNX1L  _SFR_MEM8(0x0DD4)
#define CTE_PADBNX1H  _SFR_MEM8(0x0DD5)
#define CTE_PADBPX1  _SFR_MEM16(0x0DD6)
#define CTE_PADBPX1L  _SFR_MEM8(0x0DD6)
#define CTE_PADBPX1H  _SFR_MEM8(0x0DD7)
#define CTE_PADX1  _SFR_MEM16(0x0DD8)
#define CTE_PADX1L  _SFR_MEM8(0x0DD8)
#define CTE_PADX1H  _SFR_MEM8(0x0DD9)
#define CTE_PADBNX2  _SFR_MEM16(0x0DDA)
#define CTE_PADBNX2L  _SFR_MEM8(0x0DDA)
#define CTE_PADBNX2H  _SFR_MEM8(0x0DDB)
#define CTE_PADBPX2  _SFR_MEM16(0x0DDC)
#define CTE_PADBPX2L  _SFR_MEM8(0x0DDC)
#define CTE_PADBPX2H  _SFR_MEM8(0x0DDD)
#define CTE_PADX2  _SFR_MEM16(0x0DDE)
#define CTE_PADX2L  _SFR_MEM8(0x0DDE)
#define CTE_PADX2H  _SFR_MEM8(0x0DDF)
#define CTE_PADSCTESTENA  _SFR_MEM16(0x0DE0)
#define CTE_PADSCTESTENAL  _SFR_MEM8(0x0DE0)
#define CTE_PADSCTESTENAH  _SFR_MEM8(0x0DE1)
#define CTE_PADSCTESTENB  _SFR_MEM16(0x0DE2)
#define CTE_PADSCTESTENBL  _SFR_MEM8(0x0DE2)
#define CTE_PADSCTESTENBH  _SFR_MEM8(0x0DE3)
#define CTE_GCAFCRA  _SFR_MEM16(0x0E00)
#define CTE_GCAFCRAL  _SFR_MEM8(0x0E00)
#define CTE_GCAFCRAH  _SFR_MEM8(0x0E01)
#define CTE_GCAFCRB  _SFR_MEM16(0x0E02)
#define CTE_GCAFCRBL  _SFR_MEM8(0x0E02)
#define CTE_GCAFCRBH  _SFR_MEM8(0x0E03)
#define CTE_GCAFMCENA  _SFR_MEM16(0x0E04)
#define CTE_GCAFMCENAL  _SFR_MEM8(0x0E04)
#define CTE_GCAFMCENAH  _SFR_MEM8(0x0E05)
#define CTE_GCAFMCENB  _SFR_MEM16(0x0E06)
#define CTE_GCAFMCENBL  _SFR_MEM8(0x0E06)
#define CTE_GCAFMCENBH  _SFR_MEM8(0x0E07)
#define CTE_GCAFBASELIM  _SFR_MEM16(0x0E08)
#define CTE_GCAFBASELIML  _SFR_MEM8(0x0E08)
#define CTE_GCAFBASELIMH  _SFR_MEM8(0x0E09)
#define CTE_GCAFPCLL  _SFR_MEM16(0x0E0A)
#define CTE_GCAFPCLLL  _SFR_MEM8(0x0E0A)
#define CTE_GCAFPCLLH  _SFR_MEM8(0x0E0B)
#define CTE_GCAFPCUL  _SFR_MEM16(0x0E0C)
#define CTE_GCAFPCULL  _SFR_MEM8(0x0E0C)
#define CTE_GCAFPCULH  _SFR_MEM8(0x0E0D)
#define CTE_GCAFWFCR  _SFR_MEM16(0x0E0E)
#define CTE_GCAFWFCRL  _SFR_MEM8(0x0E0E)
#define CTE_GCAFWFCRH  _SFR_MEM8(0x0E0F)
#define CTE_GCAFADCMIN  _SFR_MEM16(0x0E10)
#define CTE_GCAFADCMINL  _SFR_MEM8(0x0E10)
#define CTE_GCAFADCMINH  _SFR_MEM8(0x0E11)
#define CTE_GCAFADCMAX  _SFR_MEM16(0x0E12)
#define CTE_GCAFADCMAXL  _SFR_MEM8(0x0E12)
#define CTE_GCAFADCMAXH  _SFR_MEM8(0x0E13)
#define CTE_PIFXENA  _SFR_MEM16(0x0E40)
#define CTE_PIFXENAL  _SFR_MEM8(0x0E40)
#define CTE_PIFXENAH  _SFR_MEM8(0x0E41)
#define CTE_PIFXENB  _SFR_MEM16(0x0E42)
#define CTE_PIFXENBL  _SFR_MEM8(0x0E42)
#define CTE_PIFXENBH  _SFR_MEM8(0x0E43)
#define CTE_PIFYENA  _SFR_MEM16(0x0E44)
#define CTE_PIFYENAL  _SFR_MEM8(0x0E44)
#define CTE_PIFYENAH  _SFR_MEM8(0x0E45)
#define CTE_PIFYENB  _SFR_MEM16(0x0E46)
#define CTE_PIFYENBL  _SFR_MEM8(0x0E46)
#define CTE_PIFYENBH  _SFR_MEM8(0x0E47)
#define CTE_PIFXPINA  _SFR_MEM16(0x0E48)
#define CTE_PIFXPINAL  _SFR_MEM8(0x0E48)
#define CTE_PIFXPINAH  _SFR_MEM8(0x0E49)
#define CTE_PIFXPINB  _SFR_MEM16(0x0E4A)
#define CTE_PIFXPINBL  _SFR_MEM8(0x0E4A)
#define CTE_PIFXPINBH  _SFR_MEM8(0x0E4B)
#define CTE_PIFYPINA  _SFR_MEM16(0x0E4C)
#define CTE_PIFYPINAL  _SFR_MEM8(0x0E4C)
#define CTE_PIFYPINAH  _SFR_MEM8(0x0E4D)
#define CTE_PIFYPINB  _SFR_MEM16(0x0E4E)
#define CTE_PIFYPINBL  _SFR_MEM8(0x0E4E)
#define CTE_PIFYPINBH  _SFR_MEM8(0x0E4F)
#define CTE_PIFXSRLA  _SFR_MEM16(0x0E50)
#define CTE_PIFXSRLAL  _SFR_MEM8(0x0E50)
#define CTE_PIFXSRLAH  _SFR_MEM8(0x0E51)
#define CTE_PIFXSRLB  _SFR_MEM16(0x0E52)
#define CTE_PIFXSRLBL  _SFR_MEM8(0x0E52)
#define CTE_PIFXSRLBH  _SFR_MEM8(0x0E53)
#define CTE_PIFYSRLA  _SFR_MEM16(0x0E54)
#define CTE_PIFYSRLAL  _SFR_MEM8(0x0E54)
#define CTE_PIFYSRLAH  _SFR_MEM8(0x0E55)
#define CTE_PIFYSRLB  _SFR_MEM16(0x0E56)
#define CTE_PIFYSRLBL  _SFR_MEM8(0x0E56)
#define CTE_PIFYSRLBH  _SFR_MEM8(0x0E57)
#define CTE_MS0PCL  _SFR_MEM8(0x0F80)
#define CTE_MS0PCH  _SFR_MEM8(0x0F81)
#define CTE_MS0HIF  _SFR_MEM8(0x0F82)
#define CTE_MS0IR0  _SFR_MEM8(0x0F84)
#define CTE_MS0IR1  _SFR_MEM8(0x0F85)
#define CTE_MS0IR2  _SFR_MEM8(0x0F86)
#define CTE_MS0IR3  _SFR_MEM8(0x0F87)
#define CTE_MS0IRBUFL  _SFR_MEM8(0x0F88)
#define CTE_MS0IRBUFH  _SFR_MEM8(0x0F89)
#define CTE_MS0R0L  _SFR_MEM8(0x0F8A)
#define CTE_MS0R0H  _SFR_MEM8(0x0F8B)
#define CTE_MS0REPEATL  _SFR_MEM8(0x0F8C)
#define CTE_MS0REPEATH  _SFR_MEM8(0x0F8D)
#define CTE_MS1PCL  _SFR_MEM8(0x0F90)
#define CTE_MS1PCH  _SFR_MEM8(0x0F91)
#define CTE_MS1HIF  _SFR_MEM8(0x0F92)
#define CTE_MS1IR0  _SFR_MEM8(0x0F94)
#define CTE_MS1IR1  _SFR_MEM8(0x0F95)
#define CTE_MS1IR2  _SFR_MEM8(0x0F96)
#define CTE_MS1IR3  _SFR_MEM8(0x0F97)
#define CTE_MS1IRBUFL  _SFR_MEM8(0x0F98)
#define CTE_MS1IRBUFH  _SFR_MEM8(0x0F99)
#define CTE_MS1R0L  _SFR_MEM8(0x0F9A)
#define CTE_MS1R0H  _SFR_MEM8(0x0F9B)
#define CTE_MS1REPEATL  _SFR_MEM8(0x0F9C)
#define CTE_MS1REPEATH  _SFR_MEM8(0x0F9D)
#define CTE_CTTEMP  _SFR_MEM8(0x0FA0)
#define CTE_CTCRA  _SFR_MEM8(0x0FA1)
#define CTE_DMAPSCLR  _SFR_MEM8(0x0FA2)
#define CTE_DMAPSSET  _SFR_MEM8(0x0FA3)
#define CTE_MS0_MSACCAL  _SFR_MEM16(0x0E80)
#define CTE_MS0_MSACCAH  _SFR_MEM16(0x0E82)
#define CTE_MS0_MSACCBL  _SFR_MEM16(0x0E84)
#define CTE_MS0_MSACCBH  _SFR_MEM16(0x0E86)
#define CTE_MS0_MSACCCNTA  _SFR_MEM16(0x0E88)
#define CTE_MS0_MSACCCNTB  _SFR_MEM16(0x0E8A)
#define CTE_MS0_MSMAXA  _SFR_MEM16(0x0E8C)
#define CTE_MS0_MSMAXB  _SFR_MEM16(0x0E8E)
#define CTE_MS0_MSMINA  _SFR_MEM16(0x0E90)
#define CTE_MS0_MSMINB  _SFR_MEM16(0x0E92)
#define CTE_MS0_MSSHIFTRA  _SFR_MEM16(0x0E94)
#define CTE_MS0_MSSHIFTRB  _SFR_MEM16(0x0E96)
#define CTE_MS0_MSACCSR  _SFR_MEM16(0x0E98)
#define CTE_MS0_MSCRCCLR  _SFR_MEM16(0x0E9A)
#define CTE_MS0_MSCRCSET  _SFR_MEM16(0x0E9C)
#define CTE_MS0_MSCRA  _SFR_MEM16(0x0EE0)
#define CTE_MS0_MSCRB  _SFR_MEM16(0x0EE2)
#define CTE_MS0_MSSRACLR  _SFR_MEM16(0x0EE8)
#define CTE_MS0_MSSRASET  _SFR_MEM16(0x0EEA)
#define CTE_MS0_MSSRB  _SFR_MEM16(0x0EEC)
#define CTE_MS0_MSSRC  _SFR_MEM16(0x0EEE)
#define CTE_MS0_MSSRD  _SFR_MEM16(0x0EF0)
#define CTE_MS0_MSSRE  _SFR_MEM16(0x0EF2)
#define CTE_MS0_MSCCR  _SFR_MEM16(0x0EF4)
#define CTE_MS0_MSLINK  _SFR_MEM16(0x0EFA)


#define CTE_MS1_MSACCAL  _SFR_MEM16(0x0F00)
#define CTE_MS1_MSACCAH  _SFR_MEM16(0x0F02)
#define CTE_MS1_MSACCBL  _SFR_MEM16(0x0F04)
#define CTE_MS1_MSACCBH  _SFR_MEM16(0x0F06)
#define CTE_MS1_MSACCCNTA  _SFR_MEM16(0x0F08)
#define CTE_MS1_MSACCCNTB  _SFR_MEM16(0x0F0A)
#define CTE_MS1_MSMAXA  _SFR_MEM16(0x0F0C)
#define CTE_MS1_MSMAXB  _SFR_MEM16(0x0F0E)
#define CTE_MS1_MSMINA  _SFR_MEM16(0x0F10)
#define CTE_MS1_MSMINB  _SFR_MEM16(0x0F12)
#define CTE_MS1_MSSHIFTRA  _SFR_MEM16(0x0F14)
#define CTE_MS1_MSSHIFTRB  _SFR_MEM16(0x0F16)
#define CTE_MS1_MSACCSR  _SFR_MEM16(0x0F18)
#define CTE_MS1_MSCRCCLR  _SFR_MEM16(0x0F1A)
#define CTE_MS1_MSCRCSET  _SFR_MEM16(0x0F1C)
#define CTE_MS1_MSCRA  _SFR_MEM16(0x0F60)
#define CTE_MS1_MSCRB  _SFR_MEM16(0x0F62)
#define CTE_MS1_MSSRACLR  _SFR_MEM16(0x0F68)
#define CTE_MS1_MSSRASET  _SFR_MEM16(0x0F6A)
#define CTE_MS1_MSSRB  _SFR_MEM16(0x0F6C)
#define CTE_MS1_MSSRC  _SFR_MEM16(0x0F6E)
#define CTE_MS1_MSSRD  _SFR_MEM16(0x0F70)
#define CTE_MS1_MSSRE  _SFR_MEM16(0x0F72)
#define CTE_MS1_MSCCR  _SFR_MEM16(0x0F74)
#define CTE_MS1_MSLINK  _SFR_MEM16(0x0F7A)





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

/* PWR.PWRCRVDDIO  bit masks and bit positions */
/* PWR_PWRLVLSEN  is already defined. */
/* PWR_PWRLVLSDIS  is already defined. */
/* PWR_PWRBODEN  is already defined. */

/* PWR.PWRSRVDDIO  bit masks and bit positions */
/* PWR_PWROK  is already defined. */
/* PWR_PWRRSTDONE  is already defined. */
/* PWR_PWRLVLSS  is already defined. */

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
/* CTEMS.MSACCAL  bit masks and bit positions */
#define CTEMS_MSACCA_gm  0xFFFF  /* MS Accumulator A group mask. */
#define CTEMS_MSACCA_gp  0  /* MS Accumulator A group position. */
#define CTEMS_MSACCA0_bm  (1<<0)  /* MS Accumulator A bit 0 mask. */
#define CTEMS_MSACCA0_bp  0  /* MS Accumulator A bit 0 position. */
#define CTEMS_MSACCA1_bm  (1<<1)  /* MS Accumulator A bit 1 mask. */
#define CTEMS_MSACCA1_bp  1  /* MS Accumulator A bit 1 position. */
#define CTEMS_MSACCA2_bm  (1<<2)  /* MS Accumulator A bit 2 mask. */
#define CTEMS_MSACCA2_bp  2  /* MS Accumulator A bit 2 position. */
#define CTEMS_MSACCA3_bm  (1<<3)  /* MS Accumulator A bit 3 mask. */
#define CTEMS_MSACCA3_bp  3  /* MS Accumulator A bit 3 position. */
#define CTEMS_MSACCA4_bm  (1<<4)  /* MS Accumulator A bit 4 mask. */
#define CTEMS_MSACCA4_bp  4  /* MS Accumulator A bit 4 position. */
#define CTEMS_MSACCA5_bm  (1<<5)  /* MS Accumulator A bit 5 mask. */
#define CTEMS_MSACCA5_bp  5  /* MS Accumulator A bit 5 position. */
#define CTEMS_MSACCA6_bm  (1<<6)  /* MS Accumulator A bit 6 mask. */
#define CTEMS_MSACCA6_bp  6  /* MS Accumulator A bit 6 position. */
#define CTEMS_MSACCA7_bm  (1<<7)  /* MS Accumulator A bit 7 mask. */
#define CTEMS_MSACCA7_bp  7  /* MS Accumulator A bit 7 position. */
#define CTEMS_MSACCA8_bm  (1<<8)  /* MS Accumulator A bit 8 mask. */
#define CTEMS_MSACCA8_bp  8  /* MS Accumulator A bit 8 position. */
#define CTEMS_MSACCA9_bm  (1<<9)  /* MS Accumulator A bit 9 mask. */
#define CTEMS_MSACCA9_bp  9  /* MS Accumulator A bit 9 position. */
#define CTEMS_MSACCA10_bm  (1<<10)  /* MS Accumulator A bit 10 mask. */
#define CTEMS_MSACCA10_bp  10  /* MS Accumulator A bit 10 position. */
#define CTEMS_MSACCA11_bm  (1<<11)  /* MS Accumulator A bit 11 mask. */
#define CTEMS_MSACCA11_bp  11  /* MS Accumulator A bit 11 position. */
#define CTEMS_MSACCA12_bm  (1<<12)  /* MS Accumulator A bit 12 mask. */
#define CTEMS_MSACCA12_bp  12  /* MS Accumulator A bit 12 position. */
#define CTEMS_MSACCA13_bm  (1<<13)  /* MS Accumulator A bit 13 mask. */
#define CTEMS_MSACCA13_bp  13  /* MS Accumulator A bit 13 position. */
#define CTEMS_MSACCA14_bm  (1<<14)  /* MS Accumulator A bit 14 mask. */
#define CTEMS_MSACCA14_bp  14  /* MS Accumulator A bit 14 position. */
#define CTEMS_MSACCA15_bm  (1<<15)  /* MS Accumulator A bit 15 mask. */
#define CTEMS_MSACCA15_bp  15  /* MS Accumulator A bit 15 position. */

/* CTEMS.MSACCAH  bit masks and bit positions */
/* CTEMS_MSACCA  is already defined. */

/* CTEMS.MSACCBL  bit masks and bit positions */
#define CTEMS_MSACCB_gm  0xFFFF  /* MS Accumulator B group mask. */
#define CTEMS_MSACCB_gp  0  /* MS Accumulator B group position. */
#define CTEMS_MSACCB0_bm  (1<<0)  /* MS Accumulator B bit 0 mask. */
#define CTEMS_MSACCB0_bp  0  /* MS Accumulator B bit 0 position. */
#define CTEMS_MSACCB1_bm  (1<<1)  /* MS Accumulator B bit 1 mask. */
#define CTEMS_MSACCB1_bp  1  /* MS Accumulator B bit 1 position. */
#define CTEMS_MSACCB2_bm  (1<<2)  /* MS Accumulator B bit 2 mask. */
#define CTEMS_MSACCB2_bp  2  /* MS Accumulator B bit 2 position. */
#define CTEMS_MSACCB3_bm  (1<<3)  /* MS Accumulator B bit 3 mask. */
#define CTEMS_MSACCB3_bp  3  /* MS Accumulator B bit 3 position. */
#define CTEMS_MSACCB4_bm  (1<<4)  /* MS Accumulator B bit 4 mask. */
#define CTEMS_MSACCB4_bp  4  /* MS Accumulator B bit 4 position. */
#define CTEMS_MSACCB5_bm  (1<<5)  /* MS Accumulator B bit 5 mask. */
#define CTEMS_MSACCB5_bp  5  /* MS Accumulator B bit 5 position. */
#define CTEMS_MSACCB6_bm  (1<<6)  /* MS Accumulator B bit 6 mask. */
#define CTEMS_MSACCB6_bp  6  /* MS Accumulator B bit 6 position. */
#define CTEMS_MSACCB7_bm  (1<<7)  /* MS Accumulator B bit 7 mask. */
#define CTEMS_MSACCB7_bp  7  /* MS Accumulator B bit 7 position. */
#define CTEMS_MSACCB8_bm  (1<<8)  /* MS Accumulator B bit 8 mask. */
#define CTEMS_MSACCB8_bp  8  /* MS Accumulator B bit 8 position. */
#define CTEMS_MSACCB9_bm  (1<<9)  /* MS Accumulator B bit 9 mask. */
#define CTEMS_MSACCB9_bp  9  /* MS Accumulator B bit 9 position. */
#define CTEMS_MSACCB10_bm  (1<<10)  /* MS Accumulator B bit 10 mask. */
#define CTEMS_MSACCB10_bp  10  /* MS Accumulator B bit 10 position. */
#define CTEMS_MSACCB11_bm  (1<<11)  /* MS Accumulator B bit 11 mask. */
#define CTEMS_MSACCB11_bp  11  /* MS Accumulator B bit 11 position. */
#define CTEMS_MSACCB12_bm  (1<<12)  /* MS Accumulator B bit 12 mask. */
#define CTEMS_MSACCB12_bp  12  /* MS Accumulator B bit 12 position. */
#define CTEMS_MSACCB13_bm  (1<<13)  /* MS Accumulator B bit 13 mask. */
#define CTEMS_MSACCB13_bp  13  /* MS Accumulator B bit 13 position. */
#define CTEMS_MSACCB14_bm  (1<<14)  /* MS Accumulator B bit 14 mask. */
#define CTEMS_MSACCB14_bp  14  /* MS Accumulator B bit 14 position. */
#define CTEMS_MSACCB15_bm  (1<<15)  /* MS Accumulator B bit 15 mask. */
#define CTEMS_MSACCB15_bp  15  /* MS Accumulator B bit 15 position. */

/* CTEMS.MSACCBH  bit masks and bit positions */
/* CTEMS_MSACCB  is already defined. */

/* CTEMS.MSACCCNTA  bit masks and bit positions */
#define CTEMS_MSACCCNT_gm  0xFFFF  /* MS Accumulator Counter group mask. */
#define CTEMS_MSACCCNT_gp  0  /* MS Accumulator Counter group position. */
#define CTEMS_MSACCCNT0_bm  (1<<0)  /* MS Accumulator Counter bit 0 mask. */
#define CTEMS_MSACCCNT0_bp  0  /* MS Accumulator Counter bit 0 position. */
#define CTEMS_MSACCCNT1_bm  (1<<1)  /* MS Accumulator Counter bit 1 mask. */
#define CTEMS_MSACCCNT1_bp  1  /* MS Accumulator Counter bit 1 position. */
#define CTEMS_MSACCCNT2_bm  (1<<2)  /* MS Accumulator Counter bit 2 mask. */
#define CTEMS_MSACCCNT2_bp  2  /* MS Accumulator Counter bit 2 position. */
#define CTEMS_MSACCCNT3_bm  (1<<3)  /* MS Accumulator Counter bit 3 mask. */
#define CTEMS_MSACCCNT3_bp  3  /* MS Accumulator Counter bit 3 position. */
#define CTEMS_MSACCCNT4_bm  (1<<4)  /* MS Accumulator Counter bit 4 mask. */
#define CTEMS_MSACCCNT4_bp  4  /* MS Accumulator Counter bit 4 position. */
#define CTEMS_MSACCCNT5_bm  (1<<5)  /* MS Accumulator Counter bit 5 mask. */
#define CTEMS_MSACCCNT5_bp  5  /* MS Accumulator Counter bit 5 position. */
#define CTEMS_MSACCCNT6_bm  (1<<6)  /* MS Accumulator Counter bit 6 mask. */
#define CTEMS_MSACCCNT6_bp  6  /* MS Accumulator Counter bit 6 position. */
#define CTEMS_MSACCCNT7_bm  (1<<7)  /* MS Accumulator Counter bit 7 mask. */
#define CTEMS_MSACCCNT7_bp  7  /* MS Accumulator Counter bit 7 position. */
#define CTEMS_MSACCCNT8_bm  (1<<8)  /* MS Accumulator Counter bit 8 mask. */
#define CTEMS_MSACCCNT8_bp  8  /* MS Accumulator Counter bit 8 position. */
#define CTEMS_MSACCCNT9_bm  (1<<9)  /* MS Accumulator Counter bit 9 mask. */
#define CTEMS_MSACCCNT9_bp  9  /* MS Accumulator Counter bit 9 position. */
#define CTEMS_MSACCCNT10_bm  (1<<10)  /* MS Accumulator Counter bit 10 mask. */
#define CTEMS_MSACCCNT10_bp  10  /* MS Accumulator Counter bit 10 position. */
#define CTEMS_MSACCCNT11_bm  (1<<11)  /* MS Accumulator Counter bit 11 mask. */
#define CTEMS_MSACCCNT11_bp  11  /* MS Accumulator Counter bit 11 position. */
#define CTEMS_MSACCCNT12_bm  (1<<12)  /* MS Accumulator Counter bit 12 mask. */
#define CTEMS_MSACCCNT12_bp  12  /* MS Accumulator Counter bit 12 position. */
#define CTEMS_MSACCCNT13_bm  (1<<13)  /* MS Accumulator Counter bit 13 mask. */
#define CTEMS_MSACCCNT13_bp  13  /* MS Accumulator Counter bit 13 position. */
#define CTEMS_MSACCCNT14_bm  (1<<14)  /* MS Accumulator Counter bit 14 mask. */
#define CTEMS_MSACCCNT14_bp  14  /* MS Accumulator Counter bit 14 position. */
#define CTEMS_MSACCCNT15_bm  (1<<15)  /* MS Accumulator Counter bit 15 mask. */
#define CTEMS_MSACCCNT15_bp  15  /* MS Accumulator Counter bit 15 position. */

/* CTEMS.MSACCCNTB  bit masks and bit positions */
/* CTEMS_MSACCCNT  is already defined. */

/* CTEMS.MSMAXA  bit masks and bit positions */
#define CTEMS_MSMAX_gm  0xFFFF  /* MS Max group mask. */
#define CTEMS_MSMAX_gp  0  /* MS Max group position. */
#define CTEMS_MSMAX0_bm  (1<<0)  /* MS Max bit 0 mask. */
#define CTEMS_MSMAX0_bp  0  /* MS Max bit 0 position. */
#define CTEMS_MSMAX1_bm  (1<<1)  /* MS Max bit 1 mask. */
#define CTEMS_MSMAX1_bp  1  /* MS Max bit 1 position. */
#define CTEMS_MSMAX2_bm  (1<<2)  /* MS Max bit 2 mask. */
#define CTEMS_MSMAX2_bp  2  /* MS Max bit 2 position. */
#define CTEMS_MSMAX3_bm  (1<<3)  /* MS Max bit 3 mask. */
#define CTEMS_MSMAX3_bp  3  /* MS Max bit 3 position. */
#define CTEMS_MSMAX4_bm  (1<<4)  /* MS Max bit 4 mask. */
#define CTEMS_MSMAX4_bp  4  /* MS Max bit 4 position. */
#define CTEMS_MSMAX5_bm  (1<<5)  /* MS Max bit 5 mask. */
#define CTEMS_MSMAX5_bp  5  /* MS Max bit 5 position. */
#define CTEMS_MSMAX6_bm  (1<<6)  /* MS Max bit 6 mask. */
#define CTEMS_MSMAX6_bp  6  /* MS Max bit 6 position. */
#define CTEMS_MSMAX7_bm  (1<<7)  /* MS Max bit 7 mask. */
#define CTEMS_MSMAX7_bp  7  /* MS Max bit 7 position. */
#define CTEMS_MSMAX8_bm  (1<<8)  /* MS Max bit 8 mask. */
#define CTEMS_MSMAX8_bp  8  /* MS Max bit 8 position. */
#define CTEMS_MSMAX9_bm  (1<<9)  /* MS Max bit 9 mask. */
#define CTEMS_MSMAX9_bp  9  /* MS Max bit 9 position. */
#define CTEMS_MSMAX10_bm  (1<<10)  /* MS Max bit 10 mask. */
#define CTEMS_MSMAX10_bp  10  /* MS Max bit 10 position. */
#define CTEMS_MSMAX11_bm  (1<<11)  /* MS Max bit 11 mask. */
#define CTEMS_MSMAX11_bp  11  /* MS Max bit 11 position. */
#define CTEMS_MSMAX12_bm  (1<<12)  /* MS Max bit 12 mask. */
#define CTEMS_MSMAX12_bp  12  /* MS Max bit 12 position. */
#define CTEMS_MSMAX13_bm  (1<<13)  /* MS Max bit 13 mask. */
#define CTEMS_MSMAX13_bp  13  /* MS Max bit 13 position. */
#define CTEMS_MSMAX14_bm  (1<<14)  /* MS Max bit 14 mask. */
#define CTEMS_MSMAX14_bp  14  /* MS Max bit 14 position. */
#define CTEMS_MSMAX15_bm  (1<<15)  /* MS Max bit 15 mask. */
#define CTEMS_MSMAX15_bp  15  /* MS Max bit 15 position. */

/* CTEMS.MSMAXB  bit masks and bit positions */
/* CTEMS_MSMAX  is already defined. */

/* CTEMS.MSMINA  bit masks and bit positions */
#define CTEMS_MSMIN_gm  0xFFFF  /* MS Min group mask. */
#define CTEMS_MSMIN_gp  0  /* MS Min group position. */
#define CTEMS_MSMIN0_bm  (1<<0)  /* MS Min bit 0 mask. */
#define CTEMS_MSMIN0_bp  0  /* MS Min bit 0 position. */
#define CTEMS_MSMIN1_bm  (1<<1)  /* MS Min bit 1 mask. */
#define CTEMS_MSMIN1_bp  1  /* MS Min bit 1 position. */
#define CTEMS_MSMIN2_bm  (1<<2)  /* MS Min bit 2 mask. */
#define CTEMS_MSMIN2_bp  2  /* MS Min bit 2 position. */
#define CTEMS_MSMIN3_bm  (1<<3)  /* MS Min bit 3 mask. */
#define CTEMS_MSMIN3_bp  3  /* MS Min bit 3 position. */
#define CTEMS_MSMIN4_bm  (1<<4)  /* MS Min bit 4 mask. */
#define CTEMS_MSMIN4_bp  4  /* MS Min bit 4 position. */
#define CTEMS_MSMIN5_bm  (1<<5)  /* MS Min bit 5 mask. */
#define CTEMS_MSMIN5_bp  5  /* MS Min bit 5 position. */
#define CTEMS_MSMIN6_bm  (1<<6)  /* MS Min bit 6 mask. */
#define CTEMS_MSMIN6_bp  6  /* MS Min bit 6 position. */
#define CTEMS_MSMIN7_bm  (1<<7)  /* MS Min bit 7 mask. */
#define CTEMS_MSMIN7_bp  7  /* MS Min bit 7 position. */
#define CTEMS_MSMIN8_bm  (1<<8)  /* MS Min bit 8 mask. */
#define CTEMS_MSMIN8_bp  8  /* MS Min bit 8 position. */
#define CTEMS_MSMIN9_bm  (1<<9)  /* MS Min bit 9 mask. */
#define CTEMS_MSMIN9_bp  9  /* MS Min bit 9 position. */
#define CTEMS_MSMIN10_bm  (1<<10)  /* MS Min bit 10 mask. */
#define CTEMS_MSMIN10_bp  10  /* MS Min bit 10 position. */
#define CTEMS_MSMIN11_bm  (1<<11)  /* MS Min bit 11 mask. */
#define CTEMS_MSMIN11_bp  11  /* MS Min bit 11 position. */
#define CTEMS_MSMIN12_bm  (1<<12)  /* MS Min bit 12 mask. */
#define CTEMS_MSMIN12_bp  12  /* MS Min bit 12 position. */
#define CTEMS_MSMIN13_bm  (1<<13)  /* MS Min bit 13 mask. */
#define CTEMS_MSMIN13_bp  13  /* MS Min bit 13 position. */
#define CTEMS_MSMIN14_bm  (1<<14)  /* MS Min bit 14 mask. */
#define CTEMS_MSMIN14_bp  14  /* MS Min bit 14 position. */
#define CTEMS_MSMIN15_bm  (1<<15)  /* MS Min bit 15 mask. */
#define CTEMS_MSMIN15_bp  15  /* MS Min bit 15 position. */

/* CTEMS.MSMINB  bit masks and bit positions */
/* CTEMS_MSMIN  is already defined. */

/* CTEMS.MSSHIFTRA  bit masks and bit positions */
#define CTEMS_MSSHIFTR_gm  0xFFFF  /* MS Shift Register group mask. */
#define CTEMS_MSSHIFTR_gp  0  /* MS Shift Register group position. */
#define CTEMS_MSSHIFTR0_bm  (1<<0)  /* MS Shift Register bit 0 mask. */
#define CTEMS_MSSHIFTR0_bp  0  /* MS Shift Register bit 0 position. */
#define CTEMS_MSSHIFTR1_bm  (1<<1)  /* MS Shift Register bit 1 mask. */
#define CTEMS_MSSHIFTR1_bp  1  /* MS Shift Register bit 1 position. */
#define CTEMS_MSSHIFTR2_bm  (1<<2)  /* MS Shift Register bit 2 mask. */
#define CTEMS_MSSHIFTR2_bp  2  /* MS Shift Register bit 2 position. */
#define CTEMS_MSSHIFTR3_bm  (1<<3)  /* MS Shift Register bit 3 mask. */
#define CTEMS_MSSHIFTR3_bp  3  /* MS Shift Register bit 3 position. */
#define CTEMS_MSSHIFTR4_bm  (1<<4)  /* MS Shift Register bit 4 mask. */
#define CTEMS_MSSHIFTR4_bp  4  /* MS Shift Register bit 4 position. */
#define CTEMS_MSSHIFTR5_bm  (1<<5)  /* MS Shift Register bit 5 mask. */
#define CTEMS_MSSHIFTR5_bp  5  /* MS Shift Register bit 5 position. */
#define CTEMS_MSSHIFTR6_bm  (1<<6)  /* MS Shift Register bit 6 mask. */
#define CTEMS_MSSHIFTR6_bp  6  /* MS Shift Register bit 6 position. */
#define CTEMS_MSSHIFTR7_bm  (1<<7)  /* MS Shift Register bit 7 mask. */
#define CTEMS_MSSHIFTR7_bp  7  /* MS Shift Register bit 7 position. */
#define CTEMS_MSSHIFTR8_bm  (1<<8)  /* MS Shift Register bit 8 mask. */
#define CTEMS_MSSHIFTR8_bp  8  /* MS Shift Register bit 8 position. */
#define CTEMS_MSSHIFTR9_bm  (1<<9)  /* MS Shift Register bit 9 mask. */
#define CTEMS_MSSHIFTR9_bp  9  /* MS Shift Register bit 9 position. */
#define CTEMS_MSSHIFTR10_bm  (1<<10)  /* MS Shift Register bit 10 mask. */
#define CTEMS_MSSHIFTR10_bp  10  /* MS Shift Register bit 10 position. */
#define CTEMS_MSSHIFTR11_bm  (1<<11)  /* MS Shift Register bit 11 mask. */
#define CTEMS_MSSHIFTR11_bp  11  /* MS Shift Register bit 11 position. */
#define CTEMS_MSSHIFTR12_bm  (1<<12)  /* MS Shift Register bit 12 mask. */
#define CTEMS_MSSHIFTR12_bp  12  /* MS Shift Register bit 12 position. */
#define CTEMS_MSSHIFTR13_bm  (1<<13)  /* MS Shift Register bit 13 mask. */
#define CTEMS_MSSHIFTR13_bp  13  /* MS Shift Register bit 13 position. */
#define CTEMS_MSSHIFTR14_bm  (1<<14)  /* MS Shift Register bit 14 mask. */
#define CTEMS_MSSHIFTR14_bp  14  /* MS Shift Register bit 14 position. */
#define CTEMS_MSSHIFTR15_bm  (1<<15)  /* MS Shift Register bit 15 mask. */
#define CTEMS_MSSHIFTR15_bp  15  /* MS Shift Register bit 15 position. */

/* CTEMS.MSSHIFTRB  bit masks and bit positions */
/* CTEMS_MSSHIFTR  is already defined. */

/* CTEMS.MSACCSR  bit masks and bit positions */
#define CTEMS_MSCNTOVFLA_bm  0x01  /* MS Counter Overflow A bit mask. */
#define CTEMS_MSCNTOVFLA_bp  0  /* MS Counter Overflow A bit position. */
#define CTEMS_MSCNTOVFLB_bm  0x02  /* MS Counter Overflow B bit mask. */
#define CTEMS_MSCNTOVFLB_bp  1  /* MS Counter Overflow B bit position. */
#define CTEMS_MSACCOVFLA_bm  0x04  /* MS Accumulator Overflow A bit mask. */
#define CTEMS_MSACCOVFLA_bp  2  /* MS Accumulator Overflow A bit position. */
#define CTEMS_MSACCOVFLB_bm  0x08  /* MS Accumulator Overflow B bit mask. */
#define CTEMS_MSACCOVFLB_bp  3  /* MS Accumulator Overflow B bit position. */

/* CTEMS.MSCRCCLR  bit masks and bit positions */
#define CTEMS_MSACCMULA_bm  0x01  /* MS Accumulate Multiplier Result A bit mask. */
#define CTEMS_MSACCMULA_bp  0  /* MS Accumulate Multiplier Result A bit position. */
#define CTEMS_MSACCMULB_bm  0x02  /* MS Accumulate Multiplier Result B bit mask. */
#define CTEMS_MSACCMULB_bp  1  /* MS Accumulate Multiplier Result B bit position. */
#define CTEMS_MSSUBMULA_bm  0x04  /* MS Subtract Multiplier Result A bit mask. */
#define CTEMS_MSSUBMULA_bp  2  /* MS Subtract Multiplier Result A bit position. */
#define CTEMS_MSSUBMULB_bm  0x08  /* MS Subtract Multiplier Result B bit mask. */
#define CTEMS_MSSUBMULB_bp  3  /* MS Subtract Multiplier Result B bit position. */
#define CTEMS_MSSMODEA_bm  0x10  /* MS Signed Mode A bit mask. */
#define CTEMS_MSSMODEA_bp  4  /* MS Signed Mode A bit position. */
#define CTEMS_MSSMODEB_bm  0x20  /* MS Signed Mode B bit mask. */
#define CTEMS_MSSMODEB_bp  5  /* MS Signed Mode B bit position. */
#define CTEMS_MSDMAPSA_bm  0x40  /* Double map select for which memory to connect bit mask. */
#define CTEMS_MSDMAPSA_bp  6  /* Double map select for which memory to connect bit position. */
#define CTEMS_MSDMAPSB_bm  0x80  /* Double map select for which memory to connect bit mask. */
#define CTEMS_MSDMAPSB_bp  7  /* Double map select for which memory to connect bit position. */
#define CTEMS_MSACCMMA_bm  0x100  /* MS Accumulate and Max/Min A bit mask. */
#define CTEMS_MSACCMMA_bp  8  /* MS Accumulate and Max/Min A bit position. */
#define CTEMS_MSACCMMB_bm  0x200  /* MS Accumulate and Max/Min B bit mask. */
#define CTEMS_MSACCMMB_bp  9  /* MS Accumulate and Max/Min B bit position. */

/* CTEMS.MSCRCSET  bit masks and bit positions */
/* CTEMS_MSACCMULA  is already defined. */
/* CTEMS_MSACCMULB  is already defined. */
/* CTEMS_MSSUBMULA  is already defined. */
/* CTEMS_MSSUBMULB  is already defined. */
/* CTEMS_MSSMODEA  is already defined. */
/* CTEMS_MSSMODEB  is already defined. */
/* CTEMS_MSDMAPSA  is already defined. */
/* CTEMS_MSDMAPSB  is already defined. */
/* CTEMS_MSACCMMA  is already defined. */
/* CTEMS_MSACCMMB  is already defined. */

/* CTEMS.MSCRA  bit masks and bit positions */
#define CTEMS_MSBE_bm  0x01  /* MS Break Enable bit mask. */
#define CTEMS_MSBE_bp  0  /* MS Break Enable bit position. */
#define CTEMS_MSIL_gm  0x06  /* MS Interrupt Level group mask. */
#define CTEMS_MSIL_gp  1  /* MS Interrupt Level group position. */
#define CTEMS_MSIL0_bm  (1<<1)  /* MS Interrupt Level bit 0 mask. */
#define CTEMS_MSIL0_bp  1  /* MS Interrupt Level bit 0 position. */
#define CTEMS_MSIL1_bm  (1<<2)  /* MS Interrupt Level bit 1 mask. */
#define CTEMS_MSIL1_bp  2  /* MS Interrupt Level bit 1 position. */
#define CTEMS_MSSEXT_bm  0x10  /* MS Sign Extend LD[M].B bit mask. */
#define CTEMS_MSSEXT_bp  4  /* MS Sign Extend LD[M].B bit position. */
#define CTEMS_MSDDZC_bm  0x20  /* MS Disable Division by Zero Check bit mask. */
#define CTEMS_MSDDZC_bp  5  /* MS Disable Division by Zero Check bit position. */
#define CTEMS_MSSAT6S_bm  0x40  /* MS Signed SAT6 bit mask. */
#define CTEMS_MSSAT6S_bp  6  /* MS Signed SAT6 bit position. */

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
#define CTEMS_GCAFCCCNZ_bm  0x20  /* GCAF Computation Complete Counter Not Zero flag bit mask. */
#define CTEMS_GCAFCCCNZ_bp  5  /* GCAF Computation Complete Counter Not Zero flag bit position. */
#define CTEMS_GCAFCCCZ_bm  0x40  /* GCAF Computation Complete Counter Zero flag bit mask. */
#define CTEMS_GCAFCCCZ_bp  6  /* GCAF Computation Complete Counter Zero flag bit position. */
#define CTEMS_MSADCSYNC_bm  0x80  /* MS ADC Synchronization bit bit mask. */
#define CTEMS_MSADCSYNC_bp  7  /* MS ADC Synchronization bit bit position. */

/* CTEMS.MSSRASET  bit masks and bit positions */
/* CTEMS_MSTCUNF  is already defined. */
/* CTEMS_MSHSF  is already defined. */
/* CTEMS_GCAFCCCNZ  is already defined. */
/* CTEMS_GCAFCCCZ  is already defined. */
/* CTEMS_MSADCSYNC  is already defined. */

/* CTEMS.MSSRB  bit masks and bit positions */
/* CTEMS_MSTCUNF  is already defined. */
#define CTEMS_PIFXPIN1_bm  0x02  /* Mapped PIFXPIN bit 1 from PIFXPIN bit mask. */
#define CTEMS_PIFXPIN1_bp  1  /* Mapped PIFXPIN bit 1 from PIFXPIN bit position. */
#define CTEMS_PIFXPIN2_bm  0x04  /* Mapped PIFXPIN bit 2 from PIFXPIN bit mask. */
#define CTEMS_PIFXPIN2_bp  2  /* Mapped PIFXPIN bit 2 from PIFXPIN bit position. */
#define CTEMS_PIFXPIN3_bm  0x08  /* Mapped PIFXPIN bit 3 from PIFXPIN bit mask. */
#define CTEMS_PIFXPIN3_bp  3  /* Mapped PIFXPIN bit 3 from PIFXPIN bit position. */
#define CTEMS_PIFXPIN4_bm  0x10  /* Mapped PIFXPIN bit 4 from PIFXPIN bit mask. */
#define CTEMS_PIFXPIN4_bp  4  /* Mapped PIFXPIN bit 4 from PIFXPIN bit position. */
#define CTEMS_PIFXPIN5_bm  0x20  /* Mapped PIFXPIN bit 5 from PIFXPIN bit mask. */
#define CTEMS_PIFXPIN5_bp  5  /* Mapped PIFXPIN bit 5 from PIFXPIN bit position. */
#define CTEMS_PIFPC2_bm  0x40  /* Mapped PC2 from PORTC bit mask. */
#define CTEMS_PIFPC2_bp  6  /* Mapped PC2 from PORTC bit position. */
#define CTEMS_PIFPC6_bm  0x80  /* Mapped PC6 from PORTC bit mask. */
#define CTEMS_PIFPC6_bp  7  /* Mapped PC6 from PORTC bit position. */

/* CTEMS.MSSRC  bit masks and bit positions */
/* CTEMS_MSTCUNF  is already defined. */
#define CTEMS_TIMADONE_bm  0x02  /* Timer A Done bit mask. */
#define CTEMS_TIMADONE_bp  1  /* Timer A Done bit position. */
#define CTEMS_TIMBDONE_bm  0x04  /* Timer B Done bit mask. */
#define CTEMS_TIMBDONE_bp  2  /* Timer B Done bit position. */
#define CTEMS_TIMCDONE_bm  0x08  /* Timer C Done bit mask. */
#define CTEMS_TIMCDONE_bp  3  /* Timer C Done bit position. */
#define CTEMS_INTMOEDONE_bm  0x10  /* Integrator Master Output Enable Done bit mask. */
#define CTEMS_INTMOEDONE_bp  4  /* Integrator Master Output Enable Done bit position. */
#define CTEMS_INTRSTDONE_bm  0x20  /* Integrator Reset Done bit mask. */
#define CTEMS_INTRSTDONE_bp  5  /* Integrator Reset Done bit position. */
#define CTEMS_SHADCDONE_bm  0x40  /* S/H and ADC Trigger Done. Writing a '1' to SHADCDONE bit will trigger SHADCTRIG. bit mask. */
#define CTEMS_SHADCDONE_bp  6  /* S/H and ADC Trigger Done. Writing a '1' to SHADCDONE bit will trigger SHADCTRIG. bit position. */
#define CTEMS_ALLDONE_bm  0x80  /* All Timers Done. Writing a '1' to ALLDONE   bit will trigger INTXRDY bit mask. */
#define CTEMS_ALLDONE_bp  7  /* All Timers Done. Writing a '1' to ALLDONE   bit will trigger INTXRDY bit position. */

/* CTEMS.MSSRD  bit masks and bit positions */
/* CTEMS_MSTCUNF  is already defined. */
#define CTEMS_GCAFCCCWL_bm  0x20  /* GCAF Computation Complete Counter Within Limit bit mask. */
#define CTEMS_GCAFCCCWL_bp  5  /* GCAF Computation Complete Counter Within Limit bit position. */
#define CTEMS_GCAFIDLE_bm  0x40  /* GCAF Idle bit mask. */
#define CTEMS_GCAFIDLE_bp  6  /* GCAF Idle bit position. */

/* CTEMS.MSSRE  bit masks and bit positions */
/* CTEMS_MSTCUNF  is already defined. */
#define CTEMS_MSHDLCLR_bm  0x02  /* Any Headroom Detector Low output is cleared bit mask. */
#define CTEMS_MSHDLCLR_bp  1  /* Any Headroom Detector Low output is cleared bit position. */
#define CTEMS_MSHDLSET_bm  0x04  /* Any Headroom Detector Low output is set bit mask. */
#define CTEMS_MSHDLSET_bp  2  /* Any Headroom Detector Low output is set bit position. */
#define CTEMS_MSHDHCLR_bm  0x08  /* Any Headroom Detector High output is cleared bit mask. */
#define CTEMS_MSHDHCLR_bp  3  /* Any Headroom Detector High output is cleared bit position. */
#define CTEMS_MSHDHSET_bm  0x10  /* Any Headroom Detector High output is set bit mask. */
#define CTEMS_MSHDHSET_bp  4  /* Any Headroom Detector High output is set bit position. */

/* CTEMS.MSCCR  bit masks and bit positions */
#define CTEMS_CW_bm  0x01  /* Carry Word bit mask. */
#define CTEMS_CW_bp  0  /* Carry Word bit position. */
#define CTEMS_SW_bm  0x02  /* Signed Word bit mask. */
#define CTEMS_SW_bp  1  /* Signed Word bit position. */
#define CTEMS_PW_bm  0x04  /* Positive Word bit mask. */
#define CTEMS_PW_bp  2  /* Positive Word bit position. */
#define CTEMS_ZW_bm  0x08  /* Zero Word bit mask. */
#define CTEMS_ZW_bp  3  /* Zero Word bit position. */
#define CTEMS_T_gm  0xF0  /* T[3:0] temp flags group mask. */
#define CTEMS_T_gp  4  /* T[3:0] temp flags group position. */
#define CTEMS_T0_bm  (1<<4)  /* T[3:0] temp flags bit 0 mask. */
#define CTEMS_T0_bp  4  /* T[3:0] temp flags bit 0 position. */
#define CTEMS_T1_bm  (1<<5)  /* T[3:0] temp flags bit 1 mask. */
#define CTEMS_T1_bp  5  /* T[3:0] temp flags bit 1 position. */
#define CTEMS_T2_bm  (1<<6)  /* T[3:0] temp flags bit 2 mask. */
#define CTEMS_T2_bp  6  /* T[3:0] temp flags bit 2 position. */
#define CTEMS_T3_bm  (1<<7)  /* T[3:0] temp flags bit 3 mask. */
#define CTEMS_T3_bp  7  /* T[3:0] temp flags bit 3 position. */

/* CTEMS.MSLINK  bit masks and bit positions */
#define CTEMS_MSLINK_gm  0x1FFF  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) group mask. */
#define CTEMS_MSLINK_gp  0  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) group position. */
#define CTEMS_MSLINK0_bm  (1<<0)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 0 mask. */
#define CTEMS_MSLINK0_bp  0  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 0 position. */
#define CTEMS_MSLINK1_bm  (1<<1)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 1 mask. */
#define CTEMS_MSLINK1_bp  1  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 1 position. */
#define CTEMS_MSLINK2_bm  (1<<2)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 2 mask. */
#define CTEMS_MSLINK2_bp  2  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 2 position. */
#define CTEMS_MSLINK3_bm  (1<<3)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 3 mask. */
#define CTEMS_MSLINK3_bp  3  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 3 position. */
#define CTEMS_MSLINK4_bm  (1<<4)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 4 mask. */
#define CTEMS_MSLINK4_bp  4  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 4 position. */
#define CTEMS_MSLINK5_bm  (1<<5)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 5 mask. */
#define CTEMS_MSLINK5_bp  5  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 5 position. */
#define CTEMS_MSLINK6_bm  (1<<6)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 6 mask. */
#define CTEMS_MSLINK6_bp  6  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 6 position. */
#define CTEMS_MSLINK7_bm  (1<<7)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 7 mask. */
#define CTEMS_MSLINK7_bp  7  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 7 position. */
#define CTEMS_MSLINK8_bm  (1<<8)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 8 mask. */
#define CTEMS_MSLINK8_bp  8  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 8 position. */
#define CTEMS_MSLINK9_bm  (1<<9)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 9 mask. */
#define CTEMS_MSLINK9_bp  9  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 9 position. */
#define CTEMS_MSLINK10_bm  (1<<10)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 10 mask. */
#define CTEMS_MSLINK10_bp  10  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 10 position. */
#define CTEMS_MSLINK11_bm  (1<<11)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 11 mask. */
#define CTEMS_MSLINK11_bp  11  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 11 position. */
#define CTEMS_MSLINK12_bm  (1<<12)  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 12 mask. */
#define CTEMS_MSLINK12_bp  12  /* uS 1 has 13 bit, and uS 0 has 12 bit (bit 12 is unused) bit 12 position. */

/* CTE.ADCYCHR  bit masks and bit positions */
#define CTE_ADCYCH_gm  0x1F  /* ADC Y-Channel group mask. */
#define CTE_ADCYCH_gp  0  /* ADC Y-Channel group position. */
#define CTE_ADCYCH0_bm  (1<<0)  /* ADC Y-Channel bit 0 mask. */
#define CTE_ADCYCH0_bp  0  /* ADC Y-Channel bit 0 position. */
#define CTE_ADCYCH1_bm  (1<<1)  /* ADC Y-Channel bit 1 mask. */
#define CTE_ADCYCH1_bp  1  /* ADC Y-Channel bit 1 position. */
#define CTE_ADCYCH2_bm  (1<<2)  /* ADC Y-Channel bit 2 mask. */
#define CTE_ADCYCH2_bp  2  /* ADC Y-Channel bit 2 position. */
#define CTE_ADCYCH3_bm  (1<<3)  /* ADC Y-Channel bit 3 mask. */
#define CTE_ADCYCH3_bp  3  /* ADC Y-Channel bit 3 position. */
#define CTE_ADCYCH4_bm  (1<<4)  /* ADC Y-Channel bit 4 mask. */
#define CTE_ADCYCH4_bp  4  /* ADC Y-Channel bit 4 position. */
#define CTE_ADCSC_bm  0x20  /* ADC Single Conversion bit mask. */
#define CTE_ADCSC_bp  5  /* ADC Single Conversion bit position. */
#define CTE_ADCAUX_bm  0x40  /* ADC Auxillary Channel Enable bit mask. */
#define CTE_ADCAUX_bp  6  /* ADC Auxillary Channel Enable bit position. */

/* CTE.INTCRC  bit masks and bit positions */
#define CTE_INTRSTLVL_gm  0xFF  /* Integrator Reset Level group mask. */
#define CTE_INTRSTLVL_gp  0  /* Integrator Reset Level group position. */
#define CTE_INTRSTLVL0_bm  (1<<0)  /* Integrator Reset Level bit 0 mask. */
#define CTE_INTRSTLVL0_bp  0  /* Integrator Reset Level bit 0 position. */
#define CTE_INTRSTLVL1_bm  (1<<1)  /* Integrator Reset Level bit 1 mask. */
#define CTE_INTRSTLVL1_bp  1  /* Integrator Reset Level bit 1 position. */
#define CTE_INTRSTLVL2_bm  (1<<2)  /* Integrator Reset Level bit 2 mask. */
#define CTE_INTRSTLVL2_bp  2  /* Integrator Reset Level bit 2 position. */
#define CTE_INTRSTLVL3_bm  (1<<3)  /* Integrator Reset Level bit 3 mask. */
#define CTE_INTRSTLVL3_bp  3  /* Integrator Reset Level bit 3 position. */
#define CTE_INTRSTLVL4_bm  (1<<4)  /* Integrator Reset Level bit 4 mask. */
#define CTE_INTRSTLVL4_bp  4  /* Integrator Reset Level bit 4 position. */
#define CTE_INTRSTLVL5_bm  (1<<5)  /* Integrator Reset Level bit 5 mask. */
#define CTE_INTRSTLVL5_bp  5  /* Integrator Reset Level bit 5 position. */
#define CTE_INTRSTLVL6_bm  (1<<6)  /* Integrator Reset Level bit 6 mask. */
#define CTE_INTRSTLVL6_bp  6  /* Integrator Reset Level bit 6 position. */
#define CTE_INTRSTLVL7_bm  (1<<7)  /* Integrator Reset Level bit 7 mask. */
#define CTE_INTRSTLVL7_bp  7  /* Integrator Reset Level bit 7 position. */

/* CTE.ADCSRACLR  bit masks and bit positions */
#define CTE_ADCLC_bm  0x01  /* ADC Last Conversion bit mask. */
#define CTE_ADCLC_bp  0  /* ADC Last Conversion bit position. */
#define CTE_ADCLCX_bm  0x02  /* ADC Last Conversion in X-Line bit mask. */
#define CTE_ADCLCX_bp  1  /* ADC Last Conversion in X-Line bit position. */
#define CTE_ADCVC_bm  0x04  /* ADC Valid Conversion bit mask. */
#define CTE_ADCVC_bp  2  /* ADC Valid Conversion bit position. */
#define CTE_ADCPS_bm  0x08  /* ADC Power Save bit mask. */
#define CTE_ADCPS_bp  3  /* ADC Power Save bit position. */
#define CTE_ADCBUSY_bm  0x10  /* First Stage of ADC Sampling Valid Data bit mask. */
#define CTE_ADCBUSY_bp  4  /* First Stage of ADC Sampling Valid Data bit position. */
#define CTE_ADCPIPEBUSY_bm  0x20  /* Valid Data in ADC Pipeline Register bit mask. */
#define CTE_ADCPIPEBUSY_bp  5  /* Valid Data in ADC Pipeline Register bit position. */
#define CTE_ADCANAPIPEBUSY_bm  0x40  /* Valid Samples in Analog Pipeline bit mask. */
#define CTE_ADCANAPIPEBUSY_bp  6  /* Valid Samples in Analog Pipeline bit position. */

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
#define CTE_TIMA_bm  0x02  /* Timer A bit mask. */
#define CTE_TIMA_bp  1  /* Timer A bit position. */
#define CTE_TIMB_bm  0x04  /* Timer B bit mask. */
#define CTE_TIMB_bp  2  /* Timer B bit position. */
#define CTE_TIMC_bm  0x08  /* Timer C bit mask. */
#define CTE_TIMC_bp  3  /* Timer C bit position. */
#define CTE_INTMOE_bm  0x10  /* Integrator Master Output Enable bit mask. */
#define CTE_INTMOE_bp  4  /* Integrator Master Output Enable bit position. */
#define CTE_INTRST_bm  0x20  /* Integrator Reset bit mask. */
#define CTE_INTRST_bp  5  /* Integrator Reset bit position. */
#define CTE_INTDBULKPWR_bm  0x40  /* Connects bulk dummy to Avdd bit mask. */
#define CTE_INTDBULKPWR_bp  6  /* Connects bulk dummy to Avdd bit position. */
#define CTE_INTID_bm  0x80  /* Integrator Input Disable bit mask. */
#define CTE_INTID_bp  7  /* Integrator Input Disable bit position. */
#define CTE_INTAUTOCAL_gm  0x300  /* Integrator Automatic Calibration group mask. */
#define CTE_INTAUTOCAL_gp  8  /* Integrator Automatic Calibration group position. */
#define CTE_INTAUTOCAL0_bm  (1<<8)  /* Integrator Automatic Calibration bit 0 mask. */
#define CTE_INTAUTOCAL0_bp  8  /* Integrator Automatic Calibration bit 0 position. */
#define CTE_INTAUTOCAL1_bm  (1<<9)  /* Integrator Automatic Calibration bit 1 mask. */
#define CTE_INTAUTOCAL1_bp  9  /* Integrator Automatic Calibration bit 1 position. */
#define CTE_INTIBUFD_bm  0x400  /* Integrator Input Buffer Disable bit mask. */
#define CTE_INTIBUFD_bp  10  /* Integrator Input Buffer Disable bit position. */
#define CTE_INTIAMPOD_bm  0x800  /* Integrator Current Amplifier Output Disable bit mask. */
#define CTE_INTIAMPOD_bp  11  /* Integrator Current Amplifier Output Disable bit position. */
#define CTE_INTIBULKPWR_bm  0x1000  /* Connects bulk of input sw to Avdd bit mask. */
#define CTE_INTIBULKPWR_bp  12  /* Connects bulk of input sw to Avdd bit position. */
#define CTE_INTDIBUFD_bm  0x2000  /* Integrator Dummy Input Buffer Disable bit mask. */
#define CTE_INTDIBUFD_bp  13  /* Integrator Dummy Input Buffer Disable bit position. */

/* CTE.INTCRBSET  bit masks and bit positions */
/* CTE_INTSIGN  is already defined. */
/* CTE_TIMA  is already defined. */
/* CTE_TIMB  is already defined. */
/* CTE_TIMC  is already defined. */
/* CTE_INTMOE  is already defined. */
/* CTE_INTRST  is already defined. */
/* CTE_INTDBULKPWR  is already defined. */
/* CTE_INTID  is already defined. */
/* CTE_INTAUTOCAL  is already defined. */
/* CTE_INTIBUFD  is already defined. */
/* CTE_INTIAMPOD  is already defined. */
/* CTE_INTIBULKPWR  is already defined. */
/* CTE_INTDIBUFD  is already defined. */

/* CTE.INTCRECLR  bit masks and bit positions */
#define CTE_SCMOE_bm  0x01  /* Selfcap Master Output Enable bit mask. */
#define CTE_SCMOE_bp  0  /* Selfcap Master Output Enable bit position. */
#define CTE_SCCFGSEL_bm  0x02  /* Selfcap Configuration Select bit mask. */
#define CTE_SCCFGSEL_bp  1  /* Selfcap Configuration Select bit position. */
#define CTE_INTBYPASSX_bm  0x04  /* Integrator Bypass X bit mask. */
#define CTE_INTBYPASSX_bp  2  /* Integrator Bypass X bit position. */
#define CTE_INTBYPASSY_bm  0x08  /* Integrator Bypass Y bit mask. */
#define CTE_INTBYPASSY_bp  3  /* Integrator Bypass Y bit position. */
#define CTE_INTYONXEN_bm  0x10  /* Integrator Y-on-X Enable bit mask. */
#define CTE_INTYONXEN_bp  4  /* Integrator Y-on-X Enable bit position. */
#define CTE_INTSCCSNEN_bm  0x20  /* Integrator selfcap current source nmos enable bit mask. */
#define CTE_INTSCCSNEN_bp  5  /* Integrator selfcap current source nmos enable bit position. */
#define CTE_INTSCCSPEN_bm  0x40  /* Integrator selfcap current source pmos enable bit mask. */
#define CTE_INTSCCSPEN_bp  6  /* Integrator selfcap current source pmos enable bit position. */
#define CTE_INTCHCEN_bm  0x80  /* Integrator Charge compensation enable bit mask. */
#define CTE_INTCHCEN_bp  7  /* Integrator Charge compensation enable bit position. */
#define CTE_INTCINTPU_bm  0x100  /* Integrator Cint pullup bit mask. */
#define CTE_INTCINTPU_bp  8  /* Integrator Cint pullup bit position. */
#define CTE_INTCINTPD_bm  0x200  /* Integrator Cint pulldown bit mask. */
#define CTE_INTCINTPD_bp  9  /* Integrator Cint pulldown bit position. */
#define CTE_INTPROXPDEN_bm  0x400  /* Integrator XY pad prox pulldown enable bit mask. */
#define CTE_INTPROXPDEN_bp  10  /* Integrator XY pad prox pulldown enable bit position. */
#define CTE_INTSCAPREF_bm  0x800  /* Integrator selfcap Y-input DC voltage bit mask. */
#define CTE_INTSCAPREF_bp  11  /* Integrator selfcap Y-input DC voltage bit position. */
#define CTE_INTXYRESEN_bm  0x1000  /* Enables dummy input conn to high resistive input bit mask. */
#define CTE_INTXYRESEN_bp  12  /* Enables dummy input conn to high resistive input bit position. */
#define CTE_INTYONXPDEN_bm  0x2000  /* Enables pulldown for int YonX bit mask. */
#define CTE_INTYONXPDEN_bp  13  /* Enables pulldown for int YonX bit position. */
#define CTE_INTPROXREFCON_bm  0x4000  /* Integrator Proximity Reference Connect bit mask. */
#define CTE_INTPROXREFCON_bp  14  /* Integrator Proximity Reference Connect bit position. */
#define CTE_INTPROXREFEN_bm  0x8000  /* Integrator Proximity Reference Enable bit mask. */
#define CTE_INTPROXREFEN_bp  15  /* Integrator Proximity Reference Enable bit position. */

/* CTE.INTCRESET  bit masks and bit positions */
/* CTE_SCMOE  is already defined. */
/* CTE_SCCFGSEL  is already defined. */
/* CTE_INTBYPASSX  is already defined. */
/* CTE_INTBYPASSY  is already defined. */
/* CTE_INTYONXEN  is already defined. */
/* CTE_INTSCCSNEN  is already defined. */
/* CTE_INTSCCSPEN  is already defined. */
/* CTE_INTCHCEN  is already defined. */
/* CTE_INTCINTPU  is already defined. */
/* CTE_INTCINTPD  is already defined. */
/* CTE_INTPROXPDEN  is already defined. */
/* CTE_INTSCAPREF  is already defined. */
/* CTE_INTXYRESEN  is already defined. */
/* CTE_INTYONXPDEN  is already defined. */
/* CTE_INTPROXREFCON  is already defined. */
/* CTE_INTPROXREFEN  is already defined. */

/* CTE.INTXCHR  bit masks and bit positions */
#define CTE_INTXCH_gm  0x3F  /* Integrator X-channel group mask. */
#define CTE_INTXCH_gp  0  /* Integrator X-channel group position. */
#define CTE_INTXCH0_bm  (1<<0)  /* Integrator X-channel bit 0 mask. */
#define CTE_INTXCH0_bp  0  /* Integrator X-channel bit 0 position. */
#define CTE_INTXCH1_bm  (1<<1)  /* Integrator X-channel bit 1 mask. */
#define CTE_INTXCH1_bp  1  /* Integrator X-channel bit 1 position. */
#define CTE_INTXCH2_bm  (1<<2)  /* Integrator X-channel bit 2 mask. */
#define CTE_INTXCH2_bp  2  /* Integrator X-channel bit 2 position. */
#define CTE_INTXCH3_bm  (1<<3)  /* Integrator X-channel bit 3 mask. */
#define CTE_INTXCH3_bp  3  /* Integrator X-channel bit 3 position. */
#define CTE_INTXCH4_bm  (1<<4)  /* Integrator X-channel bit 4 mask. */
#define CTE_INTXCH4_bp  4  /* Integrator X-channel bit 4 position. */
#define CTE_INTXCH5_bm  (1<<5)  /* Integrator X-channel bit 5 mask. */
#define CTE_INTXCH5_bp  5  /* Integrator X-channel bit 5 position. */

/* CTE.INTOENA  bit masks and bit positions */
#define CTE_INTOEN_gm  0xFFFF  /* Integrator Output Enable group mask. */
#define CTE_INTOEN_gp  0  /* Integrator Output Enable group position. */
#define CTE_INTOEN0_bm  (1<<0)  /* Integrator Output Enable bit 0 mask. */
#define CTE_INTOEN0_bp  0  /* Integrator Output Enable bit 0 position. */
#define CTE_INTOEN1_bm  (1<<1)  /* Integrator Output Enable bit 1 mask. */
#define CTE_INTOEN1_bp  1  /* Integrator Output Enable bit 1 position. */
#define CTE_INTOEN2_bm  (1<<2)  /* Integrator Output Enable bit 2 mask. */
#define CTE_INTOEN2_bp  2  /* Integrator Output Enable bit 2 position. */
#define CTE_INTOEN3_bm  (1<<3)  /* Integrator Output Enable bit 3 mask. */
#define CTE_INTOEN3_bp  3  /* Integrator Output Enable bit 3 position. */
#define CTE_INTOEN4_bm  (1<<4)  /* Integrator Output Enable bit 4 mask. */
#define CTE_INTOEN4_bp  4  /* Integrator Output Enable bit 4 position. */
#define CTE_INTOEN5_bm  (1<<5)  /* Integrator Output Enable bit 5 mask. */
#define CTE_INTOEN5_bp  5  /* Integrator Output Enable bit 5 position. */
#define CTE_INTOEN6_bm  (1<<6)  /* Integrator Output Enable bit 6 mask. */
#define CTE_INTOEN6_bp  6  /* Integrator Output Enable bit 6 position. */
#define CTE_INTOEN7_bm  (1<<7)  /* Integrator Output Enable bit 7 mask. */
#define CTE_INTOEN7_bp  7  /* Integrator Output Enable bit 7 position. */
#define CTE_INTOEN8_bm  (1<<8)  /* Integrator Output Enable bit 8 mask. */
#define CTE_INTOEN8_bp  8  /* Integrator Output Enable bit 8 position. */
#define CTE_INTOEN9_bm  (1<<9)  /* Integrator Output Enable bit 9 mask. */
#define CTE_INTOEN9_bp  9  /* Integrator Output Enable bit 9 position. */
#define CTE_INTOEN10_bm  (1<<10)  /* Integrator Output Enable bit 10 mask. */
#define CTE_INTOEN10_bp  10  /* Integrator Output Enable bit 10 position. */
#define CTE_INTOEN11_bm  (1<<11)  /* Integrator Output Enable bit 11 mask. */
#define CTE_INTOEN11_bp  11  /* Integrator Output Enable bit 11 position. */
#define CTE_INTOEN12_bm  (1<<12)  /* Integrator Output Enable bit 12 mask. */
#define CTE_INTOEN12_bp  12  /* Integrator Output Enable bit 12 position. */
#define CTE_INTOEN13_bm  (1<<13)  /* Integrator Output Enable bit 13 mask. */
#define CTE_INTOEN13_bp  13  /* Integrator Output Enable bit 13 position. */
#define CTE_INTOEN14_bm  (1<<14)  /* Integrator Output Enable bit 14 mask. */
#define CTE_INTOEN14_bp  14  /* Integrator Output Enable bit 14 position. */
#define CTE_INTOEN15_bm  (1<<15)  /* Integrator Output Enable bit 15 mask. */
#define CTE_INTOEN15_bp  15  /* Integrator Output Enable bit 15 position. */

/* CTE.INTOENB  bit masks and bit positions */
/* CTE_INTOEN  is already defined. */

/* CTE.TIMMOECMP  bit masks and bit positions */
#define CTE_TIMMOECMP_gm  0x3FF  /* Timer Master Output Enable Compare group mask. */
#define CTE_TIMMOECMP_gp  0  /* Timer Master Output Enable Compare group position. */
#define CTE_TIMMOECMP0_bm  (1<<0)  /* Timer Master Output Enable Compare bit 0 mask. */
#define CTE_TIMMOECMP0_bp  0  /* Timer Master Output Enable Compare bit 0 position. */
#define CTE_TIMMOECMP1_bm  (1<<1)  /* Timer Master Output Enable Compare bit 1 mask. */
#define CTE_TIMMOECMP1_bp  1  /* Timer Master Output Enable Compare bit 1 position. */
#define CTE_TIMMOECMP2_bm  (1<<2)  /* Timer Master Output Enable Compare bit 2 mask. */
#define CTE_TIMMOECMP2_bp  2  /* Timer Master Output Enable Compare bit 2 position. */
#define CTE_TIMMOECMP3_bm  (1<<3)  /* Timer Master Output Enable Compare bit 3 mask. */
#define CTE_TIMMOECMP3_bp  3  /* Timer Master Output Enable Compare bit 3 position. */
#define CTE_TIMMOECMP4_bm  (1<<4)  /* Timer Master Output Enable Compare bit 4 mask. */
#define CTE_TIMMOECMP4_bp  4  /* Timer Master Output Enable Compare bit 4 position. */
#define CTE_TIMMOECMP5_bm  (1<<5)  /* Timer Master Output Enable Compare bit 5 mask. */
#define CTE_TIMMOECMP5_bp  5  /* Timer Master Output Enable Compare bit 5 position. */
#define CTE_TIMMOECMP6_bm  (1<<6)  /* Timer Master Output Enable Compare bit 6 mask. */
#define CTE_TIMMOECMP6_bp  6  /* Timer Master Output Enable Compare bit 6 position. */
#define CTE_TIMMOECMP7_bm  (1<<7)  /* Timer Master Output Enable Compare bit 7 mask. */
#define CTE_TIMMOECMP7_bp  7  /* Timer Master Output Enable Compare bit 7 position. */
#define CTE_TIMMOECMP8_bm  (1<<8)  /* Timer Master Output Enable Compare bit 8 mask. */
#define CTE_TIMMOECMP8_bp  8  /* Timer Master Output Enable Compare bit 8 position. */
#define CTE_TIMMOECMP9_bm  (1<<9)  /* Timer Master Output Enable Compare bit 9 mask. */
#define CTE_TIMMOECMP9_bp  9  /* Timer Master Output Enable Compare bit 9 position. */

/* CTE.HVCRA  bit masks and bit positions */
#define CTE_HVPEN_bm  0x01  /* High Voltage Pump Enable bit mask. */
#define CTE_HVPEN_bp  0  /* High Voltage Pump Enable bit position. */
#define CTE_HVSWEN_bm  0x02  /* High Voltage Switch Enable bit mask. */
#define CTE_HVSWEN_bp  1  /* High Voltage Switch Enable bit position. */
#define CTE_HVSEQEN_bm  0x04  /* High Voltage Sequencer Enable bit mask. */
#define CTE_HVSEQEN_bp  2  /* High Voltage Sequencer Enable bit position. */

/* CTE.TIMAPER  bit masks and bit positions */
#define CTE_TIMAPER_gm  0x3FF  /* Timer A Period group mask. */
#define CTE_TIMAPER_gp  0  /* Timer A Period group position. */
#define CTE_TIMAPER0_bm  (1<<0)  /* Timer A Period bit 0 mask. */
#define CTE_TIMAPER0_bp  0  /* Timer A Period bit 0 position. */
#define CTE_TIMAPER1_bm  (1<<1)  /* Timer A Period bit 1 mask. */
#define CTE_TIMAPER1_bp  1  /* Timer A Period bit 1 position. */
#define CTE_TIMAPER2_bm  (1<<2)  /* Timer A Period bit 2 mask. */
#define CTE_TIMAPER2_bp  2  /* Timer A Period bit 2 position. */
#define CTE_TIMAPER3_bm  (1<<3)  /* Timer A Period bit 3 mask. */
#define CTE_TIMAPER3_bp  3  /* Timer A Period bit 3 position. */
#define CTE_TIMAPER4_bm  (1<<4)  /* Timer A Period bit 4 mask. */
#define CTE_TIMAPER4_bp  4  /* Timer A Period bit 4 position. */
#define CTE_TIMAPER5_bm  (1<<5)  /* Timer A Period bit 5 mask. */
#define CTE_TIMAPER5_bp  5  /* Timer A Period bit 5 position. */
#define CTE_TIMAPER6_bm  (1<<6)  /* Timer A Period bit 6 mask. */
#define CTE_TIMAPER6_bp  6  /* Timer A Period bit 6 position. */
#define CTE_TIMAPER7_bm  (1<<7)  /* Timer A Period bit 7 mask. */
#define CTE_TIMAPER7_bp  7  /* Timer A Period bit 7 position. */
#define CTE_TIMAPER8_bm  (1<<8)  /* Timer A Period bit 8 mask. */
#define CTE_TIMAPER8_bp  8  /* Timer A Period bit 8 position. */
#define CTE_TIMAPER9_bm  (1<<9)  /* Timer A Period bit 9 mask. */
#define CTE_TIMAPER9_bp  9  /* Timer A Period bit 9 position. */

/* CTE.TIMBPER  bit masks and bit positions */
#define CTE_TIMBPER_gm  0x3FF  /* Timer B Period group mask. */
#define CTE_TIMBPER_gp  0  /* Timer B Period group position. */
#define CTE_TIMBPER0_bm  (1<<0)  /* Timer B Period bit 0 mask. */
#define CTE_TIMBPER0_bp  0  /* Timer B Period bit 0 position. */
#define CTE_TIMBPER1_bm  (1<<1)  /* Timer B Period bit 1 mask. */
#define CTE_TIMBPER1_bp  1  /* Timer B Period bit 1 position. */
#define CTE_TIMBPER2_bm  (1<<2)  /* Timer B Period bit 2 mask. */
#define CTE_TIMBPER2_bp  2  /* Timer B Period bit 2 position. */
#define CTE_TIMBPER3_bm  (1<<3)  /* Timer B Period bit 3 mask. */
#define CTE_TIMBPER3_bp  3  /* Timer B Period bit 3 position. */
#define CTE_TIMBPER4_bm  (1<<4)  /* Timer B Period bit 4 mask. */
#define CTE_TIMBPER4_bp  4  /* Timer B Period bit 4 position. */
#define CTE_TIMBPER5_bm  (1<<5)  /* Timer B Period bit 5 mask. */
#define CTE_TIMBPER5_bp  5  /* Timer B Period bit 5 position. */
#define CTE_TIMBPER6_bm  (1<<6)  /* Timer B Period bit 6 mask. */
#define CTE_TIMBPER6_bp  6  /* Timer B Period bit 6 position. */
#define CTE_TIMBPER7_bm  (1<<7)  /* Timer B Period bit 7 mask. */
#define CTE_TIMBPER7_bp  7  /* Timer B Period bit 7 position. */
#define CTE_TIMBPER8_bm  (1<<8)  /* Timer B Period bit 8 mask. */
#define CTE_TIMBPER8_bp  8  /* Timer B Period bit 8 position. */
#define CTE_TIMBPER9_bm  (1<<9)  /* Timer B Period bit 9 mask. */
#define CTE_TIMBPER9_bp  9  /* Timer B Period bit 9 position. */

/* CTE.TIMCPER  bit masks and bit positions */
#define CTE_TIMCPER_gm  0x3FF  /* Timer C Period group mask. */
#define CTE_TIMCPER_gp  0  /* Timer C Period group position. */
#define CTE_TIMCPER0_bm  (1<<0)  /* Timer C Period bit 0 mask. */
#define CTE_TIMCPER0_bp  0  /* Timer C Period bit 0 position. */
#define CTE_TIMCPER1_bm  (1<<1)  /* Timer C Period bit 1 mask. */
#define CTE_TIMCPER1_bp  1  /* Timer C Period bit 1 position. */
#define CTE_TIMCPER2_bm  (1<<2)  /* Timer C Period bit 2 mask. */
#define CTE_TIMCPER2_bp  2  /* Timer C Period bit 2 position. */
#define CTE_TIMCPER3_bm  (1<<3)  /* Timer C Period bit 3 mask. */
#define CTE_TIMCPER3_bp  3  /* Timer C Period bit 3 position. */
#define CTE_TIMCPER4_bm  (1<<4)  /* Timer C Period bit 4 mask. */
#define CTE_TIMCPER4_bp  4  /* Timer C Period bit 4 position. */
#define CTE_TIMCPER5_bm  (1<<5)  /* Timer C Period bit 5 mask. */
#define CTE_TIMCPER5_bp  5  /* Timer C Period bit 5 position. */
#define CTE_TIMCPER6_bm  (1<<6)  /* Timer C Period bit 6 mask. */
#define CTE_TIMCPER6_bp  6  /* Timer C Period bit 6 position. */
#define CTE_TIMCPER7_bm  (1<<7)  /* Timer C Period bit 7 mask. */
#define CTE_TIMCPER7_bp  7  /* Timer C Period bit 7 position. */
#define CTE_TIMCPER8_bm  (1<<8)  /* Timer C Period bit 8 mask. */
#define CTE_TIMCPER8_bp  8  /* Timer C Period bit 8 position. */
#define CTE_TIMCPER9_bm  (1<<9)  /* Timer C Period bit 9 mask. */
#define CTE_TIMCPER9_bp  9  /* Timer C Period bit 9 position. */

/* CTE.TIMMOEPER  bit masks and bit positions */
#define CTE_TIMMOEPER_gm  0x3FF  /* Timer Master Output Enable Period group mask. */
#define CTE_TIMMOEPER_gp  0  /* Timer Master Output Enable Period group position. */
#define CTE_TIMMOEPER0_bm  (1<<0)  /* Timer Master Output Enable Period bit 0 mask. */
#define CTE_TIMMOEPER0_bp  0  /* Timer Master Output Enable Period bit 0 position. */
#define CTE_TIMMOEPER1_bm  (1<<1)  /* Timer Master Output Enable Period bit 1 mask. */
#define CTE_TIMMOEPER1_bp  1  /* Timer Master Output Enable Period bit 1 position. */
#define CTE_TIMMOEPER2_bm  (1<<2)  /* Timer Master Output Enable Period bit 2 mask. */
#define CTE_TIMMOEPER2_bp  2  /* Timer Master Output Enable Period bit 2 position. */
#define CTE_TIMMOEPER3_bm  (1<<3)  /* Timer Master Output Enable Period bit 3 mask. */
#define CTE_TIMMOEPER3_bp  3  /* Timer Master Output Enable Period bit 3 position. */
#define CTE_TIMMOEPER4_bm  (1<<4)  /* Timer Master Output Enable Period bit 4 mask. */
#define CTE_TIMMOEPER4_bp  4  /* Timer Master Output Enable Period bit 4 position. */
#define CTE_TIMMOEPER5_bm  (1<<5)  /* Timer Master Output Enable Period bit 5 mask. */
#define CTE_TIMMOEPER5_bp  5  /* Timer Master Output Enable Period bit 5 position. */
#define CTE_TIMMOEPER6_bm  (1<<6)  /* Timer Master Output Enable Period bit 6 mask. */
#define CTE_TIMMOEPER6_bp  6  /* Timer Master Output Enable Period bit 6 position. */
#define CTE_TIMMOEPER7_bm  (1<<7)  /* Timer Master Output Enable Period bit 7 mask. */
#define CTE_TIMMOEPER7_bp  7  /* Timer Master Output Enable Period bit 7 position. */
#define CTE_TIMMOEPER8_bm  (1<<8)  /* Timer Master Output Enable Period bit 8 mask. */
#define CTE_TIMMOEPER8_bp  8  /* Timer Master Output Enable Period bit 8 position. */
#define CTE_TIMMOEPER9_bm  (1<<9)  /* Timer Master Output Enable Period bit 9 mask. */
#define CTE_TIMMOEPER9_bp  9  /* Timer Master Output Enable Period bit 9 position. */

/* CTE.TIMRSTPER  bit masks and bit positions */
#define CTE_TIMRSTPER_gm  0x3FF  /* Timer Reset Enable Period group mask. */
#define CTE_TIMRSTPER_gp  0  /* Timer Reset Enable Period group position. */
#define CTE_TIMRSTPER0_bm  (1<<0)  /* Timer Reset Enable Period bit 0 mask. */
#define CTE_TIMRSTPER0_bp  0  /* Timer Reset Enable Period bit 0 position. */
#define CTE_TIMRSTPER1_bm  (1<<1)  /* Timer Reset Enable Period bit 1 mask. */
#define CTE_TIMRSTPER1_bp  1  /* Timer Reset Enable Period bit 1 position. */
#define CTE_TIMRSTPER2_bm  (1<<2)  /* Timer Reset Enable Period bit 2 mask. */
#define CTE_TIMRSTPER2_bp  2  /* Timer Reset Enable Period bit 2 position. */
#define CTE_TIMRSTPER3_bm  (1<<3)  /* Timer Reset Enable Period bit 3 mask. */
#define CTE_TIMRSTPER3_bp  3  /* Timer Reset Enable Period bit 3 position. */
#define CTE_TIMRSTPER4_bm  (1<<4)  /* Timer Reset Enable Period bit 4 mask. */
#define CTE_TIMRSTPER4_bp  4  /* Timer Reset Enable Period bit 4 position. */
#define CTE_TIMRSTPER5_bm  (1<<5)  /* Timer Reset Enable Period bit 5 mask. */
#define CTE_TIMRSTPER5_bp  5  /* Timer Reset Enable Period bit 5 position. */
#define CTE_TIMRSTPER6_bm  (1<<6)  /* Timer Reset Enable Period bit 6 mask. */
#define CTE_TIMRSTPER6_bp  6  /* Timer Reset Enable Period bit 6 position. */
#define CTE_TIMRSTPER7_bm  (1<<7)  /* Timer Reset Enable Period bit 7 mask. */
#define CTE_TIMRSTPER7_bp  7  /* Timer Reset Enable Period bit 7 position. */
#define CTE_TIMRSTPER8_bm  (1<<8)  /* Timer Reset Enable Period bit 8 mask. */
#define CTE_TIMRSTPER8_bp  8  /* Timer Reset Enable Period bit 8 position. */
#define CTE_TIMRSTPER9_bm  (1<<9)  /* Timer Reset Enable Period bit 9 mask. */
#define CTE_TIMRSTPER9_bp  9  /* Timer Reset Enable Period bit 9 position. */

/* CTE.INTDONE  bit masks and bit positions */
#define CTE_TIMADONE_bm  0x02  /* Timer A Done bit mask. */
#define CTE_TIMADONE_bp  1  /* Timer A Done bit position. */
#define CTE_TIMBDONE_bm  0x04  /* Timer B Done bit mask. */
#define CTE_TIMBDONE_bp  2  /* Timer B Done bit position. */
#define CTE_TIMCDONE_bm  0x08  /* Timer C Done bit mask. */
#define CTE_TIMCDONE_bp  3  /* Timer C Done bit position. */
#define CTE_INTMOEDONE_bm  0x10  /* Integrator Master Output Enable Done bit mask. */
#define CTE_INTMOEDONE_bp  4  /* Integrator Master Output Enable Done bit position. */
#define CTE_INTRSTDONE_bm  0x20  /* Integrator Reset Done bit mask. */
#define CTE_INTRSTDONE_bp  5  /* Integrator Reset Done bit position. */
#define CTE_SHADCDONE_bm  0x40  /* S/H and ADC Done bit mask. */
#define CTE_SHADCDONE_bp  6  /* S/H and ADC Done bit position. */
#define CTE_ALLDONE_bm  0x80  /* All Timers Done bit mask. */
#define CTE_ALLDONE_bp  7  /* All Timers Done bit position. */

/* CTE.INTTRIGA  bit masks and bit positions */
#define CTE_INTPORTTGL_bm  0x01  /* Port Toggle bit mask. */
#define CTE_INTPORTTGL_bp  0  /* Port Toggle bit position. */
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
#define CTE_SHADCTRIG_A_bm  0x40  /* S/H and ADC Trigger A bit mask. */
#define CTE_SHADCTRIG_A_bp  6  /* S/H and ADC Trigger A bit position. */
#define CTE_INTXRDY_A_bm  0x80  /* X-line Ready A bit mask. */
#define CTE_INTXRDY_A_bp  7  /* X-line Ready A bit position. */
#define CTE_HVSEQXLTRIG_A_bm  0x100  /* HV xline hold off tigger A bit mask. */
#define CTE_HVSEQXLTRIG_A_bp  8  /* HV xline hold off tigger A bit position. */

/* CTE.INTTRIGB  bit masks and bit positions */
/* CTE_INTPORTTGL  is already defined. */
/* CTE_TIMATRIG  is already defined. */
/* CTE_TIMBTRIG  is already defined. */
/* CTE_TIMCTRIG  is already defined. */
/* CTE_INTMOETRIG  is already defined. */
/* CTE_INTRSTTRIG  is already defined. */
#define CTE_HVSEQXLTRIG_B_bm  0x40  /* HV xline hold off Trigger bit mask. */
#define CTE_HVSEQXLTRIG_B_bp  6  /* HV xline hold off Trigger bit position. */
#define CTE_SHADCTRIG_B_bm  0x100  /* S/H and ADC Trigger B bit mask. */
#define CTE_SHADCTRIG_B_bp  8  /* S/H and ADC Trigger B bit position. */
#define CTE_INTXRDY_B_bm  0x200  /* X-line Ready B bit mask. */
#define CTE_INTXRDY_B_bp  9  /* X-line Ready B bit position. */

/* CTE.INTCRFCLR  bit masks and bit positions */
#define CTE_ADCRESDIS_bm  0x01  /* ADC Result Discard bit mask. */
#define CTE_ADCRESDIS_bp  0  /* ADC Result Discard bit position. */
#define CTE_INTCAPRST_bm  0x02  /* Integrator Cap Reset bit mask. */
#define CTE_INTCAPRST_bp  1  /* Integrator Cap Reset bit position. */
#define CTE_INTCAPREL_bm  0x04  /* Integrator Cap Release bit mask. */
#define CTE_INTCAPREL_bp  2  /* Integrator Cap Release bit position. */
#define CTE_XBIASMEN_bm  0x08  /* X-line Bias Master Enable bit mask. */
#define CTE_XBIASMEN_bp  3  /* X-line Bias Master Enable bit position. */

/* CTE.INTCRFSET  bit masks and bit positions */
/* CTE_ADCRESDIS  is already defined. */
/* CTE_INTCAPRST  is already defined. */
/* CTE_INTCAPREL  is already defined. */
/* CTE_XBIASMEN  is already defined. */

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
#define CTE_GCAFHDLCNT_gm  0xFFFF  /* GCAF Headroom Detect Low Counter group mask. */
#define CTE_GCAFHDLCNT_gp  0  /* GCAF Headroom Detect Low Counter group position. */
#define CTE_GCAFHDLCNT0_bm  (1<<0)  /* GCAF Headroom Detect Low Counter bit 0 mask. */
#define CTE_GCAFHDLCNT0_bp  0  /* GCAF Headroom Detect Low Counter bit 0 position. */
#define CTE_GCAFHDLCNT1_bm  (1<<1)  /* GCAF Headroom Detect Low Counter bit 1 mask. */
#define CTE_GCAFHDLCNT1_bp  1  /* GCAF Headroom Detect Low Counter bit 1 position. */
#define CTE_GCAFHDLCNT2_bm  (1<<2)  /* GCAF Headroom Detect Low Counter bit 2 mask. */
#define CTE_GCAFHDLCNT2_bp  2  /* GCAF Headroom Detect Low Counter bit 2 position. */
#define CTE_GCAFHDLCNT3_bm  (1<<3)  /* GCAF Headroom Detect Low Counter bit 3 mask. */
#define CTE_GCAFHDLCNT3_bp  3  /* GCAF Headroom Detect Low Counter bit 3 position. */
#define CTE_GCAFHDLCNT4_bm  (1<<4)  /* GCAF Headroom Detect Low Counter bit 4 mask. */
#define CTE_GCAFHDLCNT4_bp  4  /* GCAF Headroom Detect Low Counter bit 4 position. */
#define CTE_GCAFHDLCNT5_bm  (1<<5)  /* GCAF Headroom Detect Low Counter bit 5 mask. */
#define CTE_GCAFHDLCNT5_bp  5  /* GCAF Headroom Detect Low Counter bit 5 position. */
#define CTE_GCAFHDLCNT6_bm  (1<<6)  /* GCAF Headroom Detect Low Counter bit 6 mask. */
#define CTE_GCAFHDLCNT6_bp  6  /* GCAF Headroom Detect Low Counter bit 6 position. */
#define CTE_GCAFHDLCNT7_bm  (1<<7)  /* GCAF Headroom Detect Low Counter bit 7 mask. */
#define CTE_GCAFHDLCNT7_bp  7  /* GCAF Headroom Detect Low Counter bit 7 position. */
#define CTE_GCAFHDLCNT8_bm  (1<<8)  /* GCAF Headroom Detect Low Counter bit 8 mask. */
#define CTE_GCAFHDLCNT8_bp  8  /* GCAF Headroom Detect Low Counter bit 8 position. */
#define CTE_GCAFHDLCNT9_bm  (1<<9)  /* GCAF Headroom Detect Low Counter bit 9 mask. */
#define CTE_GCAFHDLCNT9_bp  9  /* GCAF Headroom Detect Low Counter bit 9 position. */
#define CTE_GCAFHDLCNT10_bm  (1<<10)  /* GCAF Headroom Detect Low Counter bit 10 mask. */
#define CTE_GCAFHDLCNT10_bp  10  /* GCAF Headroom Detect Low Counter bit 10 position. */
#define CTE_GCAFHDLCNT11_bm  (1<<11)  /* GCAF Headroom Detect Low Counter bit 11 mask. */
#define CTE_GCAFHDLCNT11_bp  11  /* GCAF Headroom Detect Low Counter bit 11 position. */
#define CTE_GCAFHDLCNT12_bm  (1<<12)  /* GCAF Headroom Detect Low Counter bit 12 mask. */
#define CTE_GCAFHDLCNT12_bp  12  /* GCAF Headroom Detect Low Counter bit 12 position. */
#define CTE_GCAFHDLCNT13_bm  (1<<13)  /* GCAF Headroom Detect Low Counter bit 13 mask. */
#define CTE_GCAFHDLCNT13_bp  13  /* GCAF Headroom Detect Low Counter bit 13 position. */
#define CTE_GCAFHDLCNT14_bm  (1<<14)  /* GCAF Headroom Detect Low Counter bit 14 mask. */
#define CTE_GCAFHDLCNT14_bp  14  /* GCAF Headroom Detect Low Counter bit 14 position. */
#define CTE_GCAFHDLCNT15_bm  (1<<15)  /* GCAF Headroom Detect Low Counter bit 15 mask. */
#define CTE_GCAFHDLCNT15_bp  15  /* GCAF Headroom Detect Low Counter bit 15 position. */

/* CTE.GCAFHDHCNT  bit masks and bit positions */
#define CTE_GCAFHDHCNT_gm  0xFFFF  /* GCAF Headroom Detect High Counter group mask. */
#define CTE_GCAFHDHCNT_gp  0  /* GCAF Headroom Detect High Counter group position. */
#define CTE_GCAFHDHCNT0_bm  (1<<0)  /* GCAF Headroom Detect High Counter bit 0 mask. */
#define CTE_GCAFHDHCNT0_bp  0  /* GCAF Headroom Detect High Counter bit 0 position. */
#define CTE_GCAFHDHCNT1_bm  (1<<1)  /* GCAF Headroom Detect High Counter bit 1 mask. */
#define CTE_GCAFHDHCNT1_bp  1  /* GCAF Headroom Detect High Counter bit 1 position. */
#define CTE_GCAFHDHCNT2_bm  (1<<2)  /* GCAF Headroom Detect High Counter bit 2 mask. */
#define CTE_GCAFHDHCNT2_bp  2  /* GCAF Headroom Detect High Counter bit 2 position. */
#define CTE_GCAFHDHCNT3_bm  (1<<3)  /* GCAF Headroom Detect High Counter bit 3 mask. */
#define CTE_GCAFHDHCNT3_bp  3  /* GCAF Headroom Detect High Counter bit 3 position. */
#define CTE_GCAFHDHCNT4_bm  (1<<4)  /* GCAF Headroom Detect High Counter bit 4 mask. */
#define CTE_GCAFHDHCNT4_bp  4  /* GCAF Headroom Detect High Counter bit 4 position. */
#define CTE_GCAFHDHCNT5_bm  (1<<5)  /* GCAF Headroom Detect High Counter bit 5 mask. */
#define CTE_GCAFHDHCNT5_bp  5  /* GCAF Headroom Detect High Counter bit 5 position. */
#define CTE_GCAFHDHCNT6_bm  (1<<6)  /* GCAF Headroom Detect High Counter bit 6 mask. */
#define CTE_GCAFHDHCNT6_bp  6  /* GCAF Headroom Detect High Counter bit 6 position. */
#define CTE_GCAFHDHCNT7_bm  (1<<7)  /* GCAF Headroom Detect High Counter bit 7 mask. */
#define CTE_GCAFHDHCNT7_bp  7  /* GCAF Headroom Detect High Counter bit 7 position. */
#define CTE_GCAFHDHCNT8_bm  (1<<8)  /* GCAF Headroom Detect High Counter bit 8 mask. */
#define CTE_GCAFHDHCNT8_bp  8  /* GCAF Headroom Detect High Counter bit 8 position. */
#define CTE_GCAFHDHCNT9_bm  (1<<9)  /* GCAF Headroom Detect High Counter bit 9 mask. */
#define CTE_GCAFHDHCNT9_bp  9  /* GCAF Headroom Detect High Counter bit 9 position. */
#define CTE_GCAFHDHCNT10_bm  (1<<10)  /* GCAF Headroom Detect High Counter bit 10 mask. */
#define CTE_GCAFHDHCNT10_bp  10  /* GCAF Headroom Detect High Counter bit 10 position. */
#define CTE_GCAFHDHCNT11_bm  (1<<11)  /* GCAF Headroom Detect High Counter bit 11 mask. */
#define CTE_GCAFHDHCNT11_bp  11  /* GCAF Headroom Detect High Counter bit 11 position. */
#define CTE_GCAFHDHCNT12_bm  (1<<12)  /* GCAF Headroom Detect High Counter bit 12 mask. */
#define CTE_GCAFHDHCNT12_bp  12  /* GCAF Headroom Detect High Counter bit 12 position. */
#define CTE_GCAFHDHCNT13_bm  (1<<13)  /* GCAF Headroom Detect High Counter bit 13 mask. */
#define CTE_GCAFHDHCNT13_bp  13  /* GCAF Headroom Detect High Counter bit 13 position. */
#define CTE_GCAFHDHCNT14_bm  (1<<14)  /* GCAF Headroom Detect High Counter bit 14 mask. */
#define CTE_GCAFHDHCNT14_bp  14  /* GCAF Headroom Detect High Counter bit 14 position. */
#define CTE_GCAFHDHCNT15_bm  (1<<15)  /* GCAF Headroom Detect High Counter bit 15 mask. */
#define CTE_GCAFHDHCNT15_bp  15  /* GCAF Headroom Detect High Counter bit 15 position. */

/* CTE.GCAFCCCLIM  bit masks and bit positions */
#define CTE_GCAFCCCLIM_gm  0xFFFF  /* GCAF Computation Complete Counter limit group mask. */
#define CTE_GCAFCCCLIM_gp  0  /* GCAF Computation Complete Counter limit group position. */
#define CTE_GCAFCCCLIM0_bm  (1<<0)  /* GCAF Computation Complete Counter limit bit 0 mask. */
#define CTE_GCAFCCCLIM0_bp  0  /* GCAF Computation Complete Counter limit bit 0 position. */
#define CTE_GCAFCCCLIM1_bm  (1<<1)  /* GCAF Computation Complete Counter limit bit 1 mask. */
#define CTE_GCAFCCCLIM1_bp  1  /* GCAF Computation Complete Counter limit bit 1 position. */
#define CTE_GCAFCCCLIM2_bm  (1<<2)  /* GCAF Computation Complete Counter limit bit 2 mask. */
#define CTE_GCAFCCCLIM2_bp  2  /* GCAF Computation Complete Counter limit bit 2 position. */
#define CTE_GCAFCCCLIM3_bm  (1<<3)  /* GCAF Computation Complete Counter limit bit 3 mask. */
#define CTE_GCAFCCCLIM3_bp  3  /* GCAF Computation Complete Counter limit bit 3 position. */
#define CTE_GCAFCCCLIM4_bm  (1<<4)  /* GCAF Computation Complete Counter limit bit 4 mask. */
#define CTE_GCAFCCCLIM4_bp  4  /* GCAF Computation Complete Counter limit bit 4 position. */
#define CTE_GCAFCCCLIM5_bm  (1<<5)  /* GCAF Computation Complete Counter limit bit 5 mask. */
#define CTE_GCAFCCCLIM5_bp  5  /* GCAF Computation Complete Counter limit bit 5 position. */
#define CTE_GCAFCCCLIM6_bm  (1<<6)  /* GCAF Computation Complete Counter limit bit 6 mask. */
#define CTE_GCAFCCCLIM6_bp  6  /* GCAF Computation Complete Counter limit bit 6 position. */
#define CTE_GCAFCCCLIM7_bm  (1<<7)  /* GCAF Computation Complete Counter limit bit 7 mask. */
#define CTE_GCAFCCCLIM7_bp  7  /* GCAF Computation Complete Counter limit bit 7 position. */
#define CTE_GCAFCCCLIM8_bm  (1<<8)  /* GCAF Computation Complete Counter limit bit 8 mask. */
#define CTE_GCAFCCCLIM8_bp  8  /* GCAF Computation Complete Counter limit bit 8 position. */
#define CTE_GCAFCCCLIM9_bm  (1<<9)  /* GCAF Computation Complete Counter limit bit 9 mask. */
#define CTE_GCAFCCCLIM9_bp  9  /* GCAF Computation Complete Counter limit bit 9 position. */
#define CTE_GCAFCCCLIM10_bm  (1<<10)  /* GCAF Computation Complete Counter limit bit 10 mask. */
#define CTE_GCAFCCCLIM10_bp  10  /* GCAF Computation Complete Counter limit bit 10 position. */
#define CTE_GCAFCCCLIM11_bm  (1<<11)  /* GCAF Computation Complete Counter limit bit 11 mask. */
#define CTE_GCAFCCCLIM11_bp  11  /* GCAF Computation Complete Counter limit bit 11 position. */
#define CTE_GCAFCCCLIM12_bm  (1<<12)  /* GCAF Computation Complete Counter limit bit 12 mask. */
#define CTE_GCAFCCCLIM12_bp  12  /* GCAF Computation Complete Counter limit bit 12 position. */
#define CTE_GCAFCCCLIM13_bm  (1<<13)  /* GCAF Computation Complete Counter limit bit 13 mask. */
#define CTE_GCAFCCCLIM13_bp  13  /* GCAF Computation Complete Counter limit bit 13 position. */
#define CTE_GCAFCCCLIM14_bm  (1<<14)  /* GCAF Computation Complete Counter limit bit 14 mask. */
#define CTE_GCAFCCCLIM14_bp  14  /* GCAF Computation Complete Counter limit bit 14 position. */
#define CTE_GCAFCCCLIM15_bm  (1<<15)  /* GCAF Computation Complete Counter limit bit 15 mask. */
#define CTE_GCAFCCCLIM15_bp  15  /* GCAF Computation Complete Counter limit bit 15 position. */

/* CTE.PIFXPORTA  bit masks and bit positions */
#define CTE_PIFXPORT_gm  0xFFFF  /* Port Interface X-lines PORT group mask. */
#define CTE_PIFXPORT_gp  0  /* Port Interface X-lines PORT group position. */
#define CTE_PIFXPORT0_bm  (1<<0)  /* Port Interface X-lines PORT bit 0 mask. */
#define CTE_PIFXPORT0_bp  0  /* Port Interface X-lines PORT bit 0 position. */
#define CTE_PIFXPORT1_bm  (1<<1)  /* Port Interface X-lines PORT bit 1 mask. */
#define CTE_PIFXPORT1_bp  1  /* Port Interface X-lines PORT bit 1 position. */
#define CTE_PIFXPORT2_bm  (1<<2)  /* Port Interface X-lines PORT bit 2 mask. */
#define CTE_PIFXPORT2_bp  2  /* Port Interface X-lines PORT bit 2 position. */
#define CTE_PIFXPORT3_bm  (1<<3)  /* Port Interface X-lines PORT bit 3 mask. */
#define CTE_PIFXPORT3_bp  3  /* Port Interface X-lines PORT bit 3 position. */
#define CTE_PIFXPORT4_bm  (1<<4)  /* Port Interface X-lines PORT bit 4 mask. */
#define CTE_PIFXPORT4_bp  4  /* Port Interface X-lines PORT bit 4 position. */
#define CTE_PIFXPORT5_bm  (1<<5)  /* Port Interface X-lines PORT bit 5 mask. */
#define CTE_PIFXPORT5_bp  5  /* Port Interface X-lines PORT bit 5 position. */
#define CTE_PIFXPORT6_bm  (1<<6)  /* Port Interface X-lines PORT bit 6 mask. */
#define CTE_PIFXPORT6_bp  6  /* Port Interface X-lines PORT bit 6 position. */
#define CTE_PIFXPORT7_bm  (1<<7)  /* Port Interface X-lines PORT bit 7 mask. */
#define CTE_PIFXPORT7_bp  7  /* Port Interface X-lines PORT bit 7 position. */
#define CTE_PIFXPORT8_bm  (1<<8)  /* Port Interface X-lines PORT bit 8 mask. */
#define CTE_PIFXPORT8_bp  8  /* Port Interface X-lines PORT bit 8 position. */
#define CTE_PIFXPORT9_bm  (1<<9)  /* Port Interface X-lines PORT bit 9 mask. */
#define CTE_PIFXPORT9_bp  9  /* Port Interface X-lines PORT bit 9 position. */
#define CTE_PIFXPORT10_bm  (1<<10)  /* Port Interface X-lines PORT bit 10 mask. */
#define CTE_PIFXPORT10_bp  10  /* Port Interface X-lines PORT bit 10 position. */
#define CTE_PIFXPORT11_bm  (1<<11)  /* Port Interface X-lines PORT bit 11 mask. */
#define CTE_PIFXPORT11_bp  11  /* Port Interface X-lines PORT bit 11 position. */
#define CTE_PIFXPORT12_bm  (1<<12)  /* Port Interface X-lines PORT bit 12 mask. */
#define CTE_PIFXPORT12_bp  12  /* Port Interface X-lines PORT bit 12 position. */
#define CTE_PIFXPORT13_bm  (1<<13)  /* Port Interface X-lines PORT bit 13 mask. */
#define CTE_PIFXPORT13_bp  13  /* Port Interface X-lines PORT bit 13 position. */
#define CTE_PIFXPORT14_bm  (1<<14)  /* Port Interface X-lines PORT bit 14 mask. */
#define CTE_PIFXPORT14_bp  14  /* Port Interface X-lines PORT bit 14 position. */
#define CTE_PIFXPORT15_bm  (1<<15)  /* Port Interface X-lines PORT bit 15 mask. */
#define CTE_PIFXPORT15_bp  15  /* Port Interface X-lines PORT bit 15 position. */

/* CTE.PIFXPORTB  bit masks and bit positions */
/* CTE_PIFXPORT  is already defined. */

/* CTE.PIFYPORTA  bit masks and bit positions */
#define CTE_PIFYPORT_gm  0xFFFF  /* Port Interface Y-lines PORT group mask. */
#define CTE_PIFYPORT_gp  0  /* Port Interface Y-lines PORT group position. */
#define CTE_PIFYPORT0_bm  (1<<0)  /* Port Interface Y-lines PORT bit 0 mask. */
#define CTE_PIFYPORT0_bp  0  /* Port Interface Y-lines PORT bit 0 position. */
#define CTE_PIFYPORT1_bm  (1<<1)  /* Port Interface Y-lines PORT bit 1 mask. */
#define CTE_PIFYPORT1_bp  1  /* Port Interface Y-lines PORT bit 1 position. */
#define CTE_PIFYPORT2_bm  (1<<2)  /* Port Interface Y-lines PORT bit 2 mask. */
#define CTE_PIFYPORT2_bp  2  /* Port Interface Y-lines PORT bit 2 position. */
#define CTE_PIFYPORT3_bm  (1<<3)  /* Port Interface Y-lines PORT bit 3 mask. */
#define CTE_PIFYPORT3_bp  3  /* Port Interface Y-lines PORT bit 3 position. */
#define CTE_PIFYPORT4_bm  (1<<4)  /* Port Interface Y-lines PORT bit 4 mask. */
#define CTE_PIFYPORT4_bp  4  /* Port Interface Y-lines PORT bit 4 position. */
#define CTE_PIFYPORT5_bm  (1<<5)  /* Port Interface Y-lines PORT bit 5 mask. */
#define CTE_PIFYPORT5_bp  5  /* Port Interface Y-lines PORT bit 5 position. */
#define CTE_PIFYPORT6_bm  (1<<6)  /* Port Interface Y-lines PORT bit 6 mask. */
#define CTE_PIFYPORT6_bp  6  /* Port Interface Y-lines PORT bit 6 position. */
#define CTE_PIFYPORT7_bm  (1<<7)  /* Port Interface Y-lines PORT bit 7 mask. */
#define CTE_PIFYPORT7_bp  7  /* Port Interface Y-lines PORT bit 7 position. */
#define CTE_PIFYPORT8_bm  (1<<8)  /* Port Interface Y-lines PORT bit 8 mask. */
#define CTE_PIFYPORT8_bp  8  /* Port Interface Y-lines PORT bit 8 position. */
#define CTE_PIFYPORT9_bm  (1<<9)  /* Port Interface Y-lines PORT bit 9 mask. */
#define CTE_PIFYPORT9_bp  9  /* Port Interface Y-lines PORT bit 9 position. */
#define CTE_PIFYPORT10_bm  (1<<10)  /* Port Interface Y-lines PORT bit 10 mask. */
#define CTE_PIFYPORT10_bp  10  /* Port Interface Y-lines PORT bit 10 position. */
#define CTE_PIFYPORT11_bm  (1<<11)  /* Port Interface Y-lines PORT bit 11 mask. */
#define CTE_PIFYPORT11_bp  11  /* Port Interface Y-lines PORT bit 11 position. */
#define CTE_PIFYPORT12_bm  (1<<12)  /* Port Interface Y-lines PORT bit 12 mask. */
#define CTE_PIFYPORT12_bp  12  /* Port Interface Y-lines PORT bit 12 position. */
#define CTE_PIFYPORT13_bm  (1<<13)  /* Port Interface Y-lines PORT bit 13 mask. */
#define CTE_PIFYPORT13_bp  13  /* Port Interface Y-lines PORT bit 13 position. */
#define CTE_PIFYPORT14_bm  (1<<14)  /* Port Interface Y-lines PORT bit 14 mask. */
#define CTE_PIFYPORT14_bp  14  /* Port Interface Y-lines PORT bit 14 position. */
#define CTE_PIFYPORT15_bm  (1<<15)  /* Port Interface Y-lines PORT bit 15 mask. */
#define CTE_PIFYPORT15_bp  15  /* Port Interface Y-lines PORT bit 15 position. */

/* CTE.PIFYPORTB  bit masks and bit positions */
/* CTE_PIFYPORT  is already defined. */

/* CTE.PIFXDDRA  bit masks and bit positions */
#define CTE_PIFXDDR_gm  0xFFFF  /* Port Interface X-lines DDR group mask. */
#define CTE_PIFXDDR_gp  0  /* Port Interface X-lines DDR group position. */
#define CTE_PIFXDDR0_bm  (1<<0)  /* Port Interface X-lines DDR bit 0 mask. */
#define CTE_PIFXDDR0_bp  0  /* Port Interface X-lines DDR bit 0 position. */
#define CTE_PIFXDDR1_bm  (1<<1)  /* Port Interface X-lines DDR bit 1 mask. */
#define CTE_PIFXDDR1_bp  1  /* Port Interface X-lines DDR bit 1 position. */
#define CTE_PIFXDDR2_bm  (1<<2)  /* Port Interface X-lines DDR bit 2 mask. */
#define CTE_PIFXDDR2_bp  2  /* Port Interface X-lines DDR bit 2 position. */
#define CTE_PIFXDDR3_bm  (1<<3)  /* Port Interface X-lines DDR bit 3 mask. */
#define CTE_PIFXDDR3_bp  3  /* Port Interface X-lines DDR bit 3 position. */
#define CTE_PIFXDDR4_bm  (1<<4)  /* Port Interface X-lines DDR bit 4 mask. */
#define CTE_PIFXDDR4_bp  4  /* Port Interface X-lines DDR bit 4 position. */
#define CTE_PIFXDDR5_bm  (1<<5)  /* Port Interface X-lines DDR bit 5 mask. */
#define CTE_PIFXDDR5_bp  5  /* Port Interface X-lines DDR bit 5 position. */
#define CTE_PIFXDDR6_bm  (1<<6)  /* Port Interface X-lines DDR bit 6 mask. */
#define CTE_PIFXDDR6_bp  6  /* Port Interface X-lines DDR bit 6 position. */
#define CTE_PIFXDDR7_bm  (1<<7)  /* Port Interface X-lines DDR bit 7 mask. */
#define CTE_PIFXDDR7_bp  7  /* Port Interface X-lines DDR bit 7 position. */
#define CTE_PIFXDDR8_bm  (1<<8)  /* Port Interface X-lines DDR bit 8 mask. */
#define CTE_PIFXDDR8_bp  8  /* Port Interface X-lines DDR bit 8 position. */
#define CTE_PIFXDDR9_bm  (1<<9)  /* Port Interface X-lines DDR bit 9 mask. */
#define CTE_PIFXDDR9_bp  9  /* Port Interface X-lines DDR bit 9 position. */
#define CTE_PIFXDDR10_bm  (1<<10)  /* Port Interface X-lines DDR bit 10 mask. */
#define CTE_PIFXDDR10_bp  10  /* Port Interface X-lines DDR bit 10 position. */
#define CTE_PIFXDDR11_bm  (1<<11)  /* Port Interface X-lines DDR bit 11 mask. */
#define CTE_PIFXDDR11_bp  11  /* Port Interface X-lines DDR bit 11 position. */
#define CTE_PIFXDDR12_bm  (1<<12)  /* Port Interface X-lines DDR bit 12 mask. */
#define CTE_PIFXDDR12_bp  12  /* Port Interface X-lines DDR bit 12 position. */
#define CTE_PIFXDDR13_bm  (1<<13)  /* Port Interface X-lines DDR bit 13 mask. */
#define CTE_PIFXDDR13_bp  13  /* Port Interface X-lines DDR bit 13 position. */
#define CTE_PIFXDDR14_bm  (1<<14)  /* Port Interface X-lines DDR bit 14 mask. */
#define CTE_PIFXDDR14_bp  14  /* Port Interface X-lines DDR bit 14 position. */
#define CTE_PIFXDDR15_bm  (1<<15)  /* Port Interface X-lines DDR bit 15 mask. */
#define CTE_PIFXDDR15_bp  15  /* Port Interface X-lines DDR bit 15 position. */

/* CTE.PIFXDDRB  bit masks and bit positions */
/* CTE_PIFXDDR  is already defined. */

/* CTE.PIFYDDRA  bit masks and bit positions */
#define CTE_PIFYDDR_gm  0xFFFF  /* Port Interface Y-lines DDR group mask. */
#define CTE_PIFYDDR_gp  0  /* Port Interface Y-lines DDR group position. */
#define CTE_PIFYDDR0_bm  (1<<0)  /* Port Interface Y-lines DDR bit 0 mask. */
#define CTE_PIFYDDR0_bp  0  /* Port Interface Y-lines DDR bit 0 position. */
#define CTE_PIFYDDR1_bm  (1<<1)  /* Port Interface Y-lines DDR bit 1 mask. */
#define CTE_PIFYDDR1_bp  1  /* Port Interface Y-lines DDR bit 1 position. */
#define CTE_PIFYDDR2_bm  (1<<2)  /* Port Interface Y-lines DDR bit 2 mask. */
#define CTE_PIFYDDR2_bp  2  /* Port Interface Y-lines DDR bit 2 position. */
#define CTE_PIFYDDR3_bm  (1<<3)  /* Port Interface Y-lines DDR bit 3 mask. */
#define CTE_PIFYDDR3_bp  3  /* Port Interface Y-lines DDR bit 3 position. */
#define CTE_PIFYDDR4_bm  (1<<4)  /* Port Interface Y-lines DDR bit 4 mask. */
#define CTE_PIFYDDR4_bp  4  /* Port Interface Y-lines DDR bit 4 position. */
#define CTE_PIFYDDR5_bm  (1<<5)  /* Port Interface Y-lines DDR bit 5 mask. */
#define CTE_PIFYDDR5_bp  5  /* Port Interface Y-lines DDR bit 5 position. */
#define CTE_PIFYDDR6_bm  (1<<6)  /* Port Interface Y-lines DDR bit 6 mask. */
#define CTE_PIFYDDR6_bp  6  /* Port Interface Y-lines DDR bit 6 position. */
#define CTE_PIFYDDR7_bm  (1<<7)  /* Port Interface Y-lines DDR bit 7 mask. */
#define CTE_PIFYDDR7_bp  7  /* Port Interface Y-lines DDR bit 7 position. */
#define CTE_PIFYDDR8_bm  (1<<8)  /* Port Interface Y-lines DDR bit 8 mask. */
#define CTE_PIFYDDR8_bp  8  /* Port Interface Y-lines DDR bit 8 position. */
#define CTE_PIFYDDR9_bm  (1<<9)  /* Port Interface Y-lines DDR bit 9 mask. */
#define CTE_PIFYDDR9_bp  9  /* Port Interface Y-lines DDR bit 9 position. */
#define CTE_PIFYDDR10_bm  (1<<10)  /* Port Interface Y-lines DDR bit 10 mask. */
#define CTE_PIFYDDR10_bp  10  /* Port Interface Y-lines DDR bit 10 position. */
#define CTE_PIFYDDR11_bm  (1<<11)  /* Port Interface Y-lines DDR bit 11 mask. */
#define CTE_PIFYDDR11_bp  11  /* Port Interface Y-lines DDR bit 11 position. */
#define CTE_PIFYDDR12_bm  (1<<12)  /* Port Interface Y-lines DDR bit 12 mask. */
#define CTE_PIFYDDR12_bp  12  /* Port Interface Y-lines DDR bit 12 position. */
#define CTE_PIFYDDR13_bm  (1<<13)  /* Port Interface Y-lines DDR bit 13 mask. */
#define CTE_PIFYDDR13_bp  13  /* Port Interface Y-lines DDR bit 13 position. */
#define CTE_PIFYDDR14_bm  (1<<14)  /* Port Interface Y-lines DDR bit 14 mask. */
#define CTE_PIFYDDR14_bp  14  /* Port Interface Y-lines DDR bit 14 position. */
#define CTE_PIFYDDR15_bm  (1<<15)  /* Port Interface Y-lines DDR bit 15 mask. */
#define CTE_PIFYDDR15_bp  15  /* Port Interface Y-lines DDR bit 15 position. */

/* CTE.PIFYDDRB  bit masks and bit positions */
/* CTE_PIFYDDR  is already defined. */

/* CTE.PIFXTGLA  bit masks and bit positions */
#define CTE_PIFXTGL_gm  0xFFFF  /* Port Interface X-lines Toggle group mask. */
#define CTE_PIFXTGL_gp  0  /* Port Interface X-lines Toggle group position. */
#define CTE_PIFXTGL0_bm  (1<<0)  /* Port Interface X-lines Toggle bit 0 mask. */
#define CTE_PIFXTGL0_bp  0  /* Port Interface X-lines Toggle bit 0 position. */
#define CTE_PIFXTGL1_bm  (1<<1)  /* Port Interface X-lines Toggle bit 1 mask. */
#define CTE_PIFXTGL1_bp  1  /* Port Interface X-lines Toggle bit 1 position. */
#define CTE_PIFXTGL2_bm  (1<<2)  /* Port Interface X-lines Toggle bit 2 mask. */
#define CTE_PIFXTGL2_bp  2  /* Port Interface X-lines Toggle bit 2 position. */
#define CTE_PIFXTGL3_bm  (1<<3)  /* Port Interface X-lines Toggle bit 3 mask. */
#define CTE_PIFXTGL3_bp  3  /* Port Interface X-lines Toggle bit 3 position. */
#define CTE_PIFXTGL4_bm  (1<<4)  /* Port Interface X-lines Toggle bit 4 mask. */
#define CTE_PIFXTGL4_bp  4  /* Port Interface X-lines Toggle bit 4 position. */
#define CTE_PIFXTGL5_bm  (1<<5)  /* Port Interface X-lines Toggle bit 5 mask. */
#define CTE_PIFXTGL5_bp  5  /* Port Interface X-lines Toggle bit 5 position. */
#define CTE_PIFXTGL6_bm  (1<<6)  /* Port Interface X-lines Toggle bit 6 mask. */
#define CTE_PIFXTGL6_bp  6  /* Port Interface X-lines Toggle bit 6 position. */
#define CTE_PIFXTGL7_bm  (1<<7)  /* Port Interface X-lines Toggle bit 7 mask. */
#define CTE_PIFXTGL7_bp  7  /* Port Interface X-lines Toggle bit 7 position. */
#define CTE_PIFXTGL8_bm  (1<<8)  /* Port Interface X-lines Toggle bit 8 mask. */
#define CTE_PIFXTGL8_bp  8  /* Port Interface X-lines Toggle bit 8 position. */
#define CTE_PIFXTGL9_bm  (1<<9)  /* Port Interface X-lines Toggle bit 9 mask. */
#define CTE_PIFXTGL9_bp  9  /* Port Interface X-lines Toggle bit 9 position. */
#define CTE_PIFXTGL10_bm  (1<<10)  /* Port Interface X-lines Toggle bit 10 mask. */
#define CTE_PIFXTGL10_bp  10  /* Port Interface X-lines Toggle bit 10 position. */
#define CTE_PIFXTGL11_bm  (1<<11)  /* Port Interface X-lines Toggle bit 11 mask. */
#define CTE_PIFXTGL11_bp  11  /* Port Interface X-lines Toggle bit 11 position. */
#define CTE_PIFXTGL12_bm  (1<<12)  /* Port Interface X-lines Toggle bit 12 mask. */
#define CTE_PIFXTGL12_bp  12  /* Port Interface X-lines Toggle bit 12 position. */
#define CTE_PIFXTGL13_bm  (1<<13)  /* Port Interface X-lines Toggle bit 13 mask. */
#define CTE_PIFXTGL13_bp  13  /* Port Interface X-lines Toggle bit 13 position. */
#define CTE_PIFXTGL14_bm  (1<<14)  /* Port Interface X-lines Toggle bit 14 mask. */
#define CTE_PIFXTGL14_bp  14  /* Port Interface X-lines Toggle bit 14 position. */
#define CTE_PIFXTGL15_bm  (1<<15)  /* Port Interface X-lines Toggle bit 15 mask. */
#define CTE_PIFXTGL15_bp  15  /* Port Interface X-lines Toggle bit 15 position. */

/* CTE.PIFXTGLB  bit masks and bit positions */
/* CTE_PIFXTGL  is already defined. */

/* CTE.PIFYTGLA  bit masks and bit positions */
#define CTE_PIFYTGL_gm  0xFFFF  /* Port Interface Y-lines Toggle group mask. */
#define CTE_PIFYTGL_gp  0  /* Port Interface Y-lines Toggle group position. */
#define CTE_PIFYTGL0_bm  (1<<0)  /* Port Interface Y-lines Toggle bit 0 mask. */
#define CTE_PIFYTGL0_bp  0  /* Port Interface Y-lines Toggle bit 0 position. */
#define CTE_PIFYTGL1_bm  (1<<1)  /* Port Interface Y-lines Toggle bit 1 mask. */
#define CTE_PIFYTGL1_bp  1  /* Port Interface Y-lines Toggle bit 1 position. */
#define CTE_PIFYTGL2_bm  (1<<2)  /* Port Interface Y-lines Toggle bit 2 mask. */
#define CTE_PIFYTGL2_bp  2  /* Port Interface Y-lines Toggle bit 2 position. */
#define CTE_PIFYTGL3_bm  (1<<3)  /* Port Interface Y-lines Toggle bit 3 mask. */
#define CTE_PIFYTGL3_bp  3  /* Port Interface Y-lines Toggle bit 3 position. */
#define CTE_PIFYTGL4_bm  (1<<4)  /* Port Interface Y-lines Toggle bit 4 mask. */
#define CTE_PIFYTGL4_bp  4  /* Port Interface Y-lines Toggle bit 4 position. */
#define CTE_PIFYTGL5_bm  (1<<5)  /* Port Interface Y-lines Toggle bit 5 mask. */
#define CTE_PIFYTGL5_bp  5  /* Port Interface Y-lines Toggle bit 5 position. */
#define CTE_PIFYTGL6_bm  (1<<6)  /* Port Interface Y-lines Toggle bit 6 mask. */
#define CTE_PIFYTGL6_bp  6  /* Port Interface Y-lines Toggle bit 6 position. */
#define CTE_PIFYTGL7_bm  (1<<7)  /* Port Interface Y-lines Toggle bit 7 mask. */
#define CTE_PIFYTGL7_bp  7  /* Port Interface Y-lines Toggle bit 7 position. */
#define CTE_PIFYTGL8_bm  (1<<8)  /* Port Interface Y-lines Toggle bit 8 mask. */
#define CTE_PIFYTGL8_bp  8  /* Port Interface Y-lines Toggle bit 8 position. */
#define CTE_PIFYTGL9_bm  (1<<9)  /* Port Interface Y-lines Toggle bit 9 mask. */
#define CTE_PIFYTGL9_bp  9  /* Port Interface Y-lines Toggle bit 9 position. */
#define CTE_PIFYTGL10_bm  (1<<10)  /* Port Interface Y-lines Toggle bit 10 mask. */
#define CTE_PIFYTGL10_bp  10  /* Port Interface Y-lines Toggle bit 10 position. */
#define CTE_PIFYTGL11_bm  (1<<11)  /* Port Interface Y-lines Toggle bit 11 mask. */
#define CTE_PIFYTGL11_bp  11  /* Port Interface Y-lines Toggle bit 11 position. */
#define CTE_PIFYTGL12_bm  (1<<12)  /* Port Interface Y-lines Toggle bit 12 mask. */
#define CTE_PIFYTGL12_bp  12  /* Port Interface Y-lines Toggle bit 12 position. */
#define CTE_PIFYTGL13_bm  (1<<13)  /* Port Interface Y-lines Toggle bit 13 mask. */
#define CTE_PIFYTGL13_bp  13  /* Port Interface Y-lines Toggle bit 13 position. */
#define CTE_PIFYTGL14_bm  (1<<14)  /* Port Interface Y-lines Toggle bit 14 mask. */
#define CTE_PIFYTGL14_bp  14  /* Port Interface Y-lines Toggle bit 14 position. */
#define CTE_PIFYTGL15_bm  (1<<15)  /* Port Interface Y-lines Toggle bit 15 mask. */
#define CTE_PIFYTGL15_bp  15  /* Port Interface Y-lines Toggle bit 15 position. */

/* CTE.PIFYTGLB  bit masks and bit positions */
/* CTE_PIFYTGL  is already defined. */

/* CTE.PIFILA  bit masks and bit positions */
#define CTE_PIFIL_gm  0xFFFF  /* Interleave register access group mask. */
#define CTE_PIFIL_gp  0  /* Interleave register access group position. */
#define CTE_PIFIL0_bm  (1<<0)  /* Interleave register access bit 0 mask. */
#define CTE_PIFIL0_bp  0  /* Interleave register access bit 0 position. */
#define CTE_PIFIL1_bm  (1<<1)  /* Interleave register access bit 1 mask. */
#define CTE_PIFIL1_bp  1  /* Interleave register access bit 1 position. */
#define CTE_PIFIL2_bm  (1<<2)  /* Interleave register access bit 2 mask. */
#define CTE_PIFIL2_bp  2  /* Interleave register access bit 2 position. */
#define CTE_PIFIL3_bm  (1<<3)  /* Interleave register access bit 3 mask. */
#define CTE_PIFIL3_bp  3  /* Interleave register access bit 3 position. */
#define CTE_PIFIL4_bm  (1<<4)  /* Interleave register access bit 4 mask. */
#define CTE_PIFIL4_bp  4  /* Interleave register access bit 4 position. */
#define CTE_PIFIL5_bm  (1<<5)  /* Interleave register access bit 5 mask. */
#define CTE_PIFIL5_bp  5  /* Interleave register access bit 5 position. */
#define CTE_PIFIL6_bm  (1<<6)  /* Interleave register access bit 6 mask. */
#define CTE_PIFIL6_bp  6  /* Interleave register access bit 6 position. */
#define CTE_PIFIL7_bm  (1<<7)  /* Interleave register access bit 7 mask. */
#define CTE_PIFIL7_bp  7  /* Interleave register access bit 7 position. */
#define CTE_PIFIL8_bm  (1<<8)  /* Interleave register access bit 8 mask. */
#define CTE_PIFIL8_bp  8  /* Interleave register access bit 8 position. */
#define CTE_PIFIL9_bm  (1<<9)  /* Interleave register access bit 9 mask. */
#define CTE_PIFIL9_bp  9  /* Interleave register access bit 9 position. */
#define CTE_PIFIL10_bm  (1<<10)  /* Interleave register access bit 10 mask. */
#define CTE_PIFIL10_bp  10  /* Interleave register access bit 10 position. */
#define CTE_PIFIL11_bm  (1<<11)  /* Interleave register access bit 11 mask. */
#define CTE_PIFIL11_bp  11  /* Interleave register access bit 11 position. */
#define CTE_PIFIL12_bm  (1<<12)  /* Interleave register access bit 12 mask. */
#define CTE_PIFIL12_bp  12  /* Interleave register access bit 12 position. */
#define CTE_PIFIL13_bm  (1<<13)  /* Interleave register access bit 13 mask. */
#define CTE_PIFIL13_bp  13  /* Interleave register access bit 13 position. */
#define CTE_PIFIL14_bm  (1<<14)  /* Interleave register access bit 14 mask. */
#define CTE_PIFIL14_bp  14  /* Interleave register access bit 14 position. */
#define CTE_PIFIL15_bm  (1<<15)  /* Interleave register access bit 15 mask. */
#define CTE_PIFIL15_bp  15  /* Interleave register access bit 15 position. */

/* CTE.PIFILB  bit masks and bit positions */
/* CTE_PIFIL  is already defined. */

/* CTE.PIFILE  bit masks and bit positions */
/* CTE_PIFIL  is already defined. */

/* CTE.PIFILO  bit masks and bit positions */
/* CTE_PIFIL  is already defined. */

/* CTE.ADCCRA  bit masks and bit positions */
#define CTE_ADCPRESC_gm  0x1F  /* ADC Prescaler Setting group mask. */
#define CTE_ADCPRESC_gp  0  /* ADC Prescaler Setting group position. */
#define CTE_ADCPRESC0_bm  (1<<0)  /* ADC Prescaler Setting bit 0 mask. */
#define CTE_ADCPRESC0_bp  0  /* ADC Prescaler Setting bit 0 position. */
#define CTE_ADCPRESC1_bm  (1<<1)  /* ADC Prescaler Setting bit 1 mask. */
#define CTE_ADCPRESC1_bp  1  /* ADC Prescaler Setting bit 1 position. */
#define CTE_ADCPRESC2_bm  (1<<2)  /* ADC Prescaler Setting bit 2 mask. */
#define CTE_ADCPRESC2_bp  2  /* ADC Prescaler Setting bit 2 position. */
#define CTE_ADCPRESC3_bm  (1<<3)  /* ADC Prescaler Setting bit 3 mask. */
#define CTE_ADCPRESC3_bp  3  /* ADC Prescaler Setting bit 3 position. */
#define CTE_ADCPRESC4_bm  (1<<4)  /* ADC Prescaler Setting bit 4 mask. */
#define CTE_ADCPRESC4_bp  4  /* ADC Prescaler Setting bit 4 position. */
#define CTE_ADCAPS_bm  0x20  /* ADC Auto Power Save bit mask. */
#define CTE_ADCAPS_bp  5  /* ADC Auto Power Save bit position. */
#define CTE_ADCREFSEL_gm  0xC0  /* ADC Reference Select group mask. */
#define CTE_ADCREFSEL_gp  6  /* ADC Reference Select group position. */
#define CTE_ADCREFSEL0_bm  (1<<6)  /* ADC Reference Select bit 0 mask. */
#define CTE_ADCREFSEL0_bp  6  /* ADC Reference Select bit 0 position. */
#define CTE_ADCREFSEL1_bm  (1<<7)  /* ADC Reference Select bit 1 mask. */
#define CTE_ADCREFSEL1_bp  7  /* ADC Reference Select bit 1 position. */
#define CTE_SHSAMP_gm  0x300  /* Sample and Hold sampling mode group mask. */
#define CTE_SHSAMP_gp  8  /* Sample and Hold sampling mode group position. */
#define CTE_SHSAMP0_bm  (1<<8)  /* Sample and Hold sampling mode bit 0 mask. */
#define CTE_SHSAMP0_bp  8  /* Sample and Hold sampling mode bit 0 position. */
#define CTE_SHSAMP1_bm  (1<<9)  /* Sample and Hold sampling mode bit 1 mask. */
#define CTE_SHSAMP1_bp  9  /* Sample and Hold sampling mode bit 1 position. */
#define CTE_SHFALLBACK_bm  0x400  /* Enable fallback from the ADC reference system bit mask. */
#define CTE_SHFALLBACK_bp  10  /* Enable fallback from the ADC reference system bit position. */

/* CTE.ADCCRB  bit masks and bit positions */
#define CTE_ADCSPEED_gm  0x03  /* ADC Speed group mask. */
#define CTE_ADCSPEED_gp  0  /* ADC Speed group position. */
#define CTE_ADCSPEED0_bm  (1<<0)  /* ADC Speed bit 0 mask. */
#define CTE_ADCSPEED0_bp  0  /* ADC Speed bit 0 position. */
#define CTE_ADCSPEED1_bm  (1<<1)  /* ADC Speed bit 1 mask. */
#define CTE_ADCSPEED1_bp  1  /* ADC Speed bit 1 position. */
#define CTE_ADCPUEN_bm  0x04  /* ADC Pull Enable bit mask. */
#define CTE_ADCPUEN_bp  2  /* ADC Pull Enable bit position. */
#define CTE_SHDCS_bm  0x40  /* Sample and Hold Dynamic Current Scaling bit mask. */
#define CTE_SHDCS_bp  6  /* Sample and Hold Dynamic Current Scaling bit position. */
#define CTE_ADCSUM_bm  0x80  /* ADC Startup Mode bit mask. */
#define CTE_ADCSUM_bp  7  /* ADC Startup Mode bit position. */
#define CTE_ADCSUPSD_bm  0x100  /* ADC Startup Power Save Disable bit mask. */
#define CTE_ADCSUPSD_bp  8  /* ADC Startup Power Save Disable bit position. */
#define CTE_ADCPSM_bm  0x200  /* ADC Power Save Mode bit mask. */
#define CTE_ADCPSM_bp  9  /* ADC Power Save Mode bit position. */
#define CTE_ADCSUT_gm  0x1C00  /* ADC Startup Time group mask. */
#define CTE_ADCSUT_gp  10  /* ADC Startup Time group position. */
#define CTE_ADCSUT0_bm  (1<<10)  /* ADC Startup Time bit 0 mask. */
#define CTE_ADCSUT0_bp  10  /* ADC Startup Time bit 0 position. */
#define CTE_ADCSUT1_bm  (1<<11)  /* ADC Startup Time bit 1 mask. */
#define CTE_ADCSUT1_bp  11  /* ADC Startup Time bit 1 position. */
#define CTE_ADCSUT2_bm  (1<<12)  /* ADC Startup Time bit 2 mask. */
#define CTE_ADCSUT2_bp  12  /* ADC Startup Time bit 2 position. */
#define CTE_SHSUT_gm  0xE000  /* Sample and Hold Startup Time group mask. */
#define CTE_SHSUT_gp  13  /* Sample and Hold Startup Time group position. */
#define CTE_SHSUT0_bm  (1<<13)  /* Sample and Hold Startup Time bit 0 mask. */
#define CTE_SHSUT0_bp  13  /* Sample and Hold Startup Time bit 0 position. */
#define CTE_SHSUT1_bm  (1<<14)  /* Sample and Hold Startup Time bit 1 mask. */
#define CTE_SHSUT1_bp  14  /* Sample and Hold Startup Time bit 1 position. */
#define CTE_SHSUT2_bm  (1<<15)  /* Sample and Hold Startup Time bit 2 mask. */
#define CTE_SHSUT2_bp  15  /* Sample and Hold Startup Time bit 2 position. */

/* CTE.ADCINTCAL  bit masks and bit positions */
#define CTE_ADCCALIB_gm  0xFF  /* ADC Calibration Value group mask. */
#define CTE_ADCCALIB_gp  0  /* ADC Calibration Value group position. */
#define CTE_ADCCALIB0_bm  (1<<0)  /* ADC Calibration Value bit 0 mask. */
#define CTE_ADCCALIB0_bp  0  /* ADC Calibration Value bit 0 position. */
#define CTE_ADCCALIB1_bm  (1<<1)  /* ADC Calibration Value bit 1 mask. */
#define CTE_ADCCALIB1_bp  1  /* ADC Calibration Value bit 1 position. */
#define CTE_ADCCALIB2_bm  (1<<2)  /* ADC Calibration Value bit 2 mask. */
#define CTE_ADCCALIB2_bp  2  /* ADC Calibration Value bit 2 position. */
#define CTE_ADCCALIB3_bm  (1<<3)  /* ADC Calibration Value bit 3 mask. */
#define CTE_ADCCALIB3_bp  3  /* ADC Calibration Value bit 3 position. */
#define CTE_ADCCALIB4_bm  (1<<4)  /* ADC Calibration Value bit 4 mask. */
#define CTE_ADCCALIB4_bp  4  /* ADC Calibration Value bit 4 position. */
#define CTE_ADCCALIB5_bm  (1<<5)  /* ADC Calibration Value bit 5 mask. */
#define CTE_ADCCALIB5_bp  5  /* ADC Calibration Value bit 5 position. */
#define CTE_ADCCALIB6_bm  (1<<6)  /* ADC Calibration Value bit 6 mask. */
#define CTE_ADCCALIB6_bp  6  /* ADC Calibration Value bit 6 position. */
#define CTE_ADCCALIB7_bm  (1<<7)  /* ADC Calibration Value bit 7 mask. */
#define CTE_ADCCALIB7_bp  7  /* ADC Calibration Value bit 7 position. */
#define CTE_INTCALIB_gm  0x3F00  /* Integrator Calibration Value group mask. */
#define CTE_INTCALIB_gp  8  /* Integrator Calibration Value group position. */
#define CTE_INTCALIB0_bm  (1<<8)  /* Integrator Calibration Value bit 0 mask. */
#define CTE_INTCALIB0_bp  8  /* Integrator Calibration Value bit 0 position. */
#define CTE_INTCALIB1_bm  (1<<9)  /* Integrator Calibration Value bit 1 mask. */
#define CTE_INTCALIB1_bp  9  /* Integrator Calibration Value bit 1 position. */
#define CTE_INTCALIB2_bm  (1<<10)  /* Integrator Calibration Value bit 2 mask. */
#define CTE_INTCALIB2_bp  10  /* Integrator Calibration Value bit 2 position. */
#define CTE_INTCALIB3_bm  (1<<11)  /* Integrator Calibration Value bit 3 mask. */
#define CTE_INTCALIB3_bp  11  /* Integrator Calibration Value bit 3 position. */
#define CTE_INTCALIB4_bm  (1<<12)  /* Integrator Calibration Value bit 4 mask. */
#define CTE_INTCALIB4_bp  12  /* Integrator Calibration Value bit 4 position. */
#define CTE_INTCALIB5_bm  (1<<13)  /* Integrator Calibration Value bit 5 mask. */
#define CTE_INTCALIB5_bp  13  /* Integrator Calibration Value bit 5 position. */

/* CTE.ADCRES  bit masks and bit positions */
#define CTE_ADCRES_gm  0x3FF  /* ADC Result group mask. */
#define CTE_ADCRES_gp  0  /* ADC Result group position. */
#define CTE_ADCRES0_bm  (1<<0)  /* ADC Result bit 0 mask. */
#define CTE_ADCRES0_bp  0  /* ADC Result bit 0 position. */
#define CTE_ADCRES1_bm  (1<<1)  /* ADC Result bit 1 mask. */
#define CTE_ADCRES1_bp  1  /* ADC Result bit 1 position. */
#define CTE_ADCRES2_bm  (1<<2)  /* ADC Result bit 2 mask. */
#define CTE_ADCRES2_bp  2  /* ADC Result bit 2 position. */
#define CTE_ADCRES3_bm  (1<<3)  /* ADC Result bit 3 mask. */
#define CTE_ADCRES3_bp  3  /* ADC Result bit 3 position. */
#define CTE_ADCRES4_bm  (1<<4)  /* ADC Result bit 4 mask. */
#define CTE_ADCRES4_bp  4  /* ADC Result bit 4 position. */
#define CTE_ADCRES5_bm  (1<<5)  /* ADC Result bit 5 mask. */
#define CTE_ADCRES5_bp  5  /* ADC Result bit 5 position. */
#define CTE_ADCRES6_bm  (1<<6)  /* ADC Result bit 6 mask. */
#define CTE_ADCRES6_bp  6  /* ADC Result bit 6 position. */
#define CTE_ADCRES7_bm  (1<<7)  /* ADC Result bit 7 mask. */
#define CTE_ADCRES7_bp  7  /* ADC Result bit 7 position. */
#define CTE_ADCRES8_bm  (1<<8)  /* ADC Result bit 8 mask. */
#define CTE_ADCRES8_bp  8  /* ADC Result bit 8 position. */
#define CTE_ADCRES9_bm  (1<<9)  /* ADC Result bit 9 mask. */
#define CTE_ADCRES9_bp  9  /* ADC Result bit 9 position. */
#define CTE_ADCRESCH_gm  0x7C00  /* ADC Result Channel group mask. */
#define CTE_ADCRESCH_gp  10  /* ADC Result Channel group position. */
#define CTE_ADCRESCH0_bm  (1<<10)  /* ADC Result Channel bit 0 mask. */
#define CTE_ADCRESCH0_bp  10  /* ADC Result Channel bit 0 position. */
#define CTE_ADCRESCH1_bm  (1<<11)  /* ADC Result Channel bit 1 mask. */
#define CTE_ADCRESCH1_bp  11  /* ADC Result Channel bit 1 position. */
#define CTE_ADCRESCH2_bm  (1<<12)  /* ADC Result Channel bit 2 mask. */
#define CTE_ADCRESCH2_bp  12  /* ADC Result Channel bit 2 position. */
#define CTE_ADCRESCH3_bm  (1<<13)  /* ADC Result Channel bit 3 mask. */
#define CTE_ADCRESCH3_bp  13  /* ADC Result Channel bit 3 position. */
#define CTE_ADCRESCH4_bm  (1<<14)  /* ADC Result Channel bit 4 mask. */
#define CTE_ADCRESCH4_bp  14  /* ADC Result Channel bit 4 position. */
#define CTE_ADCRESAUX_bm  0x8000  /* ADC Result Auxillary Channel bit mask. */
#define CTE_ADCRESAUX_bp  15  /* ADC Result Auxillary Channel bit position. */

/* CTE.ADCINTTEST  bit masks and bit positions */
#define CTE_ADCTSPEN_bm  0x01  /* ADC Test Switch P Enable bit mask. */
#define CTE_ADCTSPEN_bp  0  /* ADC Test Switch P Enable bit position. */
#define CTE_ADCTSNEN_bm  0x02  /* ADC Test Switch N Enable bit mask. */
#define CTE_ADCTSNEN_bp  1  /* ADC Test Switch N Enable bit position. */
#define CTE_ADCBTESTEN_bm  0x04  /* ADC Bias Test Enable bit mask. */
#define CTE_ADCBTESTEN_bp  2  /* ADC Bias Test Enable bit position. */
#define CTE_ADCFV_bm  0x08  /* ADC Force Valid Conversion bit mask. */
#define CTE_ADCFV_bp  3  /* ADC Force Valid Conversion bit position. */
#define CTE_INTBIST_bm  0x10  /* Integrator BIST Enable bit mask. */
#define CTE_INTBIST_bp  4  /* Integrator BIST Enable bit position. */
#define CTE_INTY0TIEN_bm  0x20  /* Integrator Y0 Test Input Enable bit mask. */
#define CTE_INTY0TIEN_bp  5  /* Integrator Y0 Test Input Enable bit position. */
#define CTE_INTY1TIEN_bm  0x40  /* Integrator Y1 Test Input Enable bit mask. */
#define CTE_INTY1TIEN_bp  6  /* Integrator Y1 Test Input Enable bit position. */
#define CTE_INTTESTSEL_gm  0x1F00  /* Integrator Test Mode Selection group mask. */
#define CTE_INTTESTSEL_gp  8  /* Integrator Test Mode Selection group position. */
#define CTE_INTTESTSEL0_bm  (1<<8)  /* Integrator Test Mode Selection bit 0 mask. */
#define CTE_INTTESTSEL0_bp  8  /* Integrator Test Mode Selection bit 0 position. */
#define CTE_INTTESTSEL1_bm  (1<<9)  /* Integrator Test Mode Selection bit 1 mask. */
#define CTE_INTTESTSEL1_bp  9  /* Integrator Test Mode Selection bit 1 position. */
#define CTE_INTTESTSEL2_bm  (1<<10)  /* Integrator Test Mode Selection bit 2 mask. */
#define CTE_INTTESTSEL2_bp  10  /* Integrator Test Mode Selection bit 2 position. */
#define CTE_INTTESTSEL3_bm  (1<<11)  /* Integrator Test Mode Selection bit 3 mask. */
#define CTE_INTTESTSEL3_bp  11  /* Integrator Test Mode Selection bit 3 position. */
#define CTE_INTTESTSEL4_bm  (1<<12)  /* Integrator Test Mode Selection bit 4 mask. */
#define CTE_INTTESTSEL4_bp  12  /* Integrator Test Mode Selection bit 4 position. */

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
#define CTE_SHVBSEL_bm  0x100  /* S/H VBias Select bit mask. */
#define CTE_SHVBSEL_bp  8  /* S/H VBias Select bit position. */

/* CTE.INTCRA  bit masks and bit positions */
#define CTE_INTMEN_bm  0x01  /* Integrator Master Enable bit mask. */
#define CTE_INTMEN_bp  0  /* Integrator Master Enable bit position. */
#define CTE_INTARST_bm  0x02  /* Integrator Automatic Reset bit mask. */
#define CTE_INTARST_bp  1  /* Integrator Automatic Reset bit position. */
#define CTE_INTAST_bm  0x04  /* Integrator Automatic Sign Toggle bit mask. */
#define CTE_INTAST_bp  2  /* Integrator Automatic Sign Toggle bit position. */
#define CTE_INTRSTSEL_bm  0x08  /* Integrator Reset Select bit mask. */
#define CTE_INTRSTSEL_bp  3  /* Integrator Reset Select bit position. */
#define CTE_INTINCBIAS_bm  0x40  /* Integrator Increase Bias bit mask. */
#define CTE_INTINCBIAS_bp  6  /* Integrator Increase Bias bit position. */
#define CTE_INTXCHINC_bm  0x80  /* Integrator X-channel Increment bit mask. */
#define CTE_INTXCHINC_bp  7  /* Integrator X-channel Increment bit position. */
#define CTE_INTRSTEN_bm  0x100  /* Integrator Reset Enable bit mask. */
#define CTE_INTRSTEN_bp  8  /* Integrator Reset Enable bit position. */
#define CTE_INTRSTCOMPEN_bm  0x200  /* Integrator Reset Comparator Enable bit mask. */
#define CTE_INTRSTCOMPEN_bp  9  /* Integrator Reset Comparator Enable bit position. */
#define CTE_INTRSTSYSEN_bm  0x400  /* Integrator Reset System Enable bit mask. */
#define CTE_INTRSTSYSEN_bp  10  /* Integrator Reset System Enable bit position. */
#define CTE_INTDBIAS_bm  0x800  /* Integrator Double Bias bit mask. */
#define CTE_INTDBIAS_bp  11  /* Integrator Double Bias bit position. */
#define CTE_INTCALDC_bm  0x1000  /* Integrator Calibration Double Current bit mask. */
#define CTE_INTCALDC_bp  12  /* Integrator Calibration Double Current bit position. */
#define CTE_INTIAMPCALEN_bm  0x2000  /* Integrator Current Amplifier Calibration Enable bit mask. */
#define CTE_INTIAMPCALEN_bp  13  /* Integrator Current Amplifier Calibration Enable bit position. */
#define CTE_BIASXEN_bm  0x4000  /* X-Line Bias Enable bit mask. */
#define CTE_BIASXEN_bp  14  /* X-Line Bias Enable bit position. */
#define CTE_BIASYEN_bm  0x8000  /* Y-Line Bias Enable bit mask. */
#define CTE_BIASYEN_bp  15  /* Y-Line Bias Enable bit position. */

/* CTE.INTCRD  bit masks and bit positions */
#define CTE_SCENX1_bm  0x01  /* Selfcap Enable X1 bit mask. */
#define CTE_SCENX1_bp  0  /* Selfcap Enable X1 bit position. */
#define CTE_SCENX2_bm  0x02  /* Selfcap Enable X2 bit mask. */
#define CTE_SCENX2_bp  1  /* Selfcap Enable X2 bit position. */
#define CTE_SCENY1_bm  0x04  /* Selfcap Enable Y1 bit mask. */
#define CTE_SCENY1_bp  2  /* Selfcap Enable Y1 bit position. */
#define CTE_BIASY30U_bm  0x08  /* Y-Line Bias Nominal Value 30uA bit mask. */
#define CTE_BIASY30U_bp  3  /* Y-Line Bias Nominal Value 30uA bit position. */
#define CTE_INTCINTBYPASS_bm  0x10  /* Integrator Cint bypass bit mask. */
#define CTE_INTCINTBYPASS_bp  4  /* Integrator Cint bypass bit position. */
#define CTE_TIMABSCCTRL_bm  0x20  /* Timer A/B Selfcap Control bit mask. */
#define CTE_TIMABSCCTRL_bp  5  /* Timer A/B Selfcap Control bit position. */
#define CTE_SCHOT_gm  0x700  /* Selfcap Hold-Off Time group mask. */
#define CTE_SCHOT_gp  8  /* Selfcap Hold-Off Time group position. */
#define CTE_SCHOT0_bm  (1<<8)  /* Selfcap Hold-Off Time bit 0 mask. */
#define CTE_SCHOT0_bp  8  /* Selfcap Hold-Off Time bit 0 position. */
#define CTE_SCHOT1_bm  (1<<9)  /* Selfcap Hold-Off Time bit 1 mask. */
#define CTE_SCHOT1_bp  9  /* Selfcap Hold-Off Time bit 1 position. */
#define CTE_SCHOT2_bm  (1<<10)  /* Selfcap Hold-Off Time bit 2 mask. */
#define CTE_SCHOT2_bp  10  /* Selfcap Hold-Off Time bit 2 position. */

/* CTE.INTENA  bit masks and bit positions */
#define CTE_INTEN_gm  0xFFFF  /* Integrator Enable group mask. */
#define CTE_INTEN_gp  0  /* Integrator Enable group position. */
#define CTE_INTEN0_bm  (1<<0)  /* Integrator Enable bit 0 mask. */
#define CTE_INTEN0_bp  0  /* Integrator Enable bit 0 position. */
#define CTE_INTEN1_bm  (1<<1)  /* Integrator Enable bit 1 mask. */
#define CTE_INTEN1_bp  1  /* Integrator Enable bit 1 position. */
#define CTE_INTEN2_bm  (1<<2)  /* Integrator Enable bit 2 mask. */
#define CTE_INTEN2_bp  2  /* Integrator Enable bit 2 position. */
#define CTE_INTEN3_bm  (1<<3)  /* Integrator Enable bit 3 mask. */
#define CTE_INTEN3_bp  3  /* Integrator Enable bit 3 position. */
#define CTE_INTEN4_bm  (1<<4)  /* Integrator Enable bit 4 mask. */
#define CTE_INTEN4_bp  4  /* Integrator Enable bit 4 position. */
#define CTE_INTEN5_bm  (1<<5)  /* Integrator Enable bit 5 mask. */
#define CTE_INTEN5_bp  5  /* Integrator Enable bit 5 position. */
#define CTE_INTEN6_bm  (1<<6)  /* Integrator Enable bit 6 mask. */
#define CTE_INTEN6_bp  6  /* Integrator Enable bit 6 position. */
#define CTE_INTEN7_bm  (1<<7)  /* Integrator Enable bit 7 mask. */
#define CTE_INTEN7_bp  7  /* Integrator Enable bit 7 position. */
#define CTE_INTEN8_bm  (1<<8)  /* Integrator Enable bit 8 mask. */
#define CTE_INTEN8_bp  8  /* Integrator Enable bit 8 position. */
#define CTE_INTEN9_bm  (1<<9)  /* Integrator Enable bit 9 mask. */
#define CTE_INTEN9_bp  9  /* Integrator Enable bit 9 position. */
#define CTE_INTEN10_bm  (1<<10)  /* Integrator Enable bit 10 mask. */
#define CTE_INTEN10_bp  10  /* Integrator Enable bit 10 position. */
#define CTE_INTEN11_bm  (1<<11)  /* Integrator Enable bit 11 mask. */
#define CTE_INTEN11_bp  11  /* Integrator Enable bit 11 position. */
#define CTE_INTEN12_bm  (1<<12)  /* Integrator Enable bit 12 mask. */
#define CTE_INTEN12_bp  12  /* Integrator Enable bit 12 position. */
#define CTE_INTEN13_bm  (1<<13)  /* Integrator Enable bit 13 mask. */
#define CTE_INTEN13_bp  13  /* Integrator Enable bit 13 position. */
#define CTE_INTEN14_bm  (1<<14)  /* Integrator Enable bit 14 mask. */
#define CTE_INTEN14_bp  14  /* Integrator Enable bit 14 position. */
#define CTE_INTEN15_bm  (1<<15)  /* Integrator Enable bit 15 mask. */
#define CTE_INTEN15_bp  15  /* Integrator Enable bit 15 position. */

/* CTE.INTENB  bit masks and bit positions */
/* CTE_INTEN  is already defined. */

/* CTE.INTMASKENA  bit masks and bit positions */
#define CTE_INTMASKEN_gm  0xFFFF  /* Integrator Mask Enable group mask. */
#define CTE_INTMASKEN_gp  0  /* Integrator Mask Enable group position. */
#define CTE_INTMASKEN0_bm  (1<<0)  /* Integrator Mask Enable bit 0 mask. */
#define CTE_INTMASKEN0_bp  0  /* Integrator Mask Enable bit 0 position. */
#define CTE_INTMASKEN1_bm  (1<<1)  /* Integrator Mask Enable bit 1 mask. */
#define CTE_INTMASKEN1_bp  1  /* Integrator Mask Enable bit 1 position. */
#define CTE_INTMASKEN2_bm  (1<<2)  /* Integrator Mask Enable bit 2 mask. */
#define CTE_INTMASKEN2_bp  2  /* Integrator Mask Enable bit 2 position. */
#define CTE_INTMASKEN3_bm  (1<<3)  /* Integrator Mask Enable bit 3 mask. */
#define CTE_INTMASKEN3_bp  3  /* Integrator Mask Enable bit 3 position. */
#define CTE_INTMASKEN4_bm  (1<<4)  /* Integrator Mask Enable bit 4 mask. */
#define CTE_INTMASKEN4_bp  4  /* Integrator Mask Enable bit 4 position. */
#define CTE_INTMASKEN5_bm  (1<<5)  /* Integrator Mask Enable bit 5 mask. */
#define CTE_INTMASKEN5_bp  5  /* Integrator Mask Enable bit 5 position. */
#define CTE_INTMASKEN6_bm  (1<<6)  /* Integrator Mask Enable bit 6 mask. */
#define CTE_INTMASKEN6_bp  6  /* Integrator Mask Enable bit 6 position. */
#define CTE_INTMASKEN7_bm  (1<<7)  /* Integrator Mask Enable bit 7 mask. */
#define CTE_INTMASKEN7_bp  7  /* Integrator Mask Enable bit 7 position. */
#define CTE_INTMASKEN8_bm  (1<<8)  /* Integrator Mask Enable bit 8 mask. */
#define CTE_INTMASKEN8_bp  8  /* Integrator Mask Enable bit 8 position. */
#define CTE_INTMASKEN9_bm  (1<<9)  /* Integrator Mask Enable bit 9 mask. */
#define CTE_INTMASKEN9_bp  9  /* Integrator Mask Enable bit 9 position. */
#define CTE_INTMASKEN10_bm  (1<<10)  /* Integrator Mask Enable bit 10 mask. */
#define CTE_INTMASKEN10_bp  10  /* Integrator Mask Enable bit 10 position. */
#define CTE_INTMASKEN11_bm  (1<<11)  /* Integrator Mask Enable bit 11 mask. */
#define CTE_INTMASKEN11_bp  11  /* Integrator Mask Enable bit 11 position. */
#define CTE_INTMASKEN12_bm  (1<<12)  /* Integrator Mask Enable bit 12 mask. */
#define CTE_INTMASKEN12_bp  12  /* Integrator Mask Enable bit 12 position. */
#define CTE_INTMASKEN13_bm  (1<<13)  /* Integrator Mask Enable bit 13 mask. */
#define CTE_INTMASKEN13_bp  13  /* Integrator Mask Enable bit 13 position. */
#define CTE_INTMASKEN14_bm  (1<<14)  /* Integrator Mask Enable bit 14 mask. */
#define CTE_INTMASKEN14_bp  14  /* Integrator Mask Enable bit 14 position. */
#define CTE_INTMASKEN15_bm  (1<<15)  /* Integrator Mask Enable bit 15 mask. */
#define CTE_INTMASKEN15_bp  15  /* Integrator Mask Enable bit 15 position. */

/* CTE.INTMASKENB  bit masks and bit positions */
/* CTE_INTMASKEN  is already defined. */

/* CTE.SHENA  bit masks and bit positions */
#define CTE_SHEN_gm  0xFFFF  /* Sample and Hold Enable group mask. */
#define CTE_SHEN_gp  0  /* Sample and Hold Enable group position. */
#define CTE_SHEN0_bm  (1<<0)  /* Sample and Hold Enable bit 0 mask. */
#define CTE_SHEN0_bp  0  /* Sample and Hold Enable bit 0 position. */
#define CTE_SHEN1_bm  (1<<1)  /* Sample and Hold Enable bit 1 mask. */
#define CTE_SHEN1_bp  1  /* Sample and Hold Enable bit 1 position. */
#define CTE_SHEN2_bm  (1<<2)  /* Sample and Hold Enable bit 2 mask. */
#define CTE_SHEN2_bp  2  /* Sample and Hold Enable bit 2 position. */
#define CTE_SHEN3_bm  (1<<3)  /* Sample and Hold Enable bit 3 mask. */
#define CTE_SHEN3_bp  3  /* Sample and Hold Enable bit 3 position. */
#define CTE_SHEN4_bm  (1<<4)  /* Sample and Hold Enable bit 4 mask. */
#define CTE_SHEN4_bp  4  /* Sample and Hold Enable bit 4 position. */
#define CTE_SHEN5_bm  (1<<5)  /* Sample and Hold Enable bit 5 mask. */
#define CTE_SHEN5_bp  5  /* Sample and Hold Enable bit 5 position. */
#define CTE_SHEN6_bm  (1<<6)  /* Sample and Hold Enable bit 6 mask. */
#define CTE_SHEN6_bp  6  /* Sample and Hold Enable bit 6 position. */
#define CTE_SHEN7_bm  (1<<7)  /* Sample and Hold Enable bit 7 mask. */
#define CTE_SHEN7_bp  7  /* Sample and Hold Enable bit 7 position. */
#define CTE_SHEN8_bm  (1<<8)  /* Sample and Hold Enable bit 8 mask. */
#define CTE_SHEN8_bp  8  /* Sample and Hold Enable bit 8 position. */
#define CTE_SHEN9_bm  (1<<9)  /* Sample and Hold Enable bit 9 mask. */
#define CTE_SHEN9_bp  9  /* Sample and Hold Enable bit 9 position. */
#define CTE_SHEN10_bm  (1<<10)  /* Sample and Hold Enable bit 10 mask. */
#define CTE_SHEN10_bp  10  /* Sample and Hold Enable bit 10 position. */
#define CTE_SHEN11_bm  (1<<11)  /* Sample and Hold Enable bit 11 mask. */
#define CTE_SHEN11_bp  11  /* Sample and Hold Enable bit 11 position. */
#define CTE_SHEN12_bm  (1<<12)  /* Sample and Hold Enable bit 12 mask. */
#define CTE_SHEN12_bp  12  /* Sample and Hold Enable bit 12 position. */
#define CTE_SHEN13_bm  (1<<13)  /* Sample and Hold Enable bit 13 mask. */
#define CTE_SHEN13_bp  13  /* Sample and Hold Enable bit 13 position. */
#define CTE_SHEN14_bm  (1<<14)  /* Sample and Hold Enable bit 14 mask. */
#define CTE_SHEN14_bp  14  /* Sample and Hold Enable bit 14 position. */
#define CTE_SHEN15_bm  (1<<15)  /* Sample and Hold Enable bit 15 mask. */
#define CTE_SHEN15_bp  15  /* Sample and Hold Enable bit 15 position. */

/* CTE.SHENB  bit masks and bit positions */
/* CTE_SHEN  is already defined. */

/* CTE.BIASCR  bit masks and bit positions */
#define CTE_BIASXFT_gm  0x1F  /* X-Line Bias P Value (Fall Time) group mask. */
#define CTE_BIASXFT_gp  0  /* X-Line Bias P Value (Fall Time) group position. */
#define CTE_BIASXFT0_bm  (1<<0)  /* X-Line Bias P Value (Fall Time) bit 0 mask. */
#define CTE_BIASXFT0_bp  0  /* X-Line Bias P Value (Fall Time) bit 0 position. */
#define CTE_BIASXFT1_bm  (1<<1)  /* X-Line Bias P Value (Fall Time) bit 1 mask. */
#define CTE_BIASXFT1_bp  1  /* X-Line Bias P Value (Fall Time) bit 1 position. */
#define CTE_BIASXFT2_bm  (1<<2)  /* X-Line Bias P Value (Fall Time) bit 2 mask. */
#define CTE_BIASXFT2_bp  2  /* X-Line Bias P Value (Fall Time) bit 2 position. */
#define CTE_BIASXFT3_bm  (1<<3)  /* X-Line Bias P Value (Fall Time) bit 3 mask. */
#define CTE_BIASXFT3_bp  3  /* X-Line Bias P Value (Fall Time) bit 3 position. */
#define CTE_BIASXFT4_bm  (1<<4)  /* X-Line Bias P Value (Fall Time) bit 4 mask. */
#define CTE_BIASXFT4_bp  4  /* X-Line Bias P Value (Fall Time) bit 4 position. */
#define CTE_BIASXRT_gm  0x3E0  /* X-Line Bias N Value (Rise Time) group mask. */
#define CTE_BIASXRT_gp  5  /* X-Line Bias N Value (Rise Time) group position. */
#define CTE_BIASXRT0_bm  (1<<5)  /* X-Line Bias N Value (Rise Time) bit 0 mask. */
#define CTE_BIASXRT0_bp  5  /* X-Line Bias N Value (Rise Time) bit 0 position. */
#define CTE_BIASXRT1_bm  (1<<6)  /* X-Line Bias N Value (Rise Time) bit 1 mask. */
#define CTE_BIASXRT1_bp  6  /* X-Line Bias N Value (Rise Time) bit 1 position. */
#define CTE_BIASXRT2_bm  (1<<7)  /* X-Line Bias N Value (Rise Time) bit 2 mask. */
#define CTE_BIASXRT2_bp  7  /* X-Line Bias N Value (Rise Time) bit 2 position. */
#define CTE_BIASXRT3_bm  (1<<8)  /* X-Line Bias N Value (Rise Time) bit 3 mask. */
#define CTE_BIASXRT3_bp  8  /* X-Line Bias N Value (Rise Time) bit 3 position. */
#define CTE_BIASXRT4_bm  (1<<9)  /* X-Line Bias N Value (Rise Time) bit 4 mask. */
#define CTE_BIASXRT4_bp  9  /* X-Line Bias N Value (Rise Time) bit 4 position. */
#define CTE_BIASYVAL_gm  0xF000  /* Y-Line Bias Value group mask. */
#define CTE_BIASYVAL_gp  12  /* Y-Line Bias Value group position. */
#define CTE_BIASYVAL0_bm  (1<<12)  /* Y-Line Bias Value bit 0 mask. */
#define CTE_BIASYVAL0_bp  12  /* Y-Line Bias Value bit 0 position. */
#define CTE_BIASYVAL1_bm  (1<<13)  /* Y-Line Bias Value bit 1 mask. */
#define CTE_BIASYVAL1_bp  13  /* Y-Line Bias Value bit 1 position. */
#define CTE_BIASYVAL2_bm  (1<<14)  /* Y-Line Bias Value bit 2 mask. */
#define CTE_BIASYVAL2_bp  14  /* Y-Line Bias Value bit 2 position. */
#define CTE_BIASYVAL3_bm  (1<<15)  /* Y-Line Bias Value bit 3 mask. */
#define CTE_BIASYVAL3_bp  15  /* Y-Line Bias Value bit 3 position. */

/* CTE.HVSEQT  bit masks and bit positions */
#define CTE_HVHOT_gm  0xFF  /* High Voltage Hold Off Time group mask. */
#define CTE_HVHOT_gp  0  /* High Voltage Hold Off Time group position. */
#define CTE_HVHOT0_bm  (1<<0)  /* High Voltage Hold Off Time bit 0 mask. */
#define CTE_HVHOT0_bp  0  /* High Voltage Hold Off Time bit 0 position. */
#define CTE_HVHOT1_bm  (1<<1)  /* High Voltage Hold Off Time bit 1 mask. */
#define CTE_HVHOT1_bp  1  /* High Voltage Hold Off Time bit 1 position. */
#define CTE_HVHOT2_bm  (1<<2)  /* High Voltage Hold Off Time bit 2 mask. */
#define CTE_HVHOT2_bp  2  /* High Voltage Hold Off Time bit 2 position. */
#define CTE_HVHOT3_bm  (1<<3)  /* High Voltage Hold Off Time bit 3 mask. */
#define CTE_HVHOT3_bp  3  /* High Voltage Hold Off Time bit 3 position. */
#define CTE_HVHOT4_bm  (1<<4)  /* High Voltage Hold Off Time bit 4 mask. */
#define CTE_HVHOT4_bp  4  /* High Voltage Hold Off Time bit 4 position. */
#define CTE_HVHOT5_bm  (1<<5)  /* High Voltage Hold Off Time bit 5 mask. */
#define CTE_HVHOT5_bp  5  /* High Voltage Hold Off Time bit 5 position. */
#define CTE_HVHOT6_bm  (1<<6)  /* High Voltage Hold Off Time bit 6 mask. */
#define CTE_HVHOT6_bp  6  /* High Voltage Hold Off Time bit 6 position. */
#define CTE_HVHOT7_bm  (1<<7)  /* High Voltage Hold Off Time bit 7 mask. */
#define CTE_HVHOT7_bp  7  /* High Voltage Hold Off Time bit 7 position. */
#define CTE_HVCT_gm  0xFF00  /* High Voltage Charge Time group mask. */
#define CTE_HVCT_gp  8  /* High Voltage Charge Time group position. */
#define CTE_HVCT0_bm  (1<<8)  /* High Voltage Charge Time bit 0 mask. */
#define CTE_HVCT0_bp  8  /* High Voltage Charge Time bit 0 position. */
#define CTE_HVCT1_bm  (1<<9)  /* High Voltage Charge Time bit 1 mask. */
#define CTE_HVCT1_bp  9  /* High Voltage Charge Time bit 1 position. */
#define CTE_HVCT2_bm  (1<<10)  /* High Voltage Charge Time bit 2 mask. */
#define CTE_HVCT2_bp  10  /* High Voltage Charge Time bit 2 position. */
#define CTE_HVCT3_bm  (1<<11)  /* High Voltage Charge Time bit 3 mask. */
#define CTE_HVCT3_bp  11  /* High Voltage Charge Time bit 3 position. */
#define CTE_HVCT4_bm  (1<<12)  /* High Voltage Charge Time bit 4 mask. */
#define CTE_HVCT4_bp  12  /* High Voltage Charge Time bit 4 position. */
#define CTE_HVCT5_bm  (1<<13)  /* High Voltage Charge Time bit 5 mask. */
#define CTE_HVCT5_bp  13  /* High Voltage Charge Time bit 5 position. */
#define CTE_HVCT6_bm  (1<<14)  /* High Voltage Charge Time bit 6 mask. */
#define CTE_HVCT6_bp  14  /* High Voltage Charge Time bit 6 position. */
#define CTE_HVCT7_bm  (1<<15)  /* High Voltage Charge Time bit 7 mask. */
#define CTE_HVCT7_bp  15  /* High Voltage Charge Time bit 7 position. */

/* CTE.INTXCHMAX  bit masks and bit positions */
#define CTE_INTXCHMAX_gm  0x3F  /* Maximum X-channel Number group mask. */
#define CTE_INTXCHMAX_gp  0  /* Maximum X-channel Number group position. */
#define CTE_INTXCHMAX0_bm  (1<<0)  /* Maximum X-channel Number bit 0 mask. */
#define CTE_INTXCHMAX0_bp  0  /* Maximum X-channel Number bit 0 position. */
#define CTE_INTXCHMAX1_bm  (1<<1)  /* Maximum X-channel Number bit 1 mask. */
#define CTE_INTXCHMAX1_bp  1  /* Maximum X-channel Number bit 1 position. */
#define CTE_INTXCHMAX2_bm  (1<<2)  /* Maximum X-channel Number bit 2 mask. */
#define CTE_INTXCHMAX2_bp  2  /* Maximum X-channel Number bit 2 position. */
#define CTE_INTXCHMAX3_bm  (1<<3)  /* Maximum X-channel Number bit 3 mask. */
#define CTE_INTXCHMAX3_bp  3  /* Maximum X-channel Number bit 3 position. */
#define CTE_INTXCHMAX4_bm  (1<<4)  /* Maximum X-channel Number bit 4 mask. */
#define CTE_INTXCHMAX4_bp  4  /* Maximum X-channel Number bit 4 position. */
#define CTE_INTXCHMAX5_bm  (1<<5)  /* Maximum X-channel Number bit 5 mask. */
#define CTE_INTXCHMAX5_bp  5  /* Maximum X-channel Number bit 5 position. */

/* CTE.INTCAPRSTCR  bit masks and bit positions */
#define CTE_INTCAPRSTTA_gm  0x07  /* Integrator Cap Reset Time A group mask. */
#define CTE_INTCAPRSTTA_gp  0  /* Integrator Cap Reset Time A group position. */
#define CTE_INTCAPRSTTA0_bm  (1<<0)  /* Integrator Cap Reset Time A bit 0 mask. */
#define CTE_INTCAPRSTTA0_bp  0  /* Integrator Cap Reset Time A bit 0 position. */
#define CTE_INTCAPRSTTA1_bm  (1<<1)  /* Integrator Cap Reset Time A bit 1 mask. */
#define CTE_INTCAPRSTTA1_bp  1  /* Integrator Cap Reset Time A bit 1 position. */
#define CTE_INTCAPRSTTA2_bm  (1<<2)  /* Integrator Cap Reset Time A bit 2 mask. */
#define CTE_INTCAPRSTTA2_bp  2  /* Integrator Cap Reset Time A bit 2 position. */
#define CTE_INTCAPRSTTB_gm  0x70  /* Integrator Cap Reset Time B group mask. */
#define CTE_INTCAPRSTTB_gp  4  /* Integrator Cap Reset Time B group position. */
#define CTE_INTCAPRSTTB0_bm  (1<<4)  /* Integrator Cap Reset Time B bit 0 mask. */
#define CTE_INTCAPRSTTB0_bp  4  /* Integrator Cap Reset Time B bit 0 position. */
#define CTE_INTCAPRSTTB1_bm  (1<<5)  /* Integrator Cap Reset Time B bit 1 mask. */
#define CTE_INTCAPRSTTB1_bp  5  /* Integrator Cap Reset Time B bit 1 position. */
#define CTE_INTCAPRSTTB2_bm  (1<<6)  /* Integrator Cap Reset Time B bit 2 mask. */
#define CTE_INTCAPRSTTB2_bp  6  /* Integrator Cap Reset Time B bit 2 position. */

/* CTE.INTGAIN0  bit masks and bit positions */
#define CTE_INT0GAIN_gm  0x0F  /* Integrator Gain 0 group mask. */
#define CTE_INT0GAIN_gp  0  /* Integrator Gain 0 group position. */
#define CTE_INT0GAIN0_bm  (1<<0)  /* Integrator Gain 0 bit 0 mask. */
#define CTE_INT0GAIN0_bp  0  /* Integrator Gain 0 bit 0 position. */
#define CTE_INT0GAIN1_bm  (1<<1)  /* Integrator Gain 0 bit 1 mask. */
#define CTE_INT0GAIN1_bp  1  /* Integrator Gain 0 bit 1 position. */
#define CTE_INT0GAIN2_bm  (1<<2)  /* Integrator Gain 0 bit 2 mask. */
#define CTE_INT0GAIN2_bp  2  /* Integrator Gain 0 bit 2 position. */
#define CTE_INT0GAIN3_bm  (1<<3)  /* Integrator Gain 0 bit 3 mask. */
#define CTE_INT0GAIN3_bp  3  /* Integrator Gain 0 bit 3 position. */
#define CTE_INT1GAIN_gm  0xF0  /* Integrator Gain 1 group mask. */
#define CTE_INT1GAIN_gp  4  /* Integrator Gain 1 group position. */
#define CTE_INT1GAIN0_bm  (1<<4)  /* Integrator Gain 1 bit 0 mask. */
#define CTE_INT1GAIN0_bp  4  /* Integrator Gain 1 bit 0 position. */
#define CTE_INT1GAIN1_bm  (1<<5)  /* Integrator Gain 1 bit 1 mask. */
#define CTE_INT1GAIN1_bp  5  /* Integrator Gain 1 bit 1 position. */
#define CTE_INT1GAIN2_bm  (1<<6)  /* Integrator Gain 1 bit 2 mask. */
#define CTE_INT1GAIN2_bp  6  /* Integrator Gain 1 bit 2 position. */
#define CTE_INT1GAIN3_bm  (1<<7)  /* Integrator Gain 1 bit 3 mask. */
#define CTE_INT1GAIN3_bp  7  /* Integrator Gain 1 bit 3 position. */
#define CTE_INT2GAIN_gm  0xF00  /* Integrator Gain 2 group mask. */
#define CTE_INT2GAIN_gp  8  /* Integrator Gain 2 group position. */
#define CTE_INT2GAIN0_bm  (1<<8)  /* Integrator Gain 2 bit 0 mask. */
#define CTE_INT2GAIN0_bp  8  /* Integrator Gain 2 bit 0 position. */
#define CTE_INT2GAIN1_bm  (1<<9)  /* Integrator Gain 2 bit 1 mask. */
#define CTE_INT2GAIN1_bp  9  /* Integrator Gain 2 bit 1 position. */
#define CTE_INT2GAIN2_bm  (1<<10)  /* Integrator Gain 2 bit 2 mask. */
#define CTE_INT2GAIN2_bp  10  /* Integrator Gain 2 bit 2 position. */
#define CTE_INT2GAIN3_bm  (1<<11)  /* Integrator Gain 2 bit 3 mask. */
#define CTE_INT2GAIN3_bp  11  /* Integrator Gain 2 bit 3 position. */
#define CTE_INT3GAIN_gm  0xF000  /* Integrator Gain 3 group mask. */
#define CTE_INT3GAIN_gp  12  /* Integrator Gain 3 group position. */
#define CTE_INT3GAIN0_bm  (1<<12)  /* Integrator Gain 3 bit 0 mask. */
#define CTE_INT3GAIN0_bp  12  /* Integrator Gain 3 bit 0 position. */
#define CTE_INT3GAIN1_bm  (1<<13)  /* Integrator Gain 3 bit 1 mask. */
#define CTE_INT3GAIN1_bp  13  /* Integrator Gain 3 bit 1 position. */
#define CTE_INT3GAIN2_bm  (1<<14)  /* Integrator Gain 3 bit 2 mask. */
#define CTE_INT3GAIN2_bp  14  /* Integrator Gain 3 bit 2 position. */
#define CTE_INT3GAIN3_bm  (1<<15)  /* Integrator Gain 3 bit 3 mask. */
#define CTE_INT3GAIN3_bp  15  /* Integrator Gain 3 bit 3 position. */

/* CTE.INTGAIN1  bit masks and bit positions */
#define CTE_INT4GAIN_gm  0x0F  /* Integrator Gain 4 group mask. */
#define CTE_INT4GAIN_gp  0  /* Integrator Gain 4 group position. */
#define CTE_INT4GAIN0_bm  (1<<0)  /* Integrator Gain 4 bit 0 mask. */
#define CTE_INT4GAIN0_bp  0  /* Integrator Gain 4 bit 0 position. */
#define CTE_INT4GAIN1_bm  (1<<1)  /* Integrator Gain 4 bit 1 mask. */
#define CTE_INT4GAIN1_bp  1  /* Integrator Gain 4 bit 1 position. */
#define CTE_INT4GAIN2_bm  (1<<2)  /* Integrator Gain 4 bit 2 mask. */
#define CTE_INT4GAIN2_bp  2  /* Integrator Gain 4 bit 2 position. */
#define CTE_INT4GAIN3_bm  (1<<3)  /* Integrator Gain 4 bit 3 mask. */
#define CTE_INT4GAIN3_bp  3  /* Integrator Gain 4 bit 3 position. */
#define CTE_INT5GAIN_gm  0xF0  /* Integrator Gain 5 group mask. */
#define CTE_INT5GAIN_gp  4  /* Integrator Gain 5 group position. */
#define CTE_INT5GAIN0_bm  (1<<4)  /* Integrator Gain 5 bit 0 mask. */
#define CTE_INT5GAIN0_bp  4  /* Integrator Gain 5 bit 0 position. */
#define CTE_INT5GAIN1_bm  (1<<5)  /* Integrator Gain 5 bit 1 mask. */
#define CTE_INT5GAIN1_bp  5  /* Integrator Gain 5 bit 1 position. */
#define CTE_INT5GAIN2_bm  (1<<6)  /* Integrator Gain 5 bit 2 mask. */
#define CTE_INT5GAIN2_bp  6  /* Integrator Gain 5 bit 2 position. */
#define CTE_INT5GAIN3_bm  (1<<7)  /* Integrator Gain 5 bit 3 mask. */
#define CTE_INT5GAIN3_bp  7  /* Integrator Gain 5 bit 3 position. */
#define CTE_INT6GAIN_gm  0xF00  /* Integrator Gain 6 group mask. */
#define CTE_INT6GAIN_gp  8  /* Integrator Gain 6 group position. */
#define CTE_INT6GAIN0_bm  (1<<8)  /* Integrator Gain 6 bit 0 mask. */
#define CTE_INT6GAIN0_bp  8  /* Integrator Gain 6 bit 0 position. */
#define CTE_INT6GAIN1_bm  (1<<9)  /* Integrator Gain 6 bit 1 mask. */
#define CTE_INT6GAIN1_bp  9  /* Integrator Gain 6 bit 1 position. */
#define CTE_INT6GAIN2_bm  (1<<10)  /* Integrator Gain 6 bit 2 mask. */
#define CTE_INT6GAIN2_bp  10  /* Integrator Gain 6 bit 2 position. */
#define CTE_INT6GAIN3_bm  (1<<11)  /* Integrator Gain 6 bit 3 mask. */
#define CTE_INT6GAIN3_bp  11  /* Integrator Gain 6 bit 3 position. */
#define CTE_INT7GAIN_gm  0xF000  /* Integrator Gain 7 group mask. */
#define CTE_INT7GAIN_gp  12  /* Integrator Gain 7 group position. */
#define CTE_INT7GAIN0_bm  (1<<12)  /* Integrator Gain 7 bit 0 mask. */
#define CTE_INT7GAIN0_bp  12  /* Integrator Gain 7 bit 0 position. */
#define CTE_INT7GAIN1_bm  (1<<13)  /* Integrator Gain 7 bit 1 mask. */
#define CTE_INT7GAIN1_bp  13  /* Integrator Gain 7 bit 1 position. */
#define CTE_INT7GAIN2_bm  (1<<14)  /* Integrator Gain 7 bit 2 mask. */
#define CTE_INT7GAIN2_bp  14  /* Integrator Gain 7 bit 2 position. */
#define CTE_INT7GAIN3_bm  (1<<15)  /* Integrator Gain 7 bit 3 mask. */
#define CTE_INT7GAIN3_bp  15  /* Integrator Gain 7 bit 3 position. */

/* CTE.INTGAIN2  bit masks and bit positions */
#define CTE_INT8GAIN_gm  0x0F  /* Integrator Gain 8 group mask. */
#define CTE_INT8GAIN_gp  0  /* Integrator Gain 8 group position. */
#define CTE_INT8GAIN0_bm  (1<<0)  /* Integrator Gain 8 bit 0 mask. */
#define CTE_INT8GAIN0_bp  0  /* Integrator Gain 8 bit 0 position. */
#define CTE_INT8GAIN1_bm  (1<<1)  /* Integrator Gain 8 bit 1 mask. */
#define CTE_INT8GAIN1_bp  1  /* Integrator Gain 8 bit 1 position. */
#define CTE_INT8GAIN2_bm  (1<<2)  /* Integrator Gain 8 bit 2 mask. */
#define CTE_INT8GAIN2_bp  2  /* Integrator Gain 8 bit 2 position. */
#define CTE_INT8GAIN3_bm  (1<<3)  /* Integrator Gain 8 bit 3 mask. */
#define CTE_INT8GAIN3_bp  3  /* Integrator Gain 8 bit 3 position. */
#define CTE_INT9GAIN_gm  0xF0  /* Integrator Gain 9 group mask. */
#define CTE_INT9GAIN_gp  4  /* Integrator Gain 9 group position. */
#define CTE_INT9GAIN0_bm  (1<<4)  /* Integrator Gain 9 bit 0 mask. */
#define CTE_INT9GAIN0_bp  4  /* Integrator Gain 9 bit 0 position. */
#define CTE_INT9GAIN1_bm  (1<<5)  /* Integrator Gain 9 bit 1 mask. */
#define CTE_INT9GAIN1_bp  5  /* Integrator Gain 9 bit 1 position. */
#define CTE_INT9GAIN2_bm  (1<<6)  /* Integrator Gain 9 bit 2 mask. */
#define CTE_INT9GAIN2_bp  6  /* Integrator Gain 9 bit 2 position. */
#define CTE_INT9GAIN3_bm  (1<<7)  /* Integrator Gain 9 bit 3 mask. */
#define CTE_INT9GAIN3_bp  7  /* Integrator Gain 9 bit 3 position. */
#define CTE_INT10GAIN_gm  0xF00  /* Integrator Gain 10 group mask. */
#define CTE_INT10GAIN_gp  8  /* Integrator Gain 10 group position. */
#define CTE_INT10GAIN0_bm  (1<<8)  /* Integrator Gain 10 bit 0 mask. */
#define CTE_INT10GAIN0_bp  8  /* Integrator Gain 10 bit 0 position. */
#define CTE_INT10GAIN1_bm  (1<<9)  /* Integrator Gain 10 bit 1 mask. */
#define CTE_INT10GAIN1_bp  9  /* Integrator Gain 10 bit 1 position. */
#define CTE_INT10GAIN2_bm  (1<<10)  /* Integrator Gain 10 bit 2 mask. */
#define CTE_INT10GAIN2_bp  10  /* Integrator Gain 10 bit 2 position. */
#define CTE_INT10GAIN3_bm  (1<<11)  /* Integrator Gain 10 bit 3 mask. */
#define CTE_INT10GAIN3_bp  11  /* Integrator Gain 10 bit 3 position. */
#define CTE_INT11GAIN_gm  0xF000  /* Integrator Gain 11 group mask. */
#define CTE_INT11GAIN_gp  12  /* Integrator Gain 11 group position. */
#define CTE_INT11GAIN0_bm  (1<<12)  /* Integrator Gain 11 bit 0 mask. */
#define CTE_INT11GAIN0_bp  12  /* Integrator Gain 11 bit 0 position. */
#define CTE_INT11GAIN1_bm  (1<<13)  /* Integrator Gain 11 bit 1 mask. */
#define CTE_INT11GAIN1_bp  13  /* Integrator Gain 11 bit 1 position. */
#define CTE_INT11GAIN2_bm  (1<<14)  /* Integrator Gain 11 bit 2 mask. */
#define CTE_INT11GAIN2_bp  14  /* Integrator Gain 11 bit 2 position. */
#define CTE_INT11GAIN3_bm  (1<<15)  /* Integrator Gain 11 bit 3 mask. */
#define CTE_INT11GAIN3_bp  15  /* Integrator Gain 11 bit 3 position. */

/* CTE.INTGAIN3  bit masks and bit positions */
#define CTE_INT12GAIN_gm  0x0F  /* Integrator Gain 12 group mask. */
#define CTE_INT12GAIN_gp  0  /* Integrator Gain 12 group position. */
#define CTE_INT12GAIN0_bm  (1<<0)  /* Integrator Gain 12 bit 0 mask. */
#define CTE_INT12GAIN0_bp  0  /* Integrator Gain 12 bit 0 position. */
#define CTE_INT12GAIN1_bm  (1<<1)  /* Integrator Gain 12 bit 1 mask. */
#define CTE_INT12GAIN1_bp  1  /* Integrator Gain 12 bit 1 position. */
#define CTE_INT12GAIN2_bm  (1<<2)  /* Integrator Gain 12 bit 2 mask. */
#define CTE_INT12GAIN2_bp  2  /* Integrator Gain 12 bit 2 position. */
#define CTE_INT12GAIN3_bm  (1<<3)  /* Integrator Gain 12 bit 3 mask. */
#define CTE_INT12GAIN3_bp  3  /* Integrator Gain 12 bit 3 position. */
#define CTE_INT13GAIN_gm  0xF0  /* Integrator Gain 13 group mask. */
#define CTE_INT13GAIN_gp  4  /* Integrator Gain 13 group position. */
#define CTE_INT13GAIN0_bm  (1<<4)  /* Integrator Gain 13 bit 0 mask. */
#define CTE_INT13GAIN0_bp  4  /* Integrator Gain 13 bit 0 position. */
#define CTE_INT13GAIN1_bm  (1<<5)  /* Integrator Gain 13 bit 1 mask. */
#define CTE_INT13GAIN1_bp  5  /* Integrator Gain 13 bit 1 position. */
#define CTE_INT13GAIN2_bm  (1<<6)  /* Integrator Gain 13 bit 2 mask. */
#define CTE_INT13GAIN2_bp  6  /* Integrator Gain 13 bit 2 position. */
#define CTE_INT13GAIN3_bm  (1<<7)  /* Integrator Gain 13 bit 3 mask. */
#define CTE_INT13GAIN3_bp  7  /* Integrator Gain 13 bit 3 position. */
#define CTE_INT14GAIN_gm  0xF00  /* Integrator Gain 14 group mask. */
#define CTE_INT14GAIN_gp  8  /* Integrator Gain 14 group position. */
#define CTE_INT14GAIN0_bm  (1<<8)  /* Integrator Gain 14 bit 0 mask. */
#define CTE_INT14GAIN0_bp  8  /* Integrator Gain 14 bit 0 position. */
#define CTE_INT14GAIN1_bm  (1<<9)  /* Integrator Gain 14 bit 1 mask. */
#define CTE_INT14GAIN1_bp  9  /* Integrator Gain 14 bit 1 position. */
#define CTE_INT14GAIN2_bm  (1<<10)  /* Integrator Gain 14 bit 2 mask. */
#define CTE_INT14GAIN2_bp  10  /* Integrator Gain 14 bit 2 position. */
#define CTE_INT14GAIN3_bm  (1<<11)  /* Integrator Gain 14 bit 3 mask. */
#define CTE_INT14GAIN3_bp  11  /* Integrator Gain 14 bit 3 position. */
#define CTE_INT15GAIN_gm  0xF000  /* Integrator Gain 15 group mask. */
#define CTE_INT15GAIN_gp  12  /* Integrator Gain 15 group position. */
#define CTE_INT15GAIN0_bm  (1<<12)  /* Integrator Gain 15 bit 0 mask. */
#define CTE_INT15GAIN0_bp  12  /* Integrator Gain 15 bit 0 position. */
#define CTE_INT15GAIN1_bm  (1<<13)  /* Integrator Gain 15 bit 1 mask. */
#define CTE_INT15GAIN1_bp  13  /* Integrator Gain 15 bit 1 position. */
#define CTE_INT15GAIN2_bm  (1<<14)  /* Integrator Gain 15 bit 2 mask. */
#define CTE_INT15GAIN2_bp  14  /* Integrator Gain 15 bit 2 position. */
#define CTE_INT15GAIN3_bm  (1<<15)  /* Integrator Gain 15 bit 3 mask. */
#define CTE_INT15GAIN3_bp  15  /* Integrator Gain 15 bit 3 position. */

/* CTE.INTGAIN4  bit masks and bit positions */
#define CTE_INT16GAIN_gm  0x0F  /* Integrator Gain 16 group mask. */
#define CTE_INT16GAIN_gp  0  /* Integrator Gain 16 group position. */
#define CTE_INT16GAIN0_bm  (1<<0)  /* Integrator Gain 16 bit 0 mask. */
#define CTE_INT16GAIN0_bp  0  /* Integrator Gain 16 bit 0 position. */
#define CTE_INT16GAIN1_bm  (1<<1)  /* Integrator Gain 16 bit 1 mask. */
#define CTE_INT16GAIN1_bp  1  /* Integrator Gain 16 bit 1 position. */
#define CTE_INT16GAIN2_bm  (1<<2)  /* Integrator Gain 16 bit 2 mask. */
#define CTE_INT16GAIN2_bp  2  /* Integrator Gain 16 bit 2 position. */
#define CTE_INT16GAIN3_bm  (1<<3)  /* Integrator Gain 16 bit 3 mask. */
#define CTE_INT16GAIN3_bp  3  /* Integrator Gain 16 bit 3 position. */
#define CTE_INT17GAIN_gm  0xF0  /* Integrator Gain 17 group mask. */
#define CTE_INT17GAIN_gp  4  /* Integrator Gain 17 group position. */
#define CTE_INT17GAIN0_bm  (1<<4)  /* Integrator Gain 17 bit 0 mask. */
#define CTE_INT17GAIN0_bp  4  /* Integrator Gain 17 bit 0 position. */
#define CTE_INT17GAIN1_bm  (1<<5)  /* Integrator Gain 17 bit 1 mask. */
#define CTE_INT17GAIN1_bp  5  /* Integrator Gain 17 bit 1 position. */
#define CTE_INT17GAIN2_bm  (1<<6)  /* Integrator Gain 17 bit 2 mask. */
#define CTE_INT17GAIN2_bp  6  /* Integrator Gain 17 bit 2 position. */
#define CTE_INT17GAIN3_bm  (1<<7)  /* Integrator Gain 17 bit 3 mask. */
#define CTE_INT17GAIN3_bp  7  /* Integrator Gain 17 bit 3 position. */

/* CTE.TIMACMP  bit masks and bit positions */
#define CTE_TIMACMP_gm  0x3FF  /* Timer A Compare group mask. */
#define CTE_TIMACMP_gp  0  /* Timer A Compare group position. */
#define CTE_TIMACMP0_bm  (1<<0)  /* Timer A Compare bit 0 mask. */
#define CTE_TIMACMP0_bp  0  /* Timer A Compare bit 0 position. */
#define CTE_TIMACMP1_bm  (1<<1)  /* Timer A Compare bit 1 mask. */
#define CTE_TIMACMP1_bp  1  /* Timer A Compare bit 1 position. */
#define CTE_TIMACMP2_bm  (1<<2)  /* Timer A Compare bit 2 mask. */
#define CTE_TIMACMP2_bp  2  /* Timer A Compare bit 2 position. */
#define CTE_TIMACMP3_bm  (1<<3)  /* Timer A Compare bit 3 mask. */
#define CTE_TIMACMP3_bp  3  /* Timer A Compare bit 3 position. */
#define CTE_TIMACMP4_bm  (1<<4)  /* Timer A Compare bit 4 mask. */
#define CTE_TIMACMP4_bp  4  /* Timer A Compare bit 4 position. */
#define CTE_TIMACMP5_bm  (1<<5)  /* Timer A Compare bit 5 mask. */
#define CTE_TIMACMP5_bp  5  /* Timer A Compare bit 5 position. */
#define CTE_TIMACMP6_bm  (1<<6)  /* Timer A Compare bit 6 mask. */
#define CTE_TIMACMP6_bp  6  /* Timer A Compare bit 6 position. */
#define CTE_TIMACMP7_bm  (1<<7)  /* Timer A Compare bit 7 mask. */
#define CTE_TIMACMP7_bp  7  /* Timer A Compare bit 7 position. */
#define CTE_TIMACMP8_bm  (1<<8)  /* Timer A Compare bit 8 mask. */
#define CTE_TIMACMP8_bp  8  /* Timer A Compare bit 8 position. */
#define CTE_TIMACMP9_bm  (1<<9)  /* Timer A Compare bit 9 mask. */
#define CTE_TIMACMP9_bp  9  /* Timer A Compare bit 9 position. */

/* CTE.TIMBCMP  bit masks and bit positions */
#define CTE_TIMBCMP_gm  0x3FF  /* Timer B Compare group mask. */
#define CTE_TIMBCMP_gp  0  /* Timer B Compare group position. */
#define CTE_TIMBCMP0_bm  (1<<0)  /* Timer B Compare bit 0 mask. */
#define CTE_TIMBCMP0_bp  0  /* Timer B Compare bit 0 position. */
#define CTE_TIMBCMP1_bm  (1<<1)  /* Timer B Compare bit 1 mask. */
#define CTE_TIMBCMP1_bp  1  /* Timer B Compare bit 1 position. */
#define CTE_TIMBCMP2_bm  (1<<2)  /* Timer B Compare bit 2 mask. */
#define CTE_TIMBCMP2_bp  2  /* Timer B Compare bit 2 position. */
#define CTE_TIMBCMP3_bm  (1<<3)  /* Timer B Compare bit 3 mask. */
#define CTE_TIMBCMP3_bp  3  /* Timer B Compare bit 3 position. */
#define CTE_TIMBCMP4_bm  (1<<4)  /* Timer B Compare bit 4 mask. */
#define CTE_TIMBCMP4_bp  4  /* Timer B Compare bit 4 position. */
#define CTE_TIMBCMP5_bm  (1<<5)  /* Timer B Compare bit 5 mask. */
#define CTE_TIMBCMP5_bp  5  /* Timer B Compare bit 5 position. */
#define CTE_TIMBCMP6_bm  (1<<6)  /* Timer B Compare bit 6 mask. */
#define CTE_TIMBCMP6_bp  6  /* Timer B Compare bit 6 position. */
#define CTE_TIMBCMP7_bm  (1<<7)  /* Timer B Compare bit 7 mask. */
#define CTE_TIMBCMP7_bp  7  /* Timer B Compare bit 7 position. */
#define CTE_TIMBCMP8_bm  (1<<8)  /* Timer B Compare bit 8 mask. */
#define CTE_TIMBCMP8_bp  8  /* Timer B Compare bit 8 position. */
#define CTE_TIMBCMP9_bm  (1<<9)  /* Timer B Compare bit 9 mask. */
#define CTE_TIMBCMP9_bp  9  /* Timer B Compare bit 9 position. */

/* CTE.PADYCHCOMPA  bit masks and bit positions */
#define CTE_PADYCHCOMP_gm  0xFFFF  /* Enable the selfcap current source at pad_ichargecomp group mask. */
#define CTE_PADYCHCOMP_gp  0  /* Enable the selfcap current source at pad_ichargecomp group position. */
#define CTE_PADYCHCOMP0_bm  (1<<0)  /* Enable the selfcap current source at pad_ichargecomp bit 0 mask. */
#define CTE_PADYCHCOMP0_bp  0  /* Enable the selfcap current source at pad_ichargecomp bit 0 position. */
#define CTE_PADYCHCOMP1_bm  (1<<1)  /* Enable the selfcap current source at pad_ichargecomp bit 1 mask. */
#define CTE_PADYCHCOMP1_bp  1  /* Enable the selfcap current source at pad_ichargecomp bit 1 position. */
#define CTE_PADYCHCOMP2_bm  (1<<2)  /* Enable the selfcap current source at pad_ichargecomp bit 2 mask. */
#define CTE_PADYCHCOMP2_bp  2  /* Enable the selfcap current source at pad_ichargecomp bit 2 position. */
#define CTE_PADYCHCOMP3_bm  (1<<3)  /* Enable the selfcap current source at pad_ichargecomp bit 3 mask. */
#define CTE_PADYCHCOMP3_bp  3  /* Enable the selfcap current source at pad_ichargecomp bit 3 position. */
#define CTE_PADYCHCOMP4_bm  (1<<4)  /* Enable the selfcap current source at pad_ichargecomp bit 4 mask. */
#define CTE_PADYCHCOMP4_bp  4  /* Enable the selfcap current source at pad_ichargecomp bit 4 position. */
#define CTE_PADYCHCOMP5_bm  (1<<5)  /* Enable the selfcap current source at pad_ichargecomp bit 5 mask. */
#define CTE_PADYCHCOMP5_bp  5  /* Enable the selfcap current source at pad_ichargecomp bit 5 position. */
#define CTE_PADYCHCOMP6_bm  (1<<6)  /* Enable the selfcap current source at pad_ichargecomp bit 6 mask. */
#define CTE_PADYCHCOMP6_bp  6  /* Enable the selfcap current source at pad_ichargecomp bit 6 position. */
#define CTE_PADYCHCOMP7_bm  (1<<7)  /* Enable the selfcap current source at pad_ichargecomp bit 7 mask. */
#define CTE_PADYCHCOMP7_bp  7  /* Enable the selfcap current source at pad_ichargecomp bit 7 position. */
#define CTE_PADYCHCOMP8_bm  (1<<8)  /* Enable the selfcap current source at pad_ichargecomp bit 8 mask. */
#define CTE_PADYCHCOMP8_bp  8  /* Enable the selfcap current source at pad_ichargecomp bit 8 position. */
#define CTE_PADYCHCOMP9_bm  (1<<9)  /* Enable the selfcap current source at pad_ichargecomp bit 9 mask. */
#define CTE_PADYCHCOMP9_bp  9  /* Enable the selfcap current source at pad_ichargecomp bit 9 position. */
#define CTE_PADYCHCOMP10_bm  (1<<10)  /* Enable the selfcap current source at pad_ichargecomp bit 10 mask. */
#define CTE_PADYCHCOMP10_bp  10  /* Enable the selfcap current source at pad_ichargecomp bit 10 position. */
#define CTE_PADYCHCOMP11_bm  (1<<11)  /* Enable the selfcap current source at pad_ichargecomp bit 11 mask. */
#define CTE_PADYCHCOMP11_bp  11  /* Enable the selfcap current source at pad_ichargecomp bit 11 position. */
#define CTE_PADYCHCOMP12_bm  (1<<12)  /* Enable the selfcap current source at pad_ichargecomp bit 12 mask. */
#define CTE_PADYCHCOMP12_bp  12  /* Enable the selfcap current source at pad_ichargecomp bit 12 position. */
#define CTE_PADYCHCOMP13_bm  (1<<13)  /* Enable the selfcap current source at pad_ichargecomp bit 13 mask. */
#define CTE_PADYCHCOMP13_bp  13  /* Enable the selfcap current source at pad_ichargecomp bit 13 position. */
#define CTE_PADYCHCOMP14_bm  (1<<14)  /* Enable the selfcap current source at pad_ichargecomp bit 14 mask. */
#define CTE_PADYCHCOMP14_bp  14  /* Enable the selfcap current source at pad_ichargecomp bit 14 position. */
#define CTE_PADYCHCOMP15_bm  (1<<15)  /* Enable the selfcap current source at pad_ichargecomp bit 15 mask. */
#define CTE_PADYCHCOMP15_bp  15  /* Enable the selfcap current source at pad_ichargecomp bit 15 position. */

/* CTE.PADYCHCOMPB  bit masks and bit positions */
/* CTE_PADYCHCOMP  is already defined. */

/* CTE.PADBNY1  bit masks and bit positions */
#define CTE_SCBNY1A_gm  0xFF  /* Current source nmos calibration Y1 A group mask. */
#define CTE_SCBNY1A_gp  0  /* Current source nmos calibration Y1 A group position. */
#define CTE_SCBNY1A0_bm  (1<<0)  /* Current source nmos calibration Y1 A bit 0 mask. */
#define CTE_SCBNY1A0_bp  0  /* Current source nmos calibration Y1 A bit 0 position. */
#define CTE_SCBNY1A1_bm  (1<<1)  /* Current source nmos calibration Y1 A bit 1 mask. */
#define CTE_SCBNY1A1_bp  1  /* Current source nmos calibration Y1 A bit 1 position. */
#define CTE_SCBNY1A2_bm  (1<<2)  /* Current source nmos calibration Y1 A bit 2 mask. */
#define CTE_SCBNY1A2_bp  2  /* Current source nmos calibration Y1 A bit 2 position. */
#define CTE_SCBNY1A3_bm  (1<<3)  /* Current source nmos calibration Y1 A bit 3 mask. */
#define CTE_SCBNY1A3_bp  3  /* Current source nmos calibration Y1 A bit 3 position. */
#define CTE_SCBNY1A4_bm  (1<<4)  /* Current source nmos calibration Y1 A bit 4 mask. */
#define CTE_SCBNY1A4_bp  4  /* Current source nmos calibration Y1 A bit 4 position. */
#define CTE_SCBNY1A5_bm  (1<<5)  /* Current source nmos calibration Y1 A bit 5 mask. */
#define CTE_SCBNY1A5_bp  5  /* Current source nmos calibration Y1 A bit 5 position. */
#define CTE_SCBNY1A6_bm  (1<<6)  /* Current source nmos calibration Y1 A bit 6 mask. */
#define CTE_SCBNY1A6_bp  6  /* Current source nmos calibration Y1 A bit 6 position. */
#define CTE_SCBNY1A7_bm  (1<<7)  /* Current source nmos calibration Y1 A bit 7 mask. */
#define CTE_SCBNY1A7_bp  7  /* Current source nmos calibration Y1 A bit 7 position. */
#define CTE_SCBNY1B_gm  0xFF00  /* Current source nmos calibration Y1 B group mask. */
#define CTE_SCBNY1B_gp  8  /* Current source nmos calibration Y1 B group position. */
#define CTE_SCBNY1B0_bm  (1<<8)  /* Current source nmos calibration Y1 B bit 0 mask. */
#define CTE_SCBNY1B0_bp  8  /* Current source nmos calibration Y1 B bit 0 position. */
#define CTE_SCBNY1B1_bm  (1<<9)  /* Current source nmos calibration Y1 B bit 1 mask. */
#define CTE_SCBNY1B1_bp  9  /* Current source nmos calibration Y1 B bit 1 position. */
#define CTE_SCBNY1B2_bm  (1<<10)  /* Current source nmos calibration Y1 B bit 2 mask. */
#define CTE_SCBNY1B2_bp  10  /* Current source nmos calibration Y1 B bit 2 position. */
#define CTE_SCBNY1B3_bm  (1<<11)  /* Current source nmos calibration Y1 B bit 3 mask. */
#define CTE_SCBNY1B3_bp  11  /* Current source nmos calibration Y1 B bit 3 position. */
#define CTE_SCBNY1B4_bm  (1<<12)  /* Current source nmos calibration Y1 B bit 4 mask. */
#define CTE_SCBNY1B4_bp  12  /* Current source nmos calibration Y1 B bit 4 position. */
#define CTE_SCBNY1B5_bm  (1<<13)  /* Current source nmos calibration Y1 B bit 5 mask. */
#define CTE_SCBNY1B5_bp  13  /* Current source nmos calibration Y1 B bit 5 position. */
#define CTE_SCBNY1B6_bm  (1<<14)  /* Current source nmos calibration Y1 B bit 6 mask. */
#define CTE_SCBNY1B6_bp  14  /* Current source nmos calibration Y1 B bit 6 position. */
#define CTE_SCBNY1B7_bm  (1<<15)  /* Current source nmos calibration Y1 B bit 7 mask. */
#define CTE_SCBNY1B7_bp  15  /* Current source nmos calibration Y1 B bit 7 position. */

/* CTE.PADBPY1  bit masks and bit positions */
#define CTE_SCBPY1A_gm  0xFF  /* Current source pmos calibration Y1 A group mask. */
#define CTE_SCBPY1A_gp  0  /* Current source pmos calibration Y1 A group position. */
#define CTE_SCBPY1A0_bm  (1<<0)  /* Current source pmos calibration Y1 A bit 0 mask. */
#define CTE_SCBPY1A0_bp  0  /* Current source pmos calibration Y1 A bit 0 position. */
#define CTE_SCBPY1A1_bm  (1<<1)  /* Current source pmos calibration Y1 A bit 1 mask. */
#define CTE_SCBPY1A1_bp  1  /* Current source pmos calibration Y1 A bit 1 position. */
#define CTE_SCBPY1A2_bm  (1<<2)  /* Current source pmos calibration Y1 A bit 2 mask. */
#define CTE_SCBPY1A2_bp  2  /* Current source pmos calibration Y1 A bit 2 position. */
#define CTE_SCBPY1A3_bm  (1<<3)  /* Current source pmos calibration Y1 A bit 3 mask. */
#define CTE_SCBPY1A3_bp  3  /* Current source pmos calibration Y1 A bit 3 position. */
#define CTE_SCBPY1A4_bm  (1<<4)  /* Current source pmos calibration Y1 A bit 4 mask. */
#define CTE_SCBPY1A4_bp  4  /* Current source pmos calibration Y1 A bit 4 position. */
#define CTE_SCBPY1A5_bm  (1<<5)  /* Current source pmos calibration Y1 A bit 5 mask. */
#define CTE_SCBPY1A5_bp  5  /* Current source pmos calibration Y1 A bit 5 position. */
#define CTE_SCBPY1A6_bm  (1<<6)  /* Current source pmos calibration Y1 A bit 6 mask. */
#define CTE_SCBPY1A6_bp  6  /* Current source pmos calibration Y1 A bit 6 position. */
#define CTE_SCBPY1A7_bm  (1<<7)  /* Current source pmos calibration Y1 A bit 7 mask. */
#define CTE_SCBPY1A7_bp  7  /* Current source pmos calibration Y1 A bit 7 position. */
#define CTE_SCBPY1B_gm  0xFF00  /* Current source pmos calibration Y1 B group mask. */
#define CTE_SCBPY1B_gp  8  /* Current source pmos calibration Y1 B group position. */
#define CTE_SCBPY1B0_bm  (1<<8)  /* Current source pmos calibration Y1 B bit 0 mask. */
#define CTE_SCBPY1B0_bp  8  /* Current source pmos calibration Y1 B bit 0 position. */
#define CTE_SCBPY1B1_bm  (1<<9)  /* Current source pmos calibration Y1 B bit 1 mask. */
#define CTE_SCBPY1B1_bp  9  /* Current source pmos calibration Y1 B bit 1 position. */
#define CTE_SCBPY1B2_bm  (1<<10)  /* Current source pmos calibration Y1 B bit 2 mask. */
#define CTE_SCBPY1B2_bp  10  /* Current source pmos calibration Y1 B bit 2 position. */
#define CTE_SCBPY1B3_bm  (1<<11)  /* Current source pmos calibration Y1 B bit 3 mask. */
#define CTE_SCBPY1B3_bp  11  /* Current source pmos calibration Y1 B bit 3 position. */
#define CTE_SCBPY1B4_bm  (1<<12)  /* Current source pmos calibration Y1 B bit 4 mask. */
#define CTE_SCBPY1B4_bp  12  /* Current source pmos calibration Y1 B bit 4 position. */
#define CTE_SCBPY1B5_bm  (1<<13)  /* Current source pmos calibration Y1 B bit 5 mask. */
#define CTE_SCBPY1B5_bp  13  /* Current source pmos calibration Y1 B bit 5 position. */
#define CTE_SCBPY1B6_bm  (1<<14)  /* Current source pmos calibration Y1 B bit 6 mask. */
#define CTE_SCBPY1B6_bp  14  /* Current source pmos calibration Y1 B bit 6 position. */
#define CTE_SCBPY1B7_bm  (1<<15)  /* Current source pmos calibration Y1 B bit 7 mask. */
#define CTE_SCBPY1B7_bp  15  /* Current source pmos calibration Y1 B bit 7 position. */

/* CTE.PADY1  bit masks and bit positions */
#define CTE_SCEXTRAPYA_gm  0x0F  /* Enable extra pmos calibration Y1 A group mask. */
#define CTE_SCEXTRAPYA_gp  0  /* Enable extra pmos calibration Y1 A group position. */
#define CTE_SCEXTRAPYA0_bm  (1<<0)  /* Enable extra pmos calibration Y1 A bit 0 mask. */
#define CTE_SCEXTRAPYA0_bp  0  /* Enable extra pmos calibration Y1 A bit 0 position. */
#define CTE_SCEXTRAPYA1_bm  (1<<1)  /* Enable extra pmos calibration Y1 A bit 1 mask. */
#define CTE_SCEXTRAPYA1_bp  1  /* Enable extra pmos calibration Y1 A bit 1 position. */
#define CTE_SCEXTRAPYA2_bm  (1<<2)  /* Enable extra pmos calibration Y1 A bit 2 mask. */
#define CTE_SCEXTRAPYA2_bp  2  /* Enable extra pmos calibration Y1 A bit 2 position. */
#define CTE_SCEXTRAPYA3_bm  (1<<3)  /* Enable extra pmos calibration Y1 A bit 3 mask. */
#define CTE_SCEXTRAPYA3_bp  3  /* Enable extra pmos calibration Y1 A bit 3 position. */
#define CTE_SCEXTRAPYB_gm  0xF0  /* Enable extra pmos calibration Y1 B group mask. */
#define CTE_SCEXTRAPYB_gp  4  /* Enable extra pmos calibration Y1 B group position. */
#define CTE_SCEXTRAPYB0_bm  (1<<4)  /* Enable extra pmos calibration Y1 B bit 0 mask. */
#define CTE_SCEXTRAPYB0_bp  4  /* Enable extra pmos calibration Y1 B bit 0 position. */
#define CTE_SCEXTRAPYB1_bm  (1<<5)  /* Enable extra pmos calibration Y1 B bit 1 mask. */
#define CTE_SCEXTRAPYB1_bp  5  /* Enable extra pmos calibration Y1 B bit 1 position. */
#define CTE_SCEXTRAPYB2_bm  (1<<6)  /* Enable extra pmos calibration Y1 B bit 2 mask. */
#define CTE_SCEXTRAPYB2_bp  6  /* Enable extra pmos calibration Y1 B bit 2 position. */
#define CTE_SCEXTRAPYB3_bm  (1<<7)  /* Enable extra pmos calibration Y1 B bit 3 mask. */
#define CTE_SCEXTRAPYB3_bp  7  /* Enable extra pmos calibration Y1 B bit 3 position. */
#define CTE_SCEXTRANYA_gm  0xF00  /* Enable extra nmos calibration Y1 A group mask. */
#define CTE_SCEXTRANYA_gp  8  /* Enable extra nmos calibration Y1 A group position. */
#define CTE_SCEXTRANYA0_bm  (1<<8)  /* Enable extra nmos calibration Y1 A bit 0 mask. */
#define CTE_SCEXTRANYA0_bp  8  /* Enable extra nmos calibration Y1 A bit 0 position. */
#define CTE_SCEXTRANYA1_bm  (1<<9)  /* Enable extra nmos calibration Y1 A bit 1 mask. */
#define CTE_SCEXTRANYA1_bp  9  /* Enable extra nmos calibration Y1 A bit 1 position. */
#define CTE_SCEXTRANYA2_bm  (1<<10)  /* Enable extra nmos calibration Y1 A bit 2 mask. */
#define CTE_SCEXTRANYA2_bp  10  /* Enable extra nmos calibration Y1 A bit 2 position. */
#define CTE_SCEXTRANYA3_bm  (1<<11)  /* Enable extra nmos calibration Y1 A bit 3 mask. */
#define CTE_SCEXTRANYA3_bp  11  /* Enable extra nmos calibration Y1 A bit 3 position. */
#define CTE_SCEXTRANYB_gm  0xF000  /* Enable extra nmos calibration Y1 B group mask. */
#define CTE_SCEXTRANYB_gp  12  /* Enable extra nmos calibration Y1 B group position. */
#define CTE_SCEXTRANYB0_bm  (1<<12)  /* Enable extra nmos calibration Y1 B bit 0 mask. */
#define CTE_SCEXTRANYB0_bp  12  /* Enable extra nmos calibration Y1 B bit 0 position. */
#define CTE_SCEXTRANYB1_bm  (1<<13)  /* Enable extra nmos calibration Y1 B bit 1 mask. */
#define CTE_SCEXTRANYB1_bp  13  /* Enable extra nmos calibration Y1 B bit 1 position. */
#define CTE_SCEXTRANYB2_bm  (1<<14)  /* Enable extra nmos calibration Y1 B bit 2 mask. */
#define CTE_SCEXTRANYB2_bp  14  /* Enable extra nmos calibration Y1 B bit 2 position. */
#define CTE_SCEXTRANYB3_bm  (1<<15)  /* Enable extra nmos calibration Y1 B bit 3 mask. */
#define CTE_SCEXTRANYB3_bp  15  /* Enable extra nmos calibration Y1 B bit 3 position. */

/* CTE.XYBIAS  bit masks and bit positions */
#define CTE_XBIASX1EN_bm  0x01  /* Bias X1 Enable bit mask. */
#define CTE_XBIASX1EN_bp  0  /* Bias X1 Enable bit position. */
#define CTE_SELSRX1_gm  0x06  /* Select Slew Rate X1 group mask. */
#define CTE_SELSRX1_gp  1  /* Select Slew Rate X1 group position. */
#define CTE_SELSRX10_bm  (1<<1)  /* Select Slew Rate X1 bit 0 mask. */
#define CTE_SELSRX10_bp  1  /* Select Slew Rate X1 bit 0 position. */
#define CTE_SELSRX11_bm  (1<<2)  /* Select Slew Rate X1 bit 1 mask. */
#define CTE_SELSRX11_bp  2  /* Select Slew Rate X1 bit 1 position. */
#define CTE_XBIASX2EN_bm  0x08  /* Bias X2 Enable bit mask. */
#define CTE_XBIASX2EN_bp  3  /* Bias X2 Enable bit position. */
#define CTE_SELSRX2_gm  0x30  /* Select Slew Rate X2 group mask. */
#define CTE_SELSRX2_gp  4  /* Select Slew Rate X2 group position. */
#define CTE_SELSRX20_bm  (1<<4)  /* Select Slew Rate X2 bit 0 mask. */
#define CTE_SELSRX20_bp  4  /* Select Slew Rate X2 bit 0 position. */
#define CTE_SELSRX21_bm  (1<<5)  /* Select Slew Rate X2 bit 1 mask. */
#define CTE_SELSRX21_bp  5  /* Select Slew Rate X2 bit 1 position. */
#define CTE_XBIASY1EN_bm  0x100  /* Bias Y1 Enable bit mask. */
#define CTE_XBIASY1EN_bp  8  /* Bias Y1 Enable bit position. */
#define CTE_SELSRY1_gm  0x600  /* Select Slew Rate Y1 group mask. */
#define CTE_SELSRY1_gp  9  /* Select Slew Rate Y1 group position. */
#define CTE_SELSRY10_bm  (1<<9)  /* Select Slew Rate Y1 bit 0 mask. */
#define CTE_SELSRY10_bp  9  /* Select Slew Rate Y1 bit 0 position. */
#define CTE_SELSRY11_bm  (1<<10)  /* Select Slew Rate Y1 bit 1 mask. */
#define CTE_SELSRY11_bp  10  /* Select Slew Rate Y1 bit 1 position. */

/* CTE.PADSCOEXA  bit masks and bit positions */
#define CTE_PADSCOEX_gm  0xFFFF  /* Pad Self Cap Output Enable X group mask. */
#define CTE_PADSCOEX_gp  0  /* Pad Self Cap Output Enable X group position. */
#define CTE_PADSCOEX0_bm  (1<<0)  /* Pad Self Cap Output Enable X bit 0 mask. */
#define CTE_PADSCOEX0_bp  0  /* Pad Self Cap Output Enable X bit 0 position. */
#define CTE_PADSCOEX1_bm  (1<<1)  /* Pad Self Cap Output Enable X bit 1 mask. */
#define CTE_PADSCOEX1_bp  1  /* Pad Self Cap Output Enable X bit 1 position. */
#define CTE_PADSCOEX2_bm  (1<<2)  /* Pad Self Cap Output Enable X bit 2 mask. */
#define CTE_PADSCOEX2_bp  2  /* Pad Self Cap Output Enable X bit 2 position. */
#define CTE_PADSCOEX3_bm  (1<<3)  /* Pad Self Cap Output Enable X bit 3 mask. */
#define CTE_PADSCOEX3_bp  3  /* Pad Self Cap Output Enable X bit 3 position. */
#define CTE_PADSCOEX4_bm  (1<<4)  /* Pad Self Cap Output Enable X bit 4 mask. */
#define CTE_PADSCOEX4_bp  4  /* Pad Self Cap Output Enable X bit 4 position. */
#define CTE_PADSCOEX5_bm  (1<<5)  /* Pad Self Cap Output Enable X bit 5 mask. */
#define CTE_PADSCOEX5_bp  5  /* Pad Self Cap Output Enable X bit 5 position. */
#define CTE_PADSCOEX6_bm  (1<<6)  /* Pad Self Cap Output Enable X bit 6 mask. */
#define CTE_PADSCOEX6_bp  6  /* Pad Self Cap Output Enable X bit 6 position. */
#define CTE_PADSCOEX7_bm  (1<<7)  /* Pad Self Cap Output Enable X bit 7 mask. */
#define CTE_PADSCOEX7_bp  7  /* Pad Self Cap Output Enable X bit 7 position. */
#define CTE_PADSCOEX8_bm  (1<<8)  /* Pad Self Cap Output Enable X bit 8 mask. */
#define CTE_PADSCOEX8_bp  8  /* Pad Self Cap Output Enable X bit 8 position. */
#define CTE_PADSCOEX9_bm  (1<<9)  /* Pad Self Cap Output Enable X bit 9 mask. */
#define CTE_PADSCOEX9_bp  9  /* Pad Self Cap Output Enable X bit 9 position. */
#define CTE_PADSCOEX10_bm  (1<<10)  /* Pad Self Cap Output Enable X bit 10 mask. */
#define CTE_PADSCOEX10_bp  10  /* Pad Self Cap Output Enable X bit 10 position. */
#define CTE_PADSCOEX11_bm  (1<<11)  /* Pad Self Cap Output Enable X bit 11 mask. */
#define CTE_PADSCOEX11_bp  11  /* Pad Self Cap Output Enable X bit 11 position. */
#define CTE_PADSCOEX12_bm  (1<<12)  /* Pad Self Cap Output Enable X bit 12 mask. */
#define CTE_PADSCOEX12_bp  12  /* Pad Self Cap Output Enable X bit 12 position. */
#define CTE_PADSCOEX13_bm  (1<<13)  /* Pad Self Cap Output Enable X bit 13 mask. */
#define CTE_PADSCOEX13_bp  13  /* Pad Self Cap Output Enable X bit 13 position. */
#define CTE_PADSCOEX14_bm  (1<<14)  /* Pad Self Cap Output Enable X bit 14 mask. */
#define CTE_PADSCOEX14_bp  14  /* Pad Self Cap Output Enable X bit 14 position. */
#define CTE_PADSCOEX15_bm  (1<<15)  /* Pad Self Cap Output Enable X bit 15 mask. */
#define CTE_PADSCOEX15_bp  15  /* Pad Self Cap Output Enable X bit 15 position. */

/* CTE.PADSCOEXB  bit masks and bit positions */
/* CTE_PADSCOEX  is already defined. */

/* CTE.PADSCOEYA  bit masks and bit positions */
#define CTE_PADSCOEY_gm  0xFFFF  /* Pad Self Cap Output Enable Y group mask. */
#define CTE_PADSCOEY_gp  0  /* Pad Self Cap Output Enable Y group position. */
#define CTE_PADSCOEY0_bm  (1<<0)  /* Pad Self Cap Output Enable Y bit 0 mask. */
#define CTE_PADSCOEY0_bp  0  /* Pad Self Cap Output Enable Y bit 0 position. */
#define CTE_PADSCOEY1_bm  (1<<1)  /* Pad Self Cap Output Enable Y bit 1 mask. */
#define CTE_PADSCOEY1_bp  1  /* Pad Self Cap Output Enable Y bit 1 position. */
#define CTE_PADSCOEY2_bm  (1<<2)  /* Pad Self Cap Output Enable Y bit 2 mask. */
#define CTE_PADSCOEY2_bp  2  /* Pad Self Cap Output Enable Y bit 2 position. */
#define CTE_PADSCOEY3_bm  (1<<3)  /* Pad Self Cap Output Enable Y bit 3 mask. */
#define CTE_PADSCOEY3_bp  3  /* Pad Self Cap Output Enable Y bit 3 position. */
#define CTE_PADSCOEY4_bm  (1<<4)  /* Pad Self Cap Output Enable Y bit 4 mask. */
#define CTE_PADSCOEY4_bp  4  /* Pad Self Cap Output Enable Y bit 4 position. */
#define CTE_PADSCOEY5_bm  (1<<5)  /* Pad Self Cap Output Enable Y bit 5 mask. */
#define CTE_PADSCOEY5_bp  5  /* Pad Self Cap Output Enable Y bit 5 position. */
#define CTE_PADSCOEY6_bm  (1<<6)  /* Pad Self Cap Output Enable Y bit 6 mask. */
#define CTE_PADSCOEY6_bp  6  /* Pad Self Cap Output Enable Y bit 6 position. */
#define CTE_PADSCOEY7_bm  (1<<7)  /* Pad Self Cap Output Enable Y bit 7 mask. */
#define CTE_PADSCOEY7_bp  7  /* Pad Self Cap Output Enable Y bit 7 position. */
#define CTE_PADSCOEY8_bm  (1<<8)  /* Pad Self Cap Output Enable Y bit 8 mask. */
#define CTE_PADSCOEY8_bp  8  /* Pad Self Cap Output Enable Y bit 8 position. */
#define CTE_PADSCOEY9_bm  (1<<9)  /* Pad Self Cap Output Enable Y bit 9 mask. */
#define CTE_PADSCOEY9_bp  9  /* Pad Self Cap Output Enable Y bit 9 position. */
#define CTE_PADSCOEY10_bm  (1<<10)  /* Pad Self Cap Output Enable Y bit 10 mask. */
#define CTE_PADSCOEY10_bp  10  /* Pad Self Cap Output Enable Y bit 10 position. */
#define CTE_PADSCOEY11_bm  (1<<11)  /* Pad Self Cap Output Enable Y bit 11 mask. */
#define CTE_PADSCOEY11_bp  11  /* Pad Self Cap Output Enable Y bit 11 position. */
#define CTE_PADSCOEY12_bm  (1<<12)  /* Pad Self Cap Output Enable Y bit 12 mask. */
#define CTE_PADSCOEY12_bp  12  /* Pad Self Cap Output Enable Y bit 12 position. */
#define CTE_PADSCOEY13_bm  (1<<13)  /* Pad Self Cap Output Enable Y bit 13 mask. */
#define CTE_PADSCOEY13_bp  13  /* Pad Self Cap Output Enable Y bit 13 position. */
#define CTE_PADSCOEY14_bm  (1<<14)  /* Pad Self Cap Output Enable Y bit 14 mask. */
#define CTE_PADSCOEY14_bp  14  /* Pad Self Cap Output Enable Y bit 14 position. */
#define CTE_PADSCOEY15_bm  (1<<15)  /* Pad Self Cap Output Enable Y bit 15 mask. */
#define CTE_PADSCOEY15_bp  15  /* Pad Self Cap Output Enable Y bit 15 position. */

/* CTE.PADSCOEYB  bit masks and bit positions */
/* CTE_PADSCOEY  is already defined. */

/* CTE.PADYONXENA  bit masks and bit positions */
#define CTE_PADYONXEN_gm  0xFFFF  /* Pad YonX Enable group mask. */
#define CTE_PADYONXEN_gp  0  /* Pad YonX Enable group position. */
#define CTE_PADYONXEN0_bm  (1<<0)  /* Pad YonX Enable bit 0 mask. */
#define CTE_PADYONXEN0_bp  0  /* Pad YonX Enable bit 0 position. */
#define CTE_PADYONXEN1_bm  (1<<1)  /* Pad YonX Enable bit 1 mask. */
#define CTE_PADYONXEN1_bp  1  /* Pad YonX Enable bit 1 position. */
#define CTE_PADYONXEN2_bm  (1<<2)  /* Pad YonX Enable bit 2 mask. */
#define CTE_PADYONXEN2_bp  2  /* Pad YonX Enable bit 2 position. */
#define CTE_PADYONXEN3_bm  (1<<3)  /* Pad YonX Enable bit 3 mask. */
#define CTE_PADYONXEN3_bp  3  /* Pad YonX Enable bit 3 position. */
#define CTE_PADYONXEN4_bm  (1<<4)  /* Pad YonX Enable bit 4 mask. */
#define CTE_PADYONXEN4_bp  4  /* Pad YonX Enable bit 4 position. */
#define CTE_PADYONXEN5_bm  (1<<5)  /* Pad YonX Enable bit 5 mask. */
#define CTE_PADYONXEN5_bp  5  /* Pad YonX Enable bit 5 position. */
#define CTE_PADYONXEN6_bm  (1<<6)  /* Pad YonX Enable bit 6 mask. */
#define CTE_PADYONXEN6_bp  6  /* Pad YonX Enable bit 6 position. */
#define CTE_PADYONXEN7_bm  (1<<7)  /* Pad YonX Enable bit 7 mask. */
#define CTE_PADYONXEN7_bp  7  /* Pad YonX Enable bit 7 position. */
#define CTE_PADYONXEN8_bm  (1<<8)  /* Pad YonX Enable bit 8 mask. */
#define CTE_PADYONXEN8_bp  8  /* Pad YonX Enable bit 8 position. */
#define CTE_PADYONXEN9_bm  (1<<9)  /* Pad YonX Enable bit 9 mask. */
#define CTE_PADYONXEN9_bp  9  /* Pad YonX Enable bit 9 position. */
#define CTE_PADYONXEN10_bm  (1<<10)  /* Pad YonX Enable bit 10 mask. */
#define CTE_PADYONXEN10_bp  10  /* Pad YonX Enable bit 10 position. */
#define CTE_PADYONXEN11_bm  (1<<11)  /* Pad YonX Enable bit 11 mask. */
#define CTE_PADYONXEN11_bp  11  /* Pad YonX Enable bit 11 position. */
#define CTE_PADYONXEN12_bm  (1<<12)  /* Pad YonX Enable bit 12 mask. */
#define CTE_PADYONXEN12_bp  12  /* Pad YonX Enable bit 12 position. */
#define CTE_PADYONXEN13_bm  (1<<13)  /* Pad YonX Enable bit 13 mask. */
#define CTE_PADYONXEN13_bp  13  /* Pad YonX Enable bit 13 position. */
#define CTE_PADYONXEN14_bm  (1<<14)  /* Pad YonX Enable bit 14 mask. */
#define CTE_PADYONXEN14_bp  14  /* Pad YonX Enable bit 14 position. */
#define CTE_PADYONXEN15_bm  (1<<15)  /* Pad YonX Enable bit 15 mask. */
#define CTE_PADYONXEN15_bp  15  /* Pad YonX Enable bit 15 position. */

/* CTE.PADYONXENB  bit masks and bit positions */
/* CTE_PADYONXEN  is already defined. */

/* CTE.PADXONXENA  bit masks and bit positions */
#define CTE_PADXONXEN_gm  0xFFFF  /* Pad XonX Enable group mask. */
#define CTE_PADXONXEN_gp  0  /* Pad XonX Enable group position. */
#define CTE_PADXONXEN0_bm  (1<<0)  /* Pad XonX Enable bit 0 mask. */
#define CTE_PADXONXEN0_bp  0  /* Pad XonX Enable bit 0 position. */
#define CTE_PADXONXEN1_bm  (1<<1)  /* Pad XonX Enable bit 1 mask. */
#define CTE_PADXONXEN1_bp  1  /* Pad XonX Enable bit 1 position. */
#define CTE_PADXONXEN2_bm  (1<<2)  /* Pad XonX Enable bit 2 mask. */
#define CTE_PADXONXEN2_bp  2  /* Pad XonX Enable bit 2 position. */
#define CTE_PADXONXEN3_bm  (1<<3)  /* Pad XonX Enable bit 3 mask. */
#define CTE_PADXONXEN3_bp  3  /* Pad XonX Enable bit 3 position. */
#define CTE_PADXONXEN4_bm  (1<<4)  /* Pad XonX Enable bit 4 mask. */
#define CTE_PADXONXEN4_bp  4  /* Pad XonX Enable bit 4 position. */
#define CTE_PADXONXEN5_bm  (1<<5)  /* Pad XonX Enable bit 5 mask. */
#define CTE_PADXONXEN5_bp  5  /* Pad XonX Enable bit 5 position. */
#define CTE_PADXONXEN6_bm  (1<<6)  /* Pad XonX Enable bit 6 mask. */
#define CTE_PADXONXEN6_bp  6  /* Pad XonX Enable bit 6 position. */
#define CTE_PADXONXEN7_bm  (1<<7)  /* Pad XonX Enable bit 7 mask. */
#define CTE_PADXONXEN7_bp  7  /* Pad XonX Enable bit 7 position. */
#define CTE_PADXONXEN8_bm  (1<<8)  /* Pad XonX Enable bit 8 mask. */
#define CTE_PADXONXEN8_bp  8  /* Pad XonX Enable bit 8 position. */
#define CTE_PADXONXEN9_bm  (1<<9)  /* Pad XonX Enable bit 9 mask. */
#define CTE_PADXONXEN9_bp  9  /* Pad XonX Enable bit 9 position. */
#define CTE_PADXONXEN10_bm  (1<<10)  /* Pad XonX Enable bit 10 mask. */
#define CTE_PADXONXEN10_bp  10  /* Pad XonX Enable bit 10 position. */
#define CTE_PADXONXEN11_bm  (1<<11)  /* Pad XonX Enable bit 11 mask. */
#define CTE_PADXONXEN11_bp  11  /* Pad XonX Enable bit 11 position. */
#define CTE_PADXONXEN12_bm  (1<<12)  /* Pad XonX Enable bit 12 mask. */
#define CTE_PADXONXEN12_bp  12  /* Pad XonX Enable bit 12 position. */
#define CTE_PADXONXEN13_bm  (1<<13)  /* Pad XonX Enable bit 13 mask. */
#define CTE_PADXONXEN13_bp  13  /* Pad XonX Enable bit 13 position. */
#define CTE_PADXONXEN14_bm  (1<<14)  /* Pad XonX Enable bit 14 mask. */
#define CTE_PADXONXEN14_bp  14  /* Pad XonX Enable bit 14 position. */
#define CTE_PADXONXEN15_bm  (1<<15)  /* Pad XonX Enable bit 15 mask. */
#define CTE_PADXONXEN15_bp  15  /* Pad XonX Enable bit 15 position. */

/* CTE.PADXONXENB  bit masks and bit positions */
/* CTE_PADXONXEN  is already defined. */

/* CTE.PADYONYENA  bit masks and bit positions */
#define CTE_PADYONYEN_gm  0xFFFF  /* Pad YonY Enable group mask. */
#define CTE_PADYONYEN_gp  0  /* Pad YonY Enable group position. */
#define CTE_PADYONYEN0_bm  (1<<0)  /* Pad YonY Enable bit 0 mask. */
#define CTE_PADYONYEN0_bp  0  /* Pad YonY Enable bit 0 position. */
#define CTE_PADYONYEN1_bm  (1<<1)  /* Pad YonY Enable bit 1 mask. */
#define CTE_PADYONYEN1_bp  1  /* Pad YonY Enable bit 1 position. */
#define CTE_PADYONYEN2_bm  (1<<2)  /* Pad YonY Enable bit 2 mask. */
#define CTE_PADYONYEN2_bp  2  /* Pad YonY Enable bit 2 position. */
#define CTE_PADYONYEN3_bm  (1<<3)  /* Pad YonY Enable bit 3 mask. */
#define CTE_PADYONYEN3_bp  3  /* Pad YonY Enable bit 3 position. */
#define CTE_PADYONYEN4_bm  (1<<4)  /* Pad YonY Enable bit 4 mask. */
#define CTE_PADYONYEN4_bp  4  /* Pad YonY Enable bit 4 position. */
#define CTE_PADYONYEN5_bm  (1<<5)  /* Pad YonY Enable bit 5 mask. */
#define CTE_PADYONYEN5_bp  5  /* Pad YonY Enable bit 5 position. */
#define CTE_PADYONYEN6_bm  (1<<6)  /* Pad YonY Enable bit 6 mask. */
#define CTE_PADYONYEN6_bp  6  /* Pad YonY Enable bit 6 position. */
#define CTE_PADYONYEN7_bm  (1<<7)  /* Pad YonY Enable bit 7 mask. */
#define CTE_PADYONYEN7_bp  7  /* Pad YonY Enable bit 7 position. */
#define CTE_PADYONYEN8_bm  (1<<8)  /* Pad YonY Enable bit 8 mask. */
#define CTE_PADYONYEN8_bp  8  /* Pad YonY Enable bit 8 position. */
#define CTE_PADYONYEN9_bm  (1<<9)  /* Pad YonY Enable bit 9 mask. */
#define CTE_PADYONYEN9_bp  9  /* Pad YonY Enable bit 9 position. */
#define CTE_PADYONYEN10_bm  (1<<10)  /* Pad YonY Enable bit 10 mask. */
#define CTE_PADYONYEN10_bp  10  /* Pad YonY Enable bit 10 position. */
#define CTE_PADYONYEN11_bm  (1<<11)  /* Pad YonY Enable bit 11 mask. */
#define CTE_PADYONYEN11_bp  11  /* Pad YonY Enable bit 11 position. */
#define CTE_PADYONYEN12_bm  (1<<12)  /* Pad YonY Enable bit 12 mask. */
#define CTE_PADYONYEN12_bp  12  /* Pad YonY Enable bit 12 position. */
#define CTE_PADYONYEN13_bm  (1<<13)  /* Pad YonY Enable bit 13 mask. */
#define CTE_PADYONYEN13_bp  13  /* Pad YonY Enable bit 13 position. */
#define CTE_PADYONYEN14_bm  (1<<14)  /* Pad YonY Enable bit 14 mask. */
#define CTE_PADYONYEN14_bp  14  /* Pad YonY Enable bit 14 position. */
#define CTE_PADYONYEN15_bm  (1<<15)  /* Pad YonY Enable bit 15 mask. */
#define CTE_PADYONYEN15_bp  15  /* Pad YonY Enable bit 15 position. */

/* CTE.PADYONYENB  bit masks and bit positions */
/* CTE_PADYONYEN  is already defined. */

/* CTE.PADPROXENXA  bit masks and bit positions */
#define CTE_PADPROXENX_gm  0xFFFF  /* Pad Proximity Enable X group mask. */
#define CTE_PADPROXENX_gp  0  /* Pad Proximity Enable X group position. */
#define CTE_PADPROXENX0_bm  (1<<0)  /* Pad Proximity Enable X bit 0 mask. */
#define CTE_PADPROXENX0_bp  0  /* Pad Proximity Enable X bit 0 position. */
#define CTE_PADPROXENX1_bm  (1<<1)  /* Pad Proximity Enable X bit 1 mask. */
#define CTE_PADPROXENX1_bp  1  /* Pad Proximity Enable X bit 1 position. */
#define CTE_PADPROXENX2_bm  (1<<2)  /* Pad Proximity Enable X bit 2 mask. */
#define CTE_PADPROXENX2_bp  2  /* Pad Proximity Enable X bit 2 position. */
#define CTE_PADPROXENX3_bm  (1<<3)  /* Pad Proximity Enable X bit 3 mask. */
#define CTE_PADPROXENX3_bp  3  /* Pad Proximity Enable X bit 3 position. */
#define CTE_PADPROXENX4_bm  (1<<4)  /* Pad Proximity Enable X bit 4 mask. */
#define CTE_PADPROXENX4_bp  4  /* Pad Proximity Enable X bit 4 position. */
#define CTE_PADPROXENX5_bm  (1<<5)  /* Pad Proximity Enable X bit 5 mask. */
#define CTE_PADPROXENX5_bp  5  /* Pad Proximity Enable X bit 5 position. */
#define CTE_PADPROXENX6_bm  (1<<6)  /* Pad Proximity Enable X bit 6 mask. */
#define CTE_PADPROXENX6_bp  6  /* Pad Proximity Enable X bit 6 position. */
#define CTE_PADPROXENX7_bm  (1<<7)  /* Pad Proximity Enable X bit 7 mask. */
#define CTE_PADPROXENX7_bp  7  /* Pad Proximity Enable X bit 7 position. */
#define CTE_PADPROXENX8_bm  (1<<8)  /* Pad Proximity Enable X bit 8 mask. */
#define CTE_PADPROXENX8_bp  8  /* Pad Proximity Enable X bit 8 position. */
#define CTE_PADPROXENX9_bm  (1<<9)  /* Pad Proximity Enable X bit 9 mask. */
#define CTE_PADPROXENX9_bp  9  /* Pad Proximity Enable X bit 9 position. */
#define CTE_PADPROXENX10_bm  (1<<10)  /* Pad Proximity Enable X bit 10 mask. */
#define CTE_PADPROXENX10_bp  10  /* Pad Proximity Enable X bit 10 position. */
#define CTE_PADPROXENX11_bm  (1<<11)  /* Pad Proximity Enable X bit 11 mask. */
#define CTE_PADPROXENX11_bp  11  /* Pad Proximity Enable X bit 11 position. */
#define CTE_PADPROXENX12_bm  (1<<12)  /* Pad Proximity Enable X bit 12 mask. */
#define CTE_PADPROXENX12_bp  12  /* Pad Proximity Enable X bit 12 position. */
#define CTE_PADPROXENX13_bm  (1<<13)  /* Pad Proximity Enable X bit 13 mask. */
#define CTE_PADPROXENX13_bp  13  /* Pad Proximity Enable X bit 13 position. */
#define CTE_PADPROXENX14_bm  (1<<14)  /* Pad Proximity Enable X bit 14 mask. */
#define CTE_PADPROXENX14_bp  14  /* Pad Proximity Enable X bit 14 position. */
#define CTE_PADPROXENX15_bm  (1<<15)  /* Pad Proximity Enable X bit 15 mask. */
#define CTE_PADPROXENX15_bp  15  /* Pad Proximity Enable X bit 15 position. */

/* CTE.PADPROXENXB  bit masks and bit positions */
/* CTE_PADPROXENX  is already defined. */

/* CTE.PADPROXENYA  bit masks and bit positions */
#define CTE_PADPROXENY_gm  0xFFFF  /* Pad Proximity Enable Y group mask. */
#define CTE_PADPROXENY_gp  0  /* Pad Proximity Enable Y group position. */
#define CTE_PADPROXENY0_bm  (1<<0)  /* Pad Proximity Enable Y bit 0 mask. */
#define CTE_PADPROXENY0_bp  0  /* Pad Proximity Enable Y bit 0 position. */
#define CTE_PADPROXENY1_bm  (1<<1)  /* Pad Proximity Enable Y bit 1 mask. */
#define CTE_PADPROXENY1_bp  1  /* Pad Proximity Enable Y bit 1 position. */
#define CTE_PADPROXENY2_bm  (1<<2)  /* Pad Proximity Enable Y bit 2 mask. */
#define CTE_PADPROXENY2_bp  2  /* Pad Proximity Enable Y bit 2 position. */
#define CTE_PADPROXENY3_bm  (1<<3)  /* Pad Proximity Enable Y bit 3 mask. */
#define CTE_PADPROXENY3_bp  3  /* Pad Proximity Enable Y bit 3 position. */
#define CTE_PADPROXENY4_bm  (1<<4)  /* Pad Proximity Enable Y bit 4 mask. */
#define CTE_PADPROXENY4_bp  4  /* Pad Proximity Enable Y bit 4 position. */
#define CTE_PADPROXENY5_bm  (1<<5)  /* Pad Proximity Enable Y bit 5 mask. */
#define CTE_PADPROXENY5_bp  5  /* Pad Proximity Enable Y bit 5 position. */
#define CTE_PADPROXENY6_bm  (1<<6)  /* Pad Proximity Enable Y bit 6 mask. */
#define CTE_PADPROXENY6_bp  6  /* Pad Proximity Enable Y bit 6 position. */
#define CTE_PADPROXENY7_bm  (1<<7)  /* Pad Proximity Enable Y bit 7 mask. */
#define CTE_PADPROXENY7_bp  7  /* Pad Proximity Enable Y bit 7 position. */
#define CTE_PADPROXENY8_bm  (1<<8)  /* Pad Proximity Enable Y bit 8 mask. */
#define CTE_PADPROXENY8_bp  8  /* Pad Proximity Enable Y bit 8 position. */
#define CTE_PADPROXENY9_bm  (1<<9)  /* Pad Proximity Enable Y bit 9 mask. */
#define CTE_PADPROXENY9_bp  9  /* Pad Proximity Enable Y bit 9 position. */
#define CTE_PADPROXENY10_bm  (1<<10)  /* Pad Proximity Enable Y bit 10 mask. */
#define CTE_PADPROXENY10_bp  10  /* Pad Proximity Enable Y bit 10 position. */
#define CTE_PADPROXENY11_bm  (1<<11)  /* Pad Proximity Enable Y bit 11 mask. */
#define CTE_PADPROXENY11_bp  11  /* Pad Proximity Enable Y bit 11 position. */
#define CTE_PADPROXENY12_bm  (1<<12)  /* Pad Proximity Enable Y bit 12 mask. */
#define CTE_PADPROXENY12_bp  12  /* Pad Proximity Enable Y bit 12 position. */
#define CTE_PADPROXENY13_bm  (1<<13)  /* Pad Proximity Enable Y bit 13 mask. */
#define CTE_PADPROXENY13_bp  13  /* Pad Proximity Enable Y bit 13 position. */
#define CTE_PADPROXENY14_bm  (1<<14)  /* Pad Proximity Enable Y bit 14 mask. */
#define CTE_PADPROXENY14_bp  14  /* Pad Proximity Enable Y bit 14 position. */
#define CTE_PADPROXENY15_bm  (1<<15)  /* Pad Proximity Enable Y bit 15 mask. */
#define CTE_PADPROXENY15_bp  15  /* Pad Proximity Enable Y bit 15 position. */

/* CTE.PADPROXENYB  bit masks and bit positions */
/* CTE_PADPROXENY  is already defined. */

/* CTE.PADXRSTA  bit masks and bit positions */
#define CTE_PADXRST_gm  0xFFFF  /* Pad X Reset group mask. */
#define CTE_PADXRST_gp  0  /* Pad X Reset group position. */
#define CTE_PADXRST0_bm  (1<<0)  /* Pad X Reset bit 0 mask. */
#define CTE_PADXRST0_bp  0  /* Pad X Reset bit 0 position. */
#define CTE_PADXRST1_bm  (1<<1)  /* Pad X Reset bit 1 mask. */
#define CTE_PADXRST1_bp  1  /* Pad X Reset bit 1 position. */
#define CTE_PADXRST2_bm  (1<<2)  /* Pad X Reset bit 2 mask. */
#define CTE_PADXRST2_bp  2  /* Pad X Reset bit 2 position. */
#define CTE_PADXRST3_bm  (1<<3)  /* Pad X Reset bit 3 mask. */
#define CTE_PADXRST3_bp  3  /* Pad X Reset bit 3 position. */
#define CTE_PADXRST4_bm  (1<<4)  /* Pad X Reset bit 4 mask. */
#define CTE_PADXRST4_bp  4  /* Pad X Reset bit 4 position. */
#define CTE_PADXRST5_bm  (1<<5)  /* Pad X Reset bit 5 mask. */
#define CTE_PADXRST5_bp  5  /* Pad X Reset bit 5 position. */
#define CTE_PADXRST6_bm  (1<<6)  /* Pad X Reset bit 6 mask. */
#define CTE_PADXRST6_bp  6  /* Pad X Reset bit 6 position. */
#define CTE_PADXRST7_bm  (1<<7)  /* Pad X Reset bit 7 mask. */
#define CTE_PADXRST7_bp  7  /* Pad X Reset bit 7 position. */
#define CTE_PADXRST8_bm  (1<<8)  /* Pad X Reset bit 8 mask. */
#define CTE_PADXRST8_bp  8  /* Pad X Reset bit 8 position. */
#define CTE_PADXRST9_bm  (1<<9)  /* Pad X Reset bit 9 mask. */
#define CTE_PADXRST9_bp  9  /* Pad X Reset bit 9 position. */
#define CTE_PADXRST10_bm  (1<<10)  /* Pad X Reset bit 10 mask. */
#define CTE_PADXRST10_bp  10  /* Pad X Reset bit 10 position. */
#define CTE_PADXRST11_bm  (1<<11)  /* Pad X Reset bit 11 mask. */
#define CTE_PADXRST11_bp  11  /* Pad X Reset bit 11 position. */
#define CTE_PADXRST12_bm  (1<<12)  /* Pad X Reset bit 12 mask. */
#define CTE_PADXRST12_bp  12  /* Pad X Reset bit 12 position. */
#define CTE_PADXRST13_bm  (1<<13)  /* Pad X Reset bit 13 mask. */
#define CTE_PADXRST13_bp  13  /* Pad X Reset bit 13 position. */
#define CTE_PADXRST14_bm  (1<<14)  /* Pad X Reset bit 14 mask. */
#define CTE_PADXRST14_bp  14  /* Pad X Reset bit 14 position. */
#define CTE_PADXRST15_bm  (1<<15)  /* Pad X Reset bit 15 mask. */
#define CTE_PADXRST15_bp  15  /* Pad X Reset bit 15 position. */

/* CTE.PADXRSTB  bit masks and bit positions */
/* CTE_PADXRST  is already defined. */

/* CTE.PADXRESENA  bit masks and bit positions */
#define CTE_PADXRESEN_gm  0xFFFF  /* Pad xres Enable group mask. */
#define CTE_PADXRESEN_gp  0  /* Pad xres Enable group position. */
#define CTE_PADXRESEN0_bm  (1<<0)  /* Pad xres Enable bit 0 mask. */
#define CTE_PADXRESEN0_bp  0  /* Pad xres Enable bit 0 position. */
#define CTE_PADXRESEN1_bm  (1<<1)  /* Pad xres Enable bit 1 mask. */
#define CTE_PADXRESEN1_bp  1  /* Pad xres Enable bit 1 position. */
#define CTE_PADXRESEN2_bm  (1<<2)  /* Pad xres Enable bit 2 mask. */
#define CTE_PADXRESEN2_bp  2  /* Pad xres Enable bit 2 position. */
#define CTE_PADXRESEN3_bm  (1<<3)  /* Pad xres Enable bit 3 mask. */
#define CTE_PADXRESEN3_bp  3  /* Pad xres Enable bit 3 position. */
#define CTE_PADXRESEN4_bm  (1<<4)  /* Pad xres Enable bit 4 mask. */
#define CTE_PADXRESEN4_bp  4  /* Pad xres Enable bit 4 position. */
#define CTE_PADXRESEN5_bm  (1<<5)  /* Pad xres Enable bit 5 mask. */
#define CTE_PADXRESEN5_bp  5  /* Pad xres Enable bit 5 position. */
#define CTE_PADXRESEN6_bm  (1<<6)  /* Pad xres Enable bit 6 mask. */
#define CTE_PADXRESEN6_bp  6  /* Pad xres Enable bit 6 position. */
#define CTE_PADXRESEN7_bm  (1<<7)  /* Pad xres Enable bit 7 mask. */
#define CTE_PADXRESEN7_bp  7  /* Pad xres Enable bit 7 position. */
#define CTE_PADXRESEN8_bm  (1<<8)  /* Pad xres Enable bit 8 mask. */
#define CTE_PADXRESEN8_bp  8  /* Pad xres Enable bit 8 position. */
#define CTE_PADXRESEN9_bm  (1<<9)  /* Pad xres Enable bit 9 mask. */
#define CTE_PADXRESEN9_bp  9  /* Pad xres Enable bit 9 position. */
#define CTE_PADXRESEN10_bm  (1<<10)  /* Pad xres Enable bit 10 mask. */
#define CTE_PADXRESEN10_bp  10  /* Pad xres Enable bit 10 position. */
#define CTE_PADXRESEN11_bm  (1<<11)  /* Pad xres Enable bit 11 mask. */
#define CTE_PADXRESEN11_bp  11  /* Pad xres Enable bit 11 position. */
#define CTE_PADXRESEN12_bm  (1<<12)  /* Pad xres Enable bit 12 mask. */
#define CTE_PADXRESEN12_bp  12  /* Pad xres Enable bit 12 position. */
#define CTE_PADXRESEN13_bm  (1<<13)  /* Pad xres Enable bit 13 mask. */
#define CTE_PADXRESEN13_bp  13  /* Pad xres Enable bit 13 position. */
#define CTE_PADXRESEN14_bm  (1<<14)  /* Pad xres Enable bit 14 mask. */
#define CTE_PADXRESEN14_bp  14  /* Pad xres Enable bit 14 position. */
#define CTE_PADXRESEN15_bm  (1<<15)  /* Pad xres Enable bit 15 mask. */
#define CTE_PADXRESEN15_bp  15  /* Pad xres Enable bit 15 position. */

/* CTE.PADXRESENB  bit masks and bit positions */
/* CTE_PADXRESEN  is already defined. */

/* CTE.PADYRESENA  bit masks and bit positions */
#define CTE_PADYRESEN_gm  0xFFFF  /* Pad yres Enable group mask. */
#define CTE_PADYRESEN_gp  0  /* Pad yres Enable group position. */
#define CTE_PADYRESEN0_bm  (1<<0)  /* Pad yres Enable bit 0 mask. */
#define CTE_PADYRESEN0_bp  0  /* Pad yres Enable bit 0 position. */
#define CTE_PADYRESEN1_bm  (1<<1)  /* Pad yres Enable bit 1 mask. */
#define CTE_PADYRESEN1_bp  1  /* Pad yres Enable bit 1 position. */
#define CTE_PADYRESEN2_bm  (1<<2)  /* Pad yres Enable bit 2 mask. */
#define CTE_PADYRESEN2_bp  2  /* Pad yres Enable bit 2 position. */
#define CTE_PADYRESEN3_bm  (1<<3)  /* Pad yres Enable bit 3 mask. */
#define CTE_PADYRESEN3_bp  3  /* Pad yres Enable bit 3 position. */
#define CTE_PADYRESEN4_bm  (1<<4)  /* Pad yres Enable bit 4 mask. */
#define CTE_PADYRESEN4_bp  4  /* Pad yres Enable bit 4 position. */
#define CTE_PADYRESEN5_bm  (1<<5)  /* Pad yres Enable bit 5 mask. */
#define CTE_PADYRESEN5_bp  5  /* Pad yres Enable bit 5 position. */
#define CTE_PADYRESEN6_bm  (1<<6)  /* Pad yres Enable bit 6 mask. */
#define CTE_PADYRESEN6_bp  6  /* Pad yres Enable bit 6 position. */
#define CTE_PADYRESEN7_bm  (1<<7)  /* Pad yres Enable bit 7 mask. */
#define CTE_PADYRESEN7_bp  7  /* Pad yres Enable bit 7 position. */
#define CTE_PADYRESEN8_bm  (1<<8)  /* Pad yres Enable bit 8 mask. */
#define CTE_PADYRESEN8_bp  8  /* Pad yres Enable bit 8 position. */
#define CTE_PADYRESEN9_bm  (1<<9)  /* Pad yres Enable bit 9 mask. */
#define CTE_PADYRESEN9_bp  9  /* Pad yres Enable bit 9 position. */
#define CTE_PADYRESEN10_bm  (1<<10)  /* Pad yres Enable bit 10 mask. */
#define CTE_PADYRESEN10_bp  10  /* Pad yres Enable bit 10 position. */
#define CTE_PADYRESEN11_bm  (1<<11)  /* Pad yres Enable bit 11 mask. */
#define CTE_PADYRESEN11_bp  11  /* Pad yres Enable bit 11 position. */
#define CTE_PADYRESEN12_bm  (1<<12)  /* Pad yres Enable bit 12 mask. */
#define CTE_PADYRESEN12_bp  12  /* Pad yres Enable bit 12 position. */
#define CTE_PADYRESEN13_bm  (1<<13)  /* Pad yres Enable bit 13 mask. */
#define CTE_PADYRESEN13_bp  13  /* Pad yres Enable bit 13 position. */
#define CTE_PADYRESEN14_bm  (1<<14)  /* Pad yres Enable bit 14 mask. */
#define CTE_PADYRESEN14_bp  14  /* Pad yres Enable bit 14 position. */
#define CTE_PADYRESEN15_bm  (1<<15)  /* Pad yres Enable bit 15 mask. */
#define CTE_PADYRESEN15_bp  15  /* Pad yres Enable bit 15 position. */

/* CTE.PADYRESENB  bit masks and bit positions */
/* CTE_PADYRESEN  is already defined. */

/* CTE.PADSCICALENA  bit masks and bit positions */
#define CTE_PADSCICALEN_gm  0xFFFF  /* Pad sc ical Enable group mask. */
#define CTE_PADSCICALEN_gp  0  /* Pad sc ical Enable group position. */
#define CTE_PADSCICALEN0_bm  (1<<0)  /* Pad sc ical Enable bit 0 mask. */
#define CTE_PADSCICALEN0_bp  0  /* Pad sc ical Enable bit 0 position. */
#define CTE_PADSCICALEN1_bm  (1<<1)  /* Pad sc ical Enable bit 1 mask. */
#define CTE_PADSCICALEN1_bp  1  /* Pad sc ical Enable bit 1 position. */
#define CTE_PADSCICALEN2_bm  (1<<2)  /* Pad sc ical Enable bit 2 mask. */
#define CTE_PADSCICALEN2_bp  2  /* Pad sc ical Enable bit 2 position. */
#define CTE_PADSCICALEN3_bm  (1<<3)  /* Pad sc ical Enable bit 3 mask. */
#define CTE_PADSCICALEN3_bp  3  /* Pad sc ical Enable bit 3 position. */
#define CTE_PADSCICALEN4_bm  (1<<4)  /* Pad sc ical Enable bit 4 mask. */
#define CTE_PADSCICALEN4_bp  4  /* Pad sc ical Enable bit 4 position. */
#define CTE_PADSCICALEN5_bm  (1<<5)  /* Pad sc ical Enable bit 5 mask. */
#define CTE_PADSCICALEN5_bp  5  /* Pad sc ical Enable bit 5 position. */
#define CTE_PADSCICALEN6_bm  (1<<6)  /* Pad sc ical Enable bit 6 mask. */
#define CTE_PADSCICALEN6_bp  6  /* Pad sc ical Enable bit 6 position. */
#define CTE_PADSCICALEN7_bm  (1<<7)  /* Pad sc ical Enable bit 7 mask. */
#define CTE_PADSCICALEN7_bp  7  /* Pad sc ical Enable bit 7 position. */
#define CTE_PADSCICALEN8_bm  (1<<8)  /* Pad sc ical Enable bit 8 mask. */
#define CTE_PADSCICALEN8_bp  8  /* Pad sc ical Enable bit 8 position. */
#define CTE_PADSCICALEN9_bm  (1<<9)  /* Pad sc ical Enable bit 9 mask. */
#define CTE_PADSCICALEN9_bp  9  /* Pad sc ical Enable bit 9 position. */
#define CTE_PADSCICALEN10_bm  (1<<10)  /* Pad sc ical Enable bit 10 mask. */
#define CTE_PADSCICALEN10_bp  10  /* Pad sc ical Enable bit 10 position. */
#define CTE_PADSCICALEN11_bm  (1<<11)  /* Pad sc ical Enable bit 11 mask. */
#define CTE_PADSCICALEN11_bp  11  /* Pad sc ical Enable bit 11 position. */
#define CTE_PADSCICALEN12_bm  (1<<12)  /* Pad sc ical Enable bit 12 mask. */
#define CTE_PADSCICALEN12_bp  12  /* Pad sc ical Enable bit 12 position. */
#define CTE_PADSCICALEN13_bm  (1<<13)  /* Pad sc ical Enable bit 13 mask. */
#define CTE_PADSCICALEN13_bp  13  /* Pad sc ical Enable bit 13 position. */
#define CTE_PADSCICALEN14_bm  (1<<14)  /* Pad sc ical Enable bit 14 mask. */
#define CTE_PADSCICALEN14_bp  14  /* Pad sc ical Enable bit 14 position. */
#define CTE_PADSCICALEN15_bm  (1<<15)  /* Pad sc ical Enable bit 15 mask. */
#define CTE_PADSCICALEN15_bp  15  /* Pad sc ical Enable bit 15 position. */

/* CTE.PADSCICALENB  bit masks and bit positions */
/* CTE_PADSCICALEN  is already defined. */

/* CTE.PADINTENA  bit masks and bit positions */
#define CTE_PADINTEN_gm  0xFFFF  /* Pad int Enable group mask. */
#define CTE_PADINTEN_gp  0  /* Pad int Enable group position. */
#define CTE_PADINTEN0_bm  (1<<0)  /* Pad int Enable bit 0 mask. */
#define CTE_PADINTEN0_bp  0  /* Pad int Enable bit 0 position. */
#define CTE_PADINTEN1_bm  (1<<1)  /* Pad int Enable bit 1 mask. */
#define CTE_PADINTEN1_bp  1  /* Pad int Enable bit 1 position. */
#define CTE_PADINTEN2_bm  (1<<2)  /* Pad int Enable bit 2 mask. */
#define CTE_PADINTEN2_bp  2  /* Pad int Enable bit 2 position. */
#define CTE_PADINTEN3_bm  (1<<3)  /* Pad int Enable bit 3 mask. */
#define CTE_PADINTEN3_bp  3  /* Pad int Enable bit 3 position. */
#define CTE_PADINTEN4_bm  (1<<4)  /* Pad int Enable bit 4 mask. */
#define CTE_PADINTEN4_bp  4  /* Pad int Enable bit 4 position. */
#define CTE_PADINTEN5_bm  (1<<5)  /* Pad int Enable bit 5 mask. */
#define CTE_PADINTEN5_bp  5  /* Pad int Enable bit 5 position. */
#define CTE_PADINTEN6_bm  (1<<6)  /* Pad int Enable bit 6 mask. */
#define CTE_PADINTEN6_bp  6  /* Pad int Enable bit 6 position. */
#define CTE_PADINTEN7_bm  (1<<7)  /* Pad int Enable bit 7 mask. */
#define CTE_PADINTEN7_bp  7  /* Pad int Enable bit 7 position. */
#define CTE_PADINTEN8_bm  (1<<8)  /* Pad int Enable bit 8 mask. */
#define CTE_PADINTEN8_bp  8  /* Pad int Enable bit 8 position. */
#define CTE_PADINTEN9_bm  (1<<9)  /* Pad int Enable bit 9 mask. */
#define CTE_PADINTEN9_bp  9  /* Pad int Enable bit 9 position. */
#define CTE_PADINTEN10_bm  (1<<10)  /* Pad int Enable bit 10 mask. */
#define CTE_PADINTEN10_bp  10  /* Pad int Enable bit 10 position. */
#define CTE_PADINTEN11_bm  (1<<11)  /* Pad int Enable bit 11 mask. */
#define CTE_PADINTEN11_bp  11  /* Pad int Enable bit 11 position. */
#define CTE_PADINTEN12_bm  (1<<12)  /* Pad int Enable bit 12 mask. */
#define CTE_PADINTEN12_bp  12  /* Pad int Enable bit 12 position. */
#define CTE_PADINTEN13_bm  (1<<13)  /* Pad int Enable bit 13 mask. */
#define CTE_PADINTEN13_bp  13  /* Pad int Enable bit 13 position. */
#define CTE_PADINTEN14_bm  (1<<14)  /* Pad int Enable bit 14 mask. */
#define CTE_PADINTEN14_bp  14  /* Pad int Enable bit 14 position. */
#define CTE_PADINTEN15_bm  (1<<15)  /* Pad int Enable bit 15 mask. */
#define CTE_PADINTEN15_bp  15  /* Pad int Enable bit 15 position. */

/* CTE.PADINTENB  bit masks and bit positions */
/* CTE_PADINTEN  is already defined. */

/* CTE.PADSCX0  bit masks and bit positions */
#define CTE_PADSCXA_gm  0x1F  /* Pad Self Cap Control Registers X A group mask. */
#define CTE_PADSCXA_gp  0  /* Pad Self Cap Control Registers X A group position. */
#define CTE_PADSCXA0_bm  (1<<0)  /* Pad Self Cap Control Registers X A bit 0 mask. */
#define CTE_PADSCXA0_bp  0  /* Pad Self Cap Control Registers X A bit 0 position. */
#define CTE_PADSCXA1_bm  (1<<1)  /* Pad Self Cap Control Registers X A bit 1 mask. */
#define CTE_PADSCXA1_bp  1  /* Pad Self Cap Control Registers X A bit 1 position. */
#define CTE_PADSCXA2_bm  (1<<2)  /* Pad Self Cap Control Registers X A bit 2 mask. */
#define CTE_PADSCXA2_bp  2  /* Pad Self Cap Control Registers X A bit 2 position. */
#define CTE_PADSCXA3_bm  (1<<3)  /* Pad Self Cap Control Registers X A bit 3 mask. */
#define CTE_PADSCXA3_bp  3  /* Pad Self Cap Control Registers X A bit 3 position. */
#define CTE_PADSCXA4_bm  (1<<4)  /* Pad Self Cap Control Registers X A bit 4 mask. */
#define CTE_PADSCXA4_bp  4  /* Pad Self Cap Control Registers X A bit 4 position. */
#define CTE_PADSCXB_gm  0x1F00  /* Pad Self Cap Control Registers X B group mask. */
#define CTE_PADSCXB_gp  8  /* Pad Self Cap Control Registers X B group position. */
#define CTE_PADSCXB0_bm  (1<<8)  /* Pad Self Cap Control Registers X B bit 0 mask. */
#define CTE_PADSCXB0_bp  8  /* Pad Self Cap Control Registers X B bit 0 position. */
#define CTE_PADSCXB1_bm  (1<<9)  /* Pad Self Cap Control Registers X B bit 1 mask. */
#define CTE_PADSCXB1_bp  9  /* Pad Self Cap Control Registers X B bit 1 position. */
#define CTE_PADSCXB2_bm  (1<<10)  /* Pad Self Cap Control Registers X B bit 2 mask. */
#define CTE_PADSCXB2_bp  10  /* Pad Self Cap Control Registers X B bit 2 position. */
#define CTE_PADSCXB3_bm  (1<<11)  /* Pad Self Cap Control Registers X B bit 3 mask. */
#define CTE_PADSCXB3_bp  11  /* Pad Self Cap Control Registers X B bit 3 position. */
#define CTE_PADSCXB4_bm  (1<<12)  /* Pad Self Cap Control Registers X B bit 4 mask. */
#define CTE_PADSCXB4_bp  12  /* Pad Self Cap Control Registers X B bit 4 position. */

/* CTE.PADSCX1  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX2  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX3  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX4  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX5  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX6  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX7  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX8  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX9  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX10  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX11  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX12  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX13  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX14  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX15  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX16  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX17  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX18  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX19  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX20  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX21  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX22  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX23  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX24  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX25  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX26  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX27  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX28  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX29  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX30  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX31  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX32  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX33  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX34  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX35  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX36  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX37  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX38  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX39  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX40  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX41  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX42  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX43  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX44  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX45  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX46  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX47  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX48  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX49  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX50  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX51  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX52  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX53  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX54  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX55  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX56  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX57  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX58  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCX59  bit masks and bit positions */
/* CTE_PADSCXA  is already defined. */
/* CTE_PADSCXB  is already defined. */

/* CTE.PADSCY0  bit masks and bit positions */
#define CTE_PADSCYA_gm  0x1F  /* Pad Self Cap Control Registers Y A group mask. */
#define CTE_PADSCYA_gp  0  /* Pad Self Cap Control Registers Y A group position. */
#define CTE_PADSCYA0_bm  (1<<0)  /* Pad Self Cap Control Registers Y A bit 0 mask. */
#define CTE_PADSCYA0_bp  0  /* Pad Self Cap Control Registers Y A bit 0 position. */
#define CTE_PADSCYA1_bm  (1<<1)  /* Pad Self Cap Control Registers Y A bit 1 mask. */
#define CTE_PADSCYA1_bp  1  /* Pad Self Cap Control Registers Y A bit 1 position. */
#define CTE_PADSCYA2_bm  (1<<2)  /* Pad Self Cap Control Registers Y A bit 2 mask. */
#define CTE_PADSCYA2_bp  2  /* Pad Self Cap Control Registers Y A bit 2 position. */
#define CTE_PADSCYA3_bm  (1<<3)  /* Pad Self Cap Control Registers Y A bit 3 mask. */
#define CTE_PADSCYA3_bp  3  /* Pad Self Cap Control Registers Y A bit 3 position. */
#define CTE_PADSCYA4_bm  (1<<4)  /* Pad Self Cap Control Registers Y A bit 4 mask. */
#define CTE_PADSCYA4_bp  4  /* Pad Self Cap Control Registers Y A bit 4 position. */
#define CTE_PADSCYB_gm  0x1F00  /* Pad Self Cap Control Registers Y B group mask. */
#define CTE_PADSCYB_gp  8  /* Pad Self Cap Control Registers Y B group position. */
#define CTE_PADSCYB0_bm  (1<<8)  /* Pad Self Cap Control Registers Y B bit 0 mask. */
#define CTE_PADSCYB0_bp  8  /* Pad Self Cap Control Registers Y B bit 0 position. */
#define CTE_PADSCYB1_bm  (1<<9)  /* Pad Self Cap Control Registers Y B bit 1 mask. */
#define CTE_PADSCYB1_bp  9  /* Pad Self Cap Control Registers Y B bit 1 position. */
#define CTE_PADSCYB2_bm  (1<<10)  /* Pad Self Cap Control Registers Y B bit 2 mask. */
#define CTE_PADSCYB2_bp  10  /* Pad Self Cap Control Registers Y B bit 2 position. */
#define CTE_PADSCYB3_bm  (1<<11)  /* Pad Self Cap Control Registers Y B bit 3 mask. */
#define CTE_PADSCYB3_bp  11  /* Pad Self Cap Control Registers Y B bit 3 position. */
#define CTE_PADSCYB4_bm  (1<<12)  /* Pad Self Cap Control Registers Y B bit 4 mask. */
#define CTE_PADSCYB4_bp  12  /* Pad Self Cap Control Registers Y B bit 4 position. */

/* CTE.PADSCY1  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY2  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY3  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY4  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY5  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY6  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY7  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY8  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY9  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY10  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY11  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY12  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY13  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY14  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY15  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY16  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY17  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY18  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY19  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY20  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY21  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY22  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY23  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY24  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY25  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY26  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY27  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY28  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY29  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY30  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY31  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY32  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY33  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY34  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADSCY35  bit masks and bit positions */
/* CTE_PADSCYA  is already defined. */
/* CTE_PADSCYB  is already defined. */

/* CTE.PADHVSWENA  bit masks and bit positions */
#define CTE_PADHVSWEN_gm  0xFFFF  /* Pad hvsw Enable group mask. */
#define CTE_PADHVSWEN_gp  0  /* Pad hvsw Enable group position. */
#define CTE_PADHVSWEN0_bm  (1<<0)  /* Pad hvsw Enable bit 0 mask. */
#define CTE_PADHVSWEN0_bp  0  /* Pad hvsw Enable bit 0 position. */
#define CTE_PADHVSWEN1_bm  (1<<1)  /* Pad hvsw Enable bit 1 mask. */
#define CTE_PADHVSWEN1_bp  1  /* Pad hvsw Enable bit 1 position. */
#define CTE_PADHVSWEN2_bm  (1<<2)  /* Pad hvsw Enable bit 2 mask. */
#define CTE_PADHVSWEN2_bp  2  /* Pad hvsw Enable bit 2 position. */
#define CTE_PADHVSWEN3_bm  (1<<3)  /* Pad hvsw Enable bit 3 mask. */
#define CTE_PADHVSWEN3_bp  3  /* Pad hvsw Enable bit 3 position. */
#define CTE_PADHVSWEN4_bm  (1<<4)  /* Pad hvsw Enable bit 4 mask. */
#define CTE_PADHVSWEN4_bp  4  /* Pad hvsw Enable bit 4 position. */
#define CTE_PADHVSWEN5_bm  (1<<5)  /* Pad hvsw Enable bit 5 mask. */
#define CTE_PADHVSWEN5_bp  5  /* Pad hvsw Enable bit 5 position. */
#define CTE_PADHVSWEN6_bm  (1<<6)  /* Pad hvsw Enable bit 6 mask. */
#define CTE_PADHVSWEN6_bp  6  /* Pad hvsw Enable bit 6 position. */
#define CTE_PADHVSWEN7_bm  (1<<7)  /* Pad hvsw Enable bit 7 mask. */
#define CTE_PADHVSWEN7_bp  7  /* Pad hvsw Enable bit 7 position. */
#define CTE_PADHVSWEN8_bm  (1<<8)  /* Pad hvsw Enable bit 8 mask. */
#define CTE_PADHVSWEN8_bp  8  /* Pad hvsw Enable bit 8 position. */
#define CTE_PADHVSWEN9_bm  (1<<9)  /* Pad hvsw Enable bit 9 mask. */
#define CTE_PADHVSWEN9_bp  9  /* Pad hvsw Enable bit 9 position. */
#define CTE_PADHVSWEN10_bm  (1<<10)  /* Pad hvsw Enable bit 10 mask. */
#define CTE_PADHVSWEN10_bp  10  /* Pad hvsw Enable bit 10 position. */
#define CTE_PADHVSWEN11_bm  (1<<11)  /* Pad hvsw Enable bit 11 mask. */
#define CTE_PADHVSWEN11_bp  11  /* Pad hvsw Enable bit 11 position. */
#define CTE_PADHVSWEN12_bm  (1<<12)  /* Pad hvsw Enable bit 12 mask. */
#define CTE_PADHVSWEN12_bp  12  /* Pad hvsw Enable bit 12 position. */
#define CTE_PADHVSWEN13_bm  (1<<13)  /* Pad hvsw Enable bit 13 mask. */
#define CTE_PADHVSWEN13_bp  13  /* Pad hvsw Enable bit 13 position. */
#define CTE_PADHVSWEN14_bm  (1<<14)  /* Pad hvsw Enable bit 14 mask. */
#define CTE_PADHVSWEN14_bp  14  /* Pad hvsw Enable bit 14 position. */
#define CTE_PADHVSWEN15_bm  (1<<15)  /* Pad hvsw Enable bit 15 mask. */
#define CTE_PADHVSWEN15_bp  15  /* Pad hvsw Enable bit 15 position. */

/* CTE.PADHVSWENB  bit masks and bit positions */
/* CTE_PADHVSWEN  is already defined. */

/* CTE.PADBNX1  bit masks and bit positions */
#define CTE_SCBNX1A_gm  0xFF  /* Current source nmos calibration X1 A group mask. */
#define CTE_SCBNX1A_gp  0  /* Current source nmos calibration X1 A group position. */
#define CTE_SCBNX1A0_bm  (1<<0)  /* Current source nmos calibration X1 A bit 0 mask. */
#define CTE_SCBNX1A0_bp  0  /* Current source nmos calibration X1 A bit 0 position. */
#define CTE_SCBNX1A1_bm  (1<<1)  /* Current source nmos calibration X1 A bit 1 mask. */
#define CTE_SCBNX1A1_bp  1  /* Current source nmos calibration X1 A bit 1 position. */
#define CTE_SCBNX1A2_bm  (1<<2)  /* Current source nmos calibration X1 A bit 2 mask. */
#define CTE_SCBNX1A2_bp  2  /* Current source nmos calibration X1 A bit 2 position. */
#define CTE_SCBNX1A3_bm  (1<<3)  /* Current source nmos calibration X1 A bit 3 mask. */
#define CTE_SCBNX1A3_bp  3  /* Current source nmos calibration X1 A bit 3 position. */
#define CTE_SCBNX1A4_bm  (1<<4)  /* Current source nmos calibration X1 A bit 4 mask. */
#define CTE_SCBNX1A4_bp  4  /* Current source nmos calibration X1 A bit 4 position. */
#define CTE_SCBNX1A5_bm  (1<<5)  /* Current source nmos calibration X1 A bit 5 mask. */
#define CTE_SCBNX1A5_bp  5  /* Current source nmos calibration X1 A bit 5 position. */
#define CTE_SCBNX1A6_bm  (1<<6)  /* Current source nmos calibration X1 A bit 6 mask. */
#define CTE_SCBNX1A6_bp  6  /* Current source nmos calibration X1 A bit 6 position. */
#define CTE_SCBNX1A7_bm  (1<<7)  /* Current source nmos calibration X1 A bit 7 mask. */
#define CTE_SCBNX1A7_bp  7  /* Current source nmos calibration X1 A bit 7 position. */
#define CTE_SCBNX1B_gm  0xFF00  /* Current source nmos calibration X1 B group mask. */
#define CTE_SCBNX1B_gp  8  /* Current source nmos calibration X1 B group position. */
#define CTE_SCBNX1B0_bm  (1<<8)  /* Current source nmos calibration X1 B bit 0 mask. */
#define CTE_SCBNX1B0_bp  8  /* Current source nmos calibration X1 B bit 0 position. */
#define CTE_SCBNX1B1_bm  (1<<9)  /* Current source nmos calibration X1 B bit 1 mask. */
#define CTE_SCBNX1B1_bp  9  /* Current source nmos calibration X1 B bit 1 position. */
#define CTE_SCBNX1B2_bm  (1<<10)  /* Current source nmos calibration X1 B bit 2 mask. */
#define CTE_SCBNX1B2_bp  10  /* Current source nmos calibration X1 B bit 2 position. */
#define CTE_SCBNX1B3_bm  (1<<11)  /* Current source nmos calibration X1 B bit 3 mask. */
#define CTE_SCBNX1B3_bp  11  /* Current source nmos calibration X1 B bit 3 position. */
#define CTE_SCBNX1B4_bm  (1<<12)  /* Current source nmos calibration X1 B bit 4 mask. */
#define CTE_SCBNX1B4_bp  12  /* Current source nmos calibration X1 B bit 4 position. */
#define CTE_SCBNX1B5_bm  (1<<13)  /* Current source nmos calibration X1 B bit 5 mask. */
#define CTE_SCBNX1B5_bp  13  /* Current source nmos calibration X1 B bit 5 position. */
#define CTE_SCBNX1B6_bm  (1<<14)  /* Current source nmos calibration X1 B bit 6 mask. */
#define CTE_SCBNX1B6_bp  14  /* Current source nmos calibration X1 B bit 6 position. */
#define CTE_SCBNX1B7_bm  (1<<15)  /* Current source nmos calibration X1 B bit 7 mask. */
#define CTE_SCBNX1B7_bp  15  /* Current source nmos calibration X1 B bit 7 position. */

/* CTE.PADBPX1  bit masks and bit positions */
#define CTE_SCBPX1A_gm  0xFF  /* Current source pmos calibration X1 A group mask. */
#define CTE_SCBPX1A_gp  0  /* Current source pmos calibration X1 A group position. */
#define CTE_SCBPX1A0_bm  (1<<0)  /* Current source pmos calibration X1 A bit 0 mask. */
#define CTE_SCBPX1A0_bp  0  /* Current source pmos calibration X1 A bit 0 position. */
#define CTE_SCBPX1A1_bm  (1<<1)  /* Current source pmos calibration X1 A bit 1 mask. */
#define CTE_SCBPX1A1_bp  1  /* Current source pmos calibration X1 A bit 1 position. */
#define CTE_SCBPX1A2_bm  (1<<2)  /* Current source pmos calibration X1 A bit 2 mask. */
#define CTE_SCBPX1A2_bp  2  /* Current source pmos calibration X1 A bit 2 position. */
#define CTE_SCBPX1A3_bm  (1<<3)  /* Current source pmos calibration X1 A bit 3 mask. */
#define CTE_SCBPX1A3_bp  3  /* Current source pmos calibration X1 A bit 3 position. */
#define CTE_SCBPX1A4_bm  (1<<4)  /* Current source pmos calibration X1 A bit 4 mask. */
#define CTE_SCBPX1A4_bp  4  /* Current source pmos calibration X1 A bit 4 position. */
#define CTE_SCBPX1A5_bm  (1<<5)  /* Current source pmos calibration X1 A bit 5 mask. */
#define CTE_SCBPX1A5_bp  5  /* Current source pmos calibration X1 A bit 5 position. */
#define CTE_SCBPX1A6_bm  (1<<6)  /* Current source pmos calibration X1 A bit 6 mask. */
#define CTE_SCBPX1A6_bp  6  /* Current source pmos calibration X1 A bit 6 position. */
#define CTE_SCBPX1A7_bm  (1<<7)  /* Current source pmos calibration X1 A bit 7 mask. */
#define CTE_SCBPX1A7_bp  7  /* Current source pmos calibration X1 A bit 7 position. */
#define CTE_SCBPX1B_gm  0xFF00  /* Current source pmos calibration X1 B group mask. */
#define CTE_SCBPX1B_gp  8  /* Current source pmos calibration X1 B group position. */
#define CTE_SCBPX1B0_bm  (1<<8)  /* Current source pmos calibration X1 B bit 0 mask. */
#define CTE_SCBPX1B0_bp  8  /* Current source pmos calibration X1 B bit 0 position. */
#define CTE_SCBPX1B1_bm  (1<<9)  /* Current source pmos calibration X1 B bit 1 mask. */
#define CTE_SCBPX1B1_bp  9  /* Current source pmos calibration X1 B bit 1 position. */
#define CTE_SCBPX1B2_bm  (1<<10)  /* Current source pmos calibration X1 B bit 2 mask. */
#define CTE_SCBPX1B2_bp  10  /* Current source pmos calibration X1 B bit 2 position. */
#define CTE_SCBPX1B3_bm  (1<<11)  /* Current source pmos calibration X1 B bit 3 mask. */
#define CTE_SCBPX1B3_bp  11  /* Current source pmos calibration X1 B bit 3 position. */
#define CTE_SCBPX1B4_bm  (1<<12)  /* Current source pmos calibration X1 B bit 4 mask. */
#define CTE_SCBPX1B4_bp  12  /* Current source pmos calibration X1 B bit 4 position. */
#define CTE_SCBPX1B5_bm  (1<<13)  /* Current source pmos calibration X1 B bit 5 mask. */
#define CTE_SCBPX1B5_bp  13  /* Current source pmos calibration X1 B bit 5 position. */
#define CTE_SCBPX1B6_bm  (1<<14)  /* Current source pmos calibration X1 B bit 6 mask. */
#define CTE_SCBPX1B6_bp  14  /* Current source pmos calibration X1 B bit 6 position. */
#define CTE_SCBPX1B7_bm  (1<<15)  /* Current source pmos calibration X1 B bit 7 mask. */
#define CTE_SCBPX1B7_bp  15  /* Current source pmos calibration X1 B bit 7 position. */

/* CTE.PADX1  bit masks and bit positions */
#define CTE_SCEXTRAPXA_gm  0x0F  /* Enable extra pmos calibration X1 A group mask. */
#define CTE_SCEXTRAPXA_gp  0  /* Enable extra pmos calibration X1 A group position. */
#define CTE_SCEXTRAPXA0_bm  (1<<0)  /* Enable extra pmos calibration X1 A bit 0 mask. */
#define CTE_SCEXTRAPXA0_bp  0  /* Enable extra pmos calibration X1 A bit 0 position. */
#define CTE_SCEXTRAPXA1_bm  (1<<1)  /* Enable extra pmos calibration X1 A bit 1 mask. */
#define CTE_SCEXTRAPXA1_bp  1  /* Enable extra pmos calibration X1 A bit 1 position. */
#define CTE_SCEXTRAPXA2_bm  (1<<2)  /* Enable extra pmos calibration X1 A bit 2 mask. */
#define CTE_SCEXTRAPXA2_bp  2  /* Enable extra pmos calibration X1 A bit 2 position. */
#define CTE_SCEXTRAPXA3_bm  (1<<3)  /* Enable extra pmos calibration X1 A bit 3 mask. */
#define CTE_SCEXTRAPXA3_bp  3  /* Enable extra pmos calibration X1 A bit 3 position. */
#define CTE_SCEXTRAPXB_gm  0xF0  /* Enable extra pmos calibration X1 B group mask. */
#define CTE_SCEXTRAPXB_gp  4  /* Enable extra pmos calibration X1 B group position. */
#define CTE_SCEXTRAPXB0_bm  (1<<4)  /* Enable extra pmos calibration X1 B bit 0 mask. */
#define CTE_SCEXTRAPXB0_bp  4  /* Enable extra pmos calibration X1 B bit 0 position. */
#define CTE_SCEXTRAPXB1_bm  (1<<5)  /* Enable extra pmos calibration X1 B bit 1 mask. */
#define CTE_SCEXTRAPXB1_bp  5  /* Enable extra pmos calibration X1 B bit 1 position. */
#define CTE_SCEXTRAPXB2_bm  (1<<6)  /* Enable extra pmos calibration X1 B bit 2 mask. */
#define CTE_SCEXTRAPXB2_bp  6  /* Enable extra pmos calibration X1 B bit 2 position. */
#define CTE_SCEXTRAPXB3_bm  (1<<7)  /* Enable extra pmos calibration X1 B bit 3 mask. */
#define CTE_SCEXTRAPXB3_bp  7  /* Enable extra pmos calibration X1 B bit 3 position. */
#define CTE_SCEXTRANXA_gm  0xF00  /* Enable extra nmos calibration X1 A group mask. */
#define CTE_SCEXTRANXA_gp  8  /* Enable extra nmos calibration X1 A group position. */
#define CTE_SCEXTRANXA0_bm  (1<<8)  /* Enable extra nmos calibration X1 A bit 0 mask. */
#define CTE_SCEXTRANXA0_bp  8  /* Enable extra nmos calibration X1 A bit 0 position. */
#define CTE_SCEXTRANXA1_bm  (1<<9)  /* Enable extra nmos calibration X1 A bit 1 mask. */
#define CTE_SCEXTRANXA1_bp  9  /* Enable extra nmos calibration X1 A bit 1 position. */
#define CTE_SCEXTRANXA2_bm  (1<<10)  /* Enable extra nmos calibration X1 A bit 2 mask. */
#define CTE_SCEXTRANXA2_bp  10  /* Enable extra nmos calibration X1 A bit 2 position. */
#define CTE_SCEXTRANXA3_bm  (1<<11)  /* Enable extra nmos calibration X1 A bit 3 mask. */
#define CTE_SCEXTRANXA3_bp  11  /* Enable extra nmos calibration X1 A bit 3 position. */
#define CTE_SCEXTRANXB_gm  0xF000  /* Enable extra nmos calibration X1 B group mask. */
#define CTE_SCEXTRANXB_gp  12  /* Enable extra nmos calibration X1 B group position. */
#define CTE_SCEXTRANXB0_bm  (1<<12)  /* Enable extra nmos calibration X1 B bit 0 mask. */
#define CTE_SCEXTRANXB0_bp  12  /* Enable extra nmos calibration X1 B bit 0 position. */
#define CTE_SCEXTRANXB1_bm  (1<<13)  /* Enable extra nmos calibration X1 B bit 1 mask. */
#define CTE_SCEXTRANXB1_bp  13  /* Enable extra nmos calibration X1 B bit 1 position. */
#define CTE_SCEXTRANXB2_bm  (1<<14)  /* Enable extra nmos calibration X1 B bit 2 mask. */
#define CTE_SCEXTRANXB2_bp  14  /* Enable extra nmos calibration X1 B bit 2 position. */
#define CTE_SCEXTRANXB3_bm  (1<<15)  /* Enable extra nmos calibration X1 B bit 3 mask. */
#define CTE_SCEXTRANXB3_bp  15  /* Enable extra nmos calibration X1 B bit 3 position. */

/* CTE.PADBNX2  bit masks and bit positions */
#define CTE_SCBNX2A_gm  0xFF  /* Current source nmos calibration X2 A group mask. */
#define CTE_SCBNX2A_gp  0  /* Current source nmos calibration X2 A group position. */
#define CTE_SCBNX2A0_bm  (1<<0)  /* Current source nmos calibration X2 A bit 0 mask. */
#define CTE_SCBNX2A0_bp  0  /* Current source nmos calibration X2 A bit 0 position. */
#define CTE_SCBNX2A1_bm  (1<<1)  /* Current source nmos calibration X2 A bit 1 mask. */
#define CTE_SCBNX2A1_bp  1  /* Current source nmos calibration X2 A bit 1 position. */
#define CTE_SCBNX2A2_bm  (1<<2)  /* Current source nmos calibration X2 A bit 2 mask. */
#define CTE_SCBNX2A2_bp  2  /* Current source nmos calibration X2 A bit 2 position. */
#define CTE_SCBNX2A3_bm  (1<<3)  /* Current source nmos calibration X2 A bit 3 mask. */
#define CTE_SCBNX2A3_bp  3  /* Current source nmos calibration X2 A bit 3 position. */
#define CTE_SCBNX2A4_bm  (1<<4)  /* Current source nmos calibration X2 A bit 4 mask. */
#define CTE_SCBNX2A4_bp  4  /* Current source nmos calibration X2 A bit 4 position. */
#define CTE_SCBNX2A5_bm  (1<<5)  /* Current source nmos calibration X2 A bit 5 mask. */
#define CTE_SCBNX2A5_bp  5  /* Current source nmos calibration X2 A bit 5 position. */
#define CTE_SCBNX2A6_bm  (1<<6)  /* Current source nmos calibration X2 A bit 6 mask. */
#define CTE_SCBNX2A6_bp  6  /* Current source nmos calibration X2 A bit 6 position. */
#define CTE_SCBNX2A7_bm  (1<<7)  /* Current source nmos calibration X2 A bit 7 mask. */
#define CTE_SCBNX2A7_bp  7  /* Current source nmos calibration X2 A bit 7 position. */
#define CTE_SCBNX2B_gm  0xFF00  /* Current source nmos calibration X2 B group mask. */
#define CTE_SCBNX2B_gp  8  /* Current source nmos calibration X2 B group position. */
#define CTE_SCBNX2B0_bm  (1<<8)  /* Current source nmos calibration X2 B bit 0 mask. */
#define CTE_SCBNX2B0_bp  8  /* Current source nmos calibration X2 B bit 0 position. */
#define CTE_SCBNX2B1_bm  (1<<9)  /* Current source nmos calibration X2 B bit 1 mask. */
#define CTE_SCBNX2B1_bp  9  /* Current source nmos calibration X2 B bit 1 position. */
#define CTE_SCBNX2B2_bm  (1<<10)  /* Current source nmos calibration X2 B bit 2 mask. */
#define CTE_SCBNX2B2_bp  10  /* Current source nmos calibration X2 B bit 2 position. */
#define CTE_SCBNX2B3_bm  (1<<11)  /* Current source nmos calibration X2 B bit 3 mask. */
#define CTE_SCBNX2B3_bp  11  /* Current source nmos calibration X2 B bit 3 position. */
#define CTE_SCBNX2B4_bm  (1<<12)  /* Current source nmos calibration X2 B bit 4 mask. */
#define CTE_SCBNX2B4_bp  12  /* Current source nmos calibration X2 B bit 4 position. */
#define CTE_SCBNX2B5_bm  (1<<13)  /* Current source nmos calibration X2 B bit 5 mask. */
#define CTE_SCBNX2B5_bp  13  /* Current source nmos calibration X2 B bit 5 position. */
#define CTE_SCBNX2B6_bm  (1<<14)  /* Current source nmos calibration X2 B bit 6 mask. */
#define CTE_SCBNX2B6_bp  14  /* Current source nmos calibration X2 B bit 6 position. */
#define CTE_SCBNX2B7_bm  (1<<15)  /* Current source nmos calibration X2 B bit 7 mask. */
#define CTE_SCBNX2B7_bp  15  /* Current source nmos calibration X2 B bit 7 position. */

/* CTE.PADBPX2  bit masks and bit positions */
#define CTE_SCBPX2A_gm  0xFF  /* Current source pmos calibration X2 A group mask. */
#define CTE_SCBPX2A_gp  0  /* Current source pmos calibration X2 A group position. */
#define CTE_SCBPX2A0_bm  (1<<0)  /* Current source pmos calibration X2 A bit 0 mask. */
#define CTE_SCBPX2A0_bp  0  /* Current source pmos calibration X2 A bit 0 position. */
#define CTE_SCBPX2A1_bm  (1<<1)  /* Current source pmos calibration X2 A bit 1 mask. */
#define CTE_SCBPX2A1_bp  1  /* Current source pmos calibration X2 A bit 1 position. */
#define CTE_SCBPX2A2_bm  (1<<2)  /* Current source pmos calibration X2 A bit 2 mask. */
#define CTE_SCBPX2A2_bp  2  /* Current source pmos calibration X2 A bit 2 position. */
#define CTE_SCBPX2A3_bm  (1<<3)  /* Current source pmos calibration X2 A bit 3 mask. */
#define CTE_SCBPX2A3_bp  3  /* Current source pmos calibration X2 A bit 3 position. */
#define CTE_SCBPX2A4_bm  (1<<4)  /* Current source pmos calibration X2 A bit 4 mask. */
#define CTE_SCBPX2A4_bp  4  /* Current source pmos calibration X2 A bit 4 position. */
#define CTE_SCBPX2A5_bm  (1<<5)  /* Current source pmos calibration X2 A bit 5 mask. */
#define CTE_SCBPX2A5_bp  5  /* Current source pmos calibration X2 A bit 5 position. */
#define CTE_SCBPX2A6_bm  (1<<6)  /* Current source pmos calibration X2 A bit 6 mask. */
#define CTE_SCBPX2A6_bp  6  /* Current source pmos calibration X2 A bit 6 position. */
#define CTE_SCBPX2A7_bm  (1<<7)  /* Current source pmos calibration X2 A bit 7 mask. */
#define CTE_SCBPX2A7_bp  7  /* Current source pmos calibration X2 A bit 7 position. */
#define CTE_SCBPX2B_gm  0xFF00  /* Current source pmos calibration X2 B group mask. */
#define CTE_SCBPX2B_gp  8  /* Current source pmos calibration X2 B group position. */
#define CTE_SCBPX2B0_bm  (1<<8)  /* Current source pmos calibration X2 B bit 0 mask. */
#define CTE_SCBPX2B0_bp  8  /* Current source pmos calibration X2 B bit 0 position. */
#define CTE_SCBPX2B1_bm  (1<<9)  /* Current source pmos calibration X2 B bit 1 mask. */
#define CTE_SCBPX2B1_bp  9  /* Current source pmos calibration X2 B bit 1 position. */
#define CTE_SCBPX2B2_bm  (1<<10)  /* Current source pmos calibration X2 B bit 2 mask. */
#define CTE_SCBPX2B2_bp  10  /* Current source pmos calibration X2 B bit 2 position. */
#define CTE_SCBPX2B3_bm  (1<<11)  /* Current source pmos calibration X2 B bit 3 mask. */
#define CTE_SCBPX2B3_bp  11  /* Current source pmos calibration X2 B bit 3 position. */
#define CTE_SCBPX2B4_bm  (1<<12)  /* Current source pmos calibration X2 B bit 4 mask. */
#define CTE_SCBPX2B4_bp  12  /* Current source pmos calibration X2 B bit 4 position. */
#define CTE_SCBPX2B5_bm  (1<<13)  /* Current source pmos calibration X2 B bit 5 mask. */
#define CTE_SCBPX2B5_bp  13  /* Current source pmos calibration X2 B bit 5 position. */
#define CTE_SCBPX2B6_bm  (1<<14)  /* Current source pmos calibration X2 B bit 6 mask. */
#define CTE_SCBPX2B6_bp  14  /* Current source pmos calibration X2 B bit 6 position. */
#define CTE_SCBPX2B7_bm  (1<<15)  /* Current source pmos calibration X2 B bit 7 mask. */
#define CTE_SCBPX2B7_bp  15  /* Current source pmos calibration X2 B bit 7 position. */

/* CTE.PADX2  bit masks and bit positions */
/* CTE_SCEXTRAPXA  is already defined. */
/* CTE_SCEXTRAPXB  is already defined. */
/* CTE_SCEXTRANXA  is already defined. */
/* CTE_SCEXTRANXB  is already defined. */

/* CTE.PADSCTESTENA  bit masks and bit positions */
#define CTE_PADSCTESTEN_gm  0xFFFF  /* Pad Selfcap Test Enable group mask. */
#define CTE_PADSCTESTEN_gp  0  /* Pad Selfcap Test Enable group position. */
#define CTE_PADSCTESTEN0_bm  (1<<0)  /* Pad Selfcap Test Enable bit 0 mask. */
#define CTE_PADSCTESTEN0_bp  0  /* Pad Selfcap Test Enable bit 0 position. */
#define CTE_PADSCTESTEN1_bm  (1<<1)  /* Pad Selfcap Test Enable bit 1 mask. */
#define CTE_PADSCTESTEN1_bp  1  /* Pad Selfcap Test Enable bit 1 position. */
#define CTE_PADSCTESTEN2_bm  (1<<2)  /* Pad Selfcap Test Enable bit 2 mask. */
#define CTE_PADSCTESTEN2_bp  2  /* Pad Selfcap Test Enable bit 2 position. */
#define CTE_PADSCTESTEN3_bm  (1<<3)  /* Pad Selfcap Test Enable bit 3 mask. */
#define CTE_PADSCTESTEN3_bp  3  /* Pad Selfcap Test Enable bit 3 position. */
#define CTE_PADSCTESTEN4_bm  (1<<4)  /* Pad Selfcap Test Enable bit 4 mask. */
#define CTE_PADSCTESTEN4_bp  4  /* Pad Selfcap Test Enable bit 4 position. */
#define CTE_PADSCTESTEN5_bm  (1<<5)  /* Pad Selfcap Test Enable bit 5 mask. */
#define CTE_PADSCTESTEN5_bp  5  /* Pad Selfcap Test Enable bit 5 position. */
#define CTE_PADSCTESTEN6_bm  (1<<6)  /* Pad Selfcap Test Enable bit 6 mask. */
#define CTE_PADSCTESTEN6_bp  6  /* Pad Selfcap Test Enable bit 6 position. */
#define CTE_PADSCTESTEN7_bm  (1<<7)  /* Pad Selfcap Test Enable bit 7 mask. */
#define CTE_PADSCTESTEN7_bp  7  /* Pad Selfcap Test Enable bit 7 position. */
#define CTE_PADSCTESTEN8_bm  (1<<8)  /* Pad Selfcap Test Enable bit 8 mask. */
#define CTE_PADSCTESTEN8_bp  8  /* Pad Selfcap Test Enable bit 8 position. */
#define CTE_PADSCTESTEN9_bm  (1<<9)  /* Pad Selfcap Test Enable bit 9 mask. */
#define CTE_PADSCTESTEN9_bp  9  /* Pad Selfcap Test Enable bit 9 position. */
#define CTE_PADSCTESTEN10_bm  (1<<10)  /* Pad Selfcap Test Enable bit 10 mask. */
#define CTE_PADSCTESTEN10_bp  10  /* Pad Selfcap Test Enable bit 10 position. */
#define CTE_PADSCTESTEN11_bm  (1<<11)  /* Pad Selfcap Test Enable bit 11 mask. */
#define CTE_PADSCTESTEN11_bp  11  /* Pad Selfcap Test Enable bit 11 position. */
#define CTE_PADSCTESTEN12_bm  (1<<12)  /* Pad Selfcap Test Enable bit 12 mask. */
#define CTE_PADSCTESTEN12_bp  12  /* Pad Selfcap Test Enable bit 12 position. */
#define CTE_PADSCTESTEN13_bm  (1<<13)  /* Pad Selfcap Test Enable bit 13 mask. */
#define CTE_PADSCTESTEN13_bp  13  /* Pad Selfcap Test Enable bit 13 position. */
#define CTE_PADSCTESTEN14_bm  (1<<14)  /* Pad Selfcap Test Enable bit 14 mask. */
#define CTE_PADSCTESTEN14_bp  14  /* Pad Selfcap Test Enable bit 14 position. */
#define CTE_PADSCTESTEN15_bm  (1<<15)  /* Pad Selfcap Test Enable bit 15 mask. */
#define CTE_PADSCTESTEN15_bp  15  /* Pad Selfcap Test Enable bit 15 position. */

/* CTE.PADSCTESTENB  bit masks and bit positions */
/* CTE_PADSCTESTEN  is already defined. */

/* CTE.GCAFCRA  bit masks and bit positions */
#define CTE_GCAFEN_bm  0x01  /* GCAF Enable bit mask. */
#define CTE_GCAFEN_bp  0  /* GCAF Enable bit position. */
#define CTE_GCAFMEDM_gm  0x0E  /* GCAF Median Mode. group mask. */
#define CTE_GCAFMEDM_gp  1  /* GCAF Median Mode. group position. */
#define CTE_GCAFMEDM0_bm  (1<<1)  /* GCAF Median Mode. bit 0 mask. */
#define CTE_GCAFMEDM0_bp  1  /* GCAF Median Mode. bit 0 position. */
#define CTE_GCAFMEDM1_bm  (1<<2)  /* GCAF Median Mode. bit 1 mask. */
#define CTE_GCAFMEDM1_bp  2  /* GCAF Median Mode. bit 1 position. */
#define CTE_GCAFMEDM2_bm  (1<<3)  /* GCAF Median Mode. bit 2 mask. */
#define CTE_GCAFMEDM2_bp  3  /* GCAF Median Mode. bit 2 position. */
#define CTE_GCAFMCMEN_bm  0x10  /* GCAF Multi-cut Master Enable. bit mask. */
#define CTE_GCAFMCMEN_bp  4  /* GCAF Multi-cut Master Enable. bit position. */
#define CTE_GCAFPCEN_bm  0x20  /* GCAF Pre-cut Enable. bit mask. */
#define CTE_GCAFPCEN_bp  5  /* GCAF Pre-cut Enable. bit position. */
#define CTE_GCAFACCM_gm  0xC0  /* GCAF Accumulator Mode. group mask. */
#define CTE_GCAFACCM_gp  6  /* GCAF Accumulator Mode. group position. */
#define CTE_GCAFACCM0_bm  (1<<6)  /* GCAF Accumulator Mode. bit 0 mask. */
#define CTE_GCAFACCM0_bp  6  /* GCAF Accumulator Mode. bit 0 position. */
#define CTE_GCAFACCM1_bm  (1<<7)  /* GCAF Accumulator Mode. bit 1 mask. */
#define CTE_GCAFACCM1_bp  7  /* GCAF Accumulator Mode. bit 1 position. */
#define CTE_GCAFCNTM_gm  0x300  /* GCAF Count Mode. group mask. */
#define CTE_GCAFCNTM_gp  8  /* GCAF Count Mode. group position. */
#define CTE_GCAFCNTM0_bm  (1<<8)  /* GCAF Count Mode. bit 0 mask. */
#define CTE_GCAFCNTM0_bp  8  /* GCAF Count Mode. bit 0 position. */
#define CTE_GCAFCNTM1_bm  (1<<9)  /* GCAF Count Mode. bit 1 mask. */
#define CTE_GCAFCNTM1_bp  9  /* GCAF Count Mode. bit 1 position. */
#define CTE_GCAFACI_bm  0x400  /* GCAF Accumulator and Counter Initialization. bit mask. */
#define CTE_GCAFACI_bp  10  /* GCAF Accumulator and Counter Initialization. bit position. */
#define CTE_GCAFCUTS_bm  0x800  /* GCAF Sample Cut Store. bit mask. */
#define CTE_GCAFCUTS_bp  11  /* GCAF Sample Cut Store. bit position. */
#define CTE_GCAFGCM_gm  0x7000  /* GCAF Grass Cut Mode. group mask. */
#define CTE_GCAFGCM_gp  12  /* GCAF Grass Cut Mode. group position. */
#define CTE_GCAFGCM0_bm  (1<<12)  /* GCAF Grass Cut Mode. bit 0 mask. */
#define CTE_GCAFGCM0_bp  12  /* GCAF Grass Cut Mode. bit 0 position. */
#define CTE_GCAFGCM1_bm  (1<<13)  /* GCAF Grass Cut Mode. bit 1 mask. */
#define CTE_GCAFGCM1_bp  13  /* GCAF Grass Cut Mode. bit 1 position. */
#define CTE_GCAFGCM2_bm  (1<<14)  /* GCAF Grass Cut Mode. bit 2 mask. */
#define CTE_GCAFGCM2_bp  14  /* GCAF Grass Cut Mode. bit 2 position. */

/* CTE.GCAFCRB  bit masks and bit positions */
#define CTE_GCAFYDIM_gm  0x1F  /* GCAF Y-Dimension group mask. */
#define CTE_GCAFYDIM_gp  0  /* GCAF Y-Dimension group position. */
#define CTE_GCAFYDIM0_bm  (1<<0)  /* GCAF Y-Dimension bit 0 mask. */
#define CTE_GCAFYDIM0_bp  0  /* GCAF Y-Dimension bit 0 position. */
#define CTE_GCAFYDIM1_bm  (1<<1)  /* GCAF Y-Dimension bit 1 mask. */
#define CTE_GCAFYDIM1_bp  1  /* GCAF Y-Dimension bit 1 position. */
#define CTE_GCAFYDIM2_bm  (1<<2)  /* GCAF Y-Dimension bit 2 mask. */
#define CTE_GCAFYDIM2_bp  2  /* GCAF Y-Dimension bit 2 position. */
#define CTE_GCAFYDIM3_bm  (1<<3)  /* GCAF Y-Dimension bit 3 mask. */
#define CTE_GCAFYDIM3_bp  3  /* GCAF Y-Dimension bit 3 position. */
#define CTE_GCAFYDIM4_bm  (1<<4)  /* GCAF Y-Dimension bit 4 mask. */
#define CTE_GCAFYDIM4_bp  4  /* GCAF Y-Dimension bit 4 position. */
#define CTE_GCAFAM_gm  0xE0  /* GCAF Addressing Mode group mask. */
#define CTE_GCAFAM_gp  5  /* GCAF Addressing Mode group position. */
#define CTE_GCAFAM0_bm  (1<<5)  /* GCAF Addressing Mode bit 0 mask. */
#define CTE_GCAFAM0_bp  5  /* GCAF Addressing Mode bit 0 position. */
#define CTE_GCAFAM1_bm  (1<<6)  /* GCAF Addressing Mode bit 1 mask. */
#define CTE_GCAFAM1_bp  6  /* GCAF Addressing Mode bit 1 position. */
#define CTE_GCAFAM2_bm  (1<<7)  /* GCAF Addressing Mode bit 2 mask. */
#define CTE_GCAFAM2_bp  7  /* GCAF Addressing Mode bit 2 position. */
#define CTE_GCAFXDIM_gm  0x3F00  /* GCAF X-Dimension group mask. */
#define CTE_GCAFXDIM_gp  8  /* GCAF X-Dimension group position. */
#define CTE_GCAFXDIM0_bm  (1<<8)  /* GCAF X-Dimension bit 0 mask. */
#define CTE_GCAFXDIM0_bp  8  /* GCAF X-Dimension bit 0 position. */
#define CTE_GCAFXDIM1_bm  (1<<9)  /* GCAF X-Dimension bit 1 mask. */
#define CTE_GCAFXDIM1_bp  9  /* GCAF X-Dimension bit 1 position. */
#define CTE_GCAFXDIM2_bm  (1<<10)  /* GCAF X-Dimension bit 2 mask. */
#define CTE_GCAFXDIM2_bp  10  /* GCAF X-Dimension bit 2 position. */
#define CTE_GCAFXDIM3_bm  (1<<11)  /* GCAF X-Dimension bit 3 mask. */
#define CTE_GCAFXDIM3_bp  11  /* GCAF X-Dimension bit 3 position. */
#define CTE_GCAFXDIM4_bm  (1<<12)  /* GCAF X-Dimension bit 4 mask. */
#define CTE_GCAFXDIM4_bp  12  /* GCAF X-Dimension bit 4 position. */
#define CTE_GCAFXDIM5_bm  (1<<13)  /* GCAF X-Dimension bit 5 mask. */
#define CTE_GCAFXDIM5_bp  13  /* GCAF X-Dimension bit 5 position. */
#define CTE_GCAFHDM_gm  0xC000  /* GCAF Headroom Detect Mode. group mask. */
#define CTE_GCAFHDM_gp  14  /* GCAF Headroom Detect Mode. group position. */
#define CTE_GCAFHDM0_bm  (1<<14)  /* GCAF Headroom Detect Mode. bit 0 mask. */
#define CTE_GCAFHDM0_bp  14  /* GCAF Headroom Detect Mode. bit 0 position. */
#define CTE_GCAFHDM1_bm  (1<<15)  /* GCAF Headroom Detect Mode. bit 1 mask. */
#define CTE_GCAFHDM1_bp  15  /* GCAF Headroom Detect Mode. bit 1 position. */

/* CTE.GCAFMCENA  bit masks and bit positions */
#define CTE_GCAFMCEN_gm  0xFFFF  /* GCAF Multi-cut enable group mask. */
#define CTE_GCAFMCEN_gp  0  /* GCAF Multi-cut enable group position. */
#define CTE_GCAFMCEN0_bm  (1<<0)  /* GCAF Multi-cut enable bit 0 mask. */
#define CTE_GCAFMCEN0_bp  0  /* GCAF Multi-cut enable bit 0 position. */
#define CTE_GCAFMCEN1_bm  (1<<1)  /* GCAF Multi-cut enable bit 1 mask. */
#define CTE_GCAFMCEN1_bp  1  /* GCAF Multi-cut enable bit 1 position. */
#define CTE_GCAFMCEN2_bm  (1<<2)  /* GCAF Multi-cut enable bit 2 mask. */
#define CTE_GCAFMCEN2_bp  2  /* GCAF Multi-cut enable bit 2 position. */
#define CTE_GCAFMCEN3_bm  (1<<3)  /* GCAF Multi-cut enable bit 3 mask. */
#define CTE_GCAFMCEN3_bp  3  /* GCAF Multi-cut enable bit 3 position. */
#define CTE_GCAFMCEN4_bm  (1<<4)  /* GCAF Multi-cut enable bit 4 mask. */
#define CTE_GCAFMCEN4_bp  4  /* GCAF Multi-cut enable bit 4 position. */
#define CTE_GCAFMCEN5_bm  (1<<5)  /* GCAF Multi-cut enable bit 5 mask. */
#define CTE_GCAFMCEN5_bp  5  /* GCAF Multi-cut enable bit 5 position. */
#define CTE_GCAFMCEN6_bm  (1<<6)  /* GCAF Multi-cut enable bit 6 mask. */
#define CTE_GCAFMCEN6_bp  6  /* GCAF Multi-cut enable bit 6 position. */
#define CTE_GCAFMCEN7_bm  (1<<7)  /* GCAF Multi-cut enable bit 7 mask. */
#define CTE_GCAFMCEN7_bp  7  /* GCAF Multi-cut enable bit 7 position. */
#define CTE_GCAFMCEN8_bm  (1<<8)  /* GCAF Multi-cut enable bit 8 mask. */
#define CTE_GCAFMCEN8_bp  8  /* GCAF Multi-cut enable bit 8 position. */
#define CTE_GCAFMCEN9_bm  (1<<9)  /* GCAF Multi-cut enable bit 9 mask. */
#define CTE_GCAFMCEN9_bp  9  /* GCAF Multi-cut enable bit 9 position. */
#define CTE_GCAFMCEN10_bm  (1<<10)  /* GCAF Multi-cut enable bit 10 mask. */
#define CTE_GCAFMCEN10_bp  10  /* GCAF Multi-cut enable bit 10 position. */
#define CTE_GCAFMCEN11_bm  (1<<11)  /* GCAF Multi-cut enable bit 11 mask. */
#define CTE_GCAFMCEN11_bp  11  /* GCAF Multi-cut enable bit 11 position. */
#define CTE_GCAFMCEN12_bm  (1<<12)  /* GCAF Multi-cut enable bit 12 mask. */
#define CTE_GCAFMCEN12_bp  12  /* GCAF Multi-cut enable bit 12 position. */
#define CTE_GCAFMCEN13_bm  (1<<13)  /* GCAF Multi-cut enable bit 13 mask. */
#define CTE_GCAFMCEN13_bp  13  /* GCAF Multi-cut enable bit 13 position. */
#define CTE_GCAFMCEN14_bm  (1<<14)  /* GCAF Multi-cut enable bit 14 mask. */
#define CTE_GCAFMCEN14_bp  14  /* GCAF Multi-cut enable bit 14 position. */
#define CTE_GCAFMCEN15_bm  (1<<15)  /* GCAF Multi-cut enable bit 15 mask. */
#define CTE_GCAFMCEN15_bp  15  /* GCAF Multi-cut enable bit 15 position. */

/* CTE.GCAFMCENB  bit masks and bit positions */
/* CTE_GCAFMCEN  is already defined. */

/* CTE.GCAFBASELIM  bit masks and bit positions */
#define CTE_GCAFLIM_gm  0xFF  /* GCAF Delta Limit group mask. */
#define CTE_GCAFLIM_gp  0  /* GCAF Delta Limit group position. */
#define CTE_GCAFLIM0_bm  (1<<0)  /* GCAF Delta Limit bit 0 mask. */
#define CTE_GCAFLIM0_bp  0  /* GCAF Delta Limit bit 0 position. */
#define CTE_GCAFLIM1_bm  (1<<1)  /* GCAF Delta Limit bit 1 mask. */
#define CTE_GCAFLIM1_bp  1  /* GCAF Delta Limit bit 1 position. */
#define CTE_GCAFLIM2_bm  (1<<2)  /* GCAF Delta Limit bit 2 mask. */
#define CTE_GCAFLIM2_bp  2  /* GCAF Delta Limit bit 2 position. */
#define CTE_GCAFLIM3_bm  (1<<3)  /* GCAF Delta Limit bit 3 mask. */
#define CTE_GCAFLIM3_bp  3  /* GCAF Delta Limit bit 3 position. */
#define CTE_GCAFLIM4_bm  (1<<4)  /* GCAF Delta Limit bit 4 mask. */
#define CTE_GCAFLIM4_bp  4  /* GCAF Delta Limit bit 4 position. */
#define CTE_GCAFLIM5_bm  (1<<5)  /* GCAF Delta Limit bit 5 mask. */
#define CTE_GCAFLIM5_bp  5  /* GCAF Delta Limit bit 5 position. */
#define CTE_GCAFLIM6_bm  (1<<6)  /* GCAF Delta Limit bit 6 mask. */
#define CTE_GCAFLIM6_bp  6  /* GCAF Delta Limit bit 6 position. */
#define CTE_GCAFLIM7_bm  (1<<7)  /* GCAF Delta Limit bit 7 mask. */
#define CTE_GCAFLIM7_bp  7  /* GCAF Delta Limit bit 7 position. */
#define CTE_GCAFBASE_gm  0xFF00  /* GCAF Base Addess group mask. */
#define CTE_GCAFBASE_gp  8  /* GCAF Base Addess group position. */
#define CTE_GCAFBASE0_bm  (1<<8)  /* GCAF Base Addess bit 0 mask. */
#define CTE_GCAFBASE0_bp  8  /* GCAF Base Addess bit 0 position. */
#define CTE_GCAFBASE1_bm  (1<<9)  /* GCAF Base Addess bit 1 mask. */
#define CTE_GCAFBASE1_bp  9  /* GCAF Base Addess bit 1 position. */
#define CTE_GCAFBASE2_bm  (1<<10)  /* GCAF Base Addess bit 2 mask. */
#define CTE_GCAFBASE2_bp  10  /* GCAF Base Addess bit 2 position. */
#define CTE_GCAFBASE3_bm  (1<<11)  /* GCAF Base Addess bit 3 mask. */
#define CTE_GCAFBASE3_bp  11  /* GCAF Base Addess bit 3 position. */
#define CTE_GCAFBASE4_bm  (1<<12)  /* GCAF Base Addess bit 4 mask. */
#define CTE_GCAFBASE4_bp  12  /* GCAF Base Addess bit 4 position. */
#define CTE_GCAFBASE5_bm  (1<<13)  /* GCAF Base Addess bit 5 mask. */
#define CTE_GCAFBASE5_bp  13  /* GCAF Base Addess bit 5 position. */
#define CTE_GCAFBASE6_bm  (1<<14)  /* GCAF Base Addess bit 6 mask. */
#define CTE_GCAFBASE6_bp  14  /* GCAF Base Addess bit 6 position. */
#define CTE_GCAFBASE7_bm  (1<<15)  /* GCAF Base Addess bit 7 mask. */
#define CTE_GCAFBASE7_bp  15  /* GCAF Base Addess bit 7 position. */

/* CTE.GCAFPCLL  bit masks and bit positions */
#define CTE_GCAFPCLL_gm  0xFFFF  /* GCAF Pre-cut Lower Limit group mask. */
#define CTE_GCAFPCLL_gp  0  /* GCAF Pre-cut Lower Limit group position. */
#define CTE_GCAFPCLL0_bm  (1<<0)  /* GCAF Pre-cut Lower Limit bit 0 mask. */
#define CTE_GCAFPCLL0_bp  0  /* GCAF Pre-cut Lower Limit bit 0 position. */
#define CTE_GCAFPCLL1_bm  (1<<1)  /* GCAF Pre-cut Lower Limit bit 1 mask. */
#define CTE_GCAFPCLL1_bp  1  /* GCAF Pre-cut Lower Limit bit 1 position. */
#define CTE_GCAFPCLL2_bm  (1<<2)  /* GCAF Pre-cut Lower Limit bit 2 mask. */
#define CTE_GCAFPCLL2_bp  2  /* GCAF Pre-cut Lower Limit bit 2 position. */
#define CTE_GCAFPCLL3_bm  (1<<3)  /* GCAF Pre-cut Lower Limit bit 3 mask. */
#define CTE_GCAFPCLL3_bp  3  /* GCAF Pre-cut Lower Limit bit 3 position. */
#define CTE_GCAFPCLL4_bm  (1<<4)  /* GCAF Pre-cut Lower Limit bit 4 mask. */
#define CTE_GCAFPCLL4_bp  4  /* GCAF Pre-cut Lower Limit bit 4 position. */
#define CTE_GCAFPCLL5_bm  (1<<5)  /* GCAF Pre-cut Lower Limit bit 5 mask. */
#define CTE_GCAFPCLL5_bp  5  /* GCAF Pre-cut Lower Limit bit 5 position. */
#define CTE_GCAFPCLL6_bm  (1<<6)  /* GCAF Pre-cut Lower Limit bit 6 mask. */
#define CTE_GCAFPCLL6_bp  6  /* GCAF Pre-cut Lower Limit bit 6 position. */
#define CTE_GCAFPCLL7_bm  (1<<7)  /* GCAF Pre-cut Lower Limit bit 7 mask. */
#define CTE_GCAFPCLL7_bp  7  /* GCAF Pre-cut Lower Limit bit 7 position. */
#define CTE_GCAFPCLL8_bm  (1<<8)  /* GCAF Pre-cut Lower Limit bit 8 mask. */
#define CTE_GCAFPCLL8_bp  8  /* GCAF Pre-cut Lower Limit bit 8 position. */
#define CTE_GCAFPCLL9_bm  (1<<9)  /* GCAF Pre-cut Lower Limit bit 9 mask. */
#define CTE_GCAFPCLL9_bp  9  /* GCAF Pre-cut Lower Limit bit 9 position. */
#define CTE_GCAFPCLL10_bm  (1<<10)  /* GCAF Pre-cut Lower Limit bit 10 mask. */
#define CTE_GCAFPCLL10_bp  10  /* GCAF Pre-cut Lower Limit bit 10 position. */
#define CTE_GCAFPCLL11_bm  (1<<11)  /* GCAF Pre-cut Lower Limit bit 11 mask. */
#define CTE_GCAFPCLL11_bp  11  /* GCAF Pre-cut Lower Limit bit 11 position. */
#define CTE_GCAFPCLL12_bm  (1<<12)  /* GCAF Pre-cut Lower Limit bit 12 mask. */
#define CTE_GCAFPCLL12_bp  12  /* GCAF Pre-cut Lower Limit bit 12 position. */
#define CTE_GCAFPCLL13_bm  (1<<13)  /* GCAF Pre-cut Lower Limit bit 13 mask. */
#define CTE_GCAFPCLL13_bp  13  /* GCAF Pre-cut Lower Limit bit 13 position. */
#define CTE_GCAFPCLL14_bm  (1<<14)  /* GCAF Pre-cut Lower Limit bit 14 mask. */
#define CTE_GCAFPCLL14_bp  14  /* GCAF Pre-cut Lower Limit bit 14 position. */
#define CTE_GCAFPCLL15_bm  (1<<15)  /* GCAF Pre-cut Lower Limit bit 15 mask. */
#define CTE_GCAFPCLL15_bp  15  /* GCAF Pre-cut Lower Limit bit 15 position. */

/* CTE.GCAFPCUL  bit masks and bit positions */
#define CTE_GCAFPCUL_gm  0xFFFF  /* GCAF Pre-cut Upper Limit group mask. */
#define CTE_GCAFPCUL_gp  0  /* GCAF Pre-cut Upper Limit group position. */
#define CTE_GCAFPCUL0_bm  (1<<0)  /* GCAF Pre-cut Upper Limit bit 0 mask. */
#define CTE_GCAFPCUL0_bp  0  /* GCAF Pre-cut Upper Limit bit 0 position. */
#define CTE_GCAFPCUL1_bm  (1<<1)  /* GCAF Pre-cut Upper Limit bit 1 mask. */
#define CTE_GCAFPCUL1_bp  1  /* GCAF Pre-cut Upper Limit bit 1 position. */
#define CTE_GCAFPCUL2_bm  (1<<2)  /* GCAF Pre-cut Upper Limit bit 2 mask. */
#define CTE_GCAFPCUL2_bp  2  /* GCAF Pre-cut Upper Limit bit 2 position. */
#define CTE_GCAFPCUL3_bm  (1<<3)  /* GCAF Pre-cut Upper Limit bit 3 mask. */
#define CTE_GCAFPCUL3_bp  3  /* GCAF Pre-cut Upper Limit bit 3 position. */
#define CTE_GCAFPCUL4_bm  (1<<4)  /* GCAF Pre-cut Upper Limit bit 4 mask. */
#define CTE_GCAFPCUL4_bp  4  /* GCAF Pre-cut Upper Limit bit 4 position. */
#define CTE_GCAFPCUL5_bm  (1<<5)  /* GCAF Pre-cut Upper Limit bit 5 mask. */
#define CTE_GCAFPCUL5_bp  5  /* GCAF Pre-cut Upper Limit bit 5 position. */
#define CTE_GCAFPCUL6_bm  (1<<6)  /* GCAF Pre-cut Upper Limit bit 6 mask. */
#define CTE_GCAFPCUL6_bp  6  /* GCAF Pre-cut Upper Limit bit 6 position. */
#define CTE_GCAFPCUL7_bm  (1<<7)  /* GCAF Pre-cut Upper Limit bit 7 mask. */
#define CTE_GCAFPCUL7_bp  7  /* GCAF Pre-cut Upper Limit bit 7 position. */
#define CTE_GCAFPCUL8_bm  (1<<8)  /* GCAF Pre-cut Upper Limit bit 8 mask. */
#define CTE_GCAFPCUL8_bp  8  /* GCAF Pre-cut Upper Limit bit 8 position. */
#define CTE_GCAFPCUL9_bm  (1<<9)  /* GCAF Pre-cut Upper Limit bit 9 mask. */
#define CTE_GCAFPCUL9_bp  9  /* GCAF Pre-cut Upper Limit bit 9 position. */
#define CTE_GCAFPCUL10_bm  (1<<10)  /* GCAF Pre-cut Upper Limit bit 10 mask. */
#define CTE_GCAFPCUL10_bp  10  /* GCAF Pre-cut Upper Limit bit 10 position. */
#define CTE_GCAFPCUL11_bm  (1<<11)  /* GCAF Pre-cut Upper Limit bit 11 mask. */
#define CTE_GCAFPCUL11_bp  11  /* GCAF Pre-cut Upper Limit bit 11 position. */
#define CTE_GCAFPCUL12_bm  (1<<12)  /* GCAF Pre-cut Upper Limit bit 12 mask. */
#define CTE_GCAFPCUL12_bp  12  /* GCAF Pre-cut Upper Limit bit 12 position. */
#define CTE_GCAFPCUL13_bm  (1<<13)  /* GCAF Pre-cut Upper Limit bit 13 mask. */
#define CTE_GCAFPCUL13_bp  13  /* GCAF Pre-cut Upper Limit bit 13 position. */
#define CTE_GCAFPCUL14_bm  (1<<14)  /* GCAF Pre-cut Upper Limit bit 14 mask. */
#define CTE_GCAFPCUL14_bp  14  /* GCAF Pre-cut Upper Limit bit 14 position. */
#define CTE_GCAFPCUL15_bm  (1<<15)  /* GCAF Pre-cut Upper Limit bit 15 mask. */
#define CTE_GCAFPCUL15_bp  15  /* GCAF Pre-cut Upper Limit bit 15 position. */

/* CTE.GCAFWFCR  bit masks and bit positions */
#define CTE_GCAFWFEN_bm  0x01  /* GCAF Window Function Enable bit mask. */
#define CTE_GCAFWFEN_bp  0  /* GCAF Window Function Enable bit position. */
#define CTE_GCAFWFSEL_bm  0x02  /* GCAF Window Function Select bit mask. */
#define CTE_GCAFWFSEL_bp  1  /* GCAF Window Function Select bit position. */
#define CTE_GCAFWFLEN_gm  0x3C  /* GCAF Window Function Length group mask. */
#define CTE_GCAFWFLEN_gp  2  /* GCAF Window Function Length group position. */
#define CTE_GCAFWFLEN0_bm  (1<<2)  /* GCAF Window Function Length bit 0 mask. */
#define CTE_GCAFWFLEN0_bp  2  /* GCAF Window Function Length bit 0 position. */
#define CTE_GCAFWFLEN1_bm  (1<<3)  /* GCAF Window Function Length bit 1 mask. */
#define CTE_GCAFWFLEN1_bp  3  /* GCAF Window Function Length bit 1 position. */
#define CTE_GCAFWFLEN2_bm  (1<<4)  /* GCAF Window Function Length bit 2 mask. */
#define CTE_GCAFWFLEN2_bp  4  /* GCAF Window Function Length bit 2 position. */
#define CTE_GCAFWFLEN3_bm  (1<<5)  /* GCAF Window Function Length bit 3 mask. */
#define CTE_GCAFWFLEN3_bp  5  /* GCAF Window Function Length bit 3 position. */

/* CTE.GCAFADCMIN  bit masks and bit positions */
#define CTE_GCAFADCMIN_gm  0x3FF  /* GCAF Minimum ADC Result group mask. */
#define CTE_GCAFADCMIN_gp  0  /* GCAF Minimum ADC Result group position. */
#define CTE_GCAFADCMIN0_bm  (1<<0)  /* GCAF Minimum ADC Result bit 0 mask. */
#define CTE_GCAFADCMIN0_bp  0  /* GCAF Minimum ADC Result bit 0 position. */
#define CTE_GCAFADCMIN1_bm  (1<<1)  /* GCAF Minimum ADC Result bit 1 mask. */
#define CTE_GCAFADCMIN1_bp  1  /* GCAF Minimum ADC Result bit 1 position. */
#define CTE_GCAFADCMIN2_bm  (1<<2)  /* GCAF Minimum ADC Result bit 2 mask. */
#define CTE_GCAFADCMIN2_bp  2  /* GCAF Minimum ADC Result bit 2 position. */
#define CTE_GCAFADCMIN3_bm  (1<<3)  /* GCAF Minimum ADC Result bit 3 mask. */
#define CTE_GCAFADCMIN3_bp  3  /* GCAF Minimum ADC Result bit 3 position. */
#define CTE_GCAFADCMIN4_bm  (1<<4)  /* GCAF Minimum ADC Result bit 4 mask. */
#define CTE_GCAFADCMIN4_bp  4  /* GCAF Minimum ADC Result bit 4 position. */
#define CTE_GCAFADCMIN5_bm  (1<<5)  /* GCAF Minimum ADC Result bit 5 mask. */
#define CTE_GCAFADCMIN5_bp  5  /* GCAF Minimum ADC Result bit 5 position. */
#define CTE_GCAFADCMIN6_bm  (1<<6)  /* GCAF Minimum ADC Result bit 6 mask. */
#define CTE_GCAFADCMIN6_bp  6  /* GCAF Minimum ADC Result bit 6 position. */
#define CTE_GCAFADCMIN7_bm  (1<<7)  /* GCAF Minimum ADC Result bit 7 mask. */
#define CTE_GCAFADCMIN7_bp  7  /* GCAF Minimum ADC Result bit 7 position. */
#define CTE_GCAFADCMIN8_bm  (1<<8)  /* GCAF Minimum ADC Result bit 8 mask. */
#define CTE_GCAFADCMIN8_bp  8  /* GCAF Minimum ADC Result bit 8 position. */
#define CTE_GCAFADCMIN9_bm  (1<<9)  /* GCAF Minimum ADC Result bit 9 mask. */
#define CTE_GCAFADCMIN9_bp  9  /* GCAF Minimum ADC Result bit 9 position. */

/* CTE.GCAFADCMAX  bit masks and bit positions */
#define CTE_GCAFADCMAX_gm  0x3FF  /* GCAF Maximum ADC Result group mask. */
#define CTE_GCAFADCMAX_gp  0  /* GCAF Maximum ADC Result group position. */
#define CTE_GCAFADCMAX0_bm  (1<<0)  /* GCAF Maximum ADC Result bit 0 mask. */
#define CTE_GCAFADCMAX0_bp  0  /* GCAF Maximum ADC Result bit 0 position. */
#define CTE_GCAFADCMAX1_bm  (1<<1)  /* GCAF Maximum ADC Result bit 1 mask. */
#define CTE_GCAFADCMAX1_bp  1  /* GCAF Maximum ADC Result bit 1 position. */
#define CTE_GCAFADCMAX2_bm  (1<<2)  /* GCAF Maximum ADC Result bit 2 mask. */
#define CTE_GCAFADCMAX2_bp  2  /* GCAF Maximum ADC Result bit 2 position. */
#define CTE_GCAFADCMAX3_bm  (1<<3)  /* GCAF Maximum ADC Result bit 3 mask. */
#define CTE_GCAFADCMAX3_bp  3  /* GCAF Maximum ADC Result bit 3 position. */
#define CTE_GCAFADCMAX4_bm  (1<<4)  /* GCAF Maximum ADC Result bit 4 mask. */
#define CTE_GCAFADCMAX4_bp  4  /* GCAF Maximum ADC Result bit 4 position. */
#define CTE_GCAFADCMAX5_bm  (1<<5)  /* GCAF Maximum ADC Result bit 5 mask. */
#define CTE_GCAFADCMAX5_bp  5  /* GCAF Maximum ADC Result bit 5 position. */
#define CTE_GCAFADCMAX6_bm  (1<<6)  /* GCAF Maximum ADC Result bit 6 mask. */
#define CTE_GCAFADCMAX6_bp  6  /* GCAF Maximum ADC Result bit 6 position. */
#define CTE_GCAFADCMAX7_bm  (1<<7)  /* GCAF Maximum ADC Result bit 7 mask. */
#define CTE_GCAFADCMAX7_bp  7  /* GCAF Maximum ADC Result bit 7 position. */
#define CTE_GCAFADCMAX8_bm  (1<<8)  /* GCAF Maximum ADC Result bit 8 mask. */
#define CTE_GCAFADCMAX8_bp  8  /* GCAF Maximum ADC Result bit 8 position. */
#define CTE_GCAFADCMAX9_bm  (1<<9)  /* GCAF Maximum ADC Result bit 9 mask. */
#define CTE_GCAFADCMAX9_bp  9  /* GCAF Maximum ADC Result bit 9 position. */

/* CTE.PIFXENA  bit masks and bit positions */
#define CTE_PIFXEN_gm  0xFFFF  /* Port Interface X-line Enable group mask. */
#define CTE_PIFXEN_gp  0  /* Port Interface X-line Enable group position. */
#define CTE_PIFXEN0_bm  (1<<0)  /* Port Interface X-line Enable bit 0 mask. */
#define CTE_PIFXEN0_bp  0  /* Port Interface X-line Enable bit 0 position. */
#define CTE_PIFXEN1_bm  (1<<1)  /* Port Interface X-line Enable bit 1 mask. */
#define CTE_PIFXEN1_bp  1  /* Port Interface X-line Enable bit 1 position. */
#define CTE_PIFXEN2_bm  (1<<2)  /* Port Interface X-line Enable bit 2 mask. */
#define CTE_PIFXEN2_bp  2  /* Port Interface X-line Enable bit 2 position. */
#define CTE_PIFXEN3_bm  (1<<3)  /* Port Interface X-line Enable bit 3 mask. */
#define CTE_PIFXEN3_bp  3  /* Port Interface X-line Enable bit 3 position. */
#define CTE_PIFXEN4_bm  (1<<4)  /* Port Interface X-line Enable bit 4 mask. */
#define CTE_PIFXEN4_bp  4  /* Port Interface X-line Enable bit 4 position. */
#define CTE_PIFXEN5_bm  (1<<5)  /* Port Interface X-line Enable bit 5 mask. */
#define CTE_PIFXEN5_bp  5  /* Port Interface X-line Enable bit 5 position. */
#define CTE_PIFXEN6_bm  (1<<6)  /* Port Interface X-line Enable bit 6 mask. */
#define CTE_PIFXEN6_bp  6  /* Port Interface X-line Enable bit 6 position. */
#define CTE_PIFXEN7_bm  (1<<7)  /* Port Interface X-line Enable bit 7 mask. */
#define CTE_PIFXEN7_bp  7  /* Port Interface X-line Enable bit 7 position. */
#define CTE_PIFXEN8_bm  (1<<8)  /* Port Interface X-line Enable bit 8 mask. */
#define CTE_PIFXEN8_bp  8  /* Port Interface X-line Enable bit 8 position. */
#define CTE_PIFXEN9_bm  (1<<9)  /* Port Interface X-line Enable bit 9 mask. */
#define CTE_PIFXEN9_bp  9  /* Port Interface X-line Enable bit 9 position. */
#define CTE_PIFXEN10_bm  (1<<10)  /* Port Interface X-line Enable bit 10 mask. */
#define CTE_PIFXEN10_bp  10  /* Port Interface X-line Enable bit 10 position. */
#define CTE_PIFXEN11_bm  (1<<11)  /* Port Interface X-line Enable bit 11 mask. */
#define CTE_PIFXEN11_bp  11  /* Port Interface X-line Enable bit 11 position. */
#define CTE_PIFXEN12_bm  (1<<12)  /* Port Interface X-line Enable bit 12 mask. */
#define CTE_PIFXEN12_bp  12  /* Port Interface X-line Enable bit 12 position. */
#define CTE_PIFXEN13_bm  (1<<13)  /* Port Interface X-line Enable bit 13 mask. */
#define CTE_PIFXEN13_bp  13  /* Port Interface X-line Enable bit 13 position. */
#define CTE_PIFXEN14_bm  (1<<14)  /* Port Interface X-line Enable bit 14 mask. */
#define CTE_PIFXEN14_bp  14  /* Port Interface X-line Enable bit 14 position. */
#define CTE_PIFXEN15_bm  (1<<15)  /* Port Interface X-line Enable bit 15 mask. */
#define CTE_PIFXEN15_bp  15  /* Port Interface X-line Enable bit 15 position. */

/* CTE.PIFXENB  bit masks and bit positions */
/* CTE_PIFXEN  is already defined. */

/* CTE.PIFYENA  bit masks and bit positions */
#define CTE_PIFYEN_gm  0xFFFF  /* Port Interface Y-line Enable group mask. */
#define CTE_PIFYEN_gp  0  /* Port Interface Y-line Enable group position. */
#define CTE_PIFYEN0_bm  (1<<0)  /* Port Interface Y-line Enable bit 0 mask. */
#define CTE_PIFYEN0_bp  0  /* Port Interface Y-line Enable bit 0 position. */
#define CTE_PIFYEN1_bm  (1<<1)  /* Port Interface Y-line Enable bit 1 mask. */
#define CTE_PIFYEN1_bp  1  /* Port Interface Y-line Enable bit 1 position. */
#define CTE_PIFYEN2_bm  (1<<2)  /* Port Interface Y-line Enable bit 2 mask. */
#define CTE_PIFYEN2_bp  2  /* Port Interface Y-line Enable bit 2 position. */
#define CTE_PIFYEN3_bm  (1<<3)  /* Port Interface Y-line Enable bit 3 mask. */
#define CTE_PIFYEN3_bp  3  /* Port Interface Y-line Enable bit 3 position. */
#define CTE_PIFYEN4_bm  (1<<4)  /* Port Interface Y-line Enable bit 4 mask. */
#define CTE_PIFYEN4_bp  4  /* Port Interface Y-line Enable bit 4 position. */
#define CTE_PIFYEN5_bm  (1<<5)  /* Port Interface Y-line Enable bit 5 mask. */
#define CTE_PIFYEN5_bp  5  /* Port Interface Y-line Enable bit 5 position. */
#define CTE_PIFYEN6_bm  (1<<6)  /* Port Interface Y-line Enable bit 6 mask. */
#define CTE_PIFYEN6_bp  6  /* Port Interface Y-line Enable bit 6 position. */
#define CTE_PIFYEN7_bm  (1<<7)  /* Port Interface Y-line Enable bit 7 mask. */
#define CTE_PIFYEN7_bp  7  /* Port Interface Y-line Enable bit 7 position. */
#define CTE_PIFYEN8_bm  (1<<8)  /* Port Interface Y-line Enable bit 8 mask. */
#define CTE_PIFYEN8_bp  8  /* Port Interface Y-line Enable bit 8 position. */
#define CTE_PIFYEN9_bm  (1<<9)  /* Port Interface Y-line Enable bit 9 mask. */
#define CTE_PIFYEN9_bp  9  /* Port Interface Y-line Enable bit 9 position. */
#define CTE_PIFYEN10_bm  (1<<10)  /* Port Interface Y-line Enable bit 10 mask. */
#define CTE_PIFYEN10_bp  10  /* Port Interface Y-line Enable bit 10 position. */
#define CTE_PIFYEN11_bm  (1<<11)  /* Port Interface Y-line Enable bit 11 mask. */
#define CTE_PIFYEN11_bp  11  /* Port Interface Y-line Enable bit 11 position. */
#define CTE_PIFYEN12_bm  (1<<12)  /* Port Interface Y-line Enable bit 12 mask. */
#define CTE_PIFYEN12_bp  12  /* Port Interface Y-line Enable bit 12 position. */
#define CTE_PIFYEN13_bm  (1<<13)  /* Port Interface Y-line Enable bit 13 mask. */
#define CTE_PIFYEN13_bp  13  /* Port Interface Y-line Enable bit 13 position. */
#define CTE_PIFYEN14_bm  (1<<14)  /* Port Interface Y-line Enable bit 14 mask. */
#define CTE_PIFYEN14_bp  14  /* Port Interface Y-line Enable bit 14 position. */
#define CTE_PIFYEN15_bm  (1<<15)  /* Port Interface Y-line Enable bit 15 mask. */
#define CTE_PIFYEN15_bp  15  /* Port Interface Y-line Enable bit 15 position. */

/* CTE.PIFYENB  bit masks and bit positions */
/* CTE_PIFYEN  is already defined. */

/* CTE.PIFXPINA  bit masks and bit positions */
#define CTE_PIFXPIN_gm  0xFFFF  /* Port Interface X-lines PIN group mask. */
#define CTE_PIFXPIN_gp  0  /* Port Interface X-lines PIN group position. */
#define CTE_PIFXPIN0_bm  (1<<0)  /* Port Interface X-lines PIN bit 0 mask. */
#define CTE_PIFXPIN0_bp  0  /* Port Interface X-lines PIN bit 0 position. */
#define CTE_PIFXPIN1_bm  (1<<1)  /* Port Interface X-lines PIN bit 1 mask. */
#define CTE_PIFXPIN1_bp  1  /* Port Interface X-lines PIN bit 1 position. */
#define CTE_PIFXPIN2_bm  (1<<2)  /* Port Interface X-lines PIN bit 2 mask. */
#define CTE_PIFXPIN2_bp  2  /* Port Interface X-lines PIN bit 2 position. */
#define CTE_PIFXPIN3_bm  (1<<3)  /* Port Interface X-lines PIN bit 3 mask. */
#define CTE_PIFXPIN3_bp  3  /* Port Interface X-lines PIN bit 3 position. */
#define CTE_PIFXPIN4_bm  (1<<4)  /* Port Interface X-lines PIN bit 4 mask. */
#define CTE_PIFXPIN4_bp  4  /* Port Interface X-lines PIN bit 4 position. */
#define CTE_PIFXPIN5_bm  (1<<5)  /* Port Interface X-lines PIN bit 5 mask. */
#define CTE_PIFXPIN5_bp  5  /* Port Interface X-lines PIN bit 5 position. */
#define CTE_PIFXPIN6_bm  (1<<6)  /* Port Interface X-lines PIN bit 6 mask. */
#define CTE_PIFXPIN6_bp  6  /* Port Interface X-lines PIN bit 6 position. */
#define CTE_PIFXPIN7_bm  (1<<7)  /* Port Interface X-lines PIN bit 7 mask. */
#define CTE_PIFXPIN7_bp  7  /* Port Interface X-lines PIN bit 7 position. */
#define CTE_PIFXPIN8_bm  (1<<8)  /* Port Interface X-lines PIN bit 8 mask. */
#define CTE_PIFXPIN8_bp  8  /* Port Interface X-lines PIN bit 8 position. */
#define CTE_PIFXPIN9_bm  (1<<9)  /* Port Interface X-lines PIN bit 9 mask. */
#define CTE_PIFXPIN9_bp  9  /* Port Interface X-lines PIN bit 9 position. */
#define CTE_PIFXPIN10_bm  (1<<10)  /* Port Interface X-lines PIN bit 10 mask. */
#define CTE_PIFXPIN10_bp  10  /* Port Interface X-lines PIN bit 10 position. */
#define CTE_PIFXPIN11_bm  (1<<11)  /* Port Interface X-lines PIN bit 11 mask. */
#define CTE_PIFXPIN11_bp  11  /* Port Interface X-lines PIN bit 11 position. */
#define CTE_PIFXPIN12_bm  (1<<12)  /* Port Interface X-lines PIN bit 12 mask. */
#define CTE_PIFXPIN12_bp  12  /* Port Interface X-lines PIN bit 12 position. */
#define CTE_PIFXPIN13_bm  (1<<13)  /* Port Interface X-lines PIN bit 13 mask. */
#define CTE_PIFXPIN13_bp  13  /* Port Interface X-lines PIN bit 13 position. */
#define CTE_PIFXPIN14_bm  (1<<14)  /* Port Interface X-lines PIN bit 14 mask. */
#define CTE_PIFXPIN14_bp  14  /* Port Interface X-lines PIN bit 14 position. */
#define CTE_PIFXPIN15_bm  (1<<15)  /* Port Interface X-lines PIN bit 15 mask. */
#define CTE_PIFXPIN15_bp  15  /* Port Interface X-lines PIN bit 15 position. */

/* CTE.PIFXPINB  bit masks and bit positions */
/* CTE_PIFXPIN  is already defined. */

/* CTE.PIFYPINA  bit masks and bit positions */
#define CTE_PIFYPIN_gm  0xFFFF  /* Port Interface Y-lines PIN group mask. */
#define CTE_PIFYPIN_gp  0  /* Port Interface Y-lines PIN group position. */
#define CTE_PIFYPIN0_bm  (1<<0)  /* Port Interface Y-lines PIN bit 0 mask. */
#define CTE_PIFYPIN0_bp  0  /* Port Interface Y-lines PIN bit 0 position. */
#define CTE_PIFYPIN1_bm  (1<<1)  /* Port Interface Y-lines PIN bit 1 mask. */
#define CTE_PIFYPIN1_bp  1  /* Port Interface Y-lines PIN bit 1 position. */
#define CTE_PIFYPIN2_bm  (1<<2)  /* Port Interface Y-lines PIN bit 2 mask. */
#define CTE_PIFYPIN2_bp  2  /* Port Interface Y-lines PIN bit 2 position. */
#define CTE_PIFYPIN3_bm  (1<<3)  /* Port Interface Y-lines PIN bit 3 mask. */
#define CTE_PIFYPIN3_bp  3  /* Port Interface Y-lines PIN bit 3 position. */
#define CTE_PIFYPIN4_bm  (1<<4)  /* Port Interface Y-lines PIN bit 4 mask. */
#define CTE_PIFYPIN4_bp  4  /* Port Interface Y-lines PIN bit 4 position. */
#define CTE_PIFYPIN5_bm  (1<<5)  /* Port Interface Y-lines PIN bit 5 mask. */
#define CTE_PIFYPIN5_bp  5  /* Port Interface Y-lines PIN bit 5 position. */
#define CTE_PIFYPIN6_bm  (1<<6)  /* Port Interface Y-lines PIN bit 6 mask. */
#define CTE_PIFYPIN6_bp  6  /* Port Interface Y-lines PIN bit 6 position. */
#define CTE_PIFYPIN7_bm  (1<<7)  /* Port Interface Y-lines PIN bit 7 mask. */
#define CTE_PIFYPIN7_bp  7  /* Port Interface Y-lines PIN bit 7 position. */
#define CTE_PIFYPIN8_bm  (1<<8)  /* Port Interface Y-lines PIN bit 8 mask. */
#define CTE_PIFYPIN8_bp  8  /* Port Interface Y-lines PIN bit 8 position. */
#define CTE_PIFYPIN9_bm  (1<<9)  /* Port Interface Y-lines PIN bit 9 mask. */
#define CTE_PIFYPIN9_bp  9  /* Port Interface Y-lines PIN bit 9 position. */
#define CTE_PIFYPIN10_bm  (1<<10)  /* Port Interface Y-lines PIN bit 10 mask. */
#define CTE_PIFYPIN10_bp  10  /* Port Interface Y-lines PIN bit 10 position. */
#define CTE_PIFYPIN11_bm  (1<<11)  /* Port Interface Y-lines PIN bit 11 mask. */
#define CTE_PIFYPIN11_bp  11  /* Port Interface Y-lines PIN bit 11 position. */
#define CTE_PIFYPIN12_bm  (1<<12)  /* Port Interface Y-lines PIN bit 12 mask. */
#define CTE_PIFYPIN12_bp  12  /* Port Interface Y-lines PIN bit 12 position. */
#define CTE_PIFYPIN13_bm  (1<<13)  /* Port Interface Y-lines PIN bit 13 mask. */
#define CTE_PIFYPIN13_bp  13  /* Port Interface Y-lines PIN bit 13 position. */
#define CTE_PIFYPIN14_bm  (1<<14)  /* Port Interface Y-lines PIN bit 14 mask. */
#define CTE_PIFYPIN14_bp  14  /* Port Interface Y-lines PIN bit 14 position. */
#define CTE_PIFYPIN15_bm  (1<<15)  /* Port Interface Y-lines PIN bit 15 mask. */
#define CTE_PIFYPIN15_bp  15  /* Port Interface Y-lines PIN bit 15 position. */

/* CTE.PIFYPINB  bit masks and bit positions */
/* CTE_PIFYPIN  is already defined. */

/* CTE.PIFXSRLA  bit masks and bit positions */
#define CTE_PIFXSRL_gm  0xFFFF  /* Port Interface X-line Slew Rate Limit Enable group mask. */
#define CTE_PIFXSRL_gp  0  /* Port Interface X-line Slew Rate Limit Enable group position. */
#define CTE_PIFXSRL0_bm  (1<<0)  /* Port Interface X-line Slew Rate Limit Enable bit 0 mask. */
#define CTE_PIFXSRL0_bp  0  /* Port Interface X-line Slew Rate Limit Enable bit 0 position. */
#define CTE_PIFXSRL1_bm  (1<<1)  /* Port Interface X-line Slew Rate Limit Enable bit 1 mask. */
#define CTE_PIFXSRL1_bp  1  /* Port Interface X-line Slew Rate Limit Enable bit 1 position. */
#define CTE_PIFXSRL2_bm  (1<<2)  /* Port Interface X-line Slew Rate Limit Enable bit 2 mask. */
#define CTE_PIFXSRL2_bp  2  /* Port Interface X-line Slew Rate Limit Enable bit 2 position. */
#define CTE_PIFXSRL3_bm  (1<<3)  /* Port Interface X-line Slew Rate Limit Enable bit 3 mask. */
#define CTE_PIFXSRL3_bp  3  /* Port Interface X-line Slew Rate Limit Enable bit 3 position. */
#define CTE_PIFXSRL4_bm  (1<<4)  /* Port Interface X-line Slew Rate Limit Enable bit 4 mask. */
#define CTE_PIFXSRL4_bp  4  /* Port Interface X-line Slew Rate Limit Enable bit 4 position. */
#define CTE_PIFXSRL5_bm  (1<<5)  /* Port Interface X-line Slew Rate Limit Enable bit 5 mask. */
#define CTE_PIFXSRL5_bp  5  /* Port Interface X-line Slew Rate Limit Enable bit 5 position. */
#define CTE_PIFXSRL6_bm  (1<<6)  /* Port Interface X-line Slew Rate Limit Enable bit 6 mask. */
#define CTE_PIFXSRL6_bp  6  /* Port Interface X-line Slew Rate Limit Enable bit 6 position. */
#define CTE_PIFXSRL7_bm  (1<<7)  /* Port Interface X-line Slew Rate Limit Enable bit 7 mask. */
#define CTE_PIFXSRL7_bp  7  /* Port Interface X-line Slew Rate Limit Enable bit 7 position. */
#define CTE_PIFXSRL8_bm  (1<<8)  /* Port Interface X-line Slew Rate Limit Enable bit 8 mask. */
#define CTE_PIFXSRL8_bp  8  /* Port Interface X-line Slew Rate Limit Enable bit 8 position. */
#define CTE_PIFXSRL9_bm  (1<<9)  /* Port Interface X-line Slew Rate Limit Enable bit 9 mask. */
#define CTE_PIFXSRL9_bp  9  /* Port Interface X-line Slew Rate Limit Enable bit 9 position. */
#define CTE_PIFXSRL10_bm  (1<<10)  /* Port Interface X-line Slew Rate Limit Enable bit 10 mask. */
#define CTE_PIFXSRL10_bp  10  /* Port Interface X-line Slew Rate Limit Enable bit 10 position. */
#define CTE_PIFXSRL11_bm  (1<<11)  /* Port Interface X-line Slew Rate Limit Enable bit 11 mask. */
#define CTE_PIFXSRL11_bp  11  /* Port Interface X-line Slew Rate Limit Enable bit 11 position. */
#define CTE_PIFXSRL12_bm  (1<<12)  /* Port Interface X-line Slew Rate Limit Enable bit 12 mask. */
#define CTE_PIFXSRL12_bp  12  /* Port Interface X-line Slew Rate Limit Enable bit 12 position. */
#define CTE_PIFXSRL13_bm  (1<<13)  /* Port Interface X-line Slew Rate Limit Enable bit 13 mask. */
#define CTE_PIFXSRL13_bp  13  /* Port Interface X-line Slew Rate Limit Enable bit 13 position. */
#define CTE_PIFXSRL14_bm  (1<<14)  /* Port Interface X-line Slew Rate Limit Enable bit 14 mask. */
#define CTE_PIFXSRL14_bp  14  /* Port Interface X-line Slew Rate Limit Enable bit 14 position. */
#define CTE_PIFXSRL15_bm  (1<<15)  /* Port Interface X-line Slew Rate Limit Enable bit 15 mask. */
#define CTE_PIFXSRL15_bp  15  /* Port Interface X-line Slew Rate Limit Enable bit 15 position. */

/* CTE.PIFXSRLB  bit masks and bit positions */
/* CTE_PIFXSRL  is already defined. */

/* CTE.PIFYSRLA  bit masks and bit positions */
#define CTE_PIFYSRL_gm  0xFFFF  /* Port Interface Y-line Slew Rate Limit Enable group mask. */
#define CTE_PIFYSRL_gp  0  /* Port Interface Y-line Slew Rate Limit Enable group position. */
#define CTE_PIFYSRL0_bm  (1<<0)  /* Port Interface Y-line Slew Rate Limit Enable bit 0 mask. */
#define CTE_PIFYSRL0_bp  0  /* Port Interface Y-line Slew Rate Limit Enable bit 0 position. */
#define CTE_PIFYSRL1_bm  (1<<1)  /* Port Interface Y-line Slew Rate Limit Enable bit 1 mask. */
#define CTE_PIFYSRL1_bp  1  /* Port Interface Y-line Slew Rate Limit Enable bit 1 position. */
#define CTE_PIFYSRL2_bm  (1<<2)  /* Port Interface Y-line Slew Rate Limit Enable bit 2 mask. */
#define CTE_PIFYSRL2_bp  2  /* Port Interface Y-line Slew Rate Limit Enable bit 2 position. */
#define CTE_PIFYSRL3_bm  (1<<3)  /* Port Interface Y-line Slew Rate Limit Enable bit 3 mask. */
#define CTE_PIFYSRL3_bp  3  /* Port Interface Y-line Slew Rate Limit Enable bit 3 position. */
#define CTE_PIFYSRL4_bm  (1<<4)  /* Port Interface Y-line Slew Rate Limit Enable bit 4 mask. */
#define CTE_PIFYSRL4_bp  4  /* Port Interface Y-line Slew Rate Limit Enable bit 4 position. */
#define CTE_PIFYSRL5_bm  (1<<5)  /* Port Interface Y-line Slew Rate Limit Enable bit 5 mask. */
#define CTE_PIFYSRL5_bp  5  /* Port Interface Y-line Slew Rate Limit Enable bit 5 position. */
#define CTE_PIFYSRL6_bm  (1<<6)  /* Port Interface Y-line Slew Rate Limit Enable bit 6 mask. */
#define CTE_PIFYSRL6_bp  6  /* Port Interface Y-line Slew Rate Limit Enable bit 6 position. */
#define CTE_PIFYSRL7_bm  (1<<7)  /* Port Interface Y-line Slew Rate Limit Enable bit 7 mask. */
#define CTE_PIFYSRL7_bp  7  /* Port Interface Y-line Slew Rate Limit Enable bit 7 position. */
#define CTE_PIFYSRL8_bm  (1<<8)  /* Port Interface Y-line Slew Rate Limit Enable bit 8 mask. */
#define CTE_PIFYSRL8_bp  8  /* Port Interface Y-line Slew Rate Limit Enable bit 8 position. */
#define CTE_PIFYSRL9_bm  (1<<9)  /* Port Interface Y-line Slew Rate Limit Enable bit 9 mask. */
#define CTE_PIFYSRL9_bp  9  /* Port Interface Y-line Slew Rate Limit Enable bit 9 position. */
#define CTE_PIFYSRL10_bm  (1<<10)  /* Port Interface Y-line Slew Rate Limit Enable bit 10 mask. */
#define CTE_PIFYSRL10_bp  10  /* Port Interface Y-line Slew Rate Limit Enable bit 10 position. */
#define CTE_PIFYSRL11_bm  (1<<11)  /* Port Interface Y-line Slew Rate Limit Enable bit 11 mask. */
#define CTE_PIFYSRL11_bp  11  /* Port Interface Y-line Slew Rate Limit Enable bit 11 position. */
#define CTE_PIFYSRL12_bm  (1<<12)  /* Port Interface Y-line Slew Rate Limit Enable bit 12 mask. */
#define CTE_PIFYSRL12_bp  12  /* Port Interface Y-line Slew Rate Limit Enable bit 12 position. */
#define CTE_PIFYSRL13_bm  (1<<13)  /* Port Interface Y-line Slew Rate Limit Enable bit 13 mask. */
#define CTE_PIFYSRL13_bp  13  /* Port Interface Y-line Slew Rate Limit Enable bit 13 position. */
#define CTE_PIFYSRL14_bm  (1<<14)  /* Port Interface Y-line Slew Rate Limit Enable bit 14 mask. */
#define CTE_PIFYSRL14_bp  14  /* Port Interface Y-line Slew Rate Limit Enable bit 14 position. */
#define CTE_PIFYSRL15_bm  (1<<15)  /* Port Interface Y-line Slew Rate Limit Enable bit 15 mask. */
#define CTE_PIFYSRL15_bp  15  /* Port Interface Y-line Slew Rate Limit Enable bit 15 position. */

/* CTE.PIFYSRLB  bit masks and bit positions */
/* CTE_PIFYSRL  is already defined. */

/* CTE.MS0PCL  bit masks and bit positions */
#define CTE_MSPC_gm  0xFF  /* MS PC group mask. */
#define CTE_MSPC_gp  0  /* MS PC group position. */
#define CTE_MSPC0_bm  (1<<0)  /* MS PC bit 0 mask. */
#define CTE_MSPC0_bp  0  /* MS PC bit 0 position. */
#define CTE_MSPC1_bm  (1<<1)  /* MS PC bit 1 mask. */
#define CTE_MSPC1_bp  1  /* MS PC bit 1 position. */
#define CTE_MSPC2_bm  (1<<2)  /* MS PC bit 2 mask. */
#define CTE_MSPC2_bp  2  /* MS PC bit 2 position. */
#define CTE_MSPC3_bm  (1<<3)  /* MS PC bit 3 mask. */
#define CTE_MSPC3_bp  3  /* MS PC bit 3 position. */
#define CTE_MSPC4_bm  (1<<4)  /* MS PC bit 4 mask. */
#define CTE_MSPC4_bp  4  /* MS PC bit 4 position. */
#define CTE_MSPC5_bm  (1<<5)  /* MS PC bit 5 mask. */
#define CTE_MSPC5_bp  5  /* MS PC bit 5 position. */
#define CTE_MSPC6_bm  (1<<6)  /* MS PC bit 6 mask. */
#define CTE_MSPC6_bp  6  /* MS PC bit 6 position. */
#define CTE_MSPC7_bm  (1<<7)  /* MS PC bit 7 mask. */
#define CTE_MSPC7_bp  7  /* MS PC bit 7 position. */

/* CTE.MS0PCH  bit masks and bit positions */
/* CTE_MSPC  is already defined. */

/* CTE.MS0HIF  bit masks and bit positions */
#define CTE_MSRUN_bm  0x01  /* MS Run bit mask. */
#define CTE_MSRUN_bp  0  /* MS Run bit position. */
#define CTE_MSSS_bm  0x02  /* MS Single Step bit mask. */
#define CTE_MSSS_bp  1  /* MS Single Step bit position. */
#define CTE_MSIF_bm  0x04  /* MS Interrupt Flag bit mask. */
#define CTE_MSIF_bp  2  /* MS Interrupt Flag bit position. */

/* CTE.MS0IR0  bit masks and bit positions */
#define CTE_MSIR_gm  0xFF  /* MS Instruction Register group mask. */
#define CTE_MSIR_gp  0  /* MS Instruction Register group position. */
#define CTE_MSIR0_bm  (1<<0)  /* MS Instruction Register bit 0 mask. */
#define CTE_MSIR0_bp  0  /* MS Instruction Register bit 0 position. */
#define CTE_MSIR1_bm  (1<<1)  /* MS Instruction Register bit 1 mask. */
#define CTE_MSIR1_bp  1  /* MS Instruction Register bit 1 position. */
#define CTE_MSIR2_bm  (1<<2)  /* MS Instruction Register bit 2 mask. */
#define CTE_MSIR2_bp  2  /* MS Instruction Register bit 2 position. */
#define CTE_MSIR3_bm  (1<<3)  /* MS Instruction Register bit 3 mask. */
#define CTE_MSIR3_bp  3  /* MS Instruction Register bit 3 position. */
#define CTE_MSIR4_bm  (1<<4)  /* MS Instruction Register bit 4 mask. */
#define CTE_MSIR4_bp  4  /* MS Instruction Register bit 4 position. */
#define CTE_MSIR5_bm  (1<<5)  /* MS Instruction Register bit 5 mask. */
#define CTE_MSIR5_bp  5  /* MS Instruction Register bit 5 position. */
#define CTE_MSIR6_bm  (1<<6)  /* MS Instruction Register bit 6 mask. */
#define CTE_MSIR6_bp  6  /* MS Instruction Register bit 6 position. */
#define CTE_MSIR7_bm  (1<<7)  /* MS Instruction Register bit 7 mask. */
#define CTE_MSIR7_bp  7  /* MS Instruction Register bit 7 position. */

/* CTE.MS0IR1  bit masks and bit positions */
/* CTE_MSIR  is already defined. */

/* CTE.MS0IR2  bit masks and bit positions */
/* CTE_MSIR  is already defined. */

/* CTE.MS0IR3  bit masks and bit positions */
/* CTE_MSIR  is already defined. */

/* CTE.MS0IRBUFL  bit masks and bit positions */
#define CTE_MSIRBUF_gm  0xFF  /* MS Instruction Register Buffer group mask. */
#define CTE_MSIRBUF_gp  0  /* MS Instruction Register Buffer group position. */
#define CTE_MSIRBUF0_bm  (1<<0)  /* MS Instruction Register Buffer bit 0 mask. */
#define CTE_MSIRBUF0_bp  0  /* MS Instruction Register Buffer bit 0 position. */
#define CTE_MSIRBUF1_bm  (1<<1)  /* MS Instruction Register Buffer bit 1 mask. */
#define CTE_MSIRBUF1_bp  1  /* MS Instruction Register Buffer bit 1 position. */
#define CTE_MSIRBUF2_bm  (1<<2)  /* MS Instruction Register Buffer bit 2 mask. */
#define CTE_MSIRBUF2_bp  2  /* MS Instruction Register Buffer bit 2 position. */
#define CTE_MSIRBUF3_bm  (1<<3)  /* MS Instruction Register Buffer bit 3 mask. */
#define CTE_MSIRBUF3_bp  3  /* MS Instruction Register Buffer bit 3 position. */
#define CTE_MSIRBUF4_bm  (1<<4)  /* MS Instruction Register Buffer bit 4 mask. */
#define CTE_MSIRBUF4_bp  4  /* MS Instruction Register Buffer bit 4 position. */
#define CTE_MSIRBUF5_bm  (1<<5)  /* MS Instruction Register Buffer bit 5 mask. */
#define CTE_MSIRBUF5_bp  5  /* MS Instruction Register Buffer bit 5 position. */
#define CTE_MSIRBUF6_bm  (1<<6)  /* MS Instruction Register Buffer bit 6 mask. */
#define CTE_MSIRBUF6_bp  6  /* MS Instruction Register Buffer bit 6 position. */
#define CTE_MSIRBUF7_bm  (1<<7)  /* MS Instruction Register Buffer bit 7 mask. */
#define CTE_MSIRBUF7_bp  7  /* MS Instruction Register Buffer bit 7 position. */

/* CTE.MS0IRBUFH  bit masks and bit positions */
/* CTE_MSIRBUF  is already defined. */

/* CTE.MS0R0L  bit masks and bit positions */
#define CTE_MSR0_gm  0xFF  /* MS R0 in register file group mask. */
#define CTE_MSR0_gp  0  /* MS R0 in register file group position. */
#define CTE_MSR00_bm  (1<<0)  /* MS R0 in register file bit 0 mask. */
#define CTE_MSR00_bp  0  /* MS R0 in register file bit 0 position. */
#define CTE_MSR01_bm  (1<<1)  /* MS R0 in register file bit 1 mask. */
#define CTE_MSR01_bp  1  /* MS R0 in register file bit 1 position. */
#define CTE_MSR02_bm  (1<<2)  /* MS R0 in register file bit 2 mask. */
#define CTE_MSR02_bp  2  /* MS R0 in register file bit 2 position. */
#define CTE_MSR03_bm  (1<<3)  /* MS R0 in register file bit 3 mask. */
#define CTE_MSR03_bp  3  /* MS R0 in register file bit 3 position. */
#define CTE_MSR04_bm  (1<<4)  /* MS R0 in register file bit 4 mask. */
#define CTE_MSR04_bp  4  /* MS R0 in register file bit 4 position. */
#define CTE_MSR05_bm  (1<<5)  /* MS R0 in register file bit 5 mask. */
#define CTE_MSR05_bp  5  /* MS R0 in register file bit 5 position. */
#define CTE_MSR06_bm  (1<<6)  /* MS R0 in register file bit 6 mask. */
#define CTE_MSR06_bp  6  /* MS R0 in register file bit 6 position. */
#define CTE_MSR07_bm  (1<<7)  /* MS R0 in register file bit 7 mask. */
#define CTE_MSR07_bp  7  /* MS R0 in register file bit 7 position. */

/* CTE.MS0R0H  bit masks and bit positions */
/* CTE_MSR0  is already defined. */

/* CTE.MS0REPEATL  bit masks and bit positions */
#define CTE_MSREPEAT_gm  0xFF  /* MS Repeat Register group mask. */
#define CTE_MSREPEAT_gp  0  /* MS Repeat Register group position. */
#define CTE_MSREPEAT0_bm  (1<<0)  /* MS Repeat Register bit 0 mask. */
#define CTE_MSREPEAT0_bp  0  /* MS Repeat Register bit 0 position. */
#define CTE_MSREPEAT1_bm  (1<<1)  /* MS Repeat Register bit 1 mask. */
#define CTE_MSREPEAT1_bp  1  /* MS Repeat Register bit 1 position. */
#define CTE_MSREPEAT2_bm  (1<<2)  /* MS Repeat Register bit 2 mask. */
#define CTE_MSREPEAT2_bp  2  /* MS Repeat Register bit 2 position. */
#define CTE_MSREPEAT3_bm  (1<<3)  /* MS Repeat Register bit 3 mask. */
#define CTE_MSREPEAT3_bp  3  /* MS Repeat Register bit 3 position. */
#define CTE_MSREPEAT4_bm  (1<<4)  /* MS Repeat Register bit 4 mask. */
#define CTE_MSREPEAT4_bp  4  /* MS Repeat Register bit 4 position. */
#define CTE_MSREPEAT5_bm  (1<<5)  /* MS Repeat Register bit 5 mask. */
#define CTE_MSREPEAT5_bp  5  /* MS Repeat Register bit 5 position. */
#define CTE_MSREPEAT6_bm  (1<<6)  /* MS Repeat Register bit 6 mask. */
#define CTE_MSREPEAT6_bp  6  /* MS Repeat Register bit 6 position. */
#define CTE_MSREPEAT7_bm  (1<<7)  /* MS Repeat Register bit 7 mask. */
#define CTE_MSREPEAT7_bp  7  /* MS Repeat Register bit 7 position. */

/* CTE.MS0REPEATH  bit masks and bit positions */
/* CTE_MSREPEAT  is already defined. */

/* CTE.MS1PCL  bit masks and bit positions */
/* CTE_MSPC  is already defined. */

/* CTE.MS1PCH  bit masks and bit positions */
/* CTE_MSPC  is already defined. */

/* CTE.MS1HIF  bit masks and bit positions */
/* CTE_MSRUN  is already defined. */
/* CTE_MSSS  is already defined. */
/* CTE_MSIF  is already defined. */

/* CTE.MS1IR0  bit masks and bit positions */
/* CTE_MSIR  is already defined. */

/* CTE.MS1IR1  bit masks and bit positions */
/* CTE_MSIR  is already defined. */

/* CTE.MS1IR2  bit masks and bit positions */
/* CTE_MSIR  is already defined. */

/* CTE.MS1IR3  bit masks and bit positions */
/* CTE_MSIR  is already defined. */

/* CTE.MS1IRBUFL  bit masks and bit positions */
/* CTE_MSIRBUF  is already defined. */

/* CTE.MS1IRBUFH  bit masks and bit positions */
/* CTE_MSIRBUF  is already defined. */

/* CTE.MS1R0L  bit masks and bit positions */
/* CTE_MSR0  is already defined. */

/* CTE.MS1R0H  bit masks and bit positions */
/* CTE_MSR0  is already defined. */

/* CTE.MS1REPEATL  bit masks and bit positions */
/* CTE_MSREPEAT  is already defined. */

/* CTE.MS1REPEATH  bit masks and bit positions */
/* CTE_MSREPEAT  is already defined. */

/* CTE.CTTEMP  bit masks and bit positions */
#define CTE_CTTEMP_gm  0xFF  /* CapTouch Temporary register for 16-bit group mask. */
#define CTE_CTTEMP_gp  0  /* CapTouch Temporary register for 16-bit group position. */
#define CTE_CTTEMP0_bm  (1<<0)  /* CapTouch Temporary register for 16-bit bit 0 mask. */
#define CTE_CTTEMP0_bp  0  /* CapTouch Temporary register for 16-bit bit 0 position. */
#define CTE_CTTEMP1_bm  (1<<1)  /* CapTouch Temporary register for 16-bit bit 1 mask. */
#define CTE_CTTEMP1_bp  1  /* CapTouch Temporary register for 16-bit bit 1 position. */
#define CTE_CTTEMP2_bm  (1<<2)  /* CapTouch Temporary register for 16-bit bit 2 mask. */
#define CTE_CTTEMP2_bp  2  /* CapTouch Temporary register for 16-bit bit 2 position. */
#define CTE_CTTEMP3_bm  (1<<3)  /* CapTouch Temporary register for 16-bit bit 3 mask. */
#define CTE_CTTEMP3_bp  3  /* CapTouch Temporary register for 16-bit bit 3 position. */
#define CTE_CTTEMP4_bm  (1<<4)  /* CapTouch Temporary register for 16-bit bit 4 mask. */
#define CTE_CTTEMP4_bp  4  /* CapTouch Temporary register for 16-bit bit 4 position. */
#define CTE_CTTEMP5_bm  (1<<5)  /* CapTouch Temporary register for 16-bit bit 5 mask. */
#define CTE_CTTEMP5_bp  5  /* CapTouch Temporary register for 16-bit bit 5 position. */
#define CTE_CTTEMP6_bm  (1<<6)  /* CapTouch Temporary register for 16-bit bit 6 mask. */
#define CTE_CTTEMP6_bp  6  /* CapTouch Temporary register for 16-bit bit 6 position. */
#define CTE_CTTEMP7_bm  (1<<7)  /* CapTouch Temporary register for 16-bit bit 7 mask. */
#define CTE_CTTEMP7_bp  7  /* CapTouch Temporary register for 16-bit bit 7 position. */

/* CTE.CTCRA  bit masks and bit positions */
#define CTE_CT32WE_bm  0x08  /* Enable 32-bit write bit mask. */
#define CTE_CT32WE_bp  3  /* Enable 32-bit write bit position. */

/* CTE.DMAPSCLR  bit masks and bit positions */
#define CTE_CTDMAPSA_bm  0x01  /* CPU Double Mapping Select A bit mask. */
#define CTE_CTDMAPSA_bp  0  /* CPU Double Mapping Select A bit position. */
#define CTE_CTDMAPSB_bm  0x02  /* CPU Double Mapping Select B bit mask. */
#define CTE_CTDMAPSB_bp  1  /* CPU Double Mapping Select B bit position. */

/* CTE.DMAPSSET  bit masks and bit positions */
/* CTE_CTDMAPSA  is already defined. */
/* CTE_CTDMAPSB  is already defined. */

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
#  define PROGMEM_SIZE      (139264)
#else
#  define PROGMEM_START     (0x0000U)
#  define PROGMEM_SIZE      (139264U)
#endif
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define APP_SECTION_START     (0x0000)
#  define APP_SECTION_SIZE      (131072)
#  define APP_SECTION_PAGE_SIZE (256)
#else
#  define APP_SECTION_START     (0x0000U)
#  define APP_SECTION_SIZE      (131072U)
#  define APP_SECTION_PAGE_SIZE (256U)
#endif
#define APP_SECTION_END       (APP_SECTION_START + APP_SECTION_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define APPTABLE_SECTION_START     (0x1E000)
#  define APPTABLE_SECTION_SIZE      (8192)
#  define APPTABLE_SECTION_PAGE_SIZE (256)
#else
#  define APPTABLE_SECTION_START     (0x1E000U)
#  define APPTABLE_SECTION_SIZE      (8192U)
#  define APPTABLE_SECTION_PAGE_SIZE (256U)
#endif
#define APPTABLE_SECTION_END       (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define BOOT_SECTION_START     (0x20000)
#  define BOOT_SECTION_SIZE      (8192)
#  define BOOT_SECTION_PAGE_SIZE (256)
#else
#  define BOOT_SECTION_START     (0x20000U)
#  define BOOT_SECTION_SIZE      (8192U)
#  define BOOT_SECTION_PAGE_SIZE (256U)
#endif
#define BOOT_SECTION_END       (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define DATAMEM_START     (0x0000)
#  define DATAMEM_SIZE      (53248)
#else
#  define DATAMEM_START     (0x0000U)
#  define DATAMEM_SIZE      (53248U)
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
#  define INTERNAL_SRAM_SIZE      (45056)
#  define INTERNAL_SRAM_PAGE_SIZE (0)
#else
#  define INTERNAL_SRAM_START     (0x2000U)
#  define INTERNAL_SRAM_SIZE      (45056U)
#  define INTERNAL_SRAM_PAGE_SIZE (0U)
#endif
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CPU_RAM_START     (0x2000)
#  define CPU_RAM_SIZE      (10240)
#  define CPU_RAM_PAGE_SIZE (0)
#else
#  define CPU_RAM_START     (0x2000U)
#  define CPU_RAM_SIZE      (10240U)
#  define CPU_RAM_PAGE_SIZE (0U)
#endif
#define CPU_RAM_END       (CPU_RAM_START + CPU_RAM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_I0_START     (0x5000)
#  define CTE_I0_SIZE      (4096)
#  define CTE_I0_PAGE_SIZE (0)
#else
#  define CTE_I0_START     (0x5000U)
#  define CTE_I0_SIZE      (4096U)
#  define CTE_I0_PAGE_SIZE (0U)
#endif
#define CTE_I0_END       (CTE_I0_START + CTE_I0_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_D0_START     (0x6000)
#  define CTE_D0_SIZE      (3072)
#  define CTE_D0_PAGE_SIZE (0)
#else
#  define CTE_D0_START     (0x6000U)
#  define CTE_D0_SIZE      (3072U)
#  define CTE_D0_PAGE_SIZE (0U)
#endif
#define CTE_D0_END       (CTE_D0_START + CTE_D0_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_I1_START     (0x7000)
#  define CTE_I1_SIZE      (4096)
#  define CTE_I1_PAGE_SIZE (0)
#else
#  define CTE_I1_START     (0x7000U)
#  define CTE_I1_SIZE      (4096U)
#  define CTE_I1_PAGE_SIZE (0U)
#endif
#define CTE_I1_END       (CTE_I1_START + CTE_I1_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_D1_START     (0x8000)
#  define CTE_D1_SIZE      (8192)
#  define CTE_D1_PAGE_SIZE (0)
#else
#  define CTE_D1_START     (0x8000U)
#  define CTE_D1_SIZE      (8192U)
#  define CTE_D1_PAGE_SIZE (0U)
#endif
#define CTE_D1_END       (CTE_D1_START + CTE_D1_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_D2_START     (0xA000)
#  define CTE_D2_SIZE      (4096)
#  define CTE_D2_PAGE_SIZE (0)
#else
#  define CTE_D2_START     (0xA000U)
#  define CTE_D2_SIZE      (4096U)
#  define CTE_D2_PAGE_SIZE (0U)
#endif
#define CTE_D2_END       (CTE_D2_START + CTE_D2_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define CTE_D1_DOUBLE_MAP_START     (0xB000)
#  define CTE_D1_DOUBLE_MAP_SIZE      (8192)
#  define CTE_D1_DOUBLE_MAP_PAGE_SIZE (0)
#else
#  define CTE_D1_DOUBLE_MAP_START     (0xB000U)
#  define CTE_D1_DOUBLE_MAP_SIZE      (8192U)
#  define CTE_D1_DOUBLE_MAP_PAGE_SIZE (0U)
#endif
#define CTE_D1_DOUBLE_MAP_END       (CTE_D1_DOUBLE_MAP_START + CTE_D1_DOUBLE_MAP_SIZE - 1)

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
#define SIGNATURE_1 0x97
#define SIGNATURE_2 0x59

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


#endif /* #ifdef _AVR_ATMXT540SREVA_H_INCLUDED */

