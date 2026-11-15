#include<iostream>
using namespace std;

//有头结点的版本(第一个结点不带数据)
typedef int QElemType;
//定义结点类型
typedef struct QNode{
    QElemType data;
    struct QNode* next;
}QNode,*QueuePtr;

//定义链队
typedef struct {
    QueuePtr front;//队头指针,数据域为空
    QueuePtr rear; //队尾指针
}LinkQueue;

//初始化
bool InitQueue(LinkQueue &Q){
    Q.front = Q.rear = new QNode;
    Q.front->next = nullptr;
     return true;
}

//销毁,从头开始
bool Destroy(LinkQueue &Q){
    QNode* p;
    while(Q.front){
        p = Q.front->next;
        delete Q.front;
        Q.front = p;  
    }
    delete Q.front;
    return true;
}

//入队
bool EnQueue(LinkQueue &Q,QElemType &e){
    QNode* p = new QNode;
    p->next = nullptr;
    p->data = e;
    Q.rear->next = p;
    Q.rear = p;
    return true;
}

//出队
bool DeQueue(LinkQueue &Q,QElemType &e){
    if(Q.rear == Q.front) return false;
    QNode* p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    delete p;
    if(Q.front->next == nullptr) Q.rear = Q.front;
    //此处if是考虑删掉仅剩的最后一个元素
    return true;
}

//获取队头元素
bool GetHead(LinkQueue Q,QElemType &e){
    if(Q.front == Q.rear) return false;
    e = Q.front->next->data;
    return true;
}

int main(){

    return 0;
}