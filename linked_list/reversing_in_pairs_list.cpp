#include <iostream>
using namespace std;
/* author: Nitesh Thali
C++ implementation for reversing singly linked list by swapping links between nodes#
Midification: You have to do swapping in groups of n
If Linked List->1->2->3->4->5->6->7->8->9
o/p : 3->2->1->6->5->4->9->8->7 (when n == 3)
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
void insert_back(int data)
{
	node *tmp = head;
	if(head == NULL)
		head = getNode(data);
	else
	{
		while(tmp->next !=NULL)
			tmp = tmp->next;
		tmp->next = getNode(data);
	}
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
void delete_list(int data)
{
	// check on empty list before deletion is missing.
	node *tmp = head, *prev;
	if (data == head->data)
	{
		head = head->next;
	}
	else
	{
		while(tmp != NULL && tmp->data != data )
		{	prev = tmp;
			tmp = tmp->next;
		}
		if(tmp == NULL)
			cout <<"Node to be deleted not found in the linked list" << endl;
		else
			prev->next = tmp->next;
	}
	free (tmp);
}
void display()
{
	node *tmp = head;
	cout << "Linked List";
	while(tmp)
	{
		cout <<"->" << tmp->data;
		tmp = tmp->next;
	}
	cout << endl;
}
void reverse_list_in_pairs(int n)
{
	// strategy is to do normal reversing in group of 'n' and keep track of start and end of each group to link them together.
	node *prev = NULL, *curr = head, *nxt, *block_start, *prev_block_start;
	if (head == NULL)
		return;
	int count = 0;
	head = NULL;
	while(curr->next != NULL)
	{
		if(count == 0)
			block_start = curr;
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
		count ++;
		if (count == n)
		{
			if(head == NULL)
				{
					head = prev;
					prev_block_start = block_start;
					
				}
			else
			{
				prev_block_start->next = prev;
				prev_block_start = block_start;
			}
			count = 0;
		}
	}
	if (prev_block_start == block_start) // if only one element is left after grouping n elements.
	{
		prev_block_start->next = curr;
	}
	else // more than one but lesss than 'n' element is left
	{	
		curr->next = prev;
		prev_block_start->next = curr;
		block_start->next = NULL; // important
	}
	if(!head) // to handle case in which "n > number_of_elements_in_linked_list".
		head = curr;	
}
int main(int argc, char const *argv[])
{
	
	insert_back(1);
	insert_back(2);
	insert_back(3);
	insert_back(4);
	insert_back(5);
	insert_back(6);	
	insert_back(7);	
	insert_back(8);
	insert_back(9);


	display();
	reverse_list_in_pairs(4);
	cout << "Reversed Linked List: " << endl;
	display();
	
	return 0;
}