#include "unity.h"
#include "ws2812b.h"
#include "mock_plib_ports.h"

NeopixelHandler_t neopixel;

void setUp(void) {
    ws2812b_init(&neopixel, PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_5);
}

void tearDown(void) {
}

void test_should_ReturnError_when_IncorrectInput(void) {
    TEST_ASSERT_FALSE(ws2812b_set_rgb_color(&neopixel, 0x01FFFFFF));
    TEST_ASSERT_FALSE(ws2812b_set_rgb_color(&neopixel, 0xFFFFFFFF));
    TEST_ASSERT_FALSE(ws2812b_set_rgb_color(&neopixel, -1));
}

void test_should_ReturnSuccess_when_ValidInput(void) {
    PLIB_PORTS_PinSet_Ignore();
    PLIB_PORTS_PinClear_Ignore();

    TEST_ASSERT_TRUE(ws2812b_set_rgb_color(&neopixel, 0x00AAAAAA));
    TEST_ASSERT_TRUE(ws2812b_set_rgb_color(&neopixel, 0x00FFFFFF));
    TEST_ASSERT_TRUE(ws2812b_set_rgb_color(&neopixel, 0x00000000));
}

void test_should_DecodeHex_when_ValidInput(void) {
    // PLIB_PORTS_PinSet_Expect(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0);
    PLIB_PORTS_PinSet_Ignore();
    PLIB_PORTS_PinClear_Ignore();

    ws2812b_set_rgb_color(&neopixel, 0xE45347);
    TEST_ASSERT_EQUAL_HEX8(0xE4, neopixel.colors.red);
    TEST_ASSERT_EQUAL_HEX8(0x53, neopixel.colors.green);
    TEST_ASSERT_EQUAL_HEX8(0x47, neopixel.colors.blue);
}

void test_should_SavePortInfo_when_Initializing(void) {
    TEST_ASSERT_EQUAL_UINT(PORTS_ID_0, neopixel.ports_id);
    TEST_ASSERT_EQUAL_UINT(PORT_CHANNEL_B, neopixel.port_channel);
    TEST_ASSERT_EQUAL_UINT(PORTS_BIT_POS_5, neopixel.port_bit_position);
}