#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int Mod = 998244353;
int n, k, m, L[N], R[N], S[N]; 
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
inline int ksm(int a, int b){
	int cnt = 1;
	while(b){
		if(b & 1) cnt = cnt * a % Mod;
		a = a * a % Mod;
		b >>= 1;
	}
	return cnt % Mod;
}
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n = read(), k = read(), m = read();
	for(int i = 1; i <= m; i++) L[i] = read(), R[i] = read(), S[i] = read();
	if(m == 0){
		cout << ksm(ksm(2, k), n) % Mod;
		return 0;
	}	
	if(k == 0){
		bool flag = 1;
		for(int i = 1; i <= m; i++) 
			if(S[i] != 0) flag = 0;
		if(flag) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	if(k == 1){
		bool flag = 1;
		for(int i = 1; i <= m; i++)
			if(S[i] != 0 && S[i] != 1) flag = 0;
		if(!flag){
			cout << 0 << endl;
			return 0;
		}
		
	}
	if(n <= 10 && m <= 10){
		
	}
	return 0;
}

