#include "ws2812b.h"

/**************************************************************************
 *                          PRIVATE FUCTIONS
 **************************************************************************/

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

void ws2812b_set_bit(NeopixelHandler_t *handler, uint8_t bit) {
    if (bit == 1) {
        PLIB_PORTS_PinSet(handler->ports_id, handler->port_channel, handler->port_bit_position);
        WS2812B_T1H_NOP
        PLIB_PORTS_PinClear(handler->ports_id, handler->port_channel, handler->port_bit_position);
        WS2812B_T1L_NOP
    } else {
        PLIB_PORTS_PinSet(handler->ports_id, handler->port_channel, handler->port_bit_position);
        WS2812B_T0H_NOP
        PLIB_PORTS_PinClear(handler->ports_id, handler->port_channel, handler->port_bit_position);
        WS2812B_T0L_NOP
    }
}

/**************************************************************************
 *                          PUBLIC FUCTIONS
 **************************************************************************/

void ws2812b_init(NeopixelHandler_t *handler, PORTS_MODULE_ID id, PORTS_CHANNEL channel, PORTS_BIT_POS bit_position) {
    handler->ports_id = id;
    handler->port_channel = channel;
    handler->port_bit_position = bit_position;
}

bool ws2812b_set_rgb_color(NeopixelHandler_t *handler, int32_t hex) {
    int8_t bit;
    colors_t *colors = &(handler->colors);

    if (ws2812b_hex2struct(colors, hex)) {
        // According to the datasheet the order must be GRB
        for (bit = 7; bit >= 0; bit--) {
            ws2812b_set_bit(handler, (colors->green >> bit) & 0x01);
        }
        for (bit = 7; bit >= 0; bit--) {
            ws2812b_set_bit(handler, (colors->red >> bit) & 0x01);
        }
        for (bit = 7; bit >= 0; bit--) {
            ws2812b_set_bit(handler, (colors->blue >> bit) & 0x01);
        }
        return true;
    } else {
        return false;
    }
}
