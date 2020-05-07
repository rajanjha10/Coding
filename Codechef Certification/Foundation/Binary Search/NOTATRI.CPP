// https://www.spoj.com/problems/NOTATRI/

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

	while(1){
		int n;
		cin>>n;

		if(!n)
			break;

		LL a[n];
		read(a, n);

		sort(a, a+n);

		LL ans = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				int g = upper_bound(a, a+n, a[i]+a[j]) - a;
				ans += n-g;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}
