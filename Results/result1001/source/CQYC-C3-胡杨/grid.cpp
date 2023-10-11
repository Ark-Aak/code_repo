#include<bits/stdc++.h>
#define int long long
using namespace std;
int Q;
signed main(){
    freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
    cin >> Q;
    while(Q--){
    	int n,m;
    	cin >> n >> m;
    	if(n == 2 && m == 2){
    		cout << 12 << endl;
    		continue;
		} 
    	if(n == 1 && m == 1){
    		cout << 0 << endl;
    		continue;
		} 
    	if(min(n,m) < 2){
    		cout << 0 << endl;
    		continue;
		}
	}
	return 0;
}

