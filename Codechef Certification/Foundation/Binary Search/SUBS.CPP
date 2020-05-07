// https://www.spoj.com/problems/SUBS/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool eval(LL m, string x, string y){
	LL i=0, j=0, k;
	while(i<x.size() && j<y.size()){
		for(k=0; k<m && j<y.size(); j++){
			if(x[i]==y[j])
				k++;
		}
		
		if(k==m)
			i++;
	}

	return i==x.size();
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		string x, y;
		cin>>x>>y;

		LL low = 0, high = y.length()/x.length();
		while(low<high){
			LL mid = low + (high - low + 1)/2;

			if(eval(mid, x, y))
				low = mid;
			else
				high = mid - 1;
		}
		
		cout<<low<<endl;
	}

	return 0;
}
