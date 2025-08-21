#include "cpptest.h"

/**
 * This file contains user stub definitions.
 *
 * To create a user stub:
 * 1. Open stub template list:
 *    - Eclipse IDE: type 'stub' and press <Ctrl> <Space>
 *    - Microsoft Visual Studio IDE: use context menu C++test->Insert Snippet...
 * 2. Choose the stub template from the list.
 * 3. #include the header file where the function you want to stub is originally 
 *    declared as well as any supporting header files as necessary.
 * 4. Fill out the stub signature to match that of the original function, 
 *    while keeping the CppTest_Stub prefix when it applies.
 *    Note: for C++ operators, use appropriate stub names - e.g.:
 *        CppTest_Stub_operator_new    for operator new
 *        CppTest_Stub_operator_delete for operator delete
 *        CppTest_Stub_operator_plus   for operator +
 *    Refer to C++test User's Guide for a complete list of stub names for operators. 
 * 5. Fill out the body of the stub according to intent.
 *
 * Available C++test API functions (see C++test Users Guide for details):
 *     void CppTest_Assert(bool test, const char * message)
 *     void CppTest_Break()
 *     const char* CppTest_GetCurrentTestCaseName()
 *     const char* CppTest_GetCurrentTestSuiteName()
 *     bool CppTest_IsCurrentTestCase(const char* testCaseName)
 */

/** 
 * Header files where the stubbed functions are originally declared.
 * Verify #include directives and add any additional header files as necessary.
 */
#include <stdio.h>
#include <string.h>
#include "..\include\account.h"
#include "..\include\security.h"
#include <stdlib.h>
#include "..\include\utils.h"


/** User stub definition for function: char * fgets(char *__restrict__, int, FILE *__restrict__) */
EXTERN_C_LINKAGE char * fgets (char * _Buf, int _MaxCount, FILE * _File) ;
EXTERN_C_LINKAGE char * CppTest_Stub_fgets (char * _Buf, int _MaxCount, FILE * _File)
{
    CPPTEST_STUB_CALLED("fgets");

    char * __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, char ** __return, char * _Buf, int _MaxCount, FILE * _File)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("fgets", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = fgets(_Buf, _MaxCount, _File);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(char ** __return, char * _Buf, int _MaxCount, FILE * _File);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _Buf, _MaxCount, _File);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: char * strcpy(char *__restrict__, const char *__restrict__) */
//EXTERN_C_LINKAGE char * strcpy (char * _Dest, const char * _Source) ;
//EXTERN_C_LINKAGE char * CppTest_Stub_strcpy (char * _Dest, const char * _Source)
//{
//    CPPTEST_STUB_CALLED("strcpy");
//
//    char * __return = 0;
//
//    /**
//     * This section enables Dynamic Stub Configuration with Stub Callbacks.
//     *
//     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
//     *
//     * 1. Define stub callback function in test suite file - use the following signature:
//     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, char ** __return, char * _Dest, const char * _Source)
//     *
//     * 2. Register stub callback in test case function - use the following code:
//     *     CPPTEST_REGISTER_STUB_CALLBACK("strcpy", &CppTest_StubCallback_SomeName);
//     *
//     * 3. Fill out the body of the stub callback function according to intent.
//     * The following line may be used to call original function inside stub callback:
//     *     *__return = strcpy(_Dest, _Source);
//     */
//    if (CPPTEST_STUB_HAS_CALLBACK()) {
//        CPPTEST_STUB_CALLBACK_PARAMS(char ** __return, char * _Dest, const char * _Source);
//        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _Dest, _Source);
//
//    } else {
//        /* You can put additional stub logic here. */
//
//    }
//
//    return __return;
//}

/** User stub definition for function: FILE * __acrt_iob_func(unsigned int) */
EXTERN_C_LINKAGE FILE * __acrt_iob_func (unsigned index) ;
EXTERN_C_LINKAGE FILE * CppTest_Stub___acrt_iob_func (unsigned index) 
{
    CPPTEST_STUB_CALLED("__acrt_iob_func");

    FILE * __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, unsigned index)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("__acrt_iob_func", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = __acrt_iob_func(index);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(FILE ** __return, unsigned index);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, index);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: int fclose(FILE *) */
EXTERN_C_LINKAGE int fclose (FILE * _File) ;
EXTERN_C_LINKAGE int CppTest_Stub_fclose (FILE * _File)
{
    CPPTEST_STUB_CALLED("fclose");

    int __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return, FILE * _File)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("fclose", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = fclose(_File);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(int* __return, FILE * _File);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _File);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: int fflush(FILE *) */
