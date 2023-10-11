#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn = 405;

int N,K;
int A[Maxn],Sum[Maxn],dp[Maxn][Maxn];

void cmin(int &x,int y){if(y < x) x = y;}

int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	memset(dp , -1, sizeof dp);
	scanf("%d%d",&N,&K); 
	for(int i = 1 ; i <= N ; ++i) 
		scanf("%d",&A[i]),Sum[i] = Sum[i-1] + A[i];
	int mx = -1;
	for(int i = 1 ; i <= N ; ++i){
		mx = max(mx,A[i]);
		dp[i][1] = mx*i - Sum[i];
	}
	for(int i = 1 ; i <= N ; ++i)
	for(int j = 1 ; j <= i ; ++j) if(dp[i][j] != -1){
		mx = -1;
		for(int k = i + 1 ; k <= N ; ++k){
			mx = max(mx,A[k]);
			int upd = dp[i][j] + mx*(k-i)-Sum[k] + Sum[i];
			if(dp[k][j+1] != -1) cmin(dp[k][j+1],upd);
			else dp[k][j+1] = upd;
		}
	}
	printf("%d\n",dp[N][K+1]);
	return 0;
}
