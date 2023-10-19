#include "Cal_len_Huffman.h"
#include "create_Huffman_tree.h"
#include "print_Huffman_code.h"
#include "menu.h"

//创建哈夫曼树
void create_huffmantree(HuffTree &HT,int n){
    int m, s1, s2, i;
    if (n <= 1){
        return;
    }
    m = 2 * n - 1;
    HT = new HTnode[m + 1];  //0号单元未用，所以需要动态分配m+1个单元，HT[m]表示根结点
    for (i = 1; i <= m; ++i) //将1~m号单元中的双亲、左孩子，右孩子的下标都初始化为0
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    cout << "请输入字符：\n";
    for (i = 1; i <= n; ++i) //输入前n个单元中叶子结点的权值
        cin >> HT[i].data;


    cout << "请输入叶子结点的权值：\n";
    for (i = 1; i <= n; ++i) //输入前n个单元中叶子结点的权值
        cin >> HT[i].weight;
    for (i = n + 1; i <= m; ++i)
    { //通过n-1次的选择、删除、合并来创建赫夫曼树
        Select(HT, i - 1, s1, s2);
        //在HT[k](1≤k≤i-1)中选择两个其双亲域为0且权值最小的结点,
        // 并返回它们在HT中的序号s1和s2
        HT[s1].parent = i;
        HT[s2].parent = i;
        //得到新结点i，从森林中删除s1，s2，将s1和s2的双亲域由0改为i
        HT[i].lchild = s1;
        HT[i].rchild = s2;                            //s1,s2分别作为i的左右孩子
        HT[i].weight = HT[s1].weight + HT[s2].weight; //i 的权值为左右孩子权值之和
    }
}

//补全课本中函数，返回两个最小权值
void Select(HuffTree HT, int len, int &s1, int &s2){
    int i, min1 = 100, min2 = 100; //赋一个较大的值，防止开始就被返回
    for (i = 1; i <= len; i++)
    {
        if (HT[i].weight < min1 && HT[i].parent == 0)
        {
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    int zs = HT[s1].weight; //将原值存放起来，然后先赋予最大值，防止s1被重复选择
    HT[s1].weight = 100;
    for (i = 1; i <= len; i++)
    {
        if (HT[i].weight < min2 && HT[i].parent == 0)
        {
            min2 = HT[i].weight;
            s2 = i;
        }
    }
    HT[s1].weight = zs; //恢复原来的值
}

//计算哈夫曼编码
void CreateHuffmanCode(HuffTree HT,HuffmanCode &HC,int n){
    int start;
    HC = new char*[n+1];
    char cd[n];
    cd[n-1] = '\0';
    for(int i = 1;i<=n;i++){
        start = n-1;
        int c = i;
        int f = HT[i].parent;
        while(f!=0){
            start--;
            if(HT[f].lchild ==c){
                cd[start] = '0';
            }
            else{
                cd[start] = '1';
            }
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n-start];
        strcpy(HC[i],&cd[start]);
        cout<<HT[i].data<<":"<<HC[i]<<endl;
    }
}

//主函数
void print_huffman_code(HuffTree &HT){
    int n;
    printf("请输入字符总数：\n");
    scanf("%d",&n);
    create_huffmantree(HT,n);
    HuffmanCode HC;
    CreateHuffmanCode(HT,HC,n);
}
