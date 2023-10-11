#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int p,q,r,a,b,c;
int ans;
void dfs(int x,int y,int z,int s){
	if(s>=ans) return;
	if(x==a&&y==b&&z==c){
		ans=s;
		return;
	}
	for(int i=-5;i<=5;i++){
		if(s>=ans) return;
		if(i!=0){
			if(x!=a) dfs(x+i,y,z,s+1);
			if(y!=b) dfs(x,y+i,z,s+1);
			if(z!=c) dfs(x,y,z+i,s+1);
			if(x!=a&&y!=b) dfs(x+i,y+i,z,s+1);
			if(x!=a&&z!=c) dfs(x+i,y,z+i,s+1);
			if(y!=b&&z!=c) dfs(x,y+i,z+i,s+1);
			dfs(x+i,y+i,z+i,s+1);
		}
		if(i!=1){
			if(x!=a) dfs(x*i,y,z,s+1);
			if(y!=b) dfs(x,y*i,z,s+1);
			if(z!=c) dfs(x,y,z*i,s+1);
			if(x!=a&&y!=b) dfs(x*i,y*i,z,s+1);
			if(x!=a&&z!=c) dfs(x*i,y,z*i,s+1);
			if(y!=b&&z!=c) dfs(x,y*i,z*i,s+1);
			dfs(x*i,y*i,z*i,s+1);
		}	
	}
}
signed main(){
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld %lld",&p,&q,&r);
		scanf("%lld %lld %lld",&a,&b,&c);
		ans=3;
		if(p==a) ans--;
		if(q==b) ans--;
		if(r==c) ans--;
		if(abs(p)<2&&abs(q)<2&&abs(r)<2&&abs(a)<2&&abs(b)<2&&abs(c)<2){
			dfs(p,q,r,0);
			printf("%lld\n",ans);
		}
		else{
			int x,y,z;
			x=a-p;y=b-q;z=c-r;
			if(p==a&&q==b&&r==c) printf("1\n");
			else if(x==y&&y==z) printf("1\n");
			else if((x==y&&c==r)||(x==z&&b==q)||(y==z&&a==p)) printf("1\n");
			else if(a%p==0&&b%q==0&&c%r==0&&a/p==b/q&&a/p==c/r) printf("1\n");
			else if((a%p==0&&b%q==0&&a/p==b/q&&c==r)||(a%p==0&&c%r==0&&a/p==c/r&&b==q)||(c%r==0&&b%q==0&&c/r==b/q&&a==p)) printf("1\n");
			else if((x==y&&x!=z)||(x==z&&x!=y)||(y==z&&x!=y)) printf("2\n");
			else if((a%p==0&&b%q==0&&a/p==b/q&&(c%r!=0||a/p!=c/r))||(a%p==0&&c%r==0&&a/p==c/r&&(b%q!=0||a/p!=b/q))||(c%r==0&&b%q==0&&c/r==b/q&&(a%p!=0||a/p!=c/r))) printf("2\n");
			else printf("3\n");
		}
	}
	return 0;
}
/*
2
3 5 7
6 5 10
8 6 3
9 7 8
*/

