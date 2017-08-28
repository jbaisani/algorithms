/*
 * Sublist Search(Search a linked list in another list)
 * Algorithm:
 * 1- Take first node of second list.
 * 2- Start matching the first list from this first node.
 * 3- If whole lists match return true.
 * 4- Else break and take first list to the first node again.
 * 5- And take second list to its second node.
 * 6- Repeat these steps until any of linked lists becomes empty.
 * 7- If first list becomes empty then list found else not.
 * */
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

Node *newNode(int key){
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void printList(Node *node){
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
}

bool findList(Node *first, Node *second){
	Node *ptr1 = first;
	Node *ptr2 = second;

	if(first == NULL && second == NULL)
		return true;

	if(first == NULL || (first != NULL && second == NULL))
		return false;
 while(second != NULL){
   ptr2 = second;

	 while(ptr1 != NULL){
		if(ptr2 == NULL)
			return false;
		else if(ptr1->data == ptr2->data){
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}else
			break;
	 }

	 if(ptr1 == NULL)
		 return true;

	 ptr1 = first;
	 second = second->next;
 }
 return false;
}

// Time Complexity : O(m*n) where m is the number of nodes in second list and n in first.
