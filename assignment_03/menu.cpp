#include "Create_Btree.h"
#include "Ctnon.h"
#include "Cxbl.h"
#include "Dgbl.h"
#include "Fdgzxbl.h"
#include "menu.h"

void menu(){
    printf("--------���빦��ǰ����ʹ�ù���--------\n");
    printf("\t0���˳�����\n");
    printf("\t1������������\n");
    printf("\t2������������\n");
    printf("\t\t1���ݹ�����������������������������򡢺������\n");
    printf("\t\t2���ǵݹ��������\n");
    printf("\t\t3���������\n");
    printf("\t3���������Ҷ�ӽ��ĸ���\n");
    printf("��������ѡ���ܣ�\n");
}

void select_menu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            //�˳�����
            case 0:
                exit(1);
            //����������
            case 1:
                BiTree T;
                create_Btree(T);
                printf("�����������ɹ���\n");
                printf("�������������Ϊ��");
                print_Btree(T);
                printf("\n");
                refresh();
                break;
            //����������
            case 2:{
                int jc = 0;//����ã����鿴�����Ƿ�ִ��
                printf("�ٴμ����Ӳ˵�ǰ����ѡ����ع��ܣ�\n");
                while(jc == 0){
                    int xz_r;
                    scanf("%d",&xz_r);
                    switch(xz_r){
                        case 1:
                            BiTree T;
                            printf("������������\n");
                            create_Btree(T);
                            recursive_traversal(T);//�ݹ����
                            jc++;
                            break;
                        case 2:
                            non_recursive_mid_order_traversal();//�ǵݹ��������
                            jc++;
                            break;
                        case 3:
                            layer_order_traversal();//�������
                            jc++;
                            break;
                        default:
                            printf("����Ƿ��ַ������¼��룺\n");
                            break;
                    }
                }
                refresh();
                break;
            }
            //�������Ҷ�ӽڵ�ĸ���
            case 3:
                count_the_number_of_nodes();
                refresh();
                break;
            default:
                printf("����Ƿ��ַ������¼��룺\n");
                break;
        }
    }
}

void refresh(){
    system("pause");
    system("cls");
    menu();
}
