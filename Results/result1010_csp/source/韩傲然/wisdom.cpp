#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 1000 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)

void read(){};
template<class T1,class ...T2>
inline void read(T1& ret,T2&... rest){
    ret=0;char c=getchar();bool f=false;
    while(c<'0'||c>'9'){f=c=='-';c=getchar();}
    while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
    if(f)ret=-ret;
    read(rest...);
}
constexpr int mod = 1e9 + 7;
int n, m, k;
int r[N], s[N];
struct OPT {
    int opt, x, y;
    bool operator < (const OPT &A) const {
        if(opt != A.opt) return opt < A.opt;
        if(x != A.x) return x < A.x;
        return y < A.y;
    }
}a[N], b[N];
int getval(int l, int r, int cnt) {
    return (l + r) % mod * (cnt % mod) % mod * 500000004 % mod;
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("wisdom.in", "r", stdin);
        freopen("wisdom.out", "w", stdout);
    #endif
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) {
        char opt; int x, y; cin >> opt >> x >> y;
        a[i] = {(opt == 'S'), x, y};
        if(opt == 'S') s[0]++; 
        else r[0]++;
    }

    sort(a + 1, a + k + 1);
    int tot = 0, tr = r[0];
    for(int i = 1; i <= r[0]; i++) {
        if(a[i - 1].x != a[i].x) b[++tot] = {0, a[i].x, a[i].y};
        else b[tot].y = (b[tot].y * a[i].y) % mod;
    } r[0] = tot;

    for(int i = tr + 1; i <= k; i++) {
        if(i == tr + 1 || a[i - 1].x != a[i].x) b[++tot] = {1, a[i].x, a[i].y};
        else b[tot].y = (b[tot].y * a[i].y) % mod;
    } s[0] = tot - r[0];

    int ans = getval(1, n * m, n * m) % mod;

    for(int i = 1; i <= r[0]; i++) {
        r[i] = getval((b[i].x - 1) * m + 1, b[i].x * m, m) % mod;
        ans = (ans + r[i] * (b[i].y - 1) % mod) % mod;
    }


    for(int i = r[0] + 1; i <= tot; i++) {
        s[i - r[0]] = getval(b[i].x, (n - 1) * m + b[i].x, n) % mod;
        ans = (ans + s[i - r[0]] * (b[i].y - 1) % mod) % mod;
    }

    for(int i = 1; i <= r[0]; i++) {
        for(int t = 1; t <= s[0]; t++) {
            int j = r[0] + t;
            int val = (b[i].x - 1) * m + b[j].x;
            ans = (ans - val % mod * (b[i].y - 1) % mod + mod) % mod; ans = (ans - val % mod * (b[j].y - 1) % mod + mod) % mod; 
            ans = (ans + val % mod * (b[j].y * b[i].y % mod - 1) % mod) % mod; 
        }
    }
    cout << (ans + mod * 10) % mod << "\n";
    return 0;
}