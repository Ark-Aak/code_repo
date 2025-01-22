#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int __int128
#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
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

using namespace std;
const int N=1e6+5,base=999983,Mod=998244353;
int n,m;
int p[N],ans;
inline int check(int x){
    int res=0,val=0;
    for(int i=1;i<=n;i++){
        int k=((x/p[i])+1)/2;
        res+=k;
        val+=k*k*p[i];
        if(k*k>m/p[i]) return 0;
    }
    int sum=0,ss=0;
    for(int i=1;i<=n;i++){
        int k=((x-1)/p[i]+1)/2;
        sum+=k;
        ss+=k*k*p[i];
    }
    if(val<=m) ans=max(ans,res);
    else if(ss<=m)ans=max(ans,sum+(m-ss)/(x));
    return (val<=m);
}
signed main(){
    n=read(),m=read();
    int mx=0;
    for(int i=1;i<=n;i++) p[i]=read(),mx=max(mx,p[i]);
    int l=0,r=2e18,res=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1,res=mid;
        else r=mid-1;
    }rep (i, 1, 100) check(res + i);
    print(ans);
    return 0;
}
