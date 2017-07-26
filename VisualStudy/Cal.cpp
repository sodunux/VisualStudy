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
	String ^ history_str;
	unsigned char tmpchar[100];
	unsigned char FSCI[16]={16,24,32,40,48,64,96,128,255,255,255,255,255,255,255,255};
	unsigned char TA1,TB1,TC1;
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
			
			temp+="PICC�ܽ���֡����󳤶�FSCΪ"+Convert::ToString(FSCI[tmpchar[1]&0x0F],10)+"\n";
			
			switch(tmpchar[1]&0x70)
			{
			case 0x10://TA1���ڣ�TB1��TC1������
				TA1=Convert::ToByte(ats->Substring(4,2),16);
				history_str=ats->Substring(6,(ats->Length-6));
				break;
			case 0x30://TA1���ڣ�TB1����
				TA1=Convert::ToByte(ats->Substring(4,2),16);
				TB1=Convert::ToByte(ats->Substring(6,2),16);
				history_str=ats->Substring(8,(ats->Length-8));
				break;
			case 0x05:
				TA1=Convert::ToByte(ats->Substring(4,2),16);
				TC1=Convert::ToByte(ats->Substring(6,2),16);
				history_str=ats->Substring(8,(ats->Length-8));
				break;
			case 0x70:
				TA1=Convert::ToByte(ats->Substring(4,2),16);
				TB1=Convert::ToByte(ats->Substring(6,2),16);
				TC1=Convert::ToByte(ats->Substring(8,2),16);
				history_str=ats->Substring(10,(ats->Length-10));
				break;
			case 0x20:
				TB1=Convert::ToByte(ats->Substring(4,2),16);
				history_str=ats->Substring(6,(ats->Length-6));
				break;
			case 0x60:
				TB1=Convert::ToByte(ats->Substring(4,2),16);
				TC1=Convert::ToByte(ats->Substring(6,2),16);
				history_str=ats->Substring(8,(ats->Length-8));
				break;
			case 0x40:
				TC1=Convert::ToByte(ats->Substring(4,2),16);
				history_str=ats->Substring(6,(ats->Length-6));
				break;
			case 0x00:
				history_str=ats->Substring(4,(ats->Length-4));
				break;
			default:
				break;
			}
			if(tmpchar[1]&0x10)
			{
				if(TA1&0x80)
					temp+="ֻ֧��˫����ͬ����\n";
				else 
					temp+="֧��˫��ͬ����\n";
				if(TA1&0x40)
					temp+="picc����֧��848K\n";
				else
					temp+="picc���Ͳ�֧��848K\n";
				if(TA1&0x20)
					temp+="picc����֧��424K\n";
				else
					temp+="picc���Ͳ�֧��424K\n";
				if(TA1&0x10)
					temp+="picc����֧��212K\n";
				else
					temp+="picc���Ͳ�֧��212K\n";
				if(TA1&0x04)
					temp+="pcd����֧��848K\n";
				else 
					temp+="pcd����֧��848K\n";
				if(TA1&0x02)
					temp+="pcd����֧��424K\n";
				else 
					temp+="pcd���Ͳ�֧��424K\n";
				if(TA1&0x01)
					temp+="pcd����֧��212K\n";
				else 
					temp+="pcd���Ͳ�֧��212K\n";
			}

			if(tmpchar[1]&0x20)
			{
				temp+="FWI��"+Convert::ToString(TB1&0xF0,10)+"\n";
				temp+="SFGI��"+Convert::ToString(TB1&0x0F,10)+"\n";

			}
			if(tmpchar[1]&0x40)
			{
				if(TC1&0x01)
					temp+="֧��NAD\n";
				else 
					temp+="��֧��NAD\n";
				if(TC1&0x02)
					temp+="֧��CID\n";
				else 
					temp+="��֧��CID\n";
			}

			temp+="��ʷ�ֽ���"+history_str;



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

String^ Cal::Pras_CRC14443A(String^ crc14443a)
{
	
}

String^ Cal::Pras_CRC14443B(String^ crc14443b)
{
	
}

String^ Cal::Pras_CRCCCITT(String^ crcccitt)
{
	
}