//https://www.spoj.com/problems/BALIFE/

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
		
		if(n==-1)
			return 0;

		int a[n];
		read(a, n);
		LL sum = 0;
		sum = accumulate(a, a+n, sum);
		
		if(sum%n!=0){
			cout<<-1<<endl;
			continue;
		}

		LL avg = sum/n;
		
		for(int i=0; i<n; i++)
			a[i] = a[i] - avg;

		LL ans = abs(a[0]);
		for(int i=1; i<n; i++){
			a[i] += a[i-1];
			ans  = max(ans, (LL)abs(a[i]));
		}	
		
		cout<<ans<<endl;
	}

	return 0;
}
