#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
const int N=5e5+10;
int n,q,ans,L[N],R[N],tot[N];
int main()
{
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) L[i]=read(),R[i]=read();
	int m,x;
	while(q--)
	{
		m=read();ans=0;
		while(m--) x=read(),++tot[x];
		for(int i=1;i<=n;i++) tot[i]+=tot[i-1];
		for(int i=1;i<=n;i++)
			ans+=((tot[R[i]]-tot[L[i]-1])&1);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) tot[i]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
