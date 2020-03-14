//https://www.codechef.com/problems/TRISQ

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int eval(int b){
	if(b<=3)
		return 0;

	return (b/2-1) + eval(b-2);
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int b;
		cin>>b;
		cout<<eval(b)<<endl;
	}
	return 0;
}