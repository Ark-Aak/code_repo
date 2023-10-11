#include<bits/stdc++.h>
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
#define N 1000005
#define Mod 1000000007
map<pair<int,int>,int>m;
int n,q,x,y,Min=1e16;
int a[N],b[N];
signed main(){
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
    cin>>n>>q;
    For(i,1,n)cin>>a[i];
    For(i,1,n)cin>>b[i];
    For(i,1,n)m[MP(a[i],b[i])]=1;
    For(i,1,n)
    if(a[i]==b[i]+1||a[i]+1==b[i])
    Min=min(Min,min(a[i],b[i]));
//    cout<<Min;
//350769201 350769199
//For(i,1,n)if(a[i]==350769201||b[i]==350769201)cout<<a[i]<<" "<<b[i]<<endl;cout<<endl<<endl;
//For(i,1,n)if(a[i]==350769199||b[i]==350769199)cout<<a[i]<<" "<<b[i]<<endl;cout<<endl<<endl;
	while(q--){
    	cin>>x>>y;
    	if(m[MP(x,y)]||abs(x-y)<=0)cout<<"Bob"<<endl;
    	else cout<<"Alice"<<endl;
	}
    return 0;
}
