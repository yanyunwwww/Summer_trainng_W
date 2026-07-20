#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
const int mod=1e9+7;
int jc[2000100],ny[2000100];
int ksm(int x,int b){
    int res=1;
    while(b){
        if(b&1)res=(res*x)%mod;
        x=(x*x)%mod;
        b>>=1;
    }
    return res;
}
void ini(){
    jc[0]=ny[0]=1;
    for(int i=1;i<=2000000;i++){
        jc[i]=(jc[i-1]*i)%mod;
        ny[i]=(ny[i-1]*ksm(i,mod-2))%mod;
    }
}
int Cr(int a,int b){
    return jc[a]*ny[b]%mod*ny[a-b]%mod;;
}
signed main(){
    ini();
    int n,m;
    cin>>n>>m;
    vector<int> vc(n+10,0);
    for(int i=1;i<=n;i++)cin>>vc[i];
    int res=1;
    for(int i=1;i<=n;i++){
        res=(res*Cr(vc[i]+m,m))%mod;
    }
    cout<<res;
}
