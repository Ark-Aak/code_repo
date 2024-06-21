#include "testlib.h"
#include <functional>

const int N = 300'005;

namespace RMQLCA
{
	int R, lg[N * 2], pt[N], dep[N * 2];
	int fa[20][N * 2], euler[N * 2], dis[N];
	std::vector<int> g[N];

	void addEdge(int x, int y)
	{
		g[x].push_back(y); g[y].push_back(x);
		return ;
	}

	void dfs(int x, int f, int deep)
	{
		pt[x]=++R; euler[R]=x; dep[R]=deep; dis[x]=deep;
		for (int v : g[x])
			if (v != f)
			{
				dfs(v, x, deep + 1);
				euler[++R]=x; dep[R]=deep;
			}
		return ;
	}

	void prepare()
	{
		dfs(1, -1, 0);
		for (int i = 1; i <= R; i++) fa[0][i] = i;
		for (int i = 2; i <= R; i++) lg[i] = lg[i >> 1] + 1;
		for (int j = 1; j <= lg[R]; j++)
			for (int i = 1; i + (1 << j) - 1 <= R; i++)
			{
				int a = fa[j - 1][i], b = fa[j - 1][i + (1 << (j - 1))];
				fa[j][i] = dep[a] <= dep[b] ? a : b;
			}
		return ;
	}

	int getLCA(int x, int y)
	{
		x = pt[x]; y = pt[y];
		if (x > y) std::swap(x, y);
		int t = lg[y - x + 1];
		int a = fa[t][x], b = fa[t][y - (1 << t) + 1];
		return dep[a] <= dep[b] ? euler[a] : euler[b];
	}

	int getDis(int x, int y)
	{
		return dis[x] + dis[y] - 2 * dis[getLCA(x, y)];
	}
}

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int n = inf.readInt();
	int m = inf.readInt();
	long long jans = ans.readLong();
	long long pans = ouf.readLong();
	quitif(jans < pans, _wa, "wrong time consumed");
	std::vector<int> order = ouf.readInts(2 * m, 1, m, "order");
	std::vector<bool> vis(m, false);
	for (int i = 0; i < 2 * m; i += 2)
	{
		int r = order[i];
		if (vis[r - 1])
			quitp(30, "visit restaurant %d twice", r);
		vis[r - 1] = true;
	}
	std::fill(vis.begin(), vis.end(), false);
	for (int i = 1; i < 2 * m; i += 2)
	{
		int r = order[i];
		if (vis[r - 1])
			quitp(30, "visit pastry shop %d twice", r);
		vis[r - 1] = true;
	}
	std::vector<int> restaurants = inf.readInts(m);
	std::vector<int> pastrys = inf.readInts(m);
	using namespace RMQLCA;
	for (int i = 1; i < n; i++)
	{
		int u = inf.readInt();
		int v = inf.readInt();
		addEdge(u, v);
	}
	prepare();
	int now = 1; long long ans = 0;
	for (int i = 0; i < 2 * m; i++)
	{
		int nxt;
		if (i & 1)
			nxt = pastrys[order[i] - 1];
		else
			nxt = restaurants[order[i] - 1];
		ans += getDis(now, nxt);
		now = nxt;
	}
	if (now != 1)
		ans += getDis(now, 1);
	if (ans != pans)
	{
		if (pans == jans)
			quitp(30, "wrong order");
		quitf(_wa, "wrong order");
	}
	quitif(jans > pans, _fail, "participant has better solution");
	quitf(_ok, "ok");
	return 0;
}