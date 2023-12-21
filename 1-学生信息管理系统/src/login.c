#include "login.h"

//登录函数
int mylogin()
{
	int num = 3;
	char ubuf[10] = {0},
	     pbuf[10] = {0};
	//循环判断3次用户密码
	while(num--)
	{
		printf("请输入用户名：");
		scanf("%s", ubuf);
		printf("请输入密码：");
		scanf("%s", pbuf);
		if(strcmp(ubuf, USERNAME) != 0)
		{
			printf("用户名不存在！请重新输入！\n");
			continue;
		}
		else if(strcmp(pbuf, PASSWORD) != 0)
		{
			printf("密码错误！\n");
			continue;
		}
		else
		{
			printf("登录成功\n");
			return num;
		}
	}
	//如果循环跑完3次，则证明用户密码不正确，返回-1
	printf("错误次数超限！\n");
	return num;
}
