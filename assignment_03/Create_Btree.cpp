#include "Create_Btree.h"
#include "Ctnon.h"
#include "Cxbl.h"
#include "Dgbl.h"
#include "Fdgzxbl.h"
#include "menu.h"

void create_Btree(BiTree &T){
    printf("ÊäÈë×Ö·û£º\n");
    char ch;
    cin>>ch;
    if(ch =='.'){
        T = NULL;
    }
    else{
        T = new BiTNode;
        T->data = ch;
        create_Btree(T->lchild);
        create_Btree(T->rchild);
    }
}

void print_Btree(BiTree &T){
    //printf("²âÊÔ-----\n");
    //printf("%c\n",T->data);
    if(T != NULL){
        printf("%c ",T->data);
        print_Btree(T->lchild);
        print_Btree(T->rchild);
    }
    else{
        printf(". ");
    }
}
