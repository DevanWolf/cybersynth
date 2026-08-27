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

#if !defined(_PLATFORM_H_INCLUDED_)
#define _PLATFORM_H_INCLUDED_

#if defined(__GNUC__)
    #if defined(__i386) || (defined(__x86_64) && defined(_WIN32))
        #define CCALL __attribute__ ((__cdecl__))
    #else
        #define CCALL
    #endif
#elif defined(_MSC_VER)
    #define CCALL __cdecl
    #define strcasecmp _stricmp
    #if _MSC_VER < 1900
        #define snprintf _snprintf
    #endif
#else
    #define CCALL
#endif


#if ( \
    defined(__aarch64__) || \
    defined(_M_ARM64) || \
    defined(_M_ARM64EC) \
)
    #define ARMV8 1
#else
    #undef ARMV8
#endif

#if (!defined(ARMV8)) && ( \
    (defined(__ARM_ARCH) && (__ARM_ARCH >= 6)) || \
    (defined(_M_ARM) && (_M_ARM >= 6)) || \
    (defined(__TARGET_ARCH_ARM) && (__TARGET_ARCH_ARM >= 6)) || \
    (defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB >= 3)) \
)
    #define ARMV6 1
#else
    #undef ARMV6
#endif

#if (!defined(ARMV8)) && ( \
    (defined(__ARM_ARCH) && (__ARM_ARCH >= 7)) || \
    (defined(_M_ARM) && (_M_ARM >= 7)) || \
    (defined(__TARGET_ARCH_ARM) && (__TARGET_ARCH_ARM >= 7)) || \
    (defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB >= 4)) \
)
    #define ARMV7 1
#else
    #undef ARMV7
#endif

#if (!defined(ARMV8)) && ( \
    defined(__amd64__) || \
    defined(__amd64) || \
    defined(__x86_64__) || \
    defined(__x86_64) || \
    defined(_M_X64) || \
    defined(_M_AMD64) \
)
    #define X64SSE2 1
#else
    #undef X64SSE2
#endif

#if (!defined(X64SSE2)) && ( \
    defined(__i386) || \
    defined(_M_IX86) || \
    defined(_X86_) || \
    defined(__THW_INTEL__) || \
    defined(__I86__) || \
    defined(__INTEL__) || \
    defined(__386) \
)
    #define X86SSE2 1
#else
    #undef X86SSE2
#endif

#endif /* _PLATFORM_H_INCLUDED_ */
