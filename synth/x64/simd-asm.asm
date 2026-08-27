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

extern simd_10007028_c
extern simd_10007104_c
extern simd_100071D0_c
extern simd_1000720B_c
extern simd_100072A3_c
extern simd_1000732F_c
extern simd_10007364_c
extern simd_100073F1_c
extern simd_10007472_c
extern simd_10007491_c
extern simd_100074CD_c
extern simd_10007506_c
extern simd_10007525_c
extern simd_1000758D_c
extern simd_100075CC_c
extern simd_1000A920_c
extern simd_1000AD02_c
extern simd_1000B2EE_c
extern simd_1000B7C9_c

global simd_10007028_asm
global simd_10007104_asm
global simd_100071D0_asm
global simd_1000720B_asm
global simd_100072A3_asm
global simd_1000732F_asm
global simd_10007364_asm
global simd_100073F1_asm
global simd_10007472_asm
global simd_10007491_asm
global simd_100074CD_asm
global simd_10007506_asm
global simd_10007525_asm
global simd_1000758D_asm
global simd_100075CC_asm
global simd_1000A920_asm
global simd_1000AD02_asm
global simd_1000B2EE_asm
global simd_1000B7C9_asm

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
simd_10007028_asm:

; [esp + 11*4] = uint8_t *dst3
; [esp + 10*4] = uint8_t *dst2
; [esp + 9*4] = uint8_t *dst1
; [esp + 8*4] = uint8_t *tmp
; [esp + 7*4] = uint32_t mult5
; [esp + 6*4] = uint32_t mult4
; [esp + 5*4] = uint32_t mult3
; [esp + 4*4] = uint32_t mult2
; [esp + 3*4] = uint32_t mult1
; [esp + 2*4] = int32_t counter
; [esp +   4] = uint8_t *src
; [esp      ] = return address

        Call_Asm_Stack11 simd_10007028_c

; end procedure simd_10007028_asm


align 16
simd_10007104_asm:

; [esp + 11*4] = uint8_t *dst3
; [esp + 10*4] = uint8_t *dst2
; [esp + 9*4] = uint8_t *dst1
; [esp + 8*4] = uint8_t *tmp
; [esp + 7*4] = uint32_t mult5
; [esp + 6*4] = uint32_t mult4
; [esp + 5*4] = uint32_t mult3
; [esp + 4*4] = uint32_t mult2
; [esp + 3*4] = uint32_t mult1
; [esp + 2*4] = int32_t counter
; [esp +   4] = uint8_t *src
; [esp      ] = return address

        Call_Asm_Stack11 simd_10007104_c

; end procedure simd_10007104_asm


align 16
simd_100071D0_asm:

; [esp + 4*4] = uint8_t *dst3
; [esp + 3*4] = uint8_t *dst2
; [esp + 2*4] = uint8_t *dst1
; [esp +   4] = int32_t counter
; [esp      ] = return address

        Call_Asm_Stack4 simd_100071D0_c

; end procedure simd_100071D0_asm


align 16
simd_1000720B_asm:

; [esp + 8*4] = uint8_t *dst3
; [esp + 7*4] = uint8_t *dst2
; [esp + 6*4] = uint8_t *dst1
; [esp + 5*4] = uint32_t mult3
; [esp + 4*4] = uint32_t mult2
; [esp + 3*4] = uint32_t mult1
; [esp + 2*4] = int32_t counter
; [esp +   4] = uint8_t *src
; [esp      ] = return address

        Call_Asm_Stack8 simd_1000720B_c

; end procedure simd_1000720B_asm


align 16
simd_100072A3_asm:

; [esp + 8*4] = uint8_t *dst3
; [esp + 7*4] = uint8_t *dst2
; [esp + 6*4] = uint8_t *dst1
; [esp + 5*4] = uint32_t mult3
; [esp + 4*4] = uint32_t mult2
; [esp + 3*4] = uint32_t mult1
; [esp + 2*4] = int32_t counter
; [esp +   4] = uint8_t *src
; [esp      ] = return address

        Call_Asm_Stack8 simd_100072A3_c

; end procedure simd_100072A3_asm


align 16
simd_1000732F_asm:

; [esp + 4*4] = uint8_t *dst3
; [esp + 3*4] = uint8_t *dst2
; [esp + 2*4] = uint8_t *dst1
; [esp +   4] = int32_t counter
; [esp      ] = return address

        Call_Asm_Stack4 simd_1000732F_c

; end procedure simd_1000732F_asm


align 16
simd_10007364_asm:

; [esp + 6*4] = uint8_t *dst
; [esp + 5*4] = uint32_t mult3
; [esp + 4*4] = uint32_t mult2
; [esp + 3*4] = uint32_t mult1
; [esp + 2*4] = int32_t counter
; [esp +   4] = uint8_t *src
; [esp      ] = return address

        Call_Asm_Stack6 simd_10007364_c

; end procedure simd_10007364_asm


align 16
simd_100073F1_asm:

