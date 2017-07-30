#include "StdAfx.h"
#include "card.h"
#include "WinSCard.h"
using namespace VisualStudy;

card::card(void)
{

}

void card:: cardtest()
{
	SCARDCONTEXT hContext;
	LONG rv;
	LPTSTR mszReaders;
	DWORD dwReaders;
	SCARDHANDLE hCard;
	DWORD dwActiveProtocol;

	rv = SCardEstablishContext(SCARD_SCOPE_SYSTEM, NULL, NULL, &hContext);
	rv = SCardListReaders(hContext, NULL, NULL, &dwReaders);
	mszReaders = (LPTSTR)malloc(sizeof(char)*dwReaders);
	rv = SCardListReaders(hContext, NULL, mszReaders, &dwReaders);
	//rv = SCardConnect(hContext, "Reader X", SCARD_SHARE_SHARED,
	//	SCARD_PROTOCOL_T0, &hCard, &dwActiveProtocol);

}

