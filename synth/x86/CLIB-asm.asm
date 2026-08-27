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

%include "asm-calls.inc"

%ifidn __OUTPUT_FORMAT__, win32
    %define _CIpow_c __CIpow_c
%endif

extern _CIpow_c


global _CIpow_asm

global _ftol_asm

global EnlargedIntegerMultiply_asm
global ExtendedLargeIntegerDivide_asm
global LargeIntegerShiftRight_asm


%ifidn __OUTPUT_FORMAT__, elf32
section .note.GNU-stack noalloc noexec nowrite progbits
section .text progbits alloc exec nowrite align=16
%else
section .text code align=16
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

        sub esp, byte 12
        fstcw [esp + 10] ; save original control word
        wait
        mov ax, [esp + 10]
        or ah, 0x0c ; set rounding control to round to zero
        mov [esp + 8], ax
        fldcw [esp + 8]
        fistp qword [esp]
        fldcw [esp + 10] ; restore original control word
        mov eax, [esp]
        mov edx, [esp + 4]
        add esp, byte 12
        retn

; end procedure _ftol_asm


align 16
EnlargedIntegerMultiply_asm:

; [esp + 2*4] = LONG Multiplier
; [esp +   4] = LONG Multiplicand
; [esp] = return address

        mov eax, [esp + 4]
        imul dword [esp + 2*4]
        retn 2*4

; end procedure EnlargedIntegerMultiply_asm


align 16
ExtendedLargeIntegerDivide_asm:

; [esp + 4*4] = ULONG *Remainder
; [esp + 3*4] = ULONG Divisor
; [esp +   4] = LARGE_INTEGER Dividend
; [esp] = return address

        push esi
        push edi
        push ebx
        mov eax, [esp + 12 + 4]
        mov edx, [esp + 12 + 2*4]
        mov ebx, [esp + 12 + 3*4]
        or ebx, ebx
        jz short .divisor_is_zero

        push ebp
        mov ecx, 64
        xor esi, esi

align 4
    .loop:
        shl eax, 1
        rcl edx, 1
        rcl esi, 1
        sbb edi, edi
        cmp esi, ebx
        cmc
        sbb ebp, ebp
        or edi, ebp
        sub eax, edi
        and edi, ebx
        sub esi, edi
        dec ecx
        jnz short .loop

        pop ebp
        pop ebx
        pop edi
        mov ecx, [esp + 4 + 4*4]
        or ecx, ecx
        jnz short .write_remainder

        pop esi
        retn 4*4

align 4
    .write_remainder:
        mov [ecx], esi
        pop esi
        retn 4*4

    .divisor_is_zero:
        div dword [esp + 12 + 3*4]
        pop ebx
        pop edi
        pop esi
        retn 4*4

; end procedure ExtendedLargeIntegerDivide_asm


align 16
LargeIntegerShiftRight_asm:

; [esp + 3*4] = CCHAR  ShiftCount
; [esp +   4] = LARGE_INTEGER LargeInteger
; [esp] = return address

        mov ecx, [esp + 3*4]
        and ecx, byte 0x3f
        cmp ecx, byte 32
        jae short .large_shift

        mov eax, [esp + 4]
        mov edx, [esp + 2*4]
        shrd eax, edx, cl
        shr edx, cl
        retn 3*4

    .large_shift:
        mov eax, [esp + 2*4]
        xor edx, edx
        shr eax, cl
        retn 3*4

; end procedure LargeIntegerShiftRight_asm

