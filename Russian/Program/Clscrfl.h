
//==============================================================================
//                        ���������� ������� RFID-�����������
//==============================================================================

// Clscrfl.h : main header file for the CLSCRFL DLL

// ���������� ������� RFID-����������� �������� � ���� ��������� �������:
//==============================================================================
//      ���������
//------------------------------------------------------------------------------
//  ������� ���������
//  ���������� ���������
//  ������� RS-���������
//  ������� USB-���������
//  ������� Ethernet-���������
//  ���������, ������ �� ���������
//  ������� ���������
//  ������ �������� ��������
//  ���������� �������� ��������
//  ������ ��� ���������� ��������� ��������
//==============================================================================
//      ���������� ������������
//------------------------------------------------------------------------------
//  ������ ��������� �����������
//  �������� ����������-�����������
//  ��������� ����������-�����������
//  ������ ������ ����������-�����������
//  ������ �������� ����� ����������-�����������
//  �������� ���������������� ���� �����������
//  ���������� ����� ��������� ����������������� ���� �����������
//  ���������� �������� ��������
//  ���������� �����������
//  ���������� �������� ������ �� ������������ �� COM-�����
//==============================================================================
//      ���������� ������� ISO 14443-A
//------------------------------------------------------------------------------
//  ������������ ����� ISO 14443-A �� ��������� IDLE
//  �������������� ����� ISO 14443-A � ��������� HALT
//  ������������ ����� ISO 14443-A �� ��������� HALT
//==============================================================================
//      ���������� ������� ISO 14443-B
//------------------------------------------------------------------------------
//  ������������ ����� ISO 14443-B �� ��������� IDLE
//  ������� ����� ISO 14443-B
//  �������������� ����� ISO 14443-B � ��������� HALT
//  ������������ ����� ISO 14443-B �� ��������� HALT
//==============================================================================
//      ���������� ������� ISO 15693
//------------------------------------------------------------------------------
//  ���������� �������������� ����� ISO 15693
//  ��������� ����� ISO 15693 � ��������� Quiet
//  ��������� ����� ISO 15693 � ��������� Selected
//  ��������� ����� ISO 15693 � ��������� Ready
//==============================================================================
//      ���������� ������� ICODE EPC (���������: ��������)
//------------------------------------------------------------------------------
//  ���������� �������������� ����� EPC
//  ��������� ����� EPC � ��������� FIXED SLOT
//  �������� ���� � ����� EPC
//  ������������ ����� EPC
//==============================================================================
//      ���������� ������� ICODE UID (���������: ��������)
//------------------------------------------------------------------------------
//  ���������� �������������� ����� UID
//  ��������� ����� UID � ��������� FIXED SLOT
//  �������� ���� � ����� UID
//  ������������ ����� UID
//==============================================================================
//      ������ � ������� Mifare Standard
//------------------------------------------------------------------------------
//  ���������� ����
//  ����������������� ������ ���������������
//  ����������������� ������ ��������������� 6-�������� ������
//  �������� ���� � EEPROM �����������
//  ����������������� ������ ������ �� EEPROM
//  ��������� ����
//  �������� ����
//  ��������� ��������
//  ��������� ��������
//  ���������� ��������
//==============================================================================
//      ������ � ������� Mifare Ultralight
//------------------------------------------------------------------------------
//  ��������� ��������
//  �������� ��������
//==============================================================================
//      ������ � ������� ISO 15693
//------------------------------------------------------------------------------
//  ��������� ����
//  �������� ����
//  ����������� ����
//  ��������� ��������� ������
//  �������� AFI
//  ����������� AFI
//  �������� DSFID
//  ����������� DSFID
//  ������ ��������� ����������
//  ������ �������� ������� ������ ������ �� ������
//  ���������� EAS
//  �������� EAS
//  ����������� EAS
//  ��������� EAS
//==============================================================================
//      ���������������� ����� �������
//------------------------------------------------------------------------------
//  ����� ������� �� ������������
//  ���������������� ����� ������� � ������
//==============================================================================
//      ������������ ��������� �� ���� RS485
//------------------------------------------------------------------------------
//  ������ ����� ������
//  ���������� ����� ������
//  ��������� ����� ����������
//  �������� ����� ����������


// �������� ����� ������������� ���� �������� �������:
//          0 - �������� ����������
// 0x80100001 - ���������� ������ �����������, ��� ������� ����� �������� 
//              ����� ������ ������� CLSCRF_GetLastInternalError



#if !defined(AFX_CLSCRF_H__CE290562_87D9_41F4_A1CD_3B80EFEBA737__INCLUDED_)
#define AFX_CLSCRF_H__CE290562_87D9_41F4_A1CD_3B80EFEBA737__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef CLSCRF_EXPORTS
#define CLSCRF_API __declspec(dllexport)
#else
#define CLSCRF_API __declspec(dllimport)
#endif


#ifndef _LPCBYTE_DEFINED
#define _LPCBYTE_DEFINED
typedef const BYTE *LPCBYTE;
#endif

#define STRING_VERSION      "6.2"

//                                  0    1    2    3    4    5    6    7
static DWORD cDecodeBufSize [] = {  16,  24,  32,  40,  48,  64,  96, 128, 
//                                  8    9   10   11   12   13   14   15
                                   256, 256, 256, 256, 256, 256, 256, 256 };

const unsigned char cPCD_FSDI = 5;        // PCD FIFO Size = 64

const DWORD cPCD_BufSize = cDecodeBufSize[cPCD_FSDI];




#define CLSCRF_UID_LENGTH_ISO14443_B  4
#define CLSCRF_UID_LENGTH_ISO15693    8

#define CLSCRF_ICC_TYPE_ISO14443A		0x01
#define CLSCRF_ICC_TYPE_ISO14443B		0x02
#define CLSCRF_ICC_TYPE_ISO15693		0x04
#define CLSCRF_ICC_TYPE_ICODE_1			0x08
#define CLSCRF_ICC_TYPE_ISO18000		0x20
#define CLSCRF_ICC_TYPE_RFU				0x80

#define CLSCRF_DF_AUTH_TYPE_DES		0x00
#define CLSCRF_DF_AUTH_TYPE_3DES	0x01
#define CLSCRF_DF_AUTH_TYPE_3K3DES	0x02
#define CLSCRF_DF_AUTH_TYPE_AES		0x03

#define CLSCRF_DF_CRYPTO_METHOD_DES_OR_3DES	0x00
#define CLSCRF_DF_CRYPTO_METHOD_3K3DES		0x01
#define CLSCRF_DF_CRYPTO_METHOD_AES			0x02

#define CLSCRF_DF_TRANSFER_TYPE_PLAIN		0x00
#define CLSCRF_DF_TRANSFER_TYPE_MACCED		0x01
#define CLSCRF_DF_TRANSFER_TYPE_ENCRYPTED   0x03

#define CLSCRF_DF_COMMUNICATION_SETTINGS_PLAIN		0x00
#define CLSCRF_DF_COMMUNICATION_SETTINGS_MACCED		0x01
#define CLSCRF_DF_COMMUNICATION_SETTINGS_ENCRYPTED	0x03

#define CLSCRF_DF_FILE_TYPE_DATA_STANDARD				0x00
#define CLSCRF_DF_FILE_TYPE_DATA_BACKUP					0x01
#define CLSCRF_DF_FILE_TYPE_VALUE_WITH_BACKUP			0x02
#define CLSCRF_DF_FILE_TYPE_LINEAR_RECORD_WITH_BACKUP	0x03
#define CLSCRF_DF_FILE_TYPE_CYCLIC_RECORD_WITH_BACKUP	0x04

#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_MASTER_KEY	0x00
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_1		0x01
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_2		0x02
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_3		0x03
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_4		0x04
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_5		0x05
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_6		0x06
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_7		0x07
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_8		0x08
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_9		0x09
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_10		0x0A
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_11		0x0B
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_12		0x0C
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_APPLICATION_KEY_13		0x0D
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_REQUIRED_AUTHENTICATION_WITH_SAME_APPLICATION_KEY		0x0E
#define CLSCRF_DF_CHANGE_KEY_ACCESS_RIGHT_ALL_APPLICATION_KEYS_BUT_MASTER_KEY_ARE_FROZEN		0x0F

#define CLSCRF_DF_CHANGE_KEY_KEY_TYPE_DES_OR_3DES	0x00
#define CLSCRF_DF_CHANGE_KEY_KEY_TYPE_3K3DES		0x01
#define CLSCRF_DF_CHANGE_KEY_KEY_TYPE_AES			0x02

typedef struct _CLSCRF_CARD
{
    unsigned int  Timeout;  // etu = 128/fc = 9,4 us
    unsigned int  CardType;
    int           UID_Len;
    unsigned char UID[32];
    union{
        struct {    // 14443-A 
            unsigned char ATQA [2];
            unsigned char SAK;
            unsigned char ATS  [37];    // if 14443-4 only
        };
        struct {    // 14443-B
            unsigned char AppData [4];
            unsigned char ProtInf [3];
            unsigned char Attrib  [33];
        };
        struct {    // 15693
            unsigned char DSFID;
            unsigned char SLI_Data[39]; // not used
        };
        struct {    // ICODE EPC
            unsigned char CRC16 [2];
            unsigned char EPC_Data[38]; // not used
        };
    } ATQ;
    unsigned char CID;
    unsigned char Active;
    unsigned char RfMode;
    unsigned char BlockNumberBit;

} CLSCRF_CARD;

typedef struct _CLSCRF_DESFIRE_HW_SW_INFO
{
	BYTE ucVendorID;
	BYTE ucType;
	BYTE ucSubType;
	BYTE ucMajorVer;
	BYTE ucMinorVer;
	BYTE ucStorageSize;
	BYTE ucProtocol;
} CLSCRF_DESFIRE_HW_SW_INFO;

typedef struct _CLSCRF_DESFIRE_MORE_INFO
{
	BYTE pUID[7];
	BYTE pBatchNumber[5];
	BYTE ucCwProd;
	BYTE ucYearProd;
} CLSCRF_DESFIRE_MORE_INFO;

typedef struct _CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS
{
	BYTE ChangeAccessRights :4;
	BYTE ReadAndWriteAccess :4;
	BYTE WriteAccess :4;
	BYTE ReadAccess :4;
} CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS;

#pragma pack(push, 1)
typedef struct _CLSCRF_DESFIRE_FILE_SETTINGS
{
	BYTE ucFileType;
	BYTE ucCommSettings;
	CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS AccessRights;
	union
	{
		struct
		{
			DWORD dwFileSize :24;
		} DataFile;
		struct
		{
			DWORD dwLowerLimit;
			DWORD dwUpperLimit;
			DWORD dwLimitedCreditValue;
			BYTE ucLimitedCreditEnabled;
		} ValueFile;
		union
		{
			struct
			{
				DWORD dwRecordSize :24;
			};
			struct
			{
				BYTE Padding1[3];
				DWORD dwMaxNumberOfRecords :24;
			};
			struct
			{
				BYTE Padding2[6];
				DWORD dwCurrentNumberOfRecords :24;
			};
		} RecordFile;
	};
} CLSCRF_DESFIRE_FILE_SETTINGS;
#pragma pack(pop)

typedef struct _CLSCRF_DESFIRE_CONFIGURATION
{
	BYTE ucOption;
	union
	{
		union
		{
			BYTE ucConfigurationByte;
			struct
			{
				BYTE fFormatCardDisabled	:1;
				BYTE fRandomIDEnabled		:1;
				BYTE RFU					:6;
			};
		};
		struct
		{
			BYTE Key[24];
			BYTE KeyVersion;
		};
		struct
		{
			BYTE ATS[32];
			BYTE ATSSize;
		};
	};
} CLSCRF_DESFIRE_CONFIGURATION;

typedef union _CLSCRF_DESFIRE_DFNAME
{
	DWORD AID:24;
	struct
	{
		BYTE Padding[3];
		WORD FID;
		BYTE DFName[16];
		BYTE DFNameSize;
	};
} CLSCRF_DESFIRE_DFNAME;

typedef struct _CLSCRF_DESFIRE_LIMITED_CREDIT_ENABLED
{
	BYTE fEnableLimitedCredit :1;
	BYTE fEnableFreeGetValue :1;
	BYTE RFU :6;
} CLSCRF_DESFIRE_LIMITED_CREDIT_ENABLED;

typedef struct _CLSCRF_DESFIRE_PICC_MASTER_KEY_SETTINGS
{
	BYTE fAllowChangingPiccMasterKey:1;
	BYTE fFreeDirectoryListAccessWithoutPiccMasterKey:1;
	BYTE fCreateAndDeleteWithoutPiccMasterKey:1;
	BYTE fConfigurationChangeable:1;
	BYTE RFU:4;
} CLSCRF_DESFIRE_PICC_MASTER_KEY_SETTINGS;

typedef struct _CLSCRF_DESFIRE_APPLICATION_MASTER_KEY_SETTINGS
{
	BYTE fAllowChangingApplicationMasterKey:1;
	BYTE fFreeDirectoryListAccessWithoutApplicationMasterKey:1;
	BYTE fCreateAndDeleteWithoutApplicationMasterKey:1;
	BYTE fConfigurationChangeable:1;
	BYTE ChangeKeyAccessRights:4;
} CLSCRF_DESFIRE_APPLICATION_MASTER_KEY_SETTINGS;

typedef struct _CLSCRF_DESFIRE_NEW_APPLICATION_KEY_SETTINGS
{
	BYTE MaxNumberOfKeys :4;
	BYTE RFU :1;
	BYTE Supported2ByteFileIDs :1;
	BYTE CryptoMethod :2;
} CLSCRF_DESFIRE_NEW_APPLICATION_KEY_SETTINGS;

typedef union _CLSCRF_DESFIRE_MASTER_KEY_SETTINGS
{
	CLSCRF_DESFIRE_PICC_MASTER_KEY_SETTINGS PiccMasterKeySettings;
	CLSCRF_DESFIRE_APPLICATION_MASTER_KEY_SETTINGS ApplicationMasterKeySettings;
} CLSCRF_DESFIRE_MASTER_KEY_SETTINGS;

typedef struct _CLSCRF_DESFIRE_KEY_DATA
{
	union
	{
		struct
		{
			BYTE SetToZero :6;
			BYTE KeyType :2;
		} PiccMasterKey;
		BYTE ApplicationKeyNumber;
	} KeyNumber;
	BYTE Key[24];
	BYTE ucKeySize;
	BYTE ucAESKeyVersion;
	bool fIsAESKey;
} CLSCRF_DESFIRE_KEY_DATA;

typedef struct _CLSCRF_DESFIRE_MASTER_KEY_SETTINGS_AND_LENGTH
{
	CLSCRF_DESFIRE_MASTER_KEY_SETTINGS MasterKeySettings;
	union
	{
		struct
		{
			BYTE MaxPiccKeysNumber :6;
			BYTE KeyType :2;
		} PiccMasterKey;
		BYTE MaxApplicationKeysNumber;
	} MaxNumberOfKeys;
} CLSCRF_DESFIRE_MASTER_KEY_SETTINGS_AND_LENGTH;

CLSCRF_API LONG __stdcall 
            CLSCRF_Cards_Add( IN CLSCRF_CARD*  pCard );

CLSCRF_API LONG __stdcall 
            CLSCRF_Cards_GetFirst( OUT CLSCRF_CARD**  ppCard );

CLSCRF_API LONG __stdcall 
            CLSCRF_Cards_GetLast( OUT CLSCRF_CARD**  ppCard );

CLSCRF_API LONG __stdcall 
            CLSCRF_Cards_GetCount( OUT int*  piCardsCount );

CLSCRF_API LONG __stdcall 
            CLSCRF_Cards_Get( IN int iCardIndex, OUT CLSCRF_CARD**  ppCard );

CLSCRF_API LONG __stdcall 
            CLSCRF_Cards_Clear();

CLSCRF_API LONG __stdcall 
            CLSCRF_Cards_SetCurrent(IN CLSCRF_CARD*  pCard);

CLSCRF_API LONG __stdcall 
            CLSCRF_Cards_GetCurrent(OUT CLSCRF_CARD**  ppCard);

CLSCRF_API LONG __stdcall 
			CLSCRF_Cards_Search( 
						IN int UID_Len, 
						IN PBYTE pUID, 
						OUT CLSCRF_CARD** ppCard );

CLSCRF_API LONG __stdcall 
			CLSCRF_Cards_CreateNew_A(	IN BYTE bRfMode,
										IN PBYTE pbATQ,
										IN PBYTE pbSAK,
										IN PBYTE pbUID,
										IN DWORD UID_Len,
										OUT CLSCRF_CARD** ppCard );

CLSCRF_API LONG __stdcall 
	CLSCRF_Cards_CreateNew_B(	IN BYTE bRfMode,
                                IN DWORD* pdwPUPI,
                                IN DWORD* pdwAppData,
                                IN DWORD* pdwProtInfo,
                                IN int    CardCount,
								OUT CLSCRF_CARD** ppCard );

CLSCRF_API LONG __stdcall 
	CLSCRF_Cards_CreateNew15693(	IN BYTE bRfMode,
                                    IN BYTE* pbData,
                                    IN DWORD dwCount,
									OUT CLSCRF_CARD** ppCard );


