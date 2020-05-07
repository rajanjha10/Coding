// https://www.codechef.com/FLMOCK03/problems/SNAKEEAT

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int lower_bound(LL a[], int n, LL k){
    int low = 0, high = n;
    while(low<high){
        int mid = low + (high-low)/2;
        if(a[mid]>=k)
            high = mid;
        else
            low = mid+1;
    }
    
    return low;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
	    int n, q;
	    cin>>n>>q;
	    LL a[n], k;
	    LL prefixSum[n];
	    read(a, n);
	    
	    sort(a, a+n);
	    prefixSum[0] = a[0];
	    
	    for(int i=1; i<n; i++)
	        prefixSum[i] = prefixSum[i-1] + a[i];
	  
	    while(q--){
			cin>>k;
			
			int index = lower_bound(a, n, k) - 1;
			int ans = n-index-1;
			
			int low = 0, high = index;
			while(low<high)
			{
				int mid = low + (high-low)/2;
	            LL req = (index-mid)*k - (prefixSum[index] - prefixSum[mid]);
	            
	            if(req <= mid+1)
	                high = mid;
	            else
	                low = mid+1;
			}
			
			cout<<ans + index - high<<"\n";
	    }
	}

	return 0;
}
