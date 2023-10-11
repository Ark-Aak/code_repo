#include<bits/stdc++.h>
//30
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,Mod,ans;
int a[20],p[20],s[20],p1[20];
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++)s[i]=a[i],p1[i]=p[i];
		for(int i=1;i<=n;i++){
			int l=p1[i]-1,r=p1[i]+1;
			if(!l)l=n;if(r==n+1)r=1;
			int A=s[l],B=s[r];
			swap(s[l],s[r]);
			swap(p1[A],p1[B]);
			if(A>B)swap(A,B);
			if(A<i&&i<B){
				ans++;return;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(p[i])continue;
		p[i]=x;
		a[x]=i;
		dfs(x+1);
		p[i]=0;
	}
}
int main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	read(n);read(Mod);
	if(n&1){
		long long ans=1;
		for(long long i=1;i<=n;i++)ans=1ll*ans*i%Mod;
		printf("%lld",ans);
		exit(0);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}

