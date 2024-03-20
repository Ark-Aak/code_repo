#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

int n, t, a[200005], b[200005];
int v[200005], cnt, ans;
map <int, vector <pii> > mp;
map <int, int> V;

signed main() {
	n = read(), t = read();
	rep (i, 1, t) {
		a[i] = read(), b[i] = read();
		mp[i].push_back(dl(a[i], b[i]));
	}
	rep (i, 1, n) v[0]++, V[0]++, cnt = 1;
	rep (i, 1, t) {
		for (auto [x, y] : mp[i]) {
			V[v[x]]--;
			if (V[v[x]] == 0) cnt--;
			V[v[x] + y]++;
			if (V[v[x] + y] == 1) cnt++;
			v[x] += y;
		}
		print(cnt), putchar(10);
	}
	return 0;
}
