//https://www.codechef.com/problems/DELISH

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		LL a[n], dp_pre_mn[n], dp_suff_mn[n];
		LL dp_pre_mx[n], dp_suff_mx[n], ans=INT_MIN;
		
		read(a, n);

		dp_pre_mn[0] = dp_pre_mx[0] = a[0];
		dp_suff_mn[n-1] = dp_suff_mx[n-1] = a[n-1];

		for(int i=1; i<n; i++){
			dp_pre_mn[i] = min(dp_pre_mn[i-1]+a[i], a[i]);
			dp_pre_mx[i] = max(dp_pre_mx[i-1]+a[i], a[i]);
		}
		for(int i=n-2; i>=0; i--){
			dp_suff_mn[i] = min(dp_suff_mn[i+1]+a[i], a[i]);
			dp_suff_mx[i] = max(dp_suff_mx[i+1]+a[i], a[i]);
		}
		
		for(int i=0; i<n-1; i++){
			ans = max(ans, abs(dp_pre_mx[i]-dp_suff_mn[i+1]));
			ans = max(ans, abs(dp_pre_mn[i]-dp_suff_mx[i+1]));
		}
		
		cout<<ans<<endl;
	}

	return 0;
}
