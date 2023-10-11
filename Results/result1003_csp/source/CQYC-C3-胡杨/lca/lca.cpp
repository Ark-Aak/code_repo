#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int& first){
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {if(c == '-') f = -1;c = getchar();}
	while(isdigit(c)){x = (x << 3) + (x << 1) + (c ^ '0');c = getchar();}
	first = x * f;
}
namespace fastio{
	int stk[40],tp;
    template<typename T>void out(T x,char c=0){
        if(x<0)putchar('-'),x=-x;
        do stk[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(stk[tp--]^48);
        if(c)putchar(c);
    }
}using fastio::out;
int n,ans;
vector<int> tree[500010];
int son[500010], f[500010];
void dfs(int x, int fa){
	son[x] = 1;
	f[x] = fa;
	if(tree[x].size() == 1 && tree[x][0] == fa) return ;
	for(int i = 0 ; i < tree[x].size() ; i++){
		int to = tree[x][i];
		if(to == fa) continue;
		dfs(to, x);
		son[x] += son[to];
	}
}
signed main(){
    freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
    read(n);
    for(int i = 1 ; i < n ; i++){
    	int x, y;
    	read(x);read(y);
    	tree[x].push_back(y);
    	tree[y].push_back(x);
	}
	for(int i = 1 ; i <= n ; i++){
		memset(son, 0, sizeof son);
		memset(f, 0, sizeof f);
		dfs(i, 0);
		int ans = 0;
		for(int j = 1 ; j <= n ; j++){
			for(int k = 0 ; k < tree[j].size() ; k++){
				int to = tree[j][k];
				if(to != f[j]) ans += (son[j] - 1 - son[to]) * son[to] * j; 
			}
			ans += (son[j] - 1) * j * 2;
		}
		ans = ans + (1 + n) * n / 2;
		out(ans,' ');
	}
	return 0;
}

