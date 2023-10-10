#ifndef SQSTACKCH_H_INCLUDED
#define SQSTACKCH_H_INCLUDED
typedef struct{
    char *base;
    char *top;
    int stacksize;
}SqStackch;
typedef struct{
    double *base;
    double *top;
    int stacksize;
}SqStackdo;



void InitStackch(SqStackch &s);
void InitStackdo(SqStackdo &s);


void pushch(SqStackch &s,char e);
void pushnum(SqStackdo &s,double d);


char popch(SqStackch &s);
double popnum(SqStackdo &s);


char Get_top_char(SqStackch s);
double Get_top_num(SqStackdo s);

double Powerop(double a,int n);
bool JudgeIn(char c);
char Prioritize(char top,char ch);
double operate(double a,char cha,double b);

void ExpressionEvaluation();
#endif // SQSTACKCH_H_INCLUDED
