#include "cpptest.h"

/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("../src/account.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("../src/account.c");

EXTERN_C_LINKAGE void UT_account_generateAccountNumber_testSuiteBegin(void);
EXTERN_C_LINKAGE int UT_account_generateAccountNumber_callTest(const char*);

CPPTEST_TEST_SUITE(UT_account_generateAccountNumber);
        CPPTEST_TEST_SUITE_SETUP(UT_account_generateAccountNumber_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(UT_account_generateAccountNumber_testSuiteTearDown);
CPPTEST_TEST(UT_account_generateAccountNumber_TC_01);
CPPTEST_TEST(UT_account_generateAccountNumber_TC_02);
CPPTEST_TEST(UT_account_generateAccountNumber_TC_03);
CPPTEST_TEST_SUITE_END();
        

void UT_account_generateAccountNumber_TC_01(void);
void UT_account_generateAccountNumber_TC_02(void);
void UT_account_generateAccountNumber_TC_03(void);
CPPTEST_TEST_SUITE_REGISTRATION(UT_account_generateAccountNumber);

void UT_account_generateAccountNumber_testSuiteSetUp(void);
void UT_account_generateAccountNumber_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void UT_account_generateAccountNumber_testSuiteTearDown(void);
void UT_account_generateAccountNumber_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void UT_account_generateAccountNumber_setUp(void);
void UT_account_generateAccountNumber_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_account_generateAccountNumber_tearDown(void);
void UT_account_generateAccountNumber_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}

void CppTest_StubCallback_isAccountExists_00(CppTest_StubCallInfo* stubCallInfo, Status* __return, int accountNumber){
	Status status = {0};
	status.code = STATUS_ERROR;
	*__return = status;
}

void CppTest_StubCallback_isAccountExists_01(CppTest_StubCallInfo* stubCallInfo, Status* __return, int accountNumber){
	Status status = {0};
	status.code = STATUS_OK;
	*__return = status;
}

/**
 * The test case checks the correct behavior of the "generateAccountNumber" function in case when the maximum number of attempts (MAX_ATTEMPTS) is reached.
 *
 * \field{Test Specification}
 * 1. Set the global variable MAX_ATTEMPTS = 1 to simulate scenario where only the maximum number of attempts to generate an account number has been reached.
 * 2. Call the generateAccountNumber function without any stubbing of internal dependencies.
 * 3. Capture the returned Status result.
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function generateAccountNumber returns status code STATUS_MAX_ATTEMPTS_REACHED.
 * 2. No account number is generated since the maximum number of attempts has already been consumed.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_01 */
/* CPPTEST_TEST_CASE_CONTEXT Status generateAccountNumber(void) */
void UT_account_generateAccountNumber_TC_01()
{
	{
		MAX_ATTEMPTS = 1;
	}
	Status result = generateAccountNumber();
	CPPTEST_ASSERT_EQUAL(STATUS_MAX_ATTEMPTS_REACHED, result.code);
}
/* CPPTEST_TEST_CASE_END TC_01 */

/**
 * The test case checks the correct behavior of the "generateAccountNumber" function in case when the maximum number of attempts to generate a unique account number is reached.
 *
 * \field{Test Specification}
 * 1. Stub the function isAccountExists to always return true (account already exists).
 * 2. Set the global variable MAX_ATTEMPTS = 10 to allow 10 generation attempts.
 * 3. Call the generateAccountNumber function.
 * 4. Capture the returned Status result.
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function generateAccountNumber returns status code STATUS_MAX_ATTEMPTS_REACHED.
 * 2. Function isAccountExists is called exactly 10 times (once for each attempt).
 * 3. No valid account number is generated since all attempts fail.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_02 */
/* CPPTEST_TEST_CASE_CONTEXT Status generateAccountNumber(void) */
void UT_account_generateAccountNumber_TC_02()
{
	CPPTEST_REGISTER_STUB_CALLBACK("isAccountExists", &CppTest_StubCallback_isAccountExists_01);
	{
		MAX_ATTEMPTS = 10;
	}
	Status result = generateAccountNumber();
	CPPTEST_ASSERT_EQUAL(STATUS_MAX_ATTEMPTS_REACHED, result.code);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/**
 * The test case checks the correct behavior of the "generateAccountNumber" function when a unique account number is successfully generated before reaching the maximum number of attempts.
 *
 * \field{Test Specification}
 * 1. Stub the function isAccountExists to always return false (account does not exist).
 * 2. Set the global variable MAX_ATTEMPTS = 10 to allow 10 generation attempts.
 * 3. Call the generateAccountNumber function.
 * 4. Capture the returned Status result.
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function generateAccountNumber returns status code STATUS_OK.
 * 2. Function isAccountExists is called once, because the generated account number is valid immediately.
 * 3. A valid account number is produced and stored.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_03 */
/* CPPTEST_TEST_CASE_CONTEXT Status generateAccountNumber(void) */
void UT_account_generateAccountNumber_TC_03()
{
	CPPTEST_REGISTER_STUB_CALLBACK("isAccountExists", &CppTest_StubCallback_isAccountExists_00);
		{
			MAX_ATTEMPTS = 10;
		}
		Status result = generateAccountNumber();
		CPPTEST_ASSERT_EQUAL(STATUS_OK, result.code);
}
/* CPPTEST_TEST_CASE_END TC_03 */
