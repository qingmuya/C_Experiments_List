#include "NumberConversion.h"
#include "ExpressionEvaluation.h"
#include "menu.h"
#include "partner.h"

void conversion(){
    SqStack s;
    InitStack(s);
    int Num,Base;
    char sl[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    printf("����ѭ����������ת����ֱ������ʮ������Ϊ-1������\n");
    while(1){
        printf("������ʮ��������\n");
        scanf("%d",&Num);
        if(Num == -1){
            break;
        }
        printf("������ת�����ƣ�\n");
        scanf("%d",&Base);
        int a[20]; //�������
        int i=0;
        if(Base != 16){
            while(Num != 0){
                push(s,Num % Base);
                Num = Num / Base;
            }//���̲�Ϊ0ʱ����ѭ��
            printf("ת�����ֵΪ��\n");
            while(!StackEmpty(s)){
                printf("%d",pop(s));
            }
            printf("\n");
        }
        else if(Base == 16){
            int i = 0;
            char ch[20];
            while(Num != 0){
                push2(s,sl[Num % 16]);
                Num = Num / Base;
            }
            while(!StackEmpty(s)){
                printf("%c",pop(s));
            }
            printf("\n");
        }
    }
}

void InitStack(SqStack &s){
    s.base = new int[MAXSIZE];
    s.top = s.base;
    s.stacksize = MAXSIZE;
}
void push(SqStack &s,int e){
    *s.top++ = e;
}
void push2(SqStack &s,char e){
    *s.top++ = e;
}
int  pop(SqStack &s){
    return *--s.top;
}

char pop2 (SqStack &s){
    return *--s.top;
}

bool StackEmpty(SqStack &s){
    if(s.top == s.base) return true;
    return false;
}