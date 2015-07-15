// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A sample program demonstrating using Google C++ testing framework.
//
// Author: wan@google.com (Zhanyong Wan)


// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
//
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:


// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

//#include <stdio.h>
#include <limits.h>

#include "sample1.h"

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/Console.h"


// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>

#if 0
// Tests Factorial().

// Tests factorial of negative numbers.
TEST ( FactorialTest, Negative )
{
    // This test is named "Negative", and belongs to the "FactorialTest"
    // test case.
    EXPECT_EQ ( 1, Factorial ( -5 ) );
    EXPECT_EQ ( 1, Factorial ( -1 ) );
    EXPECT_GT ( Factorial ( -10 ), 0 );

    // <TechnicalDetails>
    //
    // EXPECT_EQ(expected, actual) is the same as
    //
    //   EXPECT_TRUE((expected) == (actual))
    //
    // except that it will print both the expected value and the actual
    // value when the assertion fails.  This is very helpful for
    // debugging.  Therefore in this case EXPECT_EQ is preferred.
    //
    // On the other hand, EXPECT_TRUE accepts any Boolean expression,
    // and is thus more general.
    //
    // </TechnicalDetails>
}

// Tests factorial of 0.
TEST ( FactorialTest, Zero )
{
    EXPECT_EQ ( 1, Factorial ( 0 ) );
}

// Tests factorial of positive numbers.
TEST ( FactorialTest, Positive )
{
    EXPECT_EQ ( 1, Factorial ( 1 ) );
    EXPECT_EQ ( 2, Factorial ( 2 ) );
    EXPECT_EQ ( 6, Factorial ( 3 ) );
    EXPECT_EQ ( 40320, Factorial ( 8 ) );
}


// Tests IsPrime()

// Tests negative input.
TEST ( IsPrimeTest, Negative )
{
    // This test belongs to the IsPrimeTest test case.

    EXPECT_FALSE ( IsPrime ( -1 ) );
    EXPECT_FALSE ( IsPrime ( -2 ) );
    EXPECT_FALSE ( IsPrime ( INT_MIN ) );
}

// Tests some trivial cases.
TEST ( IsPrimeTest, Trivial )
{
    EXPECT_FALSE ( IsPrime ( 0 ) );
    EXPECT_FALSE ( IsPrime ( 1 ) );
    EXPECT_TRUE ( IsPrime ( 2 ) );
    EXPECT_TRUE ( IsPrime ( 3 ) );
}

// Tests positive input.
TEST ( IsPrimeTest, Positive )
{
    EXPECT_FALSE ( IsPrime ( 4 ) );
    EXPECT_TRUE ( IsPrime ( 5 ) );
    EXPECT_FALSE ( IsPrime ( 6 ) );
    EXPECT_TRUE ( IsPrime ( 23 ) );
}
#endif

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?

/* Test Suite setup and cleanup functions: */
int init_suite ( void )
{
    return 0;
}

int clean_suite ( void )
{
    return 0;
}

// Test case list
// Tests factorial of negative numbers.
void Test_Factorial_1 ( void )
{
    CU_ASSERT_EQUAL ( Factorial ( -5 ), 1 );
    CU_ASSERT_EQUAL ( Factorial ( -1 ), 1 );
    CU_ASSERT ( Factorial ( -10 ) > 0 );
}

// Tests factorial of 0.
void Test_Factorial_2 ( void )
{
    CU_ASSERT_EQUAL ( Factorial ( 0 ), 1 );
}

// Tests factorial of positive numbers.
void Test_Factorial_3 ( void )
{
    CU_ASSERT_EQUAL ( Factorial ( 1 ), 1 );
    CU_ASSERT_EQUAL ( Factorial ( 2 ), 2 );
    CU_ASSERT_EQUAL ( Factorial ( 3 ), 6 );
    CU_ASSERT_EQUAL ( Factorial ( 8 ), 40320 );
}

int main ( void )
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if ( CUE_SUCCESS != CU_initialize_registry() )
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite ( "test_suite", init_suite, clean_suite );
    if ( NULL == pSuite )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if ( ( NULL == CU_add_test ( pSuite, "Test_Factorial_1", Test_Factorial_1 ) )
            || ( NULL == CU_add_test ( pSuite, "Test_Factorial_2", Test_Factorial_2 ) )
            || ( NULL == CU_add_test ( pSuite, "Test_Factorial_3", Test_Factorial_3 ) )
       )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_basic_set_mode ( CU_BRM_VERBOSE );
    CU_basic_run_tests();
    //printf ( "\n" );

    CU_basic_show_failures ( CU_get_failure_list() );
    //printf ( "\n\n" );

    /*
    // Run all tests using the automated interface
    CU_automated_run_tests();
    CU_list_tests_to_file();

    // Run all tests using the console interface
    CU_console_run_tests();
    */

    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
}
