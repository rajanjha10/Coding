//https://www.spoj.com/problems/ARRANGE/

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
		int n, cnt1=0, flag123=1;
		cin>>n;
		LL a[n];
		read(a, n);

		for(int i=0; i<n; i++){
			if(a[i]!=2 && a[i]!=3 && a[i]!=1)
				flag123 = 0;
			if(a[i]==1)
				cnt1++;
		}

		sort(a, a+n, greater<LL>());
		for(int i=0; i<cnt1; i++)
			cout<<1<<" ";

		if(flag123==1){
			for(int i=n-1-cnt1; ~i; i--){
				if(a[i]==1)
					break;
				cout<<a[i]<<" ";
			}
		}
		else{
			for(int i=0; i<n; i++){
				if(a[i]==1)
					break;
				cout<<a[i]<<" ";
			}
		}
		cout<<endl;

	}

	return 0;
}
