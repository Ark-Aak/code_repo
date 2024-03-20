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

const int MAXN = 2e5 + 5;

struct Query {
	int t, x, blk, id;
	bool operator < (const Query &t) const {
		if (blk != t.blk) return (this -> t) < t.t;
		if (blk & 1) return x > t.x;
		return x < t.x;
	}
};

vector <Query> query;

struct Modify {
	int x, val, bval;
} modify[MAXN];

vector <int> H;

int Hash(int x) {
	return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
}

struct List {
	int nxt[3 * MAXN], pre[3 * MAXN];

	void insert(int x, int y) {
		pre[nxt[x]] = y;
		nxt[y] = nxt[x];
		nxt[x] = y;
		pre[y] = x;
	}

	void erase(int x) {
		nxt[pre[x]] = nxt[x];
		pre[nxt[x]] = pre[x];
	}
} lst;

int n, m, cnt;

struct Bucket {
	bitset <MAXN> vis;
	int ans;

	void init() {
		rep (i, 1, n) vis[i] = 1;
		ans = 1;
	}

	void add(int x) {
		vis[x] = 1;
		if (vis[x - 1] && vis[x + 1]) ans--;
		if (!vis[x - 1] && !vis[x + 1]) ans++;
	}

	void del(int x) {
		vis[x] = 0;
		if (vis[x - 1] && vis[x + 1]) ans++;
		if (!vis[x - 1] && !vis[x + 1]) ans--;
	}
} counter;

int a[MAXN], blockSize, ans[MAXN];

signed main() {
	read(n), read(m);
	blockSize = ceil(n / sqrt(m) * 4);
	rep (i, 1, n) cin >> a[i], H.emplace_back(a[i]);
	rep (i, 1, m) {
		int op; read(op);
		if (op == 1) {
			int x; read(x);
			query.emplace_back((Query) {i, x, i / blockSize, ++cnt});
		}
		else {
			read(modify[i].x), read(modify[i].val);
			H.emplace_back(modify[i].val);
		}
	}

	sort(H.begin(), H.end());
	auto iter = unique(H.begin(), H.end());
	H.erase(iter, H.end());
	rep (i, 1, n) {
		a[i] = Hash(a[i]);
		lst.insert(a[i] + MAXN, i);
	}
	rep (i, 0, (int) (query.size() - 1)) query[i].x = Hash(query[i].x);
	rep (i, 1, m) if (modify[i].x) {
		modify[i].val = Hash(modify[i].val);
		modify[i].bval = a[modify[i].x];
		a[modify[i].x] = modify[i].val;
	}

	sort(query.begin(), query.end());
	int T = 1, X = 1;
	counter.init();
	for (auto [t, x, _bid, id] : query) {
		while (T < t) {
			if (modify[T].bval >= X) counter.del(modify[T].x);
			lst.erase(modify[T].x);
			lst.insert(modify[T].val + MAXN, modify[T].x);
			if (modify[T].val >= X) counter.add(modify[T].x);
			T++;
		}
		while (T > t) {
			T--;
			if (modify[T].val >= X) counter.del(modify[T].x);
			lst.erase(modify[T].x);
			lst.insert(modify[T].bval + MAXN, modify[T].x);
			if (modify[T].bval >= X) counter.add(modify[T].x);
		}
		while (X < x) {
			for (auto i = lst.nxt[X + MAXN]; i; i = lst.nxt[i]) counter.del(i);
			X++;
		}
		while (X > x) {
			X--;
			for (auto i = lst.nxt[X + MAXN]; i; i = lst.nxt[i]) counter.add(i);
		}
		ans[id] = counter.ans;
	}
	rep (i, 1, cnt) print(ans[i]), putchar(10);
	return 0; 
}
