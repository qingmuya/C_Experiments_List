#include "menu.h"
#include "Function.h"
#include "cmath"

using namespace std;

//输出排序后的数组
void printArray(int M[],int numOfM){
    cout<<"排序后为：";
    for(int i = 0;i < numOfM;i++){
        cout<<M[i]<<" ";
    }
    cout<<endl;
}

//直接插入排序（降序）
int* Straight_Insertion_Sort(int M[],int numOfM){
    //N数组用来存排序后的数组
    int N[numOfM],numOfN = 1;
    N[0] = M[0];
    for(int i = 1;i < numOfM;i++){
        int indexOfMin = 0;
        for(int j = 0;j < numOfN;j++){
            if(M[i] >= N[j]){
                //插入
                for(int x = numOfN;x > j;x--){
                    N[x] = N[x - 1];
                }
                N[j] = M[i];
                numOfN++;
                indexOfMin++;
                break;
            }
        }
        if(indexOfMin == 0){
            N[numOfN] = M[i];
            numOfN++;
        }
    }

    for(int i = 0;i < numOfM;i++){
        M[i] = N[i];
    }

    return M;
}

//选择排序（升序）
int* Select_Sort(int M[],int numOfM){
    /**
     * 每次抽取最小的数和起始索引换位置
     * 随后起始索引自增
     * 循环到最后完成排序
    */
    for(int i = 0;i < numOfM;i++){
        int minOfM = INT_MAX,minIndex;
        //找出最小值以及其索引
        for(int j = i;j < numOfM;j++){
            if(M[j] < minOfM){
                minOfM = M[j];
                minIndex = j;
            }
        }
        //最小值和起始索引换位置
        if(minOfM < M[i]){
            int index;
            index = M[i];
            M[i] = minOfM;
            M[minIndex] = index;
        }
    }
    return M;
}

//归并排序(升序)
int* Merge_Sort_up(int M[],int numOfM){
    /**
     * 迭代
     * 中断：内部比较出现索引越界则停止遍历，组内所有元素直接叠加即可
     * numOfG控制每次切割的大小
     * 外层循环控制切割大小，内层循环控制数组的整体切割
    */
    for(int numOfG = 1;numOfG < numOfM;numOfG *= 2){
        //N数组记录了刷新前的数组，且每次内层循环结束都会刷新
        int N[numOfM];
        for(int i = 0;i < numOfM;i++){
            N[i] = M[i];
        }
        //控制内部数组更新叠加索引
        int index = 0;
        for(int start1 = 0;start1 < numOfM;start1 += numOfG){
            int end1 = start1 + numOfG - 1,end2 = start1 + 2 * numOfG - 1,start2 = end1 + 1;
            //作为前半组不参与运算
            if(start2 >= numOfM){
                break;
            }
            //中断：只要start1或者start2任一索引越界则停止循环，转而直接叠加
            while(index <= end2){
                //判断是否中断
                if(start1 > end1){
                    while(start2 <= end2){
                        M[index] = N[start2];
                        start2++;
                        index++;
                    }
                    break;
                }
                if(start2 > end2 || start2 >= numOfM){
                    while(start1 <= end1){
                        M[index] = N[start1];
                        start1++;
                        index++;
                    }
                    break;
                }
                //归并排序：稳定排序
                if(N[start1] <= N[start2]){
                    M[index] = N[start1];
                    start1++;
                    index++;
                }else{
                    M[index] = N[start2];
                    start2++;
                    index++;
                }
            }
        }
    }

    return M;
}

//归并排序(降序)
int* Merge_Sort_down(int M[],int numOfM){
    /**
     * 迭代
     * 中断：内部比较出现索引越界则停止遍历，组内所有元素直接叠加即可
     * numOfG控制每次切割的大小
     * 外层循环控制切割大小，内层循环控制数组的整体切割
    */
    for(int numOfG = 1;numOfG < numOfM;numOfG *= 2){
        //N数组记录了刷新前的数组，且每次内层循环结束都会刷新
        int N[numOfM];
        for(int i = 0;i < numOfM;i++){
            N[i] = M[i];
        }
        //控制内部数组更新叠加索引
        int index = 0;
        for(int start1 = 0;start1 < numOfM;start1 += numOfG){
            int end1 = start1 + numOfG - 1,end2 = start1 + 2 * numOfG - 1,start2 = end1 + 1;
            //作为前半组不参与运算
            if(start2 >= numOfM){
                break;
            }
            //中断：只要start1或者start2任一索引越界则停止循环，转而直接叠加
            while(index <= end2){
                //判断是否中断
                if(start1 > end1){
                    while(start2 <= end2){
                        M[index] = N[start2];
                        start2++;
                        index++;
                    }
                    break;
                }
                if(start2 > end2 || start2 >= numOfM){
                    while(start1 <= end1){
                        M[index] = N[start1];
                        start1++;
                        index++;
                    }
                    break;
                }
                /**
                 * 归并排序：稳定排序
                 * 这里也决定了升序或降序
                */
                if(N[start1] >= N[start2]){
                    M[index] = N[start1];
                    start1++;
                    index++;
                }else{
                    M[index] = N[start2];
                    start2++;
                    index++;
                }
            }
        }
    }

    return M;
}

