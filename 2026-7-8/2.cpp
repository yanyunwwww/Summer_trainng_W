#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
vector<int> e[300000];
int vc[300000],ff[300000],n,q;
int yr[300000],ge[300000],co[300000];
int ss[300000],xx[300000];
int root=0;
void dfs1(int x,int fa){
    ff[x]=fa;
    if(vc[x]==1)yr[x]=1;
    for(auto p:e[x]){
        if(p==fa)continue;
        dfs1(p,x);
        co[x]+=co[p];
        if(yr[p]){
            yr[x]=1;
            ge[x]++;
        }
    }
    if(!vc[x] && yr[x])co[x]++;
}
void dfs2(int x,int fa,int now){
    if(!vc[x] && ge[x]==1){
        ss[x]=now;
    }
    else {
        now=0;
    }
    for(auto p:e[x]){
        if(p==fa)continue;
        dfs2(p,x,now+1);
    }
}
void dfs3(int x,int fa){
    for(auto p:e[x]){
        if(p==fa)continue;
        
        dfs3(p,x);
        if(yr[p] && !vc[x] && ge[x]==1){
            xx[x]=xx[p]+1;
        }
    }
}
signed main(){
    cin>>n>>q;
    string sl;
    cin>>sl;
    for(int i=1;i<=n;i++){
        yr[i]=ge[i]=co[i]=ss[i]=xx[i]=0;
    }
    for(int i=1;i<=n;i++){
        vc[i]=(sl[i-1]-'0');
        if(vc[i]==1)root=i;
        e[i].clear();
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if(root!=0){
        dfs1(root,0);  
        dfs2(root,0,0);
        dfs3(root,0);
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        if(ff[x]==y)swap(x,y);
        if(!root)cout<<2<<"\n";
        else {
            if(!yr[y]){
                cout<<co[root]+1<<"\n";
            }
            else {
                cout<<co[root]-ss[x]-xx[y]<<"\n";
            }
        }
    }
}
