#include<bits/stdc++.h>
#define re register
#define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,ubuf[1<<23],*u=ubuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template<typename TP> inline TP read(TP &num)
{
	re TP x=0;re int f=0;re char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename TP> inline void write(TP x)
{
	(x<0)?(putchar('-'),x=-x):0;
    (x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
template<typename TP> inline void writeln(TP x)
{
	write<TP>(x);
	puts("");
}
#define Alice 0
#define Bob 1
int n,k,a[1000001],ans,now,b[1000001],sum[1000001],cnt;
deque<int> q;
signed main()
{
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	read(n),read(k);
	rep(i,1,n)read(a[i]);
	if(k==1)
	{
		sort(a+1,a+n+1);
		rep(i,1,n) q.emplace_back(a[i]);
		while(q.size()>1)
		{
			if(now==Alice) rep(i,1,k) ans+=q.front(),q.pop_front();
			else rep(i,1,k) ans+=q.back(),q.pop_back();
			now=!now;
		}
		writeln(ans);
	}
	else
	{
		cnt=n;
		while(cnt>1)
		{
			rep(i,1,cnt) b[i]=a[i];
			partial_sum(b+1,b+cnt+1,sum+1);
			int res=0,stt;
			if(now==Alice) res=0x7fffffff;
			if(now==Alice) {rep(i,k,cnt) if(sum[i]-sum[i-k]<res) res=sum[i]-sum[i-k],stt=i;}
			else {rep(i,k,cnt) if(sum[i]-sum[i-k]>res) res=sum[i]-sum[i-k],stt=i;}
			req(i,stt,stt-k+1) b[i]=0;
			cnt-=k;
			ans+=res;
			for(int i=1,j=1;i<=cnt;++i,++j) {while(!b[j]) ++j;a[i]=b[j];}
			now=!now;
		}
		writeln(ans);
	}
	return 0; 
}
