#ifndef _BASETYPS_H
#define _BASETYPS_H

#if defined( __OS2__ )
  #define DLLEXPORT __declspec(dllexport) _System
#elif defined( ENV_HAVE_GCCVISIBILITYPATCH )
  #define DLLEXPORT __attribute__ ((visibility("default")))
#else
  #define DLLEXPORT
#endif

#ifdef __cplusplus
#define STDAPI extern "C" DLLEXPORT HRESULT
#else
#define STDAPI extern DLLEXPORT HRESULT
#endif  /* __cplusplus */ 

typedef GUID IID;
typedef GUID CLSID;
#endif

