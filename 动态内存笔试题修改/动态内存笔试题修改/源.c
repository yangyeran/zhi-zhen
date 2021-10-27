# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//void GetMemory(char*p)//原题，程序会崩溃
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char*str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello word");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
void GetMemory(char** p)//修改之后的代码1
{
	*p = (char*)malloc(100);
}
void Test(void)
{
	char*str = NULL;
	GetMemory(&str);
	strcpy(str, "hello word");
	printf(str);
	free(str);
	str = NULL;
}
int main()
{
	Test();
	return 0;
}
//char* GetMemory(void)//修改之后的代码2
//{
//	return (char*)malloc(100);
//}
//void Test(void)
//{
//	char*str = NULL;
//	str = GetMemory();
//	strcpy(str, "hello word");
//	printf(str);
//	free(str);
//	str = NULL;
//}
int main()
{
	Test();
	return 0;
}




//柔性数组使用
//struct st_str
//{
//	int i;
//	int arr[];
//};
//
//
//int main()
//{
//	int i = 0;
//	struct st_str *ps = (struct st_str*)malloc(sizeof(struct st_str)+10*sizeof(int));//开辟
//	if (ps == NULL) 
//	{
//		perror("错误原因");
//		return -1;
//	}
//	else
//	{
//		for (i = 0; i < 10; i++)
//		{
//			ps->arr[i] = i;
//			printf("%d ", ps->arr[i]);
//		}
//	}
//	struct st_str* ptr = (struct st_str*)realloc(ps, sizeof(struct st_str) + 20 * sizeof(int));//扩容
//	if (ptr == NULL)
//	{
//		perror("错误原因");
//		return -1;
//	}
//	else
//		ps = ptr;
//	for (i; i < 20; i++)
//	{
//		ps->arr[i] = i;
//		printf("%d ", ps->arr[i]);
//	}
//	return 0;
//}
