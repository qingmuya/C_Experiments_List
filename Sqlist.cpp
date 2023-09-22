#include "Sqlist.h"
#include "Linklist.h"
#include "set.h"



//顺序表初始化
void InitSqlist(Sqlist &L){
    L.number = new int[MAXSIZE];
    L.length = 0;
}

//顺序表输入函数
void Input(Sqlist &L){
    int x;//用于确定输入数组的长度
    printf("输入本数组的长度：\n");
    scanf("%d",&x);
    printf("输入本数组的%d个数值，以空格间隔：\n",x);
    for(int i = 0;i < x;i++){
        scanf("%d",&L.number[i]);
    }
    L.length += x;
}

//顺序表合并
void Sqlist_merge(Sqlist &A,Sqlist &B){
    //C用于转存A和B合并的结果
    Sqlist C;
    InitSqlist(C);
    //A的值转存进C
    for(int i = 0;i < A.length;i++){
        C.number[i] = A.number[i];
        C.length++;
    }
    //将B的值转存进C
    for(int i = 0;i < B.length;i++){
        //用于判断是否重复
        int choose = 0;
        //遍历C，判断是否有重复
        for(int j = 0;j < C.length;j++){
            if(B.number[i] == C.number[j]){
                choose++;
                break;
            }
        }
        //根据choose判断是否插入
        if(choose == 0){
            C.number[C.length] = B.number[i];
            C.length++;
        }
    }
    //打印输出结果
    for(int i = 0;i < C.length;i++){
        printf("%d ",C.number[i]);
    }
}

//初始化多项式数组
void InitSqlistdata(data L[],int x){
    for(int i = 0;i < x;i++){
        L[i].coef = 0;
    }
}

//向多项式数组添加值
int Adddata(data L[]){
    //x限制接受多项式项数，e、c存储输入的系数和指数
    int x,e,Max = 0;
    float c;
    printf("请输入该多项式的项数：\n");
    scanf("%d",&x);
    printf("请输入多项式每项的系数及指数，以空格间隔：\n");
    for(int i = 0;i < x;i++){
        scanf("%f %d",&c,&e);
        L[e].coef = c;
        //保存最大指数
        if(e > Max){
            Max = e + 1;
        }
    }
    return Max;
}

//顺序表多项式相加，存入C，打印
void SqlistdataSum(data A[],data B[],int A_max,int B_max){
    int C_max;
    //判断最大指数
    if(A_max >= B_max){
        C_max = A_max;
    }
    else{
        C_max = B_max;
    }
    //定义多项式数组C
    data C[C_max];
    InitSqlistdata(C,C_max);
    //合并同类项
    for(int i = 0;i < A_max;i++){
        C[i].coef += A[i].coef;
    }
    for(int i = 0;i <= B_max;i++){
        C[i].coef += B[i].coef;
    }
    //打印输出
    dataPrint(C,C_max);
}

void dataPrint(data L[],int Max){
    //计数器，用于判断首个项
    int jsq = 0;
    //首项为常数项
    if(L[0].coef != 0){
        printf("%f ",L[0].coef);
        jsq++;
    }
    //首项的其他情况
    if(L[1].coef > 0 && jsq != 0){
        printf("+ %fx ",L[1].coef);
    }
    else if(L[1].coef < 0 && jsq != 0){
        printf("- %fx ",-L[1].coef);
    }
    else if(L[1].coef != 0 && jsq == 0){
        printf("%fx ",L[1].coef);
    }
    //普遍情况
    for(int i = 2;i < Max;i++){
        if(L[i].coef > 0){
            printf("+ %fx^%d ",L[i].coef,i);
        }
        else if(L[i].coef < 0){
            printf("- %fx^%d ",-L[i].coef,i);
        }
    }
}
