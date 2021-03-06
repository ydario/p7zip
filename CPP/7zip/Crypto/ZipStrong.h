// Crypto/ZipStrong.h

#ifndef __CRYPTO_ZIP_STRONG_H
#define __CRYPTO_ZIP_STRONG_H

#include "../../Common/MyBuffer.h"

#include "../IPassword.h"

#include "MyAes.h"

namespace NCrypto {
namespace NZipStrong {

/* ICompressFilter::Init() does nothing for this filter.
  Call to init:
    Decoder:
      [CryptoSetPassword();]
      ReadHeader();
      [CryptoSetPassword();] Init_and_CheckPassword();
      [CryptoSetPassword();] Init_and_CheckPassword();
*/

struct CKeyInfo
{
  Byte MasterKey[32];
  UInt32 KeySize;
  
  void SetPassword(const Byte *data, UInt32 size);
};

class CBaseCoder:
  public CAesCbcDecoder,
  public ICryptoSetPassword
{
protected:
  CKeyInfo _key;
  CByteBuffer _buf;
  Byte *_bufAligned;
public:
  STDMETHOD(Init)();
  STDMETHOD(CryptoSetPassword)(const Byte *data, UInt32 size);
};

class CDecoder: public CBaseCoder
{
  UInt32 _ivSize;
  Byte _iv[16];
  UInt32 _remSize;
public:
  MY_UNKNOWN_IMP1(ICryptoSetPassword)
  HRESULT ReadHeader(ISequentialInStream *inStream, UInt32 crc, UInt64 unpackSize);
  HRESULT Init_and_CheckPassword(bool &passwOK);
};

}}

#endif
