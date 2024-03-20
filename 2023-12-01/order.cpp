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

const int MAXN = 300 + 5;
int n, a[MAXN], b[MAXN], id[MAXN];
int f[MAXN][MAXN];
int len;

vector <int> H;

void init() {
	sort(H.begin(), H.end());
	H.erase(unique(H.begin(), H.end()), H.end());
	len = H.size();
}

int find(int x) {
	return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("order.in", "r", stdin);
	freopen("order.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n) {
		read(a[i]), read(b[i]);
		H.emplace_back(b[i]); id[i] = i;
	}
	sort(id + 1, id + 1 + n, [](int aa, int bb) {return b[aa] < b[bb];});
	init();
	memset(f, 0x3f, sizeof f);
	memset(f[0], 0, sizeof f[0]);
	rep (i, 1, n) b[i] = find(b[i]);
	rep (i, 1, n) {
		_rep (j, i, 1) {
			rep (k, 1, b[id[i]]) {
				f[j][b[id[i]]] = min(f[j][b[id[i]]], f[j - 1][k] + a[id[i]]);
			}
		}
	}
	int ans = 0;
	rep (i, 1, n) {
		ans = 1e18;
		rep (j, 1, len) {
			//cout << f[i][j] << " ";
			ans = min(ans, f[i][j] + H[j - 1]);
		}
		print(ans);
		putchar(10);
	}
	return 0;
}
