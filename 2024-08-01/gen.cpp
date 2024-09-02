#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	freopen("data.in", "w", stdout);
	const int n = 500;
	cout << n << endl;
	for (int i = 2; i <= n; i++) {
		int fa = rnd() % i + 1;
		cout << fa << " " << i << endl;
	}
}
