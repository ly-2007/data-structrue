#include<iostream>
#include<string>
using namespace std;

typedef struct DuNode{
	string data;
	struct DuNode *prior,*next;
}DuNode,*DuLinkList;

void Bulid (DuLinkList L,int num){
	L->prior = nullptr; //L是头指针
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
  /*双向循环链表：
		if(i == num-1){
		   f->next = L;
		   L->prior = f;
		}*/
	}
}
//插入
void Insert(DuLinkList L,int num,DuNode &a){
	DuNode* p = L; //指向前一个
	for(int i = 1;i<num;i++){
		p = p->next;
	}
	a.next = p->next;
	a.prior = p;
	p->next->prior = &a;
	p->next = &a;
}
//删除
void Delete(DuLinkList L,int num){
	DuNode* p = L;
	for(int i=1;i<num;i++){
		p = p->next;
	}
	DuNode* s = p->next;//s指向被删除的
	s->next->prior = p;
	s->prior->next = s->next;
	delete s;
}



int main() {
	
	
	return 0;
}
