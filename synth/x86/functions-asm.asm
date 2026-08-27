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

extern SynthesizerActivate
extern SynthesizerDeactivate
extern SynthesizerMidi
extern ProcessEventsAndGenerateAudio


global CS_SynthesizerActivate
global _CS_SynthesizerActivate

global CS_SynthesizerDeactivate
global _CS_SynthesizerDeactivate

global CS_SynthesizerMidi
global _CS_SynthesizerMidi

global CS_ProcessEventsAndGenerateAudio
global _CS_ProcessEventsAndGenerateAudio

global run_thread_proc
global _run_thread_proc


%ifidn __OUTPUT_FORMAT__, elf32
section .note.GNU-stack noalloc noexec nowrite progbits
section .text progbits alloc exec nowrite align=16
%else
section .text code align=16
%endif

align 16
CS_SynthesizerActivate:
_CS_SynthesizerActivate:

; [esp + 6*4] = char *unused3
; [esp + 5*4] = uint8_t *settings
; [esp + 4*4] = uint32_t unused2
; [esp + 3*4] = uint32_t unused1
; [esp + 2*4] = uint32_t output_type
; [esp +   4] = void *hwnd
; [esp      ] = return address

        ; __stdcall
        push dword [esp + 6*4]
        push dword [esp + 6*4]
        push dword [esp + 6*4]
        push dword [esp + 6*4]
        push dword [esp + 6*4]
        push dword [esp + 6*4]

        call SynthesizerActivate

        retn

; end procedure CS_SynthesizerActivate

align 16
CS_SynthesizerDeactivate:
_CS_SynthesizerDeactivate:

; [esp      ] = return address

        ; __stdcall
        jmp SynthesizerDeactivate

; end procedure CS_SynthesizerDeactivate

align 16
CS_SynthesizerMidi:
_CS_SynthesizerMidi:

; [esp + 2*4] = uint32_t midi_bytes_num
; [esp +   4] = const uint8_t *midi_bytes_ptr
; [esp      ] = return address

        ; __stdcall
        push dword [esp + 2*4]
        push dword [esp + 2*4]

        call SynthesizerMidi

        retn

; end procedure CS_SynthesizerMidi

align 16
CS_ProcessEventsAndGenerateAudio:
_CS_ProcessEventsAndGenerateAudio:

; [esp      ] = return address

        ; __stdcall
        jmp ProcessEventsAndGenerateAudio

; end procedure CS_ProcessEventsAndGenerateAudio

align 16
run_thread_proc:
_run_thread_proc:

; [esp + 2*4] = uint32_t (WINAPI *lpStartAddress)(void *lpParameter)
; [esp +   4] = void *lpParameter
; [esp      ] = return address

        ; should be stdcall, but it's implemented as ccall
        jmp dword [esp + 2*4]

; end procedure run_thread_proc

