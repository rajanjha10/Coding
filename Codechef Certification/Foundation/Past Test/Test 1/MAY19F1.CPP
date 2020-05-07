// https://www.codechef.com/FLPAST01/problems/MAY19F1

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
		int n, q;
		cin>>n>>q;
		LL mx[n], a;

		cin>>mx[0];
		for(int i=1; i<n; i++){
			cin>>a;
			mx[i] = max(a, mx[i-1]);
		}

		while(q--){
			cin>>a;
			cout<<mx[a-1]<<"\n";
		}

	}

	return 0;
}
