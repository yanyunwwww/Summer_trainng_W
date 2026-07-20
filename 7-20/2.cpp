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
	vector<int> a(n+10,0),b;
	b=a;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int ge=0,z=0;
	bool x=0,y=0;
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]){
			if(a[i]==1)x=1;
			else y=1;
		}
		else {
			ge++;
			if(a[i]==1)z++;
		}
	}
	int res=-1;
	if(ge==0){
		res=0;
	}
	else {
		if(z%2==1){
			res=1;
		}
		else {
			if(z>0)res=2;
			else if(x && y)res=2;
		}
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
