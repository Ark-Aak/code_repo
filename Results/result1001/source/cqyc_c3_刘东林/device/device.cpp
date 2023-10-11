#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t[10];
int n,m,q;

int main(){
    freopen("device.in","r",stdin);
    freopen("device.out","w",stdout);
    cin >> q;
    while(q--){
        memset(t,0,sizeof(t));
        cin >> n >> m;
        auto s = to_string(n);
        int f = 0;
        for(char c:s){
            if(t[c^48]==1)
                f = 1;
            else if(t[c^48]==2)
                f = 2;
            t[c^48]++;
        }
        if(f==2)
            puts("1");
        else if(!m)
            puts("1");
        else if(m==1){
            if(!f)
                puts("24");
            else
                puts("7");
        }
        else if(m>1){
            if(f==1)
                puts("8");
            else
                puts("27");
        }
    }
    return 0;
}