#include "Digraph.h"
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
		m_head=new node(y, w, NULL);
		it = digraphVector.begin();
		digraphVector.insert(it+x, m_head);
	}
}
