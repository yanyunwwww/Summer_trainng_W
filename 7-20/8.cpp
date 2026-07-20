#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
signed main(){
    int n,m;
    cin>>n>>m;
    string sl;
    cin>>sl;
    vector<int> vc(n+10,0),ok;
    ok=vc;
    for(int i=0;i<n;i++)cin>>vc[i];
    for(int i=0;i<n;){
        int j=i;
        vector<int> pl;
        while(j<n && sl[j]==sl[i]){
            pl.push_back(vc[j]);
            j++;
        }
        sort(pl.begin(),pl.end());
        if(j<n){
            int t=i;
            if(sl[j]>sl[i]){
               for(auto p:pl){
                   if(p<=m){
                       m-=p;
                       ok[t]=1;
                       t++;
                   }
               }
            }
        }
        i=j;
    }
    for(int i=0;i<n;i++){
        cout<<sl[i];
        if(ok[i])cout<<sl[i];
    }
}
