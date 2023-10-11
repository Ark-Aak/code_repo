#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<1)+(x<<3)+s-48;s=getchar();}
	return x*f;
}
const int Maxn=2e5+5;
int n,f[Maxn];
struct node{
	int c,p[5];
}s[Maxn];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool cmp(node a,node b){return a.c<b.c;}
int ans;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();
	for(int i=1;i<=n<<1;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		s[i].c=read();
		for(int j=1;j<=4;j++)s[i].p[j]=read();
		f[find(s[i].p[1])]=find(s[i].p[2]);
		f[find(s[i].p[3])]=find(s[i].p[4]);
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++){
		int op=0;
		for(int j=1;j<4;j++)
			for(int k=j+1;k<=4;k++)
				if(find(s[i].p[j])!=find(s[i].p[k]))op=1;//,printf("%d %d %d\n",i,j,k);
		ans+=s[i].c*op;
		for(int j=2;j<=4;j++)f[find(s[i].p[j])]=find(s[i].p[j-1]);
	}
	printf("%d",ans);
	return 0;
}

