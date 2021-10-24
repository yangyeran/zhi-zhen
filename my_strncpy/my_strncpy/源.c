# define _CRT_SECURE_NO_WARNINGS 1
//1.strncpy��strcpy�������棬���˸����ƿ����ַ������Ĳ���
//2.���Դͷ���ַ���С����Ҫ�������ַ��������������\0
//3.���ص�����Ԫ�صĵ�ַ
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
		for (i = 0; i < n; i++)//����n��
		{
			*(dest + i) = *(src + i);
		}
	}
	else
	{
		for (i = 0; i < count; i++)//����n��
		{
			*(dest + i) = *(src + i);
		}
		for (i = 0; i < n - count; i++)//������ĸ�ֵ\0
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