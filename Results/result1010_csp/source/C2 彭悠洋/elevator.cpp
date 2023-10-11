#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T> inline void read(T &x)
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
template<typename T> inline T read()
{
	T x;read(x);return x;
}
template<typename T> inline void write(T x)
{
    if(x<0) x = -x,putchar('-');
    if(x<=9) return putchar(x+48),void();
    write(x/10);
    putchar(x%10+48);
}
template<typename T> inline void writen(T x)
{
    write(x);
    puts("");
}
const int N = 5e5+5,M = 2e6+5;
int n,k,m,a[N],ton[M],pre,ans,sum;
int dis(int x) {return 2*(x-1);} 
signed main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	read(n),read(k);
	for(int i = 1;i<=n;i++)
		read(a[i]),ton[a[i]]++;
	sort(a+1,a+n+1),m = unique(a+1,a+n+1)-a-1;
//	pre = ton[a[1]];
	a[0] = 1;
	for(int i = 1;i<=m;i++)
	{
//		cout<<ans<<' '<<pre<<' '<<sum<<'\n';
		if(((pre+ton[a[i]])*dis(a[i])+(pre+ton[i])*sum)<=(pre*dis(a[i-1])+dis(a[i-1])+dis(a[i])*ton[a[i]]+pre*sum)) pre+=ton[a[i]];//接你再接下面
		else ans = ans+pre*sum+pre*dis(a[i-1]),sum+=dis(a[i-1]),pre = ton[a[i]];//接下面再接你 
	}
	ans = ans+pre*sum+pre*dis(a[n]);
	write(ans);
	return 0;
}

