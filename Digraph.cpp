#include "Digraph.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include<stdio.h>
#include<vector>
using namespace std;

bool Digraph::insert(int x, int y, int w)
{
//initial insert case
if(m_head==NULL&&digraphVector.at(x)==NULL)
	{
	m_head = new Node(y,w, NULL);
	it = digraphVector.begin();
	digraphVector.insert(it+x, m_head);
	}
//normal insert case; need to insert a new node onto the linked list and ensure no duplicates occur. 
else if(digraphVector.at(x)!=NULL)
	{
		Node * tmp = digraphVector.at(x);
		while(tmp->m_next!=NULL)
			{
			tmp=tmp->m_next;
			}
		tmp = new Node(y, w, NULL);
	}
//last case: we are moving onto a new vertex and adding a new linked list	
else 
	{
		m_head=new Node(y, w, NULL);
		it = digraphVector.begin();
		digraphVector.insert(it+x, m_head);
	}
}
void Digraph::print(ofstream & ofile)
{
ofile<<"Graph:"<<endl;
it = digraphVector.begin();
for(int i=0; i<numOfVertices; i++,it++)
{
	ofile<<"vertex["<<i<<"]->";
	if(*it<0)
	{
		ofile<<"NULL"<<endl;
	}
	else
	{
		for(Node * tmp = *it ; tmp->m_next!=NULL; tmp=tmp->m_next)
		{
			ofile<<tmp->m_y<<","<<tmp->m_w<<"->";
		}
		ofile<<"NULL"<<endl;
	}
}
}

void Digraph::read()
{/*
//Read the adjacency matrix for the graph with +ve weights
cout<<”Enter the adjacency matrix for the graph\n”;
cout<<”To enter infinity enter “<<INFINITY<<endl;
for(int i=0;i<numOfVertices;i++) {
cout<<”Enter the (+ve)weights for the row “<<i<<endl;
for(int j=0;j<numOfVertices;j++) {
cin>>adjMatrix[i][j];
while(adjMatrix[i][j]<0) {
cout<<”Weights should be +ve. Enter the weight again\n”;
cin>>adjMatrix[i][j];
}
}
}

//read the source node from which the shortest paths to other nodes has to be found
cout<<”Enter the source vertex\n”;
cin>>source;
while((source<0) && (source>numOfVertices-1)) {
cout<<”Source vertex should be between 0 and “<<numOfVertices-1<<endl;
cout<<”Enter the source vertex again\n”;
cin>>source;
}*/
}

void Digraph::initialize()
{/*
for(int i=0;i<numOfVertices;i++) {
mark[i] = false;
predecessor[i] = -1;
distance[i] = INFINITY;
}
distance

[/source]

= 0;*/
}

int Digraph::getClosestUnmarkedNode()
{/*
int minDistance = INFINITY;
int closestUnmarkedNode;
for(int i=0;i<numOfVertices;i++) {
if((!mark[i]) && ( minDistance >= distance[i])) {
minDistance = distance[i];
closestUnmarkedNode = i;
}
}
return closestUnmarkedNode;*/
}

void Digraph::dijkstra()
{/*
initialize();
int minDistance = INFINITY;
int closestUnmarkedNode;
int count = 0;
while(count < numOfVertices) {
closestUnmarkedNode = getClosestUnmarkedNode();
mark[closestUnmarkedNode] = true;
for(int i=0;i<numOfVertices;i++) {
if((!mark[i]) && (adjMatrix[closestUnmarkedNode][i]>0) ) {
if(distance[i] > distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i]) {
distance[i] = distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i];
predecessor[i] = closestUnmarkedNode;
}
}
}
count++;
}*/
}

void Digraph::printPath(int node)
{/*
if(node == source)
cout<<node<<”..”;
else if(predecessor[node] == -1)
cout<<”No path from “<<source<<”to “<<node<<endl;
else {
printPath(predecessor[node]);
cout<<node<<”..”;
}*/
}

void Digraph::output()
{/*
for(int i=0;i<numOfVertices;i++) {
if(i == source)
cout<<source<<”..”<<source;
else
printPath(i);

cout<<”->”<<distance[i]<<endl;
}*/
}