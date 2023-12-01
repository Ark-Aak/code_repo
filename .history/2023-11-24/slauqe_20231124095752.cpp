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

const int MAXN = 30;
int T, n;
int a[MAXN], b[MAXN];
bitset <MAXN> vis;
bool flg = 0;

void dfs(int step) {
	if (step > n) {
		int suma = 0;
		int sumb = 0;
		int tsuma = 0;
		int tsumb = 0;
		rep (i, 1, n) {
			if (vis[i]) suma += a[i];
			if (vis[i]) sumb += b[i];
			if (!vis[i]) tsuma += a[i];
			if (!vis[i]) tsumb += b[i];
		}
		if (suma != tsuma || sumb != tsumb) return;
		return;
	}
	vis[step] = 1;
	dfs(step + 1);
	if (flg) return;
	vis[step] = 0;
	dfs(step + 1);
	if (flg) return;
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("slauqe.in", "r", stdin);
	freopen("slauqe.out", "w", stdout);
#endif
#endif
	
	return 0;
}