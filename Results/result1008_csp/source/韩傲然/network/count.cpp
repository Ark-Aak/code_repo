#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 1e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
int n, m, a[N], b[N], ans;
bool check() {
    for(int i = 1; i <= n; i++) {
        bool flg = 1;
        if(i + a[b[i]] > n) continue;
        for(int j = i; j <= i + a[b[i]]; j++) {
            if(b[j] != b[i]) flg = 0;
        }
        if(flg) return 0;
    }
    return 1;
}
void dfs1(int cnt) {
    if(cnt == n + 1) {
        ans += check();
        return;
    }
    for(int i = 1; i <= m; i++) {
        b[cnt] = i;
        dfs1(cnt + 1);
    }
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("count.in", "r", stdin);
        freopen("count.out", "w", stdout);
    #endif
    read(n, m);
    for(int i = 1; i <= m; i++) read(a[i]);
    dfs1(1);
    cout << ans << "\n";
    return 0;
}