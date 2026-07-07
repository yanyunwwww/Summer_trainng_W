#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int __int128
using namespace std;
int read(){
    int a=0,s=0;
    int w=1;
    string sl;
    cin>>sl;
    if(sl[0]=='-')s=1,w=-1;
    for(int i=s;i<sl.size();i++){
        a=a*10+(sl[i]-'0');
    }
    return a*w;
}
void prt(int x){
    if(x<0){
        cout<<"-";
        x=-x;
    }
    if(x==0){
        cout<<0;
        return ;
    }
    string sl;
    while(x>0){
        sl.push_back('0'+x%10);
        x/=10;
    }
    for(int i=sl.size()-1;i>=0;i--){
        cout<<sl[i];
    }
}
signed main(){
    int n,k,W;
//     cin>>n>>k>>W;
    n=read();
    k=read();
    W=read();
    vector<int> vc(n+10,0),w;
    w=vc;
    for(int i=1;i<=n;i++){
        vc[i]=read();
        w[i]=read();
//         cin>>vc[i]>>w[i];
    }
    int ss,sw;
    ss=sw=0;
    for(int i=1;i<=n;i++)sw+=w[i],ss+=vc[i]*w[i];
    int res=0;
    for(int i=1;i<=n;i++){
        sw-=w[i];
        ss-=vc[i]*w[i];
        int l=0,r=k;
        while(l<r){
            int mid=(l+r)>>1;
            if((2*k*(sw*mid-ss)+W*(2*mid-k)*k)>=0)r=mid;
            else l=mid+1;
        }
        if((2*k*(sw*r-ss)+W*(2*r-k)*k)==0)res++;
        sw+=w[i];
        ss+=vc[i]*w[i];
    }
//     cout<<res;
    prt(res);
}
