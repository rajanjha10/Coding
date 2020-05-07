//https://www.codechef.com/problems/SNTEMPLE

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool eval(LL h[], int n, LL mid){
	bool left[n] = {0}, right[n] = {0};
	
	for(int i=0, k=0; i<n; i++){
		if(h[i]>=k+1){
			k++;
			if(k==mid){
				left[i] = 1;
				k--;
			}
		}
		else
			k = h[i];
	}

	for(int i=n-1, k=0; ~i; i--){
		if(h[i]>=k+1){
			k++;
			if(k==mid){
				right[i] = 1;
				k--;
			}
		}
		else
			k = h[i];
	}

	for(int i=0; i<n; i++){
		if(left[i]==1 && right[i]==1)
			return true;
	}

	return false;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		LL h[n];
		read(h, n);
		
		LL sum = 0;
		sum = accumulate(h, h+n, sum);

		LL low = 1, high = n, ans = LLONG_MAX;
		while(low<high){
			LL mid = low + (high-low)/2;
			if(eval(h, n, mid)){
				ans = min(ans, sum - mid*mid);
				low = mid+1;
			}
			else
				high = mid;
		}

		cout<<ans<<endl;
	}

	return 0;
}
