#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
const int mod=998244353;
int x1,y1,x2,y2;
int x3,y3,x4,y4;
int solve(){
    int ans=0;
    if(y4==y2 || y4==y1){
//        if(x3==x2)ans+=1;
       if(x3<x2){
//            if(x4==x1)ans+=1;
           if(x4>x1)return -1;
       }
    } 
    if(y3==y2 || y3==y1){
//        if(x3==x2)ans+=1;
       if(x3<x2){
//            if(x4==x1)ans+=1;
           if(x4>x1)return -1;
       }
    }
    if(y3>y1 && y3<y2){
        if(x3==x1 && x4==x2)ans+=2;
        else if((x3>x1 && x3<=x2 && x4>=x2) || (x4>=x1 && x4<x2 && x3<=x1))ans+=1;
    }
    if(y4>y1 && y4<y2){
        if(x3==x1 && x4==x2)ans+=2;
        else if((x3>x1 && x3<=x2 && x4>=x2) || (x4>=x1 && x4<x2 && x3<=x1))ans+=1;
    }
    if(x3==x1 || x3==x2){
//         if(y3==y2)ans+=1;
        if(y3<y2){
//             if(y4==y1)ans+=1;
            if(y4>y1)return -1;
        }
    }
    if(x4==x1 || x4==x2){
//         if(y3==y2)ans+=1;
        if(y3<y2){
//             if(y4==y1)ans+=1;
            if(y4>y1)return -1;
        }
    }
    if(x3>x1 && x3<x2){
        if(y3==y1 && y2==y4)ans+=2;
        else if((y3>y1 && y3<=y2 && y4>=y2) || (y4<y2 && y4>=y1 && y3<=y1))ans+=1;
    }
    if(x4>x1 && x4<x2){
        if(y3==y1 && y2==y4)ans+=2;
        else if((y3>y1 && y3<=y2 && y4>=y2) || (y4<y2 && y4>=y1 && y3<=y1))ans+=1;
    }
    if(x3==x2 && y3==y2)ans+=1;
    if(x3==x2 && y4==y1)ans+=1;
    if(x4==x1 && y4==y1)ans+=1;
    if(x4==x1 && y3==y2)ans+=1;
    return ans;
}
signed main(){
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    if(x3>x4)swap(x3,x4);
    if(y3>y4)swap(y3,y4);
    int u=solve();
    if(u!=-1)cout<<u;
    else cout<<"inf";
}
