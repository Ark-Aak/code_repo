#include <iostream>
#include <cstdio>
#include <vector>
const int N=100050;
std::vector<int> vt[N];
int n,ans,a[N],b[N];
bool vis[N];
void dfs(int now) {
	vis[now]=true;
	for(auto ed:vt[now])
		if(!vis[ed]) dfs(ed);
}
int main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
    scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]<=a[j]&&b[i]<=b[j]||a[i]>=a[j]&&b[i]>=b[j]) {
				vt[i].emplace_back(j);
				vt[j].emplace_back(i);
			}
	for(int i=1;i<=n;i++)
		if(!vis[i]) {
			++ans;
			dfs(i);
		}
	printf("%d",ans);
    return 0;
}