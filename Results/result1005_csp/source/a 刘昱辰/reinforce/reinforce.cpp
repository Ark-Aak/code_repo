#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
string s;
ll cnt[N],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("reinforce.in","r",stdin);
    freopen("reinforce.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)cnt[s[i]]++,ans=max(ans,cnt[s[i]]);
    cout<<ans;
    return 0;
}