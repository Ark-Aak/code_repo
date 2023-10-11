#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = a; i <= b; i++)
#define R(i, a, b) for (int i = a; i >= b; i--)

#define mk(a, b) make_pair(a, b)
#define inv(x) ksm(x, Mod - 2)
#define mem(a, b) memset(a, b, sizeof a)

#define De(x) cerr << "------------------" << x << "--------------" << endl
#define Debug() cerr << "----------------------------------------" << endl
#define lson(x) x << 1
#define rson(x) x << 1 | 1

const int N = 2e5 + 5, TN = 1e6 + 5, Mod = 1e9 + 7, inf = INT_MAX, Inf = LONG_LONG_MAX;
inline int ksm(int a, int b);
inline int read();
string s;
int T = 1, n, m, a[N], head[N], nxt[N], to[N], tot, val;

bool vis[N], vis1[N];

inline void AddEdge(int u, int v) {
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

inline void Run(int u) {
	vis[u] = 1;
	for (int i = head[u]; i; i = nxt[i]) {
		if (vis[to[i]] || !vis1[to[i]]) continue;
		Run(to[i]);
	}
}

inline int gx(int x) {
	if (1 == m) return x;
	if (2 == m) return x * x;
	return 1;
}

inline int Mod1(int x) {
	if (x > Mod) x -= Mod;
	return x;
}

inline void Subtask1() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i;  j <= n; j++) {
			val = 0;
			vis1[j] = 1;
			for (int k = i; k <= j; k++) {
				if (vis[k]) {
					continue;
				} else Run(k), val++;
			}
			for(int k = i;k<=j;k++) vis[k]=0;
			ans = ans + gx(val);
			ans = Mod1(ans);
		}
		for (int j = 1; j <= n; j++) vis1[j] = 0;
	}
	cout << ans;
	return;
}

signed main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	while (T--) {
		n = read(), m = read();
		F(i, 1, n - 1) {
			int u, v;
			u = read(), v = read();
			AddEdge(u, v), AddEdge(v, u);
		}
		if (n <= 700) {
			Subtask1();
			return 0;
		}
	}
	return 0;
}
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			f *= -1;
		c = getchar();
	}
	while (c <= '9' && c >= '0') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline int ksm(int a, int b) {
	int aa = 1;
	while (b) {
		if (b & 1)
			aa *= a, aa %= Mod;
		a *= a;
		a %= Mod;
		b >>= 1;
	}
	return aa;
}
