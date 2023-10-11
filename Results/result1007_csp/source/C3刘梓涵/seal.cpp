#include<bits/stdc++.h>
#define inf LONG_LONG_MAX
#define fir first
#define sec second
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
#define Pr(i,j) pair<i,j>
#define PB(i) push_back(i)
#define MP(i,j) make_pair(i,j)
#define Fo(i,j) for(auto i:j)
#define mem(i,j) memset(i,j,sizeof(i))
#define FO(i,j,k) for(int i=j;i;i=k)
#define FFF(i,j,k) for(auto i=j;i!=(k);++i)
#define For(i,j,k) for(int i=j;i<=(k);++i)
#define FoR(i,j,k) for(int i=j;i^(k);++i)
#define FOR(i,j,k) for(int i=j;i>=(k);--i)
using namespace std;
template <typename _Tp>void read(_Tp& first) {
    _Tp x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    first = x * f;
}inline void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
#define N 200005
#define Mod 998244353
#define int long long
struct P{
	int a,b;
}a[N],b[N];
struct PPP{
	int x,i;
}c[N];
int n,t,m,ans;
bool cmp1(P a,P b){return a.a<b.a;}
bool cmp2(P a,P b){return a.b<b.b;}
bool cmp3(PPP a,PPP b){return a.x<b.x;}
signed main(){
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	read(n),read(t),read(m);
	For(i,1,n){
		read(a[i].a),read(a[i].b);
		b[i].a=a[i].a,b[i].b=a[i].b;
		c[(i<<1)-1].x=a[i].a;c[(i<<1)-1].i=i;
		c[(i<<1)].x=a[i].b;c[(i<<1)].i=i;
	}
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+n,cmp2);
	sort(c+1,c+1+(n<<1),cmp3);
	if(m==0){
		ans=max(a[1].a,t-b[n].b);
		write(ans);
	}
    return 0;
}

