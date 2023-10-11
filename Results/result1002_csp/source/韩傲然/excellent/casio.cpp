#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 4e7 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
constexpr int maxn = 4e7 + 100;
int T, P;
bool not_prime[maxn + 10], iscasio[maxn + 10];
//bitset<maxn> not_prime, iscasio;
int p[N / 10], tot;
int casio[maxn + 10], cnt;
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("casio.in", "r", stdin);
    freopen("casio.out", "w", stdout);
    read(T); read(P);
    for(int i = 4; i <= maxn; i += 2) not_prime[i] = 1;
    for(int i = 2; i <= maxn; i++) {
        if(!not_prime[i]) {
            p[++tot] = i;
            iscasio[i] = 1;
        }
        if(iscasio[i]) casio[++cnt] = i;
        for(int j = 1; j <= tot; j++) {
            if(i * p[j] > maxn) break;
            not_prime[i * p[j]] = 1;
            if(p[j] > P) iscasio[i * p[j]] = 1;
            if(i % p[j] == 0) break;
        }
    }
    while(T--) {
        int n; read(n);
        int mn = *lower_bound(casio + 1, casio + cnt + 1, n);
        cout << mn << "\n";
    }
    return 0;
}

