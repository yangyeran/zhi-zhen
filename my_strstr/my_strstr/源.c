# define _CRT_SECURE_NO_WARNINGS 1
//1.����strstr��һ���ַ������Һ��������ΪĿ�ĵأ��ұ�ΪԴͷ
//2.��Ŀ�ĵ���ȥ����Դͷ��������ҵ��ͻ᷵�ص�һ����ͬ����Ԫ�صĵ�ַ���Ҳ������ؿ�ָ�롣
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
		s1 = str;//Ϊ�˷��غ����Ƚϵĺ�һ��Ԫ��
		s2 = src;//Ϊ����arr2
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
		printf("�Ҳ���\n");
	else
		printf("%s\n", my_strstr(arr1, arr2));
	return 0;
}