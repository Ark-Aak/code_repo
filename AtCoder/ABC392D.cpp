#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define fi first
#define se second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int N=2e5+5,mod=998244353;
int fac[N],inv[N];
int ksm(int x,int y) {
    int ans=1;
    while(y) {
        if(y&1) ans=(1ll*ans*x)%mod;
        x=(1ll*x*x)%mod; y>>=1;
    }
    return ans;
}
inline void init() {
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=(1ll*fac[i-1]*i)%mod;
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i]=(1ll*inv[i+1]*(i+1))%mod;
}
inline int Inc(int x,int y) {return x+y<mod?x+y:x+y-mod;}
inline int Dec(int x,int y) {return x>=y?x-y:x-y+mod;}
inline int Mul(int x,int y) {return (1ll*x*y)%mod;}
vector<pair<double,int> > vec[N];
int n,a[105][N],num[N];
map<int,int> ma[105];
double Ans[105];
int cmp(double x,double y) {
    return x>y;
}
signed main() {
#ifndef KAxdd
#ifndef ONLINE_JUDGE
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
#endif
	cin >> n;
    for(int i=1;i<=n;i++) {
        int k; cin >> k;num[i]=k;
        for(int j=1;j<=k;j++) {
            int x; cin >> x;
            ma[i][x]++;
        }
        for(auto j:ma[i]) {
            vec[j.fi].push_back({(1.0*j.se/k),i});
        }
    }
    double ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) Ans[j]=0;

        for(auto j:ma[i]) {
            for(auto k:vec[j.fi]) {
                Ans[k.se]+=(k.fi*(1.0*j.se/num[i]));
            }
        }

        for(int j=1;j<=n;j++) {
            if(j==i) continue;
            ans=max(ans,Ans[j]);
        }
    }
    printf("%.010lf",ans);
    return 0;
}
