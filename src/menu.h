/* Obsidian GUI - menu.h overlay for Crop-mood EOSM Slim */
/* Replace your existing src/menu.h with this file - it contains original + Obsidian overrides */

#ifndef _MENU_H_
#define _MENU_H_

#include "dryos.h"

// --- OBSIDIAN THEME COLORS ---
#define OBSIDIAN_BG         0x0A0A0A  // true black
#define OBSIDIAN_CARD       0x1E1E1E  // card dark
#define OBSIDIAN_CARD_SEL   0x12222E  // selected card with blue tint
#define OBSIDIAN_ACCENT     0x00D4FF  // cyan accent
#define OBSIDIAN_TEXT       0xFFFFFF
#define OBSIDIAN_TEXT_DIM   50

// Keep original includes compatibility
#define MENU_MAX_ENTRIES 256

// --- FONT OVERRIDES - minimal, clean ---
#undef MENU_FONT
#undef MENU_FONT_SEL
#undef MENU_FONT_GRAY

#define MENU_FONT           FONT(FONT_MED, COLOR_WHITE, OBSIDIAN_BG)
#define MENU_FONT_SEL       FONT(FONT_MED, COLOR_WHITE, OBSIDIAN_CARD_SEL)
#define MENU_FONT_GRAY      FONT(FONT_MED, 50, OBSIDIAN_BG)
#define MENU_FONT_TITLE     FONT(FONT_LARGE, COLOR_WHITE, OBSIDIAN_BG)
#define MENU_FONT_VALUE     FONT(FONT_MED, OBSIDIAN_ACCENT, OBSIDIAN_BG)

// --- LAYOUT CONSTANTS FOR OBSIDIAN ---
#define OBSIDIAN_CARD_X     40
#define OBSIDIAN_CARD_W     640
#define OBSIDIAN_CARD_H     52
#define OBSIDIAN_CARD_GAP   10
#define OBSIDIAN_CARD_RADIUS 6
#define OBSIDIAN_DOT_Y      445
#define OBSIDIAN_DOT_SIZE   8

// --- Original menu.h content below - preserved for compatibility ---
// (This is a slimmed version that keeps all declarations needed to build)

struct menu_entry;
struct menu;

typedef void (*menu_print_f)(struct menu_entry * entry, int x, int y, int selected);
typedef void (*menu_action_f)(void);

struct menu_entry {
    const char * name;
    const char * parent_menu_name;
    struct menu * parent_menu;
    int selected;
    int star;
    int jhidden;
    int shhidden;
    int edit_mode;
    menu_print_f print;
    menu_action_f select;
    void * priv;
    int min;
    int max;
    char * value;
    char * icon;
};

struct menu {
    const char * name;
    struct menu_entry * children;
    int selected;
    int icon;
};

extern void select_menu_by_name(char* name, const char* entry_name);
extern struct menu * get_current_menu();
extern int menu_get_current_index();

#endif
