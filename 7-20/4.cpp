#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
int ge[100][100];
int to[30];
signed main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> vc(n+10,0);
    for(int i=1;i<=n;i++)cin>>vc[i];
    int ok=1;
    if(m%2==0)ok=1;
    else ok=0;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        if(x!=y)ok^=1;
        if(ok==1)cout<<"even"<<"\n";
        else cout<<"odd"<<"\n";
    }
}
