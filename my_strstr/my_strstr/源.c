# define _CRT_SECURE_NO_WARNINGS 1
//1.首先strstr是一个字符串查找函数，左边为目的地，右边为源头
//2.在目的地中去查找源头，如果能找到就会返回第一次相同的首元素的地址，找不到返回空指针。
#include<stdio.h>
#include<assert.h>
char* my_strstr(const char*dest,const char*src)
{
	assert(dest && src);
	char*s1;
	char*s2;
	char*str = dest;
	while (*str)
	{
		s1 = str;//为了返回函数比较的后一个元素
		s2 = src;//为遍历arr2
		while (*s1&&*s2&&(*s1 == *s2))
		{
			s1++; 
			s2++;
		}
		if (*s2 == '\0')
			return str;
		str++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "abcdefghf";
	char arr2[] = "efgh";
	char*p = my_strstr(arr1, arr2);
	if (p == NULL)
		printf("找不到\n");
	else
		printf("%s\n", my_strstr(arr1, arr2));
	return 0;
}