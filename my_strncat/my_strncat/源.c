# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h> 
//strncat����
//1.��strcatҪ��԰�ȫ���и����ƿ���������
//2.���Զ��ڿ������������һ��\0
//3.���Ƶ���������Դͷ�ַ������ȣ�Ҳֻ������Դͷ����������󿽱�
//4.strncatֻҪ����\0�ͻ�ֹͣ����
char* my_strncat(char*dest,const char*src,size_t n)
{
	assert(dest && src);
	char*ret = dest;
	size_t i = 0;
	while (*dest)
	{
		dest++;//��destָ��\0
	}
	for (i = 0; i < n; i++)
	{
		if(*(src+i))
		*(dest + i) = *(src + i);//����n���ַ�
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