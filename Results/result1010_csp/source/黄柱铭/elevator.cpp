#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=2e6+5;
struct Node{
	int u,x,cs;
};

int n,k,ti=0,res;
int ans;
int sum[N],vis[N],a[N],pre[N],tr[N];
int mx;
bool bk[N];
signed main(){
//	freopen("elevator.in","r",stdin);
//	freopen("elevator.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++) cin >> a[i],sum[a[i]]++,mx=max(mx,a[i]);
	
	cout << ans << "\n";
	return 0;
}


