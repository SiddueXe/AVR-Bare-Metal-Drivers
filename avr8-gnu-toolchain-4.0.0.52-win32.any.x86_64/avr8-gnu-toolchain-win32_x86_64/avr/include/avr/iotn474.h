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

#ifndef _AVR_ATTINY474_H_INCLUDED
#define _AVR_ATTINY474_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn474.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define PINA    _SFR_IO8(0x00)
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0

#define DDRA    _SFR_IO8(0x01)
#define DDRA7   7
// Inserted "DDA7" from "DDRA7" due to compatibility
#define DDA7    7
#define DDRA6   6
// Inserted "DDA6" from "DDRA6" due to compatibility
#define DDA6    6
#define DDRA5   5
// Inserted "DDA5" from "DDRA5" due to compatibility
#define DDA5    5
#define DDRA4   4
// Inserted "DDA4" from "DDRA4" due to compatibility
#define DDA4    4
#define DDRA3   3
// Inserted "DDA3" from "DDRA3" due to compatibility
#define DDA3    3
#define DDRA2   2
// Inserted "DDA2" from "DDRA2" due to compatibility
#define DDA2    2
#define DDRA1   1
// Inserted "DDA1" from "DDRA1" due to compatibility
#define DDA1    1
#define DDRA0   0
// Inserted "DDA0" from "DDRA0" due to compatibility
#define DDA0    0

#define PORTA   _SFR_IO8(0x02)
#define PORTA7  7
#define PORTA6  6
#define PORTA5  5
#define PORTA4  4
#define PORTA3  3
#define PORTA2  2
#define PORTA1  1
#define PORTA0  0

#define PUEA    _SFR_IO8(0x03)
#define PUEA7   7
#define PUEA6   6
#define PUEA5   5
#define PUEA4   4
#define PUEA3   3
#define PUEA2   2
#define PUEA1   1
#define PUEA0   0

#define PINB    _SFR_IO8(0x04)
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x05)
#define DDRB3   3
// Inserted "DDB3" from "DDRB3" due to compatibility
#define DDB3    3
#define DDRB2   2
// Inserted "DDB2" from "DDRB2" due to compatibility
#define DDB2    2
#define DDRB1   1
// Inserted "DDB1" from "DDRB1" due to compatibility
#define DDB1    1
#define DDRB0   0
// Inserted "DDB0" from "DDRB0" due to compatibility
#define DDB0    0

#define PORTB   _SFR_IO8(0x06)
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define PUEB    _SFR_IO8(0x07)
#define PUEB3   3
#define PUEB2   2
#define PUEB1   1
#define PUEB0   0

/* Reserved [0x08..0x13] */

#define PHDE    _SFR_IO8(0x14)
#define PHDEA7  7
#define PHDEB0  0
#define PHDEB1  1
#define PHDEB2  2

/* Reserved [0x15] */

#define TIFR1   _SFR_IO8(0x16)
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define ICF1    5

/* Reserved [0x17..0x1B] */

#define GIFR    _SFR_IO8(0x1C)
#define PCIF0   0
#define PCIF1   1
#define INTF0   4

#define GIMSK   _SFR_IO8(0x1D)
#define PCIE0   0
#define PCIE1   1
#define INT0    4

#define GPIOR0  _SFR_IO8(0x1E)

#define EECR    _SFR_IO8(0x1F)
#define EERE    0
#define EEPE    1
#define EEMPE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5

#define EEDR    _SFR_IO8(0x20)

#define EEAR    _SFR_IO8(0x21)

/* Reserved [0x22..0x29] */

#define GPIOR1  _SFR_IO8(0x2A)

#define GPIOR2  _SFR_IO8(0x2B)

#define SPCR    _SFR_IO8(0x2C)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPSR    _SFR_IO8(0x2D)
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#define SPDR    _SFR_IO8(0x2E)

#define ACSRB   _SFR_IO8(0x2F)
#define ACPMUX0 0
#define ACPMUX1 1
#define ACNMUX0 2
#define ACNMUX1 3
#define HLEV    6
#define HSEL    7

#define ACSRA   _SFR_IO8(0x30)
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACPMUX2 6
#define ACD     7

/* Reserved [0x31] */

