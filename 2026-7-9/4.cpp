#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long 
using namespace std;
void solve(){
	string sl;
	cin>>sl;
	int n=sl.size();
	vector<int> vc(n+10,0),qz1,qz2;
	qz1=qz2=vc;
	for(int i=1;i<=n;i++)vc[i]=(sl[i-1]-'0');
	int res=0;
	int a,b;
	a=b=0;
	for(int i=1;i<=n;i++){
		if(vc[i]==1 || vc[i]==3)b++;
	}
	res=b;
	for(int i=1;i<=n;i++){
		if(vc[i]==1 || vc[i]==3)b--;
		if(vc[i]==2)a++;
		res=max(res,a+b);
	}
	cout<<n-res<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
}
