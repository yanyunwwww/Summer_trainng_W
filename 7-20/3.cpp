#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> vc(n,0),rk;
	for(int i=0;i<n;i++)cin>>vc[i];
	rk=vc;
	sort(rk.begin(),rk.end());
	bool ok=1;
	for(int i=0;i<n;i++){
		if(rk[i]!=vc[i])ok=0;
	}
	if(ok){
		cout<<0<<"\n";
		return ;
	}
	for(int o=0;;o++){
		int ma=-1;
		bool op=1;
		for(int j=0;(j*(1ll<<(o+1)))<n;j++){
			int now=-1;
			for(int i=0;(i+j*(1ll<<(o+1)))<n && i<(1ll<<(o+1));i++){
				int u=i+j*(1ll<<(o+1));
				if(vc[u]<ma)op=0;
				now=max(now,vc[u]);
			}
			ma=max(ma,now);
		}	
		if(op){
			cout<<(1ll<<o)<<"\n";
			return ;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
