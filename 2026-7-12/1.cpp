#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int vc[100];
struct op{
	int x,y,z;
};
vector<op> res;
void yd(int x,int s,int t){
	if(x<=0)return ;
	int u=6-s-t;
	
	if(!vc[x]){
		yd(x-1,s,u);
		res.push_back({x,s,t});
		yd(x-1,u,t);
	}
	else {
		yd(x-1-vc[x],s,u);
		res.push_back({x,s,t});
		yd(x-1-vc[x],u,s);
		yd(x-1,s,t);
	}
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>vc[i];
	bool ok=1;
	for(int i=1;i<=n;i++)if(vc[i]>=i)ok=0;
	if(!ok){
		cout<<"No"<<"\n";
		return ;
	}
	else {
		cout<<"Yes"<<"\n";
		res.clear();
		
		yd(n,1,3);
		cout<<res.size()<<"\n";
		for(auto m:res)cout<<m.x<<" "<<m.y<<" "<<m.z<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
