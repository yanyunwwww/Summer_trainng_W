#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int ok[100];
void ini(){
	ok[1]=1;
	ok[2]=2;
	ok[3]=3;
	for(int i=4;i<=50;i++){
		ok[i]=ok[i-1]*2;
	}
}
void solve(){
	int n;
	cin>>n;
	if(n==1)cout<<1<<"\n";
	else if(n==2){
		cout<<-1<<"\n";
	}
	else {
		for(int i=1;i<=n;i++)cout<<ok[i]<<" ";
		cout<<"\n";
	}
}
signed main(){
	ini();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
