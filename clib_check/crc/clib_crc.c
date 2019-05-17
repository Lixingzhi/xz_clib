/**************************************************************
  文件名		: clib_crc.c
  作者			: Lixingzhi
  创建日期      : 2019/05/17
  说明		    : 本文件收录了CRC的计算方法
  修订历史      :
  1.日期        : 2019/05/17
    作者        : Lixingzhi
    修改内容	: 创建文件

***************************************************************/

#include "clib_crc.h"

/***************************************************************
  函数名			: CRC8
  功能说明			: 本函数用来计算CRC8的数值
  参数说明			:		
	p_srcdata		: 输入数据指针	
	srcdata_len		: 输入数据长度
	poly			: 多项式的值，参见头文件中的宏定义
	init			: crc初始值
					
  返回值			: CRC8的数值
****************************************************************/
unsigned char CRC8(const unsigned char *p_srcdata, unsigned char srcdata_len, unsigned char poly, unsigned char init)
{
    unsigned char i; 
    unsigned char crc = init; /* 计算的初始crc值 */ 

	while(srcdata_len--)
	{
		crc ^= *p_srcdata++;  /* 每次先与需要计算的数据异或,计算完指向下一数据 */  
		for (i = 8; i > 0; --i)   /* 数据往左移了8位，需要计算8次 */  
		{ 
			if (crc & 0x80)			/* 判断最高位是否为1 */
			{
				/* 最高位为1，往左移一位，然后与0x31异或 */
				crc = (crc << 1) ^ poly;
			}
			else
			{
				/* 最高位为0时，不需要异或，整体数据往左移一位 */
				crc = (crc << 1);
			}
				
		}
	}	

    return (crc); 
}




/***************************************************************
  函数名			: CRC16
  功能说明			: 本函数用来计算CRC16的数值
  参数说明			:		
	p_srcdata		: 输入数据指针	
	srcdata_len		: 输入数据长度
	poly			: 多项式的值，参见头文件中的宏定义
	init			: crc初始值
					
  返回值			: CRC16的数值
****************************************************************/
unsigned short CRC16(const unsigned short *p_srcdata, unsigned char srcdata_len, unsigned short poly, unsigned short init)
{
    unsigned char i; 
    unsigned short crc = init;				//计算的初始crc值
	unsigned char *p_data = (unsigned char *)p_srcdata;


	while(srcdata_len--)
	{
		crc ^= ((*p_data++) << 8);			//将数据的第一个字节与CRC高8位异或
		for (i = 0; i < 8; i++)				//重复该过程直至8位全部计算完毕
		{
			if (crc & 0x8000)				//判断最高位，若该位为 0 左移一位，若为 1 左移一位再与多项式Hex码异或。
			{
				crc = (crc << 1) ^ poly;
			}
			else
			{ 
				crc = crc << 1; 
			}
		}
	}

    return (crc); 
}

/***************************************************************
  函数名			: CRC32
  功能说明			: 本函数用来计算CRC32的数值
  参数说明			:		
	p_srcdata		: 输入数据指针	
	srcdata_len		: 输入数据长度
	poly			: 多项式的值，参见头文件中的宏定义
	init			: crc初始值
					
  返回值			: CRC32的数值
****************************************************************/
unsigned int CRC32(const unsigned int *p_srcdata, unsigned char srcdata_len, unsigned int poly, unsigned int init)  
{  
	int i;  
	unsigned int crc = init;  
	unsigned char *p_data = (unsigned char *)p_srcdata;


	while (srcdata_len--)     
	{  
		crc ^= ((*p_data++) << 24);			//将数据的第一个字节与CRC高8位异或
		for(i = 0; i < 8; i++)				//重复该过程直至8位全部计算完毕
		{  
			if(crc & 0x80000000)			//判断最高位，若该位为 0 左移一位，若为 1 左移一位再与多项式Hex码异或。
			crc = (crc << 1) ^ poly;  
			else  
			crc = crc << 1;  
		}  
	}  

	return crc;
}  







