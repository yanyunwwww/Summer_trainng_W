#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int n;
vector<int> e[300000];
int dp[300000][2];
int res;
void dfs(int x,int fa){
	for(auto p:e[x]){
		if(p==fa)continue;
		dfs(p,x);
		if(dp[p][0]>dp[x][0]){
			dp[x][1]=dp[x][0];
			dp[x][0]=dp[p][0];
		}
		else {
			if(dp[p][0]>=dp[x][1]){
				dp[x][1]=dp[p][0];
			}
		}
	}
	dp[x][0]++;
	dp[x][1]++;
}
void solve(){
	res=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i][1]=0;
		e[i].clear();
	}
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		e[x].push_back(i);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		res+=min(dp[i][0],dp[i][1]);
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
