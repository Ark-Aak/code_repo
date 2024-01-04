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

int n;
int perm[20];
pair <int, int> ball[20];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
#endif
#endif
	cin >> n;
	rep (i, 1, n << 1) perm[i] = i;
	rep (i, 1, n << 1) cin >> ball[i].first >> ball[i].second;
	int ans = 0;
	do {
		set <int> col[20], row[20];
		rep (i, 1, n << 1) col[ball[i].first].insert(ball[i].second);
		rep (i, 1, n << 1) row[ball[i].second].insert(ball[i].first);
		int cnt = 0;
		rep (i, 1, n << 1) {
			if (perm[i] > n) {
				int x, y;
				y = perm[i] - n;
				if (row[y].empty()) continue;
				x = *row[y].begin();
				col[x].erase(y);
				row[y].erase(x);
				cnt++;
			}
			else {
				int x, y;
				x = perm[i];
				if (col[x].empty()) continue;
				y = *col[x].begin();
				col[x].erase(y);
				row[y].erase(x);
				cnt++;
			}
		}
		if (cnt == (n << 1)) ans++;
	} while (next_permutation(perm + 1, perm + 1 + (n << 1)));
	cout << ans << endl;
	return 0;
}
