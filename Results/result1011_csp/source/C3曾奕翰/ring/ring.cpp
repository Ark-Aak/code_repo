#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
		x=x*10+c-'0',c=getchar();
	return x*f;
}
int Mod;
int n,m,ans;
int a[10005],g[100005];
bool vis[10005];

void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++){
			int j=g[i];
			if(a[j]==i){
				int A=min(a[(n+j-2)%n+1],a[(n+j)%n+1]);
				int B=max(a[(n+j-2)%n+1],a[(n+j)%n+1]);
				if(A>=i||B<=i){
					continue;
				}
				else{
					ans++;
					return;
				}
				break;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a[x]=i,vis[i]=1;
		g[i]=x;
		dfs(x+1);
		g[i]=0;
		vis[i]=0;
	}
}
void dfs1(int x){
	if(x>n){	
		int as;
		if(x&1==1)as=2;
		else as=1; 
		for(int i=as;i<=n;i+=2){
			g[(i+1)/2]=min(a[(n+i-2)%n+1],a[(n+i)%n+1]);
		}
		sort(g+1,g+n/2+1);
		int now=0;
		int sum=0;
		for(int i=1;i<=n/2;i++){
			if(g[i]-now<2) return;
			sum+=(g[i]-now);
			if(g[i]!=g[i+1])now++;
			now+=2;
		}
		ans-=sum;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a[x]=i,vis[i]=1;
		dfs1(x+2);
		vis[i]=0;
	}
}
signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	n=read();Mod=read();
	
	if(n<=10){
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
	if(n&1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=Mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n<=20){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=Mod;
		}
		dfs1(1);
		dfs1(2);
		cout<<ans<<endl;
	}
	return 0; 
}

