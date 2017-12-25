#include<iostream>
#include<vector>
#include<map>
using namespace std;

std::vector<int> T;

class graph;

class node
{
private:
	int parent, path;
	bool visited;
public:
	node();
	void assign(int, int);
	int distance();
	int getParent();
};

node *Tree;

node::node() : parent(-1), path(0), visited(false) {}

void node::assign(int p, int d)
{
	if((visited == true) && (path < d))
			return;
	else
	{
		visited = true;
		parent = p;
		path = d;
	}
}

int node::distance()
{
	return(path);
}

int node::getParent()
{
	return(parent);
}

class graph
{
private:
	int v;
	bool *visited;
	std::map<int, int> *edge; //May be a single pointer in case of a linear structure or a std::pair for a weighted graph/tree.
	
public:
	graph(int);
	void addEdge(int, int, int);
	void build_tree(int);
	int cost(int, int);
};

graph::graph(int v)
{
	this->v = v;
	edge = new std::map<int, int>[v];
	visited = new bool[v];
}

void graph::addEdge(int u, int v, int c)
{
	edge[u].insert(std::pair<int, int> (v, c));
	edge[v].insert(std::pair<int, int> (u, c));
}

void graph::build_tree(int s)
{
	if((visited[s]) || (edge[s].empty())) // Discards loops or leaves in the graph.
		return;
	visited[s] = true;
	for(auto I = edge[s].begin(); I != edge[s].end(); ++I)
	{
		int d = Tree[s].distance() + I->second;
		Tree[I->first].assign(s, d);
		T.push_back(I->first);
	}
	if(!T.empty())
	{
		int t = T[0];
		T.erase(T.begin(), T.begin() +0);
		build_tree(t);
	}
}

int graph::cost(int u, int v)
{
	auto i = edge[u].find(v);
	return(i->second);
}

int main() // CAUTION: Problem indexes the vertices from 1 and not 0.
{
	/*int T;
	cin >> T;
	while(T-- > 0)*/
	int u, v, e, c, s, d;
	cin >> s >> d >> v >> e;
	graph G(v+1);
	Tree = new node[v+1];
	for(int i = 0; i < e; i++)
	{
		cin >> u >> v >> c;
		G.addEdge(u, v, c);
	}
	G.build_tree(s);
	v = Tree[d].getParent();
	c = Tree[v].distance() + G.cost(v, d);
	std::cout <<  c << std::endl;
	return(0);
}
