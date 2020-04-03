#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
	private:
		int numberOfVertices;
		list<int> *adjacencyList;
		int **adjacencyMatrix;
	public:
		Graph(int n)
		{
			numberOfVertices=n;
			adjacencyMatrix=new int* [n];
			for(int i=0;i<n;i++)
			{
				adjacencyMatrix[i]=new int[n];
			}
			
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i==j)
						adjacencyMatrix[i][j]=0;
					else
						adjacencyMatrix[i][j]=-1;
				}
			}
			adjacencyList=new list<int>[n];
		}
		int addEdge(int u, int v)
		{
			adjacencyMatrix[u][v]=1;
			adjacencyMatrix[v][u]=1;
			adjacencyList[u].push_back(v);
			adjacencyList[v].push_back(u);
		}
		void printGraph()
		{
			cout<<"The graph is"<<endl;
			for(int i=0;i<numberOfVertices;i++)
			{
				for(int j=0;j<numberOfVertices;j++)
				{
					if(adjacencyMatrix[i][j]==1)
						cout<<"["<<i<<","<<j<<"]"<<endl;
				}
			}
		}
		void printAdjacencyMatrix()
		{
			cout<<"The adjacency matrix is"<<endl;
			for(int i=0;i<numberOfVertices;i++)
			{
				for(int j=0;j<numberOfVertices;j++)
				{
					cout<<adjacencyMatrix[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		void BFS(int startVertex)
		{
			int *visited;
			visited=new int[numberOfVertices];
			memset(visited,0,numberOfVertices*sizeof(int));
			list<int> q;
			list<int>::iterator i;
			int vertex;
			q.push_back(startVertex);
			visited[startVertex]=1;
			while(!q.empty())
			{
				vertex=q.front();
				cout<<vertex<<" ";
				q.pop_front();
				for(i=adjacencyList[vertex].begin();i!=adjacencyList[vertex].end();i++)
				{
					if(!visited[*i])
					{
						visited[*i]=1;
						q.push_back(*i);
					}
				}
			}
		}
		void DFSUtil(int vertex, int visited[])
		{
			visited[vertex]=1;
			cout<<vertex<<" ";
			list<int>::iterator i;
			for(i=adjacencyList[vertex].begin();i!=adjacencyList[vertex].end();i++)
			{
				if(!visited[*i])
					DFSUtil(*i,visited);
			}
		}
		void DFS(int startVertex)
		{
			int *visited;
			visited=new int[numberOfVertices];
			memset(visited,0,numberOfVertices*sizeof(int));
			DFSUtil(startVertex,visited);
		}
};
int main()
{
	Graph g(4);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
	g.printGraph();
	cout<<"The BFS traversal of the graph from vertex 0 is:"<<endl;
	g.BFS(0);
	cout<<endl;
	cout<<"The DFS traversal of the graph from vertex 0 is:"<<endl;
	g.DFS(0);
	return 0;
}
