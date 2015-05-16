
//==============================================================================
//                        БИБЛИОТЕКА ФУНКЦИЙ RFID-СЧИТЫВАТЕЛЯ
//==============================================================================

// Clscrfl.h : main header file for the CLSCRFL DLL

// Библиотека функций RFID-считывателя включает в себя следующие функции:
//==============================================================================
//      ИНТЕРФЕЙС
//------------------------------------------------------------------------------
//  Создать интерфейс
//  Уничтожить интерфейс
//  Открыть RS-интерфейс
//  Открыть USB-интерфейс
//  Открыть Ethernet-интерфейс
//  Проверить, открыт ли интерфейс
//  Закрыть интерфейс
//  Выдать значение таймаута
//  Установить значение таймаута
//  Выдать код завершения последней операции
//==============================================================================
//      УПРАВЛЕНИЕ СЧИТЫВАТЕЛЕМ
//------------------------------------------------------------------------------
//  Выдать состояние считывателя
//  Включить микросхему-считыватель
//  Выключить микросхему-считыватель
//  Выдать версию микросхемы-считывателя
//  Выдать серийный номер микросхемы-считывателя
//  Сбросить электромагнитное поле считывателя
//  Установить режим модуляции электромагнитного поля считывателя
//  Управление звуковым сигналом
//  Управление светодиодом
//  Установить скорость обмена со считывателем по COM-порту
//==============================================================================
//      УПРАВЛЕНИЕ КАРТАМИ ISO 14443-A
//------------------------------------------------------------------------------
//  Активировать карту ISO 14443-A из состояния IDLE
//  Деактивировать карту ISO 14443-A в состояние HALT
//  Активировать карту ISO 14443-A из состояния HALT
//==============================================================================
//      УПРАВЛЕНИЕ КАРТАМИ ISO 14443-B
//------------------------------------------------------------------------------
//  Активировать карты ISO 14443-B из состояния IDLE
//  Выбрать карту ISO 14443-B
//  Деактивировать карту ISO 14443-B в состояние HALT
//  Активировать карты ISO 14443-B из состояния HALT
//==============================================================================
//      УПРАВЛЕНИЕ МЕТКАМИ ISO 15693
//------------------------------------------------------------------------------
//  Произвести инвентаризацию меток ISO 15693
//  Перевести метку ISO 15693 в состояние Quiet
//  Перевести метку ISO 15693 в состояние Selected
//  Перевести метку ISO 15693 в состояние Ready
//==============================================================================
//      УПРАВЛЕНИЕ МЕТКАМИ ICODE EPC (Отключено: Устарело)
//------------------------------------------------------------------------------
//  Произвести инвентаризацию меток EPC
//  Перевести метку EPC в состояние FIXED SLOT
//  Записать байт в метку EPC
//  Аннулировать метку EPC
//==============================================================================
//      УПРАВЛЕНИЕ МЕТКАМИ ICODE UID (Отключено: Устарело)
//------------------------------------------------------------------------------
//  Произвести инвентаризацию меток UID
//  Перевести метку UID в состояние FIXED SLOT
//  Записать байт в метку UID
//  Аннулировать метку UID
//==============================================================================
//      РАБОТА С КАРТАМИ Mifare Standard
//------------------------------------------------------------------------------
//  Кодировать ключ
//  Аутентифицировать сектор непосредственно
//  Аутентифицировать сектор непосредственно 6-байтовым ключом
//  Записать ключ в EEPROM считывателя
//  Аутентифицировать сектор ключом из EEPROM
//  Прочитать блок
//  Записать блок
//  Уменьшить значение
//  Увеличить значение
//  Копировать значение
//==============================================================================
//      РАБОТА С КАРТАМИ Mifare Ultralight
//------------------------------------------------------------------------------
//  Прочитать страницу
//  Записать страницу
//==============================================================================
//      РАБОТА С МЕТКАМИ ISO 15693
//------------------------------------------------------------------------------
//  Прочитать блок
//  Записать блок
//  Блокировать блок
//  Прочитать несколько блоков
//  Записать AFI
//  Блокировать AFI
//  Записать DSFID
//  Блокировать DSFID
//  Выдать системную информацию
//  Выдать значения статуса защиты блоков от записи
//  Установить EAS
//  Сбросить EAS
//  Блокировать EAS
//  Прочитать EAS
//==============================================================================
//      НЕПОСРЕДСТВЕННЫЙ ОБМЕН ДАННЫМИ
//------------------------------------------------------------------------------
//  Обмен данными со считывателем
//  Непосредственный обмен данными с картой
//==============================================================================
//      КОНФИГУРАЦИЯ УСТРОЙСТВ НА ШИНЕ RS485
//------------------------------------------------------------------------------
//  Выдать адрес обмена
//  Установить адрес обмена
//  Прочитать адрес устройства
//  Записать адрес устройства


// Наиболее часто встречающиеся коды возврата функций:
//          0 - успешное выполнение
// 0x80100001 - внутренняя ошибка считывателя, код которой можно получить 
//              путем вызова функции CLSCRF_GetLastInternalError



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
//                              И Н Т Е Р Ф Е Й С
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Создать интерфейс
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Create( IN OUT LPVOID* ppReader );
//
// Создает объект-интерфейс
//
// ppReader - указатель на переменную, в которую будет помещена ссылка на 
//            созданный объект-интерфейс и которая будет использоваться в 
//            вызовах всех остальных функций
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Эта функция должна вызываться 1 раз в начале работы приложения 
//
////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Уничтожить интерфейс
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Destroy( IN LPVOID* ppReader );
//
// Уничтожает объект-интерфейс
//
// ppReader - указатель на переменную, которая содержит ссылку на уничтожаемый
//            объект-интерфейс (см. функцию CLSCRF_Create )
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Эта функция должна вызываться 1 раз в конце работы приложения
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Открыть интерфейс
//------------------------------------------------------------------------------

CLSCRF_API LONG __stdcall 
            CLSCRF_Open( IN LPVOID pReader,
                         IN DWORD  dwPortNumber = 0,
                         IN DWORD  dwBaudrate = 9600,
                         IN DWORD  dwLogFile = 0 );
//
// Устаревшая функция, оставлена только для совместимости с уже
// существующими приложениями. Для вновь разрабатываемых приложений
// следует пользоваться функциями CLSCRF_OpenRS и CLSCRF_OpenUSB
//
// Открывает интерфейс
//
// pReader      - ссылка на открываемый объект-интерфейс (см. функцию
//                CLSCRF_Create )
// dwPortNumber - выбор интерфейса: 0 - интерфейс USB
//                                  1 - последовательный порт COM1
//                                  2 - последовательный порт COM2
//                                  3 - последовательный порт COM3 и т.д.
// dwBaudrate   - скорость обмена по COM-порту
// dwLogFile    - вывод в файл хронологии обмена: 1 - создавать файл
//                                                0 - не создавать файл
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Эта функция должна вызываться 1 раз перед началом обмена со считывателем
// и каждый раз при изменении скорости обмена по COM-порту
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Открыть RS-интерфейс
//------------------------------------------------------------------------------

CLSCRF_API LONG __stdcall 
            CLSCRF_OpenRS( IN LPVOID pReader,
                           IN DWORD  dwIndex = 0,
                           IN DWORD  dwBaudrate = 9600,
                           IN DWORD  dwLogFile = 0 );
//
// Открывает COM-порт (интерфейс RS232 или RS485)
//
// pReader    - ссылка на открываемый объект-интерфейс (см. функцию
//              CLSCRF_Create )
// dwIndex    - номер COM-порта от 0 ( 0 - COM1, 1 - COM2 и т.д.)
// dwBaudrate - скорость обмена по COM-порту
// dwLogFile  - вывод в файл хронологии обмена: 1 - создавать файл
//                                              0 - не создавать файл
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Эта функция должна вызываться 1 раз перед началом обмена со считывателем
// и каждый раз при изменении скорости обмена по COM-порту
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Открыть USB-интерфейс
//------------------------------------------------------------------------------

CLSCRF_API LONG __stdcall 
            CLSCRF_OpenUSB( IN LPVOID pReader,
                            IN DWORD  dwIndex = 0,
                            IN DWORD  dwLogFile = 0 );
//
// Открывает USB-интерфейс
//
// pReader   - ссылка на открываемый объект-интерфейс (см. функцию
//             CLSCRF_Create )
// dwIndex   - номер USB-устройства в дереве устройств от 0
// dwLogFile - вывод в файл хронологии обмена: 1 - создавать файл
//                                             0 - не создавать файл
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Эта функция должна вызываться 1 раз перед началом обмена со считывателем
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Открыть Ethernet-интерфейс
//------------------------------------------------------------------------------

CLSCRF_API LONG __stdcall 
            CLSCRF_OpenETH( IN LPVOID pReader,
                            IN DWORD  dwPort,
                            IN PCHAR  szIP,
							IN DWORD  dwLogFile );
//
// Открывает Ethernet-интерфейс
//
// pReader   - ссылка на открываемый объект-интерфейс (см. функцию
//             CLSCRF_Create )
// dwPort   - порт считывателя
// szIP		- IP адрес считывателя в формате "aaa.bbb.ccc.ddd"
// dwLogFile - вывод в файл хронологии обмена: 1 - создавать файл
//                                             0 - не создавать файл
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Эта функция должна вызываться 1 раз перед началом обмена со считывателем
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Проверить, открыт ли интерфейс
//------------------------------------------------------------------------------
//
CLSCRF_API bool __stdcall 
            CLSCRF_IsOpened( IN LPVOID pReader );
//
// Проверяет доступность интерфейса
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
//
// Возвращаемое значение:  0   - интерфейс закрыт
//                         1   - интерфейс открыт
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Закрыть интерфейс
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Close( IN LPVOID pReader );
//
// Закрывает интерфейс
//
// pReader - ссылка на закрываемый объект-интерфейс (см. функцию 
//           CLSCRF_Create )
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Эта функция должна вызываться 1 раз перед уничтожением интерфейса
// и каждый раз при изменении скорости обмена по COM-порту
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Выдать значение таймаута
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_GetIOTimeout( IN     LPVOID  pReader,
                                    OUT LPDWORD pdwTimeout );
//
// Выдает текущий интервал ожидания выполнения функций 
//
// pReader    - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pdwTimeout - адрес переменной типа DWORD, в которую будет помещено
//              значение таймаута в миллисекундах
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Установить значение таймаута
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_SetIOTimeout( IN LPVOID pReader,
                                 IN DWORD  dwTimeout );
//
// Время выполнения функций библиотеки складывается из следующих компонентов:
//    - передача команды из компьютера в считыватель
//    - выполнение команды в считывателе
//    - передача ответа из считывателя в компьютер
//    - накладные расходы операционной системы
// При создании интерфейса устанавливается таймаут, равный 1000 мс
// С помощью этой функции можно изменить интервал ожидания выполнения функций
//
// pReader   - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwTimeout - значение таймаута в миллисекундах. Если это значение равно 0,
//             то устанавливается таймаут по умолчанию (2000 мс)
//             Минимальное отличное от 0 значение таймаута 50 мс
//             Максимальное значение таймаута 86400000 мс
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Выдать код завершения последней операции
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_GetLastInternalError( IN     LPVOID pReader,
                                            OUT LPBYTE pbError );
//
// Если предыдущая функция данной библиотеки завершилась с кодом 0x80100001,
// значит произошла ошибка выполнения операции внутри считывателя
// Данная функция выдает значение кода этой внутренней ошибки
// Наиболее часто из внутренних ошибок встречается 0xff - карта не отвечает
//
// pReader  - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbError  - адрес переменной типа unsigned char, в которую будет помещено
//            значение кода внутренней ошибки считывателя
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//                У П Р А В Л Е Н И Е   С Ч И Т Ы В А Т Е Л Е М
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Выдать состояние считывателя
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_GetState( IN     LPVOID  pReader,
                                OUT LPDWORD pdwState );
