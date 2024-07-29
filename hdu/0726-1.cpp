/* #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math") */
#include <bits/stdc++.h>

void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}

#define ll int
using namespace std;

const int Maxn=3e6+7;
const int Mod=998244353;
int n;
int ans[Maxn],lans[Maxn];

vector <int>divs[Maxn];

inline int _MOD(int x) { return x >= Mod ? x - Mod : x; }

int main(){
    scanf("%d",&n);
	freopen("test.out", "w", stdout);
	fprintf(stderr, "%.10lf\n", clock() * 1.0 / CLOCKS_PER_SEC);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            divs[j].emplace_back(i);
    ans[1]=1;
    for(int i=2;i<=n;i++){
        for(auto j:divs[i-1])
            ans[i]=_MOD(ans[i]+ans[j]);
    }

    for(int i=1;i<=n;i++){
        int ret=ans[i];
        for(int j=i;j<=n;j+=i)
            lans[j]=_MOD(lans[j]+ret),ret=(1ll * ret*ans[i])%Mod;
    }
	fprintf(stderr, "%.10lf\n", clock() * 1.0 / CLOCKS_PER_SEC);
    return 0;
}
