#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
const int mod=1e9+7;
int jc[600000],ny[600000],vc[600000];
int ksm(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=(res*x)%mod;
		x=(x*x)%mod;
		b>>=1;
	}
	return res;
}
void ini(){
	jc[0]=ny[0]=1;
	for(int i=1;i<=500000;i++){
		jc[i]=(jc[i-1]*i)%mod;
		ny[i]=(ny[i-1]*ksm(i,mod-2))%mod;
	}
}
int Cr(int x,int y){
	return jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int dg(int l,int r){
	if(r<l)return 1;
	if(l==r){
		if(vc[l]==1)return 1;
		else return 0;
	}
	for(int j=0;j<(r-l+1);j++){
		int a=j+l;
		if((a-l+1)*(r-a+1)==vc[a]){
			return Cr(r-l,a-l)*(dg(l,a-1)*dg(a+1,r)%mod)%mod;
		}
		int b=r-j;
		if((b-l+1)*(r-b+1)==vc[b]){
			return Cr(r-l,b-l)*(dg(l,b-1)*dg(b+1,r)%mod)%mod;
		}
	}
	return 0;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>vc[i];
	int sum=0;
	for(int i=1;i<=n;i++)sum+=vc[i];
	if(sum!=(n*(n+1)/2)){
		cout<<0<<"\n";
		return ;
	}
	
	cout<<dg(1,n)<<"\n";
}
signed main(){
	ini();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
