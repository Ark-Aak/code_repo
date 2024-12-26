#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 2e5 + 5;
int n, m;
pii items[MAXN];
vector <int> ans[MAXN];
priority_queue <pii, vector <pii>, greater <pii> > q1, q2;
int id[MAXN];

signed main() {
	n = read(), m = read();
	rep (i, 1, n) id[i] = i, items[i].fb = read(), items[i].ec = read();
	sort(id + 1, id + 1 + n, [](int a, int b) { return items[a] < items[b]; });
	rep (i, 1, m) q1.push(dl(i, 0));
	rep (i, 1, n) {
		int now = items[id[i]].ec;
		int tim = items[id[i]].fb;
		while (q2.size() && q2.top().ec <= now) {
			auto p = q2.top();
			q2.pop();
			swap(p.ec, p.fb);
			q1.push(p);
		}
		if (q1.size()) {
			auto p = q1.top();
			q1.pop();
			p.fb = now + tim;
			ans[p.ec].push_back(id[i]);
			swap(p.ec, p.fb);
			q2.push(p);
		}
		else {
			auto p = q2.top();
			q2.pop();
			p.ec += tim;
			ans[p.fb].push_back(id[i]);
			q2.push(p);
		}
	}
	rep (i, 1, m) {
		print(ans[i].size()), putchar(32);
		sort(ans[i].begin(), ans[i].end());
		for (auto el : ans[i]) print(el), putchar(32);
		puts("");
	}
	return 0;
}