//堆排序（升序）
int* Heap_Sort_up(int M[],int numOfM){
    /**
     * 构建有序树的方法：以左子树为基址，需对比其索引+1以及索引/2
     * 做到空间复杂度为O(1)
     * 通过更新索引，控制已经排序后的元素不再参与排序
     * 树是无形的
    */

    //未排列元素全部存于树中，numOfT指代未排序元素个数，indexOfT为未排序元素的尾指针
    int numOfT = numOfM,indexOfT;
    //元素总数为奇数时，为完全二叉树，此时将numOfM - 1则指向最末尾元素
    //元素总数为偶数时，为不完全二叉树，numOfM - 1指向左孩子

    //每次刷新后都会更新为大顶堆
    for(;numOfT > 0;numOfT--){
        //该判断作用为让indexOfT永远指向最末尾的左孩子
        if(numOfT % 2 == 1){
            //奇数情况下
            indexOfT = numOfT - 2;
        }else if(numOfT % 2 == 0){
            //偶数情况下
            indexOfT = numOfT - 1;
        }

        //depth决定遍历次数
        int depth = 3;
        for(int time = 0;time < depth - 1;time++){
        //更新大顶堆，i用于锁定左孩子
            for(int i = indexOfT;i > 0;i -= 2){
                //比较三个数的大小，创建大顶堆
                //当右孩子已经参与过排序，则不比较右孩子
                if(i + 1 != numOfT){
                    if(M[i] >= M[i + 1] && M[i] >= M[i / 2]){
                        //IV：中间变量
                        int IV = M[i];
                        M[i] = M[i / 2];
                        M[i / 2] = IV;
                    }else if(M[i + 1] >= M[i] && M[i + 1] >= M[i / 2]){
                        int IV = M[i + 1];
                        M[i + 1] = M[i / 2];
                        M[i / 2] = IV;
                    }
                }else{
                    if(M[i] >= M[i / 2]){
                        int IV = M[i];
                        M[i] = M[i / 2];
                        M[i / 2] = IV;
                    }
                }
            }
        }

        //顶点和活动末尾交换位置
        int IV = M[numOfT - 1];
        M[numOfT - 1] = M[0];
        M[0] = IV;
    }

    return M;
}

//堆排序（降序）
int* Heap_Sort_down(int M[],int numOfM){
    int numOfT = numOfM,indexOfT;
    for(;numOfT > 0;numOfT--){
        if(numOfT % 2 == 1){
            indexOfT = numOfT - 2;
        }else if(numOfT % 2 == 0){
            indexOfT = numOfT - 1;
        }

        int depth = 3;
        for(int time = 0;time < depth - 1;time++){
            for(int i = indexOfT;i > 0;i -= 2){
                if(i + 1 != numOfT){
                    if(M[i] <= M[i + 1] && M[i] <= M[i / 2]){
                        int IV = M[i];
                        M[i] = M[i / 2];
                        M[i / 2] = IV;
                    }else if(M[i + 1] <= M[i] && M[i + 1] <= M[i / 2]){
                        int IV = M[i + 1];
                        M[i + 1] = M[i / 2];
                        M[i / 2] = IV;
                    }
                }else{
                    if(M[i] <= M[i / 2]){
                        int IV = M[i];
                        M[i] = M[i / 2];
                        M[i / 2] = IV;
                    }
                }
            }
        }

        int IV = M[numOfT - 1];
        M[numOfT - 1] = M[0];
        M[0] = IV;
    }

    return M;
}

//顺序查找
int Sequential_Search(int M[],int numOfM,int index){
    for(int i = 0;i < numOfM;i++){
        if(index == M[i]){
            return i;
        }
    }
    return -1;
}

//折半查找
int Half_interval_Search(int M[],int numOfM,int index,bool up_or_down){
    int low = 0,high = numOfM - 1,mid = (low + high) / 2;

    //数组为升序
    if(up_or_down){
        while(high >= low){
            mid = (low + high) / 2;
            if(M[mid] == index){
                return mid;
            }else{
                if(M[mid] > index){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
        }
    }else{
        while(high >= low){
            mid = (low + high) / 2;
            if(M[mid] == index){
                return mid;
            }else{
                if(M[mid] < index){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
        }
    }

    return -1;
}

//书籍排序
void book_sort(book somebook[],int numOfbook){
    for(int i = 0;i < numOfbook;i++){
        int minOfM = INT_MAX,minIndex;
        //找出最小值以及其索引
        for(int j = i;j < numOfbook;j++){
            if(somebook[j].price < minOfM){
                minOfM = somebook[j].price;
                minIndex = j;
            }
        }
        //最小值和起始索引换位置
        if(minOfM < somebook[i].price){
            book index;
            index.price = somebook[i].price;
            index.name = somebook[i].name;
            somebook[i].price = minOfM;
            somebook[i].name = somebook[minIndex].name;
            somebook[minIndex].price = index.price;
            somebook[minIndex].name = index.name;
        }
    }


    cout<<"排序后为："<<endl;
    for(int i = 0;i < numOfbook;i++){
        cout<<somebook[i].name<<"---";
        cout<<somebook[i].price<<endl;
    }
}
