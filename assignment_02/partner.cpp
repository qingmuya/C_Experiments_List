#include "NumberConversion.h"
#include "ExpressionEvaluation.h"
#include "menu.h"
#include "partner.h"

//入队
void pushQueue(Point *p1,Person p2)
{
	if(p1->tail+1==p1->front) return;
	p1->person[p1->tail++]=p2;
}
//出队
void outQueue(Point*p1,char *name)
{
	if(p1->front==p1->tail) return;
	strcpy(name,p1->person[p1->front++].name);
}
//获取队中首元素
void getHead(Point *p1,char *name)
{
	strcpy(name,p1->person[p1->front].name);
}

//分配舞伴
void Dance(Point manPoint,Point womanPoint)
{
	char s1[20];
	printf("已分配的舞伴：\n");
	//分配舞伴并输出
	while((manPoint.front!=manPoint.tail)&&(womanPoint.front!=womanPoint.tail)){
		outQueue(&manPoint,s1);
		printf("%s ",s1);
		outQueue(&womanPoint,s1);
		printf("%s\n",s1);
	}
	//判断是否还有人未分配舞伴，并记录下一次谁先分配到舞伴
	int flag=0;
	if(manPoint.front!=manPoint.tail){
		flag=1;
		getHead(&manPoint,s1);
	}
	if(womanPoint.front!=womanPoint.tail){
		flag=1;
		getHead(&womanPoint,s1);
	}
	if(flag){
		printf("下一次分配舞伴时%s最先分配到舞伴\n",s1);
	}else{
		printf("当前舞伴正好完全分配!\n");
	}
}
