#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

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

int n, m;
vector <vector <int> > a;

bool check(int x) {
	int maxn = 0;
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (a[i][j] >= x) continue;
			if (j < maxn) return false;
			maxn = max(maxn, j);
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	a.resize(n + 1);
	rep (i, 1, n) a[i].resize(m + 1);
	rep (i, 1, n) rep (j, 1, m) cin >> a[i][j];
	int l = 1, r = n * m, ans = 0, mid = (l + r) >> 1;
	while (l <= r) {
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
		mid = (l + r) >> 1;
	}
	cout << ans;
	return 0; 
}