//CLSCRF_API LONG __stdcall 
//	CLSCRF_Cards_CreateNewEPCUID(	IN BYTE bRfMode,
//                                    IN DWORD dwUID_Len,
//                                    IN BYTE* pbData,
//                                    IN DWORD dwCount,
//									OUT CLSCRF_CARD** ppCard );


CLSCRF_API LONG __stdcall 
	CLSCRF_Cards_Delete(	IN int UID_Len,
							IN PBYTE pUID );


CLSCRF_API LONG __stdcall 
	CLSCRF_Cards_CheckATR(	IN LPCSTR szATR,
                            IN LPSTR szCardInfo,
                            IN DWORD dwCardInfoMaxSize	);







//
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//                              � � � � � � � � �
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������� ���������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Create( IN OUT LPVOID* ppReader );
//
// ������� ������-���������
//
// ppReader - ��������� �� ����������, � ������� ����� �������� ������ �� 
//            ��������� ������-��������� � ������� ����� �������������� � 
//            ������� ���� ��������� �������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ��� ������� ������ ���������� 1 ��� � ������ ������ ���������� 
//
////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� ���������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Destroy( IN LPVOID* ppReader );
//
// ���������� ������-���������
//
// ppReader - ��������� �� ����������, ������� �������� ������ �� ������������
//            ������-��������� (��. ������� CLSCRF_Create )
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ��� ������� ������ ���������� 1 ��� � ����� ������ ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������� ���������
//------------------------------------------------------------------------------

CLSCRF_API LONG __stdcall 
            CLSCRF_Open( IN LPVOID pReader,
                         IN DWORD  dwPortNumber = 0,
                         IN DWORD  dwBaudrate = 9600,
                         IN DWORD  dwLogFile = 0 );
//
// ���������� �������, ��������� ������ ��� ������������� � ���
// ������������� ������������. ��� ����� ��������������� ����������
// ������� ������������ ��������� CLSCRF_OpenRS � CLSCRF_OpenUSB
//
// ��������� ���������
//
// pReader      - ������ �� ����������� ������-��������� (��. �������
//                CLSCRF_Create )
// dwPortNumber - ����� ����������: 0 - ��������� USB
//                                  1 - ���������������� ���� COM1
//                                  2 - ���������������� ���� COM2
//                                  3 - ���������������� ���� COM3 � �.�.
// dwBaudrate   - �������� ������ �� COM-�����
// dwLogFile    - ����� � ���� ���������� ������: 1 - ��������� ����
//                                                0 - �� ��������� ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ��� ������� ������ ���������� 1 ��� ����� ������� ������ �� ������������
// � ������ ��� ��� ��������� �������� ������ �� COM-�����
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������� RS-���������
//------------------------------------------------------------------------------

CLSCRF_API LONG __stdcall 
            CLSCRF_OpenRS( IN LPVOID pReader,
                           IN DWORD  dwIndex = 0,
                           IN DWORD  dwBaudrate = 9600,
                           IN DWORD  dwLogFile = 0 );
//
// ��������� COM-���� (��������� RS232 ��� RS485)
//
// pReader    - ������ �� ����������� ������-��������� (��. �������
//              CLSCRF_Create )
// dwIndex    - ����� COM-����� �� 0 ( 0 - COM1, 1 - COM2 � �.�.)
// dwBaudrate - �������� ������ �� COM-�����
// dwLogFile  - ����� � ���� ���������� ������: 1 - ��������� ����
//                                              0 - �� ��������� ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ��� ������� ������ ���������� 1 ��� ����� ������� ������ �� ������������
// � ������ ��� ��� ��������� �������� ������ �� COM-�����
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������� USB-���������
//------------------------------------------------------------------------------

CLSCRF_API LONG __stdcall 
            CLSCRF_OpenUSB( IN LPVOID pReader,
                            IN DWORD  dwIndex = 0,
                            IN DWORD  dwLogFile = 0 );
//
// ��������� USB-���������
//
// pReader   - ������ �� ����������� ������-��������� (��. �������
//             CLSCRF_Create )
// dwIndex   - ����� USB-���������� � ������ ��������� �� 0
// dwLogFile - ����� � ���� ���������� ������: 1 - ��������� ����
//                                             0 - �� ��������� ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ��� ������� ������ ���������� 1 ��� ����� ������� ������ �� ������������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������� Ethernet-���������
//------------------------------------------------------------------------------

CLSCRF_API LONG __stdcall 
            CLSCRF_OpenETH( IN LPVOID pReader,
                            IN DWORD  dwPort,
                            IN PCHAR  szIP,
							IN DWORD  dwLogFile );
//
// ��������� Ethernet-���������
//
// pReader   - ������ �� ����������� ������-��������� (��. �������
//             CLSCRF_Create )
// dwPort   - ���� �����������
// szIP		- IP ����� ����������� � ������� "aaa.bbb.ccc.ddd"
// dwLogFile - ����� � ���� ���������� ������: 1 - ��������� ����
//                                             0 - �� ��������� ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ��� ������� ������ ���������� 1 ��� ����� ������� ������ �� ������������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������, ������ �� ���������
//------------------------------------------------------------------------------
//
CLSCRF_API bool __stdcall 
            CLSCRF_IsOpened( IN LPVOID pReader );
//
// ��������� ����������� ����������
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
//
// ������������ ��������:  0   - ��������� ������
//                         1   - ��������� ������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������� ���������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Close( IN LPVOID pReader );
//
// ��������� ���������
//
// pReader - ������ �� ����������� ������-��������� (��. ������� 
//           CLSCRF_Create )
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ��� ������� ������ ���������� 1 ��� ����� ������������ ����������
// � ������ ��� ��� ��������� �������� ������ �� COM-�����
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������ �������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_GetIOTimeout( IN     LPVOID  pReader,
                                    OUT LPDWORD pdwTimeout );
//
// ������ ������� �������� �������� ���������� ������� 
//
// pReader    - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pdwTimeout - ����� ���������� ���� DWORD, � ������� ����� ��������
//              �������� �������� � �������������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� �������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_SetIOTimeout( IN LPVOID pReader,
                                 IN DWORD  dwTimeout );
//
// ����� ���������� ������� ���������� ������������ �� ��������� �����������:
//    - �������� ������� �� ���������� � �����������
//    - ���������� ������� � �����������
//    - �������� ������ �� ����������� � ���������
//    - ��������� ������� ������������ �������
// ��� �������� ���������� ��������������� �������, ������ 1000 ��
// � ������� ���� ������� ����� �������� �������� �������� ���������� �������
//
// pReader   - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwTimeout - �������� �������� � �������������. ���� ��� �������� ����� 0,
//             �� ��������������� ������� �� ��������� (2000 ��)
//             ����������� �������� �� 0 �������� �������� 50 ��
//             ������������ �������� �������� 86400000 ��
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������ ��� ���������� ��������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_GetLastInternalError( IN     LPVOID pReader,
                                            OUT LPBYTE pbError );
//
// ���� ���������� ������� ������ ���������� ����������� � ����� 0x80100001,
// ������ ��������� ������ ���������� �������� ������ �����������
// ������ ������� ������ �������� ���� ���� ���������� ������
// �������� ����� �� ���������� ������ ����������� 0xff - ����� �� ��������
//
// pReader  - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbError  - ����� ���������� ���� unsigned char, � ������� ����� ��������
//            �������� ���� ���������� ������ �����������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//                � � � � � � � � � �   � � � � � � � � � � � �
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������ ��������� �����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_GetState( IN     LPVOID  pReader,
                                OUT LPDWORD pdwState );
//
// ������ ��������� �����������
//
// pReader  - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pdwState - ������ �� ����������, � ������� ����� �������� �������� 
//            ��������� ����������:
//
//  ���� 31-16 - ������
//  ���  15    - ����������-����������� ��������
//  ���  14    - ���������������� ���� ��������
//  ���  13    - ����������� ������������ ������ ICODE
//  ���  12    - ����������� ������������ ������ ISO 14443-B
//  ���� 11-7  - ������
//  ���� 6-4   - ������� ����� ����������������� ����:
//               000 - ISO 14443-A (�������� ��. ���� 3-0)
//               001 - ISO 14443-B (�������� ��. ���� 3-0)
//               100 - ISO 15693
//               101 - ICODE1
//               110 - ICODE EPC ISO 18000-3
//               111 - ICODE UID ISO 18000-3
//  ���� 3-2   - ������� �������� ������ � ������� ISO 14443
//               (����� ������ �� ����� � �����������):
//               00 - 106 ����
//               01 - 212 ����
//               10 - 424 ����
//               11 - 848 ����
//  ���� 1-0   - ������� �������� �������� � ������� ISO 14443
//               (����� ������ �� ����������� � �����):
//               00 - 106 ����
//               01 - 212 ����
//               10 - 424 ����
//               11 - 848 ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ����������-�����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Mfrc_On( IN LPVOID pReader );
//
// �������� ����������-�����������
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����������. ��� ���������� ����������-����������� � ������� ������
// ���������� ���������� ��� �� 120 mA.
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ����������-�����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Mfrc_Off( IN LPVOID pReader );
//
// ��������� ����������-�����������
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����������. ��� ����������� ����������-����������� ���������� ������������
// �������, �� �� ��������� �� �� ���, ������� �������� ���� ����������.
// � ���� ��������� ���������� ���������� ��� �� 50 mA.
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������ ������ ����������-�����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Get_Mfrc_Version( IN     LPVOID pReader,
                                        OUT LPBYTE pbMfrcVersion );
//
// ������ ��� �������� (� �.�. ������) ����������-�����������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbMfrcVersion - ����� ������� ���� unsigned char, � ������� ����� 
//                 �������� 6 ������ ������ �����������, �� �������
//                 4 ����� - ��� �������� ����������-�����������
//                 1 ����  - ������ ����������-�����������
//                 1 ����  - ������ �������������� �����������
// �������:
//      30 88 FE 03 04 20	- ���������� MF RC530,
//      30 CC FF 0F 04 20	- ���������� MF RC531,
//      30 FF FF 0F 04 20	- ���������� CL RC632,
//   ��� ������ ���������� 04, ������ �������������� 2.0
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������ �������� ����� ����������-�����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Get_Mfrc_Serial_Number( IN     LPVOID pReader,
                                              OUT LPBYTE pbMfrcSN );
//
// ������ �������� (����������) ����� ����������-�����������
//
// pReader  - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbMfrcSN - ����� ������� ���� unsigned char, � ������� ����� 
//            �������� 4 ����� ��������� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ���������������� ���� �����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Mfrc_Rf_Off_On( IN LPVOID pReader,
                                   IN USHORT usDelay );
//
// ���������� ��� ��������� ���������������� ���� (���) �����������
// ����� ��� ��������� ��� �������� ���������� ������������
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// usDelay - �������� ������� [��], � ������� �������� ��� ���������. 
//           ���� ���� �������� ����� 0, �� ��� �������� �����������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� ����� ��������� ����������������� ���� �����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Mfrc_Set_Rf_Mode( IN LPVOID pReader,
                                     IN BYTE   bRfMode );
//
// ������������� ����� ��������� ����������������� ���� ����������� �� 
// �������� ������� � ����������� ����� ������ �� �����
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bRfMode - ���� ������ ��������� ���:
//  ��� 7      - ������
//  ���� 6-4   - ��������������� ����� ����������������� ����:
//               000 - ISO 14443-A (�������� ��. ���� 3-0)
//               001 - ISO 14443-B (�������� ��. ���� 3-0)
//               100 - ISO 15693
//               101 - ICODE1
//               110 - ICODE EPC ISO 18000-3
//               111 - ICODE UID ISO 18000-3
//  ���� 3-2   - ��������������� �������� ������ � ������� ISO 14443
//               (����� ������ �� ����� � �����������):
//               00 - 106 ����
//               01 - 212 ����
//               10 - 424 ����
//               11 - 848 ����
//  ���� 1-0   - ��������������� �������� �������� � ������� ISO 14443
//               (����� ������ �� ����������� � �����):
//               00 - 106 ����
//               01 - 212 ����
//               10 - 424 ����
//               11 - 848 ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� �������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Sound( IN LPVOID pReader,
                          IN BYTE   nBeepCount );
//
// ������ �������� ������
//
// pReader    - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// nBeepCount - ���������� ��������� �������� ������������� 100 �� � 
//              ������������ ����� �� ������������.
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� �����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Led( IN LPVOID pReader,
                        IN BYTE   bBlinkColor,
                        IN BYTE   bBlinkCount,
                        IN BYTE   bPostColor );
//
// ������ ����������� �����������, ����� ����� ��� �������� ��� ���������
// ������� ������� - 2 ��
//
// pReader     - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bBlinkColor - ���� ��������� ����������:
//                0   - �� ������
//                1   - ������ �������
//                2   - ������ �������
//                3   - ������ �����-���������
// bBlinkCount - ���������� ������� (���� 0 - �� ������)
// bPostColor  - ����������� ��������� ����������:
//                0   - ��������
//                1   - ������ �������
//                2   - ������ �������
//                3   - ������ �����-���������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� �������� ������ �� ������������ �� COM-�����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_UART_Baudrate( IN LPVOID pReader,
                                  IN DWORD  dwBaudrate );
//
// ������������� �������� ������ �� ������������ �� COM-�����
//
// pReader    - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwBaudrate - ����� �������� ������ �� COM-�����; ��������� ��������:
//                  9600
//                 14400
//                 19200
//                 38400
//                 57600
//                115200
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� ��������� �� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_SetIndicatorMessage(	IN LPVOID pReader,
										IN LPCSTR lpMessage,
										IN BYTE  ucMessageLength,
										IN DWORD dwInfiniteLoop,
										IN DWORD dwLineIndex,
										IN DWORD dwMode,
										IN BYTE ucRepeats);
//
// ������������� ��������� �� ��������� ����������
//
// pReader    - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// lpMessage - ��������� �� ������ ��������, ���������� ����� ���������;
// dwMessageLength - ����� ��������� � ��������;
// dwInfiniteLoop : 0 - ���������� ������� ��� ��������� ���� ����� �������� ucRepeats,
//                  1 - ��������� ���� ����������;
// dwLineIndex: 0 - ����� ������� ������,
//              1 - ����� ������ ������;
// dwMode: 0 - ����������, 
//         1 - ������,
//         2 - ������� ������,
//         3 - ����������.
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//         � � � � � � � � � �   � � � � � � �   I S O   1 4 4 4 3 - A
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������������ ����� ISO 14443-A �� ��������� IDLE
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Activate_Idle_A( IN     LPVOID  pReader,
                                       OUT LPBYTE  pbATQ,
                                       OUT LPBYTE  pbSAK,
                                       OUT LPBYTE  pbUID,
                                    IN OUT LPDWORD pdwUIDLength );
//
// ���������� ����� ISO 14443-A �� ��������� IDLE (��. ISO 14443-3 �.6.3)
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbATQ   - ������ �� ������ (2 �����), � ������� ����� ������� ATQ �����
// pbSAK   - ������ �� ������ (1 ����), � ������� ����� ������� SAK �����
// pbUID   - ������ �� ������ �� ����� 10 ������, � ������� �����
//           ������� ���������� ������������� ����� (UID)
// pdwUIDLength - ������ �� ���������� ���� DWORD, ������� ����� �������
//                ������� ������ ��������� ������ ������� pbUID, � �� ������
//                ����� ��������� �������������� ����� ����������� 
//                �������������� �����, ����������� � ������ pbUID
//                (��������� �������� - 4, 7 ��� 10)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������������� ����� ISO 14443-A � ��������� HALT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Halt_A( IN LPVOID pReader );
//
// ������������ ����� ISO 14443-A � ��������� HALT (��. ISO 14443-3 �.6.3)
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������������ ����� ISO 14443-A �� ��������� HALT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Activate_Wakeup_A( IN     LPVOID  pReader,
                                      IN     LPBYTE  pbUID,
                                      IN     DWORD   UIDLength,
                                         OUT LPBYTE  pbATQ,
                                         OUT LPBYTE  pbSAK );

// ���������� ����� ISO 14443-A �� ��������� HALT (��. ISO 14443-3 �.6.3)
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbUID   - ������ �� ������ �� ����� 10 ������, � ������� ����� ������� 
//           ������� ������ ���� ������� ���������� ������������� ����� (UID)
// UIDLength - ����� ����������� �������������� �����, ������� ����������
//             � ������� pbUID
// pbATQ - ������ �� ������ (2 �����), � ������� ����� ������� ATQ �����
// pbSAK - ������ �� ������ (1 ����), � ������� ����� ������� SAK �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//         � � � � � � � � � �   � � � � � � �   I S O   1 4 4 4 3 - B
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������������ ����� ISO 14443-B �� ��������� IDLE
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Activate_Idle_B( IN     LPVOID  pReader,
                                    IN     BYTE    bAfi,
                                    IN     BYTE    bSni,
                                       OUT LPDWORD pdwPUPI,
                                       OUT LPDWORD pdwAppData,
                                       OUT LPDWORD pdwProtInfo,
                                    IN OUT LPDWORD pdwCardCount );
