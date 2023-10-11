#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=5e5+5;

int a[N],n,l[N],r[N],Tree[N],ans=0;

inline int read();

int vis[N];

queue <int> Q[N];

inline int lowbit(int x) {
	return x&(-x);
}

inline void Add(int x,int val) {
	for(; x<=n; x+=lowbit(x)) Tree[x]+=val;
}

inline int Query(int x) {
	int sum=0;
	for(; x; x-=lowbit(x)) sum+=Tree[x];
	return sum;
}

signed main() {
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);	
	n=read();
	F(i,1,n) a[i]=read(),Q[a[i]].push(i);
	F(i,1,500000) Q[i].push(n);
	F(i,1,n) {
		if(vis[a[i]]) {Add(i,1),vis[a[i]]++;}
		vis[a[i]]+=1;
	}
	F(i,1,n) {
		l[i]=Q[a[i]].front();
		Q[a[i]].pop();
		r[i]=Q[a[i]].front();
	}
	F(i,1,n) {
		
		ans+=r[i]-l[i];
		ans=ans-max((Query(r[i])-Query(l[i]-1)),0ll);
		vis[a[i]]--;
		//cout<<Query(r[i])<<" "<<Query(l[i])<<endl;
		if(vis[a[i]]!=0) Add(r[i],-1);
		//cout<<i<<" "<<ans<<endl;
//		F(j,1,n) cout<<Tree[j]<<" ";
//		cout<<endl;
	}
	cout<<ans;
	return 0;//Ä¾Çà±£ÎÀÕ½
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
