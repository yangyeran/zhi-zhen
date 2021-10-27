# define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
int main()
{
	int input;
	struct Contact con;//创建一个通讯录
	Initialize_Contact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择->");
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
			printf("输入错误请重新输入:\n");
			break;
		}
	} while (input);
}