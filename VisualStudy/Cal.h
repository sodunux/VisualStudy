#pragma once
namespace VisualStudy
{
	using namespace System;

	ref class Cal
	{
	public:
		Cal(void);
		String^ Pras_ATQA(String^ atqa);
		String^ Pras_SAK(String^ sak);
		String^ Pras_ATS(String^ ats);
		unsigned ^ Pras_CRC16(String^ crc16);
		String^ Pras_CRC14443A(String^ crc14443a);
		String^ Pras_CRC14443B(String^ crc14443b);
		String^ Pras_CRCCCITT(String^ crcccitt);
		
	};
	


}


