# define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//���ո�ĳ�%20
//void replace_blank(char*src,int length)
//{
//	int i ,count= 0,size=0, zsize;
//	for (i = 0; i < length; i++)
//	{
//		if (*(src + i) == '\0')
//			break;
//		size++;//��ʵ�ʵĳ���
//	}
//	for (i = 0; i <= size; i++)//�Ѿ�����������ж��ٸ��ո�
//	{
//		if (*(src + i) == ' ')
//		{
//			count++;//������ж��ٸ��ո�
//		}
//	}
//	//����ת��֮����ܴ�С
//	zsize = size + 2 * count;
//	//ת���ַ��Ӻ���ǰ��������ʹ�������±�
//	while (zsize)
//	{
//		if (*(src + size ) != ' ')
//		{
//			src[zsize--] = src[size--];
//		}
//		else//�ǿո���Ҫת��
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

//��һ����ת����쳲���������Ҫ���ٲ�
//��쳲���������ֻҪ���������������쳲�������֮�䣬ѡ����ӽ�쳲���������һ�߾��������Ҫ���ٲ���
int Fibonacci(int n)
{
	//�����Ļ�����ֱ�Ӵ���2��
	int i = 2; 
	int j=1, tmp, x=1;
	for (i = 3; j <= n; i++)
	{
		tmp = j;
		j = x+j;
		x = tmp;
		if (j == n)//n�������쳲�������
			return 0;
		else//n����쳲�������
		{
			if ((j < n) && (j+x) > n)//�ҳ�n�������ߵ�쳲�������
			{
				int ret1 = n-j;
				int ret2 = j+x - n;
				if (ret1 >= ret2)//���ز���С��
					return ret2;
				else
					return ret1;
			}
		}
	}
}
int Fibonacci_con(int n)//����ٲ�
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