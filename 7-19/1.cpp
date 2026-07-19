#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int gcd(int a,int b){
	if(b!=0)return gcd(b,a%b);
	else return a;
}
void solve(){
	int n,x,y;
	cin>>n>>x>>y;
	vector<int> vc(n+10,0);
	for(int i=1;i<=n;i++)cin>>vc[i];
	if(y<x)swap(x,y);
	if(gcd(x,y)==1){
		cout<<"Yes"<<"\n";
	}
	else {
		int o=gcd(x,y);
		for(int i=1;i<=n;i++){
			int u=abs(i-vc[i]);
			if(u%o!=0){
				cout<<"No"<<"\n";
				return ;
			}
		}
		cout<<"Yes"<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
