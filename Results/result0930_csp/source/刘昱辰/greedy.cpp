#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n" 
using namespace std;
const ll mod=147744151;

int main(){
    freopen("greedy.in","r",stdin);
    freopen("greedy.out","w",stdout);
    ll n,k;
    cin>>n>>k;
    if(k<=mod)cout<<(n%mod-1)%mod;
    else cout<<__lg(n)%mod<<endl;
    return 0;
}