#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> vc(n+10,0),pr;
	pr=vc;
	for(int i=1;i<=n;i++)cin>>vc[i];
	for(int i=1;i<=n;i++)pr[i]=pr[i-1]+vc[i];
	int las=0;
	int res=0;
	vector<int> rk;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		rk.push_back(x);
	}
	sort(rk.begin(),rk.end());
	for(int i=0;i<m;i++){
		res+=abs(pr[rk[i]]-pr[las]);
		las=rk[i];#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> vc(n+10,0),pr;
	pr=vc;
	for(int i=1;i<=n;i++)cin>>vc[i];
	for(int i=1;i<=n;i++)pr[i]=pr[i-1]+vc[i];
	int las=0;
	int res=0;
	vector<int> rk;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		rk.push_back(x);
	}
	sort(rk.begin(),rk.end());
	for(int i=0;i<m;i++){
		res+=abs(pr[rk[i]]-pr[las]);
		las=rk[i];
	}
	res+=pr[n]-pr[las];
	cout<<res<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
	}
	res+=pr[n]-pr[las];
	cout<<res<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
