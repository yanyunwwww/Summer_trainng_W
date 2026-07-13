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
	vector<int> vc(n+10,0);
	for(int i=1;i<=n;i++)cin>>vc[i];
	sort(vc.begin()+1,vc.begin()+1+n);
	int ge=0;
	int las=-1;
	bool op=0;
	int z=0;
	for(int i=n;i>=1;i--){
		if(i==n)las=vc[i],ge=1,z=vc[i];
		else {
			if(vc[i]==las){
				ge++;	
			}
			else {
				if(las==z){
					if(ge%2==0){
						op=1;
						break;
					}
					else {
						if((z-vc[i])<=k){
							op=1;
							break;
						}
						else {
							z=vc[i];
							ge=1;
							las=vc[i];
						}
					}
				}
			}
		}
	}
	if(!op && ge%2==0){
		op=1;
	}
	if(op)cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
