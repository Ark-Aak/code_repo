#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 2e6 + 5;
int n, m;
int low[MAXN], dfn[MAXN], idx;
bool isbridge[MAXN];
vector<int> G[MAXN];
int cnt_bridge;
int father[MAXN], col[MAXN];

void tarjan(int u, int fa, int c) {
	bool flag = false;
	father[u] = fa;
	low[u] = dfn[u] = ++idx;
	col[u] = c;
	for (const auto &v : G[u]) {
		if (!dfn[v]) {
			tarjan(v, u, c);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u]) {
				isbridge[v] = true;
				++cnt_bridge;
			}
		}
		else {
			if (v != fa || flag) low[u] = min(low[u], dfn[v]);
			else flag = true;
		}
	}
}

vector<pair<int,int> >s[200005],t;
int pd[200005],cnt,pdd[200005];
void dfs(int p,int fa){
    pd[p]=cnt;int op=0;
    for(int i=0;i<s[p].size();i++){
        int y=s[p][i].second;
        if(y==fa&&op==0){op=1;continue;}
        int k=s[p][i].first;
        if(pd[y]){if(!pdd[k])pdd[k]=1,t.push_back(make_pair(k,y));}
        else dfs(y,p);
    }
}
int b[200005],st[200005],top;
int ls[200005],rs[200005],ans,id[200005];
signed main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        s[x].push_back(make_pair(i,y)),s[y].push_back(make_pair(i,x));
    }
    int l=-1,root=0;
    for(int i=1;i<=n;i++){
        if(pd[i]==0){++cnt;
            if(l+1<t.size()){
                l++;int y=t[l].first,k=t[l].second;
                ls[++ans]=k,rs[ans]=i,id[ans]=y;
            }
            else st[++top]=cnt;
            dfs(i,0);
            if(st[top]==cnt&&l+1<t.size()){
                if(i!=1&&root){
                    l++;int y=t[l].first,k=t[l].second;
                    ls[++ans]=k,rs[ans]=root,id[ans]=y;
                    top--;
                }
                else root=i,top--;
            }
//            if(i==1&&t.size()) top--;
            if(i!=1)while(l+1<t.size()&&top){
                l++;
                int y=t[l].first,k=t[l].second;
                ls[++ans]=k,rs[ans]=st[top],id[ans]=y;
                top--;
            }
        }
    }
    cout<<ans<<'\n';
    for(int i=1;i<=ans;i++) cout<<id[i]<<" "<<ls[i]<<" "<<rs[i]<<'\n';
    return 0;
}
