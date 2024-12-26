#include <iostream>

using namespace std;

int n, q, P, Ans = 0;

int main() {
	cin >> n >> q >> P;
	for (int i = 1; i <= q; i++) {
		int op, Lx, Rx, Ly, Ry;
		cin >> op >> Lx >> Rx >> Ly >> Ry;
		Lx ^= Ans, Ly ^= Ans, Rx ^= Ans, Ry ^= Ans;
		Lx = (Lx % n) + 1, Rx = (Rx % n) + 1;
		Ly = (Ly % n) + 1, Ry = (Ry % n) + 1;
		if (Lx > Rx) swap(Lx, Rx);
		if (Ly > Ry) swap(Ly, Ry);
		if (op == 1) {
			// do something
		}
		else {
			bool legal = false;
			// do something
			if (legal) {
				cout << "Yes" << endl;
				Ans = (Ans + 1ll * (Lx + Ry) * (Ly + Rx)) % P;
			}
			else {
				cout << "No" << endl;
				Ans = (Ans + 1ll * (Lx + Rx) * (Ly + Ry)) % P;
			}
		}
	}
}
