using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.Threading;

namespace TestLibNDEFCS
{
    /// <summary>
    /// Класс обертка над библиотекой
    /// </summary>
    public class Clscrfl
    {
#if WindowsCE
        private const string ClscrflDll = "Clscrfl_CE.dll";
#else
        private const string ClscrflDll = "Clscrfl.dll";
#endif


        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Cards_GetCount(ref int piCardsCount);

        //        CLSCRF_Cards_Add( IN CLSCRF_CARD* pCard );

        //CLSCRF_Cards_GetFirst( OUT CLSCRF_CARD** ppCard );

        //CLSCRF_Cards_GetLast( OUT CLSCRF_CARD** ppCard );

        //CLSCRF_Cards_GetCount( OUT int* piCardsCount );

        //CLSCRF_Cards_Get( IN int iCardIndex, OUT CLSCRF_CARD** ppCard );

        //CLSCRF_Cards_Clear();

        //CLSCRF_Cards_SetCurrent(IN CLSCRF_CARD* pCard);

        //CLSCRF_Cards_GetCurrent(OUT CLSCRF_CARD** ppCard);

        //CLSCRF_Cards_Search( IN int UID_Len, IN PBYTE pUID, OUT CLSCRF_CARD** 
        //ppCard );

        //CLSCRF_Cards_CreateNew_A( IN BYTE bRfMode, IN PBYTE pbATQ, IN PBYTE pbSAK, 
        //IN PBYTE pbUID, IN DWORD UID_Len, OUT CLSCRF_CARD** ppCard );

        //CLSCRF_Cards_CreateNew_B( IN BYTE bRfMode, IN DWORD* pdwPUPI, IN DWORD* 
        //pdwAppData, IN DWORD* pdwProtInfo, IN int CardCount, OUT CLSCRF_CARD** 
        //ppCard );

        //CLSCRF_Cards_CreateNew15693( IN BYTE bRfMode, IN BYTE* pbData, IN DWORD 
        //dwCount, OUT CLSCRF_CARD** ppCard );

        //CLSCRF_Cards_CreateNewEPCUID( IN BYTE bRfMode, IN DWORD dwUID_Len, IN BYTE* 
        //pbData, IN DWORD dwCount, OUT CLSCRF_CARD** ppCard );

        //CLSCRF_Cards_Delete( IN int UID_Len, IN PBYTE pUID );




        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Create(ref IntPtr handle);

        [DllImport(ClscrflDll)]
        [Obsolete("Метод вызывает ошибку в библиотеке!")]
        public static extern uint CLSCRF_Destroy(IntPtr handle);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_OpenRS(IntPtr handle, uint dwIndex, uint dwBaudrate, uint dwLogFile);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_OpenUSB(IntPtr pReader, uint dwIndex, uint dwLogFile);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_GetState(IntPtr pReader, IntPtr pdwState);

        [DllImport(ClscrflDll)]
        public static extern bool CLSCRF_IsOpened(IntPtr pReader);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Close(IntPtr pReader);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_GetLastInternalError(IntPtr pReader, out byte pbError);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Mfrc_On(IntPtr pReader);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Mfrc_Off(IntPtr pReader);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Mfrc_Rf_Off_On(IntPtr pReader, ushort usDelay);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Get_Mfrc_Version(IntPtr pReader, IntPtr pbMfrcVersion);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Sound(IntPtr pReader, IntPtr nBeepCount);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_EraseFlash(IntPtr pReader);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_WriteFlashValue(IntPtr pReader, uint dwAddress, IntPtr pbValue);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Activate_Idle_A(IntPtr pReader, IntPtr pbATQ, IntPtr pbSAK, IntPtr pbUID, ref uint pdwUIDLength);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Halt_A(IntPtr pReader);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Activate_Wakeup_A(IntPtr pReader, IntPtr pbUID, uint UIDLength, IntPtr pbATQ, IntPtr pbSAK);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_ISO14443A_4_RATS(IntPtr pReader, byte ucCID, IntPtr pbATS );

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_ISO14443A_4_PPS(IntPtr pReader, byte ucCID, byte ucBaudrate);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_DirectIO_Card(IntPtr pReader, IntPtr pbSendBuffer, uint uiSendLength, uint uiTimeout, IntPtr pbRecvBuffer, ref uint puiRecvLength );

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_MifareStandard_HostCodeKey(IntPtr pReader, IntPtr pbUncoded, IntPtr pbCoded);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_MifareStandard_AuthKey(IntPtr pReader, byte bKeyType, IntPtr pbUID, uint dwSector, IntPtr pbCodedKey);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_MifareStandard_WriteKeyToE2(IntPtr pReader, byte bKeyType, uint dwSector, IntPtr pbUncoded);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_MifareStandard_AuthE2(IntPtr pReader, byte bKeyType, IntPtr pbUID, uint dwSector);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_MifareStandard_Read(IntPtr pReader, uint dwSector, uint dwBlock, IntPtr pbRecvBuffer);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_MifareStandard_Write(IntPtr pReader, uint dwSector, uint dwBlock, IntPtr pbSendBuffer);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_MifareUltralight_Read(IntPtr pReader, byte ucPage, IntPtr pbRecvBuffer);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_MifareUltralight_Write(IntPtr pReader, byte ucPage, IntPtr pbSendBuffer);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_Mfrc_Set_Rf_Mode(IntPtr pReader, byte ucRfMode);