//
// Выдает состояние считывателя
//
// pReader  - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pdwState - ссылка на переменную, в которую будет помещено значение 
//            состояния устройства:
//
//  биты 31-16 - резерв
//  бит  15    - микросхема-считыватель включена
//  бит  14    - электромагнитное поле включено
//  бит  13    - считыватель поддерживает режимы ICODE
//  бит  12    - считыватель поддерживает режимы ISO 14443-B
//  биты 11-7  - резерв
//  биты 6-4   - текущий режим электромагнитного поля:
//               000 - ISO 14443-A (скорость см. биты 3-0)
//               001 - ISO 14443-B (скорость см. биты 3-0)
//               100 - ISO 15693
//               101 - ICODE1
//               110 - ICODE EPC ISO 18000-3
//               111 - ICODE UID ISO 18000-3
//  биты 3-2   - текущая скорость приема в режимах ISO 14443
//               (поток данных от карты к считывателю):
//               00 - 106 кбод
//               01 - 212 кбод
//               10 - 424 кбод
//               11 - 848 кбод
//  биты 1-0   - текущая скорость передачи в режимах ISO 14443
//               (поток данных от считывателя к карте):
//               00 - 106 кбод
//               01 - 212 кбод
//               10 - 424 кбод
//               11 - 848 кбод
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Включить микросхему-считыватель
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Mfrc_On( IN LPVOID pReader );
//
// Включает микросхему-считыватель
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Примечание. При включенной микросхеме-считывателе в рабочем режиме
// устройство потребляет ток до 120 mA.
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Выключить микросхему-считыватель
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Mfrc_Off( IN LPVOID pReader );
//
// Выключает микросхему-считыватель
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Примечание. При выключенной микросхеме-считывателе устройство воспринимает
// команды, но не выполняет те из них, которые касаются этой микросхемы.
// В этом состоянии устройство потребляет ток до 50 mA.
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Выдать версию микросхемы-считывателя
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Get_Mfrc_Version( IN     LPVOID pReader,
                                        OUT LPBYTE pbMfrcVersion );
//
// Выдает код продукта (в т.ч. версию) микросхемы-считывателя
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbMfrcVersion - адрес массива типа unsigned char, в который будет 
//                 помещено 6 байтов версии считывателя, из которых
//                 4 байта - код продукта микросхемы-считывателя
//                 1 байт  - версия микросхемы-считывателя
//                 1 байт  - версия микропрограммы считывателя
// Примеры:
//      30 88 FE 03 04 20	- микросхема MF RC530,
//      30 CC FF 0F 04 20	- микросхема MF RC531,
//      30 FF FF 0F 04 20	- микросхема CL RC632,
//   где версия микросхемы 04, версия микропрограммы 2.0
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Выдать серийный номер микросхемы-считывателя
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Get_Mfrc_Serial_Number( IN     LPVOID pReader,
                                              OUT LPBYTE pbMfrcSN );
//
// Выдает серийный (уникальный) номер микросхемы-считывателя
//
// pReader  - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbMfrcSN - адрес массива типа unsigned char, в который будет 
//            помещено 4 байта серийного номера
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Сбросить электромагнитное поле считывателя
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Mfrc_Rf_Off_On( IN LPVOID pReader,
                                   IN USHORT usDelay );
//
// Сбрасывает или выключает электромагнитное поле (ЭМП) считывателя
// Сброс ЭМП необходим для рестарта микросхемы транспондера
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// usDelay - интервал времени [мс], в течение которого ЭМП выключено. 
//           Если этот параметр равен 0, то ЭМП остается выключенным
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Установить режим модуляции электромагнитного поля считывателя
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Mfrc_Set_Rf_Mode( IN LPVOID pReader,
                                     IN BYTE   bRfMode );
//
// Устанавливает режим модуляции электромагнитного поля считывателя на 
// передачу команды и последующий прием ответа от карты
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bRfMode - байт режима модуляции ЭМП:
//  бит 7      - резерв
//  биты 6-4   - устанавливаемый режим электромагнитного поля:
//               000 - ISO 14443-A (скорость см. биты 3-0)
//               001 - ISO 14443-B (скорость см. биты 3-0)
//               100 - ISO 15693
//               101 - ICODE1
//               110 - ICODE EPC ISO 18000-3
//               111 - ICODE UID ISO 18000-3
//  биты 3-2   - устанавливаемая скорость приема в режимах ISO 14443
//               (поток данных от карты к считывателю):
//               00 - 106 кбод
//               01 - 212 кбод
//               10 - 424 кбод
//               11 - 848 кбод
//  биты 1-0   - устанавливаемая скорость передачи в режимах ISO 14443
//               (поток данных от считывателя к карте):
//               00 - 106 кбод
//               01 - 212 кбод
//               10 - 424 кбод
//               11 - 848 кбод
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Управление звуковым сигналом
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Sound( IN LPVOID pReader,
                          IN BYTE   nBeepCount );
//
// Подает звуковой сигнал
//
// pReader    - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// nBeepCount - количество одиночных сигналов длительностью 100 мс с 
//              промежутками такой же длительности.
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Управление светодиодом
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Led( IN LPVOID pReader,
                        IN BYTE   bBlinkColor,
                        IN BYTE   bBlinkCount,
                        IN BYTE   bPostColor );
//
// Мигает двухцветным светодиодом, затем гасит или зажигает его постоянно
// Частота миганий - 2 Гц
//
// pReader     - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bBlinkColor - цвет мигающего светодиода:
//                0   - не мигать
//                1   - мигать красным
//                2   - мигать зеленым
//                3   - мигать желто-оранжевым
// bBlinkCount - количество миганий (если 0 - не мигать)
// bPostColor  - последующее состояние светодиода:
//                0   - погасить
//                1   - зажечь красным
//                2   - зажечь зеленым
//                3   - зажечь желто-оранжевым
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Установить скорость обмена со считывателем по COM-порту
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_UART_Baudrate( IN LPVOID pReader,
                                  IN DWORD  dwBaudrate );
//
// Устанавливает скорость обмена со считывателем по COM-порту
//
// pReader    - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwBaudrate - новая скорость обмена по COM-порту; возможные значения:
//                  9600
//                 14400
//                 19200
//                 38400
//                 57600
//                115200
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Установить сообщение на индикаторе
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
// Устанавливает сообщение на текстовом индикаторе
//
// pReader    - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// lpMessage - указатель на массив символов, содержащий текст сообщения;
// dwMessageLength - длина сообщения в символах;
// dwInfiniteLoop : 0 - отределять сколько раз повторять цикл через параметр ucRepeats,
//                  1 - повторять цикл бесконечно;
// dwLineIndex: 0 - выбор верхней строки,
//              1 - выбор нижней строки;
// dwMode: 0 - недоступно, 
//         1 - мигать,
//         2 - бегущая строка,
//         3 - недоступно.
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//         У П Р А В Л Е Н И Е   К А Р Т А М И   I S O   1 4 4 4 3 - A
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Активировать карту ISO 14443-A из состояния IDLE
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Activate_Idle_A( IN     LPVOID  pReader,
                                       OUT LPBYTE  pbATQ,
                                       OUT LPBYTE  pbSAK,
                                       OUT LPBYTE  pbUID,
                                    IN OUT LPDWORD pdwUIDLength );
//
// Активирует карту ISO 14443-A из состояния IDLE (см. ISO 14443-3 п.6.3)
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbATQ   - ссылка на массив (2 байта), в которые будет помещен ATQ карты
// pbSAK   - ссылка на массив (1 байт), в который будет помещен SAK карты
// pbUID   - ссылка на массив не менее 10 байтов, в который будет
//           помещен уникальный идентификатор карты (UID)
// pdwUIDLength - ссылка на переменную типа DWORD, которая перед вызовом
//                функции должна содержать размер массива pbUID, а на выходе
//                будет содержать действительную длину уникального 
//                идентификатора карты, помещенного в массив pbUID
//                (возможные значения - 4, 7 или 10)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Деактивировать карту ISO 14443-A в состояние HALT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Halt_A( IN LPVOID pReader );
//
// Деактивирует карту ISO 14443-A в состояние HALT (см. ISO 14443-3 п.6.3)
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Активировать карту ISO 14443-A из состояния HALT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Activate_Wakeup_A( IN     LPVOID  pReader,
                                      IN     LPBYTE  pbUID,
                                      IN     DWORD   UIDLength,
                                         OUT LPBYTE  pbATQ,
                                         OUT LPBYTE  pbSAK );

// Активирует карту ISO 14443-A из состояния HALT (см. ISO 14443-3 п.6.3)
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbUID   - ссылка на массив не менее 10 байтов, в котором перед вызовом 
//           функции должен быть помещен уникальный идентификатор карты (UID)
// UIDLength - длина уникального идентификатора карты, который содержится
//             в массиве pbUID
// pbATQ - ссылка на массив (2 байта), в которые будет помещен ATQ карты
// pbSAK - ссылка на массив (1 байт), в который будет помещен SAK карты
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//         У П Р А В Л Е Н И Е   К А Р Т А М И   I S O   1 4 4 4 3 - B
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Активировать карты ISO 14443-B из состояния IDLE
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
// Активирует карты ISO 14443-B из состояния IDLE (см. ISO 14443-3 п.7.7)
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bAfi    - идентификатор семейства приложений
// bSni    - код количества временнЫх слотов (от 0 до 4), такой что 
//           количество слотов равно   2 ^ bSni
// pdwPUPI - ссылка на массив типа DWORD размером 16, в который будут
//           помещены псевдоуникальные идентификаторы обнаруженных карт,
//           по 4 байта для одной карты на элемент массива
// pdwAppData - ссылка на массив типа DWORD размером 16, в который будет
//              помещена информация о приложениях в обнаруженных картах,
//              по 4 байта для одной карты на элемент массива
// pdwProtInfo - ссылка на массив типа DWORD размером 16, в который будет
//               помещена информация о протоколах обнаруженных карт,
//               по 3 байта для одной карты на элемент массива в битах
//               с 0 по 23
// pdwCardCount - ссылка на переменную типа DWORD, которая перед вызовом
//                функции должна содержать размер массивов pdwPUPI, 
//                pdwAppData и pdwProtInfo, а на выходе будет содержать 
//                количество обнаруженных карт (от 0 до 16)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Выбрать карту ISO 14443-B
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
// Выбирает карту ISO 14443-B (см. ISO 14443-3 п.7.10) и назначает ей 
// логический идентификатор CID для  обмена по протоколу T = CL 
// (см. ISO 14443-4)
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbPUPI  - ссылка на массив (4 байта), в котором находится
//           псевдоуникальный идентификатор выбираемой карты
// bParam1 - формат кадра от считывателя к карте
// bParam2 - максимальные размер кадра и скорости обмена считывателя
// bParam3 - поддержка считывателем протокола ISO 14443-4
// bParam4 - логический идентификатор карты (CID)
// pbHigherLayerBuf - буфер для   Higher layer - INF  на входе 
//           и  Higher layer Response  на выходе    
// dwHLBufSize - длина массива pbHigherLayerBuf
// pdwHLInfLength - ссылка на переменную, в которой на входе указывают 
//           длину  Higher layer - INF   в массиве pbHigherLayerBuf  
//           а на выходе в ней будет помещена длина Higher layer Response, 
//           записанного в массив pbHigherLayerBuf
// pbMbliCid - ссылка на переменную, в которую будет помещено 
//           значение MBLI CID
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Деактивировать карту ISO 14443-B в состояние HALT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Halt_B( IN LPVOID pReader,
                           IN LPBYTE pbPUPI );
//
// Деактивирует карту ISO 14443-B в состояние HALT (см. ISO 14443-3 п.7.12)
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbPUPI  - ссылка на массив (4 байта), в котором находится
//           псевдоуникальный идентификатор деактивируемой карты
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Активировать карты ISO 14443-B из состояния HALT
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
// Активирует карты ISO 14443-B из состояния HALT (см. ISO 14443-3 п.7.7)
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bAfi    - идентификатор семейства приложений
// bSni    - код количества временнЫх слотов (от 0 до 4), такой что 
//           количество слотов равно   2 ^ bSni
// pdwPUPI - ссылка на массив типа DWORD размером 16, в который будут
//           помещены псевдоуникальные идентификаторы обнаруженных карт,
//           по 4 байта для одной карты на элемент массива
// pdwAppData - ссылка на массив типа DWORD размером 16, в который будет
//              помещена информация о приложениях в обнаруженных картах,
//              по 4 байта для одной карты на элемент массива
// pdwProtInfo - ссылка на массив типа DWORD размером 16, в который будет
//               помещена информация о протоколах обнаруженных карт,
//               по 3 байта для одной карты на элемент массива в битах
//               с 0 по 23
// pdwCardCount - ссылка на переменную типа DWORD, которая перед вызовом
//                функции должна содержать размер массивов pdwPUPI, 
//                pdwAppData и pdwProtInfo, а на выходе будет содержать 
//                количество обнаруженных карт (от 0 до 16)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//           У П Р А В Л Е Н И Е   М Е Т К А М И   I S O   1 5 6 9 3
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Произвести безмасочную инвентаризацию меток ISO 15693
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
// Производит инвентаризацию меток ISO 15693 (см. ISO 15693-3 п.10.3.1)
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags        - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bInventory    - код команды Inventory (всегда равен 0x01)
// bAfi          - идентификатор семейства приложений
// bMaskLen      - количество битов маски
// pbMaskVal     - массив байтов, содержащий маску
// pbRecvBuffer  - массив для ответа от считывателя
// pdwRecvLength - ссылка на переменную типа DWORD, которая перед вызовом
//                 функции должна содержать размер массива pbRecvBuffer, 
//                 а на выходе будет содержать количество принятых от
//                 считывателя байтов по 1 или 16 временнЫм слотам
//
//      Для каждого временнОго слота в массиве pbRecvBuffer 
//      расположена следующая информация:
//
//      RetCode - код завершения запроса в этом слоте       - 1 байт
//      Count   - количество байтов, полученных от метки    - 1 байт
// Если Count отличен от 0, то далее следует ответ от метки
// (см. ISO 15693 п.10.3.1):
//      Flags                                               - 1 байт
//      DSFID                                               - 1 байт
//      UID                                                 - 8 байтов
// Если RetCode отличен от 0, то далее может присутствовать
//      CRC16                                               - 2 байта
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Произвести рекурсивную масочную инвентаризацию всех меток ISO 15693
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_FindAllTags_15693( IN     LPVOID  pReader,
                                    IN     BYTE    bFlags,
                                    IN     BYTE    bAfi,
                                       OUT LPBYTE  pbRecvBuffer, 
                                    IN OUT LPDWORD pdwRecvLength );
