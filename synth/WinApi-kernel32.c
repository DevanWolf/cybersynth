/**
 *
 *  Copyright (C) 2026 Roman Pauer
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of
 *  this software and associated documentation files (the "Software"), to deal in
 *  the Software without restriction, including without limitation the rights to
 *  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 *  of the Software, and to permit persons to whom the Software is furnished to do
 *  so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 */

#define _FILE_OFFSET_BITS 64
#include "WinApi-kernel32.h"
#include "memory32.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if (defined(__WIN32__) || defined(__WINDOWS__)) && !defined(_WIN32)
#define _WIN32
#endif

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#endif

#ifdef PTROFS_64BIT
#define INVALID_HANDLE32_VALUE (void *)(pointer_offset + 0xfffffffful)
#else
#define INVALID_HANDLE32_VALUE (void *)(uintptr_t)(0xfffffffful)
#endif


#define eprintf(...) fprintf(stderr,__VA_ARGS__)


#if !defined(_WIN32)
#define GMEM_ZEROINIT 0x40
#define WAIT_OBJECT_0 0

typedef struct _filetime_ {
    uint32_t dwLowDateTime;
    uint32_t dwHighDateTime;
} filetime;

typedef struct _win32_find_data_ {
    uint32_t dwFileAttributes;
    filetime ftCreationTime;
    filetime ftLastAccessTime;
    filetime ftLastWriteTime;
    uint32_t nFileSizeHigh;
    uint32_t nFileSizeLow;
    uint32_t dwReserved0;
    uint32_t dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
} win32_find_data;
#endif


#ifdef __cplusplus
extern "C" {
#endif
extern void CCALL run_thread_proc(void *lpParameter, uint32_t (*lpStartAddress)(void *));

extern const char *cs_bank_directory_path;
#ifdef __cplusplus
}
#endif

static uint32_t (*lpThreadStartAddress)(void *lpParameter);
static uint32_t *lpThreadParameter;


uint32_t CCALL CloseHandle_c(void * hObject)
{
    if (hObject == NULL) return 1;

    if (fclose((sizeof(void *) > 4) ? *(FILE **)hObject : (FILE *)hObject)) return 0;

    return 1;
}

uint32_t CCALL CreateDirectoryA_c(const char * lpPathName, void * lpSecurityAttributes)
{
    return 0;
}

void * CCALL CreateFileA_c(const char * lpFileName, uint32_t dwDesiredAccess, uint32_t dwShareMode, void * lpSecurityAttributes, uint32_t dwCreationDisposition, uint32_t dwFlagsAndAttributes, void * hTemplateFile)
{
    char *filepath;
    FILE *file;
    size_t len;

    if (cs_bank_directory_path != NULL && *cs_bank_directory_path != 0)
    {
        len = strlen(cs_bank_directory_path) + strlen(lpFileName) + 2;
        filepath = (char *)malloc(len);
        if (filepath == NULL) return NULL;

#if (defined(_MSC_VER) && __STDC_WANT_SECURE_LIB__) || (defined(__MINGW32__) && defined(_UCRT)) || (defined(__STDC_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__)
        sprintf_s(filepath, len, "%s/%s", cs_bank_directory_path, lpFileName);

        if (fopen_s(&file, filepath, "rb")) return NULL;
#else
        snprintf(filepath, len, "%s/%s", cs_bank_directory_path, lpFileName);

        file = fopen(filepath, "rb");
        if (file == NULL) return NULL;
#endif
    }
    else
    {
#if (defined(_MSC_VER) && __STDC_WANT_SECURE_LIB__) || (defined(__MINGW32__) && defined(_UCRT)) || (defined(__STDC_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__)
        if (fopen_s(&file, lpFileName, "rb")) return NULL;
#else
        file = fopen(lpFileName, "rb");
        if (file == NULL) return NULL;
#endif
    }

    if (sizeof(void *) > 4)
    {
        FILE **pfile;
        pfile = (FILE **)x86_malloc(sizeof(void *));
        if (pfile == NULL)
        {
            fclose(file);
            return NULL;
        }

        *pfile = file;
        return pfile;
    }
    else
    {
        return file;
    }
}

void * CCALL CreateSemaphoreA_c(void * lpSemaphoreAttributes, int32_t lInitialCount, int32_t lMaximumCount, const char * lpName)
{
    return NULL;
}

