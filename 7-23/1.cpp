#include <bits/stdc++.h>
using namespace std;
const int M = 1e7, inf = 1e9;
int pr[M+1];
int gcd(int a,int b){
	if(b!=0)return gcd(b,a%b);
	else return a;
}
int ge(int tr,int wh){
	int tmp=tr;
	vector<int> pri;
	while(tmp>1){
		int p=pr[tmp];
		pri.push_back(p);
		while(tmp%p==0)tmp/=p;
	}
	int ans=0;
	int sz=pri.size();
	for(int i=0;i<(1ll<<sz);i++){
		int cur=wh;
		int cnt=0;
		for(int j=0;j<sz;j++){
			if((i>>j)&1ll){
				cur/=pri[j];
				cnt++;
			}
		}
		if(cnt%2==1){
			ans-=cur;
		}
		else ans+=cur;
	}
	return ans;
}
int query(int tr,int x){
	int u=tr-1;
	while(u!=pr[u])u--;
	if(x<u){
		return 2*x-ge(tr,x);
	}
	int ans=2*(u-1)-ge(tr,u-1);
	int sz=tr-u;
	vector<int> dp(sz+10,inf);
	dp[0]=0;
	for(int i=1;i<=sz;i++){
		for(int j=0;j<i;j++){
			dp[i]=min(dp[i],dp[j]+gcd(tr-i,tr-j));
		}
		if((tr-i)<=x)ans+=dp[i];
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<=M;i++){
		pr[i]=i;
	}
	for(int i=2;i<=M;i++){
		if(pr[i]==i){
			for(int j=i;j<=M;j+=i){
				pr[j]=i;
			}
		}
	}
	int T;
	cin>>T;
	while(T--){
		int l,r,n;
		cin>>l>>r>>n;
		cout<<query(n,r)-query(n,l-1)<<"\n";
	}
}
