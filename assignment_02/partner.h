#ifndef PARTNER_H_INCLUDED
#define PARTNER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�洢�����Ϣ�Ľṹ��
typedef struct{
	char name[20];
	char sex;
}Person;

//�洢������Ϣ�Ľṹ��
typedef struct{
	Person *person;
	int front;//��ͷ
	int tail;//��β
}Point;

void pushQueue(Point *p1,Person p2);//���

void outQueue(Point *p1,char *name);//����

void getHead(Point *p1,char *name);//��ȡ������Ԫ��

void Dance(Point A,Point B);//�������

#endif // PARTNER_H_INCLUDED
