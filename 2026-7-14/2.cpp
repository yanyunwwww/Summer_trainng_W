#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int pri[2000000];
int idx=0;
bool st[2000000];
void ini(){
	for(int i=2;i<=1001000;i++){
		if(!st[i])pri[++idx]=i;
		for(int j=1;j<=idx && pri[j]*i<=1001000;j++){
			st[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
}
void solve(){
	int n;
	cin>>n;
	int res=0;
	int u=0;
	for(int i=1;pri[i]<=n;i++){
		int x=pri[i];
		if(n%x==0){
			res++;
			while(n%x==0){
				n/=x;
				u++;
			}
		}
	}
	if(n>1)res++,n/=n;
	u--;
	cout<<res+u<<"\n";
}
signed main(){
	ini();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
