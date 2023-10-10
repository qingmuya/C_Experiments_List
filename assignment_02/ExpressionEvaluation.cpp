#include "NumberConversion.h"
#include "ExpressionEvaluation.h"
#include "menu.h"
#include "partner.h"

#define MAXSIZE 100

void ExpressionEvaluation(){
    //cha   ȫ���ַ� symbol ����ļ������   allnum   ���������
    char cha[100];
    char symbol[100];
    double allnum[100];
    //��ʼ��
    SqStackch opnd;
    SqStackdo optr;
    InitStackch(opnd);
    InitStackdo(optr);
    //ѹջ�����ڼ���#
    pushch(opnd,'#');
    printf("\n�������ʽ��ĩβ��'#'��β�����������������������ã�0-x����ʾ: \n");
    scanf("%s",cha);
    int j = 0;
    //�������ֺͷ���
    int js = 0;
    for(int i = 0;i < strlen(cha);i++){
        if(JudgeIn(cha[i])){
            symbol[j] = cha[i];
            j++;
        }
        else if(cha[i]>='0' && cha[i]<='9'){
            int p = 0;
            char numch[100];
            while(!JudgeIn(cha[i]) && i < strlen(cha)){
                numch[p] = cha[i];
                i++;
                p++;
            }
            // /0������ֹ����
            numch[p] = '\0';
            //����atof�������ַ�ת��Ϊ����
            allnum[js++] = atof(numch);
            //��ԭ������ʽ�е����ֻ�ΪX
            symbol[j++] = 'x';
            i--;
        }
    }

    int m = 0;
    int n = 0;
    while(opnd.base != opnd.top){
        if(symbol[m] == 'x') {
            //�����ֽ���ѹջ����
            pushnum(optr,allnum[n]);
            n++;
            m++;
        }
        else{
            //�ж����ȼ�
            switch(Prioritize(Get_top_char(opnd),symbol[m])){
            //С�ڼ������ѹջ
            case '<':
                pushch(opnd,symbol[m++]);
                break;
            case '>':
                pushnum(optr,operate(popnum(optr),popch(opnd),popnum(optr)));
                //���ڽ��м���
                break;
            case '=':
                //��'('��'#'���д���
                char x = popch(opnd);
                m++;
                break;
            }
        }
    }
    printf("\n������Ϊ:%lf\n",Get_top_num(optr));
}

//�ַ���ʼ��
void InitStackch(SqStackch &s){
    s.base = new char[MAXSIZE];
    s.top = s.base;
    s.stacksize = MAXSIZE;
}

//����ջ��ʼ��
void InitStackdo(SqStackdo &s){
    s.base = new double[MAXSIZE];
    s.top = s.base;
    s.stacksize = MAXSIZE;
}

//ѹջ
void pushch(SqStackch &s,char e){
    *s.top++ = e;
}

//��ջ
char popch(SqStackch &s){
    return *--s.top;
}

//ȡ�ַ�ջ��Ԫ��
char Get_top_char(SqStackch s){
    return *(s.top-1);
}

//����ѹջ
void pushnum(SqStackdo &s,double e){
    *s.top++ = e;
}

//���ֳ�ջ
double popnum(SqStackdo &s){
    return *--s.top;
}

//ȡ����ջ��Ԫ��
double Get_top_num(SqStackdo s){
    return *(s.top-1);
}

//�ж��Ƿ�Ϊ�����
bool JudgeIn(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' ||c == '#'||c == '^') {
        return true;
    }
    return false;
}

//���ȼ��ж�
char Prioritize(char top,char cha){
    int numtop = 0,numch = 0;
    switch(top){
    case '+': numtop = 0;
        break;
    case '-': numtop = 1;
        break;
    case '*':numtop = 2;
        break;
    case '/':numtop = 3;
        break;
    case '(':numtop = 4;
        break;
    case ')':numtop = 5;
        break;
    case '#':numtop = 6;
        break;
    case '^':numtop = 7;
        break;

    }
    switch(cha){
    case '+': numch = 0;
        break;
    case '-': numch = 1;
        break;
    case '*':numch = 2;
        break;
    case '/':numch = 3;
        break;
    case '(':numch = 4;
        break;
    case ')':numch = 5;
        break;
    case '#':numch = 6;
        break;
    case '^':numch = 7;
        break;
    }
    char chh[8][8] = {
        {'>','>','<','<','<','>','>','<'},
        {'>','>','<','<','<','>','>','<'},
        {'>','>','>','>','<','>','>','<'},
        {'>','>','>','>','<','>','>','<'},
        {'<','<','<','<','<','=',' ','<'},
        {'>','>','>','>',' ','>','>','>'},
        {'<','<','<','<','<',' ','=','<'},
        {'>','>','>','>','<','>','>','>'}
        };
    return chh[numtop][numch];
}

//������
double Powerop(double a,int n){
    double endcount = 1;
    if(a == 0) return 0;
    if(n == 0){
        endcount = 1;
    }
    else if(n<0){
        a = 1 / a;
        n = -n;
    }
    for(int i = 0;i<n;i++){
        endcount = endcount * a;
    }
    return endcount;
}

//����
double operate(double a,char cha,double b){
    switch(cha){
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return Powerop(a,(int)b);
    }
    return 0;
}