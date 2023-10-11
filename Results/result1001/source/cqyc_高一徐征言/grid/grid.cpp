#include<bits/stdc++.h>
#define ll long long
#define i128 __int128
template<typename T> inline T read(T &num)
{
	register T x=0,f=0;
	register char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
using namespace std;
const int D=31,N=105;
int T,n,m,d[D],g[N][N];
i128 ans;
int main()
{
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout); 
    for(int a=0;a<=100;a++)
    {
    	for(int b=0;b<=100;b++) g[a][b]=__gcd(a,b);
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		if(min(n,m)==1)
		{
			printf("0\n");
			continue;
		}
		ans=0;
		if(min(n,m)==2)
		{
			int x=max(n,m);
			for(int a=3;a<=x+1;a++) ans+=(i128)2*x*a*(x+2-a);
			d[0]=0;
			i128 h=ans;
			while(h>0)
			{
				d[++d[0]]=h%10;
				h/=10;
			}
			for(int a=d[0];a>=1;a--) printf("%d",d[a]);
			printf("\n");
			//printf("%lld\n",ans);
			continue;
		}
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=m;b++)
			{
				for(int c=1;c<=n;c++)
				{
					for(int d=1;d<=m;d++)
					{
						if(a==c&&b==d) continue;
						int x=abs(a-c),y=abs(b-d);
					//	cout<<a<<" "<<b<<" "<<c<<" "<<g[x][y]<<endl;
						if(x==0) ans+=(i128)g[x][y]*m*(n-1);
						else if(y==0) ans+=(i128)g[x][y]*n*(m-1);
						else ans+=(i128)g[x][y]*((i128)n*m-2-min((min(a,c)-1)/(x/g[x][y]),(min(b,d)-1)/(y/g[x][y]))-min((n-max(a,c))/(x/g[x][y]),(m-max(b,d))/(y/g[x][y])));
				//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<(int)ans<<endl;
					}
				}
			}
		}
		ans/=2;
		d[0]=0;
		i128 h=ans;
		while(h>0)
		{
			d[++d[0]]=h%10;
			h/=10;
		}
		for(int a=d[0];a>=1;a--) printf("%d",d[a]);
		printf("\n");
	}
} 
