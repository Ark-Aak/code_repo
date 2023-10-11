//容易发现电梯运的人一定是一段一段的感觉。而且我们一定会让楼层小的尽可能先走。
//考虑 dp。 设 f_{i} 表示 i 结尾的 min cost
//  		使用 g_{i} 表示此时的时间为
//实际上只需要开到 f[100005] k=n 是不好做的。反正T2炸了，今天随便打点分玩玩。
//斜率优化 dp ！！！
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;
int n,m,g[N],f[N],a[N];
void Subtask1() {
	m = min(n,m);
	f[0]=0;
	g[0]=0;
	for(int i=1; i<=n; i++) {
		for(int j=i; j>=max(1ll,i-m+1); j--) {
			if(f[i]==f[j-1]+(g[j-1]+(a[i]-1)*2)*(i-j+1)) g[i]=min(g[i],g[j-1]+(a[i]-1)*2);
			if(f[i]>f[j-1]+(g[j-1]+(a[i]-1)*2)*(i-j+1)) {
				g[i]=g[j-1]+(a[i]-1)*2;
				f[i]=f[j-1]+(g[j-1]+(a[i]-1)*2)*(i-j+1);
			}
		}
	}
	cout<<f[n];
	return;
}

signed main() {
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(f,0x7f,sizeof f);
	memset(g,0x7f,sizeof g);
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	Subtask1();
//	m=min(m,n);
//	if(n<=10) dfs(1,0,0);//第 i 个，上一个时间段为 
//	cout<<f[1][0]; 
	return 0;
}
