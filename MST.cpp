#include"MST.h"
#include"Graph.h"
#include"BCJ.h"
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
void MST::computeMST(Graph &g,bool flag) {
	Edge *b = new Edge[23*23];
	for (int i = 0; i < g.m; i++) b[i] = g.e[i];
	sort(b, b + g.m);
	BCJ *bcj = new BCJ(g.n);
	int cnt = 0;
	for (int i = 0; i<g.m; i++)
		if (bcj->getfa(b[i].u) != bcj->getfa(b[i].v)) {
			bcj->hebing(b[i].u, b[i].v);
			e_mst[cnt++] = b[i];
		}
	delete[] b;
	if (flag) {
		double ans = 0;
		for (int i = 0; i < g.n-1; i++)
			ans += e_mst[i].w;
		cout << "The minimum spanning tree is: " << ans << endl;
		for (int i = 0; i < g.n - 1; i++)
			printf("   u=(%.3f,%.3f) v=(%.3f,%.3f) w=%.3f\n", g.a[e_mst[i].u].x, g.a[e_mst[i].u].y, g.a[e_mst[i].v].x, g.a[e_mst[i].v].y, e_mst[i].w);
	}
}
void MST::computeTopKMST(Graph &g, int K) {
}