#include <iostream>  
#include <queue>  
using namespace std;  
 /*
author: Nitesh Thalli
 */ 
int main(int argc, char const *argv[])
 {  
    //by defaul queue is max priority queue.
    
    priority_queue<int> pq;  
  
    pq.push(2);  
    pq.push(6);  
    pq.push(1);  
    pq.push(8); 
    pq.push(10); 
    while ( !pq.empty() )  
    {  
        cout << pq.top() << endl;  
        pq.pop();  
    }  
    //

    return 0;
} 