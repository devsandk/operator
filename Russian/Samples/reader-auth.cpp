CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_AuthenticateReader(	IN LPVOID pReader,
												IN BYTE ucAuthType,
												IN DWORD dwKeyNumber )
{
	LONG Status = SCARD_S_SUCCESS;

	const int BUF_SIZE = 300;
    BYTE SendBuffer[BUF_SIZE];
    BYTE RecvBuffer[BUF_SIZE];
    DWORD SendLength;
    DWORD RecvLength = BUF_SIZE;

	BYTE RndA[16] = {0};
	BYTE RndB[16] = {0};
	BYTE SessionKey[16] = {0};
	BYTE ucKeyVer = 0x00;
	int iKeyLength = 16;
	BYTE* pKey;
	DWORD keysCount;

    CTransfer* pTr = (CTransfer*)pReader;


	if (ucAuthType == 0x01)
	{
		keysCount = pTr->GetAesKeys(&pKey);
		if (dwKeyNumber > 0)
		{
			if (keysCount <= 0)
				return ERROR_RESOURCE_NOT_AVAILABLE;
			if (dwKeyNumber > keysCount - 1)
				return SCARD_E_INVALID_PARAMETER;
		}
		else
		{
			if (keysCount <= 0)
				return ERROR_RESOURCE_NOT_AVAILABLE;
		}

		ZeroMemory(m_ReaderSettings[pReader].CurrentCryptoSettings()->IV, 16);
	}

	iKeyLength = 16;

	SendBuffer[0] = 0x6F;
	SendBuffer[1] = (ucAuthType == 0x01)?0xAA:0x00;
	SendBuffer[2] = dwKeyNumber&0xFF;
	SendBuffer[3] = (dwKeyNumber>>8)&0xFF;
	SendLength = 4;

    pTr->m_TrBuf.Clear();
    pTr->m_TrBuf.AddBulk( SendBuffer, SendLength );

    Status = pTr->SingleTransceive();

	if ((ucAuthType != 0x01))//&&( Status == SCARD_S_SUCCESS ))
	{
		if( Status == SCARD_S_SUCCESS )
		{
			m_ReaderSettings[pReader].CurrentCryptoSettings()->fEncryptedMode = false;
		}
		return Status;
	}

	RecvLength = 16;
    if( ! pTr->m_RcBuf.GetBulk( 1, RecvBuffer, &RecvLength ) )
        Status = SCARD_E_COMM_DATA_LOST;

	if (( Status == SCARD_S_SUCCESS ) && RecvLength)
	{

		BYTE pOut[33] = {0};

		aes_128_decrypt_cbc( 
			RecvBuffer, 
			16, 
			&pKey[dwKeyNumber * 16], 
			m_ReaderSettings[pReader].CurrentCryptoSettings()->IV, 
			&pOut[16], 
			m_ReaderSettings[pReader].CurrentCryptoSettings()->IV
			);

		memcpy(RndB, &pOut[16], 16);

		pOut[16+16] = pOut[16];

		memmove(
			pOut+16,
			pOut+17,
			16
			);

		for (int i = 0; i < 16; i++)
			RndA[i] = pOut[i] = (BYTE)rand();

		aes_128_encrypt_cbc( 
			pOut, 
			32, 
			&pKey[dwKeyNumber * 16], 
			m_ReaderSettings[pReader].CurrentCryptoSettings()->IV, 
			&SendBuffer[4], 
			m_ReaderSettings[pReader].CurrentCryptoSettings()->IV 
			);

		SendBuffer[0] = 0x6F;
		SendBuffer[1] = 0xAF;
		SendBuffer[2] = dwKeyNumber&0xFF;
		SendBuffer[3] = (dwKeyNumber>>8)&0xFF;

		SendLength = 36;

		RecvLength = BUF_SIZE;

		pTr->m_TrBuf.Clear();
		pTr->m_TrBuf.AddBulk( SendBuffer, SendLength );

		Status = pTr->SingleTransceive();

    	RecvLength = 16;
		if( ! pTr->m_RcBuf.GetBulk( 1, RecvBuffer, &RecvLength ) )
			Status = SCARD_E_COMM_DATA_LOST;

		if (Status)
		{
			return Status;
		}	

		aes_128_decrypt_cbc( 
			RecvBuffer, 
			16, 
			&pKey[dwKeyNumber * 16], 
			m_ReaderSettings[pReader].CurrentCryptoSettings()->IV, 
			pOut, 
			m_ReaderSettings[pReader].CurrentCryptoSettings()->IV 
			);

		pOut[0+16] = pOut[0+16-1];
		memmove(
			pOut+1,
			pOut+0,
			16
			);
		pOut[0] = pOut[0+16];

		if (memcmp(RndA, pOut, 16) != 0)
		{
			return SCARD_E_CARD_UNSUPPORTED;
		}

	}

	if (Status == SCARD_S_SUCCESS)
	{
		memcpy(&SessionKey[0], &RndA[0], 4);
		memcpy(&SessionKey[4], &RndB[0], 4);
		memcpy(&SessionKey[8], &RndA[12], 4);
		memcpy(&SessionKey[12], &RndB[12], 4);
		
		ZeroMemory(m_ReaderSettings[pReader].CurrentCryptoSettings()->IV, 16);

		memcpy(&m_ReaderSettings[pReader].CurrentCryptoSettings()->SessionKey, SessionKey, 16);

		//CryptoSubkeys(pReader);//, SessionKey, SessionKeySize, m_DF_Settings[pReader].K1, m_DF_Settings[pReader].K2);
        
		m_ReaderSettings[pReader].CurrentCryptoSettings()->fEncryptedMode = true;
	}

	return Status;
}
