#include<bits/stdc++.h>
using namespace std;
int n, m;
char a[2010][2010];
signed main() {
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
	
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++) {
		if(i >= 2 && j >= 2 && a[i - 1][j] == '1' && a[i][j - 1] == '1' && a[i - 1][j - 1] == '0' && a[i][j] == '0') {
			printf("No");
			return 0;
		}
		if(i >= 2 && j >= 2 && a[i - 1][j] == '0' && a[i][j - 1] == '0' && a[i - 1][j - 1] == '1' && a[i][j] == '1') {
			printf("No");
		    return 0;
		}
	}
	//cout << "e";
	while(1) {
		bool can = 0; //还可以继续填数，就继续 
		for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= m; j++) {
		if(a[i][j] != '?') continue;
		int mt0 = -1, mt1 = -1;
		if(i >= 2 && j >= 2 && a[i - 1][j] == '1' && a[i][j - 1] == '1' && a[i - 1][j - 1] == '0') mt1 = 1;
		if(a[i + 1][j] == '1' && a[i][j + 1] == '1' && a[i + 1][j + 1] == '0') mt1 = 1;
		if(j >= 2 && a[i][j - 1] == '1' && a[i + 1][j - 1] == '0' && a[i + 1][j] == '1') mt1 = 1;
		if(i >= 2 && a[i - 1][j] == '1' && a[i - 1][j + 1] == '0' && a[i][j + 1] == '1') mt1 = 1;
		
		if(i >= 2 && j >= 2 && a[i - 1][j] == '0' && a[i][j - 1] == '0' && a[i - 1][j - 1] == '1') mt0 = 1;
		if(a[i + 1][j] == '0' && a[i][j + 1] == '0' && a[i + 1][j + 1] == '1') mt0 = 1;
		if(j >= 2 && a[i][j - 1] == '0' && a[i + 1][j - 1] == '1' && a[i + 1][j] == '0') mt0 = 1;
		if(i >= 2 && a[i - 1][j] == '0' && a[i - 1][j + 1] == '1' && a[i][j + 1] == '0') mt0 = 1;
		
		//cout << i << "," << j << " " << mt0 << " " << mt1 << endl;
		if(mt0 == 1 && mt1 == 1) {
			printf("No\n");
			return 0;
		}
		if(mt0 == 1) {
		    a[i][j] = '0';	
		    can = 1;
		}
		if(mt1 == 1) {
			a[i][j] = '1';
			can = 1;
		} 
		
		//if(mt0 != 1 && mt1 != 1) a[i][j] = '0';
	    }
		if(!can) { //填不了了，只能瞎填 
		//cout << "e";
		for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= m; j++) {
		if(a[i][j] != '?') continue;
		int mt0 = -1, mt1 = -1;
		if(i >= 2 && j >= 2 && a[i - 1][j] == '1' && a[i][j - 1] == '1' && a[i - 1][j - 1] == '0') mt1 = 1;
		if(a[i + 1][j] == '1' && a[i][j + 1] == '1' && a[i + 1][j + 1] == '0') mt1 = 1;
		if(j >= 2 && a[i][j - 1] == '1' && a[i + 1][j - 1] == '0' && a[i + 1][j] == '1') mt1 = 1;
		if(i >= 2 && a[i - 1][j] == '1' && a[i - 1][j + 1] == '0' && a[i][j + 1] == '1') mt1 = 1;
		
		if(i >= 2 && j >= 2 && a[i - 1][j] == '0' && a[i][j - 1] == '0' && a[i - 1][j - 1] == '1') mt0 = 1;
		if(a[i + 1][j] == '0' && a[i][j + 1] == '0' && a[i + 1][j + 1] == '1') mt0 = 1;
		if(j >= 2 && a[i][j - 1] == '0' && a[i + 1][j - 1] == '1' && a[i + 1][j] == '0') mt0 = 1;
		if(i >= 2 && a[i - 1][j] == '0' && a[i - 1][j + 1] == '1' && a[i][j + 1] == '0') mt0 = 1;
		
		//cout << i << "," << j << " " << mt0 << " " << mt1 << endl;
		if(mt0 == 1 && mt1 == 1) {
			printf("No");
			return 0;
		}
		if(mt0 == 1) {
		    a[i][j] = '0';	
		}
		if(mt1 == 1) {
			a[i][j] = '1';
		} 
		
		if(mt0 != 1 && mt1 != 1) a[i][j] = '0';
	    }
		 
		break;   
		} 
	}
	printf("Yes\n");
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) printf("%c", a[i][j]);
		printf("\n");
	}
	return 0;
}
/*
3 3
011
??0
001
*/

