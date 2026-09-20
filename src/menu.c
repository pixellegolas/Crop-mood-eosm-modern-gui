// --- OBSIDIAN THEME FOR AMIT'S SLIM GUI - EOS M ---
// File: src/menu.c
// Apply inside menu_draw_entry() and menu_draw()

// 1. In menu_draw() - main background
// Find: bmp_fill(COLOR_BLACK);
// Replace with:
bmp_fill(OBSIDIAN_BG);

// 2. In menu_draw_entry() - each entry as card
void menu_draw_entry_obsidian(struct menu_entry *entry, int x, int y, int w, int h) {
    int radius = 6; // Amit's Slim already supports rounded? If not, use fill_rect with margin
    int card_margin = 4;

    if(entry->selected) {
        // Card background
        bmp_fill(OBSIDIAN_CARD_SEL, x+card_margin, y+2, w-card_margin*2, h-4);
        // Left accent line - 4px cyan
        bmp_fill(OBSIDIAN_ACCENT, x+card_margin, y+2, 4, h-4);
        // Text
        bmp_printf(MENU_FONT_SEL, x+20, y+8, "%s", entry->name);
    } else {
        bmp_fill(OBSIDIAN_CARD, x+card_margin, y+2, w-card_margin*2, h-4);
        bmp_printf(MENU_FONT, x+16, y+8, "%s", entry->name);
    }

    // Value in dim gray, right aligned
    if(entry->selected) {
        bmp_printf(FONT(FONT_MEDIUM, OBSIDIAN_TEXT_DIM, OBSIDIAN_CARD_SEL), 
                   x+w-80, y+8, "%s", entry->value);
    } else {
        bmp_printf(FONT(FONT_MEDIUM, OBSIDIAN_TEXT_DIM, OBSIDIAN_CARD), 
                   x+w-80, y+8, "%s", entry->value);
    }
}

// 3. For Amit's Quick Toggles (live view tap) - keep same colors
// In quick_toggles_draw():
// Use OBSIDIAN_CARD with 80% alpha, OBSIDIAN_ACCENT for active toggle