#define CLKPR   _SFR_IO8(0x32)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3

#define CLKCR   _SFR_IO8(0x33)
#define CKSEL0  0
#define CKSEL1  1
#define CKOUTC  5
#define CSTR    6
#define OSCRDY  7

#define PRR     _SFR_IO8(0x34)
#define PRADC   0
#define PRTIM0  1
#define PRTIM1  2
#define PRSPI   3
#define PRTWI   4

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRSPI)|(1<<PRTWI))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRTWI

/* Reserved [0x35] */

#define WDTCSR  _SFR_IO8(0x36)
#define WDE     3
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDP3    5
#define WDIE    6
#define WDIF    7

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define RFLB    3
#define CTPB    4
#define RSIG    5

/* Reserved [0x38..0x39] */

#define MCUCR   _SFR_IO8(0x3A)
#define ISC00   0
#define ISC01   1
#define SE      4
#define SM0     5
#define SM1     6
#define SM2     7

#define MCUSR   _SFR_IO8(0x3B)
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3

#define CCP     _SFR_IO8(0x3C)

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define PCMSK0  _SFR_MEM8(0x60)

#define PCMSK1  _SFR_MEM8(0x61)

/* Reserved [0x62..0x64] */

#define TIMSK1  _SFR_MEM8(0x65)
#define TOIE1   0
#define OCIE1A  1
#define OCIE1B  2
#define ICIE1   5

/* Reserved [0x66..0x69] */

#define REMAP   _SFR_MEM8(0x6A)
#define SPIMAP  1

/* Reserved [0x6B..0x77] */

#define TWSCRA  _SFR_MEM8(0x78)
#define TWSME   0
#define TWPME   1
#define TWSIE   2
#define TWEN    3
#define TWASIE  4
#define TWDIE   5
#define TWSHE   7

#define TWSCRB  _SFR_MEM8(0x79)
#define TWCMD0  0
#define TWCMD1  1
#define TWAA    2
#define TWHNM   3

#define TWSSRA  _SFR_MEM8(0x7A)
#define TWAS    0
#define TWDIR   1
#define TWBE    2
#define TWC     3
#define TWRA    4
#define TWCH    5
#define TWASIF  6
#define TWDIF   7

#define TWSAM   _SFR_MEM8(0x7B)
#define TWAE    0
#define TWSAM1  1
#define TWSAM2  2
#define TWSAM3  3
#define TWSAM4  4
#define TWSAM5  5
#define TWSAM6  6
#define TWSAM7  7

#define TWSA    _SFR_MEM8(0x7C)

#define TWSD    _SFR_MEM8(0x7D)
#define TWSD0   0
#define TWSD1   1
#define TWSD2   2
#define TWSD3   3
#define TWSD4   4
#define TWSD5   5
#define TWSD6   6
#define TWSD7   7

/* Reserved [0x7E..0x8E] */

#define GTCCR   _SFR_MEM8(0x8F)
#define PSRSYNC 0
#define TSM     7
#define PSRASY  1

#define TCCR0A  _SFR_MEM8(0x90)
#define WGM00   0
#define WGM01   1
#define COM0B0  4
#define COM0B1  5
#define COM0A0  6
#define COM0A1  7

#define TCCR0B  _SFR_MEM8(0x91)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM02   3
#define FOC0B   6
#define FOC0A   7

#define TCNT0   _SFR_MEM8(0x92)

#define OCR0A   _SFR_MEM8(0x93)

#define OCR0B   _SFR_MEM8(0x94)

#define ASSR    _SFR_MEM8(0x95)
#define TCR0BUB 0
#define TCR0AUB 1
#define OCR0BUB 2
#define OCR0AUB 3
#define TCN0UB  4
#define AS0     5

#define TIMSK0  _SFR_MEM8(0x96)
#define TOIE0   0
#define OCIE0A  1
#define OCIE0B  2

#define TIFR0   _SFR_MEM8(0x97)
#define TOV0    0
#define OCF0A   1
#define OCF0B   2

/* Reserved [0x98] */

#define OSCCAL0 _SFR_MEM8(0x99)

#define OSCTCAL0A _SFR_MEM8(0x9A)

#define OSCTCAL0B _SFR_MEM8(0x9B)

