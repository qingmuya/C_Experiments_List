#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

//�ṹ��
typedef struct book
{
    string name;
    double price;
};

//�������������
void printArray(int M[],int numOfM);

//ֱ�Ӳ������򣨽���
int* Straight_Insertion_Sort(int M[],int numOfM);

//ѡ����������
int* Select_Sort(int M[],int numOfM);

//�鲢����
int* Merge_Sort_up(int M[],int numOfM);
int* Merge_Sort_down(int M[],int numOfM);

//������
int* Heap_Sort_up(int M[],int numOfM);
int* Heap_Sort_down(int M[],int numOfM);

//˳�����
int Sequential_Search(int M[],int numOfM,int index);

//�۰����
int Half_interval_Search(int M[],int numOfM,int index,bool up_or_down);

//�鼮����
void book_sort(book somebook[],int numOfbook);
#endif // FUNCTION_H_INCLUDED
