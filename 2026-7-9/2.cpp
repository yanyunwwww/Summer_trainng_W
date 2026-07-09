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
	map<int,int> mp,ml;
	vector<int> kn;
	int x=vc[1];
	ml[x]=1;
	if(x==1){
		ml[2]=1;
		mp[2]=1;
	}
	int c=0;
	while(x!=1){
		if(x%2==1)x+=1;
		else x/=2;
		c++;
		ml[x]=1;
		mp[x]=c;
	}
	for(int i=2;i<=n;i++){
		x=vc[i];
		if(ml.count(x))ml[x]++;
		if(x==1){
			if(ml.count(2)){
				ml[2]++;
				if(!mp.count(2))mp[2]=1;
				else mp[2]++;
			}
		}
		int c=0;
		while(x!=1){
			if(x%2==1)x+=1;
			else x/=2;
			c++;
			if(ml.count(x)){
				ml[x]++;
				if(!mp.count(x))mp[x]=c;
				else mp[x]+=c;
			}
		}
	}
	int res=1e18+9;
	for(auto m:ml){
		int a=m.first,b=m.second;
		if(b==n){
			if(!mp.count(a))res=0;
			else res=min(res,mp[a]);
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
