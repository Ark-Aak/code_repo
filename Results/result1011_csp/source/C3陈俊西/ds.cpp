#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
struct Node{
	int x,y;
}a[N];
int n,Q,ans,tp,s[N];
bool cmp(Node a,Node b){
	if(a.x==b.x) a.y<b.y;
	return a.x<b.x;
}
signed main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	n=read(),Q=read();
	for(int i=1;i<=n;i++) a[i].x=read();
	for(int i=1;i<=n;i++) a[i].y=read();
	sort(a+1,a+1+n,cmp);
	while(Q--){
		int U=read(),R=read(),D=read(),L=read();
		ans=tp=0;
		for(int i=1;i<=n;i++)
			if(a[i].x>=D&&a[i].x<=U&&a[i].y>=L&&a[i].y<=R) s[++tp]=i;				
		
		int r=0,maxy=0;
		for(int i=tp;i>=1;i--){
			if(a[s[i]].x!=a[s[i+1]].x){
				for(int j=i+1;j<=r;j++)
					maxy=max(maxy,a[s[j]].y);
				r=i;
			}
			if(a[s[i]].y>=maxy) ans++;
		}
		printf("%lld\n",ans);
	}		
	return 0;
}
/*
6 5
3 4 1 4 5 5
1 2 3 4 5 1
3 5 3 2
4 5 3 2
5 5 3 1
5 3 1 1
5 5 1 1

0 2 2 3 2
*/
