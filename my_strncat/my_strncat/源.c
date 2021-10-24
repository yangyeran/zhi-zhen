# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h> 
//strncat作用
//1.比strcat要相对安全（有个控制拷贝的数）
//2.会自动在拷贝结束后放上一个\0
//3.控制的数超过了源头字符串长度，也只拷贝到源头结束不会向后拷贝
//4.strncat只要遇到\0就会停止拷贝
char* my_strncat(char*dest,const char*src,size_t n)
{
	assert(dest && src);
	char*ret = dest;
	size_t i = 0;
	while (*dest)
	{
		dest++;//让dest指向\0
	}
	for (i = 0; i < n; i++)
	{
		if(*(src+i))
		*(dest + i) = *(src + i);//拷贝n个字符
	}
	//*(dest + n) = '\0';
	return ret;
}
int main()
{
	char arr1[20] = "abc";
	char arr2[] = "defghi";
	size_t i = 0;
	scanf("%u", &i);
	printf("%s", my_strncat(arr1, arr2, i));
	return 0;
}