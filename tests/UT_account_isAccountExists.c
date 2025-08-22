#include "cpptest.h"

/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("../src/account.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("../src/account.c");

EXTERN_C_LINKAGE void UT_account_isAccountExists_testSuiteBegin(void);
EXTERN_C_LINKAGE int UT_account_isAccountExists_callTest(const char*);

CPPTEST_TEST_SUITE(UT_account_isAccountExists);
        CPPTEST_TEST_SUITE_SETUP(UT_account_isAccountExists_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(UT_account_isAccountExists_testSuiteTearDown);
CPPTEST_TEST(UT_account_isAccountExists_TC_01);
CPPTEST_TEST(UT_account_isAccountExists_TC_02);
CPPTEST_TEST(UT_account_isAccountExists_TC_03);
CPPTEST_TEST_SUITE_END();
        
static int mock_index = 0;
static const char* mock_data[] = {
    "123|hash123|1|500\n",
    "456|hash456|2|1000\n",
    NULL
};


void UT_account_isAccountExists_TC_01(void);
void UT_account_isAccountExists_TC_02(void);
void UT_account_isAccountExists_TC_03(void);
CPPTEST_TEST_SUITE_REGISTRATION(UT_account_isAccountExists);

void UT_account_isAccountExists_testSuiteSetUp(void);
void UT_account_isAccountExists_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void UT_account_isAccountExists_testSuiteTearDown(void);
void UT_account_isAccountExists_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void UT_account_isAccountExists_setUp(void);
void UT_account_isAccountExists_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
	mock_index = 0;
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_account_isAccountExists_tearDown(void);
void UT_account_isAccountExists_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}

void CppTest_StubCallback_fopen_00(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	*__return = NULL;
}

void CppTest_StubCallback_fopen_01(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	FILE f = {._cnt = 1};
	FILE *fp = &f;
	*__return = fp;
}

void CppTest_StubCallback_fgets_00(CppTest_StubCallInfo* stubCallInfo, char ** __return, char * _Buf, int _MaxCount, FILE * _File){
	*__return = 0;
}

void CppTest_StubCallback_fgets_01(CppTest_StubCallInfo* stubCallInfo, char ** __return, char * _Buf, int _MaxCount, FILE * _File){
	if (mock_data[mock_index] == NULL) {
	        *__return = NULL;
	        return;
	    }

	    strcpy(_Buf, mock_data[mock_index]);
	    mock_index++;

	    *__return = _Buf;
}
/**
 * The test case checks the behavior of the "isAccountExists" function when the users file cannot be opened.
 *
 * \field{Test Specification}
 * 1. Stub fopen to always return NULL (simulate error opening file).
 * 2. Call isAccountExists with an account number (123456).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function isAccountExists returns STATUS_FILE_ERROR.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_01 */
/* CPPTEST_TEST_CASE_CONTEXT Status isAccountExists(int) */
void UT_account_isAccountExists_TC_01()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_00);

	Status result = isAccountExists(123456);
	CPPTEST_ASSERT_EQUAL(STATUS_FILE_ERROR, result.code);
}
/* CPPTEST_TEST_CASE_END TC_01 */

/**
 * The test case checks the behavior of the "isAccountExists" function when the file is opened successfully but contains no matching account number.
 *
 * \field{Test Specification}
 * 1. Stub fopen to return a valid file pointer.
 * 2. Call isAccountExists with an account number (123456).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function isAccountExists returns STATUS_ACCOUNT_NOT_EXISTS.
 * 2. File is opened and closed correctly.
 * 3. No account number is matched in the file.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_02 */
/* CPPTEST_TEST_CASE_CONTEXT Status isAccountExists(int) */
void UT_account_isAccountExists_TC_02()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_00);

	Status result = isAccountExists(123456);
	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_NOT_EXISTS, result.code);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/**
 * The test case checks the behavior of the "isAccountExists" function when the file is opened successfully and the account number exists in the file.
 *
 * \field{Test Specification}
 * 1. Stub fopen to return a valid file pointer.
 * 2. Stub fgets to return mock data lines containing the test account number.
 * 2. Call isAccountExists with an account number (123).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function isAccountExists returns STATUS_OK.
 * 2. File is opened, read and closed correctly.
 * 3. Account number 123 is found in the mock data
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_03 */
/* CPPTEST_TEST_CASE_CONTEXT Status isAccountExists(int) */
void UT_account_isAccountExists_TC_03()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);

	Status result = isAccountExists(123);
	CPPTEST_ASSERT_EQUAL(STATUS_OK, result.code);
}
/* CPPTEST_TEST_CASE_END TC_03 */