        [DllImport(ClscrflDll)]
        private static extern uint CLSCRF_Led(IntPtr pReader, Byte bBlinkColor, Byte bBlinkCount, Byte bPostColor);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_LLCP_Create(IntPtr pReader, ref IntPtr phLLCPLink);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_LLCP_SetBaudrate(IntPtr pReader, byte ucDsiDri);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_SNEP_Create(IntPtr hLLCPLink, ref IntPtr hSNEP);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_SNEP_Receive(IntPtr hSNEP, IntPtr lpData, ref uint puiDataLength);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_SNEP_Transmit(IntPtr hSNEP, IntPtr lpData, uint uiDataLength);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_SNEP_Destroy(IntPtr hSNEP);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_LLCP_Destroy(IntPtr hLLCPLink);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_ForumTags_SupposeTypeISO14443A(IntPtr pReader, IntPtr ATQ, byte SAK, ref byte pucTagType);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_ForumTags_BeginType4(IntPtr pReader);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_ForumTags_Format(IntPtr pReader, byte ucTagType);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_ForumTags_Read(IntPtr pReader, byte ucTagType, IntPtr lpData, ref uint puiDataLength, ref byte pucPermissions);

        [DllImport(ClscrflDll)]
        public static extern uint CLSCRF_NFC_ForumTags_Write(IntPtr pReader, byte ucTagType, IntPtr lpData, uint uiDataLength);

