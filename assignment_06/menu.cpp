#include "menu.h"
#include "Graph.h"
#include "Function.h"

void menu(){
    printf("\t*****��ӭʹ�����¹���****\n");
    printf("\t0���˳�\n");
    printf("\t1��������С����������Ȩ��\n");
    printf("\t2����������\n");
    printf("\t����ѡ��ǰ���ֵ��ù��ܣ�\n");
}

void Selectmenu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                exit(1);
            case 1:
                //������С����������Ȩ��
                AMGraph A;
                Min_Tree(A);
                refresh();
                break;
            case 2:{
                //��������
                AMGraph B;
                Topo_sort(B);
                refresh();
                break;
            }
            default:
                printf("����Ƿ��ַ������¼��룺\n");
                break;
        }
    }
}

//ˢ�º���
void refresh(){
    printf("\n");
    system("Pause");
    system("cls");
    menu();
}