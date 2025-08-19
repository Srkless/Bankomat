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

void CppTest_StubCallback_fopen_00(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	*__return = NULL;
}

void CppTest_StubCallback_fopen_01(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	FILE f = {._cnt = 1};
	FILE *fp = &f;
	*__return = fp;
}

void CppTest_StubCallback_fopen_02(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode){
	FILE f = {._cnt = 1};
	FILE *fp = &f;
	if(strcmp(_Mode, "r")==0){
		*__return = fp;
	}
	else if(strcmp(_Mode, "w")==0){
		*__return = NULL;
	}
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

/* CPPTEST_TEST_CASE_BEGIN TC_01 */
void UT_utils_updateAccountInFile_TC_01()
{
	Account *account = NULL;
	Status result = updateAccountInFile(account);

	CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_NOT_EXISTS, result.code);
}
/* CPPTEST_TEST_CASE_END TC_01 */

/* CPPTEST_TEST_CASE_BEGIN TC_02 */
void UT_utils_updateAccountInFile_TC_02()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_00);
	Account account = {
				.accountNumber = 1234,
				.pinHash = "1234",
				.type = 1,
				.balance = 0
		};
	Status result = updateAccountInFile(&account);
	CPPTEST_ASSERT_EQUAL(STATUS_FILE_ERROR, result.code);
}
/* CPPTEST_TEST_CASE_END TC_02 */

/* CPPTEST_TEST_CASE_BEGIN TC_03 */
// Sadrzaj fajla je prazan pa fgets vraca 0
void UT_utils_updateAccountInFile_TC_03()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_00);
		Account account = {
					.accountNumber = 1234,
					.pinHash = "1234",
					.type = 1,
					.balance = 0
			};
		Status result = updateAccountInFile(&account);
		CPPTEST_ASSERT_EQUAL(STATUS_ACCOUNT_NOT_EXISTS, result.code);
}
/* CPPTEST_TEST_CASE_END TC_03 */

/* CPPTEST_TEST_CASE_BEGIN TC_04 */
// Ima sadrzaj u fajlu ali ne pronalazi korisnika
void UT_utils_updateAccountInFile_TC_04()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
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
}
/* CPPTEST_TEST_CASE_END TC_04 */

/* CPPTEST_TEST_CASE_BEGIN TC_05 */
// Greska kod realokacije memorije
void UT_utils_updateAccountInFile_TC_05()
{

		CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_01);
		CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
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
}
/* CPPTEST_TEST_CASE_END TC_05 */

/* CPPTEST_TEST_CASE_BEGIN TC_06 */
// Greska kod kreiranja kopije strniga pomocu strdup
void UT_utils_updateAccountInFile_TC_06()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_02);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
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
}
/* CPPTEST_TEST_CASE_END TC_06 */

/* CPPTEST_TEST_CASE_BEGIN TC_07 */
//Pronasao i promjenio sadrzaj
void UT_utils_updateAccountInFile_TC_07()
{

	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
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
}
/* CPPTEST_TEST_CASE_END TC_07 */


/* CPPTEST_TEST_CASE_BEGIN TC_08 */
void UT_utils_updateAccountInFile_TC_08()
{
	CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_fopen_01);
	CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_fgets_01);
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
}
/* CPPTEST_TEST_CASE_END TC_08 */
