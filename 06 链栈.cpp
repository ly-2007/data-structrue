//LIFO Late In First Out---Stack  后进先出
//对于异常处理我还不熟练，所以有多处使用exit(0)；
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
/*好神奇啊，一开始输出的是乱码，后来加上#include<windows.h>和SetConsoleOutputCP(65001);
就好了，具体我写在笔记里了*/

typedef int ElemType;

typedef struct StackNode{
	ElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;

//initialization初始化
bool InitStack(LinkStack &s){
	s = NULL;
	return true;
}

//Is the Stack Empty?
bool StackEmpty(const LinkStack &s){
	return s == NULL;
}

//Push 头插
bool Push(LinkStack &s,ElemType e){
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if(p == NULL) return false;
	p->data = e;
	p->next = s;
	s = p;
	return true;
}

//Pop 出栈，注意下，如果返回的是局部变量，不可以在函数名的返回值上加&，否则出现悬空引用（野指针）
/*ElemType Pop(LinkStack &s){
	if(s == NULL) exit(0);
	ElemType e = s->data;
	StackNode* p = s;
	s = s->next;
	free(p);
	return e;
} 这种情况弃用，因为异常处理不是很熟练*/

bool Pop(LinkStack &s,ElemType &e){
	if(s == NULL) return false;
	e = s->data;
	StackNode* p = s;
	s = s->next;
	free(p);
	return true;
}

//获取栈顶元素
bool GetTop(const LinkStack& s,ElemType &e){
	if(s != NULL) {
		e = s->data;
		return true;
	}
	return false;
}
//test
int main() {
	SetConsoleOutputCP(65001); // 把控制台编码设置为 UTF-8
    LinkStack s;
    InitStack(s);

    ElemType val;

    // 测试压栈
    Push(s, 10);
    Push(s, 20);
    Push(s, 30);

    // 测试获取栈顶
    if (GetTop(s, val)) {
        printf("栈顶元素: %d\n", val); // 应该输出 30
    }

    // 测试出栈
    while (Pop(s, val)) {
        printf("弹出: %d\n", val); // 依次输出 30, 20, 10
    }

    return 0;
}
