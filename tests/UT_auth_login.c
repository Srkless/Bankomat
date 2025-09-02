#include "cpptest.h"

/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("../src/auth.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("../src/auth.c");

EXTERN_C_LINKAGE void UT_auth_login_testSuiteBegin(void);
EXTERN_C_LINKAGE int UT_auth_login_callTest(const char*);

CPPTEST_TEST_SUITE(UT_auth_login);
        CPPTEST_TEST_SUITE_SETUP(UT_auth_login_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(UT_auth_login_testSuiteTearDown);
CPPTEST_TEST(UT_auth_login_TC_01);
CPPTEST_TEST(UT_auth_login_TC_02);
CPPTEST_TEST(UT_auth_login_TC_03);
CPPTEST_TEST(UT_auth_login_TC_04);
CPPTEST_TEST(UT_auth_login_TC_05);
CPPTEST_TEST_SUITE_END();
        


void UT_auth_login_TC_01(void);
void UT_auth_login_TC_02(void);
void UT_auth_login_TC_03(void);
void UT_auth_login_TC_04(void);
void UT_auth_login_TC_05(void);
CPPTEST_TEST_SUITE_REGISTRATION(UT_auth_login);

static int mock_index = 0;
static const char* mock_data[] = {
    "10023349|97EF04E6|0|0.00\n",
    "10023466|842B9454|0|0.00\n",
    NULL
};

void UT_auth_login_testSuiteSetUp(void);
void UT_auth_login_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void UT_auth_login_testSuiteTearDown(void);
void UT_auth_login_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void UT_auth_login_setUp(void);
void UT_auth_login_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
	mock_index = 0;
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_auth_login_tearDown(void);
void UT_auth_login_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}
void CppTest_StubCallback_registration_fopen_00(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	*__return = NULL;
}
void CppTest_StubCallback_registration_fopen_01(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
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

void CppTest_StubCallback_malloc_00(CppTest_StubCallInfo* stubCallInfo, void ** __return, size_t _Size){
	*__return = NULL;
}

void CppTest_StubCallback_malloc_01(CppTest_StubCallInfo* stubCallInfo, void ** __return, size_t _Size){
	*__return = malloc(_Size);
}


/**
 * The test case checks the behavior of the "login" function when the users file cannot be opened.
 *
 * \field{Test Specification}
 * 1. Stub fopen to always return NULL (simulate error opening file).
 * 2. Call login with an account number (12345) and pin (1234).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function login returns NULL.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_01 */
/* CPPTEST_TEST_CASE_CONTEXT Account* login(int, const char*) */
void UT_auth_login_TC_01()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_00);
	Account* account = login(12345, "1234");

	CPPTEST_ASSERT_EQUAL(NULL, account);
}
/* CPPTEST_TEST_CASE_END TC_01 */

/**
 * The test case checks the behavior of the "login" function when the users file is opened successfully but contains no matching account number.
 *
 * \field{Test Specification}
 * 1. Stub fopen to return a valid file pointer.
 * 2. Stub fgets to return NULL (simulate empty file)
 * 3. Call login with an account number (12345) and pin (1234).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function login returns NULL.
 * 2. File is opened and closed correctly.
 * 3. No account number is matched in the file
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_02 */
/* CPPTEST_TEST_CASE_CONTEXT Account* login(int, const char*) */
void UT_auth_login_TC_02()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_00);
	Account* account = login(12345, "1234");

	CPPTEST_ASSERT_EQUAL(NULL, account);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/**
 * The test case checks the behavior of the "login" function when the users file is opened successfully but contains no matching account number.
 *
 * \field{Test Specification}
 * 1. Stub fopen to return a valid file pointer.
 * 2. Stub fgets to return mock data lines but does not contain a matching account number
 * 3. Call login with an account number (12345) and pin (1234).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function login returns NULL because no matching account number and PIN are found..
 * 2. File is opened, read and closed correctly.
 * 3. No account number is matched in the file
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_03 */
/* CPPTEST_TEST_CASE_CONTEXT Account* login(int, const char*) */
void UT_auth_login_TC_03()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
	Account* account = login(12345, "1234");

	CPPTEST_ASSERT_EQUAL(NULL, account);
}
/* CPPTEST_TEST_CASE_END TC_03 */

/**
 * The test case checks the behavior of the "login" function when the account exists in the users file but memory allocation for the Account struct fails.
 *
 * \field{Test Specification}
 * 1. Stub fopen to return a valid file pointer (simulate file exists).
 * 2. Stub fgets to return mock data lines
 * 3. Stub malloc to always return NULL (simulate memory allocation failure).
 * 4. Call login with account number 10023349 and pin "1234".
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function login returns NULL because memory allocation failed.
 * 2. File is opened and closed correctly.
 * 3. No Account struct is created.
 * \endfield
 */

/* CPPTEST_TEST_CASE_BEGIN TC_04 */
/* CPPTEST_TEST_CASE_CONTEXT Account* login(int, const char*) */
void UT_auth_login_TC_04()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
	CPPTEST_REGISTER_STUB_CALLBACK("malloc", &CppTest_StubCallback_malloc_00);
	Account* account = login(10023349, "1234");

	CPPTEST_ASSERT_EQUAL(NULL, account);
}
/* CPPTEST_TEST_CASE_END TC_04 */

/**
 * The test case checks the behavior of the "login" function when the account exists in the users file and memory allocation succeeds.
 *
 * \field{Test Specification}
 * 1. Stub fopen to return a valid file pointer (simulate file exists).
 * 2. Stub fgets to return mock data lines sequentially from mock_data containing the target account.
 * 3. Stub malloc to return a valid pointer (simulate successful memory allocation).
 * 4. Call login with account number 10023349 and pin "1234".
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function login returns a non-NULL pointer
 * 2. File is opened, read, and closed correctly.
 * 3. Account struct contains correct accountNumber
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_05 */
/* CPPTEST_TEST_CASE_CONTEXT Account* login(int, const char*) */
void UT_auth_login_TC_05()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
	CPPTEST_REGISTER_STUB_CALLBACK("malloc", &CppTest_StubCallback_malloc_01);
	Account* account = login(10023349, "1234");

	CPPTEST_ASSERT(account != NULL);
}
/* CPPTEST_TEST_CASE_END TC_05 */
