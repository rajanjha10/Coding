// https://www.codechef.com/FLPAST01/problems/BADMATH

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool eval(string s, int m){
	int rem = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='1')
			rem = (2*rem + 1)%m;
		else
			rem = (2*rem)%m;
	}

	return (rem==0);
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;

		string s;
		cin>>s;

		vector<int> blanks;
		LL cnt = 0;
		for(int i=0; i<s.size(); i++){
			if(s[i]=='_'){
				blanks.push_back(i);
				s[i] = '0';
			}
		}

		LL sz = 1<<blanks.size();

		for(LL i=0; i<sz; i++){
			string temp = s;
			for(LL j=0; j<blanks.size(); j++){
				if((1<<j) & i)
					temp[blanks[j]] = '1';
			}

			cnt += eval(temp, m);
		}

		cout<<cnt<<endl;
	}

	return 0;
}
