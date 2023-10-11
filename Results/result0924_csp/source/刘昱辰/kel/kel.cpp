#include<bits/stdc++.h>
#define ll long long
#define N 1200005
using namespace std;
ll n,l,r,a[N],t;
int main(){
    freopen("kel.in","r",stdin);
    freopen("kel.out","w",stdout);
    cin>>n>>l>>r;
    if(n<=3){
        cout<<l<<"\n"<<l<<"\n"<<l<<"\n";
        return 0;
    }
    t=l-1;
    for(int i=1;i<=n;i++){
        if(l>r){
            cout<<"Shinomiya"<<endl;
            return 0;
        }
        if(i&1)a[i]=l;
        else a[i]=(++t);
        if(t>=r){
            l++;
            t=l-1;
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<endl;
    return 0;
}