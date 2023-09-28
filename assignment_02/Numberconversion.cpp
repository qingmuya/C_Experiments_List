#include "NumberConversion.h"
#include "ExpressionEvaluation.h"
#include "menu.h"
#include "partner.h"

void conversion(){
    int Num,Base;
    char sl[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    printf("可以循环进行数制转换，直到输入十进制数为-1结束！\n");
    while(1){
        printf("请输入十进制数：\n");
        scanf("%d",&Num);
        if(Num == -1){
            break;
        }
        printf("请输入转化数制：\n");
        scanf("%d",&Base);
        int a[20]; //存放余数
        int i=0;
        if(Base != 16){
            while(Num != 0){
                a[i++] = Num % Base;
                Num = Num / Base;
            }//当商不为0时进行循环
            printf("转换后的值为：\n");
            for(int x=i-1;x>=0;x--){
                printf("%d",a[x]);
            }
            printf("\n");
        }
        else if(Base == 16){
            int i = 0;
            char ch[20];
            while(Num != 0){
                int x = Num % Base;
                ch[i++] = sl[x];
                Num = Num / Base;
            }
            for(int j  = i - 1;j >= 0;j--){
                printf("%c",ch[j]);
            }
            printf("\n");
        }
    }
}