//
// ���������� ����� ISO 14443-B �� ��������� IDLE (��. ISO 14443-3 �.7.7)
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bAfi    - ������������� ��������� ����������
// bSni    - ��� ���������� ��������� ������ (�� 0 �� 4), ����� ��� 
//           ���������� ������ �����   2 ^ bSni
// pdwPUPI - ������ �� ������ ���� DWORD �������� 16, � ������� �����
//           �������� ���������������� �������������� ������������ ����,
//           �� 4 ����� ��� ����� ����� �� ������� �������
// pdwAppData - ������ �� ������ ���� DWORD �������� 16, � ������� �����
//              �������� ���������� � ����������� � ������������ ������,
//              �� 4 ����� ��� ����� ����� �� ������� �������
// pdwProtInfo - ������ �� ������ ���� DWORD �������� 16, � ������� �����
//               �������� ���������� � ���������� ������������ ����,
//               �� 3 ����� ��� ����� ����� �� ������� ������� � �����
//               � 0 �� 23
// pdwCardCount - ������ �� ���������� ���� DWORD, ������� ����� �������
//                ������� ������ ��������� ������ �������� pdwPUPI, 
//                pdwAppData � pdwProtInfo, � �� ������ ����� ��������� 
//                ���������� ������������ ���� (�� 0 �� 16)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������� ����� ISO 14443-B
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Attrib_B( IN     LPVOID  pReader,
                             IN     LPBYTE  pbPUPI,
                             IN     BYTE    bParam1,
                             IN     BYTE    bParam2,
                             IN     BYTE    bParam3,
                             IN     BYTE    bParam4,
                             IN OUT LPBYTE  pbHigherLayerBuf,
                             IN     DWORD   dwHLBufSize,
                             IN OUT LPDWORD pdwHLInfLength,
                                OUT LPBYTE  pbMbliCid );
//
// �������� ����� ISO 14443-B (��. ISO 14443-3 �.7.10) � ��������� �� 
// ���������� ������������� CID ���  ������ �� ��������� T = CL 
// (��. ISO 14443-4)
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbPUPI  - ������ �� ������ (4 �����), � ������� ���������
//           ���������������� ������������� ���������� �����
// bParam1 - ������ ����� �� ����������� � �����
// bParam2 - ������������ ������ ����� � �������� ������ �����������
// bParam3 - ��������� ������������ ��������� ISO 14443-4
// bParam4 - ���������� ������������� ����� (CID)
// pbHigherLayerBuf - ����� ���   Higher layer - INF  �� ����� 
//           �  Higher layer Response  �� ������    
// dwHLBufSize - ����� ������� pbHigherLayerBuf
// pdwHLInfLength - ������ �� ����������, � ������� �� ����� ��������� 
//           �����  Higher layer - INF   � ������� pbHigherLayerBuf  
//           � �� ������ � ��� ����� �������� ����� Higher layer Response, 
//           ����������� � ������ pbHigherLayerBuf
// pbMbliCid - ������ �� ����������, � ������� ����� �������� 
//           �������� MBLI CID
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������������� ����� ISO 14443-B � ��������� HALT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Halt_B( IN LPVOID pReader,
                           IN LPBYTE pbPUPI );
//
// ������������ ����� ISO 14443-B � ��������� HALT (��. ISO 14443-3 �.7.12)
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbPUPI  - ������ �� ������ (4 �����), � ������� ���������
//           ���������������� ������������� �������������� �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������������ ����� ISO 14443-B �� ��������� HALT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Activate_Wakeup_B( IN     LPVOID  pReader,
                                      IN     BYTE    bAfi,
                                      IN     BYTE    bSni,
                                         OUT LPDWORD pdwPUPI,    //16*4 bytes
                                         OUT LPDWORD pdwAppData, //16*4 bytes
                                         OUT LPDWORD pdwProtInfo,//16*4 bytes
                                      IN OUT LPDWORD pdwCardCount );
//
// ���������� ����� ISO 14443-B �� ��������� HALT (��. ISO 14443-3 �.7.7)
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bAfi    - ������������� ��������� ����������
// bSni    - ��� ���������� ��������� ������ (�� 0 �� 4), ����� ��� 
//           ���������� ������ �����   2 ^ bSni
// pdwPUPI - ������ �� ������ ���� DWORD �������� 16, � ������� �����
//           �������� ���������������� �������������� ������������ ����,
//           �� 4 ����� ��� ����� ����� �� ������� �������
// pdwAppData - ������ �� ������ ���� DWORD �������� 16, � ������� �����
//              �������� ���������� � ����������� � ������������ ������,
//              �� 4 ����� ��� ����� ����� �� ������� �������
// pdwProtInfo - ������ �� ������ ���� DWORD �������� 16, � ������� �����
//               �������� ���������� � ���������� ������������ ����,
//               �� 3 ����� ��� ����� ����� �� ������� ������� � �����
//               � 0 �� 23
// pdwCardCount - ������ �� ���������� ���� DWORD, ������� ����� �������
//                ������� ������ ��������� ������ �������� pdwPUPI, 
//                pdwAppData � pdwProtInfo, � �� ������ ����� ��������� 
//                ���������� ������������ ���� (�� 0 �� 16)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//           � � � � � � � � � �   � � � � � � �   I S O   1 5 6 9 3
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� ����������� �������������� ����� ISO 15693
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Inventory_15693( IN     LPVOID  pReader,
                                    IN     BYTE    bFlags,
                                    IN     BYTE    bInventory,
                                    IN     BYTE    bAfi,
                                    IN     BYTE    bMaskLen,
                                    IN     LPCBYTE pbMaskVal, 
                                       OUT LPBYTE  pbRecvBuffer, 
                                    IN OUT LPDWORD pdwRecvLength );
//
// ���������� �������������� ����� ISO 15693 (��. ISO 15693-3 �.10.3.1)
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags        - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bInventory    - ��� ������� Inventory (������ ����� 0x01)
// bAfi          - ������������� ��������� ����������
// bMaskLen      - ���������� ����� �����
// pbMaskVal     - ������ ������, ���������� �����
// pbRecvBuffer  - ������ ��� ������ �� �����������
// pdwRecvLength - ������ �� ���������� ���� DWORD, ������� ����� �������
//                 ������� ������ ��������� ������ ������� pbRecvBuffer, 
//                 � �� ������ ����� ��������� ���������� �������� ��
//                 ����������� ������ �� 1 ��� 16 ��������� ������
//
//      ��� ������� ���������� ����� � ������� pbRecvBuffer 
//      ����������� ��������� ����������:
//
//      RetCode - ��� ���������� ������� � ���� �����       - 1 ����
//      Count   - ���������� ������, ���������� �� �����    - 1 ����
// ���� Count ������� �� 0, �� ����� ������� ����� �� �����
// (��. ISO 15693 �.10.3.1):
//      Flags                                               - 1 ����
//      DSFID                                               - 1 ����
//      UID                                                 - 8 ������
// ���� RetCode ������� �� 0, �� ����� ����� ��������������
//      CRC16                                               - 2 �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� ����������� �������� �������������� ���� ����� ISO 15693
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_FindAllTags_15693( IN     LPVOID  pReader,
                                    IN     BYTE    bFlags,
                                    IN     BYTE    bAfi,
                                       OUT LPBYTE  pbRecvBuffer, 
                                    IN OUT LPDWORD pdwRecvLength );
//
// ���������� �������������� ����� ISO 15693 (��. ISO 15693-3 �.10.3.1)
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags        - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bAfi          - ������������� ��������� ����������
// pbRecvBuffer  - ������ ��� ������ �� �����������, � ������� ��������� 8-�������� �������������� 
//                 UID ���� ������������ �����
// pdwRecvLength - ������ �� ���������� ���� DWORD, ������� ����� �������
//                 ������� ������ ��������� ������ ������� pbRecvBuffer, 
//                 � �� ������ ����� ��������� ������������� ���������� ������������ �����
//
//                 
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ����� ISO 15693 � ��������� Quiet
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Stay_Quiet_15693( IN LPVOID pReader,
                                     IN BYTE   bFlags,
                                     IN BYTE   bStayQuiet,
                                     IN LPBYTE pbUID );
//
// ��������� ����� � ��������� Quiet (��. ISO 15693-3 �.10.3.2)
//
// pReader    - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags     - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bStayQuiet - ��� ������� Stay Quiet (������ ����� 0x02)
// pbUID      - ������ �� ������ (8 ������), � ������� ���������
//              ���������� ������������� �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ����� ISO 15693 � ��������� Selected
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Select_15693( IN     LPVOID pReader,
                                 IN     BYTE   bFlags,
                                 IN     BYTE   bSelect,
                                 IN     LPBYTE pbUID,
                                    OUT LPBYTE pbFlags,
                                    OUT LPBYTE pbErrorCode );
//
// ��������� ����� � ��������� Selected (��. ISO 15693-3 �.10.4.6)
//
// pReader     - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags      - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bSelect     - ��� ������� Select (������ ����� 0x25)
// pbUID       - ������ �� ������ (8 ������), � ������� ���������
//               ���������� ������������� �����
// pbFlags     - ������ �� ���������� ���� BYTE, � ������� �����
//               �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode - ������ �� ���������� ���� BYTE, � ������� �����
//               ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ����� ISO 15693 � ��������� Ready
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ResetToReady_15693( IN     LPVOID pReader,
                                       IN     BYTE   bFlags,
                                       IN     BYTE   bResetToReady,
                                       IN     LPBYTE pbUID,
                                          OUT LPBYTE pbFlags,
                                          OUT LPBYTE pbErrorCode );
//
// ��������� ����� � ��������� Ready (��. ISO 15693-3 �.10.4.7)
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags        - ����� ������� (��. ISO 15693-3 �.7.3.1)
//                 (������������� �������� ���� Select_flag)
// bResetToReady - ��� ������� Reset to ready (������ ����� 0x26)
// pbUID         - ������ �� ������ (8 ������), � ������� ���������
//                 ���������� ������������� �����, ����� ���� ����� NULL ���
//                 ���������� ����� Select_flag (�������������)
// pbFlags       - ������ �� ���������� ���� BYTE, � ������� �����
//                 �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode   - ������ �� ���������� ���� BYTE, � ������� �����
//                 ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
/*
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//           � � � � � � � � � �   � � � � � � �   I C O D E    E P C
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� �������������� ����� EPC
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_EPC_BeginRound( IN     LPVOID  pReader,
                                   IN     BYTE    bBeginRound,
                                   IN     BYTE    bMaskLen,
                                   IN     LPCBYTE pbMaskVal, 
                                   IN     BYTE    bSlotNCode,
                                   IN     BYTE    bHashVal,
                                   IN     BYTE    bFixCommand,
                                      OUT LPBYTE  pbRecvBuffer, 
                                   IN OUT LPDWORD pdwRecvLength );
//
// ���������� �������������� ����� EPC
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bBeginRound   - ��� ������� BeginRound (������ ����� 0x30)
// bMaskLen      - ���������� ����� ����� (�� 0 �� 96)
// pbMaskVal     - ������ ������, ���������� �����
// bSlotNCode    - ��� ���������� ������: 0 -> SlotCount = 1 ����
//                                        1 -> SlotCount = 4 �����
// bHashVal      - ������������� ���������� ������ �����
// bFixCommand   - 0 - �������� ����� � ��������� READY
//                 1 - ��������� ����� � ��������� FIXED SLOT
// pbRecvBuffer  - ������ ��� ������ �� �����������
// pdwRecvLength - ������ �� ���������� ���� DWORD, ������� ����� �������
//                 ������� ������ ��������� ������ ������� pbRecvBuffer, 
//                 � �� ������ ����� ��������� ���������� �������� ��
//                 ����������� ������

// ��������� ������ �� ����������� � ������� pbRecvBuffer:
//
//      RetCodeSlotF - ��� ������ � ������������� �����     - 1 ����
//         0x00 - ���� ����� � ������������� �����
//         0xff - ��� ������ � ������������� �����
//      ������ �� ����� � ������ 0..(SlotCount-1)

//      ��� ������� ����� � �������� �� 0 �� (SlotCount-1)
//      � ������� pbRecvBuffer ����������� ��������� ����������:
//
//      RetCode - ��� ���������� ������� � ���� �����       - 1 ����
//         0x00 - ��� ������
//         0xff - ��� ������
//         0xfe - �������� CRC16
//         0xf5 - �������� ���������� �������� �����
//         0xe8 - �������� � �����
//      Count   - ���������� ������, ���������� �� �����    - 1 ����
// ���� Count ������� �� 0, �� ����� ������� ����� �� �����,
// ��������� � ������������ � ������:
//      EPC                                         - (Count-2) ������
//      CRC16                                               - 2 �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ����� EPC � ��������� FIXED SLOT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_EPC_Fix_Slot( IN LPVOID  pReader,
                                 IN LPCBYTE pbEPC,
                                 IN LPCBYTE pbCRC16 );
//
// ��������� ����� EPC �� ��������� READY � ��������� FIXED SLOT
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbEPC   - ������ ������, ���������� �������� ������ ������ ����� 
//           � ������ � 0-�� �� 11-� ������������          - 12 ������
// pbCRC16 - ������ ������, ���������� �������� ������ ������ ����� 
//           � ������ � 12-�� �� 13-� ������������         -  2 �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ���� � ����� EPC
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_EPC_Write( IN LPVOID pReader,
                              IN BYTE   bWrite,
                              IN BYTE   bBlockNumber,
                              IN BYTE   bData );
//
// ���������� ���������� � �������� ���� ����� EPC
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bWrite       - ��� ������� Write (������ ����� 0x01)
// bBlockNumber - ����� ������������� ����� ������          - 1 ����
// bData        - ������������ ��������                     - 1 ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������������ ����� EPC
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_EPC_Destroy( IN LPVOID  pReader,
                                IN BYTE    bDestroy,
                                IN LPCBYTE pbEPC, 
                                IN LPCBYTE pbDestroyCode );
//
// ���������� ����� EPC
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bDestroy      - ��� ������� Destroy (������ ����� 0x02)
// pbEPC         - ������ ������, ���������� EPC            - 12 ������
// pbDestroyCode - ������ ������, ���������� Destroy Code   -  3 �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//           � � � � � � � � � �   � � � � � � �   I C O D E    U I D
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� �������������� ����� UID
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_UID_BeginRound( IN     LPVOID  pReader,
                                   IN     BYTE    bBeginRound,
                                   IN     BYTE    bMaskLen,
                                   IN     LPCBYTE pbMaskVal, 
                                   IN     BYTE    bSlotNCode,
                                   IN     BYTE    bFixCommand,
                                      OUT LPBYTE  pbRecvBuffer, 
                                   IN OUT LPDWORD pdwRecvLength );
//
// ���������� �������������� ����� UID
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bBeginRound   - ��� ������� BeginRound (������ ����� 0x30)
// bMaskLen      - ���������� ����� ����� (�� 0 �� 152)
// pbMaskVal     - ������ ������, ���������� �����
// bSlotNCode    - ��� ���������� ������: 0 -> SlotCount = 1 ����
//                                        1 -> SlotCount = 4 �����
// bFixCommand   - 0 - �������� ����� � ��������� READY
//                 1 - ��������� ����� � ��������� FIXED SLOT
// pbRecvBuffer  - ������ ��� ������ �� �����������
// pdwRecvLength - ������ �� ���������� ���� DWORD, ������� ����� �������
//                 ������� ������ ��������� ������ ������� pbRecvBuffer, 
//                 � �� ������ ����� ��������� ���������� �������� ��
//                 ����������� ������

// ��������� ������ �� ����������� � ������� pbRecvBuffer:
//
//      RetCodeSlotF - ��� ������ � ������������� �����     - 1 ����
//         0x00 - ���� ����� � ������������� �����
//         0xff - ��� ������ � ������������� �����
//      ������ �� ����� � ������ 0..(SlotCount-1)

//      ��� ������� ����� � �������� �� 0 �� (SlotCount-1)
//      � ������� pbRecvBuffer ����������� ��������� ����������:
//
//      RetCode - ��� ���������� ������� � ���� �����       - 1 ����
//         0x00 - ��� ������
//         0xff - ��� ������
//         0xfe - �������� CRC16
//         0xf5 - �������� ���������� �������� �����
//         0xe8 - �������� � �����
//      Count   - ���������� ������, ���������� �� �����    - 1 ����
// ���� Count ������� �� 0, �� ����� ������� ����� �� �����,
// ��������� � ������������ � ������:
//      IDD                                         - (Count-2) ������
//      CRC16                                               - 2 �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ����� UID � ��������� FIXED SLOT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_UID_Fix_Slot( IN LPVOID  pReader,
                                 IN LPCBYTE pbIDD,
                                 IN LPCBYTE pbCRC16 );
//
// ��������� ����� UID �� ��������� READY � ��������� FIXED SLOT
//
// pReader  - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbIDD   - ������ ������, ���������� �������� ������ ������ ����� 
//           � ������ � 0-�� �� 18-� ������������          - 19 ������
// pbCRC16 - ������ ������, ���������� �������� ������ ������ ����� 
//           � ������ � 19-�� �� 20-� ������������         -  2 �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ���� � ����� UID
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_UID_Write( IN LPVOID pReader,
                              IN BYTE   bWrite,
                              IN BYTE   bBlockNumber,
                              IN BYTE   bData );
//
// ���������� ���������� � �������� ���� ����� UID
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bWrite       - ��� ������� Write (������ ����� 0x01)
// bBlockNumber - ����� ������������� ����� ������          - 1 ����
// bData        - ������������ ��������                     - 1 ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������������ ����� UID
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_UID_Destroy( IN LPVOID  pReader,
                                IN BYTE    bDestroy,
                                IN LPCBYTE pbIDD, 
                                IN LPCBYTE pbDestroyCode );
//
// ���������� ����� UID
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bDestroy      - ��� ������� Destroy (������ ����� 0x02)
// pbIDD         - ������ ������, ���������� IDD            - 19 ������
// pbDestroyCode - ������ ������, ���������� Destroy Code   -  3 �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
*/
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//       � � � � � �   �   � � � � � � �   M I F A R E   S T A N D A R D
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_HostCodeKey( IN     LPVOID pReader,
                                               IN     LPBYTE pbUncoded,
                                                  OUT LPBYTE pbCoded );
