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

#define int ll

int n, m;
const int MAXN = 5e6 + 5;
int fa[MAXN], prufer[MAXN], deg[MAXN];

void solve_prufer() {
	rep (i, 1, n - 1) cin >> fa[i], deg[fa[i]]++;
	int pos = 1;
	rep (i, 1, n - 2) {
		while (deg[pos]) pos++;
		prufer[i] = fa[pos];
		while (i <= n - 2 && !--deg[prufer[i]] && prufer[i] < pos)
			prufer[i + 1] = fa[prufer[i]], i++;
		pos++;
	}
	int ans = 0;
	rep (i, 1, n - 2) ans ^= i * prufer[i];
	cout << ans;
}

void solve_father() {
	rep (i, 1, n - 2) cin >> prufer[i], deg[prufer[i]]++;
	prufer[n - 1] = n;
	int pos = 1;
	rep (i, 1, n - 1) {
		while (deg[pos]) pos++;
		fa[pos] = prufer[i];
		while (i <= n - 1 && !--deg[prufer[i]] && prufer[i] < pos)
			fa[prufer[i]] = prufer[i + 1], i++;
		pos++;
	}
	int ans = 0;
	rep (i, 1, n - 1) ans ^= i * fa[i];
	cout << ans;
}

signed main() {
	cin >> n >> m;
	if (m == 1) solve_prufer();
	else solve_father();
	return 0; 
}
