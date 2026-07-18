#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> vc(n+10,0),fb;
	fb=vc;
	string sl;
	cin>>sl;
	vector<int> pa,pb;
	for(int i=1;i<=n;i++){
		if(sl[i-1]=='(')vc[i]=1,pa.push_back(i);
		else if(sl[i-1]==')')vc[i]=-1,pb.push_back(i);
	}
	reverse(pb.begin(),pb.end());
	int sa=pa.size(),sb=pb.size();
	int res=1e9+7,to=-1;
	for(int i=0;i<=min(sa,k);i++){
		int j=min(k-i,sb);
		fb=vc;
		for(int o=0;o<i;o++)fb[pa[o]]=0;
		for(int o=0;o<j;o++)fb[pb[o]]=0;
		int su=0;
		int ge=0;
		for(int o=n;o>=1;o--){
			if(su>=0 && fb[o]==1)continue;
			if(fb[o]==1){
				ge+=2;
				su++;
			}
			else if(fb[o]==-1){
				su--;
			}
		}
		if(ge<res){
			res=ge;
			to=i;
		}
	}
	vector<int> ans(n+10,0);
	if(to!=-1){
		for(int o=0;o<to;o++){
			ans[pa[o]]=1;
		}
		for(int o=0;o<min(k-to,sb);o++){
			ans[pb[o]]=1;
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i];
	cout<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
