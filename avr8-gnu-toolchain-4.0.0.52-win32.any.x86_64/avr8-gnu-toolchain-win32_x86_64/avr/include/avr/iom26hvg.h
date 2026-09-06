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

#ifndef _AVR_ATMEGA26HVG_H_INCLUDED
#define _AVR_ATMEGA26HVG_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom26hvg.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define PINA    _SFR_IO8(0x00)
#define PINA1   1
#define PINA0   0

#define DDRA    _SFR_IO8(0x01)
#define DDRA1   1
// Inserted "DDA1" from "DDRA1" due to compatibility
#define DDA1    1
#define DDRA0   0
// Inserted "DDA0" from "DDRA0" due to compatibility
#define DDA0    0

#define PORTA   _SFR_IO8(0x02)
#define PORTA1  1
#define PORTA0  0

#define PINB    _SFR_IO8(0x03)
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x04)
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

#define PORTB   _SFR_IO8(0x05)
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define PINC    _SFR_IO8(0x06)
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define PDCTRLC _SFR_IO8(0x07)
#define WEN0    0
#define WEN1    1

#define PORTC   _SFR_IO8(0x08)
#define PORTC2  2
#define PORTC1  1
#define PORTC0  0

/* Reserved [0x09..0x14] */

#define TIFR0   _SFR_IO8(0x15)
#define TOV0    0
#define OCF0A   1
#define OCF0B   2
#define ICF0    3

/* Reserved [0x16] */

#define OSICSR  _SFR_IO8(0x17)
#define OSIEN   0
#define OSIST   1
#define OSISEL0 4

/* Reserved [0x18..0x1A] */

#define PCIFR   _SFR_IO8(0x1B)
#define PCIF0   0
#define PCIF1   1

#define EIFR    _SFR_IO8(0x1C)
#define INTF0   0
#define INTF1   1
#define INTF2   2

#define EIMSK   _SFR_IO8(0x1D)
#define INT0    0
#define INT1    1
#define INT2    2

#define GPIOR0  _SFR_IO8(0x1E)

#define EECR    _SFR_IO8(0x1F)
#define EERE    0
#define EEPE    1
#define EEMPE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5

#define EEDR    _SFR_IO8(0x20)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x21)

#define EEARL   _SFR_IO8(0x21)
#define EEARH   _SFR_IO8(0x22)

#define GTCCR   _SFR_IO8(0x23)
#define PSRSYNC 0
#define TSM     7

#define TCCR0A  _SFR_IO8(0x24)
#define WGM00   0
#define ICS0    3
#define ICES0   4
#define ICNC0   5
#define ICEN0   6
#define TCW0    7

#define TCCR0B  _SFR_IO8(0x25)
#define CS00    0
#define CS01    1
#define CS02    2

/* Combine TCNT0L and TCNT0H */
#define TCNT0   _SFR_IO16(0x26)

#define TCNT0L  _SFR_IO8(0x26)
#define TCNT0H  _SFR_IO8(0x27)

#define OCR0A   _SFR_IO8(0x28)

#define OCR0B   _SFR_IO8(0x29)

#define GPIOR1  _SFR_IO8(0x2A)

#define GPIOR2  _SFR_IO8(0x2B)

/* Reserved [0x2C..0x32] */

#define SMCR    _SFR_IO8(0x33)
#define SE      0
#define SM0     1
#define SM1     2
#define SM2     3

#define MCUSR   _SFR_IO8(0x34)
#define PORF    0
#define EXTRF   1
#define BODRF   2
#define WDRF    3
#define OCDRF   4

#define MCUCR   _SFR_IO8(0x35)
#define IVCE    0
#define IVSEL   1
#define PUD     4
#define CKOE    5

/* Reserved [0x36] */

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define LBSET   3
#define RWWSRE  4
#define SIGRD   5
#define RWWSB   6
#define SPMIE   7

