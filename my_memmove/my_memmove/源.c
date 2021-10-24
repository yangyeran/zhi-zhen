# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//#include<string.h>
//dest是目的地，src是源头，当源头的地址大于目的地的地址时从前往后拷贝
//当源头小于目的地地址时从后往前拷贝
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