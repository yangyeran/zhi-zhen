# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void print_arr1(int arr[3][5],int x,int y )//ָ������
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j <y; j++)
		{
			printf("%d ", *(*(arr+i)+j));//��Ϊarr[3][5]�Ƕ�ά����������Ԫ�صĵ�ַ�ǵ�һ�еĵ�ַ*arr�����ļ�Ϊ��ά����ĵ�һ��*(arr+i)���ҵ�i+1��
			//�ҵ���һ�к���Ҫ��ӡ����һ�е�ÿ��Ԫ������*(arr+i)+j��Ϊ��һ�е�j+1�еĵ�ַ�ٽ��н�����*(*(arr+i)+j)��Ϊ��Ҫ��ӡ������Ԫ��
			//printf("%d ", *(arr[i] + j));//������Ĵ���ȼ���Ϊ��ǰint* p=&arr[5]��ȡ�ľ���arr��Ԫ�صĵ�ַarr[0]������*(arr+i)��������ͬͬ��
			//printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void print_arr2(int(*p)[5], int x, int y)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			//printf("%d ", *(*(p + i) + j));
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

}
int main()
{
	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
	print_arr1(arr, 3, 5);
	//������arr����ʾ��Ԫ�صĵ�ַ
	//���Ƕ�ά�������Ԫ���Ƕ�ά����ĵ�һ��
	//�������ﴫ�ݵ�arr����ʵ�൱�ڵ�һ�еĵ�ַ����һά����ĵ�ַ
	//��������ָ��������
	print_arr2(arr, 3, 5);
	return 0;
}