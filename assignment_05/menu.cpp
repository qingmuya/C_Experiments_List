#include "menu.h"
#include "Graph.h"
#include "Function.h"

void menu(){
    printf("\t*****欢迎使用以下功能****\n");
    printf("\t0：退出\n");
    printf("\t1：深度优先遍历（邻接矩阵）\n");
    printf("\t2：深度优先遍历（邻接表）\n");
    printf("\t3：广度优先遍历（邻接矩阵）\n");
    printf("\t4：广度优先遍历（邻接表）\n");
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
                //邻接矩阵深度优先遍历
                AMGraph A;
                Matrix_DFS(A);
                refresh();
                break;
            case 2:{
                //邻接表深度优先遍历
                ALGraph C;
                AdjList_DFS(C);
                refresh();
                break;
            }
            case 3:{
                //邻接矩阵广度优先遍历（BFS）
                AMGraph B;
                Matrix_BFS(B);
                refresh();
                break;
            }
            case 4:{
                //邻接表广度优先遍历
                ALGraph D;
                AdjList_BFS(D);
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
