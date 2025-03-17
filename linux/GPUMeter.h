#ifndef HEADER_GPUMeter
#define HEADER_GPUMeter
/*
hbottom - GPUMeter.h
(C) 2023 hbottom dev team
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#include <stdbool.h>

#include "Meter.h"


extern const MeterClass GPUMeter_class;

bool GPUMeter_active(void);

#endif /* HEADER_GPUMeter */
