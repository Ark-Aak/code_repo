#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,t1,t2,t3,t4,t5,t6;
vector<pair<int,int>> e;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
}
signed main(){
    freopen("triple.in","r",stdin);
    freopen("triple.out","w",stdout);
    T=read();
    while(T--){
        t1=read(),t2=read(),t3=read(),t4=read(),t5=read(),t6=read();
        e.clear();
        int d=0;
        if(t1!=t4) d++,e.push_back(make_pair(t1,t4));
        if(t2!=t5) d++,e.push_back(make_pair(t2,t5));
        if(t3!=t6) d++,e.push_back(make_pair(t3,t6));
        if(d==0) puts("0");
        else if(d==1) puts("1");
        else if(d==2){
            bool f=0;
            int d1=e[0].second-e[0].first,d2=e[1].second-e[1].first;
//            cout<<e[0].first<<" "<<e[0].second<<" "<<e[1].first<<" "<<e[1].second<<"\n";
            int w1=1,w2=1;
            if(e[0].first!=0) w1=e[0].second%e[0].first;
            if(e[1].first!=0) w2=e[1].second%e[1].first;
            if((w1==0)&&(w2==0)){
                int w3=e[0].second/e[0].first,w4=e[1].second/e[1].first;
                if(w3==w4) f=1;
            }
            if((e[0].second==0)&&(e[1].second==0)) f=1;
            if(f||d1==d2) puts("1");
            else puts("2");
        }
        else{          
            int f=0;
            int d1=e[0].second-e[0].first,d2=e[1].second-e[1].first,d3=e[2].second-e[2].first;
            if(t1!=0&&(t4%t1)==0){
                int o=t4/t1;
                if((o*t2)!=0&&t3!=0&&(t5%(o*t2))==0&&(t6%t3)==0){
                	if((t5/(o*t2))==(t6/t3)) f=max(f,(int)1);
				}
				if((o*t3)!=0&&t2!=0&&(t6%(o*t3))==0&&(t5%t2)==0){
                	if((t6/(o*t3))==(t5/t2)) f=max(f,(int)1);
				}
                if(o!=0&&(t5%o)==0){
                	if((t5/o-t2)==(t6-t3)) f=max(f,(int)1);
                	if((t5/o-t2)==0) f=max(f,(int)1);
				}
				if(o!=0&&(t6%o)==0){
					if((t5-t2)==(t6/o-t3)) f=max(f,(int)1);
                    if((t6/o-t3)==0) f=max(f,(int)1);
				}
                if(o!=0&&(t5%o)==0&&(t6%o)==0){
                    if((t5/o-t2)==(t6/o-t3)) f=max(f,(int)1);   
                }
                if((t5-o*t2)==(t6-o*t3)) f=max(f,(int)1);
                if((t5-o*t2)==d3||(t3*o)==t6) f=max(f,(int)1);
                if((t6-o*t3)==d2||(t2*o)==t5) f=max(f,(int)1);
            }
            if(t2!=0&&(t5%t2)==0){
                int o=t5/t2;
                if((o*t1)!=0&&t3!=0&&(t4%(o*t1))==0&&(t6%t3)==0){
                	if((t4/(o*t1))==(t6/t3)) f=max(f,(int)1);
				}
				if((o*t3)!=0&&t1!=0&&(t6%(o*t3))==0&&(t4%t1)==0){
                	if((t6/(o*t3))==(t4/t1)) f=max(f,(int)1);
				}
                if(o!=0&&(t6%o)==0){
                	if((t6/o-t3)==(t4-t1)) f=max(f,(int)1);
                	if((t6/o-t3)==0) f=max(f,(int)1);
				}
				if(o!=0&&(t4%o)==0){
					if((t6-t3)==(t4/o-t1)) f=max(f,(int)1);
                    if((t4/o-t1)==0) f=max(f,(int)1);
				}
                if(o!=0&&(t6%o)==0&&(t4%o)==0){
                    if((t6/o-t3)==(t4/o-t1)) f=max(f,(int)1);   
                }
                if((t4-o*t1)==(t6-o*t3)) f=max(f,(int)1);
                if((t4-o*t1)==d3||(t3*o)==t6) f=max(f,(int)1);
                if((t6-o*t3)==d1||(t1*o)==t4) f=max(f,(int)1); 
            }
            if(t3!=0&&(t6%t3)==0){
                int o=t6/t3;
                if((o*t2)!=0&&t1!=0&&(t5%(o*t2))==0&&(t4%t1)==0){
                	if((t5/(o*t2))==(t4/t1)) f=max(f,(int)1);
				}
				if((o*t1)!=0&&t2!=0&&(t4%(o*t1))==0&&(t5%t2)==0){
                	if((t4/(o*t1))==(t5/t2)) f=max(f,(int)1);
				}
                if(o!=0&&(t5%o)==0){
                	if((t5/o-t2)==(t4-t1)) f=max(f,(int)1);
                	if((t5/o-t2)==0) f=max(f,(int)1);
				}
				if(o!=0&&(t4%o)==0){
					if((t5-t2)==(t4/o-t1)) f=max(f,(int)1);
                    if((t4/o-t1)==0) f=max(f,(int)1);
				}
                if(o!=0&&(t5%o)==0&&(t4%o)==0){
                    if((t5/o-t2)==(t4/o-t1)) f=max(f,(int)1);   
                }
                if((t4-o*t1)==(t5-o*t2)) f=max(f,(int)1);
                if((t4-o*t1)==d2||(t2*o)==t5) f=max(f,(int)1);
                if((t5-o*t2)==d1||(t1*o)==t4) f=max(f,(int)1);
            }
            if((t1+d3)!=0&&(t4%(t1+d3))==0&&(t2+d3)!=0&&(t5%(t2+d3))==0&&(t4/(t1+d3))==(t5/(t2+d3))) f=max(f,(int)1);
            if((t1+d2)!=0&&(t4%(t1+d2))==0&&(t3+d2)!=0&&(t6%(t3+d2))==0&&(t4/(t1+d2))==(t6/(t3+d2))) f=max(f,(int)1);
            if((t3+d1)!=0&&(t6%(t3+d1))==0&&(t2+d1)!=0&&(t5%(t2+d1))==0&&(t6/(t3+d1))==(t5/(t2+d1))) f=max(f,(int)1);
            if((d1-d3)==d2||(d2-d3)==d1) f=max(f,(int)1);
            if((d1-d2)==d3||(d3-d2)==d1) f=max(f,(int)1);
            if((d2-d1)==d3||(d3-d1)==d2) f=max(f,(int)1);
            int z1=1e18,z2=1e18,z3=1e18;
            if(t1==t2||((d1-d2)%(t1-t2))) z1=2e18;
            else z1=(d1-d2)/(t1-t2);
            if(t1==t3||((d1-d3)%(t1-t3))) z2=2e18;
            else z2=(d1-d3)/(t1-t3);
            if(t3==t2||((d3-d2)%(t3-t2))) z3=2e18;
            else z3=(d3-d2)/(t3-t2);
            // cerr<<z1<<" "<<z2<<" "<<z3<<"\n";
            if(z1<=(int)1e18){
                if((d1-z1*t1)==d3) f=max(f,(int)1);
            }
            if(z2<=(int)1e18){
                if((d1-z2*t1)==d2) f=max(f,(int)1);
            }
            if(z3<=(int)1e18){
                if((d2-z3*t2)==d1) f=max(f,(int)1);
            }
            if(z1<=(int)1e18&&z2<=(int)1e18&&z3<=(int)1e18){
                if(z1==z2&&z2==z3) f=max(f,(int)1);
            }
            int w1=1,w2=1,w3=1;
            if(e[0].first!=0) w1=e[0].second%e[0].first;
            if(e[1].first!=0) w2=e[1].second%e[1].first;
            if(e[2].first!=0) w3=e[2].second%e[2].first;
            if((w1==0)&&(w2==0)&&(w3==0)){
                int w4=e[0].second/e[0].first,w5=e[1].second/e[1].first,w6=e[2].second/e[2].first;
                if((w4==w5)&&(w5==w6)) f=max(f,(int)2);
                else if(w4==w5||w5==w6||w4==w6) f=max(f,(int)1);
            }
            else if((w1==0)&&(w2==0)){
                int w4=e[0].second/e[0].first,w5=e[1].second/e[1].first;
                if(w4==w5) f=max(f,(int)1);
            }
            else if((w1==0)&&(w3==0)){
                int w4=e[0].second/e[0].first,w6=e[2].second/e[2].first;
                if(w4==w6) f=max(f,(int)1);
            }
            else if((w2==0)&&(w3==0)){
                int w5=e[1].second/e[1].first,w6=e[2].second/e[2].first;
                if(w5==w6) f=max(f,(int)1);
            }
            if((e[0].second==0)&&(e[1].second==0)&&(e[2].second==0)) f=max(f,(int)2);
            else if((e[0].second==0)&&(e[1].second==0)) f=max(f,(int)1);
            else if((e[0].second==0)&&(e[2].second==0)) f=max(f,(int)1);
            else if((e[1].second==0)&&(e[2].second==0)) f=max(f,(int)1);
            if((f==2)||((d1==d2)&&(d2==d3))) puts("1");
            else if((d1==d2)||(d2==d3)||(d1==d3)||(f==1)) puts("2");
            else puts("3");
        }
    }
    return 0;
}
