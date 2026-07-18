#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(n%2==1 && i==((1+n)/2)){
			cout<<i+1<<" ";
			continue;
		}
		if(n%2==1 && (i-1)==((1+n)/2)){
			cout<<i-1<<" ";
			continue;
		}
		cout<<i<<" ";
	}
	for(int i=1;i<=n;i++)cout<<i<<" "<<i<<" ";
	for(int i=1;i<=n;i++)cout<<i<<" ";
	cout<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
