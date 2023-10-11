#include<bits/stdc++.h>
using namespace std;
int kase;
void solve()
{
	long long a,b,c,p,q,r;
	scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&p,&q,&r);
	if(a==p&&b==q&&c==r)
	{
		puts("0");
		return;
	}
	long long xa=p-a,xb=q-b,xc=r-c;
	if(!xa||!xb||!xc)
	{
		if(xa==xb||xa==xc||xb==xc||a&&b&&!(p%a)&&!(q%b)&&p/a==q/b||a&&c&&!(p%a)&&!(r%c)&&p/a==r/c||b&&c&&!(q%b)&&!(r%c)&&q/b==r/c)
		{
			puts("1");
			return;
		}
		puts("2");
		return;
	}
	if(xa==xb&&xa==xc||a&&b&&c&&!(p%a)&&!(q%b)&&!(r%c)&&p/a==q/b&&p/a==r/c)
	{
		puts("1");
		return;
	}
	if(xa+xb==xc||xa+xc==xb||xb+xc==xa)
	{
		puts("2");
		return;
	}
	if(a&&b&&c&&!(p%a)&&!(q%b)&&!(r%c)&&((p/a)*(q/b)==r/c||(p/a)*(r/c)==q/b||(q/b)*(r/c)==p/a))
	{
		puts("2");
		return;
	}
	if(xa==xb||xa==xc||xb==xc||a&&b&&!(p%a)&&!(q%b)&&p/a==q/b||a&&c&&!(p%a)&&!(r%c)&&p/a==r/c||b&&c&&!(q%b)&&!(r%c)&&q/b==r/c)
	{
		puts("2");
		return;
	}
	if(a&&!(p%a)&&((b+xc)*(p/a)==q||b*(p/a)+xc==q||(c+xb)*(p/a)==r||c*(p/a)+xb==r))
	{
		puts("2");
		return;
	}
	if(b&&!(q%b)&&((a+xc)*(q/b)==p||a*(q/b)+xc==p||(c+xa)*(q/b)==r||c*(q/b)+xa==r))
	{
		puts("2");
		return;
	}
	if(c&&!(r%c)&&((a+xb)*(r/c)==p||a*(r/c)+xb==p||(b+xa)*(r/c)==q||b*(r/c)+xa==q))
	{
		puts("2");
		return;
	}
	if(b-a&&!((q-p)%(b-a))&&((q-p)/(b-a)*c+p-(q-p)/(b-a)*a==r||(q-p)/(b-a)*c==r||c+p-(q-p)/(b-a)*a==r||(q-p)/(b-a)&&!((p-(q-p)/(b-a)*a)%((q-p)/(b-a)))&&c+(p-(q-p)/(b-a)*a)/((q-p)/(b-a))==r))
	{
		puts("2");
		return;
	}
	if(c-a&&!((r-p)%(c-a))&&((r-p)/(c-a)*b+p-(r-p)/(c-a)*a==q||(r-p)/(c-a)*b==q||b+p-(r-p)/(c-a)*a==q||(r-p)/(c-a)&&!((p-(r-p)/(c-a)*a)%((r-p)/(c-a)))&&b+(p-(r-p)/(c-a)*a)/((r-p)/(c-a))==q))
	{
		puts("2");
		return;
	}
	if(c-b&&!((r-q)%(c-b))&&((r-q)/(c-b)*a+q-(r-q)/(c-b)*b==p||(r-q)/(c-b)*a==p||a+q-(r-q)/(c-b)*b==p||(r-q)/(c-b)&&!((q-(r-q)/(c-b)*b)%((r-q)/(c-b)))&&a+(q-(r-q)/(c-b)*b)/((r-q)/(c-b))==p))
	{
		puts("2");
		return;
	}
	puts("3");
}
int main()
{
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(kase=1;kase<=t;kase++)
		solve();
	return 0;
}
