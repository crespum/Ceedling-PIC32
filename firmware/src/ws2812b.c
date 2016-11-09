#include "ws2812b.h"

bool ws2812b_hex2struct(colors_t *colors, int32_t hex) {
    if (hex <= 0xFFFFFF && hex >= 0) {
        colors->red = (hex >> 16) & 0xFF;
        colors->green = (hex >> 8) & 0xFF;
        colors->blue = hex & 0xFF;
        return true;
    } else {
        return false;
    }
}

void ws2812b_set_bit(uint8_t bit) {
    if (bit == 1) {
        SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0);
        WS2812B_T1H_NOP
        SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0);
        WS2812B_T1L_NOP    
    } // delay_cycles (3); // Bit '1'
    else {
        SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0);
        WS2812B_T0H_NOP
        SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0);
        WS2812B_T0L_NOP
    } // delay_cycles (6); // Bit '0'
}

bool ws2812b_set_rgb_color(int32_t hex, colors_t *colors) {
    int bit;

    if (ws2812b_hex2struct(colors, hex)) {
        // According to the datasheet the order must be GRB
        for (bit = 0; bit < 8; bit++) {
            ws2812b_set_bit((colors->green >> bit) & 0x01);
        }
        for (bit = 0; bit < 8; bit++) {
            ws2812b_set_bit((colors->red >> bit) & 0x01);
        }
        for (bit = 0; bit < 8; bit++) {
            ws2812b_set_bit((colors->blue >> bit) & 0x01);
        }
        return true;
    } else {
        return false;
    }
}
