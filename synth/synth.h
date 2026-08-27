/**
 *
 *  Copyright (C) 2026 Roman Pauer
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of
 *  this software and associated documentation files (the "Software"), to deal in
 *  the Software without restriction, including without limitation the rights to
 *  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 *  of the Software, and to permit persons to whom the Software is furnished to do
 *  so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 */

#if !defined(_SYNTH_H_INCLUDED_)
#define _SYNTH_H_INCLUDED_

#include <stdint.h>

#if defined(__GNUC__) && (defined(__i386) || (defined(__x86_64) && defined(_WIN32)))
    #define CCALL __attribute__ ((__cdecl__))
#elif defined(_MSC_VER)
    #define CCALL __cdecl
#else
    #define CCALL
#endif

enum CS_OUTPUT
{
    CS_OUTPUT_GenerateAudio = 2
};

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t samples_per_call;
extern uint32_t bytes_per_call;
extern uint8_t audio_data[1024];

extern uint32_t CCALL CS_SynthesizerActivate(void *hwnd, uint32_t output_type, uint32_t unused1, uint32_t unused2, uint8_t *settings, char *unused3);
extern uint32_t CCALL CS_SynthesizerDeactivate(void);
extern void CCALL CS_SynthesizerMidi(const uint8_t *midi_bytes_ptr, uint32_t midi_bytes_num);
extern void CCALL CS_ProcessEventsAndGenerateAudio(void);

#ifdef __cplusplus
}
#endif

#endif /* _SYNTH_H_INCLUDED_ */

