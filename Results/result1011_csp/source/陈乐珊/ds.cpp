#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int ans[N];
struct don{
	int x,y;
}d[N];
struct ques{
	int u,r,d,l,id,ans;
}q[N];
int cmp1(don a,don b) {
	if(a.x==b.x) return a.y<b.y;
	return a.x > b.x ;
}
int cmp2(ques a,ques b) {
	if(a.d==b.d) return a.r<b.r;
	return a.d > b.d ;
}
int cmp(ques a,ques b) {
	return a.id<=b.id ;
}
int q1[N],q2[N],dl,dr,ql,qr,m[N];
int main() {
	freopen("ds.in", "r", stdin);
	freopen("ds.out", "w", stdout);
	int n,Q;
	cin>>n>>Q;
	for(int i=1;i<=n;i++) {
		cin>>d[i].x;
	}
	for(int i=1;i<=n;i++) {
		cin>>d[i].y;
	}
	for(int i=1;i<=Q;i++) {
		cin>>q[i].u>>q[i].r>>q[i].d>>q[i].l;
		q[i].id=i;
	}
	sort(d+1,d+n+1,cmp1) ;
	sort(q+1,q+Q+1,cmp2) ;
	dl=ql=1;
	int cnt1=0,cnt2=0;
	for(int i=n;i>=1;i--) {
		while(d[cnt1+1].x==i&&cnt1<n) {
			q1[++dr]=++cnt1;
//			cout<<cnt1<<" "<<d[cnt1].x<<" "<<d[cnt1].y<<"\n";
		} 
//		cout<<"\n";
		while(q[cnt2+1].u>=d[q1[dr]].x) {
			q2[++qr]=++cnt2;
			q[cnt2].ans=0;
		}
		while(i<q[q2[ql]].u) {
			ql++;
		}
		for(int i=dl;i<=dr;i++) {
			for(int j=ql;j<=qr;j++) {
				if(d[q1[i]].y>=q[q2[j]].l&&d[q1[i]].y<=q[q2[j]].r&&d[q1[i]].y>=m[q2[j]]) {
					q[q2[j]].ans ++ ;
					m[q2[j]]=max(m[q2[j]],d[q1[i]].y) ;
				}
			}
		}
		dr=0;
	}
	sort(q+1,q+Q+1,cmp) ;
	for(int i=1;i<=Q;i++) cout<<q[i].ans<<"\n" ;
	return 0;
}
/*
1
1 3 4 6 7

2
4 6 
*/

