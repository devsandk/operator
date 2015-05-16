namespace TestLibNDEFCS
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.buttonOpenUSB = new System.Windows.Forms.Button();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel2 = new System.Windows.Forms.ToolStripStatusLabel();
            this.buttonActivateTag = new System.Windows.Forms.Button();
            this.buttonReadNDEF = new System.Windows.Forms.Button();
            this.textBoxRecordText = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxRecordTextLangCode = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxRecordURI = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxRecordSMSNumber = new System.Windows.Forms.TextBox();
            this.textBoxRecordSMSBody = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBoxRecordEMAILAddress = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.textBoxRecordEMAILSubject = new System.Windows.Forms.TextBox();
            this.textBoxRecordEMAILBody = new System.Windows.Forms.TextBox();
            this.buttonWriteNDEF = new System.Windows.Forms.Button();
            this.buttonFormatNFCTag = new System.Windows.Forms.Button();
            this.checkBoxText = new System.Windows.Forms.CheckBox();
            this.checkBoxURI = new System.Windows.Forms.CheckBox();
            this.checkBoxSMS = new System.Windows.Forms.CheckBox();
            this.checkBoxEMail = new System.Windows.Forms.CheckBox();
            this.checkBoxTel = new System.Windows.Forms.CheckBox();
            this.textBoxRecordTelNumber = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.textBoxPayload = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.textBoxType = new System.Windows.Forms.TextBox();
            this.textBoxTNF = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.comboBoxReaderType = new System.Windows.Forms.ComboBox();
            this.buttonRefreshReaders = new System.Windows.Forms.Button();
            this.checkBoxWriteRawRecord = new System.Windows.Forms.CheckBox();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(308, 313);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Visible = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(227, 313);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 1;
            this.button2.Text = "button2";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Visible = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // buttonOpenUSB
            // 
            this.buttonOpenUSB.Location = new System.Drawing.Point(12, 31);
            this.buttonOpenUSB.Name = "buttonOpenUSB";
            this.buttonOpenUSB.Size = new System.Drawing.Size(216, 23);
            this.buttonOpenUSB.TabIndex = 1;
            this.buttonOpenUSB.Text = "Соединиться со считывателем";
            this.buttonOpenUSB.UseVisualStyleBackColor = true;
            this.buttonOpenUSB.Click += new System.EventHandler(this.buttonOpenUSB_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1,
            this.toolStripStatusLabel2});
            this.statusStrip1.Location = new System.Drawing.Point(0, 339);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(739, 22);
            this.statusStrip1.TabIndex = 3;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(63, 17);
            this.toolStripStatusLabel1.Text = "Результат:";
            // 
            // toolStripStatusLabel2
            // 
            this.toolStripStatusLabel2.Name = "toolStripStatusLabel2";
            this.toolStripStatusLabel2.Size = new System.Drawing.Size(0, 17);
            // 
            // buttonActivateTag
            // 
            this.buttonActivateTag.Enabled = false;
            this.buttonActivateTag.Location = new System.Drawing.Point(12, 60);
            this.buttonActivateTag.Name = "buttonActivateTag";
            this.buttonActivateTag.Size = new System.Drawing.Size(216, 23);
            this.buttonActivateTag.TabIndex = 2;
            this.buttonActivateTag.Text = "Активировать метку / устройство";
            this.buttonActivateTag.UseVisualStyleBackColor = true;
            this.buttonActivateTag.Click += new System.EventHandler(this.buttonActivateTag_Click);
            // 
            // buttonReadNDEF
            // 
            this.buttonReadNDEF.Enabled = false;
            this.buttonReadNDEF.Location = new System.Drawing.Point(12, 89);
            this.buttonReadNDEF.Name = "buttonReadNDEF";
            this.buttonReadNDEF.Size = new System.Drawing.Size(216, 23);
            this.buttonReadNDEF.TabIndex = 3;
            this.buttonReadNDEF.Text = "Прочитать NDEF";
            this.buttonReadNDEF.UseVisualStyleBackColor = true;
            this.buttonReadNDEF.Click += new System.EventHandler(this.buttonReadNDEF_Click);
            // 
            // textBoxRecordText
            // 
            this.textBoxRecordText.Location = new System.Drawing.Point(12, 161);
            this.textBoxRecordText.Multiline = true;
            this.textBoxRecordText.Name = "textBoxRecordText";
            this.textBoxRecordText.Size = new System.Drawing.Size(216, 66);
            this.textBoxRecordText.TabIndex = 6;
            this.textBoxRecordText.Text = "Миру мир!";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 138);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(64, 13);
            this.label1.TabIndex = 11;
            this.label1.Text = "Код языка:";
            // 
            // textBoxRecordTextLangCode
            // 
            this.textBoxRecordTextLangCode.Location = new System.Drawing.Point(82, 135);
            this.textBoxRecordTextLangCode.Name = "textBoxRecordTextLangCode";
            this.textBoxRecordTextLangCode.Size = new System.Drawing.Size(146, 20);
            this.textBoxRecordTextLangCode.TabIndex = 5;
            this.textBoxRecordTextLangCode.Text = "ru";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 253);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 13);
            this.label3.TabIndex = 15;
            this.label3.Text = "URI:";
            // 
            // textBoxRecordURI
            // 
            this.textBoxRecordURI.Location = new System.Drawing.Point(44, 250);
            this.textBoxRecordURI.Name = "textBoxRecordURI";
            this.textBoxRecordURI.Size = new System.Drawing.Size(184, 20);
            this.textBoxRecordURI.TabIndex = 8;
            this.textBoxRecordURI.Text = "http://microem.ru";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(234, 26);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 13);
            this.label2.TabIndex = 17;
            this.label2.Text = "Номер:";
            // 
            // textBoxRecordSMSNumber
            // 
            this.textBoxRecordSMSNumber.Location = new System.Drawing.Point(284, 23);
            this.textBoxRecordSMSNumber.Name = "textBoxRecordSMSNumber";
            this.textBoxRecordSMSNumber.Size = new System.Drawing.Size(179, 20);
            this.textBoxRecordSMSNumber.TabIndex = 10;
            this.textBoxRecordSMSNumber.Text = "+7(111)-222-33-44";
            // 
            // textBoxRecordSMSBody
            // 
            this.textBoxRecordSMSBody.Location = new System.Drawing.Point(234, 49);
            this.textBoxRecordSMSBody.Multiline = true;
            this.textBoxRecordSMSBody.Name = "textBoxRecordSMSBody";
            this.textBoxRecordSMSBody.Size = new System.Drawing.Size(229, 67);
            this.textBoxRecordSMSBody.TabIndex = 11;
            this.textBoxRecordSMSBody.Text = "Hello world!";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(234, 142);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 13);
            this.label4.TabIndex = 20;
            this.label4.Text = "Адресаты:";
            // 
            // textBoxRecordEMAILAddress
            // 
            this.textBoxRecordEMAILAddress.Location = new System.Drawing.Point(300, 139);
            this.textBoxRecordEMAILAddress.Name = "textBoxRecordEMAILAddress";
            this.textBoxRecordEMAILAddress.Size = new System.Drawing.Size(163, 20);
            this.textBoxRecordEMAILAddress.TabIndex = 13;
            this.textBoxRecordEMAILAddress.Text = "test@test.ru";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(234, 165);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(37, 13);
            this.label5.TabIndex = 22;
            this.label5.Text = "Тема:";
            // 
            // textBoxRecordEMAILSubject
            // 
            this.textBoxRecordEMAILSubject.Location = new System.Drawing.Point(277, 162);
            this.textBoxRecordEMAILSubject.Name = "textBoxRecordEMAILSubject";
            this.textBoxRecordEMAILSubject.Size = new System.Drawing.Size(186, 20);
            this.textBoxRecordEMAILSubject.TabIndex = 14;
            this.textBoxRecordEMAILSubject.Text = "Test";
            // 
            // textBoxRecordEMAILBody
            // 
            this.textBoxRecordEMAILBody.Location = new System.Drawing.Point(234, 188);
            this.textBoxRecordEMAILBody.Multiline = true;
            this.textBoxRecordEMAILBody.Name = "textBoxRecordEMAILBody";
            this.textBoxRecordEMAILBody.Size = new System.Drawing.Size(229, 86);
            this.textBoxRecordEMAILBody.TabIndex = 15;
            this.textBoxRecordEMAILBody.Text = "Hello world!";
            // 
            // buttonWriteNDEF
            // 
            this.buttonWriteNDEF.Enabled = false;
            this.buttonWriteNDEF.Location = new System.Drawing.Point(12, 309);
            this.buttonWriteNDEF.Name = "buttonWriteNDEF";
            this.buttonWriteNDEF.Size = new System.Drawing.Size(216, 23);
            this.buttonWriteNDEF.TabIndex = 16;
            this.buttonWriteNDEF.Text = "Записать NDEF";
            this.buttonWriteNDEF.UseVisualStyleBackColor = true;
            this.buttonWriteNDEF.Click += new System.EventHandler(this.buttonWriteNDEF_Click);
            // 
            // buttonFormatNFCTag
            // 
            this.buttonFormatNFCTag.Enabled = false;
            this.buttonFormatNFCTag.Location = new System.Drawing.Point(12, 276);
            this.buttonFormatNFCTag.Name = "buttonFormatNFCTag";
            this.buttonFormatNFCTag.Size = new System.Drawing.Size(216, 23);
            this.buttonFormatNFCTag.TabIndex = 23;
            this.buttonFormatNFCTag.Text = "Форматировать метку";
            this.buttonFormatNFCTag.UseVisualStyleBackColor = true;
            this.buttonFormatNFCTag.Click += new System.EventHandler(this.buttonFormatNFCTag_Click);
            // 
            // checkBoxText
            // 
            this.checkBoxText.AutoSize = true;
            this.checkBoxText.Location = new System.Drawing.Point(12, 118);
            this.checkBoxText.Name = "checkBoxText";
            this.checkBoxText.Size = new System.Drawing.Size(119, 17);
            this.checkBoxText.TabIndex = 24;
            this.checkBoxText.Text = "Текстовая запись";
            this.checkBoxText.UseVisualStyleBackColor = true;
            // 
            // checkBoxURI
            // 
            this.checkBoxURI.AutoSize = true;
            this.checkBoxURI.Location = new System.Drawing.Point(12, 233);
            this.checkBoxURI.Name = "checkBoxURI";
            this.checkBoxURI.Size = new System.Drawing.Size(94, 17);
            this.checkBoxURI.TabIndex = 25;
            this.checkBoxURI.Text = "Запись с URI";
            this.checkBoxURI.UseVisualStyleBackColor = true;
            // 
            // checkBoxSMS
            // 
            this.checkBoxSMS.AutoSize = true;
            this.checkBoxSMS.Location = new System.Drawing.Point(237, 6);
            this.checkBoxSMS.Name = "checkBoxSMS";
            this.checkBoxSMS.Size = new System.Drawing.Size(89, 17);
            this.checkBoxSMS.TabIndex = 26;
            this.checkBoxSMS.Text = "Запись SMS";
            this.checkBoxSMS.UseVisualStyleBackColor = true;
            // 
            // checkBoxEMail
            // 
            this.checkBoxEMail.AutoSize = true;
            this.checkBoxEMail.Location = new System.Drawing.Point(234, 119);
            this.checkBoxEMail.Name = "checkBoxEMail";
            this.checkBoxEMail.Size = new System.Drawing.Size(98, 17);
            this.checkBoxEMail.TabIndex = 27;
            this.checkBoxEMail.Text = "Запись EMAIL";
            this.checkBoxEMail.UseVisualStyleBackColor = true;
            // 
            // checkBoxTel
            // 
            this.checkBoxTel.AutoSize = true;
            this.checkBoxTel.Location = new System.Drawing.Point(237, 280);
            this.checkBoxTel.Name = "checkBoxTel";
            this.checkBoxTel.Size = new System.Drawing.Size(117, 17);
            this.checkBoxTel.TabIndex = 28;
            this.checkBoxTel.Text = "Запись Telephone";
            this.checkBoxTel.UseVisualStyleBackColor = true;
            // 
            // textBoxRecordTelNumber
            // 
            this.textBoxRecordTelNumber.Location = new System.Drawing.Point(284, 297);
            this.textBoxRecordTelNumber.Name = "textBoxRecordTelNumber";
            this.textBoxRecordTelNumber.Size = new System.Drawing.Size(179, 20);
            this.textBoxRecordTelNumber.TabIndex = 29;
            this.textBoxRecordTelNumber.Text = "+7(111)-222-33-44";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(234, 300);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(44, 13);
            this.label6.TabIndex = 30;
            this.label6.Text = "Номер:";
            // 
            // textBoxPayload
            // 
            this.textBoxPayload.Location = new System.Drawing.Point(476, 91);
            this.textBoxPayload.Multiline = true;
            this.textBoxPayload.Name = "textBoxPayload";
            this.textBoxPayload.Size = new System.Drawing.Size(251, 222);
            this.textBoxPayload.TabIndex = 31;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(473, 6);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(84, 13);
            this.label7.TabIndex = 32;
            this.label7.Text = "Общий формат";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(472, 55);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(66, 13);
            this.label8.TabIndex = 33;
            this.label8.Text = "Тип (MIME):";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(473, 75);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(51, 13);
            this.label9.TabIndex = 34;
            this.label9.Text = "Данные:";
            // 
            // textBoxType
            // 
            this.textBoxType.Location = new System.Drawing.Point(544, 52);
            this.textBoxType.Name = "textBoxType";
            this.textBoxType.Size = new System.Drawing.Size(182, 20);
            this.textBoxType.TabIndex = 35;
            // 
            // textBoxTNF
            // 
            this.textBoxTNF.Location = new System.Drawing.Point(563, 26);
            this.textBoxTNF.Name = "textBoxTNF";
            this.textBoxTNF.Size = new System.Drawing.Size(163, 20);
            this.textBoxTNF.TabIndex = 36;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(472, 29);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(85, 13);
            this.label10.TabIndex = 37;
            this.label10.Text = "Формат (TNF): ";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(9, 6);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(76, 13);
            this.label11.TabIndex = 38;
            this.label11.Text = "Считыватель:";
            // 
            // comboBoxReaderType
            // 
            this.comboBoxReaderType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxReaderType.FormattingEnabled = true;
            this.comboBoxReaderType.Location = new System.Drawing.Point(82, 4);
            this.comboBoxReaderType.Name = "comboBoxReaderType";
            this.comboBoxReaderType.Size = new System.Drawing.Size(121, 21);
            this.comboBoxReaderType.TabIndex = 39;
            // 
            // buttonRefreshReaders
            // 
            this.buttonRefreshReaders.Location = new System.Drawing.Point(209, 4);
            this.buttonRefreshReaders.Name = "buttonRefreshReaders";
            this.buttonRefreshReaders.Size = new System.Drawing.Size(22, 21);
            this.buttonRefreshReaders.TabIndex = 40;
            this.buttonRefreshReaders.Text = "@";
            this.buttonRefreshReaders.UseVisualStyleBackColor = true;
            this.buttonRefreshReaders.Click += new System.EventHandler(this.buttonRefreshReaders_Click);
            // 
            // checkBoxWriteRawRecord
            // 
            this.checkBoxWriteRawRecord.AutoSize = true;
            this.checkBoxWriteRawRecord.Location = new System.Drawing.Point(563, 6);
            this.checkBoxWriteRawRecord.Name = "checkBoxWriteRawRecord";
            this.checkBoxWriteRawRecord.Size = new System.Drawing.Size(169, 17);
            this.checkBoxWriteRawRecord.TabIndex = 41;
            this.checkBoxWriteRawRecord.Text = "Записать в общем формате";
            this.checkBoxWriteRawRecord.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(739, 361);
            this.Controls.Add(this.checkBoxWriteRawRecord);
            this.Controls.Add(this.buttonRefreshReaders);
            this.Controls.Add(this.comboBoxReaderType);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.textBoxTNF);
            this.Controls.Add(this.textBoxType);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.textBoxPayload);
            this.Controls.Add(this.textBoxRecordTelNumber);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.checkBoxTel);
            this.Controls.Add(this.checkBoxEMail);
            this.Controls.Add(this.checkBoxSMS);
            this.Controls.Add(this.checkBoxURI);
            this.Controls.Add(this.checkBoxText);
            this.Controls.Add(this.buttonFormatNFCTag);
            this.Controls.Add(this.buttonWriteNDEF);
            this.Controls.Add(this.textBoxRecordEMAILBody);
            this.Controls.Add(this.textBoxRecordEMAILSubject);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.textBoxRecordEMAILAddress);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBoxRecordSMSBody);
            this.Controls.Add(this.textBoxRecordSMSNumber);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBoxRecordURI);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBoxRecordTextLangCode);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxRecordText);
            this.Controls.Add(this.buttonReadNDEF);
            this.Controls.Add(this.buttonActivateTag);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.buttonOpenUSB);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "UEM NFC NDEF Test (NTAG + P2P)";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button buttonOpenUSB;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel2;
        private System.Windows.Forms.Button buttonActivateTag;
        private System.Windows.Forms.Button buttonReadNDEF;
        private System.Windows.Forms.TextBox textBoxRecordText;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxRecordTextLangCode;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxRecordURI;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxRecordSMSNumber;
        private System.Windows.Forms.TextBox textBoxRecordSMSBody;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBoxRecordEMAILAddress;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBoxRecordEMAILSubject;
        private System.Windows.Forms.TextBox textBoxRecordEMAILBody;
        private System.Windows.Forms.Button buttonWriteNDEF;
        private System.Windows.Forms.Button buttonFormatNFCTag;
        private System.Windows.Forms.CheckBox checkBoxText;
        private System.Windows.Forms.CheckBox checkBoxURI;
        private System.Windows.Forms.CheckBox checkBoxSMS;
        private System.Windows.Forms.CheckBox checkBoxEMail;
        private System.Windows.Forms.CheckBox checkBoxTel;
        private System.Windows.Forms.TextBox textBoxRecordTelNumber;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBoxPayload;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox textBoxType;
        private System.Windows.Forms.TextBox textBoxTNF;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.ComboBox comboBoxReaderType;
        private System.Windows.Forms.Button buttonRefreshReaders;
        private System.Windows.Forms.CheckBox checkBoxWriteRawRecord;
    }
}

