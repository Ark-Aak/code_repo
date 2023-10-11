#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e18;
int Q;
int a, b, c;
int ans;
void dfs(int x, int y, int z, int s){
	if(s > 3) return;
	if(x == a && y == b && z == c){
		ans = min(s, ans);
		return;
	} 
	for(int i = -10 ; i <= 10 ; i++){
		dfs(x + i, y, z, s + 1);
		dfs(x, y + i, z, s + 1);
		dfs(x, y, z + i, s + 1);
		dfs(x * i, y, z, s + 1);
		dfs(x, y * i, z, s + 1);
		dfs(x, y, z * i, s + 1);
		dfs(x + i, y + i, z, s + 1);
		dfs(x, y + i, z + i, s + 1);
		dfs(x + i, y, z + i, s + 1);
		dfs(x * i, y * i, z, s + 1);
		dfs(x, y * i, z * i, s + 1);
		dfs(x * i, y, z * i, s + 1);
		dfs(x + i, y + i, z + i, s + 1);
		dfs(x * i, y * i, z * i, s + 1);
	}
}
signed main(){
    freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	scanf("%lld", &Q);
	while(Q--){
		int x, y, z;
		cin >> x >> y >> z;
		cin >> a >> b >> c;
		ans = 3;
		int c1 = x - a, c2 = y - b, c3 = z - c;
		int j1 = (x == 0) ? inf : a / x, j2 = (y == 0) ? inf - 1 : b / y, j3 = (z == 0) ? inf - 2 : z / c;
		int y1 = (x == 0) ? inf : a % x, y2 = (y == 0) ? inf - 1 : b % y, y3 = (z == 0) ? inf - 2 : z % c;
		if(x == a){
			if(c1 == 0 && c2 == 0 && c3 == 0) ans = 0;
			else if(j1 == j2 && j2 == j3 && y1 == 0 && y2 == 0 && y3 == 0 && j1 != inf) ans = 0;
			else if(c2 == 0 || c3 == 0) ans = 1;
			else if(j2 == 0 || j3 == 0) ans = 1;
			else if(c2 == c3 || (j2 == j3 && j2 != inf && j3 != inf)) ans = 1;
			else ans = 2;
			printf("%lld\n", ans);
			continue;
		}
		if(c1 == 0 && c2 == 0 && c3 == 0) ans = 0;
		else if((c1 == c2 && c2 == c3) || (c1 == c2 && c3 == 0) || (c1 == c3 && c2 == 0) || (c2 == c3 && c1 == 0)) ans = 1;
		else if((j1 == j2 && j2 == j3 && y1 == 0 && y2 == 0 && y3 == 0) || (j1 == j2 && j3 == 1) || (j1 == j3 && j2 == 1) || (j2 == j3 && j1 == 1)) ans = 1;
		
		else if(c1 == c2 && c2 != c3) ans = 2;
		else if(c2 == c3 && c2 != c1) ans = 2;
		else if(c1 == c3 && c2 != c1) ans = 2;
		
		else if(j1 == j2 && j2 != j3 && y1 == 0 && y2 == 0) ans = 2;
		else if(j2 == j3 && j2 != j1 && y2 == 0 && y3 == 9) ans = 2;
		else if(j1 == j3 && j2 != j1 && y1 == 0 && y3 == 0) ans = 2;
		
		else if(b % (y + c1) == 0 && b == j3 * (y + c1)) ans = 2;
		else if(c % (z + c1) == 0 && c == j2 / (y + c1)) ans = 2;
		else if(a % (x + c3) == 0 && a == j3 / (x + c3)) ans = 2;
		printf("%lld\n",ans);
	}
	return 0;
}
