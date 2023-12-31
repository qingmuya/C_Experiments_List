#include "NumberConversion.h"
#include "ExpressionEvaluation.h"
#include "menu.h"
#include "partner.h"

#define MAXSIZE 100

void ExpressionEvaluation(){
    //cha   全部字符 symbol 保存的计算符号   allnum   保存的数字
    char cha[100];
    char symbol[100];
    double allnum[100];
    //初始化
    SqStackch opnd;
    SqStackdo optr;
    InitStackch(opnd);
    InitStackdo(optr);
    //压栈，便于计算#
    pushch(opnd,'#');
    printf("\n输入多项式，末尾以'#'结尾，若输入数包含负数，请用（0-x）表示: \n");
    scanf("%s",cha);
    int j = 0;
    //分离数字和符号
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
            // /0用于终止数组
            numch[p] = '\0';
            //利用atof函数将字符转化为数字
            allnum[js++] = atof(numch);
            //将原本表达式中的数字换为X
            symbol[j++] = 'x';
            i--;
        }
    }

    int m = 0;
    int n = 0;
    while(opnd.base != opnd.top){
        if(symbol[m] == 'x') {
            //对数字进行压栈操作
            pushnum(optr,allnum[n]);
            n++;
            m++;
        }
        else{
            //判断优先级
            switch(Prioritize(Get_top_char(opnd),symbol[m])){
            //小于即运算符压栈
            case '<':
                pushch(opnd,symbol[m++]);
                break;
            case '>':
                pushnum(optr,operate(popnum(optr),popch(opnd),popnum(optr)));
                //大于进行计算
                break;
            case '=':
                //对'('和'#'进行处理
                char x = popch(opnd);
                m++;
                break;
            }
        }
    }
    printf("\n运算结果为:%lf\n",Get_top_num(optr));
}

//字符初始化
void InitStackch(SqStackch &s){
    s.base = new char[MAXSIZE];
    s.top = s.base;
    s.stacksize = MAXSIZE;
}

//数字栈初始化
void InitStackdo(SqStackdo &s){
    s.base = new double[MAXSIZE];
    s.top = s.base;
    s.stacksize = MAXSIZE;
}

//压栈
void pushch(SqStackch &s,char e){
    *s.top++ = e;
}

//出栈
char popch(SqStackch &s){
    return *--s.top;
}

//取字符栈顶元素
char Get_top_char(SqStackch s){
    return *(s.top-1);
}

//数字压栈
void pushnum(SqStackdo &s,double e){
    *s.top++ = e;
}

//数字出栈
double popnum(SqStackdo &s){
    return *--s.top;
}

//取数字栈顶元素
double Get_top_num(SqStackdo s){
    return *(s.top-1);
}

//判断是否为运算符
bool JudgeIn(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' ||c == '#'||c == '^') {
        return true;
    }
    return false;
}

//优先级判断
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

//幂运算
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

//计算
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
