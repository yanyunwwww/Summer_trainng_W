#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n,m,q,idx,las;
int A[500010];
int fa[500010],sz[500010],ma[500010],z[500010];
int fin(int x){
	if(x==fa[x])return x;
	int p=fin(fa[x]);
	ma[x]=max(ma[x],ma[fa[x]]);
	fa[x]=p;
	return p;
}
void solve(){
	cin>>n>>m>>q;
	idx=las=0;
	vector<vector<int>> vc(n+10,vector<int>(m+10,0));
	for(int o=1;o<=q;o++){
		int op,x,y;
		cin>>op>>x>>y;
		x^=las,y^=las;
		if(op==1){
			int w;
			cin>>w;
			idx++;
			int u=idx;
			A[u]=w;
			fa[u]=vc[x][y]=u;
			sz[u]=1,ma[u]=0;
			for(int i=0;i<4;i++){
				int px=dx[i]+x,py=dy[i]+y;
				if(px<1 || py<1 || px>n || py>m || !vc[px][py])continue;
				int v=vc[px][py];
				int fu=fin(u),fv=fin(v);
				if(fu!=fv){
					idx++;
					int c=idx;
					sz[c]=sz[fu]+sz[fv];
					ma[c]=0;
					fa[c]=fa[fu]=fa[fv]=c;
					ma[fu]=w-sz[fu]+1;
					ma[fv]=w-sz[fv]+1;
					sz[fu]=sz[fv]=0;
				}
			}
			las=sz[fin(u)]-1;
			cout<<las<<"\n";
		}
		else {
			int qp=fin(vc[x][y]);
			las=max(ma[vc[x][y]]-A[vc[x][y]],0ll);
			cout<<las<<"\n";
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	T=1;
	while(T--)solve();
}