        /// <summary>
        /// Получить версию считывателя
        /// </summary>
        /// <param name="handle"></param>
        /// <returns></returns>
        public static string GetVersion(IntPtr handle)
        {
            var pbMfrcVersion = Marshal.AllocHGlobal(6);
            byte[] version = new byte[6];
            var sb = new StringBuilder();
            var lowLevelResult = CLSCRF_Get_Mfrc_Version(handle, pbMfrcVersion);
            Marshal.Copy(pbMfrcVersion, version, 0, 6);
            if (lowLevelResult != Ok)
            {
                ThrowException(handle, lowLevelResult);
            }
            for (int i = 0; i < version.Length; i++)
            {
                sb.AppendFormat(" {0:X2}", version[i]);
            }
            Marshal.FreeHGlobal(pbMfrcVersion);
            return sb.ToString();
        }
        /// <summary>
        /// Получить состояние
        /// </summary>
        /// <param name="handle"></param>
        /// <returns></returns>
        public static string GetState(IntPtr handle)
        {
            var state = Marshal.AllocHGlobal(4);
            var result = CLSCRF_GetState(handle, state);
            var resstate = new byte[4];
            var sb = new StringBuilder();
            Marshal.Copy(state, resstate, 0, 4);
            if (result != 0)
            {
                return result.ToString("X8");
            }
            Marshal.FreeHGlobal(state);
            for (int i = 0; i < resstate.Length; i++)
            {
                sb.AppendFormat(" {0:X2}", resstate[i]);
            }
            return sb.ToString();
        }
        /// <summary>
        /// Помигать индикатором
        /// </summary>
        /// <param name="handle"></param>
        public static void Blink(IntPtr handle)
        {
            var lowLevelResult = CLSCRF_Led(handle, (byte)IndicatorState.Yellow, 3, (byte)IndicatorState.Off);
            if (lowLevelResult != Ok)
            {
                ThrowException(handle, lowLevelResult);
            }
        }
        /// <summary>
        /// Признак поддержки стандарта ISO18092
        /// </summary>
        public static bool _fISO18092 = false;
        /// <summary>
        /// Признак поддержки стандарта NFC Forum Tag Type #
        /// </summary>
        public static byte _ucTagType = 0;
        /// <summary>
        /// Подключиться к карте
        /// </summary>
        /// <param name="handle"></param>
        /// <returns></returns>
        public static byte[] ConnectToCard(IntPtr handle)
        {
            var pbATQ = Marshal.AllocHGlobal(2);
            var pbSAK = Marshal.AllocHGlobal(1);
            var pbUID = Marshal.AllocHGlobal(10);
            uint pdwUIDLength = 7;
            uint Status = CLSCRF_Activate_Idle_A(handle, pbATQ, pbSAK, pbUID, ref pdwUIDLength);
            byte[] result;
            if (Status == 0)
            {
                result = new byte[pdwUIDLength];
                Marshal.Copy(pbUID, result, 0, (int)pdwUIDLength);

                _fISO18092 = ((Marshal.ReadByte(pbSAK) & 0x44) == 0x40);

                CLSCRF_NFC_ForumTags_SupposeTypeISO14443A(handle, pbATQ, Marshal.ReadByte(pbSAK), ref _ucTagType);

                //_fTagType2 = (Marshal.ReadByte(pbSAK) == 0x00 && Marshal.ReadByte(pbATQ, 0) == 0x44 && Marshal.ReadByte(pbATQ, 1) == 0x00);
                //_fTagType4 = (Marshal.ReadByte(pbSAK) == 0x20 && Marshal.ReadByte(pbATQ, 0) == 0x44 && Marshal.ReadByte(pbATQ, 1) == 0x03);

                if (_ucTagType == 4)
                {
                    //byte CID = 0;
                    //var pbATS = Marshal.AllocHGlobal(37);

                    //Status = CLSCRF_ISO14443A_4_RATS(handle, CID, pbATS);

                    //Marshal.FreeHGlobal(pbATS);
                    
                    //if (Status != 0)
                    //    return null;

                    //Status = CLSCRF_ISO14443A_4_PPS(handle, CID, 0 );
                    //if (Status != 0)
                    //    return null;

                    //Status = CLSCRF_Mfrc_Set_Rf_Mode(handle, 0 );
                    //if (Status != 0)
                    //    return null;

                    Status = CLSCRF_NFC_ForumTags_BeginType4(handle);
                    if (Status != 0)
                        return null;
                }
            }
            else
            {
                result = null;
            }
            Marshal.FreeHGlobal(pbATQ);
            Marshal.FreeHGlobal(pbSAK);
            Marshal.FreeHGlobal(pbUID);
            return result;
        }
        /// <summary>
        /// Авторизоваться к сектору
        /// </summary>
        /// <param name="handle"></param>
        /// <param name="keyType"></param>
        /// <param name="UID"></param>
        /// <param name="sector"></param>
        /// <returns></returns>
        public static bool Auth(IntPtr handle, byte keyType, byte[] UID, byte sector)
        {
            var result = false;
            var pbUID = Marshal.AllocHGlobal(UID.Length);
            Marshal.Copy(UID, UID.Length-4, pbUID, 4);
            var lowLevelResult = CLSCRF_MifareStandard_AuthE2(handle, keyType, pbUID, sector);
            Marshal.FreeHGlobal(pbUID);
            if (lowLevelResult == 0)
            {
                result = true;
            }
            else
            {
                ThrowException(handle, lowLevelResult);
            }
            return result;
        }
        /// <summary>
        /// Считать данные по адресу
        /// </summary>
        /// <param name="handle"></param>
        /// <param name="sector"></param>
        /// <param name="block"></param>
        /// <returns></returns>
        public static byte[] Read(IntPtr handle, byte sector, byte block)
        {
            var pbRecvBuffer = Marshal.AllocHGlobal(16);
            var result = new byte[16];
            var lowLevelResult = CLSCRF_MifareStandard_Read(handle, sector, block, pbRecvBuffer);
            if (lowLevelResult == 0)
            {
                Marshal.Copy(pbRecvBuffer, result, 0, 16);
                Marshal.FreeHGlobal(pbRecvBuffer);
            }
            else
            {
                Marshal.FreeHGlobal(pbRecvBuffer);
                ThrowException(handle, lowLevelResult);
            }

            return result;
        }
        private static bool _fBNBit = false;
        /// <summary>
        /// Переинициализация T=CL ISO14443-4
        /// </summary>
        /// <param name="handle"></param>
        /// <param name="sector"></param>
        /// <param name="block"></param>
        /// <returns></returns>
        public static void InitTCL()
        {
            _fBNBit = false;
        }
        /// <summary>
        /// Приемопередача T=CL ISO14443-4
        /// </summary>
        /// <param name="handle"></param>
        /// <param name="sector"></param>
        /// <param name="block"></param>
        /// <returns></returns>
        public static uint TransceiveTCL(IntPtr handle, byte[] dataSend, ref byte[] dataRecv)
        {
            var pbSendBuffer = Marshal.AllocHGlobal(dataSend.Length + 2);
            Marshal.Copy(dataSend, 0, pbSendBuffer + 2, dataSend.Length);
            if (_fBNBit)
                Marshal.WriteByte(pbSendBuffer, 0x0B);
            else
                Marshal.WriteByte(pbSendBuffer, 0x0A);
            Marshal.WriteByte(pbSendBuffer + 1, 0x00);
            uint uiRecvLength = 1024;
            var pbRecvBuffer = Marshal.AllocHGlobal((int)uiRecvLength);
            uint lowLevelResult = CLSCRF_DirectIO_Card(handle, pbSendBuffer, (uint)dataSend.Length + 2, 1000, pbRecvBuffer, ref uiRecvLength);
            Marshal.FreeHGlobal(pbSendBuffer);
            _fBNBit = !_fBNBit;
            if (lowLevelResult == 0)
            {
                if (uiRecvLength > 2)
                {
                    dataRecv = new byte[uiRecvLength - 2];
                    Marshal.Copy(pbRecvBuffer + 2, dataRecv, 0, (int)uiRecvLength - 2);
                }
                Marshal.FreeHGlobal(pbRecvBuffer);
            }
            else
            {
                Marshal.FreeHGlobal(pbRecvBuffer);
                //ThrowException(handle, lowLevelResult);
            }

            return lowLevelResult;
        }
        /// <summary>
        /// Бросает исключение
        /// </summary>
        /// <param name="handle"></param>
        /// <param name="result"></param>
        private static void ThrowException(IntPtr handle, uint result)
        {
            if (result == InternalError)
            {
                //throw new CardReaderException("Ошибка внуреняя: " + LastInternalError(handle).ToString("X2"));
            }
            else
            {
                //throw new CardReaderException("Ошибка: " + result.ToString("X8"));
            }
        }
        /// <summary>
        /// Получение полследнего ошибочного состояния при внутреней ошибке
        /// </summary>
        /// <param name="handle"></param>
        /// <returns></returns>
        public static byte LastInternalError(IntPtr handle)
        {
            byte result = 0;

            if (CLSCRF_GetLastInternalError(handle, out result) != 0)
            {
                result = 0;
            }
            return result;
        }
        /// <summary>
        /// Загрузка ключа в ридер
        /// </summary>
        /// <param name="handle"></param>
        /// <param name="sector"></param>
        /// <param name="keyType"></param>
        /// <param name="key"></param>
        internal static void LoadKey(IntPtr handle, byte sector, byte keyType, byte[] key)
        {
            var pbKey = Marshal.AllocHGlobal(6);
            Marshal.Copy(key, 0, pbKey, 6);
            var lowLevelResult = CLSCRF_MifareStandard_WriteKeyToE2(handle, keyType, sector, pbKey);
            Marshal.FreeHGlobal(pbKey);
            if (lowLevelResult != 0)
            {
                ThrowException(handle, lowLevelResult);
            }
        }
        /// <summary>
        /// Запись блока
        /// </summary>
        /// <param name="handle"></param>
        /// <param name="sector"></param>
        /// <param name="block"></param>
        /// <param name="data"></param>
        internal static void Write(IntPtr handle, byte sector, byte block, byte[] data)
        {
            var pbSendBuffer = Marshal.AllocHGlobal(16);
            Marshal.Copy(data, 0, pbSendBuffer, 16);
            var lowLevelResult = CLSCRF_MifareStandard_Write(handle, sector, block, pbSendBuffer);
            Marshal.FreeHGlobal(pbSendBuffer);
            if (lowLevelResult != 0)
            {
                ThrowException(handle, lowLevelResult);
            }
        }
        /// <summary>
        /// Создание интерфейса
        /// </summary>
        /// <param name="handle"></param>
        internal static void Create(ref IntPtr handle)
        {
            string path = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().GetName().CodeBase);
            Console.WriteLine(System.IO.File.Exists(path + "\\" + ClscrflDll) ? "File exists." : "File does not exist.");
            var lowLevelResult = CLSCRF_Create(ref handle);
            if (lowLevelResult != 0)
            {
                ThrowException(handle, lowLevelResult);
            }
        }
        /// <summary>
        /// Открытие интерфейса USB
        /// </summary>
        /// <param name="handle"></param>
        internal static void OpenUSB(IntPtr handle)
        {
            var lowLevelResult = CLSCRF_OpenUSB(handle, 0, 0);
            if (lowLevelResult != 0)
            {
                ThrowException(handle, lowLevelResult);
            }
        }
        /// <summary>
        /// Откртие интерфейса COM
        /// </summary>
        /// <param name="handle"></param>
        /// <param name="port"></param>
        /// <returns></returns>
        internal static bool OpenCom(IntPtr handle, string port)
        {
            var portNo = Convert(port);
            var lowLevelResult = CLSCRF_OpenRS(handle, portNo, 9600, 0);
            if (lowLevelResult != 0)
            {
                ThrowException(handle, lowLevelResult);
            }
            return true;
        }
        /// <summary>
        /// Преобразование названия порта в номер
        /// </summary>
        /// <param name="port"></param>
        /// <returns></returns>
        internal static byte Convert(string port)
        {
            byte result = 0;
            if (port.ToUpper().StartsWith("COM"))
            {
                try
                {
                    result = byte.Parse(port.Substring(3));
                }
                catch (Exception e)
                {
                    //throw new CardReaderException("Параметр порта должен быть вида COM1", e);
                }
            }
            else
            {
                //throw new CardReaderException("Параметр порта должен быть вида COM1");
            }
            return result;
        }
        /// <summary>
        /// Код внутренней ошибки
        /// </summary>
        public const UInt32 InternalError = 0x80100001;
        /// <summary>
        /// Код успешного выполнения
        /// </summary>
        public const int Ok = 0;
        /// <summary>
        /// Состояние индикатора
        /// </summary>
        public enum IndicatorState
        {
            Off = 0x00,
            Green = 0x01,
            Red = 0x02,
            Yellow = 0x03
        };
        /// <summary>
        /// Включить микросхему считыватель
        /// </summary>
        /// <param name="handle"></param>
        internal static void On(IntPtr handle)
        {
            var on = CLSCRF_Mfrc_On(handle);
            if (on != Ok)
            {
                Thread.Sleep(200);
                on = CLSCRF_Mfrc_On(handle);
                if (on != Ok)
                {
                    ThrowException(handle, on);
                }
            }
        }
        /// <summary>
        /// Преобразование массива байт в строку HEX символов
        /// </summary>
        /// <param name="ba"></param>
        /// <returns></returns>
        public static string ByteArrayToString(byte[] ba)
        {
            StringBuilder hex = new StringBuilder(ba.Length * 2);
            foreach (byte b in ba)
                hex.AppendFormat("{0:X2}", b);
            return hex.ToString();
        }
    }
}
