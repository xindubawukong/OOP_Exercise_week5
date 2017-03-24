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
pair<State, Edge> tihuan(State tmp) {// return the next tree
	Edge e;
	for (set<Edge>::iterator it = tmp.T.e_mst.begin(); it != tmp.T.e_mst.end(); it++)
		if (tmp.I.find(*it) == tmp.I.end()) {
			e = *it;
			break;
		}
	tmp.T.e_mst.erase(e);
	BCJ *bcj = new BCJ(g->n);
	for (set<Edge>::iterator it = tmp.T.e_mst.begin(); it != tmp.T.e_mst.end(); it++)
		bcj->hebing((*it).u, (*it).v);
	for (set<Edge>::iterator it = tmp.T.g->e.begin(); it != tmp.T.g->e.end(); it++)
		if ()
}
void MST::computeTopKMST(int K) {
	vector<State> ans;
	priority_queue< pair<pair<State, Edge>, int> > Q;
	State tmp;
	tmp.T = *this;
	ans.push_back(tmp);
	Q.push(make_pair(tihuan(tmp), 0));
	while (!Q.empty()) {
		tmp = Q.top().first.first;// get the minimum length from the available trees.
		Edge e = Q.top().first.second;
		int t = Q.top().second;
		Q.pop();
		ans.push_back(tmp);
		if (ans.size() == K) break;
		pair<State, Edge> tmp2 = tihuan(tmp);
		if (tmp2.second.u != 0)
			Q.push(make_pair(tihuan(tmp), ans.size() - 1));
		ans[t].I.insert(e);
		tmp2 = tihuan(ans[t]);
		if (tmp2.second.u != 0)
			Q.push(make_pair(tihuan(tmp), t));
	}
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