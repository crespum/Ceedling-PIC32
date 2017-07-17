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

/**
 * Initializes the Neopixel with port information. That information is saved to a hanlder
 * that will be used for configuring the LED in next calls.
 * 
 * @param handler Pointer to a structure that identifies the Neopixel and will be passed to other methods.
 * @param id Identifier for the device instance to be configured
 * @param channel Identifier for the Ports channel A, B, C, etc. 
 * @param bit_position Pin to be used mapped to port.
 */
void ws2812b_init(NeopixelHandler_t *handler, PORTS_MODULE_ID id, PORTS_CHANNEL channel, PORTS_BIT_POS bit_position);

/**
 * Gets an hex code and change the color of an LED accordingly. The decoded color is 
 * returned in a colors_t structure inside the handler.
 *
 * @param handler Pointer to a structure that identifies the Neopixel.
 * @param hex RGB Hexadecimal code.
 *
 * @return True if successful, false otherwise.
 */
bool ws2812b_set_rgb_color(NeopixelHandler_t *handler, int32_t hex);

/**
 * Definitions of the waiting time between PinSet and PinClear to implement bitbanging.
 */
#define WS2812B_T1H_NOP   _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop();
#define WS2812B_T0H_NOP   _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop();
#define WS2812B_T1L_NOP   _nop();
#define WS2812B_T0L_NOP   _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop();

#endif  /* __WS2812B_H__ */
