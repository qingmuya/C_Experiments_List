#include "Cal_len_Huffman.h"
#include "create_Huffman_tree.h"
#include "print_Huffman_code.h"
#include "menu.h"

//主函数
void cal_len_huffman_tree(Huffmantree &HT){
    int n;
    printf("请输入字符总数：\n");
    scanf("%d",&n);
    create_huffman_tree(HT,n);
    cal(HT,n);
}

//创建哈夫曼树
void create_huffman_tree(Huffmantree &HT,int n){
    int m, s1, s2, i;
    if (n <= 1){
        return;
    }
    m = 2 * n - 1;
    HT = new Htnode[m + 1];
    for (i = 1; i <= m; ++i){
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    cout << "请输入叶子结点的权值：\n";
    for (i = 1; i <= n; ++i){
        cin >> HT[i].weight;
    }
    for (i = n + 1; i <= m; ++i){
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

//补全课本中函数，返回两个最小权值
void Select(Huffmantree HT, int len, int &s1, int &s2){
    int i, min1 = 100, min2 = 100; //赋一个较大的值，防止开始就被返回
    for (i = 1; i <= len; i++){
        if (HT[i].weight < min1 && HT[i].parent == 0){
            min1 = HT[i].weight;
            s1 = i;
        }
    }

    int zs = HT[s1].weight; //将原值存放起来，然后先赋予最大值，防止s1被重复选择

    HT[s1].weight = 100;
    for (i = 1; i <= len; i++){
        if (HT[i].weight < min2 && HT[i].parent == 0){
            min2 = HT[i].weight;
            s2 = i;
        }
    }
    HT[s1].weight = zs;
}

//计算并输出
void cal(Huffmantree HT,int n){
    int wpl = 0; //带权路径长度
    for(int i = 1;i <= n;i++){
        int Num_of_layers = 0;  //层数，即结点距离二叉树的长度
        int parent = HT[i].parent;
        int zs = i; //中间变量，仅是记录序号
        while(parent != 0){
            zs = parent;
            parent = HT[zs].parent; //沿着父亲结点一直上溯
            Num_of_layers++;    //层数叠加
        }
        wpl += HT[i].weight * Num_of_layers;
    }
    printf("WPL=%d\n",wpl);
}
