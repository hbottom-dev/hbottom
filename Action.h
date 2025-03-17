#ifndef HEADER_Action
#define HEADER_Action
/*
hbottom - Action.h
(C) 2015 Hisham H. Muhammad
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#include <stdbool.h>
#include <sys/types.h>

#include "Header.h"
#include "Machine.h"
#include "Object.h"
#include "Panel.h"
#include "Process.h"
#include "Settings.h"


typedef enum {
   hbottom_OK              = 0x00,
   hbottom_REFRESH         = 0x01,
   hbottom_RECALCULATE     = 0x02 | hbottom_REFRESH,
   hbottom_SAVE_SETTINGS   = 0x04,
   hbottom_KEEP_FOLLOWING  = 0x08,
   hbottom_QUIT            = 0x10,
   hbottom_REDRAW_BAR      = 0x20,
   hbottom_UPDATE_PANELHDR = 0x40 | hbottom_REFRESH,
   hbottom_RESIZE          = 0x80 | hbottom_REFRESH | hbottom_REDRAW_BAR | hbottom_UPDATE_PANELHDR,
} hbottom_Reaction;

struct MainPanel_; // IWYU pragma: keep

typedef struct State_ {
   Machine* host;
   struct MainPanel_* mainPanel;
   Header* header;
   bool pauseUpdate;
   bool hideSelection;
   bool hideMeters;
} State;

static inline bool State_hideFunctionBar(const State* st) {
   const Settings* settings = st->host->settings;
   return settings->hideFunctionBar == 2 || (settings->hideFunctionBar == 1 && st->hideSelection);
}

typedef hbottom_Reaction (*hbottom_Action)(State* st);

Object* Action_pickFromVector(State* st, Panel* list, int x, bool follow);

bool Action_setUserOnly(const char* userName, uid_t* userId);

hbottom_Reaction Action_setSortKey(Settings* settings, ProcessField sortKey);

hbottom_Reaction Action_setScreenTab(State* st, int x);

hbottom_Reaction Action_follow(State* st);

void Action_setBindings(hbottom_Action* keys);

#endif
