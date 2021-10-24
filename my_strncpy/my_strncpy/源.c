# define _CRT_SECURE_NO_WARNINGS 1
//1.strncpy是strcpy的升级版，多了个控制拷贝字符个数的参数
//2.如果源头的字符串小于需要拷贝的字符串，多出部分填\0
//3.返回的是首元素的地址
#include<stdio.h>
#include<assert.h>
char* my_strncpy(char*dest,const char*src, size_t n)
{
	assert(dest && src);
	char*sz = src;
	int i,count = 0;
	while (*sz)
	{
		count++;
		sz++;
	}
	if (n <= count)
	{
		for (i = 0; i < n; i++)//拷贝n次
		{
			*(dest + i) = *(src + i);
		}
	}
	else
	{
		for (i = 0; i < count; i++)//拷贝n次
		{
			*(dest + i) = *(src + i);
		}
		for (i = 0; i < n - count; i++)//多出来的赋值\0
		{
			*(dest + i + count) = '\0';
		}
	}
	return dest;
}
int main()
{
	char arr1[10] ="123456789";
	char arr2[] = "abcdefg";
	size_t i = 0;
	scanf("%u", &i);
	printf("%s",my_strncpy(arr1, arr2, i));
	return 0;
}