//
// �������� ���� Mifare Standard
//
// pReader   - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbUncoded - ������ (6 ������) ��������� (���������������) �����
// pbCoded   - ������ (12 ������) ������������� �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ����������������� ������ ���������������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_AuthKey( IN LPVOID pReader,
                                           IN BYTE   bKeyType,
                                           IN LPBYTE pbUID,
                                           IN DWORD  dwSector,
                                           IN LPBYTE pbCodedKey );
//
// ���������� �������������� ������� ��������������� �������� ������
//
// pReader    - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bKeyType   - ��� �����: 0x60 - Key A
//                         0x61 - Key B
// pbUID      - ������ (4 �����), ���������� ���������� ������������� �����
// dwSector   - ����� ������������������ �������
// pbCodedKey - ������ (12 ������) ������������� �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ����������������� ������ ��������������� 6-�������� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_AuthKeyDirect(	IN LPVOID pReader,
													IN BYTE   bKeyType,
													IN LPBYTE pbUID,
													IN DWORD  dwSector,
													IN LPBYTE pbKey );
//
// ���������� �������������� ������� ��������������� �������� ������
//
// pReader    - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bKeyType   - ��� �����: 0x60 - Key A
//                         0x61 - Key B
// pbUID      - ������ (4 �����), ���������� ���������� ������������� �����
// dwSector   - ����� ������������������ �������
// pbKey	  - ������ (6 ������) �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ���� � EEPROM �����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_WriteKeyToE2( IN LPVOID pReader,
                                                IN BYTE   bKeyType,
                                                IN DWORD  dwE2RecNo,
                                                IN LPBYTE pbUncoded );
//
// ���������� ���� ��������� ���� ��� ��������� ������� � EEPROM �����������
//
// pReader   - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bKeyType  - ��� �����: 0x60 - Key A
//                        0x61 - Key B
// dwE2RecNo - ����� ������ � EEPROM �����������, � ������� ������������ ����
//			   (������������� ������ ������� ��� ������������� ������� 
//			    CLSCRF_MifareStandard_AuthE2, 0..15)
// pbUncoded - ������ (6 ������) ��������������� �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ����������������� ������ ���������� ������ �� EEPROM
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
		CLSCRF_MifareStandard_AuthE2Ex(   IN LPVOID pReader,
                                          IN BYTE   bKeyType,
                                          IN LPBYTE pbUID,
                                          IN DWORD  dwE2RecNo,
                                          IN DWORD  dwSector );
//
// ���������� �������������� ������� ������, ����������� � EEPROM �����������
//
// pReader    - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bKeyType   - ��� �����: 0x60 - Key A
//                         0x61 - Key B
// pbUID      - ������ (4 �����), ���������� ���������� ������������� �����
// dwE2RecNo  - ����� ������ � EEPROM �����������, �� ������� ����� ����� ����
//				(0..15)
// dwSector   - ����� ������������������ �������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ����������������� ������ ��������������� ������ �� EEPROM
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_AuthE2( IN LPVOID pReader,
                                          IN BYTE   bKeyType,
                                          IN LPBYTE pbUID,
                                          IN DWORD  dwSector );
//
// ���������� �������������� ������� ������, ����������� � EEPROM �����������
//
// pReader    - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bKeyType   - ��� �����: 0x60 - Key A
//                         0x61 - Key B
// pbUID      - ������ (4 �����), ���������� ���������� ������������� �����
// dwSector   - ����� ������������������ ������� (0..15)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_Read( IN     LPVOID pReader,
                                        IN     DWORD  dwSector,
                                        IN     DWORD  dwBlock,
                                           OUT LPBYTE pbRecvBuffer );
//
// ������ 16 ������ �� ��������� ����� � �������� �������
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwSector     - ����� �������, ����������� �������� ����
// dwBlock      - ����� ��������� �����
// pbRecvBuffer - ������ (�� ����� 16 ������) ��� ������������ �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����� ������� ���� ������� ������ ���� ��������� �������������� �������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_Write( IN LPVOID pReader,
                                         IN DWORD  dwSector,
                                         IN DWORD  dwBlock,
                                         IN LPBYTE pbSendBuffer );
//
// ���������� 16 ������ � �������� ���� � �������� �������
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwSector     - ����� �������, ����������� ������������ ����
// dwBlock      - ����� ������������� �����
// pbSendBuffer - ������ (�� ����� 16 ������) ������ ������������� �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����� ������� ���� ������� ������ ���� ��������� �������������� �������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_Decrement( IN LPVOID pReader,
                                             IN DWORD  dwSector,
                                             IN DWORD  dwSourceBlock,
                                             IN DWORD  dwValue,
                                             IN DWORD  dwTargetBlock );
//
// ��������� �������� ����� ���� Value
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwSector      - ����� �������, ����������� �������� ����
// dwSourceBlock - ����� ��������� �����
// dwValue       - ����������, �� ������� ����������� ��������
// dwTargetBlock - ����� �����-����������, ����� ���� ����� dwSourceBlock
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����� ������� ���� ������� ������ ���� ��������� �������������� �������
// ����� dwSourceBlock � dwTargetBlock ������ ������������ ������� dwSector
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_Increment( IN LPVOID pReader,
                                             IN DWORD  dwSector,
                                             IN DWORD  dwSourceBlock,
                                             IN DWORD  dwValue,
                                             IN DWORD  dwTargetBlock );
//
// ����������� �������� ����� ���� Value
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwSector      - ����� �������, ����������� �������� ����
// dwSourceBlock - ����� ��������� �����
// dwValue       - ���������, �� ������� ������������� ��������
// dwTargetBlock - ����� �����-����������, ����� ���� ����� dwSourceBlock
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����� ������� ���� ������� ������ ���� ��������� �������������� �������
// ����� dwSourceBlock � dwTargetBlock ������ ������������ ������� dwSector
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_Restore( IN LPVOID pReader,
                                           IN DWORD  dwSector,
                                           IN DWORD  dwSourceBlock,
                                           IN DWORD  dwTargetBlock );
//
// �������� �������� �� ������ ����� ���� Value � ������ � �������� �������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwSector      - ����� �������, ����������� ��� �����
// dwSourceBlock - ����� ��������� �����
// dwTargetBlock - ����� �����-����������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����� ������� ���� ������� ������ ���� ��������� �������������� �������
// ����� dwSourceBlock � dwTargetBlock ������ ������������ ������� dwSector
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������������� UID
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_EV1_PersonalizeUid(	IN LPVOID pReader,
														IN BYTE  ucUidMode );
//
// ������� ����������� ���� ��� � ������ ����� �����, ������������ ���� �� ������� UID
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucUidMode     - ����� UID (�����, � ������� ����������� �����)
//					���� �� ��������: 
//					UIDF0 = 0x00, 
//					UIDF1 = 0x40, 
//					UIDF2 = 0x20, 
//					UIDF3 = 0x60
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����� ������� ���� ������� ������ ���� ��������� �������������� ������� 0
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� �������� ������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_EV1_SetLoadModulationType(	IN LPVOID pReader,
																IN BYTE  ucModType );
//
// ������� ���������� �������� ������� ����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucModType     - ��� ��������: 0x01 - ������� (�� ���������), 0x00 - ����������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����� ������� ���� ������� ������ ���� ��������� �������������� ������� 0
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//   � � � � � �    �    � � � � � � �    M I F A R E    U L T R A L I G H T (C)
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareUltralight_Read( IN     LPVOID pReader,
                                          IN     BYTE   bPage,
                                             OUT LPBYTE pbRecvBuffer );
//
// ������ 4 �������� (16 ������), ������� � �������� ��������
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bPage        - ����� �������� ��������
// pbRecvBuffer - ������ (�� ����� 16 ������) ��� ����������� ��������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareUltralight_Write( IN LPVOID pReader,
                                           IN BYTE   bPage,
                                           IN LPBYTE pbSendBuffer );
//
// ����� 4 ����� � �������� ��������
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bPage        - ����� ������������ ��������
// pbSendBuffer - ������ (�� ����� 4 ������) ������ ������������ ��������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��� ���� Ultra Light C: ������ �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareUltralightC_WriteKey(	IN LPVOID pReader,
												IN DWORD  dwKeyFlashAddress );
//
// ���������� ������ � ����� ����� �� flash ����������� 
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwKeyFlashAddress - ����� ����� �� flash �����������, 
// ������� ������� �������� � �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��� ���� Ultra Light C: ��������������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareUltralightC_Authenticate(	IN LPVOID pReader,
													IN DWORD  dwKeyFlashAddress );
//
// ���������� �������������� �� �����
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwKeyFlashAddress - ����� ����� �� flash �����������, 
// ������� ������� ������������ ��� �������������� 
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//             � � � � � �   �   � � � � � � �   I S O   1 5 6 9 3
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ReadSingleBlock_15693( IN     LPVOID pReader,
                                          IN     BYTE   bFlags,
                                          IN     BYTE   bReadSingleBlock,
                                          IN     LPBYTE pbUID,
                                          IN     BYTE   bBlockNumber,
                                             OUT LPBYTE pbFlags,
                                             OUT LPBYTE pbBlockSecurityStatus,
                                             OUT LPBYTE pbData,
                                             OUT LPBYTE pbErrorCode );
//
// ������ 4 ����� �� ��������� ����� (��. ISO 15693-3 �.10.4.1)
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bReadSingleBlock - ��� ������� Read Single Block (������ ����� 0x20)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// bBlockNumber - ����� ��������� ����� (�� 0)
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbBlockSecurityStatus - ������ �� ���������� ���� BYTE, � ������� �����
//                         ������� ������ ������ ����� �� ������
// pbData       - ������ �� ������ (�� ����� 4 ������) ��� ������������ �����
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_WriteSingleBlock_15693( IN     LPVOID pReader,
                                           IN     BYTE   bFlags,
                                           IN     BYTE   bWriteSingleBlock,
                                           IN     LPBYTE pbUID,
                                           IN     BYTE   bBlockNumber,
                                           IN     LPBYTE pbData,
                                              OUT LPBYTE pbFlags,
                                              OUT LPBYTE pbErrorCode );
//
// ���������� 4 ����� � �������� ���� (��. ISO 15693-3 �.10.4.2)
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bWriteSingleBlock - ��� ������� Write Single Block (������ ����� 0x21)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// bBlockNumber - ����� ������������� ����� (�� 0)
// pbData       - ������ �� ������ (�� ����� 4 ������) ������������ �������
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_WriteMultipleBlocks_15693(	IN		LPVOID pReader,
												IN		BYTE   bFlags,
												IN		BYTE   bWriteMultipleBlocks,
												IN		LPBYTE pbUID,
												IN		BYTE   bBlockNumber,
												IN		BYTE   bBlocksCount,
												IN		LPBYTE pbData,
													OUT LPBYTE pbFlags,
													OUT LPBYTE pbErrorCode );
//
// ���������� 4*bBlocksCount ���� � �������� �������� ������ (��. ISO 15693-3 �.10.4.5)
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bWriteMultipleBlocks - ��� ������� Write Multiple Blocks (������ ����� 0x24)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// bBlockNumber - ����� ������� ������������� ����� (�� 0)
// bBlocksCount - ���������� ������������ ������ (�� 1)
// pbData       - ������ �� ������ (�� ����� 4 ������) ������������ �������
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ����������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_LockBlock_15693( IN     LPVOID pReader,
                                    IN     BYTE   bFlags,
                                    IN     BYTE   bLockBlock,
                                    IN     LPBYTE pbUID,
                                    IN     BYTE   bBlockNumber,
                                       OUT LPBYTE pbFlags,
                                       OUT LPBYTE pbErrorCode );
//
// ������������ �������� ���� �� ���������� (��. ISO 15693-3 �.10.4.3)
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bLockBlock   - ��� ������� Lock Block (������ ����� 0x22)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// bBlockNumber - ����� ������������ ����� (�� 0)
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ��������� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ReadMultipleBlocks_15693( IN     LPVOID pReader,
                                             IN     BYTE   bFlags,
                                             IN     BYTE   bReadMultipleBlock,
                                             IN     LPBYTE pbUID,
                                             IN     BYTE   bFirstBlockNumber,
                                             IN OUT LPBYTE pbNumberOfBlocks,
                                                OUT LPBYTE pbFlags,
                                                OUT LPBYTE pbBlockSecurityStatus,
                                                OUT LPBYTE pbData,
                                                OUT LPBYTE pbErrorCode );
//
// ������ ��������� ������ (��. ISO 15693-3 �.10.4.4)
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bReadMultipleBlock - ��� ������� Read Multiple Block (������ ����� 0x23)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// bFirstBlockNumber - ����� ������� ��������� ����� (�� 0)
// pbNumberOfBlocks - ������ �� ���������� ���� BYTE, ������� ����� �������
//                    ������� ������ ��������� ���������� (�� 0) �������� 
//                    ������, � �� ������ ����� ��������� ���������� 
//                    (���� �� 0) ������������� ����������� ������
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbBlockSecurityStatus - ������ �� ������ (�� 256 ������) ���� BYTE, � 
//                         ������� ����� �������� �������� ������� ������ 
//                         ������ �� ������ (������ ��� ������� ����� 
//                         Option_flag)
// pbData       - ������ �� ������ (�� 8192 ������) ��� ����������� ������
//                (�� 4 ����� �� ������ ����)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� AFI
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_WriteAFI_15693( IN     LPVOID pReader,
                                   IN     BYTE   bFlags,
                                   IN     BYTE   bWriteAFI,
                                   IN     LPBYTE pbUID,
                                   IN     BYTE   bAFI,
                                      OUT LPBYTE pbFlags,
                                      OUT LPBYTE pbErrorCode );
//
// ���������� 1 ���� AFI (��. ISO 15693-3 �.10.4.8)
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bWriteAFI    - ��� ������� Write AFI (������ ����� 0x27)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// bAFI         - ������������ �������� AFI
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ����������� AFI
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_LockAFI_15693( IN     LPVOID pReader,
                                  IN     BYTE   bFlags,
                                  IN     BYTE   bLockAFI,
                                  IN     LPBYTE pbUID,
                                     OUT LPBYTE pbFlags,
                                     OUT LPBYTE pbErrorCode );
//
// ������������ AFI �� ���������� (��. ISO 15693-3 �.10.4.9)
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bLockAFI     - ��� ������� Lock AFI (������ ����� 0x28)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� DSFID
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_WriteDSFID_15693( IN     LPVOID pReader,
                                     IN     BYTE   bFlags,
                                     IN     BYTE   bWriteDSFID,
                                     IN     LPBYTE pbUID,
                                     IN     BYTE   bDSFID,
                                        OUT LPBYTE pbFlags,
                                        OUT LPBYTE pbErrorCode );
//
// ���������� 1 ���� DSFID (��. ISO 15693-3 �.10.4.10)
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bWriteDSFID  - ��� ������� Write DSFID (������ ����� 0x29)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// bDSFID       - ������������ �������� DSFID
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ����������� DSFID
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_LockDSFID_15693( IN     LPVOID pReader,
                                    IN     BYTE   bFlags,
                                    IN     BYTE   bLockDSFID,
                                    IN     LPBYTE pbUID,
                                       OUT LPBYTE pbFlags,
                                       OUT LPBYTE pbErrorCode );
//
// ������������ DSFID �� ���������� (��. ISO 15693-3 �.10.4.11)
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bLockDSFID   - ��� ������� Lock DSFID (������ ����� 0x2a)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������ ��������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_GetSystemInfo_15693( IN     LPVOID pReader,
                                        IN     BYTE   bFlags,
                                        IN     BYTE   bGetSystemInfo,
                                        IN OUT LPBYTE pbUID,
                                           OUT LPBYTE pbFlags,
                                           OUT LPBYTE pbInfoFlags,
                                           OUT LPBYTE pbDSFID,
                                           OUT LPBYTE pbAFI,
                                           OUT LPWORD pbMemorySize,
                                           OUT LPBYTE pbICReference,
                                           OUT LPBYTE pbErrorCode );
