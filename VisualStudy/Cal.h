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
		UInt16	Pras_CRC16(UInt16 ploy,UInt16 init_value,unsigned char *data_in,UInt16 len);
		String^ Pras_CRC14443A(String^ crc14443a);
		String^ Pras_CRC14443B(String^ crc14443b);
		String^ Pras_ATR(String^ atr);

	};
	


}


