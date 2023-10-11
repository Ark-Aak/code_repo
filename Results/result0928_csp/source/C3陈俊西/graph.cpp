#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,inf=1e18;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,s[N][2],tp,ans;
struct Node{
	int x,y;
}a[N];
bool cmp(Node a,Node b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
priority_queue<int,vector<int>,greater<int> > Q;
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].x!=a[i-1].x) s[++tp][0]=a[i].y;
		if(a[i].x!=a[i+1].x) s[tp][1]=a[i].y;
	}
	for(int i=1;i<=tp;i++){
		int minn=s[i][0];
		while(!Q.empty()){
			if(Q.top()<=s[i][1]){
				minn=min(minn,Q.top());
				Q.pop();
			}
			else break;
		}
		Q.push(minn);
	}
	while(!Q.empty()) Q.pop(),ans++;
	printf("%lld",ans);
	return 0;
}
