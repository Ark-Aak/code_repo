#include<bits/stdc++.h>
using namespace std;

long long n,p,q,r,a,b,c;

int T;

signed main(){
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%lld%lld%lld%lld%lld%lld",&p,&q,&r,&a,&b,&c);
	//	cout<<i<<" ";
		if(p==a&&q==b&&r==c){
			cout<<0<<endl;
			continue;
		}
		if(a==0&&b==0&&c==0) {cout<<1<<endl;continue;}
		if(a==0){
			if(q==b) {cout<<1<<endl;continue;}
			if(r==c) {cout<<1<<endl;continue;}
			if(b==0||c==0||b==c) {cout<<2<<endl;continue;}
			goto t;
		}
		if(b==0){
			if(p==a) {cout<<1<<endl;continue;}
			if(r==c) {cout<<1<<endl;continue;}
			if(a==0||c==0||a==c) {cout<<2<<endl;continue;}
			goto t;
		}
		if(c==0){
			if(p==a){cout<<1<<endl;continue;}
			if(q==b){cout<<1<<endl;continue;}
			if(a==0||b==0||a==b) {cout<<2<<endl;continue;}
			goto t;
		}
		if(p&&q&&r&&(a%p==0)&&(b%q==0)&&(c%r==0)&&a/p==b/q&&b/q==c/r){cout<<1<<endl;continue;}
		if(p-a==q-b&&q-b==r-c){
			cout<<1<<endl;
			continue;
		}
		if(p==a){
			if(q==b||r==c) {cout<<1<<endl;continue;}
			if(q-b==r-c) {cout<<1<<endl;continue;}
			if(q&&r&&(b%q==0)&&(c%r==0)&&b/q==c/r){cout<<1<<endl;continue;}
		}		
		if(q==b){
			if(p==a||r==c){cout<<1<<endl;continue;} 
			if(p-a==r-c) {cout<<1<<endl;continue;}
			if(p&&r&&(a%p==0)&&(c%r==0)&&a/p==c/r){cout<<1<<endl;continue;}
		}
		if(r==c){
			if(p==a||q==b){cout<<1<<endl;continue;} 
			if(p-a==q-b) {cout<<1<<endl;continue;}
			if(p&&q&&(a%p==0)&&(b%q==0)&&a/p==b/q){cout<<1<<endl;continue;}
		}	
		t:;
		if(p-a==q-b){cout<<2<<endl;continue;}
		if(q-b==r-c){cout<<2<<endl;continue;}
		if(r-c==p-a){cout<<2<<endl;continue;}
		int x=p-a,y=q-b,z=r-c;
		if(x+y==z||x+z==y||y+z==x){cout<<2<<endl;continue;}
		x=a-p,y=b-q,z=c-r;
		
		cout<<3<<endl;
	}	

	return 0;
}

