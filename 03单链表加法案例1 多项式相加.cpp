#include<iostream>
using namespace std;

typedef struct data {
	float coef;	//系数，coefficient
	float exp;	//指数，exponent
} data;

typedef struct Lnode {
	data a;
	struct Lnode* next;
} Lnode, *LinkList;

// 辅助函数：建一个节点
Lnode* CreateNode(float coef, float exp) {
	Lnode* newNode = new Lnode;
	newNode->a.coef = coef;
	newNode->a.exp = exp;
	newNode->next = nullptr;
	return newNode;
}

// 辅助函数：打印链表（跳过头结点）
void PrintList(LinkList L) {
	if (!L || !L->next) {
		cout << "链表为空或只有头结点" << endl;
		return;
	}
	Lnode* p = L->next;
	while (p) {
		cout << p->a.coef << "x^" << p->a.exp;
		if (p->next) cout << " + ";
		p = p->next;
	}
	cout << endl;
}

int main() {
	LinkList L1;
	LinkList L2;
	LinkList L3;
	L1 = new Lnode;
	L2 = new Lnode;
	//假装已经有了两个链表
	// 建表 L1: 3x^2 + 4x^1
	L1->next = CreateNode(3, 2);
	L1->next->next = CreateNode(4, 1);

	// 建表 L2: -3x^2 + 2x^1
	L2->next = CreateNode(-3, 2);
	L2->next->next = CreateNode(2, 1);


	L3 = L1;
	Lnode* p1 = L1->next;
	Lnode* p2 = L2->next;
	Lnode* p3 = L3;
	p3->next = nullptr;
	while (p1 && p2) {
		if (p1->a.exp == p2->a.exp) {
			if (p1->a.coef + p2->a.coef != 0) {
				p1->a.coef += p2->a.coef;
				p3->next = p1;
				p3 = p3->next;
			}
			p1 = p1->next;
			p2 = p2->next;
		} else {
			if (p1->a.exp < p2->a.exp) {
				p3->next = p1;
				p1 = p1->next;
			} else {
				p3->next = p2;
				p2 = p2->next;
			}
			p3 = p3->next;
		}

	}
	p3->next = (!p1 ? p2 : p1);
	cout << "你的代码处理正常数据的结果：" << endl;
	PrintList(L3);
	return 0;
}
