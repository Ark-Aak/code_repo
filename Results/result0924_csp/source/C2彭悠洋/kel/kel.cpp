#include <bits/stdc++.h>
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
const int N = 1e6+5;
int n,l,r,now,cnt;
vector<int> a;
signed main()
{
	freopen("kel.in","r",stdin);
	freopen("kel.out","w",stdout);
	read(n),read(l),read(r);
	now = cnt = l;
	while(cnt<=r&&a.size()<=n)
	{
		if(now>r&&cnt==r) break;
		a.push_back(now),a.push_back(cnt);
		now++;
		if(now>r)
		{
			if(cnt+1>r) break;
			a[a.size()-1] = ++cnt;
			if(cnt<r) a.push_back(cnt);
			now = cnt+1;
		}
	}
	int siz = a.size();
	if(siz<n-1||(a[siz-1]!=r&&siz==n-1)) return puts("Shinomiya");
	for(int i = 0;i<n-1;i++)
		writen(a[i]);
	if(a[n-2]==r) puts("1");
	else write(a[n-1]);
	return 0;
}

