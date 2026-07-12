#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#define int long long
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<int> vc(n+10,0),ls,rs;
	ls=rs=vc;
	for(int i=0;i<n;i++)cin>>vc[i];
	int ma=0,s=0;
	for(int i=0;i<n;i++){
		if(ma<vc[i]){
			ma=vc[i];
			s=i;
		}
	}
	
	stack<pair<int,int>> sk;
	sk.push({1e18+9,0});
	for(int j=1;j<n;j++){
		int t=(s+j)%n;
		int zhi=ls[t]+vc[t];
		int c=1;
		while(sk.top().first<=vc[t]){
			zhi+=sk.top().second*(vc[t]-sk.top().first);
			c+=sk.top().second;
			sk.pop();
		}
		sk.push({vc[t],c});
		ls[(t+1)%n]=zhi;
	}
	while(sk.size()){
		sk.pop();
	}
	sk.push({1e18+9,0});
	for(int j=1;j<n;j++){
		int t=((s-j)%n+n)%n;
		int zhi=rs[(t+1)%n]+vc[t];
		int c=1;
		while(sk.top().first<=vc[t]){
			zhi+=sk.top().second*(vc[t]-sk.top().first);
			c+=sk.top().second;
			sk.pop();
		}
		sk.push({vc[t],c});
		rs[t]=zhi;
	}
	for(int i=0;i<n;i++){
		cout<<ls[i]+rs[i]<<" ";
	}
	cout<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