void * CCALL CreateThread_c(void * lpThreadAttributes, uint32_t dwStackSize, void * lpStartAddress, void * lpParameter, uint32_t dwCreationFlags, uint32_t * lpThreadId)
{
    lpThreadStartAddress = (uint32_t (*)(void *))lpStartAddress;
    lpThreadParameter = (uint32_t *)lpParameter;
    lpThreadParameter[2] = 1; // set quit flag
    return NULL;
}

uint32_t CCALL FindClose_c(void * hFindFile)
{
    if (hFindFile == NULL) return 1;

#ifdef _WIN32
    if (sizeof(void *) > 4)
    {
        FindClose(*(HANDLE *)hFindFile);
        x86_free(hFindFile);
    }
    else
    {
        FindClose((HANDLE)hFindFile);
    }
    return 1;
#else
    if (sizeof(void *) > 4)
    {
        closedir(*(DIR **)hFindFile);
        x86_free(hFindFile);
    }
    else
    {
        closedir((DIR *)hFindFile);
    }
    return 1;
#endif
}

void * CCALL FindFirstFileA_c(const char * lpFileName, void * lpFindFileData)
{
#ifdef _WIN32
    HANDLE hFind;
    char *filepath;
    size_t len;

    if (cs_bank_directory_path != NULL && *cs_bank_directory_path != 0)
    {
        len = strlen(cs_bank_directory_path) + 7;
        filepath = (char *)malloc(len);
        if (filepath == NULL) return INVALID_HANDLE32_VALUE;

#if (defined(_MSC_VER) && __STDC_WANT_SECURE_LIB__) || (defined(__MINGW32__) && defined(_UCRT)) || (defined(__STDC_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__)
        sprintf_s(filepath, len, "%s\\%s", cs_bank_directory_path, "*.iss");
#else
        snprintf(filepath, len, "%s\\%s", cs_bank_directory_path, "*.iss");
#endif

        hFind = FindFirstFileExA(filepath, FindExInfoBasic, (LPWIN32_FIND_DATAA)lpFindFileData, FindExSearchNameMatch, NULL, 0);
        free(filepath);
    }
    else
    {
        hFind = FindFirstFileExA("*.iss", FindExInfoBasic, (LPWIN32_FIND_DATAA)lpFindFileData, FindExSearchNameMatch, NULL, 0);
    }
    if (hFind == INVALID_HANDLE_VALUE) return INVALID_HANDLE32_VALUE;

    while ((((LPWIN32_FIND_DATAA)lpFindFileData)->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) || strlen(((LPWIN32_FIND_DATAA)lpFindFileData)->cFileName) >= 64)
    {
        if (!FindNextFileA(hFind, (LPWIN32_FIND_DATAA)lpFindFileData))
        {
            FindClose(hFind);
            return INVALID_HANDLE32_VALUE;
        }
    }

    if (sizeof(void *) > 4)
    {
        HANDLE *phFind;
        phFind = (HANDLE *)x86_malloc(sizeof(void *));
        if (phFind == NULL)
        {
            FindClose(hFind);
            return INVALID_HANDLE32_VALUE;
        }

        *phFind = hFind;
        return phFind;
    }
    else
    {
        return hFind;
    }
#else
    DIR *dirinfo;
    struct dirent *direntry;
    char *lastdot, *filepath;
    struct stat filestat;
    size_t len;

    if (cs_bank_directory_path != NULL && *cs_bank_directory_path != 0)
    {
        dirinfo = opendir(cs_bank_directory_path);
    }
    else
    {
        dirinfo = opendir(".");
    }
    if (dirinfo == NULL) return INVALID_HANDLE32_VALUE;

    filepath = NULL;
    len = 0;
    for (;;)
    {
        direntry = readdir(dirinfo);
        if (direntry == NULL)
        {
            if (filepath != NULL) free(filepath);
            closedir(dirinfo);
            return INVALID_HANDLE32_VALUE;
        }

        if (direntry->d_type != DT_UNKNOWN && direntry->d_type != DT_LNK)
        {
            if (direntry->d_type != DT_REG) continue;
        }

        if (strlen(direntry->d_name) >= 64) continue;

        lastdot = strrchr(direntry->d_name, '.');
        if (lastdot == NULL) continue;
        if (strcasecmp(lastdot, ".iss")) continue;

        if (direntry->d_type == DT_UNKNOWN || direntry->d_type == DT_LNK)
        {
            if (cs_bank_directory_path != NULL && *cs_bank_directory_path != 0)
            {
                if (filepath == NULL)
                {
                    len = strlen(cs_bank_directory_path) + 65;
                    filepath = (char *)malloc(len);
                    if (filepath == NULL)
                    {
                        closedir(dirinfo);
                        return INVALID_HANDLE32_VALUE;
                    }
                }

#if (defined(_MSC_VER) && __STDC_WANT_SECURE_LIB__) || (defined(__MINGW32__) && defined(_UCRT)) || (defined(__STDC_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__)
                sprintf_s(filepath, len, "%s/%s", cs_bank_directory_path, direntry->d_name);
#else
                snprintf(filepath, len, "%s/%s", cs_bank_directory_path, direntry->d_name);
#endif

                if (0 != stat(filepath, &filestat)) continue;
            }
            else
            {
                if (0 != stat(direntry->d_name, &filestat)) continue;
            }

            if (!S_ISREG(filestat.st_mode)) continue;
        }

        break;
    }

    if (filepath != NULL) free(filepath);

    memset(lpFindFileData, 0, sizeof(win32_find_data));
    strcpy(((win32_find_data *)lpFindFileData)->cFileName, direntry->d_name);

    if (sizeof(void *) > 4)
    {
        DIR **pdirinfo;
        pdirinfo = (DIR **)x86_malloc(sizeof(void *));
        if (pdirinfo == NULL)
        {
            closedir(dirinfo);
            return INVALID_HANDLE32_VALUE;
        }

        *pdirinfo = dirinfo;
        return pdirinfo;
    }
    else
    {
        return dirinfo;
    }
#endif
}

