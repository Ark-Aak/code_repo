#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=2e5+5; 

int n,Q,a[N],b[N],x,y;

signed main(){
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	cin>>n>>Q;
	F(i,1,n){
		cin>>a[i];	
	}
	F(i,1,n){
		cin>>b[i];
	}
	F(i,1,Q){
		cin>>x>>y;
		if(x<0&&y<0){cout<<"Bob"<<endl;continue;}
		if((x+y)%2){cout<<"Alice"<<endl;continue;}
		else cout<<"Bob"<<endl;
	}
	return 0;
}
