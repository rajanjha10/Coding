//https://www.codechef.com/problems/CAKEDOOM

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
		int k;
		cin>>k;
		string s, st;
		cin>>s;
		
		int n = s.size();
		string ans = "NO";
		for(int c='0'; c<k+'0'; c++){
			st = s;
			if(st[0]!='?' && st[0]!=c)
				continue;

			bool good = 1;
			st[0] = c;
			for(int i=1; i<n; i++){
				bool flag = 0;

				for(int j='0'; j<k+'0'; j++){
					if(st[i]!='?' && st[i]!=j)
						continue;

					if(st[i-1]!=j && st[(i+1)%n]!=j){
						st[i] = j;
						flag = 1;
						break;
					}
				}

				if(!flag){
					good = 0;
					break;
				}
			}
			
			if(good){
				ans = st;
				break;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}
