;;
;;  Copyright (C) 2026 Roman Pauer
;;
;;  Permission is hereby granted, free of charge, to any person obtaining a copy of
;;  this software and associated documentation files (the "Software"), to deal in
;;  the Software without restriction, including without limitation the rights to
;;  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
;;  of the Software, and to permit persons to whom the Software is furnished to do
;;  so, subject to the following conditions:
;;
;;  The above copyright notice and this permission notice shall be included in all
;;  copies or substantial portions of the Software.
;;
;;  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;;  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;;  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
;;  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;;  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;;  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;;  SOFTWARE.
;;

%include "x64inc.inc"
%include "asm-calls.inc"

extern CloseHandle_c
extern CreateDirectoryA_c
extern CreateFileA_c
extern CreateSemaphoreA_c
extern CreateThread_c
extern FindClose_c
extern FindFirstFileA_c
extern FindNextFileA_c
extern GetWindowsDirectoryA_c
extern GlobalAlloc_c
extern GlobalFree_c
extern ReadFile_c
extern ReleaseSemaphore_c
extern SetCurrentDirectoryA_c
extern SetFilePointer_c
extern SetThreadPriority_c
extern WaitForSingleObject_c

global CloseHandle_asm
global CreateDirectoryA_asm
global CreateFileA_asm
global CreateSemaphoreA_asm
global CreateThread_asm
global FindClose_asm
global FindFirstFileA_asm
global FindNextFileA_asm
global GetWindowsDirectoryA_asm
global GlobalAlloc_asm
global GlobalFree_asm
global ReadFile_asm
global ReleaseSemaphore_asm
global SetCurrentDirectoryA_asm
global SetFilePointer_asm
global SetThreadPriority_asm
global WaitForSingleObject_asm

%ifidn __OUTPUT_FORMAT__, elf64
section .note.GNU-stack noalloc noexec nowrite progbits
section .text progbits alloc exec nowrite align=16
%else
section .text code align=16
%endif
%ifidn __OUTPUT_FORMAT__, win64
section_prolog:
        SECTION_PROLOG
%endif

align 16
CloseHandle_asm:

; [esp +   4] = HANDLE hObject
; [esp      ] = return address

        Call_Asm_Stack1 CloseHandle_c, 1

; end procedure CloseHandle_asm


align 16
CreateDirectoryA_asm:

; [esp + 2*4] = LPSECURITY_ATTRIBUTES lpSecurityAttributes
; [esp +   4] = LPCSTR lpPathName
; [esp      ] = return address

        Call_Asm_Stack2 CreateDirectoryA_c, 2

; end procedure CreateDirectoryA_asm


align 16
CreateFileA_asm:

; [esp + 7*4] = HANDLE hTemplateFile
; [esp + 6*4] = DWORD dwFlagsAndAttributes
; [esp + 5*4] = DWORD dwCreationDisposition
; [esp + 4*4] = LPSECURITY_ATTRIBUTES lpSecurityAttributes
; [esp + 3*4] = DWORD dwShareMode
; [esp + 2*4] = DWORD dwDesiredAccess
; [esp +   4] = LPCSTR lpFileName
; [esp      ] = return address

        Call_Asm_Stack7 CreateFileA_c, 7

; end procedure CreateFileA_asm


align 16
CreateSemaphoreA_asm:

; [esp + 4*4] = LPCSTR lpName
; [esp + 3*4] = LONG lMaximumCount
; [esp + 2*4] = LONG lInitialCount
; [esp +   4] = LPSECURITY_ATTRIBUTES lpSemaphoreAttributes
; [esp      ] = return address

        Call_Asm_Stack4 CreateSemaphoreA_c, 4

; end procedure CreateSemaphoreA_asm


align 16
CreateThread_asm:

; [esp + 6*4] = LPDWORD lpThreadId
; [esp + 5*4] = DWORD dwCreationFlags
; [esp + 4*4] = LPVOID lpParameter
; [esp + 3*4] = LPTHREAD_START_ROUTINE lpStartAddress
; [esp + 2*4] = SIZE_T dwStackSize
; [esp +   4] = LPSECURITY_ATTRIBUTES lpThreadAttributes
; [esp      ] = return address

        Call_Asm_Stack6 CreateThread_c, 6

