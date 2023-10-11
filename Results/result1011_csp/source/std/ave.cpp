#include<bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int N;
double A[Maxn];

inline int read(){
	int x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') 
		x = x*10 + ch - '0',ch = getchar();
	return x;
}


int main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; ++i)
		A[i] = read();
	sort(A + 1 , A + N + 1);
	double now = A[1];
	for(int i = 1 ; i <= N ; ++i)
		now = (now + A[i])/2;
	printf("%.6lf\n",now);
	return 0;
}
