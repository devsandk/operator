
// TestNFC663Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "TestNFC663.h"
#include "TestNFC663Dlg.h"
#include "afxdialogex.h"

#include "../../Clscrfl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CTestNFC663Dlg



CTestNFC663Dlg::CTestNFC663Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestNFC663Dlg::IDD, pParent)
	, m_strNDEFText(_T("������, ���!"))
	, m_strResult(_T(""))
	, m_strNDEFUri(_T("http://microem.ru"))
	, m_ucTagType(0xFF)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestNFC663Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NDEF_TEXT, m_strNDEFText);
	DDX_Text(pDX, IDC_EDIT_STATUS, m_strResult);
	DDX_Text(pDX, IDC_EDIT_NDEF_URI, m_strNDEFUri);
}

BEGIN_MESSAGE_MAP(CTestNFC663Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_NDEF_TEXT, &CTestNFC663Dlg::OnBnClickedButtonNdefText)
	ON_BN_CLICKED(IDC_BUTTON_NDEF_TEXT_RECV, &CTestNFC663Dlg::OnBnClickedButtonNdefTextRecv)
	ON_BN_CLICKED(IDC_BUTTON_NDEF_URI_RECV, &CTestNFC663Dlg::OnBnClickedButtonNdefUriRecv)
	ON_BN_CLICKED(IDC_BUTTON_NDEF_URI, &CTestNFC663Dlg::OnBnClickedButtonNdefUri)
END_MESSAGE_MAP()


// ����������� ��������� CTestNFC663Dlg

