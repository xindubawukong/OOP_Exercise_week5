#include"Point.h"
#include<cmath>
inline double getdist(const Point &a, const Point &b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}