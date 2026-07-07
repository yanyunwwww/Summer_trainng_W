#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
signed main(){
    int l,r,x;
    cin>>l>>r>>x;
    int u;
    if(r%x!=0){
        u=r%x;
        r-=u;
    }
    if(l%x!=0){
        u=l%x;
        l+=x-u;
    }
    int res=0;
    if(l>r){
        res=0;
    }
    else {
        int a,b;
        a=l/x;
        b=r/x;
        int la,lb;
        la=a/4,lb=b/4;
        if(la==lb){
            for(int i=a;i<=b;i++)res^=i;
        }
        else {
            int kk=a%4;
            for(int i=a;i<a+4-kk;i++){
                res^=i;
            }
            kk=b%4;
            for(int i=b-kk;i<=b;i++){
                res^=i;
            }
        }
    }
    res*=x;
    cout<<res;
}
