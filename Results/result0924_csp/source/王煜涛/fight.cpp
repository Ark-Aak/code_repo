#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 10010;

int n, x, a[N];
bool f = true;
double q[N << 2];

double solve(int l, int r, int k) {
    //for(int i = l; i <= r; ++i) cout << q[i] << ' ';
    //cout << endl;
    if(l == r && k == l) return 1;
    if(l == r && k != l) return 0;
    if(l == k) {
        q[r + 1] = q[l];
        return solve(l + 2, r + 1, r + 1) * (q[l] / (q[l] + q[l + 1]));
    }
    if(l + 1 == k) {
        q[r + 1] = q[l + 1];
        return solve(l + 2, r + 1, r + 1) * (q[l + 1] / (q[l] + q[l + 1]));
    }
    double res = 0;
    //double t = (q[l] * q[l] + q[l + 1] * q[l + 1]) / (q[l] + q[l + 1]);
    //q[r + 1] = t, res += solve(l + 2, r + 1, k);
    if(!f) {
        q[r + 1] = q[l], res += solve(l + 2, r + 1, k) * (q[l] / (q[l] + q[l + 1]));
        q[r + 1] = q[l + 1], res += solve(l + 2, r + 1, k) * (q[l + 1] / (q[l] + q[l + 1]));
    }else {
        q[r + 1] = q[l], res += solve(l + 2, r + 1, k);
    }
    return res;
}

int main() {
    freopen("fight.in", "r", stdin);
    freopen("fight.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d", &n, &x);
    a[1] = x;
    for(int i = 2; i <= n; ++i) {
        scanf("%d", &a[i]);
        if(a[i] != a[i - 1]) f = 0;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) q[j] = a[j];
        printf("%.15lf\n", solve(1, n, i));
        swap(a[i], a[i + 1]);
    }
    return 0;
}