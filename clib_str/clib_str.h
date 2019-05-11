#ifndef		__C_LIB_STR_H_
#define		__C_LIB_STR_H_


#include <string.h>
#include <assert.h>
#include <ctype.h>

char * l_trim(char *p_dst, const char *p_src);
char * r_trim(char *p_dst, const char *p_src);
char * trim(char *p_dst, const char *p_src);


#endif


