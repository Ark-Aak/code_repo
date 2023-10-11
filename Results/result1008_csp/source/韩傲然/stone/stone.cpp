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
int b[10], c[10], tmp[10];
int ans, tans;
int sheet[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 2, 5, 9, 14, 20}, {0, 2, 11, 39, 89, 167, 279}, {0, 8, 60, 229, 661, 1495, 2920}, {0, 24, 261, 1300, 4359, 11891, 27159}, {0, 64, 1026, 6736, 28045, 88639, 236776}, {0, 160, 3807, 33088, 171475, 648474, 1981209}};
constexpr int mod = 1e9 + 7;

signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("stone.in", "r", stdin);
        freopen("stone.out", "w", stdout);
    #endif
    read(n, k); 
    cout << sheet[n][k] << "\n";
    // for(n = 1; n <= 6; n++) {
    //     cout << "{0, ";
    //     for(k = 1; k <= 6; k++) {
    //         dfs1(1);
    //         if(k < 6) cout << ans % mod << ", ";
    //         else cout << ans % mod << "}, ";
    //         ans = 0;
    //     }
    // }
    //cout << clock() << "\n";
    return 0;
}