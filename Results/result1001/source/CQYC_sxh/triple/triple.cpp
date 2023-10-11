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
using arr = array<i64, 3>;
int op(arr a, arr b) { int len = 3;
    For(i, 1, 3) For(j, 0, len - 1) if (a[j] == b[j]) {
        swap(a[j], a[len - 1]), swap(b[j], b[len - 1]), --len; break;
    }  if (!len) return 0;
    if (len == 1) return 1;
    i64 k = b[0] - a[0]; bool flag = 1;
    For(i, 0, len - 1) flag &= (a[i] + k == b[i]);
    if (flag) return 1;

    if (a[0]) {
        k = b[0] / a[0], flag = 1;
        For(i, 0, len - 1) flag &= (a[i] * k == b[i]);
        if (flag) return 1;
    }
    if (len == 2) return 2;
    return 3;
}
signed main() {
	freopen("triple.in", "r", stdin);
	freopen("triple.out", "w", stdout);
    T = read(); while (T--) { int len = 3;
        array<i64, 3> a = {read(), read(), read()};
        array<i64, 3> b = {read(), read(), read()};
        if (op(a, b) < 3) { cout << op(a, b) << '\n'; continue; }
        array<i64, 3> c = a; bool flag = 0; 
        For(i, 0, len - 1) c = a, c[i] = b[i], flag |= op(c, b) < 2;
        For(i, 0, len - 1) For(j, 0, len - 1) if (i != j) {
            c = a, c[i] = b[i], c[j] += b[i] - a[i], flag |= op(c, b) < 2;
            if (a[i]) c = a, c[i] *= b[i] / a[i], c[j] *= b[i] / a[i], flag |= op(c, b) < 2;
        } 
        For(i, 0, len - 1)  {
            c = a; 
            For(j, 0, len - 1) c[j] += b[i] - a[i];
            flag |= op(c, b) < 2;
            if (a[i]) { c = a;
                For(j, 0, len - 1) c[j] *= b[i] / a[i];
                flag |= op(c, b) < 2;
            }
        } 
        For(i, 0, len - 1) {  int p = i;
            For(j, 0, len - 1) if (j != i) { p = j; break; }
            if (a[p]) { c = a;
                i64 x = (a[i] + b[p] - b[i]) / a[p];
                For(j, 0, len - 1) if (j != i) c[j] *= x;
                flag |= op(c, b) < 2;
            }
        }
        if (a[0] != a[1]) {
            i64 k = (b[0] - b[1]) / (a[0] - a[1]);
            c = a; For(t, 0, 2) c[t] *= k;
            flag |= op(c, b) < 2;
        }
        puts(flag ? "2" : "3");
    }
	
	return 0;
}