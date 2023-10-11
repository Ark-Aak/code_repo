#include <bits/stdc++.h>
#define int long long
#define gcd ___________________
using namespace std;

template<typename T> void read(T &x)
{
	x = 0;
	T f = 1;char ch = getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f = -1,ch = getchar();
			break;
		}
		ch = getchar();
	}
	while(ch>='0'&&ch<='9')
		x = (x<<3)+(x<<1)+ch-48,ch = getchar();
	x*=f;
}
template<typename T> T read()
{
	T x;read(x);return x;
}
template<typename T> void write(T x)
{
    if(x<0) x = -x,putchar('-');
    if(x<=9) return putchar(x+48),void();
    write(x/10);
    putchar(x%10+48);
}
template<typename T> void writen(T x)
{
    write(x);
    puts("");
}
int T,n,m,ans;
void solve()
{
	read(n),read(m);
	if(n<m) swap(n,m);
	ans = 0;
	if(m<=1) return writen(0);
	if(m<=2)
	{
		for(int i = 2;i<=n;i++)
			ans+=(i+1)*(n-i+1)*n;
		writen(ans*2);
		return;
	}
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			for(int k = 0;k<n;k++)
				for(int l = 0;l<m;l++)
				{
					int ci = abs(i-k),cj = abs(j-l);
					if(!(ci||cj)) continue;
					int gcd = __gcd(ci,cj);
					int mxi = 0,mxj = 0;
					ci/=gcd,cj/=gcd;
					if(ci==0) mxj = m-1;
					else if(cj==0) mxi = n-1;
					else
					{
						int mul = min(n/ci,m/cj);
						mxi = ci*mul-1,mxj = cj*mul-1;
					}
					int cnt = n*m-__gcd(mxi,mxj)-1;
//					cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<mxi<<' '<<mxj<<'\n'<<cnt<<' '<<gcd<<'\n'; 
					ans+=cnt*gcd;
				}
	writen(ans/2);
}
signed main()
{
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	read(T);
	while(T--) solve();
	return 0;
}

