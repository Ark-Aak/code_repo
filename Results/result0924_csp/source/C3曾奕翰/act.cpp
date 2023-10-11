#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
int qzhx[1000005];
int qzhy[1000005];
int p[1000005];
int g[1000005];
struct XXX{
	int a,b;
}a[1000005];
bool cmp(XXX xx,XXX yy){
	if(xx.a==yy.a) return xx.b<yy.b;
	return xx.a<yy.a;
}
signed  main(){
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		qzhx[i]=qzhx[i-1];
		qzhy[i]=qzhy[i-1];
		if(a[i].a!=a[i-1].a) qzhx[i]++;
		if(a[i].b!=a[i-1].b) qzhy[i]++;
		p[i]=a[i].a;
		g[i]=a[i].b;
	}
	qzhx[n+1]=qzhx[n];
	qzhy[n+1]=qzhy[n];
	while(q--){
		int x,y;
		cin>>x>>y;
		int ri=upper_bound(p+1,p+n+1,x)-p-1;
		int le=upper_bound(p+1,p+n+1,x-1)-p;
		int asf=upper_bound(g+le,g+ri,y)-g-1;
		if(x==a[ri].a&&y==a[asf].b){
			cout<<"Bob"<<endl;
			continue;
		}
		if(x==a[ri].a||y==a[asf].b){
			cout<<"Alice"<<endl;
			continue;
		}
		int l=x-qzhx[ri];
		int r=y-qzhy[ri];
		if((l^r)==0)
			cout<<"Alice"<<endl;
		else
			cout<<"Bob"<<endl;
	}
	return 0;
}

