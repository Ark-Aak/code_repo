#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxs=1<<20;
int n,k;
int f[Maxs][11];
int s[21];
struct node{int s,k;};
int sum[22];
int vis[Maxs][11];
int main(){
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	n=read()*2-1;k=read();
	int now=0;
	for(int i=1;i<=n;i++)now+=(i&1)*(1<<i-1),sum[i]=sum[i-1]+(1<<n-i);
	queue<node>h;
	f[now][0]=1;
	h.push({now,0});
	while(h.size()){
		node tmp=h.front();
		h.pop();
		if(tmp.k==k)continue;
		vis[tmp.s][tmp.k]=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(tmp.s&(1<<n-i))s[++cnt]=n-i+1;
		for(int i=1;i<=cnt;i++)
			for(int j=i;j<=cnt;j++){
				f[tmp.s^(sum[s[i]]-sum[s[j]-1])][tmp.k+1]+=f[tmp.s][tmp.k];
				if(!vis[tmp.s^(sum[s[i]]-sum[s[j]-1])][tmp.k+1])h.push({tmp.s^(sum[s[i]]-sum[s[j]-1]),tmp.k+1});
				vis[tmp.s^(sum[s[i]]-sum[s[j]-1])][tmp.k+1]=1;
			}
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		ans+=f[i][k];
	}
	printf("%d",ans);
	return 0;
}

