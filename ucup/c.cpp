#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
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

vector <pii> edges;
vector <int> G[2000];

int col[2000];

void bfs() {
	queue <int> q;
	q.push(1);
	col[1] = 1;
	while (q.size()) {
		int tp = q.front();
		q.pop();
		for (auto v : G[tp]) {
			if (!col[v]) {
				col[v] = 3 - col[tp];
				q.push(v);
			}
		}
	}
}

signed main() {
	rep (i, 1, 512) {
		rep (j, i + 1, 512) {
			edges.push_back(dl(i * 2 - 1, j * 2));
			edges.push_back(dl(i * 2, j * 2 - 1));
		}
	}
	for (auto [u, v] : edges) {
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout << 1024 << " " << edges.size() << " " << 2 << endl;
	bfs();
	rep (i, 1, 1024) cout << col[i] << " ";
	cout << endl;
	for (auto [x, y] : edges) {
		cout << x << " " << y << endl;
	}
	return 0;
}
