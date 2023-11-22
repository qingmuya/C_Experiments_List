#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

//结构体
typedef struct book
{
    string name;
    double price;
};

//输出排序后的数组
void printArray(int M[],int numOfM);

//直接插入排序（降序）
int* Straight_Insertion_Sort(int M[],int numOfM);

//选择排序（升序）
int* Select_Sort(int M[],int numOfM);

//归并排序
int* Merge_Sort_up(int M[],int numOfM);
int* Merge_Sort_down(int M[],int numOfM);

//堆排序
int* Heap_Sort_up(int M[],int numOfM);
int* Heap_Sort_down(int M[],int numOfM);

//顺序查找
int Sequential_Search(int M[],int numOfM,int index);

//折半查找
int Half_interval_Search(int M[],int numOfM,int index,bool up_or_down);

//书籍排序
void book_sort(book somebook[],int numOfbook);
#endif // FUNCTION_H_INCLUDED
