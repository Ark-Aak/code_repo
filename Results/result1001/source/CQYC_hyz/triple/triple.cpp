#include<bits/stdc++.h>
#define int long long 
using namespace std;

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

const int M = 3;

int T;
int s[M], t[M], d[M], v[M];

bool vis[M];

void solve() {
    for(int i = 0; i < M; i++) s[i] = read();
    for(int i = 0; i < M; i++) {
        t[i] = read(), d[i] = t[i] - s[i];
        if(s[i] == 0) vis[i] = t[i] == s[i], v[i] = 0;
        else vis[i] = ((v[i] = (t[i] / s[i])) * s[i]) == t[i];
    }

    int cnt = 0;

    for(int i = 0; i < M; i++) cnt += d[i] == 0;
    
    if(cnt == 3) return puts("0"), void();

    if(cnt == 2) return puts("1"), void();

    if(d[0] == d[1] and d[1] == d[2]) return puts("1"), void();

    bool flag = 1;
    for(int i = 0; i < M; i++) for(int j = i + 1; j < M; j++)
        flag &= (vis[i] and vis[j] and (v[i] == v[j] or !s[i] or !s[j]));
    
    if(flag) return puts("1"), void();

    for(int i = 0; i < M; i++) for(int j = i + 1; j < M; j++) {
        if(d[i] == d[j] and cnt == 1) return puts("1"), void();
        if(d[i] and d[j] and vis[i] and vis[j] and v[i] == v[j] and cnt == 1) return puts("1"), void();
    }

    if(cnt == 1) return puts("2"), void();

    if(d[0] == d[1] or d[1] == d[2] or d[0] == d[2]) return puts("2"), void();

    for(int i = 0; i < M; i++) for(int j = i + 1; j < M; j++)
        if(vis[i] and vis[j] and (v[i] == v[j] or !s[i] or !s[j])) return puts("2"), void();

    for(int i = 0; i < M; i++) for(int j = i + 1; j < M; j++) {
        int x = 3 ^ i ^ j;
        if(d[i] + d[j] == d[x]) return puts("2"), void();
        if(vis[i] and vis[j] and vis[x] and v[i] * v[j] == v[x]) return puts("2"), void();
    }

    for(int i = 0; i < M; i++) for(int j = 0; j < M; j++) if(i ^ j) {
        int x = 3 ^ i ^ j, lv = 0, ls = s[j] + d[i];
        if(ls and !(t[j] % ls) and vis[x] and t[j] / ls == v[x]) return puts("2"), void();

        if(!vis[i]) continue;

        ls = s[j] * v[i];

        if(t[j] - ls == d[x]) return puts("2"), void();
    }

    if(t[0] == t[1] and t[1] == t[2]) return puts("2"), void();

    if(s[0] - s[1]) {
        int p = (d[1] - d[0]) / (s[0] - s[1]), f = d[0] + p * s[0];
        flag = 1;
        for(int i = 0; i < M; i++) if(d[i] + p * s[i] != f) flag = 0;
        if(flag) return puts("2"), void();
    }

    for(int i = 0; i < M; i++) {
        int p = 0; flag = 1; bool f = 1;
        for(int j = 0; j < M; j++) if(i ^ j) {
            int tmp = s[j] ? (t[j] - d[i]) / s[j] : p;
            if(!f and p != tmp) flag = 0;
            p = tmp, f = 0;
            if(s[j] * p != t[j] - d[i]) flag = 0;
        }
        if(flag) return puts("2"), void();
        
        if(!vis[i]) continue;
        p = 0, flag = 1;

        if(v[i] == 0) continue;
        
        for(int j = 0; j < M; j++) if(i ^ j) {
            if(t[j] / v[i] * v[i] != t[j]) flag = 0;
            int tmp = t[j] / v[i] - s[j];
            if(!p) p = tmp;
            else if(p != tmp) flag = 0;
        }

        if(flag) return puts("2"), void();
    }

    for(int i = 0; i < M; i++) {
        int x = 0, y = 1;
        if(i == x) x = 2;
        if(i == y) y = 2;

        int a = s[x] + d[i], b = s[y] + d[i];

        if(a and b and t[x] / a == t[y] / b and !(t[x] % a) and !(t[y] % b)) return puts("2"), void();

        if(!vis[i]) continue;

        a = s[x] * v[i], b = s[y] * v[i];

        if(t[x] - a == t[y] - b) return puts("2"), void();
    }

    puts("3");
}

bool edmer;
signed main() {
	freopen("triple.in", "r", stdin);
	freopen("triple.out", "w", stdout);
	cerr << "[Memory] " << (&stmer - &edmer) / 1024 / 1024 << " MB\n";
	
    T = read();
    while(T--) solve();

    cerr << "[Runtime] " << (double) clock() / CLOCKS_PER_SEC << " seconds";
	return 0;
} 