#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include<stdio.h>
#include<vector>
#include "Digraph.cpp"
using namespace std;

int main(int argc, char *argv[])
{
cout<< "GRAPH, by Joshua Hunter"<<endl;
cout<<"Supreme Commander MasterShihoChief"<<endl;
cout<<"Covenant Battle Net High Command"<<endl;
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
cout<<"@@.................................................................................................................................................. C"<<endl;
cout<<"@@                                                                                                                o:                                 C"<<endl;
cout<<"@@                                                                                                               o88:                                C"<<endl;
cout<<"@@                                                                                                              :8OOOc:.                             C"<<endl;
cout<<"@@                                                                                                        :8O88OOOOOOOOO88c                          C"<<endl;
cout<<"@@                                                                                                          :COOOOOOOOOO.                            C"<<endl;
cout<<"@@                                                                                                            COOOOOOO8.                             C"<<endl;
cout<<"@@                                                                                                            OOO8OOOO8c                             C"<<endl;
cout<<"@@                                          .:::::::::::::::::.                                              :C.     :oO                             C"<<endl;
cout<<"@@                                        .::::::::::::::::::::::                                                                                    C"<<endl;
cout<<"@@                                       :::::::::::::::::::::::::                                                                                   C"<<endl;
cout<<"@@                                        :::::::::::::::::::::::.                                                                                   C"<<endl;
cout<<"@@                                          :::::::::::::::::::.                                                                                     C"<<endl;
cout<<"@@                                               ..::::::..                                                                                          C"<<endl;
cout<<"@@                              ..::::::::::::::::::::..                                                                                             C"<<endl;
cout<<"@@                        .::::::::::::::::::::::::::::::::::.                                                                                       C"<<endl;
cout<<"@@                     .::::::::::::::::::::::::::::::::::::::::                                                                                     C"<<endl;
cout<<"@@                    ::::::::::::::::::::::::::::::::::::::::::::                                                                                   C"<<endl;
cout<<"@@                    ::::::::::::::::::::::::::::::::::::::::::::                                                                                   C"<<endl;
cout<<"@@                     :::::::::::::::::::::::::::::::::::::::::.                                                                                    C"<<endl;
cout<<"@@                        .:::::::::::::::::::::::::::::::::.                                                                                        C"<<endl;
cout<<"@@                              ...::::::::::::::::::..                                                                                              C"<<endl;
cout<<"@@                                                ........                                                                                           C"<<endl;
cout<<"@@                                          :::::::::::::::::::.                                                                                     C"<<endl;
cout<<"@@                                       .:::::::::::::::::::::::.                                                                                   C"<<endl;
cout<<"@@                                       :::::::::::::::::::::::::                                                                                   C"<<endl;
cout<<"@@                                        .::::::::::::::::::::::                                                                                    C"<<endl;
cout<<"@@                                          ..::::::::::::::::.                                                                                      C"<<endl;
cout<<"@@                                                                                                                                                   C"<<endl;
cout<<"@@                                                                                                                                                   C"<<endl;
cout<<"@@                                                                                                                                                   C"<<endl;
cout<<"@@                                                                                                                                                   C"<<endl;
cout<<"@@                                                                                                                                                   C"<<endl;
cout<<"@@                                                                                                                                                   C"<<endl;
cout<<"@@                                                                                                                                                   C"<<endl;
cout<<"@@                                                                                                                                                   C"<<endl;
cout<<"@@                                                                                                                                                   C"<<endl;
cout<<"@@                                                                                                                                                   C"<<endl;
cout<<"@@                    o:                                                                                                                             C"<<endl;
cout<<"@@                   o8Oo                                                                                                                            C"<<endl;
cout<<"@@                 .C8OO8c                                                                                                                           C"<<endl;
cout<<"@@            .C8OOOOOOOOOOOO8C                                                                                                                      C"<<endl;
cout<<"@@               oOOOOOOOOOOc                                                                                                                        C"<<endl;
cout<<"@@                c8OOOOOO8c                                                                                                                         C"<<endl;
cout<<"@@               .CO8OOOOO8C                                                                                                                         C"<<endl;
cout<<"@@               cC:      oO.                                                                                                                        C"<<endl;
cout<<"@@...................................................................................................................................................C"<<endl;
Digraph Digraph;
int vertexNum=0;
int x = 0;
int y = 0;
int w = 0;
if(argc !=3)	//Invalid number of args
	{
		cerr << "Error: invalid number of arguments. Proper use is digraph <inputfile> <outputfile>" << endl;
		exit(1);//error
	}
else	
	{
	
		ifstream ifile(argv[1], ios::in);
			if(!ifile)
		{
			cerr << "Error: could not open input file <" << argv[2] << ">" << endl;
        	exit(1); // error
		}	
		ofstream ofile(argv[2], ios::out);
			if(!ofile)
				{
				cerr << "Error: could not open input file <" << argv[2] << ">" << endl;
				exit(1); // error
				}
ifile>>vertexNum;
Digraph.initialize(vertexNum);
ifile.get();
ifile.get();
while(ifile)
	{
	ifile>>x;
	ifile>>y;
	ifile>>w;
	Digraph.insert(x,y,w);
	if(ifile.peek()=='\n')
	{
		Digraph.print(ofile);
		//Digraph.Dijkstra();
		goto outputloop;
	}
outputloop:	
	while(ifile.peek()=='\n')
		{
		ifile.get();
		ifile.get();
		ifile>>x;
		//return shortest path from x to all vertices
		}
	}
	}
return 0;
}