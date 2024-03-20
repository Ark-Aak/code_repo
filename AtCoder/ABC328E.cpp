#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _tp>
void read(_tp& first) {
	_tp x = 0, f = 1; char c = getchar();
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

template <typename _tp>
void print(_tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

int n, m, k;

const int N = 10, M = 35;
tuple <int, int, int> isl[M];
int s[N], fa[N];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
bool merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return false;
	fa[fx] = fy;
	return true;
}

int ans = 4e18;

signed main() {
	cout << LONG_LONG_MAX;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		isl[i] = make_tuple(u, v, w);
	}
	for (s[1] = 1; s[1] <= 28; s[1]++)
	for (s[2] = s[1] + 1; s[2] <= 28; s[2]++)
	for (s[3] = s[2] + 1; s[3] <= 28; s[3]++)
	for (s[4] = s[3] + 1; s[4] <= 28; s[4]++)
	for (s[5] = s[4] + 1; s[5] <= 28; s[5]++)
	for (s[6] = s[5] + 1; s[6] <= 28; s[6]++)
	for (s[7] = s[6] + 1; s[7] <= 28; s[7]++) {
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		bool flg = 0;
		for (int i = 1; i <= n - 1; i++)
			if (s[i] > m) flg = 1;
		if (flg) continue;
		int sum = 0;
		for (int i = 1; i <= n - 1; i++) {
			sum += get <2>(isl[s[i]]);
			if (merge(get <0>(isl[s[i]]), get <1>(isl[s[i]]))) continue;
			flg = 1;
			break;
		}
		if (!flg) ans = min(sum % k, ans);
	}
	cout << ans;
	return 0;
}