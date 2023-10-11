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

int n, m;
int ans[1145141] = {0};
bitset <1145141> vis;

struct Query {
	int x, id;
	bool operator < (const Query &t) const {
		return x < t.x;
	}
} q[1145141];

struct Node {
	int v, id;
	bool operator < (const Node &t) const {
		return v < t.v;
	}
} h[1145141];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("gaze.in", "r", stdin);
	freopen("gaze.out", "w", stdout);
#endif
#endif
	cin >> n >> m;
	rep (i, 1, n) cin >> h[i].v, h[i].id = i;
	h[0].v = -1;
	if (n <= 2000 && m <= 2000) {
		int a, b, c;
		while (m --> 0) {
			cin >> a >> b;
			if (a == 2) cin >> c;
			if (a == 1) {
				int ans = 0, x = b;
				rep (i, 1, n) {
					if (h[i].v >= x && h[i - 1].v < x) ans++;
				}
				cout << ans << endl;
			}
			else {
				h[b].v = c;
			}
		}
	}
	else {
		vis.set();
		vis[0] = 0, vis[n + 1] = 0;
		rep (i, 1, m) {
			int tmp;
			cin >> tmp;
			cin >> q[i].x;
			q[i].id = i;
		}
		sort(q + 1, q + 1 + m);
		sort(h + 1, h + 1 + n);
		int Ans = 1;
		int r = 1;
		rep (i, 1, m) {
			while (r <= n && h[r].v < q[i].x) {
				int ind = h[r].id;
				if (vis[ind - 1] && vis[ind + 1]) Ans++;
				if ((!vis[ind - 1]) && (!vis[ind + 1])) Ans--;
				vis[ind] = 0;
				++r;
			}
			ans[q[i].id] = Ans;
			//cout << Ans << endl;
		}
		rep (i, 1, m) cout << (ans[i]) << endl;
	}
	return 0; 
}
