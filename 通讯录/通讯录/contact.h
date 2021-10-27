#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<stdlib.h>
void menu();
#define MAX 1000
enum Cont//定义一个枚举类型
{
	EXIT,
	ADD,
	DELE,
	SEARCH,
	ARR,
	SHOW,
	MODIFY,
	CLEAR
};
#define DEFAULT 3 //默认大小
#define NAME_MAX 20
#define SEX_MAX 8
#define PHONE_MAX 15
#define SITE_MAX 40
struct Contact_people //1个联系人的信息
{
	char name[NAME_MAX];//名字
	char sex[SEX_MAX];//性别
	char phone[PHONE_MAX];//电话
	char site[SITE_MAX];//住址
	int age;
};

//非动态内存开辟
//struct Contact//通讯录
//{
//	struct Contact_people date[MAX];
//	int sz;//实际有用的信息
//};


//动态内存开辟空间
struct Contact//通讯录
{
	struct Contact_people* date;
	int sz;//实际使用的信息
	int capacity;//总的大小
};


//初始化通讯录
void Initialize_Contact(struct Contact*pcon);


//增加联系人
void Contact_ADD(struct Contact*pcon);


//查看录入的联系人信息
void Contact_SHOW(struct Contact*pcon);


//删除联系人
void Contact_DELE(struct Contact*pcon);


//查找联系人
void Contact_SEARCH(struct Contact* pcon);

//改变联系人信息
void Contact_MODIFY(struct Contact* pcon);



//排序
void Contact_ARR(struct Contact* pcon);
//清空联系人	
void Contact_CLEAR(struct Contact* pcon);
//退出通讯录
void Contact_EXIT(struct Contact* pcon);