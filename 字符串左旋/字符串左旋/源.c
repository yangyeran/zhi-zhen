# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//void fun(char*ptr,int x)
//{
//	int j = 0;
//	int sz = strlen(ptr);
//	x = x%sz;
//	for (j = 0; j < x; j++)//Ҫ���ƶ��ٴ�
//	{
//		int z = 0;
//		int temp = *ptr;
//		for (z = 0; z < sz - 1; z++)
//		{
//			*(ptr + z) = *(ptr + z + 1);
//		}
//		*(ptr + z) = temp;
//	}
//}
//void fun(char*ptr,int x)
//{
//	int len = strlen(ptr);
//	char temp[256] = { 0 };
//	int k = x%len;//���Ŀ�ʼ�Ͽ�
//	strcpy(temp, ptr + k);
//	strncat(temp, ptr, k);//��temp��Ԫ�غ������ptr��ǰk��Ԫ��
//	strcpy(ptr, temp);
//}
void fun1(char*ptr, int start,int end)//������
{
	int i, j;
	char tmp;
	for (i = start, j = end; i < j; i++, j--)
	{
		tmp = ptr[i];
		ptr[i] = ptr[j];
		ptr[j] = tmp;
	}
}
int fun2(char*arr, int y)
{
	int sz = strlen(arr);
	int i = 0;
	fun1(arr, 0, y-1);//ǰ���
	fun1(arr,y,sz-1);//����
	fun1(arr,0,sz-1);//ȫ��
}
int fun3(const char * src, char * find)
{
	char tmp[256] = { 0 };
	strcpy(tmp, src);
	strcat(tmp, src); 
	return strstr(tmp, find) != NULL;
}
int main()
{
	int i = 0,j=0;
	char str[10] = { 0 };
	char prt[10] = { 0 };
	gets_s(str,10);
	gets_s(prt,10);
	scanf("%d", &i);
	fun2(str, i);
	printf("%s\n", str);
	int z=fun3(str, prt);
	if (z != 0)
		printf("%s��%s��ת%d��֮����ַ���",prt,str,i);
	else
		printf("%s����%s��ת%d��֮����ַ���",prt,str,i);
	return 0;
}