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

#define int ll
#define mp make_pair

const int MAXN = 2e3 + 5;
int n, A, B, C;

struct node {
	int a, t;
} it[MAXN];

bool check(int x) {
	deque <pair <int, int> > q;
	q.push_back(mp(0, x));
	rep (i, 1, n) {
		int t = it[i].t, a = it[i].a;
		while (a) {
			auto im = q.front(); q.pop_front();
			if (im.first > t - A) return false;
			else {
				int siz = im.second;
				if (siz <= a) a -= siz, q.push_back(mp(max(im.first, t - B - A) + A + C, siz));
				else q.push_front(mp(im.first, siz - a)), q.push_back(mp(max(im.first, t - B - A) + A + C, a)), a = 0;
			}
		}
	}
	return true;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);
#endif
#endif
	read(n), read(A), read(B), read(C);
	rep (i, 1, n) {
		read(it[i].t), read(it[i].a);
		it[i].t += A + B;
	}
	sort(it + 1, it + 1 + n, [](node a, node b) {
		return a.t < b.t;
	});
	int l = 0, r = 1e13, mid, ans = 1e13;
	while (l < r) {
		mid = (l + r) >> 1;
		if (check(mid)) r = mid, ans = min(ans, mid);
		else l = mid + 1;
	}
	print(ans);
	return 0;
}
