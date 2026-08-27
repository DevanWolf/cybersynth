;;
;;  Copyright (C) 2019-2026 Roman Pauer
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

extern _CIpow_c


global _CIpow_asm

global _ftol_asm

global EnlargedIntegerMultiply_asm
global ExtendedLargeIntegerDivide_asm
global LargeIntegerShiftRight_asm


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
_CIpow_asm:

; st1   = x
; st0   = y
; [esp] = return address

        Call_Asm_Float2_Float _CIpow_c

; end procedure _CIpow_asm


align 16
_ftol_asm:

; st0   = num
; [esp] = return address

        sub r11d, byte 12
        fstcw [r11d + 10] ; save original control word
        wait
        mov ax, [r11d + 10]
        or ah, 0x0c ; set rounding control to round to zero
        mov [r11d + 8], ax
        fldcw [r11d + 8]
        fistp qword [r11d]
        fldcw [r11d + 10] ; restore original control word
        mov eax, [r11d]
        mov edx, [r11d + 4]
        add r11d, byte 12
        RET

; end procedure _ftol_asm


align 16
EnlargedIntegerMultiply_asm:

; [esp + 2*4] = LONG Multiplier
; [esp +   4] = LONG Multiplicand
; [esp] = return address

        mov eax, [r11d + 4]
        imul dword [r11d + 2*4]
        RET 2*4

; end procedure EnlargedIntegerMultiply_asm


align 16
ExtendedLargeIntegerDivide_asm:

; [esp + 4*4] = ULONG *Remainder
; [esp + 3*4] = ULONG Divisor
; [esp +   4] = LARGE_INTEGER Dividend
; [esp] = return address

        mov rax, [r11d + 4]
        mov ecx, [r11d + 3*4]
        xor rdx, rdx
        div rcx

        mov ecx, [r11d + 4*4]
        or ecx, ecx
        jnz short .write_remainder

        mov rdx, rax
        shr rdx, 32
        mov eax, eax
        RET 4*4

align 4
    .write_remainder:
        mov [ecx], edx
        mov rdx, rax
        shr rdx, 32
        mov eax, eax
        RET 4*4

; end procedure ExtendedLargeIntegerDivide_asm


align 16
LargeIntegerShiftRight_asm:

; [esp + 3*4] = CCHAR  ShiftCount
; [esp +   4] = LARGE_INTEGER LargeInteger
; [esp] = return address

        mov rax, [r11d + 4]
        mov ecx, [r11d + 3*4]
        shr rax, cl
        mov rdx, rax
        shr rdx, 32
        mov eax, eax
        RET 3*4

; end procedure LargeIntegerShiftRight_asm


%ifidn __OUTPUT_FORMAT__, win64
section_end:

section .pdata rdata align=4
        P_UNWIND_INFO section_prolog, section_end, x_common
section .xdata rdata align=8
align 8
x_common:
        X_UNWIND_INFO section_prolog
%endif
