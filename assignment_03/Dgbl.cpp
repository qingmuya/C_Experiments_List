#include "Create_Btree.h"
#include "Ctnon.h"
#include "Cxbl.h"
#include "Dgbl.h"
#include "Fdgzxbl.h"
#include "menu.h"

void recursive_traversal(BiTree &T){
    //先序遍历
    printf("先序遍历结果为：");
    Traverse_first(T);
    printf("\n");

    //中序遍历
    printf("中序遍历结果为：");
    Mid_order_traversal(T);
    printf("\n");

    //后序遍历
    printf("后序遍历结果为：");
    Post_order_traversal(T);
    printf("\n");
}

void Traverse_first(BiTree &T){
    if(T != NULL){
        printf("%c ",T->data);
        Traverse_first(T->lchild);
        Traverse_first(T->rchild);
    }
}

void Mid_order_traversal(BiTree &T){
    if(T != NULL){
        Mid_order_traversal(T->lchild);
        printf("%c ",T->data);
        Mid_order_traversal(T->rchild);
    }
}

void Post_order_traversal(BiTree &T){
    if(T != NULL){
        Post_order_traversal(T->lchild);
        Post_order_traversal(T->rchild);
        printf("%c ",T->data);
    }
}
