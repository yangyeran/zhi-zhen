# define _CRT_SECURE_NO_WARNINGS 1
//1.strncmp是比较函数，比较的是两个字符串中的相同位置的字符的ASCII码值
//2.是strcmp的相较于安全的版本（有一个控制比较个数的数）
//3.不是比较字符串长度，是左边和右边比较
//4.不会修改字符串，返回值是有三种类型>0 ，<0， =0
//5.返回值int类型
#include<stdio.h>
#include<assert.h>
int my_strncmp(const char*str1, const char*str2, size_t n)
{
	assert(str1 && str2);
	size_t i = 0;
	for (i = 0; i < n; i++)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return *str1 - *str2;
	}
	return 0;
}
int main()
{
	char arr1[] = "abcdcf";
	char arr2[] = "abcg";
	size_t i = 0;
	scanf("%u", &i);
	int x = my_strncmp(arr1, arr2, i);
	if (x > 0)
		printf(">\n");
	else if (x == 0)
		printf("=\n");
	else
		printf("<\n");
	return 0;
}
