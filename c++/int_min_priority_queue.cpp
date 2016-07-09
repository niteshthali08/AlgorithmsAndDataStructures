#include <iostream>  
 #include <queue>  
 using namespace std;  

 struct compare  
 {  
   bool operator()(const int& l, const int& r)  
   {  
       return l > r;   // note this you say swap when left is greater than right since this is a min priority queue.
   }  
 };  

 int main()  
 {  
     priority_queue<int,vector<int>, compare > pq;  

     pq.push(3);  
     pq.push(5);  
     pq.push(1);  
     pq.push(8);  
     while ( !pq.empty() )  
     {  
         cout << pq.top() << endl;  
         pq.pop();  
     }  
     cin.get();  
 }