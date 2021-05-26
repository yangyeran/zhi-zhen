# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 }, i;
//	int* p = &arr;
//	for (i = 0; i < 4; i++)
//	{
//	    printf("%d ", *p++);
//		printf("%d ", *p += 2);
//	}
//	system("pause");
//}
int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
		end++;//访问下一个
	return end - start;
}
int main()
{
	int ret = 0;
	char arr[] = "hello word";
	ret=my_strlen(arr);
	printf("%d\n", ret);
	return 0;
}