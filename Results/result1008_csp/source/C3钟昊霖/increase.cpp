#include <bits/stdc++.h>
using namespace std;

#define F(i, a, b) for(int i = a; i <= b; i++)

inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f *= -1;
		c = getchar();
	}
	while(c <= '9' && c >= '0') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

struct node{int _to,val;};

const int N = 2e5 + 5, inf = 11451419; 
int n, m, f[5005][5005][2]; // 符合操作员体质的记忆化搜索。 
vector<node> to[N];

inline int dfs(int u, int cost, bool falg) {
	if(f[u][cost][falg]) return f[u][cost][falg];
	int len = to[u].size();
	int Zexal = inf; bool T =  true;
	if(falg) Zexal=0;
	else Zexal = INT_MAX;
	F(i, 0, len-1) {
		node E = to[u][i];
		if(E.val <= cost) continue;
		T = false;
		if(falg) Zexal = max(Zexal, dfs(E._to, E.val, !falg));
		if(!falg) Zexal = min(Zexal,dfs(E._to, E.val, !falg)); 
	}
	//cout << u << cost << falg <<endl;
	if( T == true) return f[u][cost][falg] = 1;
	return f[u][cost][falg] = Zexal + 1;
} 

signed main() {
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	n = read(), m = read();
	F(i, 1, m) {
		int u, v, w;
		u = read(), v = read(), w =read();
		to[u].push_back((node){v,w});
		to[v].push_back((node){u,w});
	}
	F(i, 1, n) {
		cout<< dfs(i,0,1) -1 <<" ";//place cost player 
	}
	return 0;
} 
