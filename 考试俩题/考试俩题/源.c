# define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//将空格改成%20
//void replace_blank(char*src,int length)
//{
//	int i ,count= 0,size=0, zsize;
//	for (i = 0; i < length; i++)
//	{
//		if (*(src + i) == '\0')
//			break;
//		size++;//是实际的长度
//	}
//	for (i = 0; i <= size; i++)//已经计算出来了有多少个空格
//	{
//		if (*(src + i) == ' ')
//		{
//			count++;//算的是有多少个空格
//		}
//	}
//	//计算转换之后的总大小
//	zsize = size + 2 * count;
//	//转换字符从后往前换，可以使用两个下标
//	while (zsize)
//	{
//		if (*(src + size ) != ' ')
//		{
//			src[zsize--] = src[size--];
//		}
//		else//是空格需要转换
//		{
//			src[zsize--] = '%';
//			src[zsize--] = '2';
//			src[zsize--] = '0';
//			size--;
//		}
//	}
//}
//int main()
//{
//	char arr[20] = "we are happy.";
//	replace_blank(arr,20);
//	printf("%s\n",arr);
//	return 0;
//}

//将一个数转换成斐波那契数需要多少步
//求斐波那契数，只要我输入的数在两个斐波那契数之间，选择更接近斐波那契数的一边就能算出需要多少步了
int Fibonacci(int n)
{
	//进来的话数是直接大于2的
	int i = 2; 
	int j=1, tmp, x=1;
	for (i = 3; j <= n; i++)
	{
		tmp = j;
		j = x+j;
		x = tmp;
		if (j == n)//n本身就是斐波那契数
			return 0;
		else//n不是斐波那契数
		{
			if ((j < n) && (j+x) > n)//找出n左右两边的斐波那契数
			{
				int ret1 = n-j;
				int ret2 = j+x - n;
				if (ret1 >= ret2)//返回步数小的
					return ret2;
				else
					return ret1;
			}
		}
	}
}
int Fibonacci_con(int n)//求多少步
{
	if (n <=3)
		return 0;
	else
		return Fibonacci(n);
}
int main()
{
	int i = 0;
	int ret = 0;
	while (scanf("%d", &i) != EOF)
	{
		ret=Fibonacci_con(i);
		printf("%d\n",ret);
	}
	return 0;
}