// https://www.spoj.com/problems/ABCDEF/

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
	int n;
	cin>>n;

	LL a[n];
	read(a, n);

	vector<LL> lhs, rhs;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				lhs.push_back((a[i]*a[j])+a[k]);

				if(a[k]!=0)
					rhs.push_back((a[i]+a[j])*a[k]);
			}
		}
	}

	sort(rhs.begin(), rhs.end());

	LL ans = 0;
	for(int i=0; i<lhs.size(); i++){
		LL f = lower_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
		LL l = upper_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
		ans += l-f;
	}

	cout<<ans<<endl;

	return 0;
}
