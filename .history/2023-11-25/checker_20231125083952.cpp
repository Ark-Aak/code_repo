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
				quitf(_wa, "No solution expected, but found one.");
			}
			continue;
		}
		rep (i, 2, n) {
			ans.readInt();
		}
		int sum = 0;
		rep (i, 1, n) {
			arr[i] = ouf.readInt();
			sum += arr[i];
		}
		if (sum != m) {
			quitf(_wa, "Sum of all numbers expected to be %d, but found %d.", m, sum);
		}
		rep (i, 1, n) {
			if (arr[i] <= 0) {
				quitf(_wa, "All numbers expected to be positive, but found %d.", arr[i]);
			}
		}
		int minn = 1e9;
		rep (i, 1, n) minn = min(minn, arr[i]);
		int sumxor = 0;
		rep (i, 1, n) sumxor ^= arr[i];
		if (sumxor <= minn) {
			quitf(_wa, "XOR Sum found %d <= %d.", sumxor, minn);
		}
	}
	quitf(_ok, "Accepted.");
}