#include "Digraph.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include<stdio.h>
#include<vector>
#include <algorithm>
#define INFINITY 999
using namespace std;

bool Digraph::insert(int x, int y, int w)
{
cout<<"insert class start"<<endl;
if(m_head==NULL&&digraphVector.at(x)==NULL)
	{
	cout<<"initial insert case"<<endl;
	m_head = new Node(y,w, NULL);
	it = digraphVector.begin();
	digraphVector.insert(it+x, m_head);
	cout<<"inserted "<<x<<" to "<<y<<" with weight "<< w<<" at " <</*it+x<<*/" with "<<m_head<<" vertex "<<m_head->m_y<<" and weight "<<m_head->m_w<<endl;
	}
//normal insert case; need to insert a new node onto the linked list and ensure no duplicates occur."<<endl;
else if(digraphVector.at(x)!=NULL)
	{
		cout<<"normal case"<<endl;
		Node * tmp = digraphVector.at(x);
		while(tmp->m_next!=NULL)
			{
			tmp=tmp->m_next;
			}
		tmp->m_next = new Node(y, w, NULL);
			cout<<"inserted "<<x<<" to "<<y<<" with weight "<< w<<" at " <</*it+x<<*/" with "<<tmp<<" vertex "<<tmp->m_y<<" and weight "<<tmp->m_w<<endl;
	}
//last case: we are moving onto a new vertex and adding a new linked list"
else 
	{
		cout<<"last case"<<endl;
		m_head=new Node(y, w, NULL);
		it = digraphVector.begin();
		digraphVector.insert(it+x, m_head);
			cout<<"inserted "<<x<<" to "<<y<<" with weight "<< w<<" at " <</*it+x<<*/" with "<<m_head<<" vertex "<<m_head->m_y<<" and weight "<<m_head->m_w<<endl;
	}
}
void Digraph::print(ofstream & ofile)
{
cout<<"begin print function"<<endl;
ofile<<"Graph:"<<'\n'<<endl;
it = digraphVector.begin();
for(int i=0; i<numOfVertices; i++,it++)
{
	ofile<<"vertex["<<i<<"]->";
	if((*it)==NULL)
	{
		cout<<"if no linked list, output NULL"<<endl;
		ofile<<"NULL"<<endl;
	}
	else
	{
		cout<<"otherwise print out the attached linked list"<<endl;
		Node * tmp = *(it);
		
		for(true; tmp->m_next!=NULL;tmp=tmp->m_next)
		{
	
			cout<<"beginning traversal"<<endl;
			ofile<<tmp->m_y<<","<<tmp->m_w<<"->";
			cout<<tmp->m_y<<","<<tmp->m_w<<"->";
		}
		
		ofile<<tmp->m_y<<","<<tmp->m_w<<"->";
		cout<<tmp->m_y<<","<<tmp->m_w<<"->";
		ofile<<"NULL"<<endl;
	}
}
}

void Digraph::read()
{
it = digraphVector.begin();
for(int k=0; k<numOfVertices; k++,it++)
{
	if((*it)==NULL)
	{
	//do nothing, leave the infinite value alone
	}
	else
	{
		//otherwise we need to see which values to update for k source vertex
		Node * tmp = *(it);
		
		for(true; tmp->m_next!=NULL;tmp=tmp->m_next)
		{
	
			adjMatrix[k][tmp->m_y]=tmp->m_w;
			//cout<<k<<","<<tmp->m_y<<"->"<<adjMatrix[k][tmp->m_y]<<endl;
		}
		
		adjMatrix[k][tmp->m_y]=tmp->m_w;
		//cout<<k<<","<<tmp->m_y<<"->"<<adjMatrix[k][tmp->m_y]<<endl;
	
	}
}
}

void Digraph::initialize()
{
for(int i=0;i<numOfVertices;i++) {
mark[i] = false;
predecessor[i] = -1;
distance[i] = INFINITY;
}
 distance[source] = 0;
}

int Digraph::getClosestUnmarkedNode()
{
int minDistance = INFINITY;
int closestUnmarkedNode;
for(int i=0;i<numOfVertices;i++) {
if((!mark[i]) && ( minDistance >= distance[i])) {
minDistance = distance[i];
closestUnmarkedNode = i;
}
}
return closestUnmarkedNode;
}

void Digraph::dijkstra()
{
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
}
}

void Digraph::printPath(int node,ofstream &ofile)
{

if(node == source)
{
//cout<<node<<"..";DO NOTHING
}
else if(predecessor[node] == -1)
cout<<"No path from "<<source<<"to "<<node<<endl;
else {
printPath(predecessor[node],ofile);
cout<<node<<"..";
}
}

void Digraph::output(ofstream &ofile)
{
for(int i=0;i<numOfVertices;i++) {
if(i == source)
{
//cout<<source<<".."<<source;DO NOTHING
}
else
printPath(i,ofile);

cout<<"->"<<distance[i]<<endl;
}
}