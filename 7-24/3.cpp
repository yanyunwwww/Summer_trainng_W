#include<bits/stdc++.h>
#define int long long
using pii = std::pair<int,int>;
using namespace std;
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
struct op{
	int x,y;
};
void solved(){
    cin>>n>>m;
    vector<vector<int>> vc(n+10,vector<int>(m+10,0)),ru,st;
    st=vc;
    ru=vc;
    queue<op> qe;
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>vc[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int a=0,b=0;
			for(int o=0;o<4;o++){
				int xx=dx[o]+i;
				int yy=dy[o]+j;
				if(xx<1 || xx>n || yy<1 || yy>m)continue;
				b++;
				if(vc[xx][yy]<vc[i][j]){
					a++;
					ru[xx][yy]++;
				}
			}
			if(a==b){
				qe.push({i,j});
			}
		}
	}
	while(qe.size()){
		auto pp=qe.front();
		qe.pop();
		
		int x=pp.x,y=pp.y;
		int u=st[x][y];
		u^=1;
		for(int o=0;o<4;o++){
			int xx=dx[o]+x;
			int yy=dy[o]+y;
			if(xx<1 || xx>n || yy<1 || yy>m)continue;
			if(vc[xx][yy]<vc[x][y]){
				ru[xx][yy]--;
				st[xx][yy]|=u;
			}
			if(!ru[xx][yy]){
				qe.push({xx,yy});
			}
		}
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(st[x][y])cout<<"First\n";
		else cout<<"Second\n";
	}
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        solved();
    }
    return 0;
}
