#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> vec[20];
char s[1000005], t[1000005];

bool check() {
	for (int i = 0; i < n; i++)
		if (t[i] == 121) vec[(n - i & 1) * 10 + (s[i] ^ 48)].push_back(i);
	int ptr[20];
	memset(ptr, 0, sizeof ptr);
	for (int i = 0; i < n; i++)
		if (t[i] == 111) {
			int p = (n - i & 1) * 10 + (s[i] ^ 48);
			do ptr[p]++;
			while (ptr[p] < vec[p].size() && vec[p][ptr[p]] <= i);
			if (ptr[p] == vec[p].size()) return 0;
		}
	return 1;
}

int main() {
	freopen("yo.in", "r", stdin);
	freopen("yo.out", "w", stdout);
	scanf("%d%s%s", &n, s, t);
	if (check()) putchar(121);
	printf("oimiya");
	return 0;
}
