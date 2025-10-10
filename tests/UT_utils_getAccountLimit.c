#include "cpptest.h"

/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("../src/utils.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("../src/utils.c");

EXTERN_C_LINKAGE void UT_utils_getAccountLimit_testSuiteBegin(void);
EXTERN_C_LINKAGE int UT_utils_getAccountLimit_callTest(const char*);

CPPTEST_TEST_SUITE(UT_utils_getAccountLimit);
        CPPTEST_TEST_SUITE_SETUP(UT_utils_getAccountLimit_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(UT_utils_getAccountLimit_testSuiteTearDown);
CPPTEST_TEST(UT_utils_getAccountLimit_TC_01);
CPPTEST_TEST(UT_utils_getAccountLimit_TC_02);
CPPTEST_TEST(UT_utils_getAccountLimit_TC_03);
CPPTEST_TEST_SUITE_END();
        

void UT_utils_getAccountLimit_TC_01(void);
void UT_utils_getAccountLimit_TC_02(void);
void UT_utils_getAccountLimit_TC_03(void);
CPPTEST_TEST_SUITE_REGISTRATION(UT_utils_getAccountLimit);

void UT_utils_getAccountLimit_testSuiteSetUp(void);
void UT_utils_getAccountLimit_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void UT_utils_getAccountLimit_testSuiteTearDown(void);
void UT_utils_getAccountLimit_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void UT_utils_getAccountLimit_setUp(void);
void UT_utils_getAccountLimit_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_utils_getAccountLimit_tearDown(void);
void UT_utils_getAccountLimit_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}

/**
 * The test case checks the correct behaviour of the "getAccountLimit" function for a STANDARD account type.
 *
 * \field{Test Specification}
 * 1. Define AccountType as STANDARD.
 * 2. Function getAccountLimit is called with parameter
 *    *type = Standard.
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function getAccountLimit returns 1000 for STANDARD accounts.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_01 */
/* CPPTEST_TEST_CASE_CONTEXT int getAccountLimit(AccountType) */
void UT_utils_getAccountLimit_TC_01()
{
    AccountType type = STANDARD;
	int _return = getAccountLimit(type);
	CPPTEST_ASSERT_INTEGER_EQUAL(1000, _return);

}
/* CPPTEST_TEST_CASE_END TC_01 */

/**
 * The test case checks the correct behaviour of the "getAccountLimit" function for a PREMIUM account type.
 *
 * \field{Test Specification}
 * 1. Define AccountType as PREMIUM.
 * 2. Function getAccountLimit is called with parameter
 *    *type = Premium.
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function getAccountLimit returns 5000 for PREMIUM accounts.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_02 */
/* CPPTEST_TEST_CASE_CONTEXT int getAccountLimit(AccountType) */
void UT_utils_getAccountLimit_TC_02()
{
	AccountType type = PREMIUM;
	int _return = getAccountLimit(type);
	CPPTEST_ASSERT_INTEGER_EQUAL(5000, _return);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/**
 * The test case checks the correct behaviour of the "getAccountLimit" function for an invalid/unknown account type.
 *
 * \field{Test Specification}
 * 1. Define AccountType as an invalid value (e.g., 3).
  * 2. Function getAccountLimit is called with parameter
 *    *type = 3 (Unknown).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function getAccountLimit returns -1 for unknown account types.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_03 */
/* CPPTEST_TEST_CASE_CONTEXT int getAccountLimit(AccountType) */
void UT_utils_getAccountLimit_TC_03()
{
	AccountType type = (AccountType) 3;
	int _return = getAccountLimit(type);
	CPPTEST_ASSERT_INTEGER_EQUAL(-1, _return);
}
/* CPPTEST_TEST_CASE_END TC_03 */
