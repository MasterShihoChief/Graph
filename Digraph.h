#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include<stdio.h>
#include<vector>
#define INFINITY 999
using namespace std;

class Digraph {

public:

  /** Create empty undirected graph. */
  Digraph ()
  {
    // by standard we can't create zero-element array, so 
    // we create with one element since it won't matter.
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
    digraphVector.reserve(n);
	numOfVertices=n;
	predecessor.reserve(n);
	distance.reserve(n);
	mark.reserve(n);
	//for (it=digraphVector.begin() ; it<digraphVector.end() ; it++)
      //digraphVector.insert(it, 0);
  }
  
bool insert(int x, int y, int w);
void print(ofstream &ofile);
void read();
void initialize();
int getClosestUnmarkedNode();
void dijkstra();
void output();
void printPath(int);
protected:
int numOfVertices;
int source;
vector<vector<int> >adjMatrix;
vector<int> predecessor;
vector<int> distance;
vector<bool> mark;
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