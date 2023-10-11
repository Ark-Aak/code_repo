#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
const ll mod=1e9+7;
ll k;
int main(){
    freopen("crazy.in","r",stdin);
    freopen("crazy.out","w",stdout);
    cin>>k;
    if(!(k&1))cout<<2<<endl;
    else cout<<3<<endl;
    return 0;
}