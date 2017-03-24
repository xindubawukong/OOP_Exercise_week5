#ifndef Edge_h
#define Edge_h
class Edge {
public:
	int u, v;
	double w;
	Edge(int _u = 0, int _v = 0, double _w = 0) :u(_u), v(_v), w(_w) {}
};
bool operator <(const Edge &a, const Edge &b);
bool operator !=(const Edge &a, const Edge &b);
#endif