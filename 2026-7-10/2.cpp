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
	vector<int> a(n+10,0),b;
	b=a;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	vector<int> dp(n+10,n+1),pa,pb;
	pa=pb=dp;
	int res=0;
	for(int i=n;i>=1;i--){
		pa[a[i]]=i;
		pb[b[i]]=i;
		if(a[i]==b[i]){
			int x=a[i]+1;
			if(pa[x]==pb[x]){
				dp[i]=dp[pa[x]];
			}
			else {
				dp[i]=min(pa[x],pb[x]);
			}
		}
		if(pa[1]!=pb[1]){
			res+=min(pa[1],pb[1])-i;
		}
		else {
			res+=dp[pa[1]]-i;
		}
	}
	cout<<res<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