//
// Производит инвентаризацию меток ISO 15693 (см. ISO 15693-3 п.10.3.1)
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags        - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bAfi          - идентификатор семейства приложений
// pbRecvBuffer  - массив для ответа от считывателя, в который запишутся 8-байтовые идентификаторы 
//                 UID всех обнаруженных меток
// pdwRecvLength - ссылка на переменную типа DWORD, которая перед вызовом
//                 функции должна содержать размер массива pbRecvBuffer, 
//                 а на выходе будет содержать увосьмиренное количество обнаруженных меток
//
//                 
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Перевести метку ISO 15693 в состояние Quiet
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Stay_Quiet_15693( IN LPVOID pReader,
                                     IN BYTE   bFlags,
                                     IN BYTE   bStayQuiet,
                                     IN LPBYTE pbUID );
//
// Переводит метку в состояние Quiet (см. ISO 15693-3 п.10.3.2)
//
// pReader    - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags     - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bStayQuiet - код команды Stay Quiet (всегда равен 0x02)
// pbUID      - ссылка на массив (8 байтов), в котором находится
//              уникальный идентификатор метки
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Перевести метку ISO 15693 в состояние Selected
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
// Переводит метку в состояние Selected (см. ISO 15693-3 п.10.4.6)
//
// pReader     - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags      - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bSelect     - код команды Select (всегда равен 0x25)
// pbUID       - ссылка на массив (8 байтов), в котором находится
//               уникальный идентификатор метки
// pbFlags     - ссылка на переменную типа BYTE, в которую будут
//               помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode - ссылка на переменную типа BYTE, в которую будет
//               помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Перевести метку ISO 15693 в состояние Ready
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
// Переводит метку в состояние Ready (см. ISO 15693-3 п.10.4.7)
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags        - флаги запроса (см. ISO 15693-3 п.7.3.1)
//                 (рекомендуется включить флаг Select_flag)
// bResetToReady - код команды Reset to ready (всегда равен 0x26)
// pbUID         - ссылка на массив (8 байтов), в котором находится
//                 уникальный идентификатор метки, может быть равен NULL при
//                 включенном флаге Select_flag (рекомендуется)
// pbFlags       - ссылка на переменную типа BYTE, в которую будут
//                 помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode   - ссылка на переменную типа BYTE, в которую будет
//                 помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
/*
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//           У П Р А В Л Е Н И Е   М Е Т К А М И   I C O D E    E P C
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Произвести инвентаризацию меток EPC
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
// Производит инвентаризацию меток EPC
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bBeginRound   - код команды BeginRound (всегда равен 0x30)
// bMaskLen      - количество битов маски (от 0 до 96)
// pbMaskVal     - массив байтов, содержащий маску
// bSlotNCode    - код количества слотов: 0 -> SlotCount = 1 слот
//                                        1 -> SlotCount = 4 слота
// bHashVal      - инициализация генератора номера слота
// bFixCommand   - 0 - оставить метки в состоянии READY
//                 1 - перевести метки в состояние FIXED SLOT
// pbRecvBuffer  - массив для ответа от считывателя
// pdwRecvLength - ссылка на переменную типа DWORD, которая перед вызовом
//                 функции должна содержать размер массива pbRecvBuffer, 
//                 а на выходе будет содержать количество принятых от
//                 считывателя байтов

// Структура ответа от считывателя в массиве pbRecvBuffer:
//
//      RetCodeSlotF - код ответа в фиксированном слоте     - 1 байт
//         0x00 - есть ответ в фиксированном слоте
//         0xff - нет ответа в фиксированном слоте
//      ответы от меток в слотах 0..(SlotCount-1)

//      Для каждого слота с номерами от 0 до (SlotCount-1)
//      в массиве pbRecvBuffer расположена следующая информация:
//
//      RetCode - код завершения запроса в этом слоте       - 1 байт
//         0x00 - нет ошибок
//         0xff - нет ответа
//         0xfe - неверный CRC16
//         0xf5 - неверное количество принятых битов
//         0xe8 - коллизия в слоте
//      Count   - количество байтов, полученных от метки    - 1 байт
// Если Count отличен от 0, то далее следует ответ от метки,
// усеченный в соответствии с маской:
//      EPC                                         - (Count-2) байтов
//      CRC16                                               - 2 байта
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Перевести метку EPC в состояние FIXED SLOT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_EPC_Fix_Slot( IN LPVOID  pReader,
                                 IN LPCBYTE pbEPC,
                                 IN LPCBYTE pbCRC16 );
//
// Переводит метку EPC из состояния READY в состояние FIXED SLOT
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbEPC   - массив байтов, содержащий значения байтов памяти метки 
//           в блоках с 0-го по 11-й включительно          - 12 байтов
// pbCRC16 - массив байтов, содержащий значения байтов памяти метки 
//           в блоках с 12-го по 13-й включительно         -  2 байта
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать байт в метку EPC
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_EPC_Write( IN LPVOID pReader,
                              IN BYTE   bWrite,
                              IN BYTE   bBlockNumber,
                              IN BYTE   bData );
//
// Записывает информацию в заданный блок метки EPC
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bWrite       - код команды Write (всегда равен 0x01)
// bBlockNumber - номер записываемого блока данных          - 1 байт
// bData        - записываемое значение                     - 1 байт
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Аннулировать метку EPC
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_EPC_Destroy( IN LPVOID  pReader,
                                IN BYTE    bDestroy,
                                IN LPCBYTE pbEPC, 
                                IN LPCBYTE pbDestroyCode );
//
// Аннулирует метку EPC
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bDestroy      - код команды Destroy (всегда равен 0x02)
// pbEPC         - массив байтов, содержащий EPC            - 12 байтов
// pbDestroyCode - массив байтов, содержащий Destroy Code   -  3 байта
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//           У П Р А В Л Е Н И Е   М Е Т К А М И   I C O D E    U I D
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Произвести инвентаризацию меток UID
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
// Производит инвентаризацию меток UID
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bBeginRound   - код команды BeginRound (всегда равен 0x30)
// bMaskLen      - количество битов маски (от 0 до 152)
// pbMaskVal     - массив байтов, содержащий маску
// bSlotNCode    - код количества слотов: 0 -> SlotCount = 1 слот
//                                        1 -> SlotCount = 4 слота
// bFixCommand   - 0 - оставить метки в состоянии READY
//                 1 - перевести метки в состояние FIXED SLOT
// pbRecvBuffer  - массив для ответа от считывателя
// pdwRecvLength - ссылка на переменную типа DWORD, которая перед вызовом
//                 функции должна содержать размер массива pbRecvBuffer, 
//                 а на выходе будет содержать количество принятых от
//                 считывателя байтов

// Структура ответа от считывателя в массиве pbRecvBuffer:
//
//      RetCodeSlotF - код ответа в фиксированном слоте     - 1 байт
//         0x00 - есть ответ в фиксированном слоте
//         0xff - нет ответа в фиксированном слоте
//      ответы от меток в слотах 0..(SlotCount-1)

//      Для каждого слота с номерами от 0 до (SlotCount-1)
//      в массиве pbRecvBuffer расположена следующая информация:
//
//      RetCode - код завершения запроса в этом слоте       - 1 байт
//         0x00 - нет ошибок
//         0xff - нет ответа
//         0xfe - неверный CRC16
//         0xf5 - неверное количество принятых битов
//         0xe8 - коллизия в слоте
//      Count   - количество байтов, полученных от метки    - 1 байт
// Если Count отличен от 0, то далее следует ответ от метки,
// усеченный в соответствии с маской:
//      IDD                                         - (Count-2) байтов
//      CRC16                                               - 2 байта
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Перевести метку UID в состояние FIXED SLOT
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_UID_Fix_Slot( IN LPVOID  pReader,
                                 IN LPCBYTE pbIDD,
                                 IN LPCBYTE pbCRC16 );
//
// Переводит метку UID из состояния READY в состояние FIXED SLOT
//
// pReader  - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbIDD   - массив байтов, содержащий значения байтов памяти метки 
//           в блоках с 0-го по 18-й включительно          - 19 байтов
// pbCRC16 - массив байтов, содержащий значения байтов памяти метки 
//           в блоках с 19-го по 20-й включительно         -  2 байта
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать байт в метку UID
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_UID_Write( IN LPVOID pReader,
                              IN BYTE   bWrite,
                              IN BYTE   bBlockNumber,
                              IN BYTE   bData );
//
// Записывает информацию в заданный блок метки UID
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bWrite       - код команды Write (всегда равен 0x01)
// bBlockNumber - номер записываемого блока данных          - 1 байт
// bData        - записываемое значение                     - 1 байт
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Аннулировать метку UID
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_UID_Destroy( IN LPVOID  pReader,
                                IN BYTE    bDestroy,
                                IN LPCBYTE pbIDD, 
                                IN LPCBYTE pbDestroyCode );
//
// Аннулирует метку UID
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bDestroy      - код команды Destroy (всегда равен 0x02)
// pbIDD         - массив байтов, содержащий IDD            - 19 байтов
// pbDestroyCode - массив байтов, содержащий Destroy Code   -  3 байта
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
*/
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//       Р А Б О Т А   С   К А Р Т А М И   M I F A R E   S T A N D A R D
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Кодировать ключ
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_HostCodeKey( IN     LPVOID pReader,
                                               IN     LPBYTE pbUncoded,
                                                  OUT LPBYTE pbCoded );
//
// Кодирует ключ Mifare Standard
//
// pReader   - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbUncoded - массив (6 байтов) исходного (некодированного) ключа
// pbCoded   - массив (12 байтов) кодированного ключа
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Аутентифицировать сектор непосредственно
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_AuthKey( IN LPVOID pReader,
                                           IN BYTE   bKeyType,
                                           IN LPBYTE pbUID,
                                           IN DWORD  dwSector,
                                           IN LPBYTE pbCodedKey );
//
// Производит аутентификацию сектора непосредственно заданным ключом
//
// pReader    - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bKeyType   - тип ключа: 0x60 - Key A
//                         0x61 - Key B
// pbUID      - массив (4 байта), содержащий уникальный идентификатор карты
// dwSector   - номер аутентифицируемого сектора
// pbCodedKey - массив (12 байтов) кодированного ключа
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Аутентифицировать сектор непосредственно 6-байтовым ключом
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_AuthKeyDirect(	IN LPVOID pReader,
													IN BYTE   bKeyType,
													IN LPBYTE pbUID,
													IN DWORD  dwSector,
													IN LPBYTE pbKey );
//
// Производит аутентификацию сектора непосредственно заданным ключом
//
// pReader    - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bKeyType   - тип ключа: 0x60 - Key A
//                         0x61 - Key B
// pbUID      - массив (4 байта), содержащий уникальный идентификатор карты
// dwSector   - номер аутентифицируемого сектора
// pbKey	  - массив (6 байтов) ключа
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать ключ в EEPROM считывателя
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_WriteKeyToE2( IN LPVOID pReader,
                                                IN BYTE   bKeyType,
                                                IN DWORD  dwE2RecNo,
                                                IN LPBYTE pbUncoded );
