/**************************************************************
  文件名		: clib_str.c
  作者			: Lixingzhi
  创建日期      : 2019/05/11
  说明		    : 本文件收录了一些针对字符串操作的函数
  修订历史      :
  1.日期        : 2019/05/11
    作者        : Lixingzhi
    修改内容	: 创建文件

***************************************************************/


#include "clib_str.h"

/***************************************************************
  函数名		: l_trim
  功能说明		: 本函数用来删除输入字符串中左边的空格
  参数说明		:		
	p_dst		: 输出字符串指针	
	p_src		: 输入字符串指针
					
  返回值		: 输出字符串指针
****************************************************************/
char * l_trim(char *p_dst, const char *p_src)
{
	assert(p_src != NULL);
	assert(p_dst != NULL);
	//assert(p_dst != p_src);		//p_src和p_dst是否相等并没有什么影响


	/*
	 * 从左开始遍历p_src，直到找到第一个不是空格的位置
	 */
	for(NULL; *p_src != '\0' && isspace(*p_src); ++p_src)
	{
		//do nothing
	}

	return strcpy(p_dst, p_src);
}



/***************************************************************
  函数名		: r_trim
  功能说明		: 本函数用来删除输入字符串中右边的空格
  参数说明		:		
	p_dst		: 输出字符串指针	
	p_src		: 输入字符串指针
					
  返回值		: 输出字符串指针
****************************************************************/
char * r_trim(char *p_dst, const char *p_src)
{
	char *p = NULL;

	assert(p_src != NULL);
	assert(p_dst != NULL);
	//assert(p_dst != p_src);		//p_src和p_dst是否相等并没有什么影响

	/*
	 * 从右开始遍历p_src，直到找到第一个不是空格或者换行的位置
	 */
	for(p = p_dst + strlen(p_dst) - 1; p >= p_dst && isspace(*p); --p)
	{
		//do nothing
	}

	/*
	 * 将该处的空格改为\0后返回
	 */
	*(++p) = '\0';

	return p_dst;
}


/***************************************************************
  函数名		: trim
  功能说明		: 本函数用来删除输入字符串中左右两边的空格
  参数说明		:		
	p_dst		: 输出字符串指针	
	p_src		: 输入字符串指针
					
  返回值		: 输出字符串指针
****************************************************************/
char * trim(char *p_dst, const char *p_src)
{
	assert(p_src != NULL);
	assert(p_dst != NULL);
	//assert(p_dst != p_src);		//p_src和p_dst是否相等并没有什么影响

	l_trim(p_dst, p_src);
	r_trim(p_dst, p_src);

	return p_dst;
}







