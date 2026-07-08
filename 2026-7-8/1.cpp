#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
const int mod=1e9+7;
map<int,int> mp;
int n,vc[300000];
int jc[300000],ny[300000];
int ksm(int x,int b){
    int res=1;
    while(b){
        if(b&1)res=res*x%mod;
        x=x*x%mod;
        b>>=1;
    }
    res%=mod;
    return res;
}
void ini(){
    jc[0]=ny[0]=1;
    for(int i=1;i<=200000;i++){
        jc[i]=jc[i-1]*i%mod;
        ny[i]=ny[i-1]*ksm(i,mod-2)%mod;
    }
}
int Cr(int a,int b){
    return jc[a]*ny[b]%mod*ny[a-b]%mod;
}
struct qe{
    int x,c;
    bool operator<(const qe& ne)const {
        return c>ne.c;
    }
};
signed main(){
    ini();
    cin>>n;
    for(int i=1;i<=n;i++)cin>>vc[i];
    for(int i=1;i<=n;i++){
        int x=vc[i];
        for(int j=1;j<=x/j;j++){
            if(x%j==0){
                int a=j,b=x/j;
                if(a==b){
                    if(!mp.count(a))mp[a]=1;
                    else mp[a]++;
                }
                else {
                    if(!mp.count(a))mp[a]=1;
                    else mp[a]++;
                    if(!mp.count(b))mp[b]=1;
                    else mp[b]++;
                }
            }
        }
    }
    vector<qe> px;
    for(auto m:mp){
        px.push_back({m.first,m.second});
    }
    sort(px.begin(),px.end());
    int sz=px.size();
    vector<int> tt(px.size()+10,-1);
    int ma=0;
    for(int i=0;i<sz;i++){
        int a,b;
        a=px[i].x,b=px[i].c;
        if(a>ma){
            ma=a;
            tt[i]=i;
        }
        else {
            tt[i]=tt[i-1];
        }
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        int l=0,r=sz-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(px[mid].c>=x)l=mid;
            else r=mid-1;
        }
        if(px[l].c<x){
            cout<<0<<"\n";
        }
        else {
            int cnt=px[tt[l]].c;
            cout<<Cr(cnt,x)<<"\n";
        }
    }
}
