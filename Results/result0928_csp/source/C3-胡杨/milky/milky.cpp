#include<bits/stdc++.h>
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
const int maxn = 1e6 + 10;
string s;
unsigned int b[maxn],f[1010][10];
unsigned int f1[maxn][10];
unsigned int Q;
struct node {
	int l,r;
} q[maxn];
vector<int> a[10];
void cleann() {
	a[1].clear();
	a[2].clear();
	a[3].clear();
	a[4].clear();
	a[5].clear();
	memset(f,0,sizeof f);
}
int main() {
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout);
	cin >> s;
	for(int i = 1 ; i <= s.size() ; i++) {
		if(s[i - 1] == 'm') b[i] = 1;
		if(s[i - 1] == 'i') b[i] = 2;
		if(s[i - 1] == 'l') b[i] = 3;
		if(s[i - 1] == 'k') b[i] = 4;
		if(s[i - 1] == 'y') b[i] = 5;
	}
	read(Q);
	int tt = 0;
	for(int i = 1 ; i <= Q ; i++) {
		read(q[i].l),read(q[i].r);
		if(q[i].l != 1) tt = 1;
	}
	if(tt == 1) {
		for(int qq = 1 ; qq <= Q ; qq++) {
			int l = q[qq].l;
			int r = q[qq].r;
			memset(f, 0, sizeof f);
			for(int i = 0 ; i <= r - l + 1 ; i++) f[i][0] = 1;
			for(int i = 1 ; i <= r - l + 1 ; i++) {
				for(int j = 1 ; j <= 5 ; j++) {
					if(b[i + l - 1] == j)
						f[i][j] = f[i][j - 1] + f[i - 1][j];
					else f[i][j] = f[i - 1][j];
				}
			}
			printf("%lld\n",f[r - l + 1][5]);
		}
	} else {
		for(int i = 0 ; i <= s.size() ; i++) f1[i][0] = 1;
		for(int i = 1 ; i <= s.size() ; i++) {
			for(int j = 1 ; j <= 5 ; j++) {
				if(b[i] == j)
					f1[i][j] = f1[i][j - 1] + f1[i - 1][j];
				else f1[i][j] = f1[i - 1][j];
			}
		}
		for(int i = 1 ; i <= Q ; i++)
		    printf("%lld\n",f1[q[i].r][5]);
	}
	return 0;
}
/*
milky
5
1 1
1 2
1 3
1 4
1 5
*/
