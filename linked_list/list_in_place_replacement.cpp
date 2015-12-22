#include <iostream>
using namespace std;
/*author: Nitesh Thali

Question: GeeksForGeeks
Rearrange a given linked list in-place.
Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …
You are required do this in-place without altering the nodes’ values.

Examples:
Input:  1 -> 2 -> 3 -> 4
Output: 1 -> 4 -> 2 -> 3

Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3 
O(n2) solutopn would be to traverse everytime to the end of list to get the node and link it to the previous item.
O(n) solution is to reverse the othe second half of linked list and then merge it as required.
*/

struct node
{
	int data;
	struct node * next;
}*head=NULL;

node* getNode(int data)
{
	node *tmp = new node();
	tmp->data= data;
	tmp->next =NULL;
	return tmp;
}
void insert_front(int data)
{
	if (head == NULL)
		head = getNode(data);
	else
	{
		node *tmp = getNode(data);
		tmp->next = head;
		head = tmp;
	}
}
node* reverse_list(node * mid)
{
	node *prev = NULL, *curr = mid, *nxt;
	if (head == NULL)
		return NULL;
	while(curr->next != NULL)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	curr->next = prev;
	mid = curr;
	return mid;
}
node* fimd_mid_point()
{
	node *fast=head, *slow= head, *prev;
	while(fast != NULL && fast->next != NULL) // to find mid point of a linked list
	{
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}
	if (prev)
		prev->next = NULL;
	return slow;  // if slow == NULL then list is empty.

}
void display(node *start)
{
	node *tmp = start;
	cout << "Linked List";
	while(tmp)
	{
		cout <<"->" << tmp->data;
		tmp = tmp->next;
	}
	cout << endl;
}
void inorder_combine(node *m1, node *m2)
{
	//Merge two lists alternatively
	node *t1,*t2, *prev;
	head = m1;
	while( m1 && m2 )
	{
		t1 = m1->next;
		t2 = m2->next;
		m1->next = m2;
		m2->next = t1;
		prev = m2;
		m1 = t1;
		m2 = t2;
	}
	if (m2)
	{
		prev->next = m2;
	}

}
int main(int argc, char const *argv[])
{
	
	
	insert_front(6);
	insert_front(5);
	insert_front(4);
	insert_front(3);
	insert_front(2);
	insert_front(1);	
	display(head);
	
	node* mid = fimd_mid_point();	
	mid = reverse_list(mid);
	inorder_combine(head, mid);
	cout << "In place reorder: " << endl;
	display(head);
	
	return 0;
}