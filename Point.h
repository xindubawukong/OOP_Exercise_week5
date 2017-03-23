#ifndef Point_h
#define Point_h
class Point {
public:
	double x, y;
	Point() = default;
	Point(double _x, double _y) {
		x = _x, y = _y;
	}
};
double getdist(const Point &a, const Point &b);
#endif