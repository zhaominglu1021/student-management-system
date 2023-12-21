#include "stumain.h"


int menu()
{
	printf("\n");
	printf("***********************************************\n");
	printf("*                学生管理系统                 *\n");
	printf("***********************************************\n");
	printf("*               系统主界面模块                *\n");
	printf("***********************************************\n");
	printf("*  1）查看学生信息           2）增加学生信息  *\n");
	printf("*  3）修改学生信息           4）查找学生信息  *\n");
	printf("*  5）删除学生信息           6）退出系统      *\n");
	printf("***********************************************\n");
}

int main()
{

	int ret = 0;
	int choose_flag;
	
	ret = mylogin();
	if(ret == -1)
		return -1;
	
	
	while(1)
	{
		menu();
		printf("请输入您的选择：");
		ret = scanf("%d", &choose_flag);
		//错误字符处理
		if(ret == 0)
		{
			while(getchar() != '\n');
		}
		switch(choose_flag)
		{
			case 1:
				system("clear");
				viewstu();
				break;
			case 2:
				addstu();
				break;
			case 3:
				changestu();
				break;
			case 4:
				findstu();
				break;
			case 5:
				deletestu();
				break;
			case 6:
				system("clear");
				printf("已退出程序\n");
				return 0;
				break;
			default:
				system("clear");
				printf("请输入正确的选择\n");
				break;
		}
	}
	
	return 0;
}