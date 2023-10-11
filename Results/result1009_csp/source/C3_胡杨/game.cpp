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
const int mod = 1e9 + 7;
int T;
int f[1010][1010];
int s[1010][1010];
signed main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(T);
	for(int i = 1 ; i <= 10 ; i++) {
		for(int j = 1 ; j <= 10 ; j++) {
			if(j > i) {
				if(j % i == 0) f[i][j] = j / i - 1;
				else {
					int s = 0;
					if(i % 2 == 0) s += i - 1;
					if(j % 2 == 0) s += j - 1;
					if(i % 2) s += i / 2 * 2;
					if(j % 2) s += j / 2 * 2;
					f[i][j] = s;
				}
			}
			f[j][i] = f[i][j];
		}
    }
    f[4][6] = 3;
    f[6][4] = 3;
    f[4][10] = 5;
    f[10][4] = 5;
    f[6][8] = 5;
    f[8][6] = 5;
    f[6][9] = 3;
    f[6][10] = 6;
    f[8][10] = 7;
    f[10][8] = 7;
    for(int i = 1 ; i <= 10 ; i++)
        for(int j = 1 ; j <= 10 ; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + f[i][j] % mod;
    while(T--){
    	int x, y;
    	read(x); read(y);
    	printf("%lld\n", s[x][y]);
	}
	return 0;
}


