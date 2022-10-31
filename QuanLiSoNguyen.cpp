#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;

struct Node {
	int data;
	Node *pNext;
};

struct List {
	Node *pHead;
	Node *pTail;
};
/*Prototype*/
Node *getNode(int x);
void Init(List &L);
void AddHead(List &l, Node* new_node);
void InsertFirst(List &l, int x);
void addTail(List &L, Node *new_node);
void InsertLast(List &L, int x);
void AddAfter(List &L, Node *q, Node* new_node);
void processList (List L);
void Output (List L);
Node *Search (List  L, int  x);
int removeHead (List &L);
int removeAfter (List &L, Node *q );
int removeNode(List & L, int k);
void RemoveList (List &L);
int CountNodes (List L);
Node *PickHead (List &L);
/*End prototype*/

int main() {
	List listInt;
	Init(listInt);
	
	int choice;
	int x;
	
	do {
		printf("\n1. Them vao dau danh sach so nguyen");
		printf("\n2. Them vao cuoi danh sach so nguyen");
		printf("\n3. Xuat danh sach");
		printf("\n4. Bo phan tu dau cua danh sach");
		printf("\n5. Bo phan tu co gia tri k");
		printf("\n6. Xoa toan bo danh sach");
		printf("\n7. Dem so nut");
		printf("\n0. Thoat");
		printf("\nLua chon: ");
		
		scanf("%d", &choice);
		system("cls");
		
		switch(choice) {
			case 1:
				printf("\nNhap so nguyen = ");
				scanf("%d", &x);
				InsertFirst(listInt, x);
				break;
			case 2:
				printf("\nNhap so nguyen = ");
				scanf("%d", &x);
				InsertLast(listInt, x);
				break;
			case 3:
				Output(listInt);
				break;
			case 4:
				removeHead(listInt);
				break;
			case 5:
				printf("\nNhap so nguyen = ");
				scanf("%d", &x);
				removeNode(listInt, x);
				break;
			case 6:
				RemoveList(listInt);
				break;
			case 7:
				printf("So nut = %d\n", CountNodes(listInt));
		}
		
	} while (choice);
	
	
	return 0;
}
Node* PickHead (List &L) {
	Node *p = NULL;
	if (L.pHead != NULL) {
		p = L.pHead;
		L.pHead = L.pHead->pNext;
		p->pNext = NULL;
		if (L.pHead == NULL)  L.pTail =  NULL;
	}
	return p;
}
int CountNodes (List L) {
	int count = 0;
	Node *p = L.pHead;
	while (p!=NULL) {
		count++;
		p = p->pNext;
	}
	return count;
}
void RemoveList (List &L) {
	Node *p;
	while (L.pHead != NULL) {
		p = L.pHead;
		L.pHead = p->pNext;
	   delete p;
	}
	L.pTail = NULL;
}
int removeNode(List & L, int k) {
    Node * p = L.pHead;
    Node * q = NULL;
    while (p != NULL) {
        if (p -> data == k) break;
        q = p;
        p = p -> pNext;
    }
    if (p == NULL) {
        cout << "Không tìm th?y k";
        return 0;
    } else if (q != NULL) {
        if (p == L.pTail) L.pTail = q;
        q -> pNext = p -> pNext;
        delete p;
    } else //p là ph?n t? d?u xâu 
    {
        L.pHead = p -> pNext;
        if (L.pHead == NULL) L.pTail = NULL; //ds có 1ph?n t?
    }
    return 1;
}
int removeAfter (List &L, Node *q ) {
	if (q !=NULL && q->pNext !=NULL)
	{
		Node*   p = q->pNext;
		q->pNext = p->pNext;
		if  (p == L.pTail)	 L.pTail = q;
		delete p;
		return 1;
	}
	else return 0;
}
int removeHead (List &L) {
	if (L.pHead == NULL) return 0;
	Node* p = L.pHead;
	L.pHead = p->pNext;
	if (L.pHead == NULL)  L.pTail = NULL; //N?u danh sách sau khi xóa là r?ng
	delete p;
	return 1;
}
Node* Search (List  L, int  x) {
	Node* p = L.pHead;
	while (p!=NULL) {
		if (p->data == x)	return p;
		p = p->pNext;
	}
	return NULL; 
}
void Output(List L) {
	Node* p = L.pHead;
	while (p!=NULL)
	{
		cout<<p->data<<"\t";
		p = p ->pNext;
	}
	cout<<endl;
}
Node *InsertAfter(List &L, Node *q, int x) {
		Node* p = getNode(x);
		AddAfter(L, q, p);
}
void processList (List L) {
     	Node *p = L.pHead;
     	while (p!= NULL) {
			// x? lý c? th? p tùy ?ng d?ng
     		p = p->pNext;
     	}
}
void AddAfter (List &L, Node *q, Node* new_node) {
	if (q!=NULL)
	{
		new_node->pNext = q->pNext;
		q->pNext = new_node;
		if(q == L.pTail)  	L.pTail = new_node;
	}
}

void InsertLast(List &L, int x) {
	Node* new_node = getNode(x);
	if (new_node == NULL)
		return;
	addTail(L, new_node);
}

void addTail(List &L, Node *new_node) {
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = new_node;
	}
	else
	{
		L.pTail->pNext = new_node;
		L.pTail = new_node ;
	}
}


void InsertFirst(List &L, int x) {
	//Nh?n vào giá tr? nguyên x -> Node -> thêm vào d?u ds
	Node* new_node = getNode(x);
	if (new_node == NULL)
		return;
	AddHead(L, new_node);
}

void AddHead(List &L, Node* new_node) {
	if (L.pHead == NULL)  // DS r?ng
	{
		L.pHead = L.pTail = new_node;
	}
	else
	{
		new_node->pNext = L.pHead;
		L.pHead = new_node;
	}
}

void Init(List &L) {
	L.pHead = L.pTail = NULL; //Khoi tao danh sach rong
}

Node *getNode(int x) {
	Node *p;
	p = new Node; //Cap phat vung nho
	if(p==NULL) {
		printf("\nKhong du bo nho!");
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	
	return p;
}

