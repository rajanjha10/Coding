// https://www.codechef.com/FLMOCK01/problems/ALTARAY

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
		LL a[n];
		read(a, n);
		int ans[n];
		
		ans[n-1] = 1;
		for(int i=n-2; i>=0; i--){
			if((a[i]>0 && a[i+1]<0) || (a[i]<0 && a[i+1]>0))
				ans[i] = ans[i+1] + 1;
			else
				ans[i] = 1;
		}
		print(ans, n);
	}
	
	return 0;
}
