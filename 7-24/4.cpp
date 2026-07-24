#include<bits/stdc++.h>
#define int long long
using pii = std::pair<int,int>;
using namespace std;
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void solved(){
    int n;
    cin>>n;
    vector<int> vc(n+10,0);
    for(int i=1;i<=n;i++){
    	cin>>vc[i];
	}
	int dp[100][4];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		int x=vc[i];
		for(int j=30;j>=1;j--){
			int a=(1ll<<j)+(1ll<<(j-1));
			int u=a&x;
			u>>=(j-1);
			dp[j][u]++;
		}
	}
	int res=0;
	for(int j=30;j>=1;j--){
		res+=dp[j][1];
	}
	int m=0;
	cin>>m;
	int ok[5];
	for(int i=1;i<=m;i++){
		int op;
		cin>>op;
		int x=1;
		cin>>x;
		for(int o=0;o<4;o++)ok[o]=0;
		if(op==1){
			for(int j=30;j>=1;j--){
				int a=(1ll<<j)+(1ll<<(j-1));
				int u=a&x;
				u>>=(j-1);
				for(int o=0;o<4;o++){
					int pp=o&u;
					ok[pp]+=dp[j][o];
				}
				for(int o=0;o<4;o++){
					dp[j][o]=ok[o];
					ok[o]=0;
				}
			}
		}
		else if(op==2){
			for(int j=30;j>=1;j--){
				int a=(1ll<<j)+(1ll<<(j-1));
				int u=a&x;
				u>>=(j-1);
				for(int o=0;o<4;o++){
					int pp=o|u;
					ok[pp]+=dp[j][o];
				}
				for(int o=0;o<4;o++){
					dp[j][o]=ok[o];
					ok[o]=0;
				}
			}
		}
		else if(op==3){
			for(int j=30;j>=1;j--){
				int a=(1ll<<j)+(1ll<<(j-1));
				int u=a&x;
				u>>=(j-1);
				for(int o=0;o<4;o++){
					int pp=o^u;
					ok[pp]+=dp[j][o];
				}
				for(int o=0;o<4;o++){
					dp[j][o]=ok[o];
					ok[o]=0;
				}
			}
		}
		res=0;
		for(int j=30;j>=1;j--){
			res+=dp[j][1];
		}
		cout<<res<<"\n";
	}
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int _=1;
    while(_--){
        solved();
    }
    return 0;
}
