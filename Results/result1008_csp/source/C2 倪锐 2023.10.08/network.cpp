#include<bits/stdc++.h>
#define re register
// #define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
using namespace std;
// char buf[1<<23],*p1=buf,*p2=buf,ubuf[1<<23],*u=ubuf;
// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
inline bool islegal(int x){return x!='\n'&&x!='\t'&&x!=' ';}
inline void readstr(string &s,int len)
{
	s.resize(len+2);
	int cbuf=0;
	while(islegal(s[cbuf++]=getchar())&&cbuf<len);
	s.erase('\n');s.erase(' ');s.erase('\t');
}
int n,q,x,y,jc[1000001];
string opt;
vector<int> g[1000001];
bitset<10001> vis;
int bfs(int st,int ed)
{
	int as=0;
	queue<int> q;
	q.push(st);
	while(!q.empty())
	{
		++as;
		int x=q.front();q.pop();
		if(x==ed) break;
		for(re auto i:g[x]) if(!vis.test(i)) vis.set(i),q.push(i);
	}
	return as;
}
signed main()
{
freopen("network.in","r",stdin);freopen("network.out","w",stdout);
	read(n);read(q);
	rep(i,1,n-1) read(x),read(y),g[x].emplace_back(y),g[y].emplace_back(x);
	while(q--)
	{
		readstr(opt,5);
		read(x);
		if(opt[0]=='J') jc[x]=1;
		else
		{
			int pre=x,res=0;
			rep(i,1,n) if(jc[i]) vis.reset(),res+=bfs(pre,i),pre=i;
			writeln(res);
		}
	}
	return 0; 
}
