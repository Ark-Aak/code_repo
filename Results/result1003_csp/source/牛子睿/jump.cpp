#include <iostream>
#include <cstdio>
#include <stack>
#define mkp std::make_pair
const int N=500050;
std::stack< std::pair<int,int> >stk;
int n,t,dp[N];
int main() {
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    scanf("%d",&n);
    stk.push(mkp(0x7fffffff,0));
    for(int i=1;i<=n;i++)  {
        scanf("%d",&t);
        while(!stk.empty()&&t>=stk.top().first) stk.pop();
        dp[i]=dp[stk.top().second]+1;
        stk.push(mkp(t,i));
        printf("%d ",dp[i]);
    }
    return 0;
}