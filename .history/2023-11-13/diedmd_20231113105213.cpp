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

const int MAXN = 4e5 + 5;
int n, q, c[MAXN];
vector <int> G[MAXN];

map <int, int> genshin;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("diedmd.in", "r", stdin);
	freopen("diedmd.out", "w", stdout);
#endif
#endif
	read(n), read(q);
	rep (i, 1, n) read(c[i]), genshin[c[i]]++;
	rep (i, 1, n - 1) {
		int u, v; read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	//受不了回滚莫队写不了一点的日子了。
	//妈的这看着就是回滚莫队啊啊啊啊啊啊啊啊啊
	//加好做减不好做不就是回滚莫队板？？？？
	//压成欧拉序不就直接开滚呜呜呜
	//我不会写啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
	//mad 不写了。
	multiset <pair <int, int> > impact;
	for (auto x : genshin) {
		impact.insert(make_pair(x.second, x.first));
	}
	rep (i, 1, q) {
		multiset <pair <int, int> > CTRnmsl;
		int x, y;
		read(x), read(y);
		if (x > y) swap(x, y);
		if (x == 1) {
			for (auto x : impact) {
				if (x.second == c[y]) {
					CTRnmsl.insert(make_pair(x.first + 1, x.second));
					break;
				}
				else CTRnmsl.insert(x);
			}
		}
	}
	return 0;
}