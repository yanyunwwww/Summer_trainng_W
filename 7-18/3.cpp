#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
vector<int> kn[300000];
void solve(){
	int n;
	cin>>n;
	vector<int> vc(n+10,0);
	for(int i=0;i<n;i++)cin>>vc[i],kn[i].clear();
	
	auto rk=vc;
	sort(rk.begin(),rk.end());
	rk.erase(unique(rk.begin(),rk.end()),rk.end());
	for(int i=0;i<n;i++){
		vc[i]=lower_bound(rk.begin(),rk.end(),vc[i])-rk.begin();
	}
	vector<int> cnt(n+10,0);
	for(int i=0;i<n;){
		int t=i;
		while(t<n && vc[t]==vc[i]){
			t++;
		}
		kn[vc[i]].push_back(i);
		kn[vc[i]].push_back(i-1);
		kn[vc[i]].push_back(t);
		kn[vc[i]].push_back(t-1);
		cnt[vc[i]]++;
		i=t;
	}
	
	for(int i=0;i<n;i++){
		if(cnt[i]>1){
			if(cnt[i]>3){
				cout<<"No"<<"\n";
				return ;
			}
			bool ok=0;
			sort(kn[i].begin(),kn[i].end());
			kn[i].erase(unique(kn[i].begin(),kn[i].end()),kn[i].end());
			for(auto x:kn[i]){
				for(auto y:kn[i]){
					if(x<y){
						if(x<0 || y<0 ||x>=n || y>=n)continue;
						swap(vc[x],vc[y]);
						vector<int> z(n+10,0);
						for(int i=0;i<n;){
							int t=i;
							while(t<n && vc[t]==vc[i]){
								t++;
							}		
							z[vc[i]]++;
							i=t;	
						}
						swap(vc[x],vc[y]);
						bool op=1;
						for(int i=0;i<n;i++){
							if(z[vc[i]]>1)op=0;
						}
						ok|=op;
					}
				}
			}
			if(!ok){
				cout<<"No"<<"\n";
				return ;
			}
			break;
		}
	}
	cout<<"Yes"<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
