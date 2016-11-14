#ifndef __WS2812B_H__
#define __WS2812B_H__

#include <stdint.h>
#include "peripheral/ports/plib_ports.h"


typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} colors_t;

typedef struct {
    PORTS_MODULE_ID ports_id;
    PORTS_CHANNEL port_channel;
    PORTS_BIT_POS port_bit_position;
    colors_t colors;
} NeopixelHandler_t;

void ws2812b_init(NeopixelHandler_t *handler, PORTS_MODULE_ID id, PORTS_CHANNEL channel, PORTS_BIT_POS bit_position);

/**
 * Gets an hex code and change the color of an LED accordingly. The decoded color is 
 * returned in a colors_t structure.
 *
 * @param hex RGB hexadecimal code.
 * @param colors pointer to a color structure that will contain the decoded colors.
 *
 * @return true if successful, false otherwise.
 */
bool ws2812b_set_rgb_color(NeopixelHandler_t *handler, int32_t hex);

#define WS2812B_T1H_NOP   _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop();
#define WS2812B_T0H_NOP   _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop();
#define WS2812B_T1L_NOP   _nop();
#define WS2812B_T0L_NOP   _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop();

#endif  /* __WS2812B_H__ */
