#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int Inf=1e18;
int a[5];
int b[5];
int c[5];
int s[5][2];
bool check1(){
	for(int i=1;i<=3;i++)c[i]=a[i]-b[i];
	if((c[1]==0&&c[2]==0)||(c[2]==0&&c[3]==0)||(c[1]==0&&c[3]==0))return 1;//�Ѿ�������������
	if(c[1]!=0&&c[2]!=0&&c[3]!=0){//û��һ���Ѿ������ 
		if(c[1]==c[2]&&c[2]==c[3])return 1;//�Ӽ�  
		for(int i=1;i<=3;i++){
			if(a[i]==0)return 0;//˵��������޷��ٱ��� 
			if(abs(b[i])%abs(a[i]))return 0;//˵������ֻ�ó˷�
			c[i]=b[i]/a[i]; 
		}
		if(c[1]==c[2]&&c[2]==c[3])return 1;
		else return 0;
	}else{
		if(c[1]==0){swap(a[1],a[3]);swap(b[1],b[3]);swap(c[1],c[3]);}
		if(c[2]==0){swap(a[2],a[3]);swap(b[2],b[3]);swap(c[2],c[3]);}
		if(c[1]==c[2])return 1;//�Ӽ� 
		for(int i=1;i<=2;i++){
			if(a[i]==0)return 0;//˵��������޷��ٱ��� 
			if(abs(b[i])%abs(a[i]))return 0;//˵������ֻ�ó˷�
			c[i]=b[i]/a[i]; 
		}
		if(c[1]==c[2])return 1;
		else return 0;
	}
//	for(int i=2;i<=3;i++)c[i][0]=a[i]-a[i-1];
//	for(int i=2;i<=3;i++)c[i][1]=b[i]-b[i-1];
//	if(c[2][0]==c[2][1]&&c[3][0]==c[3][1])return 1;
//	if(a[1]*b[2]==a[2]*b[1]&&a[3]*b[2]==a[2]*b[3]&&a[1]*b[3]==a[3]*b[1])return 1;
//	if(c[2][0]*c[3][1]==c[2][1]*c[3][0])return 1;
	return 0;
}
bool check2(){
	for(int i=1;i<=3;i++)c[i]=a[i]-b[i];
	if(c[1]==0||c[2]==0||c[3]==0)return 1;//ֻʣ������ 
	if(c[1]==c[2]||c[2]==c[3]||c[1]==c[3])return 1;//�ӷ� 
	//������Ŀ϶���û��һ�������
//	if(b[1]==0||)
	int ops=0;
	for(int i=1;i<=3;i++){
		if(a[i]==0){c[i]=Inf;continue;}//˵��������޷��ٱ��� ������ʱ�� 
		if(abs(b[i])%abs(a[i])){c[i]=Inf+i;continue;}//˵������ֻ�ó˷�
		c[i]=b[i]/a[i];
	}
	if(c[1]==c[2]||c[2]==c[3]||c[1]==c[3])return 1;
	//���ڿ�����ΰ����2ת��Ϊ���1 
	//8 11 14 -> 3 4 5 
	//�������������ϳ�,Ȼ�������¼�
	if((a[2]-a[1])*(b[3]-b[2])==(a[3]-a[2])*(b[2]-b[1]))return 1;
	//һ���з���
	//Ҫô��ʹ�����������ƶ�����һ���Ա�,Ȼ��һ���ȥ,�о����Ӳ��ù��� 
//	for(int i=2;i<=3;i++)c[i][0]=a[i]-a[i-1];
//	for(int i=2;i<=3;i++)c[i][1]=b[i]-b[i-1];
//	if(c[2][0]==c[2][1]||c[3][0]==c[3][1])return 1;
//	if(c[2][0]*c[3][1]==c[2][1]*c[3][0])return 1;
	if(b[1]==0){swap(a[1],a[3]);swap(b[1],b[3]);swap(c[1],c[3]);}
	if(b[2]==0){swap(a[2],a[3]);swap(b[2],b[3]);swap(c[2],c[3]);}
	if(b[3]==0&&b[1]==b[2])return 1;
	return 0;
}
signed main(){
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--){
		for(int i=1;i<=3;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=3;i++)scanf("%lld",&b[i]);
		if(a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3])printf("0\n");
		else if(check1())printf("1\n");
		else if(check2())printf("2\n");
		else printf("3\n");
	}
}/*
2
3 5 7
6 5 10
8 6 3
9 7 8
*/
