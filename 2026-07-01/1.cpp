#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int __int128
using namespace std;
int read(){
    int a=0,s=0;
    int w=1;
    string sl;
    cin>>sl;
    if(sl[0]=='-')s=1,w=-1;
    for(int i=s;i<sl.size();i++){
        a=a*10+(sl[i]-'0');
    }
    return a*w;
}
void prt(int x){
    if(x<0){
        cout<<"-";
        x=-x;
    }
    if(x==0){
        cout<<0;
        return ;
    }
    string sl;
    while(x>0){
        sl.push_back('0'+x%10);
        x/=10;
    }
    for(int i=sl.size()-1;i>=0;i--){
        cout<<sl[i];
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    int n;
    n=read();
    vector<int> vc(n+10,0);
    for(int i=1;i<=n;i++)vc[i]=read();
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=vc[i];
    }
    vector<int> pr(n+10,0);
    for(int i=1;i<=n;i++){
        pr[i]=pr[i-1]+vc[i];
    }
    int a,b;
    a=sum/2;
    b=sum-a;
    int res=0;
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<r){
            int mid=(l+r+1)>>1;
            if((pr[mid]-pr[i-1])<=a)l=mid;
            else r=mid-1;
        }
        int o=pr[l]-pr[i-1];
        res=max(res,o*(sum-o));
        if(l<n)l+=1;
        o=pr[l]-pr[i-1];
        res=max(res,o*(sum-o));
        l=i,r=n;
        while(l<r){
            int mid=(l+r+1)>>1;
            if((pr[mid]-pr[i-1])<=b)l=mid;
            else r=mid-1;
        }
        o=pr[l]-pr[i-1];
        res=max(res,o*(sum-o));
        if(l<n)l+=1;
        o=pr[l]-pr[i-1];
        res=max(res,o*(sum-o));
    }
    res=res%998244353;
    prt(res);
}
