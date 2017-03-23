#include"Edge.h"
bool Edge::operator <(const Edge &a) {
	return w < a.w;
}