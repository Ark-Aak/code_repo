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
#define int long long
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
#define Mod 998244353
int n,k;
int a[N],t[N],l[N];
void dfs(int x,int s){
	if(x==n/k){
		write(s);
		exit(0);
	}
	int Max=0,Min=1e16,ans,R;
	For(i,k,n){
		int tot=1,j=i,sum=0;
		if(!t[i])continue;
		while(tot<=k&&j>0){
//			cout<<j;
			int kkkk=j;
			while(j>0&&!t[j])j=l[j];
			sum+=a[j];
			if(j!=kkkk)l[kkkk]=j;
			j=l[j];tot++;
		}
		if(tot>k){
			if(x&1){
				if(Max<sum){
					Max=max(Max,sum);
					R=i;	
				}
			}else{
				if(Min>sum){
					Min=min(Min,sum);
					R=i;
				}
			}
		}
	}
	int j=R,tot=1;
	while(tot<=k&&j>0){
//		cout<<j;	
		while(j>0&&!t[j])j=l[j];
		t[j]=0;j=l[j];tot++;
	}
//	For(i,1,n)cout<<t[i];cout<<endl;
	if(x&1)ans=Max;
	else ans=Min;
//	cout<<ans<<endl;
	dfs(x+1,s+ans);
}
signed main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	read(n),read(k);
	For(i,1,n)read(a[i]);
	if(k==1){
		int ans=0;
		For(i,1,n)ans+=a[i];
		sort(a+1,a+1+n);
		write(ans-a[n/2+1]);
	}else{
		For(i,1,n)t[i]=1;
		For(i,1,n)l[i]=i-1;
		dfs(0,0);
	}
	
	return 0;
}

