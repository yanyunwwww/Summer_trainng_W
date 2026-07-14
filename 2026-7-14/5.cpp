#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
struct op{
	int x,y;
	bool operator<(const op& ne)const{
		return x>ne.x;
	}
};
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> vc(n+10,0);
	for(int i=1;i<=n;i++){
		cin>>vc[i];
	}
	vc[n+1]=vc[n]+1;
	int s=0,las=0;
	map<int,int> mp;
	for(int i=1;i<=(n+1);i++){
		if(i==1)las=vc[i],s=1;
		else {
			if(las!=vc[i]){
				if(!mp.count(s))mp[s]=1;
				else mp[s]++;
				s=1;
				las=vc[i];
			}
			else {
				s++;
			}
		}
	}
	vector<op> vv;
	for(auto m:mp){
		vv.push_back({m.first,m.second});
	}
	sort(vv.begin(),vv.end());
	int res=0;
	int sum=0,ge=0,mi=1e18+9;
	for(int i=0;i<vv.size();i++){
		int a=vv[i].x,b=vv[i].y;
		sum+=a*b;
		ge+=b;
		int u=sum-(a-1)*ge;
		if(u<=k && (k-u)%ge==0)res++;
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
