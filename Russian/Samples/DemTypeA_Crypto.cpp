// DemTypeA.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "Windows.h"
#include "../Clscrfl_SAM.h"

int main(int argc, char* argv[])
{
    void* m_pReader;
    LONG Status;
    unsigned char Buf[300];
    DWORD i, n, KeysCount = 5;
    char Err;
    bool  InterfaceRS = true;
    DWORD PortIndex = 0;
    unsigned char codeKey[16] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, code[16];
//========================================================================
//  ...>DemTypeA.exe       - for working with reader UEM RS via COM1
//  ...>DemTypeA.exe RS 1  - for working with reader UEM RS via COM2
//  ...>DemTypeA.exe RS 2  - for working with reader UEM RS via COM3 etc.
//  ...>DemTypeA.exe USB   - for working with single reader UEM USB
//  ...>DemTypeA.exe USB 1 - for working with second reader UEM USB
//  ...>DemTypeA.exe USB 2 - for working with third reader UEM USB etc.
//========================================================================
    srand(0);

    if( argc > 1 && strcmp( argv[1], "USB" ) == 0 )
            InterfaceRS = false;

    if( argc > 2 )
        PortIndex = atoi( argv[2] );

    printf("\nCONTACTLESS CARD READER's FUNCTION LIBRARY's Demo Program\n");
    printf("\n");

    Status = CLSCRF_Create( &m_pReader );

    if( Status == 0 )
        printf("Interface is created successfully\n");
    else
        printf("Interface is not created\n");

    if( InterfaceRS )
        Status = CLSCRF_OpenRS( m_pReader, PortIndex, 9600, 1 );
    else
        Status = CLSCRF_OpenUSB( m_pReader, PortIndex, 1 );

    if( Status == 0 )
    {
        printf("Beep                ");
        Status = CLSCRF_Sound( m_pReader, 2 );
        if (Status != 0)
        {
            printf("Sorry, error 0x%08X\n", Status );
            if( Status == 0x80100001 )
            {
                CLSCRF_GetLastInternalError( m_pReader, (BYTE*)&Err );
                printf("Internal Error = %d\n", Err );
            }
        }
        else
            printf("OK\n");

        if( InterfaceRS )
            printf("Interface COM%d is opened successfully\n", PortIndex+1);
        else
            printf("Interface USB(%d) is opened successfully\n", PortIndex);
    }
    else if( InterfaceRS )
        printf("Interface COM%d is not opened\n", PortIndex+1);
    else
        printf("Interface USB(%d) is not opened\n", PortIndex);

    Status = CLSCRF_Mfrc_On( m_pReader );

    if( Status == 0 )
        printf("Reader-IC is turn on successfully\n");
    else
        printf("Reader-IC is not turn on\n");

    //***
    Status = CLSCRF_Crypto_GenerateAndSaveAESKeysToFile("C:\\keys.bin", KeysCount, "abcd");
    if (Status == 0)
        printf("File with keys is saved successfully: number of keys = %d\n", KeysCount);
    else
        printf("Sorry, error 0x%08X\n", Status );

    Status = CLSCRF_Crypto_LoadAESKeysFromFile(m_pReader, "C:\\keys.bin", "abcd", &KeysCount);
    if (Status == 0)
        printf("File with keys is loaded successfully: number of keys = %d\n", KeysCount);
    else
        printf("Sorry, error 0x%08X\n", Status );

    Status = CLSCRF_Crypto_WriteFlash_AESKeys(m_pReader, 0, KeysCount);
    if (Status != 0)
        printf("Sorry, error 0x%08X\n", Status );

    Status = CLSCRF_Crypto_SetEncryptionMode(m_pReader, 1, 1);
    if (Status != 0)
        printf("Sorry, error 0x%08X\n", Status );
    //***

    printf("Mfrc_Version        ");
    Status = CLSCRF_Get_Mfrc_Version( m_pReader, Buf );
    if( Status == 0 )
        for( i = 0; i < 6; i++ )
            printf("%02X", Buf[i] );
    else
    {
        printf("Sorry, error 0x%08X\n", Status );
        if( Status == 0x80100001 )
        {
            CLSCRF_GetLastInternalError( m_pReader, (BYTE*)&Err );
            printf("Internal Error = %d", Err );
        }
    }
    printf("\n");

    printf("Mfrc_Serial_Number  ");
    Status = CLSCRF_Get_Mfrc_Serial_Number( m_pReader, Buf );
    if( Status == 0 )
        for( i = 0; i < 4; i++ )
            printf("%02X", Buf[3-i] );
    else
    {
        printf("Sorry, error 0x%08X\n", Status );
        if( Status == 0x80100001 )
        {
            CLSCRF_GetLastInternalError( m_pReader, (BYTE*)&Err );
            printf("Internal Error = %d", Err );
        }
    }
    printf("\n");

    Sleep( 1000 );

    CLSCRF_Mfrc_Rf_Off_On( m_pReader, 1 );

    printf("Activate_Idle_A\n");
    Status = CLSCRF_Activate_Idle_A( m_pReader,
                                     &Buf[0],// pbATQ 2 bytes
                                     &Buf[2],// pbSAK 1 byte
                                     &Buf[3],// pbUID max 10 bytes
                                     &n );

    if( Status == 0 )
    {
        CLSCRF_Sound( m_pReader, 1 );
        printf("ATQ   %02X%02X\n", Buf[1], Buf[0] );
        printf("SAK   %02X\n", Buf[2] );
        printf("UID   " );
        for( i = 0; i < n; i++ )
            printf("%02X", Buf[i+3] );
        printf("\n");

        CLSCRF_MifareStandard_HostCodeKey( m_pReader, codeKey, codeKey );
        if ((Status=CLSCRF_MifareStandard_AuthKey(m_pReader, 0x60, Buf + 3, 0, codeKey)) != 0)
        {
            printf("Sorry, error 0x%08X\n", Status );
            if( Status == 0x80100001 )
            {
                CLSCRF_GetLastInternalError( m_pReader, (BYTE*)&Err );
                printf("Internal Error = %d\n", Err );
            }
        }
        else
        {
            if ((Status=CLSCRF_MifareStandard_Read(m_pReader, 0, 0, code)) != 0)
            {
                printf("Sorry, error 0x%08X\n", Status );
                if( Status == 0x80100001 )
                {
                    CLSCRF_GetLastInternalError( m_pReader, (BYTE*)&Err );
                    printf("Internal Error = %d\n", Err );
                }
            }
            else
            {
                for( i = 0; i <= 15; i++ )
                    printf("%02X", code[i] );
                printf("\n");
            }
        }
        CLSCRF_Halt_A( m_pReader );

    }
    else
    {
        printf("Sorry, error 0x%08X\n", Status );
        if( Status == 0x80100001 )
        {
            CLSCRF_GetLastInternalError( m_pReader, (BYTE*)&Err );
            printf("Internal Error = %d\n", Err );
        }
    }

    Status = CLSCRF_Mfrc_Off( m_pReader );

    if( Status == 0 )
        printf("Reader-IC is turn off successfully\n");
    else
        printf("Reader-IC is not turn off\n");

    Status = CLSCRF_Close( m_pReader );

    if( Status == 0 )
        printf("Interface is closed successfully\n");
    else
        printf("Interface is not closed\n");

    Status = CLSCRF_Destroy( &m_pReader );

    if( Status == 0 )
        printf("Interface is destroyed successfully\n");
    else
        printf("Interface is not destroyed\n");

    printf("\n");
    printf( "Press Enter key ..." );
    getchar();

    /*void* m_pReader;
    LONG Status;
    bool  InterfaceRS = true;
    DWORD PortIndex = 0;
    DWORD KeysCount = 5;

    if( argc > 1 && strcmp( argv[1], "USB" ) == 0 )
            InterfaceRS = false;

    if( argc > 2 )
        PortIndex = atoi( argv[2] );

    printf("\nCONTACTLESS CARD READER's FUNCTION LIBRARY's Demo Program\n");
    printf("\n");

    Status = CLSCRF_Create( &m_pReader );
    if( Status == 0 )
        printf("Interface is created successfully\n");
    else
        printf("Interface is not created\n");

    if( InterfaceRS )
        Status = CLSCRF_OpenRS( m_pReader, PortIndex, 9600, 0 );
    else
        Status = CLSCRF_OpenUSB( m_pReader, PortIndex, 1 );

    if( Status == 0 )
    {
        if( InterfaceRS )
            printf("Interface COM%d is opened successfully\n", PortIndex+1);
        else
            printf("Interface USB(%d) is opened successfully\n", PortIndex);
    }
    else if( InterfaceRS )
        printf("Interface COM%d is not opened\n", PortIndex+1);
    else
        printf("Interface USB(%d) is not opened\n", PortIndex);

    if( InterfaceRS )
    {
        Status = CLSCRF_Mfrc_On( m_pReader );

        if( Status == 0 )
            printf("Reader-IC is turn on successfully\n");
        else
            printf("Reader-IC is not turn on\n");
    }

    //Status = CLSCRF_MifareStandard_GenerateAndSaveAESKeysToFile("C:\\keys.bin", KeysCount, "abcd");
    //if (Status == 0)
    //    printf("File with keys is saved successfully: number of keys = %d\n", KeysCount);
    //else
    //    printf("Sorry, error 0x%08X\n", Status );
    
    Status = CLSCRF_MifareStandard_LoadAESKeysFromFile(m_pReader, "C:\\keys.bin", "abcd", &KeysCount);
    if (Status == 0)
        printf("File with keys is loaded successfully: number of keys = %d\n", KeysCount);
    else
        printf("Sorry, error 0x%08X\n", Status );

    Status = CLSCRF_WriteFlash_AESKeys(m_pReader, 0, KeysCount);
    if (Status != 0)
        printf("Sorry, error 0x%08X\n", Status );

    Status = CLSCRF_MifareStandard_EnableEncryptionMode(m_pReader, 1, 1);
    if (Status != 0)
        printf("Sorry, error 0x%08X\n", Status );

    Status = CLSCRF_Sound( m_pReader, 2 );
    if (Status != 0)
        printf("Sorry, error 0x%08X\n", Status );*/

    return 0;
}
