#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<stdlib.h>
void menu();
#define MAX 1000
enum Cont//����һ��ö������
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
#define DEFAULT 3 //Ĭ�ϴ�С
#define NAME_MAX 20
#define SEX_MAX 8
#define PHONE_MAX 15
#define SITE_MAX 40
struct Contact_people //1����ϵ�˵���Ϣ
{
	char name[NAME_MAX];//����
	char sex[SEX_MAX];//�Ա�
	char phone[PHONE_MAX];//�绰
	char site[SITE_MAX];//סַ
	int age;
};

//�Ƕ�̬�ڴ濪��
//struct Contact//ͨѶ¼
//{
//	struct Contact_people date[MAX];
//	int sz;//ʵ�����õ���Ϣ
//};


//��̬�ڴ濪�ٿռ�
struct Contact//ͨѶ¼
{
	struct Contact_people* date;
	int sz;//ʵ��ʹ�õ���Ϣ
	int capacity;//�ܵĴ�С
};


//��ʼ��ͨѶ¼
void Initialize_Contact(struct Contact*pcon);


//������ϵ��
void Contact_ADD(struct Contact*pcon);


//�鿴¼�����ϵ����Ϣ
void Contact_SHOW(struct Contact*pcon);


//ɾ����ϵ��
void Contact_DELE(struct Contact*pcon);


//������ϵ��
void Contact_SEARCH(struct Contact* pcon);

//�ı���ϵ����Ϣ
void Contact_MODIFY(struct Contact* pcon);



//����
void Contact_ARR(struct Contact* pcon);
//�����ϵ��	
void Contact_CLEAR(struct Contact* pcon);
//�˳�ͨѶ¼
void Contact_EXIT(struct Contact* pcon);