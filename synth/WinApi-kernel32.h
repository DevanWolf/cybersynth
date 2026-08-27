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

#if !defined(_WINAPI_KERNEL32_H_INCLUDED_)
#define _WINAPI_KERNEL32_H_INCLUDED_

#include "ptr32.h"
#include "platform.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32_t CCALL CloseHandle_c(void * hObject);
uint32_t CCALL CreateDirectoryA_c(const char * lpPathName, void * lpSecurityAttributes);
void * CCALL CreateFileA_c(const char * lpFileName, uint32_t dwDesiredAccess, uint32_t dwShareMode, void * lpSecurityAttributes, uint32_t dwCreationDisposition, uint32_t dwFlagsAndAttributes, void * hTemplateFile);
void * CCALL CreateSemaphoreA_c(void * lpSemaphoreAttributes, int32_t lInitialCount, int32_t lMaximumCount, const char * lpName);
void * CCALL CreateThread_c(void * lpThreadAttributes, uint32_t dwStackSize, void * lpStartAddress, void * lpParameter, uint32_t dwCreationFlags, uint32_t * lpThreadId);
uint32_t CCALL FindClose_c(void * hFindFile);
void * CCALL FindFirstFileA_c(const char * lpFileName, void * lpFindFileData);
uint32_t CCALL FindNextFileA_c(void * hFindFile, void * lpFindFileData);
uint32_t CCALL GetWindowsDirectoryA_c(char * lpBuffer, uint32_t uSize);
void * CCALL GlobalAlloc_c(uint32_t uFlags, uint32_t dwBytes);
void * CCALL GlobalFree_c(void * hMem);
uint32_t CCALL ReadFile_c(void * hFile, void * lpBuffer, uint32_t nNumberOfBytesToRead, uint32_t * lpNumberOfBytesRead, void * lpOverlapped);
uint32_t CCALL ReleaseSemaphore_c(void * hSemaphore, int32_t lReleaseCount, int32_t * lpPreviousCount);
uint32_t CCALL SetCurrentDirectoryA_c(const char * lpPathName);
uint32_t CCALL SetFilePointer_c(void * hFile, int32_t lDistanceToMove, int32_t * lpDistanceToMoveHigh, uint32_t dwMoveMethod);
uint32_t CCALL SetThreadPriority_c(void * hThread, int32_t nPriority);
uint32_t CCALL WaitForSingleObject_c(void * hHandle, uint32_t dwMilliseconds);

#ifdef __cplusplus
}
#endif

#endif

