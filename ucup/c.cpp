#include <bits/stdc++.h>

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

char res[11];

int ans = 0;

void check(string str, int sum) {
	// cout << str << endl;
	if (str.size() == 0) {
		ans = max(ans, sum);
		return;
	}
	// 枚举并删除连续段
	rep (i, 0, str.size() - 1) {
		int j = i;
		while (j < (int) str.size() && str[j] == str[i]) j++;
		string tmp = str;
		tmp.erase(i, j - i);
		check(tmp, sum + ((j - i) == 3));
		i = j - 1;
	}
}

int fans = 0;

map <string, int> anss;

void dfs(int step, int sx, int sy, int sz) {
	if (step > 9) {
		string a;
		rep (i, 1, 9) a += res[i];
		ans = 0;
		check(a, 0);
		// cout << a << endl;
		fans = max(fans, ans);
		// cout << ans << endl;
		anss[a] = ans;
		return;
	}
	if (sx < 3) {
		res[step] = 'g';
		dfs(step + 1, sx + 1, sy, sz);
	}
	if (sy < 3) {
		res[step] = 'a';
		dfs(step + 1, sx, sy + 1, sz);
	}
	if (sz < 3) {
		res[step] = 'o';
		dfs(step + 1, sx, sy, sz + 1);
	}
}

int n;
int T;

signed main() {
	dfs(1, 0, 0, 0);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T --> 0) {
		string str;
		cin >> str;
		cout << anss[str] << endl;
	}
	return 0;
}
