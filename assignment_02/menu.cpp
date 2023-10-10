#include "NumberConversion.h"
#include "ExpressionEvaluation.h"
#include "menu.h"
#include "partner.h"

#define MAXSIZE 1000  //���д�С

void menu(){
    printf("\t\t1����ֵת��\n");
    printf("\t\t2������ʽ��ֵ\n");
    printf("\t\t3������������\n");
    printf("\t\t0���˳�����\n");
    printf("\t\t��ѡ�����蹦��\n");
}

void select_menu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                exit(1);
            case 1:
                conversion();
                refresh();
                break;
            case 2:
                ExpressionEvaluation();
                refresh();
                break;
            case 3:
                Person man[MAXSIZE];//�洢�����Ķ���
                Person woman[MAXSIZE];//�洢Ů���Ķ���
                Point manPoint;//�������е���Ϣ
                Point womanPoint;//Ů�����е���Ϣ

                manPoint.person=man;
                manPoint.front=0;
                manPoint.tail=0;
                womanPoint.person=woman;
                womanPoint.front=0;
                womanPoint.tail=0;

                int n;
                Person x;
                printf("�������������������");
                scanf("%d",&n);
                printf("������������˵��������Ա�('F'Ϊ���ԣ�'MΪŮ��')\n");
                //�������������Ϣ����Ӧ���
                for(int i=0;i<n;i++){
                    scanf("%s %c",x.name,&x.sex);
                    if(x.sex=='F'){
                        pushQueue(&manPoint,x);
                    }else if(x.sex=='M'){
                        pushQueue(&womanPoint,x);
                    }
                }
                Dance(manPoint,womanPoint);//�������
                refresh();
                break;
            default:
                printf("����Ƿ��ַ������¼��룺\n");
                refresh();
                break;
        }
    }
}

void refresh(){
    system("pause");
    system("cls");
    menu();
}