#include<bits/stdc++.h>
#define int long long
using pii = std::pair<int,int>;
using namespace std;
struct op{
	int x,y;
};
void solved(){
    int n;
    cin>>n;
    vector<op> vc(n+10);
    for(int i=1;i<=n;i++){
    	int a,b;
    	cin>>a>>b;
    	vc[i]={a,b};
	}
    int x,y;
    x=vc[2].x-vc[1].x;
    y=vc[2].y-vc[1].y;
    for(int i=3;i<=n;i++){
    	int lx=vc[i].x-vc[i-1].x;
    	int ly=vc[i].y-vc[i-1].y;
    	int u=lx*y-ly*x;
    	if(u>0){
    		cout<<"RIGHT ";
		}
		else if(u==0){
			cout<<"STRAIGHT ";
		}
		else {
			cout<<"LEFT ";
		}
		x=lx;
		y=ly;
	}
	cout<<"\n";
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
