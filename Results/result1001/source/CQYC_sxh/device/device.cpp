#include <bits/stdc++.h>

//#pragma GCC optimize(2)
#define For(x, y, z) for (int x = y; x <= z; ++x)
#define Rof(x, y, z) for (int x = y; x >= z; --x)
#define Eor(u) for (int i = head[u]; i; i = nxt[i])
#define SZ(x) (int(x.size()))
#define pb push_back

using namespace std;
using i64 = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

// char buf[(1<<21)+5],*p1,*p2;
// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

inline int read() {
	int x = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}
int __stk[128], __tp;
inline void put(i64 x) {
	if (x < 0) putchar('-'), x = -x;
	do { __stk[++__tp] = x % 10, x /= 10; } while (x);
	while (__tp) putchar(__stk[__tp--] + '0');
}

const int mod = 998244353;
inline int ksm(int x, int y, int res = 1) {
	for ( ; y; y >>= 1, x = 1ll * x * x % mod)
		(y & 1) && (res = 1ll * res * x % mod);
	return res;
}
inline int inv(int x) { return ksm(x, mod - 2); }
inline int gcd(int a, int b) { if (b) while ((a %= b) && (b %= a)); return a | b; }
inline void add(int &x, int y) { (x += y) >= mod && (x -= mod); }
inline void Min(int &x, int y) { (y < x) && (x = y); }
inline void Max(int &x, int y) { (y > x) && (x = y); }

int T;
signed main() {
	freopen("device.in", "r", stdin);
	freopen("device.out", "w", stdout);
    T = read(); while (T--) {
        string s; cin >> s; int k = read();
        if (s[0] == s[1] && s[0] == s[2]) { puts("1"); continue; }
        if (k == 0) { puts("1"); continue; }
        if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) {
            puts(k == 1 ? "7" : "8"); continue; 
        } puts(k == 1 ? "24" : "27");
    }
	return 0;
}