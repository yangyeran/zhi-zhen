# define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("*********************************\n");
	printf("*****0.EXIT       1.ADD  ********\n");//0->退出，1->增加
	printf("*****2.DELE       3.SEARCH  *****\n");//2->删除，3->查找
	printf("*****4.ARR        5.SHOW ********\n");//5->打印，4->排列
	printf("**** 6.MODIFY     7.CLEAR   *****\n");//6->改
	printf("*********************************\n");
}

//初始化函数
void Initialize_Contact(struct Contact*pcon)
{
	pcon->sz = 0;
	pcon->date = (struct Contact_people*)calloc(DEFAULT,sizeof(struct Contact_people));
	pcon->capacity = DEFAULT;
}

//增加联系人(非动态内存开辟)
//void Contact_ADD(struct Contact* pcon)
//{
//	if (pcon->sz < MAX)//判断人数有没有满,没满的话增加
//	{
//		printf("请输入名字：\n");
//		scanf("%s",pcon->date[pcon->sz].name);
//		printf("请输入性别：\n");
//		scanf("%s", pcon->date[pcon->sz].sex);
//		printf("请输入电话：\n");
//		scanf("%s", pcon->date[pcon->sz].phone);
//		printf("请输入地址：\n");
//		scanf("%s", pcon->date[pcon->sz].site);
//		printf("请输入年龄：\n");
//		scanf("%d", &pcon->date[pcon->sz].age);
//		printf("保存成功\n");
//		pcon->sz++;	
//	}
//	else
//	{	
//		printf("增加联系人失败，已经达到最大存储\n");
//	}
//}

//动态内存开辟
void Contact_ADD(struct Contact* pcon)
{
	if(pcon->sz==pcon->capacity)//满了的话就realloc来开辟空间
	{
		struct Contact_people* ptr = (struct Contact_people*)realloc(pcon->date,(pcon->capacity+=2)*sizeof(struct Contact_people));
		if (ptr != NULL)
		{
			pcon->date = ptr;
			ptr = NULL;
			printf("扩容成功\n");
		}
		else
			return -1;
	}
		printf("请输入名字：\n");
		scanf("%s",pcon->date[pcon->sz].name);
		printf("请输入性别：\n");
		scanf("%s", pcon->date[pcon->sz].sex);
		printf("请输入电话：\n");
		scanf("%s", pcon->date[pcon->sz].phone);
		printf("请输入地址：\n");
		scanf("%s", pcon->date[pcon->sz].site);
		printf("请输入年龄：\n");
		scanf("%d", &pcon->date[pcon->sz].age);
		printf("保存成功\n");
		pcon->sz++;
}

//查看录入的信息
void Contact_SHOW(struct Contact* pcon)
{
	int i = 0;
	printf("%20s\t%10s\t%15s\t%20s\t%10s\t\n","name","sex","phone","site","age");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%20s\t%10s\t%15s\t%20s\t%10d\n", pcon->date[i].name,
			                                   pcon->date[i].sex, 
			                                   pcon->date[i].phone, 
			                                   pcon->date[i].site,
			                                   pcon->date[i].age);
	}
}

//查找联系人，如果能找到联系人就会返回1，找不到返回-1
//通过名字找
int Find_Contact(const struct Contact* pcon, const char*name)
{
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->date[i].name,name) == 0)
			return i;//找到返回下标
	}
	return -1;//找不到返回-1
}

//删除联系人
void Contact_DELE(struct Contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	if (pcon->sz != 0)
	{
		printf("输入需要删除的联系人姓名：\n");
		scanf("%s", name);
		//查找是否有这个联系人
		if (Find_Contact(pcon, name) != -1)
		{
			int i = Find_Contact(pcon, name);
			//删除联系人，那后面的数据来覆盖
			int j = 0;
			for (j = i; j < pcon->sz - 1; j++)
			{
				pcon->date[j] = pcon->date[j + 1];
			}
			pcon->sz--;
			printf("删除成功\n");
		}
		else
			printf("找不到联系人\n");
	}
	else
		printf("通讯录里面没有联系人\n");
}

//查找联系人
void Contact_SEARCH(const struct Contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入需要查找的联系人姓名：");
	scanf("%s", name);
	int i = Find_Contact(pcon, name);
	if (i != -1)
	{
		printf("%20s\t%10s\t%15s\t%20s\t%2s\t\n", "name", "sex", "phone", "site", "age");
		printf("%20s\t%10s\t%15s\t%20s\t%2d\n", pcon->date[i].name,
			pcon->date[i].sex,
			pcon->date[i].phone,
			pcon->date[i].site,
			pcon->date[i].age);
	}
	else
		printf("没有输入的联系人\n");
}

//改变联系人信息
void Contact_MODIFY(struct Contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入需要修改信息的联系人姓名：");
	scanf("%s", name);
	int i = Find_Contact(pcon, name);
	if (i != -1)//修改信息
	{
		printf("请输入新的名字：\n");
		scanf("%s", pcon->date[i].name);
		printf("请输入新的性别：\n");
		scanf("%s", pcon->date[i].sex);
		printf("请输入新的电话：\n");
		scanf("%s", pcon->date[i].phone);
		printf("请输入新的地址：\n");
		scanf("%s", pcon->date[i].site);
		printf("请输入新的年龄：\n");
		scanf("%d", &pcon->date[i].age);
		printf("保存成功\n");
	}
	else
	{
		printf("没有输入的联系人信息\n");
	}
}

//排序
void Contact_ARR(struct Contact* pcon)
{
	//根据姓名排列

	//根据年龄排列
}


//清空联系人
void Contact_CLEAR(struct Contact* pcon)
{
	if (pcon->sz != 0)
	{
		Initialize_Contact(pcon);
		printf("清空联系人成功\n");
	}
	else
		printf("通讯录中无联系人无需清空\n");
}

//退出通讯录
void Contact_EXIT(struct Contact* pcon)
{
	free(pcon->date);
	pcon->date = NULL;
	pcon->sz = 0;
	pcon->capacity = 0;
	printf("退出通讯录\n");
}