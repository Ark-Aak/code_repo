#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char ch = getchar();
	int f = 1;
	while (!isdigit(ch) && ch ^ '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
	x *= f;
}
struct node {
	int x,y,c,id,X,Y;
} a[250010];
struct node1 {
	int z,x,y;
} b[2510][2510];
int s[2510][2510];
int n,ans;
bool cmp(node q,node p) {
	if(q.x == p.x && q.y == p.y) return q.c > p.c;
	if(q.x == p.x) return q.y < p.y;
	return q.x < p.x;
}
signed main() {
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	read(n);
	for(int i = 1 ; i <= n ; i++) read(a[i].x),read(a[i].y),read(a[i].c),a[i].id = i;
	sort(a + 1, a + n + 1, cmp);
	int X = 1,Y = 1;
	b[X][Y] = {a[1].c,a[1].x,a[1].y};
	a[1].X = X;a[1].Y = Y;
	for(int i = 2 ; i <= n ; i++) {
		if(a[i].x > a[i - 1].x) X++;
		else if(a[i].y > a[i - 1].y) Y++;
		b[X][Y] = {a[i].c,a[i].x,a[i].y};
		a[i].X = X;
		a[i].Y = Y;
	}
	for(int i = 1 ; i <= X ; i++)
		for(int j = 1 ; j <= Y ; j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + b[i][j].z;
	for(int i = 1 ; i <= n ; i++) {
		if(a[i].x > a[i].y) continue;
		for(int j = 1 ; j <= n ; j++) {
			if(a[i].y > a[i].x) continue;
			int len = max(a[i].y - min(a[i].x,a[j].x),a[j].x - min(a[i].y,a[j].y));
			int X1 = max(a[j].X,a[i].X),X2 = a[j].X + a[i].X - X1;
			int Y1 = max(a[j].Y,a[i].Y),Y2 = a[j].Y + a[i].Y - Y1;
			ans = max(ans,s[X1][Y2] - s[X1][Y1 - 1] - s[X2 - 1][Y2] + s[X2][Y1] - len);
		}
	}
	cout << ans << endl;
	return 0;
}
