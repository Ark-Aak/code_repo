#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
long long a[5],b[5],d[5],nw[5];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	cin >> T;
	while(T--)
	{
		for(int i = 1;i <= 3;i++) cin >> a[i];
		for(int i = 1;i <= 3;i++) cin >> b[i];
		for(int i = 1;i <= 3;i++) d[i] = b[i] - a[i];
		if(!d[1] && !d[2] && !d[3])
		{
			cout << 0 << "\n";
			continue;
		}
		int flag = LLONG_MIN;
		for(int i = 1;flag != LLONG_MAX && i <= 3;i++) if(d[i])
		{
			if(flag == LLONG_MIN) flag = d[i];
			if(flag != d[i]) flag = LLONG_MAX;
		}
		if(flag != LLONG_MAX)//+?
		{
			cout << 1 << "\n";
			continue;
		}
		flag = LLONG_MIN;
		for(int i = 1;flag != LLONG_MAX && i <= 3;i++) if(d[i])
		{
			if(!a[i] || b[i] % a[i] != 0)
			{
				flag = LLONG_MAX;
				continue;
			}
			if(flag == LLONG_MIN) flag = b[i] / a[i];
			if(flag != b[i] / a[i]) flag = LLONG_MAX;
		}
		if(flag != LLONG_MAX)//*?
		{
			cout << 1 << "\n";
			continue;
		}
		if(!d[1] || !d[2] || !d[3])//+1+1
		{
			cout << 2 << "\n";
			continue;
		}
		flag = 0;
		for(int i = 1;i <= 3 && !flag;i++)
		{
			for(int j = 1;j <= 3 && !flag;j++) if(i != j)
			{
				int k = 6 - i - j;
				/*white on the front: *1 = +1 | if(a+b=3) a-b = b-a | The to opt can change when they are in the same class. | Can merge when they are in the same class and one is three:(?3?a=?(3-a)?a),such ?3?1=?2?1 */
				//+1+1 have solved
				if(d[i] == d[j]){flag = 1;continue;}//+1+2
				//+1+3=+1+2
				//+2+1=+1+2
				if(d[i] == d[j] + d[k]) {flag = 1;continue;}//+2+2
				//+2+3=+1+2
				//+3+1=+2+1
				//+3+2=+2+1
				//+3+3=???What are you talking about?
				//+1*1=+1+1
				if(a[i] && a[j] && b[i] % a[i] == 0 && b[j] % a[j] == 0 && b[i] / a[i] == b[j] / a[j]) {flag = 1;continue;}//+1*2
				//+1*3=+1*2
				//+2*1=+1+2
				{//+2*2
					int x = d[i];
					nw[j] = a[j] + x,nw[k] = a[k] + x;
					if(nw[j] && a[k] && b[j] % nw[j] == 0 && b[k] % a[k] == 0 && b[j] / nw[j] == b[k] / a[k] || a[j] && nw[k] && b[j] % a[j] == 0 && b[k] % nw[k] == 0 && b[j] / a[j] == b[k] / nw[k]) {flag = 1;continue;}
				}
				if(a[i] && b[i] && b[i] % a[i] == 0)//+2*3
				{
					int x = b[i] / a[i];
					if(b[j] % x == 0 && b[k] % x == 0 && b[j] / x - a[j] == b[k] / x - a[k]) {flag = 1;continue;}
				}
				//+3*1=+2+1
				{//+3*2
					int x = d[i];
					nw[j] = a[j] + x,nw[k] + a[k] + x;
					if(nw[j] && nw[i] && nw[k] && b[j] % nw[j] == 0 && b[k] % nw[k] == 0 && b[j] / nw[j] == b[k] / nw[k]) {flag = 1;continue;}
				}
				if(b[j] != b[i] && a[j] != a[i])//+3*3
				{
					int K = (b[i] - b[j]) / (a[i] - a[j]);
					if(K * (a[i] - a[j]) == (b[i] - b[j]))
					{
						int x = (b[i] - a[i] * K) / K;
						if(K * (a[i] + x) == b[i] && K * (a[j] + x) == b[j] && K * (a[k] + x) == b[k]) {flag = 1;continue;}
					}
				}
				//*1+1=+1+1
				//*1+2=+2+1
				//*1+3=+2+1
				//*2+1=+1*2
				{//*2+2
					//i+,j*,k*+
					if(a[j] && b[j] % a[j] == 0 && a[k] * (b[j] / a[j]) + d[i] == b[k]) {flag = 1;continue;}
				}
				{//*2+3
					nw[i] = b[i] - d[k],nw[j] = b[j] - d[k];
					if(a[i] && a[j] && nw[i] % a[i] == 0 && nw[j] % a[j] == 0 && nw[i] / a[i] == nw[j] / a[j]) {flag = 1;continue;}//*2+3
				}
				//*3+1=*2+1
				if(a[i] && b[i] % a[i] == 0)//*3+2
				{
					int x = b[i] / a[i];
					if(a[j] * x - b[j] == a[k] * x - b[k]) {flag = 1;continue;}
				}
				if(a[j] != a[i])//*3+3
				{
					int K = (b[i] - b[j]) / (a[i] - a[j]);
					if(K * (a[i] - a[j]) == (b[i] - b[j]))
					{
						int x = b[i] - a[i] * K;
						if(a[i] * K + x == b[i] && a[j] * K + x == b[j] && a[k] * K + x == b[k]) {flag = 1;continue;}
					}
				}
				//*2*1=*2+1
				if(a[i] && a[j] && a[k] && b[i] % a[i] == 0 && b[j] % a[j] == 0 && b[k] % a[k] == 0 && b[i] / a[i] == (b[j] / a[j]) * (b[k] / a[k])) {flag = 1;continue;}//*2*2
				//*2*3=*2+1
				//*3*1=*2+1
				//*3*2=*2+1
				//*3*3=???What are you talking about?
			}
		}
		if(flag)
		{
			cout << 2 << "\n";
			continue;
		}
		cout << 3 << "\n";
	}
	return 0;
}
