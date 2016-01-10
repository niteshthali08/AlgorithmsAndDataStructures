#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;
/*
Reference: HackerRank: https://www.hackerrank.com/challenges/abstract-classes-polymorphism
Sample Input

3 1
set 1 2
get 1
get 2
Sample Output

2
-1
Explanation

Since, the capacity of the cache is 1, the first set results in setting up the key 1 with it's value 2. The first get results in a cache hit of key 1, so 2 is printed as the value for the first get. The second get is a cache miss, so -1 is printed.
*/
struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache{
    public:
    int keys_present;
    LRUCache(int cap)
    {
        cp = cap;
        keys_present = 0;
        tail = head = NULL;
        
    } 
    void set (int key, int value)
    {
        if(head == NULL)
        {
                
            head = new Node(key, value);
            tail = head;
            mp.insert(std::pair <int, Node*>(key, head)); 
            keys_present++;          
        }
        else
          {
            map<int,Node*>::iterator it;
            it = mp.find(key);
            if (it == mp.end())
            {    
                if (keys_present == cp)
                {
                    Node *t = tail; 
                    tail = tail->prev;
                    if (tail == NULL)
                        head = NULL;
                     mp.erase(t->key);
                     delete t;
                }
                Node *tmp = new Node(NULL, head->next, key, value);
                head = tmp;
                mp.insert(std::pair <int, Node*>(key, head));
                keys_present++;
            }
            else
            {
                Node * t = it->second;
                 t->value = value;
            }
        }
    }
    int get(int key)
    {
        map<int,Node*>::iterator it;
        it = mp.find(key);
        if (it != mp.end())
        {
            Node *node = it->second;
            if (node->prev != NULL)
            {
                node->prev->next = node->next;
                if (node->next)
                    node->next->prev = node->prev;
                head = node;
            }
            return node->value;
            
        }
        return -1;
    }
                          
                          
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
