#include <iostream>
#include <vector>
#include <queue>

class Graph
{
public:
	Graph(int numVertices);
	~Graph() {}

	void insert(int u, int v);
	void printGraph();

	void BFS(int startingVertex, std::vector<bool>& visited);
	void BFSDis(int& numConnectedComp);

	void DFS(int startingVertex, std::vector<bool>& visited);
	void DFSDis();

private:
	std::vector<std::vector<int>> adjList;
};

Graph::Graph(int numVertices)
{
	adjList.resize(numVertices);
}

void Graph::printGraph()
{
	for (int i = 0; i < adjList.size(); ++i)
	{
		std::cout << i << " <-> ";
		for (int j = 0; j < adjList[i].size(); ++j)
		{
			std::cout << adjList[i][j] << " <-> ";
		}
		std::cout << std::endl;
	}
}

void Graph::insert(int u, int v)
{
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

void Graph::BFS(int startingVertex, std::vector<bool>& visited)
{
	std::queue<int> bfsQueue;

	bfsQueue.push(startingVertex);
	visited[startingVertex] = true;

	while(!bfsQueue.empty())
	{
		int u = bfsQueue.front();		
		bfsQueue.pop();

		std::cout << u << " ";

		for(auto& v : adjList[u])
		{
			if(!visited[v]) 
			{
				visited[v] = true;
				bfsQueue.push(v);
			}
		}

	}
}

void Graph::BFSDis(int& numConnectedComp)
{
	std::vector<bool> visited(adjList.size(), false);
	for (int i = 0; i < visited.size(); ++i)
	{
		if(!visited[i])
		{
			numConnectedComp++;
			BFS(i, visited);
		}
	}
}

void Graph::DFS(int startingVertex, std::vector<bool>& visited)
{
	std::cout << startingVertex << " ";
	visited[startingVertex] = true;

	for(auto& v : adjList[startingVertex])
	{
		if(!visited[v])
		{
			visited[v] = true;
			DFS(v, visited);
		}
	}
}

void Graph::DFSDis()
{
	std::vector<bool> visited(adjList.size(), false);
	for (int i = 0; i < visited.size(); ++i)
	{
		if(!visited[i])
		{
			DFS(i, visited);
		}
	}
}

int main(int argc, char const *argv[])
{
	Graph graph(7);

	graph.insert(0, 1);
	graph.insert(0, 4);
	graph.insert(1, 2);
	graph.insert(2, 3);
	graph.insert(4, 5);
	graph.insert(4, 6);
	graph.insert(5, 6);

	graph.printGraph();

	int numConnectedComp{0};
	graph.BFSDis(numConnectedComp);
	std::cout << std::endl;
	std::cout << "Number of connected components = " << numConnectedComp << std::endl;

	graph.DFSDis();
	std::cout << std::endl;

	return 0;
}

// g++ -std=c++11 Graph.cpp -o Graph