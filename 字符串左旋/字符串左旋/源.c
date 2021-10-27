# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//void fun(char*ptr,int x)
//{
//	int j = 0;
//	int sz = strlen(ptr);
//	x = x%sz;
//	for (j = 0; j < x; j++)//要左移多少次
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
//	int k = x%len;//从哪开始断开
//	strcpy(temp, ptr + k);
//	strncat(temp, ptr, k);//在temp的元素后面接上ptr的前k个元素
//	strcpy(ptr, temp);
//}
void fun1(char*ptr, int start,int end)//逆序函数
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
	fun1(arr, 0, y-1);//前半段
	fun1(arr,y,sz-1);//后半段
	fun1(arr,0,sz-1);//全部
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
		printf("%s是%s旋转%d次之后的字符串",prt,str,i);
	else
		printf("%s不是%s旋转%d次之后的字符串",prt,str,i);
	return 0;
}