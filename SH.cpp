#include "pch.h"
#include "framework.h"
#include "ScreenHolder.h"
#include "ScreenHolderDlg.h"

namespace SH {
	uint MovementMode;
	uint Hdis, Vdis; //horizontal distance,vertical distance
	uint Speed; //pixel per sec
	bool HoldScreen, MainThreadWorking;
	std::thread *MainThreadPtr;
	
	void StartMainThread() {
		if (MainThreadWorking)
			return;
		HoldScreen = true;
		MainThreadPtr = new std::thread(MainThread);
		while (!MainThreadWorking);
	}

	void RestartMainThread() {
		StopMainThread();
		StartMainThread();
	}

	void StopMainThread() {
		if (!MainThreadWorking)
			return;
		HoldScreen = false;
		MainThreadPtr->join();
	}

	void MainThread() {
		HWND hWnd = theApp.m_pMainWnd->m_hWnd;
		MainThreadWorking = true;

		//Test MM
		char tmp[2]={0,0};
		tmp[0] = MovementMode + '0';
		MessageBoxA(hWnd,tmp,tmp,MB_OK);

		bool badmm = false;
		while (HoldScreen) {
			switch (MovementMode) {
			case MM_LR:
				
				break;
			case MM_UD:

				break;
			case MM_ULLR:

				break;
			case MM_LLUR:

				break;
			case MM_CR:

				break;
			default:
				MessageBox(hWnd, TEXT("Bad MovementMode!"), TEXT("Error!"), MB_ICONERROR | MB_OK);
				badmm = true;
				break;
			}
			if (badmm)
				break;
		}
		MainThreadWorking = false;
	}

	void Exit() {
		StopMainThread();
		HWND hWnd = theApp.m_pMainWnd->m_hWnd;
		HoldScreen = false;
		while (MainThreadWorking);
		DestroyWindow(hWnd);
	}
}