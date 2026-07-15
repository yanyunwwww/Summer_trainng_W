#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
const int mod=1e9+7;
int ksm(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res%mod;
}
void solve(){
	int n;
	cin>>n;
	vector<int> vc(n+10,0);
	for(int i=1;i<=n;i++)cin>>vc[i];
	bool op=0;
	int las=0,ge=0;
	int z=0;
	for(int i=1;i<=n;i++){
		if(vc[i]==-1)op=1,z=1;
		else {
			if(vc[i]>0 && las==0){
				las=vc[i];
				z++;
			}
			else {
				if(las!=vc[i]){
					if(vc[i]==(las+1))ge++;
					z++;
					las=vc[i];
				}
			}
		}
	}
	if(op){
		cout<<ksm(2,n-z)*(ge+1)%mod<<"\n";
	}
	else {
		cout<<ksm(2,n-z)<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
