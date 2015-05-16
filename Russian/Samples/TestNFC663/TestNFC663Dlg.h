
// TestNFC663Dlg.h : ���� ���������
//

#pragma once


// ���������� ���� CTestNFC663Dlg
class CTestNFC663Dlg : public CDialogEx
{
// ��������
public:
	CTestNFC663Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_TESTNFC663_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BYTE m_ucTagType;
	CString m_strNDEFText;
	afx_msg void OnBnClickedButtonNdefText();
	CString m_strResult;
	afx_msg void OnBnClickedButtonNdefTextRecv();
	LONG StartInterface(void **ppReader);
	LONG StopInterface(void *pReader);
	CString m_strNDEFUri;
	afx_msg void OnBnClickedButtonNdefUriRecv();
	afx_msg void OnBnClickedButtonNdefUri();
};
