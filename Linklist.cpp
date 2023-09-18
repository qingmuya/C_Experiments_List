#include "Sqlist.h"
#include "Linklist.h"
#include "set.h"

//初始化单链表
void InitLNode(LinkList &L){
    L = new LNode;
    L->next = NULL;
}

//尾插法建立单链表
LinkList LNodeInsert(LinkList &L){
    InitLNode(L);
    LNode *s,*r=L;
    int x,xz = 1,js = 0;
    while(1){
        printf("上次输入：%d\n",r->data);
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

//合并方法
void LNode_merge(LinkList &A,LinkList &B){
    LinkList C;
    InitLNode(C);
    LNode *p = A,*q = B,*r = C,*s;
    p = p->next;
    q = q->next;
    printf("p->data : %d\n",p->data);
    printf("q->data : %d\n",q->data);
    /*while(1){
        printf("%d ",p->data);
        p = p->next;
        if(p == NULL){
            printf("Good Lucky");
            break;
        }
    }*/
    while(p != NULL && q != NULL){
        s = new LNode;
        if(p->data > q->data){
            s->data = q->data;
            r->next = s;
            r = s;
            r->next = NULL;
            q = q->next;
            //printf("1 C->data == %d\n",C->data);
        }

        else if(p->data < q->data){
            s->data = p->data;
            r->next = s;
            r = s;
            r->next = NULL;
            p = p->next;
            //printf("2 C->data == %d\n",C->data);
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
            //printf("3 C->data == %d\n",C->data);
        }
    }
    if(q == NULL){
        while(p != NULL){
            s = new LNode;
            s->data = p->data;
            r->next = s;
            r = s;
            r->next = NULL;
            p = p->next;
            //printf("4 C->data == %d\n",C->data);
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
            //printf("5 C->data == %d\n",C->data);
        }
    }
    printf("合并结果为：\n");
    Print(C);
}


void Print(LinkList &L){
    L = L->next;
    while(L != NULL){
        printf("%d ",L->data);
        L = L->next;
    }
}
