#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
void solve(){
	int n,t,s;
	cin>>n>>t>>s;
	string sl;
	cin>>sl;
	int l,r;
	int res=0;
	l=r=0;
	for(int i=0;i<sl.size();i++){
		if(sl[i]=='A'){
			if(t*s==res)continue;
			res++;
			if(l*s<res)l++;
			r=min(r+1,t);
		}
		else if(sl[i]=='I'){
			if(l==t)continue;
			
			res++;
			l++;
			r=min(r+1,t);
		}
		else {
			if(r*s==res)continue;
			
			res++;
			if(res>l*s)l++;
		}
	}
	cout<<res<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
