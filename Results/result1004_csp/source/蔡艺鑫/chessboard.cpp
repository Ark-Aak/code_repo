#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m;
int vis[N][N];
char c[N][N];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
signed main(){
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(c[i][j] != '?'){
				if(j != 1 && i != n && c[i][j - 1] == '0' && c[i][j] == '1') vis[i + 1][j] = vis[i + 1][j - 1] = 1;
				if(j != 1 && i != n && c[i][j - 1] == '1' && c[i][j] == '0') vis[i + 1][j] = vis[i + 1][j - 1] = 2;	
				if(j != 1 && vis[i][j] == 1 && vis[i][j - 1] == 1 && c[i][j - 1] == '1' && c[i][j] == '0'){
					cout << "No\n";
					return 0;
				}
				if(j != 1 && vis[i][j] == 2 && vis[i][j - 1] == 2 && c[i][j - 1] == '0' && c[i][j] == '1'){
					cout << "No\n";
					return 0;
				}				
			}
			else{
				if(j == 1){
					if(vis[i][j] == 1) c[i][j] = '0';
					else if(vis[i][j] == 2) c[i][j] = '1';
					else if(int(c[i][j + 1]) > 57 || int(c[i][j + 1]) < 48) c[i][j] = '1';
					else c[i][j] = c[i][j + 1];
				} 
				else{
//					if(vis[i][j - 1] == 1 && vis[i][j] == 1 && c[i][j - 1] == '1') c[i][j] = '1';
//					else if(vis[i][j - 1] == 2 && vis[i][j] == 2 && c[i][j - 1] == '0') c[i][j] = '0'; 
					c[i][j] = c[i][j - 1];
					if(vis[i][j] == 1 && vis[i][j + 1] == 1 && c[i][j + 1] == '0') c[i][j] = '0';
					if(vis[i][j] == 2 && vis[i][j + 1] == 2 && c[i][j + 1] == '1') c[i][j] = '1';
				}
				if(j != 1 && i != n && c[i][j - 1] == '0' && c[i][j] == '1') vis[i + 1][j - 1] = vis[i + 1][j] = 1;
				if(j != 1 && i != n && c[i][j - 1] == '1' && c[i][j] == '0') vis[i + 1][j - 1] = vis[i + 1][j] = 2;
			}
		}
	cout << "Yes\n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cout << c[i][j];
		cout << endl;
	}
	return 0;
}

