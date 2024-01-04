#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int main(int argc,char **argv){
    registerTestlibCmd(argc,argv);
    int n=inf.readInt();
    string outs=ouf.readString();
    string anss=ans.readString();
    if(outs!=anss){
        quitf(_wa,"yes/no differs");
    }
    if(outs=="YES"){
        vector<int> s1,s2,s3;
        for(int i=1;i<=n;i++){
            int x=ouf.readInt(1,n),y=ouf.readInt(1,n);
            s1.push_back(x);
            s2.push_back(y);
            s3.push_back(abs(x-y));
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        sort(s3.begin(),s3.end());
        for(int i=1;i<n;i++){
            if(s1[i]==s1[i-1])quitf(_wa,"x coord same");
        }
        for(int i=1;i<n;i++){
            if(s2[i]==s2[i-1])quitf(_wa,"y coord same");
        }
        for(int i=1;i<n;i++){
            if(s3[i]==s3[i-1])quitf(_wa,"|x-y| same");
        }
    }
    quitf(_ok,""); 
    return 0;
}