//
// Записывает ключ заданного типа для заданного сектора в EEPROM считывателя
//
// pReader   - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bKeyType  - тип ключа: 0x60 - Key A
//                        0x61 - Key B
// dwE2RecNo - номер записи в EEPROM считывателя, в которую записывается ключ
//			   (соответствует номеру сектора при использовании команды 
//			    CLSCRF_MifareStandard_AuthE2, 0..15)
// pbUncoded - массив (6 байтов) некодированного ключа
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Аутентифицировать сектор конкретным ключом из EEPROM
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
		CLSCRF_MifareStandard_AuthE2Ex(   IN LPVOID pReader,
                                          IN BYTE   bKeyType,
                                          IN LPBYTE pbUID,
                                          IN DWORD  dwE2RecNo,
                                          IN DWORD  dwSector );
//
// Производит аутентификацию сектора ключом, находящимся в EEPROM считывателя
//
// pReader    - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bKeyType   - тип ключа: 0x60 - Key A
//                         0x61 - Key B
// pbUID      - массив (4 байта), содержащий уникальный идентификатор карты
// dwE2RecNo  - номер записи в EEPROM считывателя, из которой нужно взять ключ
//				(0..15)
// dwSector   - номер аутентифицируемого сектора
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Аутентифицировать сектор соответствующим ключом из EEPROM
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_AuthE2( IN LPVOID pReader,
                                          IN BYTE   bKeyType,
                                          IN LPBYTE pbUID,
                                          IN DWORD  dwSector );
//
// Производит аутентификацию сектора ключом, находящимся в EEPROM считывателя
//
// pReader    - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bKeyType   - тип ключа: 0x60 - Key A
//                         0x61 - Key B
// pbUID      - массив (4 байта), содержащий уникальный идентификатор карты
// dwSector   - номер аутентифицируемого сектора (0..15)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Прочитать блок
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_Read( IN     LPVOID pReader,
                                        IN     DWORD  dwSector,
                                        IN     DWORD  dwBlock,
                                           OUT LPBYTE pbRecvBuffer );
//
// Читает 16 байтов из заданного блока в заданном секторе
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwSector     - номер сектора, содержащего читаемый блок
// dwBlock      - номер читаемого блока
// pbRecvBuffer - массив (не менее 16 байтов) для прочитанного блока
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Перед вызовом этой функции должна быть проведена аутентификация сектора
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать блок
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_Write( IN LPVOID pReader,
                                         IN DWORD  dwSector,
                                         IN DWORD  dwBlock,
                                         IN LPBYTE pbSendBuffer );
//
// Записывает 16 байтов в заданный блок в заданном секторе
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwSector     - номер сектора, содержащего записываемый блок
// dwBlock      - номер записываемого блока
// pbSendBuffer - массив (не менее 16 байтов) данных записываемого блока
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Перед вызовом этой функции должна быть проведена аутентификация сектора
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Уменьшить значение
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_Decrement( IN LPVOID pReader,
                                             IN DWORD  dwSector,
                                             IN DWORD  dwSourceBlock,
                                             IN DWORD  dwValue,
                                             IN DWORD  dwTargetBlock );
//
// Уменьшает значение блока типа Value
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwSector      - номер сектора, содержащего читаемый блок
// dwSourceBlock - номер исходного блока
// dwValue       - вычитаемое, на которое уменьшается значение
// dwTargetBlock - номер блока-результата, может быть равен dwSourceBlock
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Перед вызовом этой функции должна быть проведена аутентификация сектора
// Блоки dwSourceBlock и dwTargetBlock должны принадлежать сектору dwSector
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Увеличить значение
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_Increment( IN LPVOID pReader,
                                             IN DWORD  dwSector,
                                             IN DWORD  dwSourceBlock,
                                             IN DWORD  dwValue,
                                             IN DWORD  dwTargetBlock );
//
// Увеличивает значение блока типа Value
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwSector      - номер сектора, содержащего читаемый блок
// dwSourceBlock - номер исходного блока
// dwValue       - слагаемое, на которое увеличивается значение
// dwTargetBlock - номер блока-результата, может быть равен dwSourceBlock
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Перед вызовом этой функции должна быть проведена аутентификация сектора
// Блоки dwSourceBlock и dwTargetBlock должны принадлежать сектору dwSector
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Копировать значение
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_Restore( IN LPVOID pReader,
                                           IN DWORD  dwSector,
                                           IN DWORD  dwSourceBlock,
                                           IN DWORD  dwTargetBlock );
//
// Копирует значение из одного блока типа Value в другой в заданном секторе
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwSector      - номер сектора, содержащего оба блока
// dwSourceBlock - номер исходного блока
// dwTargetBlock - номер блока-результата
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Перед вызовом этой функции должна быть проведена аутентификация сектора
// Блоки dwSourceBlock и dwTargetBlock должны принадлежать сектору dwSector
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Персонализация UID
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_EV1_PersonalizeUid(	IN LPVOID pReader,
														IN BYTE  ucUidMode );
//
// Команда выполняется один раз в период жизни карты, устанавливая один из режимов UID
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucUidMode     - режим UID (режим, в который переводится карта)
//					Одно из значений: 
//					UIDF0 = 0x00, 
//					UIDF1 = 0x40, 
//					UIDF2 = 0x20, 
//					UIDF3 = 0x60
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Перед вызовом этой функции должна быть проведена аутентификация сектора 0
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Изменение нагрузки антенны карт
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareStandard_EV1_SetLoadModulationType(	IN LPVOID pReader,
																IN BYTE  ucModType );
//
// Команда измененяет нагрузку антенны карт
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucModType     - тип нагрузки: 0x01 - Сильная (по умолчанию), 0x00 - нормальная
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Перед вызовом этой функции должна быть проведена аутентификация сектора 0
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//   Р А Б О Т А    С    К А Р Т А М И    M I F A R E    U L T R A L I G H T (C)
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Прочитать страницу
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareUltralight_Read( IN     LPVOID pReader,
                                          IN     BYTE   bPage,
                                             OUT LPBYTE pbRecvBuffer );
//
// Читает 4 страницы (16 байтов), начиная с заданной страницы
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bPage        - номер читаемой страницы
// pbRecvBuffer - массив (не менее 16 байтов) для прочитанной страницы
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать страницу
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareUltralight_Write( IN LPVOID pReader,
                                           IN BYTE   bPage,
                                           IN LPBYTE pbSendBuffer );
//
// Пишет 4 байта в заданную страницу
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bPage        - номер записываемой страницы
// pbSendBuffer - массив (не менее 4 байтов) данных записываемой страницы
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Для карт Ultra Light C: Запись ключа
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareUltralightC_WriteKey(	IN LPVOID pReader,
												IN DWORD  dwKeyFlashAddress );
//
// Производит запись в карту ключа из flash считывателя 
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwKeyFlashAddress - адрес ключа во flash считывателя, 
// который следует записать в карту
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Для карт Ultra Light C: Аутентификация
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareUltralightC_Authenticate(	IN LPVOID pReader,
													IN DWORD  dwKeyFlashAddress );
//
// Производит аутентификацию по ключу
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwKeyFlashAddress - адрес ключа во flash считывателя, 
// который следует использовать для аутентификации 
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//             Р А Б О Т А   С   М Е Т К А М И   I S O   1 5 6 9 3
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Прочитать блок
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
// Читает 4 байта из заданного блока (см. ISO 15693-3 п.10.4.1)
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bReadSingleBlock - код команды Read Single Block (всегда равен 0x20)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// bBlockNumber - номер читаемого блока (от 0)
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbBlockSecurityStatus - ссылка на переменную типа BYTE, в которую будет
//                         помещен статус защиты блока от записи
// pbData       - ссылка на массив (не менее 4 байтов) для прочитанного блока
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать блок
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
// Записывает 4 байта в заданный блок (см. ISO 15693-3 п.10.4.2)
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bWriteSingleBlock - код команды Write Single Block (всегда равен 0x21)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// bBlockNumber - номер записываемого блока (от 0)
// pbData       - ссылка на массив (не менее 4 байтов) записываемых даннных
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать блок
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
// Записывает 4*bBlocksCount байт в заданный диапазон блоков (см. ISO 15693-3 п.10.4.5)
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bWriteMultipleBlocks - код команды Write Multiple Blocks (всегда равен 0x24)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// bBlockNumber - номер первого записываемого блока (от 0)
// bBlocksCount - количество записываемых блоков (от 1)
// pbData       - ссылка на массив (не менее 4 байтов) записываемых даннных
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Блокировать блок
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
// Предохраняет заданный блок от перезаписи (см. ISO 15693-3 п.10.4.3)
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bLockBlock   - код команды Lock Block (всегда равен 0x22)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// bBlockNumber - номер закрываемого блока (от 0)
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Прочитать несколько блоков
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
// Читает несколько блоков (см. ISO 15693-3 п.10.4.4)
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bReadMultipleBlock - код команды Read Multiple Block (всегда равен 0x23)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// bFirstBlockNumber - номер первого читаемого блока (от 0)
// pbNumberOfBlocks - ссылка на переменную типа BYTE, которая перед вызовом
//                    функции должна содержать количество (от 0) читаемых 
//                    блоков, а на выходе будет содержать количество 
//                    (тоже от 0) действительно прочитанных блоков
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbBlockSecurityStatus - ссылка на массив (до 256 байтов) типа BYTE, в 
//                         который будут помещены значения статуса защиты 
//                         блоков от записи (только при наличии флага 
//                         Option_flag)
// pbData       - ссылка на массив (до 8192 байтов) для прочитанных данных
//                (по 4 байта на каждый блок)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать AFI
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
// Записывает 1 байт AFI (см. ISO 15693-3 п.10.4.8)
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bWriteAFI    - код команды Write AFI (всегда равен 0x27)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// bAFI         - записываемое значение AFI
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Блокировать AFI
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
// Предохраняет AFI от перезаписи (см. ISO 15693-3 п.10.4.9)
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bLockAFI     - код команды Lock AFI (всегда равен 0x28)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать DSFID
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
// Записывает 1 байт DSFID (см. ISO 15693-3 п.10.4.10)
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bWriteDSFID  - код команды Write DSFID (всегда равен 0x29)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// bDSFID       - записываемое значение DSFID
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Блокировать DSFID
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
// Предохраняет DSFID от перезаписи (см. ISO 15693-3 п.10.4.11)
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bLockDSFID   - код команды Lock DSFID (всегда равен 0x2a)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Выдать системную информацию
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
// Выдает значения системной информации (см. ISO 15693-3 п.10.4.12)
//
// pReader        - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags         - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bGetSystemInfo - код команды Get System Information (всегда равен 0x2b)
// pbUID          - ссылка на массив (8 байтов), который перед вызовом
//                  функции может содержать уникальный идентификатор метки, а
//                  на выходе будет содержать уникальный идентификатор метки, 
//                  прочитанный как часть системной информации
// pbFlags        - ссылка на переменную типа BYTE, в которую будут
//                  помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbInfoFlags    - ссылка на переменную типа BYTE, в которую будут
//                  помещены флаги системной информации
// pbDSFID        - ссылка на переменную типа BYTE, в которую будет
//                  помещено значение DSFID
// pbAFI          - ссылка на переменную типа BYTE, в которую будет
//                  помещено значение AFI
// pbMemorySize   - ссылка на переменную типа WORD, в которую будет
//                  помещено значение Information on VICC memory size
// pbICReference  - ссылка на переменную типа BYTE, в которую будет
//                  помещено значение Information on IC reference
// pbErrorCode    - ссылка на переменную типа BYTE, в которую будет
//                  помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Выдать значения статуса защиты блоков от записи
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
// Выдает значения статуса защиты блоков от записи (block security status)
// (см. ISO 15693-3 п.10.4.13)
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bGetMultipleBSS - код команды Get Multiple Block Security Status
//                   (всегда равен 0x2c)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// bFirstBlockNumber - номер первого читаемого блока (от 0)
// pbNumberOfBlocks - ссылка на переменную типа BYTE, которая перед вызовом
//                    функции должна содержать количество (от 0) читаемых 
//                    значений статуса защиты блоков от записи,
//                    а на выходе будет содержать количество 
//                    (тоже от 0) действительно прочитанных значений
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbBlockSecurityStatus - ссылка на массив (до 256 байтов) типа BYTE, в 
//                         который будут помещены значения статуса защиты 
//                         блоков от записи
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Установить EAS
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
// Устанавливает EAS в 1
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bSetEAS      - код команды Set EAS (всегда равен 0xa2)
// bICMfgCode   - код производителя микросхемы метки
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Сбросить EAS
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
// Сбрасывает EAS в 0
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bResetEAS    - код команды Reset EAS (всегда равен 0xa3)
// bICMfgCode   - код производителя микросхемы метки
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Блокировать EAS
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
// Предохраняет EAS от перезаписи
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bLockEAS     - код команды Lock EAS (всегда равен 0xa4)
// bICMfgCode   - код производителя микросхемы метки
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Прочитать EAS
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
// Читает EAS-последовательность, если бит EAS установлен в 1
//
// pReader      - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bFlags       - флаги запроса (см. ISO 15693-3 п.7.3.1)
// bEASAlarm    - код команды EAS Alarm (всегда равен 0xa5)
// pbUID        - ссылка на массив (8 байтов), в котором находится
//                уникальный идентификатор метки
// bICMfgCode   - код производителя микросхемы метки
// pbFlags      - ссылка на переменную типа BYTE, в которую будут
//                помещены флаги ответа (см. ISO 15693-3 п.7.4.1)
// pbEASData    - ссылка на массив (32 байта) для прочитанной 
//                EAS-последовательности
// pbErrorCode  - ссылка на переменную типа BYTE, в которую будет
//                помещен код ошибки (см. ISO 15693-3 п.7.4.2)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//         Н Е П О С Р Е Д С Т В Е Н Н Ы Й   О Б М Е Н   Д А Н Н Ы М И
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Обмен данными со считывателем
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_DirectIO_Reader( IN     LPVOID  pReader,
                                    IN     LPCBYTE pbSendBuffer, 
                                    IN     DWORD   dwSendLength, 
                                       OUT LPBYTE  pbRecvBuffer, 
                                    IN OUT LPDWORD pdwRecvLength );
