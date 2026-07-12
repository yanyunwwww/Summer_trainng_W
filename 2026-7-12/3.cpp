#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	int u=(1ll<<k)+1;
	string a,b;
	cin>>a>>b;
	vector<int> aa,bb(n+10,0);
	aa=bb;
	for(int i=1;i<=n;i++){
		aa[i]=(a[i-1]-'0');
		bb[i]=(b[i-1]-'0');
	}
	int a0,a1,b0,b1,c0,c1;
	a0=a1=b0=b1=c0=c1=0;
	for(int i=1;i<=n;i++){
		if(aa[i]==1)a1++;
		else a0++;
		if(bb[i]==1)b1++;
		else b0++;
		if((aa[i]^bb[i])==1)c1++;
		else c0++;
	}
	int kk=a1*a0+b1*b0+c1*c0;
	int res=0;
	if(u%3==0){
		res=kk*(u/3);
	}
	else {
		res=kk*(u/3);
		res+=a1*a0+b1*b0;
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
