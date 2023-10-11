#include<bits/stdc++.h>
#define ls ch[p][0]
#define rs ch[p][1]
const int N = 4e5 + 10;
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(c == '-') f = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int sz[N], val[N], fa[N], tot, tp, n, m;
struct Edge {
	int pr[N], nx[N << 1], to[N << 1], tp;
	void add(int u, int v) {to[++tp] = v; nx[tp] = pr[u]; pr[u] = tp;}
	void adds(int u, int v) {add(u, v); add(v, u);}
};
namespace RST {
	Edge T; int w[N];
	void Dfs(int u) {
		sz[u] = w[u];
		for(int i = T.pr[u], v; i; i = T.nx[i]) 
			if((v = T.to[i]) != fa[u]) {
				fa[v] = u;
				Dfs(v);
				sz[u] += sz[v];
				val[u] ^= (u <= n ? sz[v] : val[v]);
			}
		if(u > n) val[u] ^= sz[u];
	}
}
namespace Tarjan {
    Edge G; int dfn[N], low[N], st[N], tp, tm;
    void Dfs(int u, int fa) {
        dfn[u] = low[u] = ++tm; RST::w[u] = 1; st[++tp] = u;
        for(int i = G.pr[u], v; i; i = G.nx[i]) 
        if((v = G.to[i]) != fa) {
            if(!dfn[v]) {
                Dfs(v, u), low[u] = std::min(low[u], low[v]); 
                if(low[v] >= dfn[u])
                    for(RST::T.adds(u, ++tot); st[tp + 1] != v;)
                        RST::T.adds(st[tp--], tot);
            }
            else low[u] = std::min(low[u], dfn[v]);
        }
    }
}
namespace LCA {
	Edge Q; int U[N], V[N], C[N], g[N], id[N], s[N]; bool vis[N];
	int F(int x) {return !g[x] ? x : g[x] = F(g[x]);}
	void Dfs(int u) {
		using namespace RST;
		vis[u] = true; s[u] = (u <= n ? 0 : val[u]) ^ s[fa[u]];
		for(int i = T.pr[u], v; i; i = T.nx[i])
			if((v = T.to[i]) != fa[u]) {
				Dfs(v);
				g[v] = u;
			}
		for(int i = Q.pr[u], v; i; i = Q.nx[i])
			if(vis[v = Q.to[i]] && !C[id[i]])
				C[id[i]] = F(v);
	}
}
int main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	tot = n = ri(); m = ri();
	for(;m--;)
		Tarjan::G.adds(ri(), ri());
	Tarjan::Dfs(1, 0); RST::Dfs(1);
	int q = ri(); using namespace LCA;
	for(int i = 1;i <= q; ++i)
		U[i] = ri(), V[i] = ri(), Q.adds(U[i], V[i]), id[Q.tp] = id[Q.tp - 1] = i;
	Dfs(1);
	for(int i = 1;i <= q; ++i) {
		int u = U[i], v = V[i], c = C[i];
		if(c <= n) printf("%d\n", s[u] ^ s[v] ^ val[c] ^ (n - sz[c]));
		else printf("%d\n", s[u] ^ s[v] ^ val[c] ^ val[fa[c]] ^ (n - sz[fa[c]]));
	}
	return 0;
}

