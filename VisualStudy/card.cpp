#include "StdAfx.h"
#include "card.h"
#include "WinSCard.h"
using namespace VisualStudy;

card::card(void)
{
	hContext=NULL;
	ReaderName=gcnew array<String^>(10);
	
}

void card::GetReaders()
{
	bool ret;
	TCHAR readerbuff[1024];
	DWORD dwlen=1024;
	DWORD i,j;
	SCARDCONTEXT hSC;
	LONG lreturn;
	try
	{
		lreturn=SCardEstablishContext(SCARD_SCOPE_SYSTEM,NULL,NULL,&hSC);
		if(lreturn!=SCARD_S_SUCCESS) throw lreturn;
		hContext=hSC;

		lreturn=SCardListReaders(hSC,NULL,(LPTSTR)readerbuff,&dwlen);
		if(lreturn!=SCARD_S_SUCCESS) throw lreturn;

		for(i=0;i<dwlen;i++)
		{
			
		}

		



	}
	catch(...)
	{
		;
	}
}





