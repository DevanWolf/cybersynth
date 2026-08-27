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

%include "asm-calls.inc"

%ifidn __OUTPUT_FORMAT__, win32
    %define RegCloseKey_c _RegCloseKey_c
    %define RegCreateKeyExA_c _RegCreateKeyExA_c
    %define RegQueryValueExA_c _RegQueryValueExA_c
%endif

extern RegCloseKey_c
extern RegCreateKeyExA_c
extern RegQueryValueExA_c

global RegCloseKey_asm
global RegCreateKeyExA_asm
global RegQueryValueExA_asm

%ifidn __OUTPUT_FORMAT__, elf32
section .note.GNU-stack noalloc noexec nowrite progbits
section .text progbits alloc exec nowrite align=16
%else
section .text code align=16
%endif

align 16
RegCloseKey_asm:

; [esp +   4] = HKEY hKey
; [esp      ] = return address

        Call_Asm_Stack1 RegCloseKey_c, 1

; end procedure RegCloseKey_asm


align 16
RegCreateKeyExA_asm:

; [esp + 9*4] = LPDWORD lpdwDisposition
; [esp + 8*4] = PHKEY phkResult
; [esp + 7*4] = CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes
; [esp + 6*4] = REGSAM samDesired
; [esp + 5*4] = DWORD dwOptions
; [esp + 4*4] = LPSTR lpClass
; [esp + 3*4] = DWORD Reserved
; [esp + 2*4] = LPCSTR lpSubKey
; [esp +   4] = HKEY hKey
; [esp      ] = return address

        Call_Asm_Stack9 RegCreateKeyExA_c, 9

; end procedure RegCreateKeyExA_asm


align 16
RegQueryValueExA_asm:

; [esp + 6*4] = LPDWORD lpcbData
; [esp + 5*4] = LPBYTE lpData
; [esp + 4*4] = LPDWORD lpType
; [esp + 3*4] = LPDWORD lpReserved
; [esp + 2*4] = LPCSTR lpValueName
; [esp +   4] = HKEY hKey
; [esp      ] = return address

        Call_Asm_Stack6 RegQueryValueExA_c, 6

; end procedure RegQueryValueExA_asm

