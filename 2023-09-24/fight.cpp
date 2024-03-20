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

#define int ll

double qpow(double a, int b) {
	double x = 1;
	while (b) {
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

int n, x;
int a[5000];
double ans;

void dfs(deque <int> q, double chance) {
	if (q.empty()) return;
	if (q.size() == 1 && q.front() == x * 100000) return (void) (ans += chance);
	deque <int> t1, t2;
	t1 = t2 = q;
	double x1 = q.front();
	q.pop_front();
	double x2 = q.front();
	int flg = 0;
	if (x1 > 1e4) flg = -1, x1 /= 1e5;
	if (x2 > 1e4) flg = 1, x2 /= 1e5;
	double c = x1 / (x1 + x2);
	t1.pop_front();
	t2.pop_front();
	t1.pop_front();
	t2.pop_front();
	t1.push_back(flg == 1 ? x2 * 1e5 : x2);
	t2.push_back(flg == -1 ? x1 * 1e5 : x1);
	dfs(t2, chance * c);
	dfs(t1, chance * (1.0 - c));
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("fight.in", "r", stdin);
	freopen("fight.out", "w", stdin);
#endif
#endif
	cin >> n >> x;
	rep (i, 1, n - 1) cin >> a[i];
	if (n <= 8) {
		rep (i, 1, n) {
			deque <int> q;
			rep (j, 1, n) {
				if (j < i) q.push_back(a[j]);
				if (j == i) q.push_back(x * 1e5);
				if (j > i) q.push_back(a[j - 1]);
			}
			dfs(q, 1);
			printf("%.15lf\n", ans);
			ans = 0;
		}
		return 0;
	}
	else {
		rep (i, 1, n) printf("%.15lf\n", qpow(0.5, log2(n)));
	}
	return 0; 
}
