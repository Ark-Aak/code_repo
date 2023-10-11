#include<bits/stdc++.h>
#define N 5100
using namespace std;
int n, len = 0;
long long ans = -1e15;
long long sum[N][N]; 
struct node{
	int X, Y; //真实的坐标
	int x, y; //离散化后的坐标
	int c;  
}a[3000];
int b[N], C[N], tot;
map<int, int>s;
int get_sum(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];	
}
signed main() {
	freopen("imp.in", "r", stdin);
	freopen("imp.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a[i].X, &a[i].Y, &a[i].c);
		b[++tot] = a[i].X;
		b[++tot] = a[i].Y;
	}
	sort(b + 1, b + tot + 1);
	for(int i = 1; i <= tot; i++) if(i == 1 || b[i] != b[i - 1]) C[++len] = b[i];
	for(int i = 1; i <= len; i++) s[C[i]] = i;
	for(int i = 1; i <= n; i++) {
		a[i].x = s[a[i].X];
		a[i].y = s[a[i].Y];
		sum[a[i].x][a[i].y] += a[i].c;
	} 
	for(int i = 1; i <= len; i++)
	for(int j = 1; j <= len; j++) sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
	for(int i = 1; i <= len; i++)  //左下角 (i,i) 
		for(int j = i; j <= len; j++) // 右上角 (j, j)
			ans = max(ans, get_sum(i, i, j, j) - (long long)(C[j] - C[i]));
	printf("%lld", ans);
	return 0;
} 
/*
8
3 19 -9
11 22 10
8 18 2
8 19 -3
1 4 -5
2 4 -6
18 18 1
7 7 -4
*/
