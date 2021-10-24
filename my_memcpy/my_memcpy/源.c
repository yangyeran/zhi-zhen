# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* dest, void* src, size_t count)
{
	assert(dest && src);
	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[20] = { 0 };
	int* ret = NULL;
	int i = 0;
	ret=(int*)my_memcpy(arr2, arr1, 10 * sizeof(int));
	for (i = 0; i < 20; i++)
	{
		printf("%d ",*(ret+i));
	}
	return 0;
}