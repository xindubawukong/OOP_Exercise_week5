#ifndef BCJ_h
#define BCJ_h
class BCJ {
private:
	int fa[23];
public:
	BCJ(int n);
	int getfa(int x);
	void hebing(int x, int y);
};
#endif