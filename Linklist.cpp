#include "Sqlist.h"
#include "Linklist.h"
#include "set.h"

//��ʼ��������
void InitLNode(LinkList &L){
    L = new LNode;
    L->next = NULL;
}

//β�巨����������
LinkList LNodeInsert(LinkList &L){
    InitLNode(L);
    LNode *s,*r=L;
    int x,xz = 1,js = 0;
    while(1){
        printf("�ϴ����룺%d\n",r->data);
        printf("�����������Ҫ���������(��%d��)��\n",js + 1);
sr:        scanf("%d",&x);
        if(js != 0 && x < r->data){
            printf("δ��������˳�����룬����������(��%d��)��\n",js + 1);
            goto sr;
        }
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
        js += 1;
        printf("���� 0 �˳����룬���� 1 ��������:\n");
        scanf("%d",&xz);
        switch(xz){
            case 0:
                break;
            case 1:
                continue;
            default:
                printf("����Ƿ��ַ������¼��룺\n");
                break;
        }
        if(xz == 0){
            break;
        }
    }
    printf("���������\n");
    r->next = NULL;
    return L;
}

//�ϲ�����
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
    printf("�ϲ����Ϊ��\n");
    Print(C);
}


void Print(LinkList &L){
    L = L->next;
    while(L != NULL){
        printf("%d ",L->data);
        L = L->next;
    }
}
