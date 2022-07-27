#ifndef	GRAPH_H
#define GRAPH_H
#include "Tuple.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Graph
{
private:
	vector<Tuple*> tupleList;
	struct Node
	{
		string vertex;
		string value;
		Node(string one, string two) : vertex(one), value(two) {}
		string toString()
		{
			string outString = vertex + ": " + value;
			return outString;
		}
	};
	vector<Node*> nodeList;
public:
	void addEdge(string firstVertex, string secondVertex)
	{
		if (nodeExists(firstVertex) && nodeExists(secondVertex))
		{
			Tuple* newTuple = new Tuple(firstVertex, secondVertex);
			tupleList.push_back(newTuple);
			return;
		}
		else
		{
			throw("VERTICES NOT FOUND");
		}
		
		
	}
	void makeAdjacent(string firstVertex, string secondVertex) //assuming not already connected
	{
		if (nodeExists(firstVertex) && nodeExists(secondVertex))
		{
			Tuple* newTuple = new Tuple(firstVertex, secondVertex);
			tupleList.push_back(newTuple);
			newTuple = new Tuple(secondVertex, firstVertex);
			tupleList.push_back(newTuple);
			return;
		}
		else
		{
			throw("VERTICES NOT FOUND");
		}
	}

	void addNode(string name, string input)
	{
		Node* newNode = new Node(name, input);
		nodeList.push_back(newNode);
	}

	bool nodeExists(string vertex)
	{
		for (Node* currNode : nodeList)
		{
			if (currNode->vertex == vertex)
			{
				return true;
			}
		}
		return false;
	}

	string toString()
	{
		stringstream out;
		out << "Vertices: \n\n";
		for (Node * currNode : nodeList)
		{
			out << currNode->toString() << endl;
		}
		out << "\nEdges: \n\n";
		for (Tuple* currTuple : tupleList)
		{
			out << currTuple->toString() << endl;
		}
		return out.str();
	}
};
#endif

