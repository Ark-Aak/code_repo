#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n, lst = -1;
	cin >> n;
	while (n) {
		long long x = n % 10;
		if (x <= lst) {
			cout << "No" << endl;
			return 0;
		}
		lst = x;
		n /= 10;
	}
	cout << "Yes" << endl;
}