; [esp + 6*4] = uint8_t *dst
; [esp + 5*4] = uint32_t mult3
; [esp + 4*4] = uint32_t mult2
; [esp + 3*4] = uint32_t mult1
; [esp + 2*4] = int32_t counter
; [esp +   4] = uint8_t *src
; [esp      ] = return address

        Call_Asm_Stack6 simd_100073F1_c

; end procedure simd_100073F1_asm


align 16
simd_10007472_asm:

; [esp + 2*4] = uint8_t *dst
; [esp +   4] = int32_t counter
; [esp      ] = return address

        Call_Asm_Stack2 simd_10007472_c

; end procedure simd_10007472_asm


align 16
simd_10007491_asm:

; [esp + 4*4] = uint8_t *dst
; [esp + 3*4] = uint32_t mult
; [esp + 2*4] = int32_t counter
; [esp +   4] = uint8_t *src
; [esp      ] = return address

        Call_Asm_Stack4 simd_10007491_c

; end procedure simd_10007491_asm


align 16
simd_100074CD_asm:

; [esp + 4*4] = uint8_t *dst
; [esp + 3*4] = uint32_t mult
; [esp + 2*4] = int32_t counter
; [esp +   4] = uint8_t *src
; [esp      ] = return address

        Call_Asm_Stack4 simd_100074CD_c

; end procedure simd_100074CD_asm


align 16
simd_10007506_asm:

; [esp + 2*4] = uint8_t *dst
; [esp +   4] = int32_t counter
; [esp      ] = return address

        Call_Asm_Stack2 simd_10007506_c

; end procedure simd_10007506_asm


align 16
simd_10007525_asm:

; [esp + 4*4] = uint8_t *src
; [esp + 3*4] = uint8_t *dst
; [esp + 2*4] = int32_t multadd2
; [esp +   4] = int32_t counter1
; [esp      ] = return address

        Call_Asm_Stack4 simd_10007525_c

; end procedure simd_10007525_asm


align 16
simd_1000758D_asm:

; [esp + 4*4] = uint8_t *src
; [esp + 3*4] = uint8_t *dst
; [esp + 2*4] = int32_t multadd2
; [esp +   4] = int32_t counter1
; [esp      ] = return address

        Call_Asm_Stack4 simd_1000758D_c

; end procedure simd_1000758D_asm


align 16
simd_100075CC_asm:

; [esp + 4*4] = uint8_t *src
; [esp + 3*4] = uint8_t *dst
; [esp + 2*4] = uint32_t shift
; [esp +   4] = int32_t counter
; [esp      ] = return address

        Call_Asm_Stack4 simd_100075CC_c

; end procedure simd_100075CC_asm


align 16
simd_1000A920_asm:

; [esp + 8*4] = uint8_t *src
; [esp + 7*4] = uint8_t *dst
; [esp + 6*4] = uint32_t *data3
; [esp + 5*4] = uint32_t *data2
; [esp + 4*4] = uint16_t *data1
; [esp + 3*4] = uint16_t *params2
; [esp + 2*4] = int16_t *params1
; [esp +   4] = int32_t counter1
; [esp      ] = return address

        Call_Asm_Stack8 simd_1000A920_c

; end procedure simd_1000A920_asm


align 16
simd_1000AD02_asm:

; [esp + 8*4] = uint8_t *src
; [esp + 7*4] = uint8_t *dst
; [esp + 6*4] = uint32_t *data3
; [esp + 5*4] = uint32_t *data2
; [esp + 4*4] = uint16_t *data1
; [esp + 3*4] = uint16_t *params2
; [esp + 2*4] = int16_t *params1
; [esp +   4] = int32_t counter1
; [esp      ] = return address

        Call_Asm_Stack8 simd_1000AD02_c

; end procedure simd_1000AD02_asm


align 16
simd_1000B2EE_asm:

; [esp + 6*4] = uint8_t *src
; [esp + 5*4] = uint8_t *dst
; [esp + 4*4] = uint8_t *params3
; [esp + 3*4] = uint16_t *data
; [esp + 2*4] = uint8_t *params2
; [esp +   4] = uint8_t *params1
; [esp      ] = return address

        Call_Asm_Stack6 simd_1000B2EE_c

; end procedure simd_1000B2EE_asm


align 16
simd_1000B7C9_asm:

; [esp + 6*4] = uint8_t *src
; [esp + 5*4] = uint8_t *dst
; [esp + 4*4] = uint8_t *params3
; [esp + 3*4] = uint16_t *data
; [esp + 2*4] = uint8_t *params2
; [esp +   4] = uint8_t *params1
; [esp      ] = return address

        Call_Asm_Stack6 simd_1000B7C9_c

; end procedure simd_1000B7C9_asm


%ifidn __OUTPUT_FORMAT__, win64
section_end:

section .pdata rdata align=4
        P_UNWIND_INFO section_prolog, section_end, x_common
section .xdata rdata align=8
align 8
x_common:
        X_UNWIND_INFO section_prolog
%endif
