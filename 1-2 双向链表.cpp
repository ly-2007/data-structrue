#include<iostream>
#include<string>
using namespace std;

typedef struct DuNode{
	string data;
	struct DuNode *prior,*next;
}DuNode,*DuLinkList;

void Bulid (DuLinkList L,int num){
	L->prior = nullptr; //L is the head node, its prior pointer is null
	DuNode* p = L;
	for(int i = 0;i<num;i++){
		string a;
		cin>>a;
		DuNode* f = new DuNode;
		p->next = f;
		f->data = a;
		f->prior = p;
		f->next = nullptr;
		p = f;
  /*
		if(i == num-1){
		   f->next = L;
		   L->prior = f;
		}*/
	}
}
//insert an element into the linked list
void Insert(DuLinkList L,int num,DuNode &a){
	DuNode* p = L; //point to the head node
	for(int i = 1;i<num;i++){
		p = p->next;
	}
	a.next = p->next;
	a.prior = p;
	p->next->prior = &a;
	p->next = &a;
}
//delete the num-th element of the linked list
void Delete(DuLinkList L,int num){
	DuNode* p = L;
	for(int i=1;i<num;i++){
		p = p->next;
	}
	DuNode* s = p->next;//s point to the node to be deleted
	s->next->prior = p;
	s->prior->next = s->next;
	delete s;
}


//just a test
int main() {
	
	
	return 0;
}
