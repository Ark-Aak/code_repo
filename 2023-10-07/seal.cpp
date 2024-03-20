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

const int MAXN = 5005;
int a[MAXN], b[MAXN];
int n, t, m;
pair <int, int> axis[MAXN];

namespace Hash {
	vector <int> H;

	void init() {
		sort(H.begin(), H.end());
		auto iter = unique(H.begin(), H.end());
		H.erase(iter, H.end());
	}

	int Hash(int x) {
		return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
	}

	int get(int x) {
		return H[x - 1];
	}
}

namespace DFS {
	int sp[MAXN], fans = 0;

	void dfs(int step, int lst, int cnt) {
		if (cnt > m) return;
		if (step > m) {
			if (cnt != m) return;
			int siz = Hash::H.size();
			int ans = 0, st = 1;
			rep (i, 1, siz - 1) {
				if (!st) ans += Hash::get(i) - Hash::get(i - 1);
				int stat = axis[i].second;
				int p = axis[i].first;
				if (!stat) {
					if (!p) st = 0;
					if (p) {
						if (axis[i + 1].second == 1 && (!sp[axis[i + 1].first])) {
							st = 0;
						}
						else st = 1;
					}
				}
				else {
					if (axis[i + 1].second == 1 && (!sp[axis[i + 1].first])) {
						st = 0;
					}
					else st = 1;
				}
			}
			fans = max(fans, t - ans);
			return;
		}
		rep (i, lst, n) {
			sp[i] = 1;
			dfs(step + 1, i + 1, cnt + 1);
			sp[i] = 0;
			dfs(step + 1, i + 1, cnt);
		}
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("seal.in", "r", stdin);
	freopen("seal.out", "w", stdout);
#endif
#endif
	read(n), read(t), read(m);
	rep (i, 1, n) {
		read(a[i]), read(b[i]);
		Hash::H.emplace_back(a[i]);
		Hash::H.emplace_back(b[i]);
	}
	Hash::init();
	rep (i, 1, n) {
		int ai = Hash::Hash(a[i]);
		int bi = Hash::Hash(b[i]);
		axis[ai].first = i, axis[ai].second = 0;
		axis[bi].first = i, axis[ai].second = 1;
	}
	DFS::dfs(1, 1, 0);
	cout << DFS::fans;
	return 0; 
}
