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
			temp="ATQA专用编码:"+Convert::ToString(tmpchar[1]&0x0F)+"\n";
			switch((tmpchar[0]>>6))
			{
			case 0x00:
					temp+="UID重数：一重\n";
					break;
			case 0x01:
					temp+="UID重数：二重\n";
					break;
			case 0x02:
					temp+="UID重数：三重\n";
					break;
			case 0x03:
					temp+="UID重数：错误UID重数\n";
					break;
			default:
					break;
			}
			if(((tmpchar[0]&0x1F)==0x01)||((tmpchar[0]&0x1F)==0x02)||((tmpchar[0]&0x1F)==0x04)||((tmpchar[0]&0x1F)==0x08)||((tmpchar[0]&0x1F)==0x10))
			{
				temp+="采用位帧防冲突\n";
			}
			else
			{
				temp+="没有采用位帧防冲突\n";
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
				temp="支持ISO/IEC14443协议\n";
			}
			else
			{
				temp="不支持ISO/IEC14443协议\n";
			}
			if(tmpchar&0x04)
			{
				temp+="UID还未完整";
			}
			else
			{
				temp+="UID完整";
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
			temp="ATS长度TL为"+	Convert::ToString(tmpchar[0],10)+"\n";
			tmpchar[1]=Convert::ToByte(ats->Substring(2,2),16);//T0
			if(tmpchar[1]&0x40)//bit6,TC1
				temp+="TC1存在\n";
			else
				temp+="TC1不存在\n";
			
			if(tmpchar[1]&0x20)//bit5,TB1
				temp+="TB1存在\n";
			else
				temp+="TB1不存在\n";		

			if(tmpchar[1]&0x10)//bit4,TA1
				temp+="TA1存在\n";
			else
				temp+="TA1不存在\n";
			
			temp+="PICC能接受帧的最大长度FSC为"+Convert::ToString(FSCI[tmpchar[1]&0x0F],10)+"\n";
			
			switch(tmpchar[1]&0x70)
			{
			case 0x10://TA1存在，TB1和TC1不存在
				TA1=Convert::ToByte(ats->Substring(4,2),16);
				history_str=ats->Substring(6,(ats->Length-6));
				break;
			case 0x30://TA1存在，TB1存在
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
					temp+="只支持双向相同速率\n";
				else 
					temp+="支持双向不同速率\n";
				if(TA1&0x40)
					temp+="picc发送支持848K\n";
				else
					temp+="picc发送不支持848K\n";
				if(TA1&0x20)
					temp+="picc发送支持424K\n";
				else
					temp+="picc发送不支持424K\n";
				if(TA1&0x10)
					temp+="picc发送支持212K\n";
				else
					temp+="picc发送不支持212K\n";
				if(TA1&0x04)
					temp+="pcd发送支持848K\n";
				else 
					temp+="pcd发送支持848K\n";
				if(TA1&0x02)
					temp+="pcd发送支持424K\n";
				else 
					temp+="pcd发送不支持424K\n";
				if(TA1&0x01)
					temp+="pcd发送支持212K\n";
				else 
					temp+="pcd发送不支持212K\n";
			}

			if(tmpchar[1]&0x20)
			{
				temp+="FWI是"+Convert::ToString(TB1&0xF0,10)+"\n";
				temp+="SFGI是"+Convert::ToString(TB1&0x0F,10)+"\n";

			}
			if(tmpchar[1]&0x40)
			{
				if(TC1&0x01)
					temp+="支持NAD\n";
				else 
					temp+="不支持NAD\n";
				if(TC1&0x02)
					temp+="支持CID\n";
				else 
					temp+="不支持CID\n";
			}

			temp+="历史字节是"+history_str;



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
	String ^ temp;
	UInt16 len=1024*10;
	unsigned char data_in[1024*10];
	UInt16 crc_result=0,ploy=0x8408,init_value=0x6363;
	UInt16 i;
	try
	{
		if(crc14443a->Length>(len*2)) throw len;
		if(crc14443a->Length%2) throw len;

		for(i=0;i<(crc14443a->Length/2);i=i+1)
		{
			data_in[i]=Convert::ToByte(crc14443a->Substring((i*2),2),16);
		}
		crc_result=Pras_CRC16(ploy,init_value,data_in,(crc14443a->Length/2));
		temp="CRC = 0x"+Convert::ToString(crc_result,16)+"\n";	
	}
	catch(...)
	{
		temp="Please enter a correct data(小于10240bytes)!";
	}
	return temp;
}

