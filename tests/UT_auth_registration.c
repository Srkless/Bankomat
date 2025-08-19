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
CPPTEST_TEST_SUITE_END();
        

void UT_auth_registration_TC_01(void);
void UT_auth_registration_TC_02(void);
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
	*__return = NULL;
}
void CppTest_StubCallback_registration_fopen_01(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	FILE f = {._cnt = 1};
	FILE *fp = &f;
	*__return = fp;
}


/* CPPTEST_TEST_CASE_BEGIN TC_01 */
void UT_auth_registration_TC_01()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_00);
	Status result = registration(1234, "1234", 1);

	CPPTEST_ASSERT_EQUAL(STATUS_FILE_ERROR, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Greska pri citanju iz fajla.\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_01 */

/* CPPTEST_TEST_CASE_BEGIN TC_02 */
void UT_auth_registration_TC_02()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
	Status result = registration(1234, "1234", 1);

	CPPTEST_ASSERT_EQUAL(STATUS_OK, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Uspjesna registracija korisnika!\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_02 */
