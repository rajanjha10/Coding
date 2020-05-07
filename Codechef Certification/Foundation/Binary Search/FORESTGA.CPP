//https://www.codechef.com/problems/FORESTGA

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool eval(LL h[], LL r[], LL w, LL l, LL n, LL mid){
	LL res = 0;
	for(LL i=0; i<n; i++){
		LL v = h[i] + r[i]*mid;
		if(v>=l){
			res += v;
			if(res>=w)
				return true;
		} 
	}

	return false;
}

int main()
{
	fastio;
	LL n, w, l;
	cin>>n>>w>>l;

	LL h[n], r[n];
	for(int i=0; i<n; i++)
		cin>>h[i]>>r[i];

	LL low = 0, high = LLONG_MAX;
	while(low<high){
		LL mid = low + (high-low)/2;

		if(eval(h, r, w, l, n, mid))
			high = mid;
		else
			low = mid+1;
	}

	cout<<low<<endl;	

	return 0;
}
