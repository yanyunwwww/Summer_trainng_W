#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n;
	cin>>n;
	string sl;
	cin>>sl;
	vector<vector<int>> dp(n+10,vector<int>(n+10,1e9+7));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		vector<vector<int>> ndp(n+10,vector<int>(n+10,1e9+7));
		for(int j=0;j<i;j++){
			for(int o=0;o<i;o++){
				if(sl[i-1]!='T'){
					ndp[j+1][o+1]=min(ndp[j+1][o+1],max(dp[j][o],o+1));
				}
				if(sl[i-1]!='F'){
					ndp[j][max(0ll,o-1)]=min(ndp[j][max(0ll,o-1)],dp[j][o]);
				}
			}
		}
		swap(dp,ndp);
	}
	int res=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			res=max(res,i-dp[i][j]);
		}
	}
	cout<<res<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
