#include <iostream>
#include <cstdio>
#include <cmath>
struct tri{node a,b,c;};
struct node{int x,y;};
inline int gcd(int x,int y) {
    if(y==0) return 1;
    return !(x%y)?y:gcd(y,x%y);
}
inline int getcnt(node x,node y){return gcd(abs(x.x-y.x),abs(x.y-y.y))+1;}
inline int check(node x,node y,node z){return (x.x-y.x)*(y.y-z.y)==(x.y-y.y)*(y.x*z.x);}
int main() {
    freopen("grid.in","r",stdin);
    freopen("grid.out","w",stdout);

    printf("Nothing there o_O");

    return 0;
}
