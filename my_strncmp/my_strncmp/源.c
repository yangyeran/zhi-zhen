# define _CRT_SECURE_NO_WARNINGS 1
//1.strncmp�ǱȽϺ������Ƚϵ��������ַ����е���ͬλ�õ��ַ���ASCII��ֵ
//2.��strcmp������ڰ�ȫ�İ汾����һ�����ƱȽϸ���������
//3.���ǱȽ��ַ������ȣ�����ߺ��ұ߱Ƚ�
//4.�����޸��ַ���������ֵ������������>0 ��<0�� =0
//5.����ֵint����
#include<stdio.h>
#include<assert.h>
int my_strncmp(const char*str1, const char*str2, size_t n)
{
	assert(str1 && str2);
	size_t i = 0;
	for (i = 0; i < n; i++)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return *str1 - *str2;
	}
	return 0;
}
int main()
{
	char arr1[] = "abcdcf";
	char arr2[] = "abcg";
	size_t i = 0;
	scanf("%u", &i);
	int x = my_strncmp(arr1, arr2, i);
	if (x > 0)
		printf(">\n");
	else if (x == 0)
		printf("=\n");
	else
		printf("<\n");
	return 0;
}
