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

#include "WinApi-advapi32.h"
#include <string.h>

#define ERROR_SUCCESS 0
#define ERROR_FILE_NOT_FOUND 2

#define REG_BINARY 3
#define REG_DWORD 4


#ifdef __cplusplus
extern "C" {
#endif
extern unsigned char cs_effects_enabled;
extern unsigned char cs_chorus_enabled;
extern unsigned char cs_reverb_enabled;
extern unsigned char cs_midi_mode; // 0 = CyberSound Mode, 1 = GM Mode, 2 = GS Mode
extern unsigned int cs_number_of_voices; // 0-128
extern unsigned int cs_sound_cache_size; // 2048-16384 kilobytes
extern unsigned char cs_simd_enabled;
#ifdef __cplusplus
}
#endif


int32_t CCALL RegCloseKey_c(void * hKey)
{
    return ERROR_SUCCESS;
}

int32_t CCALL RegCreateKeyExA_c(void * hKey, const char * lpSubKey, uint32_t Reserved, char * lpClass, uint32_t dwOptions, uint32_t samDesired, const void * lpSecurityAttributes, void * phkResult, uint32_t * lpdwDisposition)
{
    return ERROR_SUCCESS;
}

int32_t CCALL RegQueryValueExA_c(void * hKey, const char * lpValueName, uint32_t * lpReserved, uint32_t * lpType, uint8_t * lpData, uint32_t * lpcbData)
{
    if (!strcmp(lpValueName, "Effects"))
    {
        *lpType = REG_BINARY;
        *lpData = cs_effects_enabled ? 1 : 0;
        *lpcbData = 1;
    }
    else if (!strcmp(lpValueName, "Chorus On"))
    {
        *lpType = REG_BINARY;
        *lpData = cs_chorus_enabled ? 1 : 0;
        *lpcbData = 1;
    }
    else if (!strcmp(lpValueName, "Reverb On"))
    {
        *lpType = REG_BINARY;
        *lpData = cs_reverb_enabled ? 1 : 0;
        *lpcbData = 1;
    }
    else if (!strcmp(lpValueName, "GM"))
    {
        *lpType = REG_BINARY;
        *lpData = cs_midi_mode;
        *lpcbData = 1;
    }
    else if (!strcmp(lpValueName, "Stereo"))
    {
        *lpType = REG_BINARY;
        *lpData = 1;
        *lpcbData = 1;
    }
    else if (!strcmp(lpValueName, "Number Of Voices"))
    {
        *lpType = REG_DWORD;
        *(uint32_t *)lpData = cs_number_of_voices;
        *lpcbData = 4;
    }
    else if (!strcmp(lpValueName, "CPU"))
    {
        *lpType = REG_DWORD;
        *(uint32_t *)lpData = 100;
        *lpcbData = 4;
    }
    else if (!strcmp(lpValueName, "Sound Cache"))
    {
        *lpType = REG_DWORD;
        *(uint32_t *)lpData = cs_sound_cache_size * 1024;
        *lpcbData = 4;
    }
    else if (!strcmp(lpValueName, "Chorus Amount"))
    {
        *lpType = REG_DWORD;
        *(uint32_t *)lpData = 16384;
        *lpcbData = 4;
    }
    else if (!strcmp(lpValueName, "Reverb Amount"))
    {
        *lpType = REG_DWORD;
        *(uint32_t *)lpData = 16384;
        *lpcbData = 4;
    }
    else if (!strcmp(lpValueName, "MMX"))
    {
        *lpType = REG_BINARY;
        *lpData = cs_simd_enabled ? 1 : 0;
        *lpcbData = 1;
    }
    else
    {
        return ERROR_FILE_NOT_FOUND;
    }

    return ERROR_SUCCESS;
}

