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

#include "WinApi-winmm.h"
#include <stdio.h>
#include <stdlib.h>


#define eprintf(...) fprintf(stderr,__VA_ARGS__)


#ifdef __cplusplus
extern "C"
#endif
uint32_t CCALL CS_GetTime(void);


int32_t CCALL timeBeginPeriod_c(uint32_t uPeriod)
{
    eprintf("Unimplemented: %s\n", "timeBeginPeriod");
    exit(1);
    //return timeBeginPeriod(uPeriod);
}

int32_t CCALL timeEndPeriod_c(uint32_t uPeriod)
{
    eprintf("Unimplemented: %s\n", "timeEndPeriod");
    exit(1);
    //return timeEndPeriod(uPeriod);
}

int32_t CCALL timeGetDevCaps_c(void * ptc, uint32_t cbtc)
{
    eprintf("Unimplemented: %s\n", "timeGetDevCaps");
    exit(1);
    //return timeGetDevCaps((LPTIMECAPS)ptc, cbtc);
}

uint32_t CCALL timeGetTime_c(void)
{
    return CS_GetTime();
}

int32_t CCALL timeKillEvent_c(uint32_t uTimerID)
{
    eprintf("Unimplemented: %s\n", "timeKillEvent");
    exit(1);
    //return timeKillEvent(uTimerID);
}

int32_t CCALL timeSetEvent_c(uint32_t uDelay, uint32_t uResolution, void * fptc, uint32_t * dwUser, uint32_t fuEvent)
{
    eprintf("Unimplemented: %s\n", "timeSetEvent");
    exit(1);
    //return timeSetEvent(uDelay, uResolution, (LPTIMECALLBACK)fptc, (DWORD_PTR)dwUser, fuEvent);
}

int32_t CCALL waveOutClose_c(void * hwo)
{
    eprintf("Unimplemented: %s\n", "waveOutClose");
    exit(1);
    //return waveOutClose((HWAVEOUT)hwo);
}

int32_t CCALL waveOutGetDevCapsA_c(uint32_t * uDeviceID, void * pwoc, uint32_t cbwoc)
{
    eprintf("Unimplemented: %s\n", "waveOutGetDevCapsA");
    exit(1);
    //return waveOutGetDevCapsA((UINT_PTR)uDeviceID, (LPWAVEOUTCAPSA)pwoc, cbwoc);
}

int32_t CCALL waveOutGetErrorTextA_c(int32_t mmrError, char * pszText, uint32_t cchText)
{
    eprintf("Unimplemented: %s\n", "waveOutGetErrorTextA");
    exit(1);
    //return waveOutGetErrorTextA(mmrError, pszText, cchText);
}

uint32_t CCALL waveOutGetNumDevs_c(void)
{
    eprintf("Unimplemented: %s\n", "waveOutGetNumDevs");
    exit(1);
    //return waveOutGetNumDevs();
}

int32_t CCALL waveOutGetVolume_c(void * hwo, uint32_t * pdwVolume)
{
    eprintf("Unimplemented: %s\n", "waveOutGetVolume");
    exit(1);
    //return waveOutGetVolume((HWAVEOUT)hwo, (LPDWORD)pdwVolume);
}

int32_t CCALL waveOutOpen_c(PTR32(void) * phwo, uint32_t uDeviceID, const void * pwfx, uint32_t * dwCallback, uint32_t * dwInstance, uint32_t fdwOpen)
{
    eprintf("Unimplemented: %s\n", "waveOutOpen");
    exit(1);
    //return waveOutOpen((LPHWAVEOUT)phwo, uDeviceID, (LPCWAVEFORMATEX)pwfx, (DWORD_PTR)dwCallback, (DWORD_PTR)dwInstance, fdwOpen);
}

int32_t CCALL waveOutPrepareHeader_c(void * hwo, void * pwh, uint32_t cbwh)
{
    eprintf("Unimplemented: %s\n", "waveOutPrepareHeader");
    exit(1);
    //return waveOutPrepareHeader((HWAVEOUT)hwo, (LPWAVEHDR)pwh, cbwh);
}

int32_t CCALL waveOutReset_c(void * hwo)
{
    eprintf("Unimplemented: %s\n", "waveOutReset");
    exit(1);
    //return waveOutReset((HWAVEOUT)hwo);
}

int32_t CCALL waveOutUnprepareHeader_c(void * hwo, void * pwh, uint32_t cbwh)
{
    eprintf("Unimplemented: %s\n", "waveOutUnprepareHeader");
    exit(1);
    //return waveOutUnprepareHeader((HWAVEOUT)hwo, (LPWAVEHDR)pwh, cbwh);
}

int32_t CCALL waveOutWrite_c(void * hwo, void * pwh, uint32_t cbwh)
{
    eprintf("Unimplemented: %s\n", "waveOutWrite");
    exit(1);
    //return waveOutWrite((HWAVEOUT)hwo, (LPWAVEHDR)pwh, cbwh);
}

