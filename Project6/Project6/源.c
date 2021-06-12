# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char* (*pf)(char*, const char*);
	char*(*pfArr[4])(char*, const char*);
}
//1.写一个函数指针pf，能够指向my_strcpy
//2.写一个函数指针数组 pfArr，能够存放4个my_strcpy函数的地址