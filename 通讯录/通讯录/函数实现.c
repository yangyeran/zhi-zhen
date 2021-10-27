# define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("*********************************\n");
	printf("*****0.EXIT       1.ADD  ********\n");//0->�˳���1->����
	printf("*****2.DELE       3.SEARCH  *****\n");//2->ɾ����3->����
	printf("*****4.ARR        5.SHOW ********\n");//5->��ӡ��4->����
	printf("**** 6.MODIFY     7.CLEAR   *****\n");//6->��
	printf("*********************************\n");
}

//��ʼ������
void Initialize_Contact(struct Contact*pcon)
{
	pcon->sz = 0;
	pcon->date = (struct Contact_people*)calloc(DEFAULT,sizeof(struct Contact_people));
	pcon->capacity = DEFAULT;
}

//������ϵ��(�Ƕ�̬�ڴ濪��)
//void Contact_ADD(struct Contact* pcon)
//{
//	if (pcon->sz < MAX)//�ж�������û����,û���Ļ�����
//	{
//		printf("���������֣�\n");
//		scanf("%s",pcon->date[pcon->sz].name);
//		printf("�������Ա�\n");
//		scanf("%s", pcon->date[pcon->sz].sex);
//		printf("������绰��\n");
//		scanf("%s", pcon->date[pcon->sz].phone);
//		printf("�������ַ��\n");
//		scanf("%s", pcon->date[pcon->sz].site);
//		printf("���������䣺\n");
//		scanf("%d", &pcon->date[pcon->sz].age);
//		printf("����ɹ�\n");
//		pcon->sz++;	
//	}
//	else
//	{	
//		printf("������ϵ��ʧ�ܣ��Ѿ��ﵽ���洢\n");
//	}
//}

//��̬�ڴ濪��
void Contact_ADD(struct Contact* pcon)
{
	if(pcon->sz==pcon->capacity)//���˵Ļ���realloc�����ٿռ�
	{
		struct Contact_people* ptr = (struct Contact_people*)realloc(pcon->date,(pcon->capacity+=2)*sizeof(struct Contact_people));
		if (ptr != NULL)
		{
			pcon->date = ptr;
			ptr = NULL;
			printf("���ݳɹ�\n");
		}
		else
			return -1;
	}
		printf("���������֣�\n");
		scanf("%s",pcon->date[pcon->sz].name);
		printf("�������Ա�\n");
		scanf("%s", pcon->date[pcon->sz].sex);
		printf("������绰��\n");
		scanf("%s", pcon->date[pcon->sz].phone);
		printf("�������ַ��\n");
		scanf("%s", pcon->date[pcon->sz].site);
		printf("���������䣺\n");
		scanf("%d", &pcon->date[pcon->sz].age);
		printf("����ɹ�\n");
		pcon->sz++;
}

//�鿴¼�����Ϣ
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

//������ϵ�ˣ�������ҵ���ϵ�˾ͻ᷵��1���Ҳ�������-1
//ͨ��������
int Find_Contact(const struct Contact* pcon, const char*name)
{
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->date[i].name,name) == 0)
			return i;//�ҵ������±�
	}
	return -1;//�Ҳ�������-1
}

//ɾ����ϵ��
void Contact_DELE(struct Contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	if (pcon->sz != 0)
	{
		printf("������Ҫɾ������ϵ��������\n");
		scanf("%s", name);
		//�����Ƿ��������ϵ��
		if (Find_Contact(pcon, name) != -1)
		{
			int i = Find_Contact(pcon, name);
			//ɾ����ϵ�ˣ��Ǻ��������������
			int j = 0;
			for (j = i; j < pcon->sz - 1; j++)
			{
				pcon->date[j] = pcon->date[j + 1];
			}
			pcon->sz--;
			printf("ɾ���ɹ�\n");
		}
		else
			printf("�Ҳ�����ϵ��\n");
	}
	else
		printf("ͨѶ¼����û����ϵ��\n");
}

//������ϵ��
void Contact_SEARCH(const struct Contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	printf("��������Ҫ���ҵ���ϵ��������");
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
		printf("û���������ϵ��\n");
}

//�ı���ϵ����Ϣ
void Contact_MODIFY(struct Contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	printf("��������Ҫ�޸���Ϣ����ϵ��������");
	scanf("%s", name);
	int i = Find_Contact(pcon, name);
	if (i != -1)//�޸���Ϣ
	{
		printf("�������µ����֣�\n");
		scanf("%s", pcon->date[i].name);
		printf("�������µ��Ա�\n");
		scanf("%s", pcon->date[i].sex);
		printf("�������µĵ绰��\n");
		scanf("%s", pcon->date[i].phone);
		printf("�������µĵ�ַ��\n");
		scanf("%s", pcon->date[i].site);
		printf("�������µ����䣺\n");
		scanf("%d", &pcon->date[i].age);
		printf("����ɹ�\n");
	}
	else
	{
		printf("û���������ϵ����Ϣ\n");
	}
}

//����
void Contact_ARR(struct Contact* pcon)
{
	//������������

	//������������
}


//�����ϵ��
void Contact_CLEAR(struct Contact* pcon)
{
	if (pcon->sz != 0)
	{
		Initialize_Contact(pcon);
		printf("�����ϵ�˳ɹ�\n");
	}
	else
		printf("ͨѶ¼������ϵ���������\n");
}

//�˳�ͨѶ¼
void Contact_EXIT(struct Contact* pcon)
{
	free(pcon->date);
	pcon->date = NULL;
	pcon->sz = 0;
	pcon->capacity = 0;
	printf("�˳�ͨѶ¼\n");
}