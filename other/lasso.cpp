#include <bits/stdc++.h>

//#define int ll
//#define double long double

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 50005;
const double INF = 1e6;
const double SQRT = sqrt(2) / 2.0;

struct edge {
	int nxt, v;
	double c;
} e[10 * MAXN];

int cnt = 1, then[MAXN], dis[MAXN];

queue <int> q;

void _add(int u, int v, double c) { e[++cnt] = (edge) { then[u], v, c }; then[u] = cnt; }
void add(int u, int v, double c) { _add(u, v, c); _add(v, u, 0); }

int S, T, cur[MAXN];

bool dinic_bfs() {
	//fill(dis, dis + MAXN, -1);
	rep (i, 0, T) dis[i] = 5e4;
    queue <int> q;
    dis[S] = 0; q.push(S); cur[S] = then[S];
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = then[x]; i; i = e[i].nxt) {
            int v = e[i].v;
            if (e[i].c > 0 && dis[v] == 5e4) {
                q.push(v);
                cur[v] = then[v];
                dis[v] = dis[x] + 1;
                if(v == T) return 1;
            }
        }
    }
    return 0;
}

double dinic_dfs(int x, double flow) {
    if (x == T) return flow;
    double k, res=0;
    for (int i = cur[x]; i && flow; i = e[i].nxt) {
        cur[x] = i;
        int v = e[i].v;
        if (e[i].c > 0 && (dis[v] == dis[x] + 1)) {
            k = dinic_dfs(v, min(flow, e[i].c));
            if (k == 0) dis[v] = 5e4;
            e[i].c -= k; e[i^1].c += k;
            res += k; flow -= k;
        }
    }
    return res;
}

double dinic(){
	double ans = 0;
	while (dinic_bfs()) {
		//copy(then, then + MAXN, cur);
		//rep (i, 0, T) cur[i] = then[i];
		ans += dinic_dfs(S, INF);
	}
	return ans;
}

int n, m;
string str;
int mp[505][505];

#define _up(x) ((((x) - 1) << 2 | 0) + 1)
#define _dn(x) ((((x) - 1) << 2 | 1) + 1)
#define _lf(x) ((((x) - 1) << 2 | 2) + 1)
#define _rt(x) ((((x) - 1) << 2 | 3) + 1)
#define up(x, y) _up(((x) - 1) * m + (y))
#define dn(x, y) _dn(((x) - 1) * m + (y))
#define lf(x, y) _lf(((x) - 1) * m + (y))
#define rt(x, y) _rt(((x) - 1) * m + (y))

signed main() {
	/* freopen("test.txt", "w", stdout); */
	cin >> n >> m;
	rep (i, 1, n) {
		cin >> str;
		rep (j, 1, m) mp[i][j] = str[j - 1] != '.';
	}
	int cnt = n * m * 4;
	/* cerr << cnt << endl; */
	rep (i, 1, m) {
		/* add(up(1, i), ++cnt, 1); */
		add(++cnt, up(1, i), 1);
		add(S, cnt, INF);
		/* add(dn(n, i), ++cnt, 1); */
		add(++cnt, dn(n, i), 1);
		add(S, cnt, INF);
	}
	rep (i, 1, n) {
		/* add(lf(i, 1), ++cnt, 1); */
		add(++cnt, lf(i, 1), 1);
		add(S, cnt, INF);
		/* add(rt(i, m), ++cnt, 1); */
		add(++cnt, rt(i, m), 1);
		add(S, cnt, INF);
	}
	T = cnt + 1, S = 0;
	/* cerr << cnt << endl; */
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (mp[i][j]) {
				add(up(i, j), T, INF);
				add(dn(i, j), T, INF);
				add(lf(i, j), T, INF);
				add(rt(i, j), T, INF);
			}
			add(up(i, j), lf(i, j), SQRT);
			add(lf(i, j), up(i, j), SQRT);
			add(up(i, j), rt(i, j), SQRT);
			add(rt(i, j), up(i, j), SQRT);
			add(dn(i, j), lf(i, j), SQRT);
			add(lf(i, j), dn(i, j), SQRT);
			add(dn(i, j), rt(i, j), SQRT);
			add(rt(i, j), dn(i, j), SQRT);
			if (j - 1 > 0) {
				add(lf(i, j), rt(i, j - 1), 1);
			}
			if (j + 1 <= m) {
				add(rt(i, j), lf(i, j + 1), 1);
			}
			if (i - 1 > 0) {
				add(up(i, j), dn(i - 1, j), 1);
			}
			if (i + 1 <= n) {
				add(dn(i, j), up(i + 1, j), 1);
			}
		}
	}
	cerr << ::cnt << " " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	printf("%.11lf", dinic());
}
