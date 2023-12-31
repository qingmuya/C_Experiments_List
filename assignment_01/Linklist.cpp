#include "Sqlist.h"
#include "Linklist.h"
#include "set.h"

//初始化单链表
void InitLNode(LinkList &L){
    L = new LNode;
    L->next = NULL;
}

//初始化多项式单链表
void InitPNode(polynomial &L){
    L = new PNode;
    L->coef = 0;
    L->expn = 0;
    L->next = NULL;
}

//尾插法建立单链表
LinkList LNodeInsert(LinkList &L){
    InitLNode(L);
    LNode *s,*r=L;
    int x,xz = 1,js = 0;
    while(1){
        printf("按照升序键入要保存的数据(第%d个)：\n",js + 1);
sr:        scanf("%d",&x);
        if(js != 0 && x < r->data){
            printf("未按照升序顺序输入，请重新输入(第%d个)：\n",js + 1);
            goto sr;
        }
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
        js += 1;
        printf("输入 0 退出插入，输入 1 继续插入:\n");
        scanf("%d",&xz);
        switch(xz){
            case 0:
                break;
            case 1:
                continue;
            default:
                printf("输入非法字符，重新键入：\n");
                break;
        }
        if(xz == 0){
            break;
        }
    }
    printf("插入结束！\n");
    r->next = NULL;
    return L;
}

//多项式输入
polynomial PNodeInsert(polynomial &P){
    // 初始化单链表，指数设置为0，next设置NULL
    InitPNode(P);
    // P赋值给r
    PNode *s,*r = P;
    // e是指数的输入，
    int e,laste,js = 0,dd = 1;//指数
    float c;//系数
    while(dd){
pi:        printf("请按照指数升序输入第%d项的指数：\n",js + 1);
        scanf("%d",&e);
        if(js == 0){
            s = new PNode;
            s->expn = e;
            laste = e;
            printf("请输入第%d项的系数：\n",js + 1);
            scanf("%f",&c);
            s->coef = c;
            r->next = s;
            r = s;
            printf("停止输入请键入 0 ，继续输入请键入任意非零数：\n");
            scanf("%d",&dd);
            js++;
        }
        else if(js != 0 && e > laste){
            s = new PNode;
            s->expn = e;
            laste = e;
            printf("请输入第%d项的系数：\n",js + 1);
            scanf("%f",&c);
            s->coef = c;
            r->next = s;
            r = s;
            printf("停止输入请键入 0 ，继续输入请随意键入非零数：\n");
            scanf("%d",&dd);
            js++;
        }
        else{
            printf("所输入项未按照升序输入，请重新输入：\n");
            goto pi;
        }
    }
    r->next = NULL;
    printf("输入结束\n");
    return P;
}

//合并方法
void LNode_merge(LinkList &A,LinkList &B){
    LinkList C;
    InitLNode(C);
    LNode *p = A,*q = B,*r = C,*s;
    p = p->next;
    q = q->next;
    //有一方为空即停止
    while(p != NULL && q != NULL){
        s = new LNode;
        //开始对比数据大小
        if(p->data > q->data){
            s->data = q->data;
            r->next = s;
            r = s;
            r->next = NULL;
            q = q->next;
        }
        else if(p->data < q->data){
            s->data = p->data;
            r->next = s;
            r = s;
            r->next = NULL;
            p = p->next;
        }
        else if(p->data == q->data){
            s->data = q->data;
            r->next = s;
            r = s;
            r->next = NULL;
            s = new LNode;
            s->data = q->data;
            r->next = s;
            r = s;
            r->next = NULL;
            p = p->next;
            q = q->next;
        }
    }
    //一方先为空
    if(q == NULL){
        while(p != NULL){
            s = new LNode;
            s->data = p->data;
            r->next = s;
            r = s;
            r->next = NULL;
            p = p->next;
        }
    }
    else if(p == NULL){
        while(q != NULL){
            s = new LNode;
            s->data = q->data;
            r->next = s;
            r = s;
            r->next = NULL;
            q = q->next;
        }
    }
    printf("合并结果为：\n");
    PrintLNode(C);
}

//多项式合并
void PNode_merge(polynomial &A,polynomial &B){
    //A复制给C，将B中的元素添加到C即可
    //要么叠加，要么尾插
    polynomial C = A;
    PNode *p = B,*last = C;//last指针用于指向C的末尾，便于尾插
    p = p->next;
    //last = last->next;
    //将last的指针指到C末尾
    while(last->next != NULL){
        last = last->next;
    }
    //外循环用于循环B的内容
    while(p != NULL){
        int choose = 0;//用于判断是否尾插
        //每次循环q都会指向C的头节点
        PNode *q = C,*s;
        q = q->next;
        //内层循环用于遍历C，决定叠加or尾插
        while(q != NULL){
            //查找到了相同的指数,叠加后退出内循环
            if(p->expn == q->expn){
                q->coef = p->coef + q->coef;
                choose++;
                break;
            }
            q = q->next;
        }
        //叠加条件不充分，进行尾插
        if(choose == 0){
            s = new PNode;
            s->coef = p->coef;
            s->expn = p->expn;
            last->next = s;
            last = s;
            last->next = NULL;
        }
        //遍历下一个B中的值
        p = p->next;
    }
    printf("合并结果为：\n");
    PrintPNode(C);
}

//打印输出单链表
void PrintLNode(LinkList &L){
    L = L->next;
    while(L != NULL){
        printf("%d ",L->data);
        L = L->next;
    }
}

//打印输出多项式
void PrintPNode(polynomial &L){
    /*L = L->next;
    int jsq = 0;
    printf("系数\t指数\n");
    while(L != NULL){
        printf("%f\t%d\n",L->coef,L->expn);
        L = L->next;
    }*/

    L = L->next;
    int jsq = 0;
    //第一项为常数
    if(L->expn == 0){
        printf("%f ",L->coef);
        L = L->next;
        jsq++;
    }
    while(L != NULL){
        //第一项不是常数，不分正负
        if(jsq == 0 && L->expn != 0){
            printf("%fx^%d",L->coef,L->expn);
            L = L->next;
            jsq++;
        }
        //系数为负数时候
        else if(jsq != 0 && L->coef < 0){
            printf("- %fx^%d ",-L->coef,L->expn);
            L = L->next;
            jsq++;
        }
        else if(jsq != 0 && L->coef > 0){
            printf("+ %fx^%d ",L->coef,L->expn);
            L = L->next;
            jsq++;
        }
        else if(L->coef == 0){
            L = L->next;
        }
    }
}
