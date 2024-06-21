#include <bits/stdc++.h>

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

int n, T, perm[20];
string s;

void solve() {
	cin >> n >> s;
	rep (i, 1, n) perm[i] = i;
	list <vector <int> > lst;
	do {
		vector <int> p;
		rep (i, 1, n) p.push_back(perm[i]);
		lst.push_back(p);
	} while (next_permutation(perm + 1, perm + 1 + n));
	rep (i, 0, n - 2) {
		char c = s[i];
		if (c == '<') {
			for (auto it = lst.begin(); it != lst.end(); ) {
				vector <int> val = *it;
				bool flg = val[i] > val[i + 1];
				if (flg) it = lst.erase(it);
				else ++it;
			}
		}
		else {
			for (auto it = lst.begin(); it != lst.end(); ) {
				vector <int> val = *it;
				bool flg = val[i] < val[i + 1];
				if (flg) it = lst.erase(it);
				else ++it;
			}
		}
	}
	cout << fixed << setprecision(10) << log2(lst.size()) << endl;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) solve();
	return 0;
}
