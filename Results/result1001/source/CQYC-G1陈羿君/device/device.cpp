#include <bits/stdc++.h>
using namespace std;
int q,n,m,t[10];
string s;
int main(){
    freopen("device.in","r",stdin);
    freopen("device.out","w",stdout);
    cin>>q;
    while(q--){
        int bj=0;
        memset(t,0,sizeof(t));
        cin>>n>>m;
        s=to_string(n);
        for(int i=0;i<s.size();i++){
            if(t[s[i]-'0']==1) bj=1;
            else if(t[s[i]-'0']==2) bj=2;
            t[s[i]-'0']++;
        }
        if(bj==2) cout<<1<<"\n";
        else if(m>=2){
            if(bj==1) cout<<8<<"\n";
            else cout<<27<<"\n";
        }
        else if(m==1){
            if(bj==0) cout<<24<<"\n";
            else cout<<7<<"\n";
        }
        else if(m==0) cout<<1<<"\n";
    }
    return 0;
}