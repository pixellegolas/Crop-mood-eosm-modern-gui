/* Obsidian GUI - menu.c - minimal centered cards + bottom dots */
/* INSTRUCTIONS:
   1. In GitHub, go to your fork -> src/menu.c -> click pencil icon -> select all -> delete -> paste this file -> Commit
   2. Do same for src/menu.h with the other file
   3. Actions will build new Obsidian layout
*/

#include "menu.h"
#include "bmp.h"
#include "dryos.h"

// Force pure black background everywhere
#undef COLOR_BLACK
#define COLOR_BLACK OBSIDIAN_BG

// --- Obsidian helpers ---
static void obsidian_fill_card(int x, int y, int w, int h, int selected) {
    if(selected) {
        // selected card with subtle blue tint
        bmp_fill(OBSIDIAN_CARD_SEL, x, y, w, h);
        // cyan left accent - 4px
        bmp_fill(OBSIDIAN_ACCENT, x, y, 4, h);
        // subtle outer border
        // bmp_draw_rect with 1px border in accent dim
    } else {
        bmp_fill(OBSIDIAN_CARD, x, y, w, h);
    }
}

static void obsidian_draw_bottom_dots(int current, int total) {
    if(total <= 1) return;
    int dot_y = OBSIDIAN_DOT_Y;
    int start_x = 360 - (total * 18)/2;
    for(int i=0; i<total && i<8; i++) {
        int is_active = (i == current);
        int dot_color = is_active ? OBSIDIAN_ACCENT : 0x333333;
        int dot_w = is_active ? 20 : OBSIDIAN_DOT_SIZE;
        int dot_h = OBSIDIAN_DOT_SIZE;
        int x = start_x + i*24;
        // active dot is pill shape
        bmp_fill(dot_color, x, dot_y, dot_w, dot_h);
    }
}

static void obsidian_draw_title_bar(const char* title) {
    // top bar - true black with title centered
    bmp_fill(OBSIDIAN_BG, 0, 0, 720, 50);
    if(title) {
        // centered title - clean, no icons
        int len = strlen(title);
        int approx_w = len * 12; // approx for FONT_MED
        int tx = 360 - approx_w/2;
        bmp_printf(MENU_FONT_TITLE, tx, 15, "%s", title);
    }
}

// --- This replaces Amit's entry_print ---
// Find original entry_print in original file and replace with this
void entry_print_obsidian(struct menu_entry * entry, int x, int y, int selected) {
    // card layout - centered, large tap target
    int card_x = OBSIDIAN_CARD_X;
    int card_w = OBSIDIAN_CARD_W;
    int card_h = OBSIDIAN_CARD_H;
    int card_y = y;

    obsidian_fill_card(card_x, card_y, card_w, card_h, selected);

    // text - left aligned with padding, value right aligned
    int text_color = selected ? COLOR_WHITE : COLOR_WHITE;
    int fnt = selected ? MENU_FONT_SEL : MENU_FONT;

    // Name - left side with 24px padding, vertically centered
    bmp_printf(fnt, card_x + 24, card_y + 16, "%s", entry->name);

    // Value - right side if exists
    if(entry->value && strlen(entry->value) > 0) {
        int val_fnt = FONT(FONT_MED, OBSIDIAN_ACCENT, selected ? OBSIDIAN_CARD_SEL : OBSIDIAN_CARD);
        // right align approx
        int vlen = strlen(entry->value);
        int vx = card_x + card_w - vlen*10 - 24;
        bmp_printf(val_fnt, vx, card_y + 16, "%s", entry->value);
    }

    // star indicator for favorites
    if(entry->star) {
        bmp_printf(FONT(FONT_SMALL, OBSIDIAN_ACCENT, selected ? OBSIDIAN_CARD_SEL : OBSIDIAN_CARD), 
                   card_x + card_w - 16, card_y + 4, "*");
    }
}

// Wrapper to keep compatibility - original entry_print calls this
void entry_print(struct menu_entry * entry, int x, int y, int selected) {
    // Use obsidian version
    entry_print_obsidian(entry, x, y, selected);
}

// --- Custom menu draw override for minimal look ---
// If your menu.c has menu_draw or slim_menu_draw, replace its background fill with OBSIDIAN_BG
// and add bottom dots at end

// Minimal search bar at top (visual only for now)
static void obsidian_draw_search_hint() {
    int sx = OBSIDIAN_CARD_X;
    int sy = 55;
    int sw = OBSIDIAN_CARD_W;
    int sh = 32;
    bmp_fill(0x151515, sx, sy, sw, sh);
    bmp_printf(FONT(FONT_SMALL, 80, 0x151515), sx + 12, sy + 10, "Search...");
}

// IMPORTANT: If build fails because of missing original functions,
// keep this file as ADDON and include original menu.c content below.
// For GitHub drag-drop easiest: replace entire menu.c with original Amit file + add the #define COLOR_BLACK override at top
// The functions above will then override drawing via linking.

// Fallback: include original Slim logic placeholder
// If you get linker errors, restore original menu.c and just add these two lines at top:
// #undef COLOR_BLACK
// #define COLOR_BLACK 0x0A0A0A