//
// Передает считывателю команду и принимает ответ на нее
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbSendBuffer  - массив байтов, передаваемых считывателю
// dwSendLength  - количество передаваемых байтов
// pbRecvBuffer  - массив для ответа от считывателя
// pdwRecvLength - ссылка на переменную типа DWORD, которая перед вызовом
//                 функции должна содержать размер массива pbRecvBuffer, 
//                 а на выходе будет содержать количество принятых от
//                 считывателя байтов
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Непосредственный обмен данными с картой
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
// Осуществляет передачу данных карте без предварительной обработки и 
// последующий прием данных от карты, в том числе при выполнении команд 
// карте по протоколу ISO 14443-4 (T=CL)
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbSendBuffer  - массив байтов, передаваемых карте
// dwSendLength  - количество передаваемых в карту байтов
// dwTimeout     - величина таймаута карты в единицах (128 / 13,56)[мкс]
// pbRecvBuffer  - массив для ответа от карты
// pdwRecvLength - ссылка на переменную типа DWORD, которая перед вызовом
//                 функции должна содержать размер массива pbRecvBuffer, 
//                 а на выходе будет содержать количество принятых от
//                 карты байтов
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
//------------------------------------------------------------------------------
//  Обмен данными в формате APDU с контактной картой по ISO 7816
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_APDU_7816( IN     LPVOID  pReader,
                              IN     LPCBYTE pbSendBuffer, 
                              IN     DWORD   dwSendLength, 
                                 OUT LPBYTE  pbRecvBuffer, 
                              IN OUT LPDWORD pdwRecvLength );
//
// Осуществляет передачу команды 
// контактной карте и приём ответа от неё по протоколу ISO 7816
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbSendBuffer  - массив байтов, передаваемых контактной карте
// dwSendLength  - количество передаваемых в карту байтов
// pbRecvBuffer  - массив для ответа от контактной карты
// pdwRecvLength - ссылка на переменную типа DWORD, которая перед вызовом
//                 функции должна содержать размер массива pbRecvBuffer, 
//                 а на выходе будет содержать количество принятых от
//                 контактной карты байтов
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
*/
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//==============================================================================
//    К О Н Ф И Г У Р А Ц И Я   У С Т Р О Й С Т В   Н А   Ш И Н Е   R S 4 8 5
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Устройства на шине RS485 должны иметь разные адреса
// Адрес - это число от 0 до 255
// При создании интерфейса в качестве текущего устанавливается адрес 0
// На команду по адресу 0 считыватель отвечает независимо от своего адреса
// Команды по адресу 0 допустимы только в случае одного устройства на шине
// Перед обращением к другому устройству необходимо изменить адрес обмена
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Выдать адрес обмена
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_GetIOAddress( IN     LPVOID pReader,
                                    OUT LPBYTE pbIOAddr );
//
// Выдает адрес устройства, с которым производится обмен данными
//
// pReader  - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbIOAddr - адрес переменной типа unsigned char, в которую будет помещен
//            адрес  устройства, с которым производится обмен данными
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Установить адрес обмена
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_SetIOAddress( IN LPVOID pReader,
                                 IN BYTE   bIOAddr );
//
// Задает адрес устройства, с которым будет производиться обмен данными
// Значение адреса 0 допустимо лишь при условии, что на шине RS485
// находится только один считыватель
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bIOAddr  - адрес устройства, с которым будет производиться обмен данными
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Прочитать адрес устройства
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ReadDeviceAddress( IN     LPVOID pReader,
                                         OUT LPBYTE pbDevAddr );
//
// Выдает адрес устройства.
// Если адрес устройства неизвестен, необходимо оставить устройство на шине
// RS485 единственным, задать адрес обмена 0 (см. CLSCRF_SetIOAddress())
// и вызвать данную функцию.
//
// pReader   - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pbDevAddr - адрес переменной типа unsigned char, в которую будет помещен
//             адрес  устройства
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать адрес устройства
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_WriteDeviceAddress( IN LPVOID pReader,
                                       IN BYTE   bDevAddr );
//
// Задает устройству новый адрес и записывает его во flash-памяти
//
// pReader - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// bDevAddr - новый адрес устройства
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
//------------------------------------------------------------------------------
//  Аутентифицировать карту DESFire
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_DESFire_Authenticate( IN LPVOID pReader,
                                         IN DWORD  dwKeyNumber );
//
// Производит аутентификацию карты DESFire
//
// pReader     - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwKeyNumber - номер ключа DES от 0 до 31
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Ключ DES предварительно должен быть записан во flash-памяти,
// иначе ключ с номером 0 равен 0x0000000000000000,
// остальные ключи равны 0xFFFFFFFFFFFFFFFF
//
*/
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
//------------------------------------------------------------------------------
//  Записать во flash-память ключ AES
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_WriteFlash_AESKey( IN LPVOID pReader,
                                        IN DWORD  dwKeyNumber,
                                        IN LPBYTE pbK16,
                                        IN LPBYTE pbICV16 );
//
// Записывает во flash-память ключ AES
//
// pReader     - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwKeyNumber - номер ключа от 0 до 12
// pbK16       - массив ключа (не менее 16 байтов)
// pbICV16      - массив начального вектора CBC (не менее 16 байтов)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/
//==============================================================================
//                A E S ( С О  1 2 8 - Б И Т Н Ы М   К Л Ю Ч О М )
//==============================================================================
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Сохранить в зашифрованный файл ключи шифрования
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_SaveAESKeysToFile( IN LPSTR  lsFileName,
                                             IN LPBYTE pbIV, 
                                             IN LPBYTE pbKeys,  
                                             IN DWORD  dwKeysCount,
                                             IN LPSTR  lsPassword);
//
// Сохраняет в зашифрованный файл ключи шифрования
//      
// lsFileName  - имя файла, ASCII-строка, должна заканчиваться нулём
// pbIV        - массив из 16 байт - вектор инициализации для шифрования файла 
// pbKeys      - массив ключей, каждый ключ представляет из себя 16 байт в этом 
//               массиве
// dwKeysCount - количество ключей шифрования
// lsPassword  - пароль для шифрования файла, ASCII-строка, должна заканчиваться
//               нулём
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Cгенерировать и сохранить в зашифрованный файл псевдослучайные ключи шифрования
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_GenerateAndSaveAESKeysToFile( IN LPSTR  lsFileName,
                                                        IN DWORD  dwKeysCount,
                                                        IN LPSTR  lsPassword);
//
// Генерирует и сохраняет в зашифрованный файл псевдослучайные ключи шифрования
//       
// lsFileName  - имя файла, ASCII-строка, должна заканчиваться нулём
// dwKeysCount - количество ключей шифрования
// lsPassword  - пароль для шифрования файла, ASCII-строка, должна заканчиваться
//               нулём
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Загрузить из файла ключи шифрования
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_LoadAESKeysFromFile( IN LPVOID pReader,
                                               IN LPSTR  lsFileName,
                                               IN LPSTR  lsPassword,
                                               IN OUT LPDWORD ldKeysCount);
//
// Загружает из файла ключи шифрования
//       
// pReader     - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// lsFileName  - имя файла, ASCII-строка, должна заканчиваться нулём
// lsPassword    - пароль для расшифровки файла, ASCII-строка, должна заканчиваться
//               нулём
// ldKeysCount - количество ключей, которое требуется загрузить, а после операции - 
//               количество загруженных по факту ключей
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать во flash-память ключи AES
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_WriteFlash_AESKeys(  IN LPVOID pReader,
                                               IN DWORD  dwStartKey,
                                               IN DWORD  dwKeysCount );
//
// Записывает во flash-память ключи AES
//
// pReader     - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwStartKey  - номер первого ключа
// dwKeysCount - количество ключей (максимум 9)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Предварительно ключи должны быть загружены функцией 
// CLSCRF_Crypto_LoadAESKeysFromFile
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Установить режим обмена на стороне хоста
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_SetEncryptionMode(	IN LPVOID pReader,
												IN BOOL fEncryptionMode );
//
// Принудительно устанавливает режим обмена на стороне хоста. 
// Вызывается в случае, если считыватель вышел в открытый режим обмена.
//
// pReader			- ссылка на объект-интерфейс (см. функцию CLSCRF_Create );
// fEncryptionMode  - режим обмена (1 - шифрованный, 0 - открытый)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Прочитать режим обмена на стороне хоста
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_GetEncryptionMode(	IN LPVOID pReader,
												OUT PBOOL pfEncryptionMode );
//
// Считывает текущий режим обмена на стороне хоста. 
//
// pReader			- ссылка на объект-интерфейс (см. функцию CLSCRF_Create );
// pfEncryptionMode - указатель на переменную типа BOOL, в которую будет
//					  помещён прочитанный режим обмена 
//					  (1 - шифрованный, 0 - открытый)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Прочитать количество ключей в массиве
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_GetAESKeysCount(	IN LPVOID pReader,
											OUT LPDWORD pdwKeysCount);
//
// Производит идентификацию хоста и считывателя и устанавливает режим шифрованного 
// обмена при успешной аутентификации
//
// pReader     - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pdwKeysCount - указатель на переменную, куда будет записано количество 
//				  загруженных ключей во flash-памяти считывателя
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Ключи должны быть загружены функцией
// CLSCRF_Crypto_LoadAESKeysFromFile до
// вызова CLSCRF_Crypto_AuthenticateReader
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Прочитать ключ из массива
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_GetAESKey( IN  LPVOID	pReader,
                                     IN  DWORD	dwKeyIndex,
                                     OUT LPBYTE	lpKey);
//
// Производит чтение ключа по указанному индексу из массива ключей,
// полученного командой CLSCRF_Crypto_LoadAESKeysFromFile
//
// pReader    - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwKeyIndex - номер ключа во flash-памяти считывателя
// lpKey	  - указатель на массив из 16 байт, куда будет записан ключ
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Ключи должны быть загружены функцией
// CLSCRF_Crypto_LoadAESKeysFromFile до
// вызова CLSCRF_Crypto_GetAESKey
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Провести аутентификацию считывателя
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_Crypto_AuthenticateReader(	IN LPVOID pReader,
												IN BYTE ucAuthType,
												IN DWORD dwKeyNumber );
//
// Производит идентификацию хоста и считывателя и устанавливает режим шифрованного 
// обмена при успешной аутентификации
//
// pReader     - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucAuthType  - тип операции (0x00 - сброс аутентификации, 0x01 - аутентификация)
// dwKeyNumber - номер ключа во flash-памяти считывателя
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
// Ключи должны быть загружены функцией
// CLSCRF_Crypto_LoadAESKeysFromFile до
// вызова CLSCRF_Crypto_AuthenticateReader
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Очистить flash
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_EraseFlash(	IN LPVOID pReader );
//
// Очищает flash для последующей записи
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Записать во flash блок по указанному адресу
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_WriteFlashValue(	IN LPVOID pReader,
									IN DWORD  dwAddress,
									IN LPBYTE  pbValue );
//
// Записать во flash блок (16 байт) по указанному адресу
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwAddress	 - адрес блока во flash
// pbValue       - указатель на блок (16 байт)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Проверка заполненности блока flash-памяти считывателя
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_CheckFlashValueFilled( IN LPVOID pReader,
										  IN DWORD  dwFlashAddr,
										  OUT LPBYTE pbStatus );
