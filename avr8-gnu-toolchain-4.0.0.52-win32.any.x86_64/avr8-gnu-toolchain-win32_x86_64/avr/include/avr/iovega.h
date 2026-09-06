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

#ifndef _AVR_VEGA_H_INCLUDED
#define _AVR_VEGA_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iovega.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define SPCR    _SFR_IO8(0x0D)
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR0    0
#define SPR1    1

#define SPSR    _SFR_IO8(0x0E)
#define SPIF    7
#define WCOL    6
#define SPI2X   0

#define SPDR    _SFR_IO8(0x0F)

/* Reserved [0x10..0x1B] */

#define EECR    _SFR_IO8(0x1C)
#define EERIE   3
#define EEMWE   2
#define EEWE    1
#define EERE    0

#define EEDR    _SFR_IO8(0x1D)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x1E)

#define EEARL   _SFR_IO8(0x1E)
#define EEARH   _SFR_IO8(0x1F)

/* Reserved [0x20] */

#define WDTCR   _SFR_IO8(0x21)
#define WDCE    4
#define WDE     3
#define WDP0    0
#define WDP1    1
#define WDP2    2

/* Reserved [0x22..0x33] */

#define MCUCSR  _SFR_IO8(0x34)
#define JTD     7
#define JTRF    4
#define WDRF    3
#define BORF    2
#define EXTRF   1
#define PORF    0

#define MCUCR   _SFR_IO8(0x35)
#define SRE     7
#define SRW10   6
#define SE      5
#define SM0     3
#define SM1     4
#define SM2     2
#define IVSEL   1
#define IVCE    0

/* Reserved [0x36..0x3A] */

#define RAMPZ   _SFR_IO8(0x3B)
#define RAMPZ0  0

#define XDIV    _SFR_IO8(0x3C)
#define XDIVEN  7
#define XDIV6   6
#define XDIV5   5
#define XDIV4   4
#define XDIV3   3
#define XDIV2   2
#define XDIV1   1
#define XDIV0   0

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

/* Reserved [0x40..0x6B] */

#define XMCRB   _SFR_MEM8(0x6C)
#define XMBK    7
#define XMM0    0
#define XMM1    1
#define XMM2    2

#define XMCRA   _SFR_MEM8(0x6D)
#define SRL0    4
#define SRL1    5
#define SRL2    6
#define SRW00   2
#define SRW01   3
#define SRW11   1

/* Reserved [0x6E] */

#define OSCCAL  _SFR_MEM8(0x6F)
#define OSCCAL0 0
#define OSCCAL1 1
#define OSCCAL2 2
#define OSCCAL3 3
#define OSCCAL4 4
#define OSCCAL5 5
#define OSCCAL6 6
#define OSCCAL7 7



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<2)
#define SLEEP_MODE_ADC (0x02<<2)
#define SLEEP_MODE_PWR_DOWN (0x04<<2)
#define SLEEP_MODE_PWR_SAVE (0x06<<2)
#define SLEEP_MODE_STANDBY (0x05<<2)
#define SLEEP_MODE_EXT_STANDBY (0x07<<2)

/* Interrupt vectors */
/* Vector 0 is the reset vector */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define _VECTORS_SIZE 4
#else
#  define _VECTORS_SIZE 4U
#endif


/* Constants */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define RAMSTART     0x2000
#  define RAMSIZE      16384
#  define RAMEND       0x5FFF
#else
#  define RAMSTART     0x2000U
#  define RAMSIZE      16384U
#  define RAMEND       0x5FFFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define E2START     0
#  define E2SIZE      20480
#  define E2PAGESIZE  None
#  define E2END       0x4FFF
#else
#  define E2START     0U
#  define E2SIZE      20480U
#  define E2PAGESIZE  NoneU
#  define E2END       0x4FFFU
#endif
#define XRAMEND      RAMEND


/* Fuses */


/* Lock Bits */


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x97
#define SIGNATURE_2 0x02




#endif /* #ifdef _AVR_VEGA_H_INCLUDED */

