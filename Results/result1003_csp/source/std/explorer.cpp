#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=1000010;
int n,l[N],r[N];
ll ans1,ans2;

struct node
{
    int x,y,id;
}a[N];

struct BIT
{
    int c[N];
    
    void add(int x,int val)
    {
        for (;x<=n*2;x+=x&-x)
            c[x]+=val;
    }
    
    int ask(int x)
    {
        int sum=0;
        for (;x;x-=x&-x)
            sum+=c[x];
        return sum;
    }
}bit;

bool cmp1(node x,node y)
{
    return x.x<y.x;
}

bool cmp2(node x,node y)
{
    return x.y>y.y;
}

int main()
{
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp1);
    for (int i=1;i<=n;i++)  //二维偏序求每一条弦的 l[i] 和 r[i]
    {
        l[a[i].id]+=bit.ask(a[i].x)+bit.ask(n*2)-bit.ask(a[i].y);
        bit.add(a[i].y,1);
    }
    memset(bit.c,0,sizeof(bit.c));
    for (int i=n;i>=1;i--)
    {
        r[a[i].id]+=bit.ask(a[i].y)-bit.ask(a[i].x);
        bit.add(a[i].y,1);
    }
    memset(bit.c,0,sizeof(bit.c));
    sort(a+1,a+1+n,cmp2);
    for (int i=1;i<=n;i++)
    {
        l[a[i].id]+=bit.ask(n*2)-bit.ask(a[i].y);
        bit.add(a[i].x,1);
    }
    ans1=1LL*n*(n-1)*(n-2)/6;  //C(n,3)
    for (int i=1;i<=n;i++)
    {
        ans1-=1LL*l[i]*r[i];
        ans2+=1LL*(l[i]+r[i])*(n-l[i]-r[i]-1);
    }
    printf("%I64d",ans1-ans2/2);
    return 0;
}
