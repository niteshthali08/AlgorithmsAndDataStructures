#include <iostream>
#include <list>
#include <vector>

using namespace std;
/* insert(), begin(), end(), push_back(), pop_back(), pop_front(), pop_back(), empty(), remove(), remove_if(), erase()
"reference: http://www.cplusplus.com/reference/list/list/"
"Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.
List containers are implemented as doubly-linked lists
Doubly linked lists can store each of the elements they contain in different and unrelated storage locations."
forward_list =>  objects are single-linked lists.
Generally lists perform better than array, vector and deque.
Disad : lack of direct access to element by index.
*/

int main(int argc, char const *argv[])
{
	list <int> mylist;
	list <int>::iterator it, it1;
	for (int i=10; i<=50; i = i+10) 
		mylist.push_back(i); // ->10->20->30->40->50
	for (it=mylist.begin(); it!=mylist.end(); ++it)
    	cout << "->" << *it;
	cout << endl;
	it1 = mylist.begin();
	cout << "begin() -> points to: "<< *it << endl;
	it1 ++; // now begin points to 20
	cout << "now it -> points to: "<< *it << endl;
	
	mylist.insert(it1, 100); // this will insert infront of it
	for (it=mylist.begin(); it!=mylist.end(); ++it)
    	cout << "->" << *it;
	cout << endl;
	// it still points to 20
  	mylist.insert (it1,2,2);    // insert 20 twice infront of it  
	for (it=mylist.begin(); it!=mylist.end(); ++it)
    	cout << "->" << *it;
	cout << endl;

	vector<int> myvector (2,300); // vector having 300 twice.
  	mylist.insert (it1,myvector.begin(),myvector.end());
    for (it=mylist.begin(); it!=mylist.end(); ++it)
    	cout << "->" << *it;
	cout << endl;  
  	
  	cout << "pushing in front and back---" << endl;
  	mylist.push_back(1000); // insert at end;
  	mylist.push_front(2000); // insert at start of the list
  	for (it=mylist.begin(); it!=mylist.end(); ++it)
    	cout << "->" << *it;
	cout << endl; 
	
	cout << "poping from front and back---" <<endl;
	mylist.pop_back();
	mylist.pop_front();
	for (it=mylist.begin(); it!=mylist.end(); ++it)
    	cout << "->" << *it;
	cout << endl;
	
	// remove() function, removes by value
	cout << "reoving node with value 300 by using remove()" << endl;
	mylist.remove(300); // removes all nodes with value 300
	for (it=mylist.begin(); it!=mylist.end(); ++it)
    	cout << "->" << *it;
	cout << endl;
	// remove_if() function => mylist.remove_if (some_function()) // functio should return a boolean
	
	// erase() function takes iterator and not value, u can specify range as well by giving two iterators.
	cout << "deleting second element using erase() function" << endl;
	it1 = mylist.begin();
	it1++ ;
	mylist.erase(it1);
	for (it=mylist.begin(); it!=mylist.end(); ++it)
    	cout << "->" << *it;
	cout << endl;

	cout << "poping all values till list gets emptied" << endl;
	//empty function
	while (!mylist.empty())
  {
     cout << "->" << mylist.front();
     mylist.pop_front();
     
   }
   cout << "\nNow list is empty" <<endl;
	return 0;
}