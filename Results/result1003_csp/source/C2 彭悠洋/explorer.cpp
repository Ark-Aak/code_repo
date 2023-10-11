#include <bits/stdc++.h>
#define int long long
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
const int N = 5e5+5;
int n,a[N],b[N],s1,s2,s3,ans;
signed solve()
{
	int ans = 0;
	for(int i = 1;i<=n;i++)
		ans+=(i-1)*(i-2)/2;
	write(ans);
	exit(0);
}
signed main()
{
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++)
	{
		read(a[i]),read(b[i]);
		if(a[i]>b[i]) swap(a[i],b[i]); 
	}
	if(n>500) solve();
	for(int i = 1;i<n-1;i++)
		for(int j = i+1;j<n;j++)
			for(int k = j+1;k<=n;k++)
			{
				int tmp1 = 0,tmp2 = 0;
				if(a[j]>a[i]&&a[j]<b[i]) tmp1++;
				else tmp2++;
				if(b[j]>a[i]&&b[j]<b[i]) tmp1++;
				else tmp2++;
				if(a[k]>a[i]&&a[k]<b[i]) tmp1++;
				else tmp2++;
				if(b[k]>a[i]&&b[k]<b[i]) tmp1++;
				else tmp2++;
				s1 = min(tmp1,tmp2),tmp1 = tmp2 = 0;
				if(a[i]>a[j]&&a[i]<b[j]) tmp1++;
				else tmp2++;
				if(b[i]>a[j]&&b[i]<b[j]) tmp1++;
				else tmp2++;
				if(a[k]>a[j]&&a[k]<b[j]) tmp1++;
				else tmp2++;
				if(b[k]>a[j]&&b[k]<b[j]) tmp1++;
				else tmp2++;
				s2 = min(tmp1,tmp2),tmp1 = tmp2 = 0;
				if(s1!=s2) continue;
				if(a[j]>a[k]&&a[j]<b[k]) tmp1++;
				else tmp2++;
				if(b[j]>a[k]&&b[j]<b[k]) tmp1++;
				else tmp2++;
				if(a[i]>a[k]&&a[i]<b[k]) tmp1++;
				else tmp2++;
				if(b[i]>a[k]&&b[i]<b[k]) tmp1++;
				else tmp2++;
				s3 = min(tmp1,tmp2);
				if(s2==s3) ans++;
			}
	write(ans);
	return 0;
}

