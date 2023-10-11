#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
ll n,q,a[N],b[N];
map<pair<ll,ll>,bool>mp;
int main(){
    freopen("act.in","r",stdin);
    freopen("act.out","w",stdout);
    cin>>n>>q;
    if(q==0)return 0;
    if(n==0){
        while(q--){
            ll x,y;
            cin>>x>>y;
            if(x==y)cout<<"Bob\n";
            else if(x!=y)cout<<"Alice\n";
        }
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        mp[make_pair(a[i],b[i])]=1;
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(x==0&&y==0)cout<<"Bob\n";
        else if(mp[make_pair(x,y)])cout<<"Bob\n";
        else cout<<"Alice\n";
    }
    return 0;
}