//
// ������ �������� ��������� ���������� (��. ISO 15693-3 �.10.4.12)
//
// pReader        - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags         - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bGetSystemInfo - ��� ������� Get System Information (������ ����� 0x2b)
// pbUID          - ������ �� ������ (8 ������), ������� ����� �������
//                  ������� ����� ��������� ���������� ������������� �����, �
//                  �� ������ ����� ��������� ���������� ������������� �����, 
//                  ����������� ��� ����� ��������� ����������
// pbFlags        - ������ �� ���������� ���� BYTE, � ������� �����
//                  �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbInfoFlags    - ������ �� ���������� ���� BYTE, � ������� �����
//                  �������� ����� ��������� ����������
// pbDSFID        - ������ �� ���������� ���� BYTE, � ������� �����
//                  �������� �������� DSFID
// pbAFI          - ������ �� ���������� ���� BYTE, � ������� �����
//                  �������� �������� AFI
// pbMemorySize   - ������ �� ���������� ���� WORD, � ������� �����
//                  �������� �������� Information on VICC memory size
// pbICReference  - ������ �� ���������� ���� BYTE, � ������� �����
//                  �������� �������� Information on IC reference
// pbErrorCode    - ������ �� ���������� ���� BYTE, � ������� �����
//                  ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������ �������� ������� ������ ������ �� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_GetMultipleBSS_15693( IN     LPVOID pReader,
                                         IN     BYTE   bFlags,
                                         IN     BYTE   bGetMultipleBSS,
                                         IN     LPBYTE pbUID,
                                         IN     BYTE   bFirstBlockNumber,
                                         IN OUT LPBYTE pbNumberOfBlocks,
                                            OUT LPBYTE pbFlags,
                                            OUT LPBYTE pbBlockSecurityStatus,
                                            OUT LPBYTE pbErrorCode );
//
// ������ �������� ������� ������ ������ �� ������ (block security status)
// (��. ISO 15693-3 �.10.4.13)
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bGetMultipleBSS - ��� ������� Get Multiple Block Security Status
//                   (������ ����� 0x2c)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// bFirstBlockNumber - ����� ������� ��������� ����� (�� 0)
// pbNumberOfBlocks - ������ �� ���������� ���� BYTE, ������� ����� �������
//                    ������� ������ ��������� ���������� (�� 0) �������� 
//                    �������� ������� ������ ������ �� ������,
//                    � �� ������ ����� ��������� ���������� 
//                    (���� �� 0) ������������� ����������� ��������
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbBlockSecurityStatus - ������ �� ������ (�� 256 ������) ���� BYTE, � 
//                         ������� ����� �������� �������� ������� ������ 
//                         ������ �� ������
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� EAS
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_SetEAS_15693( IN     LPVOID pReader,
                                 IN     BYTE   bFlags,
                                 IN     BYTE   bSetEAS,
                                 IN     BYTE   bICMfgCode,
                                 IN     LPBYTE pbUID,
                                    OUT LPBYTE pbFlags,
                                    OUT LPBYTE pbErrorCode );
//
// ������������� EAS � 1
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bSetEAS      - ��� ������� Set EAS (������ ����� 0xa2)
// bICMfgCode   - ��� ������������� ���������� �����
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� EAS
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ResetEAS_15693( IN     LPVOID pReader,
                                   IN     BYTE   bFlags,
                                   IN     BYTE   bResetEAS,
                                   IN     BYTE   bICMfgCode,
                                   IN     LPBYTE pbUID,
                                      OUT LPBYTE pbFlags,
                                      OUT LPBYTE pbErrorCode );
//
// ���������� EAS � 0
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bResetEAS    - ��� ������� Reset EAS (������ ����� 0xa3)
// bICMfgCode   - ��� ������������� ���������� �����
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ����������� EAS
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_LockEAS_15693( IN     LPVOID pReader,
                                  IN     BYTE   bFlags,
                                  IN     BYTE   bLockEAS,
                                  IN     BYTE   bICMfgCode,
                                  IN     LPBYTE pbUID,
                                     OUT LPBYTE pbFlags,
                                     OUT LPBYTE pbErrorCode );
//
// ������������ EAS �� ����������
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bLockEAS     - ��� ������� Lock EAS (������ ����� 0xa4)
// bICMfgCode   - ��� ������������� ���������� �����
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� EAS
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_EASAlarm_15693( IN     LPVOID pReader,
                                   IN     BYTE   bFlags,
                                   IN     BYTE   bEASAlarm,
                                   IN     BYTE   bICMfgCode,
                                   IN     LPBYTE pbUID,
                                      OUT LPBYTE pbFlags,
                                      OUT LPBYTE pbEASData,
                                      OUT LPBYTE pbErrorCode );
//
// ������ EAS-������������������, ���� ��� EAS ���������� � 1
//
// pReader      - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bFlags       - ����� ������� (��. ISO 15693-3 �.7.3.1)
// bEASAlarm    - ��� ������� EAS Alarm (������ ����� 0xa5)
// pbUID        - ������ �� ������ (8 ������), � ������� ���������
//                ���������� ������������� �����
// bICMfgCode   - ��� ������������� ���������� �����
// pbFlags      - ������ �� ���������� ���� BYTE, � ������� �����
//                �������� ����� ������ (��. ISO 15693-3 �.7.4.1)
// pbEASData    - ������ �� ������ (32 �����) ��� ����������� 
//                EAS-������������������
// pbErrorCode  - ������ �� ���������� ���� BYTE, � ������� �����
//                ������� ��� ������ (��. ISO 15693-3 �.7.4.2)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//         � � � � � � � � � � � � � � � �   � � � � �   � � � � � � �
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ����� ������� �� ������������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_DirectIO_Reader( IN     LPVOID  pReader,
                                    IN     LPCBYTE pbSendBuffer, 
                                    IN     DWORD   dwSendLength, 
                                       OUT LPBYTE  pbRecvBuffer, 
                                    IN OUT LPDWORD pdwRecvLength );
//
// �������� ����������� ������� � ��������� ����� �� ���
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbSendBuffer  - ������ ������, ������������ �����������
// dwSendLength  - ���������� ������������ ������
// pbRecvBuffer  - ������ ��� ������ �� �����������
// pdwRecvLength - ������ �� ���������� ���� DWORD, ������� ����� �������
//                 ������� ������ ��������� ������ ������� pbRecvBuffer, 
//                 � �� ������ ����� ��������� ���������� �������� ��
//                 ����������� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������������� ����� ������� � ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_DirectIO_Card( IN     LPVOID  pReader,
                                  IN     LPCBYTE pbSendBuffer, 
                                  IN     DWORD   dwSendLength, 
                                  IN     DWORD   dwTimeout,
                                     OUT LPBYTE  pbRecvBuffer, 
                                  IN OUT LPDWORD pdwRecvLength );
//
// ������������ �������� ������ ����� ��� ��������������� ��������� � 
// ����������� ����� ������ �� �����, � ��� ����� ��� ���������� ������ 
// ����� �� ��������� ISO 14443-4 (T=CL)
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbSendBuffer  - ������ ������, ������������ �����
// dwSendLength  - ���������� ������������ � ����� ������
// dwTimeout     - �������� �������� ����� � �������� (128 / 13,56)[���]
// pbRecvBuffer  - ������ ��� ������ �� �����
// pdwRecvLength - ������ �� ���������� ���� DWORD, ������� ����� �������
//                 ������� ������ ��������� ������ ������� pbRecvBuffer, 
//                 � �� ������ ����� ��������� ���������� �������� ��
//                 ����� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
//------------------------------------------------------------------------------
//  ����� ������� � ������� APDU � ���������� ������ �� ISO 7816
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_APDU_7816( IN     LPVOID  pReader,
                              IN     LPCBYTE pbSendBuffer, 
                              IN     DWORD   dwSendLength, 
                                 OUT LPBYTE  pbRecvBuffer, 
                              IN OUT LPDWORD pdwRecvLength );
//
// ������������ �������� ������� 
// ���������� ����� � ���� ������ �� �� �� ��������� ISO 7816
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbSendBuffer  - ������ ������, ������������ ���������� �����
// dwSendLength  - ���������� ������������ � ����� ������
// pbRecvBuffer  - ������ ��� ������ �� ���������� �����
// pdwRecvLength - ������ �� ���������� ���� DWORD, ������� ����� �������
//                 ������� ������ ��������� ������ ������� pbRecvBuffer, 
//                 � �� ������ ����� ��������� ���������� �������� ��
//                 ���������� ����� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
*/
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//    � � � � � � � � � � � �   � � � � � � � � �   � �   � � � �   R S 4 8 5
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// ���������� �� ���� RS485 ������ ����� ������ ������
// ����� - ��� ����� �� 0 �� 255
// ��� �������� ���������� � �������� �������� ��������������� ����� 0
// �� ������� �� ������ 0 ����������� �������� ���������� �� ������ ������
// ������� �� ������ 0 ��������� ������ � ������ ������ ���������� �� ����
// ����� ���������� � ������� ���������� ���������� �������� ����� ������
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������ ����� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_GetIOAddress( IN     LPVOID pReader,
                                    OUT LPBYTE pbIOAddr );
//
// ������ ����� ����������, � ������� ������������ ����� �������
//
// pReader  - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbIOAddr - ����� ���������� ���� unsigned char, � ������� ����� �������
//            �����  ����������, � ������� ������������ ����� �������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� ����� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_SetIOAddress( IN LPVOID pReader,
                                 IN BYTE   bIOAddr );
//
// ������ ����� ����������, � ������� ����� ������������� ����� �������
// �������� ������ 0 ��������� ���� ��� �������, ��� �� ���� RS485
// ��������� ������ ���� �����������
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bIOAddr  - ����� ����������, � ������� ����� ������������� ����� �������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ����� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ReadDeviceAddress( IN     LPVOID pReader,
                                         OUT LPBYTE pbDevAddr );
//
// ������ ����� ����������.
// ���� ����� ���������� ����������, ���������� �������� ���������� �� ����
// RS485 ������������, ������ ����� ������ 0 (��. CLSCRF_SetIOAddress())
// � ������� ������ �������.
//
// pReader   - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pbDevAddr - ����� ���������� ���� unsigned char, � ������� ����� �������
//             �����  ����������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ����� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_WriteDeviceAddress( IN LPVOID pReader,
                                       IN BYTE   bDevAddr );
//
// ������ ���������� ����� ����� � ���������� ��� �� flash-������
//
// pReader - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// bDevAddr - ����� ����� ����������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
//------------------------------------------------------------------------------
//  ����������������� ����� DESFire
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_DESFire_Authenticate( IN LPVOID pReader,
                                         IN DWORD  dwKeyNumber );
//
// ���������� �������������� ����� DESFire
//
// pReader     - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwKeyNumber - ����� ����� DES �� 0 �� 31
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ���� DES �������������� ������ ���� ������� �� flash-������,
// ����� ���� � ������� 0 ����� 0x0000000000000000,
// ��������� ����� ����� 0xFFFFFFFFFFFFFFFF
//
*/
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
//------------------------------------------------------------------------------
//  �������� �� flash-������ ���� AES
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_WriteFlash_AESKey( IN LPVOID pReader,
                                        IN DWORD  dwKeyNumber,
                                        IN LPBYTE pbK16,
                                        IN LPBYTE pbICV16 );
//
// ���������� �� flash-������ ���� AES
//
// pReader     - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwKeyNumber - ����� ����� �� 0 �� 12
// pbK16       - ������ ����� (�� ����� 16 ������)
// pbICV16      - ������ ���������� ������� CBC (�� ����� 16 ������)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/
//==============================================================================
//                A E S ( � �  1 2 8 - � � � � � �   � � � � � � )
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� � ������������� ���� ����� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_SaveAESKeysToFile( IN LPSTR  lsFileName,
                                             IN LPBYTE pbIV, 
                                             IN LPBYTE pbKeys,  
                                             IN DWORD  dwKeysCount,
                                             IN LPSTR  lsPassword);
//
// ��������� � ������������� ���� ����� ����������
//      
// lsFileName  - ��� �����, ASCII-������, ������ ������������� ����
// pbIV        - ������ �� 16 ���� - ������ ������������� ��� ���������� ����� 
// pbKeys      - ������ ������, ������ ���� ������������ �� ���� 16 ���� � ���� 
//               �������
// dwKeysCount - ���������� ������ ����������
// lsPassword  - ������ ��� ���������� �����, ASCII-������, ������ �������������
//               ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  C������������ � ��������� � ������������� ���� ��������������� ����� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_GenerateAndSaveAESKeysToFile( IN LPSTR  lsFileName,
                                                        IN DWORD  dwKeysCount,
                                                        IN LPSTR  lsPassword);
//
// ���������� � ��������� � ������������� ���� ��������������� ����� ����������
//       
// lsFileName  - ��� �����, ASCII-������, ������ ������������� ����
// dwKeysCount - ���������� ������ ����������
// lsPassword  - ������ ��� ���������� �����, ASCII-������, ������ �������������
//               ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� �� ����� ����� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_LoadAESKeysFromFile( IN LPVOID pReader,
                                               IN LPSTR  lsFileName,
                                               IN LPSTR  lsPassword,
                                               IN OUT LPDWORD ldKeysCount);
//
// ��������� �� ����� ����� ����������
//       
// pReader     - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// lsFileName  - ��� �����, ASCII-������, ������ ������������� ����
// lsPassword    - ������ ��� ����������� �����, ASCII-������, ������ �������������
//               ����
// ldKeysCount - ���������� ������, ������� ��������� ���������, � ����� �������� - 
//               ���������� ����������� �� ����� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� �� flash-������ ����� AES
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_WriteFlash_AESKeys(  IN LPVOID pReader,
                                               IN DWORD  dwStartKey,
                                               IN DWORD  dwKeysCount );
//
// ���������� �� flash-������ ����� AES
//
// pReader     - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwStartKey  - ����� ������� �����
// dwKeysCount - ���������� ������ (�������� 9)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// �������������� ����� ������ ���� ��������� �������� 
// CLSCRF_Crypto_LoadAESKeysFromFile
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ���������� ����� ������ �� ������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_SetEncryptionMode(	IN LPVOID pReader,
												IN BOOL fEncryptionMode );
//
// ������������� ������������� ����� ������ �� ������� �����. 
// ���������� � ������, ���� ����������� ����� � �������� ����� ������.
//
// pReader			- ������ �� ������-��������� (��. ������� CLSCRF_Create );
// fEncryptionMode  - ����� ������ (1 - �����������, 0 - ��������)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ����� ������ �� ������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_GetEncryptionMode(	IN LPVOID pReader,
												OUT PBOOL pfEncryptionMode );
//
// ��������� ������� ����� ������ �� ������� �����. 
//
// pReader			- ������ �� ������-��������� (��. ������� CLSCRF_Create );
// pfEncryptionMode - ��������� �� ���������� ���� BOOL, � ������� �����
//					  ������� ����������� ����� ������ 
//					  (1 - �����������, 0 - ��������)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ���������� ������ � �������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_GetAESKeysCount(	IN LPVOID pReader,
											OUT LPDWORD pdwKeysCount);
//
// ���������� ������������� ����� � ����������� � ������������� ����� ������������ 
// ������ ��� �������� ��������������
//
// pReader     - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pdwKeysCount - ��������� �� ����������, ���� ����� �������� ���������� 
//				  ����������� ������ �� flash-������ �����������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����� ������ ���� ��������� ��������
// CLSCRF_Crypto_LoadAESKeysFromFile ��
// ������ CLSCRF_Crypto_AuthenticateReader
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� ���� �� �������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_GetAESKey( IN  LPVOID	pReader,
                                     IN  DWORD	dwKeyIndex,
                                     OUT LPBYTE	lpKey);
//
// ���������� ������ ����� �� ���������� ������� �� ������� ������,
// ����������� �������� CLSCRF_Crypto_LoadAESKeysFromFile
//
// pReader    - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwKeyIndex - ����� ����� �� flash-������ �����������
// lpKey	  - ��������� �� ������ �� 16 ����, ���� ����� ������� ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����� ������ ���� ��������� ��������
// CLSCRF_Crypto_LoadAESKeysFromFile ��
// ������ CLSCRF_Crypto_GetAESKey
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� �������������� �����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_AuthenticateReader(	IN LPVOID pReader,
												IN BYTE ucAuthType,
												IN DWORD dwKeyNumber );
//
// ���������� ������������� ����� � ����������� � ������������� ����� ������������ 
// ������ ��� �������� ��������������
//
// pReader     - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucAuthType  - ��� �������� (0x00 - ����� ��������������, 0x01 - ��������������)
// dwKeyNumber - ����� ����� �� flash-������ �����������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
// ����� ������ ���� ��������� ��������
// CLSCRF_Crypto_LoadAESKeysFromFile ��
// ������ CLSCRF_Crypto_AuthenticateReader
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� flash
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_EraseFlash(	IN LPVOID pReader );
//
// ������� flash ��� ����������� ������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� �� flash ���� �� ���������� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_WriteFlashValue(	IN LPVOID pReader,
									IN DWORD  dwAddress,
									IN LPBYTE  pbValue );
//
// �������� �� flash ���� (16 ����) �� ���������� ������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwAddress	 - ����� ����� �� flash
// pbValue       - ��������� �� ���� (16 ����)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  �������� ������������� ����� flash-������ �����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_CheckFlashValueFilled( IN LPVOID pReader,
										  IN DWORD  dwFlashAddr,
										  OUT LPBYTE pbStatus );
//
// �������� ������������� ����� flash-������ �����������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwFlashAddr	 - ����� ����� ������ �� flash
// pbStatus      - 0x00: ������� ������� flash ��������; 
//                 0xFF: ������� ������� flash ��������.
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ��������� �� flash ���� ������ �� ���������� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ReadFlashValue(	IN LPVOID pReader,
									IN DWORD  dwAddress,
									OUT LPBYTE  pbValue );
