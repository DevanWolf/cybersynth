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

#include "x64_stack.h"
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

extern _stack *x86_initialize_stack(void);
extern void x86_deinitialize_stack(void);

extern uint32_t CCALL c_SynthesizerActivate(_stack *stack, void *hwnd, uint32_t output_type, uint32_t unused1, uint32_t unused2, uint8_t *settings, char *unused3);
extern uint32_t CCALL c_SynthesizerDeactivate(_stack *stack);
extern void CCALL c_SynthesizerMidi(_stack *stack, const uint8_t *midi_bytes_ptr, uint32_t midi_bytes_num);
extern void CCALL c_ProcessEventsAndGenerateAudio(_stack *stack);
extern void CCALL c_run_thread_proc(_stack *stack, void *lpParameter, uint32_t (*lpStartAddress)(void *));

#ifdef __cplusplus
}
#endif


EXTERNC uint32_t CCALL CS_SynthesizerActivate(void *hwnd, uint32_t output_type, uint32_t unused1, uint32_t unused2, uint8_t *settings, char *unused3)
{
    _stack *stack;

    stack = x86_initialize_stack();

    return c_SynthesizerActivate(stack, hwnd, output_type, unused1, unused2, settings, unused3);
}

EXTERNC uint32_t CCALL CS_SynthesizerDeactivate(void)
{
    _stack *stack;

    stack = x86_initialize_stack();

    return c_SynthesizerDeactivate(stack);
}

EXTERNC void CCALL CS_SynthesizerMidi(const uint8_t *midi_bytes_ptr, uint32_t midi_bytes_num)
{
    _stack *stack;

    stack = x86_initialize_stack();

    return c_SynthesizerMidi(stack, midi_bytes_ptr, midi_bytes_num);
}

EXTERNC void CCALL CS_ProcessEventsAndGenerateAudio(void)
{
    _stack *stack;

    stack = x86_initialize_stack();

    c_ProcessEventsAndGenerateAudio(stack);
}

EXTERNC void CCALL run_thread_proc(void *lpParameter, uint32_t (*lpStartAddress)(void *))
{
    _stack *stack;

    stack = x86_initialize_stack();

    c_run_thread_proc(stack, lpParameter, lpStartAddress);
}

