#include"Graph.h"
#ifndef MST_h
#define MST_h
class MST {
public:
	void computeMST(Graph &g);
	void computeTopKMST(Graph &g, int K);
};
#endif