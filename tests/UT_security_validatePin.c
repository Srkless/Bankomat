#include "cpptest.h"
/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("../src/security.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("../src/security.c");

EXTERN_C_LINKAGE void UT_security_validatePin_testSuiteBegin(void);
EXTERN_C_LINKAGE int UT_security_validatePin_callTest(const char*);

CPPTEST_TEST_SUITE(UT_security_validatePin);
        CPPTEST_TEST_SUITE_SETUP(UT_security_validatePin_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(UT_security_validatePin_testSuiteTearDown);
CPPTEST_TEST(UT_security_validatePin_TC_01);
CPPTEST_TEST(UT_security_validatePin_TC_02);
CPPTEST_TEST(UT_security_validatePin_TC_03);
CPPTEST_TEST(UT_security_validatePin_TC_04);
CPPTEST_TEST_SUITE_END();
        

void UT_security_validatePin_TC_01(void);
void UT_security_validatePin_TC_02(void);
void UT_security_validatePin_TC_03(void);
void UT_security_validatePin_TC_04(void);
CPPTEST_TEST_SUITE_REGISTRATION(UT_security_validatePin);

void UT_security_validatePin_testSuiteSetUp(void);
void UT_security_validatePin_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void UT_security_validatePin_testSuiteTearDown(void);
void UT_security_validatePin_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void UT_security_validatePin_setUp(void);
void UT_security_validatePin_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_security_validatePin_tearDown(void);
void UT_security_validatePin_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}

/* CPPTEST_TEST_CASE_BEGIN TC_01 */
void UT_security_validatePin_TC_01()
{
	char pinBuffer[5] = {0};
	Status result = validatePin(pinBuffer, "123456");
	CPPTEST_ASSERT_EQUAL(STATUS_PIN_INVALID, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("PIN mora imati tacno 4 cifre.\n", result.message);
	CPPTEST_ASSERT_CSTR_EQUAL("", pinBuffer);
}
/* CPPTEST_TEST_CASE_END TC_01 */

/* CPPTEST_TEST_CASE_BEGIN TC_02 */
void UT_security_validatePin_TC_02()
{
	char pinBuffer[5] = {0};
	Status result = validatePin(pinBuffer, "123");
	CPPTEST_ASSERT_EQUAL(STATUS_PIN_INVALID, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("PIN mora imati tacno 4 cifre.\n", result.message);
	CPPTEST_ASSERT_CSTR_EQUAL("", pinBuffer);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/* CPPTEST_TEST_CASE_BEGIN TC_03 */
void UT_security_validatePin_TC_03()
{
	char pinBuffer[5] = {0};
	Status result = validatePin(pinBuffer, "1fg2");
	CPPTEST_ASSERT_EQUAL(STATUS_PIN_INVALID, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("PIN smije sadrzavati samo cifre.\n", result.message);
	CPPTEST_ASSERT_CSTR_EQUAL("", pinBuffer);
}
/* CPPTEST_TEST_CASE_END TC_03 */

/* CPPTEST_TEST_CASE_BEGIN TC_04 */
void UT_security_validatePin_TC_04()
{
	char pinBuffer[5] = {0};
	Status result = validatePin(pinBuffer, "1234");
	CPPTEST_ASSERT_EQUAL(STATUS_OK, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Validacija pina uspjesna.\n", result.message);
	CPPTEST_ASSERT_CSTR_EQUAL("1234", pinBuffer);
}
/* CPPTEST_TEST_CASE_END TC_04 */
