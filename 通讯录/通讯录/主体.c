# define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
int main()
{
	int input;
	struct Contact con;//����һ��ͨѶ¼
	Initialize_Contact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Contact_ADD(&con);
			break;
		case DELE:
			Contact_DELE(&con);
			break;
		case SEARCH:
			Contact_SEARCH(&con);
			break;
		case MODIFY:
			Contact_MODIFY(&con);
			break;
		case ARR:
			Contact_ARR(&con);
			break;
		case EXIT:
			Contact_EXIT(&con);
			break;
		case SHOW:
			Contact_SHOW(&con);
			break;
		case CLEAR:
			Contact_CLEAR(&con);
			break;
		default:
			printf("�����������������:\n");
			break;
		}
	} while (input);
}