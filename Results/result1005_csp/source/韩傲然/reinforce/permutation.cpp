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
int n, k;
struct PERMUTATION {
    int f[N];
    PERMUTATION operator + (const PERMUTATION &A) {
        PERMUTATION tmp;
        for(int i = 1; i <= n; i++) {
            tmp.f[f[i]] = A.f[i];
        }
        return tmp;
    }
};
PERMUTATION p, q, s;
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("permutation.in", "r", stdin);
        freopen("permutation.out", "w", stdout);
    #endif
    read(n, k);
    for(int i = 1; i <= n; i++) read(p.f[i]);
    for(int i = 1; i <= n; i++) read(q.f[i]);
    for(int i = 2; i <= k; i++) {
        s = p + q;
        // for(int i = 1; i <= n; i++) cout << s.f[i] << " ";
        // cout << "\n";
        p = q, q = s;
    }
    for(int i = 1; i <= n; i++) cout << s.f[i] << " ";
    return 0;
}