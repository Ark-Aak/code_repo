#include<bits/stdc++.h>
#define lowbit(x) x & -x;
#define int long long 
#define N 400010
using namespace std;
int re() {
	int p=0; char i=getchar();
	while(i<'0'||i>'9')	i=getchar();
	while(i>='0'&&i<='9')	p=p*10+i-'0',i=getchar();
	return p;
}
int n,ans;
int a[N],f[N];
int tree[N];
int ask(int x) {
	int sum=0;
	while(x>0) {
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
void add(int x,int k)
{
	while(x<=2*n) {
		tree[x]+=k;
		x+=lowbit(x);
	}	
}
signed main()
{
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
	n=re();
	for(int i=1;i<=n;i++) {
		a[i]=re();
		f[i]=n+1;
	}
	for(int i=n;i>=1;i--)
	{
		ans+=ask(f[a[i]]-1);
		add(f[a[i]],-1);
		f[a[i]]=i;
		add(f[a[i]],1);
	}
	cout<<ans<<endl;
}
