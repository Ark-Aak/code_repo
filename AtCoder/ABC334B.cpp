#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;


#define int __int128

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}


int a,m,l,r;
signed main(){
	a = read(), m = read(), l = read(), r = read();
	int L=-2e18,R=2e18,res=-2e18;
	while(L<=R){

		int mid=(L+R)/2;
		if(a+mid*m>=l) res=mid,R=mid-1;
		else L=mid+1;
	}

	a=a+m*res;

	int cnt=r-a;
	print( (a>=l&&a<=r)+((cnt>0)*cnt/m) );
	return 0;
}
