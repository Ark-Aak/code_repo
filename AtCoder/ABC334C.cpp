#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

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

#define int ll

int n, k;
const int Maxn = 2000010;
int a[Maxn], sum1, sum2;
int pre[Maxn], suf[Maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1 ; i <= k ; i++) cin >> a[i];
    sort(a + 1, a + k + 1);
    if(k & 1){
        for(int i = 1 ; i < k ; i += 2) pre[i + 1] = pre[i - 1] + a[i + 1] - a[i];
        for(int i = k ; i > 1 ; i -= 2) suf[i - 1] = suf[i + 1] + a[i] - a[i - 1];
        sum1 = 1e18;
        for(int i = 1 ; i <= k ; i += 2) sum1 = min(sum1, pre[i - 1] + suf[i + 1]);
        cout << sum1 << '\n';
    }else{
        for(int i = 1 ; i <= k ; i += 2) sum1 += a[i + 1] - a[i];
        cout << sum1 << '\n';
    }
    return 0;
}
