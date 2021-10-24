# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//#include<string.h>
//dest��Ŀ�ĵأ�src��Դͷ����Դͷ�ĵ�ַ����Ŀ�ĵصĵ�ַʱ��ǰ���󿽱�
//��ԴͷС��Ŀ�ĵص�ַʱ�Ӻ���ǰ����
void* my_memmove(void* dest,const void* src, size_t count)
{
	assert(dest && src);
	void* ret = dest;
	if (dest > src)
	{
		while (count--)
		{
			*((char*)dest+count) =*((char*)src+count);
		}
	}
	else
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
    my_memmove(arr + 2, arr, 16);
	//memmove(arr + 2, arr, 16);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}