/* Reserved [0x38..0x3C] */

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define WDTCSR  _SFR_MEM8(0x60)
#define WDE     3
#define WDCE    4
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDP3    5
#define WDIE    6
#define WDIF    7

#define CLKPR   _SFR_MEM8(0x61)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPCE  7

/* Reserved [0x62..0x63] */

#define PRR0    _SFR_MEM8(0x64)
#define PRVADC  0
#define PRTIM0  1
#define PRVRM   5
#define PRTWI   6

#define __AVR_HAVE_PRR0	((1<<PRVADC)|(1<<PRTIM0)|(1<<PRVRM)|(1<<PRTWI))
#define __AVR_HAVE_PRR0_PRVADC
#define __AVR_HAVE_PRR0_PRTIM0
#define __AVR_HAVE_PRR0_PRVRM
#define __AVR_HAVE_PRR0_PRTWI

/* Reserved [0x65] */

#define FOSCCAL _SFR_MEM8(0x66)

/* Reserved [0x67] */

#define PCICR   _SFR_MEM8(0x68)
#define PCIE0   0
#define PCIE1   1

#define EICRA   _SFR_MEM8(0x69)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define ISC20   4
#define ISC21   5

/* Reserved [0x6A] */

#define PCMSK0  _SFR_MEM8(0x6B)

#define PCMSK1  _SFR_MEM8(0x6C)

/* Reserved [0x6D] */

#define TIMSK0  _SFR_MEM8(0x6E)
#define TOIE0   0
#define OCIE0A  1
#define OCIE0B  2
#define ICIE0   3

/* Reserved [0x6F..0x77] */

/* Combine VADCL and VADCH */
#define VADC    _SFR_MEM16(0x78)

#define VADCL   _SFR_MEM8(0x78)
#define VADCH   _SFR_MEM8(0x79)

#define VADCSR  _SFR_MEM8(0x7A)
#define VADCCIE 0
#define VADCCIF 1
#define VADSC   2
#define VADEN   3

/* Reserved [0x7B] */

#define VADMUX  _SFR_MEM8(0x7C)
#define VADMUX0 0
#define VADMUX1 1
#define VADMUX2 2
#define VADMUX3 3

#define VREFCTRL _SFR_MEM8(0x7D)
#define VREFPULL0 0
#define VREFPULL1 1

#define DIDR0   _SFR_MEM8(0x7E)
#define PA0DID  0
#define PA1DID  1

/* Reserved [0x7F..0xB7] */

#define TWBR    _SFR_MEM8(0xB8)

#define TWSR    _SFR_MEM8(0xB9)
#define TWPS0   0
#define TWPS1   1
#define TWS3    3
#define TWS4    4
#define TWS5    5
#define TWS6    6
#define TWS7    7

#define TWAR    _SFR_MEM8(0xBA)
#define TWGCE   0
#define TWA0    1
#define TWA1    2
#define TWA2    3
#define TWA3    4
#define TWA4    5
#define TWA5    6
#define TWA6    7

#define TWDR    _SFR_MEM8(0xBB)

#define TWCR    _SFR_MEM8(0xBC)
#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7

#define TWAMR   _SFR_MEM8(0xBD)
#define TWAM0   1
#define TWAM1   2
#define TWAM2   3
#define TWAM3   4
#define TWAM4   5
#define TWAM5   6
#define TWAM6   7

#define TWBCSR  _SFR_MEM8(0xBE)
#define TWBCIP  0
#define TWBDT0  1
#define TWBDT1  2
#define TWBCIE  6
#define TWBCIF  7

/* Reserved [0xBF..0xC7] */

#define ROCR    _SFR_MEM8(0xC8)
#define ROCWIE  0
#define ROCWIF  1
#define ROCD    4
#define ROCS    7

/* Reserved [0xC9..0xCF] */

#define BGCCR   _SFR_MEM8(0xD0)
#define BGCC0   0
#define BGCC1   1
#define BGCC2   2
#define BGCC3   3
#define BGCC4   4
#define BGCC5   5

