//https://www.codechef.com/problems/CHEFST

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
		LL n1, n2, m;
		cin>>n1>>n2>>m;

		LL diff = max(n1, n2) - min(n1, n2);
		LL som = (m*(m+1))/2;

		if(som >= min(n1, n2))
			cout<<diff<<endl;
		else
			cout<< 2*(min(n1, n2) - som) + diff <<endl;
		
	}

	return 0;
}
