#include<iostream>
using namespace std;

//顺序存储 Binary Tree
#define MAXTSIZE 100
typedef int TElemType;
typedef TElemType SqBiTree[MAXTSIZE];
SqBiTree bt;
/*其中，没有的元素可以用0/-1占位，此外，建议从1开始，因为二叉树的编号是从1开始的*/
//由于空结点会导致空间的浪费，该存储结构适合存完全二叉树

//链式存储
typedef struct BiNode{
    TElemType data;
    struct BiNode *lchild,*rchild;//左右孩子指针
}BiNode,*BiTree;//同时定义了tree的头指针

//链式存储+三叉链表（实现查找双亲的功能）
typedef struct TriTNode{
    TElemType data;
    struct TriTNode *lchild,*rchild,*parent;
}TriTNode,*TriTree;
