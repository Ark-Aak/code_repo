#include<bits/stdc++.h>
using namespace std;
long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <='9') {
		x=(x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
string s;
long long T, sum[1005][6];
int pos(char c) {
	switch(c) {
		case 'm' : return 1;
		case 'i' : return 2;
		case 'l' : return 3;
		case 'k' : return 4;
		case 'y' : return 5;
	}
}
signed main() {
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout);
	cin>>s;
	if(s.size()<=1000) {
		s = '0' + s;
		T = read();
		while(T--) {
			memset(sum, 0, sizeof sum);
			long long l, r;
			l = read(); r = read();
			int id = 0;
			for(int i = l; i <= r; ++i) {
				if(pos(s[i]) == id+1)	id++;
				for(int j = 1; j <= id; ++j) {
					sum[i][j] = sum[i-1][j];
				}
				if(pos(s[i]) <= id)	{
					if(pos(s[i]) == 1)	sum[i][pos(s[i])]++;
					else	sum[i][pos(s[i])] += sum[i-1][pos(s[i])-1];
				}
			}
			cout<<sum[r][5]<<endl;
		}
	}
	else {
		s = '0' + s;
		for(int i = 0; i <= s.size(); ++i) {
			sum[i][0] = 1;
		}
		int id = 0;
		for(int i = 1; i < s.size(); ++i) {
			if(pos(s[i]) == id+1)	id++;
			for(int j = 1; j <= id; ++j) {
				sum[i][j] = sum[i-1][j];
			}
			if(pos(s[i]) <= id)	sum[i][pos(s[i])] += sum[i-1][pos(s[i])-1];
		}
		T = read();
		while(T--) {
			long long l, r;
			l = read(), r = read();
			cout<<sum[r][5]<<endl;
		}
	}
	return 0;
} 
