#include <iostream>
#include <cstdio>
const int N=(int)1e6+100;
int n,num[N];
bool flag=true;
int main() {
    freopen("yo.in","r",stdin);
    freopen("yo.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%1d",&num[i]);
        if(num[i]) flag=false;
    }
    char str[N];
    scanf("%s",str);
    if(str[0]=='o'&&!flag) printf("oimiya");
    else printf("yoimiya");
    return 0;
}