#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

class Node 
{
public:
	int vertex;
	Node *next;

	Node(int v)
	{
		vertex = v;
		next = NULL;
	}
};

class Graph 
{
private:
	int numVertices;
	Node **adjList;

public:
	Graph(int vertices)
	{
		numVertices = vertices;
		adjList = new Node*[numVertices];

		for (int i = 0; i < numVertices; i++)
			adjList[i] = NULL;
	}

	void AddVertex(int vertex)
	{

		if (vertex < 0 || vertex >= numVertices)
			return;

		Node *temp = adjList[vertex];
		while (temp != NULL)
		{
			if (temp->vertex == vertex)
				return;

			temp = temp->next;
		}


		Node *n = new Node(vertex);
		n->next = adjList[vertex];
		adjList[vertex] = n;
	}

	void AddEdge(int firstVertex, int secondVertex) 
	{
		if (firstVertex < 0 || firstVertex >= numVertices || secondVertex < 0 || secondVertex >= numVertices)
			return;
		
		Node *n = new Node(secondVertex);
		n->next = adjList[firstVertex];
		adjList[firstVertex] = n;

		
		n = new Node(firstVertex);
		n->next = adjList[secondVertex];
		adjList[secondVertex] = n;
	}

	void RemoveEdge(int firstVertex, int secondVertex) 
	{
		
		if (firstVertex < 0 || firstVertex >= numVertices || secondVertex < 0 || secondVertex >= numVertices)
			return;
			
		Node *current = adjList[firstVertex];
		Node *prev = NULL;

		while (current) 
		{
			if (current->vertex == secondVertex) 
			{
				if (prev)
					prev->next = current->next;
				else
					adjList[firstVertex] = current->next;

				delete current;
				return;
			}

			prev = current;
			current = current->next;
		}

		return;
	}

	void RemoveVertex(int vertex) 
	{
		
		if (vertex < 0 || vertex >= numVertices)
			return;
		
		for (int i = 0; i < numVertices; ++i) 
		{
			if (i != vertex)
				RemoveEdge(i, vertex);
		}

		
		Node *current = adjList[vertex];
		while (current) 
		{
			Node* next = current->next;
			delete current;
			current = next;
		}

		adjList[vertex] = nullptr;
	}

	string BFS(int startVertex)
	{
		if (startVertex < 0 || startVertex >= numVertices)
			return "";

		bool *visited = new bool[numVertices];

		for (int i = 0; i < numVertices; i++)
			visited[i] = false;

		queue<int> q;
		q.push(startVertex);
		visited[startVertex] = true;

		string result;
		while (q.empty() == false)
		{
			int currentVertex = q.front();
			q.pop();
			result += to_string(currentVertex) + " ";

			Node *temp = adjList[currentVertex];
			while (temp != NULL)
			{
				if (visited[temp->vertex] == false)
				{
					q.push(temp->vertex);
					visited[temp->vertex] = true;

				}
				temp = temp->next;
			}

		}
		delete[] visited;
		return result;
	}

	string DFS(int startVertex) 
	{
		if (startVertex < 0 || startVertex >= numVertices)
			return "";
		
		string result;
		stack<int> s;
		bool *visited = new bool[numVertices];

		s.push(startVertex);
		visited[startVertex] = true;

		
		while (s.empty() == false)
		{
			int currentVertex = s.top();
			s.pop();
			result += to_string(currentVertex) + " ";

			Node *temp = adjList[currentVertex];
			while (temp != NULL)
			{
				if (visited[temp->vertex] == false)
				{
					s.push(temp->vertex);
					visited[temp->vertex] = true;

				}
				temp = temp->next;
			}

		}
		delete[] visited;
		return result;
		
	}

};
