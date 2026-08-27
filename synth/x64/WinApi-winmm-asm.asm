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

extern timeBeginPeriod_c
extern timeEndPeriod_c
extern timeGetDevCaps_c
extern timeGetTime_c
extern timeKillEvent_c
extern timeSetEvent_c
extern waveOutClose_c
extern waveOutGetDevCapsA_c
extern waveOutGetErrorTextA_c
extern waveOutGetNumDevs_c
extern waveOutGetVolume_c
extern waveOutOpen_c
extern waveOutPrepareHeader_c
extern waveOutReset_c
extern waveOutUnprepareHeader_c
extern waveOutWrite_c

global timeBeginPeriod_asm
global timeEndPeriod_asm
global timeGetDevCaps_asm
global timeGetTime_asm
global timeKillEvent_asm
global timeSetEvent_asm
global waveOutClose_asm
global waveOutGetDevCapsA_asm
global waveOutGetErrorTextA_asm
global waveOutGetNumDevs_asm
global waveOutGetVolume_asm
global waveOutOpen_asm
global waveOutPrepareHeader_asm
global waveOutReset_asm
global waveOutUnprepareHeader_asm
global waveOutWrite_asm

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
timeBeginPeriod_asm:

; [esp +   4] = UINT uPeriod
; [esp      ] = return address

        Call_Asm_Stack1 timeBeginPeriod_c, 1

; end procedure timeBeginPeriod_asm


align 16
timeEndPeriod_asm:

; [esp +   4] = UINT uPeriod
; [esp      ] = return address

        Call_Asm_Stack1 timeEndPeriod_c, 1

; end procedure timeEndPeriod_asm


align 16
timeGetDevCaps_asm:

; [esp + 2*4] = UINT cbtc
; [esp +   4] = LPTIMECAPS ptc
; [esp      ] = return address

        Call_Asm_Stack2 timeGetDevCaps_c, 2

; end procedure timeGetDevCaps_asm


align 16
timeGetTime_asm:

; [esp      ] = return address

        Call_Asm_Stack0 timeGetTime_c

; end procedure timeGetTime_asm


align 16
timeKillEvent_asm:

; [esp +   4] = UINT uTimerID
; [esp      ] = return address

        Call_Asm_Stack1 timeKillEvent_c, 1

; end procedure timeKillEvent_asm


align 16
timeSetEvent_asm:

; [esp + 5*4] = UINT fuEvent
; [esp + 4*4] = DWORD_PTR dwUser
; [esp + 3*4] = LPTIMECALLBACK fptc
; [esp + 2*4] = UINT uResolution
; [esp +   4] = UINT uDelay
; [esp      ] = return address

        Call_Asm_Stack5 timeSetEvent_c, 5

; end procedure timeSetEvent_asm


align 16
waveOutClose_asm:

; [esp +   4] = HWAVEOUT hwo
; [esp      ] = return address

        Call_Asm_Stack1 waveOutClose_c, 1

; end procedure waveOutClose_asm


align 16
waveOutGetDevCapsA_asm:

; [esp + 3*4] = UINT cbwoc
; [esp + 2*4] = LPWAVEOUTCAPSA pwoc
; [esp +   4] = UINT_PTR uDeviceID
; [esp      ] = return address

        Call_Asm_Stack3 waveOutGetDevCapsA_c, 3

; end procedure waveOutGetDevCapsA_asm


align 16
waveOutGetErrorTextA_asm:

; [esp + 3*4] = UINT cchText
; [esp + 2*4] = LPSTR pszText
; [esp +   4] = MMRESULT mmrError
; [esp      ] = return address

        Call_Asm_Stack3 waveOutGetErrorTextA_c, 3

; end procedure waveOutGetErrorTextA_asm


align 16
waveOutGetNumDevs_asm:

; [esp      ] = return address

        Call_Asm_Stack0 waveOutGetNumDevs_c

; end procedure waveOutGetNumDevs_asm


align 16
waveOutGetVolume_asm:

; [esp + 2*4] = LPDWORD pdwVolume
; [esp +   4] = HWAVEOUT hwo
; [esp      ] = return address

        Call_Asm_Stack2 waveOutGetVolume_c, 2

; end procedure waveOutGetVolume_asm


align 16
waveOutOpen_asm:

; [esp + 6*4] = DWORD fdwOpen
; [esp + 5*4] = DWORD_PTR dwInstance
; [esp + 4*4] = DWORD_PTR dwCallback
; [esp + 3*4] = LPCWAVEFORMATEX pwfx
; [esp + 2*4] = UINT uDeviceID
; [esp +   4] = LPHWAVEOUT phwo
; [esp      ] = return address

        Call_Asm_Stack6 waveOutOpen_c, 6

; end procedure waveOutOpen_asm


align 16
waveOutPrepareHeader_asm:

; [esp + 3*4] = UINT cbwh
; [esp + 2*4] = LPWAVEHDR pwh
; [esp +   4] = HWAVEOUT hwo
; [esp      ] = return address

        Call_Asm_Stack3 waveOutPrepareHeader_c, 3

; end procedure waveOutPrepareHeader_asm


align 16
waveOutReset_asm:

; [esp +   4] = HWAVEOUT hwo
; [esp      ] = return address

        Call_Asm_Stack1 waveOutReset_c, 1

; end procedure waveOutReset_asm


align 16
waveOutUnprepareHeader_asm:

; [esp + 3*4] = UINT cbwh
; [esp + 2*4] = LPWAVEHDR pwh
; [esp +   4] = HWAVEOUT hwo
; [esp      ] = return address

        Call_Asm_Stack3 waveOutUnprepareHeader_c, 3

; end procedure waveOutUnprepareHeader_asm


align 16
waveOutWrite_asm:

; [esp + 3*4] = UINT cbwh
; [esp + 2*4] = LPWAVEHDR pwh
; [esp +   4] = HWAVEOUT hwo
; [esp      ] = return address

        Call_Asm_Stack3 waveOutWrite_c, 3

; end procedure waveOutWrite_asm


%ifidn __OUTPUT_FORMAT__, win64
section_end:

section .pdata rdata align=4
        P_UNWIND_INFO section_prolog, section_end, x_common
section .xdata rdata align=8
align 8
x_common:
        X_UNWIND_INFO section_prolog
%endif