BOOL CTestNFC663Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CTestNFC663Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CTestNFC663Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LONG CTestNFC663Dlg::StartInterface(void **ppReader)
{
	LONG Status; // ���������� ��� �������� �������, ������������� ��������

	Status = CLSCRF_Create(ppReader); // ������� ������ �����������
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������ ������ ����������!";
		UpdateData(FALSE);
		return Status;
	}

	Status = CLSCRF_OpenUSB(*ppReader); // ��������� ���������� �� ������������ �� USB
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "�� ������ �����������!";
		UpdateData(FALSE);
		CLSCRF_Destroy(ppReader);
		return Status;
	}

	Status = CLSCRF_Mfrc_On(*ppReader); // �������� ���������� �����������
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������ ��������� � �����������!";
		UpdateData(FALSE);
		StopInterface(*ppReader);
		return Status;
	}

	Sleep(50); // ����� ����� ��� ����, ����� ����� ������ ����� � ������� ����� ����� ��������� ���������

	DWORD dwState = 0;

	Status = CLSCRF_GetState(*ppReader, &dwState); // �������� ��������� �����������
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������ ��������� � �����������!";
		UpdateData(FALSE);
		StopInterface(*ppReader);
		return Status;
	}

	BYTE Ver[256] = { 0 };
	Status = CLSCRF_Get_Mfrc_Version(*ppReader, Ver); // ��������� ������ �������������� �����������
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������ ��������� � �����������!";
		UpdateData(FALSE);
		StopInterface(*ppReader);
		return Status;
	}

	BYTE m_FW_Version;
	m_FW_Version = Ver[5];

	if ((dwState & 0xFFUL) != 0x00) // ���� ������� �������� ������ - �� ISO14443A
	{
		Status = CLSCRF_Mfrc_Set_Rf_Mode(*ppReader, 0x00); // ������������� �������� ISO14443A
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������ ��������� � �����������!";
			UpdateData(FALSE);
			StopInterface(*ppReader);
			return Status;
		}
	}

	//Status = CLSCRF_Mfrc_Rf_Off_On(*ppReader, 10);
	//if (Status != SCARD_S_SUCCESS)
	//{
	//	m_strResult = "������ ��������� � �����������!";
	//	UpdateData(FALSE);
	//	StopInterface(*ppReader);
	//	return Status;
	//}

	//Sleep(50);

	BYTE m_UID[10];
	DWORD m_dwUIDLen;
	BYTE m_ATQ[2];
	BYTE m_SAK;

	Status = CLSCRF_Activate_Idle_A(*ppReader, // ������� ������������ ����� � ����
		m_ATQ,// pbATQ 2 bytes
		&m_SAK,// pbSAK 1 byte
		m_UID,// pbUID max 10 bytes
		&m_dwUIDLen);

	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������ ������ �����!";
		UpdateData(FALSE);
		StopInterface(*ppReader);
		return Status;
	}

	// ���������� ��� �����/���������� NFC
	Status = CLSCRF_NFC_ForumTags_SupposeTypeISO14443A(*ppReader, m_ATQ, m_SAK, &m_ucTagType);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������ ��������� � ����������!";
		UpdateData(FALSE);
		StopInterface(*ppReader);
		return Status;
	}

	if (m_ucTagType == 0xFF)
	{
		m_strResult = "��� ����� �� ��������������!";
		UpdateData(FALSE);
		StopInterface(*ppReader);
		return SCARD_E_NO_SMARTCARD;
	}

	// ���� ��������� ����� - ���� NFC Forum Tag Type 4, �� ����� �������������� ��������� � � ����� T=CL
	if (m_ucTagType == 4)
	{
		//BYTE CID = 0;
		//BYTE pbATS[37] = { 0 };

		//// ���������� ����� T=CL
		//Status = CLSCRF_ISO14443A_4_RATS(*ppReader, CID, pbATS);

		//if (Status != SCARD_S_SUCCESS)
		//{
		//	m_strResult = "������ ��������� ������ T=CL!";
		//	UpdateData(FALSE);
		//	StopInterface(*ppReader);
		//	return Status;
		//}

		//// ������������� �������� ������
		//Status = CLSCRF_ISO14443A_4_PPS(*ppReader, CID, 0);

		//if (Status != SCARD_S_SUCCESS)
		//{
		//	m_strResult = "������ ��������� �������� ������ ������ T=CL!";
		//	UpdateData(FALSE);
		//	StopInterface(*ppReader);
		//	return Status;
		//}

		//// ��������� ��������� ������ T=CL
		//Status = CLSCRF_Mfrc_Set_Rf_Mode(*ppReader, 0);

		//if (Status != SCARD_S_SUCCESS)
		//{
		//	m_strResult = "������ ��������� ������ T=CL!";
		//	UpdateData(FALSE);
		//	StopInterface(*ppReader);
		//	return Status;
		//}

		CLSCRF_NFC_ForumTags_BeginType4(*ppReader);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������ ��������� ������ T=CL!";
			UpdateData(FALSE);
			StopInterface(*ppReader);
			return Status;
		}
	}

	return Status;
}

LONG CTestNFC663Dlg::StopInterface(void *pReader)
{
	LONG Status;

	Status = CLSCRF_Mfrc_Off(pReader); // ��������� ���������� ��������������� �����������
	if (Status != SCARD_S_SUCCESS)
	{
		//m_strResult = "������ ��������� � �����������!";
		//UpdateData(FALSE);
		//StopInterface(*ppReader);
		//return Status;
	}

	Status = CLSCRF_Close(pReader); // ��������� ���������� USB
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������ ������ ����������!";
		UpdateData(FALSE);
		CLSCRF_Destroy(&pReader);
		return Status;
	}

	Status = CLSCRF_Destroy(&pReader); // ������� �� ������ ������ �����������
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������ ������ ����������!";
		UpdateData(FALSE);
		return Status;
	}

	return Status;
}

