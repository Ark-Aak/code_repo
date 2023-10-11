#include<bits/stdc++.h>
#define int long long 
using namespace std;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 and (p2 = (p1 = buf) + fread(buf, 1, 1 << 23, stdin), p1 == p2) ? EOF : *p1++)

inline int read() {
	int x = 0, f = 0; char ch = getchar();
	while(ch < '0' or ch > '9') f |= (ch == '-'), ch = getchar();
	while(ch >= '0' and ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int __stk[128], __top;
inline void write(int x) {
    if(x < 0) putchar('-'), x = -x;
	do { __stk[++__top] = x % 10, x /= 10; } while(x);
	while (__top) putchar(__stk[__top--] + '0');
}
bool stmer;

int T, k, n;

void solve() {
    k = read(), n = read();
    if(n == 0) return puts("1"), void();
    
    int a = k / 100, b = k / 10 % 10, c = k % 10;
    
    if(n == 1) {
        if(a == b and b == c) return puts("1"), void();
        if(a == b or a == c or b == c) return puts("7"), void();
        return puts("24"), void();
    }

    if(a == b and b == c) return puts("1"), void();
    if(a == b or a == c or b == c) return puts("8"), void();
    return puts("27"), void();
}

bool edmer;
signed main() {
	freopen("device.in", "r", stdin);
	freopen("device.out", "w", stdout);
	cerr << "[Memory] " << (&stmer - &edmer) / 1024 / 1024 << " MB\n";
	
    T = read();
    while(T--) solve();

    cerr << "[Runtime] " << (double) clock() / CLOCKS_PER_SEC << " seconds";
	return 0;
} 