//
// Проверка заполненности блока flash-памяти считывателя
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwFlashAddr	 - адрес блока данных во flash
// pbStatus      - 0x00: элемент массива flash заполнен; 
//                 0xFF: элемент массива flash свободен.
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Прочитать из flash блок данных по указанному адресу
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ReadFlashValue(	IN LPVOID pReader,
									IN DWORD  dwAddress,
									OUT LPBYTE  pbValue );
//
// Прочитать из flash блок данных (16 байт) по указанному адресу
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwAddress	 - адрес блока данных во flash
// pbValue       - указатель на блок данных (16 байт)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Активировать режим T=CL: получение доступных скоростей карты
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ISO14443A_4_RATS(	IN LPVOID pReader,
										IN BYTE  ucCID,
										OUT LPBYTE  pbATS );
//
// Передает карте команду RATS, получает от нее список доступных скоростей 
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucCID		 - идентификатор карты (любое значение от 0 до 14)
// pbATS         - принятый ATS карты
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Активировать режим T=CL: установка скорости работы с картой
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_ISO14443A_4_PPS( IN LPVOID pReader,
								   IN BYTE  ucCID,
								   IN BYTE  ucBaudrate );
//
// Передает карте команду PPS, устанавливает скорость обмена и режим T=CL
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucCID		 - идентификатор карты (любое значение от 0 до 14)
// ucBaudrate    - устанавливаемая скорость обмена с картой
//  биты 3-2   - устанавливаемая скорость приема в режимах ISO 14443
//               (поток данных от карты к считывателю):
//               00 - 106 кбод
//               01 - 212 кбод
//               10 - 424 кбод
//               11 - 848 кбод
//  биты 1-0   - устанавливаемая скорость передачи в режимах ISO 14443
//               (поток данных от считывателя к карте):
//               00 - 106 кбод
//               01 - 212 кбод
//               10 - 424 кбод
//               11 - 848 кбод
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Запись информации персонализации
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_WritePerso(	IN LPVOID pReader,
											IN BYTE  ucValueType,
											IN BYTE  ucSectorNumber,
											IN BYTE  ucBlockNumber,
											IN DWORD dwValueFlashAddress );
//
// Записывает данные персонализации в карту
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucValueType   - тип записываемого значения (см. таблицу)
// ucSectorNumber- номер сектора (используется при записи блока данных или ключа, 
//                 относящегося к определенному сектору)
// ucBlockNumber - номер блока (используется при записи блока данных или ключа, 
//                 относящегося к определенному блоку в секторе)
// dwValueFlashAddress - адрес блока во flash считывателя, откуда следует 
//				   взять данные для записи
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Запись информации персонализации в виде открытых данных
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_WritePersoExplicit(	IN LPVOID pReader,
													IN BYTE  ucValueType,
													IN BYTE  ucSectorNumber,
													IN BYTE  ucBlockNumber,
													IN LPBYTE pData );
//
// Записывает переданный блок данных персонализации в карту
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucValueType   - тип записываемого значения (см. таблицу)
// ucSectorNumber- номер сектора (используется при записи блока данных или ключа, 
//                 относящегося к определенному сектору)
// ucBlockNumber - номер блока (используется при записи блока данных или ключа, 
//                 относящегося к определенному блоку в секторе)
// pData		 - данные блока для записи
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Завершение персонализации
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_CommitPerso(	IN LPVOID pReader );
//
// Завершает персонализацию карты
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Аутентификация
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
// Выполняет первичную аутентификацию карты
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucAuthType     - тип аутентификации (см. таблицу)
// ucKeyType     - тип ключа для аутентификации (см. таблицу)
// ucSectorNumber- номер сектора для аутентификации
// dwKeyFlashAddress - адрес ключа во flash считывателя для аутентификации
// ucLenCap      - длина блока характеристик считывателя (0..6, установить в 0)
// pbPcdCap      - блок характеристик считывателя (пока отсутствует)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Чтение нескольких блоков SL2
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_MultiBlockRead(	IN LPVOID pReader,
												IN BYTE ucSectorNumber,
												IN BYTE ucBlockNumber,
												IN BYTE ucBlocksCount,
												OUT LPBYTE pbData );
//
// Для карты в режиме SL2, производит множественное чтение блоков
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucSectorNumber - номер сектора
// ucBlockNumber - номер блока, с которого нужно начинать чтение
// ucBlocksCount - количество читаемых блоков
// pbData		 - указатель на байтовый массив, в который будут записаны данные
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Запись нескольких блоков SL2
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_MultiBlockWrite(	IN LPVOID pReader,
												IN BYTE ucSectorNumber,
												IN BYTE ucBlockNumber,
												IN BYTE ucBlocksCount,
												IN LPBYTE pbData );
//
// Для карты в режиме SL2, производит множественную запись блоков
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucSectorNumber - номер сектора
// ucBlockNumber - номер начального блока для записи
// ucBlocksCount - количество записываемых блоков
// pbData		 - указатель на байтовый массив с данными для записи
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Чтение данных
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
// Для карты в режиме SL3, производит чтение данных
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucEncryptionMode - режим защиты данных (см. таблицу)
// ucValueType   - тип читаемого значения (см. таблицу 117 в руководстве MifarePlus)
// ucSectorNumber - номер сектора с читаемым блоком
// ucBlockNumber - номер начального блока для чтения
// ucBlocksCount - количество читаемых блоков
// pbData		 - указатель на байтовый массив, в который будут записаны данные
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Запись данных
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
// Для карты в режиме SL3, производит запись данных
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucEncryptionMode - режим защиты данных (см. таблицу)
// ucValueType   - тип записываемого значения (см. таблицу 117 в руководстве MifarePlus)
// ucSectorNumber - номер сектора для записи
// ucBlockNumber - номер начального блока для записи
// ucBlocksCount - количество записываемых блоков
// pbData		 - указатель на байтовый массив с данными для записи
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Увеличение счетчика
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_Increment(	IN LPVOID pReader,
											IN BYTE ucEncryptionMode,
											IN BYTE ucSourceSectorNumber,
											IN BYTE ucSourceBlockNumber,
											IN DWORD dwValue );
//
// Для карты в режиме SL3, производит увеличение значения счетчика
// и последующую запись увеличенного значения в буфер переноса (Transfer Buffer) 
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucEncryptionMode - режим защиты данных (см. таблицу)
// ucSourceSectorNumber - номер исходного сектора
// ucSourceBlockNumber - номер исходного блока
// dwValue		 - прибавляемое к счетчику значение
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Уменьшение счетчика
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_Decrement(	IN LPVOID pReader,
											IN BYTE ucEncryptionMode,
											IN BYTE ucSourceSectorNumber,
											IN BYTE ucSourceBlockNumber,
											IN DWORD dwValue );
//
// Для карты в режиме SL3, производит уменьшение значения счетчика
// и последующую запись уменьшенного значения в буфер переноса (Transfer Buffer) 
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucEncryptionMode - режим защиты данных (см. таблицу)
// ucSourceSectorNumber - номер исходного сектора
// ucSourceBlockNumber - номер исходного блока
// dwValue		 - вычитаемое из счетчика значение
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Запись данных буфера переноса
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_Transfer(	IN LPVOID pReader,
										IN BYTE ucEncryptionMode,
										IN BYTE ucDestinationSectorNumber,
										IN BYTE ucDestinationBlockNumber);
//
// Для карты в режиме SL3, записывает данные буфера переноса (Transfer Buffer) 
// в указанный блок
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucEncryptionMode - режим защиты данных (см. таблицу)
// ucDestinationSectorNumber - номер сектора для записи
// ucDestinationBlockNumber - номер блока для записи
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Увеличение счетчика и запись данных буфера переноса
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
// Для карты в режиме SL3, производит увеличение значения счетчика,
// запись увеличенного значения в буфер переноса (Transfer Buffer) и затем
// в указанный блок
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucEncryptionMode - режим защиты данных (см. таблицу)
// ucSourceSectorNumber - номер исходного сектора
// ucSourceBlockNumber - номер исходного блока
// ucDestinationSectorNumber - номер сектора для записи
// ucDestinationBlockNumber - номер блока для записи
// dwValue		 - прибавляемое к счетчику значение
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Уменьшение счетчика и запись данных буфера переноса
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
// Для карты в режиме SL3, производит уменьшение значения счетчика,
// запись уменьшенного значения в буфер переноса (Transfer Buffer) и затем
// в указанный блок
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucEncryptionMode - режим защиты данных (см. таблицу)
// ucSourceSectorNumber - номер исходного сектора
// ucSourceBlockNumber - номер исходного блока
// ucDestinationSectorNumber - номер сектора для записи
// ucDestinationBlockNumber - номер блока для записи
// dwValue		 - вычитаемое из счетчика значение
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Запись данных блока-значения в буфер переноса (Transfer Buffer)
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_Restore(	IN LPVOID pReader,
										IN BYTE ucEncryptionMode,
										IN BYTE ucSourceSectorNumber,
										IN BYTE ucSourceBlockNumber );
//
// Для карты в режиме SL3, производит запись значения указанного блока-значения
// в буфер переноса (Transfer Buffer) 
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// ucEncryptionMode - режим защиты данных (см. таблицу)
// ucSourceSectorNumber - номер исходного сектора
// ucSourceBlockNumber - номер исходного блока
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Запрос поддержки виртуальных карт
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_VirtualCardSupport(	IN LPVOID pReader,
													IN LPBYTE  pIID );
//
// Передает карте очередной идентификатор инфраструктуры
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pIID - идентификатор инфраструктуры (16 байт)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Заключительный запрос поддержки виртуальных карт
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
// Передает карте последний идентификатор инфраструктуры, а также собственные 
// характеристики и принимает характиристики карты
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// pIID - идентификатор инфраструктуры (16 байт)
// dwKencFlashAddress - адрес ключа VC Polling ENC Key во flash считывателя
// dwKmacFlashAddress - адрес ключа VC Polling MAC Key во flash считывателя
// ucLenCap      - длина блока характеристик считывателя (0..3, установить в 0)
// pbPcdCap      - блок характеристик считывателя (пока отсутствует)
// pucInfo		 - указатель на байтовую переменную, в которую будет записана
//				   информация о карте (0x83 - 4-байтовый UID, 0x80 - 7-байтовый UID)
// pPiccCap		 - указатель на буфер (2 байта), в который будут записаны
//				   характеристика карты
// pPaddedUID	 - указатель на буфер (13 байт), в который будет записан UID карты
//					а также байты паддировки (общим размером 13 байт)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Выбирает виртуальную карту
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_VirtualCardSelect(	IN LPVOID pReader,
													IN DWORD dwKselFlashAddress,
													IN PBYTE pPiccCap,
													IN PBYTE pPaddedUID);
//
// Выбирает виртуальную карту 
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwKselFlashAddress - адрес ключа Select VC Key во flash считывателя
// pPiccCap		 - указатель на буфер (2 байта), из которого будут читаться
//				   характеристика карты
// pPaddedUID	 - указатель на буфер (13 байт), из которого будет взят UID карты
//					а также байты паддинга (общим размером 13 байт)
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Отменяет выбор виртуальной карты
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_VirtualCardDeselect(	IN LPVOID pReader );
//
// Отменяет выбор виртуальной карты
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Plus: Производит проверку близости карты
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifarePlus_ProximityCheck(	IN LPVOID pReader,
												IN DWORD dwKproxFlashAddress );
//
// Проверяет, достаточно ли близко от считывателя расположена карта - защита от релейных атак
//
// pReader       - ссылка на объект-интерфейс (см. функцию CLSCRF_Create )
// dwKproxFlashAddress - адрес ключа Proximity Check Key во flash считывателя
//
// Возвращаемое значение:  0   - успешное выполнение
//                       иначе - ошибка при выполнении
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX







//------------------------------------------------------------------------------
//  Mifare Des Fire: Производит аутентификацию карты
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_Authenticate(	IN LPVOID pReader,
												IN BYTE ucAuthType,
												IN PBYTE pKey,
												IN BYTE ucKeyNumber );
//
//Производит аутентификацию (карты или приложения) указанного типа и с указанным ключём.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucAuthType – тип аутентификации (0x00 – DES, 0x01 – 3DES, 0x02 – 3K3DES, 0x03 - AES);
//pKey – указатель на массив байт, содержащий ключ (8 – 24 байта);
//ucKeyNumber – номер ключа на карте, который будет использован при аутентификации.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Устанавливает формат обмена считыватель - карта
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_SetTransferType(	IN LPVOID pReader,
													IN BYTE ucTransferType );
