#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long 
using namespace std;
void solve(){
	int n;
	cin>>n;
	string sl;
	cin>>sl;
	vector<int> vc(n+10,0),a,c,d,b;
	d=c=a=b=vc;
	d[0]=1;
	c[0]=-1e18;
	for(int i=1;i<=n;i++)vc[i]=(sl[i-1]-'0');
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		if(c[i-1]!=c[i]){
			if(c[i]<c[i-1]){
				cout<<"No"<<"\n";
				return ;
			}
			b[i]=c[i];
			d[i]=1;
			for(int j=i;j>=1;j--){
				if(vc[j]==1){
					if(d[j-1] && (b[j-1]+a[j])!=b[j]){
						cout<<"No"<<"\n";
						return ;
					}
					d[j-1]=1;
					b[j-1]=b[j]-a[j];
				}
				else break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vc[i])b[i]=b[i-1]+a[i],d[i]=1;
		if(!d[i])b[i]=-1e16;
		a[i]=b[i]-b[i-1];
		if(max(c[i-1],b[i])!=c[i]){
			cout<<"No"<<"\n";
			return ;
		}
	}
	cout<<"Yes"<<"\n";
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
}
