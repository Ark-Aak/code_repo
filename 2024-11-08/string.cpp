#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
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

int n;
string str;
int cnt[3], pre[3][300005];
map <char, char> chs;
map <char, char> cchs;
int id[3];
bool flg = 0;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
#endif
#endif
	// freopen("data.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> str;
	n *= 3;
	for (auto ch : str) cnt[ch - 'A']++;
	id[0] = 0, id[1] = 1, id[2] = 2;
	sort(id, id + 3, [&](int a, int b) { return cnt[a] < cnt[b]; });
	sort(cnt, cnt + 3);
	chs['A' + id[0]] = 'A', chs['A' + id[1]] = 'B', chs['A' + id[2]] = 'C';
	cchs['A'] = 'A' + id[0], cchs['B'] = 'A' + id[1], cchs['C'] = 'A' + id[2];
	for (auto &ch : str) ch = chs[ch];
	str = ' ' + str;
	rep (i, 1, n) {
		pre[0][i] = pre[0][i - 1] + (str[i] == 'A');
		pre[1][i] = pre[1][i - 1] + (str[i] == 'B');
		pre[2][i] = pre[2][i - 1] + (str[i] == 'C');
	}
	pre[0][n + 1] = pre[0][n], pre[1][n + 1] = pre[1][n], pre[2][n + 1] = pre[2][n];
	if (cnt[0] == cnt[1] && cnt[1] == cnt[2]) return puts("0"), 0;
	const int target = n / 3;
	// cerr << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
rerun:
	rep (i, 1, n) {
		int pos = lower_bound(pre[2] + 1, pre[2] + n + 1, pre[2][i - 1] + target) - pre[2];
		if (pos > n) {
			// cout << "k1" << endl;
			continue;
		}
		int ina = pre[0][pos] + pre[1][i - 1] + pre[2][i - 1];
		if (ina > target) {
			// cout << "k2" << endl;
			continue;
		}
		// cout << i << " " << pos << endl;
		int nxt = lower_bound(pre[2] + 1, pre[2] + n + 1, pre[2][i - 1] + target + 1) - pre[2];
		vector <tuple <int, int, char> > ops;
		// cerr << ina << " " << n - pos << " " << cnt[0] - pre[0][pos] << endl;
		if (ina + (n - pos) >= target && ina + cnt[0] - pre[0][pos] < target) {
			// cerr << "???" << endl;
			// cerr << i << " " << pos << " " << nxt << endl;
			int pp = 0;
			rep (i, pos + 1, nxt) {
				// cerr << i << " " << ina + (n - i + 1) + pre[0][i - 1] - pre[0][pos] << endl;
				if (ina + (n - i + 1) + pre[0][i - 1] - pre[0][pos] == target) {
					pp = i;
					break;
				}
			}
			if (pp == 0) continue;
			if (i - 1 > 0) ops.push_back(dk(1, i - 1, cchs['A']));
			if (pp <= n) ops.push_back(dk(pp, n, cchs['A']));
			cout << ops.size() << endl;
			for (auto op : ops) {
				int l, r; char ch;
				tie(l, r, ch) = op;
				cout << l << " " << r << " " << ch << endl;
			}
			return 0;
		}
		else if (ina + cnt[0] - pre[0][pos] >= target) {
			// cerr << "!!!" << endl;
			int pp = 0;
			rep (i, pos + 1, nxt) {
				// cerr << i << " " << pos << endl;
				if (ina + (pre[0][i - 1] - pre[0][pos]) == target) {
					pp = i;
					break;
				}
			}
			if (pp == 0) continue;
			if (i - 1 > 0) ops.push_back(dk(1, i - 1, cchs['A']));
			if (pp <= n) ops.push_back(dk(pp, n, cchs['B']));
			cout << ops.size() << endl;
			for (auto op : ops) {
				int l, r; char ch;
				tie(l, r, ch) = op;
				cout << l << " " << r << " " << ch << endl;
			}
			return 0;
		}
	}
	if (!flg && cnt[1] == cnt[2]) {
		// cerr << "!?" << endl;
		swap(pre[1], pre[2]);
		flg = 1;
		chs['A' + id[0]] = 'A', chs['A' + id[1]] = 'C', chs['A' + id[2]] = 'B';
		cchs['A'] = 'A' + id[0], cchs['C'] = 'A' + id[1], cchs['B'] = 'A' + id[2];
		goto rerun;
	}
	assert(0);
	cout << "3" << endl;
	cout << 1 << " " << n / 3 << " A" << endl;
	cout << n / 3 + 1 << " " << n / 3 * 2 << " B" << endl;
	cout << n / 3 * 2 + 1 << " " << n << " C" << endl;
	return 0;
}