//
// ��������� �� flash ���� ������ (16 ����) �� ���������� ������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwAddress	 - ����� ����� ������ �� flash
// pbValue       - ��������� �� ���� ������ (16 ����)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������������ ����� T=CL: ��������� ��������� ��������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ISO14443A_4_RATS(	IN LPVOID pReader,
										IN BYTE  ucCID,
										OUT LPBYTE  pbATS );
//
// �������� ����� ������� RATS, �������� �� ��� ������ ��������� ��������� 
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucCID		 - ������������� ����� (����� �������� �� 0 �� 14)
// pbATS         - �������� ATS �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  ������������ ����� T=CL: ��������� �������� ������ � ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ISO14443A_4_PPS( IN LPVOID pReader,
								   IN BYTE  ucCID,
								   IN BYTE  ucBaudrate );
//
// �������� ����� ������� PPS, ������������� �������� ������ � ����� T=CL
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucCID		 - ������������� ����� (����� �������� �� 0 �� 14)
// ucBaudrate    - ��������������� �������� ������ � ������
//  ���� 3-2   - ��������������� �������� ������ � ������� ISO 14443
//               (����� ������ �� ����� � �����������):
//               00 - 106 ����
//               01 - 212 ����
//               10 - 424 ����
//               11 - 848 ����
//  ���� 1-0   - ��������������� �������� �������� � ������� ISO 14443
//               (����� ������ �� ����������� � �����):
//               00 - 106 ����
//               01 - 212 ����
//               10 - 424 ����
//               11 - 848 ����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ������ ���������� ��������������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_WritePerso(	IN LPVOID pReader,
											IN BYTE  ucValueType,
											IN BYTE  ucSectorNumber,
											IN BYTE  ucBlockNumber,
											IN DWORD dwValueFlashAddress );
//
// ���������� ������ �������������� � �����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucValueType   - ��� ������������� �������� (��. �������)
// ucSectorNumber- ����� ������� (������������ ��� ������ ����� ������ ��� �����, 
//                 ������������ � ������������� �������)
// ucBlockNumber - ����� ����� (������������ ��� ������ ����� ������ ��� �����, 
//                 ������������ � ������������� ����� � �������)
// dwValueFlashAddress - ����� ����� �� flash �����������, ������ ������� 
//				   ����� ������ ��� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ������ ���������� �������������� � ���� �������� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_WritePersoExplicit(	IN LPVOID pReader,
													IN BYTE  ucValueType,
													IN BYTE  ucSectorNumber,
													IN BYTE  ucBlockNumber,
													IN LPBYTE pData );
//
// ���������� ���������� ���� ������ �������������� � �����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucValueType   - ��� ������������� �������� (��. �������)
// ucSectorNumber- ����� ������� (������������ ��� ������ ����� ������ ��� �����, 
//                 ������������ � ������������� �������)
// ucBlockNumber - ����� ����� (������������ ��� ������ ����� ������ ��� �����, 
//                 ������������ � ������������� ����� � �������)
// pData		 - ������ ����� ��� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ���������� ��������������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_CommitPerso(	IN LPVOID pReader );
//
// ��������� �������������� �����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ��������������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_Authenticate(	IN LPVOID pReader,
											IN BYTE  ucAuthType,
											IN BYTE  ucKeyType,
											IN BYTE  ucSectorNumber,
											IN DWORD dwKeyFlashAddress,
											IN BYTE  ucLenCap,
											IN LPBYTE pbPcdCap );
//
// ��������� ��������� �������������� �����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucAuthType     - ��� �������������� (��. �������)
// ucKeyType     - ��� ����� ��� �������������� (��. �������)
// ucSectorNumber- ����� ������� ��� ��������������
// dwKeyFlashAddress - ����� ����� �� flash ����������� ��� ��������������
// ucLenCap      - ����� ����� ������������� ����������� (0..6, ���������� � 0)
// pbPcdCap      - ���� ������������� ����������� (���� �����������)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ������ ���������� ������ SL2
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_MultiBlockRead(	IN LPVOID pReader,
												IN BYTE ucSectorNumber,
												IN BYTE ucBlockNumber,
												IN BYTE ucBlocksCount,
												OUT LPBYTE pbData );
//
// ��� ����� � ������ SL2, ���������� ������������� ������ ������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucSectorNumber - ����� �������
// ucBlockNumber - ����� �����, � �������� ����� �������� ������
// ucBlocksCount - ���������� �������� ������
// pbData		 - ��������� �� �������� ������, � ������� ����� �������� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ������ ���������� ������ SL2
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_MultiBlockWrite(	IN LPVOID pReader,
												IN BYTE ucSectorNumber,
												IN BYTE ucBlockNumber,
												IN BYTE ucBlocksCount,
												IN LPBYTE pbData );
//
// ��� ����� � ������ SL2, ���������� ������������� ������ ������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucSectorNumber - ����� �������
// ucBlockNumber - ����� ���������� ����� ��� ������
// ucBlocksCount - ���������� ������������ ������
// pbData		 - ��������� �� �������� ������ � ������� ��� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ������ ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_ReadData(	IN LPVOID pReader,
										IN BYTE ucEncryptionMode,
										IN BYTE ucValueType,
										IN BYTE ucSectorNumber,
										IN BYTE ucBlockNumber,
										IN BYTE ucBlocksCount,
										OUT LPBYTE pbData );
//
// ��� ����� � ������ SL3, ���������� ������ ������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucEncryptionMode - ����� ������ ������ (��. �������)
// ucValueType   - ��� ��������� �������� (��. ������� 117 � ����������� MifarePlus)
// ucSectorNumber - ����� ������� � �������� ������
// ucBlockNumber - ����� ���������� ����� ��� ������
// ucBlocksCount - ���������� �������� ������
// pbData		 - ��������� �� �������� ������, � ������� ����� �������� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ������ ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_WriteData(	IN LPVOID pReader,
											IN BYTE ucEncryptionMode,
											IN BYTE ucValueType,
											IN BYTE ucSectorNumber,
											IN BYTE ucBlockNumber,
											IN BYTE ucBlocksCount,
											IN LPBYTE pbData );
//
// ��� ����� � ������ SL3, ���������� ������ ������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucEncryptionMode - ����� ������ ������ (��. �������)
// ucValueType   - ��� ������������� �������� (��. ������� 117 � ����������� MifarePlus)
// ucSectorNumber - ����� ������� ��� ������
// ucBlockNumber - ����� ���������� ����� ��� ������
// ucBlocksCount - ���������� ������������ ������
// pbData		 - ��������� �� �������� ������ � ������� ��� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ���������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_Increment(	IN LPVOID pReader,
											IN BYTE ucEncryptionMode,
											IN BYTE ucSourceSectorNumber,
											IN BYTE ucSourceBlockNumber,
											IN DWORD dwValue );
//
// ��� ����� � ������ SL3, ���������� ���������� �������� ��������
// � ����������� ������ ������������ �������� � ����� �������� (Transfer Buffer) 
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucEncryptionMode - ����� ������ ������ (��. �������)
// ucSourceSectorNumber - ����� ��������� �������
// ucSourceBlockNumber - ����� ��������� �����
// dwValue		 - ������������ � �������� ��������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ���������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_Decrement(	IN LPVOID pReader,
											IN BYTE ucEncryptionMode,
											IN BYTE ucSourceSectorNumber,
											IN BYTE ucSourceBlockNumber,
											IN DWORD dwValue );
//
// ��� ����� � ������ SL3, ���������� ���������� �������� ��������
// � ����������� ������ ������������ �������� � ����� �������� (Transfer Buffer) 
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucEncryptionMode - ����� ������ ������ (��. �������)
// ucSourceSectorNumber - ����� ��������� �������
// ucSourceBlockNumber - ����� ��������� �����
// dwValue		 - ���������� �� �������� ��������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ������ ������ ������ ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_Transfer(	IN LPVOID pReader,
										IN BYTE ucEncryptionMode,
										IN BYTE ucDestinationSectorNumber,
										IN BYTE ucDestinationBlockNumber);
//
// ��� ����� � ������ SL3, ���������� ������ ������ �������� (Transfer Buffer) 
// � ��������� ����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucEncryptionMode - ����� ������ ������ (��. �������)
// ucDestinationSectorNumber - ����� ������� ��� ������
// ucDestinationBlockNumber - ����� ����� ��� ������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ���������� �������� � ������ ������ ������ ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_IncrementTransfer(	IN LPVOID pReader,
													IN BYTE ucEncryptionMode,
													IN BYTE ucSourceSectorNumber,
													IN BYTE ucSourceBlockNumber,
													IN BYTE ucDestinationSectorNumber,
													IN BYTE ucDestinationBlockNumber,
													IN DWORD dwValue );
//
// ��� ����� � ������ SL3, ���������� ���������� �������� ��������,
// ������ ������������ �������� � ����� �������� (Transfer Buffer) � �����
// � ��������� ����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucEncryptionMode - ����� ������ ������ (��. �������)
// ucSourceSectorNumber - ����� ��������� �������
// ucSourceBlockNumber - ����� ��������� �����
// ucDestinationSectorNumber - ����� ������� ��� ������
// ucDestinationBlockNumber - ����� ����� ��� ������
// dwValue		 - ������������ � �������� ��������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ���������� �������� � ������ ������ ������ ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_DecrementTransfer(	IN LPVOID pReader,
													IN BYTE ucEncryptionMode,
													IN BYTE ucSourceSectorNumber,
													IN BYTE ucSourceBlockNumber,
													IN BYTE ucDestinationSectorNumber,
													IN BYTE ucDestinationBlockNumber,
													IN DWORD dwValue );
//
// ��� ����� � ������ SL3, ���������� ���������� �������� ��������,
// ������ ������������ �������� � ����� �������� (Transfer Buffer) � �����
// � ��������� ����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucEncryptionMode - ����� ������ ������ (��. �������)
// ucSourceSectorNumber - ����� ��������� �������
// ucSourceBlockNumber - ����� ��������� �����
// ucDestinationSectorNumber - ����� ������� ��� ������
// ucDestinationBlockNumber - ����� ����� ��� ������
// dwValue		 - ���������� �� �������� ��������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ������ ������ �����-�������� � ����� �������� (Transfer Buffer)
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_Restore(	IN LPVOID pReader,
										IN BYTE ucEncryptionMode,
										IN BYTE ucSourceSectorNumber,
										IN BYTE ucSourceBlockNumber );
//
// ��� ����� � ������ SL3, ���������� ������ �������� ���������� �����-��������
// � ����� �������� (Transfer Buffer) 
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// ucEncryptionMode - ����� ������ ������ (��. �������)
// ucSourceSectorNumber - ����� ��������� �������
// ucSourceBlockNumber - ����� ��������� �����
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ������ ��������� ����������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_VirtualCardSupport(	IN LPVOID pReader,
													IN LPBYTE  pIID );
//
// �������� ����� ��������� ������������� ��������������
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pIID - ������������� �������������� (16 ����)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: �������������� ������ ��������� ����������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_VirtualCardSupportLast(	IN LPVOID pReader,
														IN LPBYTE  pIID,
														IN DWORD dwKencFlashAddress,
														IN DWORD dwKmacFlashAddress,
														IN BYTE  ucLenCap,
														IN LPBYTE pbPcdCap,
														OUT PBYTE pucInfo,
														OUT PBYTE pPiccCap,
														OUT PBYTE pPaddedUID);
//
// �������� ����� ��������� ������������� ��������������, � ����� ����������� 
// �������������� � ��������� �������������� �����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// pIID - ������������� �������������� (16 ����)
// dwKencFlashAddress - ����� ����� VC Polling ENC Key �� flash �����������
// dwKmacFlashAddress - ����� ����� VC Polling MAC Key �� flash �����������
// ucLenCap      - ����� ����� ������������� ����������� (0..3, ���������� � 0)
// pbPcdCap      - ���� ������������� ����������� (���� �����������)
// pucInfo		 - ��������� �� �������� ����������, � ������� ����� ��������
//				   ���������� � ����� (0x83 - 4-�������� UID, 0x80 - 7-�������� UID)
// pPiccCap		 - ��������� �� ����� (2 �����), � ������� ����� ��������
//				   �������������� �����
// pPaddedUID	 - ��������� �� ����� (13 ����), � ������� ����� ������� UID �����
//					� ����� ����� ���������� (����� �������� 13 ����)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: �������� ����������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_VirtualCardSelect(	IN LPVOID pReader,
													IN DWORD dwKselFlashAddress,
													IN PBYTE pPiccCap,
													IN PBYTE pPaddedUID);
//
// �������� ����������� ����� 
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwKselFlashAddress - ����� ����� Select VC Key �� flash �����������
// pPiccCap		 - ��������� �� ����� (2 �����), �� �������� ����� ��������
//				   �������������� �����
// pPaddedUID	 - ��������� �� ����� (13 ����), �� �������� ����� ���� UID �����
//					� ����� ����� �������� (����� �������� 13 ����)
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: �������� ����� ����������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_VirtualCardDeselect(	IN LPVOID pReader );
//
// �������� ����� ����������� �����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: ���������� �������� �������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_ProximityCheck(	IN LPVOID pReader,
												IN DWORD dwKproxFlashAddress );
//
// ���������, ���������� �� ������ �� ����������� ����������� ����� - ������ �� �������� ����
//
// pReader       - ������ �� ������-��������� (��. ������� CLSCRF_Create )
// dwKproxFlashAddress - ����� ����� Proximity Check Key �� flash �����������
//
// ������������ ��������:  0   - �������� ����������
//                       ����� - ������ ��� ����������
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX







//------------------------------------------------------------------------------
//  Mifare Des Fire: ���������� �������������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_Authenticate(	IN LPVOID pReader,
												IN BYTE ucAuthType,
												IN PBYTE pKey,
												IN BYTE ucKeyNumber );
//
//���������� �������������� (����� ��� ����������) ���������� ���� � � ��������� ������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucAuthType � ��� �������������� (0x00 � DES, 0x01 � 3DES, 0x02 � 3K3DES, 0x03 - AES);
//pKey � ��������� �� ������ ����, ���������� ���� (8 � 24 �����);
//ucKeyNumber � ����� ����� �� �����, ������� ����� ����������� ��� ��������������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������������� ������ ������ ����������� - �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_SetTransferType(	IN LPVOID pReader,
													IN BYTE ucTransferType );
//
//������������� ������ ������ ����������� - �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucTransferType � ��� �������� ������ (0x00 � ��������, 0x01 � MAC, 0x03 - �����������).
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������ ��������� ������-����� ��� �������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_ChangeKeySettings(	IN LPVOID pReader,
													IN CLSCRF_DESFIRE_MASTER_KEY_SETTINGS* pMasterKeySettings );
//
//������ ��������� ������-����� ��� �������� ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pMasterKeySettings � ��������� �� ��������� CLSCRF_DESFIRE_MASTER_KEY_SETTINGS � ����������� �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� ��������� ������-����� ��� �������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetKeySettings(	IN LPVOID pReader,
													OUT CLSCRF_DESFIRE_MASTER_KEY_SETTINGS_AND_LENGTH* pKeyData );
//
//��������� ��������� ������-����� ��� �������� ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pKeyData � ��������� �� ��������� CLSCRF_DESFIRE_MASTER_KEY_SETTINGS_AND_LENGTH, � ������� ����� �������� ��������� ��������� ������-�����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������ ���� � ������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_ChangeKey(	IN LPVOID pReader,
											IN CLSCRF_DESFIRE_KEY_DATA* pKeyData );
//
//������ ���� � ������� ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pKeyData � ��������� �� ��������� CLSCRF_DESFIRE_KEY_DATA, � ������� �������� ��������� ������ �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� ������ �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetKeyVersion(	IN LPVOID pReader,
												IN BYTE ucKeyNumber,
												OUT PBYTE pucKeyVersion );
//
//��������� ������ �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucKeyNumber � ����� ����� �����;
//pucKeyVersion � ��������� �� ����������, � ������� ����� �������� ������ �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������ ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_CreateApplication(	IN LPVOID pReader,
													IN PBYTE pAID,
													IN CLSCRF_DESFIRE_APPLICATION_MASTER_KEY_SETTINGS* pKeySett1,
													IN CLSCRF_DESFIRE_NEW_APPLICATION_KEY_SETTINGS* pKeySett2,
													IN PBYTE pIsoFileID,
													IN PBYTE pIso7816DfName,
													IN int iIso7816DfNameLength );
//
//������ ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pAID � ��������� �� ������ (3 �����), ���������� ����� ������������ ����������;
//pKeySett1� ��������� �� ��������� CLSCRF_DESFIRE_APPLICATION_MASTER_KEY_SETTINGS, ���������� ��������� ������-����� ����������;
//pKeySett2� ��������� �� ��������� CLSCRF_DESFIRE_NEW_APPLICATION_KEY_SETTINGS, ���������� ��������� ������ ����������;
//pIsoFileID � ��������� �� ������ (2 �����), ISO-������������� ����� (NULL, ���� �� ������������);
//pIso7816DfName � ��������� �� ������ (�������� iIso7816DfNameLength), ���������� ISO7816 Df-��� ������������ ���������� (NULL, ���� �� ������������);
//iIso7816DfNameLength � ������ ISO7816 Df-����� ������������ ���������� � ������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_DeleteApplication(	IN LPVOID pReader,
													IN PBYTE pAID );
