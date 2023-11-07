#include "menu.h"
#include "Graph.h"
#include "Function.h"

void menu(){
    printf("\t*****欢迎使用以下功能****\n");
    printf("\t0：退出\n");
    printf("\t1：计算最小生成树的总权重\n");
    printf("\t2：拓扑排序\n");
    printf("\t键入选项前数字调用功能：\n");
}

void Selectmenu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                exit(1);
            case 1:
                //计算最小生成树的总权重
                AMGraph A;
                Min_Tree(A);
                refresh();
                break;
            case 2:{
                //拓扑排序
                AMGraph B;
                Topo_sort(B);
                refresh();
                break;
            }
            default:
                printf("输入非法字符，重新键入：\n");
                break;
        }
    }
}

//刷新函数
void refresh(){
    printf("\n");
    system("Pause");
    system("cls");
    menu();
}
