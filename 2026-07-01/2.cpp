#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
const int mod=998244353;
signed main(){
    int n;
    cin>>n;
    string sl1,sl2;
    cin>>sl1>>sl2;
    vector<int> a(n+10,0),b;
    b=a;
    for(int i=1;i<=n;i++){
        if(sl1[i-1]=='?')a[i]=-1;
        else {
            a[i]=(sl1[i-1]-'0');
        }
        if(sl2[i-1]=='?')b[i]=-1;
        else{
            b[i]=(sl2[i-1]-'0');
        }
    }
    vector<vector<int>> dp(n+10,vector<int>(10,0));
    if(a[1]==-1 && b[1]==-1){
        for(int i=1;i<=4;i++)dp[1][i]=1;
    }
    else if(a[1]==-1){
        if(b[1])dp[1][2]=dp[1][4]=1;
        else dp[1][1]=dp[1][3]=1;
    }
    else if(b[1]==-1){
        if(a[1])dp[1][3]=dp[1][4]=1;
        else dp[1][1]=dp[1][2]=1;
    }
    else {
        if(!a[1] && !b[1])dp[1][1]=1;
        if(!a[1] && b[1])dp[1][2]=1;
        if(a[1] && !b[1])dp[1][3]=1;
        if(a[1] && b[1])dp[1][4]=1;
    }
    for(int i=2;i<=n;i++){
        if(a[i]==-1 && b[i]==-1){
            dp[i][1]=((dp[i-1][2]+dp[i-1][3])%mod+dp[i-1][4])%mod;
            dp[i][2]=(((dp[i-1][1]+dp[i-1][3])%mod+dp[i-1][4])%mod+dp[i-1][2])%mod;
            dp[i][3]=(((dp[i-1][1]+dp[i-1][2])%mod+dp[i-1][3])%mod+dp[i-1][4])%mod;
            dp[i][4]=((dp[i-1][1]+dp[i-1][2])%mod+dp[i-1][3])%mod;
        }
        else if(a[i]==-1){
            if(b[i]==1){
                dp[i][2]=(((dp[i-1][1]+dp[i-1][3])%mod+dp[i-1][4])%mod+dp[i-1][2])%mod;
                dp[i][4]=((dp[i-1][1]+dp[i-1][2])%mod+dp[i-1][3])%mod;
            }
            else{
                dp[i][1]=((dp[i-1][2]+dp[i-1][3])%mod+dp[i-1][4])%mod;
                dp[i][3]=(((dp[i-1][1]+dp[i-1][2])%mod+dp[i-1][3])%mod+dp[i-1][4])%mod;
            }
        }
        else if(b[i]==-1){
            if(a[i]==1){
                dp[i][3]=(((dp[i-1][1]+dp[i-1][2])%mod+dp[i-1][3])%mod+dp[i-1][4])%mod;
                dp[i][4]=((dp[i-1][1]+dp[i-1][2])%mod+dp[i-1][3])%mod;
            }
            else {
                dp[i][1]=((dp[i-1][2]+dp[i-1][3])%mod+dp[i-1][4])%mod;
                dp[i][2]=(((dp[i-1][1]+dp[i-1][3])%mod+dp[i-1][4])%mod+dp[i-1][2])%mod;
            }
        }
        else {
            if(!a[i] && !b[i])dp[i][1]=((dp[i-1][2]+dp[i-1][3])%mod+dp[i-1][4])%mod;
            if(!a[i] && b[i])dp[i][2]=(((dp[i-1][1]+dp[i-1][3])%mod+dp[i-1][4])%mod+dp[i-1][2])%mod;
            if(a[i] && !b[i])dp[i][3]=(((dp[i-1][1]+dp[i-1][2])%mod+dp[i-1][3])%mod+dp[i-1][4])%mod;
            if(a[i] && b[i])dp[i][4]=((dp[i-1][1]+dp[i-1][2])%mod+dp[i-1][3])%mod;
        }
    }
    int res=0;
    for(int i=1;i<=4;i++){
        res=(dp[n][i]+res)%mod;
    }
    cout<<res;
}
