#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;char c=getchar();
	while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}
	while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();
	return s*w;
}
int a[22];
long long ans;
bool t[22];
int n;
void dfs(int x,int s){
	if(x>n){
		ans+=s-1;
		return;
	}
	for(int i=0;i<=a[x];i++){
		t[i]=1;
		int o=s;
		while(t[o])o++;
		dfs(x+1,o);
		t[i]=0;
	}
}
int main() {
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	n=read();
	if(n<=20){
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
//		sort(a+1,a+n+1);
		dfs(1,0);
		cout<<ans;
	}
	else {
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%1000000007;
		cout<<ans;
	}
	return 0;
}


