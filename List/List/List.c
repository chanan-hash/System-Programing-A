#include "List.h"
#include <stdlib.h>
#include <stdio.h>

// Node & List Data Structures
typedef struct _node {
    double _data;
    struct _node * _next;
} Node;


struct _List {
    Node* _head;
    size_t _size;
};


//------------------------------------------------
// Node implementation
//------------------------------------------------

Node* Node_alloc(double data,
				 Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
	p->_data= data;
	p->_next= next;
	return p;
}

void Node_free(Node* node) {
	free(node);
}
//------------------------------------------------



//------------------------------------------------
// List implementation
//------------------------------------------------

List* List_alloc() {
	List* p= (List*)malloc(sizeof(List));
	p->_head= NULL;
	p->_size= 0;
	return p;
}

void List_free(List* list) {
	if (list==NULL) return;
	Node* p1= list->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		Node_free(p2);
	}
	free(list);
}

size_t List_size(const List* list) {
	return list->_size;
}

double List_firstData(const List* list) {
	return list->_head->_data;
}

void List_insertFirst(List* list,
					  double data) {
	list->_head= Node_alloc(data,list->_head);
	++(list->_size);
}

void List_print(const List* list) {
	const Node* p= list->_head;
	while(p) {
		printf("(%.2f)->",p->_data);
		p= p->_next;
	}
	printf("|| size:%zu\n",list->_size);
}

int List_equal(const List* list1, const List* list2) {
	const int eq= 0;
	const int neq= 1;
	
	const Node* p1= list1->_head;
	const Node* p2= list2->_head;
	while(p1) {
		if (p2==NULL||p1->_data!=p2->_data) return neq;
		p1= p1->_next;
		p2= p2->_next;
	}
	if (p2!=NULL) return neq;
	return eq;
}

List* List_clone(const List* list) {
	List* ret= List_alloc();
	const Node* old= list->_head;
	Node* * copy= &(ret->_head);
	ret->_size= list->_size;
	while(old) {
		*copy= Node_alloc(old->_data,NULL);
		old= old->_next;
		copy= &((*copy)->_next);
	}
	return ret;
}
//------------------------------------------------
