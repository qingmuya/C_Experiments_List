#include "Sqlist.h"
#include "Linklist.h"
#include "set.h"



//˳����ʼ��
void InitSqlist(Sqlist &L){
    L.number = new int[MAXSIZE];
    L.length = 0;
}

//˳������뺯��
void Input(Sqlist &L){
    int x;//����ȷ����������ĳ���
    printf("���뱾����ĳ��ȣ�\n");
    scanf("%d",&x);
    printf("���뱾�����%d����ֵ���Կո�����\n",x);
    for(int i = 0;i < x;i++){
        scanf("%d",&L.number[i]);
    }
    L.length += x;
}

//˳���ϲ�
void Sqlist_merge(Sqlist &A,Sqlist &B){
    //C����ת��A��B�ϲ��Ľ��
    Sqlist C;
    InitSqlist(C);
    //A��ֵת���C
    for(int i = 0;i < A.length;i++){
        C.number[i] = A.number[i];
        C.length++;
    }
    //��B��ֵת���C
    for(int i = 0;i < B.length;i++){
        //�����ж��Ƿ��ظ�
        int choose = 0;
        //����C���ж��Ƿ����ظ�
        for(int j = 0;j < C.length;j++){
            if(B.number[i] == C.number[j]){
                choose++;
                break;
            }
        }
        //����choose�ж��Ƿ����
        if(choose == 0){
            C.number[C.length] = B.number[i];
            C.length++;
        }
    }
    //��ӡ������
    for(int i = 0;i < C.length;i++){
        printf("%d ",C.number[i]);
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
    //x���ƽ��ܶ���ʽ������e��c�洢�����ϵ����ָ��
    int x,e,Max = 0;
    float c;
    printf("������ö���ʽ��������\n");
    scanf("%d",&x);
    printf("���������ʽÿ���ϵ����ָ�����Կո�����\n");
    for(int i = 0;i < x;i++){
        scanf("%f %d",&c,&e);
        L[e].coef = c;
        //�������ָ��
        if(e > Max){
            Max = e + 1;
        }
    }
    return Max;
}

//˳������ʽ��ӣ�����C����ӡ
void SqlistdataSum(data A[],data B[],int A_max,int B_max){
    int C_max;
    //�ж����ָ��
    if(A_max >= B_max){
        C_max = A_max;
    }
    else{
        C_max = B_max;
    }
    //�������ʽ����C
    data C[C_max];
    InitSqlistdata(C,C_max);
    //�ϲ�ͬ����
    for(int i = 0;i < A_max;i++){
        C[i].coef += A[i].coef;
    }
    for(int i = 0;i <= B_max;i++){
        C[i].coef += B[i].coef;
    }
    //��ӡ���
    dataPrint(C,C_max);
}

void dataPrint(data L[],int Max){
    //�������������ж��׸���
    int jsq = 0;
    //����Ϊ������
    if(L[0].coef != 0){
        printf("%f ",L[0].coef);
        jsq++;
    }
    //������������
    if(L[1].coef > 0 && jsq != 0){
        printf("+ %fx ",L[1].coef);
    }
    else if(L[1].coef < 0 && jsq != 0){
        printf("- %fx ",-L[1].coef);
    }
    else if(L[1].coef != 0 && jsq == 0){
        printf("%fx ",L[1].coef);
    }
    //�ձ����
    for(int i = 2;i < Max;i++){
        if(L[i].coef > 0){
            printf("+ %fx^%d ",L[i].coef,i);
        }
        else if(L[i].coef < 0){
            printf("- %fx^%d ",-L[i].coef,i);
        }
    }
}
