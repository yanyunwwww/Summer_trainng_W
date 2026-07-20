#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int ge[100];
void solve(){
    int n,y;
    cin>>n>>y;
    vector<int> vc(n+10,0);
    int sum=0;
    for(int i=1;i<=n;i++)cin>>vc[i],sum+=vc[i];
    if(sum>=y){
        cout<<0<<"\n";
        return ;
    }
    int res=(1ll<<60)+10;
    for(int o=60;o>=0;o--){
        int now=sum;
        int u=1ll<<o;
        vector<int> kn;
        for(int i=1;i<=n;i++){
            if((vc[i]>>o)&1)continue;
            kn.push_back(vc[i]);
            now+=(1ll<<o);
        }
        int sz=kn.size();
        for(int i=o-1;i>=0;i--)ge[i]=0;
        for(auto p:kn){
            for(int i=o-1;i>=0;i--){
                if((p>>i)&1)ge[i]++;
            }
        }
        vector<int> wz;
        for(int i=o-1;i>=0;i--){
            if((sz-ge[i])>ge[i]){
                wz.push_back(i);
                u^=(1ll<<i);
                now+=(sz-2*ge[i])*(1ll<<i);
            }
        }
        if(now<y)continue;
        for(auto p:wz){
            int op=(sz-2*ge[p])*(1ll<<p);
            if((now-op)>=y){
                now-=op;
                u^=(1ll<<p);
            }
        }
//         cout<<o<<" "<<u<<"\n";
        res=min(res,u);
    }
    cout<<res<<"\n";
}
signed main(){
    int T;
    cin>>T;
    while(T--)solve();
}
