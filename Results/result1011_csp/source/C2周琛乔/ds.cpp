#include<bits/stdc++.h>
using namespace std;
const int N=8e5+5;
inline void read(int &x){
	int f=1;x=0;char c=getchar();
	while(!isdigit(c)&&c^'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,q,k[N],d,u,l,r,pre[N],ans;
struct node{int x,y;}a[N];
inline bool cmp(node x,node y){return x.x==y.x?x.y<y.y:x.x<y.x;}
void print(int x){
	if(x>9) print(x/10);
	putchar(48+x%10);
}
int main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	read(n),read(q);
	for(int i=1;i<=n;i++) read(a[i].x);
	for(int i=1;i<=n;i++) read(a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=1,p=1;i<=n;i++){
		while(p<=n&&a[p].x<=i) ++p;
		k[i]=p;
	}
	for(int i=2;i<=n;i++){
		if(a[i].x>a[i-1].x) pre[i]=i-1;
		else pre[i]=pre[i-1];
	}
	for(int i=1;i<=q;i++){
		read(u),read(r);
		read(d),read(l);
		ans=0;
		for(int i=k[u]-1,mx=l,mx2;i&&i>=k[d-1];){
			mx2=0;
			for(int j=i;a[j].x==a[i].x&&a[j].y>=mx;--j) 
				if(a[j].y<=r) ++ans,mx2=max(mx2,a[j].y);
			mx=max(mx,mx2);
			i=pre[i];
		}
		print(ans);
		putchar('\n');
	}
	return 0;
}