void CTestNFC663Dlg::OnBnClickedButtonNdefText()
{
	LONG Status;
	void *pReader = NULL; // ���������� ��� �������� ��������� �� ������ �����������

	UpdateData();

	m_strResult = "������������ �������� ���������...";
	UpdateData(FALSE);
	this->UpdateWindow();

	Status = StartInterface(&pReader);
	if (Status != SCARD_S_SUCCESS)
	{
		return;
	}

	HANDLE hNDEFMessage;
	// ������ ������ ��������� NDEF
	Status = CLSCRF_NFC_NDEF_Message_Create(NULL, 0, &hNDEFMessage);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	// ��������� ������ ���� ����� � ��������� NDEF
	Status = CLSCRF_NFC_NDEF_Message_AddRecordText(hNDEFMessage, m_strNDEFText.GetBuffer(), L"ru");
	m_strNDEFText.ReleaseBuffer();
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	DWORD dwMsgSize = 0;
	// ���������� ������ ��������� NDEF � ������
	Status = CLSCRF_NFC_NDEF_Message_GetDataSize(hNDEFMessage, &dwMsgSize);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	BYTE lpMsgData[1024] = { 0 };
	// �������� � ������ ������ ��������� NDEF
	Status = CLSCRF_NFC_NDEF_Message_GetData(hNDEFMessage, lpMsgData);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	if (m_ucTagType == 0)
	{
		HANDLE hLLCPLink;
		// ������ ������ ��������� LLCP
		Status = CLSCRF_NFC_LLCP_Create(pReader, &hLLCPLink);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		// ������������� �������� ������ �� ��������� LLCP
		Status = CLSCRF_NFC_LLCP_SetBaudrate(hLLCPLink, PHPAL_I18092MPI_DATARATE_106);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		HANDLE hSNEP;
		// ������ ������ ��������� SNEP
		Status = CLSCRF_NFC_SNEP_Create(hLLCPLink, &hSNEP);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		// ��������� ���������� ���� Client �� ��������� LLCP � 
		// �������� ������ ���� ��������� NDEF �� ��������� SNEP
		Status = CLSCRF_NFC_SNEP_Transmit(hSNEP, lpMsgData, dwMsgSize);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		// ������� ������ ��������� SNEP
		Status = CLSCRF_NFC_SNEP_Destroy(hSNEP);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		// ������� ������ ��������� LLCP
		Status = CLSCRF_NFC_LLCP_Destroy(hLLCPLink);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		// ������� ������ ��������� NDEF
		Status = CLSCRF_NFC_NDEF_Message_Destroy(hNDEFMessage);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}
	}

	if ((m_ucTagType == 2) || (m_ucTagType == 4))
	{
		// �������� �������� ��������� NDEF � �����
		Status = CLSCRF_NFC_ForumTags_Write(pReader, m_ucTagType, lpMsgData, dwMsgSize);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������ ������ � �����!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}
	}

	StopInterface(pReader);

	m_strResult = "��������� ������� ����������!";

	UpdateData(FALSE);
}


