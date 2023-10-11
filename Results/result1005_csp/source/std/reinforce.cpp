#include<bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;
const int N=21,M=100010,INF=0x3f3f3f3f;
inline int Max(int x,int y){return x>y?x:y;}
inline int Min(int x,int y){return x<y?x:y;}
inline void Swap(int &x,int &y){x^=y^=x^=y;}
int n,m,ans=INF,f[1<<20],a[M],b[M],c[N][N];
char s[M];
int main(){
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)b[i]=s[i];
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+m+1,s[i])-b-1;
	for(int i=1;i<n;i++)c[a[i]][a[i+1]]++;
	memset(f,0x3f,sizeof(f));f[0]=1;
	for(int S=1;S<(1<<m);S++)
		for(int j=0;j<m;j++)
			if(S&1<<j){
				int sum=f[S^1<<j];
				for(int k=0;k<m;k++)
					if(S&1<<k)sum+=c[j][k];
				f[S]=Min(f[S],sum);
			}
	printf("%d\n",f[(1<<m)-1]);
	return 0;
}
