// https://www.codechef.com/FLMOCK02/problems/CIELRCPT

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int count_set(int n){
	int cnt=0;
	while(n){
		n = n&(n-1);
		cnt++;
	}
	return cnt;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, ans=0;
		cin>>n;
		while(n>=2048){
			ans++;
			n -= 2048;
		}

		cout<<ans + count_set(n)<<endl;
	}

	return 0;
}
