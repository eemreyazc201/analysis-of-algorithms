#include "munit.h"
#include "item_tests.h" 

// Main function to run all test suites
int main (int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    // Combine both test suites into an array
    int result = munit_suite_main(&itemTestSuite, NULL, argc, argv);

    return result;  // Return the result of the last executed test suite
}