#define BGCRR   _SFR_MEM8(0xD1)

#define BGCSR   _SFR_MEM8(0xD2)
#define BGSCDIE 0
#define BGSCDIF 1
#define BGSCDE  4
#define BGD     5

/* Reserved [0xD3] */

#define CHGDCSR _SFR_MEM8(0xD4)
#define CHGDIE  0
#define CHGDIF  1
#define CHGDISC0 2
#define CHGDISC1 3
#define BATTPVL 4

/* Reserved [0xD5..0xDF] */

#define CADAC0  _SFR_MEM8(0xE0)

#define CADAC1  _SFR_MEM8(0xE1)

#define CADAC2  _SFR_MEM8(0xE2)

#define CADAC3  _SFR_MEM8(0xE3)

/* Combine CADICL and CADICH */
#define CADIC   _SFR_MEM16(0xE4)

#define CADICL  _SFR_MEM8(0xE4)
#define CADICH  _SFR_MEM8(0xE5)

#define CADCSRA _SFR_MEM8(0xE6)
#define CADSE   0
#define CADSI0  1
#define CADSI1  2
#define CADAS0  3
#define CADAS1  4
#define CADUB   5
#define CADPOL  6
#define CADEN   7

#define CADCSRB _SFR_MEM8(0xE7)
#define CADICIF 0
#define CADRCIF 1
#define CADACIF 2
#define CADICIE 4
#define CADRCIE 5
#define CADACIE 6

#define CADCSRC _SFR_MEM8(0xE8)
#define CADVSE  0

#define CADRCC  _SFR_MEM8(0xE9)

#define CADRDC  _SFR_MEM8(0xEA)

#define CADOSC  _SFR_MEM8(0xEB)
#define SELULP  0

/* Reserved [0xEC..0xEE] */

#define FCCSR   _SFR_MEM8(0xEF)
#define TMOUT0  0
#define TMOUT1  1
#define TMOUT2  2
#define CE      7

#define FCSR    _SFR_MEM8(0xF0)
#define CFE     0
#define DFE     1
#define CPS     2
#define DUVRD   3

#define CCCCR   _SFR_MEM8(0xF1)
#define CCCE1   0
#define CCCE2   1
#define CCCE3   2
#define CCCE4   3

#define BPIMSK  _SFR_MEM8(0xF2)
#define COCIE   2
#define DOCIE   3
#define SCIE    4

#define BPIFR   _SFR_MEM8(0xF3)
#define COCIF   2
#define DOCIF   3
#define SCIF    4

/* Reserved [0xF4] */

#define BPSCD   _SFR_MEM8(0xF5)

#define BPDOCD  _SFR_MEM8(0xF6)

#define BPCOCD  _SFR_MEM8(0xF7)

/* Reserved [0xF8..0xF9] */

#define BPSCTR  _SFR_MEM8(0xFA)

#define BPOCTR  _SFR_MEM8(0xFB)

/* Reserved [0xFC] */

#define BPCR    _SFR_MEM8(0xFD)
#define CHCD    0
#define DHCD    1
#define COCD    2
#define DOCD    3
#define SCD     4
#define UCPD    5

#define BPPLR   _SFR_MEM8(0xFE)
#define BPPL    0
#define BPPLE   1
#define PRMD    7

#define BPUCP   _SFR_MEM8(0xFF)
#define STATUS  0



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* Battery Protection Interrupt */
#define BPINT_vect            _VECTOR(1)
#define BPINT_vect_num        1

/* Voltage regulator monitor interrupt */
#define VREGMON_vect            _VECTOR(2)
#define VREGMON_vect_num        2

/* External Interrupt Request 0 */
#define INT0_vect            _VECTOR(3)
#define INT0_vect_num        3

/* External Interrupt Request 1 */
#define INT1_vect            _VECTOR(4)
#define INT1_vect_num        4

/* External Interrupt Request 2 */
#define INT2_vect            _VECTOR(5)
#define INT2_vect_num        5

