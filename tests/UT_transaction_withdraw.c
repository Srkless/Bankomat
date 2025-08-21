#include "cpptest.h"

/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("../src/transaction.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("../src/transaction.c");

EXTERN_C_LINKAGE void UT_transaction_withdraw_testSuiteBegin(void);
EXTERN_C_LINKAGE int UT_transaction_withdraw_callTest(const char*);

CPPTEST_TEST_SUITE(UT_transaction_withdraw);
        CPPTEST_TEST_SUITE_SETUP(UT_transaction_withdraw_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(UT_transaction_withdraw_testSuiteTearDown);
CPPTEST_TEST(UT_transaction_withdraw_TC_01);
CPPTEST_TEST(UT_transaction_withdraw_TC_02);
CPPTEST_TEST(UT_transaction_withdraw_TC_03);
CPPTEST_TEST(UT_transaction_withdraw_TC_04);
CPPTEST_TEST(UT_transaction_withdraw_TC_05);
CPPTEST_TEST(UT_transaction_withdraw_TC_06);
CPPTEST_TEST_SUITE_END();
        

void UT_transaction_withdraw_TC_01(void);
void UT_transaction_withdraw_TC_02(void);
void UT_transaction_withdraw_TC_03(void);
void UT_transaction_withdraw_TC_04(void);
void UT_transaction_withdraw_TC_05(void);
void UT_transaction_withdraw_TC_06(void);
CPPTEST_TEST_SUITE_REGISTRATION(UT_transaction_withdraw);

void UT_transaction_withdraw_testSuiteSetUp(void);
void UT_transaction_withdraw_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void UT_transaction_withdraw_testSuiteTearDown(void);
void UT_transaction_withdraw_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void UT_transaction_withdraw_setUp(void);
void UT_transaction_withdraw_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_transaction_withdraw_tearDown(void);
void UT_transaction_withdraw_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}

void CppTest_StubCallback_getAccountLimit_00(CppTest_StubCallInfo* stubCallInfo, int* __return, AccountType type){
	*__return = -1;
}

void CppTest_StubCallback_getAccountLimit_01(CppTest_StubCallInfo* stubCallInfo, int* __return, AccountType type){
	*__return = 1000;
}


/* CPPTEST_TEST_CASE_BEGIN TC_01 */
void UT_transaction_withdraw_TC_01()
{
	Account* account = NULL;
	Status result = withdraw(account, 20);
	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_NOT_EXISTS, result.code);

}
/* CPPTEST_TEST_CASE_END TC_01 */

/* CPPTEST_TEST_CASE_BEGIN TC_02 */
void UT_transaction_withdraw_TC_02()
{
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_00);
	Account account = {.accountNumber = 1234, .balance = 0};
	Status result = withdraw(&account, 20);
	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_TYPE_INVALID, result.code);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/* CPPTEST_TEST_CASE_BEGIN TC_03 */
void UT_transaction_withdraw_TC_03()
{
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
	Account account = {.accountNumber = 1234, .balance = 0};
	Status result = withdraw(&account, 5);
	CPPTEST_ASSERT_EQUAL(STATUS_WRONG_VALUE, result.code);
}
/* CPPTEST_TEST_CASE_END TC_03 */

/* CPPTEST_TEST_CASE_BEGIN TC_04 */
void UT_transaction_withdraw_TC_04()
{
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
	Account account = {.accountNumber = 1234, .balance = 0};
	Status result = withdraw(&account, 15);
	CPPTEST_ASSERT_EQUAL(STATUS_WRONG_VALUE, result.code);
}
/* CPPTEST_TEST_CASE_END TC_04 */

/* CPPTEST_TEST_CASE_BEGIN TC_05 */
void UT_transaction_withdraw_TC_05()
{
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
	Account account = {.accountNumber = 1234, .balance = 0};
	Status result = withdraw(&account, 20);
	CPPTEST_ASSERT_EQUAL(STATUS_INSUFFICIENT_MONEY, result.code);
}
/* CPPTEST_TEST_CASE_END TC_05 */

/* CPPTEST_TEST_CASE_BEGIN TC_06 */
void UT_transaction_withdraw_TC_06()
{
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
		int accountBalance = 100;
		int accountWithdrawMoney = 50;
		Account account = {.accountNumber = 1234, .balance = accountBalance};
		Status result = withdraw(&account, accountWithdrawMoney);
		CPPTEST_ASSERT_EQUAL(STATUS_OK, result.code);
		CPPTEST_ASSERT_EQUAL(account.balance, accountBalance - accountWithdrawMoney);
}
/* CPPTEST_TEST_CASE_END TC_06 */
