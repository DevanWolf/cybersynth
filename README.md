# CyberSynth

CyberSynth made by [InVision Interactive, Inc.](https://web.archive.org/web/19970110062458/http://www.cybersound.com/docs/bckrndr1.html) is a [software synthesizer](https://en.wikipedia.org/wiki/Software_synthesizer) that was bundled with some sound cards and is also part of [CyberSound Studio 3.0](https://www.reddit.com/r/chiptunes/comments/9vcuod/sega_sound_librarycybersound_studio_30_download/).

This project uses a disassembled (or statically recompiled) version of the synthesizer to build some tools (like Linux ALSA driver).


The source code is released with [MIT license](https://spdx.org/licenses/MIT.html).

<hr/>

The projects consists of following parts:

* **synth**
  * Disassembled (**x86**) / statically recompiled (**llasm** / **x64**) version of CyberSynth synthesizer.
  * This allows using the software synthesizer on other *CPU* architectures (32-bit, 64-bit) and platforms.
  * 64-bit version only works with 32-bit addresses - the code and all data it uses must be in the first 2GB of memory space.
* **cs_alsadrv**
  * Linux daemon which provides [ALSA](https://en.wikipedia.org/wiki/Advanced_Linux_Sound_Architecture) MIDI sequencer interface using *synth*.
  * It requires the CyberSynth GM datafile *Gmbank.iss* (or other datafiles).
  * Compilation for x86/x64 requires [gcc](https://gcc.gnu.org/)/[clang](https://clang.llvm.org/) and [nasm](https://www.nasm.us/).
  * Compilation for other architectures requires [gcc](https://gcc.gnu.org/)/[clang](https://clang.llvm.org/), [llvm](https://llvm.org/) and [llasm](https://github.com/M-HT/SR/tree/master/llasm) (from [SR project](https://github.com/M-HT/SR)).
* **cs_coredrv**
  * MacOS daemon which provides Core MIDI synthesizer using *synth*.
  * It requires the CyberSynth GM datafile *Gmbank.iss* (or other datafiles).
  * Compilation requires [Xcode](https://developer.apple.com/xcode/) Command Line Tools, [llvm](https://llvm.org/) and [llasm](https://github.com/M-HT/SR/tree/master/llasm) (from [SR project](https://github.com/M-HT/SR)).
* **cs_pcmconvert**
  * Tool to convert [Standard MIDI File](https://www.midi.org/specifications-old/item/standard-midi-files-smf) to *PCM* (*WAV* or *RAW*) using *synth*.
  * It requires the CyberSynth GM datafile *Gmbank.iss* (or other datafiles).
  * Compilation for x86/x64 requires [gcc](https://gcc.gnu.org/)/[clang](https://clang.llvm.org/)/[MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/) and [nasm](https://www.nasm.us/).
  * Compilation for other architectures requires [gcc](https://gcc.gnu.org/)/[clang](https://clang.llvm.org/)/[MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/), [llvm](https://llvm.org/) and [llasm](https://github.com/M-HT/SR/tree/master/llasm) (from [SR project](https://github.com/M-HT/SR)).
* **datafile**
  * CyberSynth GM (General Midi) datafile *Gmbank.iss* (bundled with some sound cards). More datafiles are part of CyberSound Studio 3.0.
* **documentation**
  * MIDI implementation (unofficial)
* **synth-gen**
  * Files required to generate disassembled / statically recompiled version of the synthesizer from original library *CyberSyn.dll* (part of CyberSound Studio 3.0).
  * [SRW tool](https://github.com/M-HT/SR/tree/master/SRW) (from [SR project](https://github.com/M-HT/SR)) is required.
