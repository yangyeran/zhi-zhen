# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//void GetMemory(char*p)//ԭ�⣬��������
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
void GetMemory(char** p)//�޸�֮��Ĵ���1
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
//char* GetMemory(void)//�޸�֮��Ĵ���2
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




//��������ʹ��
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
//	struct st_str *ps = (struct st_str*)malloc(sizeof(struct st_str)+10*sizeof(int));//����
//	if (ps == NULL) 
//	{
//		perror("����ԭ��");
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
//	struct st_str* ptr = (struct st_str*)realloc(ps, sizeof(struct st_str) + 20 * sizeof(int));//����
//	if (ptr == NULL)
//	{
//		perror("����ԭ��");
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
