#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=1e6+5,inf=INT_MAX;

int a[N],n,x,y,z;
struct node {
	int val,id;
} xx[N],yy[N],zz[N],xy[N],xz[N],yz[N],xyz[N];

string s;

inline int read();

inline int calc(int x,int y) {
	return (x/y+(x%y!=0))*y-x;
}

bool cmp(node a,node b) {
	return a.val<b.val;
}


signed main() {
	cin>>n>>x>>y>>z;
	int xxy,xxz,yyz,xyzz;
	xxy=x*y/__gcd(x,y),xxz=x*z/__gcd(x,z),yyz=y*z/__gcd(y,z),xyzz=xxy*z/__gcd(xxy,z);
	//cout<<xyzz<<endl;
	F(i,1,n) {
		int u;
		cin>>u;
		xx[i]=(node) {
			calc(u,x),i
		};
		yy[i]=(node) {
			calc(u,y),i
		};
		zz[i]=(node) {
			calc(u,z),i
		};
		xy[i]=(node) {
			calc(u,xxy),i
		};
		xz[i]=(node) {
			calc(u,xxz),i
		};
		yz[i]=(node) {
			calc(u,yyz),i
		};
		xyz[i]=(node) {
			calc(u,xyzz),i
		};
	}
	sort(xx+1,xx+1+n,cmp);
	sort(yy+1,yy+1+n,cmp);
	sort(zz+1,zz+1+n,cmp);
	sort(xy+1,xy+1+n,cmp);
	sort(xz+1,xz+1+n,cmp);
	sort(xyz+1,xyz+1+n,cmp);
	sort(yz+1,yz+1+n,cmp);
	int ans=LONG_LONG_MAX;
	if(xz[1].id==yy[1].id&&n!=1) ans=min(ans,min(xz[1].val+yy[2].val,xz[2].val+yy[1].val));
	else if(n!=1)ans=min(ans,xz[1].val+yy[1].val);
	if(xy[1].id==zz[1].id&&n!=1) ans=min(ans,min(xy[1].val+zz[2].val,xy[2].val+zz[1].val));
	else if(n!=1)ans=min(ans,xy[1].val+zz[1].val);
	if(yz[1].id==xx[1].id&&n!=1) ans=min(ans,min(yz[1].val+xx[2].val,yz[2].val+xx[1].val));
	else if(n!=1)ans=min(ans,yz[1].val+xx[1].val);
	 if(n>=3) {
		for(int i=1; i<=3; i++)
			for(int j=1; j<=3; j++)
				for(int k=1; k<=3; k++) {
					if(xx[i].id!=yy[j].id&&yy[j].id!=zz[k].id&&zz[k].id!=xx[i].id){
						ans=min(ans,xx[i].val+yy[j].val+zz[k].val);
					}
				}
	}
	ans=min(ans,xyz[1].val);
	cout<<ans;
	return 0;
}

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-f;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}


