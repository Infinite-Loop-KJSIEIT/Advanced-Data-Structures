#include<iostream>
#include<vector>
using namespace std;

int path; //Global variable to count possible paths.

class graph
{
private:
	int v;
	bool *visited;
	std::vector<int> *edge; //May be a single pointer in case of a linear structure or a std::pair for a weighted graph/tree.
	
public:
	graph(int);
	void addEdge(int, int);
	void dfs(int, int);
};

graph::graph(int v)
{
	this->v = v;
	edge = new std::vector<int>[v];
	visited = new bool[v];
}

void graph::addEdge(int u, int v)
{
	edge[u].push_back(v);
	//edge[v].push_back(u); Remove comment for undirected graph.
}

void graph::dfs(int s, int d)
{
	if(s != d) //DFS is limited by the destination value.
	{
		if((visited[s]) || (edge[s].empty())) // Discards loops or leaves in the graph.
			return;
		else
		{
			visited[s] = true; // Prevents loops in the child tree.
			for(auto I = edge[s].begin(); I != edge[s].end(); ++I)
				dfs(*I, d);
			visited[s] = false; // Allows new paths.
		}
	}
	else
		path++; //Successfull paths.
}

int main()
{
	int T;
	cin >> T;
	while(T-- > 0)
	{
		int u, v, e;
		cin >> v >> e;
		graph G(v);
		for(int i = 0; i < e; i++)
		{
			cin >> u >> v;
			G.addEdge(u, v);
		}
		cin >> u >> v;
		path = 0;
		G.dfs(u, v);
		cout << path << std::endl;
	}
	return(0);
}
