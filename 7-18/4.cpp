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
	string sl;
	cin>>sl;
	int ge=0,las=-1;
	for(int i=0;i<n;i++){
		if(las!=(sl[i]-'0')){
			las=(sl[i]-'0');
			ge++;
		}
	}
	if(ge==2){
		cout<<2<<"\n";
	}
	else {
		cout<<1<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
