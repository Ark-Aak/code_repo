#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep (i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 50005;
int n, q, a[MAXN];
vector <int> G[MAXN];
vector <int> h;
bitset <MAXN> bs[MAXN];

int get(int x) { return lower_bound(h.begin(), h.end(), x) - h.begin() + 1; }

void dfs0(int u, int fa) {

}

int main() {
	n = read(), q = read();
	rep (i, 1, n) {
		a[i] = read();
		rep (j, 2, sqrt(a[i])) {
			int cnt = 0;
			while (a[i] % j == 0) {
				a[i] /= j;
				cnt++;
			}
			if (cnt & 1) a[i] *= j;
		}
		h.push_back(a[i]);
	}
	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());
	rep (i, 1, n) a[i] = get(a[i]);
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}

	return 0;
}
