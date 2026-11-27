#include<iostream>
using namespace std;

#define TElemType int

typedef struct BiNode{
    TElemType data;
    struct BiNode *lchild,*rchild;//左右孩子指针
}BiNode,*BiTree;//同时定义了tree的头指针

