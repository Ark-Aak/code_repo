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
}inline void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
#define N 200005
#define Mod 1000000007
#define int long long
int n,ans,tot;
int a[N],jj[N];
vector<int>h[N],t[N];
signed main(){
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
    read(n);
    For(i,1,n)read(a[i]);
    if(n<=5000){
    	For(i,1,n){
    		For(j,1,n)jj[j]=0;
    		jj[a[i]]=1;
    		For(j,i+1,n){
    			if(a[j]==a[i])break;
	    		if(!jj[a[j]])ans++;
				jj[a[j]]=1; 
			}
		}cout<<ans;
		return 0;
	}
    For(i,1,n)h[a[i]].PB(i-1);
    For(i,1,n)t[a[i]].PB(n-i+1);
    For(i,1,n){
        int s=0;
        if(h[i].size()<2)continue;
        FoR(j,0,h[i].size()-1){
            s+=h[i][j];
            ans+=s;
        }
//        cout<<i<<endl;
//        Fo(j,h[i])cout<<j<<" ";
//        cout<<endl;
//        cout<<ans<<endl;
    }
//    cout<<ans<<endl<<endl;
    For(i,1,n){
        int s=0;
        if(t[i].size()<2)continue;
        FOR(j,t[i].size()-1,1){
            s+=t[i][j];
            ans+=s;
        }
//        cout<<i<<endl;
//        FOR(j,t[i].size()-1,0)cout<<t[i][j]<<" ";
//        cout<<endl;
//        cout<<ans<<endl;
    }
//    cout<<ans<<endl<<endl;
    printf("%lld",(long long)max((n*(n-1)/2-ans),0ll));
//    cout<<endl<<ans;
    return 0;
}
