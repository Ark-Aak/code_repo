#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define re register
#define int long long
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
using namespace std;
using namespace __gnu_pbds;
template<typename T> inline T read(T &num)
{
	re int x=0,f=0; re char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename T> inline void write(T x)
{
	(x<0)?(putchar('-'),x=-x):0;
	(x>9)?(write(x/10),0):0;
	putchar(x%10+48);
}
int n,q,qopt[200001],w[200001],nowx,qid[200001];
int queryfind(int x)
{
	rep(i,1,q) if(qopt[i]==x) return i;
	return -1;
}
struct opt2
{
	int x,y;
};
union query
{
	int o1;
	opt2 o2;
}query[200001];
bitset<200001> vis;
namespace subtask1
{
	void dfs(int x)
	{
		vis.set(x);
		if(w[x-1]>=nowx&&!vis.test(x-1)) dfs(x-1);
		if(w[x+1]>=nowx&&!vis.test(x+1)) dfs(x+1);
	}
	int main()
	{
		rep(_,1,q)
		{
			if(qopt[_]==2) w[query[_].o2.x]=query[_].o2.y;
			else
			{
				nowx=query[_].o1;
				vis.reset();
				int res=0;
				rep(i,1,n) if(w[i]>=nowx&&!vis.test(i)) dfs(i),++res;
				write(res);puts("");
			}
		}
		return 0;
	}
}
namespace subtask2
{
	int main()
	{
		subtask1::main();
		return 0;
	}
	int ans[200001];
	int mian()
	{
		iota(qid+1,qid+q+1,1);
		sort(qid+1,qid+q+1,[](int x,int y){return query[x].o1<=query[y].o1;});
		sort(w+1,w+n+1);
		// lower_bound()
		rep(_,1,q)
		{
			int qthis=query[qid[_]].o1,posi=lower_bound(w+1,w+n+1,qthis)-w-1;
			ans[qid[_]]=n-posi;
		}
		rep(_,1,q) write(ans[_]),puts("");
		return 0;
	}
}
namespace subtask3
{
	int main()
	{
		subtask1::main();
		return 0;
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
#endif
	read(n);read(q);
	rep(i,1,n) read(w[i]);
	rep(i,1,q)
	{
		read(qopt[i]);
		if(qopt[i]==1) read(query[i].o1);
		else read(query[i].o2.x),read(query[i].o2.y);
	}
	if(n*q<=1) subtask1::main();
	else if(queryfind(2)==-1) subtask2::main();
	else subtask3::main();
	cerr<<"[Total used time: "<<clock()<<" ms.]";
	return 0;
}
