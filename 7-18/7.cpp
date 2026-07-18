#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#define int long long
using namespace std;
void solve(){
	int n;
	cin>>n;
	string sl;
	cin>>sl;
	vector<int> vc(n+10,0);
	for(int i=0;i<n;i++){
		vc[i]=(sl[i]-'0');
	}
	int le=0,rt=n-1;
	while(le<n && vc[le]==0)le++;
	while(rt>=0 && vc[rt]==1)rt--;
	
	if(le>rt){
		cout<<"Bob"<<"\n";
		return ;
	}
	
	bool ok=1;
	int cc=1;
	for(int i=le;i<rt;i++){
		if(vc[i+1]==vc[i])cc++;
		else {
			if(cc%2==1)ok=0;
			cc=1;
		}
	}
	if(cc%2==1)ok=0;
	if(ok)cout<<"Bob"<<"\n";
	else cout<<"Alice"<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
