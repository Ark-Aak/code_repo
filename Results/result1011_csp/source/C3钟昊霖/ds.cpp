#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)

inline int read();

const int N=5e5+5,inf=INT_MAX;
struct node {
	int x,y;
} a[N];
int n,Q,ans[N],u,r,d,l;
inline bool cmp(node a,node b) {
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
inline int Ef1(int num) {
	int l=1,r=n+1;
	while(l<r) {
		int mid=(l+r)>>1;
		if(a[mid].x>=num) r=mid;
		else l=mid+1;
	}
	return l;
}
inline void Subtask1() {
	sort(a+1,a+n+1,cmp);
	while(Q--) {
		u=read(),r=read(),d=read(),l=read();
		int ans=0;
		//	int l = Ef1(d);
		for(int i=1; i<=n; i++) {
			if(a[i].x>u) break;
			if(a[i].y>r||a[i].y<l) continue;
			if(a[i].x<d||a[i].x>u) continue;
			for(int j=i+1; j<=n; j++) {
				if(a[j].x>u) break;
				if(a[j].y>r||a[j].y<l) continue;
				if(a[j].x<d||a[j].x>u) continue;
				if(a[i].x<a[j].x&&a[i].y<a[j].y) {
					goto t;
				}
			}
			ans++;
t:
			;
		}
		printf("%lld\n",ans);
	}
	return;
}

inline void Subtask2() {

	
}

signed main() {
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	n=read(),Q=read();
	F(i,1,n) a[i].x=read();
	F(i,1,n) a[i].y=read();
//	if(n<=5000&&Q<=5000) {
		Subtask1();
		return 0;
	//}
//	Subtask2();
	return 0;
}

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}

