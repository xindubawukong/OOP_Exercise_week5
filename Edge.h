#ifndef Edge_h
#define Edge_h
class Edge {
public:
	int u, v;
	double w;
	Edge() = default;
	Edge(int _u, int _v, double _w) :u(_u), v(_v), w(_w) {}
};
bool operator <(const Edge &a, const Edge &b);
#endif