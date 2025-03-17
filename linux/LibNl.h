#ifndef HEADER_LibNl
#define HEADER_LibNl
/*
hbottom - linux/LibNl.h
(C) 2024 hbottom dev team
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#include "linux/LinuxProcess.h"
#include "linux/LinuxProcessTable.h"


void LibNl_destroyNetlinkSocket(LinuxProcessTable* this);

void LibNl_readDelayAcctData(LinuxProcessTable* this, LinuxProcess* process);

#endif /* HEADER_LibNl */
