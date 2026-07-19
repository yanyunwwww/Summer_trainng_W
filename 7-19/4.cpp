#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
vector<int> e[300000];
int n;
bool ok;
struct dd{
	int l,r;
}dp[300000];
void dfs(int x,int fa){
	vector<dd> z;
	z.clear();
	for(auto p:e[x]){
		dfs(p,x);
		if(dp[p].r!=0)z.push_back(dp[p]);
	}
	int sz=z.size();
	int s=-1;
	int mi=1e9+7;
	if(sz>1){
		for(int i=0;i<sz;i++){
			if(z[i].l!=0){
				if(z[i].l<mi){
					mi=z[i].l;
					s=i;
				}
			}
			else {
				if(z[i].r<mi){
					mi=z[i].r;
					s=i;
				}
			}
		}
		for(int i=0;i<sz;i++){
			z.push_back(z[i]);
		}
		for(int j=2;j<=sz;j++){
			if(z[j+s-1].l==0){
				if((z[j+s-1].r-z[j+s-2].r)!=1)ok=0;
			}
			else {
				if((z[j+s-1].l-z[j+s-2].r)!=1)ok=0;
			}
		}
		if(z[s].l!=0)dp[x].l=z[s].l;
		else dp[x].l=z[s].r;
		dp[x].r=z[s+sz-1].r;
	}
	else {
		if(sz==1)dp[x]=z[0];
	}
	
}
void solve(){
	cin>>n;
	ok=1;
	for(int i=1;i<=n;i++)e[i].clear(),dp[i].l=dp[i].r=0;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		e[x].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cin>>dp[i].r;
	}
	dfs(1,0);
	if(ok)cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