/* Pin Change Interrupt 0 */
#define PCINT0_vect            _VECTOR(6)
#define PCINT0_vect_num        6

/* Pin Change Interrupt 1 */
#define PCINT1_vect            _VECTOR(7)
#define PCINT1_vect_num        7

/* Watchdog Timeout Interrupt */
#define WDT_vect            _VECTOR(8)
#define WDT_vect_num        8

/* Bandgap Buffer Short Circuit Detected */
#define BGSCD_vect            _VECTOR(9)
#define BGSCD_vect_num        9

/* Charger Detect */
#define CHDET_vect            _VECTOR(10)
#define CHDET_vect_num        10

/* Timer 0 Input Capture */
#define TIMER0_IC_vect            _VECTOR(11)
#define TIMER0_IC_vect_num        11

/* Timer 0 Compare Match A */
#define TIMER0_COMPA_vect            _VECTOR(12)
#define TIMER0_COMPA_vect_num        12

/* Timer 0 Compare Match B */
#define TIMER0_COMPB_vect            _VECTOR(13)
#define TIMER0_COMPB_vect_num        13

/* Timer 0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(14)
#define TIMER0_OVF_vect_num        14

/* Two-Wire Bus Connect/Disconnect */
#define TWIBUSCD_vect            _VECTOR(15)
#define TWIBUSCD_vect_num        15

/* Two-Wire Serial Interface */
#define TWI_vect            _VECTOR(16)
#define TWI_vect_num        16

/* Voltage ADC Conversion Complete */
#define VADC_vect            _VECTOR(17)
#define VADC_vect_num        17

/* Coulomb Counter ADC Conversion Complete */
#define CCADC_CONV_vect            _VECTOR(18)
#define CCADC_CONV_vect_num        18

/* Coloumb Counter ADC Regular Current */
#define CCADC_REG_CUR_vect            _VECTOR(19)
#define CCADC_REG_CUR_vect_num        19

/* Coloumb Counter ADC Accumulator */
#define CCADC_ACC_vect            _VECTOR(20)
#define CCADC_ACC_vect_num        20

/* EEPROM Ready */
#define EE_READY_vect            _VECTOR(21)
#define EE_READY_vect_num        21

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define _VECTORS_SIZE 88
#else
#  define _VECTORS_SIZE 88U
#endif


/* Constants */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SPM_PAGESIZE 128
#  define FLASHSTART   0x0000
#  define FLASHEND     0x67FF
#else
#  define SPM_PAGESIZE 128U
#  define FLASHSTART   0x0000U
#  define FLASHEND     0x67FFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define RAMSTART     0x0100
#  define RAMSIZE      1024
#  define RAMEND       0x04FF
#else
#  define RAMSTART     0x0100U
#  define RAMSIZE      1024U
#  define RAMEND       0x04FFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define E2START     0
#  define E2SIZE      512
#  define E2PAGESIZE  4
#  define E2END       0x01FF
#else
#  define E2START     0U
#  define E2SIZE      512U
#  define E2PAGESIZE  4U
#  define E2END       0x01FFU
#endif
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 2

/* Low Fuse Byte */
#define FUSE_RSTDISBL    (unsigned char)~_BV(0)
#define FUSE_SUT0        (unsigned char)~_BV(1)
#define FUSE_SUT1        (unsigned char)~_BV(2)
#define FUSE_CKSEL       (unsigned char)~_BV(3)
#define FUSE_CKDIV8      (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_EESAVE      (unsigned char)~_BV(6)
#define FUSE_WDTON       (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_CKDIV8 & FUSE_SPIEN)


/* High Fuse Byte */
#define FUSE_SELFPRGEN   (unsigned char)~_BV(0)
#define FUSE_DWEN        (unsigned char)~_BV(1)
#define HFUSE_DEFAULT    (0xFF)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x94
#define SIGNATURE_2 0x14




#endif /* #ifdef _AVR_ATMEGA26HVG_H_INCLUDED */

