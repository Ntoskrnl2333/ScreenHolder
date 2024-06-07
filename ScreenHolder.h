
// ScreenHolder.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

typedef unsigned int uint;

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CScreenHolderApp:
// 有关此类的实现，请参阅 ScreenHolder.cpp
//

class CScreenHolderApp : public CWinApp
{
public:
	CScreenHolderApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CScreenHolderApp theApp;


////////////////////////----MAIN FUNCTIONS----////////////////////////
namespace SH {
	extern uint MovementMode;
	enum {
		MM_LR,//left and right
		MM_UD,//up and down
		MM_LD_RU,//from upper left to lower right
	};

	extern void HoldScreenMainThread();
}