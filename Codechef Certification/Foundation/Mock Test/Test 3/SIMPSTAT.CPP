// https://www.codechef.com/FLMOCK03/problems/SIMPSTAT

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
	cout<<fixed<<setprecision(6);
	while(t--){
		int n, k, cnt=0;
		cin>>n>>k;

		LL a[n], sum = 0;
		read(a, n);
		sort(a, a+n);

		for(int i=k; i<n-k; i++, cnt++)
			sum += a[i];

		cout<<(double(sum)/cnt)<<endl;
	}

	return 0;
}
