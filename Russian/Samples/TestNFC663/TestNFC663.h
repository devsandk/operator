
// TestNFC663.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CTestNFC663App:
// � ���������� ������� ������ ��. TestNFC663.cpp
//

class CTestNFC663App : public CWinApp
{
public:
	CTestNFC663App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CTestNFC663App theApp;