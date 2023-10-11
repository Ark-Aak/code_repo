#include <bits/stdc++.h>
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
const int N = 1e6+5;
int n,k,a[N],now,l[N],r[N];
long long ans,sum;
bool f;
struct node{
	int lt,rt;
	long long val;
	friend bool operator < (node x,node y)
	{
		return (x.val==y.val)?(x.lt<y.lt):(x.val<y.val);
	}
};
set<node> s;
void print()
{
	cout<<s.size()<<'\n';
	for(auto i:s)
		cout<<i.lt<<' '<<i.rt<<' '<<i.val<<'\n';
	cout<<'\n';
}
signed main()
{
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	read(n),read(k);
	for(int i = 1;i<=n;i++)
		read(a[i]),sum+=a[i];
	if(k==1)
	{
		sort(a+1,a+n+1);
		write(sum-a[n/2+1]);
		return 0;
	}
	sum = 0;
	for(int i = 1;i<=n;i++)
		l[i] = i-1,r[i] = i+1;
	for(int i = 1;i<k;i++)
		sum+=a[i];
	for(int i = k;i<=n;i++)
	{
		sum+=a[i]-a[i-k];
		s.insert((node){i-k+1,i,sum});
	}
	while(1)
	{
//		cout<<now<<'\n';
//		print();
		if(now+k>n||(k==1&&now==n-1)) break;
		f^=1;
		now+=k;
		int lt,rt;
		if(f) lt = (*s.begin()).lt,rt = (*(s.begin())).rt,ans+=(*s.begin()).val;
		else lt = (*(--s.end())).lt,rt = (*(--s.end())).rt,ans+=(*(--s.end())).val;
		int tmpl = lt,sz = 1;
		for(;sz<k;sz++)
		{
			if(l[tmpl]==0) break;
			tmpl = l[tmpl];
		}
		int tmpr = tmpl;
		sz = 1;
		sum = a[tmpr];
		for(;sz<k;sz++)
		{
			tmpr = r[tmpr];
			sum+=a[tmpr];
		}
		while(tmpl<=rt&&tmpr!=n+1)
		{
//			cout<<"era"<<tmpl<<' '<<tmpr<<' '<<sum<<'\n';
			s.erase((node){tmpl,tmpr,sum});
			tmpr = r[tmpr];sum+=a[tmpr]-a[tmpl];tmpl = r[tmpl];
		}
		if(l[lt]==0||r[rt]==n+1) goto nxt;
		tmpl = l[lt];
		sum = a[tmpl];
		sz = 1;
		for(;sz<k-1;sz++)
		{
			if(l[tmpl]==0) break;
			tmpl = l[tmpl];
			sum+=a[tmpl];
		}
		tmpr = r[rt],sz++;
		sum+=a[tmpr];
		for(;sz<k;sz++)
		{
			if(r[tmpr]==n+1) goto nxt;
			tmpr = r[tmpr];
			sum+=a[tmpr];
		}
//		cout<<"st\n"<<tmpl<<' '<<tmpr<<'\n';;
		while(tmpl<lt&&tmpr!=n+1)
		{
//			cout<<"ins"<<tmpl<<' '<<tmpr<<' '<<sum<<'\n';
			s.insert((node){tmpl,tmpr,sum});
//			print();
			tmpr = r[tmpr];sum+=a[tmpr]-a[tmpl];tmpl = r[tmpl];
		}
		nxt:;
		r[l[lt]] = r[rt],l[r[rt]] = l[lt];
	}
	write(ans);
	return 0;
}

