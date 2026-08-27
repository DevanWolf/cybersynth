/**
 *
 *  Copyright (C) 2025-2026 Roman Pauer
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

#include "llasm_cpu.h"


#ifdef __cplusplus
extern "C" {
#endif

extern _cpu *x86_initialize_cpu(void);
extern void x86_deinitialize_cpu(void);

extern void CCALL c_SynthesizerActivate(CPU);
extern void CCALL c_SynthesizerDeactivate(CPU);
extern void CCALL c_SynthesizerMidi(CPU);
extern void CCALL c_ProcessEventsAndGenerateAudio(CPU);
extern void CCALL c_run_thread_proc(CPU);

#ifdef __cplusplus
}
#endif


EXTERNC uint32_t CCALL CS_SynthesizerActivate(void *hwnd, uint32_t output_type, uint32_t unused1, uint32_t unused2, uint8_t *settings, char *unused3)
{
    _cpu *cpu;

    cpu = x86_initialize_cpu();

    // stdcall
    esp -= 4;
    *((uint32_t *)REG2PTR(esp)) = PTR2REG(unused3);
    esp -= 4;
    *((uint32_t *)REG2PTR(esp)) = PTR2REG(settings);
    esp -= 4;
    *((uint32_t *)REG2PTR(esp)) = unused2;
    esp -= 4;
    *((uint32_t *)REG2PTR(esp)) = unused1;
    esp -= 4;
    *((uint32_t *)REG2PTR(esp)) = output_type;
    esp -= 4;
    *((uint32_t *)REG2PTR(esp)) = PTR2REG(hwnd);

    c_SynthesizerActivate(cpu);

    return eax;
}

EXTERNC uint32_t CCALL CS_SynthesizerDeactivate(void)
{
    _cpu *cpu;

    cpu = x86_initialize_cpu();

    c_SynthesizerDeactivate(cpu);

    return eax;
}

EXTERNC void CCALL CS_SynthesizerMidi(const uint8_t *midi_bytes_ptr, uint32_t midi_bytes_num)
{
    _cpu *cpu;

    cpu = x86_initialize_cpu();

    // stdcall
    esp -= 4;
    *((uint32_t *)REG2PTR(esp)) = midi_bytes_num;
    esp -= 4;
    *((uint32_t *)REG2PTR(esp)) = PTR2REG(midi_bytes_ptr);

    c_SynthesizerMidi(cpu);
}

EXTERNC void CCALL CS_ProcessEventsAndGenerateAudio(void)
{
    _cpu *cpu;

    cpu = x86_initialize_cpu();

    c_ProcessEventsAndGenerateAudio(cpu);
}

EXTERNC void CCALL run_thread_proc(void *lpParameter, uint32_t (*lpStartAddress)(void *))
{
    _cpu *cpu;

    cpu = x86_initialize_cpu();

    esp -= 4;
    *((uint32_t *)REG2PTR(esp)) = PTR2REG(lpStartAddress);
    esp -= 4;
    *((uint32_t *)REG2PTR(esp)) = PTR2REG(lpParameter);

    // should be stdcall, but it's implemented as ccall
    c_run_thread_proc(cpu);

    esp += 2*4;
}

