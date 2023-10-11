#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=1e5; 
int n,m,t;
struct node{
	int l,r;
}a[Maxn];
int main(){
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	if(n==m){
		cout<<t;
		return 0;
	}
	else{
		cout<<(t-(n-1)*m);
		return 0;
	}
	return 0;
}


