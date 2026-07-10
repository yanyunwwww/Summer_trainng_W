#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n,sum;
	cin>>n;
	sum=0;
	vector<int> vc(n+10,0);
	for(int i=1;i<=n;i++){
		cin>>vc[i];
		sum+=vc[i];
	}
	int res=0;
	int a=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vc[i]>=2){
			a++;
			res+=vc[i];
			cnt+=(vc[i]/2)-1;
		}
	}
	int b=n-a;
	if(a==1)cnt+=1;
	res+=min(cnt,b);
	if(sum<3)res=0;
	cout<<res<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
