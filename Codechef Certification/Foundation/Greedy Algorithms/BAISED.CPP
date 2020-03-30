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
	LL t;
	cin>>t;
	while(t--){
		LL n, r;
		cin>>n;
		
		LL a[n];
		string s;
		
		for(LL i=0; i<n; i++)
			cin>>s>>a[i];
		
		sort(a, a+n);
		LL ans=0;

		for(LL i=0; i<n; i++){
			if(a[i]!=i+1)
				ans += abs(i+1-a[i]);
		}

		cout<<ans<<endl;
	}

	return 0;
}
