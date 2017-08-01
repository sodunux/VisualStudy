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
		void GetReaders();
		void ConnectReader(Byte ReaderID);
		void DisconnectReader(); 
		void TransmitReader(String^sendstr,String^ &recstr);
		void ReleaseContext();                                                                                            
		SCARDCONTEXT hContext;
		array<String^>^ReaderName;
		Byte ReaderCnt;
		SCARDHANDLE hCardHandle;
		
		

	};
	

}

