# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int* singleNumbers(int* nums, int numsSize, int* returnSize) {
	int count1 = nums[0], count2 = 0, count3 = 0;
	int i = 0;
	for (i = 1; i<numsSize; i++)
	{
		count1 ^= nums[i];//count1代表两个单独的数按位与
	}
	count2 = count1;//count2是count1的拷贝，后面会改变值
	while (count2)
	{
		count3++;//计算二进制中第几位是1,那就在找的时候找相同位置是0的位置
		if (count2 % 2 == 1)
		{
			break;
		}
		count2 = count2 / 2;
	}
	count2 = count1;
	for (i = 0; i<numsSize; i++)//找nums数组里面符合的数
	{
		if ((nums[i]>>(count3-1))&1 == 1)
		{
			//如果有符合条件的那么就直接和count2异或
			count2 ^= nums[i];
		}
	}
	int* ptr = (int*)malloc(2 * 4);
	*ptr = count2;
	count1 ^= count2;
	*(ptr + 1) = count1;
	returnSize = ptr;
	return returnSize;
}
int main()
{
	int i = 0;
	int arr[4] = {1,2,5,2};
	int *str = NULL;
		str=singleNumbers(arr, 4, str);
	for (i = 0; i < 2; i++)
	{
		printf("%d ", *(str + i));
	}
	free(str);
	str = NULL;
	return 0;
}
//int* singleNumbers(int* nums, int numsSize, int* returnSize) {
//	int count1 = nums[0], count2 = 0, count3 = 0;
//	int i = 0;
//	
//	//int*src = NULL;
//	//int count4 = 0, count5 = 0;
//	for (i = 1; i<numsSize; i++)
//	{
//		count1 ^= nums[i];//count1代表两个单独的数按位与
//	}
//	count2 = count1;//count2是count1的拷贝，后面会改变值
//	while (count2)
//	{
//		count3++;//计算二进制中第几位是1,那就在找的时候找相同位置是0的位置
//		if (count2 % 2 == 1)
//		{
//			break;
//		}
//		count2 = count2 / 2;
//	}
//	count2 = count1;
//	for (i = 0; i<numsSize; i++)//找nums数组里面符合的数
//	{
//		if (nums[i] % (int)pow(2, count3) == 0)
//		{
//			//如果有符合条件的那么就直接和count2异或
//			count2^=nums[i];
//			//src = (int*)realloc(src, 4 * (1+i*i));
//			//src[count4] = nums[i];
//			//count4++;//记录一下加了多少个数
//		}
//	}
//	*returnSize = count2;
//	count1 ^= count2;
//	*(returnSize + 1) = count1;
//	//return returnSize;
//	//count5 = src[0];
//	//for (i = 1; i<count4; i++)
//	//{
//	//	count5 ^= src[i];
//	//}
//	//int tep = 0;
//	//tep = count1^count5;
//	//int*ptr = (int*)malloc(2 * 4);
//	//*ptr = tep;
//	//tep = count1^tep;
//	//*(ptr + 1) = tep;
//	//returnSize = ptr;
//	//free(src);
//	//src = NULL;
//	//return returnSize;
//}
//int main()
//{
//	int i = 0;
//	int arr[4] = { 3,1,3,2 };
//	int str[2] = {0};
//	singleNumbers(arr,4,str);
//	for (i = 0; i < 2; i++)
//	{
//		printf("%d ", *(str + i));
//	}
//	return 0;
//}
//#include<stddef.h>
//struct ss
//{
//	double b;
//	int a;
//};
////struct str
////{
////	struct ss;
////	int b;
////};
//int main()
//{
//	/*printf("%u ", sizeof(struct ss));
//	printf("%u ", sizeof(s1));*/
//	printf("%u ", offsetof(struct ss, a));
//}
//union Un
//{
//	char c;
//	int i;
//};
//int main()//用union来计算大小端
//{
//	union Un u;
//	u.i = 1;
//	if (u.c == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
