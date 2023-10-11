#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 5e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
int n;
int a[N], b[N], tot, f[N]; 
int mx[N];
int lowbit(int x) {return x & (-x);}
void modify(int x, int v) {
    for(int i = x; i <= tot; i += lowbit(i)) mx[i] = max(mx[i], v);
}
int query(int x) {
    int res = -inf; for(int i = x; i ; i -= lowbit(i)) res = max(res, mx[i]);
    return res;
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("jump.in", "r", stdin);
    freopen("jump.out", "w", stdout);
    a[1] = inf; b[++tot] = inf;
    read(n); n++;
    for(int i = 2; i <= n; i++) read(a[i]), b[++tot] = a[i];
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - b - 1;
    f[1] = 0;
    for(int i = 2; i <= n; i++) {
        int x = lower_bound(b + 1, b + tot + 1, a[i]) - b;
        f[i] = f[query(tot - (x + 1) + 1)] + 1;
        modify(tot - x + 1, i);
        cout << f[i] << " ";
    }
    
    return 0;
}
