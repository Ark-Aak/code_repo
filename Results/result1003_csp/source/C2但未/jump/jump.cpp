#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=5e5+5;
map<int,int>vis;
int cnt,d[Maxn];
int n,a[Maxn];
int f[Maxn];
int t[Maxn];
inline void add(int x,int d){
	while(x<cnt){t[x]=max(t[x],d);x+=x&-x;}
}
inline int query(int x){
	int res=0;
	while(x){res=max(res,t[x]);x-=x&-x;}
	return res;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		d[i]=a[i];
	}
	sort(d+1,d+1+n);
	cnt=unique(d+1,d+1+n)-d;
	for(int i=1;i<cnt;i++)vis[d[i]]=i;
	for(int i=1;i<=n;i++){
		a[i]=vis[a[i]];
		f[i]=f[query(cnt-a[i])]+1;
		add(cnt-a[i]+1,i);
		printf("%d ",f[i]);
	}
	return 0;
}

