#include<bits/stdc++.h>
#define N 5010
using namespace std;
int n, m;
struct node{
	int to, w;
};
vector<node>p[N];
int f[N][N][2]; //1:Alice 0:Bob
int dfs(int x, int W, int pos) {
	if(f[x][W][pos] != -1) return f[x][W][pos];
	int A = 0, B = 1e9;
    for(int i = 0; i < p[x].size(); i++) {
    	int y = p[x][i].to, w = p[x][i].w;
    	//cout << w << " " << W << endl;
    	if(pos == 1) {
    		if(w > W) {
    			A = max(A, dfs(y, w, pos ^ 1) + 1);
			}
		}
		else {
			if(w > W) {
				B = min(B, dfs(y, w, pos ^ 1) + 1);
			}
		}
	}	
	if(pos == 1) {
		return f[x][W][pos] = A;
	}
	else {
		if(B == 1e9) return f[x][W][pos] = 0;
		else return f[x][W][pos] = B;
	}
}
signed main() {
	freopen("increase.in", "r", stdin);
	freopen("increase.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) 
    for(int j = 0; j <= m; j++) f[i][j][0] = f[i][j][1] = -1;
    for(int i = 1; i <= m; i++) {
    	int u, v, w;
    	scanf("%d %d %d", &u, &v, &w);
    	p[u].push_back((node){v, w});
    	p[v].push_back((node){u, w});
	}
	for(int i = 1; i <= n; i++) {
		printf("%d ", dfs(i, 0, 1));
	}
	return 0;
}

