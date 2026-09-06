
#ifndef _AVR_IOM007B_H_
#define _AVR_IOM007B_H_ 1

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif
 
#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom007b.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Constants */
#define RAMSTART        0x71E0
#define RAMEND          (0x8000 -1)

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (8 * _VECTOR_SIZE)

/* Include host processor headers for peripherals */
#ifdef INCLUDE_SAM
    #include "../saml21j18b.h"
#endif

#endif /*  _AVR_IOM007_H_ */

