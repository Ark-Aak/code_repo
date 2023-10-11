#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll n;
double a[N];
double ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("ave.in","r",stdin);
    freopen("ave.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ans=a[1];
    for(int i=2;i<=n;i++) ans=(ans+a[i])/2;
    printf("%.6lf",ans);
    return 0;
}
