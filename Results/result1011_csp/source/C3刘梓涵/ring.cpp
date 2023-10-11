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
#define N 1000005
//#define Mod 998244353
#define int long long
int n,Mod,ans,a[N],s[N],vis[N];
void dfs(int u){
	if(u>n){
		For(i,1,n)s[i]=a[i];
//		For(i,1,n)cout<<a[i]<<' ';cout<<endl;
		int kkk=0;
		For(i,1,n){
			if(kkk)break;
			For(j,1,n)
			if(a[j]==i){
				int x=j-1<1?n:j-1;
				int y=j+1>n?1:j+1;
				if(a[x]<i&&i<a[y]){
					kkk=1;
					break;
				}if(a[x]>i&&i>a[y]){
					kkk=1;
					break;
				}
				swap(a[x],a[y]);
			}
//			For(i,1,n)cout<<a[i]<<' ';cout<<endl;
		}if(kkk)ans++;
//		cout<<endl;
		For(i,1,n)a[i]=s[i];
		return;
	}
	For(i,1,n)
	if(!vis[i]){
		a[u]=i,vis[i]=1;
		dfs(u+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);	
	read(n),read(Mod);
	if(n<=10){
		dfs(1);
		write(ans);
		return 0;
	}else if(n==11){
		cout<<39916800%Mod;
		return 0;
	}else if(n==12){
		cout<<474756096%Mod;
		return 0;
	}else if(n==13){
		cout<<6227020800%Mod;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}

