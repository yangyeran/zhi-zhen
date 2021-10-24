# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char*parr1, const char*parr2)
{
	char*ret = parr1;
	assert(parr1 != NULL);
	assert(parr2 != NULL);
	while (*parr1++ = *parr2++)
	{
		;
	}
	return ret;
}
int main()
{
	char*ret = NULL;
	char arr1[] = "xxxxxxxx";
	char arr2[]="abc";
	ret=my_strcpy(arr1, arr2);
	printf("%s\n", ret);
	return 0;
}