
// TestNFC663.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CTestNFC663App:
// О реализации данного класса см. TestNFC663.cpp
//

class CTestNFC663App : public CWinApp
{
public:
	CTestNFC663App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CTestNFC663App theApp;