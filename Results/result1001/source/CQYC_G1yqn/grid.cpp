#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
void write(int x)
{
    if(x<0){putchar('-'),x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
    return;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int cp(int x1,int y1,int x2,int y2)
{
	if(x1==x2&&y1==y2)return 1;
	return gcd(abs(x2-x1),abs(y2-y1))+1;
}
int cgp(int n,int m)
{
	int sum=0;
	for(int x1=0;x1<n;x1++)
	{
		for(int y1=0;y1<m;y1++)
		{
			for(int x2=x1;x2<n;x2++)
			{
				for(int y2=y1;y2<m;y2++)
				{
					if(x1!=x2||y1!=y2)
					{
						sum+=cp(x1,y1,x2,y2);
					}
				}
			}
		}
	}
	return sum;
}
signed main()
{
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	int n,m,t;
	t=read();
	while(t--)
	{
		n=read(),m=read();
		cout<<cgp(n,m)<<endl;
	}
	return 0;
}
