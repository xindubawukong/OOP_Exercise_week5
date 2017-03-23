#include"Point.h"
#include"Edge.h"

#ifndef Graph_h
#define Graph_h
class Graph {
public:
	int n, m;
	Point a[23];
	Edge e[23 * 23];
	void insert(double x,double y);
};
#endif