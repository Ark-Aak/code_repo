#include <bits/stdc++.h>
#define int long long
using namespace std;
template <typename T>
void read(T &x)
{
	char ch = getchar();
	int fl = 1;
	x = 0;
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')
			fl = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0')
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	x *= fl;
}
template <typename T, typename... Args>
void read(T &x, Args &...args)
{
	read(x);
	read(args...);
}
const int N = 1e5 + 5, B = 32;
int n, q, a[N];
struct basis
{
	int ops; // 0取小的,1取大的
	int p[B], d[B];
	void Init()
	{
		for (int i = 0; i < B; i++)
			p[i] = d[i] = 0;
		return;
	}
	void add(int x, int y)
	{
		for (int i = B - 1; i >= 0; i--)
			if ((x >> i) & 1)
			{
				if (!p[i])
					return p[i] = x, d[i] = y, void();
				if ((ops == 0 && y < d[i]) || (ops == 1 && y > d[i]))
					swap(p[i], x), swap(d[i], y);
				x ^= p[i];
			}
	}
} close[N], far[N], f, g;
void add(basis &A, int s)
{
	for (int i = 0; i < B; i++)
		if (A.p[i])
			A.d[i] += s;
}
void add(basis &X, basis Y, int s = 0)
{
	for (int i = 0; i < B; i++)
		if (Y.p[i])
			X.add(Y.p[i], Y.d[i] + s);
}
vector<int> v[N], to[N];
void dfs1(int x, int fa)
{
	close[x].add(a[x], 0), far[x].add(a[x], 0);
	for (auto y : v[x])
	{
		if (y == fa)
			continue;
		to[x].push_back(y);
		dfs1(y, x);
		add(close[x], close[y], 1), add(far[x], far[y], 1);
	}
}
void dfs2(int x, int fa)
{
	add(f, 1), add(close[x], close[fa], 1), add(far[x], f), f.add(a[x], 0);
	if (!to[x].size())
		return;
	basis tmp = f;
	basis last[to[x].size() + 1];
	last[to[x].size()].Init(), g.Init();
	for (int i = to[x].size() - 1; i >= 0; i--)
		add(g, far[to[x][i]], 1), last[i] = g;
	basis pre[to[x].size() + 1];
	pre[0].Init(), g.Init();
	for (int i = 0; i < to[x].size(); i++)
		add(g, far[to[x][i]], 1), pre[i + 1] = g;
	for (int i = 0; i < to[x].size(); i++)
		f = tmp, add(f, pre[i]), add(f, last[i + 1]), dfs2(to[x][i], x);
	return;
}
void sol(int x, int y, int l, int r)
{
	basis tmp;
	tmp.Init();
	for (int i = 0; i < B; i++)
		if (close[x].d[i] < l)
			tmp.add(close[x].p[i], close[x].d[i]);
	for (int i = 0; i < B; i++)
		if (far[x].d[i] > r)
			tmp.add(far[x].p[i], far[x].d[i]);
	for (int i = B - 1; i >= 0; i--)
		if ((y >> i) & 1)
			y ^= tmp.p[i];
	if (y == 0)
		putchar('c'), putchar('i'), putchar('a'), putchar('l'), putchar('l'), putchar('o'), putchar('\n');
	else
		putchar('N'), putchar('O'), putchar('\n');
}
signed main()
{
	//	freopen("ciallo.in","r",stdin);
	//	freopen("ciallo.out","w",stdout);
	f.ops = g.ops = 1;
	for (int i = 0; i < N; i++)
		far[i].ops = 1;
	read(n, q);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1, x, y; i < n; i++)
		read(x, y), v[x].push_back(y), v[y].push_back(x);
	dfs1(1, 0), dfs2(1, 0);
	int x, y, l, r;
	while (q--)
		read(x, y, l, r), sol(x, y, l, r);
	return 0;
}