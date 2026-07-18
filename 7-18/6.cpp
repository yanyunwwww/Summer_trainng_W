#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#define int long long
using namespace std;
vector<int> e[300000];
int n;
int vc[300000],dp[300000];
int res;
void dfs(int x,int fa){
	vector<int> vv;
	int s1=0,s2=0,s3=0;
	for(auto p:e[x]){
		if(p==fa)continue;
		dfs(p,x);
		dp[x]+=dp[p];
		s1+=dp[p];
		s2+=dp[p]*dp[p];
		s3+=dp[p]*dp[p]*dp[p];
		vv.push_back(dp[p]);
	}
	int o=sqrt(vc[x]);
	s1+=n-dp[x]-1;
	s2+=(n-dp[x]-1)*(n-dp[x]-1);
	s3+=(n-dp[x]-1)*(n-dp[x]-1)*(n-dp[x]-1);
	if((o*o)==vc[x] && (n-dp[x])>=1){
		if(vv.size()>=2){
			res+=(s1*s1*s1-3*s1*s2+2*s3)/6;
		}
		int sum=n-1;
		for(auto g:vv){
			sum-=g;
			res+=g*sum;
		}
	}
	dp[x]++;
}
void solve(){
	res=0;
	cin>>n;
	for(int i=1;i<=n;i++)dp[i]=0,cin>>vc[i],e[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	cout<<res<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
