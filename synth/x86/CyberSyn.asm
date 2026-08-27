%include "x86inc.inc"
%include "misc.inc"
%include "extern.inc"
global ProcessEventsAndGenerateAudio
global _ProcessEventsAndGenerateAudio
global samples_per_call
global _samples_per_call
global bytes_per_call
global _bytes_per_call
global audio_data
global _audio_data

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

%ifidn __OUTPUT_FORMAT__, elf32
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

%ifidn __OUTPUT_FORMAT__, elf32
section .text progbits alloc exec nowrite align=16
%else
section .text code align=16
%endif
imagebase1000:
global SynthesizerActivate
global _SynthesizerActivate
global SynthesizerDeactivate
global _SynthesizerDeactivate
global SynthesizerPreload
global _SynthesizerPreload
global SynthesizerMidi
global _SynthesizerMidi
global SynthesizerMidiLong
global _SynthesizerMidiLong
global SynthesizerPlayback
global _SynthesizerPlayback
global SynthesizerAllNotesOff
global _SynthesizerAllNotesOff
global SynthesizerReset
global _SynthesizerReset
global SynthesizerControllersReset
global _SynthesizerControllersReset
global SynthesizerStatus
global _SynthesizerStatus
global SynthesizerNumberOfBanks
global _SynthesizerNumberOfBanks
global SynthesizerBankIndexToNumber
global _SynthesizerBankIndexToNumber
global SynthesizerBankNumberToIndex
global _SynthesizerBankNumberToIndex
global SynthesizerBankName
global _SynthesizerBankName
global SynthesizerNumberOfPrograms
global _SynthesizerNumberOfPrograms
global SynthesizerProgramName
global _SynthesizerProgramName
global SynthesizerProgramNumberToIndex
global _SynthesizerProgramNumberToIndex
global SynthesizerProgramIndexToNumber
global _SynthesizerProgramIndexToNumber
global SynthesizerSetMode
global _SynthesizerSetMode
global SynthesizerPlayClick
global _SynthesizerPlayClick
global SynthesizerGetDirectSound
global _SynthesizerGetDirectSound
global SynthesizerVolume
global _SynthesizerVolume
global SynthesizerTrackVolume
global _SynthesizerTrackVolume
global SynthesizerPan
global _SynthesizerPan
global SynthesizerTrackPan
global _SynthesizerTrackPan
%include "seg01.inc"

%ifidn __OUTPUT_FORMAT__, elf32
section .rdata progbits alloc noexec nowrite align=8
%else
section .rdata rdata align=8
%endif
%include "seg02.inc"

%ifidn __OUTPUT_FORMAT__, elf32
section .data progbits alloc noexec write align=4
%else
section .data data align=4
%endif
%include "seg03.inc"

%ifidn __OUTPUT_FORMAT__, elf32
section .bss nobits alloc noexec write align=4
%else
section .bss bss align=4
%endif
%include "seg07.inc"