String^ Cal::Pras_CRC14443B(String^ crc14443b)
{
	String ^ temp;
	UInt16 len=1024*10;
	unsigned char data_in[1024*10];
	UInt16 crc_result=0,ploy=0x8408,init_value=0xFFFF;
	UInt16 i;
	try
	{
		if(crc14443b->Length>(len*2)) throw len;
		if(crc14443b->Length%2) throw len;

		for(i=0;i<(crc14443b->Length/2);i=i+1)
		{
			data_in[i]=Convert::ToByte(crc14443b->Substring((i*2),2),16);
		}
		crc_result=Pras_CRC16(ploy,init_value,data_in,(crc14443b->Length/2));
		temp="CRC = 0x"+Convert::ToString(crc_result,16)+"\n";	
	}
	catch(...)
	{
		temp="Please enter a correct data(小于10240bytes)!";
	}
	return temp;
}



UInt16 Cal::Pras_CRC16(UInt16 ploy,UInt16 init_value,unsigned char *data_in,UInt16 len)
{
	UInt16 crc_result=init_value;
	UInt16 i,j;
	for(i=0;i<len;i++)
	{
		crc_result=crc_result^data_in[i];
		for(j=0;j<8;j++)
		{
			if(crc_result&0x0001)
				crc_result=(crc_result>>1)^ploy;
			else 
				crc_result=(crc_result>>1);
		}
	}
	return crc_result;
}

