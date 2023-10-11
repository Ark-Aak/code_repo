#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
const int Maxn=1e6+5;
int n,k;
int a[Maxn];
int vis[Maxn];
priority_queue<pair<int,int> >heap;
priority_queue<pair<int,int> >heap1;
signed main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	read(n);read(k);
	for(int i=1;i<=n;i++)read(a[i]);
	if(k==1){
		for(int i=1;i<=n;i++)
			heap.push({a[i],i}),
			heap1.push({-a[i],i});
		int cnt=n,ans=0;
		while(cnt>1){
			pair<int,int>top{0,0};
			while(vis[heap.top().second])heap.pop();
			top=heap.top();
			vis[top.second]=1;
			ans+=top.first;
			while(vis[heap1.top().second])heap1.pop();
			top=heap1.top();
			vis[top.second]=1;
			ans-=top.first;
			cnt-=2;
		}
		printf("%lld",ans);
	}
	return 0;
}

