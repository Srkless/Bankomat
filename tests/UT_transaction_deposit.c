#include "cpptest.h"

/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("../src/transaction.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("../src/transaction.c");

EXTERN_C_LINKAGE void UT_transaction_deposit_testSuiteBegin(void);
EXTERN_C_LINKAGE int UT_transaction_deposit_callTest(const char*);

CPPTEST_TEST_SUITE(UT_transaction_deposit);
        CPPTEST_TEST_SUITE_SETUP(UT_transaction_deposit_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(UT_transaction_deposit_testSuiteTearDown);
CPPTEST_TEST(UT_transaction_deposit_TC_01);
CPPTEST_TEST(UT_transaction_deposit_TC_02);
CPPTEST_TEST(UT_transaction_deposit_TC_03);
CPPTEST_TEST(UT_transaction_deposit_TC_04);
CPPTEST_TEST(UT_transaction_deposit_TC_05);
CPPTEST_TEST(UT_transaction_deposit_TC_06);
CPPTEST_TEST_SUITE_END();
        

void UT_transaction_deposit_TC_01(void);
void UT_transaction_deposit_TC_02(void);
void UT_transaction_deposit_TC_03(void);
void UT_transaction_deposit_TC_04(void);
void UT_transaction_deposit_TC_05(void);
void UT_transaction_deposit_TC_06(void);
CPPTEST_TEST_SUITE_REGISTRATION(UT_transaction_deposit);

void UT_transaction_deposit_testSuiteSetUp(void);
void UT_transaction_deposit_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void UT_transaction_deposit_testSuiteTearDown(void);
void UT_transaction_deposit_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void UT_transaction_deposit_setUp(void);
void UT_transaction_deposit_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_transaction_deposit_tearDown(void);
void UT_transaction_deposit_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}

void CppTest_StubCallback_getAccountLimit_00(CppTest_StubCallInfo* stubCallInfo, int* __return, AccountType type){
	CPPTEST_ASSERT_EQUAL(type, STANDARD);
	*__return = -1;
}

void CppTest_StubCallback_getAccountLimit_01(CppTest_StubCallInfo* stubCallInfo, int* __return, AccountType type){
	CPPTEST_ASSERT_EQUAL(type, STANDARD);
	*__return = 1000;
}
void CppTest_StubCallback_updateAccountInFile(CppTest_StubCallInfo* stubCallInfo, Status* __return, Account * account){
	CPPTEST_ASSERT_EQUAL(account->accountNumber, 1234);
	__return = STATUS_OK;
}

/**
 * The test case checks the correct behaviour of the "deposit" function
 * when the provided Account pointer is NULL.
 *
 * \field{Test Specification}
 * 1. Define account pointer as NULL.
 * 2. Call deposit(account, 20).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function deposit returns STATUS_ACCOUNT_NOT_EXISTS.
 * 2. No balance update is performed.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_01 */
/* CPPTEST_TEST_CASE_CONTEXT Status deposit(Account*, int) */
void UT_transaction_deposit_TC_01()
{
	CPPTEST_EXPECT_NCALLS("getAccountLimit", 0);
	CPPTEST_EXPECT_NCALLS("updateAccountInFile", 0);
	Account* account = NULL;
    Status result = deposit(account, 20);
    CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_NOT_EXISTS, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Account nije pronadjen\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_01 */

/**
 * The test case checks the behaviour of the "deposit" function when the account type is invalid (getAccountLimit returns -1).
 *
 * \field{Test Specification}
 * 1. Stub getAccountLimit to return -1 (invalid account type).
 * 2. Create an Account struct with balance = 0.
 * 3. Call deposit(&account, 20).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function deposit returns STATUS_ACCOUNT_TYPE_INVALID.
 * 2. Account balance remains unchanged.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_02 */
/* CPPTEST_TEST_CASE_CONTEXT Status deposit(Account*, int) */
void UT_transaction_deposit_TC_02()
{
	CPPTEST_EXPECT_NCALLS("getAccountLimit", 1);
	CPPTEST_EXPECT_NCALLS("updateAccountInFile", 0);
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_00);
	Account account = {.accountNumber = 1234, .balance = 0,.type = STANDARD};
	Status result = deposit(&account, 20);
	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_TYPE_INVALID, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Account type nije pronadjen\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/**
 * The test case checks the behaviour of the "deposit" function when the deposited amount is below the minimum allowed (less than 10).
 *
 * \field{Test Specification}
 * 1. Stub getAccountLimit to return a valid limit (e.g., 1000).
 * 2. Create an Account struct with balance = 0.
 * 3. Call deposit(&account, 5).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function deposit returns STATUS_WRONG_VALUE.
 * 2. Account balance remains unchanged.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_03 */
/* CPPTEST_TEST_CASE_CONTEXT Status deposit(Account*, int) */
void UT_transaction_deposit_TC_03()
{
	CPPTEST_EXPECT_NCALLS("getAccountLimit", 1);
	CPPTEST_EXPECT_NCALLS("updateAccountInFile", 0);
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
	Account account = {.accountNumber = 1234, .balance = 0,.type = STANDARD};
	Status result = deposit(&account, 5);
	CPPTEST_ASSERT_EQUAL(STATUS_WRONG_VALUE, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Minimalan unos je 10.\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_03 */

/**
 * The test case checks the behaviour of the "deposit" function when the deposited amount is not divisible by 10.
 *
 * \field{Test Specification}
 * 1. Stub getAccountLimit to return a valid limit (e.g., 1000).
 * 2. Create an Account struct with balance = 0.
 * 3. Call deposit(&account, 15).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function deposit returns STATUS_WRONG_VALUE.
 * 2. Account balance remains unchanged.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_04 */
/* CPPTEST_TEST_CASE_CONTEXT Status deposit(Account*, int) */
void UT_transaction_deposit_TC_04()
{
	CPPTEST_EXPECT_NCALLS("getAccountLimit", 1);
	CPPTEST_EXPECT_NCALLS("updateAccountInFile", 0);
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
	Account account = {.accountNumber = 1234, .balance = 0,.type = STANDARD};
	Status result = deposit(&account, 15);
	CPPTEST_ASSERT_EQUAL(STATUS_WRONG_VALUE, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Pogresna vrijednost (mora biti djeljiva sa 10)\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_04 */

/**
 * The test case checks the behaviour of the "deposit" function when the deposited amount exceeds the account limit.
 *
 * \field{Test Specification}
 * 1. Stub getAccountLimit to return a valid limit (e.g., 1000).
 * 2. Create an Account struct with balance = 0.
 * 3. Call deposit(&account, 2000).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function deposit returns STATUS_LIMIT_EXCEEDING.
 * 2. Account balance remains unchanged.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_05 */
/* CPPTEST_TEST_CASE_CONTEXT Status deposit(Account*, int) */
void UT_transaction_deposit_TC_05()
{
	CPPTEST_EXPECT_NCALLS("getAccountLimit", 1);
	CPPTEST_EXPECT_NCALLS("updateAccountInFile", 0);
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
	Account account = {.accountNumber = 1234, .balance = 0,.type = STANDARD};
	Status result = deposit(&account, 2000);
	CPPTEST_ASSERT_EQUAL(STATUS_LIMIT_EXCEEDING, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Prekoracenje limita\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_05 */

/**
 * The test case checks the correct behaviour of the "deposit" function when the deposited amount is valid and within the account limit.
 *
 * \field{Test Specification}
 * 1. Stub getAccountLimit to return a valid limit (e.g., 1000).
 * 3. Stub updateAccountInFile validates that the function is called with the expected parameter values.
 * 4. Create an Account struct with balance = 0.
 * 5. Call deposit(&account, 50).
 * \endfield
 *
 * \field{Expected Results}
 * Expected result is Passed:
 * 1. Function deposit returns STATUS_OK.
 * 2. Account balance is increased by the deposited amount (0 + 50 = 50).
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_06 */
/* CPPTEST_TEST_CASE_CONTEXT Status deposit(Account*, int) */
void UT_transaction_deposit_TC_06()
{
	CPPTEST_EXPECT_NCALLS("getAccountLimit", 1);
	CPPTEST_EXPECT_NCALLS("updateAccountInFile", 1);
	CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_getAccountLimit_01);
	CPPTEST_REGISTER_STUB_CALLBACK("updateAccountInFile", &CppTest_StubCallback_updateAccountInFile);
	int accountBalance = 0;
	int accountDepositMoney = 50;
	Account account = {.accountNumber = 1234, .balance = accountBalance, .type = STANDARD};
	Status result = deposit(&account, accountDepositMoney);
	CPPTEST_ASSERT_EQUAL(STATUS_OK, result.code);
	CPPTEST_ASSERT_EQUAL(account.balance, accountBalance + accountDepositMoney);
	CPPTEST_ASSERT_CSTR_EQUAL("Uplata na racun uspjesna\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_06 */
