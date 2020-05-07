// https://www.codechef.com/FLMOCK03/problems/STRBIT

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
		int n, k;
		cin>>n>>k;
		string s;
		cin>>s;

		int cnt[n+1], ans = 0;
		memset(cnt, 0, sizeof(cnt));
		for(int i=0; i<n; i++){
			if(s[i]=='R' && cnt[i]%2==0){
				ans++;
				cnt[i] += 1;
				cnt[min(n-1, i+k-1)+1] += -1;
			}
			else if(s[i]=='G' && cnt[i]&1){
				ans++;
				cnt[i] += 1;
				cnt[min(n-1, i+k-1)+1] += -1;
			}

			cnt[i+1] += cnt[i];
		}

		cout<<ans<<endl;
	}

	return 0;
}
