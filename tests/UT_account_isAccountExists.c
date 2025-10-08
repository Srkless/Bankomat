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
static int atoi_next_value = 0;
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
	atoi_next_value = 0;


/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_account_isAccountExists_tearDown(void);
void UT_account_isAccountExists_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}

void CppTest_StubCallback_fopen_00(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){

	CPPTEST_ASSERT_EQUAL("users.txt", _Filename);
	CPPTEST_ASSERT_EQUAL("r", _Mode);
	*__return = NULL;
}

void CppTest_StubCallback_fopen_01(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){

	CPPTEST_ASSERT_EQUAL("users.txt", _Filename);
	CPPTEST_ASSERT_EQUAL("r", _Mode);
	FILE f = {._cnt = 1};
	FILE *fp = &f;
	*__return = fp;
}

void CppTest_StubCallback_fgets_00(CppTest_StubCallInfo* stubCallInfo, char ** __return, char * _Buf, int _MaxCount, FILE * _File){
	CPPTEST_ASSERT(_MaxCount > 0);
	*__return = 0;
}

void CppTest_StubCallback_fgets_01(CppTest_StubCallInfo* stubCallInfo, char ** __return, char * _Buf, int _MaxCount, FILE * _File){
	CPPTEST_ASSERT(_MaxCount > 0);
	if (mock_data[mock_index] == NULL) {
	        *__return = NULL;
	        return;
	    }

	    strcpy(_Buf, mock_data[mock_index]);
	    mock_index++;

	    *__return = _Buf;
}
void CppTest_StubCallback_fclose(CppTest_StubCallInfo* stubCallInfo, int* __return, FILE* _File){
	 * __return = atoi_next_value;

}

void CppTest_StubCallback_atoi(CppTest_StubCallInfo* stubCallInfo, int* __return){

	*__return = atoi_next_value;
}
/**
 * The test case checks the behavior of the "isAccountExists" function when the users file cannot be opened.
 *
 * \field{Test Specification}
 * 1. Stub fopen to always return NULL (simulate error opening file).
 * 2. Function fgets is stubbed to return 0.
 * 3. Function atoi is stubbed to return 0.
 * 4. Function fclose is stubbed to return 0, file is successfully closed
 * 5. Function isAccountExists is called with parameter
 *    *accountNumber = 123456
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function fopen is called once
 * 2. Function fgets is not called
 * 3. Function atoi is not called
 * 4. Function fclose is not called
 * 5. Function isAccountExists returns code which is equal STATUS_FILE_ERROR with proper message
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_01 */
/* CPPTEST_TEST_CASE_CONTEXT Status isAccountExists(int) */
void UT_account_isAccountExists_TC_01()
{
	CPPTEST_EXPECT_NCALLS("fopen", 1);
	CPPTEST_EXPECT_NCALLS("fgets", 0);
	CPPTEST_EXPECT_NCALLS("fclose", 0);
	CPPTEST_EXPECT_NCALLS("atoi", 0);

	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_00);

	Status result = isAccountExists(123456);
	CPPTEST_ASSERT_EQUAL(STATUS_FILE_ERROR, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Greska pri citanju iz fajla.\n", result.message);

}
/* CPPTEST_TEST_CASE_END TC_01 */

/**
 * The test case checks the behavior of the "isAccountExists" function when the file is opened successfully but contains no matching account number.
 *
 * \field{Test Specification}
 * 1. Function fopen is stubbed to return a valid file pointer.
 * 2. Function fgets to return NULL, simulate an empty file
 * 3. Function atoi is stubbed to return 0.
 * 4. Function fclose is stubbed to return 0, file is successfully closed
 * 5. Function isAccountExists is called with parameter
 *    *accountNumber = 123456
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. File is opened and closed correctly.
 * 2. Function fopen is called once
 * 3. Function fgets is called once
 * 4. Function atoi is not called
 * 5. Function fclose is called once
 * 6. Function isAccountExists returns code which is equal STATUS_ACCOUNT_NOT_EXISTS with proper message
 * 7. No account number is matched in the file.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_02 */
/* CPPTEST_TEST_CASE_CONTEXT Status isAccountExists(int) */
void UT_account_isAccountExists_TC_02()
{
	CPPTEST_EXPECT_NCALLS("fopen", 1);
	CPPTEST_EXPECT_NCALLS("fgets", 1);
	CPPTEST_EXPECT_NCALLS("fclose", 1);
	CPPTEST_EXPECT_NCALLS("atoi", 0);
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_00);
	CPPTEST_REGISTER_STUB_CALLBACK("fclose", &CppTest_StubCallback_fclose);

	Status result = isAccountExists(123456);
	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_NOT_EXISTS, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Broj racuna ne postoji.\n", result.message);

}
/* CPPTEST_TEST_CASE_END TC_02 */

/**
 * The test case checks the behavior of the "isAccountExists" function when the file is opened successfully and the account number exists in the file.
 *
 * \field{Test Specification}
 * 1. Function fopen is stubbed to return a valid file pointer.
 * 2. Function fgets is stubbed to return mock data lines containing the test account number.
 * 3. Function atoi is stubbed to return the predefined value (atoi_next_value).
 * 4. Function fclose is stubbed to return 0, file is successfully closed
  * 5. Function isAccountExists is called with parameter
 *    *accountNumber = 123
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. File is opened, read and closed correctly.
 * 2. Function fopen is called once
 * 3. Function fgets is called once
 * 4. Function atoi is called once
 * 5. Function fclose is called once
 * 6. Function isAccountExists returns code which is equal STATUS_OK with proper message
 * 7. Account number 123 is found in the mock data
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_03 */
/* CPPTEST_TEST_CASE_CONTEXT Status isAccountExists(int) */
void UT_account_isAccountExists_TC_03()
{
	CPPTEST_EXPECT_NCALLS("fopen", 1);
	CPPTEST_EXPECT_NCALLS("fgets", 1);
	CPPTEST_EXPECT_NCALLS("fclose", 1);
	CPPTEST_EXPECT_NCALLS("atoi", 1);
	atoi_next_value = 123;
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fclose", &CppTest_StubCallback_fclose);
	CPPTEST_REGISTER_STUB_CALLBACK("atoi", &CppTest_StubCallback_atoi);
	Status result = isAccountExists(123);

	CPPTEST_ASSERT_EQUAL(STATUS_OK, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Broj racuna uspjesno pronadjen.\n", result.message);

}
/* CPPTEST_TEST_CASE_END TC_03 */
