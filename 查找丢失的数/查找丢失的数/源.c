# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//力扣的第2368题
int missingNumber(int* nums, int numsSize) {
	int*ptr = (int*)malloc((numsSize + 1) * 4);
	int i = 0, count1 = nums[0], count2;
	for (i = 0; i <= numsSize; i++)
	{
		ptr[i] = i;
	}
	count2 = ptr[0];
	for (i = 1; i<numsSize; i++)
	{
		count1 ^= nums[i];
	}
	for (i = 1; i <= numsSize; i++)
	{
		count2 ^= ptr[i];
	}
	return count1^count2;
}
