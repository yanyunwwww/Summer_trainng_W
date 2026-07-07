#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int wy[100];
int dp[205][205][205];
int ge(int x){
    if(x==0)return 1;
    int cnt=0;
    while(x>0){
        x/=10;
        cnt++;
    }
    return cnt;
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> vc(n+10,0),gg;
    gg=vc;
    for(int i=1;i<=n;i++)cin>>vc[i];
    for(int i=1;i<=n;i++)gg[i]=ge(vc[i]);
    wy[0]=1;
    for(int i=1;i<=10;i++)wy[i]=wy[i-1]*10%m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=m;k++){
                dp[i][j][k]=-1;
            }
        }
    }
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        int x=vc[i];
        for(int c=0;c<m;c++){
            int a=(c+x)%m;
            for(int s=0;s<m;s++){
                dp[i][c][s]=max(dp[i][c][s],dp[i-1][c][s]);
                int b=(s*wy[gg[i]]+x)%m;
                if(dp[i-1][c][s]>=0)dp[i][a][b]=max(dp[i][a][b],dp[i-1][c][s]+1);
            }
        }
    }
    int res=0;
    int cc,ss,tar;
    vector<int> zz;
    for(int c=0;c<m;c++){
            if(dp[n][c][c]>res){
                res=dp[n][c][c];
                ss=c;
                cc=c;
            }
    }
    tar=res;
    for(int i=n;i>=1 && tar>0;i--){
            int x=vc[i];
        bool op=0;
            for(int c=0;c<m && !op;c++){
                int a=(c+x)%m;
                for(int s=0;s<m && !op;s++){
                    if(dp[i-1][c][s]<0)continue;
                    int b=(s*wy[gg[i]]+x)%m;
                    if(a==cc && b==ss && (dp[i-1][c][s]+1)==dp[i][cc][ss]){
                        op=1;
                        cc=c,ss=s;
                        tar-=1;
                        zz.push_back(vc[i]);
                    }
                }
            }
    }
    cout<<res<<"\n";
    if(res!=0){
        for(int i=res-1;i>=0;i--){
            cout<<zz[i]<<" ";
        }
    }
}
