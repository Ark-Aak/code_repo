#include<bits/stdc++.h>
#define int long long 
#define ull unsigned long long
using namespace std;
const int N = 1e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
int n, k;
vector<int> e[N];
int vis[N];
void dfs(int x, int f, int l, int r) {
	vis[x] = 1;
	for(auto i : e[x]) {
		if(i == f) continue;
		if(i < l || i > r) continue;
		dfs(i, x, l, r);
	}
}
int f(int l, int r) {
	int cnt = 0;
	for(int i = l; i <= r; i++) {
		if(!vis[i]) dfs(i, -1, l, r), cnt++;
	}
	for(int i = l; i <= r; i++) vis[i] = 0;
	return cnt;
}
signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	read(n); read(k);
	for(int i = 1; i < n; i++) {
		int x, y;
		read(x);
		read(y);
		e[x].emplace_back(y);
		e[y].emplace_back(x);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int x = f(i, j);
			if(k == 2) ans += x * x;
			else ans += x;
		}
	}
	write(ans);
	fast_io :: fls();
	return 0;
}
