/* name: jump
 * author: 5ab
 * created at: 2023-08-19
 */
#include <iostream>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define ssz(x) (int((x).size()))

using ll = long long;
const int max_n = 5e5;

int stk[max_n + 1];

signed main()
{
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, stp = 0;
	
	cin >> n;
	stk[stp++] = 0x3fffffff;
	for (int i = 0, x; i < n; i++)
	{
		cin >> x;
		while (stp > 0 && x >= stk[stp - 1])
			stp--;
		stk[stp++] = x;
		cout << stp - 1 << " \n"[i == n - 1];
	}
	
	return 0;
}
// started coding at: 08-19 08:45:34