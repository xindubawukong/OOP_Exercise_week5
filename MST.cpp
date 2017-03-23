#include"MST.h"
#include"Graph.h"
#include"BCJ.h"
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
#define eps 1e-7

void MST::computeMST() {
	Edge *b = new Edge[23 * 23];
	int cnt = 0;
	for (set<Edge>::iterator it = g->e.begin(); it != g->e.end(); it++)
		b[cnt++] = *it;
	sort(b, b + g->m);
	BCJ *bcj = new BCJ(g->n);
	for (int i = 0; i<g->m; i++)
		if (bcj->getfa(b[i].u) != bcj->getfa(b[i].v)) {
			bcj->hebing(b[i].u, b[i].v);
			e_mst.insert(b[i]);
			length += b[i].w;
		}
	//cout << e_mst.size() << endl;
	delete[] b;
}

class State {
public:
	MST T;
	set<Edge> I, X;
	State(Graph *g = new Graph) :T(MST(g)) {}
	friend bool operator <(const State &a, const State &b) {
		return a.T.length > b.T.length + eps;
	}
};
State tihuan(State tmp) {
}
void MST::computeTopKMST(int K) {
	vector<State> ans;
	priority_queue< pair<double, int> >Q;
	State tmp;
	tmp.T = *this;
	ans.push_back(tmp);
	Q.push(make_pair<tihuan(ans).T.length, 0>);
	while (!Q.empty()) {
		tmp = Q.top().first;
		Q.pop();
		ans.push_back(tmp);
		Q.push(make_pair < tihuan(tmp), ans.size() - 1>);
	}
	/*
	if (ans.size() == K) break;
	if (tmp.I.size() == g->n) continue;
	Edge e;
	for (set<Edge>::iterator it = tmp.T.e_mst.begin(); it != tmp.T.e_mst.end(); it++)
	if (tmp.I.find(*it) == tmp.I.end()) {
	e = *it;
	break;
	}
	tmp.I.insert(e);
	Q.push(tmp);
	tmp.I.erase(e);
	for (set<Edge>::iterator it = g->e.begin(); it != g->e.end(); it++)
	if (tmp.T.e_mst.find(*it) == tmp.T.e_mst.end() && tmp.X.find(*it) == tmp.X.end()) {
	tmp.T.length = tmp.T.length - e.w + (*it).w;
	tmp.T.e_mst.erase(e);
	tmp.T.e_mst.insert(*it);
	tmp.X.insert(e);
	Q.push(tmp);
	break;
	}
	*/
	printf("\n\nThe top %d minimum spanning trees are:\n", min(K, (int)ans.size()));
	for (int i = 0; i < min(K, (int)ans.size()); i++) {
		cout << "  the spanning tree is: " << ans[i].T.length << endl;
		for (set<Edge>::iterator it = ans[i].T.e_mst.begin(); it != ans[i].T.e_mst.end(); it++) {
			printf("   u=(%.3f,%.3f) v=(%.3f,%.3f) w=%.3f\n", g->a[(*it).u].x, g->a[(*it).u].y, g->a[(*it).v].x, g->a[(*it).v].y, (*it).w);
		}
	}
}

void MST::output() {
	cout << "The minimum spanning tree is: " << length << endl;
	//cout << e_mst.size() << endl;
	for (set<Edge>::iterator it = e_mst.begin(); it != e_mst.end(); it++) {
		printf("   u=(%.3f,%.3f) v=(%.3f,%.3f) w=%.3f\n", g->a[(*it).u].x, g->a[(*it).u].y, g->a[(*it).v].x, g->a[(*it).v].y, (*it).w);
	}
}