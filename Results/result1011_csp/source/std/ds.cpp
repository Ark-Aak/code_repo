#include<bits/stdc++.h>
#define M 2097152
#define N 1000005
using namespace std;
char buf[(1<<21)+5],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int b[N],c[N],d[N],e[N],f[N],x[N];
int find(int u){return d[u]==u?u:d[u]=find(d[u]);}
void Find(int u){if(d[u]!=u)Find(d[u]),e[u]+=e[d[u]],d[u]=d[d[u]];}
void dfs(int*a,int*h,int n,int*L,int*R,int*U,int*V,int*X,int q)
{
	if(n==1)
	{
		for(int i=0;i<q;i++)if(L[i]<=R[i])x[X[i]]++;
		return;
	}
	int m=n>>1,p=upper_bound(R,R+q,m)-R;
	for(int i=1,j=0,k=m;i<=n;i++)h[i]<=m?d[++j]=h[i]:d[++k]=h[i]-m;
	memcpy(h+1,d+1,n<<2);
	for(int i=1;i<=m;i++)c[a[i]]++;
	for(int i=1;i<=n;i++)d[i]=c[i]?i:d[i-1];
	for(int i=1;i<=m;f[i]=find(a[i]),i++)if(!--c[a[i]])d[a[i]]=a[i]-1;
	for(int i=m;i;i--)f[i]=d[f[i]],d[a[i]]=i;
	for(int i=m+1;i<=n;i++)c[a[i]]++;
	for(int i=1;i<=n;i++)d[i]=c[i]?i:d[i-1];
	for(int i=n,j=q;m<i;i--)
	{
		while(j>p&&R[j-1]==i)if(L[--j]<=m)V[j]=find(V[j]);
		if(!--c[a[i]])d[a[i]]=a[i]-1;
	}
	for(int i=p;i<q;i++)
	{
		if(V[i]<U[i])V[i]=U[i]++;
		if(L[i]<=m)b[V[i]]++;
	}
	for(int i=2;i<=n+1;i++)b[i]+=b[i-1];
	for(int i=p;i<q;i++)if(L[i]<=m)c[--b[V[i]]]=i;
	for(int i=1;i<=m;i++)d[i]=i;
	for(int i=n,j=m,k=b[n+1];i;i--)
	{
		while(j&&a[h[j]]==i)d[h[j]]=f[h[j]],e[h[j--]]=1;
		for(;k>b[i];x[X[c[k]]]+=e[L[c[k]]])Find(L[c[--k]]);
	}
	for(int i=n;i>m;i--)d[a[i]]=i;
	for(int i=p;i<q;i++)if(L[i]<=m)L[i]=V[i]<U[i]?R[i]+1:d[V[i]];
	memset(c,0,b[n+1]<<2),memset(d+1,0,n<<2),memset(e+1,0,m<<2),memset(f+1,0,m<<2),memset(b+2,0,n<<2);
	for(int i=1;i<=m;i++)e[a[i]]=1;
	for(int i=m+1;i<=n;i++)f[a[i]]=1;
	for(int i=1;i<=n;i++)e[i]+=e[i-1],f[i]+=f[i-1];
	for(int i=1;i<=m;i++)a[i]=e[a[i]];
	for(int i=m+1;i<=n;i++)a[i]=f[a[i]];
	for(int i=0;i<p;i++)U[i]=e[U[i]-1]+1,V[i]=e[V[i]];
	for(int i=p;i<q;i++)L[i]-=m,R[i]-=m,U[i]=f[U[i]-1]+1,V[i]=f[V[i]];
	memset(e+1,0,n<<2),memset(f+1,0,n<<2);
	dfs(a,h,m,L,R,U,V,X,p),dfs(a+m,h+m,n-m,L+p,R+p,U+p,V+p,X+p,q-p);
}
int A[M],m;
inline void modify(int u,int v){for(u|=m;u;u>>=1)A[u]=v;}
inline int query(int u,int v)
{
	for(u+=m+1;u>1;u>>=1)if((u&1)&&v<=A[u^1])
	{
		for(u^=1;u<m;u=u<<1|(v<=A[u<<1|1]));
		return u^m;
	}
	return 0;
}
int L[N],R[N],U[N],V[N],X[N],a[N],h[N];
int sta[10],top;
void write(int x) {
	do sta[++top]=x%10,x/=10;while(x);
	while(top)putchar(sta[top--]+'0');
	putchar('\n');
}
int main()
{
	cerr<<1<<endl;
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	int n,q;
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read(),c[a[i]]++;
	for(int i=1;i<=n;i++)b[i]=read(),d[b[i]]++;
	for(int i=1;i<=n;i++)c[i]+=c[i-1],d[i]+=d[i-1];
	for(int i=1;i<=n;i++)e[d[b[i]]--]=a[i];
	memcpy(b,d+1,n<<2),b[n]=n;
	for(int i=1,j=0;i<=n;i++)for(;j<b[i];a[h[j]=c[e[j]]--]=i)j++;
	memcpy(b,c+1,n<<2),memset(c+1,0,n<<2),memset(d+1,0,n<<2),memset(e+1,0,n<<2);
	for(int i=0;i<q;i++)d[i]=read(),f[i]=read(),c[i]=read(),e[i]=read(),c[i]=b[c[i]-1]+1,d[i]=b[d[i]];
	memset(b+1,0,n<<2);
	for(int i=0;i<q;i++)b[d[i]]++;
	for(int i=1;i<=n;i++)b[i]+=b[i-1];
	for(int i=0;i<q;i++)X[--b[d[i]]]=i;
	for(int i=0;i<q;i++)L[i]=c[X[i]],R[i]=d[X[i]],U[i]=e[X[i]],V[i]=f[X[i]];
	for(m=1;m<n+2;m<<=1);
	memset(b+1,0,n<<2),memset(c,0,q<<2),memset(d,0,q<<2),memset(e,0,q<<2),memset(f,0,q<<2);
	for(int i=0,j=0;i<q;V[i]=query(V[i],L[i]),i++)for(;j<R[i];modify(a[j],j))j++;
	for(int i=0;i<q;i++)if(V[i]<U[i])L[i]=R[i]+1;
	for(int i=0;i<q;i++)if(L[i]<=R[i])b[L[i]]++;
	for(int i=1;i<=n;i++)b[i]+=b[i-1];
	b[n+1]=b[n];
	for(int i=0;i<q;i++)if(L[i]<=R[i])c[--b[L[i]]]=i;
	for(int i=n,j=b[n+1];i;i--)for(d[a[i]]=i;b[i]<j;L[c[j]]=V[c[j]]<U[c[j]]?R[c[j]]+1:d[V[c[j]]])j--;
	memset(b+2,0,n<<2),memset(c,0,q<<2),memset(d+1,0,n<<2),dfs(a,h,n,L,R,U,V,X,q);
	for(int i=0;i<q;i++)write(x[i]);
	return 0;
}
