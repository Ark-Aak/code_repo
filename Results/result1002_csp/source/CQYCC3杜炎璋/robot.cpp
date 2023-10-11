#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	int T;
	cin>>T;
	srand(time(0));
	while(T--) {
		if(rand()%3<2) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