String^ Cal::Pras_ATR(String^ atr)
{
	String ^ temp;
	unsigned char TS,T0,TA1,TB1,TC1,TD1;
	String^ history_string;
	int F[16]={372,372,558,744,1116,1488,2232,0,0,512,768,1024,1536,2048,0,0};
	int D[16]={0,1,2,4,8,16,32,0,12,20,0,0,0,0,0,0};
	try
	{
		TS=Convert::ToByte(atr->Substring(0,2),16);
		T0=Convert::ToByte(atr->Substring(2,2),16);
		if(TS==0x3B)
			temp="ATR正向约定，首先传送LSB\n";
		else if(TS==0x3F)
			temp="ATR反向约定，首先传送MSB\n";
		else 
			throw temp;

		if(T0&0x10)
			temp+="TA1存在\n";
		else 
			temp+="TA1不存在\n";
		if(T0&0x20)
			temp+="TB1存在\n";
		else 
			temp+="TB1不存在\n";
		if(T0&0x40)
			temp+="TC1存在\n";
		else 
			temp+="TC1不存在\n";
		if(T0&0x80)
			temp+="TD1存在\n";
		else
			temp+="TD1不存在\n";

		temp+="历史字节数为"+Convert::ToString((T0&0x0F),16)+"\n";	
		
		switch(T0>>4)
		{
		case 0:
			break;
		case 1:
			TA1=Convert::ToByte(atr->Substring(4,2),16);
			history_string=atr->Substring(6,(atr->Length-6));
			break;
		case 2:
			TB1=Convert::ToByte(atr->Substring(4,2),16);
			history_string=atr->Substring(6,(atr->Length-6));
			break;
		case 3:
			TA1=Convert::ToByte(atr->Substring(4,2),16);
			TB1=Convert::ToByte(atr->Substring(6,2),16);
			history_string=atr->Substring(8,(atr->Length-8));
			break;
		case 4:
			TC1=Convert::ToByte(atr->Substring(4,2),16);
			history_string=atr->Substring(6,(atr->Length-6));
			break;
		case 5:
			TA1=Convert::ToByte(atr->Substring(4,2),16);
			TC1=Convert::ToByte(atr->Substring(6,2),16);
			history_string=atr->Substring(8,(atr->Length-8));
			break;
		case 6:
			TB1=Convert::ToByte(atr->Substring(4,2),16);
			TC1=Convert::ToByte(atr->Substring(6,2),16);
			history_string=atr->Substring(8,(atr->Length-8));
			break;
		case 7:
			TA1=Convert::ToByte(atr->Substring(4,2),16);
			TB1=Convert::ToByte(atr->Substring(6,2),16);
			TC1=Convert::ToByte(atr->Substring(8,2),16);
			history_string=atr->Substring(10,(atr->Length-10));
			break;
		case 8:
			TD1=Convert::ToByte(atr->Substring(4,2),16);
			history_string=atr->Substring(6,(atr->Length-6));
			break;
		case 9:
			TA1=Convert::ToByte(atr->Substring(4,2),16);
			TD1=Convert::ToByte(atr->Substring(6,2),16);
			history_string=atr->Substring(8,(atr->Length-8));
			break;
		case 10:
			TB1=Convert::ToByte(atr->Substring(4,2),16);
			TD1=Convert::ToByte(atr->Substring(6,2),16);
			history_string=atr->Substring(8,(atr->Length-8));
			break;
		case 11:
			TA1=Convert::ToByte(atr->Substring(4,2),16);
			TB1=Convert::ToByte(atr->Substring(6,2),16);
			TD1=Convert::ToByte(atr->Substring(8,2),16);
			history_string=atr->Substring(10,(atr->Length-10));
			break;
		case 12:
			TC1=Convert::ToByte(atr->Substring(4,2),16);
			TD1=Convert::ToByte(atr->Substring(6,2),16);
			history_string=atr->Substring(8,(atr->Length-8));
			break;
		case 13:
			TA1=Convert::ToByte(atr->Substring(4,2),16);
			TC1=Convert::ToByte(atr->Substring(6,2),16);
			TD1=Convert::ToByte(atr->Substring(8,2),16);
			history_string=atr->Substring(10,(atr->Length-10));
			break;
		case 14:
			TB1=Convert::ToByte(atr->Substring(4,2),16);
			TC1=Convert::ToByte(atr->Substring(6,2),16);
			TD1=Convert::ToByte(atr->Substring(8,2),16);
			history_string=atr->Substring(10,(atr->Length-10));
			break;
		case 15:
			TA1=Convert::ToByte(atr->Substring(4,2),16);
			TB1=Convert::ToByte(atr->Substring(6,2),16);
			TC1=Convert::ToByte(atr->Substring(8,2),16);
			TD1=Convert::ToByte(atr->Substring(10,2),16);
			history_string=atr->Substring(12,(atr->Length-12));
			break;
		default:
			break;
		}
	
		if(T0&0x10)
		{
			temp+="F="+Convert::ToString(F[TA1>>4],10)+","+"D="+Convert::ToString(D[TA1&0x0F],10)+"\n";
		}
		if(T0&0x20)
		{
			temp+="最大编程电流因子I1为"+Convert::ToString(TB1>>5,10)+"\n";
			temp+="最大编程电压因子V1为"+Convert::ToString(TB1&0x1F,10)+"\n";
		}
		if(T0&0x40)
		{
			temp+="额外保护时间N为"+Convert::ToString(TC1,10)+"(12+(F/D)*(N/f))\n";
		}
		if(T0&0x80)
		{
			temp+="后续发送的协议类型T="+Convert::ToString(TD1&0x0F,10)+"\n";
		}
		if(history_string->Length)
			temp+="历史字符："+history_string+"\n";

	}

	catch(...)
	{
		temp="Please enter a correct data!";
	}
	return temp;

}