//
//������� ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pAID � ��������� �� ������ (3 �����), ���������� ����� ���������� ����������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� �������������� ���������� �� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetApplicationIDs(	IN LPVOID pReader,
													OUT PBYTE pAIDs,
													OUT PBYTE pucApplicationsCount);
//
//��������� �������������� ���������� �� �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pAIDs � ��������� �� ������, � ������� ����� ��������������� �������� 3-�������� �������������� ����������;
//pucApplicationsCount � ��������� �� ����������, � ������� ����� �������� ���������� ��������� �� ����� ����������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� Df-����� ���������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetDFNames(	IN LPVOID pReader,
												OUT CLSCRF_DESFIRE_DFNAME* pDFNames,
												OUT PBYTE pDFNamesCount );
//
//��������� Df-����� ���������� �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pDFNames � ��������� �� ������, � ������� ����� ��������������� �������� �������� CLSCRF_DESFIRE_DFNAME, ���������� Df-����� ����������;
//pucDFNamesCount � ��������� �� ����������, � ������� ����� �������� ���������� ��������� �� ����� ���������� � Df-�������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ����������� ������� ���������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_SelectApplication(	IN LPVOID pReader,
													IN PBYTE pAID );
//
//����������� ������� ���������� �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pAID � ��������� �� ������ (3 �����), ���������� ����� ����������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: �������������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_FormatPICC(	IN LPVOID pReader );
//
//�������������� ����� (��������� ��������������� �������������� ������-������ �����).
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� ���������� � �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetVersion(	IN LPVOID pReader,
												OUT CLSCRF_DESFIRE_HW_SW_INFO* pHWInfo,
												OUT CLSCRF_DESFIRE_HW_SW_INFO* pSWInfo,
												OUT CLSCRF_DESFIRE_MORE_INFO* pMoreInfo );
//
//��������� ���������� � �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pHWInfo � ��������� �� ��������� CLSCRF_DESFIRE_HW_SW_INFO, � ������� ����� �������� ���������� �� Hardware �����;
//pSWInfo � ��������� �� ��������� CLSCRF_DESFIRE_HW_SW_INFO, � ������� ����� �������� ���������� �� Software �����;
//pMoreInfo � ��������� �� ��������� CLSCRF_DESFIRE_MORE_INFO, � ������� ����� �������� �������������� ���������� �� ������ �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ����������� ������ �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_FreeMemory(	IN LPVOID pReader,
												OUT PDWORD pdwMemSize );
//
//����������� ������ �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pdwMemSize � ��������� �� ����������, � ������� ����� ������� ������ ������ �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������������� ������������ �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_SetConfiguration(	IN LPVOID pReader,
                                                    IN CLSCRF_DESFIRE_CONFIGURATION* pCfg );
//
//������������� ������������ �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pCfg � ��������� �� ��������� CLSCRF_DESFIRE_CONFIGURATION, ���������� ��������������� ��������� ������������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� UID �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetCardUID(	IN LPVOID pReader,
												OUT PBYTE pUID );
//
//��������� UID �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pUID � ��������� �� ������ ����, � ������� ����� ������� UID �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� ������ ������ � ������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetFileIDs(	IN LPVOID pReader,
												OUT PBYTE pFileIDs,
												OUT PBYTE pucFilesCount );
//
//��������� ������ ������ � ������� ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pFileIDs � ��������� �� ������ ����, � ������ ����� ��������������� �������� ������ ������ (1 ���� �� ������) � ������� ����������;
//pucFilesCount � ��������� �� ����������, � ������� ����� �������� ���������� ������ � ������� ����������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� ISO-������ ������ � ������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetISOFileIDs(	IN LPVOID pReader,
												OUT PWORD pISOFileIDs,
												OUT PBYTE pucFilesCount );
//
//��������� ISO-������ ������ � ������� ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//pISOFileIDs � ��������� �� ������ ����, � ������ ����� ��������������� �������� ISO-������ ������ (2 ����� �� ������) � ������� ����������;
//pucFilesCount � ��������� �� ����������, � ������� ����� �������� ���������� ������, ������� ISO-�������������, � ������� ����������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� ������� ���������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetFileSettings(	IN LPVOID pReader,
													IN BYTE ucFileNumber,
													OUT CLSCRF_DESFIRE_FILE_SETTINGS* pFileSettings );
//
//��������� ������� ���������� �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//pFileSettings � ��������� �� ��������� CLSCRF_DESFIRE_FILE_SETTINGS, � ������� ����� �������� ��������� �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: �������� ��������� ���������� �����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_ChangeFileSettings(	IN LPVOID pReader,
														IN BYTE ucFileNumber,
														IN BYTE ucCommSettings,
														IN CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS* pAccessRights );
//
//�������� ��������� ���������� �����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//ucCommSettings � ��������� ������ ������ (0x00 � ��������, 0x01 � MAC, 0x03 - �����������);
//pAccessRights � ��������� �� ��������� CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, ���������� ��������� �������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������ ����������� ���� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_CreateStdDataFile(	IN LPVOID pReader,
													IN BYTE ucFileNumber,
													IN PBYTE pISOFileID,
													IN BYTE ucCommSettings,
													IN CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS* pAccessRights,
													IN DWORD dwFileSize );
//
//������ ����������� ���� ������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//pISOFileID � ��������� �� ������, ���������� ISO-����� ����� (2 �����, ���� NULL, �� ������������);
//ucCommSettings � ��������� ������ ������ (0x00 � ��������, 0x01 � MAC, 0x03 - �����������);
//pAccessRights � ��������� �� ��������� CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, ���������� ��������� �������;
//dwFileSize � ������ �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������ ���� ������ � ��������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_CreateBackupDataFile(	IN LPVOID pReader,
														IN BYTE ucFileNumber,
														IN PBYTE pISOFileID,
														IN BYTE ucCommSettings,
														IN CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS* pAccessRights,
														IN DWORD dwFileSize );
//
//������ ���� ������ � ��������� ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//pISOFileID � ��������� �� ������, ���������� ISO-����� ����� (2 �����, ���� NULL, �� ������������);
//ucCommSettings � ��������� ������ ������ (0x00 � ��������, 0x01 � MAC, 0x03 - �����������);
//pAccessRights � ��������� �� ��������� CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, ���������� ��������� �������;
//dwFileSize � ������ �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������ ���� �������� � ��������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_CreateValueFile(	IN LPVOID pReader,
													IN BYTE ucFileNumber,
													IN BYTE ucCommSettings,
													IN CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS* pAccessRights,
													IN DWORD dwLowerLimit,
													IN DWORD dwUpperLimit,
													IN DWORD dwValue,
													IN CLSCRF_DESFIRE_LIMITED_CREDIT_ENABLED* pLimitedCreditEnabled );
//
//������ ���� �������� � ��������� ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//ucCommSettings � ��������� ������ ������ (0x00 � ��������, 0x01 � MAC, 0x03 - �����������);
//pAccessRights � ��������� �� ��������� CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, ���������� ��������� �������;
//dwLowerLimit � ������ ������ ��������;
//dwUpperLimit � ������� ������ ��������;
//dwValue � ��������� ��������;
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������ �������� ���� ������� � ��������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_CreateLinearRecordFile(	IN LPVOID pReader,
															IN BYTE ucFileNumber,
															IN PBYTE pISOFileID,
															IN BYTE ucCommSettings,
															IN CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS* pAccessRights,
															IN DWORD dwRecordSize,
															IN DWORD dwMaxNumOfRecords );
//
//������ �������� ���� ������� � ��������� ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//pISOFileID � ��������� �� ������, ���������� ISO-����� ����� (2 �����, ���� NULL, �� ������������);
//ucCommSettings � ��������� ������ ������ (0x00 � ��������, 0x01 � MAC, 0x03 - �����������);
//pAccessRights � ��������� �� ��������� CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, ���������� ��������� �������;
//dwRecordSize � ������ ������;
//dwMaxNumOfRecords � ������������ ���������� �������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������ ����������� ���� ������� � ��������� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_CreateCyclicRecordFile(	IN LPVOID pReader,
															IN BYTE ucFileNumber,
															IN PBYTE pISOFileID,
															IN BYTE ucCommSettings,
															IN CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS* pAccessRights,
															IN DWORD dwRecordSize,
															IN DWORD dwMaxNumOfRecords );
//
//������ ����������� ���� ������� � ��������� ����������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//pISOFileID � ��������� �� ������, ���������� ISO-����� ����� (2 �����, ���� NULL, �� ������������);
//ucCommSettings � ��������� ������ ������ (0x00 � ��������, 0x01 � MAC, 0x03 - �����������);
//pAccessRights � ��������� �� ��������� CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, ���������� ��������� �������;
//dwRecordSize � ������ ������;
//dwMaxNumOfRecords � ������������ ���������� �������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������� ����
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_DeleteFile(	IN LPVOID pReader,
												IN BYTE ucFileNumber );
//
//������� ����.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� ������ �� ����� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_ReadData(	IN LPVOID pReader,
											IN BYTE ucFileNumber,
											IN DWORD dwOffset,
											IN DWORD dwLength,
											OUT PBYTE pData,
											OUT PDWORD pdwDataLength);
//
//��������� ������ �� ����� ������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//dwOffset � ����� ���������� �����;
//dwLength � ���������� ����������� ����;
//pData � ��������� �� ������ ����, � ������� ����� ������� ������;
//pdwDataLength � ��������� �� ����������, � ������� ����� �������� ���������� ��������� ����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ���������� ������ � ���� ������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_WriteData(	IN LPVOID pReader,
											IN BYTE ucFileNumber,
											IN DWORD dwOffset,
											IN DWORD dwLength,
											IN PBYTE pData );
//
//���������� ������ � ���� ������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//dwOffset � ����� ���������� �����;
//dwLength � ���������� ������������ ����;
//pData � ��������� �� ������ ����, ���������� ������������ ������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� �������� �� �����-��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetValue(	IN LPVOID pReader,
											IN BYTE ucFileNumber,
											OUT PDWORD pdwValue);
//
//��������� �������� �� �����-��������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//pdwValue � ��������� �� ����������, � ������� ����� �������� ��������� ��������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ����������� �������� � �����-�������� �� �������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_Credit(	IN LPVOID pReader,
											IN BYTE ucFileNumber,
											IN DWORD dwValue );
//
//����������� �������� � �����-�������� �� �������� ��������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//dwValue � ��������, �� ������� ����� ��������� �������� (�������� �� ����������).
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� �������� � �����-�������� �� �������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_Debit(	IN LPVOID pReader,
										IN BYTE ucFileNumber,
										IN DWORD dwValue );
//
//��������� �������� � �����-�������� �� �������� ��������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//dwValue � ��������, �� ������� ����� ��������� �������� (�������� �� ����������).
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ����������� ����������� �������� � �����-�������� �� �������� ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_LimitedCredit(	IN LPVOID pReader,
												IN BYTE ucFileNumber,
												IN DWORD dwValue );
//
//����������� ����������� �������� � �����-�������� �� �������� ��������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//dwValue � ��������, �� ������� ����� ��������� �������� (�������� �� ����������).
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ���������� ������ � ���� �������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_WriteRecord(	IN LPVOID pReader,
												IN BYTE ucFileNumber,
												IN DWORD dwOffset,
												IN DWORD dwLength,
												IN PBYTE pData );
//
//���������� ������ � ���� �������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//dwOffset � ����� ���������� �����;
//dwLength � ���������� ������������ ����;
//pData � ��������� �� ������ ����, ���������� ������������ ������.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ��������� ������ �� ����� �������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_ReadRecords(	IN LPVOID pReader,
												IN BYTE ucFileNumber,
												IN DWORD dwRecordOffset,
												IN DWORD dwRecordsCount,
												IN DWORD dwRecordSize,
												OUT PBYTE pData,
												OUT PDWORD pdwDataLength);
//
//��������� ������ �� ����� �������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����;
//dwRecordOffset � ����� ��������� ������;
//dwRecordsCount � ���������� ����������� �������;
//dwRecordSize � ������ ����������� ������;
//pData � ��������� �� ������ ����, � ������� ����� ������� ������;
//pdwDataLength � ��������� �� ����������, � ������� ����� �������� ���������� ��������� ����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: ������� ���� �������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_ClearRecordFile(	IN LPVOID pReader,
													IN BYTE ucFileNumber );
//
//������� ���� �������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create);
//ucFileNumber � ����� �����.
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: �������� ������ �� ���������� ������ ����� � ��������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_CommitTransaction(	IN LPVOID pReader );
//
//�������� ������ �� ���������� ������ ����� � ��������.
//
//pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
//
//������������ ��������:  0   � �������� ����������,
//  ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: �������� ������ �� ��������� ������ ����� � ���������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_AbortTransaction(	IN LPVOID pReader );
//
// �������� ������ �� ��������� ������ ����� � ���������.
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX




//------------------------------------------------------------------------------
//  NFC663: ��������� ����������
//------------------------------------------------------------------------------
//
/**
* �������� DRI/DSI (BRI/BSI)
*/
/*@{*/
#define PHPAL_I18092MPI_DATARATE_106   0x00U   /**< �������� DRI/DSI ��� 106 kBit/s. */
#define PHPAL_I18092MPI_DATARATE_212   0x01U   /**< �������� DRI/DSI ��� 212 kBit/s. */
#define PHPAL_I18092MPI_DATARATE_424   0x02U   /**< �������� DRI/DSI ��� 424 kBit/s. */
/*@}*/

/**
* �������� FSL/LRI
*/
/*@{*/
#define PHPAL_I18092MPI_FRAMESIZE_64   0x00U   /**< �������� FSL ��� ����. ������� ����� � 64 �����.  */
#define PHPAL_I18092MPI_FRAMESIZE_128  0x01U   /**< �������� FSL ��� ����. ������� ����� � 128 ����. */
#define PHPAL_I18092MPI_FRAMESIZE_192  0x02U   /**< �������� FSL ��� ����. ������� ����� � 192 �����. */
#define PHPAL_I18092MPI_FRAMESIZE_254  0x03U   /**< �������� FSL ��� ����. ������� ����� � 254 �����. */
/*@}*/
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_ActivateCard( IN  LPVOID  pReader,
										IN	LPBYTE	Nfcid3i,/**< [In] NFCID3 - any number in case of 106kbps initial datarate.
                                                            For 212/424kbps datarate bytes 0 - 7 have to be NFCID2,
                                                            bytes 8 - 9 need to be set to 0; uint8_t[10] */
										IN	BYTE	Did,/**< [In] Device Identifier; '0' to disable usage else 1-14. */
										IN	BYTE	NadEnable,/**< [In] Enable usage of Node Address; Unequal '0' to enable. */
										IN	BYTE	Nad,/**< [In] Node Address; Ignored if bNadEnabled is equal '0'. */
										IN	BYTE	Dsi,/**< [In] Divisor Send (target to initiator) Integer; 0-7 */
										IN	BYTE	Dri,/**< [In] Divisor Receive (initiator to target) Integer; 0-7 */
										IN	BYTE	Fsl,/**< [In] Frame Length Byte; 0-3 */
										IN	BYTE	GiLength,/**< [In] Number of General Information bytes. */
										IN	LPBYTE	Gi,/**< [In] Optional General Information bytes. */
										OUT LPBYTE  pbATR, /**< [Out] Attribute Response; uint8_t[64]. */
									 IN OUT LPDWORD pdwATRLength );/**< [Out] Attribute Response Length. */
// ��������� ������� ISO18092 ATR � PSL.
// Nfcid3i	- ������ �� 10 ����: ��� ��������� �������� � 106kbps - NFCID3,
//			  ������������ ��������� �������;
//			  ��� ��������� 212/424kbps - ����� 0-7 ������������� NFCID2, 
//			  � ����� 8-9 ������ ���� ����������� � 0.
// Did		- ������������� ����������, "0" - �� ������������, ���� 1-14
// NadEnable- ��������� ������������� ������ ����, ��� ��������� ���������� �� � "0"
// Nad		- ����� ����: ������������, ���� bNadEnabled = 0
// Dsi		- ������ �������� �������� (�� ���� � ����������) 0-2
// Dri		- ������ �������� ������ (�� ���������� � ����) 0-2
// Fsl		- ���� ����� ����� 0-3
// GiLength	- ���������� ���� ����� ����������.
// Gi		- �����������, ����� ����� ����������
// pbATR	- �����, ���� ����� �������� ����� ATR (������ � ���������), 
//			  ������ ���� �� ������ 64 ����
// pdwATRLength - ����� ��������� ��������� � ������
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: ������ ������
//------------------------------------------------------------------------------
//
/**
* �������� ��������� bDeselectCommand
*/
/*@{*/
#define PHPAL_I18092MPI_DESELECT_DSL   0x08U   /**< DSL ������������ ��� ������ ������ ����. */
#define PHPAL_I18092MPI_DESELECT_RLS   0x0AU   /**< RLS ������������ ��� ������ ������ ����. */
/*@}*/
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_Deselect(	IN  LPVOID  pReader,
									IN	BYTE	DeselectCommand );/**< [In] Request to send, either #PHPAL_I18092MPI_DESELECT_DSL or #PHPAL_I18092MPI_DESELECT_RLS. */
