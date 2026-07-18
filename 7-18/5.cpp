#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
vector<int> kn[300000];
void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10,0),b;
	b=a;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int u=0;
	for(int i=n;i>1;i--){
		if(a[i]>=b[i]){
			a[i-1]+=a[i]-b[i];
		}
	}
	if(a[1]<=b[1])cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
