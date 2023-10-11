#include<bits/stdc++.h>
using namespace std;
int n, k;
int f[2010][2010];
signed main() {
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &f[0][i]);
	for(int i = 1; i <= n; i++) scanf("%d", &f[1][i]);
	for(int i = 2; i <= k; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][f[i - 2][j]] = f[i - 1][j];
		}
	}
	for(int j = 1; j <= n; j++) printf("%d ", f[k][j]);
    /*
    for(int i = 0; i <= k; i++) {
    	printf("f[%d]: ", i);
    	for(int j = 1; j <= n; j++) printf("%d ", f[i][j]);
    	printf("\n");
	}*/
	

	return 0;
}

//012345 6789
//012345 012345 012345

/*
5 20
4 5 1 2 3
3 2 1 5 4
*/

/*
4:5
5:14
*/
