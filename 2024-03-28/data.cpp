#include <bits/stdc++.h>

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

const int N = 10;
mt19937 _rnd(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return abs((int) _rnd()) % (r - l + 1) + l; }
int val[N + 5], son[N + 5], ord[N + 5];
int ch[N + 5][2], ocnt;

void dfs(int u) {
	if (ch[u][0]) val[ch[u][0]] = val[u] * 2, dfs(ch[u][0]);
	ord[++ocnt] = u;
	if (ch[u][1]) val[ch[u][1]] = val[u] * 2, dfs(ch[u][1]);
}

signed main() {
	/* freopen("data.in", "w", stdout); */
	rep (i, 2, N) {
		int fa;
		do {
			fa = rnd(1, i - 1);
		} while (son[fa] == 2);
		ch[fa][son[fa]++] = i;
	}
	val[1] = 1;
	dfs(1);
	rep (i, 1, N) cout << ch[i][0] << " " << ch[i][1] << endl;
	cout << 2000 << " " << 1 << endl;
	cout << N << endl;
	rep (i, 1, N) cout << val[ord[i]] << " ";
	return 0;
}
