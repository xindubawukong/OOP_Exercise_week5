#include"Edge.h"
#include<cmath>

#define eps 1e-7
bool operator <(const Edge &a, const Edge &b) {
	if (fabs(a.w - b.w) > eps) return a.w < b.w;
	if (a.u != b.u) return a.u < b.u;
	return a.v < b.v;
}
bool operator !=(const Edge &a, const Edge &b) {
	return a.u != b.u || a.v != b.v;
}