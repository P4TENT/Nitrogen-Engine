#pragma once

#include <SDL2/SDL.h>

#define K_unknown SDL_SCANCODE_UNKNOWN
#define K_a SDL_SCANCODE_A
#define K_b SDL_SCANCODE_B
#define K_c SDL_SCANCODE_C
#define K_d SDL_SCANCODE_D
#define K_e SDL_SCANCODE_E
#define K_f SDL_SCANCODE_F
#define K_g SDL_SCANCODE_G
#define K_h SDL_SCANCODE_H
#define K_i SDL_SCANCODE_I
#define K_j SDL_SCANCODE_J
#define K_k SDL_SCANCODE_K
#define K_l SDL_SCANCODE_L
#define K_m SDL_SCANCODE_M
#define K_n SDL_SCANCODE_N
#define K_o SDL_SCANCODE_O
#define K_p SDL_SCANCODE_P
#define K_q SDL_SCANCODE_Q
#define K_r SDL_SCANCODE_R
#define K_s SDL_SCANCODE_S
#define K_t SDL_SCANCODE_T
#define K_u SDL_SCANCODE_U
#define K_v SDL_SCANCODE_V
#define K_w SDL_SCANCODE_W
#define K_x SDL_SCANCODE_X
#define K_y SDL_SCANCODE_Y
#define K_z SDL_SCANCODE_Z
#define K_1 SDL_SCANCODE_1
#define K_2 SDL_SCANCODE_2
#define K_3 SDL_SCANCODE_3
#define K_4 SDL_SCANCODE_4
#define K_5 SDL_SCANCODE_5
#define K_6 SDL_SCANCODE_6
#define K_7 SDL_SCANCODE_7
#define K_8 SDL_SCANCODE_8
#define K_9 SDL_SCANCODE_9
#define K_0 SDL_SCANCODE_0
#define K_ret SDL_SCANCODE_RETURN 
#define K_esc SDL_SCANCODE_ESCAPE 
#define K_backspace SDL_SCANCODE_BACKSPACE 
#define K_tab SDL_SCANCODE_TAB 
#define K_space SDL_SCANCODE_SPACE 
#define K_min SDL_SCANCODE_MINUS 
#define K_equal SDL_SCANCODE_EQUALS 
#define K_lbracket SDL_SCANCODE_LEFTBRACKET 
#define K_rbracket SDL_SCANCODE_RIGHTBRACKET 
#define K_backslash SDL_SCANCODE_BACKSLASH   /**< Located at the lower left of the return
                                              *   key on ISO keyboards and at the right end
                                              *   of the QWERTY row on ANSI keyboards.
                                              *   Produces REVERSE SOLIDUS (backslash) and
                                              *   VERTICAL LINE in a US layout, REVERSE
                                              *   SOLIDUS and VERTICAL LINE in a UK Mac
                                              *   layout, NUMBER SIGN and TILDE in a UK
                                              *   Windows layout, DOLLAR SIGN and POUND SIGN
                                              *   in a Swiss German layout, NUMBER SIGN and
                                              *   APOSTROPHE in a German layout, GRAVE
                                              *   ACCENT and POUND SIGN in a French Mac
                                              *   layout, and ASTERISK and MICRO SIGN in a
                                              *   French Windows layout.
                                              */
#define K_nonushash SDL_SCANCODE_NONUSHASH   /**< ISO USB keyboards actually use this code
                                              *   instead of 49 for the same key, but all
                                              *   OSes I've seen treat the two codes
                                              *   identically. So, as an implementor, unless
                                              *   your keyboard generates both of those
                                              *   codes and your OS treats them differently,
                                              *   you should generate SDL_SCANCODE_BACKSLASH
                                              *   instead of this code. As a user, you
                                              *   should not rely on this code because SDL
                                              *   will never generate it with most (all?)
                                              *   keyboards.
                                              */
