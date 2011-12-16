#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include<stdio.h>
#include<vector>
#include <algorithm>
#define INFINITY 999
using namespace std;

class Digraph {

public:

  /** Create empty undirected graph. */
  Digraph ()
  {
    // by standard we can't create zero-element array, so 
    // we create with one element since it won't matter.
	//cout<<"constructor"<<endl;
    digraphVector.clear();
	predecessor.clear();
	distance.clear();
	mark.clear();
	adjMatrix.clear();
	m_head==NULL;
  }

  /** Create directed graphs with n vertices. */
  //here we will resize the vector with the number of vertices given, since we will know the vertices at this time.
  void initialize (int n)
  {
	//cout<<"initialization"<<endl;
	digraphVector.resize(n);
	numOfVertices=n;
	predecessor.resize(n);
	distance.resize(n);
	mark.resize(n);
	adjMatrix.resize(numOfVertices, vector <int>(numOfVertices,INFINITY));
	//for (it=digraphVector.begin() ; it<digraphVector.end() ; it++)
      //digraphVector.insert(it, 0);
  }
void setSource(int x)
{
source=x;
}
bool insert(int x, int y, int w);
void print(ofstream &ofile);
void read();
void initialize();
int getClosestUnmarkedNode();
void dijkstra();
void output(ofstream &ofile);
void printPath(int,int,ofstream &ofile);
protected:
int numOfVertices;
int source;
vector<vector<int> >adjMatrix;
vector<int> predecessor;
vector<int> distance;
vector<bool> mark;
vector<int> path;
vector<int>::iterator pathIt;
vector<int> recurseDist;
//int adjMatrix[15][15];
//int predecessor[15],distance[15];
//bool mark[15];
	class Node
        {
            public:
                // small functions can be inserted into the class definition
                // don't put large functions in the class definition
                Node(int y, int w, Node * next)
                {m_y = y; m_w = w; m_next = next;}
				int m_y;
				int m_w;
                Node *m_next;
        };
        Node *m_head;
		vector<Node*> digraphVector;
		vector<Node*>::iterator it;
};