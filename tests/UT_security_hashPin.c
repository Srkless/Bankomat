#include "cpptest.h"

/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("../src/utils.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("../src/utils.c");

EXTERN_C_LINKAGE void UT_security_hashPin_testSuiteBegin(void);
EXTERN_C_LINKAGE int UT_security_hashPin_callTest(const char*);

CPPTEST_TEST_SUITE(UT_security_hashPin);
        CPPTEST_TEST_SUITE_SETUP(UT_security_hashPin_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(UT_security_hashPin_testSuiteTearDown);
CPPTEST_TEST(UT_security_hashPin_TC_01);
CPPTEST_TEST(UT_security_hashPin_TC_02);
CPPTEST_TEST_SUITE_END();
        

void UT_security_hashPin_TC_01(void);
void UT_security_hashPin_TC_02(void);
CPPTEST_TEST_SUITE_REGISTRATION(UT_security_hashPin);

void UT_security_hashPin_testSuiteSetUp(void);
void UT_security_hashPin_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void UT_security_hashPin_testSuiteTearDown(void);
void UT_security_hashPin_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void UT_security_hashPin_setUp(void);
void UT_security_hashPin_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_security_hashPin_tearDown(void);
void UT_security_hashPin_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}

/**
 * The test case checks the correct behavior of the "hashPin" function when hashing a standard 4-digit PIN code.
 *
 * \field{Test Specification}
 * 1. Define a PIN string: "1234".
 * 2. Call hashPin with the PIN and the output buffer.
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. The hashPin function computes the hash correctly.
 * 2. The output buffer contains the expected hash string: "97EF04E6".
 * 3. The length of the output string is 8 characters and matches the expected value.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_01 */
/* CPPTEST_TEST_CASE_CONTEXT void hashPin(const char*, char*) */
void UT_security_hashPin_TC_01()
{
	char pin[5] = "1234";
	char hash[65];
	hashPin(pin, hash);
	CPPTEST_ASSERT_CSTR_EQUAL("97EF04E6", hash);
}
/* CPPTEST_TEST_CASE_END TC_01 */

/**
 * The test case checks the correct behavior of the "hashPin" function when hashing a standard 4-digit PIN code.
 *
 * \field{Test Specification}
 * 1. Define a PIN string: "4567".
 * 2. Call hashPin with the PIN and the output buffer.
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. The hashPin function computes the hash correctly.
 * 2. The output buffer contains the expected hash string: "842B9454".
 * 3. The length of the output string is 8 characters and matches the expected value.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_02 */
/* CPPTEST_TEST_CASE_CONTEXT void hashPin(const char*, char*) */
void UT_security_hashPin_TC_02()
{
	char pin[5] = "4567";
	char hash[65];
	hashPin(pin, hash);
	CPPTEST_ASSERT_CSTR_EQUAL("842B9454", hash);
}
/* CPPTEST_TEST_CASE_END TC_02 */
