// --- OBSIDIAN THEME FOR AMIT'S SLIM GUI - EOS M ---
// File: src/menu.h
// Based on Amit199167/Crop-mood-eosm-slim-gui (which already uses Roboto font)

#define OBSIDIAN_BG         0x0A0A0A  // True black
#define OBSIDIAN_CARD       0x1E1E1E  // Charcoal card
#define OBSIDIAN_CARD_SEL   0x12222E  // Dark blue tint for selected
#define OBSIDIAN_ACCENT     0x00D4FF  // Cyan accent #00D4FF
#define OBSIDIAN_TEXT       COLOR_WHITE
#define OBSIDIAN_TEXT_DIM   0x888888

// Keep Amit's Roboto font, just change colors
#undef MENU_FONT
#define MENU_FONT           FONT(FONT_MEDIUM, COLOR_WHITE, OBSIDIAN_BG)
#define MENU_FONT_SEL       FONT(FONT_MEDIUM, COLOR_WHITE, OBSIDIAN_CARD_SEL)
#define MENU_FONT_GRAY      FONT(FONT_MEDIUM, 50, OBSIDIAN_BG)

// Custom page and Quick Toggles keep same font
