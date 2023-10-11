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
const ll inf=0x3f3f3f3f3f3f3f3f;
int T,t[5],ck;
ll a[5],x[5];
int solve1(ll a,ll b,ll x,ll y)
{
	if(x-a==y-b) return 1;
	if(a!=0&&b!=0&&x%a==0&&y%b==0&&x/a==y/b) return 1;
	return 2;
}
bool check1()
{
	int h=0;
	if(t[1]==1) h++;
	if(t[2]==1) h++;
	if(t[3]==1) h++;
	if(h>1) return 0;
	h=0;
	if(t[1]==2) h++;
	if(t[2]==2) h++;
	if(t[3]==2) h++;
	if(h>1) return 0;
	ll A=inf,B=inf;
	for(int i=1;i<=3;i++) 
	{
		if(t[i]==1) A=x[i]-a[i];
		else if(t[i]==2)
		{
			if(a[i]!=0&&x[i]%a[i]==0) B=x[i]/a[i];
			else return 0;
		}
	}
	if(A!=inf&&B!=inf)
	{
		for(int i=1;i<=3;i++)
		{
			if(t[i]==3)
			{
				if((a[i]+A)*B==x[i]) ;
				else return 0;
			}
		}
		return 1;
	}
	if(A!=inf)
	{
		for(int i=1;i<=3;i++)
		{
			if(t[i]==3)
			{
				if(B==inf)
				{
					if(a[i]+A!=0&&x[i]%(a[i]+A)==0) B=x[i]/(a[i]+A);
					else return 0;
				}
				else
				{
					if((a[i]+A)*B==x[i]) ;
				    else return 0;
				}
			}
		}
		return 1;
	}
	if(B!=inf)
	{
		for(int i=1;i<=3;i++)
		{
			if(t[i]==3)
			{
				if(A==inf)
				{
					if(B!=0&&(x[i]-a[i]*B)%B==0) A=(x[i]-a[i]*B)/B;
					else return 0;
				}
				else
				{
					if((a[i]+A)*B==x[i]) ;
				    else return 0;
				}
			}
		}
		return 1;
	}
	if(a[1]-a[2]!=0&&(x[1]-x[2])%(a[1]-a[2])==0) B=(x[1]-x[2])/(a[1]-a[2]);
	else return 0;
	for(int i=1;i<=3;i++)
	{
		if(t[i]==3)
		{
			if(A==inf)
			{
				if(B!=0&&(x[i]-a[i]*B)%B==0) A=(x[i]-a[i]*B)/B;
				else return 0;
			}
			else
			{
				if((a[i]+A)*B==x[i]) ;
			    else return 0;
			}
		}
	}
	return 1;
}
bool check2()
{
	int h=0;
	if(t[1]==1) h++;
	if(t[2]==1) h++;
	if(t[3]==1) h++;
	if(h>1) return 0;
	h=0;
	if(t[1]==2) h++;
	if(t[2]==2) h++;
	if(t[3]==2) h++;
	if(h>1) return 0;
	ll A=inf,B=inf;
	for(int i=1;i<=3;i++) 
	{
		if(t[i]==1) B=x[i]-a[i];
		else if(t[i]==2)
		{
			if(a[i]!=0&&x[i]%a[i]==0) A=x[i]/a[i];
			else return 0;
		}
	}
	if(A!=inf&&B!=inf)
	{
		for(int i=1;i<=3;i++)
		{
			if(t[i]==3)
			{
				if(a[i]*A+B==x[i]) ;
				else return 0;
			}
		}
		return 1;
	}
	if(A!=inf)
	{
		for(int i=1;i<=3;i++)
		{
			if(t[i]==3)
			{
				if(B==inf)
				{
					B=x[i]-a[i]*A;
				}
				else
				{
					if(a[i]*A+B==x[i]) ;
				    else return 0;
				}
			}
		}
		return 1;
	}
	if(B!=inf)
	{
		for(int i=1;i<=3;i++)
		{
			if(t[i]==3)
			{
				if(A==inf)
				{
					if(a[i]!=0&&(x[i]-B)%a[i]==0) A=(x[i]-B)/a[i];
					else return 0;
				}
				else
				{
					if(a[i]*A+B==x[i]) ;
				    else return 0;
				}
			}
		}
		return 1;
	}
	if(a[1]-a[2]!=0&&(x[1]-x[2])%(a[1]-a[2])==0) A=(x[1]-x[2])/(a[1]-a[2]);
	else return 0;
	for(int i=1;i<=3;i++)
	{
		if(t[i]==3)
		{
			if(B==inf)
			{
				B=x[i]-a[i]*A;
			}
			else
			{
				if(a[i]*A+B==x[i]) ;
			    else return 0;
			}
		}
	}
	return 1;
}
void dfs1(int k)
{
	if(k>3)
	{
		ck|=check1();
		ck|=check2();
		return;
	}
	t[k]=1;
	dfs1(k+1);
	t[k]=2;
	dfs1(k+1);
	t[k]=3;
	dfs1(k+1);
}
int solve2(ll a,ll b,ll c,ll x,ll y,ll z)
{
    ll h1=x-a,h2=y-b,h3=z-c;
	if(h1==h2&&h2==h3) return 1;
	if(a!=0&&b!=0&&c!=0&&x%a==0&&y%b==0&&z%c==0&&x/a==y/b&&y/b==z/c) return 1;
	if(h1==h2||h1==h3||h2==h3||h1+h2==h3||h1+h3==h2||h2+h3==h1) return 2;
	if((a!=0&&b!=0&&x%a==0&&y%b==0&&x/a==y/b)||(a!=0&&c!=0&&x%a==0&&z%c==0&&x/a==z/c)||(b!=0&&c!=0&&y%b==0&&z%c==0&&y/b==z/c)) return 2;
	if(a!=0&&b!=0&&c!=0&&x%a==0&&y%b==0&&z%c==0&&(x/a*y/b==z/c||x/a*z/c==y/b||y/b*z/c==x/a)) return 2;
	ck=0;
	dfs1(1);
	if(ck==1) return 2;
	return 3;
}
int solve(ll a,ll b,ll c,ll x,ll y,ll z)
{
	if(a==x&&b==y&&c==z) return 0;
	if((a==x&&b==y)||(a==x&&c==z)||(b==y&&c==z)) return 1;
	if(a==x) return solve1(b,c,y,z);
	if(b==y) return solve1(a,c,x,z);
	if(c==z) return solve1(a,b,x,y);
	return solve2(a,b,c,x,y,z);
}
int main()
{
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
    	scanf("%lld%lld%lld%lld%lld%lld",&a[1],&a[2],&a[3],&x[1],&x[2],&x[3]);
    	printf("%d\n",solve(a[1],a[2],a[3],x[1],x[2],x[3]));
	}
} 
