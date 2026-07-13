#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int ksm(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=res*x;
		x=x*x;
		b>>=1;
	}
	return res;
}
void solve(){
	int a,b,x;
	cin>>a>>b>>x;
	int res=1e18+9;
	if(a>b)swap(a,b);
	if(a==b){
		cout<<0<<"\n";
		return ;
	}
	for(int i=0;i<=40;i++){
		int q,p;
		q=a/ksm(x,i);
		for(int j=0;j<=40;j++){
			p=b/ksm(x,j);
			res=min(res,abs(p-q)+i+j);
			if(p==0)break;
		}
		if(q==0)break;
	}
	cout<<res<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
