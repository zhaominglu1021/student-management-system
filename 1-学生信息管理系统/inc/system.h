#ifndef __SYSTEM_H
#define __SYSTEM_H

//依赖的头文件
#include <stdio.h>
#include "stumain.h"

//学生数量最大值
#define STUMAX 10

//学生信息结构体定义
typedef struct student_info{
	char sex[4];	//性别
	int num;		//学号
	int age;		//年龄
	char name[16];	//姓名
	char tel[16];	//电话
	char address[32];	//地址
}Student_Info, *StudentInfo;

//函数声明
int addstu();
int viewstu();
int deletestu();
int findstu();
int changestu();
#endif