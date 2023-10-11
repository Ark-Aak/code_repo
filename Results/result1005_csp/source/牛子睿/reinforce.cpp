#include <iostream>
#include <cstdio>
#include <cstring>
char str[114514];
int t[200],ans;
int main() {
    freopen("reinforce.in","r",stdin);
    freopen("reinforce.out","w",stdout);
    scanf("%s",str);
    int n=strlen(str);
    for(int i=1;i<=n;i++) ++t[str[i]];
    for(int i=1;i<=199;i++) ans=std::max(ans,t[i]);
    printf("%d",ans)    ;
    return 0;
}