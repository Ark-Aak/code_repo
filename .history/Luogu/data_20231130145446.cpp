#include<bits/stdc++.h>
using namespace std;
int n=10,m=30;
int a[16];
int main(){
	srand(time(0));
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++){
		a[i]=rand();
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		int t=rand()%5+1;
		cout<<t<<" ";
		if(t==1 || t==4 || t==5){
			int l=rand()%n+1;
			int r=rand()%(n-l+1)+l;
			cout<<l<<" "<<r<<" "<<rand()<<endl; 
		}
		if(t==2){
			int l=rand()%n+1;
			int r=rand()%(n-l+1)+l;
			cout<<l<<" "<<r<<" "<<rand()%(r-l+1)+1<<endl;
		}
		if(t==3){
			int pos=rand()%n+1;
			cout<<pos<<" "<<rand()<<endl;
		}
	}
}
