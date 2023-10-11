#include<bits/stdc++.h>
//28
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
const int Maxn=5005;
int n,q;
struct node{
	int x,y;
}s[Maxn];
int sum[Maxn][Maxn];
int main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	read(n);read(q);
	for(int i=1;i<=n;i++)read(s[i].x);
	for(int i=1;i<=n;i++)read(s[i].y),sum[s[i].x][s[i].y]++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
	while(q--){
		int d,u,l,r;
		read(u);read(r);read(d);read(l);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(d<=s[i].x&&s[i].x<=u&&l<=s[i].y&&s[i].y<=r){
				if(sum[u][r]-sum[s[i].x][r]-sum[u][s[i].y]+sum[s[i].x][s[i].y]==0)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

