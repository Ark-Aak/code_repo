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

#define lowbit(x) ((x) & (-(x)))

const int MAXN = 5e5;

class BIT {
	private:
		int sum[4 * MAXN];
	public:
		void insert(int x, int val) {
			while (x <= 4 * MAXN) sum[x] += val, x += lowbit(x); 
		}
		
		int query(int x) {
			int ans = 0;
  			while (x) ans += sum[x], x -= lowbit(x);
  			return ans;
		}
} sum, suf;

struct Group {
	int x, y;
	bool operator < (const Group &t) const {
		return x == t.x ? y < t.y : x < t.x;
	}
} g[MAXN];

vector <int> H;

void initHash() {
	sort(H.begin(), H.end());
	auto iter = unique(H.begin(), H.end());
	H.erase(iter, H.end());
}

int Hash(int x) {
	return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
}

int n, ans;
bitset <MAXN> pt;
int G[MAXN], fa[MAXN];
set <int> v;

int find(int x) {
	if (x == fa[x]) return x;
	return x = find(fa[x]);
}

void merge(int x, int y) {
	fa[find(y)] = find(x);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n) {
		read(g[i].x), read(g[i].y);
		H.emplace_back(g[i].x), H.emplace_back(g[i].y);
	}
	initHash();
	rep (i, 1, n) {
		g[i].x = Hash(g[i].x);
		g[i].y = Hash(g[i].y);
	}
	sort(g + 1, g + 1 + n);
	rep (i, 1, n) {
		suf.insert(g[i].y, 1);
	}
	rep (i, 1, n) {
		if (sum.query(g[i].y) == 0) pt[i] = 1;
		//else {
		//	if (v.size()) {
		//		auto iter = v.upper_bound(g[i].y);
		//		iter--;
		//		merge(G[*iter], i);
		//	}
		//}
		sum.insert(g[i].y, 1);
		//v.insert(g[i].y);
		//G[g[i].y] = i;
	}
	//rep (i, 1, n) find(i);

	rep (i, 1, n) {
		suf.insert(g[i].y, -1);
		if (suf.query(4 * MAXN) - suf.query(g[i].y - 1) == 0 && pt[i]) {
			ans++;
			//cout << g[i].x << " " << g[i].y << endl;
		}
	}
	cout << ans + (ans == n ? 0 : 1);
	return 0;
}
