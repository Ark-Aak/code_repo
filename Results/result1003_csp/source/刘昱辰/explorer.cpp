#include<bits/stdc++.h>
#define ll long long
#define N 600005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll n;
struct qwq{
    ll x,y,c;
}f[N];
bool cmp(qwq a,qwq b){
    return a.x<b.x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("explorer.in","r",stdin);
    freopen("explorer.out","w",stdout);
    cin>>n;
    ll fl=0;
    for(int i=1;i<=n;i++){
        cin>>f[i].x>>f[i].y;
        if(f[i].x>f[i].y)swap(f[i].x,f[i].y);
        if(f[i].x!=2*i-1||f[i].y!=2*i)fl=1;
        f[i].c=i;
    }
    sort(f+1,f+n+1,cmp);
    if(fl==0){
        cout<<n*(n-1)/2*(n-2)/3;
        return 0;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(f[k].x<f[i].y&&f[i].y<f[j].y&&f[j].y<f[k].y)ans++;
                if(f[j].y<f[k].x&&f[k].y<f[i].y)ans++;
                if(f[i].y<f[j].x&&f[j].y<f[k].x)ans++;
            }
        }
    }
    cout<<ans;  
    return 0;
}
