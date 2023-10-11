#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
bool to(int a0,int a1,int p0,int p1){
    if(a0-p0==a1-p1) return 1;
    if(p0&&p1&&a0%p0==0&&a1%p1==0&&a0/p0==a1/p1) return 1;
    return 0;
}
bool to3(int a0,int a1,int a2,int p0,int p1,int p2){
    int a[3],p[3];
    a[0]=a0,a[1]=a1,a[2]=a2,p[0]=p0,p[1]=p1,p[2]=p2;
    if(a0-p0==a1-p1&&a1-p1==a2-p2) return 1;
    if(p0&&p1&&p2&&a0%p0==0&&a1%p1==0&&a2%p2==0&&a0/p0==a1/p1&&a1/p1==a2/p2) return 1;
    for(int i=0;i<=2;i++){
        for(int j=i+1;j<=2;j++){
            if(a[i]==p[i]&&a[j]==p[j]) return 1;
            for(int k=0;k<=2;k++){
                if(k==i||k==j) continue;
                if(to(a[i],a[j],p[i],p[j]))
                    if(a[k]==p[k]) return 1;
            }
        }
    }
    return 0;
}
signed main(){
    freopen("triple.in","r",stdin);
    freopen("triple.out","w",stdout);
    cin>>t;
    for(int kkk=1;kkk<=t;kkk++){
        int a[3],p[3],ans=3;
        cin>>p[0]>>p[1]>>p[2]>>a[0]>>a[1]>>a[2];
        if(a[0]==p[0]&&a[1]==p[1]&&a[2]==p[2]){
            cout<<0<<"\n";
            continue;
        }
        if(to3(a[0],a[1],a[2],p[0],p[1],p[2])){
            cout<<1<<"\n";
            continue;
        }
        for(int i=0;i<=2;i++){
            for(int j=i+1;j<=2;j++){
                if(to(a[i],a[j],p[i],p[j])) ans=min(ans,2ll);
            }
        }
        if(a[0]==p[0]||a[1]==p[1]||a[2]==p[2]) ans=min(ans,2ll);
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++){
                if(i==j) continue;
                for(int k=0;k<=2;k++){
                    if(k==i||k==j) continue;
                    int pj1=p[j]+a[i]-p[i],pk1=p[k]+a[i]-p[i];
                    if(to(a[j],a[k],pj1,pk1)||to(a[k],a[j],p[k],pj1)) ans=min(ans,2ll);
                    if(p[i]){
                        if(a[i]%p[i]) continue;
                        int pk2=p[k]*a[i]/p[i],pj2=p[j]*a[i]/p[i];
                        if(to(a[j],a[k],pj2,pk2)||to(a[k],a[j],p[k],pj2)) ans=min(ans,2ll);
                    }
                }
            }
        }
        for(int i=0;i<=2;i++){
            if(p[i]&&a[i]%p[i]==0&&(to(a[(i+1)%3],a[(i+2)%3],p[(i+1)%3]*a[i]/p[i],p[(i+2)%3]*a[i]/p[i])||((a[i]/p[i]&&a[(i+1)%3]%(a[i]/p[i])==0&&a[(i+2)%3]%(a[i]/p[i])==0&&to(a[(i+1)%3]/(a[i]/p[i]),a[(i+2)%3]/(a[i]/p[i]),p[(i+1)%3],p[(i+2)%3]))))) ans=min(ans,2ll);
        }
        for(int i=0;i<=2;i++){
            int a0=a[(i+1)%3],a1=a[(i+2)%3],p0=p[(i+1)%3],p1=p[(i+2)%3],c=a[i]-p[i];
            if(to(a0-c,a1-c,p0,p1)||to(a0,a1,p0+c,p1+c)) ans=min(ans,2ll);
        }
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++){
                if(i==j) continue;
                for(int k=0;k<=2;k++){
                    if(k==i||k==j) continue;
                    if(p[i]-p[j]&&(a[i]-a[j])%(p[i]-p[j])==0){
                        int kk=(a[i]-a[j])/(p[i]-p[j]);
                        int b=a[i]-p[i]*kk;
                        if(kk*p[k]+b==a[k]) ans=min(ans,2ll);
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}