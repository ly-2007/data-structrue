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

//计算长度(带头结点)
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
//查找-按顺序查找，返回元素
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
//按值查找-返回地址
Lnode* LocateElem1(LinkList L,int num){
	if(!L) return NULL;
	Lnode *p = L->next;

	while(p && p->data.id != num){
		p = p->next;
	}

	return p;
}
/*C 语言底层巧妙设计：结构体的地址，等于其第一个成员的地址。
也就是，假设 LNode *p = 0x1000;（节点的起始地址），
那么&(p->data) 的内存地址也是 0x1000(因为 data 是第一个成员)*/
//按值查找-返回位序
int LocateElem2(LinkList L,int num){
	if(!L) return 0;
	/*如果 L 不为空，但 L->next 为空（即空表），代码也是安全的，
	因为 p = L->next 会得到 NULL，直接跳过 while 循环，
	最后返回 0。*/
	Lnode* p = L->next;
	int j=1;
	while(p && p->data.id != num){
		p = p->next;
		j++;
	}
	if(p) return j;
	return 0;
}
//按stu查找是否存在
bool ExistElem(LinkList L,Student goal){
	if(!L) return false;
	Lnode *p = L->next;

	while(p && p->data.id != goal.id){
		p = p->next;
	}
	return p != nullptr;
}
//在num之前插入结点
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
//删除第i个结点
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
	//p指向被删的前一个,d指向被删的
	Lnode *d = p->next;
	
	p->next = d->next;
	delete d;
	return 1;
}
// 建立链表
void Build(LinkList L,int num){
	L->next = NULL;
	for(int i = 0;i<num;i++){
//输入student
		Student a1;
		Lnode* p = (Lnode*)malloc(sizeof(Lnode));
		p->next = L->next;
		p->data = a1;
		L->next = p;
	}
}
//尾插法
void Bulid2(LinkList L,int num){
	Lnode* p;
	p = L;
	for(int i = 0;i<num;i++){
		Student a1;
		Lnode* a = (Lnode*)malloc(sizeof(Lnode));
		//cin>>(Student a1);
		//p是尾指针，指向最后一个元素
		a->data = a1;
		a->next = NULL ;
		p->next = a;
		p = a;
	}
}
//合并链表
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
int main(){


    return 0;
}