// ������ ������ ���� ISO18092 ����� �������� �������� DSL ���� RLS.
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
// DeselectCommand - ������ �� ��������, PHPAL_I18092MPI_DESELECT_DSL, 
//					 ���� PHPAL_I18092MPI_DESELECT_RLS
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: �����
//------------------------------------------------------------------------------
//
/** ����� ������� Exchange
*/
/*@{*/
/**
����� ������ �� ���������.
��� ���������� ����������� ������������ 
� PH_EXCHANGE_BUFFERED_BIT � PH_EXCHANGE_LEAVE_BUFFER_BIT
���������� ��� ISO14443-4:
��������� �������� �������� Tx/Rx � ������.
���������� PH_ERR_SUCCESS_CHAINING, ���� RxBuffer ����� � �� ���������� 
������������� (ACK) ��� ���������� ��������� �����.
*/
#define PH_EXCHANGE_DEFAULT             0x0000U

/**
���������� ��� ISO14443-4:
�������� ������ � ����� �������� ���������.
������������ � PH_EXCHANGE_BUFFERED_BIT � PH_EXCHANGE_LEAVE_BUFFER_BIT 
��� ���������� �����������.
�� ��������� ������� ������.
*/
#define PH_EXCHANGE_TXCHAINING          0x0001U

/**
���������� ��� ISO14443-4:
�������� �������� � ������ R(ACK) � ��������� �������� �������� Rx � ������.
���������� PH_ERR_SUCCESS_CHAINING, ���� RxBuffer ����� � �� ������������ (ACK)
��������� �������� ����.
*/
#define PH_EXCHANGE_RXCHAINING          0x0002U

/**
���������� ��� ISO14443-4:
�������� �������� � ������ R(ACK) � ��������� �������� �������� Rx � ������.
��������� �������� �������� Rx � ������, ���� RxBuffer �����.
*/
#define PH_EXCHANGE_RXCHAINING_BUFSIZE  0x0003U

/** ����� ��� ������� ����. ��� ��������� ���� ���������������. */
#define PH_EXCHANGE_MODE_MASK           0x000FU

/**
�� ���������� ������� ����������� ������ ����� ����������� ��������.
���� ���� ��� ���������� � ������ ��������,
�� ���������� ����������� ������ ������������ � ������ �������.
*/
#define PH_EXCHANGE_LEAVE_BUFFER_BIT    0x4000U

/**
���������� Tx-Data �� ���������� ����� ������ ��� ��������.
*/
#define PH_EXCHANGE_BUFFERED_BIT        0x8000U

/**
��������� ������ �������� ������ ������ ������.
(����������� ��������� ��� �����������).
*/
#define PH_EXCHANGE_BUFFER_FIRST   (PH_EXCHANGE_DEFAULT | PH_EXCHANGE_BUFFERED_BIT)

/**
��������� ������ �������� ��������� ������ ������.
(����������� ��������� ��� �����������).
*/
#define PH_EXCHANGE_BUFFER_CONT    (PH_EXCHANGE_DEFAULT | PH_EXCHANGE_BUFFERED_BIT | PH_EXCHANGE_LEAVE_BUFFER_BIT)

/**
��������� ������ �������� ��������� ������ ������.
(����������� ��������� ��� �����������).
*/
#define PH_EXCHANGE_BUFFER_LAST    (PH_EXCHANGE_DEFAULT | PH_EXCHANGE_LEAVE_BUFFER_BIT)
/*@}*/
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_Exchange( IN  LPVOID  pReader,
									IN	DWORD	dwOption,/**< [In] Option parameter. */
									IN	LPCBYTE pbSendBuffer, /**< [In] Data to transmit. */
									IN	DWORD   dwSendLength, /**< [In] Length of data to transmit. */
									OUT LPBYTE  pbRecvBuffer, /**< [Out] Pointer to received data. */
								 IN OUT LPDWORD pdwRecvLength );/**< [Out] number of received data bytes. */
// ��������� ����� ������� ISO18092 � �����.
//
// pReader  � ������ �� ������-��������� (��. ������� CLSCRF_Create).
// dwOption	- �������� �����
// pbSendBuffer - ����� � ������� ��� ��������
// dwSendLength - ���������� ���� ��� ��������
// pbRecvBuffer - ����� ��� ���������� �������� ����
// pdwRecvLength - ���������� �������� ����
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: ����� ���������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_ResetProtocol(	IN  LPVOID  pReader );
// ���������� ��������� ��������� ISO18092.
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: ������ ���������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_AttributeRequest( IN  LPVOID  pReader,
											IN	LPBYTE	Nfcid3i,/**< [In] NFCID3 - randomly generated in case of 106kbps initial datarate or
                                                   NFCID2 in case of 212/424kbps datarate; uint8_t[10] */
											IN	BYTE	Did,/**< [In] Device Identifier; '0' to disable usage else 1-14. */
											IN	BYTE	NadEnable,/**< [In] Enable usage of Node Address; Unequal '0' to enable. */
											IN	BYTE	Nad,/**< [In] Node Address; Ignored if bNadEnabled is equal '0'. */
											IN	BYTE	Fsl,/**< [In] Frame Length Byte; 0-3  */
											IN	BYTE	GiLength,/**< [In] Number of General Information bytes; Not more than #PHPAL_I18092MPI_MAX_GI_LENGTH. */
											IN	LPBYTE	Gi,/**< [In] Optional General Information bytes. */
											OUT LPBYTE  pbATR, /**< [Out] Attribute Response; uint8_t[64]. */
										 IN OUT LPDWORD pdwATRLength );/**< [Out] Attribute Response Length. */
// ��������� ������� ISO18092 "Attribute Request".
//
// pReader  � ������ �� ������-��������� (��. ������� CLSCRF_Create).
// Nfcid3i	- ������ �� 10 ����, ������������ ��������� ������� ��� ��������� 
//			  �������� � 106kbps, ���� ������������� NFCID2 ��� ��������� 212/424kbps
// Did		- ������������� ����������, "0" - �� ������������, ���� 1-14
// NadEnable- ��������� ������������� ������ ����, ��� ��������� ���������� �� � "0"
// Nad		- ����� ����: ������������, ���� bNadEnabled = 0
// Fsl		- ���� ����� ����� 0-3
// GiLength	- ���������� ���� ����� ����������, �� ��������� PHPAL_I18092MPI_MAX_GI_LENGTH.
// Gi		- �����������, ����� ����� ����������
// pbATR	- �����, ���� ������ �������� ����� ATR (������ � ���������), 
//			  ������ ���� �� ������ 64 ����
// pdwATRLength - ����� ��������� ��������� � ������
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: ����� ����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_ParameterSelect(	IN  LPVOID  pReader,
											IN	BYTE	Dsi,/**< [In] Divisor Send (target to initiator) Integer; 0-2 */
											IN	BYTE	Dri,/**< [In] Divisor Receive (initiator to target) Integer; 0-2 */
											IN	BYTE	Fsl );/**< [In] Frame Length Byte; 0-3  */
// ��������� ������� ISO18092 "Parameter Select".
//
// pReader	� ������ �� ������-��������� (��. ������� CLSCRF_Create).
// Dsi		- ������ �������� �������� (�� ���� � ����������) 0-2
// Dri		- ������ �������� ������ (�� ���������� � ����) 0-2
// Fsl		- ���� ����� ����� 0-3
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: �������� �����������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_PresenceCheck(	IN  LPVOID  pReader );
// ��������� �������� ����������� ��� ������� ����.
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: ��������� ������������
//------------------------------------------------------------------------------
//
/**
* ��������� ������ ���������� ���������� ISO18092 ucParameterNumber
*/
/*@{*/
/**
* ������ / �������� ����� ������
*/
#define PHPAL_I18092MPI_CONFIG_PACKETNO          0x0000U
/**
* ������ / �������� ������������� ����������
*/
#define PHPAL_I18092MPI_CONFIG_DID               0x0001U
/**
* ������ / �������� ����� ����
*/
#define PHPAL_I18092MPI_CONFIG_NAD               0x0002U
/**
* ������ / �������� ����� ��������
*/
#define PHPAL_I18092MPI_CONFIG_WT                0x0003U
/**
* ������ / �������� ����� �����
*/
#define PHPAL_I18092MPI_CONFIG_FSL               0x0004U
/**
* ������ / �������� ������������ ���������� ��������� �������
*/
#define PHPAL_I18092MPI_CONFIG_MAXRETRYCOUNT     0x0005U
/*@}*/
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_SetConfig(	IN  LPVOID  pReader,
										IN	DWORD	dwParameterNumber,
										IN  DWORD   pdwParameterValue );
// ��������� ��������� ����������������� ���������
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
// dwParameterNumber - ������������� ���������
// pdwParameterValue - �������� ���������
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: ������ ������������
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_GetConfig(	IN  LPVOID  pReader,
										IN	DWORD	dwParameterNumber,
										OUT LPDWORD  pdwParameterValue );
// ��������� ������ ����������������� ���������
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
// dwParameterNumber - ������������� ���������
// pdwParameterValue - ��������� �� �������� ���������
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: ������ ��������� ������ (NFCID3)
//------------------------------------------------------------------------------
//
#define PHPAL_I18092MPI_NFCID3_LENGTH    0x0AU /**< ������ NFCID3. */
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_GetSerialNo(	IN  LPVOID  pReader,
										OUT LPBYTE  NFCID3 );
// ��������� ������ ����������������� ���������
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
// NFCID3 - �������� ����� NFCID3 - 10 ����
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: ������ ��������� ���������� ���� �� ���������� ������ EEPROM
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_E2_Read(	IN  LPVOID  pReader,
									IN  DWORD dwAddr,
									IN	BYTE ucLength,
									OUT LPBYTE  pData );
// ��������� ������ ��������� ���������� ���� �� ���������� ������ EEPROM
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
// dwAddr - ����� ����� 192(0x00C0)..6143(0x17FF)
// ucLength - ���������� ������������ ���� ������ 1..127
// pData - ������, ���� ����� ����������� ����������� ����� ������
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: ������ ������ ����� ������ � ��������� ����� EEPROM
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_E2_Write(	IN  LPVOID  pReader,
									IN  DWORD dwAddr,
									IN	BYTE ucData );
// ��������� ������ ������ ����� ������ � ��������� ����� EEPROM
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
// dwAddr - ����� ����� 192(0x00C0)..6143(0x17FF)
// ucData - ������������ ���� ������
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: ������ ���������� ���� ������ � ��������� �������� EEPROM
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_E2_WritePage(	IN  LPVOID  pReader,
										IN  DWORD dwAddr,
										IN	BYTE ucLength,
										IN  LPBYTE pData );
// ��������� ������ ���������� ���� ������ � ��������� �������� EEPROM
//
// pReader � ������ �� ������-��������� (��. ������� CLSCRF_Create).
// dwAddr - ����� �������� 3..95(0x5F)
// ucLength - ���������� ������������ ���� ������ 1..64
// pData - ��������� �� ������ ���� ������
//
// ������������ ��������:  0   � �������� ����������,
//   ����� � ������ ��� ����������.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX



CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_Create(
IN LPBYTE  lpMsgDataBytes,
IN DWORD  dwMsgDataLength,
OUT LPHANDLE phNDEFMessage);


CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_GetRecordsCount(
IN HANDLE hNDEFMessage,
OUT LPDWORD  pdwRecordsCount);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_GetDataSize(
IN HANDLE hNDEFMessage,
OUT LPDWORD  pdwDataSize);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_GetData(
IN HANDLE hNDEFMessage,
OUT LPBYTE  lpData);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_AddRecord(
IN HANDLE hNDEFMessage,
IN HANDLE hNDEFRecord);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_AddRecordEmpty(
IN HANDLE hNDEFMessage);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_AddRecordText(
IN HANDLE hNDEFMessage,
IN LPWSTR lpwstrText,
IN LPWSTR lpwstrEncoding);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_AddRecordUri(
IN HANDLE hNDEFMessage,
IN LPWSTR lpwstrUri);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_AddRecordMimeMedia(
IN HANDLE hNDEFMessage,
IN LPWSTR lpwstrMimeType,
IN LPBYTE lpPayload,
IN DWORD dwPayloadLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_AddRecordMimeMediaText(
IN HANDLE hNDEFMessage,
IN LPWSTR lpwstrMimeType,
IN LPWSTR lpwstrText);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_GetRecord(
IN HANDLE hNDEFMessage,
IN DWORD  dwRecordIndex,
OUT LPHANDLE phNDEFRecord);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Message_Destroy(
IN HANDLE hNDEFMessage);





CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_Create(
OUT LPHANDLE phNDEFRecord);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetDataSize(
IN HANDLE hNDEFRecord,
OUT LPDWORD  pdwDataSize);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetTnf(
IN HANDLE hNDEFRecord,
OUT LPBYTE  pucTnf);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_SetTnf(
IN HANDLE hNDEFRecord,
IN BYTE  ucTnf);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetTypeLength(
IN HANDLE hNDEFRecord,
OUT LPDWORD  pdwTypeLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetType(
IN HANDLE hNDEFRecord,
OUT LPBYTE  lpTypeData);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetTypeStr(
IN HANDLE hNDEFRecord,
OUT LPWSTR  lpwstrType);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_SetType(
IN HANDLE hNDEFRecord,
IN LPBYTE  lpTypeData,
IN DWORD dwTypeLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_SetTypeStr(
IN HANDLE hNDEFRecord,
IN LPWSTR  lpwstrType);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetPayloadLength(
IN HANDLE hNDEFRecord,
OUT LPDWORD  pdwPayloadLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetPayload(
IN HANDLE hNDEFRecord,
OUT LPBYTE  lpPayloadData);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetPayloadText(
IN HANDLE hNDEFRecord,
OUT LPWSTR  lpwstrText);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetPayloadUri(
IN HANDLE hNDEFRecord,
OUT LPWSTR  lpwstrUri);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_SetPayload(
IN HANDLE hNDEFRecord,
IN LPBYTE  lpPayloadData,
IN DWORD dwPayloadLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetIdLength(
IN HANDLE hNDEFRecord,
OUT LPDWORD  pdwIdLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetId(
IN HANDLE hNDEFRecord,
OUT LPBYTE  lpIdData);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_GetIdStr(
IN HANDLE hNDEFRecord,
OUT LPWSTR  lpwstrId);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_SetId(
IN HANDLE hNDEFRecord,
IN LPBYTE  lpIdData,
IN DWORD dwIdLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_NDEF_Record_Destroy(
IN HANDLE hNDEFRecord);





CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_Create(IN LPVOID pReader,
OUT LPHANDLE phLLCPLink);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_SetTimeout(
IN HANDLE hLLCPLink,
IN DWORD dwTimeoutMs);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_SetBaudrate(
IN HANDLE hLLCPLink,
IN BYTE ucDsiDri);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_SetGeneralInformation(
IN HANDLE hLLCPLink,
IN PBYTE lpGI,
IN DWORD dwGILength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_SetNFCID3Information(
IN HANDLE hLLCPLink,
IN PBYTE lpNFCID3i);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_ServerOpen(
IN HANDLE hLLCPLink);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_ServerReceive(
IN HANDLE hLLCPLink,
OUT LPBYTE  lpData,
OUT DWORD lpdwDataLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_ServerClose(
IN HANDLE hLLCPLink);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_ClientOpen(
IN HANDLE hLLCPLink);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_ClientTransmit(
IN HANDLE hLLCPLink,
IN LPBYTE  lpData,
IN DWORD dwDataLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_ClientClose(
IN HANDLE hLLCPLink);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_LLCP_Destroy(
IN HANDLE hLLCPLink);





CLSCRF_API LONG __stdcall
CLSCRF_NFC_SNEP_Create(
IN HANDLE hLLCPLink,
OUT LPHANDLE phSNEP);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_SNEP_Receive(
IN HANDLE hSNEP,
OUT LPBYTE  lpData,
OUT LPDWORD pdwDataLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_SNEP_Transmit(
IN HANDLE hSNEP,
IN LPBYTE  lpData,
IN DWORD dwDataLength);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_SNEP_Destroy(
IN HANDLE hSNEP);



CLSCRF_API LONG __stdcall
CLSCRF_NFC_ForumTags_SupposeTypeISO14443A(IN LPVOID pReader,
IN LPBYTE  ATQ,
IN BYTE  SAK,
OUT LPBYTE pucTagType);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_ForumTags_BeginType4(IN LPVOID pReader);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_ForumTags_Format(IN LPVOID pReader,
IN BYTE ucTagType);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_ForumTags_Read(IN LPVOID pReader,
IN BYTE ucTagType,
OUT LPBYTE  lpData,
IN OUT LPDWORD  lpdwDataSize,
OUT LPBYTE lpucPermissions);

CLSCRF_API LONG __stdcall
CLSCRF_NFC_ForumTags_Write(IN LPVOID pReader,
IN BYTE ucTagType,
IN LPBYTE  lpData,
IN DWORD dwDataSize);


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.





#endif // !defined(AFX_CLSCRF_H__CE290562_87D9_41F4_A1CD_3B80EFEBA737__INCLUDED_)
