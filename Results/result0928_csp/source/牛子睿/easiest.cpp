#include <iostream>
#include <cstdio>
#include <stack>
#define scnaf scanf
#define mkp std::make_pair
const int npos=-0x7ffffffe;
const int N=100050;
std::stack< std::pair<int,int> > stk;
int n,m,a[N],lst[N];
int main() {
    freopen("easiest.in","r",stdin);
    freopen("easiest.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        while(!stk.empty()&&stk.top().first<a[i]) stk.pop();
        if(stk.empty()) lst[i]=npos;
        else lst[i]=stk.top().second;
        stk.push(mkp(a[i],i));
    }
    while(m--) {
        int l1,r1,l2,r2;
        scanf("%*d%d%d%d%d",&l1,&r1,&l2,&r2);
        int ans=l2-l1;
        for(int i=r2+1;i<=r1;i++)
            if(lst[i]>r2) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
