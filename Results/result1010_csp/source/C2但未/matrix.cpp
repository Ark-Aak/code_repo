#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<1)+(x<<3)+s-48;s=getchar();}
	return x*f;
}
const int Maxs=1<<23;
const int Maxn=23,Maxm=2e5+5;
int f[Maxs];
int g[Maxs];
int n,m;
int a[Maxm][Maxn];
int cnt[Maxs];
int ans=1e9;
int sum=0;
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&a[j][i]),sum+=a[j][i];
	for(int s=0;s<(1<<n);s++)
		for(int i=1;i<=n;i++)
			if(s&(1<<i-1))cnt[s]++;
	for(int i=1;i<=m;i++){
		int w=0;
		for(int j=1;j<=n;j++){
			if(a[i][j])w+=(1<<j-1);
		}
		g[w]++;
	}
	for(int s=0;s<(1<<n);s++){
		int ans1=0;
		for(int s1=0;s1<(1<<n);s1++){
			int S=s1;
			for(int i=1;i<=n;i++)
				if(s&(1<<i-1)){
					S^=(1<<i-1);
				}
			ans1+=g[s1]*min(cnt[S],n-cnt[S]);
		}
		ans=min(ans,ans1);
	}
	printf("%d",ans);
	return 0;
}

