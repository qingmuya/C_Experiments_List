#include "NumberConversion.h"
#include "ExpressionEvaluation.h"
#include "menu.h"
#include "partner.h"

#define MAXSIZE 1000  //队列大小

void menu(){
    printf("\t\t1、数值转换\n");
    printf("\t\t2、表达式求值\n");
    printf("\t\t3、解决舞伴问题\n");
    printf("\t\t0、退出程序\n");
    printf("\t\t请选择所需功能\n");
}

void select_menu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                exit(1);
            case 1:
                conversion();
                refresh();
                break;
            case 2:
                ExpressionEvaluation();
                refresh();
                break;
            case 3:
                Person man[MAXSIZE];//存储男舞伴的队列
                Person woman[MAXSIZE];//存储女舞伴的队列
                Point manPoint;//男舞伴队列的信息
                Point womanPoint;//女舞伴队列的信息

                manPoint.person=man;
                manPoint.front=0;
                manPoint.tail=0;
                womanPoint.person=woman;
                womanPoint.front=0;
                womanPoint.tail=0;

                int n;
                Person x;
                printf("请输入跳舞的总人数：");
                scanf("%d",&n);
                printf("请输入跳舞的人的姓名和性别('F'为男性，'M为女性')\n");
                //输入跳舞的人信息并对应入队
                for(int i=0;i<n;i++){
                    scanf("%s %c",x.name,&x.sex);
                    if(x.sex=='F'){
                        pushQueue(&manPoint,x);
                    }else if(x.sex=='M'){
                        pushQueue(&womanPoint,x);
                    }
                }
                Dance(manPoint,womanPoint);//分配舞伴
                refresh();
                break;
            default:
                printf("输入非法字符，重新键入：\n");
                refresh();
                break;
        }
    }
}

void refresh(){
    system("pause");
    system("cls");
    menu();
}
