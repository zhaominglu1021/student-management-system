#include "system.h"

//已经存储的学生数量
static int stu_num = 0;
//定义学生信息结构体指针数组
static StudentInfo stuinfo[STUMAX];

//学生信息
char sex[6];	//性别
int num;		//学号
int age;		//年龄
char name[16];	//姓名
char tel[16];	//电话
char address[32];	//地址

//添加学生信息
int addstu()
{
	int scan_num = 0;
	int ret;
	//判断是否已经存满
	if(stu_num >= STUMAX)
	{
		system("clear");
		printf("可存放的学生数量已满，请删除学生后再添加学生\n");
	}
	else
	{
		printf("请输入学生信息\n");
		printf("学号：");
		while((ret = scanf("%d", &num)) == 0)
		{
			printf("学号输入有误，请重新输入\n");
			while(getchar() != '\n');
		}
		//循环遍历整个数组
		while(scan_num < STUMAX)
		{
			//跳过数组空位
			if(stuinfo[scan_num] == NULL)
			{
				scan_num++;
				continue;
			}
			//判断学生是否存在，若存在则退出
			if(stuinfo[scan_num]->num == num)
			{
				system("clear");
				printf("\n==================\n该学生已存在\n==================\n");
				return 0;
			}
			scan_num++;

		}
		
		//遍历可存放的数组空位
		for(scan_num = 0; stuinfo[scan_num] != NULL; scan_num++);
		//判断是否是一个可存放的数组空位
		if(stuinfo[scan_num] == NULL)
		{
			//申请空间
			stuinfo[scan_num] = (StudentInfo)malloc(sizeof(Student_Info));
			//输入信息
			printf("姓名：");
			while((ret = scanf("%s", name)) == 0)
			{
				printf("姓名输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			printf("性别：");
			while((ret = scanf("%s", sex)) == 0)
			{
				printf("性别输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			printf("年龄：");
			while((ret = scanf("%d", &age)) == 0)
			{
				printf("年龄输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			printf("电话：");
			while((ret = scanf("%s", tel)) == 0)
			{
				printf("电话输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			printf("地址：");
			while((ret = scanf("%s", address)) == 0)
			{
				printf("地址输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			//将学生信息写入结构体中
			strcpy(stuinfo[scan_num]->sex, sex); 			//性别
			strcpy(stuinfo[scan_num]->tel, tel);			//电话
			strcpy(stuinfo[scan_num]->name, name);			//姓名
			strcpy(stuinfo[scan_num]->address, address);	//地址
			stuinfo[scan_num]->num = num;					//学号
			stuinfo[scan_num]->age = age;					//年龄
			//清屏
			system("clear");
			printf("\n==================\n学生信息添加完成\n==================\n");
			//存放的学生数量累计
			stu_num++;
		}
	}
	return 0;
}

//查看学生信息
int viewstu()
{
	int scan_num = 0;
	int ret;
	if(stu_num == 0)
	{
		printf("==================================\n");
		printf("            无学生信息            \n");
		printf("==================================\n");
	}
	//循环遍历整个数组
	while(scan_num < STUMAX)
	{
		//判断学生是否存在
		if(stuinfo[scan_num] == NULL)
		{
			scan_num++;
			continue;
		}
		printf("\n==================================\n");
		printf("学生%d信息：\n", scan_num);
		printf("姓名：%s\n", stuinfo[scan_num]->name);
		printf("学号：%d\n", stuinfo[scan_num]->num);
		printf("性别：%s\n", stuinfo[scan_num]->sex);
		printf("年龄：%d\n", stuinfo[scan_num]->age);
		printf("电话：%s\n", stuinfo[scan_num]->tel);
		printf("地址：%s\n", stuinfo[scan_num]->address);
		printf("====================================\n");
		scan_num++;
	}
}

//删除学生信息
int deletestu()
{
	int scan_num = 0;
	int ret;
	char flag;
	printf("请输入要删除的学生学号：\n");
	while((ret = scanf("%d", &num)) == 0)
	{
		printf("学号输入有误，请重新输入\n");
		while(getchar() != '\n');
	}
	//判断学生是否存在
	while(scan_num < STUMAX)
	{
		if(stuinfo[scan_num] == NULL)
		{
			scan_num++;
			continue;
		}
		if(stuinfo[scan_num]->num == num)
		{
			while(flag != 'y' && flag != 'n')
			{
				printf("==================\n确定删除该学生？ y：是 n：否\n==================\n");
				while(getchar() != '\n');
				scanf("%c", &flag);
			}
			if(flag == 'y')
			{
				memset(stuinfo[scan_num], 0, sizeof(Student_Info));
				free(stuinfo[scan_num]);
				stuinfo[scan_num] = NULL;
				system("clear");
				printf("\n==================\n学生信息已清空！\n==================\n");
				stu_num--;
				return 0;
			}
			else if(flag == 'n')
			{
				system("clear");
				printf("\n==================\n你在找茬是吧！\n==================\n\n");
				return 0;
			}
		}
		scan_num++;
	}
	system("clear");
	printf("\n==================\n该学生不存在\n==================\n");
	return 0;
}

//查找学生信息（仅限学号）
int findstu()
{
	int scan_num = 0;
	int ret;
	char flag;
	printf("请输入要查找的学生学号：\n");
	while((ret = scanf("%d", &num)) == 0)
	{
		printf("学号输入有误，请重新输入\n");
		while(getchar() != '\n');
	}
	//循环遍历整个数组
	while(scan_num < STUMAX)
	{
		//跳过数组空位
		if(stuinfo[scan_num] == NULL)
		{
			scan_num++;
			continue;
		}
		//判断学生是否存在，输出信息后退出
		if(stuinfo[scan_num]->num == num)
		{
			system("clear");
			printf("\n==================================\n");
			printf("已找到该学生%d：\n", scan_num);
			printf("姓名：%s\n", stuinfo[scan_num]->name);
			printf("学号：%d\n", stuinfo[scan_num]->num);
			printf("性别：%s\n", stuinfo[scan_num]->sex);
			printf("年龄：%d\n", stuinfo[scan_num]->age);
			printf("电话：%s\n", stuinfo[scan_num]->tel);
			printf("地址：%s\n", stuinfo[scan_num]->address);
			printf("====================================\n");
			return 0;
		}
		scan_num++;
	}
	//循环遍历整个数组结束没有找到学生则证明不存在
	system("clear");
	printf("\n==================\n该学生不存在\n==================\n");
	return 0;
}

//修改学生信息（仅限学号）
int changestu()
{
	int scan_num = 0;
	int ret;
	char flag;
	printf("请输入要修改的学生学号：\n");
	while((ret = scanf("%d", &num)) == 0)
	{
		printf("学号输入有误，请重新输入\n");
		while(getchar() != '\n');
	}
	//循环遍历整个数组
	while(scan_num < STUMAX)
	{
		//跳过数组空位
		if(stuinfo[scan_num] == NULL)
		{
			scan_num++;
			continue;
		}
		//判断学生是否存在，输出信息后退出
		if(stuinfo[scan_num]->num == num)
		{
			//输入信息
			system("clear");
			printf("请输入修改后的信息：\n");
			printf("学号：");
			while((ret = scanf("%d", &num)) == 0)
			{
				printf("学号输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			printf("姓名：");
			while((ret = scanf("%s", name)) == 0)
			{
				printf("姓名输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			printf("性别：");
			while((ret = scanf("%s", sex)) == 0)
			{
				printf("性别输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			printf("年龄：");
			while((ret = scanf("%d", &age)) == 0)
			{
				printf("年龄输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			printf("电话：");
			while((ret = scanf("%s", tel)) == 0)
			{
				printf("电话输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			printf("地址：");
			while((ret = scanf("%s", address)) == 0)
			{
				printf("地址输入有误，请重新输入\n");
				while(getchar() != '\n');
			}
			//将学生信息写入结构体中
			strcpy(stuinfo[scan_num]->sex, sex); 			//性别
			strcpy(stuinfo[scan_num]->tel, tel);			//电话
			strcpy(stuinfo[scan_num]->name, name);			//姓名
			strcpy(stuinfo[scan_num]->address, address);	//地址
			stuinfo[scan_num]->num = num;					//学号
			stuinfo[scan_num]->age = age;					//年龄
			//清屏
			system("clear");
			printf("\n==================\n学生信息修改完成\n==================\n");
			return 0;
		}
		scan_num++;
	}
	//循环遍历整个数组结束没有找到学生则证明不存在
	system("clear");
	printf("\n==================\n该学生不存在\n==================\n");
	return 0;
}
