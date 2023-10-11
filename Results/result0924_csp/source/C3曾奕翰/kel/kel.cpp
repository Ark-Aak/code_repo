#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r;
int a[1005];
int gg[1005];
bool flag;
int wei(int x){
	int sum=0;
	while(x){
		x/=10;
		sum++;
	}
	return sum;
}
bool check(int x){
	int p;
	while(x>9){
		if(a[x%100]&&p!=x%100) return 0;
		p=x%100;
		x/=10;
	}
	return 1;
}
void dfs(int ws,int as,int sh){
	if(ws>n){
	//	for(int i=0;i<=100;i++) cout<<a[i]<<" ";
	//	cout<<endl;
		return;
	}
	if(flag) return;
	if(ws==n){
		for(int i=1;i<as;i++){
			cout<<gg[i];
		}
		flag=1;
		return;
	}
	for(int i=max(l,sh+1);i<=r;i++){
		int nx=i,p;
		while(nx>9){
			p=nx;
			nx/=10;
		}
			
		if(as==1||(check(i)&&(a[gg[as-1]%10*10+nx]==0||gg[as-1]%10*10+p))){
			if(as!=1)a[gg[as-1]%10*10+nx]=1;
			int x=i;
			int ppp=0;
			while(x>9){
				a[x%100]=1;
				x/=10;
				ppp++;
			}
			gg[as]=i;
			dfs(ws+ppp+1,as+1,i);
			x=i;
			while(x>9){
				a[x%100]=0;
				x/=10;
			}
			if(as!=1)a[gg[as-1]%10*10+nx]=0;
		}
	}
}
signed  main(){
	freopen("kel.in","r",stdin);
	freopen("kel.out","w",stdout);
	cin>>n>>l>>r;
	if(l==0&&r==0){
		cout<<0;
		return 0;
	}
	if((r-l)*10<n) {
		cout<<"Shinomiya";
		return 0;
	}
	if(n>=100*2){
		cout<<"1Shinomiya";
		return 0;
		
	}
	dfs(0,1,0);
	if(!flag){
		cout<<"Shinomiya";
		return 0;
		
	}
	return 0;
}

