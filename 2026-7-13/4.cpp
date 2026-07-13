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
	vector<int> vc(n+10,0);
	for(int i=1;i<=n;i++)cin>>vc[i];
	vector<vector<int>> dp(n+10,vector<int>(n+10,0));
	vector<bool> st(n+10,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)st[j]=0;
		int ma,mi;
		mi=ma=vc[i];
		for(int j=i;j<=n;j++){
			if(st[vc[j]])break;
			st[vc[j]]=1;
			ma=max(ma,vc[j]);
			mi=min(mi,vc[j]);
			if((j-i)==(ma-mi)){
				dp[mi][ma]=1;
			}
		}
	}
	
	for(int j=n/2;j>=1;j--){
		for(int i=1;(i+2*j-1)<=n;i++){
			if(dp[i][i+j-1]==1 && dp[i+j][i+2*j-1]){
				cout<<j<<"\n";
				return ;
			}
		}
	}
	cout<<0<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
