/*
File:   FirmwareDefs.h
Author: J. Ian Lindsay
Date:   2015.03.01


This is one of the files that the application author is required to provide.
This is where definition of (application or device)-specific parameters ought to go.

This is an example file for building firmware on linux. Anticipated target is a Raspi.
  but that shouldn't matter too much. These settings are only typically relevant for
  reasons of memory-constraint, threading model (if any), or specific features that
  this hardware can support.
*/

#ifndef __FIRMWARE_DEFS_H
#define __FIRMWARE_DEFS_H


/*
* PROTOCOL_MTU is required for constraining communication length due to memory restrictions at
*   one-or-both sides. Since the protocol currently supports up to (2^24)-1 bytes in a single transaction,
*   a microcontroller would want to limit its counter-party's use of precious RAM. PROTOCOL_MTU, therefore,
*   determines the effective maximum packet size for this device, and by extension, the sessions in which
*   it participates.
*/


/****************************************************************************************************
* Required fields...                                                                                *
****************************************************************************************************/

/*
* Particulars of this platform.
*/
#define PLATFORM_RNG_CARRY_CAPACITY      128    // How many random numbers should be cached? Must be > 0.
#define PROTOCOL_MTU                  655536    // See MTU notes above....

/*
* Particulars of this Manuvrable.
*/
// This is the string that identifies this Manuvrable to other Manuvrables. In MHB's case, this
//   will select the mEngine.
#define IDENTITY_STRING         "ManuvrDemo"    // The name of this firmware.

// This would be the version of the Manuvrable's firmware (this program).
#define VERSION_STRING               "0.0.1"

// Hardware is versioned. Manuvrables that are strictly-software should comment this.
//#define HW_VERSION_STRING               "rev4"

// The version of Manuvr's protocol we are using.
#define PROTOCOL_VERSION             "0.0.1"


/*
* Kernel options.
*/
#define EVENT_MANAGER_PREALLOC_COUNT      32    // How large a preallocation buffer should we keep?
#define MANUVR_PLATFORM_TIMER_PERIOD_MS   10    // What is the granularity of our scheduler?

#define MAXIMUM_SEQUENTIAL_SKIPS          20    // How many scheduler skips are we willing to tolerate?


/****************************************************************************************************
* Optional fields...                                                                                *
****************************************************************************************************/

/**************************************************************************************************
* Threading options                                                                               *
* Manuvr was designed to not be reliant on a threading model. However, many designes and          *
*   environments mandate threading. Set options related to these features below.                  *
* In anticipation of support for RIOT and Zephyr,                                                 *
**************************************************************************************************/
//#define MANUVR_THREAD_MODEL     "__THREADING_PTHREADS"
//#define MANUVR_THREAD_MODEL     "__THREADING_FREERTOS"
//#define MANUVR_THREAD_MODEL     "__THREADING_ZEPHYR"


#define EXTENDED_DETAIL_STRING    "RasPiBuild"  // Optional. User-defined.

// We have console support on linux. On a bare-metal build, this would mean that we've designated
//   a serial port (or some other transport) as a target for plaintext interaction. This is
//   typically only useful for debugging firmware.
// If you don't want console support, comment the line below.
// NOTE: If your Makefile passes the __MANUVR_DEBUG option, this will be enabled regardless.
#if defined(__MANUVR_DEBUG) && !defined(__MANUVR_CONSOLE_SUPPORT)
  #define __MANUVR_CONSOLE_SUPPORT
#endif

// If another Manuverable asks, we will send them semantic definitions for our messages.
// Comment the line below if your platform is too-small to support these, or you don't intend
//   your Manuvrable to be used by a human directly.
#define __ENABLE_MSG_SEMANTICS

#endif