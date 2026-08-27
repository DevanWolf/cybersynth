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

#include "simd.h"
#include "ptr32.h"

#if defined(__GNUC__)
    #define UNLIKELY_COND(x) __builtin_expect(!!(x), 0)
#else
    #define UNLIKELY_COND(x) x
#endif

#if __cplusplus >= 202002L || (_MSC_VER >= 1926 && _MSVC_LANG >= 202002L)
    #define UNLIKELY_ATTR [[unlikely]]
#else
    #define UNLIKELY_ATTR
#endif


#ifdef __cplusplus
extern "C" {
#endif
extern int32_t cs_volume_multiplier; // linear volume multiplier in fixed-point format s.4.11
#ifdef __cplusplus
}
#endif


#if !defined(X86SSE2) && !defined(X64SSE2) && !defined(ARMV8) && !defined(ARMV7)

#if defined(_MSC_VER)

static __inline uint64_t unaligned_read_64(void *adr)
{
    uint64_t __unaligned *uptr = (uint64_t __unaligned *)adr;
    return *uptr;
}

static __inline void unaligned_write_64(void *adr, uint64_t val)
{
    uint64_t __unaligned *uptr = (uint64_t __unaligned *)adr;
    *uptr = val;
}

#else

typedef struct {
    uint64_t u;
} __attribute__((__packed__)) _unaligned64;

static inline uint64_t unaligned_read_64(void *adr)
{
    _unaligned64 *uptr = (_unaligned64 *)adr;
    return uptr->u;
}

static inline void unaligned_write_64(void *adr, uint64_t val)
{
    _unaligned64 *uptr = (_unaligned64 *)adr;
    uptr->u = val;
}

#endif

#endif

#if defined(X86SSE2) || defined(X64SSE2)
#include "simd_sse2.h"
#elif defined(ARMV8) || defined(ARMV7)
#include "simd_neon.h"
#elif defined(ARMV6)
#include "simd_armdsp.h"
#else
#include "simd_other.h"
#endif

