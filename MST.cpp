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

void show(set<Edge> &S) {
	for (set<Edge>::iterator it = S.begin(); it != S.end(); it++) {
		printf("         %d   %d   %.3f\n", (*it).u, (*it).v, (*it).w);
	}
}
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
pair<State, bool> tihuan(State tmp, Edge e) {
	BCJ *bcj = new BCJ(tmp.T.g->n);
	for (set<Edge>::iterator it = tmp.T.e_mst.begin(); it != tmp.T.e_mst.end(); it++)
		if ((*it) != e) bcj->hebing((*it).u, (*it).v);
	for (set<Edge>::iterator it = tmp.T.g->e.begin(); it != tmp.T.g->e.end(); it++)
		if (tmp.T.e_mst.find(*it) == tmp.T.e_mst.end() && tmp.X.find(*it) == tmp.X.end() && bcj->getfa((*it).u) != bcj->getfa((*it).v)) {
			Edge f = *it;
			tmp.T.e_mst.erase(e);
			tmp.T.e_mst.insert(f);
			tmp.T.length += f.w - e.w;
			return make_pair(tmp, true);
		}
	return make_pair(tmp, false);
}
void MST::computeTopKMST(int K) {
	vector<State> ans;
	State tmp;
	tmp.T = *this;
	ans.push_back(tmp);
	int cnt = 1;
	while (ans.size() < K) {
		double t = 1e18;
		pair<int, Edge> res;
		for (unsigned int i = 0; i < ans.size(); i++)
			for (set<Edge>::iterator it = ans[i].T.e_mst.begin(); it != ans[i].T.e_mst.end(); it++)
				if (ans[i].I.find(*it) == ans[i].I.end()) {
					pair<State, bool> newtree = tihuan(ans[i], *it);
					tmp = newtree.first;
					bool can = newtree.second;
					if (!can) continue;
					if (tmp.T.length < t) {
						t = tmp.T.length;
						res = make_pair(i, *it);
					}
				}
		if (t > 1e18 / 2) break;
		int i = res.first;
		Edge e = res.second;
		tmp = tihuan(ans[i], e).first;
		tmp.X.insert(e);
		ans.push_back(tmp);
		ans[i].I.insert(e);
		cnt++;
	}
	printf("\n\nThe top %d minimum spanning trees are:\n", min(K, (int)ans.size()));
	for (int i = 0; i < min(K, (int)ans.size()); i++) {
		cout << "  the " << i + 1 << "'th spanning tree is: " << ans[i].T.length << endl;
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