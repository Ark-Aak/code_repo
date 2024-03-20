#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e5 + 5;
vector <int> G[MAXN];
int n, m, a[MAXN], b[MAXN];
int col[MAXN];

void dfs(int u, int c) {
	if (col[u] > 0 && col[u] != c) {
		cout << "No\n";
		exit(0);
	}
	col[u] = c;
	for (auto x : G[u]) {
		if (col[x] == c) {
			cout << "No\n";
			exit(0);
		}
		if (col[x] == 0)
			dfs(x, 3 - c);
	}
}

int main() {
	cin >> n >> m;
	rep (j, 1, m) cin >> a[j];
	rep (j, 1, m) cin >> b[j];
	rep (i, 1, m) G[a[i]].emplace_back(b[i]), G[b[i]].emplace_back(a[i]);
	rep (i, 1, n) if (!col[i]) dfs(i, 1);
	cout << "Yes\n";
	return 0;
}
