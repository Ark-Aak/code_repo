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

#include <bits/extc++.h>

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

using u32 = unsigned;
struct IO_Tp
{
	const static int _I_Buffer_Size = 30 << 20;
	char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;

	const static int _O_Buffer_Size = 8 << 20;
	char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;

	u32 m[10000];

	IO_Tp()
	{
		constexpr u32 e0 = '\0\0\0\1', e1 = '\0\0\1\0', e2 = '\0\1\0\0', e3 = '\1\0\0\0';
		int x = 0;
		for (u32 i = 0, c0 = '0000'; i != 10; ++i, c0 += e0)
			for (u32 j = 0, c1 = c0; j != 10; ++j, c1 += e1)
				for (u32 k = 0, c2 = c1; k != 10; ++k, c2 += e2)
					for (u32 l = 0, c3 = c2; l != 10; ++l, c3 += e3)
						m[x++] = c3;

		fread(_I_Buffer, 1, _I_Buffer_Size, stdin);
	}
	~IO_Tp() { fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout); }

	IO_Tp &operator>>(int &res)
	{
		while (!isdigit(*_I_pos))
			++_I_pos;
		res = *_I_pos++ - '0';
		while (isdigit(*_I_pos))
			res = res * 10 + (*_I_pos++ - '0');
		return *this;
	}

	IO_Tp &operator<<(int x)
	{
		if (x == 0)
		{
			*_O_pos++ = '0';
			return *this;
		}
		static char _buf[35];
		char *_pos = _buf + 35;
		while (x >= 10000)
			*--reinterpret_cast<u32 *&>(_pos) = m[x % 10000], x /= 10000;
		*--reinterpret_cast<u32 *&>(_pos) = m[x];
		_pos += (x < 1000) + (x < 100) + (x < 10);
		_O_pos = std::copy(_pos, _buf + 35, _O_pos);
		return *this;
	}

	IO_Tp &operator<<(char ch)
	{
		*_O_pos++ = ch;
		return *this;
	}
} IO;

const int MAXN = 1e6 + 5;
int n, q, B;
int a[MAXN], bel[MAXN];

struct query {

	int l, r, id;

	bool operator < (const query &t) const {
		return bel[l] != bel[t.l] ? bel[l] < bel[t.l] : (bel[l] & 1 ? r < t.r : r > t.r);
	}

} que[MAXN];

int cnt[MAXN], vis[MAXN];
int ans = 0, l = 1, r = 0;
int o[MAXN];

void Move(int pos, int flg) {
	if (flg == 1) {
		vis[cnt[a[pos]]]--;
		cnt[a[pos]]++;
		vis[cnt[a[pos]]]++;
		ans = max(ans, cnt[a[pos]]);
	}
	else {
		vis[cnt[a[pos]]]--;
		if (vis[cnt[a[pos]]] == 0 && cnt[a[pos]] == ans) ans--;
		cnt[a[pos]]--;
		vis[cnt[a[pos]]]++;
	}
}

int qcnt = 0;
__gnu_pbds::cc_hash_table <int, int> mp;

signed main() {
	IO >> n >> q;
	rep (i, 1, n) IO >> a[i];
	rep (i, 1, q) {
		int l, r;
		IO >> l >> r;
		if (r - l + 1 <= 100) {
			int ans = 0;
			rep (j, l, r) {
				mp[a[j]]++;
				ans = max(ans, mp[a[j]]);
			}
			mp.clear();
			o[i] = ans;
			continue;
		}
		que[++qcnt].l = (l + 1) / 2;
		que[qcnt].r = (r) / 2;
		que[qcnt].id = i;
	}
	rep (i, 1, n / 2 + 1) a[i] = a[i << 1];
	n = n / 2 + 1;
	B = sqrt(n);
	rep (i, 1, n) bel[i] = (i - 1) / B;
	vis[0] = n;
	sort(que + 1, que + 1 + qcnt);
	rep (i, 1, qcnt) {
		query x = que[i];
		while (l < x.l) Move(l++, -1);
		while (l > x.l) Move(--l, 1);
		while (r < x.r) Move(++r, 1);
		while (r > x.r) Move(r--, -1);
		o[que[i].id] = ans * 2;
	}
	rep (i, 1, q) IO << o[i] << '\n';
	return 0;
}