void CTestNFC663Dlg::OnBnClickedButtonNdefTextRecv()
{
	LONG Status;
	void *pReader = NULL;

	UpdateData();

	m_strResult = "������������ ����� ���������...";
	m_strNDEFText = "";

	UpdateData(FALSE);
	this->UpdateWindow();

	Status = StartInterface(&pReader);
	if (Status != SCARD_S_SUCCESS)
	{
		return;
	}


	BYTE lpMsgData[1024] = { 0 };
	DWORD dwMsgSize = sizeof(lpMsgData);

	if (m_ucTagType == 0)
	{
		HANDLE hLLCPLink;
		// ������ ������ ��������� LLCP
		Status = CLSCRF_NFC_LLCP_Create(pReader, &hLLCPLink);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		// ������������� �������� ������ �� ��������� LLCP
		Status = CLSCRF_NFC_LLCP_SetBaudrate(hLLCPLink, PHPAL_I18092MPI_DATARATE_106);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		HANDLE hSNEP;
		// ������ ������ ��������� SNEP
		Status = CLSCRF_NFC_SNEP_Create(hLLCPLink, &hSNEP);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		// ��������� ���������� LLCP ���� Server � ��������� ����� ���� ������ �� ��������� SNEP
		Status = CLSCRF_NFC_SNEP_Receive(hSNEP, lpMsgData, &dwMsgSize);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		// ������� ������ ��������� SNEP
		Status = CLSCRF_NFC_SNEP_Destroy(hSNEP);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		// ������� ������ ��������� LLCP
		Status = CLSCRF_NFC_LLCP_Destroy(hLLCPLink);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}
	}

	if ((m_ucTagType == 2)||(m_ucTagType == 4))
	{
		BYTE ucPermissions = 0x00;
		// �������� �������� NDEF �� �����
		Status = CLSCRF_NFC_ForumTags_Read(pReader, m_ucTagType, lpMsgData, &dwMsgSize, &ucPermissions);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������ ������ �����!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}
	}

	HANDLE hNDEFMessage;
	// ������ ������ ��������� NDEF �� ������ �������� ������
	Status = CLSCRF_NFC_NDEF_Message_Create(lpMsgData, dwMsgSize, &hNDEFMessage);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	DWORD dwRecCount = 0;
	// ��������� ���������� ������� � ��������� NDEF
	Status = CLSCRF_NFC_NDEF_Message_GetRecordsCount(hNDEFMessage, &dwRecCount);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	HANDLE hNDEFRecord;
	if (dwRecCount > 0)
	{
		// ��������� ������ �� ������ ������ ������ � ��������� NDEF
		Status = CLSCRF_NFC_NDEF_Message_GetRecord(hNDEFMessage, 0, &hNDEFRecord);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		TCHAR lpStrType[16] = { 0 };
		// ��������� ��� ������ � ������
		Status = CLSCRF_NFC_NDEF_Record_GetTypeStr(hNDEFRecord, lpStrType);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		if ((CString(lpStrType) == CString("T")) || (CString(lpStrType) == CString("U")))
		{
			TCHAR lpStrText[1024] = { 0 };
			// ��������� ����� �� ������ ������ � ������
			Status = CLSCRF_NFC_NDEF_Record_GetPayloadText(hNDEFRecord, lpStrText);
			if (Status != SCARD_S_SUCCESS)
			{
				m_strResult = "������!";
				UpdateData(FALSE);
				StopInterface(pReader);
				return;
			}

			m_strNDEFText = lpStrText;
		}
	}

	// ������� ������ ��������� NDEF
	Status = CLSCRF_NFC_NDEF_Message_Destroy(hNDEFMessage);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	m_strResult.Format(L"��������� ������� ���������! ������� �������: %d.", dwRecCount);

	StopInterface(pReader);

	UpdateData(FALSE);
}


void CTestNFC663Dlg::OnBnClickedButtonNdefUriRecv()
{
	LONG Status;
	void *pReader = NULL;

	UpdateData();

	m_strResult = "������������ ����� ���������...";
	m_strNDEFUri = "";

	UpdateData(FALSE);
	this->UpdateWindow();

	Status = StartInterface(&pReader);
	if (Status != SCARD_S_SUCCESS)
	{
		return;
	}



	BYTE lpMsgData[1024] = { 0 };
	DWORD dwMsgSize = sizeof(lpMsgData);

	if (m_ucTagType == 0)
	{
		HANDLE hLLCPLink;
		Status = CLSCRF_NFC_LLCP_Create(pReader, &hLLCPLink);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		Status = CLSCRF_NFC_LLCP_SetBaudrate(hLLCPLink, PHPAL_I18092MPI_DATARATE_106);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		HANDLE hSNEP;
		Status = CLSCRF_NFC_SNEP_Create(hLLCPLink, &hSNEP);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		Status = CLSCRF_NFC_SNEP_Receive(hSNEP, lpMsgData, &dwMsgSize);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		Status = CLSCRF_NFC_SNEP_Destroy(hSNEP);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		Status = CLSCRF_NFC_LLCP_Destroy(hLLCPLink);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}
	}

	if ((m_ucTagType == 2) || (m_ucTagType == 4))
	{
		BYTE ucPermissions = 0x00;
		// �������� �������� NDEF �� �����
		Status = CLSCRF_NFC_ForumTags_Read(pReader, m_ucTagType, lpMsgData, &dwMsgSize, &ucPermissions);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������ ������ �����!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}
	}

	HANDLE hNDEFMessage;
	Status = CLSCRF_NFC_NDEF_Message_Create(lpMsgData, dwMsgSize, &hNDEFMessage);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	DWORD dwRecCount = 0;
	Status = CLSCRF_NFC_NDEF_Message_GetRecordsCount(hNDEFMessage, &dwRecCount);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	HANDLE hNDEFRecord;
	if (dwRecCount > 0)
	{
		Status = CLSCRF_NFC_NDEF_Message_GetRecord(hNDEFMessage, 0, &hNDEFRecord);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		TCHAR lpStrType[16] = { 0 };
		Status = CLSCRF_NFC_NDEF_Record_GetTypeStr(hNDEFRecord, lpStrType);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		if (CString(lpStrType) == CString("U"))
		{
			TCHAR lpStrText[1024] = { 0 };
			Status = CLSCRF_NFC_NDEF_Record_GetPayloadUri(hNDEFRecord, lpStrText);
			if (Status != SCARD_S_SUCCESS)
			{
				m_strResult = "������!";
				UpdateData(FALSE);
				StopInterface(pReader);
				return;
			}

			m_strNDEFUri = lpStrText;
		}
	}

	Status = CLSCRF_NFC_NDEF_Message_Destroy(hNDEFMessage);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	m_strResult.Format(L"��������� ������� ���������! ������� �������: %d.", dwRecCount);

	StopInterface(pReader);

	UpdateData(FALSE);
}


