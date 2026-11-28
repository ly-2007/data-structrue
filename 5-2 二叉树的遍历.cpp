#include <iostream>
#include <stack>
using namespace std;

#define TElemType int

typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild, *rchild; // 左右孩子指针
} BiNode, *BiTree;                  // 同时定义了tree的头指针

// 访问结点-->依需求而定
bool visit(BiNode *a)
{
    cout << a->data << ' ';
}

// 时间复杂度均为O(n)
// 先序遍历(根左右)，BiTree一开始指向根结点
bool PreOrderTraverse(BiTree T)
{
    if (T == nullptr)
        return true;
    else
    {
        visit(T);                    // d
        PreOrderTraverse(T->lchild); // l
        PreOrderTraverse(T->rchild); // r
    }
}
// 中序遍历
bool InOrderTraverse(BiTree T)
{
    if (T == nullptr)
        return true;
    else
    {
        InOrderTraverse(T->lchild);
        visit(T);
        InOrderTraverse(T->rchild);
    }
}
// 后序遍历
bool PostOrderTraverse(BiTree T)
{
    if (T == nullptr)
        return true;
    else
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T);
    }
}

// 非递归遍历 中序，左根右

//这个stack 的 push和pop需要自己定义
bool InOrderTraverse(BiTree T)
{   
    BiTree p = T;
    stack<BiNode> a;
    while (p || !a.empty())
    {
        if(p) {
            a.push(T);
            p = p->lchild;
        }else{
            BiNode q = a.pop();
            p = q->rchild;
        }
    }

    return true;
}