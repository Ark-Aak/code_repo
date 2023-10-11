#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, l, r;

int main() {
    freopen("kel.in", "r", stdin);
    freopen("kel.out", "w", stdout);
    cin >> n >> l >> r;
    if(n == 1 && l <= r) {
        cout << l;
        return 0;
    }
    if((r - l + 1) * (r - l) < n) {
        cout << "Shinomiya";
        return 0;
    }
    ll len = r - l + 1;
    for(ll i = 1; i <= len - 1; ++i) {
        ll c = 0;
        for(ll j = 1; j <= len; ++j) {
            if((i - 1) * len + j > n) return 0;
            if(j != 1 && (i * (j - 1) + c) % len == c) ++c;
            cout << l + (i * (j - 1) + c) % len << ' ';
        }
    }
    return 0;
}