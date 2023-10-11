#include<bits/stdc++.h>
#define int long long
using namespace std;
int x, y, z, a, b, c, t;
int f(int x, int y, int a, int b) {
	if(y - b == x - a) return 1;
	if(y != 0 && x != 0) {
		if(b % y == 0 && a % x == 0 && b / y == a / x) {
			return 1;
		}
	}
	return 2;			
}
int min(int a, int b) {
	if(a < b) return a;
	return b;
}
struct node{
	int X, Y, Z, d;
};
/*void bfs() {
	queue<node>Q;
	map<int, map<int, map<int, int> > >vis;
	Q.push((node){x, y, z, 0});
	vis[x][y][z] = 1;
	while(!Q.empty()) {
		node cmp = Q.front();
		Q.pop();
		for(int i = -20; i <= 20; i++) {
			int dx = x + i, dy = y + i, dz = z + i;
			if(!vis[dx][dy][dz]) {
			    vis[dx][dy][dz] = 1;
			    Q.push((node){dx, dy, dz, cmp.X})
			}
		}
	}
}*/
int Ans;
void dfs(int x, int y, int z, int k) {
	if(k == 4 || k >= Ans) return;
	//cout << Ans << endl;
	if(x == a && y == b && z == c) {
		Ans = min(Ans, k);
		return;
	}
	for(int i = -2; i <= 2; i++) {
		dfs(x + i, y, z, k + 1);
		dfs(x, y + i, z, k + 1);
		dfs(x, y, z + i, k + 1);
		dfs(x + i, y + i, z, k + 1);
		dfs(x + i, y, z + i, k + 1);
		dfs(x, y + i, z + i, k + 1);
		dfs(x + i, y + i, z + i, k + 1);
		
		dfs(x * i, y, z, k + 1);
		dfs(x, y * i, z, k + 1);
		dfs(x, y, z * i, k + 1);
		dfs(x * i, y * i, z, k + 1);
		dfs(x * i, y, z * i, k + 1);
		dfs(x, y * i, z * i, k + 1);
		dfs(x * i, y * i, z * i, k + 1);
	}
}

signed main() {
	freopen("triple.in", "r", stdin);
	freopen("triple.out", "w", stdout);
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &z, &a, &b, &c);
		int num = 0;
		if(x == a) num++;
		if(y == b) num++;
		if(z == c) num++;
		if(num == 3) {
			cout << 0 << endl;
			continue;
		}
		if(num == 2) {
			cout << 1 << endl;
			continue;
		}
		if(num == 1) {
			if(x == a) {
				cout << f(y, z, b, c) << endl;
				continue; 
			}
			if(y == b) {
				cout << f(x, z, a, c) << endl;
				continue;
			}
			if(c == z) {
				cout << f(x, y, a, b) << endl;
				continue;
			}
		}
		if(num == 0) {
			if(abs(x) <= 1 && abs(y) <= 1 && abs(z) <= 1 && abs(a) <= 1 && abs(b) <= 1 && abs(c) <= 1) {
			    Ans = 3;
			    dfs(x, y, z, 0);
			    cout << Ans << endl;
			    continue;
	        }
			int ans = 3;
			int g1 = x - a, g2 = y - b, g3 = z - c;
			if(x - a == y - b && y - b == z - c) {
				cout << 1 << endl;
				continue;
			}
			if(g1 == g2 || g1 == g3 || g2 == g3) {
				ans = min(ans, (long long)2);
			} //只用加法 
			g1 = abs(g1);
			g2 = abs(g2);
			g3 = abs(g3);
			if(g1 + g2 == g3 || g1 + g3 == g2 || g2 + g3 == g1) {
				ans = min(ans, (long long)2);
			} 
			
			
			if(x != 0 && y != 0 && z != 0) {
				if(a % x == 0 && b % y == 0 && c % z == 0 && a / x == b / y && b / y == c / z) {
					cout << 1 << endl;
					continue;
				}
			}
			if(x != 0 && y != 0) {
				if(a % x == 0 && b % y == 0 && a / x == b / y) {
					cout << 2 << endl;
					continue;
				}
			}
			if(x != 0 && z != 0) {
				if(a % x == 0 && c % z == 0 && a / x == c / z) {
					cout << 2 << endl;
					continue;
				}
			}
			if(y != 0 && z != 0) {
				if(c % z == 0 && b % y == 0 && c / z == b / y) {
					cout << 2 << endl;
					continue;
				}
			}
			ans = min(ans, min(f(x, y, a, b), min(f(x, z, a, c), f(y, z, b, c))) + 1);
			
			cout << ans << endl;
		}
	}
	
	return 0;
}
/*
1
-1 -3 -1
10 -10 4
*/

/*
-2 8 5
3 3 -5
*/

/*
-9 -10 -4
0 4 0
*/
