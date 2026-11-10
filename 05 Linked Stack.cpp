//I will use C to practice my ability.
//LIFO Late In First Out---Stack
#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode{
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;

//initialization
bool InitStack(LinkStack &s){
	s = NULL;
	return true;
}

//Is the Stack Empty?
bool StackEmpty(LinkStack s){
	return s == NULL;
}

//Push
bool Push(LinkStack s,int e){
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if(p == NULL) return false;
	p->data = e;
	p->next = s;
	s = p;
	free(p);
	return true;
}

//Pop
bool Pop(LinkStack s){
	if(StackEmpty(s)) return false;
	
}