//
//Устанавливает формат обмена считыватель - карта.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucTransferType – тип передачи данных (0x00 – открытая, 0x01 – MAC, 0x03 - шифрованная).
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Меняет параметры мастер-ключа для текущего приложения
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_ChangeKeySettings(	IN LPVOID pReader,
													IN CLSCRF_DESFIRE_MASTER_KEY_SETTINGS* pMasterKeySettings );
//
//Меняет параметры мастер-ключа для текущего приложения.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pMasterKeySettings – указатель на структуру CLSCRF_DESFIRE_MASTER_KEY_SETTINGS с параметрами ключа.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает параметры мастер-ключа для текущего приложения
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetKeySettings(	IN LPVOID pReader,
													OUT CLSCRF_DESFIRE_MASTER_KEY_SETTINGS_AND_LENGTH* pKeyData );
//
//Считывает параметры мастер-ключа для текущего приложения.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pKeyData – указатель на структуру CLSCRF_DESFIRE_MASTER_KEY_SETTINGS_AND_LENGTH, в которую будут записаны считанные параметры мастер-ключа.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Меняет ключ в текущем приложении
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_ChangeKey(	IN LPVOID pReader,
											IN CLSCRF_DESFIRE_KEY_DATA* pKeyData );
//
//Меняет ключ в текущем приложении.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pKeyData – указатель на структуру CLSCRF_DESFIRE_KEY_DATA, в которой хранятся параметры нового ключа.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает версию ключа
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetKeyVersion(	IN LPVOID pReader,
												IN BYTE ucKeyNumber,
												OUT PBYTE pucKeyVersion );
//
//Считывает версию ключа.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucKeyNumber – номер ключа карты;
//pucKeyVersion – указатель на переменную, в которую будет записана версия ключа.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Создаёт приложение
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
//Создаёт приложение.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pAID – указатель на массив (3 байта), содержащий номер создаваемого приложения;
//pKeySett1– указатель на структуру CLSCRF_DESFIRE_APPLICATION_MASTER_KEY_SETTINGS, содержащую параметры мастер-ключа приложения;
//pKeySett2– указатель на структуру CLSCRF_DESFIRE_NEW_APPLICATION_KEY_SETTINGS, содержащую параметры ключей приложения;
//pIsoFileID – указатель на массив (2 байта), ISO-идентификатор файла (NULL, если не использовать);
//pIso7816DfName – указатель на массив (размером iIso7816DfNameLength), содержащий ISO7816 Df-имя создаваемого приложения (NULL, если не использовать);
//iIso7816DfNameLength – размер ISO7816 Df-имени создаваемого приложения в байтах.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Удаляет приложение
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_DeleteApplication(	IN LPVOID pReader,
													IN PBYTE pAID );
//
//Удаляет приложение.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pAID – указатель на массив (3 байта), содержащий номер удаляемого приложения.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает идентификаторы приложений на карте
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetApplicationIDs(	IN LPVOID pReader,
													OUT PBYTE pAIDs,
													OUT PBYTE pucApplicationsCount);
//
//Считывает идентификаторы приложений на карте.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pAIDs – указатель на массив, в который будут последовательно записаны 3-байтовые идентификаторы приложений;
//pucApplicationsCount – указатель на переменную, в которую будет записано количество имеющихся на карте приложений.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает Df-имена приложений карты
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetDFNames(	IN LPVOID pReader,
												OUT CLSCRF_DESFIRE_DFNAME* pDFNames,
												OUT PBYTE pDFNamesCount );
//
//Считывает Df-имена приложений карты.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pDFNames – указатель на массив, в который будут последовательно записаны структры CLSCRF_DESFIRE_DFNAME, содержащие Df-имена приложений;
//pucDFNamesCount – указатель на переменную, в которую будет записано количество имеющихся на карте приложений с Df-именами.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Переключает текущее приложение карты
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_SelectApplication(	IN LPVOID pReader,
													IN PBYTE pAID );
//
//Переключает текущее приложение карты.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pAID – указатель на массив (3 байта), содержащий номер приложения.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Форматирование карты
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_FormatPICC(	IN LPVOID pReader );
//
//Форматирование карты (требуется предварительная аутентификация мастер-ключём карты).
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает информацию о карте
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetVersion(	IN LPVOID pReader,
												OUT CLSCRF_DESFIRE_HW_SW_INFO* pHWInfo,
												OUT CLSCRF_DESFIRE_HW_SW_INFO* pSWInfo,
												OUT CLSCRF_DESFIRE_MORE_INFO* pMoreInfo );
//
//Считывает информацию о карте.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pHWInfo – указатель на структуру CLSCRF_DESFIRE_HW_SW_INFO, в которую будет записана информация по Hardware карты;
//pSWInfo – указатель на структуру CLSCRF_DESFIRE_HW_SW_INFO, в которую будет записана информация по Software карты;
//pMoreInfo – указатель на структуру CLSCRF_DESFIRE_MORE_INFO, в которую будет записана дополнительная информация по версии карты.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Освобождает память карты
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_FreeMemory(	IN LPVOID pReader,
												OUT PDWORD pdwMemSize );
//
//Освобождает память карты.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pdwMemSize – указатель на переменную, в которую будет записан размер памяти карты.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Устанавливает конфигурацию карты
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_SetConfiguration(	IN LPVOID pReader,
                                                    IN CLSCRF_DESFIRE_CONFIGURATION* pCfg );
//
//Устанавливает конфигурацию карты.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pCfg – указатель на структуру CLSCRF_DESFIRE_CONFIGURATION, содержащую устанавливаемые параметры конфигурации.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает UID карты
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetCardUID(	IN LPVOID pReader,
												OUT PBYTE pUID );
//
//Считывает UID карты.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pUID – указатель на массив байт, к который будет записан UID карты.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает номера файлов в текущем приложении
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetFileIDs(	IN LPVOID pReader,
												OUT PBYTE pFileIDs,
												OUT PBYTE pucFilesCount );
//
//Считывает номера файлов в текущем приложении.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pFileIDs – указатель на массив байт, в котрый будут последовательно записаны номера файлов (1 байт на каждый) в текущем приложении;
//pucFilesCount – указатель на переменную, в которую будет записано количество файлов в текущем приложении.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает ISO-номера файлов в текущем приложении
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetISOFileIDs(	IN LPVOID pReader,
												OUT PWORD pISOFileIDs,
												OUT PBYTE pucFilesCount );
//
//Считывает ISO-номера файлов в текущем приложении.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//pISOFileIDs – указатель на массив байт, в котрый будут последовательно записаны ISO-номера файлов (2 байта на каждый) в текущем приложении;
//pucFilesCount – указатель на переменную, в которую будет записано количество файлов, имеющих ISO-идентификатор, в текущем приложении.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает паметры указанного файла
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetFileSettings(	IN LPVOID pReader,
													IN BYTE ucFileNumber,
													OUT CLSCRF_DESFIRE_FILE_SETTINGS* pFileSettings );
//
//Считывает паметры указанного файла.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//pFileSettings – указатель на структуру CLSCRF_DESFIRE_FILE_SETTINGS, в которую будут записаны параметры файла.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Изменяет параметры указанного файла
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_ChangeFileSettings(	IN LPVOID pReader,
														IN BYTE ucFileNumber,
														IN BYTE ucCommSettings,
														IN CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS* pAccessRights );
//
//Изменяет параметры указанного файла.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//ucCommSettings – настройки канала обмена (0x00 – открытый, 0x01 – MAC, 0x03 - шифрованный);
//pAccessRights – указатель на структуру CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, содержащую настройки доступа.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Создаёт стандартный файл данных
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
//Создаёт стандартный файл данных.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//pISOFileID – указатель на массив, содержащий ISO-номер файла (2 байта, если NULL, то пропускается);
//ucCommSettings – настройки канала обмена (0x00 – открытый, 0x01 – MAC, 0x03 - шифрованный);
//pAccessRights – указатель на структуру CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, содержащую настройки доступа;
//dwFileSize – размер файла.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Создаёт файл данных с резервным хранилищем
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
//Создаёт файл данных с резервным хранилищем.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//pISOFileID – указатель на массив, содержащий ISO-номер файла (2 байта, если NULL, то пропускается);
//ucCommSettings – настройки канала обмена (0x00 – открытый, 0x01 – MAC, 0x03 - шифрованный);
//pAccessRights – указатель на структуру CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, содержащую настройки доступа;
//dwFileSize – размер файла.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Создаёт файл значения с резервным хранилищем
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
//Создаёт файл значения с резервным хранилищем.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//ucCommSettings – настройки канала обмена (0x00 – открытый, 0x01 – MAC, 0x03 - шифрованный);
//pAccessRights – указатель на структуру CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, содержащую настройки доступа;
//dwLowerLimit – нижний предел значения;
//dwUpperLimit – верхний предел значения;
//dwValue – начальное значение;
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Создаёт линейный файл записей с резервным хранилищем
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
//Создаёт линейный файл записей с резервным хранилищем.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//pISOFileID – указатель на массив, содержащий ISO-номер файла (2 байта, если NULL, то пропускается);
//ucCommSettings – настройки канала обмена (0x00 – открытый, 0x01 – MAC, 0x03 - шифрованный);
//pAccessRights – указатель на структуру CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, содержащую настройки доступа;
//dwRecordSize – размер записи;
//dwMaxNumOfRecords – максимальное количество записей.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Создаёт циклический файл записей с резервным хранилищем
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
//Создаёт циклический файл записей с резервным хранилищем.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//pISOFileID – указатель на массив, содержащий ISO-номер файла (2 байта, если NULL, то пропускается);
//ucCommSettings – настройки канала обмена (0x00 – открытый, 0x01 – MAC, 0x03 - шифрованный);
//pAccessRights – указатель на структуру CLSCRF_DESFIRE_FILE_ACCESS_RIGHTS, содержащую настройки доступа;
//dwRecordSize – размер записи;
//dwMaxNumOfRecords – максимальное количество записей.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Удаляет файл
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_DeleteFile(	IN LPVOID pReader,
												IN BYTE ucFileNumber );
//
//Удаляет файл.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает данные из файла данных
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
//Считывает данные из файла данных.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//dwOffset – адрес начального байта;
//dwLength – количество считываемых байт;
//pData – указатель на массив байт, в который будут считаны данные;
//pdwDataLength – указатель на переменную, в которую будет записано количество считанных байт.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Записывает данные в файл данных
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_WriteData(	IN LPVOID pReader,
											IN BYTE ucFileNumber,
											IN DWORD dwOffset,
											IN DWORD dwLength,
											IN PBYTE pData );
//
//Записывает данные в файл данных.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//dwOffset – адрес начального байта;
//dwLength – количество записываемых байт;
//pData – указатель на массив байт, содержащий записываемые данные.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает значение из файла-значения
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_GetValue(	IN LPVOID pReader,
											IN BYTE ucFileNumber,
											OUT PDWORD pdwValue);
//
//Считывает значение из файла-значения.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//pdwValue – указатель на переменную, в которую будет записано считанное значение.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Увеличивает значение в файле-значении на заданную величину
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_Credit(	IN LPVOID pReader,
											IN BYTE ucFileNumber,
											IN DWORD dwValue );
//
//Увеличивает значение в файле-значении на заданную величину.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//dwValue – значение, на которое нужно увеличить значение (простите за тафталогию).
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Уменьшает значение в файле-значении на заданную величину
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_Debit(	IN LPVOID pReader,
										IN BYTE ucFileNumber,
										IN DWORD dwValue );
//
//Уменьшает значение в файле-значении на заданную величину.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//dwValue – значение, на которое нужно уменьшить значение (простите за тафталогию).
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Ограниченно увеличивает значение в файле-значении на заданную величину
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_LimitedCredit(	IN LPVOID pReader,
												IN BYTE ucFileNumber,
												IN DWORD dwValue );
//
//Ограниченно увеличивает значение в файле-значении на заданную величину.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//dwValue – значение, на которое нужно увеличить значение (простите за тафталогию).
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Записывает данные в файл записей
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_WriteRecord(	IN LPVOID pReader,
												IN BYTE ucFileNumber,
												IN DWORD dwOffset,
												IN DWORD dwLength,
												IN PBYTE pData );
//
//Записывает данные в файл записей.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//dwOffset – адрес начального байта;
//dwLength – количество записываемых байт;
//pData – указатель на массив байт, содержащий записываемые данные.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Считывает данные из файла записей
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
//Считывает данные из файла записей.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла;
//dwRecordOffset – адрес начальной записи;
//dwRecordsCount – количество считываемых записей;
//dwRecordSize – размер считываемой записи;
//pData – указатель на массив байт, в который будут считаны данные;
//pdwDataLength – указатель на переменную, в которую будет записано количество считанных байт.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Очищает файл записей
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_ClearRecordFile(	IN LPVOID pReader,
													IN BYTE ucFileNumber );
