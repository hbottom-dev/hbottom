#ifndef HEADER_NetworkIOMeter
#define HEADER_NetworkIOMeter
/*
hbottom - NetworkIOMeter.h
(C) 2020-2023 hbottom dev team
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#include <stdint.h>

#include "Meter.h"


typedef struct NetworkIOData_ {
   uint64_t bytesReceived;
   uint64_t packetsReceived;
   uint64_t bytesTransmitted;
   uint64_t packetsTransmitted;
} NetworkIOData;

extern const MeterClass NetworkIOMeter_class;

#endif /* HEADER_NetworkIOMeter */
