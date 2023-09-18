#include "Sqlist.h"
#include "Linklist.h"
#include "set.h"

void menu(){
    printf("\t*****��ӭʹ�����¹���****\n");
    printf("\t0���˳�\n");
    printf("\t1�����Ա��ϲ�\n");
    printf("\t2��������ϲ�\n");
    printf("\t3��ϡ�����ʽ�ӷ���˳�����\n");
    printf("\t4��ϡ�����ʽ�ӷ�����������\n");
    printf("\t��ѡ�����ݽṹ���ͣ�\n");
}

void refresh(){
    printf("\n");
    system("Pause");
    system("cls");
    menu();
}

void Selectmenu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                exit(1);
            case 1:
                Sqlist_merge();
                refresh();
                break;
            case 2:
                LinkList A,B;
                printf("������A�в�����ֵ��\n");
                LNodeInsert(A);
                printf("������B�в�����ֵ��\n");
                LNodeInsert(B);
                LNode_merge(A,B);
                refresh();
                break;
            case 3:
                int P_max,Q_max;
                data P[10],Q[10];
                InitSqlistdata(P,10);
                InitSqlistdata(Q,10);
                printf("�������ʽA��ֵ��\n");
                P_max = Adddata(P);
                printf("�������\n");
                printf("�������ʽB��ֵ��\n");
                Q_max = Adddata(Q);
                printf("�������\n");
                SqlistdataSum(P,Q,P_max,Q_max);
                refresh();
                break;
            //case 4:LNodeSum(LNode A,LNode B);break:
            default:
                printf("����Ƿ��ַ������¼��룺\n");
                break;
        }
    }
}