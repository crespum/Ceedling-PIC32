#include "unity.h"
#include "calc.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_should_ReturnSum_when_ValidInput(void) {
    TEST_ASSERT_EQUAL_INT32(sum(4, 5), 9);
}
