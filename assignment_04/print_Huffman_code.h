#ifndef PRINT_HUFFMAN_CODE_H_INCLUDED
#define PRINT_HUFFMAN_CODE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

//使用同一个结构体貌似存在冲突，且C++不允许方法重写，只能创建多个结构体和同功能函数

//哈夫曼树的存储结构
typedef struct{
    char data;
    int weight;  //结点的权重
    string code;
    int parent, lchild, rchild;  //结点的双亲、左孩子、右孩子的下标
}HTnode,*HuffTree;
//哈夫曼编码结构体
typedef char **HuffmanCode;
//主函数
void print_huffman_code(HuffTree &HT);
//根据哈夫曼树计算哈夫曼编码
void CreateHuffmanCode(HuffTree HT,HuffmanCode &HC,int n);
//创建哈夫曼树
void create_huffmantree(HuffTree &HT,int n);
//返回两个最小值
void Select(HuffTree HT, int len, int &s1, int &s2);

#endif // PRINT_HUFFMAN_CODE_H_INCLUDED
