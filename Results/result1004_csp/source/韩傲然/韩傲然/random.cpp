#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 1001, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
int n, m;
int a[N][N], p[N][N], inv2, inv4, inv8, inv3;
int qpow(int x, int y) {
    int ans = 1;
    for(; y; y >>= 1) {
        if(y & 1) ans = ((ans % mod) * (x % mod)) % mod;
        x = ((x % mod) * (x % mod)) % mod;
    }
    return ans % mod;
}
void solve40() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!p[i][j]) continue;
            for(int k = 1; k <= n; k++) {
                if(i == j || i == k || j == k) continue;
                ans = (ans + (p[i][j] * p[j][k] * p[k][i]));
            }
            if(ans > mod) ans -= mod; 
        }
    }
    ans = ans * inv3 % mod;
    if(m == 2) cout << ans * inv2 % mod << "\n";
    else if(m == 1) cout << ans * inv4 % mod << "\n";
    else if(m == 0) cout << ans * inv8 % mod << "\n";
    else cout << ans * qpow(2, m - 3) % mod<< "\n";
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("random.in", "r", stdin);
    freopen("random.out", "w", stdout);
    auto st = clock();
    cin >> n; m = n * (n - 1) / 2; inv2 = qpow(2, mod - 2), inv4 = qpow(4, mod - 2), inv8 = qpow(8, mod - 2);
    inv3 = qpow(3, mod - 2);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
        char c; cin >> c; a[i][j] = c - '0';
        if(a[i][j] == 1) m--;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(!a[i][j] and !a[j][i]) p[i][j] = p[j][i] = 1;
            else if(a[j][i]) p[j][i] = 2;
            else if(a[i][j]) p[i][j] = 2;
        }
    }
    solve40();
    return 0;
}