#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e5 + 5;
int n, B, offset, ans, tot;
__gnu_pbds::tree<tuple <int, int>, __gnu_pbds::null_type,
	less<tuple <int, int> >, __gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update> nti, itn;

int dropCnt[MAXN];

void drop() {
	auto [num, id] = *nti.rbegin();
	auto iter = nti.lower_bound(dk(num, id));
	nti.erase(iter);
	iter = itn.lower_bound(dk(id, num));
	itn.erase(iter);
	dropCnt[id]++;
	if (num - 1 > offset) {
		itn.insert(dk(id, num - 1));
		nti.insert(dk(num - 1, id));
	}
	--tot;
}

void putin(int id) {
	++tot;
	bool isInq = 1;
	auto [pid, num] = *itn.lower_bound(dk(id, 0));
	if (id != pid) isInq = 0;
	if (num <= offset) isInq = 0;
	if (!isInq) {
		if (id == pid) {
			itn.erase(itn.lower_bound(dk(id, num)));
			nti.erase(nti.lower_bound(dk(num, id)));
		}
		nti.insert(dk(offset + 1, id));
		itn.insert(dk(id, offset + 1));
	}
	else {
		auto iter = itn.lower_bound(dk(id, 0));
		auto [ignore, num] = *iter;
		itn.erase(iter);
		iter = nti.lower_bound(dk(num, id));
		nti.erase(iter);
		nti.insert(dk(num + 1, id));
		itn.insert(dk(id, num + 1));
	}
	if (tot > B) drop();
}

void transfer() {
	offset++;
	ans += nti.size();
	tot -= nti.size();
	__gnu_pbds::tree<tuple <int, int>, __gnu_pbds::null_type,
	less<tuple <int, int> >, __gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update> T;
	nti.split(dk(offset, 1e9), T);
	nti.swap(T);
}

vector <int> msgs[MAXN];

signed main() {
#ifndef LOCAL
	ignore = freopen("zenless.in", "r", stdin);
	ignore = freopen("zenless.out", "w", stdout);
#endif
	n = read(), B = read();
	rep (i, 1, n) {
		int id = read();
		if (id > 0) msgs[id].emplace_back(i), putin(id);
		else transfer();
	}
	print(ans + tot), puts("");
	rep (i, 1, n) {
		if (msgs[i].size()) {
			rep (j, dropCnt[i], msgs[i].size() - 1) {
				print(msgs[i][j]), putchar(32);
			}
		}
	}
	fprintf(stderr, "%.2lf sec\n", clock() * 1.0 / CLOCKS_PER_SEC);
	return 0;
}
