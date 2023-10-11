#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=1e6+5;
int n;
char s[Maxn],t[Maxn];
int f[Maxn][11];
int a[11],b[11];
vector<int>q,p;
int xs[Maxn];
int main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	n=read();
	scanf("%s",s+1);scanf("%s",t+1);
	xs[1]=1;
	for(int i=2;i<=n;i++)xs[i]=xs[i-1]*10%11;
	for(int i=1;i<=n;i++){
		if(t[i]=='y')q.push_back((s[i]-'0')*xs[n-i+1]%11);
		else p.push_back((s[i]-'0')*xs[n-i+1]%11);
	}
	int len=q.size();
	f[0][0]=1;
	for(int i=1;i<=len;i++)
		for(int j=10;~j;j--)
			f[i][j]=max(f[i-1][j],f[i-1][(j-q[i-1]+11)%11]);
	for(int i=0;i<11;i++)a[i]=f[len][i];
	memset(f,0,sizeof f);
	len=p.size();
	f[0][0]=1;
	for(int i=1;i<=len;i++)
		for(int j=10;~j;j--)
			f[i][j]=max(f[i-1][j],f[i-1][(j-p[i-1]+11)%11]);
	for(int i=0;i<11;i++)b[i]=f[len][i];
	int ans=1;
	for(int i=0;i<11;i++)
		if(b[i]&&a[(11-i)%11]==0)ans=0;
	if(ans)printf("yoimiya");
	else printf("oimiya");
	return 0;
}

