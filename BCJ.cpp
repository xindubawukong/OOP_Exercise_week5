#include"BCJ.h"
#include<cstring>
BCJ::BCJ(int n) {
	for (int i = 0; i < n; i++) fa[i] = i;
}
int BCJ::getfa(int x) {
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
void BCJ::hebing(int x, int y) {
	fa[getfa(x)] = getfa(y);
}