#include<bits/stdc++.h>
using namespace std;
int T, a, b, c, x, y, z;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0'&& ch <= '9') {
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int main() {
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	T = read();
	while(T--) {
		a = read(); b = read(); c = read(); x = read(); y = read(); z = read();
		int adda = x-a, addb = y-b, addc = z-c, cfa, cfb, cfc, moda, modb, modc, ans = 3;
		if(a != 0)	cfa = x / a, moda = x - a * cfa;
		if(b != 0)	cfb = y / b, modb = y - b * cfb;
		if(c != 0)	cfc = z / c, modc = z - c * cfc;
		if(a != x&&b != y&&c != z) {
		if(cfa == cfb&&cfb == cfc&&moda == modb&&modb == modc) {
			if(moda == 0)	ans = min(ans, 1);
			else	ans = min(ans, 2);
		}
		else if((cfa == cfb&&moda == modb)||(cfa == cfc&&moda == modc)||(cfb == cfc&&modb == modc)) {
			if(cfa == cfb&&moda == modb) {
				int sum = 0;
				if(moda == 0)	sum += 1;
				else	sum += 2;
				if(moda == modc)	sum += 1;
				else if(cfa == cfc)	sum += 1;
				else if(modc == 0)	sum += 1;
				else	sum += 2;
				ans = min(ans, sum);
			}
			else if(cfa == cfc&&moda == modc) {
				int sum = 0;
				if(moda == 0)	sum += 1;
				else	sum += 2;
				if(moda == modb)	sum += 1;
				else if(cfa == cfb)	sum += 1;
				else if(modb == 0)	sum += 1;
				else	sum += 2;
				ans = min(ans, sum);
			}
			else {
				int sum = 0;
				if(modb == 0)	sum += 1;
				else	sum += 2;
				if(modb == moda)	sum += 1;
				else if(cfb == cfa)	sum += 1;
				else if(moda == 0)	sum += 1;
				else	sum += 2;
				ans = min(ans, sum);
			}
		}
		if(adda == addb&& addb == addc) {
			ans = min(ans, 1);
		}
		else if(adda == addb||adda == addc||addb == addc) {
			ans = min(ans, 2);
		}}
		else if(a == x&&b == y&&c == z)	ans = 0;
		else if(a != x&&b != y) {
			if(adda == addb)	ans = min(ans, 1);
			else if(cfa == cfb&&moda == modb)	ans = min(ans,1);
			else	ans =min(ans, 2);
		}
		else if(a!=x&&c != z) {
			if(adda == addc)	ans = min(ans, 1);
			else if(cfa == cfc&&moda == modc)	ans = min(ans,1);
			else	ans =min(ans, 2);
		}
		else if(b != y&&c != z) {
			if(addc == addb)	ans = min(ans, 1);
			else if(cfc == cfb&&modc == modb)	ans = min(ans,1);
			else	ans =min(ans, 2);
		}
		else	ans = 1;
		cout<<ans<<endl;
	}
	return 0;
}
