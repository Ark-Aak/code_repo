#include "testlib.h"

using namespace std;

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
		rep (i, 1, n) {
			arr[i] = ouf.readInt();
		}
	}
}