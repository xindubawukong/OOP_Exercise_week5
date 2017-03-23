#include"Graph.h"
#ifndef MST_h
#define MST_h
class MST {
public:
	int n;// 
	Edge e_mst[23];
	void computeMST(Graph &g,bool flag=true);// I think this function is better to be "static MST computeMST(Graph &g)", but it reflicts the .pdf document.
	void computeTopKMST(Graph &g, int K);// the same as above.
};
#endif