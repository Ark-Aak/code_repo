#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 5e5;

struct Group {
	int x, y;
	bool operator < (const Group &t) const {
		return x == t.x ? y < t.y : x < t.x;
	}
} g[MAXN];

int minl[MAXN], maxr[MAXN];
int n;

int main() {
	cin >> n;
	rep (i, 1, n) cin >> g[i].x >> g[i].y;
	sort(g + 1, g + 1 + n);
	minl[1] = g[1].y;
	rep (i, 2, n) minl[i] = min(minl[i - 1], g[i].y);
	maxr[n] = g[n].y;
	_rep (i, n - 1, 1) maxr[i] = max(maxr[i + 1], g[i].y);
	int ans = 1;
	rep (i, 1, n - 1) if (minl[i] > maxr[i + 1]) ans++;
	cout << ans;
	return 0;
}
