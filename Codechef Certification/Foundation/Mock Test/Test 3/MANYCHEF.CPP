// https://www.codechef.com/FLMOCK03/problems/MANYCHEF

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
	string chef="CHEF";
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = s.size();

		for(int i=n-4, j; i>=0; i--){
			for(j=0; j<4; j++){
				if(!(s[i+j]==chef[j] || s[i+j]=='?'))
					break;
			}

			if(j==4){
				for(j=0; j<4; j++)
					s[i+j] = chef[j];
			}
		}

		for(int i=0; i<n; i++){
			if(s[i]=='?')
				s[i] = 'A';
		}

		cout<<s<<endl;
	}

	return 0;
}
