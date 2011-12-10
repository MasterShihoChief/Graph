class Digraph {

public:

  /** Create empty undirected graph. */
  Digraph ()
  {
    // by standard we can't create zero-element array, so 
    // we create with one element since it won't matter.
    digraphVector.clear();
  }

  /** Create directed graphs with n vertices. */
  //here we will resize the vector with the number of vertices given, since we will know the vertices at this time.
  Digraph (int n)
  {
    digraphVector.reserve(n);
  }
  
	bool insert(int x, int y, int w);
	vector<unsigned> digraphVector;
	vector<unsigned>::iterator it;
 Protected:
	class Node
        {
            public:
                // small functions can be inserted into the class definition
                // don't put large functions in the class definition
                Node(int y, int w, Node * next)
                {m_y = y, m_w = w, m_next = next}
				int m_y;
				int m_w;
                Node *m_next;
        };
        Node *m_head;
