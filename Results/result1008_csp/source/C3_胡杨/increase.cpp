#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
int n, m;
struct node{
	int x, y, w;
}t[500010];
bool cmp(node x, node y){
	return x.w > y.w;
}
int a[500010], b[500010], Min[500010];
signed main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
    read(n); read(m);
    for(int i = 1 ; i <= m ; i++){
    	read(t[i].x);
    	read(t[i].y);
    	read(t[i].w);
	}
	sort(t + 1, t + m + 1, cmp);
	memset(Min, 0x3f, sizeof Min);
	for(int i = 1 ; i <= m ; i++){
		int x = t[i].x, y = t[i].y;
		int ax = a[x], bx = b[x], ay = a[y], by = b[y];
		if(Min[x] >= ay + 1) Min[x] = ay + 1;
		b[x] = Min[x];
		if(Min[y] >= ax + 1) Min[y] = ax + 1;
		b[y] = Min[y];
		a[x] = max(a[x], by + 1);
		a[y] = max(a[y], bx + 1);
	}
	for(int i = 1 ; i <= n ; i++) printf("%lld ", a[i]);
	
	return 0;
}
/*
6 12
5 3 2
4 5 4
4 1 7
4 2 8
3 6 3
6 6 10
1 1 6
5 2 11
3 6 9
4 2 12
4 6 5
3 4 1
*/

