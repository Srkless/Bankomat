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

/**
 * The test case checks the correct behaviour of the "withdraw" function when the provided Account pointer is NULL.
 *
 * \field{Test Specification}
 * 1. Define account pointer as NULL.
 * 2. Call withdraw(account, 20).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function withdraw returns STATUS_ACCOUNT_NOT_EXISTS.
 * 2. No balance change occurs.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_01 */
/* CPPTEST_TEST_CASE_CONTEXT Status withdraw(Account*, int) */
void UT_transaction_withdraw_TC_01()
{
	Account* account = NULL;
	Status result = withdraw(account, 20);
	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_NOT_EXISTS, result.code);

}
/* CPPTEST_TEST_CASE_END TC_01 */

/**
 * The test case checks the behaviour of the "withdraw" function when the account type is invalid (getAccountLimit returns -1).
 *
 * \field{Test Specification}
 * 1. Stub getAccountLimit to return -1 (invalid account type).
 * 2. Create an Account struct with balance = 0.
 * 3. Call withdraw(&account, 20).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function withdraw returns STATUS_ACCOUNT_TYPE_INVALID.
 * 2. Account balance remains unchanged.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_02 */
/* CPPTEST_TEST_CASE_CONTEXT Status withdraw(Account*, int) */
void UT_transaction_withdraw_TC_02()
{
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_00);
	Account account = {.accountNumber = 1234, .balance = 0};
	Status result = withdraw(&account, 20);
	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_TYPE_INVALID, result.code);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/**
 * The test case checks the behaviour of the "withdraw" function when the withdrawn amount is below the minimum allowed (less than 10).
 *
 * \field{Test Specification}
 * 1. Stub getAccountLimit to return a valid limit (e.g., 1000).
 * 2. Create an Account struct with balance = 0.
 * 3. Call withdraw(&account, 5).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function withdraw returns STATUS_WRONG_VALUE.
 * 2. Account balance remains unchanged.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_03 */
/* CPPTEST_TEST_CASE_CONTEXT Status withdraw(Account*, int) */
void UT_transaction_withdraw_TC_03()
{
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
	Account account = {.accountNumber = 1234, .balance = 0};
	Status result = withdraw(&account, 5);
	CPPTEST_ASSERT_EQUAL(STATUS_WRONG_VALUE, result.code);
}
/* CPPTEST_TEST_CASE_END TC_03 */

/**
 * The test case checks the behaviour of the "withdraw" function when the withdrawn amount is not divisible by 10.
 *
 * \field{Test Specification}
 * 1. Stub getAccountLimit to return a valid limit (e.g., 1000).
 * 2. Create an Account struct with balance = 0.
 * 3. Call withdraw(&account, 15).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function withdraw returns STATUS_WRONG_VALUE.
 * 2. Account balance remains unchanged.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_04 */
/* CPPTEST_TEST_CASE_CONTEXT Status withdraw(Account*, int) */
void UT_transaction_withdraw_TC_04()
{
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
	Account account = {.accountNumber = 1234, .balance = 0};
	Status result = withdraw(&account, 15);
	CPPTEST_ASSERT_EQUAL(STATUS_WRONG_VALUE, result.code);
}
/* CPPTEST_TEST_CASE_END TC_04 */

/**
 * The test case checks the behaviour of the "withdraw" function when the account does not have enough balance to withdraw the requested amount.
 *
 * \field{Test Specification}
 * 1. Stub getAccountLimit to return a valid limit (e.g., 1000).
 * 2. Create an Account struct with balance = 0.
 * 3. Call withdraw(&account, 20).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function withdraw returns STATUS_INSUFFICIENT_MONEY.
 * 2. Account balance remains unchanged.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_05 */
/* CPPTEST_TEST_CASE_CONTEXT Status withdraw(Account*, int) */
void UT_transaction_withdraw_TC_05()
{
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
	Account account = {.accountNumber = 1234, .balance = 0};
	Status result = withdraw(&account, 20);
	CPPTEST_ASSERT_EQUAL(STATUS_INSUFFICIENT_MONEY, result.code);
}
/* CPPTEST_TEST_CASE_END TC_05 */

/**
 * The test case checks the correct behaviour of the "withdraw" function when the withdrawn amount is valid and the account has sufficient balance.
 *
 * \field{Test Specification}
 * 1. Stub getAccountLimit to return a valid limit (e.g., 1000).
 * 2. Create an Account struct with balance = 100.
 * 3. Call withdraw(&account, 50).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function withdraw returns STATUS_OK.
 * 2. Account balance is decreased correctly (100 - 50 = 50).
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_06 */
/* CPPTEST_TEST_CASE_CONTEXT Status withdraw(Account*, int) */
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
