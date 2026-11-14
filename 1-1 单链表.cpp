#include<stdio.h>
#include<stdlib.h>

typedef struct Student{
	int id;
	char name[8];
	float score;
}ElemType;


typedef struct Lnode{
	ElemType data;
	struct Lnode* next;
}Lnode,*LinkList;

//get the length of the linked list
int GetLength(LinkList a){
	int len = 0;
	if(!a || a->next == nullptr){
		return 0;
	}else{
		a = a->next;
		while(a){
			len++;
			a = a->next;
		}
	}
	return len;
}
//get the num-th element of the linked list, and return it through stu
bool GetElem(LinkList L,int num,Student* stu){
	if(num < 1 || !L || stu == nullptr) return false;
	Lnode* p = L->next;
	for(int i = 1;i<num && p != nullptr;i++){
		p = p->next;
	}
	if(!p) return false;
	*stu = p->data;
	return true;
}
//locate an element by its value and return its address
Lnode* LocateElem1(LinkList L,int num){
	if(!L) return NULL;
	Lnode *p = L->next;

	while(p && p->data.id != num){
		p = p->next;
	}

	return p;
}
//locate an element by its value and return its position
int LocateElem2(LinkList L,int num){
	if(!L) return 0;
	Lnode* p = L->next;
	int j=1;
	while(p && p->data.id != num){
		p = p->next;
		j++;
	}
	if(p) return j;
	return 0;
}
//check if an element exists in the linked list
bool ExistElem(LinkList L,Student goal){
	if(!L) return false;
	Lnode *p = L->next;

	while(p && p->data.id != goal.id){
		p = p->next;
	}
	return p != nullptr;
}
//insert an element into the linked list
bool insert(LinkList L,int num,Lnode &G){
	if(!L || num < 1) return false;
	int j = 1;
	Lnode* p = L;
	while(j<num && p){
		p = p->next;
		j++;
	}
	G.next = p->next;
	p->next = &G;
	return 1;
}
//delete the num-th element of the linked list
bool Delete(LinkList &L,int i){
	if(!L || i<1) return 0;
	int j = 1;
	Lnode *p = L;
	while(j<i && p){
		p=p->next;
		j++;
	}
	if(!p || p->next == NULL) {
		return false;
	}
	Lnode *d = p->next;
	
	p->next = d->next;
	delete d;
	return 1;
}
//build a linked list by head insertion
void Build(LinkList L,int num){
	L->next = NULL;
	for(int i = 0;i<num;i++){
		Student a1;
		Lnode* p = (Lnode*)malloc(sizeof(Lnode));
		p->next = L->next;
		p->data = a1;
		L->next = p;
	}
}
//build a linked list by tail insertion
void Bulid2(LinkList L,int num){
	Lnode* p;
	p = L;
	for(int i = 0;i<num;i++){
		Student a1;
		Lnode* a = (Lnode*)malloc(sizeof(Lnode));
		//cin>>(Student a1);
		a->data = a1;
		a->next = NULL ;
		p->next = a;
		p = a;
	}
}
//merge two linked lists into a new linked list
void Union(LinkList L1,LinkList L2,LinkList L3){
	Lnode* p1 = L1->next;
	Lnode* p2 = L2->next;

	Lnode* p3 = L1;
	L3 = L1;
	while(p1 && p2){
		if(p1->data.id < p2->data.id){
			p3->next = p1;
			p1 = p1->next;
		}else{
			p3->next = p2;
			p2 = p2->next;
		}
		p3 = p3->next;
	}
	
	p3->next = (!p1 ? p2:p1);
	delete L2;
}
//just a test
int main(){


    return 0;
}