; end procedure CreateThread_asm


align 16
FindClose_asm:

; [esp +   4] = HANDLE hFindFile
; [esp      ] = return address

        Call_Asm_Stack1 FindClose_c, 1

; end procedure FindClose_asm


align 16
FindFirstFileA_asm:

; [esp + 2*4] = LPWIN32_FIND_DATAA lpFindFileData
; [esp +   4] = LPCSTR lpFileName
; [esp      ] = return address

        Call_Asm_Stack2 FindFirstFileA_c, 2

; end procedure FindFirstFileA_asm


align 16
FindNextFileA_asm:

; [esp + 2*4] = LPWIN32_FIND_DATAA lpFindFileData
; [esp +   4] = HANDLE hFindFile
; [esp      ] = return address

        Call_Asm_Stack2 FindNextFileA_c, 2

; end procedure FindNextFileA_asm


align 16
GetWindowsDirectoryA_asm:

; [esp + 2*4] = UINT uSize
; [esp +   4] = LPSTR lpBuffer
; [esp      ] = return address

        Call_Asm_Stack2 GetWindowsDirectoryA_c, 2

; end procedure GetWindowsDirectoryA_asm


align 16
GlobalAlloc_asm:

; [esp + 2*4] = SIZE_T dwBytes
; [esp +   4] = UINT uFlags
; [esp      ] = return address

        Call_Asm_Stack2 GlobalAlloc_c, 2

; end procedure GlobalAlloc_asm


align 16
GlobalFree_asm:

; [esp +   4] = HGLOBAL hMem
; [esp      ] = return address

        Call_Asm_Stack1 GlobalFree_c, 1

; end procedure GlobalFree_asm


align 16
ReadFile_asm:

; [esp + 5*4] = LPOVERLAPPED lpOverlapped
; [esp + 4*4] = LPDWORD lpNumberOfBytesRead
; [esp + 3*4] = DWORD nNumberOfBytesToRead
; [esp + 2*4] = LPVOID lpBuffer
; [esp +   4] = HANDLE hFile
; [esp      ] = return address

        Call_Asm_Stack5 ReadFile_c, 5

; end procedure ReadFile_asm


align 16
ReleaseSemaphore_asm:

; [esp + 3*4] = LPLONG lpPreviousCount
; [esp + 2*4] = LONG lReleaseCount
; [esp +   4] = HANDLE hSemaphore
; [esp      ] = return address

        Call_Asm_Stack3 ReleaseSemaphore_c, 3

; end procedure ReleaseSemaphore_asm


align 16
SetCurrentDirectoryA_asm:

; [esp +   4] = LPCSTR lpPathName
; [esp      ] = return address

        Call_Asm_Stack1 SetCurrentDirectoryA_c, 1

; end procedure SetCurrentDirectoryA_asm


align 16
SetFilePointer_asm:

; [esp + 4*4] = DWORD dwMoveMethod
; [esp + 3*4] = PLONG lpDistanceToMoveHigh
; [esp + 2*4] = LONG lDistanceToMove
; [esp +   4] = HANDLE hFile
; [esp      ] = return address

        Call_Asm_Stack4 SetFilePointer_c, 4

; end procedure SetFilePointer_asm


align 16
SetThreadPriority_asm:

; [esp + 2*4] = int nPriority
; [esp +   4] = HANDLE hThread
; [esp      ] = return address

        Call_Asm_Stack2 SetThreadPriority_c, 2

; end procedure SetThreadPriority_asm


align 16
WaitForSingleObject_asm:

; [esp + 2*4] = DWORD dwMilliseconds
; [esp +   4] = HANDLE hHandle
; [esp      ] = return address

        Call_Asm_Stack2 WaitForSingleObject_c, 2

; end procedure WaitForSingleObject_asm


%ifidn __OUTPUT_FORMAT__, win64
section_end:

section .pdata rdata align=4
        P_UNWIND_INFO section_prolog, section_end, x_common
section .xdata rdata align=8
align 8
x_common:
        X_UNWIND_INFO section_prolog
%endif