uint32_t FindNextFileA_c(void * hFindFile, void * lpFindFileData)
{
#ifdef _WIN32
    HANDLE hFind;

    hFind = (sizeof(void *) > 4) ? *(HANDLE *)hFindFile : (HANDLE)hFindFile;
    do
    {
        if (!FindNextFileA(hFind, (LPWIN32_FIND_DATAA)lpFindFileData)) return 0;
    }
    while ((((LPWIN32_FIND_DATAA)lpFindFileData)->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) || strlen(((LPWIN32_FIND_DATAA)lpFindFileData)->cFileName) >= 64);

    return 1;
#else
    DIR *dirinfo;
    struct dirent *direntry;
    char *lastdot, *filepath;
    struct stat filestat;
    size_t len;

    dirinfo = (sizeof(void *) > 4) ? *(DIR **)hFindFile : (DIR *)hFindFile;

    filepath = NULL;
    len = 0;
    for (;;)
    {
        direntry = readdir(dirinfo);
        if (direntry == NULL)
        {
            if (filepath != NULL) free(filepath);
            return 0;
        }

        if (direntry->d_type != DT_UNKNOWN && direntry->d_type != DT_LNK)
        {
            if (direntry->d_type != DT_REG) continue;
        }

        if (strlen(direntry->d_name) >= 64) continue;

        lastdot = strrchr(direntry->d_name, '.');
        if (lastdot == NULL) continue;
        if (strcasecmp(lastdot, ".iss")) continue;

        if (direntry->d_type == DT_UNKNOWN || direntry->d_type == DT_LNK)
        {
            if (cs_bank_directory_path != NULL && *cs_bank_directory_path != 0)
            {
                if (filepath == NULL)
                {
                    len = strlen(cs_bank_directory_path) + 65;
                    filepath = (char *)malloc(len);
                    if (filepath == NULL)
                    {
                        return 0;
                    }
                }

#if (defined(_MSC_VER) && __STDC_WANT_SECURE_LIB__) || (defined(__MINGW32__) && defined(_UCRT)) || (defined(__STDC_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__)
                sprintf_s(filepath, len, "%s/%s", cs_bank_directory_path, direntry->d_name);
#else
                snprintf(filepath, len, "%s/%s", cs_bank_directory_path, direntry->d_name);
#endif

                if (0 != stat(filepath, &filestat)) continue;
            }
            else
            {
                if (0 != stat(direntry->d_name, &filestat)) continue;
            }

            if (!S_ISREG(filestat.st_mode)) continue;
        }

        break;
    }

    if (filepath != NULL) free(filepath);

    memset(lpFindFileData, 0, sizeof(win32_find_data));
    strcpy(((win32_find_data *)lpFindFileData)->cFileName, direntry->d_name);

    return 1;
#endif
}

