//https://www.codechef.com/problems/NOKIA

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int cal_min(int n){
	if(n==0)
		return 0;
	
	return cal_min(n/2) + cal_min(n-n/2-1) + (n+1);
}

int cal_max(int n){
	if(n==0)
		return 0;

	return cal_max(n-1) + (n+1);
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, m, ans=INT_MAX;
		cin>>n>>m;
		int l = cal_min(n);
		int r = cal_max(n);

		if(l>m) 
			cout<<-1<<endl;
		else if(m<=r) 
			cout<<0<<endl;
		else 
			cout<<m-r<<endl;
	}
	return 0;
}