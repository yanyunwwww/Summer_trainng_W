#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n,k,m;
	cin>>n>>k>>m;
	if(k>m){
		cout<<"No"<<"\n";
		return ;
	}
	cout<<"Yes"<<"\n";
	for(int i=1;i<=n;){
		while(i<=n && i%k!=0){
			cout<<1<<" ";
			i++;
		}
		if(i<=n){
			cout<<m-(k-1)<<" ";
			i++;
		}
	}
	cout<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
