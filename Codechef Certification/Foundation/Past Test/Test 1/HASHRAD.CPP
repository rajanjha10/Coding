// https://www.codechef.com/FLPAST01/problems/HASHRAD

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
		string s;
		cin>>s;

		LL sum=0;
		for(LL i=0; i<s.size(); i++)
			sum += s[i]-'a';

		cout<<sum<<" ";
		string ans(s.size(), 'a');
		for(LL i=ans.size()-1; i>=0; i--){
			ans[i] = min(25LL, sum) + 'a';
			sum -= ans[i] - 'a';
		}



		if(ans==s){
			sort(ans.begin(), ans.end());
			if(ans!=s)
				cout<<ans<<endl;
			else{
				for(LL i=1; i<ans.size(); i++){
					if(ans[i]=='z' && ans[i-1]!='z'){
						ans[i] -= 1;
						ans[i-1] += 1;
						break;
					}
				}

				if(ans!=s)
					cout<<ans<<endl;
				else if(next_permutation(s.begin(), s.end()))
					cout<<s<<endl;
				else
					cout<<-1<<endl;
			}
		}
		else
			cout<<ans<<endl;

	}

	return 0;
}
