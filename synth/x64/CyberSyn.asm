%include "x64inc.inc"
%include "misc.inc"
%include "extern.inc"
global ProcessEventsAndGenerateAudio
global samples_per_call
global bytes_per_call
global audio_data

extern DirectSoundCreate ; DSOUND.dll
extern timeGetTime ; WINMM.dll
extern waveOutGetErrorTextA ; WINMM.dll
extern waveOutOpen ; WINMM.dll
extern waveOutPrepareHeader ; WINMM.dll
extern waveOutGetVolume ; WINMM.dll
extern timeKillEvent ; WINMM.dll
extern timeEndPeriod ; WINMM.dll
extern timeGetDevCaps ; WINMM.dll
extern timeBeginPeriod ; WINMM.dll
extern timeSetEvent ; WINMM.dll
extern waveOutWrite ; WINMM.dll
extern waveOutReset ; WINMM.dll
extern waveOutUnprepareHeader ; WINMM.dll
extern waveOutClose ; WINMM.dll
extern waveOutGetNumDevs ; WINMM.dll
extern waveOutGetDevCapsA ; WINMM.dll
extern WaitForSingleObject ; KERNEL32.dll
extern ReleaseSemaphore ; KERNEL32.dll
extern CreateThread ; KERNEL32.dll
extern SetThreadPriority ; KERNEL32.dll
extern CreateSemaphoreA ; KERNEL32.dll
extern GlobalFree ; KERNEL32.dll
extern GlobalAlloc ; KERNEL32.dll
extern CloseHandle ; KERNEL32.dll
extern CreateDirectoryA ; KERNEL32.dll
extern SetCurrentDirectoryA ; KERNEL32.dll
extern GetWindowsDirectoryA ; KERNEL32.dll
extern FindClose ; KERNEL32.dll
extern FindNextFileA ; KERNEL32.dll
extern FindFirstFileA ; KERNEL32.dll
extern ReadFile ; KERNEL32.dll
extern CreateFileA ; KERNEL32.dll
extern SetFilePointer ; KERNEL32.dll
extern RegQueryValueExA ; ADVAPI32.dll
extern RegCreateKeyExA ; ADVAPI32.dll
extern RegCloseKey ; ADVAPI32.dll

%ifidn __OUTPUT_FORMAT__, elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

%ifidn __OUTPUT_FORMAT__, elf64
section .text progbits alloc exec nowrite align=16
%else
section .text code align=16
%endif
%ifidn __OUTPUT_FORMAT__, win64
section_prolog_0:
SECTION_PROLOG
%endif
imagebase1000:
global SynthesizerActivate
global SynthesizerDeactivate
global SynthesizerPreload
global SynthesizerMidi
global SynthesizerMidiLong
global SynthesizerPlayback
global SynthesizerAllNotesOff
global SynthesizerReset
global SynthesizerControllersReset
global SynthesizerStatus
global SynthesizerNumberOfBanks
global SynthesizerBankIndexToNumber
global SynthesizerBankNumberToIndex
global SynthesizerBankName
global SynthesizerNumberOfPrograms
global SynthesizerProgramName
global SynthesizerProgramNumberToIndex
global SynthesizerProgramIndexToNumber
global SynthesizerSetMode
global SynthesizerPlayClick
global SynthesizerGetDirectSound
global SynthesizerVolume
global SynthesizerTrackVolume
global SynthesizerPan
global SynthesizerTrackPan
%include "seg01.inc"
%ifidn __OUTPUT_FORMAT__, win64
section_end_0:
%endif

%ifidn __OUTPUT_FORMAT__, elf64
section .rdata progbits alloc noexec nowrite align=8
%else
section .rdata rdata align=8
%endif
%include "seg02.inc"

%ifidn __OUTPUT_FORMAT__, elf64
section .data progbits alloc noexec write align=4
%else
section .data data align=4
%endif
%include "seg03.inc"

%ifidn __OUTPUT_FORMAT__, elf64
section .bss nobits alloc noexec write align=4
%else
section .bss bss align=4
%endif
%include "seg07.inc"

%ifidn __OUTPUT_FORMAT__, win64
section .pdata rdata align=4
P_UNWIND_INFO section_prolog_0, section_end_0, x_common
section .xdata rdata align=8
align 8
x_common:
X_UNWIND_INFO section_prolog_0
%endif
