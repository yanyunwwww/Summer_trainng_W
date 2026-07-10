#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define int long long
using namespace std;
struct qe{
	int x,y;
	bool operator<(const qe& ne)const{
		return x<ne.x;
	}
};
void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10,0),b;
	b=a;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int m;
	cin>>m;
	vector<int> l(m+10,0),r,d;
	d=r=l;
	for(int i=1;i<=m;i++){
		cin>>l[i];
	}
	for(int i=1;i<=m;i++)cin>>r[i];
	for(int i=1;i<=m;i++)cin>>d[i];
	vector<int> qz1(n+10,0),hz1(n+10,0),qz2(n+10,0),hz2(n+10,0);
	vector<qe> aa,bb;
	for(int i=1;i<=n;i++){
		aa.push_back({a[i],b[i]});
		bb.push_back({b[i],a[i]});
	}
	sort(aa.begin(),aa.end());
	sort(bb.begin(),bb.end());
	qz1[1]=aa[0].y;
	hz1[n]=aa[n-1].y;
	qz2[1]=bb[0].y;
	hz2[n]=bb[n-1].y;
	for(int i=2;i<=n;i++){
		qz1[i]=min(qz1[i-1],aa[i-1].y);
		qz2[i]=min(qz2[i-1],bb[i-1].y);
	}
	for(int i=n-1;i>=1;i--){
		hz1[i]=min(hz1[i+1],aa[i-1].y);
		hz2[i]=min(hz2[i+1],bb[i-1].y);
	}
	int zx=1e18+9;
	int res=1e18+9;
	for(int i=1;i<=n;i++)zx=min(zx,a[i]+b[i]);
	for(int i=1;i<=m;i++){
		res=1e18+9;
		int xx=l[i],yy=r[i],dd=d[i];
		qe op={xx,0};
		auto p=lower_bound(aa.begin(),aa.end(),op);
		if(p!=aa.begin()){
			p--;
			int ok=p-aa.begin();
			ok++;
			int om=qz1[ok];
			if(om<yy)om=0;
			else if(om>(yy+dd))om=yy+dd;
			res=min(res,om);
		}
//		cout<<res<<"A\n";
		op={yy,0};
		p=lower_bound(bb.begin(),bb.end(),op);
		if(p!=bb.begin()){
			p--;
			int ok=p-bb.begin();
			ok++;
			int om=qz2[ok];
			if(om<xx)om=0;
			else if(om>(xx+dd))om=xx+dd;
			res=min(res,om);
		}
//		cout<<res<<"B\n";
		op={xx+dd,0};
		p=lower_bound(aa.begin(),aa.end(),op);
		if(p!=aa.end()){
			int ok=p-aa.begin();
			ok++;
			int om=hz1[ok];
			if(om<yy)om=0;
			else if(om>(yy+dd))om=yy+dd;
			res=min(res,om+xx+dd);
		} 
//		cout<<res<<"C\n";
		op={yy+dd,0};
		p=lower_bound(bb.begin(),bb.end(),op);
		if(p!=bb.end()){
			int ok=p-bb.begin();
			ok++;
			int om=hz2[ok];
			if(om<xx)om=0;
			else if(om>(xx+dd))om=xx+dd;
			res=min(res,om+yy+dd);
		}
//		cout<<res<<"D\n";
		res=min(res,zx);
		cout<<res<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t=1;
	while(t--)solve();
}
