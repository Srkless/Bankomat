#include "cpptest.h"

/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("../src/utils.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("../src/utils.c");

EXTERN_C_LINKAGE void UT_utils_updateAccountInFile_testSuiteBegin(void);
EXTERN_C_LINKAGE int UT_utils_updateAccountInFile_callTest(const char*);

CPPTEST_TEST_SUITE(UT_utils_updateAccountInFile);
        CPPTEST_TEST_SUITE_SETUP(UT_utils_updateAccountInFile_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(UT_utils_updateAccountInFile_testSuiteTearDown);
CPPTEST_TEST(UT_utils_updateAccountInFile_TC_01);
CPPTEST_TEST(UT_utils_updateAccountInFile_TC_02);
CPPTEST_TEST(UT_utils_updateAccountInFile_TC_03);
CPPTEST_TEST(UT_utils_updateAccountInFile_TC_04);
CPPTEST_TEST(UT_utils_updateAccountInFile_TC_05);
CPPTEST_TEST(UT_utils_updateAccountInFile_TC_06);
CPPTEST_TEST(UT_utils_updateAccountInFile_TC_07);
CPPTEST_TEST(UT_utils_updateAccountInFile_TC_08);
CPPTEST_TEST_SUITE_END();
        
static int mock_index = 0;
static const char* mock_data[] = {
    "123|hash123|1|500\n",
    "456|hash456|2|1000\n",
    NULL
};

void UT_utils_updateAccountInFile_TC_01(void);
void UT_utils_updateAccountInFile_TC_02(void);
void UT_utils_updateAccountInFile_TC_03(void);
void UT_utils_updateAccountInFile_TC_04(void);
void UT_utils_updateAccountInFile_TC_05(void);
void UT_utils_updateAccountInFile_TC_06(void);
void UT_utils_updateAccountInFile_TC_07(void);
void UT_utils_updateAccountInFile_TC_08(void);
CPPTEST_TEST_SUITE_REGISTRATION(UT_utils_updateAccountInFile);

void UT_utils_updateAccountInFile_testSuiteSetUp(void);
void UT_utils_updateAccountInFile_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */

/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void UT_utils_updateAccountInFile_testSuiteTearDown(void);
void UT_utils_updateAccountInFile_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void UT_utils_updateAccountInFile_setUp(void);
void UT_utils_updateAccountInFile_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
	mock_index = 0;
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void UT_utils_updateAccountInFile_tearDown(void);
void UT_utils_updateAccountInFile_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}

void CppTest_StubCallback_updateAccountInFile_fopen_00(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	CPPTEST_ASSERT_EQUAL("users.txt", _Filename);
	CPPTEST_ASSERT_EQUAL("r", _Mode);
	*__return = NULL;
}

void CppTest_StubCallback_updateAccountInFile_fopen_01(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	 static int fopen_call_count = 0;
	    fopen_call_count++;

	    if (fopen_call_count == 1) {
	        CPPTEST_ASSERT_EQUAL("users.txt", _Filename);
	        CPPTEST_ASSERT_EQUAL("r", _Mode);
	    } else if (fopen_call_count == 2) {
	        CPPTEST_ASSERT_EQUAL("users.txt", _Filename);
	        CPPTEST_ASSERT_EQUAL("w", _Mode);
	    }
	FILE f = {._cnt = 1};
	FILE *fp = &f;
	*__return = fp;
}

void CppTest_StubCallback_updateAccountInFile_fopen_02(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	static int fopen_call_count = 0;
	fopen_call_count++;
	if (fopen_call_count == 1) {
		CPPTEST_ASSERT_EQUAL("users.txt", _Filename);
		CPPTEST_ASSERT_EQUAL("r", _Mode);
	} else if (fopen_call_count == 2) {
		CPPTEST_ASSERT_EQUAL("users.txt", _Filename);
		CPPTEST_ASSERT_EQUAL("w", _Mode);
	}
	FILE f = {._cnt = 1};
	FILE *fp = &f;
	if(strcmp(_Mode, "r")==0){
		*__return = fp;
	}
	else if(strcmp(_Mode, "w")==0){
		*__return = NULL;
	}
}

void CppTest_StubCallback_updateAccountInFile_fgets_00(CppTest_StubCallInfo* stubCallInfo, char ** __return, char * _Buf, int _MaxCount, FILE * _File){
	*__return = 0;
}

void CppTest_StubCallback_updateAccountInFile_fgets_01(CppTest_StubCallInfo* stubCallInfo, char ** __return, char * _Buf, int _MaxCount, FILE * _File){
	if (mock_data[mock_index] == NULL) {
	        *__return = NULL;
	        return;
	    }

	    strcpy(_Buf, mock_data[mock_index]);
	    mock_index++;

	    *__return = _Buf;
}

void CppTest_StubCallback_strcmp_00(CppTest_StubCallInfo* stubCallInfo, int* __return){
	* __return = 0;
}

void CppTest_StubCallback_strcmp_01(CppTest_StubCallInfo* stubCallInfo, int* __return){
	* __return = 1;
}

void CppTest_StubCallback_realloc_00(CppTest_StubCallInfo* stubCallInfo, void ** __return, void * _Memory, size_t _NewSize){
	*__return = NULL;
}

void CppTest_StubCallback_realloc_01(CppTest_StubCallInfo* stubCallInfo, void ** __return, void * _Memory, size_t _NewSize){
	*__return = realloc(_Memory, _NewSize);;
}

void CppTest_StubCallback_strdup_00(CppTest_StubCallInfo* stubCallInfo, char** __return, const char* s){
	*__return = NULL;
}

void CppTest_StubCallback_strdup_01(CppTest_StubCallInfo* stubCallInfo, char** __return, const char* s){
	char* copy = (char*)malloc(strlen(s) + 1);
	    if (copy) {
	        strcpy(copy, s);
	        *__return = copy;
	    } else {
	        *__return = NULL;
	    }
}

/**
 * The test case checks the correct behavior of "updateAccountInFile" when the provided Account pointer is NULL.
 *
 * \field{Test Specification}
 * 1. Define account pointer as NULL.
 * 2. Call updateAccountInFile(account).
 * \endfield
 *
 * \field{Expected Results}
 * 1. Function returns STATUS_ACCOUNT_NOT_EXISTS.
 * 2. No file operations are performed.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_01 */
/* CPPTEST_TEST_CASE_CONTEXT Status updateAccountInFile(Account*) */
void UT_utils_updateAccountInFile_TC_01()
{
	Account *account = NULL;
	Status result = updateAccountInFile(account);

	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_NOT_EXISTS, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Account ne postoji\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_01 */

/**
 * The test case checks the behaviour of "updateAccountInFile" when fopen fails to open the file for reading.
 *
 * \field{Test Specification}
 * 1. Stub fopen to return NULL.
 * 2. Create a valid Account struct.
 * 3. Call updateAccountInFile(&account).
 * \endfield
 *
 * \field{Expected Results}
 * 1. Function returns STATUS_FILE_ERROR.
 * 2. No further operations are performed.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_02 */
/* CPPTEST_TEST_CASE_CONTEXT Status updateAccountInFile(Account*) */
void UT_utils_updateAccountInFile_TC_02()
{
	CPPTEST_EXPECT_NCALLS("fopen", 1);
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_updateAccountInFile_fopen_00);
	Account account = {
				.accountNumber = 1234,
				.pinHash = "1234",
				.type = 1,
				.balance = 0
		};
	Status result = updateAccountInFile(&account);
	CPPTEST_ASSERT_EQUAL(STATUS_FILE_ERROR, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Greska pri citanju iz fajla.\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/**
 * The test case checks the behaviour of "updateAccountInFile" when the file is empty (fgets returns 0).
 *
 * \field{Test Specification}
 * 1. Stub fopen to return a valid file pointer.
 * 2. Stub fgets to return NULL.
 * 3. Create a valid Account struct.
 * 4. Call updateAccountInFile(&account).
 * \endfield
 *
 * \field{Expected Results}
 * 1. Function returns STATUS_ACCOUNT_NOT_EXISTS.
 * 2. No account update occurs.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_03 */
/* CPPTEST_TEST_CASE_CONTEXT Status updateAccountInFile(Account*) */
void UT_utils_updateAccountInFile_TC_03()
{
	CPPTEST_EXPECT_NCALLS("fopen", 2);
	CPPTEST_EXPECT_NCALLS("fgets", 1);
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_updateAccountInFile_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_updateAccountInFile_fgets_00);
	Account account = {
				.accountNumber = 1234,
				.pinHash = "1234",
				.type = 1,
				.balance = 0
		};
	Status result = updateAccountInFile(&account);
	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_NOT_EXISTS, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Nalog nije pronadjen u fajlu\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_03 */

/**
 * The test case checks the behaviour of "updateAccountInFile" when the file has content but the account number is not found.
 *
 * \field{Test Specification}
 * 1. Stub fopen to return a valid file pointer.
 * 2. Stub fgets to return mock data.
 * 3. Stub strcmp to return non-zero (no match).
 * 4. Stub realloc to fail (return NULL).
 * 5. Call updateAccountInFile(&account).
 * \endfield
 *
 * \field{Expected Results}
 * 1. Function returns STATUS_ERROR due to realloc failure.
 * 2. No changes are written to file.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_04 */
/* CPPTEST_TEST_CASE_CONTEXT Status updateAccountInFile(Account*) */
void UT_utils_updateAccountInFile_TC_04()
{
	CPPTEST_EXPECT_NCALLS("fopen", 1);
	CPPTEST_EXPECT_NCALLS("fgets", 1);
	CPPTEST_EXPECT_NCALLS("strcmp", 1);
	CPPTEST_EXPECT_NCALLS("realloc", 1);
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_updateAccountInFile_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_updateAccountInFile_fgets_01);
	CPPTEST_REGISTER_STUB_CALLBACK("strcmp", &CppTest_StubCallback_strcmp_01);
	CPPTEST_REGISTER_STUB_CALLBACK("realloc", &CppTest_StubCallback_realloc_00);

	Account account = {
				.accountNumber = 1234,
				.pinHash = "1234",
				.type = 1,
				.balance = 0
		};
	Status result = updateAccountInFile(&account);
	CPPTEST_ASSERT_EQUAL(STATUS_ERROR, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Greska u realokaciji\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_04 */

/**
 * The test case checks the behaviour of "updateAccountInFile" when realloc succeeds but strdup fails.
 *
 * \field{Test Specification}
 * 1. Stub fopen to return valid pointer.
 * 2. Stub fgets to return mock data.
 * 3. Stub strcmp to return non-zero (no match).
 * 4. Stub realloc to succeed.
 * 5. Stub strdup to return NULL.
 * 6. Call updateAccountInFile(&account).
 * \endfield
 *
 * \field{Expected Results}
 * 1. Function returns STATUS_ERROR due to strdup failure.
 * 2. No changes are written to file.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_05 */
/* CPPTEST_TEST_CASE_CONTEXT Status updateAccountInFile(Account*) */
void UT_utils_updateAccountInFile_TC_05()
{
	CPPTEST_EXPECT_NCALLS("fopen", 1);
	CPPTEST_EXPECT_NCALLS("fgets", 1);
	CPPTEST_EXPECT_NCALLS("strcmp", 1);
	CPPTEST_EXPECT_NCALLS("realloc", 1);
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_updateAccountInFile_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_updateAccountInFile_fgets_01);
	CPPTEST_REGISTER_STUB_CALLBACK("strcmp", &CppTest_StubCallback_strcmp_01);
	CPPTEST_REGISTER_STUB_CALLBACK("realloc", &CppTest_StubCallback_realloc_01);
	CPPTEST_REGISTER_STUB_CALLBACK("strdup", &CppTest_StubCallback_strdup_00);

	Account account = {
				.accountNumber = 1234,
				.pinHash = "1234",
				.type = 1,
				.balance = 0
		};
	Status result = updateAccountInFile(&account);
	CPPTEST_ASSERT_EQUAL(STATUS_ERROR, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Greska kod sadrzaja u fajlu\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_05 */

/**
 * The test case checks the behaviour of "updateAccountInFile" when fopen fails to open the file for writing.
 *
 * \field{Test Specification}
 * 1. Stub fopen to succeed for reading but fail for writing.
 * 2. Stub fgets, strcmp, realloc to succeed.
 * 3. Call updateAccountInFile(&account).
 * \endfield
 *
 * \field{Expected Results}
 * 1. Function returns STATUS_FILE_ERROR.
 * 2. Account data is not updated in file.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_06 */
/* CPPTEST_TEST_CASE_CONTEXT Status updateAccountInFile(Account*) */
void UT_utils_updateAccountInFile_TC_06()
{
	CPPTEST_EXPECT_NCALLS("fopen", 2);
	CPPTEST_EXPECT_NCALLS("fgets", 3);
	CPPTEST_EXPECT_NCALLS("strcmp", 2);
	CPPTEST_EXPECT_NCALLS("realloc", 2);
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_updateAccountInFile_fopen_02);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_updateAccountInFile_fgets_01);
	CPPTEST_REGISTER_STUB_CALLBACK("strcmp", &CppTest_StubCallback_strcmp_01);
	CPPTEST_REGISTER_STUB_CALLBACK("realloc", &CppTest_StubCallback_realloc_01);

	Account account = {
				.accountNumber = 1234,
				.pinHash = "1234",
				.type = 1,
				.balance = 0
		};
	Status result = updateAccountInFile(&account);
	CPPTEST_ASSERT_EQUAL(STATUS_FILE_ERROR, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Greska pri otvaranju fajla za pisanje\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_06 */

/**
 * The test case checks the behaviour of "updateAccountInFile" when the account is found and balance is updated in memory, but file writing is not verified.
 *
 * \field{Test Specification}
 * 1. Stub fopen, fgets, strcmp, realloc to succeed.
 * 2. Stub strcmp to simulate account not found (non-zero).
 * 3. Call updateAccountInFile(&account).
 * \endfield
 *
 * \field{Expected Results}
 * 1. Function returns STATUS_ACCOUNT_NOT_EXISTS.
 * 2. BalanceUpdated flag remains 0; no actual update confirmed.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_07 */
/* CPPTEST_TEST_CASE_CONTEXT Status updateAccountInFile(Account*) */
void UT_utils_updateAccountInFile_TC_07()
{
	CPPTEST_EXPECT_NCALLS("fopen", 2);
	CPPTEST_EXPECT_NCALLS("fgets", 3);
	CPPTEST_EXPECT_NCALLS("strcmp", 2);
	CPPTEST_EXPECT_NCALLS("realloc", 2);

	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_updateAccountInFile_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_updateAccountInFile_fgets_01);
	CPPTEST_REGISTER_STUB_CALLBACK("strcmp", &CppTest_StubCallback_strcmp_01);
	CPPTEST_REGISTER_STUB_CALLBACK("realloc", &CppTest_StubCallback_realloc_01);

	Account account = {
				.accountNumber = 1234,
				.pinHash = "1234",
				.type = 1,
				.balance = 0
		};
	Status result = updateAccountInFile(&account);
	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_NOT_EXISTS, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Nalog nije pronadjen u fajlu\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_07 */

/**
 * The test case checks the correct behaviour of "updateAccountInFile" when the account is found and successfully updated in the file.
 *
 * \field{Test Specification}
 * 1. Stub fopen, fgets, strcmp, realloc, strdup to succeed.
 * 2. Stub strcmp to match the account number (return 0).
 * 3. Call updateAccountInFile(&account).
 * \endfield
 *
 * \field{Expected Results}
 * 1. Function returns STATUS_OK.
 * 2. Account balance and data are successfully updated in the file.
 * \endfield
 */
/* CPPTEST_TEST_CASE_BEGIN TC_08 */
/* CPPTEST_TEST_CASE_CONTEXT Status updateAccountInFile(Account*) */
void UT_utils_updateAccountInFile_TC_08()
{
	CPPTEST_EXPECT_NCALLS("fopen", 2);
	CPPTEST_EXPECT_NCALLS("fgets", 3);
	CPPTEST_EXPECT_NCALLS("strcmp", 2);
	CPPTEST_EXPECT_NCALLS("realloc", 2);
	CPPTEST_EXPECT_NCALLS("strdup", 2);

	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_updateAccountInFile_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_updateAccountInFile_fgets_01);
	CPPTEST_REGISTER_STUB_CALLBACK("strcmp", &CppTest_StubCallback_strcmp_00);
	CPPTEST_REGISTER_STUB_CALLBACK("realloc", &CppTest_StubCallback_realloc_01);
	CPPTEST_REGISTER_STUB_CALLBACK("strdup", &CppTest_StubCallback_strdup_01);

	Account account = {
				.accountNumber = 1234,
				.pinHash = "1234",
				.type = 1,
				.balance = 0
		};
	Status result = updateAccountInFile(&account);
	CPPTEST_ASSERT_EQUAL(STATUS_OK, result.code);
	CPPTEST_ASSERT_CSTR_EQUAL("Uspjesan update i balance promijenjen\n", result.message);
}
/* CPPTEST_TEST_CASE_END TC_08 */
