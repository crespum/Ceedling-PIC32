#include "unity.h"
#include "ws2812b.h"

colors_t colors;

void setUp(void) {
}

void tearDown(void) {
}

void test_should_ReturnError_when_IncorrectInput(void) {
	TEST_ASSERT_EQUAL(false, ws2812b_set_rgb_color(0x01FFFFFF, &colors));
	TEST_ASSERT_EQUAL(false, ws2812b_set_rgb_color(0xFFFFFFFF, &colors));
	TEST_ASSERT_EQUAL(false, ws2812b_set_rgb_color(-1, &colors));
}

void test_should_ReturnSuccess_when_ValidInput(void) {
	TEST_ASSERT_EQUAL(true, ws2812b_set_rgb_color(0x00AAAAAA, &colors));
	TEST_ASSERT_EQUAL(true, ws2812b_set_rgb_color(0x00FFFFFF, &colors));
	TEST_ASSERT_EQUAL(true, ws2812b_set_rgb_color(0x00000000, &colors));
}

void test_should_DecodeHex_when_ValidInput(void) {
	ws2812b_set_rgb_color(0x00ABCDEF, &colors);
	TEST_ASSERT_EQUAL_HEX8(0xAB, colors.red);
	TEST_ASSERT_EQUAL_HEX8(0xCD, colors.green);
	TEST_ASSERT_EQUAL_HEX8(0xEF, colors.blue);
}