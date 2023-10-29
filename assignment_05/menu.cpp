#include "menu.h"
#include "Graph.h"
#include "Function.h"

void menu(){
    printf("\t*****��ӭʹ�����¹���****\n");
    printf("\t0���˳�\n");
    printf("\t1��������ȱ������ڽӾ���\n");
    printf("\t2��������ȱ������ڽӱ�\n");
    printf("\t3��������ȱ������ڽӾ���\n");
    printf("\t4��������ȱ������ڽӱ�\n");
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
                //�ڽӾ���������ȱ���
                AMGraph A;
                Matrix_DFS(A);
                refresh();
                break;
            case 2:{
                //�ڽӱ�������ȱ���
                ALGraph C;
                AdjList_DFS(C);
                refresh();
                break;
            }
            case 3:{
                //�ڽӾ��������ȱ�����BFS��
                AMGraph B;
                Matrix_BFS(B);
                refresh();
                break;
            }
            case 4:{
                //�ڽӱ������ȱ���
                ALGraph D;
                AdjList_BFS(D);
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
