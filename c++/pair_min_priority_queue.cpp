#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Compare
{
public:
    bool operator()(const pair<int,int> &n1, const pair<int,int>& n2) { // overloaded function with (), return true whenever you want to change priority
        return n1.second > n2.second; // min-priority queue, since you are changing priority of n2 when n1 > n2
    }
};
int main()
{
    priority_queue< pair<int,int>, vector<pair <int, int> >, Compare> pq; // **** function should be third args, second should be container.
    pq.push(make_pair(1,2));
    pq.push(make_pair(1,10));
    pq.push(make_pair(1,5));  //*** Note make_pair() function

    while(!pq.empty()){
    	pair <int, int> current = pq.top();
    	cout << "(" << current.first << ", " << current.second << ")\n";
    	pq.pop();
    }

}

/*
OUTPUT
(1, 2)
(1, 5)
(1, 10)
*/