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
	vector<int> vc(n+10,0),l,r;
	l=r=vc;
	for(int i=0;i<n;i++)cin>>vc[i];
	for(int i=0;i<n;i++){
		int x=0;
		for(int j=1;j<n;j++){
			int b=i+j;
			int a=b-1;
			b%=n;
			a%=n;
			r[b]=max(vc[a],x);
			x=max(vc[a],x);
		}
		x=0;
		for(int j=1;j<n;j++){
			int b=i-j;
			b=(b%n+n)%n;
			l[b]=max(vc[b],x);
			x=max(vc[b],x);
		}
		int res=0;
		for(int k=0;k<n;k++){
			if(k==i)continue;
			res+=min(l[k],r[k]);
		}
		cout<<res<<" ";
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
