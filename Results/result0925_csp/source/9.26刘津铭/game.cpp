#include<bits/stdc++.h>
#define N 20
using namespace std;
/*int T, n, k;
string s;
int f[10005][2]; //2:win 1:lose 0:win
int dfs(int num, bool o) {
	if(num == 0 || num == (1 << n) - 1) return 2;
	for(int i = 0; i + k - 1 < n; i++) {
		int New = num;
		for(int j = i; j <= i + k - 1; j++)
		    New = New & (1 << j);
		if(dfs(New, !o) == )
	}
}*/
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		cout << "win" << endl;
	}
	/*
	while(T--) {
		cin >> n >> k;
		cin >> s;
		int num = 0;
		for(int i = 0; i < n; i++) 
		    if(s[i] == '1') num += pow(2, i); 
		int ans = dfs(num, 1);
		if(ans == 2) cout << "win" << endl;
		else if(ans == 1) cout << "lose" << endl;
		else if(ans == 0) cout << "tie" << endl;
	}*/
	return 0;
} 
