/**
 * #FujiNet Tests - fnUartCTL Test
 */

#include "test_fnUART_CTL.h"
#include "../lib/hardware/fnUART.h"

// Define test_fnUartCTL_init function
void test_fnUartCTL_init()
{
    // Begin with a standard baud rate
    fnUartCTL.begin(19200);

    // Verify it claims to be initialized
    TEST_ASSERT_TRUE_MESSAGE(fnUartCTL.initialized(), "fnUartCTL not initialized after begin()");

    // Verify baud rate matches
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(19200, fnUartCTL.get_baudrate(), "Baud rate mismatch at 19200");

    // Change baud rate and verify
    fnUartCTL.set_baudrate(9600);
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(9600, fnUartCTL.get_baudrate(), "Baud rate mismatch after change to 9600");

    // Cleanup
    fnUartCTL.end();
}

void test_fnUartCTL_run()
{
    RUN_TEST(test_fnUartCTL_init);
}
