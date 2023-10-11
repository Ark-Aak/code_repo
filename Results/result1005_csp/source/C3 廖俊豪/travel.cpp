#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MAXN=100005,mod=998244353;
int n,k,m;
struct node{
	int l,r,s;
}p[MAXN];
int ops[MAXN];
int f[MAXN][2];
bool cmp(node A,node B){
	return A.r<B.r;
}
int poww(int x,int y){
	int sum=1;
	while(y){
		if(y&1){
			sum=sum*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	}
	return sum;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=m;i++){
		cin>>p[i].l>>p[i].r>>p[i].s;
		if(k==0&&p[i].s==1){
			cout<<0<<endl;
			return 0;
		}
	}
	if(k==0){
		cout<<1<<endl;
		return 0;
	}
	int ops=1;
	for(int i=1;i<=m;i++)if(p[i].l!=1)ops=0;
	if(ops==1){
		sort(p+1,p+m+1,cmp);
		int tot=1;
		for(int i=2;i<=m;i++){
			if(p[i].r!=p[i-1].r)tot++;
			if(p[i].r==p[i-1].r&&p[i].s!=p[i-1].s){
				cout<<0<<endl;
				return 0;
			}
		}
		cout<<poww(poww(2,n-tot),k)<<endl;
		return 0;
	}
	return 0;
} 
