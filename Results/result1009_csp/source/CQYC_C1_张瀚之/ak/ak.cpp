#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100005];
long long sum;

int main() {
    freopen("ak.in", "r", stdin);
    freopen("ak.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), sum += a[i];
    printf("%lld", sum - a[rand() % 100000 + 1]);
    return 0;
}
