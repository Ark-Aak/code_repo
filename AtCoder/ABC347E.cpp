#include <bits/stdc++.h>

#define int ll

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

const int MAXN = 2e5 + 5;
int n, m, siz[MAXN], b[MAXN];

struct node {
	int l, r, id;
};

vector <node> vec;
int ans[MAXN];

signed main() {
	cin >> n >> m;
	rep (i, 1, m) {
		int x;
		cin >> x;
		if (b[x]) {
			siz[i] = siz[i - 1] - 1;
			vec.push_back({b[x], i - 1, x});
			b[x] = 0;
		}
		else {
			siz[i] = siz[i - 1] + 1;
			b[x] = i;
		}
	}
	rep (i, 1, n) if (b[i]) vec.push_back({b[i], m, i});
	rep (i, 1, m) siz[i] += siz[i - 1];
	for (auto [l, r, w] : vec) {
		ans[w] += siz[r] - siz[l - 1];
	}
	rep (i, 1, n) cout << ans[i] << " ";
	return 0;
}
