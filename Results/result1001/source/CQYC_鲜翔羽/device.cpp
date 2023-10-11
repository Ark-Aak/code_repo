#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
int stk[10],tp;
inline void write(int x)
{
	if(!x) return puts("0"),void();
	tp=0;
	while(x) stk[++tp]=x%10,x/=10;
	while(tp) putchar(stk[tp--]^48);
	putchar('\n');
}
const int N=15;
int T,n,k,cnt,res[N][N];
bool vis[N];
int main()
{
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	for(int i=1;i<=3;i++) res[0][i]=res[i][1]=1;
	res[1][2]=7;res[1][3]=24;
	res[2][2]=8;res[2][3]=27;
	T=read();
	while(T--)
	{
		k=read(),n=read();
		cnt=0;n=min(2,n);
		for(int i=1;i<=9;i++) vis[i]=0;
		while(k) cnt+=!vis[k%10],vis[k%10]=1,k/=10;
		write(res[n][cnt]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
