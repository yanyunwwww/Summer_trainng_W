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
	vector<int> vc(n+10,0),pr,ma,pp;
	pr=ma=pp=vc;
	for(int i=1;i<=n;i++)cin>>vc[i];
	for(int i=1;i<=n;i++){
		pr[i]=pr[i-1];
		if(vc[i]==1 || vc[i]==2)pr[i]++;
		else pr[i]--;
		pp[i]=pp[i-1];
		if(vc[i]==1)pp[i]++;
		else pp[i]--;
	}
	ma[n]=-1e9-7;
	for(int i=n-1;i>=2;i--){
		ma[i]=max(ma[i+1],pr[i]);
	}
	bool op=0;
	for(int i=1;i<=(n-2);i++){
		if(pp[i]>=0){
			if(ma[i+1]-pr[i]>=0){
				op=1;
				break;
			}
		}
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
