
Digraph: graphmain.o
	g++ -o Digraph graphmain.o

graphmain.o: Digraph.h Digraph.cpp
	g++ -Wall -pedantic -c graphmain.cpp

clean:
	rm -f graphmain.o Digraph
