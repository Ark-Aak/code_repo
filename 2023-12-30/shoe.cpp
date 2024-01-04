#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

#define int ll

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

#define INF 1e12

const int MAXN = 20005;

struct edge{
	int nxt, u, v;
	ll c;
} e[10 * MAXN];

int cnt = 1, then[MAXN], dis[MAXN];

queue<int> q;

void _add(int u, int v, ll c){e[++cnt]=(edge){then[u], u, v, c}; then[u]=cnt;}
void add(int u, int v, ll c){_add(u, v, c); _add(v, u, 0);}

int S, T = 1e4 + 5, cur[MAXN];

bool dinic_bfs(){
	fill(dis, dis + MAXN, -1);
	dis[S] = 0; q.push(S);
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int u = then[t]; u; u = e[u].nxt){
			if(e[u].c > 0 && dis[e[u].v] == -1){
				dis[e[u].v] = dis[t] + 1;
				q.push(e[u].v);
			}
		}
	}
	return dis[T] != -1;
}

ll dinic_dfs(int x, ll flow){
	if(x == T) return flow;
	ll rf = flow;
	for(int &u = cur[x]; u; u = e[u].nxt){
		if(rf <= 0) break;
		cur[x] = u;
		ll rf_x = e[u].c;
		if(rf_x > 0 && dis[e[u].v] > dis[x]){
			ll transfer = dinic_dfs(e[u].v, min(rf_x, rf));
			rf -= transfer;
			e[u].c -= transfer;
			e[u ^ 1].c += transfer;
		}
	}
	return flow - rf;
}

ll dinic(){
	ll ans = 0;
	while(dinic_bfs()){
		copy(then, then + MAXN, cur);
		ans += dinic_dfs(S, INF);
	}
	return ans;
}

int n, m;
int a[105][105];
int wx[4] = {0, 0, 1, -1};
int wy[4] = {1, -1, 0, 0};

inline int num(int X,int Y) {
	return (X - 1) * m + Y;
}

signed main() {
	cin >> n >> m;
	rep (i, 1, n) {
		rep (j, 1, m) {
			char c;
			cin >> c;
			if (c == 'R') a[i][j] = 1;
		}
	}
	rep (i, 1, n) {
		rep (j, 1, m) {
			if ((i + j) & 1) {
				add(S, num(i, j), 1);
				rep (k, 0, 3) {
					int nx = i + wx[k], ny = j + wy[k];
					if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
						if (a[i][j] ^ a[nx][ny]) add(num(i, j), num(nx, ny), 1);
					}
				}
			}
			else add(num(i, j), T, 1);
		}
	}
	int ans = dinic();
	if (ans * 2 < n * m) {
		return print(ans), 0;
	}
	int sum = 0;
	rep (i, 1, n) {
		rep (j, 1, m) {
			char c;
			cin >> c;
			if (c == 'R') ++sum;
			if (c == 'D') ++sum, ++sum;
			if (c == 'L') ++sum, ++sum, ++sum;
		}
	}
	for (int i = 2; i <= cnt; i += 2) {
		if (e[i].c) continue;
		if (!e[i].u) continue;
		if (e[i].v == T) continue;
		int u = e[i].u, v = e[i].v;
		int X1 = (u - 1) / m + 1, Y1 = u - (X1 - 1) * m;
		int X2 = (v - 1) / m + 1, Y2 = v - (X2 - 1) * m;
		if (Y1 == Y2) sum -= 2;
	}
	sum %= 4;
	if (sum) print(ans - 1);
	else print(ans);
}
