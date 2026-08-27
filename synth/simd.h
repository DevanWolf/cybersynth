/**
 *
 *  Copyright (C) 2026 Roman Pauer
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of
 *  this software and associated documentation files (the "Software"), to deal in
 *  the Software without RESTRICTion, including without limitation the rights to
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

#if !defined(_SIMD_H_INCLUDED_)
#define _SIMD_H_INCLUDED_

#include <stdint.h>
#include "platform.h"

#if (defined(_MSC_VER) && _MSC_VER < 1900) || (defined(__cplusplus))
    #define RESTRICT __restrict
#else
    #define RESTRICT restrict
#endif

#ifdef __cplusplus
extern "C" {
#endif

// unless otherwise noted, pointer arguments are allocated with function GlobalAlloc_c and are expected to be aligned for simd processing
// which means that function GlobalAlloc_c must return pointers aligned for simd processing

void CCALL simd_10007028_c(uint8_t * RESTRICT src, int32_t counter, uint32_t mult1, uint32_t mult2, uint32_t mult3, uint32_t mult4, uint32_t mult5, uint8_t * RESTRICT tmp, uint8_t * RESTRICT dst1, uint8_t * RESTRICT dst2, uint8_t * RESTRICT dst3); // tmp is aligned to 8 bytes
void CCALL simd_10007104_c(uint8_t * RESTRICT src, int32_t counter, uint32_t mult1, uint32_t mult2, uint32_t mult3, uint32_t mult4, uint32_t mult5, uint8_t * RESTRICT tmp, uint8_t * RESTRICT dst1, uint8_t * RESTRICT dst2, uint8_t * RESTRICT dst3); // tmp is aligned to 8 bytes
void CCALL simd_100071D0_c(int32_t counter, uint8_t * RESTRICT dst1, uint8_t * RESTRICT dst2, uint8_t * RESTRICT dst3);
void CCALL simd_1000720B_c(uint8_t * RESTRICT src, int32_t counter, uint32_t mult1, uint32_t mult2, uint32_t mult3, uint8_t * RESTRICT dst1, uint8_t * RESTRICT dst2, uint8_t * RESTRICT dst3);
void CCALL simd_100072A3_c(uint8_t * RESTRICT src, int32_t counter, uint32_t mult1, uint32_t mult2, uint32_t mult3, uint8_t * RESTRICT dst1, uint8_t * RESTRICT dst2, uint8_t * RESTRICT dst3);
void CCALL simd_1000732F_c(int32_t counter, uint8_t * RESTRICT dst1, uint8_t * RESTRICT dst2, uint8_t * RESTRICT dst3);
void CCALL simd_10007364_c(uint8_t * RESTRICT src, int32_t counter, uint32_t mult1, uint32_t mult2, uint32_t mult3, uint8_t * RESTRICT dst);
void CCALL simd_100073F1_c(uint8_t * RESTRICT src, int32_t counter, uint32_t mult1, uint32_t mult2, uint32_t mult3, uint8_t * RESTRICT dst);
void CCALL simd_10007472_c(int32_t counter, uint8_t * RESTRICT dst);
void CCALL simd_10007491_c(uint8_t * RESTRICT src, int32_t counter, uint32_t mult, uint8_t * RESTRICT dst);
void CCALL simd_100074CD_c(uint8_t * RESTRICT src, int32_t counter, uint32_t mult, uint8_t * RESTRICT dst);
void CCALL simd_10007506_c(int32_t counter, uint8_t * RESTRICT dst);
void CCALL simd_10007525_c(int32_t counter1, int32_t multadd2, uint8_t * RESTRICT dst, uint8_t * RESTRICT src);
void CCALL simd_1000758D_c(int32_t counter1, int32_t multadd2, uint8_t * RESTRICT dst, uint8_t * RESTRICT src);
void CCALL simd_100075CC_c(int32_t counter, uint32_t shift, uint8_t * RESTRICT dst, uint8_t * RESTRICT src); // dst is audio_data, which is aligned to 4 bytes

// reverb
void CCALL simd_1000A920_c(int32_t counter1, int16_t * RESTRICT params1, uint16_t * RESTRICT params2, uint16_t * RESTRICT data1, uint32_t * RESTRICT data2, uint32_t * RESTRICT data3, uint8_t * RESTRICT dst, uint8_t * RESTRICT src); // params1, data1, data2, data3 are aligned to 8 bytes, params2 is aligned to 2 bytes
void CCALL simd_1000AD02_c(int32_t counter1, int16_t * RESTRICT params1, uint16_t * RESTRICT params2, uint16_t * RESTRICT data1, uint32_t * RESTRICT data2, uint32_t * RESTRICT data3, uint8_t * RESTRICT dst, uint8_t * RESTRICT src); // params1, data1, data2, data3 are aligned to 8 bytes, params2 is aligned to 2 bytes

// chorus
void CCALL simd_1000B2EE_c(uint8_t * RESTRICT params1, uint8_t * RESTRICT params2, uint16_t * RESTRICT data, uint8_t * RESTRICT params3, uint8_t * RESTRICT dst, uint8_t * RESTRICT src); // params1, params2, params3 are aligned to 8 bytes, data is aligned to 2 bytes
void CCALL simd_1000B7C9_c(uint8_t * RESTRICT params1, uint8_t * RESTRICT params2, uint16_t * RESTRICT data, uint8_t * RESTRICT params3, uint8_t * RESTRICT dst, uint8_t * RESTRICT src); // params1, params2, params3 are aligned to 8 bytes, data is aligned to 2 bytes

#ifdef __cplusplus
}
#endif

#endif /* _SIMD_H_INCLUDED_ */

