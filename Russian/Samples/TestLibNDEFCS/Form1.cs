using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
//using System.Threading.Tasks;
using System.Windows.Forms;
using NdefLibrary.Ndef;
using System.Runtime.InteropServices;
//using System.Threading;
using GemCard;

namespace TestLibNDEFCS
{
    public partial class Form1 : Form
    {
        byte[] _rawMsg = { 0x00 };

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Let the NDEF library parse the NDEF message out of the raw byte array
            var ndefMessage = NdefMessage.FromByteArray(_rawMsg);

            foreach (NdefRecord record in ndefMessage)
            {
                // --------------------------------------------------------------------------
                // Check the type of each record
                // Using 'true' as parameter for CheckSpecializedType() also checks for sub-types of records,
                // e.g., it will return the SMS record type if a URI record starts with "sms:"
                // If using 'false', a URI record will always be returned as Uri record and its contents won't be further analyzed
                // Currently recognized sub-types are: SMS, Mailto, Tel, Nokia Accessories, NearSpeak, WpSettings
                var specializedType = record.CheckSpecializedType(true);
                if (specializedType == typeof(NdefMailtoRecord))
                {
                    // --------------------------------------------------------------------------
                    // Convert and extract Mailto record info
                    var mailtoRecord = new NdefMailtoRecord(record);
                    //tagContents.Append("-> Mailto record\n");
                    //tagContents.AppendFormat("Address: {0}\n", mailtoRecord.Address);
                    //tagContents.AppendFormat("Subject: {0}\n", mailtoRecord.Subject);
                    //tagContents.AppendFormat("Body: {0}\n", mailtoRecord.Body);
                }
                else if (specializedType == typeof(NdefUriRecord))
                {
                    // --------------------------------------------------------------------------
                    // Convert and extract URI record info
                    var uriRecord = new NdefUriRecord(record);
                    //tagContents.Append("-> URI record\n");
                    //tagContents.AppendFormat("URI: {0}\n", uriRecord.Uri);
                }
                else if (specializedType == typeof(NdefLaunchAppRecord))
                {
                    // --------------------------------------------------------------------------
                    // Convert and extract LaunchApp record info
                    var launchAppRecord = new NdefLaunchAppRecord(record);
                    //tagContents.Append("-> LaunchApp record" + Environment.NewLine);
                    //if (!string.IsNullOrEmpty(launchAppRecord.Arguments))
                    //    tagContents.AppendFormat("Arguments: {0}\n", launchAppRecord.Arguments);
                    //if (launchAppRecord.PlatformIds != null)
                    //{
                    //    foreach (var platformIdTuple in launchAppRecord.PlatformIds)
                    //    {
                    //        if (platformIdTuple.Key != null)
                    //            tagContents.AppendFormat("Platform: {0}\n", platformIdTuple.Key);
                    //        if (platformIdTuple.Value != null)
                    //            tagContents.AppendFormat("App ID: {0}\n", platformIdTuple.Value);
                    //    }
                    //}
                }
                else if (specializedType == typeof(NdefVcardRecordBase))
                {
                    // --------------------------------------------------------------------------
                    // Convert and extract business card info
                    //var vcardRecord = NdefVcardRecord.CreateFromGenericBaseRecord(record);
                    //tagContents.Append("-> Business Card record" + Environment.NewLine);
                    //tagContents.AppendFormat("vCard Version: {0}" + Environment.NewLine,
                    //                         vcardRecord.VCardFormatToWrite == VCardFormat.Version2_1 ? "2.1" : "3.0");
                    //var contact = vcardRecord.ContactData;
                    //var contactInfo = await contact.GetPropertiesAsync();
                    //foreach (var curProperty in contactInfo.OrderBy(i => i.Key))
                    //{
                    //    tagContents.Append(String.Format("{0}: {1}" + Environment.NewLine, curProperty.Key, curProperty.Value));
                    //}
                }
                else
                {
                    // Other type, not handled by this demo
                    //tagContents.Append("NDEF record not parsed by this demo app" + Environment.NewLine);
                }
            }


        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Create a new LaunchApp record to launch this app
            // The app will print the arguments when it is launched (see MainPage.OnNavigatedTo() method)
            //var record1 = new NdefLaunchAppRecord { Arguments = "Hello World" };
            // WindowsPhone is the pre-defined platform ID for WP8.
            // You can get the application ID from the WMAppManifest.xml file
            //record1.AddPlatformAppId("WindowsPhone", "{544ec154-b521-4d73-9405-963830adb213}");


            //ContactInformation contactInfo;
            //// Create demo contact
            //contactInfo = new ContactInformation
            //{
            //    FamilyName = "Jakl",
            //    GivenName = "Andreas"
            //};
            //var contactProps = await contactInfo.GetPropertiesAsync();
            //contactProps.Add(KnownContactProperties.CompanyName, "Mopius");
            //contactProps.Add(KnownContactProperties.Url, "http://www.mopius.com/");
            //// Create new NDEF record based on selected contact
            //var vcardRecord = await NdefVcardRecord.CreateFromContactInformation(contactInfo);


            // Create a new mailto record, set the relevant properties for the email
            var record2 = new NdefMailtoRecord
            {
                Address = "andreas.jakl@mopius.com",
                Subject = "Feedback for the NDEF Library",
                Body = "I think the NDEF library is ..."
            };
            // Wrap the NDEF record into an NDEF message
            var message = new NdefMessage { record2 };


            // Create a URI record
            var record3 = new NdefUriRecord { Uri = "http://www.nfcinteractor.com/" };
            // Publish the record using the proximity device

            message.Add(record3);

            // Convert the NDEF message to a byte array
            _rawMsg = message.ToByteArray();
            var msgArray = message.ToByteArray();
        }

        IntPtr pReader = new IntPtr();
        bool _fPCSC = false;

        private void buttonOpenUSB_Click(object sender, EventArgs e)
        {
            _fPCSC = false;

            Clscrfl.CLSCRF_Close(pReader);

            if (comboBoxReaderType.SelectedIndex == 0)
            {
                uint err = Clscrfl.CLSCRF_OpenUSB(pReader, 0, 0);

                if (err == 0)
                {
                    toolStripStatusLabel2.Text = "OK";

                    buttonActivateTag.Enabled = true;
                }
                else
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");
            }
            else
            {
                toolStripStatusLabel2.Text = "OK";

                buttonActivateTag.Enabled = true;

                _fPCSC = true;
            }
        }


        private void DetectPCSCReaders()
        {
            comboBoxReaderType.Items.Clear();
            comboBoxReaderType.Items.Add("Считыватель USB");
            comboBoxReaderType.SelectedIndex = 0;

            string[] szReaders = _iCard.ListReaders();

            //foreach (string szReader in szReaders)
            //{
            //    comboBoxReaderType.Items.Add("PC/SC: " + szReader);
            //}
            if (szReaders != null)
            if (szReaders.Length > 0)
                comboBoxReaderType.Items.AddRange(szReaders);
        }

        CardNative _iCard = new CardNative();
        private void Form1_Load(object sender, EventArgs e)
        {
            Clscrfl.Create(ref pReader);

            DetectPCSCReaders();
        }

