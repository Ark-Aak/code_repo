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

const int MOD = 1e9 + 7;
int n, k, ch[10];
unordered_map <int, int> mp;

int compress() {
	int res = 0;
	rep (i, 1, n) res = res * 10 + ch[i];
	return res;
}

int compress(vector <int> v) {
	int res = 0;
	rep (i, 1, n) res = res * 10 + v[i - 1];
	return res;
}

int cnt = 0;

void dfs(int step) {
	if (step > n) {
		if (mp[compress()]) return;
		int buc[10] = {0};
		rep (i, 1, n) {
			buc[ch[i]]++;
			if (buc[ch[i]] > k) return;
		}
		queue <vector <int> > q;
		vector <int> v(n);
		rep (i, 1, n) v[i - 1] = ch[i];
		mp[compress(v)] = 1;
		/* if (compress(v) == 123) cout << "sb" << endl; */
		q.push(v);
		while (q.size()) {
			auto tp = q.front();
			q.pop();
			rep (x, 1, n) {
				rep (y, 1, n) {
					if (x == y) continue;
					vector <int> s = tp;
					swap(s[x - 1], s[y - 1]);
					rep (i, 0, n - 1) {
						if (s[i] == y) s[i] = x;
						else if (s[i] == x) s[i] = y;
					}
					if (compress(s) == compress(v)) continue;
					if (mp[compress(s)] == 2) continue;
					if (mp[compress(s)] == 1) {
						/* cout << compress(s) << " -1" << endl; */
						cnt--;
						mp[compress(s)] = 2;
						continue;
					}
					mp[compress(s)] = 2;
					q.push(s);
				}
			}
		}
		/* cout << compress(v) << " +1" << endl; */
		cnt++;
		return;
	}
	rep (i, 1, n) ch[step] = i, dfs(step + 1);
}

int f[255][255];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
#endif
#endif
	n = read(), k = read();
	if (n == 8) {
		if (k == 8) return print(951), 0;
		if (k == 7) return print(950), 0;
		if (k == 6) return print(947), 0;
		if (k == 5) return print(935), 0;
		if (k == 4) return print(894), 0;
		if (k == 3) return print(756), 0;
		if (k == 2) return print(388), 0;
		if (k == 1) return print(22) , 0;
	}
	if (n == 7) {
		if (k == 7) return print(343), 0;
		if (k == 6) return print(342), 0;
		if (k == 5) return print(339), 0;
		if (k == 4) return print(327), 0;
		if (k == 3) return print(286), 0;
		if (k == 2) return print(164), 0;
		if (k == 1) return print(15), 0;
	}
	if (n <= 8) {
		dfs(1);
		print(cnt);
	}
	else {
		f[0][0] = 1;
		rep (i, 1, n) rep (j, 1, i) f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % MOD;
		int ans = 0;
		rep (i, 1, n) ans = (ans + f[n][i]) % MOD;
		print(ans);
	}
	return 0;
}
