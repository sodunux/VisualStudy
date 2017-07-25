#include "StdAfx.h"
#include "Cal.h"
using namespace VisualStudy;

Cal::Cal(void)
{

}

String^ Cal::Pras_ATQA(String^ atqa)
{
	String ^temp;
	unsigned char tmpchar[2];
	//
	if(atqa->Length==4)//ATQA=4,hex
	{
		try
		{	
			tmpchar[0]=Convert::ToByte(atqa->Substring(0,2),16);
			tmpchar[1]=Convert::ToByte(atqa->Substring(2,2),16);
			temp="ATQAר�ñ���:"+Convert::ToString(tmpchar[1]&0x0F)+"\n";
			switch((tmpchar[0]>>6)==0x03)
			{
			case 0x00:
					temp+="UID������һ��\n";
					break;
			case 0x01:
					temp+="UID����������\n";
					break;
			case 0x02:
					temp+="UID����������\n";
					break;
			case 0x03:
					temp+="UID����������UID����\n";
					break;
			default:
					break;
			}
			if(((tmpchar[0]&0x1F)==0x01)||((tmpchar[0]&0x1F)==0x02)||((tmpchar[0]&0x1F)==0x04)||((tmpchar[0]&0x1F)==0x08)||((tmpchar[0]&0x1F)==0x10))
			{
				temp+="����λ֡����ͻ\n";
			}
			else
			{
				temp+="û�в���λ֡����ͻ\n";
			}
			
			 

		}
		catch(...)//Catch all type exception
		{
			temp="Please enter a correct ATQA!";
		}
	}
	else
	{
		temp="Please enter the correct ATQA!";
	
	}
	return temp;
}
String^ Cal::Pras_SAK(String^ sak)
{
	String ^temp;
	unsigned char tmpchar;
	if(sak->Length==0x02)
	{
		try
		{
			tmpchar=Convert::ToByte(sak->Substring(0,2),16);
			if(tmpchar&0x20)
			{
				temp="֧��ISO/IEC14443Э��\n";
			}
			else
			{
				temp="��֧��ISO/IEC14443Э��\n";
			}
			if(tmpchar&0x04)
			{
				temp+="UID��δ����";
			}
			else
			{
				temp+="UID����";
			}
		
	
		}
		catch(...)
		{
			temp="Please enter a correct SAK!";
		}
	}
	else
	{
		temp="Please enter a correct SAK!";
	}
	//temp="This is Pras_SAK function!";
	return temp;	
}

String^ Cal::Pras_ATS(String^ ats)
{
	String ^temp;
	unsigned char tmpchar[100];
	unsigned char FSCI[16]={16,24,32,40,48,64,96,128,255,255,255,255,255,255,255,255};
	try
	{
		tmpchar[0]=Convert::ToByte(ats->Substring(0,2),16);//TL
		if((tmpchar[0]*2)==(ats->Length))
		{
			temp="ATS����TLΪ"+	Convert::ToString(tmpchar[0],10)+"\n";
			tmpchar[1]=Convert::ToByte(ats->Substring(2,2),16);//T0
			if(tmpchar[1]&0x40)//bit6,TC1
				temp+="TC1����\n";
			else
				temp+="TC1������\n";
			
			if(tmpchar[1]&0x20)//bit5,TB1
				temp+="TB1����\n";
			else
				temp+="TB1������\n";		

			if(tmpchar[1]&0x10)//bit4,TA1
				temp+="TA1����\n";
			else
				temp+="TA1������\n";
			
			temp+="PICC�ܽ���֡����󳤶�FSCΪ"+Convert::ToString(FSCI[tmpchar[1]],10)+"\n";
			
			
			
			if(tmpchar[1]&0x10)
			{
				tmpchar[2]=Convert::ToByte(ats->Substring(2,2),16);//TA1
			}


		}
		else
		{
			throw temp;
		}
	

	}
	catch(...)
	{
		temp="Please enter a correct ATS!";
	}

	return temp;	
}
