#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
string a,t;
bool ans;
int n;
bool c=0;
void dfs(int x,int l,int r){
	if(c)return;
	if(x==n){
		if(abs(l-r)%11==0)ans=1;
		return;
	}
	dfs(x+1,l+a[x]-'0',r);
	dfs(x+1,l,r+a[x]-'0');
}
int main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	cin>>n;
	cin>>a>>t;
	int o=1;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1])o=0;
	}
	if(o==0){
		if(n<=10){
			dfs(0,0,0);
			if(ans)cout<<"yoimiya";
			else cout<<"oimiya";
		}
		else cout<<"oimiya";
	}
	else{
		if(a[1]=='o')cout<<"oimiya";
		else if(a[1]=='y'&&n>=2)cout<<"yoimiya";
		else cout<<"oimiya";
	}
	return 0;
} 
