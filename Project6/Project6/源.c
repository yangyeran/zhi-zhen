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
//1.дһ������ָ��pf���ܹ�ָ��my_strcpy
//2.дһ������ָ������ pfArr���ܹ����4��my_strcpy�����ĵ�ַ