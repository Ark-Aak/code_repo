#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=1e6+5;
int n,q;
int u[N],r[N],d[N],l[N],ans[N];
struct node{
	int x,y;
}a[N];
struct edge{
	int u,r,d,l,id;
}qu[N];
bool cmp(node a,node b){
	return a.x==b.x?a.y<b.y:a.x>b.x;
}
bool cmp2(node a,node b){
	return a.y==b.y?a.x>b.x:a.y>b.y;
}
bool cmp1(edge x,edge y){
	return x.r==y.r?x.u<y.u:x.r>y.r;
}
signed main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++) a[i].x=read();
	for(int i=1;i<=n;i++) a[i].y=read();
		sort(a+1,a+n+1,cmp);
		for(int p=1;p<=q;p++){
//			qu[i].u=read();qu[i].r=read();qu[i].d=read();qu[i].l=read();qu[i].id=i;
			//----35pts~55ptsO(n*q)--------
			u[p]=read();r[p]=read();d[p]=read();l[p]=read();
			int mx=0,ans=0;
			for(int i=1;i<=n;i++){
				if(a[i].x>=d[p] && a[i].x<=u[p] && a[i].y>=l[p] && a[i].y<=r[p]){
					if(a[i].y>=mx) ans++;
					mx=max(mx,a[i].y);
				}
			}cout << ans << "\n";
		}
	
	
	return 0;
}