#define OSCCAL1 _SFR_MEM8(0x9C)

/* Reserved [0x9D..0x9F] */

/* Combine ADCL and ADCH */
#ifndef __ASSEMBLER__
#define ADC     _SFR_MEM16(0xA0)
#endif
#define ADCW    _SFR_MEM16(0xA0)

#define ADCL    _SFR_MEM8(0xA0)
#define ADCH    _SFR_MEM8(0xA1)

#define ADCSRA  _SFR_MEM8(0xA2)
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADCSRB  _SFR_MEM8(0xA3)
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define ADRS    3

/* Reserved [0xA4..0xAB] */

#define ADMUX   _SFR_MEM8(0xAC)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define REFS0   5
#define REFS1   6
#define REFS2   7

/* Reserved [0xAD..0xB3] */

#define DIDR0   _SFR_MEM8(0xB4)
#define ADC0D   0
#define ADC1D   1
#define ADC2D   2
#define ADC3D   3
#define ADC4D   4
#define ADC5D   5
#define ADC6D   6
#define ADC7D   7

#define DIDR1   _SFR_MEM8(0xB5)
#define ADC8D   0
#define ADC9D   1
#define ADC10D  2
#define ADC11D  3

/* Reserved [0xB6..0xBF] */

#define TCCR1A  _SFR_MEM8(0xC0)
#define WGM10   0
#define WGM11   1
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define TCCR1B  _SFR_MEM8(0xC1)
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define TCCR1C  _SFR_MEM8(0xC2)
#define FOC1B   6
#define FOC1A   7

/* Reserved [0xC3] */

/* Combine TCNT1L and TCNT1H */
#define TCNT1   _SFR_MEM16(0xC4)

#define TCNT1L  _SFR_MEM8(0xC4)
#define TCNT1H  _SFR_MEM8(0xC5)

/* Combine ICR1L and ICR1H */
#define ICR1    _SFR_MEM16(0xC6)

#define ICR1L   _SFR_MEM8(0xC6)
#define ICR1H   _SFR_MEM8(0xC7)

/* Combine OCR1AL and OCR1AH */
#define OCR1A   _SFR_MEM16(0xC8)

#define OCR1AL  _SFR_MEM8(0xC8)
#define OCR1AH  _SFR_MEM8(0xC9)

/* Combine OCR1BL and OCR1BH */
#define OCR1B   _SFR_MEM16(0xCA)

#define OCR1BL  _SFR_MEM8(0xCA)
#define OCR1BH  _SFR_MEM8(0xCB)

/* Reserved [0xCC..0xE1] */

#define TOCPMCOE _SFR_MEM8(0xE2)
#define TOCC0OE 0
#define TOCC1OE 1
#define TOCC2OE 2
#define TOCC3OE 3
#define TOCC4OE 4
#define TOCC5OE 5
#define TOCC6OE 6
#define TOCC7OE 7

/* Reserved [0xE3..0xE7] */

#define TOCPMSA0 _SFR_MEM8(0xE8)
#define TOCC0S0 0
#define TOCC0S1 1
#define TOCC1S0 2
#define TOCC1S1 3
#define TOCC2S0 4
#define TOCC2S1 5
#define TOCC3S0 6
#define TOCC3S1 7

#define TOCPMSA1 _SFR_MEM8(0xE9)
#define TOCC4S0 0
#define TOCC4S1 1
#define TOCC5S0 2
#define TOCC5S1 3
#define TOCC6S0 4
#define TOCC6S1 5
#define TOCC7S0 6
#define TOCC7S1 7



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<5)
#define SLEEP_MODE_ADC (0x01<<5)
#define SLEEP_MODE_PWR_DOWN (0x02<<5)
#define SLEEP_MODE_PWR_SAVE (0x03<<5)

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* External Interrupt Request 0 */
#define INT0_vect            _VECTOR(1)
#define INT0_vect_num        1

/* Pin Change Interrupt Request 0 */
#define PCINT0_vect            _VECTOR(2)
#define PCINT0_vect_num        2

/* Pin Change Interrupt Request 1 */
#define PCINT1_vect            _VECTOR(3)
#define PCINT1_vect_num        3

