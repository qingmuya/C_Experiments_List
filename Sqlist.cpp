#include "Sqlist.h"
#include "Linklist.h"
#include "set.h"



//˳����ʼ��
void InitSqlist(Sqlist &L){
    L.number = new int[MAXSIZE];
    L.length = 0;
}

//˳���ϲ�
void Sqlist_merge(){
    Sqlist A;
    InitSqlist(A);
    Sqlist B;
    InitSqlist(B);
    Sqlist C;
    InitSqlist(C);

    for(int i = 0;i < 4;i++){
        int a;
        printf("����˳���A�ĵ�%d��Ԫ�أ����ĸ�Ԫ�أ�:\n",i+1);
        scanf("%d",&a);
        A.number[i] = a;
        A.length++;
    }

    for(int i = 0;i < 3;i++){
        int b;
        printf("����˳���B�ĵ�%d��Ԫ�أ�������Ԫ�أ�:\n",i+1);
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

//��ʼ������ʽ����
void InitSqlistdata(data L[],int x){
    for(int i = 0;i < x;i++){
        L[i].coef = 0;
    }
}

//�����ʽ�������ֵ
int Adddata(data L[]){
    int i = 1,js = 1,last;
    while(i){
        printf("�����%d���ֵ��\n",js);
        float c = 0;   //ϵ��
        int e = 0;   //ָ��
        printf("��������ָ����\n");
        scanf("%d",&e);
        last = e;
        printf("��������ϵ����\n");
        scanf("%f",&c);
        L[e].coef = c;
        js++;
        printf("�������������� 0 ���������������� 1 ��\n");
        scanf("%d",&i);
    }
    //printf("coef = %f  expn = %d\n",L[last].coef,last);
    return last;
}

//��ӣ�����C����ӡ
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
    //�ж�ָ��Ϊ0��1ʱ����ӡ����ֵ
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
    //ѭ���жϼ���
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
