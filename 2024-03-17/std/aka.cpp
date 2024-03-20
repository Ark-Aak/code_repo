#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fi first
#define se second
#define eb emplace_back
#define popc __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef long double ld;

int read() {
  int x=0,w=1; char c=getchar(); 
  while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
  while(isdigit(c)) {x=x*10+(c-'0'); c=getchar();}
  return x*w;
}

const int N=10009;

int n,m,c[N],vst[N],ans,sp,sc,np;
vi e[N];

bool dfs(int u) {
  for(int v:e[u]) if(!vst[v]) {
    vst[v]=1;
    if(!c[v]||dfs(c[v])) return c[v]=u,1;
  } return 0;
}

void work() {
  n=read(), m=read(); ans=sp=sc=np=0;
  rep(i,1,2*n) c[i]=0, e[i].clear();
  rep(i,1,m) {
    int u=read(), v=read();
    e[u].eb(v+n), e[v].eb(u+n);
    e[v+n].eb(u), e[u+n].eb(v);
  }
  rep(i,1,2*n) memset(vst,0,sizeof(vst)), dfs(i);
  rep(i,1,n) {
    if(c[i]) ans++;
    else {
      if(!c[i+n]) sp++, np=i;
      else sc++;
    }
  }
  if(sp!=1||sc) printf("%d\n",ans-sp-sc);
  else if(e[np].size()) printf("%d\n",ans-sp-sc);
  else printf("%d\n",ans-sp-sc-2);
}

signed main() {
  int o=read(), t=read();
  while(t--) work();
  return 0;
}