uint32_t CCALL GetWindowsDirectoryA_c(char * lpBuffer, uint32_t uSize)
{
    memcpy(lpBuffer, "C:\\Windows", 10 + 1);
    return 10;
}

void * CCALL GlobalAlloc_c(uint32_t uFlags, uint32_t dwBytes)
{
    void *hMem;

// function must return pointers aligned for simd processing

#if defined(X86SSE2) || defined(X64SSE2) || defined(ARMV8) || defined(ARMV7)
#define ALIGNMENT 16
#else
#define ALIGNMENT 8
#endif


#if !defined(x86_malloc)
    if (sizeof(void *) > 4)
    {
        hMem = x86_memalign(ALIGNMENT, dwBytes);
        if (hMem == NULL) return NULL;
    }
    else
#endif
    {
#if defined(_WIN32)
        hMem = _aligned_malloc(dwBytes, ALIGNMENT);
        if (hMem == NULL) return NULL;
#else
        if (0 != posix_memalign(&hMem, ALIGNMENT, dwBytes)) return NULL;
#endif
    }

    if (uFlags & GMEM_ZEROINIT)
    {
        memset(hMem, 0, dwBytes);
    }

#undef ALIGNMENT

    return hMem;
}

void * CCALL GlobalFree_c(void * hMem)
{
    if (hMem == NULL) return NULL;

#if !defined(x86_malloc)
    if (sizeof(void *) > 4)
    {
        x86_free(hMem);
    }
    else
#endif
    {
#if defined(_WIN32)
        _aligned_free(hMem);
#else
        free(hMem);
#endif
    }

    return NULL;
}

uint32_t CCALL ReadFile_c(void * hFile, void * lpBuffer, uint32_t nNumberOfBytesToRead, uint32_t * lpNumberOfBytesRead, void * lpOverlapped)
{
    FILE *file;
    size_t bytes_total, bytes_read, bytes_to_read;
    int iseof;

    file = (sizeof(void *) > 4) ? *(FILE **)hFile : (FILE *)hFile;

    *lpNumberOfBytesRead = 0;

    bytes_total = 0;
    iseof = 0;
    bytes_to_read = nNumberOfBytesToRead;
    while (bytes_to_read)
    {
        bytes_read = fread(lpBuffer, 1, bytes_to_read, file);
        if (bytes_read == 0)
        {
            if (feof(file))
            {
                iseof = 1;
            }
            clearerr(file);

            break;
        }
        else
        {
            if (bytes_read != bytes_to_read)
            {
                clearerr(file);
            }
            bytes_total += bytes_read;
            bytes_to_read -= bytes_read;
            lpBuffer = (void *) (((uintptr_t) lpBuffer) + bytes_read);
        }
    }

    if ((bytes_total != 0) || (nNumberOfBytesToRead == 0))
    {
        *lpNumberOfBytesRead = (uint32_t)bytes_total;
        return 1;
    }
    else
    {
        return (iseof ? 1 : 0);
    }
}

uint32_t CCALL ReleaseSemaphore_c(void * hSemaphore, int32_t lReleaseCount, int32_t * lpPreviousCount)
{
    lpThreadParameter[2] = 1; // set quit flag
    run_thread_proc(lpThreadParameter, lpThreadStartAddress);
    return 1;
}

uint32_t CCALL SetCurrentDirectoryA_c(const char * lpPathName)
{
    return 1;
}

uint32_t CCALL SetFilePointer_c(void * hFile, int32_t lDistanceToMove, int32_t * lpDistanceToMoveHigh, uint32_t dwMoveMethod)
{
    FILE *file;

    file = (sizeof(void *) > 4) ? *(FILE **)hFile : (FILE *)hFile;

    if (fseek(file, lDistanceToMove, dwMoveMethod)) return -1;

    return ftell(file);
}

uint32_t CCALL SetThreadPriority_c(void * hThread, int32_t nPriority)
{
    return 0;
}

uint32_t CCALL WaitForSingleObject_c(void * hHandle, uint32_t dwMilliseconds)
{
    return WAIT_OBJECT_0;
}

