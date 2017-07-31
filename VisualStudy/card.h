#pragma once
#include <WinSCard.h>
namespace VisualStudy
{
	using namespace System;
	ref class card
	{
	public:
		card(void);
		void GetReaders();
		

	private:
		SCARDCONTEXT hContext;
		array<String^>^ReaderName;
		

	};
	

}

