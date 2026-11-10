#include<iostream>
using namespace std;

typedef struct data {
	float coef;	//coefficient
	float exp;	//exponent
} data;

typedef struct Lnode {
	data a;
	struct Lnode* next;
} Lnode, *LinkList;

// add two polynomials represented as linked lists
Lnode* CreateNode(float coef, float exp) {
	Lnode* newNode = new Lnode;
	newNode->a.coef = coef;
	newNode->a.exp = exp;
	newNode->next = nullptr;
	return newNode;
}

// helper function: print the linked list (skip the head node)
void PrintList(LinkList L) {
	if (!L || !L->next) {
		cout << "List is empty or has only a head node" << endl;
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
	// Pretend that you already have two linked lists
	// create L1: 3x^2 + 4x^1
	L1->next = CreateNode(3, 2);
	L1->next->next = CreateNode(4, 1);

	// create L2: -3x^2 + 2x^1
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
	cout << "Your code's result for normal data:" << endl;
	PrintList(L3);
	return 0;
}
