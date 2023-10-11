#include<bits/stdc++.h>
// #define int long long
#define il inline
#define ct const
#define dl double
#define pk push_back
#define fi first
#define se second
#define pii pair<int,int>
#define N 200010
#define SQ 720
// #define inf (int)(1000000000000000000)
using namespace std;
bool ppp;
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);ch=getchar();
	}
	return x*f;
}
char f__[40];
il void write(int x){
	int cnt=0;
	if(x<0){
		putchar('-');x=-x;
	}
	if(!x) putchar('0');
	while(x){
		f__[cnt++]=x%10+'0';x/=10;
	}
	while(cnt) putchar(f__[--cnt]);
}
int n,Q,sq;
bitset<N> ans[SQ],now;
vector<int> Vl[N],Vr[N],qus[N];
il void solve(){
    now=0;
    for(int i=1;i<=n;++i){
        for(auto x:Vl[i]) now[x]=now[x]^1;
        for(auto x:qus[i]) ans[x]=ans[x]^now;
        for(auto x:Vr[i]) now[x]=now[x]^1;
    }
}
bool pppp;
signed main(){
    cerr<<(&ppp-&pppp)/1024.0/1024.0<<"\n";
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
    n=read();Q=read();sq=sqrt(Q);
    for(int i=1;i<=n;++i){
        int l=read(),r=read();
        Vl[l].pk(i);Vr[r].pk(i);
    }
    for(int l=1,r;l<=Q;l=r+1){
        // cerr<<"ERROR";
        r=min(l+sq,Q);
        for(int i=1;i<=n;++i) qus[i].clear();
        for(int i=l;i<=r;++i){
            int m=read();
            ans[i-l]=0;
            while(m--) qus[read()].pk(i-l);
        }
        solve();
        for(int i=l;i<=r;++i){
            write(ans[i-l].count());putchar('\n');
        }
    }
    cerr<<"\n"<<(dl)clock()/CLOCKS_PER_SEC;
	// cerr<<"ERROR";
	return 0;
}