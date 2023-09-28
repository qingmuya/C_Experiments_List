#include "Sqlist.h"
#include "Linklist.h"
#include "set.h"

//��ʼ��������
void InitLNode(LinkList &L){
    L = new LNode;
    L->next = NULL;
}

//��ʼ������ʽ������
void InitPNode(polynomial &L){
    L = new PNode;
    L->coef = 0;
    L->expn = 0;
    L->next = NULL;
}

//β�巨����������
LinkList LNodeInsert(LinkList &L){
    InitLNode(L);
    LNode *s,*r=L;
    int x,xz = 1,js = 0;
    while(1){
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

//����ʽ����
polynomial PNodeInsert(polynomial &P){
    // ��ʼ����������ָ������Ϊ0��next����NULL
    InitPNode(P);
    // P��ֵ��r
    PNode *s,*r = P;
    // e��ָ�������룬
    int e,laste,js = 0,dd = 1;//ָ��
    float c;//ϵ��
    while(dd){
pi:        printf("�밴��ָ�����������%d���ָ����\n",js + 1);
        scanf("%d",&e);
        if(js == 0){
            s = new PNode;
            s->expn = e;
            laste = e;
            printf("�������%d���ϵ����\n",js + 1);
            scanf("%f",&c);
            s->coef = c;
            r->next = s;
            r = s;
            printf("ֹͣ��������� 0 ��������������������������\n");
            scanf("%d",&dd);
            js++;
        }
        else if(js != 0 && e > laste){
            s = new PNode;
            s->expn = e;
            laste = e;
            printf("�������%d���ϵ����\n",js + 1);
            scanf("%f",&c);
            s->coef = c;
            r->next = s;
            r = s;
            printf("ֹͣ��������� 0 ��������������������������\n");
            scanf("%d",&dd);
            js++;
        }
        else{
            printf("��������δ�����������룬���������룺\n");
            goto pi;
        }
    }
    r->next = NULL;
    printf("�������\n");
    return P;
}

//�ϲ�����
void LNode_merge(LinkList &A,LinkList &B){
    LinkList C;
    InitLNode(C);
    LNode *p = A,*q = B,*r = C,*s;
    p = p->next;
    q = q->next;
    //��һ��Ϊ�ռ�ֹͣ
    while(p != NULL && q != NULL){
        s = new LNode;
        //��ʼ�Ա����ݴ�С
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
    //һ����Ϊ��
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
    printf("�ϲ����Ϊ��\n");
    PrintLNode(C);
}

//����ʽ�ϲ�
void PNode_merge(polynomial &A,polynomial &B){
    //A���Ƹ�C����B�е�Ԫ�����ӵ�C����
    //Ҫô���ӣ�Ҫôβ��
    polynomial C = A;
    PNode *p = B,*last = C;//lastָ������ָ��C��ĩβ������β��
    p = p->next;
    //last = last->next;
    //��last��ָ��ָ��Cĩβ
    while(last->next != NULL){
        last = last->next;
    }
    //��ѭ������ѭ��B������
    while(p != NULL){
        int choose = 0;//�����ж��Ƿ�β��
        //ÿ��ѭ��q����ָ��C��ͷ�ڵ�
        PNode *q = C,*s;
        q = q->next;
        //�ڲ�ѭ�����ڱ���C����������orβ��
        while(q != NULL){
            //���ҵ�����ͬ��ָ��,���Ӻ��˳���ѭ��
            if(p->expn == q->expn){
                q->coef = p->coef + q->coef;
                choose++;
                break;
            }
            q = q->next;
        }
        //������������֣�����β��
        if(choose == 0){
            s = new PNode;
            s->coef = p->coef;
            s->expn = p->expn;
            last->next = s;
            last = s;
            last->next = NULL;
        }
        //������һ��B�е�ֵ
        p = p->next;
    }
    printf("�ϲ����Ϊ��\n");
    PrintPNode(C);
}

//��ӡ���������
void PrintLNode(LinkList &L){
    L = L->next;
    while(L != NULL){
        printf("%d ",L->data);
        L = L->next;
    }
}

//��ӡ�������ʽ
void PrintPNode(polynomial &L){
    /*L = L->next;
    int jsq = 0;
    printf("ϵ��\tָ��\n");
    while(L != NULL){
        printf("%f\t%d\n",L->coef,L->expn);
        L = L->next;
    }*/

    L = L->next;
    int jsq = 0;
    //��һ��Ϊ����
    if(L->expn == 0){
        printf("%f ",L->coef);
        L = L->next;
        jsq++;
    }
    while(L != NULL){
        //��һ��ǳ�������������
        if(jsq == 0 && L->expn != 0){
            printf("%fx^%d",L->coef,L->expn);
            L = L->next;
            jsq++;
        }
        //ϵ��Ϊ����ʱ��
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