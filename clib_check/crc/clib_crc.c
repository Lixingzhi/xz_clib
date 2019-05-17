/**************************************************************
  �ļ���		: clib_crc.c
  ����			: Lixingzhi
  ��������      : 2019/05/17
  ˵��		    : ���ļ���¼��CRC�ļ��㷽��
  �޶���ʷ      :
  1.����        : 2019/05/17
    ����        : Lixingzhi
    �޸�����	: �����ļ�

***************************************************************/

#include "clib_crc.h"

/***************************************************************
  ������			: CRC8
  ����˵��			: ��������������CRC8����ֵ
  ����˵��			:		
	p_srcdata		: ��������ָ��	
	srcdata_len		: �������ݳ���
	poly			: ����ʽ��ֵ���μ�ͷ�ļ��еĺ궨��
	init			: crc��ʼֵ
					
  ����ֵ			: CRC8����ֵ
****************************************************************/
unsigned char CRC8(const unsigned char *p_srcdata, unsigned char srcdata_len, unsigned char poly, unsigned char init)
{
    unsigned char i; 
    unsigned char crc = init; /* ����ĳ�ʼcrcֵ */ 

	while(srcdata_len--)
	{
		crc ^= *p_srcdata++;  /* ÿ��������Ҫ������������,������ָ����һ���� */  
		for (i = 8; i > 0; --i)   /* ������������8λ����Ҫ����8�� */  
		{ 
			if (crc & 0x80)			/* �ж����λ�Ƿ�Ϊ1 */
			{
				/* ���λΪ1��������һλ��Ȼ����0x31��� */
				crc = (crc << 1) ^ poly;
			}
			else
			{
				/* ���λΪ0ʱ������Ҫ�����������������һλ */
				crc = (crc << 1);
			}
				
		}
	}	

    return (crc); 
}




/***************************************************************
  ������			: CRC16
  ����˵��			: ��������������CRC16����ֵ
  ����˵��			:		
	p_srcdata		: ��������ָ��	
	srcdata_len		: �������ݳ���
	poly			: ����ʽ��ֵ���μ�ͷ�ļ��еĺ궨��
	init			: crc��ʼֵ
					
  ����ֵ			: CRC16����ֵ
****************************************************************/
unsigned short CRC16(const unsigned short *p_srcdata, unsigned char srcdata_len, unsigned short poly, unsigned short init)
{
    unsigned char i; 
    unsigned short crc = init;				//����ĳ�ʼcrcֵ
	unsigned char *p_data = (unsigned char *)p_srcdata;


	while(srcdata_len--)
	{
		crc ^= ((*p_data++) << 8);			//�����ݵĵ�һ���ֽ���CRC��8λ���
		for (i = 0; i < 8; i++)				//�ظ��ù���ֱ��8λȫ���������
		{
			if (crc & 0x8000)				//�ж����λ������λΪ 0 ����һλ����Ϊ 1 ����һλ�������ʽHex�����
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
  ������			: CRC32
  ����˵��			: ��������������CRC32����ֵ
  ����˵��			:		
	p_srcdata		: ��������ָ��	
	srcdata_len		: �������ݳ���
	poly			: ����ʽ��ֵ���μ�ͷ�ļ��еĺ궨��
	init			: crc��ʼֵ
					
  ����ֵ			: CRC32����ֵ
****************************************************************/
unsigned int CRC32(const unsigned int *p_srcdata, unsigned char srcdata_len, unsigned int poly, unsigned int init)  
{  
	int i;  
	unsigned int crc = init;  
	unsigned char *p_data = (unsigned char *)p_srcdata;


	while (srcdata_len--)     
	{  
		crc ^= ((*p_data++) << 24);			//�����ݵĵ�һ���ֽ���CRC��8λ���
		for(i = 0; i < 8; i++)				//�ظ��ù���ֱ��8λȫ���������
		{  
			if(crc & 0x80000000)			//�ж����λ������λΪ 0 ����һλ����Ϊ 1 ����һλ�������ʽHex�����
			crc = (crc << 1) ^ poly;  
			else  
			crc = crc << 1;  
		}  
	}  

	return crc;
}  







