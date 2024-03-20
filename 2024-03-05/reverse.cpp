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

const int MAXN = 1e5 + 5;
int T, n, a[MAXN];
vector <int> op_seq;

void Reverse(int l, int r) {
	for (int i = l, j = r; i < j; i++, j--)
		swap(a[i], a[j]);
}

void BasicOperation(int x) {
	op_seq.push_back(x);
	Reverse(1, x - 1);
	Reverse(x + 1, n);
}

void ReverseOperation(int l, int r) {
	op_seq.push_back(l);
	op_seq.push_back(l + n -r + 1);
	op_seq.push_back(n - r + 1);
}

int cnt[MAXN], pos[MAXN], tpos[MAXN];

bool check() {
	bool res = 0;
	int posi = -1, posj = -1;
	memset(cnt, 0, sizeof cnt);
	rep (i, 1, n) {
		cnt[a[i]]++;
		if (cnt[a[i]] > 1 && posi == -1) posi = i;
	}
	rep (i, 1, posi - 1) if (a[i] == a[posi]) posj = i;
	rep (i, 1, n) cnt[i] += cnt[i - 1];
	rep (i, 1, n) a[i] = cnt[a[i]]--;
	rep (i, 1, n) pos[a[i]] = i, tpos[i] = a[i];
	rep (i, 1, n) {
		if (pos[i] == i) continue;
		swap(tpos[pos[i]], tpos[i]);
		swap(pos[tpos[pos[i]]], pos[i]);
		res ^= 1;
	}
	if (res && posj != -1) {
		swap(a[posi], a[posj]);
		return 0;
	}
	return res;
}

void work(bool flg = 0) {
	rep (i, 1, n) pos[a[i]] = i;
	rep (i, 1, n) {
		if (pos[i] == i) continue;
		if (flg) ReverseOperation(n - pos[i] + 1, n - i + 1);
		else ReverseOperation(i, pos[i]);
		flg ^= 1;
		swap(a[pos[i]], a[i]);
		swap(pos[a[pos[i]]], pos[i]);
	}
}

void solve() {
	op_seq.clear();
	n = read();
	rep(i, 1, n) a[i] = read();
	if (check()) {
		if (n % 4 == 1) BasicOperation(2);
		else if (n % 4 == 2) {
			puts("-1");
			return;
		}
		else BasicOperation(1);
	}
	work();
	print(op_seq.size()), putchar(10);
	for (auto v : op_seq) print(v), putchar(32);
	putchar(10);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("reverse.in", "r", stdin);
	freopen("reverse.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
