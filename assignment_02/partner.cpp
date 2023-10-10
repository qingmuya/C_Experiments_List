#include "NumberConversion.h"
#include "ExpressionEvaluation.h"
#include "menu.h"
#include "partner.h"

//���
void pushQueue(Point *p1,Person p2)
{
	if(p1->tail+1==p1->front) return;
	p1->person[p1->tail++]=p2;
}
//����
void outQueue(Point*p1,char *name)
{
	if(p1->front==p1->tail) return;
	strcpy(name,p1->person[p1->front++].name);
}
//��ȡ������Ԫ��
void getHead(Point *p1,char *name)
{
	strcpy(name,p1->person[p1->front].name);
}

//�������
void Dance(Point manPoint,Point womanPoint)
{
	char s1[20];
	printf("�ѷ������飺\n");
	//������鲢���
	while((manPoint.front!=manPoint.tail)&&(womanPoint.front!=womanPoint.tail)){
		outQueue(&manPoint,s1);
		printf("%s ",s1);
		outQueue(&womanPoint,s1);
		printf("%s\n",s1);
	}
	//�ж��Ƿ�����δ������飬����¼��һ��˭�ȷ��䵽���
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
		printf("��һ�η������ʱ%s���ȷ��䵽���\n",s1);
	}else{
		printf("��ǰ���������ȫ����!\n");
	}
}