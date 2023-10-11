#include<bits/stdc++.h>
using namespace std;
inline int Clac(int x)
{
	bool b[10] = {0};
	int res = 0;
	while(x) b[x % 10] = 1,x /= 10;
	for(int i = 0;i < 10;i++) if(b[i]) res++;
	return res;
}
int T;
int x,n;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> x >> n;
		if(n == 0)
		{
			cout << 1 << "\n";
			continue;
		}
		int op = Clac(x);
		if(op == 1)
		{
			cout << 1 << "\n";
			continue;
		}
		if(n == 1)
		{
			if(op == 2)
				cout << 7 << "\n";
			else
				cout << 24 << "\n";
		}else{
			if(op == 2)
				cout << 8 << "\n";
			else
				cout << 27 << "\n";
		}
	}
	return 0;
}
