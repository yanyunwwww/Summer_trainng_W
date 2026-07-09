#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long 
using namespace std;
int vc[100];
int a,n;
int ge(int w,int b){
	int res=0;
	int m=1;
	for(int i=1;i<=w;i++){
		res+=vc[b%n]*m;
		m*=10;
		b/=n;
	}
	return res;
}
int pow(int a,int b){
	int res=a;
	for(int i=1;i<b;i++)res*=a;
	return res;
}
void solve(){
	cin>>a>>n;
	for(int i=0;i<n;i++)cin>>vc[i];
	sort(vc,vc+n);
	int res=1e18+9;
	for(int i=1;i<=18;i++){
		int l=0;
		int r=pow(n,i)-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(ge(i,mid)>=a)r=mid;
			else l=mid+1;
		}
		if(l>0){
			res=min(res,abs(a-ge(i,l-1)));
		}
		if(l<pow(n,i)){
			res=min(res,abs(a-ge(i,l)));
		}
	}
	cout<<res<<"\n";
}
signed main(){
	int t;
	cin>>t;
	while(t--)solve(); 
}
