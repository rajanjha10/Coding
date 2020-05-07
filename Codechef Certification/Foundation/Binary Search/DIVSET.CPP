//https://www.codechef.com/problems/DIVSET

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool eval(LL a[], int n, int k, int c, int x){
	if(x==0)
		return true;

	LL last[x];
	int count[x]={0}, index=0, valid=0;

	for(int i=0; i<n; i++){
		while(count[index]>=k)
			index = (index+1)%x;

		if(count[index]==0 || a[i]>=last[index]*c){
			last[index] = a[i];
			count[index]++;
			if(count[index]>=k)
				valid++;
			index = (index+1)%x;
		}

		if(valid==x)
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
		int n, k, c;
		cin>>n>>k>>c;
		LL a[n];
		read(a, n);

		sort(a, a+n);

		int low = -1, high = n+1;
		while(high-low>1){
			int mid = low + (high-low)/2;
			if(eval(a, n, k, c, mid))
				low = mid;
			else
				high = mid; 
		}

		cout<<low<<endl;
	}

	return 0;
}
