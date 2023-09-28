#ifndef PARTNER_H_INCLUDED
#define PARTNER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//存储舞伴信息的结构体
typedef struct{
	char name[20];
	char sex;
}Person;

//存储队列信息的结构体
typedef struct{
	Person *person;
	int front;//队头
	int tail;//队尾
}Point;

void pushQueue(Point *p1,Person p2);//入队

void outQueue(Point *p1,char *name);//出队

void getHead(Point *p1,char *name);//获取队中首元素

void Dance(Point A,Point B);//分配舞伴

#endif // PARTNER_H_INCLUDED
