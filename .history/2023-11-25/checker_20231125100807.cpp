#include "testlib.h"

using namespace std;

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

int arr[1000005];

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
	int T = inf.readInt();
	rep (__, 1, T) {
		int n = inf.readInt(), m = inf.readInt();
		bool noSolution = 0;
		if (ans.readInt() == -1) {
			noSolution = 1;
		}
		if (noSolution) {
			if (ouf.readInt() != -1) {
				quitf(_wa, "TC %d, No solution expected, but found one.", __);
			}
			continue;
		}
		else {
			if (arr[1] = ouf.readInt(), arr[1] < 0) {
				quitf(_wa, "TC %d, There has one solution, but found -1.", __);
			}
		}
		rep (i, 1, n) cout << arr[i] << " ";
		cout << endl;
		rep (i, 1, n) if (arr[i] <= 0) {
			quitf(_wa, "TC %d, Found zero at %d = %d.", __, i, arr[i]);
		}
		rep (i, 2, n) {
			ans.readInt();
		}
		int sum = arr[1];
		rep (i, 2, n) {
			arr[i] = ouf.readInt();
			sum += arr[i];
		}
		if (sum != m) {
			quitf(_wa, "TC %d, Sum of all numbers expected to be %d, but found %d.", __, m, sum);
		}
		int minn = 1e9;
		rep (i, 1, n) minn = min(minn, arr[i]);
		int sumxor = 0;
		rep (i, 1, n) sumxor ^= arr[i];
		if (minn <= sumxor) {
			quitf(_wa, "TC %d, XOR Sum found %d > %d.", __, sumxor, minn);
		}
	}
	quitf(_ok, "Accepted.");
}