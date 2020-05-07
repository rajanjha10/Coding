// https://www.codechef.com/FLMOCK04/problems/RESQ

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
		LL n;
		cin>>n;
		LL sn = sqrt(n);

		while(sn>1 && n%sn!=0)
			sn--;

		cout<<abs(sn - n/sn)<<endl;
	}

	return 0;
}