/* Watchdog Time-out Interrupt */
#define WDT_vect            _VECTOR(4)
#define WDT_vect_num        4

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(5)
#define TIMER1_CAPT_vect_num        5

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(6)
#define TIMER1_COMPA_vect_num        6

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(7)
#define TIMER1_COMPB_vect_num        7

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(8)
#define TIMER1_OVF_vect_num        8

/* Timer/Counter0 Compare Match A */
#define TIMER0_COMPA_vect            _VECTOR(9)
#define TIMER0_COMPA_vect_num        9

/* Timer/Counter0 Compare Match B */
#define TIMER0_COMPB_vect            _VECTOR(10)
#define TIMER0_COMPB_vect_num        10

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(11)
#define TIMER0_OVF_vect_num        11

/* Analog Comparator */
#define ANALOG_COMP_vect            _VECTOR(12)
#define ANALOG_COMP_vect_num        12

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(13)
#define ADC_vect_num        13

/* EEPROM Ready */
#define EE_READY_vect            _VECTOR(14)
#define EE_READY_vect_num        14

/* SPI Serial Transfer Complete */
#define SPI__STC_vect            _VECTOR(15)
#define SPI__STC_vect_num        15

/* Two-wire Serial Interface */
#define TWI_SLAVE_vect            _VECTOR(16)
#define TWI_SLAVE_vect_num        16

/* Coprocessor 0, signalize */
#define COP0_vect            _VECTOR(17)
#define COP0_vect_num        17

/* Coprocessor 1, halt */
#define COP1_vect            _VECTOR(18)
#define COP1_vect_num        18

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define _VECTORS_SIZE 38
#else
#  define _VECTORS_SIZE 38U
#endif


/* Constants */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SPM_PAGESIZE 8
#  define FLASHSTART   0x0000
#  define FLASHEND     0x0FFF
#else
#  define SPM_PAGESIZE 8U
#  define FLASHSTART   0x0000U
#  define FLASHEND     0x0FFFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define RAMSTART     0x0100
#  define RAMSIZE      256
#  define RAMEND       0x01FF
#else
#  define RAMSTART     0x0100U
#  define RAMSIZE      256U
#  define RAMEND       0x01FFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define E2START     0
#  define E2SIZE      64
#  define E2PAGESIZE  4
#  define E2END       0x003F
#else
#  define E2START     0U
#  define E2SIZE      64U
#  define E2PAGESIZE  4U
#  define E2END       0x003FU
#endif
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_SUT_CKSEL0  (unsigned char)~_BV(0)
#define FUSE_SUT_CKSEL1  (unsigned char)~_BV(1)
#define FUSE_CKOUT       (unsigned char)~_BV(6)
#define FUSE_CKDIV8      (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_SUT_CKSEL0 & FUSE_CKDIV8)


/* High Fuse Byte */
#define FUSE_RSTDISBL    (unsigned char)~_BV(0)
#define FUSE_BODLEVEL0   (unsigned char)~_BV(1)
#define FUSE_BODLEVEL1   (unsigned char)~_BV(2)
#define FUSE_BODLEVEL2   (unsigned char)~_BV(3)
#define FUSE_DWEN        (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_WDTON       (unsigned char)~_BV(6)
#define FUSE_EESAVE      (unsigned char)~_BV(7)
#define HFUSE_DEFAULT    (FUSE_SPIEN)


/* Extended Fuse Byte */
#define FUSE_SELFPRGEN   (unsigned char)~_BV(0)
#define FUSE_BODACT0     (unsigned char)~_BV(1)
#define FUSE_BODACT1     (unsigned char)~_BV(2)
#define FUSE_BODPD0      (unsigned char)~_BV(3)
#define FUSE_BODPD1      (unsigned char)~_BV(4)
#define FUSE_ULPOSCSEL0  (unsigned char)~_BV(5)
#define FUSE_ULPOSCSEL1  (unsigned char)~_BV(6)
#define FUSE_ULPOSCSEL2  (unsigned char)~_BV(7)
#define EFUSE_DEFAULT    (0xFF)



/* Lock Bits */
#define __LOCK_BITS_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x92
#define SIGNATURE_2 0x0F




#endif /* #ifdef _AVR_ATTINY474_H_INCLUDED */