#define K_semicolon SDL_SCANCODE_SEMICOLON
#define K_apostrophe SDL_SCANCODE_APOSTROPHE
#define K_grave SDL_SCANCODE_GRAVE    /**< Located in the top left corner (on both ANSI
                                      *   and ISO keyboards). Produces GRAVE ACCENT and
                                      *   TILDE in a US Windows layout and in US and UK
                                      *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                                      *   and NOT SIGN in a UK Windows layout, SECTION
                                      *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                                      *   layouts on ISO keyboards, SECTION SIGN and
                                      *   DEGREE SIGN in a Swiss German layout (Mac:
                                      *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                                      *   DEGREE SIGN in a German layout (Mac: only on
                                      *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                                      *   French Windows layout, COMMERCIAL AT and
                                      *   NUMBER SIGN in a French Mac layout on ISO
                                      *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                                      *   SIGN in a Swiss German, German, or French Mac
                                      *   layout on ANSI keyboards.
                                      */
#define K_period SDL_SCANCODE_PERIOD 
#define K_slash SDL_SCANCODE_SLASH
#define K_comma SDL_SCANCODE_COMMA

#define K_caps SDL_SCANCODE_CAPSLOCK

#define K_F1 SDL_SCANCODE_F1 
#define K_F2 SDL_SCANCODE_F2 
#define K_F3 SDL_SCANCODE_F3 
#define K_F4 SDL_SCANCODE_F4 
#define K_F5 SDL_SCANCODE_F5 
#define K_F6 SDL_SCANCODE_F6 
#define K_F7 SDL_SCANCODE_F7 
#define K_F8 SDL_SCANCODE_F8 
#define K_F9 SDL_SCANCODE_F9 
#define K_F10 SDL_SCANCODE_F10 
#define K_F11 SDL_SCANCODE_F11 
#define K_F12 SDL_SCANCODE_F12 

#define K_prtscrn SDL_SCANCODE_PRINTSCREEN
#define K_scrllock SDL_SCANCODE_SCROLLLOCK
#define K_pause SDL_SCANCODE_PAUSE 
#define K_insert SDL_SCANCODE_INSERT /**< insert on PC, help on some Mac keyboards (but
                               does send code 73, not 117) */
#define K_home SDL_SCANCODE_HOME 
#define K_pgup SDL_SCANCODE_PAGEUP 
#define K_del SDL_SCANCODE_DELETE 
#define K_end SDL_SCANCODE_END
#define K_pgdown SDL_SCANCODE_PAGEDOWN
#define K_right SDL_SCANCODE_RIGHT
#define K_left SDL_SCANCODE_LEFT 
#define K_down SDL_SCANCODE_DOWN 
#define K_up SDL_SCANCODE_UP

#define K_numlockclr SDL_SCANCODE_NUMLOCKCLEAR /**< num lock on PC, clear on Mac keyboards
                                    */
#define K_KP_div SDL_SCANCODE_KP_DIVIDE
#define K_KP_mul SDL_SCANCODE_KP_MULTIPLY 
#define K_KP_min SDL_SCANCODE_KP_MINUS 
#define K_KP_plus SDL_SCANCODE_KP_PLUS 
#define K_KP_enter SDL_SCANCODE_KP_ENTER 
#define K_KP_1 SDL_SCANCODE_KP_1 
#define K_KP_2 SDL_SCANCODE_KP_2 
#define K_KP_3 SDL_SCANCODE_KP_3 
#define K_KP_4 SDL_SCANCODE_KP_4 
#define K_KP_5 SDL_SCANCODE_KP_5 
#define K_KP_6 SDL_SCANCODE_KP_6 
#define K_KP_7 SDL_SCANCODE_KP_7 
#define K_KP_8 SDL_SCANCODE_KP_8 
#define K_KP_9 SDL_SCANCODE_KP_9 
#define K_KP_0 SDL_SCANCODE_KP_0 
#define K_KP_period SDL_SCANCODE_KP_PERIOD