#include<bits/stdc++.h>
#define db doub
#define int long long
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
#define FFF(i,j,k) for(auto i=j;i!=k;++i)
#define For(i,j,k) for(int i=j;i<=k;++i)
#define FoR(i,j,k) for(int i=j;i^k;++i)
#define FOR(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
template <typename _Tp>void read(_Tp& first) {
    _Tp x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    first = x * f;
}
#define N 100005
#define Mod 1000000007
struct Node{
	int x,y,c;
}a[N];
int n,k,ans;
int in[N],sub3;
signed main(){
	freopen("tree.in","r",stdin);	
	freopen("tree.out","w",stdout);
    cin>>n>>k;
    FoR(i,1,n){
    	int u,v;
    	cin>>u>>v;
    	in[u]++;
		in[v]++;
	}
	For(i,1,n)
	if(in[i]==n-1)sub3=i;
	if(sub3){
		For(i,1,n){
			if(i<sub3)ans+=i*i*(sub3-i)%Mod,ans%=Mod;
			if(i+sub3<=n)ans+=i*i*(n-sub3-i+1)%Mod,ans%=Mod;
		}ans+=sub3*(n-sub3+1),ans%=Mod;
		cout<<ans<<endl;
	}
    return 0;
}
