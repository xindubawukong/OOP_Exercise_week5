#include"Graph.h"
#include"Point.h"
#include"Edge.h"

void Graph::insert(double x, double y) {
	a[n++] = Point(x, y);
	for (int i = 0; i < n - 1; i++) {
		m++;
		e.insert(Edge(i, n - 1, getdist(a[i], a[n - 1])));
	}
}