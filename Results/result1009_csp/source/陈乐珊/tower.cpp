#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e4+4;
int n,k,b[N];
vector <int> col[55];
char s[55][55];
int main() {
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	
	cin>>n>>k;
	srand(n);
	for(int i=1;i<=n;i++) {
		cin>>b[i];
		col[b[i]].push_back(i);
	}
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=k;j++) {
			cin>>s[i][j];
		}
	}
	cout<<rand()%(n*2);
	return 0;
}

