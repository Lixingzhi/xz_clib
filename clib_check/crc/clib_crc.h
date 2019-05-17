#ifndef		_CLIB_CRC_H_
#define		_CLIB_CRC_H_

//这里定义常用CRC算法的多项式值
#define		CRC_4_ITU						(0x03)
#define		CRC_5_EPC						(0x09)
#define		CRC_5_ITU						(0x15)
#define		CRC_5_USB						(0x05)
#define		CRC_6_ITU						(0x03)
#define		CRC_7_MMC						(0x09)
#define		CRC_8							(0x07)
#define		CRC_8_ITU						(0x07)
#define		CRC_8_ROHC						(0x07)
#define		CRC_8_MAXIM						(0x31)
#define		CRC_16_IBM						(0x8005)
#define		CRC_16_MAXIM					(0x8005)
#define		CRC_16_USB						(0x8005)
#define		CRC_16_MODBUS					(0x8005)
#define		CRC_16_CCITT					(0x1021)
#define		CRC_16_CCITT_FALSE				(0x1021)
#define		CRC_16_x5						(0x1021)
#define		CRC_16_XMODEM					(0x1021)
#define		CRC_16_DNP						(0x3D65)
#define		CRC_32							(04C11DB7)
#define		CRC_32_MPEG_2					(04C11DB7)




unsigned char CRC8(const unsigned char *p_srcdata, unsigned char srcdata_len, unsigned char poly, unsigned char init);
unsigned short CRC16(const unsigned short *p_srcdata, unsigned char srcdata_len, unsigned short poly, unsigned short init);
unsigned int CRC32(const unsigned int *p_srcdata, unsigned char srcdata_len, unsigned int poly, unsigned int init);  


#endif


