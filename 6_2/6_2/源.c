# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void print_arr1(int arr[3][5],int x,int y )//指针数组
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j <y; j++)
		{
			printf("%d ", *(*(arr+i)+j));//因为arr[3][5]是二维数组它的首元素的地址是第一行的地址*arr所表达的即为二维数组的第一行*(arr+i)是找第i+1行
			//找到第一行后需要打印出第一行的每个元素所以*(arr+i)+j即为第一行第j+1列的地址再进行解引用*(*(arr+i)+j)即为所要打印的数组元素
			//printf("%d ", *(arr[i] + j));//与上面的代码等价因为以前int* p=&arr[5]所取的就是arr首元素的地址arr[0]所以与*(arr+i)的意义相同同理
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
	//数组名arr，表示首元素的地址
	//但是二维数组的首元素是二维数组的第一行
	//所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
	//可以数组指针来接收
	print_arr2(arr, 3, 5);
	return 0;
}