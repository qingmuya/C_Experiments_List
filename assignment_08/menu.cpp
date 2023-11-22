#include "menu.h"
#include "Function.h"

void menu(){
    printf("\t*****��ӭʹ�����¹���****\n");
    printf("\t0���˳�\n");
    printf("\t1������Ͳ���\n");
    printf("\t\t���򷽷�:\n");
    printf("\t\t\t(1��ֱ�Ӳ������򣨽���\n");
    printf("\t\t\t(2��ѡ����������\n");
    printf("\t\t\t(3���鲢��������\n");
    printf("\t\t\t(4���鲢���򣨽���\n");
    printf("\t\t\t(5������������\n");
    printf("\t\t\t(6�������򣨽���\n");
    printf("\t\t���ҷ���:\n");
    printf("\t\t\t(1��˳�����\n");
    printf("\t\t\t(2���۰����\n");
    printf("\t2���鼮����\n");
    printf("\t����ѡ��ǰ���ֵ��ù��ܣ�\n");
}

void Selectmenu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                exit(1);
            case 1:{
                int numOfdata,data[10],order[10];
                cout<<"����������Ԫ�صĸ�����"<<endl;
                //¼��������Ԫ�صĸ���
                cin>>numOfdata;
                //��������
                cout<<"���������ĸ���Ԫ�أ��Կո�����"<<endl;
                for(int i = 0;i < numOfdata;i++){
                    cin>>data[i];
                }
                //ѡ�����򷽷�
                //ǰ������������ѡ������Ĳ�ѯ�ķ���������������������ֹѡ���ѭ��
                int indexOfSort,quitOfSort = 0;

                cout<<"�������򷽷���"<<endl;
                while(true){
                    if(quitOfSort != 0){
                        break;
                    }
                    cin>>indexOfSort;
                    //����ΪTure������Ϊfalse
                    switch(indexOfSort){
                        case 1:{
                            //ֱ�Ӳ������򣨽���
                            int *new_data = Straight_Insertion_Sort(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,false);
                            break;
                        }
                        case 2:{
                            //ѡ����������
                            int *new_data = Select_Sort(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,true);
                            break;
                        }
                        case 3:{
                            //�鲢��������
                            int *new_data = Merge_Sort_up(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,true);
                            break;
                        }
                        case 4:{
                            //�鲢���򣨽���
                            int *new_data = Merge_Sort_down(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,false);
                            break;
                        }
                        case 5:{
                            //����������
                            int *new_data = Heap_Sort_up(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,true);
                            break;
                        }
                        case 6:{
                            //�����򣨽���
                            int *new_data = Heap_Sort_down(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,false);
                            break;
                        }
                        default:
                            cout<<"����Ƿ��ַ������¼��룺"<<endl;
                            break;
                    }
                }
                refresh();
                break;
            }
            case 2:{
                //�鼮����
                book somebook[10];
                int numOfbook;
                cout<<"�������������"<<endl;
                cin>>numOfbook;
                cout<<"���������͵��ۣ�"<<endl;
                for(int i = 0;i < numOfbook;i++){
                    cin>>somebook[i].name;
                    cin>>somebook[i].price;
                }
                book_sort(somebook,numOfbook);
                refresh();
                break;
            }
            default:
                cout<<"����Ƿ��ַ������¼��룺"<<endl;
                break;
        }
    }
}

//ѡ����ҷ�ʽ
void Search(int new_data[],int numOfdata,bool up_or_down){
    int indexOfQuery,quitOfQuery = 0;
    //ѡ���ѯ����
    cout<<"�����ѯ������"<<endl;
    while(true){
        if(quitOfQuery != 0){
            break;
        }
        cin>>indexOfQuery;
        switch(indexOfQuery){
            case 1:{
                //˳�����
                int index;
                cout<<"����Ҫ���ҵ�����"<<endl;
                cin>>index;
                int result = Sequential_Search(new_data,numOfdata,index);
                if(result == -1){
                    cout<<"Not Found"<<endl;
                }else{
                    cout<<"��������Ӧ����Ϊ��"<<result<<endl;
                }
                quitOfQuery++;
                break;
            }
            case 2:{
                //�۰����
                int index;
                cout<<"����Ҫ���ҵ�����"<<endl;
                cin>>index;
                int result = Half_interval_Search(new_data,numOfdata,index,up_or_down);
                if(result == -1){
                    cout<<"Not Found"<<endl;
                }else{
                    cout<<"��������Ӧ����Ϊ��"<<result<<endl;
                }
                quitOfQuery++;
                break;
            }
            default:
                cout<<"����Ƿ��ַ������¼��룺"<<endl;
                break;
        }
    }
}

//ˢ�º���
void refresh(){
    printf("\n");
    system("Pause");
    system("cls");
    menu();
}