        private void buttonActivateTag_Click(object sender, EventArgs e)
        {
            if (!_fPCSC)
            {
                Clscrfl.CLSCRF_Mfrc_On(pReader);

                Clscrfl.CLSCRF_Mfrc_Rf_Off_On(pReader, 10);

                Clscrfl.CLSCRF_Mfrc_Set_Rf_Mode(pReader, 0x00);

                byte[] UID = Clscrfl.ConnectToCard(pReader);

                if (UID == null)
                    toolStripStatusLabel2.Text = "Ничего не найдено!";
                else
                {
                    if (Clscrfl._fISO18092)
                        toolStripStatusLabel2.Text = "Найдено устройство P2P, UID = 0x" + Clscrfl.ByteArrayToString(UID);
                    else
                    {
                        if (Clscrfl._ucTagType > 0)
                            toolStripStatusLabel2.Text = "Найдена метка NFC Forum Tag Type " + Clscrfl._ucTagType.ToString() + " Compatible, UID = 0x" + Clscrfl.ByteArrayToString(UID);
                        else 
                            toolStripStatusLabel2.Text = "Найдена метка, UID = 0x" + Clscrfl.ByteArrayToString(UID);

                        buttonFormatNFCTag.Enabled = true;
                    }

                    buttonReadNDEF.Enabled = true;
                    buttonWriteNDEF.Enabled = true;
                }
            }
            else
            {
                try
                // Connect to the card
                {
                    const ushort SC_OK = 0x9000;
                    const byte SC_PENDING = 0x9F;

                    APDUCommand apduGetID = new APDUCommand(0xFF, 0xCA, 0, 0, null, 0);

                    APDUResponse apduResp;

                    _iCard.Disconnect(DISCONNECT.Unpower);
                    _iCard.Connect(comboBoxReaderType.Text, SHARE.Shared, PROTOCOL.T0orT1);
                    byte[] ATR = _iCard.GetAttribute(CardNative.SCARD_ATTR_ATR_STRING);

                    byte[] mfulATRmask = { 0x3B, 0x8F, 0x80, 0x01, 0x80, 0x4F, 0x0C, 0xA0, 0x00, 0x00, 0x03, 0x06, 0x03, 0x00 };
                    if (ATR.Length >= mfulATRmask.Length)
                    {
                        if (ATR.Take(mfulATRmask.Length).SequenceEqual(mfulATRmask))
                            Clscrfl._ucTagType = 2;
                    }

                    byte[] mfdfATRmask = { 0x3B, 0x81, 0x80, 0x01, 0x80, 0x80 };
                    if (ATR.Length >= mfdfATRmask.Length)
                    {
                        if (ATR.Take(mfdfATRmask.Length).SequenceEqual(mfdfATRmask))
                            Clscrfl._ucTagType = 4;
                    }

                    //Console.WriteLine("Connects card on reader: " + readers[0]);

                    //APDUParam apduParam = new APDUParam();
                    //apduParam.Data = new byte[] { 0x6F, 0x3A };
                    //apduGetID.Update(apduParam);
                    apduResp = _iCard.Transmit(apduGetID);
                    //if (apduResp.Status != SC_OK && apduResp.SW1 != SC_PENDING)
                    //    throw new Exception("Select command failed: " + apduResp.ToString());
                    //Console.WriteLine("Card ID: " + apduResp.ToString());

                    //_iCard.Disconnect(DISCONNECT.Unpower);

                    if (apduResp.Status != SC_OK)
                    {
                        toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                        return;
                    }

                    if (Clscrfl._ucTagType > 0)
                        toolStripStatusLabel2.Text = "Найдена метка NFC Forum Tag Type " + Clscrfl._ucTagType.ToString() + " Compatible, UID = 0x" + Clscrfl.ByteArrayToString(apduResp.Data);
                    else
                        toolStripStatusLabel2.Text = "Найдена метка, UID = 0x" + Clscrfl.ByteArrayToString(apduResp.Data);

                    buttonFormatNFCTag.Enabled = true;
                    buttonReadNDEF.Enabled = true;
                    buttonWriteNDEF.Enabled = true;
                }
                catch (SmartCardException ex)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + ex.HResult.ToString("X");
                }
            }

        }

        private void ParseNDEF()
        {
            // Let the NDEF library parse the NDEF message out of the raw byte array
            var ndefMessage = NdefMessage.FromByteArray(_rawMsg);

            checkBoxText.Checked = false;
            checkBoxEMail.Checked = false;
            checkBoxURI.Checked = false;
            checkBoxSMS.Checked = false;

            foreach (NdefRecord record in ndefMessage)
            {
                if (record.Type == null)
                    continue;
                // --------------------------------------------------------------------------
                // Check the type of each record
                // Using 'true' as parameter for CheckSpecializedType() also checks for sub-types of records,
                // e.g., it will return the SMS record type if a URI record starts with "sms:"
                // If using 'false', a URI record will always be returned as Uri record and its contents won't be further analyzed
                // Currently recognized sub-types are: SMS, Mailto, Tel, Nokia Accessories, NearSpeak, WpSettings
                var specializedType = record.CheckSpecializedType(true);
                if (specializedType == typeof(NdefTextRecord))
                {
                    var textRecord = new NdefTextRecord(record);
                    textBoxRecordText.Text = textRecord.Text;
                    textBoxRecordTextLangCode.Text = textRecord.LanguageCode;
                    checkBoxText.Checked = true;
                }
                if (specializedType == typeof(NdefMailtoRecord))
                {
                    // --------------------------------------------------------------------------
                    // Convert and extract Mailto record info
                    var mailtoRecord = new NdefMailtoRecord(record);
                    textBoxRecordEMAILAddress.Text = mailtoRecord.Address;
                    textBoxRecordEMAILSubject.Text = mailtoRecord.Subject;
                    textBoxRecordEMAILBody.Text = mailtoRecord.Body;
                    checkBoxEMail.Checked = true;
                }
                if (specializedType == typeof(NdefUriRecord))
                {
                    // --------------------------------------------------------------------------
                    // Convert and extract URI record info
                    var uriRecord = new NdefUriRecord(record);
                    textBoxRecordURI.Text = uriRecord.Uri;
                    checkBoxURI.Checked = true;
                }
                if (specializedType == typeof(NdefSmsRecord))
                {
                    var smsRecord = new NdefSmsRecord(record);
                    textBoxRecordSMSNumber.Text = smsRecord.SmsNumber;
                    textBoxRecordSMSBody.Text = smsRecord.SmsBody;
                    checkBoxSMS.Checked = true;
                }
                if (specializedType == typeof(NdefTelRecord))
                {
                    var telRecord = new NdefTelRecord(record);
                    textBoxRecordTelNumber.Text = telRecord.TelNumber;
                    checkBoxTel.Checked = true;
                }
                if (specializedType == typeof(NdefVcardRecordBase))
                {
                    var vcardRecordBase = new NdefVcardRecordBase(record);
                    //textBoxRecordSMSNumber.Text = vcardRecordBase.SmsNumber;
                    //textBoxRecordSMSBody.Text = vcardRecordBase.SmsBody;
                    //checkBoxSMS.Checked = true;

                    var encoding = Encoding.UTF8; // Encoding.BigEndianUnicode;

                    textBoxPayload.Text = encoding.GetString(vcardRecordBase.Payload, 0, vcardRecordBase.Payload.Length).Replace("\n", "\r\n");
                    textBoxTNF.Text = vcardRecordBase.TypeNameFormat.ToString();
                    textBoxType.Text = encoding.GetString(vcardRecordBase.Type, 0, vcardRecordBase.Type.Length);
                }
                if (specializedType == typeof(NdefMimeImageRecordBase))
                {
                    var mimeImageRecordBase = new NdefMimeImageRecordBase(record);
                    //textBoxRecordSMSNumber.Text = vcardRecordBase.SmsNumber;
                    //textBoxRecordSMSBody.Text = vcardRecordBase.SmsBody;
                    //checkBoxSMS.Checked = true;
                }
                if (specializedType == typeof(NdefRecord))
                {
                    var Record = new NdefRecord(record);

                    var encoding = Encoding.UTF8; // Encoding.BigEndianUnicode;

                    textBoxPayload.Text = encoding.GetString(Record.Payload, 0, Record.Payload.Length).Replace("\n", "\r\n");
                    textBoxTNF.Text = Record.TypeNameFormat.ToString();
                    textBoxType.Text = encoding.GetString(Record.Type, 0, Record.Type.Length);
                }
                else
                {
                    var Record = new NdefRecord(record);

                    var encoding = Encoding.UTF8; // Encoding.BigEndianUnicode;

                    textBoxPayload.Text = encoding.GetString(Record.Payload, 0, Record.Payload.Length).Replace("\n", "\r\n");
                    textBoxTNF.Text = Record.TypeNameFormat.ToString();
                    textBoxType.Text = encoding.GetString(Record.Type, 0, Record.Type.Length);
                }
            }
        }

        private uint ReadP2P()
        {
            IntPtr hLLCPLink = IntPtr.Zero;
	        uint Status;
            
            Status = Clscrfl.CLSCRF_NFC_LLCP_Create(pReader, ref hLLCPLink);
	        if (Status != 0)
	        {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
	        }

	        Status = Clscrfl.CLSCRF_NFC_LLCP_SetBaudrate(hLLCPLink, 0);
	        if (Status != 0)
	        {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

            IntPtr hSNEP = IntPtr.Zero;
	        Status = Clscrfl.CLSCRF_NFC_SNEP_Create(hLLCPLink, ref hSNEP);
	        if (Status != 0)
	        {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

	        uint uiMsgSize = 0;
            var pbRecvBuffer = Marshal.AllocHGlobal(1024);

	        Status = Clscrfl.CLSCRF_NFC_SNEP_Receive(hSNEP, pbRecvBuffer, ref uiMsgSize);
	        if (Status == 0)
            {
                _rawMsg = new byte[uiMsgSize];
                Marshal.Copy(pbRecvBuffer, _rawMsg, 0, (int)uiMsgSize);
                Marshal.FreeHGlobal(pbRecvBuffer);
            }
            else
            {
                Marshal.FreeHGlobal(pbRecvBuffer);

                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

            Status = Clscrfl.CLSCRF_NFC_SNEP_Destroy(hSNEP);
	        if (Status != 0)
	        {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

	        Status = Clscrfl.CLSCRF_NFC_LLCP_Destroy(hLLCPLink);
	        if (Status != 0)
	        {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

            try
            {
                ParseNDEF();
            }
            catch (NdefException ex)
            {
                return (uint)ex.HResult;
            }

            return Status;
        }

        private void buttonReadNDEF_Click(object sender, EventArgs e)
        {
            textBoxPayload.Text = "";
            textBoxTNF.Text = "";
            textBoxType.Text = "";
            checkBoxWriteRawRecord.Checked = false;

            byte[] pByteBuff = new byte[1024];

            if (Clscrfl._fISO18092)
            {
                toolStripStatusLabel2.Text = "Подтвердите отправку данных на устройстве";
                this.Refresh();

                uint Status = ReadP2P();

                Clscrfl.CLSCRF_Mfrc_Off(pReader);

                buttonFormatNFCTag.Enabled = false;
                buttonReadNDEF.Enabled = false;
                buttonWriteNDEF.Enabled = false;

                if (Status != 0)
                {
                    return;
                }

                toolStripStatusLabel2.Text = "Прочитаны данные (message): 0x" + Clscrfl.ByteArrayToString(_rawMsg);

                return;
            }

            if (_fPCSC)
            {
                try
                {
                    const ushort SC_OK = 0x9000;
                    APDUResponse apduResp;

                    if (Clscrfl._ucTagType == 4)
                    {
                        APDUCommand apduSelectApp = new APDUCommand(0x00, 0xA4, 0x04, 0x00, new byte[] { 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x01 }, 0x00);

                        apduResp = _iCard.Transmit(apduSelectApp);

                        if (apduResp.Status != SC_OK)
                        {
                            apduSelectApp = new APDUCommand(0x00, 0xA4, 0x04, 0x00, new byte[] { 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x00 }, 0x00);

                            apduResp = _iCard.Transmit(apduSelectApp);

                            if (apduResp.Status != SC_OK)
                            {
                                toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                                return;
                            }
                        }

                        APDUCommand apduSelectCC = new APDUCommand(0x00, 0xA4, 0x00, 0x0C, new byte[] { 0xE1, 0x03 }, 0x00);

                        apduResp = _iCard.Transmit(apduSelectCC);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        APDUCommand apduReadCC = new APDUCommand(0x00, 0xB0, 0x00, 0x00, new byte[] { }, 0x00);

                        apduResp = _iCard.Transmit(apduReadCC);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        if (apduResp.Data[13] != 0x00)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: Файл NDEF в метке защищена от чтения.";

                            return;
                        }

                        if (apduResp.Data[14] != 0x00)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: Файл NDEF в метке защищена от записи.";

                            return;
                        }

                        int iMaxLe = apduResp.Data[3] * 256 + apduResp.Data[4] - 2;
                        int iMaxLc = apduResp.Data[5] * 256 + apduResp.Data[6];
                        int iMaxNDEFSize = apduResp.Data[11] * 256 + apduResp.Data[12];

                        APDUCommand apduSelectNDEF = new APDUCommand(0x00, 0xA4, 0x00, 0x00, new byte[] { apduResp.Data[9], apduResp.Data[10] }, 0x00);

                        apduResp = _iCard.Transmit(apduSelectNDEF);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        APDUCommand apduReadNLEN = new APDUCommand(0x00, 0xB0, 0x00, 0x00, null, 0x02);

                        apduResp = _iCard.Transmit(apduReadNLEN);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        uint LenNDEF = (uint)apduResp.Data[0] * 256 + apduResp.Data[1];

                        _rawMsg = new byte[0];

                        uint uiReadPos = 2;
                        byte ucReadSize = 0;
                        while (uiReadPos - 2 < LenNDEF)
                        {
                            if (LenNDEF - uiReadPos + 2 > iMaxLe)
                                ucReadSize = (byte)iMaxLe;
                            else
                                ucReadSize = (byte)(LenNDEF - uiReadPos + 2);

                            APDUCommand apduReadNDEF = new APDUCommand(0x00, 0xB0, (byte)((uiReadPos - (uiReadPos % 0x100)) / 0x100), (byte)(uiReadPos % 0x100), null, ucReadSize);

                            apduResp = _iCard.Transmit(apduReadNDEF);

                            if (apduResp.Status != SC_OK)
                            {
                                toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                                return;
                            }

                            _rawMsg = _rawMsg.Concat(apduResp.Data.Take(apduResp.Data.Length)).ToArray();

                            uiReadPos += ucReadSize;
                        }
                    }

                    if (Clscrfl._ucTagType == 2)
                    {
                        APDUCommand apduReadMFUL = new APDUCommand(0xFF, 0xC2, 0x00, 0x01, new byte[] { 0x90, 0x02, 0x00, 0x00, 0x95, 0x02, 0x30, 0x00 }, 0x00);

                        apduResp = _iCard.Transmit(apduReadMFUL);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        if ((apduResp.Data.Length != 0x20) || (apduResp.Data[15] != 0x10))
                        {
                            toolStripStatusLabel2.Text = "Ошибка чтения!";

                            return;
                        }

                        if (apduResp.Data.Skip(16).Take(16).ToArray()[12] != 0xE1)
                        {
                            toolStripStatusLabel2.Text = "Метка не отформатирована под стандарт NFC Forum Tag Type 2";
                            return;
                        }

                        int iTagDataPages = apduResp.Data.Skip(16).Take(16).ToArray()[14] * 8 / 4;

                        bool fReadOnly = (apduResp.Data.Skip(16).Take(16).ToArray()[15] == 0x0F);

                        pByteBuff = new byte[0];

                        for (byte nPage = 0; nPage < (byte)Math.Ceiling((double)iTagDataPages / 4); nPage++)
                        {
                            apduReadMFUL = new APDUCommand(0xFF, 0xC2, 0x00, 0x01, new byte[] { 0x90, 0x02, 0x00, 0x00, 0x95, 0x02, 0x30, (byte)(4 * nPage + 4) }, 0x00);

                            apduResp = _iCard.Transmit(apduReadMFUL);

                            if (apduResp.Status != SC_OK)
                            {
                                toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                                return;
                            }

                            if ((apduResp.Data.Length != 0x20) || (apduResp.Data[15] != 0x10))
                            {
                                toolStripStatusLabel2.Text = "Ошибка чтения!";

                                return;
                            }

                            pByteBuff = pByteBuff.Concat(apduResp.Data.Skip(16).Take(16)).ToArray();

                            if ((Tlv.fromByteArray(pByteBuff, 0)).Last().type() == (byte)Tlv.TlvType.Terminator)
                                break;
                        }

                        toolStripStatusLabel2.Text = "Прочитаны данные (message): 0x" + Clscrfl.ByteArrayToString(pByteBuff);

                        List<Tlv> ltlv = Tlv.fromByteArray(pByteBuff, 0);

                        foreach (Tlv tlv in ltlv)
                        {
                            if (tlv.type() != (byte)Tlv.TlvType.NDEF)
                                continue;

                            _rawMsg = tlv.value();

                            if (_rawMsg.Length == 0)
                                continue;

                            try
                            {
                                ParseNDEF();

                                toolStripStatusLabel2.Text = (fReadOnly ? "Метка - только для чтения. " : "") + "Прочитаны данные (message): 0x" + Clscrfl.ByteArrayToString(_rawMsg);

                                return;
                            }
                            catch (NdefException ex)
                            {
                                toolStripStatusLabel2.Text = ex.Message;

                                return;
                            }
                        }

                        toolStripStatusLabel2.Text = (fReadOnly ? "Метка - только для чтения. " : "") + "Инициализированная, пустая метка";

                    }

                    try
                    {
                        ParseNDEF();

                        toolStripStatusLabel2.Text = "Прочитаны данные (message): 0x" + Clscrfl.ByteArrayToString(_rawMsg);
                    }
                    catch (NdefException ex)
                    {
                        toolStripStatusLabel2.Text = "Ошибка формата NDEF: 0x" + ex.HResult.ToString("X");
                    }
                }
                catch (SmartCardException ex)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + ex.HResult.ToString("X");
                } 
                
                return;
            }

#if (!NFC_CLSCRFL)
            if (Clscrfl._ucTagType == 4)
            {
                byte SW1, SW2;

                byte[] SelectAppCAPDU = new byte[] { 0x00, 0xA4, 0x04, 0x00, 0x07, 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x01, 0x00 };
                byte[] SelectAppRAPDU = null;

                uint Status = Clscrfl.TransceiveTCL(pReader, SelectAppCAPDU, ref SelectAppRAPDU);

                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

            	if (SelectAppRAPDU.Length < 2)
			        return;

                SW1 = SelectAppRAPDU[SelectAppRAPDU.Length - 2];
                SW2 = SelectAppRAPDU[SelectAppRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    SelectAppCAPDU = new byte[] { 0x00, 0xA4, 0x04, 0x00, 0x07, 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x00, 0x00 };
                    SelectAppRAPDU = null;

                    Status = Clscrfl.TransceiveTCL(pReader, SelectAppCAPDU, ref SelectAppRAPDU);

                    if (Status != 0)
                    {
                        toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                        return;
                    }

            	    if (SelectAppRAPDU.Length < 2)
			            return;

                    SW1 = SelectAppRAPDU[SelectAppRAPDU.Length - 2];
                    SW2 = SelectAppRAPDU[SelectAppRAPDU.Length - 1];
                    if (SW1 != 0x90 || SW2 != 0x00)
                    {
                        toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                        return;
                    }
                }
                //if (Status == 0)
                //{
                //    toolStripStatusLabel2.Text = "Ответ RAPDU: 0x" + Clscrfl.ByteArrayToString(SelectAppRAPDU);

                //    return;
                //}

                byte[] SelectCCCAPDU = new byte[] { 0x00, 0xA4, 0x00, 0x0C, 0x02, 0xE1, 0x03 };
                byte[] SelectCCRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, SelectCCCAPDU, ref SelectCCRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }
                SW1 = SelectCCRAPDU[SelectCCRAPDU.Length - 2];
                SW2 = SelectCCRAPDU[SelectCCRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                byte[] ReadCCCAPDU = new byte[] { 0x00, 0xB0, 0x00, 0x00, 0x00 };
                byte[] ReadCCRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, ReadCCCAPDU, ref ReadCCRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }
                SW1 = ReadCCRAPDU[ReadCCRAPDU.Length - 2];
                SW2 = ReadCCRAPDU[ReadCCRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                if (ReadCCRAPDU[13] != 0x00)
                {
                    toolStripStatusLabel2.Text = "Запись NDEF в метке защищена от чтения.";
                    return;
                }

                int iMaxLe = ReadCCRAPDU[3] * 256 + ReadCCRAPDU[4] - 2;
                int iMaxLc = ReadCCRAPDU[5] * 256 + ReadCCRAPDU[6];

                byte[] SelectNDEFCAPDU = new byte[] { 0x00, 0xA4, 0x00, 0x00, 0x02, ReadCCRAPDU[9], ReadCCRAPDU[10] };
                byte[] SelectNDEFRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, SelectNDEFCAPDU, ref SelectNDEFRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }
                SW1 = SelectNDEFRAPDU[SelectNDEFRAPDU.Length - 2];
                SW2 = SelectNDEFRAPDU[SelectNDEFRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                byte[] ReadNLENCAPDU = new byte[] { 0x00, 0xB0, 0x00, 0x00, 0x02 };
                byte[] ReadNLENRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, ReadNLENCAPDU, ref ReadNLENRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }
                SW1 = ReadNLENRAPDU[ReadNLENRAPDU.Length - 2];
                SW2 = ReadNLENRAPDU[ReadNLENRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                uint LenNDEF = (uint)ReadNLENRAPDU[0] * 256 + ReadNLENRAPDU[1];
                //byte[] pbNDEF = new byte[0];
                //pbNDEF[0] = ReadNLENRAPDU[0];
                //pbNDEF[1] = ReadNLENRAPDU[1];

                _rawMsg = new byte[0];

                uint uiReadPos = 2;
                byte ucReadSize = 0;
                while (uiReadPos - 2 < LenNDEF)
                {
                    if (LenNDEF - uiReadPos > iMaxLe)
                        ucReadSize = (byte)iMaxLe;
                    else
                        ucReadSize = (byte)(LenNDEF - uiReadPos + 2);

                    byte[] ReadNDEFCAPDU = new byte[] { 0x00, 0xB0, (byte)((uiReadPos - (uiReadPos % 0x100)) / 0x100), (byte)(uiReadPos % 0x100), ucReadSize };
                    byte[] ReadNDEFRAPDU = null;

                    Status = Clscrfl.TransceiveTCL(pReader, ReadNDEFCAPDU, ref ReadNDEFRAPDU);
                    if (Status != 0)
                    {
                        toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                        return;
                    }
                    SW1 = ReadNDEFRAPDU[ReadNDEFRAPDU.Length - 2];
                    SW2 = ReadNDEFRAPDU[ReadNDEFRAPDU.Length - 1];
                    if (SW1 != 0x90 || SW2 != 0x00)
                    {
                        toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                        return;
                    }

                    _rawMsg = _rawMsg.Concat(ReadNDEFRAPDU.Take(ReadNDEFRAPDU.Length - 2)).ToArray();

                    uiReadPos += ucReadSize;
                }

                try
                {
                    ParseNDEF();
                }
                catch (NdefException ex)
                {
                    return;// (uint)ex.HResult;
                }

                return;
            }

            if (Clscrfl._ucTagType == 2)
            {
                var pRecBuff = Marshal.AllocHGlobal(1024);

                uint err = Clscrfl.CLSCRF_MifareUltralight_Read(pReader, 0x00, pRecBuff);

                if (err != 0)
                {
                    Marshal.FreeHGlobal(pRecBuff);
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");
                    return;
                }

                Marshal.Copy(pRecBuff, pByteBuff, 0, 16);

                if (pByteBuff[12] != 0xE1)
                {
                    Marshal.FreeHGlobal(pRecBuff);
                    toolStripStatusLabel2.Text = "Метка не отформатирована под стандарт NFC Forum Tag Type 2";
                    return;
                }

                int iTagDataPages = pByteBuff[14] * 8 / 4;

                bool fReadOnly = (pByteBuff[15] == 0x0F);

                for (byte nPage = 0; nPage < (byte)Math.Ceiling((double)iTagDataPages / 4); nPage++)
                {
                    IntPtr ptr = pRecBuff;
                    err = Clscrfl.CLSCRF_MifareUltralight_Read(pReader, (byte)(4 * nPage + 4), ptr);

                    if (err != 0)
                    {
                        Marshal.FreeHGlobal(pRecBuff);
                        toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");
                        return;
                    }

                    Marshal.Copy(pRecBuff, pByteBuff, 16 * nPage, 16);

                    if ((Tlv.fromByteArray(pByteBuff, 0)).Last().type() == (byte)Tlv.TlvType.Terminator)
                        break;
                }

                Marshal.FreeHGlobal(pRecBuff);

                List<Tlv> ltlv = Tlv.fromByteArray(pByteBuff, 0);

                foreach (Tlv tlv in ltlv)
                {
                    if (tlv.type() != (byte)Tlv.TlvType.NDEF)
                        continue;

                    _rawMsg = tlv.value();

                    if (_rawMsg.Length == 0)
                        continue;

                    try
                    {
                        ParseNDEF();

                        toolStripStatusLabel2.Text = (fReadOnly ? "Метка - только для чтения. " : "") + "Прочитаны данные (message): 0x" + Clscrfl.ByteArrayToString(_rawMsg);

                        return;
                    }
                    catch (NdefException ex)
                    {
                        toolStripStatusLabel2.Text = ex.Message;

                        return;
                    }
                }

                toolStripStatusLabel2.Text = (fReadOnly ? "Метка - только для чтения. " : "") + "Инициализированная, пустая метка";
            }
#else
            var pRecBuff = Marshal.AllocHGlobal(pByteBuff.Length);
            uint uiRecSize = (uint)pByteBuff.Length;
            byte ucPermissions = 0;
            uint err = Clscrfl.CLSCRF_NFC_ForumTags_Read(pReader, Clscrfl._ucTagType, pRecBuff, ref uiRecSize, ref ucPermissions);
            if (err != 0)
            {

                toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");

                return;
            }
            Marshal.Copy(pRecBuff, pByteBuff, 0, (int)uiRecSize);
            Marshal.FreeHGlobal(pRecBuff);
            _rawMsg = pByteBuff;

            if (_rawMsg.Length > 0)
            {
                try
                {
                    ParseNDEF();

                    toolStripStatusLabel2.Text = ((ucPermissions == 0x0F) ? "Метка - только для чтения. " : "") + "Прочитаны данные (message): 0x" + Clscrfl.ByteArrayToString(_rawMsg);

                    return;
                }
                catch (NdefException ex)
                {
                    toolStripStatusLabel2.Text = ex.Message;

                    return;
                }
            }

            toolStripStatusLabel2.Text = ((ucPermissions == 0x0F) ? "Метка - только для чтения. " : "") + "Инициализированная, пустая метка";
#endif
        }

        private byte[] PrepareNDEF()
        {
            var message = new NdefMessage();

            if (checkBoxText.Checked)
            {
                message.Add(new NdefTextRecord
                {
                    Text = textBoxRecordText.Text,
                    LanguageCode = textBoxRecordTextLangCode.Text
                });
            }
            if (checkBoxURI.Checked)
            {
                message.Add(new NdefUriRecord
                {
                    Uri = textBoxRecordURI.Text
                });
            }
            if (checkBoxSMS.Checked)
            {
                message.Add(new NdefSmsRecord
                {
                    SmsNumber = textBoxRecordSMSNumber.Text,
                    SmsBody = textBoxRecordSMSBody.Text
                });
            }
            if (checkBoxEMail.Checked)
            {
                message.Add(new NdefMailtoRecord
                {
                    Address = textBoxRecordEMAILAddress.Text,
                    Subject = textBoxRecordEMAILSubject.Text,
                    Body = textBoxRecordEMAILBody.Text
                });
            }
            if (checkBoxTel.Checked)
            {
                message.Add(new NdefTelRecord
                {
                    TelNumber = textBoxRecordTelNumber.Text,
                });
            }
            if (checkBoxWriteRawRecord.Checked)
            {
                var encodedText = Encoding.UTF8.GetBytes(textBoxPayload.Text.Replace("\r\n", "\n"));
                //// Calculate the length of the payload & create the array
                //var payloadLength = encodedText.Length;
                //byte[] Payload = new byte[payloadLength];

                //// Text
                //Array.Copy(encodedText, 0, Payload, 0, payloadLength);
                NdefRecord.TypeNameFormatType TNF = NdefRecord.TypeNameFormatType.Empty;

                if (textBoxTNF.Text == NdefRecord.TypeNameFormatType.Empty.ToString())
                    TNF = NdefRecord.TypeNameFormatType.Empty;
                if (textBoxTNF.Text == NdefRecord.TypeNameFormatType.ExternalRtd.ToString())
                    TNF = NdefRecord.TypeNameFormatType.ExternalRtd;
                if (textBoxTNF.Text == NdefRecord.TypeNameFormatType.Mime.ToString())
                    TNF = NdefRecord.TypeNameFormatType.Mime;
                if (textBoxTNF.Text == NdefRecord.TypeNameFormatType.NfcRtd.ToString())
                    TNF = NdefRecord.TypeNameFormatType.NfcRtd;
                if (textBoxTNF.Text == NdefRecord.TypeNameFormatType.Reserved.ToString())
                    TNF = NdefRecord.TypeNameFormatType.Reserved;
                if (textBoxTNF.Text == NdefRecord.TypeNameFormatType.Unchanged.ToString())
                    TNF = NdefRecord.TypeNameFormatType.Unchanged;
                if (textBoxTNF.Text == NdefRecord.TypeNameFormatType.Unknown.ToString())
                    TNF = NdefRecord.TypeNameFormatType.Unknown;
                if (textBoxTNF.Text == NdefRecord.TypeNameFormatType.Uri.ToString())
                    TNF = NdefRecord.TypeNameFormatType.Uri;

                var encodedType = Encoding.UTF8.GetBytes(textBoxType.Text);

                message.Add(new NdefRecord
                {
                    TypeNameFormat = TNF,
                    Type = encodedType,
                    Payload = encodedText
                });
            }

            return message.ToByteArray();
        }

        private uint WriteP2P()
        {
            byte[] rawMsg = PrepareNDEF();

            if (rawMsg.Length == 0)
            {
                toolStripStatusLabel2.Text = "Ошибка! Нет данных для отправки!";
                return 1;
            }

            IntPtr hLLCPLink = IntPtr.Zero;
            uint Status = 0;

            Status = Clscrfl.CLSCRF_NFC_LLCP_Create(pReader, ref hLLCPLink);
            if (Status != 0)
            {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

            Status = Clscrfl.CLSCRF_NFC_LLCP_SetBaudrate(hLLCPLink, 0);
            if (Status != 0)
            {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

            IntPtr hSNEP = IntPtr.Zero;
            Status = Clscrfl.CLSCRF_NFC_SNEP_Create(hLLCPLink, ref hSNEP);
            if (Status != 0)
            {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

            var pbSendBuffer = Marshal.AllocHGlobal(rawMsg.Length);
            Marshal.Copy(rawMsg, 0, pbSendBuffer, rawMsg.Length);
            Status = Clscrfl.CLSCRF_NFC_SNEP_Transmit(hSNEP, pbSendBuffer, (uint)rawMsg.Length);
            Marshal.FreeHGlobal(pbSendBuffer);
            if (Status != 0)
            {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

            Status = Clscrfl.CLSCRF_NFC_SNEP_Destroy(hSNEP);
            if (Status != 0)
            {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

            Status = Clscrfl.CLSCRF_NFC_LLCP_Destroy(hLLCPLink);
            if (Status != 0)
            {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                return Status;
            }

            return Status;
        }

        private void buttonWriteNDEF_Click(object sender, EventArgs e)
        {
            if (Clscrfl._fISO18092)
            {
                uint Status = WriteP2P();

                Clscrfl.CLSCRF_Mfrc_Off(pReader);

                buttonFormatNFCTag.Enabled = false;
                buttonReadNDEF.Enabled = false;
                buttonWriteNDEF.Enabled = false;

                if (Status != 0)
                {
                    return;
                }

                toolStripStatusLabel2.Text = "OK: Данные успешно отправлены на удаленное устройство NFC P2P!";

                return;
            }

            byte[] arrNDEF = PrepareNDEF();

            if (_fPCSC)
            {
                const ushort SC_OK = 0x9000;
                APDUResponse apduResp;

                try
                {
                    if (Clscrfl._ucTagType == 4)
                    {
                        APDUCommand apduSelectApp = new APDUCommand(0x00, 0xA4, 0x04, 0x00, new byte[] { 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x01 }, 0x00);

                        apduResp = _iCard.Transmit(apduSelectApp);

                        if (apduResp.Status != SC_OK)
                        {
                            apduSelectApp = new APDUCommand(0x00, 0xA4, 0x04, 0x00, new byte[] { 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x00 }, 0x00);

                            apduResp = _iCard.Transmit(apduSelectApp);

                            if (apduResp.Status != SC_OK)
                            {
                                toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                                return;
                            }
                        }

                        APDUCommand apduSelectCC = new APDUCommand(0x00, 0xA4, 0x00, 0x0C, new byte[] { 0xE1, 0x03 }, 0x00);

                        apduResp = _iCard.Transmit(apduSelectCC);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        APDUCommand apduReadCC = new APDUCommand(0x00, 0xB0, 0x00, 0x00, new byte[] { }, 0x00);

                        apduResp = _iCard.Transmit(apduReadCC);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        if (apduResp.Data[13] != 0x00)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: Файл NDEF в метке защищена от чтения.";

                            return;
                        }

                        if (apduResp.Data[14] != 0x00)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: Файл NDEF в метке защищена от записи.";

                            return;
                        }

                        int iMaxLe = apduResp.Data[3] * 256 + apduResp.Data[4];
                        int iMaxLc = apduResp.Data[5] * 256 + apduResp.Data[6];
                        int iMaxNDEFSize = apduResp.Data[11] * 256 + apduResp.Data[12];

                        if (iMaxNDEFSize < arrNDEF.Length)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: Недостаточный размер файла NDEF.";
                            return;
                        }

                        APDUCommand apduSelectNDEF = new APDUCommand(0x00, 0xA4, 0x00, 0x00, new byte[] { apduResp.Data[9], apduResp.Data[10] }, 0x00);

                        apduResp = _iCard.Transmit(apduSelectNDEF);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        APDUCommand apduWriteNLEN1 = new APDUCommand(0x00, 0xD6, 0x00, 0x00, new byte[] { 0x00, 0x00 }, 0x00);

                        apduResp = _iCard.Transmit(apduWriteNLEN1);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        uint uiWritePos = 2;
                        byte ucWriteSize = 0;
                        while (uiWritePos - 2 < arrNDEF.Length)
                        {
                            if (arrNDEF.Length - uiWritePos + 2 > iMaxLc)
                                ucWriteSize = (byte)iMaxLc;
                            else
                                ucWriteSize = (byte)(arrNDEF.Length - uiWritePos + 2);

                            APDUCommand apduWriteNDEF = new APDUCommand(0x00, 0xD6, (byte)((uiWritePos - (uiWritePos % 0x100)) / 0x100), (byte)(uiWritePos % 0x100), arrNDEF.Skip((int)uiWritePos - 2).Take(ucWriteSize).ToArray(), 0x00);

                            apduResp = _iCard.Transmit(apduWriteNDEF);

                            if (apduResp.Status != SC_OK)
                            {
                                toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                                return;
                            }

                            uiWritePos += ucWriteSize;
                        }

                        APDUCommand apduWriteNLEN2 = new APDUCommand(0x00, 0xD6, 0x00, 0x00, new byte[] { (byte)Math.Floor((double)arrNDEF.Length / 256), (byte)(arrNDEF.Length % 256) }, 0x00);

                        apduResp = _iCard.Transmit(apduWriteNLEN2);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        toolStripStatusLabel2.Text = "OK: Метка NFC Forum Tag Type 4 успешно записана.";

                        return;
                    }

                    if (Clscrfl._ucTagType == 2)
                    {
                        APDUCommand apduReadMFUL = new APDUCommand(0xFF, 0xC2, 0x00, 0x01, new byte[] { 0x90, 0x02, 0x00, 0x00, 0x95, 0x02, 0x30, 0x00 }, 0x00);

                        apduResp = _iCard.Transmit(apduReadMFUL);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        if ((apduResp.Data.Length != 0x20) || (apduResp.Data[15] != 0x10))
                        {
                            toolStripStatusLabel2.Text = "Ошибка чтения!";

                            return;
                        }

                        if (apduResp.Data.Skip(16).Take(16).ToArray()[12] != 0xE1)
                        {
                            toolStripStatusLabel2.Text = "Метка не отформатирована под стандарт NFC Forum Tag Type 2";
                            return;
                        }

                        int iTagDataPages = apduResp.Data.Skip(16).Take(16).ToArray()[14] * 8 / 4;

                        bool fReadOnly = (apduResp.Data.Skip(16).Take(16).ToArray()[15] == 0x0F);

                        if (fReadOnly)
                        {
                            toolStripStatusLabel2.Text = "Метка только для чтения!";
                            return;
                        }

                        byte[] BArr = Tlv.createTestLockControlTlv().toByteArray().Concat(
                                        Tlv.createNDEFMessageTlv(PrepareNDEF()).toByteArray()).Concat(
                                        Tlv.createTerminatorTlv().toByteArray()).ToArray();

                        for (byte nPage = 0; nPage < (byte)Math.Ceiling((double)BArr.Length / 4); nPage++)
                        {
                            APDUCommand apduWriteMFUL = new APDUCommand(0xFF, 0xC2, 0x00, 0x01, new byte[] { 0x90, 0x02, 0x00, 0x00, 0x95, 0x06, 0xA2, (byte)(4 + nPage), BArr[4 * nPage], BArr[4 * nPage + 1], BArr[4 * nPage + 2], BArr[4 * nPage + 3] }, 0x00);

                            apduResp = _iCard.Transmit(apduWriteMFUL);

                            if (apduResp.Status != SC_OK)
                            {
                                toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");
                                return;
                            }
                        }

                        toolStripStatusLabel2.Text = "OK: Метка NFC Forum Tag Type 2 успешно записана.";
                    }

                }
                catch (SmartCardException ex)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + ex.HResult.ToString("X");
                }

                return;
            }

#if (!NFC_CLSCRFL)
            if (Clscrfl._ucTagType == 4)
            {
                byte SW1, SW2;

                byte[] SelectAppCAPDU = new byte[] { 0x00, 0xA4, 0x04, 0x00, 0x07, 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x01, 0x00 };
                byte[] SelectAppRAPDU = null;

                uint Status = Clscrfl.TransceiveTCL(pReader, SelectAppCAPDU, ref SelectAppRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

               	if (SelectAppRAPDU.Length < 2)
			        return;

                SW1 = SelectAppRAPDU[SelectAppRAPDU.Length - 2];
                SW2 = SelectAppRAPDU[SelectAppRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    SelectAppCAPDU = new byte[] { 0x00, 0xA4, 0x04, 0x00, 0x07, 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x00, 0x00 };
                    SelectAppRAPDU = null;

                    Status = Clscrfl.TransceiveTCL(pReader, SelectAppCAPDU, ref SelectAppRAPDU);
                    if (Status != 0)
                    {
                        toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                        return;
                    }

               	    if (SelectAppRAPDU.Length < 2)
			            return;

                    SW1 = SelectAppRAPDU[SelectAppRAPDU.Length - 2];
                    SW2 = SelectAppRAPDU[SelectAppRAPDU.Length - 1];
                    if (SW1 != 0x90 || SW2 != 0x00)
                    {
                        toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                        return;
                    }
                }

                byte[] SelectCCCAPDU = new byte[] { 0x00, 0xA4, 0x00, 0x0C, 0x02, 0xE1, 0x03 };
                byte[] SelectCCRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, SelectCCCAPDU, ref SelectCCRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }
                SW1 = SelectCCRAPDU[SelectCCRAPDU.Length - 2];
                SW2 = SelectCCRAPDU[SelectCCRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                byte[] ReadCCCAPDU = new byte[] { 0x00, 0xB0, 0x00, 0x00, 0x00 };
                byte[] ReadCCRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, ReadCCCAPDU, ref ReadCCRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

                SW1 = ReadCCRAPDU[ReadCCRAPDU.Length - 2];
                SW2 = ReadCCRAPDU[ReadCCRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                if (ReadCCRAPDU[13] != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка: Файл NDEF в метке защищен от чтения.";
                    return;
                }

                if (ReadCCRAPDU[14] != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка: Файл NDEF в метке защищен от записи.";
                    return;
                }

                int iMaxLe = ReadCCRAPDU[3] * 256 + ReadCCRAPDU[4];
                int iMaxLc = ReadCCRAPDU[5] * 256 + ReadCCRAPDU[6];
                int iMaxNDEFSize = ReadCCRAPDU[11] * 256 + ReadCCRAPDU[12];

                if (iMaxNDEFSize < arrNDEF.Length)
                {
                    toolStripStatusLabel2.Text = "Ошибка: Недостаточный размер файла NDEF.";
                    return;
                }

                byte[] SelectNDEFCAPDU = new byte[] { 0x00, 0xA4, 0x00, 0x00, 0x02, ReadCCRAPDU[9], ReadCCRAPDU[10] };
                byte[] SelectNDEFRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, SelectNDEFCAPDU, ref SelectNDEFRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

                SW1 = SelectNDEFRAPDU[SelectNDEFRAPDU.Length - 2];
                SW2 = SelectNDEFRAPDU[SelectNDEFRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                byte[] WriteNLENCAPDU1 = new byte[] { 0x00, 0xD6, 0x00, 0x00, 0x02, 0x00, 0x00 };
                byte[] WriteNLENRAPDU1 = null;

                Status = Clscrfl.TransceiveTCL(pReader, WriteNLENCAPDU1, ref WriteNLENRAPDU1);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

                SW1 = WriteNLENRAPDU1[WriteNLENRAPDU1.Length - 2];
                SW2 = WriteNLENRAPDU1[WriteNLENRAPDU1.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                uint uiWritePos = 2;
                byte ucWriteSize = 0;
                while (uiWritePos - 2 < arrNDEF.Length)
                {
                    if (arrNDEF.Length - uiWritePos + 2 > iMaxLc)
                        ucWriteSize = (byte)iMaxLc;
                    else
                        ucWriteSize = (byte)(arrNDEF.Length - uiWritePos + 2);

                    byte[] WriteNDEFCAPDU = new byte[] { 0x00, 0xD6, (byte)((uiWritePos - (uiWritePos % 0x100)) / 0x100), (byte)(uiWritePos % 0x100), ucWriteSize };
                    WriteNDEFCAPDU = WriteNDEFCAPDU.Concat(arrNDEF.Skip((int)uiWritePos - 2).Take(ucWriteSize)).ToArray();
                    byte[] WriteNDEFRAPDU = null;

                    Status = Clscrfl.TransceiveTCL(pReader, WriteNDEFCAPDU, ref WriteNDEFRAPDU);
                    if (Status != 0)
                    {
                        toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                        return;
                    }

                    SW1 = WriteNDEFRAPDU[WriteNDEFRAPDU.Length - 2];
                    SW2 = WriteNDEFRAPDU[WriteNDEFRAPDU.Length - 1];
                    if (SW1 != 0x90 || SW2 != 0x00)
                    {
                        toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                        return;
                    }

                    uiWritePos += ucWriteSize;
                }

                byte[] WriteNLENCAPDU2 = new byte[] { 0x00, 0xD6, 0x00, 0x00, 0x02, (byte)Math.Floor((double)arrNDEF.Length / 256), (byte)(arrNDEF.Length % 256) };
                byte[] WriteNLENRAPDU2 = null;

                Status = Clscrfl.TransceiveTCL(pReader, WriteNLENCAPDU2, ref WriteNLENRAPDU2);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

                SW1 = WriteNLENRAPDU2[WriteNLENRAPDU2.Length - 2];
                SW2 = WriteNLENRAPDU2[WriteNLENRAPDU2.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                toolStripStatusLabel2.Text = "OK: Метка NFC Forum Tag Type 4 успешно записана.";

                return;
            }

            if (Clscrfl._ucTagType == 2)
            {
                byte[] BArr = Tlv.createTestLockControlTlv().toByteArray().Concat(
                                            Tlv.createNDEFMessageTlv(PrepareNDEF()).toByteArray()).Concat(
                                            Tlv.createTerminatorTlv().toByteArray()).ToArray();

                var pRecBuff = Marshal.AllocHGlobal(1024);
                byte[] pByteBuff = new byte[1024];

                uint err = Clscrfl.CLSCRF_MifareUltralight_Read(pReader, 0x00, pRecBuff);

                if (err != 0)
                {
                    Marshal.FreeHGlobal(pRecBuff);
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");
                    return;
                }

                Marshal.Copy(pRecBuff, pByteBuff, 0, 16);

                if (pByteBuff[12] != 0xE1)
                {
                    Marshal.FreeHGlobal(pRecBuff);
                    toolStripStatusLabel2.Text = "Метка не отформатирована под стандарт NFC Forum Tag Type 2";
                    return;
                }

                int iTagDataPages = pByteBuff[14] * 8 / 4;

                bool fReadOnly = (pByteBuff[15] == 0x0F);

                if (fReadOnly)
                {
                    Marshal.FreeHGlobal(pRecBuff);
                    toolStripStatusLabel2.Text = "Метка только для чтения!";
                    return;
                }

                var pSendBuff = Marshal.AllocHGlobal(BArr.Length);
                Marshal.Copy(BArr, 0, pSendBuff, BArr.Length);
                for (byte nPage = 0; nPage < (byte)Math.Ceiling((double)BArr.Length / 4); nPage++)
                {
                    IntPtr ptr = new IntPtr(pSendBuff.ToInt64() + 4 * nPage);
                    err = Clscrfl.CLSCRF_MifareUltralight_Write(pReader, (byte)(4 + nPage), ptr);
                    if (err != 0)
                    {
                        toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");

                        Marshal.FreeHGlobal(pSendBuff);

                        return;
                    }
                }
                Marshal.FreeHGlobal(pSendBuff);
            }
#else
            var pSendBuff = Marshal.AllocHGlobal(arrNDEF.Length);
            Marshal.Copy(arrNDEF, 0, pSendBuff, arrNDEF.Length);
            uint err = Clscrfl.CLSCRF_NFC_ForumTags_Write(pReader, Clscrfl._ucTagType, pSendBuff, (uint)arrNDEF.Length);
            Marshal.FreeHGlobal(pSendBuff);
            if (err != 0)
            {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");

                return;
            }
#endif
            toolStripStatusLabel2.Text = "OK: Метка NFC Forum Tag Type 2 успешно записана.";
        }

        private void buttonFormatNFCTag_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Данная операция необратима! Продолжить?", "Внимание!", MessageBoxButtons.OKCancel) != System.Windows.Forms.DialogResult.OK)
                return;

            if (_fPCSC)
            {
                try
                {
                    const ushort SC_OK = 0x9000;
                    APDUResponse apduResp;

                    if (Clscrfl._ucTagType == 4)
                    {
                        APDUCommand apduSelectApp = new APDUCommand(0x00, 0xA4, 0x04, 0x00, new byte[] { 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x01 }, 0x00);

                        apduResp = _iCard.Transmit(apduSelectApp);

                        if (apduResp.Status != SC_OK)
                        {
                            apduSelectApp = new APDUCommand(0x00, 0xA4, 0x04, 0x00, new byte[] { 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x00 }, 0x00);

                            apduResp = _iCard.Transmit(apduSelectApp);

                            if (apduResp.Status != SC_OK)
                            {
                                toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                                return;
                            }
                        }

                        APDUCommand apduSelectCC = new APDUCommand(0x00, 0xA4, 0x00, 0x0C, new byte[] { 0xE1, 0x03 }, 0x00);

                        apduResp = _iCard.Transmit(apduSelectCC);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        APDUCommand apduReadCC = new APDUCommand(0x00, 0xB0, 0x00, 0x00, new byte[] { }, 0x00);

                        apduResp = _iCard.Transmit(apduReadCC);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        if (apduResp.Data[13] != 0x00)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: Файл NDEF в метке защищена от чтения.";

                            return;
                        }

                        if (apduResp.Data[14] != 0x00)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: Файл NDEF в метке защищена от записи.";

                            return;
                        }

                        int iMaxLe = apduResp.Data[3] * 256 + apduResp.Data[4];
                        int iMaxLc = apduResp.Data[5] * 256 + apduResp.Data[6];
                        int iMaxNDEFSize = apduResp.Data[11] * 256 + apduResp.Data[12];

                        APDUCommand apduSelectNDEF = new APDUCommand(0x00, 0xA4, 0x00, 0x00, new byte[] { apduResp.Data[9], apduResp.Data[10] }, 0x00);

                        apduResp = _iCard.Transmit(apduSelectNDEF);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        APDUCommand WriteNLENNDEFAPDU = new APDUCommand(0x00, 0xD6, 0x00, 0x00, new byte[] { 0x00, 0x03, 0xD0, 0x00, 0x00 }, 0x00);

                        apduResp = _iCard.Transmit(WriteNLENNDEFAPDU);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        toolStripStatusLabel2.Text = "OK: Метка NFC Forum Tag Type 4 успешно отформатирована.";

                        return;
                    }

                    if (Clscrfl._ucTagType == 2)
                    {
                        APDUCommand apduReadMFUL = new APDUCommand(0xFF, 0xC2, 0x00, 0x01, new byte[] { 0x90, 0x02, 0x00, 0x00, 0x95, 0x02, 0x30, 0x00 }, 0x00);

                        apduResp = _iCard.Transmit(apduReadMFUL);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");

                            return;
                        }

                        if ((apduResp.Data.Length != 0x20) || (apduResp.Data[15] != 0x10))
                        {
                            toolStripStatusLabel2.Text = "Ошибка чтения!";

                            return;
                        }

                        if (apduResp.Data.Skip(16).Take(16).ToArray()[12] == 0xE1)
                        {
                            toolStripStatusLabel2.Text = "Метка уже отформатирована под стандарт NFC Forum Tag Type 2!";

                            return;
                        }

                        if (apduResp.Data.Skip(16).Take(16).ToArray()[12] != 0x00)
                        {
                            toolStripStatusLabel2.Text = "Невозможно отформатировать метку: уже была запись в биты OTP!";

                            return;
                        }

                        int iTagDataPages = 0;
                        for (byte nPage = 0; nPage < 60; nPage++)
                        {
                            apduReadMFUL = new APDUCommand(0xFF, 0xC2, 0x00, 0x01, new byte[] { 0x90, 0x02, 0x00, 0x00, 0x95, 0x02, 0x30, (byte)(4 * nPage + 4) }, 0x00);

                            apduResp = _iCard.Transmit(apduReadMFUL);

                            if (apduResp.Status != SC_OK)
                            {
                                break;
                            }

                            if ((apduResp.Data.Length != 0x20) || (apduResp.Data[15] != 0x10))
                            {
                                break;
                            }

                            iTagDataPages += 4;
                        }

                        if (iTagDataPages <= 0)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: Недостаточно памяти в метке!";

                            return;
                        }

                        APDUCommand apduWriteMFUL = new APDUCommand(0xFF, 0xC2, 0x00, 0x01, new byte[] { 0x90, 0x02, 0x00, 0x00, 0x95, 0x06, 0xA2, 0x03, 0xE1, 0x10, (byte)Math.Floor((double)(iTagDataPages - 4) * 4 / 8), 0x00 }, 0x00);

                        apduResp = _iCard.Transmit(apduWriteMFUL);

                        if (apduResp.Status != SC_OK)
                        {
                            toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");
                            return;
                        }

                        byte[] BArr = Tlv.createTestLockControlTlv().toByteArray().Concat(
                                        Tlv.createEmptyNDEFMessageTlv().toByteArray()).Concat(
                                        Tlv.createTerminatorTlv().toByteArray()).ToArray();

                        for (byte nPage = 0; nPage < (byte)Math.Floor((double)BArr.Length / 4); nPage++)
                        {
                            apduWriteMFUL = new APDUCommand(0xFF, 0xC2, 0x00, 0x01, new byte[] { 0x90, 0x02, 0x00, 0x00, 0x95, 0x06, 0xA2, (byte)(4 + nPage), BArr[4 * nPage], BArr[4 * nPage + 1], BArr[4 * nPage + 2], BArr[4 * nPage + 3] }, 0x00);

                            apduResp = _iCard.Transmit(apduWriteMFUL);

                            if (apduResp.Status != SC_OK)
                            {
                                toolStripStatusLabel2.Text = "Ошибка: SW1,SW2=" + apduResp.Status.ToString("X");
                                return;
                            }
                        }

                        toolStripStatusLabel2.Text = "OK: Метка NFC Forum Tag Type 2 успешно записана.";
                    }
                }
                catch (SmartCardException ex)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + ex.HResult.ToString("X");
                }

                return;
            }

#if (!NFC_CLSCRFL)
            if (Clscrfl._ucTagType == 4)
            {
                byte SW1, SW2;

                byte[] SelectAppCAPDU = new byte[] { 0x00, 0xA4, 0x04, 0x00, 0x07, 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x01, 0x00 };
                byte[] SelectAppRAPDU = null;

                uint Status = Clscrfl.TransceiveTCL(pReader, SelectAppCAPDU, ref SelectAppRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

               	if (SelectAppRAPDU.Length < 2)
			        return;

                SW1 = SelectAppRAPDU[SelectAppRAPDU.Length - 2];
                SW2 = SelectAppRAPDU[SelectAppRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    SelectAppCAPDU = new byte[] { 0x00, 0xA4, 0x04, 0x00, 0x07, 0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x00, 0x00 };
                    SelectAppRAPDU = null;

                    Status = Clscrfl.TransceiveTCL(pReader, SelectAppCAPDU, ref SelectAppRAPDU);
                    if (Status != 0)
                    {
                        toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                        return;
                    }

               	    if (SelectAppRAPDU.Length < 2)
			            return;

                    SW1 = SelectAppRAPDU[SelectAppRAPDU.Length - 2];
                    SW2 = SelectAppRAPDU[SelectAppRAPDU.Length - 1];
                    if (SW1 != 0x90 || SW2 != 0x00)
                    {
                        toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                        return;
                    }
                }

                byte[] SelectCCCAPDU = new byte[] { 0x00, 0xA4, 0x00, 0x0C, 0x02, 0xE1, 0x03 };
                byte[] SelectCCRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, SelectCCCAPDU, ref SelectCCRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

                SW1 = SelectCCRAPDU[SelectCCRAPDU.Length - 2];
                SW2 = SelectCCRAPDU[SelectCCRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                byte[] ReadCCCAPDU = new byte[] { 0x00, 0xB0, 0x00, 0x00, 0x00 };
                byte[] ReadCCRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, ReadCCCAPDU, ref ReadCCRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

                SW1 = ReadCCRAPDU[ReadCCRAPDU.Length - 2];
                SW2 = ReadCCRAPDU[ReadCCRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                if (ReadCCRAPDU[13] != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка: Файл NDEF в метке защищен от чтения.";
                    return;
                }

                if (ReadCCRAPDU[14] != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка: Файл NDEF в метке защищен от записи.";
                    return;
                }

                int iMaxLe = ReadCCRAPDU[3] * 256 + ReadCCRAPDU[4];
                int iMaxLc = ReadCCRAPDU[5] * 256 + ReadCCRAPDU[6];
                int iMaxNDEFSize = ReadCCRAPDU[11] * 256 + ReadCCRAPDU[12];

                byte[] SelectNDEFCAPDU = new byte[] { 0x00, 0xA4, 0x00, 0x00, 0x02, ReadCCRAPDU[9], ReadCCRAPDU[10] };
                byte[] SelectNDEFRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, SelectNDEFCAPDU, ref SelectNDEFRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

                SW1 = SelectNDEFRAPDU[SelectNDEFRAPDU.Length - 2];
                SW2 = SelectNDEFRAPDU[SelectNDEFRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                byte[] WriteNLENNDEFCAPDU = new byte[] { 0x00, 0xD6, 0x00, 0x00, 0x05, 0x00, 0x03, 0xD0, 0x00, 0x00 };
                byte[] WriteNLENNDEFRAPDU = null;

                Status = Clscrfl.TransceiveTCL(pReader, WriteNLENNDEFCAPDU, ref WriteNLENNDEFRAPDU);
                if (Status != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + Status.ToString("X");
                    return;
                }

                SW1 = WriteNLENNDEFRAPDU[WriteNLENNDEFRAPDU.Length - 2];
                SW2 = WriteNLENNDEFRAPDU[WriteNLENNDEFRAPDU.Length - 1];
                if (SW1 != 0x90 || SW2 != 0x00)
                {
                    toolStripStatusLabel2.Text = "Ошибка SW1: 0x" + SW1.ToString("X") + " SW2: 0x" + SW2.ToString("X");
                    return;
                }

                toolStripStatusLabel2.Text = "OK: Метка NFC Forum Tag Type 4 успешно записана.";

                return;
            }

            if (Clscrfl._ucTagType == 2)
            {
                var pRecBuff = Marshal.AllocHGlobal(1024);
                byte[] pByteBuff = new byte[1024];

                uint err = Clscrfl.CLSCRF_MifareUltralight_Read(pReader, 0x00, pRecBuff);

                if (err != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");
                    Marshal.FreeHGlobal(pRecBuff);
                    return;
                }

                Marshal.Copy(pRecBuff, pByteBuff, 0, 16);

                if (pByteBuff[12] == 0xE1)
                {
                    toolStripStatusLabel2.Text = "Метка уже отформатирована под стандарт NFC Forum Tag Type 2!";
                    Marshal.FreeHGlobal(pRecBuff);
                    return;
                }

                if (pByteBuff[12] != 0x00)
                {
                    toolStripStatusLabel2.Text = "Невозможно отформатировать метку: уже была запись в биты OTP!";
                    Marshal.FreeHGlobal(pRecBuff);
                    return;
                }

                int iTagDataPages = 0;
                for (byte nPage = 0; nPage < 60; nPage++)
                {
                    IntPtr ptr = pRecBuff;
                    err = Clscrfl.CLSCRF_MifareUltralight_Read(pReader, (byte)(4 * nPage + 4), ptr);

                    if (err != 0)
                        break;

                    iTagDataPages += 4;
                }
                Marshal.FreeHGlobal(pRecBuff);

                if (iTagDataPages <= 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: Недостаточно памяти в метке!";

                    return;
                }

                var pSendBuff = Marshal.AllocHGlobal(4);
                Marshal.Copy(new byte[] { 0xE1, 0x10, (byte)Math.Floor((double)(iTagDataPages - 4) * 4 / 8), 0x00 }, 0, pSendBuff, 4);
                err = Clscrfl.CLSCRF_MifareUltralight_Write(pReader, 3, pSendBuff);
                Marshal.FreeHGlobal(pSendBuff);

                if (err != 0)
                {
                    toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");

                    return;
                }

                byte[] BArr = Tlv.createTestLockControlTlv().toByteArray().Concat(
                                Tlv.createEmptyNDEFMessageTlv().toByteArray()).Concat(
                                Tlv.createTerminatorTlv().toByteArray()).ToArray();
                pSendBuff = Marshal.AllocHGlobal(BArr.Length);
                Marshal.Copy(BArr, 0, pSendBuff, BArr.Length);
                for (byte nPage = 0; nPage < (byte)Math.Floor((double)BArr.Length / 4); nPage++)
                {
                    IntPtr ptr = new IntPtr(pSendBuff.ToInt64() + 4 * nPage);
                    err = Clscrfl.CLSCRF_MifareUltralight_Write(pReader, (byte)(4 + nPage), ptr);
                    if (err != 0)
                    {
                        toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");

                        Marshal.FreeHGlobal(pSendBuff);

                        return;
                    }
                }
                Marshal.FreeHGlobal(pSendBuff);
            }
#else
            uint err = Clscrfl.CLSCRF_NFC_ForumTags_Format(pReader, Clscrfl._ucTagType);
            if (err != 0)
            {
                toolStripStatusLabel2.Text = "Ошибка: 0x" + err.ToString("X");

                return;
            }
#endif
            toolStripStatusLabel2.Text = "OK: Метка успешно отформатирована как NFC Forum Tag Type " + Clscrfl._ucTagType.ToString();

        }

        private void buttonRefreshReaders_Click(object sender, EventArgs e)
        {
            DetectPCSCReaders();
        }
    }
}
