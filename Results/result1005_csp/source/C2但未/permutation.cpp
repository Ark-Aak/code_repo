#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=1e5+5;
int n,k;
int p[Maxn],q[Maxn],f[3][Maxn];
int a[3][3];
int t[3][3];
inline void cheng1(int x[3][3],int y[3][3]){
	memset(t,0,sizeof t);
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;i<=2;k++)
				t[i][j]+=x[i][k]*y[j][k];
}
int tmp[Maxn];
inline void solve30(){
	for(int i=3;i<=k+1;i++){
		for(int j=1;j<=n;j++)
			tmp[f[i&1][j]]=f[i&1^1][j];
		for(int j=1;j<=n;j++)f[i&1][j]=tmp[j];
	}
	for(int i=1;i<=n;i++)printf("%d ",f[k&1^1][i]);
}
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++)f[1][i]=p[i]=read();
	for(int i=1;i<=n;i++)f[0][i]=q[i]=read();
	solve30();
	return 0;
}

