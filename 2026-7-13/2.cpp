#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
// void read(int &n){
//     int x=0,f=1;
//     char ch=getchar();
//     while(ch<'0'||ch>'9'){
//         if(ch=='-') f=-1;
//         ch=getchar();
//     }
//     while(ch>='0'&&ch<='9'){
//         x=x*10+(ch-'0');
//         ch=getchar();
//     }
//     n=x*f;
// }
// void print(int n){
//     if(n<0){
//         putchar('-');
//         n*=-1;
//     }
//     if(n>9) print(n/10);
//     putchar(n % 10 + '0');
// }
signed main(){
    int n;
    cin>>n;
    vector<int> vc(n+10,0),b;
    b=vc;
    for(int i=1;i<=n;i++)cin>>vc[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        if(vc[i]<=0){
            x=max(x,y),y=-1e18-9;
            continue;
        }
        else {
            int xx,yy;
            xx=max(x+b[i]/2*vc[i],y+(b[i]-1)/2*vc[i]);
            yy=max(x+(b[i]+1)/2*vc[i],y+b[i]/2*vc[i]);
            x=xx;
            y=yy;
        }
    }
    cout<<max(x,y);
}
