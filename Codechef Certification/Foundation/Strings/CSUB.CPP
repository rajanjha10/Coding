//https://www.codechef.com/problems/CSUB

#include<bits/stdc++.h>
#define LL long long
#define M 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl;
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
	fastio;
	LL t;
	cin>>t;
	while(t--){
		LL n, i;
		cin>>n;
		string s;
		cin>>s;
		for(i=0; i<s.size(); i++)
			if(s[i]=='0')
				n--;

		cout<<(n*(n+1))/2<<endl;
	}
	return 0;
}