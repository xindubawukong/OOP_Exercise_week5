#include"MST.h"
#include"Graph.h"
#include"Point.h"
#include"Edge.h"
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<bitset>
#include<fstream>
using namespace std;
long long random_integer(long long n) {
	// return a random integer in range of [0,n)
	long long tmp = (long long)rand()*rand()*rand() % n;
	if (tmp < 0) tmp += n;
	return tmp;
}
double random_double(double x) {
	// return a random double in range of [0,x)
	return random_integer(x * 1000000) / 1000000.0;
}
int main() {
	srand(time(0));
	Graph g;
	for (int i = 0; i < 20; i++)
		g.insert(Point(random_double(10000), random_double(10000)));
	MST g_mst;
	g_mst.computeMST(g);// output the minimum spanning tree of Graph g;
	int K = 20;
	g_mst.computeTopKMST(g, K);//output the top K minimum spanning trees of Graph g;
	return 0;
}