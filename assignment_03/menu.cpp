#include "Create_Btree.h"
#include "Ctnon.h"
#include "Cxbl.h"
#include "Dgbl.h"
#include "Fdgzxbl.h"
#include "menu.h"

void menu(){
    printf("--------键入功能前数字使用功能--------\n");
    printf("\t0：退出程序\n");
    printf("\t1：创建二叉树\n");
    printf("\t2：遍历二叉树\n");
    printf("\t\t1：递归遍历二叉树：输出结果按照先序、中序、后序遍历\n");
    printf("\t\t2：非递归中序遍历\n");
    printf("\t\t3：层序遍历\n");
    printf("\t3：求二叉树叶子结点的个数\n");
    printf("键入数字选择功能：\n");
}

void select_menu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            //退出程序
            case 0:
                exit(1);
            //创建二叉树
            case 1:
                BiTree T;
                create_Btree(T);
                printf("创建二叉树成功！\n");
                printf("创建二叉树结果为：");
                print_Btree(T);
                printf("\n");
                refresh();
                break;
            //遍历二叉树
            case 2:{
                int jc = 0;//检测用，即查看函数是否执行
                printf("再次键入子菜单前数字选择相关功能：\n");
                while(jc == 0){
                    int xz_r;
                    scanf("%d",&xz_r);
                    switch(xz_r){
                        case 1:
                            BiTree T;
                            printf("创建二叉树：\n");
                            create_Btree(T);
                            recursive_traversal(T);//递归遍历
                            jc++;
                            break;
                        case 2:
                            non_recursive_mid_order_traversal();//非递归中序遍历
                            jc++;
                            break;
                        case 3:
                            layer_order_traversal();//层序遍历
                            jc++;
                            break;
                        default:
                            printf("键入非法字符，重新键入：\n");
                            break;
                    }
                }
                refresh();
                break;
            }
            //求二叉树叶子节点的个数
            case 3:
                count_the_number_of_nodes();
                refresh();
                break;
            default:
                printf("键入非法字符，重新键入：\n");
                break;
        }
    }
}

void refresh(){
    system("pause");
    system("cls");
    menu();
}
