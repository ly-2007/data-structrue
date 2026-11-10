#include<iostream>
using namespace std;

typedef struct Book {
	string id;
	string name;
	float price;
} Book;

typedef struct Lnode {
	Book data;
	struct Lnode* next;
} Lnode, *LinkList;

bool operator ==(const Book &a, const Book &b) {
	if (a.id == b.id) {
		return 1;
	}
	return 0;
}
bool operator !=(const Book &a, const Book &b) {
	if (a.id == b.id) {
		return 0;
	}
	return 1;
}
void mshow(const Book &a) {
	cout << "id: " << a.id << "   name: " << a.name
	     << "   price: " << a.price << endl;
}

//add a book to the linked list
bool Add(LinkList L, const Book &b) {
	if (!L) {
		cout << "Something is wrong." << endl;
		return 0;
	}
	Lnode* n = new Lnode;
	n->data = b;
	n->next = nullptr;
	Lnode* p = L;
	while (p->next) {
		p = p->next;
	}
	p->next = n;
	cout << "Success." << endl;
	return 1;
}
//delete a book from the linked list
bool Delete(LinkList L, const Book &a) {
	if (!L || !L->next) {
		cout << "Something is wrong." << endl;
		return 0;
	}
	Lnode* p = L;
	while (p->next != nullptr && p->next->data != a) {
		p = p->next;
	}
	if (p->next == nullptr) {
		cout << "We can't find this book." << endl;
		return 0;
	}
	Lnode* b = p->next;
	p->next = b->next;
	delete b;
	cout << "Success." << endl;
	return 1;
}
//search a book in the linked list
bool Search(LinkList L, const Book &b) {
	if (!L || !L->next) {
		cout << "Something is Wrong." << endl;
		return 0;
	}
	Lnode* p = L->next;
	while (p) {
		if (p->data == b) {
			cout << "Yes,we find it." << endl;
			mshow(p->data);
			return 1;
		}
		p = p->next;
	}
	cout << "We can't find it." << endl;
	return 0;
}
//just a test
int main() {



	return 0;
}
