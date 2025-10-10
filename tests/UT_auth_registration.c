#include "cpptest.h"

/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("../src/auth.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("../src/auth.c");

EXTERN_C_LINKAGE void UT_auth_registration_testSuiteBegin(void);
EXTERN_C_LINKAGE int UT_auth_registration_callTest(const char*);

CPPTEST_TEST_SUITE(UT_auth_registration);
        CPPTEST_TEST_SUITE_SETUP(UT_auth_registration_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(UT_auth_registration_testSuiteTearDown);
CPPTEST_TEST(UT_auth_registration_TC_01);
CPPTEST_TEST(UT_auth_registration_TC_02);
CPPTEST_TEST(UT_auth_registration_TC_03);
CPPTEST_TEST_SUITE_END();
        

void UT_auth_registration_TC_01(void);
void UT_auth_registration_TC_02(void);
void UT_auth_registration_TC_03(void);
CPPTEST_TEST_SUITE_REGISTRATION(UT_auth_registration);

void UT_auth_registration_testSuiteSetUp(void);
void UT_auth_registration_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void UT_auth_registration_testSuiteTearDown(void);
void UT_auth_registration_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void UT_auth_registration_setUp(void);
void UT_auth_registration_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_auth_registration_tearDown(void);
void UT_auth_registration_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}

void CppTest_StubCallback_registration_fopen_00(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	CPPTEST_ASSERT_EQUAL("users.txt", _Filename);
	CPPTEST_ASSERT_EQUAL("a", _Mode);
	*__return = NULL;
}
void CppTest_StubCallback_registration_fopen_01(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	CPPTEST_ASSERT_EQUAL("users.txt", _Filename);
	CPPTEST_ASSERT_EQUAL("a", _Mode);
	FILE f = {._cnt = 1};
	FILE *fp = &f;
	*__return = fp;
}

#ifndef CPPTEST_STUB_HASH_PIN_DEFINED
#define CPPTEST_STUB_HASH_PIN_DEFINED
void CppTest_StubCallback_hashPin_00(CppTest_StubCallInfo* stubCallInfo, const char* pinCode, const char* hash){
	CPPTEST_ASSERT_EQUAL("1234", pinCode);
	strcpy(hash, "dummyHash");
}
#endif


/**
 * The test case checks the behavior of the "register" function when the users file cannot be opened.
 * \field{Test Specification}
 * 1. Function fopen is stubbed to return a NULL (simulate error opening file).
 * 2. Function hashPin is stubbed to return "dummyHash"
 * 3. Function fclose is stubbed to return 0, file is successfully closed
 * 4. Function fprintf is stubbed to return 0
 * 5. Function register is called with parameters
 *    *number = 1234, *pin = "1234", *accountType = 1 (Standard)
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function fopen is called once
 * 2. Function hashPin is not called
 * 3. Function fclose is not called
 * 4. Function fprintf is not called
 * 5. Function registration returns code which is equal STATUS_FILE_ERROR with proper message
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_01 */
/* CPPTEST_TEST_CASE_CONTEXT Status* registration(int, char*, int) */
void UT_auth_registration_TC_01()
{
	CPPTEST_EXPECT_NCALLS("fopen", 1);
	CPPTEST_EXPECT_NCALLS("hashPin", 0);
	CPPTEST_EXPECT_NCALLS("fclose", 0);
	CPPTEST_EXPECT_NCALLS("fprintf", 0);
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_00);
	Status result = registration(1234, "1234", 1);

	CPPTEST_ASSERT_EQUAL(STATUS_FILE_ERROR, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Greska pri citanju iz fajla.\n", result.message);
}



/* CPPTEST_TEST_CASE_END TC_01 */

/**
 * The test case checks the behavior of the "register" function when the users file is opened successfully.
 * \field{Test Specification}
 * 1. Function fopen is stubbed to return a valid file pointer
 * 2. Function hashPin is stubbed to return "dummyHash"
 * 3. Function fclose is stubbed to return 0, file is successfully closed
 * 4. Function fprintf is stubbed to return 0
 * 5. Function register is called with parameters
 *    *number = 1234, *pin = "1234", *accountType = 1 (Standard)
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function fopen is called once
 * 2. Function hashPin is called once
 * 3. Function fclose is called once
 * 4. Function fprintf is called once
 * 5. Function registration returns code which is equal STATUS_OK with proper message
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_02 */
/* CPPTEST_TEST_CASE_CONTEXT Status registration(int, char*, int) */
void UT_auth_registration_TC_02()
{
	CPPTEST_EXPECT_NCALLS("fopen", 1);
	CPPTEST_EXPECT_NCALLS("hashPin", 1);
	CPPTEST_EXPECT_NCALLS("fclose", 1);
	CPPTEST_EXPECT_NCALLS("fprintf", 1);
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("hashPin", &CppTest_StubCallback_hashPin_00);
	Status result = registration(1234, "1234", 1);

	CPPTEST_ASSERT_EQUAL(STATUS_OK, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Uspjesna registracija korisnika!\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/* CPPTEST_TEST_CASE_BEGIN TC_03 */
/**
 * The test case checks the behavior of the "register" function when the users file is opened successfully.
 * \field{Test Specification}
 * 1. Function fopen is stubbed to return a valid file pointer
 * 2. Function hashPin is stubbed to return "dummyHash"
 * 3. Function fclose is stubbed to return 0, file is successfully closed
 * 4. Function fprintf is stubbed to return 0
 * 5. Function register is called with parameters
 *    *number = 1234, *pin = "1234", *accountType = 2 (Premium)
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function fopen is called once
 * 2. Function hashPin is called once
 * 3. Function fclose is called once
 * 4. Function fprintf is called once
 * 5. Function registration returns code which is equal STATUS_OK with proper message
 * \endfield
 */
/* CPPTEST_TEST_CASE_CONTEXT Status registration(int, char*, int) */
void UT_auth_registration_TC_03()
{
	CPPTEST_EXPECT_NCALLS("fopen", 1);
	CPPTEST_EXPECT_NCALLS("hashPin", 1);
	CPPTEST_EXPECT_NCALLS("fclose", 1);
	CPPTEST_EXPECT_NCALLS("fprintf", 1);
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("hashPin", &CppTest_StubCallback_hashPin_00);
	Status result = registration(1234, "1234", 2);

	CPPTEST_ASSERT_EQUAL(STATUS_OK, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Uspjesna registracija korisnika!\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_03 */
