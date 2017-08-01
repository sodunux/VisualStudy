#include "StdAfx.h"
#include <WinSCard.h>
#include "card.h"
using namespace std;
using namespace VisualStudy;



card::card(void)
{
	
	hContext=NULL;
	ReaderName=gcnew array<String^>(10);
	
}

void card::GetReaders()
{
	
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

		lreturn=SCardListReaders(hContext,NULL,(LPTSTR)readerbuff,&dwlen);
		if(lreturn!=SCARD_S_SUCCESS) throw lreturn;

		for(i=0,j=0;i<(dwlen-1);i++)
		{
			if(readerbuff[i]=='\0')
				j++;
			else
				ReaderName[j]+=readerbuff[i];
		}
		ReaderCnt=j;

	}
	catch(...)
	{
		;
	}
	
}

void card::ConnectReader(Byte ReaderID)
{
	
	DWORD dwAP;
	DWORD ret,i;
	TCHAR reader[1000];
	
	SCARDHANDLE handletemp;
	try
	{
		for(i=0;i<ReaderName[ReaderID]->Length;i++)
		{
			reader[i]=ReaderName[ReaderID][i];
		}
		reader[i]='\0';
		reader[i+1]='\0';

		ret=SCardConnect(hContext,(LPTSTR)reader,SCARD_SHARE_SHARED,SCARD_PROTOCOL_T0|SCARD_PROTOCOL_T1,&handletemp,&dwAP);
		if(ret!=SCARD_S_SUCCESS)throw ret;

		hCardHandle=handletemp;

	}
	catch(...)
	{
		;
	}



}

void card::DisconnectReader()
{
	DWORD ret;
	try
	{
		ret=SCardDisconnect(hCardHandle,SCARD_LEAVE_CARD);
		if(ret!=SCARD_S_SUCCESS)throw ret;
	}
	catch(...)
	{
		;
	}
}

void card::ReleaseContext()
{
	DWORD ret;
	try
	{
		ret=SCardReleaseContext(hContext);
	}
	catch(...)
	{
		;
	}
}

void card::TransmitReader(String^sendstr,String^ &recstr)
{
	DWORD ret,i;
	String ^temp;
	Byte sendbuff[1024],recebuff[1024];
	DWORD sendlen=1024,recelen=1024;
	SCARD_IO_REQUEST g_rgSCardT1Pci;
	g_rgSCardT1Pci.dwProtocol=SCARD_PROTOCOL_T1;
	g_rgSCardT1Pci.cbPciLength=sizeof(SCARD_IO_REQUEST);

	try
	{
		if(sendstr->Length%2) throw ret;

		for(i=0;i<(sendstr->Length/2);i++)
		{
			sendbuff[i]=Convert::ToByte(sendstr->Substring(i*2,2),16);
		}
		sendlen=sendstr->Length/2;
		

		ret=SCardBeginTransaction(hCardHandle); 
		if(ret!=SCARD_S_SUCCESS)throw ret;
		ret=SCardTransmit(hCardHandle,&g_rgSCardT1Pci,sendbuff,sendlen,NULL,recebuff,&recelen);
		if(ret!=SCARD_S_SUCCESS)throw ret;
		ret=SCardEndTransaction(hCardHandle,SCARD_LEAVE_CARD);
		if(ret!=SCARD_S_SUCCESS)throw ret;

		recstr="";
		for(i=0;i<recelen;i++)
		{
			recstr+=Convert::ToString(recebuff[i],16);
		}

	}
	catch(...)
	{
		;
	}
}


