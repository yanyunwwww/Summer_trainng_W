#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n,q;
    cin>>n>>q;
    string sl;
    cin>>sl;
    vector<int> pr(n+10,0);
    for(int i=0;i<(n-1);i++){
    	pr[i+1]=pr[i];
    	if(sl[i+1]==sl[i])pr[i+1]++;
	}
	for(int i=1;i<=q;i++){
		int l,r,k;
		cin>>l>>r>>k;
		if(l==r){
			cout<<"Yes"<<"\n";
			continue ;
		}
		int u=pr[r-1]-pr[l-1];
		int c=(u+1)/2;
		if(c<=k)cout<<"Yes"<<"\n";
		else cout<<"No"<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
