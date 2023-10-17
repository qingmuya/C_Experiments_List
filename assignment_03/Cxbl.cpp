#include "Create_Btree.h"
#include "Ctnon.h"
#include "Cxbl.h"
#include "Dgbl.h"
#include "Fdgzxbl.h"
#include "menu.h"

void layer_order_traversal(){
    BiTNode *q= NULL;
    BiTree T;
    create_Btree(T);
    SqQueue* Q;
    Q = new Queue;

    Q->front=Q->rear=-1;

    if(T==NULL) return;
	Q->data[++Q->rear]=T;

	printf("层序遍历结果为：\n");
    while(Q->front!=Q->rear)
	{
		q=Q->data[++Q->front];
		printf("%c ",q->data);
        if (q->lchild != NULL)  Q->data[++Q->rear]=q->lchild;
        if (q->rchild != NULL)  Q->data[++Q->rear]=q->rchild;
	}
    printf("\n");
}
