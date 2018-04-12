#pragma once
#include "StdAfx.h"
#include <WinSCard.h>
namespace VisualStudy
{
	using namespace System;
	ref class card
	{
	public:
		card(void);
		int GetReaders();
		int ConnectReader(int ReaderID);
		int DisconnectReader(); 
		int TransmitReader(String^sendstr,String^ &recstr);
		int ReleaseContext(); 
		~card();
		SCARDCONTEXT hContext;
		array<String^>^ReaderName;
		Byte ReaderCnt;
		SCARDHANDLE hCardHandle;
		
		

	};
	

}

