#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k,cnt;
int a[1000005];
ll ans;

int main()
{
    freopen("ak.in","r",stdin);
    freopen("ak.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        
        ans+=b;

        if(i%k==1%k)
            a[++cnt]=b;
    }

    sort(a+1,a+cnt+1);

    cout<<ans-a[1+(cnt>>1)]<<'\n';

    return 0;
}