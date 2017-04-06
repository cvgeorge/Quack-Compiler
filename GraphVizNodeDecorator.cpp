/*

 * GraphVizNodeDecorator.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: roscoecasita
 */
#include "GraphVizNodeDecorator.hpp"
#include <sstream>
#include <math.h>



// This is the static class that generates unique
IdentifierDatabase StaticIdentifiers;

/*
 * Initialize an identifier database, initialize the 6 alpha HEX characters as the string identifiers.
 * These serve as characters for random identifiers to generate graphviz nodes.
 */
IdentifierDatabase::IdentifierDatabase()
{
	std::string alphas = "ABCDEF";
	for(size_t i = 0; i < alphas.size(); i++)
	{
		ValidCharacters.push_back(alphas[i]);
	}
}

/*
 * This might not actually ever be called.
 */
IdentifierDatabase::~IdentifierDatabase()
{
	Database.clear();
}

/*
 * Generate a new string identifier.
 * Guaranteed to be unique, starting at 5 characters.
 */
std::string IdentifierDatabase::GenerateID()
{
	std::stringstream returnValue;

	int count = 42;
	while(count > 0)
	{
		returnValue<< ValidCharacters[ rand() % ValidCharacters.size()];
		count--;
	}

	std::string rvalue = returnValue.str();
	count = Database[rvalue];

	if(count != 0)
	{
		std::cerr << "INVALID ALLOCATE OF IDENTIFIER FOR GRAPHVIZ." << std::endl;
	}

	Database[rvalue] = 1;

	return rvalue;

}

/*
 * This gets called when a node is leaving the system. this should be hit at some point,
 * If the system is dynamic and deleting these.
 */
void IdentifierDatabase::RetireID(std::string id)
{

	Database.erase(id);

}

/*
 * Generate a new node, default to the ID, and set to circle.
 */
GraphVizNodeDecorator::GraphVizNodeDecorator():UniqueIdentifier(StaticIdentifiers.GenerateID())
{
	this->NodeLabel = this->UniqueIdentifier;
	this->NodeShape = "circle";

}

/*
 * Cleanup any identifiers.
 */
GraphVizNodeDecorator::~GraphVizNodeDecorator()
{
	StaticIdentifiers.RetireID(this->UniqueIdentifier);
	this->NodeLabel = "";
	this->NodeShape = "";

}

/*
 * This abstracts the generation of node text away.
 * Just put your label text and style.
 */
std::string GraphVizNodeDecorator::GenerateGravizNode()
{
	std::string returnValue = "";
	returnValue += "\t";
	returnValue += this->UniqueIdentifier;
	returnValue += " [label=\"";
	returnValue += this->NodeLabel;
	returnValue += "\", shape = \"";
	returnValue += this->NodeShape;
	returnValue += "\"];\r\n";
	return returnValue;
}

/*
 * This abstracts the graphviz edge generation,
 * Notice there is a graphvizEdgeDecoration.
 */
std::string GraphVizNodeDecorator::GenerateGravizEdge(GraphVizNodeDecorator *edge,bool digraph)
{
	std::string returnValue ="";
	if(edge != NULL)
	{
		returnValue += "\t";
		returnValue += this->UniqueIdentifier;
		if(digraph)
		{
			returnValue += " -> ";
		}
		else
		{
			returnValue += " -- ";
		}
		returnValue += edge->UniqueIdentifier;

		returnValue += GenerateGravizEdgeDecoration(edge);
		returnValue += ";\r\n";
	}

	return returnValue;
}

/*
 * If edges are decorated, this this function should be overwritten with the entire decoration.
 */
std::string GraphVizNodeDecorator::GenerateGravizEdgeDecoration(GraphVizNodeDecorator *edge)
{
	return "";
}

/*
 * This is the main function to actually generate all the strings.
 *
 */
void RecurseGraphVizNodeDecorators(GraphVizNodeDecorator *root, std::vector<GraphVizNodeDecorator *> &visited, std::stringstream &printer,bool digraph)
{
	if(NULL != root)
	{
		std::vector<GraphVizNodeDecorator *>::iterator itr = find(visited.begin(),visited.end(),root);
		if(itr == visited.end())
		{
			visited.push_back(root);
			
			std::vector<GraphVizNodeDecorator *> edges = root->GenerateGraphvizChildren();
			printer << root->GenerateGravizNode().c_str();

			for(size_t i =0; i < edges.size(); i++)
			{
				GraphVizNodeDecorator *call = edges[i];

				printer << root->GenerateGravizEdge(call,digraph);
				RecurseGraphVizNodeDecorators(call,visited,printer,digraph);
			}
		}
	}
}

/*
 * This generates the entire graphvize file, if you give it the root, it will trace edges and nodes until complete.
 * This also looks for repetitions, so the graph will not loop forever.
 */
std::string GenerateGraphviz(GraphVizNodeDecorator *root,bool digraph,std::string name)
{
	std::stringstream returnValue;
	std::vector<GraphVizNodeDecorator *> visited;

	if(digraph)
	{
		returnValue << "digraph ";
	}
	else
	{
		returnValue << "graph";
	}

	returnValue << "noname";

	returnValue << "\r\n{\r\n";

	RecurseGraphVizNodeDecorators(root,visited,returnValue,digraph);
	returnValue << "label = \"" + name + "\";\r\n";
	returnValue << "}\r\n";

	return returnValue.str();
}