EXTERN_C_LINKAGE int fflush (FILE * _File) ;
EXTERN_C_LINKAGE int CppTest_Stub_fflush (FILE * _File) 
{
    CPPTEST_STUB_CALLED("fflush");

    int __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return, FILE * _File)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("fflush", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = fflush(_File);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(int* __return, FILE * _File);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _File);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}


/** User stub definition for function: int isdigit(void) */
//EXTERN_C_LINKAGE int isdigit () ;
//EXTERN_C_LINKAGE int CppTest_Stub_isdigit (void)
//{
//    CPPTEST_STUB_CALLED("isdigit");
//
//    int __return = 0;
//
//    /**
//     * This section enables Dynamic Stub Configuration with Stub Callbacks.
//     *
//     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
//     *
//     * 1. Define stub callback function in test suite file - use the following signature:
//     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return)
//     *
//     * 2. Register stub callback in test case function - use the following code:
//     *     CPPTEST_REGISTER_STUB_CALLBACK("isdigit", &CppTest_StubCallback_SomeName);
//     *
//     * 3. Fill out the body of the stub callback function according to intent.
//     * The following line may be used to call original function inside stub callback:
//     *     *__return = isdigit();
//     */
//    if (CPPTEST_STUB_HAS_CALLBACK()) {
//        CPPTEST_STUB_CALLBACK_PARAMS(int* __return);
//        CPPTEST_STUB_INVOKE_CALLBACK(&__return);
//
//    } else {
//        /* You can put additional stub logic here. */
//
//    }
//
//    return __return;
//}

/** User stub definition for function: int printf(const char *__restrict__, ...) */
EXTERN_C_LINKAGE int printf (const char * _Format, ...) ;
EXTERN_C_LINKAGE int CppTest_Stub_printf (const char * _Format, ...) 
{
    CPPTEST_STUB_CALLED("printf");

    int __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return, const char * _Format)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("printf", &CppTest_StubCallback_SomeName);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(int* __return, const char * _Format);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _Format);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: int rand(void) */
