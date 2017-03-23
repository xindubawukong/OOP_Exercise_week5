#include"Graph.h"
#include<set>
using namespace std;

#ifndef MST_h
#define MST_h
class MST {
public:
	Graph *g;
	set<Edge> e_mst;
	double length;
	MST() = default;
	MST(Graph *_g) :g(_g) {}
	void computeMST();// I think this function is better to be "static MST computeMST(Graph &g)", but it reflicts the .pdf document.
	void computeTopKMST(int K);// the same as above.
	void output();// output the minimum spanning tree.
};
#endif