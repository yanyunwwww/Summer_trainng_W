#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	string sa,sb;
	cin>>sa>>sb;
	int n,m;
	n=sa.size();
	m=sb.size();
	vector<int> a(n+10,0),b(m+10,0);
	for(int i=1;i<=n;i++){
		a[i]=(a[i-1]+(sa[i-1]-'0'))%10;
	}
	for(int i=1;i<=m;i++){
		b[i]=(b[i-1]+(sb[i-1]-'0'))%10;
	}
	if(a[n]!=b[m]){
		cout<<-1<<"\n";
		return ;
	}
	vector<vector<int>> dp(n+10,vector<int>(m+10,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			if(a[i]==b[j]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			}
		}
	}
	cout<<dp[n][m]<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
