#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int cnt = 0;

int main() {
	system("g++ std.cpp -o std.exe -DLOCAL -O2 -std=c++17 -static -Wl,--stack=51200000000");
	system("g++ prob.cpp -o prob.exe -DLOCAL -O2 -std=c++17 -static -Wl,--stack=51200000000");
	system("g++ generator.cpp -o generator.exe -DLOCAL -O2 -std=c++17 -static -Wl,--stack=51200000000");
	cout << "Trying to generator a hack testcase..." << endl;
	do {
		++cnt;
		system("generator > test.in");
		system("std < test.in > test.ans");
		system("prob < test.in > test.out");
		cout << "Testcase " << cnt << " accepted" << endl;
	} while(!system("fc test.out test.ans /W > nul"));
	cout << "Get Wrong Answer at testcase " << cnt << ", exit.";
	return 0;
}
