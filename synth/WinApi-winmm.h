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

#if !defined(_WINAPI_WINMM_H_INCLUDED_)
#define _WINAPI_WINMM_H_INCLUDED_

#include "ptr32.h"
#include "platform.h"

#ifdef __cplusplus
extern "C" {
#endif

int32_t CCALL timeBeginPeriod_c(uint32_t uPeriod);
int32_t CCALL timeEndPeriod_c(uint32_t uPeriod);
int32_t CCALL timeGetDevCaps_c(void * ptc, uint32_t cbtc);
uint32_t CCALL timeGetTime_c(void);
int32_t CCALL timeKillEvent_c(uint32_t uTimerID);
int32_t CCALL timeSetEvent_c(uint32_t uDelay, uint32_t uResolution, void * fptc, uint32_t * dwUser, uint32_t fuEvent);
int32_t CCALL waveOutClose_c(void * hwo);
int32_t CCALL waveOutGetDevCapsA_c(uint32_t * uDeviceID, void * pwoc, uint32_t cbwoc);
int32_t CCALL waveOutGetErrorTextA_c(int32_t mmrError, char * pszText, uint32_t cchText);
uint32_t CCALL waveOutGetNumDevs_c(void);
int32_t CCALL waveOutGetVolume_c(void * hwo, uint32_t * pdwVolume);
int32_t CCALL waveOutOpen_c(PTR32(void) * phwo, uint32_t uDeviceID, const void * pwfx, uint32_t * dwCallback, uint32_t * dwInstance, uint32_t fdwOpen);
int32_t CCALL waveOutPrepareHeader_c(void * hwo, void * pwh, uint32_t cbwh);
int32_t CCALL waveOutReset_c(void * hwo);
int32_t CCALL waveOutUnprepareHeader_c(void * hwo, void * pwh, uint32_t cbwh);
int32_t CCALL waveOutWrite_c(void * hwo, void * pwh, uint32_t cbwh);

#ifdef __cplusplus
}
#endif

#endif

