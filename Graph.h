#include"Point.h"
#include"Edge.h"
#include<set>
using namespace std;

#ifndef Graph_h
#define Graph_h
class Graph {
public:
	int n, m;
	Point a[23];
	set<Edge> e;
	Graph() :n(0), m(0) {}
	void insert(double x,double y);
};
#endif