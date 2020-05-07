// https://www.spoj.com/problems/PIE/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

const auto PI = 3.14159265358979323846;

bool eval(double mid, int r[], int n, int f){
	int cnt = 0;

	for(int i=0; i<n; i++){
		double volume = PI * r[i] * r[i];
		while(volume-mid>=0){
			volume -= mid;
			cnt++;
		}
	}

	return cnt>=f;
}

int main()
{
	fastio;
	cout<<fixed<<setprecision(4);
	int t;
	cin>>t;
	while(t--){
		int n, f;
		cin>>n>>f;

		int r[n];
		read(r, n);

		int mx = *max_element(r, r+n);
		double volume = PI * mx * mx;
		double tolerance = 1e-6;
		f++;

		double low = 0, high = volume;
		int cnt = 100;
		while(low<high && cnt--){
			double mid = low + (high-low)/2;

			if(eval(mid, r, n, f))
				low = mid + tolerance;
			else
				high = mid - tolerance;
		}

		cout<<low<<endl;
	}

	return 0;
}
