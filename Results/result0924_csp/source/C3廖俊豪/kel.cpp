#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r;
int vis[3005][3005];
int st[3005];
int d[3005];
void dfs(int x,int len){
	if(len==n){
		for(int i=1;i<=n;i++)
			cout<<st[i]+l-1<<endl;
		exit(0);
	}
	for(int i=1;i<=r-l+1;i++)
		if(vis[x][i]==0){
			vis[x][i]=1;
			st[len+1]=i;
			dfs(i,len+1);
			vis[x][i]=0;
		}
}
bool cmp(int A,int B){
	return d[A]>d[B];
}
void w(int x,int len){
	if(len==n){
		for(int i=1;i<=n;i++)
			cout<<st[i]+l-1<<endl;
		exit(0);
	}
	d[x]--;
	int b[3005];
	memset(b,0,sizeof b);
	for(int i=1;i<=r-l+1;i++){
		if(vis[x][i]==0){
			b[i]=i;
		}else{
			b[i]=0;
		}
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(b[i]==0)break;
		vis[x][i]=1;
		st[len+1]=i;
		dfs(i,len+1);
		vis[x][i]=0;
	}
}
signed main(){
	freopen("kel.in","r",stdin);
	freopen("kel.out","w",stdout);
	cin>>n>>l>>r;
	if(n<=10){
		dfs(0,0);
		cout<<"Shinomiya";
	}else{
		for(int i=1;i<=n;i++)d[i]=n;
		w(0,0);
		cout<<"Shinomiya"<<endl;
	}
	return 0;
}

