#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=7e5+5;

int n,f[N],f1[N],ans=0,Ans;

struct node {
	int cost,a,b,c,d;
} v[N];

inline int find(int x) {
	if(f[x]==x) return f[x];
	else return f[x]=find(f[x]);
}
inline int read();
inline cmp(node a,node b) {
	return a.cost<b.cost;
}


signed main() {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();
	F(i,1,2*n) f[i]=i;
	F(i,1,n) {
		v[i].cost=read(),v[i].a=read(),v[i].b=read(),v[i].c=read(),v[i].d=read();
		f[find(v[i].a)]=find(v[i].b);
		f[find(v[i].c)]=find(v[i].d);
	}
	sort(v+1,v+n+1,cmp);
	Ans-=1;
	F(i,1,n) {
		int u=find(v[i].a),v1=find(v[i].b),uu=find(v[i].c),vv=find(v[i].d);
		f[u]=find(v1);
		f[uu]=find(vv);
		if(f[u]==f[uu]) continue;
		ans+=v[i].cost;
		Ans++;
		f[u]=find(uu);
	}
//	cout<<Ans<<endl;
	cout<<ans;
	return 0;
}

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
