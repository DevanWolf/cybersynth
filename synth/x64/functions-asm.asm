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

extern SynthesizerActivate
extern SynthesizerDeactivate
extern SynthesizerMidi
extern ProcessEventsAndGenerateAudio


global c_SynthesizerActivate
global c_SynthesizerDeactivate
global c_SynthesizerMidi
global c_ProcessEventsAndGenerateAudio
global c_run_thread_proc


%ifidn __OUTPUT_FORMAT__, win64

%macro PROLOG 0
        SECTION_PROLOG
        mov [rsp+FIRST_PARAMETER_OFFSET], rcx ; store first function parameter in reserved slot
        mov r11d, [rcx] ; load 32-bit stack pointer
%endm

%macro EPILOG 0
        mov rcx, [rsp+FIRST_PARAMETER_OFFSET] ; load first function parameter from reserved slot
        mov [rcx], r11d ; store 32-bit stack pointer
        SECTION_EPILOG
    .end_function: ; end of function for unwinding
%endm

%macro P_UNWIND 1
        P_UNWIND_INFO %1, %1.end_function, x_common
%endm

%else

%macro PROLOG 0
        push rbp ; save non-volatile register on stack
        push rbx ; save non-volatile register on stack
        push rdi ; save first function parameter on stack (which also alignes the stack to 16 bytes)
        mov r11d, [rdi] ; load 32-bit stack pointer
%endm

%macro EPILOG 0
        pop rdi ; restore first function parameter from stack
        mov [rdi], r11d ; store 32-bit stack pointer
        pop rbx ; restore non-volatile register from stack
        pop rbp ; restore non-volatile register from stack
        ret
%endm

%endif


%ifidn __OUTPUT_FORMAT__, elf64
section .note.GNU-stack noalloc noexec nowrite progbits
section .text progbits alloc exec nowrite align=16
%else
section .text code align=16
%endif

align 16
c_SynthesizerActivate:

; [rsp+8]/[rsp+7*8] = char *unused3
; r9/[rsp+6*8] = uint8_t *settings
; r8/[rsp+5*8] = uint32_t unused2
; rcx/r9  = uint32_t unused1
; rdx/r8  = uint32_t output_type
; rsi/rdx = void *hwnd
; rdi/rcx = _stack *stack
; [rsp] = return address

        PROLOG

%ifidn __OUTPUT_FORMAT__, win64
        lea r11d, [r11d-4*6]
        mov dword [r11d], edx
        mov dword [r11d+4], r8d
        mov dword [r11d+2*4], r9d
        mov eax, [rsp+FIRST_PARAMETER_OFFSET+4*8]
        mov dword [r11d+3*4], eax
        mov eax, [rsp+FIRST_PARAMETER_OFFSET+5*8]
        mov dword [r11d+4*4], eax
        mov eax, [rsp+FIRST_PARAMETER_OFFSET+6*8]
        mov dword [r11d+5*4], eax
%else
        mov eax, [rsp+8]
        PUSH32 eax, r9d, r8d, ecx, edx, esi
%endif

        ; stdcall
        CALL SynthesizerActivate

        EPILOG

; end procedure c_SynthesizerActivate

align 16
c_SynthesizerDeactivate:

; rdi/rcx = _stack *stack
; [rsp] = return address

        PROLOG

        ; stdcall
        CALL SynthesizerDeactivate

        EPILOG

; end procedure c_SynthesizerDeactivate

align 16
c_SynthesizerMidi:

; rdx/r8  = uint32_t midi_bytes_num
; rsi/rdx = const uint8_t *midi_bytes_ptr
; rdi/rcx = _stack *stack
; [rsp] = return address

        PROLOG

%ifidn __OUTPUT_FORMAT__, win64
        PUSH32 r8d, edx
%else
        PUSH32 edx, esi
%endif

        ; stdcall
        CALL SynthesizerMidi

        EPILOG

; end procedure c_SynthesizerMidi

align 16
c_ProcessEventsAndGenerateAudio:

; rdi/rcx = _stack *stack
; [rsp] = return address

        PROLOG

        ; stdcall
        CALL ProcessEventsAndGenerateAudio

        EPILOG

; end procedure c_ProcessEventsAndGenerateAudio

align 16
c_run_thread_proc:

; rdx/r8  = uint32_t (WINAPI *lpStartAddress)(void *lpParameter)
; rsi/rdx = void *lpParameter
; rdi/rcx = _stack *stack
; [rsp] = return address

        PROLOG

%ifidn __OUTPUT_FORMAT__, win64
        mov r10d, r8d
        PUSH32 edx

        ; should be stdcall, but it's implemented as ccall
        CALL r10
%else
        PUSH32 esi

        ; should be stdcall, but it's implemented as ccall
        CALL rdx
%endif

        add r11d, byte 4

        EPILOG

; end procedure c_run_thread_proc


%ifidn __OUTPUT_FORMAT__, win64

section .pdata rdata align=4
        P_UNWIND c_SynthesizerActivate
        P_UNWIND c_SynthesizerDeactivate
        P_UNWIND c_SynthesizerMidi
        P_UNWIND c_ProcessEventsAndGenerateAudio

section .xdata rdata align=8
align 8
x_common:
        X_UNWIND_INFO c_SynthesizerActivate

%endif