void CTestNFC663Dlg::OnBnClickedButtonNdefUri()
{
	LONG Status;
	void *pReader = NULL;

	UpdateData();

	m_strResult = "������������ �������� ���������...";
	UpdateData(FALSE);
	this->UpdateWindow();

	Status = StartInterface(&pReader);
	if (Status != SCARD_S_SUCCESS)
	{
		return;
	}

	HANDLE hNDEFMessage;
	Status = CLSCRF_NFC_NDEF_Message_Create(NULL, 0, &hNDEFMessage);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	Status = CLSCRF_NFC_NDEF_Message_AddRecordUri(hNDEFMessage, m_strNDEFUri.GetBuffer());
	m_strNDEFText.ReleaseBuffer();
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	DWORD dwMsgSize = 0;
	Status = CLSCRF_NFC_NDEF_Message_GetDataSize(hNDEFMessage, &dwMsgSize);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	BYTE lpMsgData[1024] = { 0 };
	Status = CLSCRF_NFC_NDEF_Message_GetData(hNDEFMessage, lpMsgData);
	if (Status != SCARD_S_SUCCESS)
	{
		m_strResult = "������!";
		UpdateData(FALSE);
		StopInterface(pReader);
		return;
	}

	if (m_ucTagType == 0)
	{
		HANDLE hLLCPLink;
		Status = CLSCRF_NFC_LLCP_Create(pReader, &hLLCPLink);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		Status = CLSCRF_NFC_LLCP_SetBaudrate(hLLCPLink, PHPAL_I18092MPI_DATARATE_106);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		HANDLE hSNEP;
		Status = CLSCRF_NFC_SNEP_Create(hLLCPLink, &hSNEP);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		Status = CLSCRF_NFC_SNEP_Transmit(hSNEP, lpMsgData, dwMsgSize);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		Status = CLSCRF_NFC_SNEP_Destroy(hSNEP);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		Status = CLSCRF_NFC_LLCP_Destroy(hLLCPLink);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}

		Status = CLSCRF_NFC_NDEF_Message_Destroy(hNDEFMessage);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}
	}

	if ((m_ucTagType == 2) || (m_ucTagType == 4))
	{
		Status = CLSCRF_NFC_ForumTags_Write(pReader, m_ucTagType, lpMsgData, dwMsgSize);
		if (Status != SCARD_S_SUCCESS)
		{
			m_strResult = "������ ������ � �����!";
			UpdateData(FALSE);
			StopInterface(pReader);
			return;
		}
	}

	StopInterface(pReader);

	m_strResult = "��������� ������� ����������!";

	UpdateData(FALSE);
}
