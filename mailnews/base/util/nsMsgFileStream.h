/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "msgCore.h"
#include "nsIInputStream.h"
#include "nsIOutputStream.h"
#include "nsISeekableStream.h"
#include "prio.h"

class nsMsgFileStream : public nsIInputStream, public nsIOutputStream, public nsISeekableStream
{
public:
  nsMsgFileStream();
  ~nsMsgFileStream();

  NS_DECL_ISUPPORTS

  NS_IMETHOD Available(PRUint32 *_retval); 
  NS_IMETHOD Read(char * aBuf, PRUint32 aCount, PRUint32 *_retval); 
  NS_IMETHOD ReadSegments(nsWriteSegmentFun aWriter, void * aClosure, PRUint32 aCount, PRUint32 *_retval);
  NS_DECL_NSIOUTPUTSTREAM
  NS_DECL_NSISEEKABLESTREAM

  nsresult InitWithFile(nsILocalFile *localFile);
protected:
  PRFileDesc *mFileDesc;
  bool mSeekedToEnd;
};
