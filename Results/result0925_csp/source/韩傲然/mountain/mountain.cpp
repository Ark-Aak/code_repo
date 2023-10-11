#include<bits/stdc++.h>
#define int long long 
#define ull unsigned long long
using namespace std;
const int N = 1e6 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)
namespace fast_io {
	int it, ed, c, f, ot;
	char t, stk[20], bf[N + 50], ob[N + 50];
#define gc (it == ed && (ed = (it = 0) + fread(bf, 1, N, stdin), it == ed)) ? EOF : bf[it++]
	template <typename T> inline void read(T &x) {
		for (c = gc; c < 48; c = gc);
		for (x = 0; c > 47; x = x * 10 + (48 ^ c), c = gc); return ;
	} inline void fls() { fwrite(ob, 1, ot, stdout), ot = 0; }
	inline void write(int x) {
		while (x > 9) stk[++t] = 48 ^ (x % 10), x /= 10;
		for (ob[ot++] = 48 ^ x; t; ob[ot++] = stk[t--]);
		ob[ot++] = '\n'; if (ot > N) fls(); return ;
	}
} using fast_io::read; using fast_io::write;
int n;
int h[N];
int t[N], top, ans[N], cnt[N];
signed main() {
	freopen("mountain.in", "r", stdin);
	freopen("mountain.out", "w", stdout);
	read(n);
	h[0] = inf, h[n + 1] = inf;
	for(int i = 1; i <= n; i++) read(h[i]);
	for(int i = 0; i <= n; i++) {
		cnt[i] = 1;
		while(top && h[t[top]] < h[i]) top--, ans[i]++;
		if(h[t[top]] == h[i]) ans[i] += cnt[t[top]], cnt[i] = cnt[t[top]] + 1;
		t[++top] = i;
	}
	memset(cnt, 0, sizeof(cnt));
	top = 0;
	for(int i = n + 1; i >= 1; i--) {
		cnt[i] = 1;
		while(top && h[t[top]] < h[i]) top--, ans[i]++;
		if(h[t[top]] == h[i]) ans[i] += cnt[t[top]], cnt[i] = cnt[t[top]] + 1;
		t[++top] = i;
	}
	for(int i = 1; i <= n; i++) {
		write(ans[i]);
		//cerr << ans[i] << "\n";
	}
	fast_io :: fls();
	return 0;
}
