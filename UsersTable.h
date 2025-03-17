#ifndef HEADER_UsersTable
#define HEADER_UsersTable
/*
hbottom - UsersTable.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#include "Hashtable.h"


typedef struct UsersTable_ {
   Hashtable* users;
} UsersTable;

UsersTable* UsersTable_new(void);

void UsersTable_delete(UsersTable* this);

char* UsersTable_getRef(UsersTable* this, unsigned int uid);

void UsersTable_foreach(UsersTable* this, Hashtable_PairFunction f, void* userData);

#endif
