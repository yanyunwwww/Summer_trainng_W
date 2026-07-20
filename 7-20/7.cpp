#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int gcd(int a,int b){
    if(b!=0)return gcd(b,a%b);
    else return a;
}
signed main(){
    int n;
    cin>>n;
    vector<int> vc(n+10,0),rk;
    for(int i=1;i<=n;i++){
        if(gcd(i,999999999)!=1){
            rk.push_back(i);
            vc[i]=1;
        }
    }
    if((rk.size()*3)<n)cout<<"Baka!";
    else {
        int now=1;
        for(int i=0;i<rk.size();i++){
            while(now<=n && vc[now]==1){
                now++;
            }
            if(now>n){
                for(int j=i;j<rk.size();j++)cout<<rk[j]<<" ";
                break;
            }
            else {
                cout<<now<<" "<<rk[i]<<" ";
            }
            now++;
            while(now<=n && vc[now]==1){
                now++;
            }
            if(now<=n){
                cout<<now<<" ";
                now++;
            }
        }
    }
}
