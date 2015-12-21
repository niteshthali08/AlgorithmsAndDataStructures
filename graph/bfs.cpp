#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
	int v;
	list<int> *adj;
	
public:
	Graph(int v);
	int *distance; // keep track of distances between all pairs of node in BFS.
	void create_adjacency_list(int i, int j);
	void BFS(int start);
};

Graph :: Graph(int v1)
{
	v = v1;
	distance = new int [v];
	adj = new list<int> [v]; //note [] brackets here.
}

void Graph :: create_adjacency_list(int i, int j)
{
	adj[i].push_back(j); // creating a adjajency list for vertex i
}

void Graph :: BFS (int start)
{
	bool *visited = new bool[v];
	for (int i = 0; i < v; ++i)
	{
		 visited[i] = false;
	}
	queue<int> q;
	q.push(start);
	visited[start] = true;
	distance[start] = 0;
	list <int>::iterator i;
	while (!q.empty())
	{
		start = q.front(); // q doesn't have top fucntion as in queue and priority queue.
		cout <<"->" << start ;
		q.pop();
		for (i = adj[start].begin(); i != adj[start].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				q.push(*i);
				distance[*i] = distance[start] + 1;
			}
		}
		
		
	}	
cout << endl;
}

int main(int argc, char const *argv[])
{
	Graph g(4);
    g.create_adjacency_list(0, 1);
    g.create_adjacency_list(0, 2);
    g.create_adjacency_list(1, 2);
    g.create_adjacency_list(2, 0);
    g.create_adjacency_list(2, 3);
    g.create_adjacency_list(3, 3);
 
    cout << "BFS: ";
    g.BFS(2);
    cout<< "Total steps to reach node 1 from node 2 in above BFS is "<<g.distance[1] << endl;
	return 0;
}
