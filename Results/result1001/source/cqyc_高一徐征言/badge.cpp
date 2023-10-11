#include<bits/stdc++.h>
#define ll long long
template<typename T> inline T read(T &num)
{
	register T x=0,f=0;
	register char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
using namespace std;
const int N=5e5+5;
int n,q,l[N],r[N],m,ans,cnt[N],u[N][7],cnt2[N][7],A[N];
void solve1()
{
	while(q--)
	{
		scanf("%d",&m);
		for(int a=1;a<=n;a++) cnt[a]=0;
		for(int a=1;a<=m;a++)
		{
			int x;
			scanf("%d",&x);
			for(int b=1;b<=n;b++)
			{
				if(l[b]<=x&&r[b]>=x) cnt[b]^=1;
			}
		}
		ans=0;
		for(int a=1;a<=n;a++) ans+=cnt[a];
		printf("%d\n",ans);
	}
}
void solve2()
{
	for(int a=1;a<=n;a++) u[l[a]][r[a]-l[a]]++;
	while(q--)
	{
		scanf("%d",&m);
		ans=0;
		for(int a=1;a<=m;a++)
		{
			scanf("%d",&A[a]);
			for(int l=max(1,A[a]-5);l<=A[a];l++)
			{
				for(int r=A[a];r<=min(l+5,n);r++)
				{
					ans-=cnt2[l][r-l]*u[l][r-l];
					cnt2[l][r-l]^=1;
					ans+=cnt2[l][r-l]*u[l][r-l];
				}
			}
			//cout<<ans<<endl;
		}
		printf("%d\n",ans);
		for(int a=1;a<=m;a++)
		{
			for(int l=max(1,A[a]-5);l<=A[a];l++)
			{
				for(int r=A[a];r<=min(l+5,n);r++)
				{
					cnt2[l][r-l]^=1;
				}
			}
		}
	}
}
int main()
{
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout); 
	scanf("%d%d",&n,&q);
	for(int a=1;a<=n;a++) scanf("%d%d",&l[a],&r[a]);
	if(n<=3000)
	{
		solve1();
		return 0;
	}
	solve2();
} 