//
//Очищает файл записей.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create);
//ucFileNumber – номер файла.
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Копирует данные из резервного буфера файла в основной
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_CommitTransaction(	IN LPVOID pReader );
//
//Копирует данные из резервного буфера файла в основной.
//
//pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
//
//Возвращаемое значение:  0   – успешное выполнение,
//  иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  Mifare Des Fire: Копирует данные из основного буфера файла в резервный
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_MifareDesFire_AbortTransaction(	IN LPVOID pReader );
//
// Копирует данные из основного буфера файла в резервный.
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX




//------------------------------------------------------------------------------
//  NFC663: Активация устройства
//------------------------------------------------------------------------------
//
/**
* Значения DRI/DSI (BRI/BSI)
*/
/*@{*/
#define PHPAL_I18092MPI_DATARATE_106   0x00U   /**< Значение DRI/DSI для 106 kBit/s. */
#define PHPAL_I18092MPI_DATARATE_212   0x01U   /**< Значение DRI/DSI для 212 kBit/s. */
#define PHPAL_I18092MPI_DATARATE_424   0x02U   /**< Значение DRI/DSI для 424 kBit/s. */
/*@}*/

/**
* Значения FSL/LRI
*/
/*@{*/
#define PHPAL_I18092MPI_FRAMESIZE_64   0x00U   /**< Значение FSL для макс. размера кадра в 64 байта.  */
#define PHPAL_I18092MPI_FRAMESIZE_128  0x01U   /**< Значение FSL для макс. размера кадра в 128 байт. */
#define PHPAL_I18092MPI_FRAMESIZE_192  0x02U   /**< Значение FSL для макс. размера кадра в 192 байта. */
#define PHPAL_I18092MPI_FRAMESIZE_254  0x03U   /**< Значение FSL для макс. размера кадра в 254 байта. */
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
// Выполняет команды ISO18092 ATR и PSL.
// Nfcid3i	- массив из 10 байт: при начальной скорости в 106kbps - NFCID3,
//			  генерируется случайным образом;
//			  при скоростях 212/424kbps - байты 0-7 соответствуют NFCID2, 
//			  а байты 8-9 должны быть установлены в 0.
// Did		- идентификатор устройства, "0" - не использовать, либо 1-14
// NadEnable- включение использования адреса шины, для включения установить НЕ в "0"
// Nad		- адрес узла: игнорируется, если bNadEnabled = 0
// Dsi		- индекс делителя отправки (от цели к инициатору) 0-2
// Dri		- индекс делителя приема (от инициатора к цели) 0-2
// Fsl		- байт длины кадра 0-3
// GiLength	- количество байт общей информации.
// Gi		- опционально, байты общей информации
// pbATR	- буфер, куда будут записаны байты ATR (ответа с атрибутаи), 
//			  должен быть не меньше 64 байт
// pdwATRLength - длина считанных атрибутов в байтах
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Отмена выбора
//------------------------------------------------------------------------------
//
/**
* Значения параметра bDeselectCommand
*/
/*@{*/
#define PHPAL_I18092MPI_DESELECT_DSL   0x08U   /**< DSL отправляется для отмена выбора цели. */
#define PHPAL_I18092MPI_DESELECT_RLS   0x0AU   /**< RLS отправляется для отмены выбора цели. */
/*@}*/
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_Deselect(	IN  LPVOID  pReader,
									IN	BYTE	DeselectCommand );/**< [In] Request to send, either #PHPAL_I18092MPI_DESELECT_DSL or #PHPAL_I18092MPI_DESELECT_RLS. */
// Отмена выбора цели ISO18092 путем отправки запросов DSL либо RLS.
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
// DeselectCommand - запрос на отправку, PHPAL_I18092MPI_DESELECT_DSL, 
//					 либо PHPAL_I18092MPI_DESELECT_RLS
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Обмен
//------------------------------------------------------------------------------
//
/** Опции команды Exchange
*/
/*@{*/
/**
Режим обмена по умолчанию.
Для выполнения буферизации комбинируйте 
с PH_EXCHANGE_BUFFERED_BIT и PH_EXCHANGE_LEAVE_BUFFER_BIT
Специфично для ISO14443-4:
Выполняет цепочную передачу Tx/Rx с картой.
Возвращает PH_ERR_SUCCESS_CHAINING, если RxBuffer полон и не отправляет 
подтверждение (ACK) для последнего принятого блока.
*/
#define PH_EXCHANGE_DEFAULT             0x0000U

/**
Специфично для ISO14443-4:
Передает данные в карту цепочной передачей.
Кобинируется с PH_EXCHANGE_BUFFERED_BIT и PH_EXCHANGE_LEAVE_BUFFER_BIT 
для выполнения буферизации.
Не принимает никаких данных.
*/
#define PH_EXCHANGE_TXCHAINING          0x0001U

/**
Специфично для ISO14443-4:
Начинает передачу с блоком R(ACK) и выполняет цепочную передачу Rx с картой.
Возвращает PH_ERR_SUCCESS_CHAINING, если RxBuffer полон и не подтверждает (ACK)
последний принятый блок.
*/
#define PH_EXCHANGE_RXCHAINING          0x0002U

/**
Специфично для ISO14443-4:
Начинает передачу с блоком R(ACK) и выполняет цепочную передачу Rx с картой.
Завершает цепочную передачу Rx с картой, если RxBuffer полон.
*/
#define PH_EXCHANGE_RXCHAINING_BUFSIZE  0x0003U

/** Маска для режимов выше. Все остальные биты зарезервированы. */
#define PH_EXCHANGE_MODE_MASK           0x000FU

/**
Не производит очистки внутреннего буфера перед выполнением операции.
Если этот бит установлен и данные переданы,
то содержимое внутреннего буфера отправляются в первую очередь.
*/
#define PH_EXCHANGE_LEAVE_BUFFER_BIT    0x4000U

/**
Буферизует Tx-Data во внутренний буфер вместо его передачи.
*/
#define PH_EXCHANGE_BUFFERED_BIT        0x8000U

/**
Введенные данные являются первой частью потока.
(Определение помощника для буферизации).
*/
#define PH_EXCHANGE_BUFFER_FIRST   (PH_EXCHANGE_DEFAULT | PH_EXCHANGE_BUFFERED_BIT)

/**
Введенные данные являются следующей частью потока.
(Определение помощника для буферизации).
*/
#define PH_EXCHANGE_BUFFER_CONT    (PH_EXCHANGE_DEFAULT | PH_EXCHANGE_BUFFERED_BIT | PH_EXCHANGE_LEAVE_BUFFER_BIT)

/**
Введенные данные являются последней частью потока.
(Определение помощника для буферизации).
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
// Выполняет обмен данными ISO18092 с целью.
//
// pReader  – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
// dwOption	- параметр опций
// pbSendBuffer - буфер с данными для передачи
// dwSendLength - количество байт для передачи
// pbRecvBuffer - буфер для размещения принятых байт
// pdwRecvLength - количество принятых байт
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Сброс протокола
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_ResetProtocol(	IN  LPVOID  pReader );
// Сбрасывает параметры протокола ISO18092.
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Запрос атрибутов
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
// Выполняет команду ISO18092 "Attribute Request".
//
// pReader  – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
// Nfcid3i	- массив из 10 байт, генерируется случайным образом при начальной 
//			  скорости в 106kbps, либо соответствует NFCID2 при скоростях 212/424kbps
// Did		- идентификатор устройства, "0" - не использовать, либо 1-14
// NadEnable- включение использования адреса шины, для включения установить НЕ в "0"
// Nad		- адрес узла: игнорируется, если bNadEnabled = 0
// Fsl		- байт длины кадра 0-3
// GiLength	- количество байт общей информации, не превышает PHPAL_I18092MPI_MAX_GI_LENGTH.
// Gi		- опционально, байты общей информации
// pbATR	- буфер, куда будудт записаны байты ATR (ответа с атрибутаи), 
//			  должен быть не меньше 64 байт
// pdwATRLength - длина считанных атрибутов в байтах
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Выбор параметров
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_ParameterSelect(	IN  LPVOID  pReader,
											IN	BYTE	Dsi,/**< [In] Divisor Send (target to initiator) Integer; 0-2 */
											IN	BYTE	Dri,/**< [In] Divisor Receive (initiator to target) Integer; 0-2 */
											IN	BYTE	Fsl );/**< [In] Frame Length Byte; 0-3  */
// Выполняет команду ISO18092 "Parameter Select".
//
// pReader	– ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
// Dsi		- индекс делителя отправки (от цели к инициатору) 0-2
// Dri		- индекс делителя приема (от инициатора к цели) 0-2
// Fsl		- байт длины кадра 0-3
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Проверка присутствия
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_PresenceCheck(	IN  LPVOID  pReader );
// Выполняет проверку присутствия для текущей цели.
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Установка конфигурации
//------------------------------------------------------------------------------
//
/**
* Параметры режима пассивного инициатора ISO18092 ucParameterNumber
*/
/*@{*/
/**
* Задать / получить номер пакета
*/
#define PHPAL_I18092MPI_CONFIG_PACKETNO          0x0000U
/**
* Задать / получить идентификатор устройства
*/
#define PHPAL_I18092MPI_CONFIG_DID               0x0001U
/**
* Задать / получить адрес узла
*/
#define PHPAL_I18092MPI_CONFIG_NAD               0x0002U
/**
* Задать / получить время ожидания
*/
#define PHPAL_I18092MPI_CONFIG_WT                0x0003U
/**
* Задать / получить длину кадра
*/
#define PHPAL_I18092MPI_CONFIG_FSL               0x0004U
/**
* Задать / получить максимальное количество повторных попыток
*/
#define PHPAL_I18092MPI_CONFIG_MAXRETRYCOUNT     0x0005U
/*@}*/
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_SetConfig(	IN  LPVOID  pReader,
										IN	DWORD	dwParameterNumber,
										IN  DWORD   pdwParameterValue );
// Выполняет установку конфигурационного параметра
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
// dwParameterNumber - идентификатор параметра
// pdwParameterValue - значение параметра
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Чтение конфигурации
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_GetConfig(	IN  LPVOID  pReader,
										IN	DWORD	dwParameterNumber,
										OUT LPDWORD  pdwParameterValue );
// Выполняет чтение конфигурационного параметра
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
// dwParameterNumber - идентификатор параметра
// pdwParameterValue - указатель на значение параметра
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Чтение серийного номера (NFCID3)
//------------------------------------------------------------------------------
//
#define PHPAL_I18092MPI_NFCID3_LENGTH    0x0AU /**< Размер NFCID3. */
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_GetSerialNo(	IN  LPVOID  pReader,
										OUT LPBYTE  NFCID3 );
// Выполняет чтение конфигурационного параметра
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
// NFCID3 - серийный номер NFCID3 - 10 байт
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Чтение заданного количества байт из указанного адреса EEPROM
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_E2_Read(	IN  LPVOID  pReader,
									IN  DWORD dwAddr,
									IN	BYTE ucLength,
									OUT LPBYTE  pData );
// Выполняет чтение заданного количества байт из указанного адреса EEPROM
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
// dwAddr - адрес байта 192(0x00C0)..6143(0x17FF)
// ucLength - количество вычитываемых байт данных 1..127
// pData - массив, куда будут скопированы прочитанные байты данных
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Запись одного байта данных в указанный адрес EEPROM
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_E2_Write(	IN  LPVOID  pReader,
									IN  DWORD dwAddr,
									IN	BYTE ucData );
// Выполняет запись одного байта данных в указанный адрес EEPROM
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
// dwAddr - адрес байта 192(0x00C0)..6143(0x17FF)
// ucData - записываемый байт данных
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
//
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//------------------------------------------------------------------------------
//  NFC663: Запись нескольких байт данных в указанную страницу EEPROM
//------------------------------------------------------------------------------
//
CLSCRF_API LONG __stdcall 
            CLSCRF_NFC663_E2_WritePage(	IN  LPVOID  pReader,
										IN  DWORD dwAddr,
										IN	BYTE ucLength,
										IN  LPBYTE pData );
// Выполняет запись нескольких байт данных в указанную страницу EEPROM
//
// pReader – ссылка на объект-интерфейс (см. функцию CLSCRF_Create).
// dwAddr - адрес страницы 3..95(0x5F)
// ucLength - количество записываемых байт данных 1..64
// pData - указатель на массив байт данных
//
// Возвращаемое значение:  0   – успешное выполнение,
//   иначе – ошибка при выполнении.
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
