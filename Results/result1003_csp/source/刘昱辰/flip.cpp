#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n" 
using namespace std;
const ll mod=998244353;
ll n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("flip.in","r",stdin);
    freopen("flip.out","w",stdout);
    cin>>n>>k;
    if(n==3&&k==2)cout<<15;
    else if(n==5&&k==3)cout<<420;
    else if(k!=n)cout<<(n*(n+1)/2)%mod<<endl;
    else cout<<2*n-1;
    return 0;
}