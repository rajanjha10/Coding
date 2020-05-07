// https://www.codechef.com/FLMOCK03/problems/CHEFSOCK

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
	LL j, s, m;
	cin>>j>>s>>m;
	m = m - j;
	if((m/s)&1)
		cout<<"Unlucky Chef"<<endl;
	else
		cout<<"Lucky Chef"<<endl;
	
	return 0;
}
