#ifndef CAL_LEN_HUFFMAN_H_INCLUDED
#define CAL_LEN_HUFFMAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

//使用同一个结构体貌似存在冲突，且C++不允许方法重写，只能创建多个结构体和同功能函数

//哈夫曼树的存储结构
typedef struct{
    int weight;  //结点的权重
    int parent, lchild, rchild;  //结点的双亲、左孩子、右孩子的下标
}Htnode,*Huffmantree;

//主函数
void cal_len_huffman_tree(Huffmantree &HT);
//创建哈夫曼树
void create_huffman_tree(Huffmantree &HT,int n);
//返回两个最小值
void Select(Huffmantree HT, int len, int &s1, int &s2);
//计算带权路径长度
void cal(Huffmantree HT,int n);

#endif // CAL_LEN_HUFFMAN_H_INCLUDED
