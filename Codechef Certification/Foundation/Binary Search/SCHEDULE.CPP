//https://www.codechef.com/problems/SCHEDULE

#include<bits/stdc++.h>
#define LL long long
#define MOD 998244353
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
		LL n, k;
		cin>>n>>k;
		string s;
		cin>>s;

		int cnt1 = 0, cnt2 = 0;
		for(int i=0; i<s.size(); i++){
			if(i%2==0){
				if(s[i]-'0')
					cnt1++;
				else
					cnt2++;
			}
			else{
				if(s[i]-'0')
					cnt2++;
				else
					cnt1++;
			}
		}

		if(k>=min(cnt1, cnt2)){
			cout<<1<<endl;
			continue;
		}

        vector<int> block;
		char curr = s[0];
		int cnt = 1;
		for(int i=1; i<s.size(); i++){
			if(s[i]==curr)
				cnt++;
			else{
				block.push_back(cnt);
				cnt = 1;
				curr = s[i];
			}
		}
		block.push_back(cnt);

		int ans = 0;
		int low = 2, high = n;
		while(low<high){
		    int mid = low + (high-low)/2;
		    
		    int cost = 0;
		    for(int i: block)
		        cost += i/(mid+1);
		    
		    if(cost<=k)
		        high = mid;
		    else
		        low = mid + 1;
		}
		
		cout<<high<<endl;
	}

	return 0;
}
