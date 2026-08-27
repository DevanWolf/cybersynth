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

%ifidn __OUTPUT_FORMAT__, win32
    %define cs_volume_multiplier _cs_volume_multiplier
%endif

extern cs_volume_multiplier

extern _ftol_asm
extern _CIpow_asm
extern EnlargedIntegerMultiply_asm
extern ExtendedLargeIntegerDivide_asm
extern LargeIntegerShiftRight_asm


; advapi32.dll
%define RegCloseKey RegCloseKey_asm
%define RegCreateKeyExA RegCreateKeyExA_asm
%define RegQueryValueExA RegQueryValueExA_asm

; dsound.dll
%define DirectSoundCreate DirectSoundCreate_asm

; kernel32.dll
%define CloseHandle CloseHandle_asm
%define CreateDirectoryA CreateDirectoryA_asm
%define CreateFileA CreateFileA_asm
%define CreateSemaphoreA CreateSemaphoreA_asm
%define CreateThread CreateThread_asm
%define FindClose FindClose_asm
%define FindFirstFileA FindFirstFileA_asm
%define FindNextFileA FindNextFileA_asm
%define GetWindowsDirectoryA GetWindowsDirectoryA_asm
%define GlobalAlloc GlobalAlloc_asm
%define GlobalFree GlobalFree_asm
%define ReadFile ReadFile_asm
%define ReleaseSemaphore ReleaseSemaphore_asm
%define SetCurrentDirectoryA SetCurrentDirectoryA_asm
%define SetFilePointer SetFilePointer_asm
%define SetThreadPriority SetThreadPriority_asm
%define WaitForSingleObject WaitForSingleObject_asm

; winmm.dll
%define timeBeginPeriod timeBeginPeriod_asm
%define timeEndPeriod timeEndPeriod_asm
%define timeGetDevCaps timeGetDevCaps_asm
%define timeGetTime timeGetTime_asm
%define timeKillEvent timeKillEvent_asm
%define timeSetEvent timeSetEvent_asm
%define waveOutClose waveOutClose_asm
%define waveOutGetDevCapsA waveOutGetDevCapsA_asm
%define waveOutGetErrorTextA waveOutGetErrorTextA_asm
%define waveOutGetNumDevs waveOutGetNumDevs_asm
%define waveOutGetVolume waveOutGetVolume_asm
%define waveOutOpen waveOutOpen_asm
%define waveOutPrepareHeader waveOutPrepareHeader_asm
%define waveOutReset waveOutReset_asm
%define waveOutUnprepareHeader waveOutUnprepareHeader_asm
%define waveOutWrite waveOutWrite_asm

