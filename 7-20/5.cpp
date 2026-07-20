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
    int n,q;
    cin>>n>>q;
    string sl;
    cin>>sl;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            ge[i][j]=0;
        }
    }
    for(int j=0;j<26;j++){
        to[j]=0;
    }
    for(int i=n;i>=1;i--){
        int x=(sl[i-1]-'a');
        for(int j=0;j<26;j++){
            ge[x][j]+=to[j];
        }
        to[x]++;
    }
    int res=0;
    for(int o=1;o<=q;o++){
        string tl;
        cin>>tl;
        res=0;
        for(int i=0;i<26;i++)to[i]=0;
        for(int i=0;i<26;i++){
            int p=(tl[i]-'a');
            for(int j=0;j<26;j++){
                if(to[j])res+=ge[p][j];
            }
            to[p]=1;
        }
        cout<<res<<"\n";
    }
}
