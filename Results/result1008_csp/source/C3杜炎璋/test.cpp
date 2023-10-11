#include<bits/stdc++.h>
using namespace std;
int main(){
	int sum=0;
	for(int i=0;i<(1<<4);i++) {
		for(int j=0;j<4;j++) {
			if(i&(1<<j)) sum++;
		}
	}
	printf("%d",sum);
	return 0;
}