EXTERN_C_LINKAGE int rand () ;
EXTERN_C_LINKAGE int CppTest_Stub_rand (void) 
{
    CPPTEST_STUB_CALLED("rand");

    int __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("rand", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = rand();
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(int* __return);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: int scanf(const char *__restrict__, ...) */
EXTERN_C_LINKAGE int scanf (const char * _Format, ...) ;
EXTERN_C_LINKAGE int CppTest_Stub_scanf (const char * _Format, ...) 
{
    CPPTEST_STUB_CALLED("scanf");

    int __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return, const char * _Format)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("scanf", &CppTest_StubCallback_SomeName);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(int* __return, const char * _Format);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _Format);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

///** User stub definition for function: int sprintf(char *__restrict__, const char *__restrict__, ...) */
//EXTERN_C_LINKAGE int sprintf (char * _Dest, const char * _Format, ...) ;
//EXTERN_C_LINKAGE int CppTest_Stub_sprintf (char * _Dest, const char * _Format, ...)
//{
//    CPPTEST_STUB_CALLED("sprintf");
//
//    int __return = 0;
//
//    /**
//     * This section enables Dynamic Stub Configuration with Stub Callbacks.
//     *
//     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
//     *
//     * 1. Define stub callback function in test suite file - use the following signature:
//     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return, char * _Dest, const char * _Format)
//     *
//     * 2. Register stub callback in test case function - use the following code:
//     *     CPPTEST_REGISTER_STUB_CALLBACK("sprintf", &CppTest_StubCallback_SomeName);
//     */
//    if (CPPTEST_STUB_HAS_CALLBACK()) {
//        CPPTEST_STUB_CALLBACK_PARAMS(int* __return, char * _Dest, const char * _Format);
//        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _Dest, _Format);
//
//    } else {
//        /* You can put additional stub logic here. */
//
//    }
//
//    return __return;
//}

///** User stub definition for function: int sscanf(const char *__restrict__, const char *__restrict__, ...) */
//EXTERN_C_LINKAGE int sscanf (const char * _Src, const char * _Format, ...) ;
//EXTERN_C_LINKAGE int CppTest_Stub_sscanf (const char * _Src, const char * _Format, ...)
//{
//    CPPTEST_STUB_CALLED("sscanf");
//
//    int __return = 0;
//
//    /**
//     * This section enables Dynamic Stub Configuration with Stub Callbacks.
//     *
//     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
//     *
//     * 1. Define stub callback function in test suite file - use the following signature:
//     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return, const char * _Src, const char * _Format)
//     *
//     * 2. Register stub callback in test case function - use the following code:
//     *     CPPTEST_REGISTER_STUB_CALLBACK("sscanf", &CppTest_StubCallback_SomeName);
//     */
//    if (CPPTEST_STUB_HAS_CALLBACK()) {
//        CPPTEST_STUB_CALLBACK_PARAMS(int* __return, const char * _Src, const char * _Format);
//        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _Src, _Format);
//
//    } else {
//        /* You can put additional stub logic here. */
//
//    }
//
//    return __return;
//}

/** User stub definition for function: int strcmp(void) */
EXTERN_C_LINKAGE int strcmp () ;
EXTERN_C_LINKAGE int CppTest_Stub_strcmp (void) 
{
    CPPTEST_STUB_CALLED("strcmp");

    int __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("strcmp", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = strcmp();
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(int* __return);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: int time(void) */
EXTERN_C_LINKAGE int time () ;
EXTERN_C_LINKAGE int CppTest_Stub_time (void) 
{
    CPPTEST_STUB_CALLED("time");

    int __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("time", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = time();
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(int* __return);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

///** User stub definition for function: size_t strlen(const char *) */
//EXTERN_C_LINKAGE size_t strlen (const char * _Str) ;
//EXTERN_C_LINKAGE size_t CppTest_Stub_strlen (const char * _Str)
//{
//    CPPTEST_STUB_CALLED("strlen");
//
//    size_t __return = (unsigned long long)0;
//
//    /**
//     * This section enables Dynamic Stub Configuration with Stub Callbacks.
//     *
//     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
//     *
//     * 1. Define stub callback function in test suite file - use the following signature:
//     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, size_t* __return, const char * _Str)
//     *
//     * 2. Register stub callback in test case function - use the following code:
//     *     CPPTEST_REGISTER_STUB_CALLBACK("strlen", &CppTest_StubCallback_SomeName);
//     *
//     * 3. Fill out the body of the stub callback function according to intent.
//     * The following line may be used to call original function inside stub callback:
//     *     *__return = strlen(_Str);
//     */
//    if (CPPTEST_STUB_HAS_CALLBACK()) {
//        CPPTEST_STUB_CALLBACK_PARAMS(size_t* __return, const char * _Str);
//        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _Str);
//
//    } else {
//        /* You can put additional stub logic here. */
//
//    }
//
//    return __return;
//}

/** User stub definition for function: void perror(const char *) */
EXTERN_C_LINKAGE void perror (const char * _ErrMsg) ;
EXTERN_C_LINKAGE void CppTest_Stub_perror (const char * _ErrMsg) 
{
    CPPTEST_STUB_CALLED("perror");

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, const char * _ErrMsg)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("perror", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     perror(_ErrMsg);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(const char * _ErrMsg);
        CPPTEST_STUB_INVOKE_CALLBACK(_ErrMsg);

    } else {
        /* You can put additional stub logic here. */

    }

}

/** User stub definition for function: Status generateAccountNumber(void) */
EXTERN_C_LINKAGE Status generateAccountNumber () ;
EXTERN_C_LINKAGE Status CppTest_Stub_generateAccountNumber (void) 
{
    CPPTEST_STUB_CALLED("generateAccountNumber");

    static Status _MT_svar1;    

    Status __return = _MT_svar1;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, Status* __return)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("generateAccountNumber", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = generateAccountNumber();
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(Status* __return);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: Status isAccountExists(int) */
EXTERN_C_LINKAGE Status isAccountExists (int accountNumber) ;
EXTERN_C_LINKAGE Status CppTest_Stub_isAccountExists (int accountNumber) 
{
    CPPTEST_STUB_CALLED("isAccountExists");

    static Status _MT_svar1;    

    Status __return = _MT_svar1;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, Status* __return, int accountNumber)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("isAccountExists", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = isAccountExists(accountNumber);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(Status* __return, int accountNumber);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, accountNumber);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: FILE * fopen(const char *__restrict__, const char *__restrict__) */
EXTERN_C_LINKAGE FILE * fopen (const char * _Filename, const char * _Mode) ;
EXTERN_C_LINKAGE FILE * CppTest_Stub_fopen (const char * _Filename, const char * _Mode) 
{
    CPPTEST_STUB_CALLED("fopen");

    FILE * __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, FILE ** __return, const char * _Filename, const char * _Mode)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("fopen", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = fopen(_Filename, _Mode);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(FILE ** __return, const char * _Filename, const char * _Mode);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _Filename, _Mode);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: int fprintf(FILE *__restrict__, const char *__restrict__, ...) */
EXTERN_C_LINKAGE int fprintf (FILE * _File, const char * _Format, ...) ;
EXTERN_C_LINKAGE int CppTest_Stub_fprintf (FILE * _File, const char * _Format, ...) 
{
    CPPTEST_STUB_CALLED("fprintf");

    int __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return, FILE * _File, const char * _Format)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("fprintf", &CppTest_StubCallback_SomeName);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(int* __return, FILE * _File, const char * _Format);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _File, _Format);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: void * realloc(void *, size_t) */
EXTERN_C_LINKAGE void * realloc (void * _Memory, size_t _NewSize) ;
EXTERN_C_LINKAGE void * CppTest_Stub_realloc (void * _Memory, size_t _NewSize)
{
    CPPTEST_STUB_CALLED("realloc");

    void * __return = _Memory;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, void ** __return, void * _Memory, size_t _NewSize)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("realloc", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = realloc(_Memory, _NewSize);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(void ** __return, void * _Memory, size_t _NewSize);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _Memory, _NewSize);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: char* strdup(const char*) */
EXTERN_C_LINKAGE char* strdup (const char* s);
EXTERN_C_LINKAGE char* CppTest_Stub_strdup (const char* s)
{
    CPPTEST_STUB_CALLED("strdup");

    char* __return = 0;

    /**
     * 1. Define stub callback in test suite file:
     *     void CppTest_StubCallback_strdup(CppTest_StubCallInfo* stubCallInfo, char** __return, const char* s);
     *
     * 2. Register stub callback in test case:
     *     CPPTEST_REGISTER_STUB_CALLBACK("strdup", &CppTest_StubCallback_strdup);
     *
     * 3. In the callback, fill __return with a pointer to a test string
     *    (e.g., via malloc/strcpy or static buffer).
     */

    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(char** __return, const char* s);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, s);
    } else {
        // default ponašanje možeš simulirati ru�?no ili pustiti originalni strdup
        if (s) {
            __return = (char*)malloc(strlen(s) + 1);
            if (__return) {
                strcpy(__return, s);
            }
        }
    }

    return __return;
}


/** User stub definition for function: void * malloc(size_t) */
EXTERN_C_LINKAGE void * malloc (size_t _Size) ;
EXTERN_C_LINKAGE void * CppTest_Stub_malloc (size_t _Size) 
{
    CPPTEST_STUB_CALLED("malloc");

    void * __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, void ** __return, size_t _Size)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("malloc", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = malloc(_Size);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(void ** __return, size_t _Size);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, _Size);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}

/** User stub definition for function: int getAccountLimit(AccountType) */
EXTERN_C_LINKAGE int getAccountLimit (AccountType type) ;
EXTERN_C_LINKAGE int CppTest_Stub_getAccountLimit (AccountType type) 
{
    CPPTEST_STUB_CALLED("getAccountLimit");

    int __return = 0;

    /**
     * This section enables Dynamic Stub Configuration with Stub Callbacks.
     *
     * IMPORTANT: THIS COMMENT BLOCK SHOULD NOT BE DELETED OR MODIFIED
     *
     * 1. Define stub callback function in test suite file - use the following signature:
     *     void CppTest_StubCallback_SomeName(CppTest_StubCallInfo* stubCallInfo, int* __return, AccountType type)
     *
     * 2. Register stub callback in test case function - use the following code:
     *     CPPTEST_REGISTER_STUB_CALLBACK("getAccountLimit", &CppTest_StubCallback_SomeName);
     *
     * 3. Fill out the body of the stub callback function according to intent.
     * The following line may be used to call original function inside stub callback:
     *     *__return = getAccountLimit(type);
     */
    if (CPPTEST_STUB_HAS_CALLBACK()) {
        CPPTEST_STUB_CALLBACK_PARAMS(int* __return, AccountType type);
        CPPTEST_STUB_INVOKE_CALLBACK(&__return, type);

    } else {
        /* You can put additional stub logic here. */

    }

    return __return;
}
