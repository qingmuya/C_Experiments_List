#include "menu.h"
#include "Function.h"

void menu(){
    printf("\t*****欢迎使用以下功能****\n");
    printf("\t0：退出\n");
    printf("\t1：排序和查找\n");
    printf("\t\t排序方法:\n");
    printf("\t\t\t(1：直接插入排序（降序）\n");
    printf("\t\t\t(2：选择排序（升序）\n");
    printf("\t\t\t(3：归并排序（升序）\n");
    printf("\t\t\t(4：归并排序（降序）\n");
    printf("\t\t\t(5：堆排序（升序）\n");
    printf("\t\t\t(6：堆排序（降序）\n");
    printf("\t\t查找方法:\n");
    printf("\t\t\t(1：顺序查找\n");
    printf("\t\t\t(2：折半查找\n");
    printf("\t2：书籍排序\n");
    printf("\t键入选项前数字调用功能：\n");
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
                cout<<"键入数组中元素的个数："<<endl;
                //录入数组中元素的个数
                cin>>numOfdata;
                //创建数组
                cout<<"请键入数组的各个元素，以空格间隔："<<endl;
                for(int i = 0;i < numOfdata;i++){
                    cin>>data[i];
                }
                //选择排序方法
                //前两个变量用于选择排序的查询的方法，后两个变量用于终止选择的循环
                int indexOfSort,quitOfSort = 0;

                cout<<"键入排序方法："<<endl;
                while(true){
                    if(quitOfSort != 0){
                        break;
                    }
                    cin>>indexOfSort;
                    //升序为Ture，降序为false
                    switch(indexOfSort){
                        case 1:{
                            //直接插入排序（降序）
                            int *new_data = Straight_Insertion_Sort(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,false);
                            break;
                        }
                        case 2:{
                            //选择排序（升序）
                            int *new_data = Select_Sort(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,true);
                            break;
                        }
                        case 3:{
                            //归并排序（升序）
                            int *new_data = Merge_Sort_up(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,true);
                            break;
                        }
                        case 4:{
                            //归并排序（降序）
                            int *new_data = Merge_Sort_down(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,false);
                            break;
                        }
                        case 5:{
                            //堆排序（升序）
                            int *new_data = Heap_Sort_up(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,true);
                            break;
                        }
                        case 6:{
                            //堆排序（降序）
                            int *new_data = Heap_Sort_down(data,numOfdata);
                            printArray(new_data,numOfdata);
                            quitOfSort++;
                            Search(new_data,numOfdata,false);
                            break;
                        }
                        default:
                            cout<<"输入非法字符，重新键入："<<endl;
                            break;
                    }
                }
                refresh();
                break;
            }
            case 2:{
                //书籍排序
                book somebook[10];
                int numOfbook;
                cout<<"键入书的数量："<<endl;
                cin>>numOfbook;
                cout<<"键入书名和单价："<<endl;
                for(int i = 0;i < numOfbook;i++){
                    cin>>somebook[i].name;
                    cin>>somebook[i].price;
                }
                book_sort(somebook,numOfbook);
                refresh();
                break;
            }
            default:
                cout<<"输入非法字符，重新键入："<<endl;
                break;
        }
    }
}

//选择查找方式
void Search(int new_data[],int numOfdata,bool up_or_down){
    int indexOfQuery,quitOfQuery = 0;
    //选择查询方法
    cout<<"键入查询方法："<<endl;
    while(true){
        if(quitOfQuery != 0){
            break;
        }
        cin>>indexOfQuery;
        switch(indexOfQuery){
            case 1:{
                //顺序查找
                int index;
                cout<<"键入要查找的数："<<endl;
                cin>>index;
                int result = Sequential_Search(new_data,numOfdata,index);
                if(result == -1){
                    cout<<"Not Found"<<endl;
                }else{
                    cout<<"查找数对应索引为："<<result<<endl;
                }
                quitOfQuery++;
                break;
            }
            case 2:{
                //折半查找
                int index;
                cout<<"键入要查找的数："<<endl;
                cin>>index;
                int result = Half_interval_Search(new_data,numOfdata,index,up_or_down);
                if(result == -1){
                    cout<<"Not Found"<<endl;
                }else{
                    cout<<"查找数对应索引为："<<result<<endl;
                }
                quitOfQuery++;
                break;
            }
            default:
                cout<<"输入非法字符，重新键入："<<endl;
                break;
        }
    }
}

//刷新函数
void refresh(){
    printf("\n");
    system("Pause");
    system("cls");
    menu();
}
