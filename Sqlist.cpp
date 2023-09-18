#include "Sqlist.h"
#include "Linklist.h"
#include "set.h"



//顺序表初始化
void InitSqlist(Sqlist &L){
    L.number = new int[MAXSIZE];
    L.length = 0;
}

//顺序表合并
void Sqlist_merge(){
    Sqlist A;
    InitSqlist(A);
    Sqlist B;
    InitSqlist(B);
    Sqlist C;
    InitSqlist(C);

    for(int i = 0;i < 4;i++){
        int a;
        printf("输入顺序表A的第%d个元素（共四个元素）:\n",i+1);
        scanf("%d",&a);
        A.number[i] = a;
        A.length++;
    }

    for(int i = 0;i < 3;i++){
        int b;
        printf("输入顺序表B的第%d个元素（共三个元素）:\n",i+1);
        scanf("%d",&b);
        B.number[i] = b;
        B.length++;
    }

    for(int i = 0;i < B.length;i++){
        A.number[i + 4] = B.number[i];
        A.length++;
    }

    for(int i = 0;i < A.length;i++){
        printf("%d ",A.number[i]);
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
    int i = 1,js = 1,last;
    while(i){
        printf("输入第%d项的值：\n",js);
        float c = 0;   //系数
        int e = 0;   //指数
        printf("输入该项的指数：\n");
        scanf("%d",&e);
        last = e;
        printf("输入该项的系数：\n");
        scanf("%f",&c);
        L[e].coef = c;
        js++;
        printf("结束输入请输入 0 ，继续输入请输入 1 ：\n");
        scanf("%d",&i);
    }
    //printf("coef = %f  expn = %d\n",L[last].coef,last);
    return last;
}

//相加，存入C，打印
void SqlistdataSum(data A[],data B[],int A_max,int B_max){
    int C_max;
    data C[20];
    InitSqlistdata(C,20);
    if(A_max >= B_max){
        C_max = A_max;
    }
    else{
        C_max = B_max;
    }
    for(int i = 0;i <= A_max;i++){
        C[i].coef = C[i].coef + A[i].coef;
    }
    for(int i = 0;i <= B_max;i++){
        C[i].coef = C[i].coef + B[i].coef;
    }
    dataPrint(C,C_max);
}

void dataPrint(data L[],int Max){
    int sf = 0;
    //判断指数为0、1时，打印特殊值
    if(L[0].coef != 0){
        printf("%f",L[0].coef);
        sf++;
    }
    if(L[1].coef > 0){
        printf("+%fx",L[0].coef);
        sf++;
    }
    else if(L[1].coef < 0){
        printf("%fx",L[0].coef);
        sf++;
    }
    //循环判断即可
    for(int i = 2;i <= Max;i++){
        if(sf == 0 && L[i].coef != 0){
            printf("%fx^%d",L[i].coef,i);
            sf++;
        }
        else if(L[i].coef > 0 && sf == 1){
            printf("+%fx^%d",L[i].coef,i);
        }
        else if(L[i].coef < 0 && sf == 1){
            printf("%fx^%d",L[i].coef,i);
        }
    }
}
