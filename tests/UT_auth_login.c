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

/* CPPTEST_TEST_CASE_BEGIN TC_01 */
void UT_auth_login_TC_01()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_00);
	Account* account = login(12345, "1234");

	CPPTEST_ASSERT_EQUAL(NULL, account);
}
/* CPPTEST_TEST_CASE_END TC_01 */

/* CPPTEST_TEST_CASE_BEGIN TC_02 */
void UT_auth_login_TC_02()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_00);
		Account* account = login(12345, "1234");

		CPPTEST_ASSERT_EQUAL(NULL, account);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/* CPPTEST_TEST_CASE_BEGIN TC_03 */
void UT_auth_login_TC_03()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
	Account* account = login(12345, "1234");

	CPPTEST_ASSERT_EQUAL(NULL, account);
}
/* CPPTEST_TEST_CASE_END TC_03 */

/* CPPTEST_TEST_CASE_BEGIN TC_04 */
void UT_auth_login_TC_04()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
	CPPTEST_REGISTER_STUB_CALLBACK("malloc", &CppTest_StubCallback_malloc_00);
	Account* account = login(10023349, "1234");

	CPPTEST_ASSERT_EQUAL(NULL, account);
}
/* CPPTEST_TEST_CASE_END TC_04 */

/* CPPTEST_TEST_CASE_BEGIN TC_05 */
void UT_auth_login_TC_05()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_registration_fopen_01);
		CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
		CPPTEST_REGISTER_STUB_CALLBACK("malloc", &CppTest_StubCallback_malloc_01);
		Account* account = login(10023349, "1234");

		CPPTEST_ASSERT(account != NULL);
}
/* CPPTEST_TEST_CASE_END TC_05 */
