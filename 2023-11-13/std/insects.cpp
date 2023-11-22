#include <bits/stdc++.h>
using namespace std;
long double sx,sy,x,y,d;
struct name{
    long double a,b;
}a[2];
int main(){
	freopen("insects.in","r",stdin);
	freopen("insects.out","w",stdout); 
    cin>>sx>>sy>>x>>y;
    for(int i=0;i<2;i++) cin>>a[i].a>>a[i].b;
    if(a[1].b==0) swap(a[1],a[0]);
    d=acos(-1)/atan2(a[1].b,a[1].a);
    cout<<ceil(d-1e-8)-1;
    return 0;
}
