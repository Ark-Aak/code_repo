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
constexpr int mod = 998244353;
int n, k;
int f[12][(1 << 21)];
int g[11] = {0, 1, 5, 21, 85, 341, 1365, 5461, 21845, 87381, 349525};
int h[11] = {0, 0, 2, 10, 42, 170, 682, 2730, 10922, 43690, 174762};
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("flip.in", "r", stdin);
    freopen("flip.out", "w", stdout);
    read(n, k);
    int s = 1;
    for(int i = 1; i < n; i++) 
        s <<= 2, s++;
    f[0][s] = 1;
    int sum = 0;
    for(int i = 1; i <= k; i++) {
        for(int st = 0; st < (1 << (2 * n - 1)); st++) {
            if(f[i - 1][st]) {
                int cnt = 0;
                for(int p = 1; p <= 10; p++) {
                    for(int pos = 0; pos <= 2 * n - 1; pos++) {
                        if((st & (g[p] << pos)) == (g[p] << pos)) {
                            f[i][(st ^ (g[p] << pos)) + ((h[p]) << pos)] = (f[i][(st ^ (g[p] << pos)) + ((h[p]) << pos)] + f[i - 1][st]) % mod ;
                        }
                    }
                }
            }
        }
    }
    for(int st = 0; st < (1 << (2 * n - 1)); st++) {
        sum = (sum + f[k][st]) % mod;
    }
    cout << sum << "\n";
    return 0;
}