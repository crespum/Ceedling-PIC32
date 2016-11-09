#ifndef WS2812B_H
#define	WS2812B_H

#include <stdint.h>
#include "system/ports/sys_ports.h"

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} colors_t;

/**
 * Gets an hex code and change the color of an LED accordingly. The decoded color is 
 * returned in a colors_t structure.
 *
 * @param hex RGB hexadecimal code.
 * @param colors pointer to a color structure that will contain the decoded colors.
 *
 * @return true if successful, false otherwise.
 */
bool ws2812b_set_rgb_color(int32_t hex, colors_t *colors);

#define WS2812B_T1H_NOP   _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop();
#define WS2812B_T0H_NOP   _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop();
#define WS2812B_T1L_NOP   _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); 
#define WS2812B_T0L_NOP   _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop(); _nop();

#endif	/* WS2812B_H */
