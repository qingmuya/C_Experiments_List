#include "Cal_len_Huffman.h"
#include "create_Huffman_tree.h"
#include "print_Huffman_code.h"
#include "menu.h"

void menu(){
    printf("\t*****欢迎使用以下功能****\n");
    printf("\t0：退出\n");
    printf("\t1：创建哈夫曼树\n");
    printf("\t2：输出每个字符的哈夫曼编码\n");
    printf("\t3：计算哈夫曼树的带权路径长度\n");
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
                //创建哈夫曼树
                HuffmanTree HT;
                int n;
                cout<<"请输入总数:\n";
                scanf("%d",&n);
                create_huffman_tree(HT,n);
                refresh();
                break;
            case 2:{
                //输出每个字符对应的哈夫曼编码
                HuffTree HT;
                print_huffman_code(HT);
                refresh();
                break;
            }
            case 3:{
                //计算带权路径长度
                Huffmantree HT;
                cal_len_huffman_tree(HT);
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
