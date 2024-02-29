#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // Data field. The data type is free.
	struct Node* link; // Link field. Connect to next node.
} Node;

void add_first(Node* list, int value);
void add_last(Node* list, int value);
void remove_first(Node* list);
void remove_last(Node* list);
void remove_item(Node* list, int value);
void reverse(Node* list);
void print_list(Node* list);

Node* Head = NULL; // Startup default (empty head)
char remove_value = 'NULL'; // Startup default

void main(void) {
	Node* list = NULL;
	list = Head;

	add_first(list, 20); // 20
	print_list(list);

	add_last(list, 30); // 20-30
	print_list(list);

	add_last(list, 40); // 20-30-40
	print_list(list);

	add_first(list, 10); // 10-20-30-40
	print_list(list);

	add_last(list, 50); // 10-20-30-40-50
	print_list(list);

	reverse(list); // 50-40-30-20-10
	print_list(list);

	remove_first(list); // 40-30-20-10
	print_list(list);

	remove_item(list, 20); // 40-30-10
	print_list(list);

	remove_item(list, 30); // 40-10
	print_list(list);

	reverse(list); // 10-40
	print_list(list);
}

void add_first(Node* list, int value) {
	Node* newnode;
	newnode = (Node*)malloc(sizeof(Node));
	newnode->data = value;

	if (Head == NULL) { // If Head is NULL value.
		newnode->link = NULL;
		Head = newnode;
	}
	else {
		newnode->link = Head;
		Head = newnode;
	}
}

void add_last(Node* list, int value) {
	Node* newnode, * temp;
	newnode = (Node*)malloc(sizeof(Node));
	newnode->data = value;
	newnode->link = NULL;
	temp = Head;

	while (temp->link != NULL) { // Temp move to last
		temp = temp->link;
	}

	temp->link = newnode;
}

void remove_first(Node* list) {
	Node* target = NULL;

	if (Head == NULL) {
		printf("List is empty\n");
	}
	else {
		target = Head;
		remove_value = target->data;
		Head = target->link;
	}

	free(target);
}

void remove_last(Node* list) {
	Node* target, * previous;
	previous = Head;
	target = Head->link;

	if (target == NULL) {
		remove_value = previous->data;
		Head = NULL;
		return;
	}

	while (target->link != NULL) {
		previous = target;
		target = target->link;
	}

	remove_value = target->data;
	previous->link = NULL;

	free(target);
}

void remove_item(Node* list, int value) {
	Node* pt1, * pt2, * item;
	pt1 = Head;
	pt2 = pt1->link;
	item = pt1;

	if (item->data == value) {
		Head = pt1->link;
	}
	else {
		while (pt2 != NULL) {
			if (pt2->data == value) {
				item = pt2;
				pt1->link = pt2->link;
			}
			pt1 = pt2;
			pt2 = pt2->link;
		}
	}

	remove_value = item->data;

	free(item);
}

void reverse(Node* list) {
	Node* pt1, * pt2, * pt3;
	pt1 = Head;
	pt2 = NULL;
	pt3 = NULL;

	while (pt1 != NULL) {
		pt3 = pt2;
		pt2 = pt1;
		pt1 = pt1->link;
		pt2->link = pt3;
	}

	Head = pt2;
}

void print_list(Node* list) {
	printf(" Linked List :");

	list = Head;

	while (list != NULL) {
		printf(" %d ", list->data);
		list = list->link;
	}

	printf("\n");
}
