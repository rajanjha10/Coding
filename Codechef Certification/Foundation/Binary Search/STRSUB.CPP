// https://www.codechef.com/problems/STRSUB

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

void preprocess(char s[], int far[], int n, int k){
	int j = 1;
	int count0 = 0, count1 = 0;

	if(s[1]=='0')
		count0++;
	else
		count1++;

	for(int i=1; i<=n; i++){
		while(j<=n && count0<=k && count1<=k){
			j++;
			if(j>n)
				break;

			if(s[j]=='0')
				count0++;
			else
				count1++;
		}

		far[i] = j;

		if(s[i]=='0')
			count0--;
		else
			count1--;
	}
}

LL query(char s[], int far[], LL sumfar[], LL l, LL r){
	int k1 = l-1;
	int k2 = r+1;

	while(k2-k1>1){
		LL mid = ((LL)k2+k1)/2;
		if(far[mid]<=r)
			k1 = mid;
		else
			k2 = mid;
	}

	LL ans = sumfar[k1] - sumfar[l-1];
	ans += (r-k1)*(r+1);
	ans -= (r*(r+1)/2 - l*(l-1)/2);

	return ans;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, k, q;
		cin>>n>>k>>q;
		char s[n+1];
		for(int i=1; i<=n; i++)
			cin>>s[i];

		int far[n+1];
		LL sumfar[n+1];
		far[0] = sumfar[0] = 0;
		
		preprocess(s, far, n, k);
		for(int i=1; i<=n; i++)
			sumfar[i] = sumfar[i-1] + far[i];

		LL l, r;
		while(q--){
			cin>>l>>r;
			cout<<query(s, far, sumfar, l, r)<<endl;
		}
	}

	return 0;
}
