//https://www.codechef.com/problems/RIGHTTRI

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
		double h, s;
		cin>>h>>s;

		double hsq = h*h;
		double maxBase = sqrt((hsq)/2);
		double tolerance = 1e-12;

		if(hsq/4<s || s<1){
			cout<<-1<<endl;
			continue;
		}

		double low = 0.0, high = maxBase;
		double height;
		int cnt=100;
		while(low<=high && cnt--){
			double mid = low + (high-low)/2;

			height = sqrt((hsq - mid*mid));
			double area = (mid*height)/2;

			if(area > s)
				high = mid - tolerance;
			else
				low = mid + tolerance;
		}

		if(low > height)
			swap(low, height);

		cout<<fixed<<setprecision(6)<<low<<" "<<height<<" "<<h<<endl;
	}

	return 0;
}
